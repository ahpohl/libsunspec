#include "Sunspec.h"
#include "Inverter.h"

using namespace CommonModel;
using namespace InverterModel;

Inverter::Inverter(void) {
	// TODO Auto-generated constructor stub

}

Inverter::~Inverter(void) {
	// TODO Auto-generated destructor stub
}

bool Inverter::GetManufacturer(std::string &mfg)
{
	return GetString(mfg, C001_ADDR_Mn, C001_SIZE_Mn);
}

bool Inverter::GetAcPower(double &pwr)
{
	return GetIntSf<int16_t>(pwr, I10X_ADDR_W, I10X_SIZE_W, I10X_ADDR_W_SF);
}

bool Inverter::GetAcLifetimeEnergy(double &energy_lifetime)
{
	return GetIntSf<uint64_t>(energy_lifetime, I10X_ADDR_WH, I10X_SIZE_WH, I10X_ADDR_WH_SF);
}

