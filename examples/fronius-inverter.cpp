/** @example fronius-inverter.cpp

    Demonstration of a SunSpec compatible Fronius inverter.

    Fronius specific register map

    Connection in ModBus RTU serial mode.
*/

#include <FroniusInverter.h>
#include <iostream>
#include <iomanip>
#include <memory>


int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<FroniusInverter> inverter(new FroniusInverter());
  
  if (!inverter->ConnectModbusRtu(device))
  {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  if (!inverter->IsSunSpecInverter()) {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }

  FroniusInverter::StateEvt_t state_evt = inverter->GetStateEvt();
  std::cout << "Vendor flag: "
		  << state_evt.EvtVndStr << "("
		  << state_evt.EvtVnd1 << " "
		  << state_evt.EvtVnd2 << " "
		  << state_evt.EvtVnd3 << " "
		  << state_evt.EvtVnd4 << ")" << std::endl;

  std::cout << "Flag: "
		  << state_evt.EvtStr << "("
		  << state_evt.Evt1 << " "
		  << state_evt.Evt2 << ")" << std::endl;

  std::cout << "Vendor operating state: "
		  << state_evt.StVndStr << "("
		  << state_evt.StVnd << ")" << std::endl;

  std::cout << "Operating state: "
		  << state_evt.StStr << "("
  		  << state_evt.St << ")" << std::endl;

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  double power;
  if (!inverter->GetSitePower(power))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "Site power total: " << power  << " W" << std::endl;

  double energy_day;
  if (!inverter->GetSiteEnergyDay(energy_day))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Site energy current day: " << energy_day  << " kWh" << std::endl;

  double energy_year;
  if (!inverter->GetAcEnergyLifetime(energy_year))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Site energy current year: " << energy_year  << " kWh" << std::endl;

  double energy_total;
  if (!inverter->GetSiteEnergyTotal(energy_total))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Site energy total lifetime: " << energy_total  << " kWh" << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
