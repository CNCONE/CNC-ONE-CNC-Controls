/*
 * Display.cpp
 *
 * Created: 04/11/2014 09:42:47
 *  Author: David
 */

#include "Display.hpp"
#include "ColourSchemes.hpp"
#include "Icons/Icons.hpp"

#undef min
#undef max
#undef array
#undef result
#include <algorithm>

extern UTFT lcd;

const int maxXerror = 8, maxYerror = 8;		// how close (in pixels) the X and Y coordinates of a touch event need to be to the outline of the button for us to allow it

// Static fields of class DisplayField
LcdFont DisplayField::defaultFont = nullptr;
Colour DisplayField::defaultFcolour = white;
Colour DisplayField::defaultBcolour = black;
Colour DisplayField::defaultButtonBorderColour = black;
Colour DisplayField::defaultGradColour = 0;
Colour DisplayField::defaultPressedBackColour = black;
Colour DisplayField::defaultPressedGradColour = 0;
Palette DisplayField::defaultIconPalette = IconPaletteLight;

DisplayField::DisplayField(PixelNumber py, PixelNumber px, PixelNumber pw)
	: y(py), x(px), width(pw), fcolour(defaultFcolour), bcolour(defaultBcolour),
		changed(true), visible(true), underlined(false), border(false), textRows(1), next(nullptr)
{
}

void DisplayField::SetTextRows(const char * _ecv_array null t)
{
	unsigned int rows = 1;
	if (t != nullptr)
	{
		while (*t != 0)
		{
			if (*t == '\n')
			{
				++rows;
			}
			++t;
		}
	}
	textRows = rows;
}

void DisplayField::SetPositionAndWidth(PixelNumber newX, PixelNumber newWidth)
{
	if (x == newX && width == newWidth)
	{
		return;
	}
	x = newX;
	width = newWidth;
	changed = true;
}

void DisplayField::SetPosition(PixelNumber x, PixelNumber y)
{
	if (this->x == x && this->y == y)
	{
		return;
	}
	this->x = x;
	this->y = y;
	changed = true;
}

/*static*/ void DisplayField::SetDefaultColours(Colour pf, Colour pb, Colour pbb, Colour pg, Colour pbp, Colour pgp, Palette pal)
{
	defaultFcolour = pf;
	defaultBcolour = pb;
	defaultButtonBorderColour = pbb;
	defaultGradColour = pg;
	defaultPressedBackColour = pbp;
	defaultPressedGradColour = pgp;
	defaultIconPalette = pal;
}

/*static*/ PixelNumber DisplayField::GetTextWidth(const char* _ecv_array s, PixelNumber maxWidth)
{
	lcd.setFont(DisplayField::defaultFont);
	lcd.setTextPos(0, 9999, maxWidth);
	lcd.printf(s);						// dummy print to get text width
	return lcd.getTextX();
}

/*static*/ PixelNumber DisplayField::GetTextWidth(const char* _ecv_array s, PixelNumber maxWidth, size_t maxChars)
{
	lcd.setTextPos(0, 9999, maxWidth);
	lcd.printf("%.*s", maxChars, s);				// dummy print to get text width
	return lcd.getTextX();
}

void DisplayField::Show(bool v)
{
	if (visible != v)
	{
		visible = changed = v;
	}
}

// Find the best match to a touch event in a list of fields
ButtonPress DisplayField::FindEvent(PixelNumber x, PixelNumber y, DisplayField * null p)
{
	int bestError = maxXerror + maxYerror;
	ButtonPress best;
	while (p != nullptr)
	{
		p->CheckEvent(x, y, bestError, best);
		p = p->next;
	}
	return best;
}

void DisplayField::SetColours(Colour pf, Colour pb)
{
	if (fcolour != pf || bcolour != pb)
	{
		fcolour = pf;
		bcolour = pb;
		changed = true;
	}
}

// ButtonPress class methods
ButtonPress::ButtonPress() : button(nullptr), index(0) { }

ButtonPress::ButtonPress(ButtonBase *b, unsigned int pi) : button(b), index(pi) { }

void ButtonPress::Set(ButtonBase *b, unsigned int pi)
{
	button = b;
	index = pi;
}

void ButtonPress::Clear()
{
	button = nullptr;
	index = 0;
}

event_t ButtonPress::GetEvent() const
{
	return button->GetEvent();
}

int ButtonPress::GetIParam() const
{
	return button->GetIParam(index);
}

const char* _ecv_array ButtonPress::GetSParam() const
{
	return button->GetSParam(index);
}

bool ButtonPress::operator==(const ButtonPress& other) const { return button == other.button && index == other.index; }

// Window class methods
Window::Window(Colour pb)
	: root(nullptr), next(nullptr), backgroundColour(pb)
{
}

// Prepend a field to the linked list of displayed fields
void Window::AddField(DisplayField *d)
{
	d->next = root;
	root = d;
}

bool Window::ObscuredByPopup(const DisplayField *p) const
{
	return next != nullptr
			&& (  (   p->GetMaxY() >= next->Ypos() && p->GetMinY() < next->Ypos() + next->GetHeight()
				   && p->GetMaxX() >= next->Xpos() && p->GetMinX() < next->Xpos() + next->GetWidth()
				  )
				|| next->ObscuredByPopup(p)
			   );
}

bool Window::Visible(const DisplayField *p) const
{
	return p->IsVisible() && !ObscuredByPopup(p);
}

// Get the field that has been touched, or nullptr if we can't find one
ButtonPress Window::FindEvent(PixelNumber x, PixelNumber y)
{
	return (next != nullptr) ? next->FindEvent(x, y)
			: (x < Xpos() || y < Ypos()) ? ButtonPress()
				: DisplayField::FindEvent(x - Xpos(), y - Ypos(), root);
}

// Get the field that has been touched, but search only outside the popup
ButtonPress Window::FindEventOutsidePopup(PixelNumber x, PixelNumber y)
{
	if (next == nullptr) return ButtonPress();

	ButtonPress f = DisplayField::FindEvent(x, y, root);
	return (f.IsValid() && Visible(f.GetButton())) ? f : ButtonPress();
}

void Window::SetPopup(PopupWindow * p, PixelNumber px, PixelNumber py, bool redraw)
{
	if (px == AutoPlace)
	{
		px = (DisplayX - p->GetWidth())/2;
	}
	if (py == AutoPlace)
	{
		py = (DisplayY - p->GetHeight())/2;
	}
	p->SetPos(px, py);
	Window *pw = this;
	while (pw->next != nullptr)
	{
		if (pw->next == p)
		{
			if (redraw)
			{
				p->Refresh(true);
			}
			return;				// popup is already displayed
		}
		pw = pw->next;
	}
	p->next = nullptr;			// ensure no nested popup
	pw->next = p;
	if (redraw)
	{
		p->Refresh(true);
	}
}

void Window::ClearPopup(bool redraw, PopupWindow *whichOne)
{
	if (next != nullptr)
	{
		// Find the penultimate window
		Window *pw = this;
		while (pw->next->next != nullptr)
		{
			pw = pw->next;
		}

		if (whichOne == nullptr || whichOne == pw->next)
		{
			const PixelNumber xmin = pw->next->Xpos(), xmax = xmin + pw->next->GetWidth() - 1, ymin = pw->next->Ypos(), ymax = ymin + pw->next->GetHeight() - 1;
			bool popupWasContained = pw->Contains(xmin, ymin, xmax, ymax);
			if (popupWasContained)
			{
				// Clear the area that was occupied by the last window to the background colour of the penultimate window
				lcd.setColor(pw->backgroundColour);
				lcd.fillRoundRect(xmin, ymin, xmax, ymax);
			}

			// Detach the last window
			pw->next = nullptr;

			if (redraw)
			{
				if (popupWasContained)
				{
					// Re-display the fields of the penultimate window that were obscured
					for (DisplayField * null pp = pw->root; pp != nullptr; pp = pp->next)
					{
						if (pp->IsVisible())
						{
							pp->Refresh(true, pw->Xpos(), pw->Ypos());
						}
					}
				}
				else
				{
					Refresh(true);		// redraw everything
				}
			}
		}
	}
}

// Redraw the specified field
void Window::Redraw(DisplayField *f)
{
	for (DisplayField * null p = root; p != nullptr; p = p->next)
	{
		if (p == f)
		{
			// The field belongs to this window
			if (!ObscuredByPopup(p))
			{
				if (p->IsVisible())
				{
					p->Refresh(true, Xpos(), Ypos());
				}
				else
				{
					lcd.setColor(backgroundColour);
					lcd.fillRect(p->GetMinX() + Xpos(), p->GetMinY() + Ypos(), p->GetMaxX() + Xpos(), p->GetMaxY() + Ypos());
				}
			}
			return;
		}
	}

	// Else we didn't find the field in our window, so look in nested windows
	if (next != nullptr)
	{
		next->Redraw(f);
	}
}

void Window::Show(DisplayField * null f, bool v)
{
	if (f != nullptr && (f->IsVisible() != v || f->HasChanged()))
	{
		f->Show(v);

		// Check whether the field is currently in the display list, if so then show or hide it
		for (DisplayField *p = root; p != nullptr; p = p->next)
		{
			if (p == f)
			{
				if (ObscuredByPopup(f))
				{
					// nothing to do
				}
				else if (v)
				{
					f->Refresh(true, Xpos(), Ypos());
				}
				else
				{
					lcd.setColor(backgroundColour);
					lcd.fillRect(f->GetMinX(), f->GetMinY(), f->GetMaxX(), f->GetMaxY());
				}
				return;
			}
		}

		// Else we didn't find it, so maybe it is in a popup field
		if (next != nullptr)
		{
			next->Redraw(f);
		}
	}
}

// Show the button as pressed or not
void Window::Press(ButtonPress bp, bool v)
{
	if (bp.IsValid())
	{
		bp.GetButton()->Press(v, bp.GetIndex());
		if (bp.GetButton()->IsVisible())		// need to check this in case we are releasing the button and it has gone invisible since we pressed it
		{
			Redraw(bp.GetButton());
		}
	}
}

MainWindow::MainWindow() : Window(black), staticLeftMargin(0)
{
}

void MainWindow::Init(Colour bc)
{
	backgroundColour = bc;
}

// Refresh all fields. If 'full' is true then we rewrite them all, else we just rewrite those that have changed.
void MainWindow::Refresh(bool full)
{
	if (full)
	{
		lcd.fillScr(backgroundColour, staticLeftMargin);
	}

	for (DisplayField * null pp = root; pp != nullptr; pp = pp->next)
	{
		if (Visible(pp))
		{
			pp->Refresh(full, 0, 0);
		}
	}
	if (next != nullptr)
	{
		next->Refresh(full);
	}
}

bool MainWindow::Contains(PixelNumber xmin, PixelNumber ymin, PixelNumber xmax, PixelNumber ymax) const
{
	UNUSED(xmin); UNUSED(ymin); UNUSED(xmax); UNUSED(ymax);
	return true;
}

void MainWindow::ClearAllPopups()
{
	while (next != nullptr)
	{
		ClearPopup(true);
	}
}

PopupWindow::PopupWindow(PixelNumber ph, PixelNumber pw, Colour pb, Colour pBorder, bool roundCorners)
	: Window(pb), height(ph), width(pw), borderColour(pBorder), roundedCorners(roundCorners)
{
}

void PopupWindow::Refresh(bool full)
{
	if (full)
	{
		// Draw a rectangle inside the border
		lcd.setColor(backgroundColour);
		if (roundedCorners)
		{
			lcd.fillRoundRect(xPos + 1, yPos + 2, xPos + width - 2, yPos + height - 3);
		}
		else
		{
			lcd.fillRect(xPos, yPos, xPos + width, yPos + height);
		}

		// Draw a double border
		lcd.setColor(borderColour);
		if (roundedCorners)
		{
			lcd.drawRoundRect(xPos, yPos, xPos + width - 1, yPos + height - 1);
			lcd.drawRoundRect(xPos + 1, yPos + 1, xPos + width - 2, yPos + height - 2);
		}
		else
		{
			lcd.drawRect(xPos, yPos, xPos + width - 1, yPos + height - 1);
			lcd.drawRect(xPos + 1, yPos + 1, xPos + width - 2, yPos + height - 2);
		}
	}

	for (DisplayField * null p = root; p != nullptr; p = p->next)
	{
		if (p->IsVisible() && (full || !ObscuredByPopup(p)))
		{
			p->Refresh(full, xPos, yPos);
		}
	}

	if (next != nullptr)
	{
		next->Refresh(full);
	}
}

bool PopupWindow::Contains(PixelNumber xmin, PixelNumber ymin, PixelNumber xmax, PixelNumber ymax) const
{
	return xPos + 2 <= xmin && yPos + 2 <= ymin && xPos + width >= xmax + 3 && yPos + height >= ymax + 3;
}

void ColourGradientField::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full)
	{
		PixelNumber px = x + xOffset;
		const PixelNumber py = y + yOffset;
		const PixelNumber lineRepeat = width/128;
		for (PixelNumber i = 0; i < 32; ++i)
		{
			lcd.setColor(i << 11);
			for (PixelNumber j = 0; j < lineRepeat; ++j)
			{
				lcd.drawLine(px, py, px, py + height - 1);
				++px;
			}
		}
		for (PixelNumber i = 0; i < 64; ++i)
		{
			lcd.setColor(i << 5);
			for (PixelNumber j = 0; j < lineRepeat; ++j)
			{
				lcd.drawLine(px, py, px, py + height - 1);
				++px;
			}
		}
		for (PixelNumber i = 0; i < 32; ++i)
		{
			lcd.setColor(i);
			for (PixelNumber j = 0; j < lineRepeat; ++j)
			{
				lcd.drawLine(px, py, px, py + height - 1);
				++px;
			}
		}
	}
}

void StaticColourField::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full)
	{
		xOffset += x;
		yOffset += y;
		lcd.setColor(bcolour);
		lcd.fillRect(xOffset, yOffset, xOffset + width - 1, yOffset + GetHeight() - 1);
		lcd.setColor(fcolour);
		lcd.drawRect(xOffset, yOffset, xOffset + width - 1, yOffset + GetHeight() - 1);
	}
}


PixelNumber FieldWithText::GetHeight() const
{
	PixelNumber height = UTFT::GetFontHeight(font) * textRows;
	height += (textRows - 1) * 2;		// 2px space between lines
	if (underlined)
	{
		height += 2;					// one space and the underline
	}
	if (border)
	{
		height += 4;					// one space abd border top and bottom
	}
	return height;
}

void FieldWithText::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		xOffset += x;
		yOffset += y;
		PixelNumber textWidth = width;
		if (border)
		{
			if (full)
			{
				lcd.setColor(fcolour);
				lcd.drawRect(xOffset, yOffset, xOffset + width - 1, yOffset + GetHeight() - 1);
			}
			xOffset += 2;
			yOffset += 2;
			textWidth -= 4;
		}

		lcd.setFont(font);
		lcd.setColor(fcolour);
		lcd.setBackColor(bcolour);

		// Do a dummy print to get the text width. Needed for underlining and for centre- or right-aligned text.
		lcd.setTextPos(0, 9999, textWidth);
		PrintText();
		const PixelNumber actualWidth = lcd.getTextX();
		const PixelNumber underlineY = yOffset + UTFT::GetFontHeight(font) + 1;
		if (underlined)
		{
			// Remove previous underlining
			lcd.setColor(bcolour);
			lcd.drawLine(xOffset, underlineY, xOffset + textWidth - 1, underlineY);
			lcd.setColor(fcolour);
		}

		lcd.setTextPos(xOffset, yOffset, xOffset + textWidth);
		if (align == TextAlignment::Left)
		{
			PrintText();
			lcd.clearToMargin();
			if (underlined)
			{
				lcd.drawLine(xOffset, underlineY, xOffset + actualWidth, underlineY);
			}
		}
		else
		{
			lcd.clearToMargin();
			PixelNumber spare = textWidth - actualWidth;
			if (align == TextAlignment::Centre)
			{
				const PixelNumber textX = xOffset + spare/2;
				lcd.setTextPos(textX, yOffset, xOffset + textWidth);
				PrintText();
				if (underlined)
				{
					lcd.drawLine(textX, underlineY, textX + actualWidth - 1, underlineY);
				}
			}
			else
			{
				// Must be right aligned. Try to add a right margin of up to 3 pixels for better appearance.
				if (spare <= 3)
				{
					spare = 0;
				}
				else
				{
					spare -= 3;
				}
				const PixelNumber textX = xOffset + spare;
				lcd.setTextPos(textX, yOffset, xOffset + textWidth);
				PrintText();
				if (underlined)
				{
					lcd.drawLine(textX, underlineY, textX + actualWidth, underlineY);
				}
			}
		}
		changed = false;
	}
}

void TextField::PrintText() const
{
	if (label != nullptr)
	{
		lcd.printf(label);
	}
	if (text != nullptr)
	{
		lcd.printf(text);
	}
}

void FloatField::PrintText() const
{
	if (label != nullptr)
	{
		lcd.printf(label);
	}
	lcd.printf("%.*f", numDecimals, val);
	if (units != nullptr)
	{
		lcd.printf(units);
	}
}

void IntegerField::PrintText() const
{
	if (label != nullptr)
	{
		lcd.printf(label);
	}
	lcd.printf("%d", val);
	if (units != nullptr)
	{
		lcd.printf(units);
	}
}

void StaticTextField::PrintText() const
{
	if (text != nullptr)
	{
		lcd.printf(text);
	}
}

ButtonBase::ButtonBase(PixelNumber py, PixelNumber px, PixelNumber pw)
	: DisplayField(py, px, pw),
	  borderColour(defaultButtonBorderColour), gradColour(defaultGradColour),
	  pressedBackColour(defaultPressedBackColour), pressedGradColour(defaultPressedGradColour), evt(nullEvent), pressed(false)
{
}

PixelNumber ButtonBase::textMargin = 1;
PixelNumber ButtonBase::iconMargin = 1;

void ButtonBase::DrawOutline(PixelNumber xOffset, PixelNumber yOffset, bool isPressed) const
{
	lcd.setColor((isPressed) ? pressedBackColour : bcolour);
	// Note that we draw the filled rounded rectangle with the full width but 2 pixels less height than the border.
	// This means that we start with the requested colour inside the border.
	lcd.fillRoundRect(x + xOffset, y + yOffset + 1, x + xOffset + width - 1, y + yOffset + GetHeight() - 2, (isPressed) ? pressedGradColour : gradColour, buttonGradStep);
	lcd.setColor(borderColour);
	lcd.drawRoundRect(x + xOffset, y + yOffset, x + xOffset + width - 1, y + yOffset + GetHeight() - 1);
}

void ButtonBase::CheckEvent(PixelNumber x, PixelNumber y, int& bestError, ButtonPress& best) /*override*/
{
	if (IsVisible() && GetEvent() != nullEvent)
	{
		const int xError = (x < GetMinX()) ? GetMinX() - x
								: (x > GetMaxX()) ? x - GetMaxX()
									: 0;
		if (xError < maxXerror)
		{
			const int yError = (y < GetMinY()) ? GetMinY() - y
									: (y > GetMaxY()) ? y - GetMaxY()
										: 0;
			if (yError < maxYerror && xError + yError < bestError)
			{
				bestError = xError + yError;
				best.Set(this, 0);
			}
		}
	}
}

SingleButton::SingleButton(PixelNumber py, PixelNumber px, PixelNumber pw)
	: ButtonBase(py, px, pw)
{
	param.sParam = nullptr;
}

void SingleButton::DrawOutline(PixelNumber xOffset, PixelNumber yOffset) const
{
	ButtonBase::DrawOutline(xOffset, yOffset, pressed);
}

void SingleButton::Press(bool p, int index) /*override*/
{
	UNUSED(index);
	if (p != pressed)
	{
		pressed = p;
		changed = true;
	}
}

ArrowButton::ArrowButton(PixelNumber py, PixelNumber px, PixelNumber pw, PixelNumber ph, Orientations orientation, event_t e, int iParam)
	: ButtonBase(py, px, pw), height(ph), myOrientation(orientation)
{
	param.sParam = nullptr;
	SetEvent(e, iParam);
}

void ArrowButton::DrawOutline(PixelNumber xOffset, PixelNumber yOffset) const
{
	PixelNumber thickness, height, leg;
	PixelNumber x0, y0, x1, y1, x2, y2, x3, y3, x4, y4 ,x5, y5, x6, y6,
				x1b, y1b, x2b, y2b, x3b, y3b, x4b, y4b, x5b, y5b, x6b, y6b;

	height = GetHeight();
	x0 = x + xOffset;
	y0 = y + xOffset;

	switch (myOrientation)
	{
	case left:
		thickness = width/4;
		leg = sqrt((thickness*thickness)/2);

		x1 = x0 + width - leg;
		y1 = y0;
		x1b = x1;
		y1b = y1 + 1;

		x2 = x0;
		y2 = y0 + height / 2;
		x2b = x2+1;
		y2b = y2;

		x3 = x1;
		y3 = y1 + height;
		x3b = x3;
		y3b = y3 - 1;

		x4 = x0 + width;
		y4 = y3 - leg;
		x4b = x4 - 1;
		y4b = y4;

		x5 = x0 + 2 * leg;
		y5 = y2;
		x5b = x5 - 1;
		y5b = y5;

		x6 = x4;
		y6 = y1 + leg;
		x6b = x6 - 1;
		y6b = y6;
		break;
	case up:
		thickness = height/4;
		leg = sqrt((thickness*thickness)/2);

		x1 = x0;
		y1 = y0 + height - leg;
		x1b = x1 + 1;
		y1b = y1;

		x2 = x0 + width / 2;
		y2 = y0;
		x2b = x2;
		y2b = y2 + 1;

		x3 = x1 + width;
		y3 = y1;
		x3b = x3 - 1;
		y3b = y3;

		x4 = x3 - leg;
		y4 = y0 + height;
		x4b = x4;
		y4b = y4 + 1;

		x5 = x2;
		y5 = y2 + 2 * leg;
		x5b = x5;
		y5b = y5 + 1;

		x6 = x1 + leg;
		y6 = y4;
		x6b = x6;
		y6b = y6 + 1;
		break;
	case right:
		thickness = width/4;
		leg = sqrt((thickness*thickness)/2);

		x1 = x0 + leg;
		y1 = y0;
		x1b = x1;
		y1b = y1 + 1;

		x2 = x0 + width;
		y2 = y0 + height / 2;
		x2b = x2 - 1;
		y2b = y2;

		x3 = x1;
		y3 = y1 + height;
		x3b = x3;
		y3b = y3 - 1;

		x4 = x0;
		y4 = y3 - leg;
		x4b = x4 + 1;
		y4b = y4;

		x5 = x2 - 2 * leg;
		y5 = y2;
		x5b = x5 + 1;
		y5b = y5;

		x6 = x4;
		y6 = y1 + leg;
		x6b = x6 + 1;
		y6b = y6;
		break;
	case down:
		thickness = height/4;
		leg = sqrt((thickness*thickness)/2);

		x1 = x0;
		y1 = y0 + leg;
		x1b = x1;
		y1b = y1 + 1;

		x2 = x0 + width / 2;
		y2 = y0 + height;
		x2b = x2;
		y2b = y2 + 1;

		x3 = x1 + width;
		y3 = y1;
		x3b = x3;
		y3b = y3 + 1;

		x4 = x3 - leg;
		y4 = y0;
		x4b = x4 - 1;
		y4b = y4;

		x5 = x2;
		y5 = y2 - 2 * leg;
		x5b = x5 ;
		y5b = y5 - 1;

		x6 = x1 + leg;
		y6 = y4;
		x6b = x6 + 1;
		y6b = y6;
		break;
	default:
		x1 = x2 = x3 = x4 = x5 = x6 = x0;
		y1 = y2 = y3 = y4 = y5 = y6 = y0;
	}
	//		lcd.setColor(borderColour);
	lcd.setColor((pressed) ? pressedBackColour : borderColour);
	lcd.drawLine(x1,y1,x2,y2);
	lcd.drawLine(x2,y2,x3,y3);
	lcd.drawLine(x3,y3,x4,y4);
	lcd.drawLine(x4,y4,x5,y5);
	lcd.drawLine(x5,y5,x6,y6);
	lcd.drawLine(x6,y6,x1,y1);

	lcd.drawLine(x1b,y1b,x2b,y2b);
	lcd.drawLine(x2b,y2b,x3b,y3b);
	lcd.drawLine(x3b,y3b,x4b,y4b);
	lcd.drawLine(x4b,y4b,x5b,y5b);
	lcd.drawLine(x5b,y5b,x6b,y6b);
	lcd.drawLine(x6b,y6b,x1b,y1b);
}

void ArrowButton::Press(bool p, int index) /*override*/
{
	UNUSED(index);
	if (p != pressed)
	{
		pressed = p;
		changed = true;
	}
}

void ArrowButton::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		DrawOutline(xOffset, yOffset);
		changed = false;
	}
}

void StopButton::DrawOutline(PixelNumber xOffset, PixelNumber yOffset) const
{
	PixelNumber thickness, height, leg;
	PixelNumber x0, y0, x1, y1, r1, r2;

	x0 = x + xOffset;
	y0 = y + xOffset;

	x1 = x0 + width/2;
	y1 = y0 + width/2;

	r1 = width/2;
	r2 = (r1>3) ? r1-3 : 0;

	//	lcd.setColor(borderColour);
	lcd.setColor(borderColour);
	lcd.fillCircle(x1, y1, r1);

	if(!pressed)
	{
		lcd.setColor(bcolour);
		lcd.fillCircle(x1, y1, r2);
	}

	// Note that we draw the filled rounded rectangle with the full width but 2 pixels less height than the border.
	// This means that we start with the requested colour inside the border.
	//lcd.fillRoundRect(x + xOffset, y + yOffset + 1, x + xOffset + width - 1, y + yOffset + GetHeight() - 2, (isPressed) ? pressedGradColour : gradColour, buttonGradStep);
	//lcd.setColor(borderColour);
	//lcd.drawRoundRect(x + xOffset, y + yOffset, x + xOffset + width - 1, y + yOffset + GetHeight() - 1);
}

void StopButton::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		DrawOutline(xOffset, yOffset);
		lcd.setTransparentBackground(true);
		lcd.setColor(fcolour);
		lcd.setFont(font);
		unsigned int rowsLeft = textRows;
		size_t offset = 0;
		PixelNumber rowY = y + yOffset + width/2 - UTFT::GetFontHeight(font)/2;
		do
		{
			lcd.setTextPos(0, 9999, width - 6);
			PrintText(offset);							// dummy print to get text width
			PixelNumber spare = width - 6 - lcd.getTextX();
			lcd.setTextPos(x + xOffset + 3 + spare/2, rowY, x + xOffset + width - 3);	// text is always centre-aligned
			offset += PrintText(offset) + 1;
			rowY += UTFT::GetFontHeight(font) + 2;
		} while (--rowsLeft != 0);
		lcd.setTransparentBackground(false);
		changed = false;
	}
}

/*static*/ LcdFont ButtonWithText::font;

PixelNumber ButtonWithText::GetHeight() const
{
	PixelNumber ret = (UTFT::GetFontHeight(font) + 2) * textRows - 2;	// height of the text
	ret += 2 * textMargin + 2;											// add the border height
	return ret;
}

void ButtonWithText::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		DrawOutline(xOffset, yOffset);
		lcd.setTransparentBackground(true);
		lcd.setColor(fcolour);
		lcd.setFont(font);
		unsigned int rowsLeft = textRows;
		size_t offset = 0;
		PixelNumber rowY = y + yOffset + textMargin + 1;
		do
		{
			lcd.setTextPos(0, 9999, width - 6);
			PrintText(offset);							// dummy print to get text width
			PixelNumber spare = width - 6 - lcd.getTextX();
			lcd.setTextPos(x + xOffset + 3 + spare/2, rowY, x + xOffset + width - 3);	// text is always centre-aligned
			offset += PrintText(offset) + 1;
			rowY += UTFT::GetFontHeight(font) + 2;
		} while (--rowsLeft != 0);
		lcd.setTransparentBackground(false);
		changed = false;
	}
}

CharButton::CharButton(PixelNumber py, PixelNumber px, PixelNumber pw, char pc, event_t e)
	: ButtonWithText(py, px, pw)
{
	SetEvent(e, (int)pc);
}

size_t CharButton::PrintText(size_t offset) const
{
	UNUSED(offset);
	return lcd.write((char)GetIParam(0));
}

TextButton::TextButton(PixelNumber py, PixelNumber px, PixelNumber pw, const char * _ecv_array null pt, event_t e, int param)
	: ButtonWithText(py, px, pw), text(pt)
{
	SetTextRows(pt);
	SetEvent(e, param);
}

TextButton::TextButton(PixelNumber py, PixelNumber px, PixelNumber pw, const char * _ecv_array null pt, event_t e, const char * _ecv_array param)
	: ButtonWithText(py, px, pw), text(pt)
{
	SetEvent(e, param);
}

size_t TextButton::PrintText(size_t offset) const
{
	if (text != nullptr)
	{
		return lcd.printf(text + offset);
	}
	return 0;
}

TextButtonWithLabel::TextButtonWithLabel(PixelNumber py, PixelNumber px, PixelNumber pw, const char * _ecv_array null pt, event_t e, int param, const char* _ecv_array null label)
	: TextButton(py, px, pw, pt, e, param), label(label)
{
}

TextButtonWithLabel::TextButtonWithLabel(PixelNumber py, PixelNumber px, PixelNumber pw, const char * _ecv_array null pt, event_t e, const char * _ecv_array param, const char* _ecv_array null label)
	: TextButton(py, px, pw, pt, e, param), label(label)
{
}

size_t TextButtonWithLabel::PrintText(size_t offset) const
{
	size_t w = 0;
	if (label != nullptr)
	{
		w += lcd.printf(label);
	}
	w += TextButton::PrintText(offset);
	return w;
}

IconButton::IconButton(PixelNumber py, PixelNumber px, PixelNumber pw, Icon ic, event_t e, int param)
	: SingleButton(py, px, pw), icon(ic)
{
	SetEvent(e, param);
}

IconButton::IconButton(PixelNumber py, PixelNumber px, PixelNumber pw, Icon ic, event_t e, const char * _ecv_array param)
: SingleButton(py, px, pw), icon(ic)
{
	SetEvent(e, param);
}

void IconButton::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		DrawOutline(xOffset, yOffset);
		const uint16_t sx = GetIconWidth(icon), sy = GetIconHeight(icon);
		lcd.setTransparentBackground(true);
		lcd.drawBitmap4(xOffset + x + (width - sx)/2, yOffset + y + iconMargin + 1, sx, sy, GetIconData(icon), defaultIconPalette);
		lcd.setTransparentBackground(false);
		changed = false;
	}
}

IconButtonWithText::IconButtonWithText(PixelNumber py, PixelNumber px, PixelNumber pw, Icon ic, event_t e, const char * text, int param)
	: IconButton(py, px, pw, ic, e, param), font(DisplayField::defaultFont), text(text), val(0), printText(true)
{
}

IconButtonWithText::IconButtonWithText(PixelNumber py, PixelNumber px, PixelNumber pw, Icon ic, event_t e, const char * text, const char * _ecv_array param)
	: IconButton(py, px, pw, ic, e, param), font(DisplayField::defaultFont), text(text), val(0), printText(true)
{
}

IconButtonWithText::IconButtonWithText(PixelNumber py, PixelNumber px, PixelNumber pw, Icon ic, event_t e, int textVal, int param)
	: IconButton(py, px, pw, ic, e, param), font(DisplayField::defaultFont), text(nullptr), val(textVal), printText(true)
{
}

IconButtonWithText::IconButtonWithText(PixelNumber py, PixelNumber px, PixelNumber pw, Icon ic, event_t e, int textVal, const char * _ecv_array param)
	: IconButton(py, px, pw, ic, e, param), font(DisplayField::defaultFont), text(nullptr), val(textVal), printText(true)
{
}

size_t IconButtonWithText::PrintText() const
{
	size_t ret = 0;
	if (!printText)
	{
		return ret;
	}
	if (text != nullptr)
	{
		ret += lcd.printf(text);
	}
	else {
		ret += lcd.printf("%d", val);
	}
	return ret;
}

void IconButtonWithText::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		DrawOutline(xOffset, yOffset);
		const uint16_t sx = GetIconWidth(icon), sy = GetIconHeight(icon);

		lcd.setFont(font);
		lcd.setTextPos(0, 9999, width - 6);
		PrintText();							// dummy print to get text width
		const PixelNumber textWidth = lcd.getTextX() + 6;	// add three pixels on each side

		// Print the icon
		lcd.setTransparentBackground(true);
		const PixelNumber iconXOffset = xOffset + x + (width - (sx+textWidth))/2;
		lcd.drawBitmap4(iconXOffset, yOffset + y + iconMargin + 1, sx, sy, GetIconData(icon), defaultIconPalette);

		// Print the text
		const PixelNumber textX = iconXOffset + sx + 3;
		const PixelNumber rowY = y + yOffset + textMargin + 1;
		lcd.setTextPos(textX, rowY, textX + textWidth);
		lcd.setColor(fcolour);
		PrintText();
		lcd.setTransparentBackground(false);

		changed = false;
	}
}

size_t IntegerButton::PrintText(size_t offset) const
{
	UNUSED(offset);
	size_t ret = 0;
	if (label != nullptr)
	{
		ret += lcd.printf(label);
	}
	ret += lcd.printf("%d", val);
	if (units != nullptr)
	{
		ret += lcd.printf(units);
	}
	return ret;
}

size_t FloatButton::PrintText(size_t offset) const
{
	UNUSED(offset);
	size_t ret = lcd.printf("%.*f", numDecimals, val);
	if (units != nullptr)
	{
		ret += lcd.printf(units);
	}
	return ret;
}

ButtonRow::ButtonRow(PixelNumber py, PixelNumber px, PixelNumber pw, PixelNumber ps, unsigned int nb, event_t e)
	: ButtonBase(py, px, pw), numButtons(nb), whichPressed(-1), step(ps)
{
	evt = e;
}

/*static*/ LcdFont ButtonRowWithText::font;

ButtonRowWithText::ButtonRowWithText(PixelNumber py, PixelNumber px, PixelNumber pw, PixelNumber ps, unsigned int nb, event_t e)
	: ButtonRow(py, px, pw, ps, nb, e)
{
}

PixelNumber ButtonRowWithText::GetHeight() const
{
	PixelNumber ret = (UTFT::GetFontHeight(font) + 2) * textRows - 2;	// height of the text
	ret += 2 * textMargin + 2;											// add the border height
	return ret;
}

void ButtonRowWithText::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		for (unsigned int i = 0; i < numButtons; ++i)
		{
			const PixelNumber buttonXoffset = xOffset + i * step;
			DrawOutline(buttonXoffset, yOffset, (int)i == whichPressed);
			lcd.setTransparentBackground(true);
			lcd.setColor(fcolour);
			lcd.setFont(font);
			lcd.setTextPos(0, 9999, width - 6);
			PrintText(i);							// dummy print to get text width
			PixelNumber spare = width - 6 - lcd.getTextX();
			lcd.setTextPos(x + buttonXoffset + 3 + spare/2, y + yOffset + textMargin + 1, x + buttonXoffset + width - 3);	// text is always centre-aligned
			PrintText(i);
			lcd.setTransparentBackground(false);
		}
		changed = false;
	}
}

void CharButtonRow::PrintText(unsigned int n) const
{
	lcd.write(text[n]);
}

CharButtonRow::CharButtonRow(PixelNumber py, PixelNumber px, PixelNumber pw, PixelNumber ps, const char * _ecv_array s, event_t e)
	: ButtonRowWithText(py, px, pw, ps, strlen(s), e), text(s)
{
}

void CharButtonRow::CheckEvent(PixelNumber x, PixelNumber y, int& bestError, ButtonPress& best) /*override*/
{
	if (visible && GetEvent() != nullEvent)
	{
		const int yError = (y < GetMinY()) ? GetMinY() - y
								: (y > GetMaxY()) ? y - GetMaxY()
									: 0;
		if (yError < maxYerror && yError < bestError)
		{
			PixelNumber minX = GetMinX();
			PixelNumber maxX = GetMaxX();
			for (size_t i = 0; i < numButtons; ++i)
			{
				const int xError = (x < minX) ? minX - x
										: (x > maxX) ? x - maxX
											: 0;
				if (xError < maxXerror && xError + yError < bestError)
				{
					bestError = xError + yError;
					best.Set(this, i);
				}
				minX += step;
				maxX += step;
			}
		}
	}
}

void CharButtonRow::Press(bool p, int index) /*override*/
{
	whichPressed = (p) ? index : -1;
}

void CharButtonRow::ChangeText(const char* _ecv_array s)
{
	if (strcmp(text, s) == 0)
	{
		return;
	}
	text = s;
	changed = true;
}

void ProgressBar::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		PixelNumber pixelsSet = ((width - 2) * percent)/100;
		if (full)
		{
			lcd.setColor(fcolour);
			lcd.drawLine(x + xOffset, y, x + xOffset + width - 1, y + yOffset);
			lcd.drawLine(x + xOffset, y + yOffset + height - 1, x + xOffset + width - 1, y + yOffset + height - 1);
			lcd.drawLine(x + xOffset + width - 1, y + yOffset + 1, x + xOffset + width - 1, y + yOffset + height - 2);

			lcd.fillRect(x + xOffset, y + yOffset + 1, x + xOffset + pixelsSet, y + yOffset + height - 2);
			if (pixelsSet < width - 2)
			{
				lcd.setColor(bcolour);
				lcd.fillRect(x + xOffset + pixelsSet + 1, y + yOffset + 1, x + xOffset + width - 2, y + yOffset + height - 2);
			}
		}
		else if (pixelsSet > lastNumPixelsSet)
		{
			lcd.setColor(fcolour);
			lcd.fillRect(x + xOffset + lastNumPixelsSet, y + yOffset + 1, x + xOffset + pixelsSet, y + yOffset + height - 2);
		}
		else if (pixelsSet < lastNumPixelsSet)
		{
			lcd.setColor(bcolour);
			lcd.fillRect(x + xOffset + pixelsSet + 1, y + yOffset + 1, x + xOffset + lastNumPixelsSet, y + yOffset + height - 2);
		}
		changed = false;
		lastNumPixelsSet = pixelsSet;
	}
}

void StaticImageField::Refresh(bool full, PixelNumber xOffset, PixelNumber yOffset)
{
	if (full || changed)
	{
		lcd.drawCompressedBitmap(x + xOffset, y + yOffset, width, height, data);
		changed = false;
	}
}

// End
