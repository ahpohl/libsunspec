#ifndef SUNSPECMODELINTSF_H_
#define SUNSPECMODELINTSF_H_

#include <cstdint>

/** @brief Register description of the Common SunSpec model */
namespace CommonRegisterMap
{
	/** Well-known value. Uniquely identifies this as a SunSpec ModBus map.

	    @returns 0x53756e53 ('SunS')
	*/
	struct { uint32_t res = 0; const uint16_t reg = 40001-1; const uint16_t nb = 2;  } C001_SID;

    /** Well-known value. Uniquely identifies this as a SunSpec Common Model block

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
	/** Uniquely identifies this as a SunSpec inverter ModBus map.

	    @returns 101: single phase
	             102: split phase
	             103: three phase
	*/
	struct { uint16_t res = 0; const uint16_t reg = 40070-1; const uint16_t nb = 1; } I10X_ID;

	/** Length of inverter model block.

	    @returns 50
	 */
	struct { uint16_t res = 0; const uint16_t reg = 40071-1; const uint16_t nb = 1; } I10X_L;

	/** AC total current value [A] */
	struct { uint16_t res = 0; const uint16_t reg = 40072-1; const uint16_t nb = 1; } I10X_A;

	/** AC phase-A current value [A] */
	struct { uint16_t res = 0; const uint16_t reg = 40073-1; const uint16_t nb = 1; } I10X_AphA;

	/** AC phase-B current value [A] */
	struct { uint16_t res = 0; const uint16_t reg = 40074-1; const uint16_t nb = 1; } I10X_AphB;

	/** AC phase-C current value [A] */
	struct { uint16_t res = 0; const uint16_t reg = 40075-1; const uint16_t nb = 1; } I10X_AphC;

	/** AC current scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40076-1; const uint16_t nb = 1; } I10X_A_SF;

	/** AC voltage phase-AB value [V] */
	struct { uint16_t res = 0; const uint16_t reg = 40077-1; const uint16_t nb = 1; } I10X_PPVphAB;

	/** AC voltage phase-BC value [V] */
	struct { uint16_t res = 0; const uint16_t reg = 40078-1; const uint16_t nb = 1; } I10X_PPVphBC;

	/** AC voltage phase-CA value [V] */
	struct { uint16_t res = 0; const uint16_t reg = 40079-1; const uint16_t nb = 1; } I10X_PPVphCA;

	/** AC voltage phase-A-to-neutral value [V] */
	struct { uint16_t res = 0; const uint16_t reg = 40080-1; const uint16_t nb = 1; } I10X_PhVphA;

	/** AC voltage phase-B-to-neutral value [V] */
	struct { uint16_t res = 0; const uint16_t reg = 40081-1; const uint16_t nb = 1; } I10X_PhVphB;

	/** AC voltage phase-C-to-neutral value [V] */
	struct { uint16_t res = 0; const uint16_t reg = 40082-1; const uint16_t nb = 1; } I10X_PhVphC;

	/** AC voltage scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40083-1; const uint16_t nb = 1; } I10X_V_SF;

	/** AC power value [W] */
	struct { int16_t  res = 0; const uint16_t reg = 40084-1; const uint16_t nb = 1; } I10X_W;

	/** AC power scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40085-1; const uint16_t nb = 1; } I10X_W_SF;

	/** AC frequency value [Hz] */
	struct { uint16_t res = 0; const uint16_t reg = 40086-1; const uint16_t nb = 1; } I10X_Hz;

	/** AC frequency scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40087-1; const uint16_t nb = 1; } I10X_Hz_SF;

	/** Apparent power [VA] */
	struct { int16_t  res = 0; const uint16_t reg = 40088-1; const uint16_t nb = 1; } I10X_VA;

	/** Apparent power scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40089-1; const uint16_t nb = 1; } I10X_VA_SF;

	/** Reactive power [VAr] */
	struct { int16_t  res = 0; const uint16_t reg = 40090-1; const uint16_t nb = 1; } I10X_VAr;

	/** Reactive power scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40091-1; const uint16_t nb = 1; } I10X_VAr_SF;

	/** Power factor [%] */
	struct { int16_t  res = 0; const uint16_t reg = 40092-1; const uint16_t nb = 1; } I10X_PF;

	/** Power factor scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40093-1; const uint16_t nb = 1; } I10X_PF_SF;

	/** AC lifetime energy production [Wh] */
	struct { uint32_t res = 0; const uint16_t reg = 40094-1; const uint16_t nb = 2; } I10X_WH;

	/** AC lifetime energy production scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40096-1; const uint16_t nb = 1; } I10X_WH_SF;

	/** DC current value [A]

	    @note Not supported if multiple DC inputs; current can be found in Multiple MPPT model
	*/
	struct { uint16_t res = 0; const uint16_t reg = 40097-1; const uint16_t nb = 1; } I10X_DCA;

	/** DC current scale factor

	    @note Not supported if multiple DC inputs.
	*/
	struct { int16_t  res = 0; const uint16_t reg = 40098-1; const uint16_t nb = 1; } I10X_DCA_SF;

	/** DC voltage value [V]

	    @note Not supported if multiple DC inputs; voltage can be found in Multiple MPPT model
	*/
	struct { uint16_t res = 0; const uint16_t reg = 40099-1; const uint16_t nb = 1; } I10X_DCV;

	/** DC voltage scale factor

	    @note Not supported if multiple DC inputs.
	*/
	struct { int16_t  res = 0; const uint16_t reg = 40100-1; const uint16_t nb = 1; } I10X_DCV_SF;

	/** DC power value [W]

	    @note Total power of all DC inputs.
	*/
	struct { int16_t  res = 0; const uint16_t reg = 40101-1; const uint16_t nb = 1; } I10X_DCW;

	/** DC power value scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40102-1; const uint16_t nb = 1; } I10X_DCW_SF;

	/** Cabinet temperature [°C]

	  	@note Not supported
	*/
	struct { int16_t  res = 0; const uint16_t reg = 40103-1; const uint16_t nb = 1; } I10X_TmpCab;

	/** Coolant or heat sink temperature [°C]

	    @note Not supported
	 */
	struct { int16_t  res = 0; const uint16_t reg = 40104-1; const uint16_t nb = 1; } I10X_TmpSnk;

	/** Transformer temperature [°C]

	    @note Not supported
	*/
	struct { int16_t  res = 0; const uint16_t reg = 40105-1; const uint16_t nb = 1; } I10X_TmpTrns;

	/** Other temperature [°C]

	    @note Not supported
	*/
	struct { int16_t  res = 0; const uint16_t reg = 40106-1; const uint16_t nb = 1; } I10X_TmpOt;

	/** Temperature scale factor */
	struct { int16_t  res = 0; const uint16_t reg = 40107-1; const uint16_t nb = 1; } I10X_Tmp_SF;

	/** Operating state */
	struct { uint16_t res = 0; const uint16_t reg = 40108-1; const uint16_t nb = 1; } I10X_St;

	/** Vendor defined operating state */
	struct { uint16_t res = 0; const uint16_t reg = 40109-1; const uint16_t nb = 1; } I10X_StVnd;

	/** Event flags (bits 0-31) */
	struct { uint32_t res = 0; const uint16_t reg = 40110-1; const uint16_t nb = 2; } I10X_Evt1;

	/** Event flags (bits 32-63) */
	struct { uint32_t res = 0; const uint16_t reg = 40112-1; const uint16_t nb = 2; } I10X_Evt2;

	/** Vendor defined event flags (bits 0-31) */
	struct { uint32_t res = 0; const uint16_t reg = 40114-1; const uint16_t nb = 2; } I10X_EvtVnd1;

	/** Vendor defined event flags (bits 32-63) */
	struct { uint32_t res = 0; const uint16_t reg = 40116-1; const uint16_t nb = 2; } I10X_EvtVnd2;

	/** Vendor defined event flags (bits 63-95) */
	struct { uint32_t res = 0; const uint16_t reg = 40118-1; const uint16_t nb = 2; } I10X_EvtVnd3;

	/** Vendor defined event flags (bits 96-127) */
	struct { uint32_t res = 0; const uint16_t reg = 40120-1; const uint16_t nb = 2; } I10X_EvtVnd4;
};

/** @brief Register description of the Multi MPPT Model registers */
namespace MultiMpptRegisterMap
{
	struct { uint16_t res = 0; const uint16_t reg = 40254; const uint16_t nb = 1; } I160_ID;
	struct { uint16_t res = 0; const uint16_t reg = 40255; const uint16_t nb = 1; } I160_L;
	struct { int16_t  res = 0; const uint16_t reg = 40256; const uint16_t nb = 1; } I160_DCA_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40257; const uint16_t nb = 1; } I160_DCV_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40258; const uint16_t nb = 1; } I160_DCW_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40259; const uint16_t nb = 1; } I160_DCWH_SF;
	struct { uint32_t res = 0; const uint16_t reg = 40260; const uint16_t nb = 2; } I160_Evt;
	struct { uint16_t res = 0; const uint16_t reg = 40262; const uint16_t nb = 1; } I160_N;
	struct { uint16_t res = 0; const uint16_t reg = 40263; const uint16_t nb = 1; } I160_TmsPer;
	struct { uint16_t res = 0; const uint16_t reg = 40264; const uint16_t nb = 1; } I160_1_ID;
	struct { std::string str;  const uint16_t reg = 40265; const uint16_t nb = 8; } I160_1_IDStr;
	struct { uint16_t res = 0; const uint16_t reg = 40273; const uint16_t nb = 1; } I160_1_DCA;
	struct { uint16_t res = 0; const uint16_t reg = 40274; const uint16_t nb = 1; } I160_1_DCV;
	struct { uint16_t res = 0; const uint16_t reg = 40275; const uint16_t nb = 1; } I160_1_DCW;
	struct { uint32_t res = 0; const uint16_t reg = 40276; const uint16_t nb = 2; } I160_1_DCWH;
	struct { uint32_t res = 0; const uint16_t reg = 40278; const uint16_t nb = 2; } I160_1_Tms;
	struct { int16_t  res = 0; const uint16_t reg = 40280; const uint16_t nb = 1; } I160_1_Tmp;
	struct { uint16_t res = 0; const uint16_t reg = 40281; const uint16_t nb = 1; } I160_1_DCSt;
	struct { uint32_t res = 0; const uint16_t reg = 40282; const uint16_t nb = 2; } I160_1_DCEvt;
	struct { uint16_t res = 0; const uint16_t reg = 40284; const uint16_t nb = 1; } I160_2_ID;
	struct { std::string str;  const uint16_t reg = 40285; const uint16_t nb = 8; } I160_2_IDStr;
	struct { uint16_t res = 0; const uint16_t reg = 40293; const uint16_t nb = 1; } I160_2_DCA;
	struct { uint16_t res = 0; const uint16_t reg = 40294; const uint16_t nb = 1; } I160_2_DCV;
	struct { uint16_t res = 0; const uint16_t reg = 40295; const uint16_t nb = 1; } I160_2_DCW;
	struct { uint32_t res = 0; const uint16_t reg = 40296; const uint16_t nb = 2; } I160_2_DCWH;
	struct { uint32_t res = 0; const uint16_t reg = 40298; const uint16_t nb = 2; } I160_2_Tms;
	struct { int16_t  res = 0; const uint16_t reg = 40300; const uint16_t nb = 1; } I160_2_Tmp;
	struct { uint16_t res = 0; const uint16_t reg = 40301; const uint16_t nb = 1; } I160_2_DCSt;
	struct { uint32_t res = 0; const uint16_t reg = 40302; const uint16_t nb = 2; } I160_2_DCEvt;
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

#endif /* SUNSPECMODELINTSF_H_ */
