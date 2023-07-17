/** @example inverter.cpp

    Demonstration of a SunSpec compatible Fronius inverter.

    Inverter register map

    Connection in Modbus RTU serial mode.
*/

#include <FroniusInverter.h>
#include <iostream>
#include <iomanip>
#include <memory>


int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<FroniusInverter> inverter(new FroniusInverter());
  
  if (!inverter->ConnectModbusRtu(device, 19200))
  {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  if (!inverter->IsInverterRegisterMap()) {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  double current;
  if (!inverter->GetAcCurrent(current))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "AC total current: " << current << " A" << std::endl;

  double voltage;
  if (!inverter->GetAcVoltage(voltage))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "AC voltage : " << voltage << " V" << std::endl;

  double ac_power;
  if (!inverter->GetAcPower(ac_power))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "AC power: " << ac_power << " W" << std::endl;

  double freq;
  if (!inverter->GetAcFrequency(freq))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "AC frequency: " << freq << " Hz" << std::endl;

  double power_va;
  if (!inverter->GetAcPowerApparent(power_va))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "AC apparent power: " << power_va << " VA" << std::endl;

  double power_var;
  if (!inverter->GetAcPowerReactive(power_var))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "AC reactive power: " << power_var << " VAr" << std::endl;

  double power_factor;
  if (!inverter->GetAcPowerFactor(power_factor))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "AC power factor: " << power_factor << " %" << std::endl;

  double energy_lifetime;
  if (!inverter->GetAcEnergyLifetime(energy_lifetime))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "AC energy lifetime: " << energy_lifetime  << " kWh" << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
