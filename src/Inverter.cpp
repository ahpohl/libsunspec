#include <SunSpec.h>
#include <SunSpecModelIntSf.h>
#include <cmath>
#include "Inverter.h"

using namespace InverterModel;
using namespace FroniusRegister;

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

