/**
	@brief   Class to capture data from inverters
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef INVERTER_H_
#define INVERTER_H_

#include "SunSpec.h"

class Inverter: public SunSpec
{
public:
	/** Checks if the inverter is SunSpec ModBus protocol compatible */
	bool IsSunSpecInverter(void);

	/** Instantaneous AC power being produced from inverter

	    @returns AC power [W]
	*/
	bool GetAcPower(double &res);
};

#endif /* INVERTER_H_ */
