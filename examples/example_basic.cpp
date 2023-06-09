/** @example example_basic.cpp

    Get instantaneous energy, power and MPPT voltages from a Fronius inverter

    Connection in ModBus RTU serial mode.
*/

#include <FroniusInverter.h>
#include <iostream>
#include <iomanip>
#include <memory>


int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<FroniusInverter> sun(new FroniusInverter());
  
  if (!sun->ConnectModbusRtu(device))
  {
    std::cout << sun->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  if (!sun->IsSunSpecInverter()) {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  double ac_power;
  if (!sun->GetAcPower(ac_power))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "AC power now: " << ac_power << " W" << std::endl;

  /*
  double energy_total;
  if (!sun->GetSiteEnergyTotal(energy_total))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(3);
  std::cout << "Site energy total: " << energy_total  << " kWh" << std::endl;
  */

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}