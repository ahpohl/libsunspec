/**
 @brief   Class to manipulate Immediate Controls registers
 @author  Alexander Pohl <alex@ahpohl.com>
 */
#ifndef IMMEDIATEMODEL_H_
#define IMMEDIATEMODEL_H_

#include "SunSpec.h"
#include <string>

class ImmediateModel : virtual public SunSpec {
public:
  /** Checks if device has a SunSpec immediate controls register map */
  bool IsImmediateRegisterMap(void);

  /** Get AC grid connection

   0: standby (disconnected)
   1: operate (connected)
   */
  bool GetAcConnection(bool &state);

  /** Set AC grid connection

   0: standby (disconnected)
   1: operate (connected)
   */
  bool SetAcConnection(const bool &state);
};

#endif /* IMMEDIATEMODEL_H_ */
