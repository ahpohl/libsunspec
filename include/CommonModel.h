/**
 @brief   Class to manipulate Common Model registers
 @author  Alexander Pohl <alex@ahpohl.com>
 */
#ifndef COMMONMODEL_H_
#define COMMONMODEL_H_

#include "SunSpec.h"

class CommonModel : virtual public SunSpec {
 public:
  /** Checks if device has a SunSpec common register map */
  bool IsCommonRegisterMap(void);

  /** Manufacturer

   @returns i.e. Fronius
   */
  bool GetManufacturer(std::string &str);

  /** Device model

   @returns i.e. IG+150V [3p]
   */
  bool GetDeviceModel(std::string &str);

  /** SW version of installed option

   @returns i.e. Firmware version of Datamanager
   */
  bool GetOptionFwVersion(std::string &str);

  /** SW version of main device

   @returns i.e. Firmware version of inverter, meter, battery etc.
   */
  bool GetDeviceFwVersion(std::string &str);

  /** Serial number of the device

   @returns Serial number
   */
  bool GetSerialNumber(std::string &str);

};

#endif /* COMMONMODEL_H_ */
