/**
	@brief   Class to manipulate Immediate Controls registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/
#ifndef IMMEDIATEMODEL_H_
#define IMMEDIATEMODEL_H_

#include "SunSpec.h"

class ImmediateModel: virtual public SunSpec
{
public:
	/** Checks if device has a SunSpec immediate controls register map */
	bool IsImmediateRegisterMap(void);
};

#endif /* IMMEDIATEMODEL_H_ */
