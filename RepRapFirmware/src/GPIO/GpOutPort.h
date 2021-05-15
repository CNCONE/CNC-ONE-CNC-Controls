/*
 * GpOutPort.h
 *
 *  Created on: 11 Feb 2020
 *      Author: David
 */

#ifndef SRC_GPIO_GPOUTPORT_H_
#define SRC_GPIO_GPOUTPORT_H_

#include <RepRapFirmware.h>
#include <Hardware/IoPorts.h>
#include <GCodes/GCodeResult.h>
#include <ObjectModel/ObjectModel.h>

class GpOutputPort INHERIT_OBJECT_MODEL
{
public:
	GpOutputPort() noexcept
		: lastPwm(0.0)
#if SUPPORT_CAN_EXPANSION
		, boardAddress(CanId::MasterAddress)
#endif
	{ }

	GpOutputPort(const GpOutputPort&) = delete;

	bool IsUnused() const noexcept;
	GCodeResult WriteAnalog(uint32_t gpioPortNumber, bool isServo, float pwm, const GCodeBuffer& gb, const StringRef& reply) noexcept;
	GCodeResult Configure(uint32_t gpioNumber, bool isServo, GCodeBuffer& gb, const StringRef& reply) THROWS(GCodeException);

#ifdef PCCB
	void Assign(const char *pinName) noexcept;
#endif

protected:
	DECLARE_OBJECT_MODEL

private:
	PwmPort port;									// will be initialised by PwmPort default constructor
	float lastPwm;
#if SUPPORT_CAN_EXPANSION
	CanAddress boardAddress;
#endif
};

#endif /* SRC_GPIO_GPOUTPORT_H_ */
