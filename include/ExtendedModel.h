/**
	@brief   Class to manipulate Extended (Measurements_Status) Model registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef EXTENDEDMODEL_H_
#define EXTENDEDMODEL_H_

#include "SunSpec.h"

class ExtendedModel: virtual public SunSpec
{
public:
	/** Checks if device has a SunSpec extended register map */
	bool IsExtendedRegisterMap(void);

	/** Timestamp seconds since the unix Epoch

	    @note The inverter timezone needs to be set to Etc (GMT)
	*/
	bool GetTimestamp(long int &ts);
};

#endif /* EXTENDEDMODEL_H_ */
