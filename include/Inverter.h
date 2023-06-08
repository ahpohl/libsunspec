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
	/** Instantaneous AC power being produced from inverter

	    @returns: AC power [W]
	*/
	bool GetAcPower(double &res);

	/** Instantaneous total site energy produced from inverter

	    @returns: total site energy [kWh]
	*/
	bool GetSiteEnergyTotal(double &res);
};

#endif /* INVERTER_H_ */
