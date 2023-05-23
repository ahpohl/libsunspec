/*
 *  SunSpec Alliance Specifications
 */

#ifndef SUNSPEC_H_
#define SUNSPEC_H_

#include <cstdint>
#include <string>
#include <modbus/modbus.h>

class SunspecInverter
{
public:
	SunspecInverter(void);
	~SunspecInverter(void);
	bool ConnectModeTcp(std::string ip_address, int port);
	bool ConnectModeRtu(std::string device);
	void SetModbusDebug(const bool &debug);
	bool SetRemoteId(const int &remote_id);
	int GetRemoteId(void) const;
	bool ReadRegisterString(std::string &str, const uint16_t &address,
		const uint16_t &size);
	bool ReadRegisterInt(unsigned int &num, const uint16_t &address, 
    const uint16_t &size);
	std::string GetErrorMessage(void) const;

	/* Methods to retrieve inverter data */
	bool GetManufacturer(std::string &mfg);
	bool GetAcPower(double &ac_power);

private:
	modbus_t *Ctx;
	std::string ErrorMessage;
};

#endif /* SUNSPEC_H_ */
