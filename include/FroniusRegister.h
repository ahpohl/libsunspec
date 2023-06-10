/**
	@brief   Class to manipulate Fronius specific registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef FRONIUSREGISTER_H_
#define FRONIUSREGISTER_H_

#include "SunSpec.h"

class FroniusRegister: virtual public SunSpec
{
public:
	/** Instantaneous total site energy produced from inverter

	    @returns total site energy [kWh]
	*/
	bool GetSiteEnergyTotal(double &res);
};

#endif /* FRONIUSREGISTER_H_ */
