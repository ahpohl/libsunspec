/*
 *  Inverter model
 */

#ifndef INVERTER_H_
#define INVERTER_H_

#include <cstdint>

class InverterModel
{
public:
	static const uint16_t I10X_REG_OFFSET;

	/* inverter model register start address */

	static const uint16_t I10X_ADDR_ID;
	static const uint16_t I10X_ADDR_L;
	static const uint16_t I10X_ADDR_A;
	static const uint16_t I10X_ADDR_AphA;
	static const uint16_t I10X_ADDR_AphB;
	static const uint16_t I10X_ADDR_AphC;
	static const uint16_t I10X_ADDR_A_SF;
	static const uint16_t I10X_ADDR_PPVphAB;
	static const uint16_t I10X_ADDR_PPVphBC;
	static const uint16_t I10X_ADDR_PPVphCA;
	static const uint16_t I10X_ADDR_PhVphA;
	static const uint16_t I10X_ADDR_PhVphB;
	static const uint16_t I10X_ADDR_PhVphC;
	static const uint16_t I10X_ADDR_V_SF;
	static const uint16_t I10X_ADDR_W;
	static const uint16_t I10X_ADDR_W_SF;
	static const uint16_t I10X_ADDR_Hz;
	static const uint16_t I10X_ADDR_Hz_SF;
	static const uint16_t I10X_ADDR_VA;
	static const uint16_t I10X_ADDR_VA_SF;
	static const uint16_t I10X_ADDR_VAr;
	static const uint16_t I10X_ADDR_VAr_SF;
	static const uint16_t I10X_ADDR_PF;
	static const uint16_t I10X_ADDR_PF_SF;
	static const uint16_t I10X_ADDR_WH;
	static const uint16_t I10X_ADDR_WH_SF;
	static const uint16_t I10X_ADDR_DCA;
	static const uint16_t I10X_ADDR_DCA_SF;
	static const uint16_t I10X_ADDR_DCV;
	static const uint16_t I10X_ADDR_DCV_SF;
	static const uint16_t I10X_ADDR_DCW;
	static const uint16_t I10X_ADDR_DCW_SF;
	static const uint16_t I10X_ADDR_TmpCab;
	static const uint16_t I10X_ADDR_TmpSnk;
	static const uint16_t I10X_ADDR_TmpTrns;
	static const uint16_t I10X_ADDR_TmpOt;
	static const uint16_t I10X_ADDR_Tmp_SF;
	static const uint16_t I10X_ADDR_St;
	static const uint16_t I10X_ADDR_StVnd;
	static const uint16_t I10X_ADDR_Evt1;
	static const uint16_t I10X_ADDR_Evt2;
	static const uint16_t I10X_ADDR_EvtVnd1;
	static const uint16_t I10X_ADDR_EvtVnd2;
	static const uint16_t I10X_ADDR_EvtVnd3;
	static const uint16_t I10X_ADDR_EvtVnd4;

	/* inverter model register size */

	static const uint16_t I10X_SIZE_ID;
	static const uint16_t I10X_SIZE_L;
	static const uint16_t I10X_SIZE_A;
	static const uint16_t I10X_SIZE_AphA;
	static const uint16_t I10X_SIZE_AphB;
	static const uint16_t I10X_SIZE_AphC;
	static const uint16_t I10X_SIZE_A_SF;
	static const uint16_t I10X_SIZE_PPVphAB;
	static const uint16_t I10X_SIZE_PPVphBC;
	static const uint16_t I10X_SIZE_PPVphCA;
	static const uint16_t I10X_SIZE_PhVphA;
	static const uint16_t I10X_SIZE_PhVphB;
	static const uint16_t I10X_SIZE_PhVphC;
	static const uint16_t I10X_SIZE_V_SF;
	static const uint16_t I10X_SIZE_W;
	static const uint16_t I10X_SIZE_W_SF;
	static const uint16_t I10X_SIZE_Hz;
	static const uint16_t I10X_SIZE_Hz_SF;
	static const uint16_t I10X_SIZE_VA;
	static const uint16_t I10X_SIZE_VA_SF;
	static const uint16_t I10X_SIZE_VAr;
	static const uint16_t I10X_SIZE_VAr_SF;
	static const uint16_t I10X_SIZE_PF;
	static const uint16_t I10X_SIZE_PF_SF;
	static const uint16_t I10X_SIZE_WH;
	static const uint16_t I10X_SIZE_WH_SF;
	static const uint16_t I10X_SIZE_DCA;
	static const uint16_t I10X_SIZE_DCA_SF;
	static const uint16_t I10X_SIZE_DCV;
	static const uint16_t I10X_SIZE_DCV_SF;
	static const uint16_t I10X_SIZE_DCW;
	static const uint16_t I10X_SIZE_DCW_SF;
	static const uint16_t I10X_SIZE_TmpCab;
	static const uint16_t I10X_SIZE_TmpSnk;
	static const uint16_t I10X_SIZE_TmpTrns;
	static const uint16_t I10X_SIZE_TmpOt;
	static const uint16_t I10X_SIZE_Tmp_SF;
	static const uint16_t I10X_SIZE_St;
	static const uint16_t I10X_SIZE_StVnd;
	static const uint16_t I10X_SIZE_Evt1;
	static const uint16_t I10X_SIZE_Evt2;
	static const uint16_t I10X_SIZE_EvtVnd1;
	static const uint16_t I10X_SIZE_EvtVnd2;
	static const uint16_t I10X_SIZE_EvtVnd3;
	static const uint16_t I10X_SIZE_EvtVnd4;
};

#endif /* INVERTER_H_ */
