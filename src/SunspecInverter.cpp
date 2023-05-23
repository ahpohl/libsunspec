#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <modbus/modbus.h>

#include "SunspecInverter.h"
#include "CommonModel.h"
#include "InverterModel.h"

SunspecInverter::SunspecInverter(void) : Ctx(nullptr)
{

}

SunspecInverter::~SunspecInverter(void)
{
	modbus_close(Ctx);
	modbus_free(Ctx);
}

bool SunspecInverter::ConnectModeTcp(std::string ip_addr, int port = 502)
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

bool SunspecInverter::ConnectModeRtu(std::string device)
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

void SunspecInverter::SetModbusDebug(const bool &debug)
{
	modbus_set_debug(Ctx, debug);
}

bool SunspecInverter::SetRemoteId(const int &remote_id)
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

int SunspecInverter::GetRemoteId(void) const
{
	return modbus_get_slave(Ctx);
}

bool SunspecInverter::ReadRegister(std::string &str, const uint16_t &address,
		const uint16_t &size)
{
	uint16_t tab_reg[size] = {0};

	int rc = modbus_read_registers(Ctx, address, size, tab_reg);
	if (rc == -1) {
	    ErrorMessage = std::string("Read register ") + std::to_string(address) + " failed: "
	    	+ modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
		return false;
	}
	for (int i = 0; i < rc; i++) {
		str.push_back((tab_reg[i] >> 8) & 0xFF);
	    str.push_back(tab_reg[i]);
	}
	return true;
}

bool SunspecInverter::ReadRegister(unsigned int &num, const uint16_t &address,
		const uint16_t &size)
{
	uint16_t tab_reg[size] = {0};

	int rc = modbus_read_registers(Ctx, address, size, tab_reg);
	if (rc == -1) {
	    ErrorMessage = std::string("Read register ") + std::to_string(address) + " failed: "
	    	+ modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
		return false;
	}
	memcpy(&num, &tab_reg, sizeof(tab_reg));
	return true;
}

bool SunspecInverter::ReadRegister(int16_t &num, const uint16_t &address,
		const uint16_t &size)
{
	if (size != 1) {
		ErrorMessage = "Only 16-bit wide integer supported by this method";
		return false;
	}
	uint16_t tab_reg = 0;

	int rc = modbus_read_registers(Ctx, address, 1, &tab_reg);
	if (rc == -1) {
	    ErrorMessage = std::string("Read register ") + std::to_string(address) + " failed: "
	    	+ modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
		return false;
	}
	num = static_cast<int16_t>(tab_reg);

	return true;
}

std::string SunspecInverter::GetErrorMessage(void) const
{
	return ErrorMessage;
}

bool SunspecInverter::GetManufacturer(std::string &mfg)
{
	if (!ReadRegister(mfg, CommonModel::C001_ADDR_Mn, CommonModel::C001_SIZE_Mn)) {
		return false;
	}
	return true;
}

bool SunspecInverter::GetAcPower(double &pwr)
{
	int16_t num = 0, sf = 0;
	if (!ReadRegister(num, InverterModel::I10X_ADDR_W, InverterModel::I10X_SIZE_W)) {
		return false;
	}
	if (!ReadRegister(sf, InverterModel::I10X_ADDR_W_SF, InverterModel::I10X_SIZE_W_SF)) {
		return false;
	}
	pwr = static_cast<double>(num) * pow(10, sf);
	std::cout << "AC power unscaled: " << num << std::endl;
	std::cout << "Scale factor: " << sf << std::endl;

	return true;
}
