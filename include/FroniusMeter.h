/**
	@brief   Class to get data from a SunSpec compatible Fronius meter
	@author  Alexander Pohl <alex@ahpohl.com>
*/
#ifndef FRONIUSMETER_H_
#define FRONIUSMETER_H_

#include "CommonModel.h"
#include "MeterModel.h"

class FroniusMeter: public CommonModel, public MeterModel
{
public:
	/** Checks if device is a SunSpec compatible meter */
	bool IsSunSpecMeter(void);
};

#endif /* FRONIUSMETER_H_ */
