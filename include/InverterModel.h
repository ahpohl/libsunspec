/**
	@brief   Class to capture data from inverters
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef INVERTERMODEL_H_
#define INVERTERMODEL_H_

#include "SunSpec.h"

class InverterModel: virtual public SunSpec
{
public:
	/** Checks if the inverter is SunSpec ModBus protocol compatible */
	bool IsSunSpecInverter(void);

	/** Instantaneous AC power being produced from inverter

	    @returns AC power [W]
	*/
	bool GetAcPower(double &res);
};

#endif /* INVERTERMODEL_H_ */
