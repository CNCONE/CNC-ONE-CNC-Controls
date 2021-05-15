/*
 * ThermocoupleSensor31856.h
 *
 *  Created on: 27 Jun 2017
 *      Author: David
 */

#ifndef SRC_HEATING_SENSORS_THERMOCOUPLESENSOR31856_H_
#define SRC_HEATING_SENSORS_THERMOCOUPLESENSOR31856_H_

#include "SpiTemperatureSensor.h"

class ThermocoupleSensor31856 : public SpiTemperatureSensor
{
public:
	ThermocoupleSensor31856(unsigned int sensorNum) noexcept;
	GCodeResult Configure(GCodeBuffer& gb, const StringRef& reply, bool& changed) override THROWS(GCodeException);
	void Poll() noexcept override;
	const char *GetShortSensorType() const noexcept override { return TypeName; }

	static constexpr const char *TypeName = "thermocouplemax31856";

private:
	TemperatureError TryInitThermocouple() const noexcept;

	uint8_t cr0;
	uint8_t thermocoupleType;
};

#endif /* SRC_HEATING_SENSORS_THERMOCOUPLESENSOR31856_H_ */
