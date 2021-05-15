/*
 * ZProbeEndstop.h
 *
 *  Created on: 15 Sep 2019
 *      Author: David
 */

#ifndef SRC_ENDSTOPS_ZPROBEENDSTOP_H_
#define SRC_ENDSTOPS_ZPROBEENDSTOP_H_

#include "Endstop.h"

class ZProbeEndstop final : public Endstop
{
public:
	void* operator new(size_t sz) noexcept { return FreelistManager::Allocate<ZProbeEndstop>(); }
	void operator delete(void* p) noexcept { FreelistManager::Release<ZProbeEndstop>(p); }

	ZProbeEndstop(uint8_t axis, EndStopPosition pos) noexcept;

	EndStopType GetEndstopType() const noexcept override { return EndStopType::zProbeAsEndstop; }
	EndStopHit Stopped() const noexcept override;
	bool Prime(const Kinematics& kin, const AxisDriversConfig& axisDrivers) noexcept override;
	EndstopHitDetails CheckTriggered(bool goingSlow) noexcept override;
	bool Acknowledge(EndstopHitDetails what) noexcept override;
	void AppendDetails(const StringRef& str) noexcept override;

private:
	size_t zProbeNumber;					// which Z probe to use, always 0 for now
	bool stopAll;
};

#endif /* SRC_ENDSTOPS_ZPROBEENDSTOP_H_ */
