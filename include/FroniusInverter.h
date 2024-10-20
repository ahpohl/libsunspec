/**
 @brief   Class to get data from a SunSpec compatible Fronius inverter
 @author  Alexander Pohl <alex@ahpohl.com>
 */
#ifndef FRONIUSINVERTER_H_
#define FRONIUSINVERTER_H_

#include <string>

#include "CommonModel.h"
#include "ExtendedModel.h"
#include "FroniusRegister.h"
#include "ImmediateModel.h"
#include "InverterModel.h"
#include "MultiMpptModel.h"
#include "NameplateModel.h"

class FroniusInverter : public CommonModel,
                        public InverterModel,
                        public NameplateModel,
                        public ExtendedModel,
                        public ImmediateModel,
                        public MultiMpptModel,
                        public FroniusRegister {
public:
  /** Checks if device is a SunSpec compatible inverter */
  bool IsSunSpecInverter(void);

  /** Fronius state code */
  struct StateCode_t {
    /** State code */
    uint16_t St;
    /** State code as string */
    std::string StStr;
    /** Fronius inverter model */
    std::string Model;
  };

  /** Get Fronius state code */
  bool GetStateCode(StateCode_t &state);

private:
  /** Set Fronius state code string */
  bool SetStateCodeStr(StateCode_t &state);
};

#endif /* FRONIUSINVERTER_H_ */
