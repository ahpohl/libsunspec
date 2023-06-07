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
	bool GetAcPower(double &res);

	/* Fronius register */
	bool GetAcLifetimeEnergy(double &res);
	bool GetSiteEnergyTotal(uint64_t &res);
};

#endif /* INVERTER_H_ */
