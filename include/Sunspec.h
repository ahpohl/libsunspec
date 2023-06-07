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
	std::string GetErrorMessage(void) const;
	bool ConnectModeTcp(std::string ip_address, int port);
	bool ConnectModeRtu(std::string device);
	void SetModbusDebug(const bool &debug);
	bool SetRemoteId(const int &remote_id);
	int GetRemoteId(void) const;

	template <typename T>
	bool GetRegister(T &res, const uint16_t &reg_addr, const uint16_t &size);
	template <typename T>
	bool GetIntSf(double &res, const uint16_t &reg_addr, const uint16_t &reg_size,
		const uint16_t &sf_addr);

private:
	modbus_t *Ctx;
	std::string ErrorMessage;
	uint16_t *ReadRegister(const uint16_t &address, const uint16_t &size);

	template <typename T>
	T ConvertRegister(const uint16_t *tab_reg, const uint16_t &size);
};

#endif /* SUNSPEC_H_ */
