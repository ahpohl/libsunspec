#include "FroniusInverter.h"

bool FroniusInverter::IsSunSpecInverter(void)
{
	if (!IsCommonRegisterMap()) {
		return false;
	}
	if (!IsNameplateRegisterMap()) {
		return false;
	}
	if (!IsInverterRegisterMap()) {
		return false;
	}
	if (!IsMultiMpptRegisterMap()) {
		return false;
	}
    if (!ReadStateEvtFlags()) {
	    return false;
    }

	return true;
}
