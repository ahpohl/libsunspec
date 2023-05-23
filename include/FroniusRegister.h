/*
 *  Fronius specific registers
 */

#ifndef FRONIUSREGISTER_H_
#define FRONIUSREGISTER_H_

#include <cstdint>

class FroniusRegister
{
public:
	static const uint16_t F_ADDR_Delete_Data;
	static const uint16_t F_ADDR_Store_Data;
	static const uint16_t F_ADDR_Active_State_Code;
	static const uint16_t F_ADDR_Reset_All_Event_Flags;
	static const uint16_t F_ADDR_ModelType;
	static const uint16_t F_ADDR_Storage_Restrictions_View_Mode;
	static const uint16_t F_ADDR_Site_Power;
	static const uint16_t F_ADDR_Site_Energy_Day;
	static const uint16_t F_ADDR_Site_Energy_Year;
	static const uint16_t F_ADDR_Site_Energy_Total;

	static const uint16_t F_SIZE_Delete_Data;
	static const uint16_t F_SIZE_Store_Data;
	static const uint16_t F_SIZE_Active_State_Code;
	static const uint16_t F_SIZE_Reset_All_Event_Flags;
	static const uint16_t F_SIZE_ModelType;
	static const uint16_t F_SIZE_Storage_Restrictions_View_Mode;
	static const uint16_t F_SIZE_Site_Power;
	static const uint16_t F_SIZE_Site_Energy_Day;
	static const uint16_t F_SIZE_Site_Energy_Year;
	static const uint16_t F_SIZE_Site_Energy_Total;
};

#endif /* FRONIUSREGISTER_H_ */
