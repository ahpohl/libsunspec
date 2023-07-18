/**
	@brief   Class to manipulate Meter Model registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef METERMODEL_H_
#define METERMODEL_H_

#include "SunSpec.h"
#include "StateEvents.h"

class MeterModel: virtual public SunSpec
{
public:
	/** Checks if device has a SunSpec inverter register map */
	bool IsMeterRegisterMap(void);

	/** AC total current [A] */
	bool GetAcCurrent(double &res);

	/** AC phase current

	    param res current [A]
	    param ph phase A, B or C (default A)
	*/
	bool GetAcCurrentPhase(double &res, const char &ph = 'A');

	/** AC voltage phase-to-neutral

	    param res voltage [V]
	    param ph phase A, B or C (default A)
	*/
	bool GetAcVoltage(double &res, const char &ph = 'A');

	/** AC phase-to-phase voltage

	    param res voltage [V]
	    param ph_pair phase AB, BC or CA
	*/
	bool GetAcVoltagePhaseToPhase(double &res, const std::string &ph_pair);

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

	/** AC energy total exported [kWh] */
	bool GetAcEnergyExport(double &res);

	/** AC energy total imported [kWh] */
	bool GetAcEnergyImport(double &res);

private:
	/** Read meter event flags */
	bool ReadEventFlags(uint32_t &flag1, uint32_t &flag2);
};

#endif /* METERMODEL_H_ */
