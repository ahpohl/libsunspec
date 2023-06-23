#include <FroniusRegister.h>
#include <SunSpec.h>
#include <SunSpecModelIntSf.h>

using namespace FroniusRegisterMap;

bool FroniusRegister::GetActiveStateCode(uint16_t &code)
{
	if (!GetRegister(F_Active_State_Code.res, F_Active_State_Code.reg, F_Active_State_Code.nb))
	{
		return false;
	}
	code = F_Active_State_Code.res;

	return true;
}

bool FroniusRegister::GetSitePower(double &res)
{
	if (!GetRegister(F_Site_Power.res, F_Site_Power.reg, F_Site_Power.nb))
	{
		return false;
	}
	res = static_cast<double>(F_Site_Power.res);

	return true;
}

bool FroniusRegister::GetSiteEnergyDay(double &res)
{
	if (!GetRegister(F_Site_Energy_Day.res, F_Site_Energy_Day.reg, F_Site_Energy_Day.nb))
	{
		return false;
	}
	res = static_cast<double>(F_Site_Energy_Day.res) * 0.001f;

	return true;
}

bool FroniusRegister::GetSiteEnergyYear(double &res)
{
	if (!GetRegister(F_Site_Energy_Year.res, F_Site_Energy_Year.reg, F_Site_Energy_Year.nb))
	{
		return false;
	}
	res = static_cast<double>(F_Site_Energy_Year.res) * 0.001f;

	return true;
}

bool FroniusRegister::GetSiteEnergyTotal(double &res)
{
	if (!GetRegister(F_Site_Energy_Total.res, F_Site_Energy_Total.reg, F_Site_Energy_Total.nb))
	{
		return false;
	}
	res = static_cast<double>(F_Site_Energy_Total.res) * 0.001f;

	return true;
}



