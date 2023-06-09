/** @example example_fronius.cpp

    Demonstration of a SunSpec compatible Fronius inverter.

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

  if (!sun->IsSunSpecModBus()) {
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

  std::string model;
  if (!sun->GetDeviceModel(model))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Model: " << model << std::endl;

  std::string option;
  if (!sun->GetOptionFwVersion(option))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Datamanager FW: " << option << std::endl;

  std::string device_fw;
  if (!sun->GetDeviceFwVersion(device_fw))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Inverter FW: " << device_fw << std::endl;

  std::string serial_nb;
  if (!sun->GetDeviceFwVersion(serial_nb))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "Serial: " << serial_nb << std::endl;

  int address;
  if (!sun->GetModBusAddress(address))
  {
	  std::cout << sun->GetErrorMessage() << std::endl;
	  return EXIT_FAILURE;
  }
  std::cout << "ModBus address (slave ID): " << address << std::endl;

  return EXIT_SUCCESS;
}
