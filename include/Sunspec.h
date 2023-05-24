/*
 *  SunSpec Alliance Specifications
 */

#ifndef SUNSPEC_H_
#define SUNSPEC_H_

#include <cstdint>
#include <string>
#include <modbus/modbus.h>

class Sunspec
{
public:
	Sunspec(void);
	virtual ~Sunspec(void);
	bool ConnectModeTcp(std::string ip_address, int port);
	bool ConnectModeRtu(std::string device);
	void SetModbusDebug(const bool &debug);
	bool SetRemoteId(const int &remote_id);
	int GetRemoteId(void) const;
	bool ReadRegister(std::string &str, const uint16_t &address,
		const uint16_t &size);
	bool ReadRegister(uint64_t &num, const uint16_t &address,
    const uint16_t &size);
	bool ReadRegister(int16_t &num, const uint16_t &address,
		const uint16_t &size);
	std::string GetErrorMessage(void) const;

private:
	modbus_t *Ctx;
	std::string ErrorMessage;
};

#endif /* SUNSPEC_H_ */
