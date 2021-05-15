# Version 3.2.11
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2 or later.

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.

## Bug fixes:
* When multiple tools used the same extruder or fan only the first tool using it was considered
* When multiple beds/chambers used the same heater status was only updated for the first one

# Version 3.2.10
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2 or later.
- Flashing this release will reset the configuration to defaults

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
    
## Changed:
* Added Italian language - thanks @brisma
* If no tool is selected show fan speed of Fan 0
* Add a new setting so multiple heaters of one tool can be combined into one (as it was until 3.2.6)

## Bug fixes:
* Try a few graphic glitches

# Version 3.2.9
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2 or later.

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
    
## Changed:
* Removed obsolete code
* Replaced custome code by C-standard impl

## Bug fixes:
* Fix heater state of bed heater being temporarily applied to all but the first tool
* When STOP button was pressed PanelDue never really got into "Initializing" state again
* When OM key "tools" updated all tools would temporarily show 0.0°C as current temp

# Version 3.2.8
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2 or later.

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
    
## Changed:
* Added Ukrainian translation (disabled for now) - thanks vitaliy172
* Removed unused fonts
* Move heater status into bed and chamber only to save some RAM
* Support multiplexed heaters
* Add color gradient to buttons in Dark 1 theme

## Bug fixes:
* Fan used `fans[].actualValue` instead of `fans[].requestedValue`
* Color gradient for heater-fault was broken on Light theme
* Additional bed and heater buttons alwaysed controlled the first bed or chamber respectively
* Extrusion factor could be shown for an element without an extruder
* Active/standby controls for tools with multiple heaters always set all heaters of this tool

# Version 3.2.7
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.

## Changed:
* Fill left screen estate with addtional bed and chamber heaters
* Support tools with multiple heaters
* Reduced flickering while initialization
* Bring minimum and maximum axes count in line with RRF
* Respect spindle minimum RPM

## Bug fixes:
* First bed/chamber/tool/axis could not be removed
* On 4.3" macro shortcut buttons would not show up even if there was enough space left
* If more tools or beds that can be displayed were defined this could lead to illegal memory access
* Fix possible memory leaks in object model representation


# Version 3.2.6
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
- There will be no reliable status updates coming from RepRapFirmware while waiting for heaters to reach temperature (and some other cases) before RRF 3.2-beta3.2.
- Reprint/resimulate button on DSF setups will only work with DSF 3.2-beta5 (or RC1 whatever will be version after beta4)

## Changed:
* Improve data structures to hold the ObjectModel data
* Use more of the common code base from RRFLibraries to get rid of duplicate code

## Bug fixes:
* Fix memory leaks
* Show fan value of current tool instead of hard-coded fan with number 0
* Fix reprint/resimulate button not sending the correct command (3.2.6+1)
* Fix reprint/resimulate button not hiding when mainboard restarts (3.2.6+1)


# Version 3.2.5
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
- There will be no reliable status updates coming from RepRapFirmware while waiting for heaters to reach temperature (and some other cases) before RRF 3.2-beta3.2.
- Reprint/resimulate button on DSF setups will only work with DSF 3.2-beta5 (or RC1 whatever will be version after beta4)

## Changed:
* Tool active/standby temp is now the one from the tool instead of the heater

## Bug fixes:
* Unnecessary refresh for each printer state change
* Forcing an update on a text field could get stuck
* Title in Alert/Message window was hidden
* Reprint/resimulate failed for filenames with more than 40 characters (including path)
* Reprint/resimulate button collided with axes positions on 5"/7" screens
* If a heater was shared between tools/beds/chambers current temp was only updated for the first one displayed
* Homing status was not updated after a reset of the panel
* Screensaver left pixels with the background color of the underlying screen in the corners

# Version 3.2.4
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
- There will be no reliable status updates coming from RepRapFirmware while waiting for heaters to reach temperature (and some other cases) before RRF 3.2-beta3.2.

## New and changed features:
* Add button to reprint/resimulate last file

## Bug fixes:
* For PanelDue v2 the wrong linker script was used resulting in PanelDueFirmware not booting
* After a print/simulation has finished some of the elements partially remained on screen

# Version 3.2.3
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.
- Flashing this release will reset the configuration to defaults

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
- There will be no reliable status updates coming from RepRapFirmware while waiting for heaters to reach temperature (and some other cases) before RRF 3.2-beta3.2.

## New and changed features:
* Sped up intialization phase
* Increased poll rate from 1s to 500ms and add adaptive slow down if too many out-of-buffer occur

## Bug fixes:
* Command input field did not show inserted character


# Version 3.2.2
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.
- Flashing this release will reset the configuration to defaults

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
- There will be no reliable status updates coming from RepRapFirmware while waiting for heaters to reach temperature (and some other cases) before RRF 3.2-beta4.

## New and changed features:
* Babystep amount is configurable from preset values
* When babystep buttons are pressed the value on the screen will be updated immediately and will be overwritten
with the actual value on the next status update (usually these values should be equal anyway)
* Feedrate for move buttons is configuratble from preset values
* PanelDueFirmware does no longer distinguish between responses to `M409` with and without `K` parameter. This prevents
issues if values are moved from live to detail response or vice versa
* Provide interface for RepRapFirmware to reset as well as erase and reset the PanelDue
* Preparations to show more than one bed/one chamber

## Bug fixes:
* Babystepping amount was not initialized

## Bug fixes since 3.2.1:
* Setting babystep amount to the lowest value would invalidate stored settings on next start of PanelDue
* A chamber could steal the second slot and status/temperatures would alternate between the tool and the chamber
* A null pointer dereference could occur when RRF was restarted leading to a reset of PanelDueFirmware
* State "Initializing" was replaced too early by "Idle"
* Fetching the first bed/heater would not filter out invalidated entries
* Under rare cicumstances it could happen that selectin a bed/chamber or setting temperatures for these could
cause a restart of PanelDueFirmware


# Version 3.2.1 - Revoked
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.
- Flashing this release will reset the configuration to defaults

# Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
- There will be no reliable status updates coming from RepRapFirmware while waiting for heaters to reach temperature (and some other cases) before RRF 3.2-beta4.

## New and changed features:
* Babystep amount is configurable from preset values
* When babystep buttons are pressed the value on the screen will be updated immediately and will be overwritten
with the actual value on the next status update (usually these values should be equal anyway)
* Feedrate for move buttons is configuratble from preset values
* PanelDueFirmware does no longer distinguish between responses to `M409` with and without `K` parameter. This prevents
issues if values are moved from live to detail response or vice versa
* Provide interface for RepRapFirmware to reset as well as erase and reset the PanelDue
* Preparations to show more than one bed/one chamber

## Bug fixes:
* Babystepping amount was not initialized

# Version 3.2.0
## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.
- Flashing this release will reset the configuration to defaults

## Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
    - Version 1.0, 1.1 and earlier v2 PanelDue: `ATSAM3S2B` processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
    - Version 2 PanelDue manufactured from August 2016: `ATSAM3S4B` processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
    - Version 3 PanelDue, including all 5i and 7i: `ATSAM4S4B` processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.
- There will be no reliable status updates coming from RepRapFirmware while waiting for heaters to reach temperature (and some other cases) before RRF 3.2-beta3.

## New and changed features:
- This release uses the RepRapFirmware ObjectModel instead of limited status responses
- Support for spindles with current RPM as well as active RPM
- Bed heater will only be shown if it is configured
- Support for chamber heaters (will only show if bed heater + number of tools `<= 6` on 5" and 7" or `<= 4` on 4.3")
- Tools and assigned heaters and extruders can be numbered arbitrarily (e.g. tool 1 can use heater 8 and extruder 2)
- A simple screensaver has been added to help preventing screen burn-in on long-lasting prints
- Tool buttons will reflect the tool status (only "Active" and anything else ("Standby" is displayed as "Off" because it is confusing otherwise)
- Prevent flickering if values did not change

### Changes within the Release Candidate iterations
- Status colors of tools were confusing (because a tool can never go to "off" after being active once) so it only shows "active" or "anything else"
- Extrusion and retraction commands are now a single line to prevent being interleaved by other commands
- Screensaver is now a popup to better interact with existing or incoming popups
- No longer fetch detailed M409 for Fans or Sensors (as they are currently not required)
- Only request null-flag for state request

## Bug fixes
- Axes will be shown as they are configured, i.e. if configured axes are XYZA then PanelDue will display them like this instead of XYZU

### Bug Fixes within the Release Candidate itereations
- In some cases setting a tool's heater would instead the heatbed temperature
- Chamber and heatbed icons did not change colors according to their state
- It was not possible to disable the chamber heater by tapping the chamber button
- Move popup buttons were none-functional
- Commands entered via on-screen-keyboard were not echoed into the text field
- Screensaver timeout select pop-up would not disappear when clicking anything but "Set" or a tab button
- Extrusion factor was not always targeting the correct extruder
- Extrusion factor controls were not hidden if amount of tools was decreased
- Bed and chamber controls were not hidden if they were removed from config
- If a JSON key path was too long it would result in an endless fetch-loop
- Message box was not closed on PanelDue if closed e.g. in DWC
- Fix some fields not being hidden correctly (possible screensaver fix)

# Version 3.2-RC4
## Upgrade Notes and Limitations
See 3.2-RC2

## Changes since RC3+1:
- Only request null-flag for state request

## Bug fixes:
- Fix some fields not being hidden correctly (possible screensaver fix)

# Version 3.2-RC3+1

## Bug fixes:
- Message box was not closed on PanelDue if closed e.g. in DWC

# Version 3.2-RC3

## Upgrade Notes and Limitations
See 3.2-RC2

## Changes since RC2
- Extrusion and retraction commands are now a single line to prevent being interleaved by other commands
- Screensaver is now a popup to better interact with existing or incoming popups
- No longer fetch detailed M409 for Fans or Sensors (as they are currently not required)

## Bug Fixes since RC2:
- Screensaver timeout select pop-up would not disappear when clicking anything but "Set" or a tab button
- Extrusion factor was not always targeting the correct extruder
- Extrusion factor controls were not hidden if amount of tools was decreased
- Bed and chamber controls were not hidden if they were removed from config
- If a JSON key path was too long it would result in an endless fetch-loop

# Version 3.2-RC2

## Upgrade Notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.

## Limitations
Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip.
- Version 1.0, 1.1 and earlier v2 PanelDue: ATSAM3S2B processor (64MHz, 32kb RAM, 128kB flash) - these are the ones that the new firmware probably won't run on.
- Version 2 PanelDue manufactured from August 2016: ATSAM3S4B processor (64MHz, 48kb RAM, 256kb flash). Will run the new firmware, but not as fast as version 3 will.
- Version 3 PanelDue, including all 5i and 7i: ATSAM4S4B processor, 120MHz, 64kB RAM, 256kb flash. Will run the new firmware.

# Changes since RC1:
- Status colors of tools were confusing (because a tool can never go to "off" after being active once) so it only shows "active" or "anything else"

## Bug fixes since RC1:
- In some cases setting a tool's heater would instead the heatbed temperature
- Chamber and heatbed icons did not change colors according to their state
- It was not possible to disable the chamber heater by tapping the chamber button
- Move popup buttons were none-functional
- Commands entered via on-screen-keyboard were not echoed into the text field

# Version 3.2-RC1

## Upgrade notes:
- This release is compatible with RepRapFirmware 3.2-beta1 or later. It will partially work with RepRapFirmware 3.1.1 but not with any older version.
- Flashing this release will reset the configuration to defaults

## Limitations
- Due to the lack of RAM this build will not run on version 1 or early version 2 PanelDue boards that use the `ATSAM3S2B` chip. It  is expected to work on later
version 2 PanelDue boards using the `ATSAM3S4B` chip. If you have a PanelDue using the `ATSAM3S2B` chip, we suggest you replace the board by
a version 3 PanelDue board, which can drive your existing LCD.

## New and changed features:
- This release uses the RepRapFirmware ObjectModel instead of limited status responses
- Support for spindles with current RPM as well as active RPM
- Bed heater will only be shown if it is configured
- Support for chamber heaters (will only show if bed heater + number of tools <= 6)
- Tools and assigned heaters and extruders can be numbered arbitrarily (e.g. tool 1 can use heater 8 and extruder 2)
- A simple screensaver has been added to help preventing screen burn-in on long-lasting prints
- Tool buttons will reflect the tool status
- Prevent flickering if values did not change

## Bug fixes
- Axes will be shown as they are configured, i.e. if configured axes are XYZA then PanelDue will display them like this instead of XYZU

Version 1.20
------------

Upgrade notes:
- This release is compatible with RepRapFirmware 1.20 and 1.21RC versions. It will not work with older versions of RepRapFirmware.

New and changed features:
- The first 4 macros are displayed on the Control page unless there are too many tools configured to leave room
- Macro file names can be prefixed by e.g. "1_" to control the display order, as in DWC
- Custom splash screens can be added by appending the compressed splash screen image to the end of the 'nologo' version of the binary
- The splash screen can now be cancelled by touching the display
- Larger brightness up/down steps are used
- The display dims after 1 minute of inactivity. Dimming can be disabled.
- The "Simulating" state reported by 1.21RC3 RepRapFirmware is recognised
- The babystepping increment is reduced to 0.02mm
- Czech language is supported, but not displaying correctly on 4.3" build
- Characters from U_0x0100 to U+0x1FF are now supported, but not displaying correctly on 4.3" build
- Corrected German translation of "Invert display"
- "Speed" is not longer translated to German because the translation was too long to fit
- Pressing the Control button now closes popups on the Control page
- The standby bed temperature can now be set
- Added support for M291 message boxes with optional OK/Cancel buttons and Z adjustment
- Added a shifted mode to the keyboard
- Added an option to simulate printing a file
- Added support for CPLD 7" display (thanks bluesign2k)
- Filenames in GCode commands sent to the host are always quoted, so that filenames containing parentheses or semicolon can be used
- Configuration changes in the geometry etc. of the host are now picked up, normally within 10 seconds of being made

Bug fixes:
- The extrusion factor adjustment buttons always adjusted the factor for extruder 0
- Corrected colours for extrusion popup (thanks chandler767)

Internal changes:
- Use later version of gcc
- Up/down/left/right arrow icons replaced by characters to save flash memory space
- Keyboard generation reworked to save flash memory space

