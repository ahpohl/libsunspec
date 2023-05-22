#include <iostream>
#include <iomanip>
#include <memory>
#include "SunspecInverter.h"

int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<SunspecInverter> inverter(new SunspecInverter());
  
  if (!inverter->ConnectRtu(device))
  {
    std::cout << "Inverter setup failed: " << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  std::string mfg = inverter->GetManufacturer();
  std::cout << "Manufacturer: " << mfg << std::endl;

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed, std::ios::floatfield);  

  double grid_power = inverter->GetAcPower();
  std::cout << "Grid Power Reading: " << grid_power << " W" << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
