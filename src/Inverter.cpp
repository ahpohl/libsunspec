#include <cmath>
#include "Sunspec.h"
#include "SunspecModelIntSf.h"
#include "Inverter.h"

using namespace CommonModel;
using namespace InverterModel;
using namespace FroniusRegister;

bool Inverter::GetManufacturer(std::string &str)
{
	if (!GetRegister(C001_Mn.str, C001_Mn.reg, C001_Mn.nb)) {
		return false;
	}
	str = C001_Mn.str;

	return true;
}

bool Inverter::GetAcPower(double &res)
{
	if (!GetRegister(I10X_W.res, I10X_W.reg, I10X_W.nb))
	{
		return false;
	}
	if (!GetRegister(I10X_W_SF.res, I10X_W_SF.reg, I10X_W_SF.nb))
	{
		return false;
	}
	res = static_cast<double>(I10X_W.res) * pow(10, I10X_W_SF.res);

	return true;
}

bool Inverter::GetSiteEnergyTotal(double &res)
{
	if (!GetRegister(F_Site_Energy_Total.res, F_Site_Energy_Total.reg, F_Site_Energy_Total.nb))
	{
		return false;
	}
	res = static_cast<double>(F_Site_Energy_Total.res) * 0.001f;

	return true;
}

