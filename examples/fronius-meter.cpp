/** @example fronius-meter.cpp

    Demonstration of a SunSpec compatible Fronius electricity meter.

    Connection in Modbus RTU serial mode.
*/
#include <FroniusMeter.h>
#include <iostream>
#include <iomanip>
#include <memory>

int main(int argc, char *argv[])
{
  const std::string device = "/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0";

  std::unique_ptr<FroniusMeter> meter(new FroniusMeter());
  
  if (!meter->ConnectModbusRtu(device))
  {
    std::cout << meter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  meter->SetModbusDebug(false);

  if (!meter->SetModbusAddress(2))
  {
    std::cout << meter->GetErrorMessage() << std::endl;
    return EXIT_FAILURE;
  }
  if (!meter->IsSunSpecMeter()) {
	  std::cout << meter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }

  FroniusMeter::ModelType_t model;
  if (!meter->GetModelType(model)) {
	  std::cout << meter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "SunSpec model: " << model.TypeStr << " (" << model.Type << ")" << std::endl;

  if (model.Type == 2) {
	  std::cout << "Switching SunSpec model ..." << std::endl;
	  if (!meter->SetModelType()) {
		  std::cout << meter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  if (!meter->GetModelType(model)) {
		  std::cout << meter->GetErrorMessage() << std::endl;
		  return EXIT_FAILURE;
	  }
	  std::cout << "SunSpec model: " << model.TypeStr << " (" << model.Type << ")" << std::endl;
  }

  std::ios::fmtflags old_settings = std::cout.flags();
  std::cout.setf(std::ios::fixed, std::ios::floatfield);

  double energy_export;
  if (!meter->GetAcEnergyExport(energy_export))
  {
	  std::cout << meter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Energy exported: " << energy_export  << " kWh" << std::endl;

  double energy_import;
  if (!meter->GetAcEnergyImport(energy_import))
  {
	  std::cout << meter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout.precision(2);
  std::cout << "Energy imported: " << energy_import  << " kWh" << std::endl;

  std::cout.flags(old_settings);
  return EXIT_SUCCESS;
}
