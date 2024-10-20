/**
 @brief   Class to manipulate Nameplate Model registers
 @author  Alexander Pohl <alex@ahpohl.com>
 */
#ifndef NAMEPLATEMODEL_H_
#define NAMEPLATEMODEL_H_

#include "SunSpec.h"

class NameplateModel : virtual public SunSpec {
public:
  /** Checks if device has a SunSpec nameplate register map */
  bool IsNameplateRegisterMap(void);

  /** Continuous power output capability of the inverter.

   @returns power output [W]
   */
  bool GetPowerOutputMax(double &res);

  /** Continuous Volt-Ampere capability of the inverter.

   @returns apparent power [VA]
   */
  bool GetPowerApparentMax(double &res);

  /** Continuous VAR capability of the inverter.

   @param res reactive power [VAr]
   @param quadrant quadrant [1-4]
   */
  bool GetPowerReactiveMax(double &res, const int quadrant);

  /** Maximum RMS AC current level capability of the inverter.

   @returns AC current [A]
   */
  bool GetAcCurrentMax(double &res);

  /** Minimum power factor capability of the inverter.

   @param res power factor [cos(phi)]
   @param quadrant quadrant [1-4]
   */
  bool GetPowerFactorMin(double &res, const int quadrant);
};

#endif /* NAMEPLATEMODEL_H_ */
