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
  
  if (!inverter->ConnectModbusRtu(device, 19200))
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
  std::cout << "Inverter time:" << std::endl;
  std::cout << "  " << std::put_time(std::gmtime(&rawtime), "%a %Y-%m-%d %H:%M:%S %Z") << std::endl;
  std::cout << "  " << std::put_time(std::localtime(&rawtime), "%a %Y-%m-%d %H:%M:%S %Z") << std::endl;

  std::cout << "System time:" << std::endl;
  std::time_t t = std::time(nullptr);
  std::cout << "  " << std::put_time(std::gmtime(&t), "%a %Y-%m-%d %H:%M:%S %Z") << std::endl;
  std::cout << "  " << std::put_time(std::localtime(&t), "%a %Y-%m-%d %H:%M:%S %Z") << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
