/**
	@brief   Class for Fronius specific registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef FRONIUS_H_
#define FRONIUS_H_

#include "SunSpec.h"

class Fronius: public SunSpec
{
public:
	/** Instantaneous total site energy produced from inverter

	    @returns total site energy [kWh]
	*/
	bool GetSiteEnergyTotal(double &res);
};

#endif /* FRONIUS_H_ */
