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
	bool GetEnergyYear(uint64_t &energy_year);
};

#endif /* INVERTER_H_ */
