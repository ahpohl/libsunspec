#ifndef INVERTER_H_
#define INVERTER_H_

#include "SunSpec.h"

class Inverter: public SunSpec
{
public:
	/* Common model */
	bool GetManufacturer(std::string &str);

	/* Inverter model */
	bool GetAcPower(double &res);

	/* Fronius register */
	bool GetSiteEnergyTotal(double &res);
};

#endif /* INVERTER_H_ */
