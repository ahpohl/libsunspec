#include <FroniusRegister.h>
#include <SunSpec.h>
#include <SunSpecModelIntSf.h>

using namespace FroniusRegisterMap;

bool FroniusRegister::GetSiteEnergyTotal(double &res)
{
	if (!GetRegister(F_Site_Energy_Total.res, F_Site_Energy_Total.reg, F_Site_Energy_Total.nb))
	{
		return false;
	}
	res = static_cast<double>(F_Site_Energy_Total.res) * 0.001f;

	return true;
}
