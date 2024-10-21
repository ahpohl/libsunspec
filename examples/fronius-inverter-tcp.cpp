/** @example fronius-inverter-tcp.cpp

 Demonstration of a SunSpec compatible Fronius inverter.

 Fronius specific register map

 Connection in Modbus TCP mode.
 */

#include <FroniusInverter.h>
#include <iomanip>
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  const std::string ip_addr = "192.168.6.56";

  std::unique_ptr<FroniusInverter> inverter(new FroniusInverter());

  if (!inverter->ConnectModbusTcp(ip_addr)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  inverter->SetModbusDebug(false);

  if (!inverter->SetModbusAddress(1)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  if (!inverter->IsCommonRegisterMap()) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  FroniusInverter::ModelType_t model;
  if (!inverter->GetModelType(model)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "SunSpec model: " << model.TypeStr << " (" << model.Type << ")"
            << std::endl;

  if (model.Type == 2) {
    std::cout << "Switching SunSpec model ..." << std::endl;
    if (!inverter->SetModelType()) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    if (!inverter->GetModelType(model)) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    std::cout << "SunSpec model: " << model.TypeStr << " (" << model.Type << ")"
              << std::endl;
  }

  FroniusInverter::StateEvt_t state_evt;
  if (!inverter->GetStateEvtFlags(state_evt)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Inverter state: " << state_evt.StStr << " (" << state_evt.St
            << ")" << std::endl;
  if (!(state_evt.EvtStr.empty())) {
    std::cout << "Event: " << state_evt.EvtStr << std::endl;
  }
  if ((!state_evt.EvtVndStr.empty())) {
    std::cout << "Vendor event: " << state_evt.EvtVndStr << std::endl;
  }

  FroniusInverter::StateCode_t state_code;
  if (!inverter->GetStateCode(state_code)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  if (!(state_code.StStr.empty())) {
    std::cout << "State code: " << state_code.StStr << " (" << state_code.St
              << ")" << std::endl;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  double power;
  if (!inverter->GetSitePower(power)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "Site power total: " << power << " W" << std::endl;

  double energy_day;
  if (!inverter->GetSiteEnergyDay(energy_day)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Site energy current day: " << energy_day << " kWh" << std::endl;

  double energy_year;
  if (!inverter->GetAcEnergyLifetime(energy_year)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Site energy current year: " << energy_year << " kWh"
            << std::endl;

  double energy_total;
  if (!inverter->GetSiteEnergyTotal(energy_total)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Site energy total lifetime: " << energy_total << " kWh"
            << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
