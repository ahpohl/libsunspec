/**
 @brief   Class to manipulate Fronius specific registers
 @author  Alexander Pohl <alex@ahpohl.com>
 */

#ifndef FRONIUSREGISTER_H_
#define FRONIUSREGISTER_H_

#include "SunSpec.h"

class FroniusRegister : virtual public SunSpec {
public:
  /** Get current active state code of inverter

   @returns state code
   */
  bool GetActiveStateCode(uint16_t &code);

  /** Reset all event flags and active state code */
  bool ResetEventFlags(void);

  /** SunSpec model type */
  struct ModelType_t {
    /** SunSpec model type */
    int Type;
    /** Model type as string */
    std::string TypeStr;
  };

  /** Get type of SunSpec model used for inverter and meter data. */
  bool GetModelType(struct ModelType_t &model);

  /** Set type of SunSpec model used for inverter and meter data.

   @param value 1: floating point (default)
   2: integer + scale factor
   */
  bool SetModelType(const int &value = 1);

  /** Total power (site sum) of all connected inverters.

   @returns power [W]
   */
  bool GetSitePower(double &res);
  /** Total energy for current day of all connected inverters.

   @returns current day energy [kWh]
   */
  bool GetSiteEnergyDay(double &res);

  /** Total energy for current year of all connected inverters.

   @returns current year energy [kWh]
   */
  bool GetSiteEnergyYear(double &res);

  /** Total lifetime energy of all connected inverters.

   @returns lifetime energy [kWh]
   */
  bool GetSiteEnergyTotal(double &res);
};

#endif /* FRONIUSREGISTER_H_ */
