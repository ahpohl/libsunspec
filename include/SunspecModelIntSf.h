#ifndef SUNSPECMODELINTSF_H_
#define SUNSPECMODELINTSF_H_

#include <cstdint>

namespace CommonModel
{
	struct { uint32_t res = 0; const uint16_t reg = 40001-1; const uint16_t nb = 2;  } C001_SID;
	struct { uint16_t res = 0; const uint16_t reg = 40003-1; const uint16_t nb = 1;  } C001_ID;
	struct { uint16_t res = 0; const uint16_t reg = 40004-1; const uint16_t nb = 1;  } C001_L;
	struct { std::string str;  const uint16_t reg = 40005-1; const uint16_t nb = 16; } C001_Mn;
	struct { std::string str;  const uint16_t reg = 40021-1; const uint16_t nb = 16; } C001_Md;
	struct { std::string str;  const uint16_t reg = 40037-1; const uint16_t nb = 8;  } C001_Opt;
	struct { std::string str;  const uint16_t reg = 40045-1; const uint16_t nb = 8;  } C001_Vr;
	struct { std::string str;  const uint16_t reg = 40053-1; const uint16_t nb = 16; } C001_SN;
	struct { uint16_t res = 0; const uint16_t reg = 40069-1; const uint16_t nb = 1; } C001_DA;
};

namespace InverterModel
{
	struct { uint16_t res = 0; const uint16_t reg = 40070-1; const uint16_t nb = 1; } I10X_ID;
	struct { uint16_t res = 0; const uint16_t reg = 40071-1; const uint16_t nb = 1; } I10X_L;
	struct { uint16_t res = 0; const uint16_t reg = 40072-1; const uint16_t nb = 1; } I10X_A;
	struct { uint16_t res = 0; const uint16_t reg = 40073-1; const uint16_t nb = 1; } I10X_AphA;
	struct { uint16_t res = 0; const uint16_t reg = 40074-1; const uint16_t nb = 1; } I10X_AphB;
	struct { uint16_t res = 0; const uint16_t reg = 40075-1; const uint16_t nb = 1; } I10X_AphC;
	struct { uint16_t res = 0; const uint16_t reg_= 40076-1; const uint16_t nb = 1; } I10X_A_SF;
	struct { uint16_t res = 0; const uint16_t reg = 40077-1; const uint16_t nb = 1; } I10X_PPVphAB;
	struct { uint16_t res = 0; const uint16_t reg = 40078-1; const uint16_t nb = 1; } I10X_PPVphBC;
	struct { uint16_t res = 0; const uint16_t reg = 40079-1; const uint16_t nb = 1; } I10X_PPVphCA;
	struct { uint16_t res = 0; const uint16_t reg = 40080-1; const uint16_t nb = 1; } I10X_PhVphA;
	struct { uint16_t res = 0; const uint16_t reg = 40081-1; const uint16_t nb = 1; } I10X_PhVphB;
	struct { uint16_t res = 0; const uint16_t reg = 40082-1; const uint16_t nb = 1; } I10X_PhVphC;
	struct { uint16_t res = 0; const uint16_t reg = 40083-1; const uint16_t nb = 1; } I10X_V_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40084-1; const uint16_t nb = 1; } I10X_W;
	struct { uint16_t res = 0; const uint16_t reg = 40085-1; const uint16_t nb = 1; } I10X_W_SF;
	struct { uint16_t res = 0; const uint16_t reg = 40086-1; const uint16_t nb = 1; } I10X_Hz;
	struct { uint16_t res = 0; const uint16_t reg = 40087-1; const uint16_t nb = 1; } I10X_Hz_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40088-1; const uint16_t nb = 1; } I10X_VA;
	struct { uint16_t res = 0; const uint16_t reg = 40089-1; const uint16_t nb = 1; } I10X_VA_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40090-1; const uint16_t nb = 1; } I10X_VAr;
	struct { uint16_t res = 0; const uint16_t reg = 40091-1; const uint16_t nb = 1; } I10X_VAr_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40092-1; const uint16_t nb = 1; } I10X_PF;
	struct { uint16_t res = 0; const uint16_t reg = 40093-1; const uint16_t nb = 1; } I10X_PF_SF;
	struct { uint32_t res = 0; const uint16_t reg = 40094-1; const uint16_t nb = 2; } I10X_WH;
	struct { uint16_t res = 0; const uint16_t reg = 40096-1; const uint16_t nb = 1; } I10X_WH_SF;
	struct { uint16_t res = 0; const uint16_t reg = 40097-1; const uint16_t nb = 1; } I10X_DCA;
	struct { uint16_t res = 0; const uint16_t reg = 40098-1; const uint16_t nb = 1; } I10X_DCA_SF;
	struct { uint16_t res = 0; const uint16_t reg = 40099-1; const uint16_t nb = 1; } I10X_DCV;
	struct { uint16_t res = 0; const uint16_t reg = 40100-1; const uint16_t nb = 1; } I10X_DCV_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40101-1; const uint16_t nb = 1; } I10X_DCW;
	struct { uint16_t res = 0; const uint16_t reg = 40102-1; const uint16_t nb = 1; } I10X_DCW_SF;
	struct { int16_t  res = 0; const uint16_t reg = 40103-1; const uint16_t nb = 1; } I10X_TmpCab;
	struct { int16_t  res = 0; const uint16_t reg = 40104-1; const uint16_t nb = 1; } I10X_TmpSnk;
	struct { int16_t  res = 0; const uint16_t reg = 40105-1; const uint16_t nb = 1; } I10X_TmpTrns;
	struct { int16_t  res = 0; const uint16_t reg = 40106-1; const uint16_t nb = 1; } I10X_TmpOt;
	struct { uint16_t res = 0; const uint16_t reg = 40107-1; const uint16_t nb = 1; } I10X_Tmp_SF;
	struct { uint16_t res = 0; const uint16_t reg = 40108-1; const uint16_t nb = 1; } I10X_St;
	struct { uint16_t res = 0; const uint16_t reg = 40109-1; const uint16_t nb = 1; } I10X_StVnd;
	struct { uint32_t res = 0; const uint16_t reg = 40110-1; const uint16_t nb = 2; } I10X_Evt1;
	struct { uint32_t res = 0; const uint16_t reg = 40112-1; const uint16_t nb = 2; } I10X_Evt2;
	struct { uint32_t res = 0; const uint16_t reg = 40114-1; const uint16_t nb = 2; } I10X_EvtVnd1;
	struct { uint32_t res = 0; const uint16_t reg = 40116-1; const uint16_t nb = 2; } I10X_EvtVnd2;
	struct { uint32_t res = 0; const uint16_t reg = 40118-1; const uint16_t nb = 2; } I10X_EvtVnd3;
	struct { uint32_t res = 0; const uint16_t reg = 40120-1; const uint16_t nb = 2; } I10X_EvtVnd4;
};

namespace FroniusRegister
{
	struct { uint16_t res = 0; const uint16_t reg = 212-1; const uint16_t nb = 1; } F_Delete_Data;
	struct { uint16_t res = 0; const uint16_t reg = 213-1; const uint16_t nb = 1; } F_Store_Data;
	struct { uint16_t res = 0; const uint16_t reg = 214-1; const uint16_t nb = 1; } F_Active_State_Code;
	struct { uint16_t res = 0; const uint16_t reg = 215-1; const uint16_t nb = 1; } F_Reset_All_Event_Flags;
	struct { uint16_t res = 0; const uint16_t reg = 216-1; const uint16_t nb = 1; } F_ModelType;
	struct { uint16_t res = 0; const uint16_t reg = 217-1; const uint16_t nb = 1; } F_Storage_Restrictions_View_Mode;
	struct { uint32_t res = 0; const uint16_t reg = 500-1; const uint16_t nb = 2; } F_Site_Power;
	struct { uint64_t res = 0; const uint16_t reg = 502-1; const uint16_t nb = 4; } F_Site_Energy_Day;
	struct { uint64_t res = 0; const uint16_t reg = 506-1; const uint16_t nb = 4; } F_Site_Energy_Year;
	struct { uint64_t res = 0; const uint16_t reg = 510-1; const uint16_t nb = 4; } F_Site_Energy_Total;
};

#endif /* SUNSPECMODELINTSF_H_ */
