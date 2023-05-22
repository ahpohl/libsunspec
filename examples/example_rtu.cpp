#include <iostream>
#include <iomanip>
#include <memory>
#include "SunspecInverter.h"

int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<SunspecInverter> inverter(new SunspecInverter());
  
  if (!inverter->ConnectModeRtu(device))
  {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  if (!inverter->SetRemoteId(1))
  {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  std::string mfg;
  if (!inverter->GetManufacturer(mfg))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Manufacturer: " << mfg << std::endl;

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed, std::ios::floatfield);  

  double ac_power;
  if (!inverter->GetAcPower(ac_power))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Grid Power Reading: " << ac_power << " W" << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
