/**
	@brief   Base class to capture data from SunSpec compatible inverters, meters and batteries.

             Supports both ModBus TCP and ModBus RTU protocols.

	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef SUNSPEC_H_
#define SUNSPEC_H_

#include <cstdint>
#include <string>
#include <modbus/modbus.h>

class SunSpec
{
public:
	/** SunSpec class constructor */
	SunSpec(void);

	/** SunSpec class destructor */
	virtual ~SunSpec(void);

	/** Return the error message (if any) */
	std::string GetErrorMessage(void) const;

    /** Create a libmodbus context for TCP/IPv4

        The ConnectModbusTcp() function shall allocate and initialize a modbus_t structure
        to communicate with a ModBus TCP IPv4 server.

        @param ip_address IP address of the server to which the client wants to establish a connection
        @param port port argument is the TCP port to use
    */
	bool ConnectModbusTcp(std::string ip_address, int port = 502);

	/** Create a libmodbus context for RTU serial

	    The ConnectModbusRtu() function shall allocate and initialize a modbus_t structure
	    to communicate in RTU mode on a serial line.

	    @param device device specifies the name of the serial port
	    @param baud_rate baud rate (9600 or 19200)
	*/
	bool ConnectModbusRtu(std::string device, int baud_rate = 9600);

	/**  Set/clear debug flag of the ModBus context (very verbose) */
	void SetModbusDebug(const bool &debug);

	/** Sets the ModBus device address (slave ID)

	    The SetModBusAddress() function sets the slave number in the libmodbus context. It is usually only required
	    to set the slave ID in RTU. The meaning of this ID will be different if your program acts as client (master)
	    or server (slave).

        As RTU client, SetModBusAddress() sets the ID of the remote device you want to communicate. Be sure to set the
        slave ID before issuing any ModBus requests on the serial bus. If you communicate with several servers
        (slaves), you can set the slave ID of the remote device before each request.

	    In TCP, the slave number is only required if the message must reach a device on a serial network.

	    @param slave_id ModBus device address (1-247), default (1)
	*/
	bool SetModBusAddress(const int slave_id = 1);

	/** Reads ModBus device address (slave ID)

	    @returns: 1-247
	*/
	bool GetModBusAddress(int &slave_id);

	/** Checks if the device is SunSpec ModBus protocol compatible */
	bool IsSunSpecModBus(void);

	/** Manufacturer

	    @returns i.e. Fronius
	*/
	bool GetManufacturer(std::string &str);

	/** Device model

	    @returns i.e. IG+150V [3p]
	*/
	bool GetDeviceModel(std::string &str);

	/** SW version of installed option

	    @returns i.e. Firmware version of Datamanager
	*/
	bool GetOptionFwVersion(std::string &str);

	/** SW version of main device

	    @returns i.e. Firmware version of inverter, meter, battery etc.
	*/
	bool GetDeviceFwVersion(std::string &str);

	/** Serial number of the device

		@returns Serial number
	*/
	bool GetSerialNumber(std::string &str);

protected:
	/** Get a ModBus register and convert to number or string

	    Method automatically converts the raw register value(s) to the destination format
	    specified in the res parameter. Supported register types are:

	    T: int16_t, uint16_t, uint32_t, uint64_t, std::string

	    @returns number or string (template T)
	*/
	template <typename T>
	bool GetRegister(T &res, const uint16_t &reg_addr, const uint16_t &size);

private:
	/** Structure that holds the ModBus connection */
	modbus_t *Ctx;

	/** String to hold the error message */
	std::string ErrorMessage;

	/** Read raw ModBus registers from the device

	    @returns pointer to an array with the register values
	*/
	uint16_t *ReadRegister(const uint16_t &address, const uint16_t &size);

	/** Convert raw ModBus registers to usable values

	    @returns number or string (template T)
	*/
	template <typename T>
	T ConvertRegister(const uint16_t *tab_reg, const uint16_t &size);
};

#endif /* SUNSPEC_H_ */
