/**
	@brief   Class to manipulate Inverter Model registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef INVERTERMODEL_H_
#define INVERTERMODEL_H_

#include "SunSpec.h"

class InverterModel: virtual public SunSpec
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
};

#endif /* INVERTERMODEL_H_ */
