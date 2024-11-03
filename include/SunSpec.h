/**
 @brief   Base class for SunSpec compatible inverters, meters and batteries.

 Supports both Modbus TCP and Modbus RTU protocols.

 @author  Alexander Pohl <alex@ahpohl.com>
 */

#ifndef SUNSPEC_H_
#define SUNSPEC_H_

#include <cstdint>
#include <modbus/modbus.h>
#include <string>

class SunSpec {
public:
  /** SunSpec class constructor */
  SunSpec(void);

  /** SunSpec class destructor */
  virtual ~SunSpec(void);

  /** Return the error message (if any) */
  std::string GetErrorMessage(void) const;

  /** Create a libmodbus context for TCP/IPv4

   The ConnectModbusTcp() function shall allocate and initialize a modbus_t
   structure to communicate with a Modbus TCP IPv4/IPv6 server.

   @param node hostname or address of the server to which the client wants to
   establish a connection
   @param service service name/port number to connect to
   */
  bool ConnectModbusTcp(const std::string &node,
                        const std::string &service = "502");

  /** Create a libmodbus context for RTU serial

   The ConnectModbusRtu() function shall allocate and initialize a modbus_t
   structure to communicate in RTU mode on a serial line.

   @param device device specifies the name of the serial port
   @param baud_rate baud rate (9600 or 19200)
   */
  bool ConnectModbusRtu(const std::string &device, const int &baud_rate = 9600);

  /**  Set/clear debug flag of the Modbus context (very verbose) */
  void SetModbusDebug(const bool &debug);

  /** Sets the Modbus device address (slave ID)

   The SetModbusAddress() function sets the slave number in the libmodbus
   context. It is usually only required to set the slave ID in RTU. The meaning
   of this ID will be different if your program acts as client (master) or
   server (slave).

   As RTU client, SetModbusAddress() sets the ID of the remote device you want
   to communicate. Be sure to set the slave ID before issuing any Modbus
   requests on the serial bus. If you communicate with several servers (slaves),
   you can set the slave ID of the remote device before each request.

   In TCP, the slave number is only required if the message must reach a device
   on a serial network.

   @param slave_id Modbus device address (1-247), default (1)
   */
  bool SetModbusAddress(const int &slave_id = 1);

  /** Reads Modbus device address (slave ID)

   @returns: 1-247
   */
  bool GetModbusAddress(int &slave_id);

  /** Set timeout for response

   The SetResponseTimeout() function shall set the timeout interval used to wait
   for a response. When a byte timeout is set, if elapsed time for the first
   byte of response is longer than the given timeout, an ETIMEDOUT error will be
   raised by the function waiting for a response. When byte timeout is disabled,
   the full confirmation response must be received before expiration of the
   response timeout.

   @param millis [ms], default 500
   */
  bool SetResponseTimeout(const int &millis = 500);

  /** Get timeout for response [ms] */
  bool GetResponseTimeout(int &millis);

  /** Set timeout between bytes

   The SetByteTimeout() function shall set the timeout interval between two
   consecutive bytes of the same message. The timeout is an upper bound on the
   amount of time elapsed before select() returns, if the time elapsed is longer
   than the defined timeout, an ETIMEDOUT error will be raised by the function
   waiting for a response.

   If millis is zero, this timeout will not be used at all. In this case,
   SetResponseTimeout() governs the entire handling of the response, the full
   confirmation response must be received before expiration of the response
   timeout. When a byte timeout is set, the response timeout is only used to
   wait for until the first byte of the response.

   @param millis [ms], default 500

   */
  bool SetByteTimeout(const int &millis = 500);

  /** Get timeout between bytes [ms] */
  bool GetByteTimeout(int &millis);

  /** Set timeout for indication

   The SetIndicationTimeout() function shall set the timeout interval
   used by a server to wait for a request from a client. The value of to_usec
   argument must be in the range 0 to 999999. If both to_sec and to_usec are
   zero, this timeout will not be used at all. In this case, the server will
   wait forever.

   @param millis [ms], default 0
   */
  bool SetIndicationTimeout(const int &millis = 0);

  /** Get timeout for indication [ms] */
  bool GetIndicationTimeout(int &millis);

  /** Set error recovery

   The SetErrorRecovery() function shall set the error recovery mode to apply
   when the connection fails, a response timeout occurred or the byte received
   is not expected.

   @param recovery flag to enable or disable error recovery mode
   */
  bool SetErrorRecovery(const bool recovery);

protected:
  /** Get a Modbus register and convert to number or string

   Method automatically converts the raw register value(s) to the destination
   format specified in the res parameter. Supported register types are:

   T: int16_t, uint16_t, uint32_t, uint64_t, std::string

   @returns number or string (template T)
   */
  template <typename T>
  bool GetRegister(T &res, const uint16_t &reg_addr, const uint16_t &size);

  /** Set a single Modbus register (function 0x06) */
  bool SetRegister(const uint16_t &value, const uint16_t &reg_addr);

  /** String to hold the error message */
  std::string ErrorMessage;

private:
  /** Structure that holds the Modbus connection */
  modbus_t *Ctx;

  /** Read raw Modbus registers from the device

   @returns pointer to an array with the register values
   */
  uint16_t *ReadRegister(const uint16_t &address, const uint16_t &size);

  /** Convert raw Modbus registers to usable values

   @returns number or string (template T)
   */
  template <typename T>
  T ConvertRegister(const uint16_t *tab_reg, const uint16_t &size);
};

#endif /* SUNSPEC_H_ */
