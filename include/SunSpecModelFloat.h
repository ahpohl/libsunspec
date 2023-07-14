#ifndef SUNSPECMODELFLOAT_H_
#define SUNSPECMODELFLOAT_H_

#include <cstdint>

/** @brief Register description of the SunSpec Common model */
namespace CommonRegisterMap
{
	/** Uniquely identifies this as a SunSpec ModBus map.

	    @returns 0x53756e53 ('SunS')
	*/
	struct { uint32_t res = 0; const uint16_t reg = 40001-1; const uint16_t nb = 2;  } C001_SID;

    /** Uniquely identifies this as a SunSpec Common Model block

     	@returns 1
    */
	struct { uint16_t res = 0; const uint16_t reg = 40003-1; const uint16_t nb = 1;  } C001_ID;

	/** Length of Common Model block.

	    @returns 65
	*/
	struct { uint16_t res = 0; const uint16_t reg = 40004-1; const uint16_t nb = 1;  } C001_L;

	/** Manufacturer

	    @returns: Fronius
	*/
	struct { std::string str;  const uint16_t reg = 40005-1; const uint16_t nb = 16; } C001_Mn;

	/** Device model

	    @returns i.e. IG+150V [3p]
	*/
	struct { std::string str;  const uint16_t reg = 40021-1; const uint16_t nb = 16; } C001_Md;

	/** SW version of installed option

	    @returns i.e. Firmware version of Datamanager
	*/
	struct { std::string str;  const uint16_t reg = 40037-1; const uint16_t nb = 8;  } C001_Opt;

	/** SW version of main device

	    @returns i.e. Firmware version of inverter, meter, battery etc.
	*/
	struct { std::string str;  const uint16_t reg = 40045-1; const uint16_t nb = 8;  } C001_Vr;

	/** Serial number of the inverter

        Please note, that the inverter serial number is not supported on all devices and also
        depends on the internal inverter controller‘s production date and its software version.

        If the inverter serial number is not supported, then two fallbacks are implemented that
        are still unique but may not match the inverter serial number printed on the nameplate:

        1: Serial of inverter controller (PMC) if supported
        2: Unique ID (UID) of inverter controller

        For SYMOHYBRID inverters the inverter serial number is not supported and this register
        always contains one of the two implemented fallbacks.

        Please note further that due to startup timing issues or synchronization faults this field
        may change its value during operation from one option to another, e.g. at boot time only UID
        is available and after some time device information is synchronized then this field changes
        from UID to PMC or inverter serial number.
	*/
	struct { std::string str;  const uint16_t reg = 40053-1; const uint16_t nb = 16; } C001_SN;

	/** Read ModBus device address

	    @returns 1-247
	*/
	struct { uint16_t res = 0; const uint16_t reg = 40069-1; const uint16_t nb = 1;  } C001_DA;
};

/** @brief Register description of the Inverter SunSpec model */
namespace InverterRegisterMap
{

};

/** @brief Register description of the Nameplate SunSpec model */
namespace NameplateRegisterMap
{

};

/** @brief Register description of the Extended SunSpec model */
namespace ExtendedRegisterMap
{

}

/** @brief Register description of the SunSpec Immediate Controls model */
namespace ImmediateRegisterMap
{

}

/** @brief Register description of the Multi MPPT SunSpec model */
namespace MultiMpptRegisterMap
{

};

/** @brief Register description of the Fronius specific registers */
namespace FroniusRegisterMap
{
	/** Delete stored ratings of the current inverter by writing 0xFFFF. */
	struct { uint16_t res = 0; const uint16_t reg = 212-1; const uint16_t nb = 1; } F_Delete_Data;

	/** Rating data of all inverters connected to the Fronius Datamanager are persistently stored
	    by writing 0xFFFF.
	*/
	struct { uint16_t res = 0; const uint16_t reg = 213-1; const uint16_t nb = 1; } F_Store_Data;

	/** Current active state code of inverter - Description can be found in inverter manual

	 	Not supported for Fronius Hybrid inverters (because of this inverter status maybe
	 	reported differently during night time compared to other inverter types)
	*/
	struct { uint16_t res = 0; const uint16_t reg = 214-1; const uint16_t nb = 1; } F_Active_State_Code;

	/** Write 0xFFFF to reset all event flags and active state code */
	struct { uint16_t res = 0; const uint16_t reg = 215-1; const uint16_t nb = 1; } F_Reset_All_Event_Flags;

	/** Type of SunSpec models used for inverter and meter data. Write 1 or 2 and then immediately 6
	    to acknowledge setting.

	    1: Floating point
		2: Integer & SF
	*/
	struct { uint16_t res = 0; const uint16_t reg = 216-1; const uint16_t nb = 1; } F_ModelType;

	/** Type of Restrictions reported in BasicStorageControl Model (IC124). Local restrictions
	    are those that are set by ModBus Interface. Global restrictions are those that are set
	    system wide.

	    0: local (default)
	    1: global
	*/
	struct { uint16_t res = 0; const uint16_t reg = 217-1; const uint16_t nb = 1; } F_Storage_Restrictions_View_Mode;

	/** Total power (site sum) of all connected inverters [W]. */
	struct { uint32_t res = 0; const uint16_t reg = 500-1; const uint16_t nb = 2; } F_Site_Power;

	/** Total energy for current day of all connected inverters [Wh]. */
	struct { uint64_t res = 0; const uint16_t reg = 502-1; const uint16_t nb = 4; } F_Site_Energy_Day;

	/** Total energy for last year of all connected inverters [Wh]. */
	struct { uint64_t res = 0; const uint16_t reg = 506-1; const uint16_t nb = 4; } F_Site_Energy_Year;

	/** Total energy of all connected inverters [Wh]. */
	struct { uint64_t res = 0; const uint16_t reg = 510-1; const uint16_t nb = 4; } F_Site_Energy_Total;
};

/** @brief Register description of the Meter specific registers */
namespace MeterRegisterMap
{

};

#endif /* SUNSPECMODELFLOAT_H_ */
