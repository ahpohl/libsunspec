/** @example extended.cpp

    Demonstration of a SunSpec compatible Fronius inverter.

    Extended (Measurements_Status) register map

    Connection in ModBus RTU serial mode.
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

  long int ts;
  if (!inverter->GetTimestamp(ts))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "Inverter time: " << std::asctime(std::localtime(&ts)) << ts
		  	<< " seconds since the Epoch" << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
