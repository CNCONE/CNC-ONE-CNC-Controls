/*
 * ColourSchemes.cpp
 *
 * Created: 01/09/2016 13:13:29
 *  Author: David
 */

#ifndef OEM_COLOURS

#include "ColourSchemes.hpp"
#include "UserInterfaceConstants.hpp"
#include "Icons/Icons.hpp"

const ColourScheme colourSchemes[NumColourSchemes] =
{
	// Default CNC One
	{
		.index = 0,
		.pal = IconPaletteDefault,

		.titleBarTextColour = white,
		.titleBarBackColour = UTFT::fromRGB(47, 47, 47),
		.titleBarButtonBorderColour = UTFT::fromRGB(99, 99, 99),
		.labelTextColour = white,
		.infoTextColour = white,
		.infoBackColour = black,
		.defaultBackColour = black,
		.activeBackColour = black,
		.standbyBackColour = black,
		.tuningBackColour = black,
		.errorTextColour = white,
		.errorBackColour = veryDarkGrey,

		.popupBorderColour = midGrey,
		.popupBackColour = darkGrey,
		.popupTextColour = white,
		.popupButtonTextColour = white,
		.popupButtonBackColour = veryDarkGrey,
		.popupInfoTextColour = white,
		.popupInfoBackColour = darkGrey,

		.alertPopupBackColour = darkGrey,
		.alertPopupTextColour = white,

		.buttonTextColour = white,
		.buttonPressedTextColour = white,
		.buttonTextBackColour = UTFT::fromRGB(47, 47, 47),
		.buttonImageBackColour = UTFT::fromRGB(47, 47, 47),
		.buttonGradColour = 0,	//UTFT::fromRGB(8, 4, 8),
		.buttonPressedBackColour = UTFT::fromRGB(99, 99, 99),
		.buttonPressedGradColour = 0,	//UTFT::fromRGB(8, 8, 8),
		.buttonBorderColour = UTFT::fromRGB(47, 47, 47),
		.homedButtonBackColour = UTFT::fromRGB(47, 47, 47),
		.notHomedButtonBackColour = darkOrange,
		.pauseButtonBackColour = darkOrange,
		.resumeButtonBackColour = darkYellow,
		.resetButtonBackColour = darkRed,

		.progressBarColour = midGrey,
		.progressBarBackColour = veryDarkGrey,
		.stopButtonTextColour = white,
		.stopButtonBackColour = red,
		.coordBoxTextColour = UTFT::fromRGB(108, 108, 108),
		.coordBoxValueColour = white,
		.coordBoxBackColour = UTFT::fromRGB(47, 47, 47),
		.ctrlMoveArrowBackColour = black,
		.ctrlMoveArrowPressedBorderColour = UTFT::fromRGB(0, 138, 252),
		.ctrlMoveArrowBorderColour = UTFT::fromRGB(80, 80, 80)
	},

	// Light colour schema.
	{
		.index = 1,
		.pal = IconPaletteLight,

		.titleBarTextColour = white,
		.titleBarBackColour = red,
		.titleBarButtonBorderColour = UTFT::fromRGB(80, 80, 80),
		.labelTextColour = black,
		.infoTextColour = black,
		.infoBackColour = lightBlue,
		.defaultBackColour = white,
		.activeBackColour = lightRed,
		.standbyBackColour = lightYellow,
		.tuningBackColour = lightGreen,
		.errorTextColour = white,
		.errorBackColour = byzantine,

		.popupBorderColour = black,
		.popupBackColour = lightBlue,
		.popupTextColour = black,
		.popupButtonTextColour = black,
		.popupButtonBackColour = white,
		.popupInfoTextColour = black,
		.popupInfoBackColour = white,

		.alertPopupBackColour = lightGreen,
		.alertPopupTextColour = black,

		.buttonTextColour = black,
		.buttonPressedTextColour = black,
		.buttonTextBackColour = white,
		.buttonImageBackColour = white,
		.buttonGradColour = UTFT::fromRGB(255-8-8, 255-8-4, 255-8),
		.buttonPressedBackColour = lightGreen,
		.buttonPressedGradColour = UTFT::fromRGB(255-8-8, 255-8-4, 255-8),
		.buttonBorderColour = black,
		.homedButtonBackColour = lightBlue,
		.notHomedButtonBackColour = lightOrange,
		.pauseButtonBackColour = lightOrange,
		.resumeButtonBackColour = lightYellow,
		.resetButtonBackColour = lightRed,

		.progressBarColour = midGreen,
		.progressBarBackColour = white,

		.stopButtonTextColour = white,
		.stopButtonBackColour = UTFT::fromRGB(255, 24, 32),			// need enough G and B to allow for the gradient
		.coordBoxTextColour = UTFT::fromRGB(108, 108, 108),
		.coordBoxValueColour = white,
		.coordBoxBackColour = UTFT::fromRGB(28, 28, 31),
		.ctrlMoveArrowBackColour = white,
		.ctrlMoveArrowPressedBorderColour = UTFT::fromRGB(0, 138, 252),
		.ctrlMoveArrowBorderColour = UTFT::fromRGB(43, 43, 43)
	},

	// Dark colour scheme

	{
		.index = 2,
		.pal = IconPaletteDark,

		.titleBarTextColour = white,
		.titleBarBackColour = midGrey,
		.titleBarButtonBorderColour = UTFT::fromRGB(80, 80, 80),
		.labelTextColour = white,
		.infoTextColour = white,
		.infoBackColour = veryDarkGrey,
		.defaultBackColour = veryDarkGrey,
		.activeBackColour = red,
		.standbyBackColour = yellow,
		.tuningBackColour = darkGrey,
		.errorTextColour = white,
		.errorBackColour = veryDarkGrey,

		.popupBorderColour = darkGrey,
		.popupBackColour = darkGrey,
		.popupTextColour = white,
		.popupButtonTextColour = white,
		.popupButtonBackColour = veryDarkGrey,
		.popupInfoTextColour = white,
		.popupInfoBackColour = darkGrey,

		.alertPopupBackColour = darkGrey,
		.alertPopupTextColour = white,

		.buttonTextColour = white,
		.buttonPressedTextColour = white,
		.buttonTextBackColour = midGrey,
		.buttonImageBackColour = grey,
		.buttonGradColour = 0,	//UTFT::fromRGB(8, 4, 8),
		.buttonPressedBackColour = grey,
		.buttonPressedGradColour = 0,	//UTFT::fromRGB(8, 8, 8),
		.buttonBorderColour = midGrey,
		.homedButtonBackColour = midGrey,
		.notHomedButtonBackColour = orange,
		.pauseButtonBackColour = darkOrange,
		.resumeButtonBackColour = darkYellow,
		.resetButtonBackColour = darkRed,

		.progressBarColour = midGrey,
		.progressBarBackColour = veryDarkGrey,
		.stopButtonTextColour = white,
		.stopButtonBackColour = red,
		.coordBoxTextColour = UTFT::fromRGB(108, 108, 108),
		.coordBoxValueColour = white,
		.coordBoxBackColour = UTFT::fromRGB(28, 28, 31),
		.ctrlMoveArrowBackColour = black,
		.ctrlMoveArrowPressedBorderColour = UTFT::fromRGB(0, 138, 252),
		.ctrlMoveArrowBorderColour = UTFT::fromRGB(43, 43, 43)
	}
};

#endif

// End

