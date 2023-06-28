/**
	@brief   Class to manipulate Multi MPPT Model registers
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef MULTIMPPTMODEL_H_
#define MULTIMPPTMODEL_H_

#include "SunSpec.h"

class MultiMpptModel: virtual public SunSpec
{
public:
	/** Checks if device has a SunSpec Multi MPPT register map */
	bool IsMultiMpptRegisterMap(void);

	/** DC current

		@param res DC current [A]
		@param string_id string 1 (default) or string 2
	*/
	bool GetDcCurrent(double &res, const int string_id = 1);

	/** DC voltage

		@param res DC voltage [V]
		@param string_id string 1 (default) or string 2
	*/
	bool GetDcVoltage(double &res, const int string_id = 1);

	/** DC power

		@param res DC power [W]
		@param string_id string 1 (default) or string 2
	*/
	bool GetDcPower(double &res, const int string_id = 1);

	/** DC lifetime energy

		@param res DC energy [kWh]
		@param string_id string 1 (default) or string 2
	*/
	bool GetDcEnergyLifetime(double &res, const int string_id = 1);

	/** Temperature

		@param res temperature [°C]
		@param string_id string 1 (default) or string 2
	*/
	bool GetDcTemperature(double &res, const int string_id = 1);
};

#endif /* MULTIMPPTMODEL_H_ */
