#include "CommonModel.h"
#include "SunSpec.h"
#include <SunSpecModelIntSf.h>

using namespace CommonRegisterMap;

bool CommonModel::IsCommonRegisterMap(void)
{
	uint32_t sid;
	if (!GetRegister(sid, C001_SID.reg, C001_SID.nb)) {
		return false;
	}
	if ( sid != 0x53756e53 ) {
		ErrorMessage = "Device is not compatible with the ModBus SunSpec protocol.";
		return false;
	}
	uint16_t id;
	if (!GetRegister(id, C001_ID.reg, C001_ID.nb)) {
		return false;
	}
	if ( id != 1 ) {
		ErrorMessage = std::string("Invalid ID of Common Model block (") + std::to_string(id) + ")";
		return false;
	}
	uint16_t length;
	if (!GetRegister(length, C001_L.reg, C001_L.nb)) {
		return false;
	}
	if ( length != 65 ) {
		ErrorMessage = std::string("Invalid length of Common Model block (") + std::to_string(length) + ")";
		return false;
	}

	return true;
}

bool CommonModel::GetManufacturer(std::string &str)
{
	if (!GetRegister(C001_Mn.str, C001_Mn.reg, C001_Mn.nb)) {
		return false;
	}
	str = C001_Mn.str;

	return true;
}

bool CommonModel::GetDeviceModel(std::string &str)
{
	if (!GetRegister(C001_Md.str, C001_Md.reg, C001_Md.nb)) {
		return false;
	}
	str = C001_Md.str;

	return true;
}

bool CommonModel::GetOptionFwVersion(std::string &str)
{
	if (!GetRegister(C001_Opt.str, C001_Opt.reg, C001_Opt.nb)) {
		return false;
	}
	str = C001_Opt.str;

	return true;
}

bool CommonModel::GetDeviceFwVersion(std::string &str)
{
	if (!GetRegister(C001_Vr.str, C001_Vr.reg, C001_Vr.nb)) {
		return false;
	}
	str = C001_Vr.str;

	return true;
}

bool CommonModel::GetSerialNumber(std::string &str)
{
	if (!GetRegister(C001_SN.str, C001_SN.reg, C001_SN.nb)) {
		return false;
	}
	str = C001_SN.str;

	return true;
}
