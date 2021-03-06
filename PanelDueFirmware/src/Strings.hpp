/*
 * Strings.hpp
 *
 *  Created on: 27 Feb 2017
 *      Author: David
 *
 * The encoding used for this file must be UTF-8 to ensure that accented characters are displayed correctly.
 */

#ifndef SRC_STRINGS_HPP_
#define SRC_STRINGS_HPP_

#include "ecv.h"
#undef array
#undef result
#undef value
#include "UserInterfaceConstants.hpp"

#define CSTRING const char * const _ecv_array
#define Newline			"\n"
#define DegreeSymbol	"\u00B0"

constexpr unsigned int NumLanguages = 5 + USE_CYRILLIC_CHARACTERS;
constexpr unsigned int NumStatusStrings = 14;

struct StringTable
{
	// Language name
	CSTRING languageName;

	// Main page strings
	CSTRING control;
	CSTRING workplaces;
	CSTRING aux;
	CSTRING print;
	CSTRING console;
	CSTRING setup;
	CSTRING current;
	CSTRING active;
	CSTRING standby;
	CSTRING move;
	CSTRING extrusion;
	CSTRING macro;
	CSTRING files;
	CSTRING stop;
	CSTRING coordinates;
	CSTRING machine;

	// Control page
	CSTRING manualctrl;
	CSTRING home;

	// Workplaces page
	CSTRING setZero;
	CSTRING gotoZero;

	// Aux page
	CSTRING coolant;
	CSTRING vacuum;
	CSTRING spindle;
	CSTRING on;
	CSTRING off;
	CSTRING rpm;

	// Print page
	CSTRING extruderPercent;
	CSTRING speed;
	CSTRING fan;
	CSTRING timeRemaining;
	CSTRING file;
	CSTRING filament;
	CSTRING layer;
	CSTRING notAvailable;
	CSTRING pause;
	CSTRING babystep;
	CSTRING resume;
	CSTRING cancel;
	CSTRING reprint;
	CSTRING resimulate;
	CSTRING set;

	// Setup page
	CSTRING volume;
	CSTRING calibrateTouch;
	CSTRING mirrorDisplay;
	CSTRING invertDisplay;
	CSTRING theme;
	CSTRING brightnessDown;
	CSTRING brightnessUp;
	CSTRING saveSettings;
	CSTRING clearSettings;
	CSTRING saveAndRestart;
	CSTRING infoTimeout;
	CSTRING screensaverAfter;
	CSTRING babystepAmount;
	CSTRING feedrate;
	CSTRING defMoveSteps;

	// Misc
	CSTRING confirmFactoryReset;
	CSTRING confirmFileDelete;
	CSTRING confirmFileStart;
	CSTRING areYouSure;
	CSTRING touchTheSpot;
	CSTRING moveHead;
	CSTRING extrusionAmount;
	CSTRING extrusionSpeed;
	CSTRING extrude;
	CSTRING retract;
	CSTRING babyStepping;
	CSTRING currentZoffset;
	CSTRING message;
	CSTRING messages;
	CSTRING firmwareVersion;
	CSTRING response;

	// File popup
	CSTRING filesOnCard;
	CSTRING macros;
	CSTRING error;
	CSTRING accessingSdCard;
	CSTRING fileName;
	CSTRING fileSize;
	CSTRING layerHeight;
	CSTRING objectHeight;
	CSTRING filamentNeeded;
	CSTRING generatedBy;
	CSTRING lastModified;
	CSTRING estimatedPrintTime;
	CSTRING simulatedPrintTime;
	CSTRING simulate;

	// Printer status strings
	CSTRING statusValues[NumStatusStrings];

	// Colour theme names
	CSTRING colourSchemeNames[NumColourSchemes];

	// Display dimmer types
	CSTRING displayDimmingNames[(unsigned int)DisplayDimmerType::NumTypes];

	CSTRING heaterCombineTypeNames[(unsigned int)HeaterCombineType::NumTypes];

};

const StringTable LanguageTables[NumLanguages] =
{
	// English
	{
		// ISO-639.1 language code
		"en",

		// Main page strings
		"Control",
		"Workplaces",
		"Aux",
		"Job",
		"Console",
		"Setup",
		"Current" THIN_SPACE DEGREE_SYMBOL "C",
		"Active" THIN_SPACE DEGREE_SYMBOL "C",
		"Standby" THIN_SPACE DEGREE_SYMBOL "C",
		"Move",
		"Extrusion",
		"Macros",
		"Files",
		"STOP",
		"Coordinates",
		"Machine",

		// Control page
		"Manual Control",
		"Send to Home",

		// Workplaces page
		"Set to 0",
		"Go to 0",

		// Aux page
		"Coolant",
		"Vacuum",
		"Spindle",
		"On",
		"Off",
		" rpm",

		// Print page
		"Extruder" THIN_SPACE "%",
		"Speed ",							// note space at end
		"Fan ",								// note space at end
		"Time left: ",
		"file ",							// note space at end
		", filament ",						// note space at end
		", layer ",							// note space at end
		"n/a",
		"Pause",
		"Baby step",
		"Resume",
		"Cancel",
		"Run again",
		"Simulate again",
		"Set",

		// Setup page
		"Volume ",							// note space at end
		"Calibrate touch",
		"Mirror display",
		"Invert display",
		"Theme",
		"Brightness -",
		"Brightness +",
		"Save settings",
		"Clear settings",
		"Save & Restart",
		"Info timeout ",					// note space at end
		"Screensaver ",						// note space at end
		"Babystep ",						// note space at end
		"Feedrate ",						// note space at end
		"Def. Step ",						// note space at end

		// Misc
		"Confirm factory reset",
		"Confirm file delete",
		"Start Job?",
		"Are you sure?",
		"Touch the spot",
		"Move head",
		"Extrusion amount (mm)",
		"Speed (mm/s)",
		"Extrude",
		"Retract",
		"Baby stepping",
		"Current Z offset: ",
		"Message",
		"Messages",
		"Panel Due firmware version ",	// note space at end
		"Response",

		// File popup
		"Files on card ",				// note the space on the end
		"Macros",
		"Error ",						// note the space at the end
		" accessing SD card",			// note the space at the start
		"Filename: ",
		"Size: ",
		"Layer height: ",
		"Object height: ",
		"Filament needed: ",
		"Sliced by: ",
		"Last modified: ",
		"Estimated job time: ",
		"Simulated job time: ",
		"Simulate",

		// Printer status strings
		{
			"Connecting",
			"Idle",
			"Working",
			"Halted",
			"Starting up",
			"Paused",
			"Busy",
			"Pausing",
			"Resuming",
			"Firmware upload",
			"Changing tool",
			"Simulating",
			"Standby",
			"Initializing",
		},

		// Theme names
		{
			"CNC ONE Default",
			"Light theme",
			"Dark theme"
		},

		// Display dimming types
		{
			"Never dim",
			"Dim if idle",
			"Always dim"
		},

		// Heater combine types
		{
			"Heat's not comb.",
			"Heaters comb.",
		}
 	},

	// German
	{
		// ISO-639.1 language code
		"de",

		// Main page strings
		"Steuerung",
		"Workplaces",		//TODO:TRANSLATE
		"Aux",		//TODO:TRANSLATE
		"Auftrag",
		"Konsole",
		"Setup",
		"Istwert" THIN_SPACE DEGREE_SYMBOL "C",
		"Aktiv" THIN_SPACE DEGREE_SYMBOL "C",
		"Standby" THIN_SPACE DEGREE_SYMBOL "C",
		"Bewegung",
		"Extrusion",
		"Makros",
		"Files",		//TODO:TRANSLATE
		"STOP",
		"Koordinaten",
		"Maschine",

		// Control page
		"Manual Control",	//TODO:TRANSLATE
		"Send to Home",		//TODO:TRANSLATE

		// Workplaces page
		"Set to 0",		//TODO:TRANSLATE
		"Go to 0",		//TODO:TRANSLATE

		// Aux page
		"Coolant",		//TODO:TRANSLATE
		"Vacuum",		//TODO:TRANSLATE
		"Spindle",		//TODO:TRANSLATE
		"On",			//TODO:TRANSLATE
		"Off",			//TODO:TRANSLATE
		" rpm",			//TODO:TRANSLATE

		// Print page
		"Extruder" THIN_SPACE "%",
		"Tempo ",							// note space at end. Was "Geschwindigkeit " but that is too long to fit in the space available.
		"L??fter ",							// note space at end
		"Restzeit: ",
		"Datei ",							// note space at end
		", Filament ",						// note space at end
		", Layer ",							// note space at end. "Schicht" is too long.
		"n/v",
		"Pause",
		"Einzelschritt",
		"Fortsetzen",
		"Abbrechen",
		"Erneut starten",
		"Erneut simulieren",
		"Set",

		// Setup page
		"Lautst??rke ",						// note space at end
		"Touch kalibrieren",
		"Anzeige spiegeln",
		"Anzeige umkehren",
		"Darstellung",
		"Beleuchtung  -",
		"Beleuchtung  +",
		"Einstllgen sichern",
		"Werks-Reset",
		"Sichern & Reboot",
		"Info timeout ",					// note space at end
		"Screensaver ",						// note space at end
		"Babystep ",						// note space at end
		"Feedrate ",						// note space at end
		"Def. Step ", //TODO:TRANSLATE		// note space at end

		// Misc
		"Alle Einstellungen zur??cksetzen",
		"Die Datei wird gel??scht",
		"Start Job?",	///TODO:TRANSLATE
		"Sind sie sicher?",
		"Bitte auf den Punkt tippen",
		"Kopf bewegen",
		"Extrusionsmenge (mm)",
		"Geschwindigkeit (mm/s)",
		"Extrudieren",
		"Zur??ckziehen",
		"Einzelschritte",
		"Aktueller Z-Versatz: ",
		"Nachricht",
		"Nachrichten",
		"Panel Due Firmwareversion ",	// note space at end
		"Antwort",

		// File popup
		"Dateien auf Karte ",			// note the space on the end
		"Makros",
		"Fehler ",						// note the space at the end
		" beim Zugriff auf SD-Karte",	// note the space at the start
		"Dateiname: ",
		"Gr????e: ",
		"Schichth??he: ",
		"Objekth??he: ",
		"Ben??tigtes Filament: ",
		"Erzeugt mit: ",
		"Letzte ??nderung: ",
		"Gesch??tzte Dauer: ",
		"Errechnete Dauer: ",
		"Simulieren",

		// Printer status strings
		{
			"Verbinde",
			"Leerlauf",
			"Arbeitet",
			"Angehalten",
			"Starte",
			"Pausiert",
			"Besch??ftigt",
			"Pausiere",
			"Fortsetzen",
			"Firmware-Upload",
			"Wechsle Tool",
			"Simuliert",
			"Stand-by"
		},

		// Theme names
		{
			"CNC ONE Standard",
			"Anzeige hell",
			"Anzeige dunkel"
		},

		// Display dimming types
		{
			"Dimmen aus",
			"Dim bei idle",				// shortened due to space limitations, ideally "Nur im Standby dimmen"
			"Dimmen ein"
		},

		// Heater combine types
		{
			"Heat's not comb.",
			"Heaters comb.",
		}
	},

	// French
	{
		// ISO-639.1 language code
		"fr",

		// Main page strings
		"Contr??le",
		"Workplaces",		//TODO:TRANSLATE
		"Aux",		//TODO:TRANSLATE
		"Job",	//TODO:TRANSLATE
		"Console",
		"Installation",
		"Actuel" THIN_SPACE DEGREE_SYMBOL "C",
		"Actif" THIN_SPACE DEGREE_SYMBOL "C",
		"Standby" THIN_SPACE DEGREE_SYMBOL "C",
		"Mouvement",
		"Extrusion",
		"Macros",
		"Files",		//TODO:TRANSLATE
		"ARR??T",
		"Coordonn??es",
		"Machine",		//TODO:TRANSLATE

		// Control page
		"Manual Control",	//TODO:TRANSLATE
		"Send to Home",		//TODO:TRANSLATE

		// Workplaces page
		"Set to 0",		//TODO:TRANSLATE
		"Go to 0",		//TODO:TRANSLATE

		// Aux page
		"Coolant",		//TODO:TRANSLATE
		"Vacuum",		//TODO:TRANSLATE
		"Spindle",		//TODO:TRANSLATE
		"On",			//TODO:TRANSLATE
		"Off",			//TODO:TRANSLATE
		" rpm",			//TODO:TRANSLATE

		// Print page
		"Extrudeuse" THIN_SPACE "%",
		"Vitesse ",								// note space at end
		"Ventilo ",								// note space at end. "Ventilateur 0%" was too long to fit.
		"Temps Restant: ",
		"Fichier ",								// note space at end
		", filament ",							// note space at end
		", couche ",							// note space at end
		"n/a",
		"Pause",
		"Baby step",
		"Reprise",
		"Annuler",
		"Run again",
		"Simulate again",
		"Set",

		// Setup page
		"Volume ",								// note space at end
		"Calibrer touch",
		"Affichage en n??gatif",
		"Inverser affichage",
		"Th??me",
		"Luminosit?? -",
		"Luminosit?? +",
		"Sauver param??tres",
		"Effacer param??tres",
		"Sauvegarde & Red??marrage",
		"Info timeout ",						// note space at end
		"Screensaver ",							// note space at end
		"Babystep ",							// note space at end
		"Feedrate ",							// note space at end
		"Def. Step ", //TODO:TRANSLATE		// note space at end

		// Misc
		"Confirmer le r??initialisation de l'imprimante",
		"Confirm suppression fichier",
		"Start Job?",	///TODO:TRANSLATE
		"Vous ??tes s??re?",
		"Appuyer sur le point",
		"Mouvement de la  t??te",
		"Quantit?? de Mati??re extrud??e (mm)",
		"Vitesse (mm/s)",
		"Extruder",
		"Retracter",
		"Baby stepping",
		"d??calage Z courant : ",
		"Message",
		"Messages",
		"Version du firmware du Panel Due ",	// note space at end
		"R??ponse",

		// File popup
		"Fichier sur carte ",					// note the space on the end
		"Macros",
		"Erreur ",								// note the space at the end
		" acc??s SD card en cours",				// note the space at the start
		"Nom du fichier : ",
		"Taille : ",
		"Hauteur de couche: ",
		"Hauteur de l'objet: ",
		"Filament requis: ",
		"Sliced par: ",
		"Derni??re modification: ",
		"Temps d'impression estim??: ",
		"Temps d'impression simul??: ",
		"Simuler",

		// Printer status strings
		{
			"Liaison en cours",					// "Connexion en cours" was too long
			"Au repos",
			"Working",		//TODO:TRANSLATE
			"Arr??t",
			"D??marrage",
			"Pause",
			"Occup??"
			"Pause",
			"Reprise",
			"Flasher firmware",
			"Changer outil",
			"Simuler",
			"En veille"
		},

		// Theme names
		{
			"CNC ONE d??faut",
			"Fond Blanc",
			"Fond Noir 2"
		},

		// Display dimming types
		{
			"Jamais Dim",
			"Idle Dim",
			"Toujours Dim"
		},

		// Heater combine types
		{
			"Heat's not comb.",
			"Heaters comb.",
		}
	},

	// Spanish
	{
		// ISO-639.1 language code
		"es",

		// Main page strings
		"Control",
		"Workplaces",		//TODO:TRANSLATE
		"Aux",		//TODO:TRANSLATE
		"Job",	//TODO:TRANSLATE
		"Consola",
		"Configuraci??n",
		"Actual" THIN_SPACE DEGREE_SYMBOL "C",
		"Activo" THIN_SPACE DEGREE_SYMBOL "C",
		"Esperando" THIN_SPACE DEGREE_SYMBOL "C",
		"Mover",
		"Extrusi??n",
		"Macros",
		"Files",		//TODO:TRANSLATE
		"PARADA",							// It could also be STOP, both are OK
		"Coordenadas",
		"Machine",		//TODO:TRANSLATE

		// Control page
		"Manual Control",	//TODO:TRANSLATE
		"Send to Home",		//TODO:TRANSLATE

		// Workplaces page
		"Set to 0",		//TODO:TRANSLATE
		"Go to 0",		//TODO:TRANSLATE

		// Aux page
		"Coolant",		//TODO:TRANSLATE
		"Vacuum",		//TODO:TRANSLATE
		"Spindle",		//TODO:TRANSLATE
		"On",			//TODO:TRANSLATE
		"Off",			//TODO:TRANSLATE
		" rpm",			//TODO:TRANSLATE

		// Print page
		"Extrusor" THIN_SPACE "%",
		"Veloc. ",							// note space at end. "Velocidad" is too long.
		"Ventil. ",							// note space at end. "Ventilador" is too lonh.
		"Tiempo restante: ",
		"archivo ",							// note space at end
		", filamento ",						// note space at end
		", capa ",							// note space at end
		"n/d",								// Not available / no disponible
		"Pausa",
		"Micro paso",						// Literal translation of baby step it's very odd in spanish...
		"Resumir",
		"Cancelar",
		"Run again",
		"Simulate again",
		"Fijar",							// "Establecer" would be more correct, but it's longer.

		// Setup page
		"Volumen ",							// note space at end
		"Calibrar toque",					// this one is tricky because "touch" is very known in regard to screens...
		"Espejar pantalla",
		"Invertir pantalla",
		"Tema",
		"Brillo -",
		"Brillo +",
		"Guardar par??metros",
		"Borrar par??metros",
		"Guardar y Reiniciar",
		"Info timeout ",					// note space at end
		"Screensaver ",						// note space at end
		"Babystep ",						// note space at end
		"Feedrate ",						// note space at end
		"Def. Step ", //TODO:TRANSLATE		// note space at end

		// Misc
		"Confirma restablecimiento de f??brica",
		"Confirma borrar archivo",
		"Start Job?",	///TODO:TRANSLATE
		"Est?? seguro?",
		"Tocar el punto",
		"Mover cabezal",
		"Cantidad de extrusi??n (mm)",
		"Velocidad (mm/s)",
		"Extruir",
		"Retraer",
		"Micro paso",
		"Separaci??n actual de Z: ",
		"Mensaje",
		"Mensajes",
		"Panel Due versi??n de firmware ",	// note space at end
		"Respuesta",

		// File popup
		"Archivos en la tarjeta ",			// note the space on the end
		"Macros",
		"Error ",							// note the space at the end
		" accediendo a la tarjeta SD",		// note the space at the start
		"Nombre de archivo: ",
		"Tama??o: ",
		"Altura de capa: ",
		"Altura de objeto: ",
		"Filamento necesario: ",
		"Procesado por: ",					// there is no translation in spanish for this meaning, so I proposed to use "processed by" which is understandable
		"??ltima modificaci??n: ",
		"Tiempo estimado de impresi??n: ",
		"Tiempo de impresi??n simulado: ",
		"Simular",

		// Printer status strings
		{
			"conexi??n",
			"en espera",					// it's more frequently use "en espera" than "ocioso", it makes more sense for a machine
			"Working",		//TODO:TRANSLATE
			"detuvo",
			"empezando",
			"pausado",
			"ocupado",
			"pausando",
			"reanudando",
			"carga del firmware",
			"herramienta de cambio",
			"simulando",
			"en espera"
		},

		// Theme names
		{
			"CNC ONE defecto",
			"Claro",
			"Oscuro"
		},

		// Display dimming types
		{
			"Nunca Atenuar",
			"Atenuar en espera",
			"Siempre Atenuar",
		},

		// Heater combine types
		{
			"Heat's not comb.",
			"Heaters comb.",
		}
	},

	// Italian
	{
		// ISO-639.1 language code
		"it",

		// Main page strings
		"Controlla",
		"Workplaces",		//TODO:TRANSLATE
		"Aux",		//TODO:TRANSLATE
		"Job",	//TODO:TRANSLATE
		"Console",
		"Configura",
		"Corrente" THIN_SPACE DEGREE_SYMBOL "C",
		"Attiva" THIN_SPACE DEGREE_SYMBOL "C",
		"Standby" THIN_SPACE DEGREE_SYMBOL "C",
		"Muovi",
		"Estrusione",
		"Macros",
		"Files",		//TODO:TRANSLATE
		"FERMA",
		"Coordinate",
		"Machine",		//TODO:TRANSLATE

		// Control page
		"Manual Control",	//TODO:TRANSLATE
		"Send to Home",		//TODO:TRANSLATE

		// Workplaces page
		"Set to 0",		//TODO:TRANSLATE
		"Go to 0",		//TODO:TRANSLATE

		// Aux page
		"Coolant",		//TODO:TRANSLATE
		"Vacuum",		//TODO:TRANSLATE
		"Spindle",		//TODO:TRANSLATE
		"On",			//TODO:TRANSLATE
		"Off",			//TODO:TRANSLATE
		" rpm",			//TODO:TRANSLATE

		// Print page
		"Estrusore" THIN_SPACE "%",
		"Velocit?? ",							// note space at end
		"Ventola ",								// note space at end
		"Tempo rimanente: ",
		"file ",							// note space at end
		", filamento ",						// note space at end
		", layer ",							// note space at end
		"n/a",
		"Pausa",
		"Baby step",
		"Riprendi",
		"Cancella",
		"Stampa di nuovo",
		"Simula di nuovo",
		"Imposta",

		// Setup page
		"Volume ",							// note space at end
		"Calibra touch",
		"Specchia schermo",
		"Inverti schermo",
		"Tema",
		"Luminosit?? -",
		"Luminosit?? +",
		"Salva impostazioni",
		"Resetta impostazioni",
		"Salva & Riavvia",
		"Info timeout ",					// note space at end
		"Salvaschermo ",					// note space at end
		"Babystep ",						// note space at end
		"Feedrate ",						// note space at end
		"Def. Step ", //TODO:TRANSLATE		// note space at end

		// Misc
		"Conferma reset impostazioni",
		"Confirma eliminazione file",
		"Start Job?",	///TODO:TRANSLATE
		"Sei sicuro?",
		"Tocca il punto",
		"Muovi testa",
		"Quantit?? estrusione (mm)",
		"Velocit?? (mm/s)",
		"Estrudi",
		"Retrai",
		"Baby stepping",
		"Z offset corrente: ",
		"Messaggio",
		"Messaggi",
		"Versione firmware Panel Due ",	// note space at end
		"Risposta",

		// File popup
		"File su card ",				// note the space on the end
		"Macro",
		"Errore ",						// note the space at the end
		" accedendo alla SD card",			// note the space at the start
		"Nome file: ",
		"Dimensione: ",
		"Altezza layer: ",
		"Altezza oggetto: ",
		"Filamento necessario: ",
		"Slice effettuato con: ",
		"Ultima modifica: ",
		"Tempo di stampa stimato: ",
		"Tempo di stampa simulato: ",
		"Simula",

		// Printer status strings
		{
			"Connettendo",
			"Idle",
			"Working",		//TODO:TRANSLATE
			"Fermato",
			"Avviando",
			"Pausa",
			"Occupato",
			"Pausa",
			"Riprendendo",
			"Caricamento firmware",
			"Cambiando tool",
			"Simulando",
			"Standby",
			"Inizializzando",
		},

		// Theme names
		{
			"CNC ONE predefinito",
			"Tema chiaro",
			"Tema scuro"
		},

		// Display dimming types
		{
			"Non attenuare",
			"Attenua se idle",
			"Attenua sempre"
		},

		// Heater combine types
		{
			"Heat's not comb.",
			"Heaters comb.",
		}
 	},

#if USE_CYRILLIC_CHARACTERS
	// Ukrainian
	{
		"uk",

		// Main page strings
		"????????????????",
		"????????",
		"??????????????",
		"????????????????????????",
		"??????????????" THIN_SPACE DEGREE_SYMBOL "C",
		"??????????????" THIN_SPACE DEGREE_SYMBOL "C",
		"??????????????????" THIN_SPACE DEGREE_SYMBOL "C",
		"??????",
		"??????????????????",
		"??????????",
		"????????",

		// Print page
		"??????????????????" THIN_SPACE "%",
		"?????????????????? ",             // note space at end
		"???????????????????? ",               // note space at end
		"???????????????????? ????????: ",
		"???????? ",              // note space at end
		", ???????????????? ",            // note space at end
		", ?????? ",             // note space at end
		"-",
		"??????????",
		"??????????????????",
		"??????????????????????",
		"??????????????????",
		"?????????????????? ??????????",
		"???????????????????? ??????????",
		"????????????????????",

		// Setup page
		"???????????????? ",              // note space at end
		"????????????????. ??????????",
		"???????????????????????? ????????.",
		"?????????????????????? ??????????.",
		"????????",
		"???????????????????? -",
		"???????????????????? +",
		"???????????????? ????????????.",
		"?????????????? ????????????.",
		"???????????????? & ??????????????????????????????",
		"???????????????????? ?????? ???????????????????? ???? ???????????????????? ",          // note space at end
		"???????????????? ",           // note space at end
		"?????????????????? ",            // note space at end
		"???????????? ",            // note space at end

		// Misc
		"?????????????????????? ???????????????? ???? ???????????????????? ??????????????????????",
		"?????????????????????? ?????????????????? ??????????",
		"???? ?????????????????",
		"???????????????????????? ???? ??????????",
		"???????????? ??????????????",
		"?????????????????? ?????????????????? (????/??)",
		"?????????????????? (????/??)",
		"????????????????????????",
		"??????????????",
		"??????????????????",
		"?????????????? ???????????????? Z: ",
		"????????????????????????",
		"????????????????????????",
		"???????????? ???????????????? Panel Due ",  // note space at end
		"??????????????????",

		// File popup
		"?????????? ???? ???????????? ",       // note the space on the end
		"??????????????",
		"?????????????? ",           // note the space at the end
		" ?????????????? ???? SD-????????????",     // note the space at the start
		"????'?? ??????????: ",
		"????????????: ",
		"???????????? ????????: ",
		"???????????? ????'????????t: ",
		"???????????????? ????????????????: ",
		"?????????? ????????????: ",
		"???????????????? ??????????????: ",
		"???????????????????? ?????? ??????????: ",
		"???????????????????????? ?????? ??????????: ",
		"????????????????????",

		// Printer status strings
		{
			"??????????????????????",
			"??????????????????????????",
			"????????????",
			"????????????????",
			"????????????",
			"??????????????????",
			"????????????????",
			"??????????????",
			"??????????????????",
			"???????????????????????? ????????????????",
			"???????????? ????????????????????",
			"??????????????",
			"??????????????????",
			"??????????????????????????",
		},

		// Theme names
		{
			"???????????? ????????",
			"?????????? ???????? 1",
			"?????????? ???????? 2"
		},

		// Display dimming types
		{
			"???????????? ???? ????????????????",
			"???????????????? ???? ??????????????????????????",
			"???????????? ????????????????"
		},

		// Heater combine types
		{
			"Heat's not comb.",
			"Heaters comb.",
		}
	}
#endif
};

#endif /* SRC_STRINGS_HPP_ */
