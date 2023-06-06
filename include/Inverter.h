#ifndef INVERTER_H_
#define INVERTER_H_

#include "Sunspec.h"

class Inverter: public Sunspec
{
public:
	Inverter();
	virtual ~Inverter();

	/* Common model */
	bool GetManufacturer(std::string &mfg);

	/* Inverter model */
	bool GetAcPower(double &ac_power);

	/* Fronius register */
	bool GetAcLifetimeEnergy(double &energy_year);
};

#endif /* INVERTER_H_ */
