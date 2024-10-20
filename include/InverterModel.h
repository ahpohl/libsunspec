/**
 @brief   Class to manipulate Inverter Model registers
 @author  Alexander Pohl <alex@ahpohl.com>
 */

#ifndef INVERTERMODEL_H_
#define INVERTERMODEL_H_

#include "SunSpec.h"
#include "StateEvents.h"

class InverterModel : virtual public SunSpec, public StateEvents {
 public:
  /** Checks if device has a SunSpec inverter register map */
  bool IsInverterRegisterMap(void);

  /** AC total current [A] */
  bool GetAcCurrent(double &res);

  /** AC phase current

   param res current [A]
   param ph phase A, B or C (default A)
   */
  bool GetAcCurrentPhase(double &res, const char &ph = 'A');

  /** AC voltage phase-to-neutral

   param res voltage [V]
   param ph phase A, B or C (default A)
   */
  bool GetAcVoltage(double &res, const char &ph = 'A');

  /** AC phase-to-phase voltage

   param res voltage [V]
   param ph_pair phase AB, BC or CA
   */
  bool GetAcVoltagePhaseToPhase(double &res, const std::string &ph_pair);

  /** AC power value [W] */
  bool GetAcPower(double &res);

  /** AC frequency value [Hz] */
  bool GetAcFrequency(double &res);

  /** Apparent power [VA] */
  bool GetAcPowerApparent(double &res);

  /** Reactive power [VAr] */
  bool GetAcPowerReactive(double &res);

  /** Power factor [%] */
  bool GetAcPowerFactor(double &res);

  /** AC lifetime energy production [Wh] */
  bool GetAcEnergyLifetime(double &res);

  /** Read all state and event flags */
  bool GetStateEvtFlags(StateEvt_t &state_evt);

 private:
  /** Read inverter operating state */
  bool ReadState(uint16_t &state);

  /** Read vendor inverter operating state */
  bool ReadStateVendor(uint16_t &state);

  /** Read inverter event flags */
  bool ReadEventFlags(uint32_t &flag1, uint32_t &flag2);

  /** Read vendor inverter event flags */
  bool ReadEventFlagsVendor(uint32_t &flag1, uint32_t &flag2, uint32_t &flag3,
                            uint32_t &flag4);
};

#endif /* INVERTERMODEL_H_ */
