#include "ImmediateModel.h"
#include "SunSpec.h"
#include "SunSpecModelIntSf.h"

using namespace ImmediateRegisterMap;

bool ImmediateModel::IsImmediateRegisterMap(void)
{
	if (!GetRegister(I123_ID.res, I123_ID.reg, I123_ID.nb)) {
		return false;
	}
	if ( !(I123_ID.res == 123) ) {
		ErrorMessage = std::string("Invalid ID of Immediate Controls Model block (") + std::to_string(I123_ID.res) + ")";
		return false;
	}
	if (!GetRegister(I123_L.res, I123_L.reg, I123_L.nb)) {
		return false;
	}
	if ( I123_L.res != 24 ) {
		ErrorMessage = std::string("Invalid length of Immediate Controls Model block (") + std::to_string(I123_L.res) + ")";
		return false;
	}

	return true;
}

