#include <iostream>
#include <string>
#include <cstring>
#include <modbus/modbus.h>
#include <Sunspec.h>

Sunspec::Sunspec(void) : Ctx(nullptr)
{

}

Sunspec::~Sunspec(void)
{
	modbus_close(Ctx);
	modbus_free(Ctx);
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
	if (!tab_reg)
	{
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

std::string Sunspec::Register2String(const uint16_t *tab_reg, const uint16_t &size)
{
	std::string str;

	for (int i = 0; i < size; i++) {
		str.push_back((tab_reg[i] >> 8) & 0xFF);
	    str.push_back(tab_reg[i]);
	}
	return str;
}

int16_t Sunspec::Register2s16(const uint16_t *tab_reg)
{
	return static_cast<int16_t>(tab_reg[0]);
}

uint16_t Sunspec::Register2u16(const uint16_t *tab_reg)
{
	return tab_reg[0];
}

float Sunspec::Register2float(const uint16_t *tab_reg)
{
	float num = 0;
    memcpy(&num, tab_reg, 2);

    return num;
}

int32_t Sunspec::Register2s32(const uint16_t *tab_reg)
{
	int32_t num = 0;
    memcpy(&num, tab_reg, 2);

    return num;
}

uint32_t Sunspec::Register2u32(const uint16_t *tab_reg)
{
	uint32_t num = 0;
    memcpy(&num, tab_reg, 2);

    return num;
}

int64_t Sunspec::Register2s64(const uint16_t *tab_reg)
{
	int64_t num = 0;
    memcpy(&num, tab_reg, 4);

    return num;
}

uint64_t Sunspec::Register2u64(const uint16_t *tab_reg)
{
	uint64_t num = 0;
    memcpy(&num, tab_reg, 4);

    return num;
}

template <typename T_NUM, typename T_SIZE>
T_NUM Sunspec::Reg2Num(const uint16_t *tab_reg, const uint16_t &size)
{
	T_NUM num = 0;
    memcpy(&num, tab_reg, size);

    return num;
}

std::string Sunspec::GetErrorMessage(void) const
{
	return ErrorMessage;
}
