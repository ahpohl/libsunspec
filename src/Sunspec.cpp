#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <modbus/modbus.h>
#include <Sunspec.h>

#include "../src/Sunspec-impl.cpp"

Sunspec::Sunspec(void) : Ctx(nullptr)
{

}

Sunspec::~Sunspec(void)
{
	modbus_close(Ctx);
	modbus_free(Ctx);
}

std::string Sunspec::GetErrorMessage(void) const
{
	return ErrorMessage;
}

bool Sunspec::ConnectModeTcp(std::string ip_addr, int port = 502)
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

bool Sunspec::ConnectModeRtu(std::string device)
{
	if (device.empty()) {
	    ErrorMessage = "Serial device argument empty";
	    return false;
	}
	Ctx = modbus_new_rtu(device.c_str(), 9600, 'N', 8, 1);
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

void Sunspec::SetModbusDebug(const bool &debug)
{
	modbus_set_debug(Ctx, debug);
}

bool Sunspec::SetRemoteId(const int &remote_id)
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

int Sunspec::GetRemoteId(void) const
{
	return modbus_get_slave(Ctx);
}

uint16_t *Sunspec::ReadRegister(const uint16_t &address, const uint16_t &size)
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

template <>
std::string Sunspec::ConvertRegister(const uint16_t *tab_reg, const uint16_t &size)
{
	std::string str;

	for (int i = 0; i < size; i++) {
		str.push_back((tab_reg[i] >> 8) & 0xFF);
	    str.push_back(tab_reg[i]);
	}
	return str;
}

bool Sunspec::GetString(std::string &str, const uint16_t &reg_addr, const uint16_t &size)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(reg_addr, size);
	if (!tab_reg) {
		return false;
	}
	str = ConvertRegister<std::string>(tab_reg, size);
	free(tab_reg);

	return true;
}

bool Sunspec::GetFloat(float &res, const uint16_t &reg_addr, const uint16_t &size)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(reg_addr, size);
	if (!tab_reg) {
		return false;
	}
	res = ConvertRegister<float>(tab_reg, size);
	free(tab_reg);

	return true;
}
