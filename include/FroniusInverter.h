/**
	@brief   Class to get data from a Fronius inverter
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef FRONIUSINVERTER_H_
#define FRONIUSINVERTER_H_

#include "InverterModel.h"
#include "FroniusRegister.h"

class FroniusInverter: public InverterModel, public FroniusRegister {

};

#endif /* FRONIUSiNVERTER_H_ */
