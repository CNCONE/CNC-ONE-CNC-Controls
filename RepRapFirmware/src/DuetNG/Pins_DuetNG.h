#ifndef PINS_DUETNG_H__
#define PINS_DUETNG_H__

// Pins definition file for Duet 2 WiFi/Ethernet
// This file is normally #included by #including RepRapFirmware.h, which includes this file

#define BOARD_NAME_WIFI			"Duet 2 WiFi"
#define BOARD_NAME_ETHERNET		"Duet 2 Ethernet"
#define BOARD_NAME_SBC			"Duet 2 + SBC"
#define BOARD_SHORT_NAME_WIFI		"2WiFi"
#define BOARD_SHORT_NAME_ETHERNET	"2Ethernet"
#define BOARD_SHORT_NAME_SBC		"2SBC"

#if defined(USE_SBC)

#define FIRMWARE_NAME			"RepRapFirmware for Duet 2 SBC"
#define DEFAULT_BOARD_TYPE	 	BoardType::Duet2SBC_10
#define IAP_FIRMWARE_FILE		"Duet2Firmware_SBC.bin"
#define IAP_UPDATE_FILE_SBC		"Duet2_SBCiap32_SBC.bin"

constexpr size_t NumFirmwareUpdateModules = 5;		// 0 = mainboard, 4 = PanelDue, values in between unused

#else

#define FIRMWARE_NAME			"RepRapFirmware for CNC ONE WiFi"
#define DEFAULT_BOARD_TYPE	 	BoardType::DuetWiFi_10
#define IAP_FIRMWARE_FILE		"CNCONECombinedFirmware.bin"
#define IAP_UPDATE_FILE			"iap4e.bin"	// using the same IAP file for both Duet WiFi and Duet Ethernet
#define WIFI_FIRMWARE_FILE		"CNCONE_WiFiServer.bin"

constexpr size_t NumFirmwareUpdateModules = 5;		// 4 modules, plus one for manual upload to WiFi module (module 2 is now unused)

#endif

constexpr uint32_t IAP_IMAGE_START = 0x20018000;	// IAP is loaded into the last 32kb of RAM

// Features definition
#define HAS_LWIP_NETWORKING		0

#if defined(USE_SBC)
# define HAS_WIFI_NETWORKING	0
# define HAS_W5500_NETWORKING	0
# define HAS_LINUX_INTERFACE	1
# define HAS_MASS_STORAGE		0
#else
# define HAS_WIFI_NETWORKING	1
# define HAS_W5500_NETWORKING	0
# define HAS_LINUX_INTERFACE	0
#endif

#define HAS_CPU_TEMP_SENSOR		1
#if defined(USE_SBC)
# define HAS_HIGH_SPEED_SD		0
#else
# define HAS_HIGH_SPEED_SD		1
#endif
#define SUPPORT_TMC2660			0
#define TMC2660_USES_USART		0
#define HAS_VOLTAGE_MONITOR		1
#define ENFORCE_MAX_VIN			1
#define HAS_VREF_MONITOR		0
#define ACTIVE_LOW_HEAT_ON		1

#define SUPPORT_INKJET			0					// set nonzero to support inkjet control
#define SUPPORT_ROLAND			0					// set nonzero to support Roland mill
#if defined(USE_SBC)
# define SUPPORT_SCANNER		0
#else
# define SUPPORT_SCANNER		0					// set zero to disable support for FreeLSS scanners
#endif
#define SUPPORT_LASER			1					// support laser cutters and engravers using G1 S parameter
#define SUPPORT_IOBITS			1					// set to support P parameter in G0/G1 commands
#define SUPPORT_DHT_SENSOR		1					// set nonzero to support DHT temperature/humidity sensors
#define SUPPORT_WORKPLACE_COORDINATES	1			// set nonzero to support G10 L2 and G53..59
#define SUPPORT_12864_LCD		0					// set nonzero to support 12864 LCD and rotary encoder
#define SUPPORT_OBJECT_MODEL	1

#define VARIABLE_NUM_DRIVERS	SUPPORT_12864_LCD	// nonzero means that some pins may only support drivers if not used for other purposes e.g. LCD

#if defined(USE_SBC)
# define SUPPORT_HTTP			0
# define SUPPORT_FTP			0
# define SUPPORT_TELNET			0
#else
# define SUPPORT_HTTP			1
# define SUPPORT_FTP			1
# define SUPPORT_TELNET			1
#endif

#define SUPPORT_ASYNC_MOVES		1
#define ALLOCATE_DEFAULT_PORTS	0
#define TRACK_OBJECT_NAMES		1

#define USE_CACHE				1					// set nonzero to enable the cache
#define USE_MPU					0					// set nonzero to enable the memory protection unit

// The physical capabilities of the machine

constexpr size_t NumDirectDrivers = 6;				// The maximum number of drives supported directly by the electronics
constexpr size_t MaxSmartDrivers = 5;				// The maximum number of smart drivers

constexpr size_t MaxSensors = 32;

constexpr size_t MaxHeaters = 2;					// The maximum number of heaters in the machine
constexpr size_t MaxMonitorsPerHeater = 1;			// The maximum number of monitors per heater

constexpr size_t MaxBedHeaters = 0;
constexpr size_t MaxChamberHeaters = 0;
constexpr int8_t DefaultBedHeater = 0;
constexpr int8_t DefaultE0Heater = 0;				// Index of the default first extruder heater, used only for the legacy status response

constexpr size_t NumThermistorInputs = 2;
constexpr size_t NumTmcDriversSenseChannels = 2;

constexpr size_t MaxZProbes = 4;
constexpr size_t MaxGpInPorts = 10;
constexpr size_t MaxGpOutPorts = 10;

constexpr size_t MinAxes = 3;						// The minimum and default number of axes
constexpr size_t MaxAxes = 6;						// The maximum number of movement axes in the machine, usually just X, Y and Z
constexpr size_t MaxDriversPerAxis = 2;				// The maximum number of stepper drivers assigned to one axis

constexpr size_t MaxExtruders = 1;					// The maximum number of extruders
constexpr size_t NumDefaultExtruders = 0;			// The number of drivers that we configure as extruders by default

constexpr size_t MaxAxesPlusExtruders = 6;

constexpr size_t MaxHeatersPerTool = 1;
constexpr size_t MaxExtrudersPerTool = 1;

constexpr size_t MaxFans = 12;

constexpr unsigned int MaxTriggers = 16;			// Must be <= 32 because we store a bitmap of pending triggers in a uint32_t

constexpr size_t MaxSpindles = 4;					// Maximum number of configurable spindles

constexpr size_t NumSerialChannels = 2;				// The number of serial IO channels not counting the WiFi serial connection (USB and one auxiliary UART)
#define SERIAL_MAIN_DEVICE	SerialUSB
#define SERIAL_AUX_DEVICE	Serial
#define SERIAL_WIFI_DEVICE	Serial1

constexpr Pin UsbVBusPin = PortCPin(22);			// Pin used to monitor VBUS on USB port

#define I2C_IFACE	Wire							// Which TWI interface we use
#define I2C_IRQn	WIRE_ISR_ID						// The interrupt number it uses

constexpr Pin DueXnExpansionStart = 200;			// Pin numbers 200-215 are on the I/O expander
constexpr Pin AdditionalIoExpansionStart = 220;		// Pin numbers 220-235 are on the additional I/O expander

// The numbers of entries in each array must correspond with the values of DRIVES, AXES, or HEATERS. Set values to NoPin to flag unavailability.

// Drives
//constexpr Pin GlobalTmc2660EnablePin = PortCPin(6);	// The pin that drives ENN of all TMC2660 drivers on production boards (on pre-production boards they are grounded)
constexpr Pin ENABLE_PINS[NumDirectDrivers] =
{
	PortDPin(14), PortCPin(9), PortCPin(10), PortCPin(17), PortCPin(25),
	PortDPin(23),
};
constexpr Pin STEP_PINS[NumDirectDrivers] =
{
	PortDPin(6), PortDPin(7), PortDPin(8), PortDPin(5), PortDPin(4),
	PortDPin(2),
};
constexpr Pin DIRECTION_PINS[NumDirectDrivers] =
{	PortDPin(11), PortDPin(12), PortDPin(13), PortAPin(1), PortDPin(9),
	PortDPin(28),
};

// Pin assignments etc. using USART1 in SPI mode
//Usart * const USART_TMC2660 = USART1;
//constexpr uint32_t  ID_TMC2660_SPI = ID_USART1;
//constexpr IRQn TMC2660_SPI_IRQn = USART1_IRQn;
//# define TMC2660_SPI_Handler	USART1_Handler

//constexpr Pin TMC2660MosiPin = PortAPin(22);
//constexpr Pin TMC2660MisoPin = PortAPin(21);
//constexpr Pin TMC2660SclkPin = PortAPin(23);

constexpr uint32_t DefaultStandstillCurrentPercent = 100;					// it's not adjustable on Duet 2

//constexpr Pin DueX_SG = PortEPin(0);										// DueX stallguard detect pin on older DueX boards (was E2_STOP)
//constexpr Pin DueX_INT = PortAPin(17);										// DueX interrupt pin (was E6_STOP)

// Thermistors
constexpr Pin TEMP_SENSE_PINS[NumThermistorInputs] =
{
	NoPin, NoPin,
};

// Thermistor series resistor value in Ohms
constexpr float DefaultThermistorSeriesR = 4700.0;

// Digital pins the 31855s have their select lines tied to
constexpr Pin SpiTempSensorCsPins[] =
	{ NoPin };

// Pin that controls the ATX power on/off
constexpr Pin ATX_POWER_PIN = NoPin; // not supported

// Analogue pin numbers
constexpr Pin PowerMonitorVinDetectPin = PortCPin(4);						// AFE1_AD7/PC4 Vin monitor
#if 0	// the 5V regulator input monitor pin has never been used and may be removed on future PCB revisions
constexpr Pin PowerMonitor5vDetectPin = PortBPin(3);						// AFE1_AD1/PB3 5V regulator input monitor
#endif

constexpr float PowerMonitorVoltageRange = 15.7 * 3.3;						// We use an 51.8:1 voltage divider

//constexpr Pin VssaSensePin = PortBPin(7);

constexpr Pin EmStopDisPin = PortCPin(11);
constexpr Pin EmStopInPin = PortAPin(25);
constexpr Pin axis1almPin = PortDPin(17);
constexpr Pin axis2almPin = PortDPin(19);
constexpr Pin axis3almPin = PortDPin(21);
constexpr Pin axis4almPin = PortDPin(25);
constexpr Pin axis5almPin = PortDPin(27);
constexpr Pin axis6almPin = PortAPin(8);

/*{ PortDPin(16),	PinCapability::read,	"axis1ped" },
{ PortDPin(18),	PinCapability::read,	"axis2ped" },
{ PortDPin(20),	PinCapability::read,	"axis3ped" },
{ PortDPin(24),	PinCapability::read,	"axis4ped" },
{ PortDPin(26),	PinCapability::read,	"axis5ped" },
{ PortAPin(7),	PinCapability::read,	"axis6ped" },*/



// Z probes
constexpr Pin Z_PROBE_PIN = PortCPin(1);									// AFE1_AD4/PC1 Z probe analog input
constexpr Pin Z_PROBE_MOD_PIN = PortCPin(2);
constexpr Pin DiagPin = PortCPin(12); // error LED Pin 44
constexpr bool DiagOnPolarity = true;

// SD cards
constexpr size_t NumSdCards = 1;
constexpr Pin SdCardDetectPins[NumSdCards] = { PortCPin(21) };
constexpr Pin SdWriteProtectPins[NumSdCards] = { NoPin };
constexpr Pin SdSpiCSPins[1] = { NoPin };
constexpr IRQn SdhcIRQn = HSMCI_IRQn;
constexpr uint32_t ExpectedSdCardSpeed = 20000000;

#if SUPPORT_12864_LCD
// The ST7920 datasheet specifies minimum clock cycle time 400ns @ Vdd=4.5V, min. clock width 200ns high and 20ns low.
// This assumes that the Vih specification is met, which is 0.7 * Vcc = 3.5V @ Vcc=5V
// The Duet Maestro level shifts all 3 LCD signals to 5V, so we meet the Vih specification and can reliably run at 2MHz.
// For other electronics, there are reports that operation with 3.3V LCD signals may work if you reduce the clock frequency.
// Displays based on the ST7567 use level shifters because the ST7567 is a 3.3V device.
constexpr uint32_t LcdSpiClockFrequency = 2000000;             // 2.0MHz

constexpr Pin EncoderPinB = PortCPin(7);		// connlcd.3	-> exp2.6
constexpr Pin EncoderPinA = PortAPin(8);		// connlcd.4	-> exp2.8
constexpr Pin LcdNeopixelPin = PortDPin(18);	// connlcd.5	-> exp1.5
constexpr Pin LcdResetPin = PortCPin(28);		// connlcd.6	-> exp1.6
constexpr Pin LcdA0Pin = PortDPin(19);			// connlcd.7	-> exp1.7
constexpr Pin LcdCSPin = PortAPin(25);			// connlcd.8	-> exp1.8
constexpr Pin EncoderPinSw = PortDPin(20);		// connlcd.9	-> exp1.9
constexpr Pin LcdBeepPin = PortDPin(21);		// connlcd.10	-> exp1.10

// Additional spi wiring for FYSETC Mini 12864 display:
// connlcd.2 (gnd)	-> exp1.2
// connsd.1 (+5V)	-> exp1.1
// connsd.2 (gnd)	-> exp2.2
// connsd.3 (SD CS)	-> exp2.7
// connsd.4 (sck)	-> exp2.9
// connsd.5 (mosi)	-> exp2.5
// connsd.6 (miso)	-> exp2.10
#endif

// Shared SPI definitions
#define USART_SPI		1
#define USART_SSPI		USART0
#define ID_SSPI			ID_USART0

// Enum to represent allowed types of pin access
// We don't have a separate bit for servo, because Duet PWM-capable ports can be used for servos if they are on the Duet main board
enum class PinCapability: uint8_t
{
	// Individual capabilities
	read = 1,
	ain = 2,
	write = 4,
	pwm = 8,

	// Combinations
	ainr = 1|2,
	rw = 1|4,
	wpwm = 4|8,
	rwpwm = 1|4|8,
	ainrw = 1|2|4,
	ainrwpwm = 1|2|4|8
};

constexpr inline PinCapability operator|(PinCapability a, PinCapability b) noexcept
{
	return (PinCapability)((uint8_t)a | (uint8_t)b);
}

// Struct to represent a pin that can be assigned to various functions
// This can be varied to suit the hardware. It is a struct not a class so that it can be direct initialised in read-only memory.
struct PinEntry
{
	Pin GetPin() const noexcept { return pin; }
	PinCapability GetCapability() const noexcept { return cap; }
	const char* GetNames() const noexcept { return names; }

	Pin pin;
	PinCapability cap;
	const char *names;
};

// List of assignable pins and their mapping from names to MPU ports. This is indexed by logical pin number.
// The names must match user input that has been concerted to lowercase and had _ and - characters stripped out.
// Aliases are separate by the , character.
// If a pin name is prefixed by ! then this means the pin is hardware inverted. The same pin may have names for both the inverted and non-inverted cases,
// for example the inverted heater pins on the expansion connector are available as non-inverted servo pins on a DueX.
constexpr PinEntry PinTable[] =
{
	// Duet 2 and DueX heater outputs
	{ NoPin,		PinCapability::wpwm,	"!bedheat" },
	{ NoPin,		PinCapability::wpwm,	"!e0heat" },
	{ NoPin,		PinCapability::wpwm,	"!e1heat" },
	{ NoPin,		PinCapability::wpwm,	"exp.heater3,exp.8,!duex.e2heat,!duex.pwm1" },
	{ NoPin,		PinCapability::wpwm,	"exp.heater4,exp.13,!duex.e3heat,!duex.pwm2" },
	{ NoPin,		PinCapability::wpwm,	"exp.heater5,exp.18,!duex.e4heat,!duex.pwm3" },
	{ NoPin,		PinCapability::wpwm,	"exp.heater6,exp.23,!duex.e5heat,!duex.pwm4" },
	{ NoPin,		PinCapability::wpwm,	"exp.heater7,exp.31,!duex.e6heat,!duex.pwm5" },

	// Duet 2 and DueX fan outputs
	{ PortCPin(23),	PinCapability::wpwm,	"fan0" },
	{ PortCPin(26),	PinCapability::wpwm,	"fan1" },
	{ PortAPin(19),	PinCapability::wpwm,	"fan2" },
	{ PortAPin(20),	PinCapability::wpwm,	"duex.fan3" },
	{ PortAPin(16),	PinCapability::wpwm,	"duex.fan4" },
	{ NoPin,		PinCapability::wpwm,	"duex.fan5" },
	{ NoPin,		PinCapability::wpwm,	"duex.fan6" },
	{ NoPin,		PinCapability::wpwm,	"duex.fan7" },
	{ NoPin,		PinCapability::wpwm,	"duex.fan8" },

	// Endstop inputs
	{ PortCPin(14),	PinCapability::read,	"xstop" },
	{ PortAPin(02),	PinCapability::read,	"ystop" },
	{ PortDPin(29),	PinCapability::read,	"zstop" },
	{ PortDPin(10),	PinCapability::read,	"e0stop" },
	{ PortCPin(16),	PinCapability::read,	"e1stop" },
	{ PortEPin(0),	PinCapability::rw,		"exp.e2stop,exp.4" },
	{ NoPin,		PinCapability::rw,		"exp.e3stop,exp.9,spi.cs6,duex.cs6" },
	{ NoPin,		PinCapability::rw,		"exp.e4stop,exp.14,spi.cs7,duex.cs7" },
	{ NoPin,		PinCapability::rw,		"exp.e5stop,exp.19,spi.cs8,duex.cs8" },
	{ NoPin,		PinCapability::rw,		"exp.e6stop,exp.24" },
	{ NoPin,			PinCapability::read,	"duex.e2stop" },
	{ NoPin,			PinCapability::read,	"duex.e3stop" },
	{ NoPin,			PinCapability::read,	"duex.e4stop" },
	{ NoPin,			PinCapability::read,	"duex.e5stop" },
	{ NoPin,			PinCapability::read,	"duex.e6stop" },

	// Thermistor inputs
	{ NoPin,		PinCapability::ainr,	"bedtemp" },
	{ NoPin,		PinCapability::ainr,	"e0temp" },
	{ NoPin,		PinCapability::ainr,	"e1temp" },
	{ NoPin,		PinCapability::ainr,	"e2temp,duex.e2temp,exp.thermistor3,exp.35" },
	{ NoPin,		PinCapability::ainr,	"e3temp,duex.e3temp,exp.thermistor4,exp.36" },
	{ NoPin,		PinCapability::ainr,	"e4temp,duex.e4temp,exp.thermistor5,exp.37" },
	{ NoPin,		PinCapability::ainr,	"e5temp,duex.e5temp,exp.thermistor6,exp.38" },
	{ NoPin,		PinCapability::ainr,	"e6temp,duex.e6temp,exp.thermistor7,exp.39" },

	// SPI CS pins
	{ NoPin,		PinCapability::rw,		"spi.cs1" },
	{ NoPin,		PinCapability::rw,		"spi.cs2" },
	{ NoPin,		PinCapability::rw,		"spi.cs3" },
	{ NoPin,		PinCapability::rw,		"spi.cs4" },
	{ NoPin,		PinCapability::rw,		"spi.cs5,duex.cs5,exp.50" },

	// Misc
	{ Z_PROBE_PIN,	PinCapability::ainr,	"zprobe.in" },
	{ Z_PROBE_MOD_PIN, PinCapability::write, "zprobe.mod" },
//	{ ATX_POWER_PIN, PinCapability::write,	"pson" },
	{ PortCPin(5),	PinCapability::rw,		"gpio1" },
	{ PortCPin(7),	PinCapability::rw,		"gpio2" },
	{ PortCPin(28),	PinCapability::rw,		"gpio3" },
	{ PortAPin(24),	PinCapability::rw,		"gpio4" },
	{ PortDPin(22),	PinCapability::rw,		"gpio5" },
	{ PortAPin(9),	PinCapability::rw,		"urxd0" },
	{ PortAPin(10),	PinCapability::rw,		"utxd0" },

	{ PortAPin(0),	PinCapability::rw,	"xyz_probe_en" },
	{ PortAPin(17),	PinCapability::read,	"xyz_probe_in" },
	{ PortBPin(14),		PinCapability::rwpwm,	"spindle" },
	{ PortCPin(24),		PinCapability::rw,	"spindleoff" },


	{ NoPin,	PinCapability::rw,		"exp.pb6,exp.29,duex.pb6" },
	{ NoPin,			PinCapability::rwpwm,	"duex.gp1" },
	{ NoPin,			PinCapability::rwpwm,	"duex.gp2" },
	{ NoPin,			PinCapability::rwpwm,	"duex.gp3" },
	{ NoPin,			PinCapability::rwpwm,	"duex.gp4" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.0" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.1" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.2" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.3" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.4" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.5" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.6" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.7" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.8" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.9" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.10" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.11" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.12" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.13" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.14" },
	{ NoPin,			PinCapability::rwpwm,	"sx1509b.15" }
};

constexpr unsigned int NumNamedPins = ARRAY_SIZE(PinTable);

// Function to look up a pin name pass back the corresponding index into the pin table
bool LookupPinName(const char *pn, LogicalPin& lpin, bool& hardwareInverted) noexcept;

// Duet pin numbers to control the WiFi interface on the Duet WiFi
#define ESP_SPI					SPI
#define ESP_SPI_INTERFACE_ID	ID_SPI
#define ESP_SPI_IRQn			SPI_IRQn
#define ESP_SPI_HANDLER			SPI_Handler

// Hardware IDs of the SPI transmit and receive DMA interfaces. See atsam datasheet.
const uint32_t DMA_HW_ID_SPI_TX = 1;
const uint32_t DMA_HW_ID_SPI_RX = 2;

constexpr Pin APIN_ESP_SPI_MOSI = APIN_SPI_MOSI;
constexpr Pin APIN_ESP_SPI_MISO = APIN_SPI_MISO;
constexpr Pin APIN_ESP_SPI_SCK = APIN_SPI_SCK;
constexpr Pin APIN_ESP_SPI_SS0 = APIN_SPI_SS0;

constexpr Pin EspResetPin = PortEPin(4);			// Low on this in holds the WiFi module in reset (ESP_RESET)
constexpr Pin EspEnablePin = NoPin;			// High to enable the WiFi module, low to power it down (ESP_CH_PD)
constexpr Pin EspDataReadyPin = PortDPin(31);		// Input from the WiFi module indicating that it wants to transfer data (ESP GPIO0)
constexpr Pin SamTfrReadyPin = PortDPin(30);		// Output from the SAM to the WiFi module indicating we can accept a data transfer (ESP GPIO4 via 7474)
constexpr Pin SamCsPin = PortAPin(11);				// SPI NPCS pin, input from WiFi module

// Duet pin numbers to control the W5500 interface on the Duet Ethernet
/*#define W5500_SPI				SPI
#define W5500_SPI_INTERFACE_ID	ID_SPI
#define W5500_SPI_IRQn			SPI_IRQn
#define W5500_SPI_HANDLER		SPI_Handler

constexpr Pin APIN_W5500_SPI_MOSI = APIN_SPI_MOSI;
constexpr Pin APIN_W5500_SPI_MISO = APIN_SPI_MISO;
constexpr Pin APIN_W5500_SPI_SCK = APIN_SPI_SCK;
constexpr Pin APIN_W5500_SPI_SS0 = APIN_SPI_SS0;

constexpr Pin W5500ResetPin = PortEPin(4);			// Low on this in holds the W5500 module in reset (ESP_RESET)
constexpr Pin W5500InterruptPin = PortDPin(31);		// W5500 interrupt output, active low
constexpr Pin W5500ModuleSensePin = PortAPin(5);	// URXD1, tied to ground on the Ethernet module
constexpr Pin W5500SsPin = PortAPin(11);			// SPI NPCS pin, input from W5500 module

// Duet pin numbers for the SBC interface
#define SBC_SPI					SPI
#define SBC_SPI_INTERFACE_ID	ID_SPI
#define SBC_SPI_IRQn			SPI_IRQn
#define SBC_SPI_HANDLER			SPI_Handler
constexpr Pin APIN_SBC_SPI_MOSI = 13;
constexpr Pin APIN_SBC_SPI_MISO = 12;
constexpr Pin APIN_SBC_SPI_SCK = 14;
constexpr Pin APIN_SBC_SPI_SS0 = 11;

constexpr Pin SbcTfrReadyPin = PortDPin(31);
*/
// Timer allocation (no network timer on DuetNG)
// TC0 channel 0 is used for FAN2
// TC0 channel 1 is currently unused (may use it for a heater or a fan)
// TC0 channel 2 is available for us to use
#define STEP_TC				(TC0)
#define STEP_TC_CHAN		(2)
#define STEP_TC_IRQN		TC2_IRQn
#define STEP_TC_HANDLER		TC2_Handler
#define STEP_TC_ID			ID_TC2

// DMA channel allocation
#if HAS_LINUX_INTERFACE
constexpr DmaChannel DmacChanSbcTx = 1;
constexpr DmaChannel DmacChanSbcRx = 2;
#endif

#if HAS_WIFI_NETWORKING
constexpr DmaChannel DmacChanWiFiTx = 1;
constexpr DmaChannel DmacChanWiFiRx = 2;
#endif

namespace StepPins
{
	// *** These next three functions must use the same bit assignments in the drivers bitmap ***
	// Each stepper driver must be assigned one bit in a 32-bit word, in such a way that multiple drivers can be stepped efficiently
	// and more or less simultaneously by doing parallel writes to several bits in one or more output ports.
	// All our step pins are on port D, so the bitmap is just the map of step bits in port D.

	// Calculate the step bit for a driver. This doesn't need to be fast. It must return 0 if the driver is remote.
	static inline uint32_t CalcDriverBitmap(size_t driver) noexcept
	{
		return (driver < NumDirectDrivers)
				? g_APinDescription[STEP_PINS[driver]].ulPin
				: 0;
	}

	// Set the specified step pins high. This needs to be fast.
	static inline __attribute__((always_inline)) void StepDriversHigh(uint32_t driverMap) noexcept
	{
		PIOD->PIO_SODR = driverMap;				// on Duet WiFi/Ethernet all step pins are on port D
	}

	// Set all step pins low. This needs to be fast.
	static inline __attribute__((always_inline)) void StepDriversLow(uint32_t driverMap) noexcept
	{
		PIOD->PIO_CODR = driverMap;				// on Duet WiFi/Ethernet all step pins are on port D
	}
}

#endif
