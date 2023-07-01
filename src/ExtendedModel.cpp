#include "ExtendedModel.h"
#include "SunSpecModelIntSf.h"

using namespace ExtendedRegisterMap;

bool ExtendedModel::IsExtendedRegisterMap(void)
{
	uint16_t id;
	if (!GetRegister(id, I122_ID.reg, I122_ID.nb)) {
		return false;
	}
	if ( !(id == 122) ) {
		ErrorMessage = std::string("Invalid ID of Extended Model block (") + std::to_string(id) + ")";
		return false;
	}
	uint16_t length;
	if (!GetRegister(length, I122_L.reg, I122_L.nb)) {
		return false;
	}
	if ( length != 44 ) {
		ErrorMessage = std::string("Invalid length of Extended Model block (") + std::to_string(length) + ")";
		return false;
	}

	return true;
}

bool ExtendedModel::GetTimestamp(long int &ts)
{
	if (!GetRegister(I122_Tms.res, I122_Tms.reg, I122_Tms.nb)) {
		return false;
	}
	ts = static_cast<unsigned long int>(I122_Tms.res) + 946684800ul;

	return true;
}
