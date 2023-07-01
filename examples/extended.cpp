/** @example extended.cpp

    Demonstration of a SunSpec compatible Fronius inverter.

    Extended (Measurements_Status) register map

    Connection in Modbus RTU serial mode.
*/

#include <FroniusInverter.h>
#include <iostream>
#include <iomanip>
#include <memory>
#include <chrono>
#include <ctime>

int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<FroniusInverter> inverter(new FroniusInverter());
  
  if (!inverter->ConnectModbusRtu(device))
  {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  if (!inverter->IsExtendedRegisterMap()) {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  long int rawtime;
  if (!inverter->GetTimestamp(rawtime))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "Unix timestamp: " << rawtime << std::endl;

  struct tm ts;
  char buf[80];

  ts = *(std::gmtime(&rawtime));
  std::strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
  std::cout << buf << std::endl;

  ts = *(std::localtime(&rawtime));
  std::strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
  std::cout << buf << std::endl;


  /*
  Raw time: 741530225
  Unix timestamp: 1688215025
  Sat 2023-07-01 12:37:05 GMT
  Sat 2023-07-01 14:37:05 CEST
  */

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
