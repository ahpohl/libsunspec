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
    if (!SetStateEvt()) {
	    return false;
    }

	return true;
}
