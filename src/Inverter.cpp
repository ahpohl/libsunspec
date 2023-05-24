#include <cmath>
#include "Inverter.h"
#include "CommonModel.h"
#include "InverterModel.h"
#include "FroniusRegister.h"

Inverter::Inverter(void) {
	// TODO Auto-generated constructor stub

}

Inverter::~Inverter(void) {
	// TODO Auto-generated destructor stub
}

bool Inverter::GetManufacturer(std::string &mfg)
{
	if (!ReadRegister(mfg, CommonModel::C001_ADDR_Mn, CommonModel::C001_SIZE_Mn)) {
		return false;
	}
	return true;
}

bool Inverter::GetAcPower(double &pwr)
{
	int16_t num = 0, sf = 0;
	if (!ReadRegister(num, InverterModel::I10X_ADDR_W, InverterModel::I10X_SIZE_W)) {
		return false;
	}
	if (!ReadRegister(sf, InverterModel::I10X_ADDR_W_SF, InverterModel::I10X_SIZE_W_SF)) {
		return false;
	}
	pwr = static_cast<double>(num) * pow(10, sf);

	return true;
}

bool Inverter::GetEnergyYear(uint64_t &energy_year)
{
	if (!ReadRegister(energy_year, FroniusRegister::F_ADDR_Site_Energy_Year,
			FroniusRegister::F_SIZE_Site_Energy_Year)) {
		return false;
	}

	return true;
}

