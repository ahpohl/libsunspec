#include "FroniusInverter.h"

bool FroniusInverter::IsSunSpecInverter(void)
{
	if (!IsCommonRegisterMap()) {
		return false;
	}
	if (!IsInverterRegisterMap()) {
		return false;
	}

	return true;
}



