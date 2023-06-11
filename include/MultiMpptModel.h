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
		@param string string ID
	*/
	bool GetDcCurrent(double &res, int string_id);

	/** DC voltage

		@param res DC voltage [V]
		@param string string ID
	*/
	bool GetDcVoltage(double &res, int string_id);

	/** DC power

		@param res DC power [W]
		@param string string ID
	*/
	bool GetDcPower(double &res, int string_id);

	/** DC lifetime energy

		@param res DC energy [kWh]
		@param string string ID
	*/
	bool GetDcEnergyLifetime(double &res, int string_id);

	/** Timestamp

		@param ts timestamp [seconds since 01-Jan-2000 00:00 UTC]
		@param string string ID
	*/
	bool GetTimestamp(unsigned int &ts, int string_id);

	/** Temperature

		@param res temperature [°C]
		@param string string ID
	*/
	bool GetDcTemperature(double &res, int string_id);
};

#endif /* MULTIMPPTMODEL_H_ */
