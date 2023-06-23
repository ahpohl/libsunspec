/**
	@brief   Class to get data from a SunSpec compatible Fronius inverter
	@author  Alexander Pohl <alex@ahpohl.com>
*/
#ifndef FRONIUSINVERTER_H_
#define FRONIUSINVERTER_H_

#include <string>

#include "CommonModel.h"
#include "InverterModel.h"
#include "NameplateModel.h"
#include "MultiMpptModel.h"
#include "FroniusRegister.h"

class FroniusInverter: public CommonModel, public InverterModel,
	public NameplateModel, public MultiMpptModel, public FroniusRegister
{
public:
	/** Checks if device is a SunSpec compatible inverter */
	bool IsSunSpecInverter(void);

	/** Fronius state code */
	struct StateCode_t {
		uint16_t St;
		std::string StStr;
		std::string Model;
	};

	/** Get Fronius state code */
	bool GetStateCode(StateCode_t &state);

private:
	/** Set Fronius state code string */
	bool SetStateCodeStr(StateCode_t &state);
};

#endif /* FRONIUSINVERTER_H_ */
