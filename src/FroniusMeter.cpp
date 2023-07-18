#include "FroniusMeter.h"

bool FroniusMeter::IsSunSpecMeter(void)
{
	if (!IsCommonRegisterMap()) {
		return false;
	}
	if (!IsMeterRegisterMap()) {
		return false;
	}

	return true;
}
