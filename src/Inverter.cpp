#include "Sunspec.h"
#include "SunspecModelIntSf.h"
#include "Inverter.h"

#include "../src/Sunspec-impl.cpp"

using namespace CommonModel;
using namespace InverterModel;
using namespace FroniusRegister;

Inverter::Inverter(void) {
	// TODO Auto-generated constructor stub

}

Inverter::~Inverter(void) {
	// TODO Auto-generated destructor stub
}

bool Inverter::GetManufacturer(std::string &mfg)
{
	return GetRegister<std::string>(mfg, C001_ADDR_Mn, C001_SIZE_Mn);
}

bool Inverter::GetAcPower(double &res)
{
	return GetIntSf<int16_t>(res, I10X_ADDR_W, I10X_SIZE_W, I10X_ADDR_W_SF);
}

bool Inverter::GetAcLifetimeEnergy(double &res)
{
	return GetIntSf<uint32_t>(res, I10X_ADDR_WH, I10X_SIZE_WH, I10X_ADDR_WH_SF);
}

bool Inverter::GetSiteEnergyTotal(uint64_t &res)
{
	return GetRegister<uint64_t>(res, F_ADDR_Site_Energy_Total, F_SIZE_Site_Energy_Total);
}

