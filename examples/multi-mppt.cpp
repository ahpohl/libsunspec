/** @example nameplate.cpp

 Demonstration of a SunSpec compatible Fronius inverter.

 Nameplate register map

 Connection in Modbus RTU serial mode.
 */

#include <FroniusInverter.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  const std::string device =
      "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<FroniusInverter> inverter(new FroniusInverter());

  if (!inverter->ConnectModbusRtu(device)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  if (!inverter->IsMultiMpptRegisterMap()) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  for (int string_id = 1; string_id < 3; ++string_id) {
    std::cout << "String " << string_id << ":" << std::endl;
    double dc_current;
    if (!inverter->GetDcCurrent(dc_current, string_id)) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    std::cout.precision(2);
    std::cout << "  DC current: " << dc_current << " A" << std::endl;

    double dc_voltage;
    if (!inverter->GetDcVoltage(dc_voltage, string_id)) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    std::cout.precision(2);
    std::cout << "  DC voltage: " << dc_voltage << " V" << std::endl;

    double dc_power;
    if (!inverter->GetDcPower(dc_power, string_id)) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    std::cout.precision(2);
    std::cout << "  DC power: " << dc_power << " W" << std::endl;

    double dc_energy;
    if (!inverter->GetDcEnergyLifetime(dc_energy, string_id)) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    std::cout.precision(2);
    std::cout << "  DC energy lifetime: " << dc_energy << " kWh" << std::endl;
  }

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
