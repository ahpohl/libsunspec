#include "ExtendedModel.h"
#include "SunSpecModelIntSf.h"
#include <SunSpecModelFloat.h>

#ifdef MODEL_INTSF
using namespace ExtendedRegisterMapIntSf;
#endif

#ifdef MODEL_FLOAT
using namespace ExtendedRegisterMapFloat;
#endif

bool ExtendedModel::IsExtendedRegisterMap(void)
{
	if (!GetRegister(I122_ID.res, I122_ID.reg, I122_ID.nb)) {
		return false;
	}
	if ( !(I122_ID.res == 122) ) {
		ErrorMessage = std::string("Invalid ID of Extended Model block (") + std::to_string(I122_ID.res) + ")";
		return false;
	}
	if (!GetRegister(I122_L.res, I122_L.reg, I122_L.nb)) {
		return false;
	}
	if ( I122_L.res != 44 ) {
		ErrorMessage = std::string("Invalid length of Extended Model block (") + std::to_string(I122_L.res) + ")";
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
