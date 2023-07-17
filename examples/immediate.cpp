/** @example immediate.cpp

    Demonstration of a SunSpec compatible Fronius inverter.

    Immediate Control register map

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

  if (!inverter->IsImmediateRegisterMap()) {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }

  bool ac_state;
  if (!inverter->GetAcConnection(ac_state)) {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "AC grid: " << (ac_state ? "connected" : "disconnected") << std::endl;

  if (!ac_state) {
	  std::cout << "Starting up ..." << std::endl;
	  if (!inverter->SetAcConnection(true)) {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  if (!inverter->GetAcConnection(ac_state)) {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout << "AC grid: " << (ac_state ? "connected" : "disconnected") << std::endl;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
