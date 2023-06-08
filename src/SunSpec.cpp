#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <modbus/modbus.h>
#include <SunSpec.h>
#include <SunSpecModelIntSf.h>

using namespace CommonModel;

SunSpec::SunSpec(void) : Ctx(nullptr)
{

}

SunSpec::~SunSpec(void)
{
	modbus_close(Ctx);
	modbus_free(Ctx);
}

std::string SunSpec::GetErrorMessage(void) const
{
	return ErrorMessage;
}

bool SunSpec::ConnectModbusTcp(std::string ip_addr, int port)
{
	if (ip_addr.empty()) {
	    ErrorMessage = "IP address argument empty";
	    return false;
	}
	Ctx = modbus_new_tcp(ip_addr.c_str(), port);
	if (Ctx == nullptr) {
		ErrorMessage = "Unable to create the libmodbus context";
		return false;
	}
	if (modbus_connect(Ctx)) {
	    ErrorMessage = std::string("Connection to \"") + ip_addr + "\" failed: "
	      + modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
		return false;
	}
	return true;
}

bool SunSpec::ConnectModbusRtu(std::string device, int baud_rate)
{
	if (device.empty()) {
	    ErrorMessage = "Serial device argument empty";
	    return false;
	}
	Ctx = modbus_new_rtu(device.c_str(), baud_rate, 'N', 8, 1);
	if (Ctx == nullptr) {
		ErrorMessage = "Unable to create the libmodbus context";
		return false;
	}
	if (modbus_connect(Ctx) == -1) {
	    ErrorMessage = std::string("Connection to \"") + device + "\" failed: "
	    	+ modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
		return false;
	}
	if (!SetRemoteId(1)) {
		return false;
	}
	return true;
}

void SunSpec::SetModbusDebug(const bool &debug)
{
	modbus_set_debug(Ctx, debug);
}

bool SunSpec::SetRemoteId(const int &remote_id)
{
	if (remote_id <= 0) {
	    ErrorMessage = "Remote ID must be greater than zero.";
	    return false;
	}
	if (modbus_set_slave(Ctx, remote_id)) {
		ErrorMessage = "Invalid remote ID";
		return false;
	}
	return true;
}

int SunSpec::GetRemoteId(void) const
{
	return modbus_get_slave(Ctx);
}

uint16_t *SunSpec::ReadRegister(const uint16_t &address, const uint16_t &size)
{
	uint16_t *tab_reg = (uint16_t*) malloc(sizeof(uint16_t) * size);
	if (!tab_reg) {
		return nullptr;
	}

	int rc = modbus_read_registers(Ctx, address, size, tab_reg);
	if (rc == -1) {
	    ErrorMessage = std::string("Read register ") + std::to_string(address) + " failed: "
	    	+ modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
		return nullptr;
	}

	return tab_reg;
}

template <typename T>
T SunSpec::ConvertRegister(const uint16_t *tab_reg, const uint16_t &size)
{
	uint16_t tab_rev[size] = {0};
	uint16_t *ptr = (uint16_t*) &tab_reg[size - 1];
    for (int i = 0; i < size; i++) {
    	tab_rev[i] = *ptr--;
    }
	T res = 0;
	memcpy(&res, tab_rev, sizeof(uint16_t) * size);

    return res;
}

/** Convert raw ModBus registers to a string */
template <>
std::string SunSpec::ConvertRegister(const uint16_t *tab_reg, const uint16_t &size)
{
	std::string str;

	for (int i = 0; i < size; i++) {
		str.push_back((tab_reg[i] >> 8) & 0xFF);
	    str.push_back(tab_reg[i]);
	}
	return str;
}

template <typename T>
bool SunSpec::GetRegister(T &res, const uint16_t &reg_addr, const uint16_t &size)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(reg_addr, size);
	if (!tab_reg) {
		return false;
	}
	res = ConvertRegister<T>(tab_reg, size);
	delete tab_reg;

	return true;
}

template bool SunSpec::GetRegister(int16_t &, const uint16_t &, const uint16_t &);
template bool SunSpec::GetRegister(uint16_t &, const uint16_t &, const uint16_t &);
template bool SunSpec::GetRegister(uint32_t &, const uint16_t &, const uint16_t &);
template bool SunSpec::GetRegister(uint64_t &, const uint16_t &, const uint16_t &);
template bool SunSpec::GetRegister(std::string &, const uint16_t &, const uint16_t &);

bool SunSpec::IsSunSpecModBus(void)
{
	uint64_t sid;
	if (!GetRegister(sid, C001_SID.reg, C001_SID.nb)) {
		return false;
	}
	if ( sid != 0x53756e53 ) {
		ErrorMessage = "Device is not compatible with the ModBus SunSpec protocol.";
		return false;
	}

	return true;
}

bool SunSpec::GetManufacturer(std::string &str)
{
	if (!GetRegister(C001_Mn.str, C001_Mn.reg, C001_Mn.nb)) {
		return false;
	}
	str = C001_Mn.str;

	return true;
}

bool SunSpec::GetDeviceModel(std::string &str)
{
	if (!GetRegister(C001_Md.str, C001_Md.reg, C001_Md.nb)) {
		return false;
	}
	str = C001_Md.str;

	return true;
}
