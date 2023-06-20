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
};

#endif /* FRONIUSINVERTER_H_ */
