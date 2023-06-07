#include "Sunspec.h"
#include "SunspecModelIntSf.h"
#include "Inverter.h"

#include "../src/Sunspec-impl.cpp"

using namespace CommonModel;
using namespace InverterModel;
using namespace FroniusRegister;

bool Inverter::GetManufacturer(std::string &mfg)
{
	return GetRegister<std::string>(mfg, C001_ADDR_Mn, C001_SIZE_Mn);
}

bool Inverter::GetAcPower(double &res)
{
	return GetRegister<int16_t>(res, I10X_ADDR_W, I10X_SIZE_W, I10X_ADDR_W_SF);
}

bool Inverter::GetSiteEnergyTotal(uint64_t &res)
{
	return GetRegister<uint64_t>(res, F_ADDR_Site_Energy_Total, F_SIZE_Site_Energy_Total);
}

