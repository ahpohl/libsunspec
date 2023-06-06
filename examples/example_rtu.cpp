#include <iostream>
#include <iomanip>
#include <memory>

#include "../include/Inverter.h"

int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<Inverter> sun(new Inverter());
  
  if (!sun->ConnectModeRtu(device))
  {
    std::cout << sun->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  std::string mfg;
  if (!sun->GetManufacturer(mfg))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Manufacturer: " << mfg << std::endl;

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed, std::ios::floatfield);  

  double ac_power;
  if (!sun->GetAcPower(ac_power))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "AC power now: " << ac_power << " W" << std::endl;

  double energy_lifetime;
  if (!sun->GetAcLifetimeEnergy(energy_lifetime))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Lifetime energy: " << energy_lifetime  << " kWh" << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
