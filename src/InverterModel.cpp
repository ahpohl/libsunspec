#include <InverterModel.h>
#include <SunSpec.h>
#include <SunSpecModelIntSf.h>
#include <cmath>

using namespace InverterRegisterMap;

bool InverterModel::IsSunSpecInverter(void)
{
	if (!IsSunSpecModBus()) {
		return false;
	}
	uint16_t id;
	if (!GetRegister(id, I10X_ID.reg, I10X_ID.nb)) {
		return false;
	}
	if ( id != 1 ) {
		ErrorMessage = std::string("Invalid ID of Inverter Model block (") + std::to_string(id) + ")";
		return false;
	}
	uint16_t length;
	if (!GetRegister(length, I10X_L.reg, I10X_L.nb)) {
		return false;
	}
	if ( length != 50 ) {
		ErrorMessage = std::string("Invalid length of Inverter Model block (") + std::to_string(length) + ")";
		return false;
	}

	return true;
}

bool InverterModel::GetAcPower(double &res)
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
