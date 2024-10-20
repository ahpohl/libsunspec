/** @example multi-mppt.cpp

 Demonstration of a SunSpec compatible Fronius inverter.

 Multi MPPT register map

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

  if (!inverter->IsNameplateRegisterMap()) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  double power_max;
  if (!inverter->GetPowerOutputMax(power_max)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "Max power output: " << power_max << " W" << std::endl;

  double power_apparent_max;
  if (!inverter->GetPowerApparentMax(power_apparent_max)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "Max apparent power output: " << power_apparent_max << " VA"
            << std::endl;

  std::cout << "Max reactive power output:" << std::endl;
  for (int quadrant = 1; quadrant < 5; ++quadrant) {
    double power_reactive_max;
    if (!inverter->GetPowerReactiveMax(power_reactive_max, quadrant)) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    std::cout.precision(0);
    std::cout << " Quadrant " << quadrant << ": " << power_reactive_max
              << " VAr" << std::endl;
  }

  double ac_current_max;
  if (!inverter->GetAcCurrentMax(ac_current_max)) {
    std::cout << inverter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout.precision(0);
  std::cout << "Max AC current: " << ac_current_max << " A" << std::endl;

  std::cout << "Min power factor:" << std::endl;
  for (int quadrant = 1; quadrant < 5; ++quadrant) {
    double power_factor_min;
    if (!inverter->GetPowerFactorMin(power_factor_min, quadrant)) {
      std::cout << inverter->GetErrorMessage() << std::endl;
      return EXIT_FAILURE;
    }
    std::cout.precision(3);
    std::cout << " Quadrant " << quadrant << ": " << power_factor_min
              << " cos(phi)" << std::endl;
  }

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
