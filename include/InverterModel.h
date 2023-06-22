/**
	@brief   Class to manipulate Inverter Model registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef INVERTERMODEL_H_
#define INVERTERMODEL_H_

#include "SunSpec.h"
#include "StateEvents.h"

class InverterModel: virtual public SunSpec, public StateEvents
{
public:
	/** Checks if device has a SunSpec inverter register map */
	bool IsInverterRegisterMap(void);

	/** AC total current value [A] */
	bool GetAcCurrentTotal(double &res);

	/** AC phase-A current value [A] */
	bool GetAcCurrentPhaseA(double &res);

	/** AC phase-B current value [A] */
	bool GetAcCurrentPhaseB(double &res);

	/** AC phase-C current value [A] */
	bool GetAcCurrentPhaseC(double &res);

	/** AC phase-AB voltage value [V] */
	bool GetAcVoltagePhaseAB(double &res);

	/** AC phase-BC voltage value [V] */
	bool GetAcVoltagePhaseBC(double &res);

	/** AC phase-CA voltage [V] value */
	bool GetAcVoltagePhaseCA(double &res);

	/** AC voltage phase-A-to-neutral value [V] */
	bool GetAcVoltagePhaseA(double &res);

	/** AC voltage phase-B-to-neutral value [V] */
	bool GetAcVoltagePhaseB(double &res);

	/** AC voltage phase-C-to-neutral value [V] */
	bool GetAcVoltagePhaseC(double &res);

	/** AC power value [W] */
	bool GetAcPower(double &res);

	/** AC frequency value [Hz] */
	bool GetAcFrequency(double &res);

	/** Apparent power [VA] */
	bool GetAcPowerApparent(double &res);

	/** Reactive power [VAr] */
	bool GetAcPowerReactive(double &res);

	/** Power factor [%] */
	bool GetAcPowerFactor(double &res);

	/** AC lifetime energy production [Wh] */
	bool GetAcEnergyLifetime(double &res);

	/** Set events and flags */
	bool SetStateEvt(void);

	/** Get events and flags */
	StateEvtVendor_t GetStateEvt(void);

private:
	/** Operating state and flags */
	struct StateEvtVendor_t StateEvt;

	/** Operating state */
	bool ReadState(uint16_t &state);

	/** Vendor defined operating state */
	bool ReadStateVendor(uint16_t &state);

	/** Event flags */
	bool ReadEventFlags(uint32_t &flag1, uint32_t &flag2);

	/** Vendor defined event flags */
	bool ReadEventFlagsVendor(uint32_t &flag1, uint32_t &flag2, uint32_t &flag3, uint32_t &flag4);
};

#endif /* INVERTERMODEL_H_ */
