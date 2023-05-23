#include <cstdint>
#include "FroniusRegister.h"

const uint16_t FroniusRegister::F_ADDR_Delete_Data                    = 212;
const uint16_t FroniusRegister::F_ADDR_Store_Data                     = 213;
const uint16_t FroniusRegister::F_ADDR_Active_State_Code              = 214;
const uint16_t FroniusRegister::F_ADDR_Reset_All_Event_Flags          = 215;
const uint16_t FroniusRegister::F_ADDR_ModelType                      = 216;
const uint16_t FroniusRegister::F_ADDR_Storage_Restrictions_View_Mode = 217;
const uint16_t FroniusRegister::F_ADDR_Site_Power                     = 500;
const uint16_t FroniusRegister::F_ADDR_Site_Energy_Day                = 502;
const uint16_t FroniusRegister::F_ADDR_Site_Energy_Year               = 506;
const uint16_t FroniusRegister::F_ADDR_Site_Energy_Total              = 510;

const uint16_t FroniusRegister::F_SIZE_Delete_Data                    = 1;
const uint16_t FroniusRegister::F_SIZE_Store_Data                     = 1;
const uint16_t FroniusRegister::F_SIZE_Active_State_Code              = 1;
const uint16_t FroniusRegister::F_SIZE_Reset_All_Event_Flags          = 1;
const uint16_t FroniusRegister::F_SIZE_ModelType                      = 1;
const uint16_t FroniusRegister::F_SIZE_Storage_Restrictions_View_Mode = 1;
const uint16_t FroniusRegister::F_SIZE_Site_Power                     = 2;
const uint16_t FroniusRegister::F_SIZE_Site_Energy_Day                = 4;
const uint16_t FroniusRegister::F_SIZE_Site_Energy_Year               = 4;
const uint16_t FroniusRegister::F_SIZE_Site_Energy_Total              = 4;
