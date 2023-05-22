#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <modbus/modbus.h>

#include "SunspecInverter.h"
#include "CommonModel.h"
#include "InverterModel.h"

SunspecInverter::SunspecInverter(void) : Ctx(nullptr), Log(0)
{

}

SunspecInverter::~SunspecInverter(void)
{
	modbus_close(Ctx);
	modbus_free(Ctx);
}

bool SunspecInverter::ConnectTcp(std::string ip_addr, int port = 502)
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
	if (modbus_connect(Ctx) == -1) {
	    ErrorMessage = std::string("Connection to \"") + ip_addr + "\" failed: "
	      + modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
		return false;
	}
	return true;
}

bool SunspecInverter::ConnectRtu(std::string device)
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
	return true;
}

bool SunspecInverter::SetRemoteId(const int &remote_id)
{
	if (modbus_set_slave(Ctx, remote_id) == -1) {
		ErrorMessage = "Invalid slave ID";
		return false;
	}
	return true;
}

int SunspecInverter::GetRemoteId(void) const
{
	return modbus_get_slave(Ctx);
}

bool SunspecInverter::ReadRegisterString(std::string &str, const uint16_t &address,
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

bool SunspecInverter::ReadRegisterInt(int &num, const uint16_t &address,
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

void SunspecInverter::SetLogLevel(const unsigned char &log_level)
{
	Log = log_level;
}

std::string SunspecInverter::GetErrorMessage(void) const
{
	return ErrorMessage;
}

bool SunspecInverter::GetManufacturer(std::string &mfg)
{
	if (!ReadRegisterString(mfg, CommonModel::C001_ADDR_Mn, CommonModel::C001_SIZE_Mn)) {
		return false;
	}
	return true;
}

bool SunspecInverter::GetAcPower(double &pwr)
{
	int num = 0, sf = 0;
	if (!ReadRegisterInt(num, InverterModel::I10X_ADDR_W, InverterModel::I10X_SIZE_W)) {
		return false;
	}
	if (!ReadRegisterInt(sf, InverterModel::I10X_ADDR_W_SF, InverterModel::I10X_SIZE_W_SF)) {
		return false;
	}
	pwr = pow(num, sf);

	return true;
}
