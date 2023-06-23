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
	/** Get current active state code of inverter

	    @returns state code
	*/
	bool GetActiveStateCode(uint16_t &code);

	/** Total power (site sum) of all connected inverters.

	    @returns power [W]
	*/
	bool GetSitePower(double &res);
	/** Total energy for current day of all connected inverters.

	    @returns current day energy [kWh]
	*/
	bool GetSiteEnergyDay(double &res);

	/** Total energy for current year of all connected inverters.

	    @returns current year energy [kWh]
	*/
	bool GetSiteEnergyYear(double &res);

	/** Total lifetime energy of all connected inverters.

	    @returns lifetime energy [kWh]
	*/
	bool GetSiteEnergyTotal(double &res);
};

#endif /* FRONIUSREGISTER_H_ */
