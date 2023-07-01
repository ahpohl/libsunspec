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
  
  if (!inverter->ConnectModbusRtu(device))
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

  double current_total;
  if (!inverter->GetAcCurrentTotal(current_total))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "AC total current: " << current_total << " A" << std::endl;

  /* only for 3-phase inverter
	  double current_pha;
	  if (!inverter->GetAcCurrentPhaseA(current_pha))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-A current: " << current_pha << " A" << std::endl;

	  double current_phb;
	  if (!inverter->GetAcCurrentPhaseB(current_phb))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-B current: " << current_pha << " A" << std::endl;

	  double current_phc;
	  if (!inverter->GetAcCurrentPhaseC(current_phc))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-C current: " << current_pha << " A" << std::endl;

	  double voltage_ab;
	  if (!inverter->GetAcVoltagePhaseAB(voltage_ab))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-AB voltage : " << voltage_ab << " V" << std::endl;

	  double voltage_bc;
	  if (!inverter->GetAcVoltagePhaseBC(voltage_bc))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-BC voltage : " << voltage_bc << " V" << std::endl;

	  double voltage_ca;
	  if (!inverter->GetAcVoltagePhaseCA(voltage_ca))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-CA voltage : " << voltage_ca << " V" << std::endl;
  */

  double voltage_pha;
  if (!inverter->GetAcVoltagePhaseA(voltage_pha))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "AC phase-A voltage : " << voltage_pha << " V" << std::endl;

  /* only for 3-phase inverter
	  double voltage_phb;
	  if (!inverter->GetAcVoltagePhaseB(voltage_phb))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-B voltage : " << voltage_phb << " V" << std::endl;

	  double voltage_phc;
	  if (!inverter->GetAcVoltagePhaseC(voltage_phc))
	  {
		  std::cout << inverter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout.precision(2);
	  std::cout << "AC phase-C voltage : " << voltage_phc << " V" << std::endl;
  */

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
