#ifndef SUNSPECMODELINTSF_H_
#define SUNSPECMODELINTSF_H_

#include <cstdint>

/** @brief Register description of the SunSpec Common model */
namespace CommonRegisterMapIntSf {
/** Uniquely identifies this as a SunSpec ModBus map.

 @returns 0x53756e53 ('SunS')
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40001 - 1;
  const uint16_t nb = 2;
} C001_SID;

/** Uniquely identifies this as a SunSpec Common Model block

 @returns 1
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40003 - 1;
  const uint16_t nb = 1;
} C001_ID;

/** Length of Common Model block.

 @returns 65
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40004 - 1;
  const uint16_t nb = 1;
} C001_L;

/** Manufacturer

 @returns: Fronius
 */
struct {
  std::string str;
  const uint16_t reg = 40005 - 1;
  const uint16_t nb = 16;
} C001_Mn;

/** Device model

 @returns i.e. IG+150V [3p]
 */
struct {
  std::string str;
  const uint16_t reg = 40021 - 1;
  const uint16_t nb = 16;
} C001_Md;

/** SW version of installed option

 @returns i.e. Firmware version of Datamanager
 */
struct {
  std::string str;
  const uint16_t reg = 40037 - 1;
  const uint16_t nb = 8;
} C001_Opt;

/** SW version of main device

 @returns i.e. Firmware version of inverter, meter, battery etc.
 */
struct {
  std::string str;
  const uint16_t reg = 40045 - 1;
  const uint16_t nb = 8;
} C001_Vr;

/** Serial number of the inverter

 Please note, that the inverter serial number is not supported on all devices
 and also depends on the internal inverter controller‘s production date and its
 software version.

 If the inverter serial number is not supported, then two fallbacks are
 implemented that are still unique but may not match the inverter serial number
 printed on the nameplate:

 1: Serial of inverter controller (PMC) if supported
 2: Unique ID (UID) of inverter controller

 For SYMOHYBRID inverters the inverter serial number is not supported and this
 register always contains one of the two implemented fallbacks.

 Please note further that due to startup timing issues or synchronization faults
 this field may change its value during operation from one option to another,
 e.g. at boot time only UID is available and after some time device information
 is synchronized then this field changes from UID to PMC or inverter serial
 number.
 */
struct {
  std::string str;
  const uint16_t reg = 40053 - 1;
  const uint16_t nb = 16;
} C001_SN;

/** Read ModBus device address

 @returns 1-247
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40069 - 1;
  const uint16_t nb = 1;
} C001_DA;
} // namespace CommonRegisterMapIntSf

/** @brief Register description of the Inverter SunSpec model */
namespace InverterRegisterMapIntSf {
/** Uniquely identifies this as a SunSpec inverter ModBus map.

 @returns 101: single phase
 102: split phase
 103: three phase
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40070 - 1;
  const uint16_t nb = 1;
} I10X_ID;

/** Length of inverter model block.

 @returns 50
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40071 - 1;
  const uint16_t nb = 1;
} I10X_L;

/** AC total current value [A] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40072 - 1;
  const uint16_t nb = 1;
} I10X_A;

/** AC phase-A current value [A] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40073 - 1;
  const uint16_t nb = 1;
} I10X_AphA;

/** AC phase-B current value [A] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40074 - 1;
  const uint16_t nb = 1;
} I10X_AphB;

/** AC phase-C current value [A] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40075 - 1;
  const uint16_t nb = 1;
} I10X_AphC;

/** AC current scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40076 - 1;
  const uint16_t nb = 1;
} I10X_A_SF;

/** AC voltage phase-AB value [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40077 - 1;
  const uint16_t nb = 1;
} I10X_PPVphAB;

/** AC voltage phase-BC value [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40078 - 1;
  const uint16_t nb = 1;
} I10X_PPVphBC;

/** AC voltage phase-CA value [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40079 - 1;
  const uint16_t nb = 1;
} I10X_PPVphCA;

/** AC voltage phase-A-to-neutral value [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40080 - 1;
  const uint16_t nb = 1;
} I10X_PhVphA;

/** AC voltage phase-B-to-neutral value [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40081 - 1;
  const uint16_t nb = 1;
} I10X_PhVphB;

/** AC voltage phase-C-to-neutral value [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40082 - 1;
  const uint16_t nb = 1;
} I10X_PhVphC;

/** AC voltage scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40083 - 1;
  const uint16_t nb = 1;
} I10X_V_SF;

/** AC power value [W] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40084 - 1;
  const uint16_t nb = 1;
} I10X_W;

/** AC power scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40085 - 1;
  const uint16_t nb = 1;
} I10X_W_SF;

/** AC frequency value [Hz] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40086 - 1;
  const uint16_t nb = 1;
} I10X_Hz;

/** AC frequency scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40087 - 1;
  const uint16_t nb = 1;
} I10X_Hz_SF;

/** Apparent power [VA] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40088 - 1;
  const uint16_t nb = 1;
} I10X_VA;

/** Apparent power scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40089 - 1;
  const uint16_t nb = 1;
} I10X_VA_SF;

/** Reactive power [VAr] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40090 - 1;
  const uint16_t nb = 1;
} I10X_VAr;

/** Reactive power scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40091 - 1;
  const uint16_t nb = 1;
} I10X_VAr_SF;

/** Power factor [%] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40092 - 1;
  const uint16_t nb = 1;
} I10X_PF;

/** Power factor scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40093 - 1;
  const uint16_t nb = 1;
} I10X_PF_SF;

/** AC lifetime energy production [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40094 - 1;
  const uint16_t nb = 2;
} I10X_WH;

/** AC lifetime energy production scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40096 - 1;
  const uint16_t nb = 1;
} I10X_WH_SF;

/** DC current value [A]

 @note Not supported if multiple DC inputs; current can be found in Multiple
 MPPT model
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40097 - 1;
  const uint16_t nb = 1;
} I10X_DCA;

/** DC current scale factor

 @note Not supported if multiple DC inputs.
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40098 - 1;
  const uint16_t nb = 1;
} I10X_DCA_SF;

/** DC voltage value [V]

 @note Not supported if multiple DC inputs; voltage can be found in Multiple
 MPPT model
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40099 - 1;
  const uint16_t nb = 1;
} I10X_DCV;

/** DC voltage scale factor

 @note Not supported if multiple DC inputs.
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40100 - 1;
  const uint16_t nb = 1;
} I10X_DCV_SF;

/** DC power value [W]

 @note Total power of all DC inputs.
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40101 - 1;
  const uint16_t nb = 1;
} I10X_DCW;

/** DC power value scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40102 - 1;
  const uint16_t nb = 1;
} I10X_DCW_SF;

/** Cabinet temperature [°C]

 @note Not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40103 - 1;
  const uint16_t nb = 1;
} I10X_TmpCab;

/** Coolant or heat sink temperature [°C]

 @note Not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40104 - 1;
  const uint16_t nb = 1;
} I10X_TmpSnk;

/** Transformer temperature [°C]

 @note Not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40105 - 1;
  const uint16_t nb = 1;
} I10X_TmpTrns;

/** Other temperature [°C]

 @note Not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40106 - 1;
  const uint16_t nb = 1;
} I10X_TmpOt;

/** Temperature scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40107 - 1;
  const uint16_t nb = 1;
} I10X_Tmp_SF;

/** Operating state */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40108 - 1;
  const uint16_t nb = 1;
} I10X_St;

/** Vendor defined operating state */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40109 - 1;
  const uint16_t nb = 1;
} I10X_StVnd;

/** Event flags (bits 0-31) */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40110 - 1;
  const uint16_t nb = 2;
} I10X_Evt1;

/** Event flags (bits 32-63) */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40112 - 1;
  const uint16_t nb = 2;
} I10X_Evt2;

/** Vendor defined event flags (bits 0-31) */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40114 - 1;
  const uint16_t nb = 2;
} I10X_EvtVnd1;

/** Vendor defined event flags (bits 32-63) */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40116 - 1;
  const uint16_t nb = 2;
} I10X_EvtVnd2;

/** Vendor defined event flags (bits 64-95) */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40118 - 1;
  const uint16_t nb = 2;
} I10X_EvtVnd3;

/** Vendor defined event flags (bits 96-127) */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40120 - 1;
  const uint16_t nb = 2;
} I10X_EvtVnd4;
} // namespace InverterRegisterMapIntSf

/** @brief Register description of the Nameplate SunSpec model */
namespace NameplateRegisterMapIntSf {
/** Uniquely identifies this as a SunSpec Nameplate Model

 @returns 120
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40122 - 1;
  const uint16_t nb = 1;
} I120_ID;

/** Length of Nameplate Model block.

 @returns 26
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40123 - 1;
  const uint16_t nb = 1;
} I120_L;

/** Type of DER device. Default value is 4 to indicate PV device. */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40124 - 1;
  const uint16_t nb = 1;
} I120_DERTyp;

/** Continuous power output capability of the inverter.

 @returns power output [W]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40125 - 1;
  const uint16_t nb = 1;
} I120_WRtg;

/** Continuous power output scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40126 - 1;
  const uint16_t nb = 1;
} I120_WRtg_SF;

/** Continuous Volt-Ampere capability of the inverter.

 @returns apparent power [VA]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40127 - 1;
  const uint16_t nb = 1;
} I120_VARtg;

/** Continuous Volt-Ampere capability scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40128 - 1;
  const uint16_t nb = 1;
} I120_VARtg_SF;

/** Continuous VAR capability of the inverter in quadrant 1.

 @returns reactive power q1 [VAr]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40129 - 1;
  const uint16_t nb = 1;
} I120_VArRtgQ1;

/** Continuous VAR capability of the inverter in quadrant 2.

 @note not supported
 @returns reactive power q2 [VAr]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40130 - 1;
  const uint16_t nb = 1;
} I120_VArRtgQ2;

/** Continuous VAR capability of the inverter in quadrant 3.

 @note not supported
 @returns reactive power q3 [VAr]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40131 - 1;
  const uint16_t nb = 1;
} I120_VArRtgQ3;

/** Continuous VAR capability of the inverter in quadrant 4.

 @returns reactive power q4 [VAr]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40132 - 1;
  const uint16_t nb = 1;
} I120_VArRtgQ4;

/** Continuous VAR capability scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40133 - 1;
  const uint16_t nb = 1;
} I120_VArRtg_SF;

/** Maximum RMS AC current level capability of the inverter.

 @returns AC current [A]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40134 - 1;
  const uint16_t nb = 1;
} I120_ARtg;

/** Maximum RMS AC current level scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40135 - 1;
  const uint16_t nb = 1;
} I120_ARtg_SF;

/** Minimum power factor capability of the inverter in quadrant 1.

 @returns power factor Q1 [cos(phi)]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40136 - 1;
  const uint16_t nb = 1;
} I120_PFRtgQ1;

/** Minimum power factor capability of the inverter in quadrant 2.

 @note not supported
 @returns power factor Q2 [cos(phi)]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40137 - 1;
  const uint16_t nb = 1;
} I120_PFRtgQ2;

/** Minimum power factor capability of the inverter in quadrant 3.

 @note not supported
 @returns power factor Q3 [cos(phi)]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40138 - 1;
  const uint16_t nb = 1;
} I120_PFRtgQ3;

/** Minimum power factor capability of the inverter in quadrant 4.

 @returns power factor Q4 [cos(phi)]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40139 - 1;
  const uint16_t nb = 1;
} I120_PFRtgQ4;

/** Minimum power factor capability scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40140 - 1;
  const uint16_t nb = 1;
} I120_PFRtg_SF;

/** Nominal energy rating of storage device.

 @returns energy rating [Wh]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40141 - 1;
  const uint16_t nb = 1;
} I120_WHRtg;

/** Nominal energy rating scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40142 - 1;
  const uint16_t nb = 1;
} I120_WHRtg_SF;

/** The usable capacity of the battery. Maximum charge minus minimum charge
 from a technology capability perspective (Amp-hour capacity rating).

 @note not supported
 @returns capacity [AH]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40143 - 1;
  const uint16_t nb = 1;
} I120_AhrRtg;

/** Scale factor for amp-hour rating.

 @note not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40144 - 1;
  const uint16_t nb = 1;
} I120_AhrRtg_SF;

/** Maximum rate of energy transfer into the storage device

 @returns transfer power [W]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40145 - 1;
  const uint16_t nb = 1;
} I120_MaxChaRte;

/** Charge rate scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40146 - 1;
  const uint16_t nb = 1;
} I120_MaxChaRte_SF;

/** Maximum rate of energy transfer out of the storage device.

 @returns transfer power [W]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40147 - 1;
  const uint16_t nb = 1;
} I120_MaxDisChaRte;

/** Discharge rate scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40148 - 1;
  const uint16_t nb = 1;
} I120_MaxDisChaRte_SF;
} // namespace NameplateRegisterMapIntSf

/** @brief Register description of the Extended SunSpec model */
namespace ExtendedRegisterMapIntSf {
/** Uniquely identifies this as a SunSpec Extended (Measurements_Status) Model

 @returns 122
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40182 - 1;
  const uint16_t nb = 1;
} I122_ID;

/** Length of Extended Model block.

 @returns 44
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40183 - 1;
  const uint16_t nb = 1;
} I122_L;

/** PV inverter present/available status.

 Bit 0: Connected
 Bit 1: Available
 Bit 2: Operating
 Bit 3: Test
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40184 - 1;
  const uint16_t nb = 1;
} I122_PVConn;

/** Storage inverter present/available status.

 bit 0: Connected
 bit 1: Available
 bit 2: Operating
 bit 3: Test
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40185 - 1;
  const uint16_t nb = 1;
} I122_StorConn;

/** ECP connection status

 0: Disconnected
 1: Connected
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40186 - 1;
  const uint16_t nb = 1;
} I122_ECPConn;

/** AC lifetime active (real) energy output [Wh] */
struct {
  uint64_t res = 0;
  const uint16_t reg = 40187 - 1;
  const uint16_t nb = 4;
} I122_ActWh;

/** AC lifetime apparent energy output [VAh]

 @note not supported
 */
struct {
  uint64_t res = 0;
  const uint16_t reg = 40191 - 1;
  const uint16_t nb = 4;
} I122_ActVAh;

/** AC lifetime reactive energy output in quadrant 1 [VArh]

 @note not supported
 */
struct {
  uint64_t res = 0;
  const uint16_t reg = 40195 - 1;
  const uint16_t nb = 4;
} I122_ActVArhQ1;

/** AC lifetime reactive energy output in quadrant 2 [VArh]

 @note not supported
 */
struct {
  uint64_t res = 0;
  const uint16_t reg = 40199 - 1;
  const uint16_t nb = 4;
} I122_ActVArhQ2;

/** AC lifetime reactive energy output in quadrant 3 [VArh]

 @note not supported
 */
struct {
  uint64_t res = 0;
  const uint16_t reg = 40203 - 1;
  const uint16_t nb = 4;
} I122_ActVArhQ3;

/** AC lifetime reactive energy output in quadrant 4 [VArh]

 @note not supported
 */
struct {
  uint64_t res = 0;
  const uint16_t reg = 40207 - 1;
  const uint16_t nb = 4;
} I122_ActVArhQ4;

/** Amount of VARs available without impacting output [VArh]

 @note not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40211 - 1;
  const uint16_t nb = 1;
} I122_VArAval;

/** Scale factor for available VARs

 @note not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40212 - 1;
  const uint16_t nb = 1;
} I122_VArAval_SF;

/** Amount of power available [W]

 @note not supported
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40213 - 1;
  const uint16_t nb = 1;
} I122_WAval;

/** Scale factor for available power

 @note not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40214 - 1;
  const uint16_t nb = 1;
} I122_WAval_SF;

/** Bit Mask indicating set point limit(s) reached.
 Bits are persistent and must be cleared by the controller.

 @note not supported.
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40215 - 1;
  const uint16_t nb = 2;
} I122_StSetLimMsk;

/** Bit Mask indicating which inverter controls are currently active.

 Bit 0: FixedW
 Bit 1: FixedVAR
 Bit 2: FixedPF
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40217 - 1;
  const uint16_t nb = 2;
} I122_StActCtl;

/** Source of time synchronization.

 @returns RTC
 */
struct {
  std::string str;
  const uint16_t reg = 40219 - 1;
  const uint16_t nb = 4;
} I122_TmSrc;

/** Timestamp seconds since 01-01-2000 00:00 UTC */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40223 - 1;
  const uint16_t nb = 2;
} I122_Tms;

/** Bit Mask indicating which voltage ride through modes are currently active.

 @note not supported
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40225 - 1;
  const uint16_t nb = 1;
} I122_RtSt;

/** Isolation resistance Riso [Ohm]

 @note not supported
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40226 - 1;
  const uint16_t nb = 1;
} I112_Ris;

/** Scale factor for Isolation resistance

 @note not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40227 - 1;
  const uint16_t nb = 1;
} I122_Ris_SF;
} // namespace ExtendedRegisterMapIntSf

/** @brief Register description of the SunSpec Immediate Controls model */
namespace ImmediateRegisterMapIntSf {
/** Uniquely identifies this as a SunSpec Immediate Controls model

 @returns 123
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40228 - 1;
  const uint16_t nb = 1;
} I123_ID;

/** Length of the SunSpec Immediate Controls model

 @returns 24
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40229 - 1;
  const uint16_t nb = 1;
} I123_L;

/** Time window for connect/disconnect [s] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40230 - 1;
  const uint16_t nb = 1;
} I123_Conn_WinTms;

/** Timeout period for connect/disconnect [s] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40231 - 1;
  const uint16_t nb = 1;
} I123_Conn_RvrtTms;

/** Connection control

 0: Disconnected
 1: Connected
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40232 - 1;
  const uint16_t nb = 1;
} I123_Conn;

/** Set power output to specified level [%] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40233 - 1;
  const uint16_t nb = 1;
} I123_WMaxLimPct;

/** Time window for power limit change

 @returns 0-300 [s]

 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40234 - 1;
  const uint16_t nb = 1;
} I123_WMaxLimPct_WinTms;

/** Timeout period for power limit

 @returns 0-28800 [s]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40235 - 1;
  const uint16_t nb = 1;
} I123_WMaxLimPct_RvrtTms;

/** Ramp time for moving from current setpoint to new setpoint

 @returns 0-65534 [s] (0xFFFF has the same effect as 0x0000)
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40236 - 1;
  const uint16_t nb = 1;
} I123_WMaxLimPct_RmpTms;

/** Throttle enable/disable control

 0: Disabled
 1: Enabled
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40237 - 1;
  const uint16_t nb = 1;
} I123_WMaxLim_Ena;

/** Set power factor to specific value

 @returns 0.8 to 1.0 and -0.8 to -0.999 [cos phi]
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40238 - 1;
  const uint16_t nb = 1;
} I123_OutPFSet;

/** Time window for power factor change

 @returns 0-300 [s]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40239 - 1;
  const uint16_t nb = 1;
} I123_OutPFSet_WinTms;

/** Timeout period for power factor

 @returns 0-28800 [s]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40240 - 1;
  const uint16_t nb = 1;
} I123_OutPFSet_RvrtTms;

/** Ramp time for moving from current setpoint to new setpoint

 @returns 0-65534 [s] (0xFFFF has the same effect as 0x0000)
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40241 - 1;
  const uint16_t nb = 1;
} I123_OutPFSet_RmpTms;

/** Fixed power factor enable/disable control

 0: Disabled
 1: Enabled
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40242 - 1;
  const uint16_t nb = 1;
} I123_OutPFSet_Ena;

/** Reactive power in percent of I_WMax

 @note not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40243 - 1;
  const uint16_t nb = 1;
} I123_VArWMaxPct;

/** Reactive power in percent of I_VArMax */
struct {
  int16_t res = 0;
  const uint16_t reg = 40244 - 1;
  const uint16_t nb = 1;
} I123_VArMaxPct;

/** Reactive power in percent of I_VArAval

 @note not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40245 - 1;
  const uint16_t nb = 1;
} I123_VArAvalPct;

/** Time window for VAR limit change

 @returns 0-300 [s]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40246 - 1;
  const uint16_t nb = 1;
} I123_VArPct_WinTms;

/** Timeout period for VAR limit

 @returns 0-28800 [s]
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40247 - 1;
  const uint16_t nb = 1;
} I123_VArPct_RvrtTms;

/** Ramp time for moving from current setpoint to new setpoint

 @returns 0-65534 [s] (0xFFFF has the same effect as 0x0000)
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40248 - 1;
  const uint16_t nb = 1;
} I123_VArPct_RmpTms;

/** VAR limit mode

 2: VAR limit as a % of VArMax
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40249 - 1;
  const uint16_t nb = 1;
} I123_VArPct_Mod;

/** Fixed VAR enable/disable control

 0: Disabled
 1: Enabled
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40250 - 1;
  const uint16_t nb = 1;
} I123_VArPct_Ena;

/** Scale factor for power output percent

 @returns -2
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40251 - 1;
  const uint16_t nb = 1;
} I123_WMaxLimPct_SF;

/** Scale factor for power factor

 @returns -3
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40252 - 1;
  const uint16_t nb = 1;
} I123_OutPFSet_SF;

/** Scale factor for reactive power

 @returns 0
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40253 - 1;
  const uint16_t nb = 1;
} I123_VArPct_SF;
} // namespace ImmediateRegisterMapIntSf

/** @brief Register description of the Multi MPPT SunSpec model */
namespace MultiMpptRegisterMapIntSf {
/** Uniquely identifies this as a SunSpec Multiple MPPT Inverter Extension Model
 mode

 @returns 160
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40254 - 1;
  const uint16_t nb = 1;
} I160_ID;

/** Length of Multiple MPPT Inverter Extension Model

 @returns 48
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40255 - 1;
  const uint16_t nb = 1;
} I160_L;

/** DC current scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40256 - 1;
  const uint16_t nb = 1;
} I160_DCA_SF;

/** DC voltage scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40257 - 1;
  const uint16_t nb = 1;
} I160_DCV_SF;

/** DC power scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40258 - 1;
  const uint16_t nb = 1;
} I160_DCW_SF;

/** DC energy scale factor

 @note Not supported for Fronius Hybrid inverters
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40259 - 1;
  const uint16_t nb = 1;
} I160_DCWH_SF;

/** Global Events */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40260 - 1;
  const uint16_t nb = 2;
} I160_Evt;

/** Number of modules

 @returns 2
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40262 - 1;
  const uint16_t nb = 1;
} I160_N;

/** Timestamp Period

 @note not supported
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40263 - 1;
  const uint16_t nb = 1;
} I160_TmsPer;

/** Input ID

 @returns 1
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40264 - 1;
  const uint16_t nb = 1;
} I160_1_ID;

/** Input ID string

 @returns String 1
 */
struct {
  std::string str;
  const uint16_t reg = 40265 - 1;
  const uint16_t nb = 8;
} I160_1_IDStr;

/** DC current [A] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40273 - 1;
  const uint16_t nb = 1;
} I160_1_DCA;

/** DC voltage [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40274 - 1;
  const uint16_t nb = 1;
} I160_1_DCV;

/** DC power [V] */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40275 - 1;
  const uint16_t nb = 1;
} I160_1_DCW;

/** DC lifetime energy [Wh]

 @note not supported for Fronius Hybrid inverters
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40276 - 1;
  const uint16_t nb = 2;
} I160_1_DCWH;

/** Timestamp since 01-Jan-2000 00:00 UTC */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40278 - 1;
  const uint16_t nb = 2;
} I160_1_Tms;

/** Temperature [°C] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40280 - 1;
  const uint16_t nb = 1;
} I160_1_Tmp;

/** Operating state */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40281 - 1;
  const uint16_t nb = 1;
} I160_1_DCSt;

/** Module events */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40282 - 1;
  const uint16_t nb = 2;
} I160_1_DCEvt;

/** Input ID string 2

 @returns 2
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40284 - 1;
  const uint16_t nb = 1;
} I160_2_ID;

/** Input ID string 2

 @returns "String 2" or "not supported"
 */
struct {
  std::string str;
  const uint16_t reg = 40285 - 1;
  const uint16_t nb = 8;
} I160_2_IDStr;

/** DC current [A] string 2

 @note not supported if only one DC input.
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40293 - 1;
  const uint16_t nb = 1;
} I160_2_DCA;

/** DC voltage [V] string 2

 @note not supported if only one DC input.
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40294 - 1;
  const uint16_t nb = 1;
} I160_2_DCV;

/** DC power [V] string 2

 @note not supported if only one DC input.
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40295 - 1;
  const uint16_t nb = 1;
} I160_2_DCW;

/** DC lifetime energy [Wh] string 2

 @note not supported for Fronius Hybrid inverters
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40296 - 1;
  const uint16_t nb = 2;
} I160_2_DCWH;

/** Timestamp since 01-Jan-2000 00:00 UTC string 2

 @note not supported if only one DC input.
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40298 - 1;
  const uint16_t nb = 2;
} I160_2_Tms;

/** Temperature [°C] string 2

 @note not supported if only one DC input.
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40300 - 1;
  const uint16_t nb = 1;
} I160_2_Tmp;

/** Operating state string 2

 @note not supported if only one DC input.
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40301 - 1;
  const uint16_t nb = 1;
} I160_2_DCSt;

/** Module events string 2

 @note not supported if only one DC input.
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40302 - 1;
  const uint16_t nb = 2;
} I160_2_DCEvt;
} // namespace MultiMpptRegisterMapIntSf

/** @brief Register description of the Fronius specific registers */
namespace FroniusRegisterMapIntSf {
/** Delete stored ratings of the current inverter by writing 0xFFFF. */
struct {
  uint16_t res = 0;
  const uint16_t reg = 212 - 1;
  const uint16_t nb = 1;
} F_Delete_Data;

/** Rating data of all inverters connected to the Fronius Datamanager are
 persistently stored by writing 0xFFFF.
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 213 - 1;
  const uint16_t nb = 1;
} F_Store_Data;

/** Current active state code of inverter - Description can be found in inverter
 manual

 Not supported for Fronius Hybrid inverters (because of this inverter status
 maybe reported differently during night time compared to other inverter types)
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 214 - 1;
  const uint16_t nb = 1;
} F_Active_State_Code;

/** Write 0xFFFF to reset all event flags and active state code */
struct {
  uint16_t res = 0;
  const uint16_t reg = 215 - 1;
  const uint16_t nb = 1;
} F_Reset_All_Event_Flags;

/** Type of SunSpec models used for inverter and meter data. Write 1 or 2 and
 then immediately 6 to acknowledge setting.

 1: Floating point
 2: Integer & SF
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 216 - 1;
  const uint16_t nb = 1;
} F_ModelType;

/** Type of Restrictions reported in BasicStorageControl Model (IC124). Local
 restrictions are those that are set by ModBus Interface. Global restrictions
 are those that are set system wide.

 0: local (default)
 1: global
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 217 - 1;
  const uint16_t nb = 1;
} F_Storage_Restrictions_View_Mode;

/** Total power (site sum) of all connected inverters [W]. */
struct {
  uint32_t res = 0;
  const uint16_t reg = 500 - 1;
  const uint16_t nb = 2;
} F_Site_Power;

/** Total energy for current day of all connected inverters [Wh]. */
struct {
  uint64_t res = 0;
  const uint16_t reg = 502 - 1;
  const uint16_t nb = 4;
} F_Site_Energy_Day;

/** Total energy for last year of all connected inverters [Wh]. */
struct {
  uint64_t res = 0;
  const uint16_t reg = 506 - 1;
  const uint16_t nb = 4;
} F_Site_Energy_Year;

/** Total energy of all connected inverters [Wh]. */
struct {
  uint64_t res = 0;
  const uint16_t reg = 510 - 1;
  const uint16_t nb = 4;
} F_Site_Energy_Total;
} // namespace FroniusRegisterMapIntSf

/** @brief Register description of the Meter specific registers */
namespace MeterRegisterMapIntSf {
/** Uniquely identifies this as a SunSpec Meter Modbus Map

 201: single phase
 202: split phase
 203: three phase
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40070 - 1;
  const uint16_t nb = 1;
} M20X_ID;

/** Length of meter model block

 @returns 105
 */
struct {
  uint16_t res = 0;
  const uint16_t reg = 40071 - 1;
  const uint16_t nb = 1;
} M20X_L;

/** AC total current [A] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40072 - 1;
  const uint16_t nb = 1;
} M20X_A;

/** AC phase-A current [A] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40073 - 1;
  const uint16_t nb = 1;
} M20X_AphA;

/** AC phase-B current [A] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40074 - 1;
  const uint16_t nb = 1;
} M20X_AphB;

/** AC phase-C current [A] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40075 - 1;
  const uint16_t nb = 1;
} M20X_AphC;

/** AC current scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40076 - 1;
  const uint16_t nb = 1;
} M20X_A_SF;

/** AC voltage average phase-to-neutral [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40077 - 1;
  const uint16_t nb = 1;
} M20X_PhV;

/** AC voltage phase-A-to-neutral [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40078 - 1;
  const uint16_t nb = 1;
} M20X_PhVphA;

/** AC voltage phase-B-to-neutral [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40079 - 1;
  const uint16_t nb = 1;
} M20X_PhVphB;

/** AC voltage phase-C-to-neutral [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40080 - 1;
  const uint16_t nb = 1;
} M20X_PhVphC;

/** AC voltage average phase-to-phase [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40081 - 1;
  const uint16_t nb = 1;
} M20X_PPV;

/** AC voltage phase-AB [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40082 - 1;
  const uint16_t nb = 1;
} M20X_PPVphAB;

/** AC voltage phase-BC [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40083 - 1;
  const uint16_t nb = 1;
} M20X_PPVphBC;

/** AC voltage phase-CA [V] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40084 - 1;
  const uint16_t nb = 1;
} M20X_PPVphCA;

/** Voltage scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40085 - 1;
  const uint16_t nb = 1;
} M20X_V_SF;

/** AC frequency [Hz] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40086 - 1;
  const uint16_t nb = 1;
} M20X_Hz;

/** Frequency scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40087 - 1;
  const uint16_t nb = 1;
} M20X_Hz_SF;

/** AC power total [W] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40088 - 1;
  const uint16_t nb = 1;
} M20X_W;

/** AC power phase-A [W] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40089 - 1;
  const uint16_t nb = 1;
} M20X_WphA;

/** AC power phase-B [W] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40090 - 1;
  const uint16_t nb = 1;
} M20X_WphB;

/** AC power phase-C [W] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40091 - 1;
  const uint16_t nb = 1;
} M20X_WphC;

/** Power scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40092 - 1;
  const uint16_t nb = 1;
} M20X_W_SF;

/** AC apparent power total [VA] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40093 - 1;
  const uint16_t nb = 1;
} M20X_VA;

/** AC apparent power phase-A [VA] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40094 - 1;
  const uint16_t nb = 1;
} M20X_VAphA;

/** AC apparent power phase-B [VA] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40095 - 1;
  const uint16_t nb = 1;
} M20X_VAphB;

/** AC apparent power phase-C [VA] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40096 - 1;
  const uint16_t nb = 1;
} M20X_VAphC;

/** Apparent power scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40097 - 1;
  const uint16_t nb = 1;
} M20X_VA_SF;

/** AC reactive power total [VAr] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40098 - 1;
  const uint16_t nb = 1;
} M20X_VAR;

/** AC reactive power phase-A [VAr] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40099 - 1;
  const uint16_t nb = 1;
} M20X_VARphA;

/** AC reactive power phase-B [VAr] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40100 - 1;
  const uint16_t nb = 1;
} M20X_VARphB;

/** AC reactive power phase-C [VAr] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40101 - 1;
  const uint16_t nb = 1;
} M20X_VARphC;

/** Reactive power scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40102 - 1;
  const uint16_t nb = 1;
} M20X_VAR_SF;

/** Power factor [%] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40103 - 1;
  const uint16_t nb = 1;
} M20X_PF;

/** Power factor phase-A [%] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40104 - 1;
  const uint16_t nb = 1;
} M20X_PFphA;

/** Power factor phase-B [%] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40105 - 1;
  const uint16_t nb = 1;
} M20X_PFphB;

/** Power factor phase-C [%] */
struct {
  int16_t res = 0;
  const uint16_t reg = 40106 - 1;
  const uint16_t nb = 1;
} M20X_PFphC;

/** Power factor scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40107 - 1;
  const uint16_t nb = 1;
} M20X_PF_SF;

/** Total energy exported [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40108 - 1;
  const uint16_t nb = 2;
} M20X_TotWhExp;

/** Total energy exported phase-A [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40110 - 1;
  const uint16_t nb = 2;
} M20X_TotWhExpPhA;

/** Total energy exported phase-B [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40112 - 1;
  const uint16_t nb = 2;
} M20X_TotWhExpPhB;

/** Total energy exported phase-C [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40114 - 1;
  const uint16_t nb = 2;
} M20X_TotWhExpPhC;

/** Total energy imported [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40116 - 1;
  const uint16_t nb = 2;
} M20X_TotWhImp;

/** Total energy imported phase-A [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40118 - 1;
  const uint16_t nb = 2;
} M20X_TotWhImpPhA;

/** Total energy imported phase-B [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40120 - 1;
  const uint16_t nb = 2;
} M20X_TotWhImpPhB;

/** Total energy imported phase-C [Wh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40122 - 1;
  const uint16_t nb = 2;
} M20X_TotWhImpPhC;

/** Total energy scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40124 - 1;
  const uint16_t nb = 1;
} M20X_TotWh_SF;

/** Total apparent energy exported [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40125 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhExp;

/** Total apparent energy exported phase-A [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40127 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhExpPhA;

/** Total apparent energy exported phase-B [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40129 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhExpPhB;

/** Total apparent energy exported phase-C [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40131 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhExpPhC;

/** Total apparent energy imported [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40133 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhImp;

/** Total apparent energy imported phase-A [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40135 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhImpPhA;

/** Total apparent energy imported phase-B [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40137 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhImpPhB;

/** Total apparent energy imported phase-C [VAh] */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40139 - 1;
  const uint16_t nb = 2;
} M20X_TotVAhImpPhC;

/** Total apparent energy scale factor */
struct {
  int16_t res = 0;
  const uint16_t reg = 40141 - 1;
  const uint16_t nb = 1;
} M20X_TotVAh_SF;

/** Total reactive energy imported Q1 [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40142 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ1;

/** Total reactive energy imported Q1 phase-A [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40144 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ1phA;

/** Total reactive energy imported Q1 phase-B [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40146 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ1phB;

/** Total reactive energy imported Q1 phase-C [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40148 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ1phC;

/** Total reactive energy imported Q2 [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40150 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ2;

/** Total reactive energy imported Q2 phase-A [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40152 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ2phA;

/** Total reactive energy imported Q2 phase-B [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40154 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ2phB;

/** Total reactive energy imported Q2 phase-C [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40156 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhImpQ2phC;

/** Total reactive energy exported Q3 [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40158 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ3;

/** Total reactive energy exported Q3 phase-A [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40160 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ3phA;

/** Total reactive energy exported Q3 phase-B [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40162 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ3phB;

/** Total reactive energy exported Q3 phase-C [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40164 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ3phC;

/** Total reactive energy exported Q4 [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40166 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ4;

/** Total reactive energy exported Q4 phase-A [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40168 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ4phA;

/** Total reactive energy exported Q4 phase-B [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40170 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ4phB;

/** Total reactive energy exported Q4 phase-C [VArh]

 @note register not supported
 */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40172 - 1;
  const uint16_t nb = 2;
} M20X_TotVArhExpQ4phC;

/** Total reactive energy scale factor

 @note register not supported
 */
struct {
  int16_t res = 0;
  const uint16_t reg = 40174 - 1;
  const uint16_t nb = 1;
} M20X_TotVArh_SF;

/** Events */
struct {
  uint32_t res = 0;
  const uint16_t reg = 40175 - 1;
  const uint16_t nb = 2;
} M20X_Evt;
} // namespace MeterRegisterMapIntSf

#endif /* SUNSPECMODELINTSF_H_ */
