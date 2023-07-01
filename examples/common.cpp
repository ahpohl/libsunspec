/** @example common.cpp

    Demonstration of a SunSpec compatible Fronius inverter.

    Common register map

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

  if (!inverter->IsCommonRegisterMap()) {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }

  std::string mfg;
  if (!inverter->GetManufacturer(mfg))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Manufacturer: " << mfg << std::endl;

  std::string model;
  if (!inverter->GetDeviceModel(model))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Model: " << model << std::endl;

  std::string option;
  if (!inverter->GetOptionFwVersion(option))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Datamanager FW: " << option << std::endl;

  std::string device_fw;
  if (!inverter->GetDeviceFwVersion(device_fw))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Inverter FW: " << device_fw << std::endl;

  std::string serial_nb;
  if (!inverter->GetDeviceFwVersion(serial_nb))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Serial: " << serial_nb << std::endl;

  int address;
  if (!inverter->GetModbusAddress(address))
  {
	  std::cout << inverter->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Modbus address (slave ID): " << address << std::endl;

  return EXIT_SUCCESS;
}
