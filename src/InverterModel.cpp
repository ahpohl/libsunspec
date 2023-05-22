#include <cstdint>
#include <InverterModel.h>

const uint16_t InverterModel::I10X_REG_OFFSET = 0x9C84;

/* inverter model register start address */

const uint16_t InverterModel::I10X_ADDR_ID      =  1 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_L       =  2 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_A       =  3 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_AphA    =  4 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_AphB    =  5 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_AphC    =  6 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_A_SF    =  7 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PPVphAB =  8 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PPVphBC =  9 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PPVphCA = 10 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PhVphA  = 11 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PhVphB  = 12 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PhVphC  = 13 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_V_SF    = 14 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_W       = 15 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_W_SF    = 16 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_Hz      = 17 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_Hz_SF   = 18 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_VA      = 19 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_VA_SF   = 20 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_VAr     = 21 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_VAr_SF  = 22 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PF      = 23 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_PF_SF   = 24 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_WH      = 25 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_WH_SF   = 27 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_DCA     = 28 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_DCA_SF  = 29 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_DCV     = 30 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_DCV_SF  = 31 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_DCW     = 32 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_DCW_SF  = 33 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_TmpCab  = 34 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_TmpSnk  = 35 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_TmpTrns = 36 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_TmpOt   = 37 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_Tmp_SF  = 38 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_St      = 39 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_StVnd   = 40 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_Evt1    = 41 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_Evt2    = 43 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_EvtVnd1 = 45 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_EvtVnd2 = 47 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_EvtVnd3 = 49 + I10X_REG_OFFSET;
const uint16_t InverterModel::I10X_ADDR_EvtVnd4 = 51 + I10X_REG_OFFSET;

/* inverter model register size */

const uint16_t InverterModel::I10X_SIZE_ID      = 1;
const uint16_t InverterModel::I10X_SIZE_L       = 1;
const uint16_t InverterModel::I10X_SIZE_A       = 1;
const uint16_t InverterModel::I10X_SIZE_AphA    = 1;
const uint16_t InverterModel::I10X_SIZE_AphB    = 1;
const uint16_t InverterModel::I10X_SIZE_AphC    = 1;
const uint16_t InverterModel::I10X_SIZE_A_SF    = 1;
const uint16_t InverterModel::I10X_SIZE_PPVphAB = 1;
const uint16_t InverterModel::I10X_SIZE_PPVphBC = 1;
const uint16_t InverterModel::I10X_SIZE_PPVphCA = 1;
const uint16_t InverterModel::I10X_SIZE_PhVphA  = 1;
const uint16_t InverterModel::I10X_SIZE_PhVphB  = 1;
const uint16_t InverterModel::I10X_SIZE_PhVphC  = 1;
const uint16_t InverterModel::I10X_SIZE_V_SF    = 1;
const uint16_t InverterModel::I10X_SIZE_W       = 1;
const uint16_t InverterModel::I10X_SIZE_W_SF    = 1;
const uint16_t InverterModel::I10X_SIZE_Hz      = 1;
const uint16_t InverterModel::I10X_SIZE_Hz_SF   = 1;
const uint16_t InverterModel::I10X_SIZE_VA      = 1;
const uint16_t InverterModel::I10X_SIZE_VA_SF   = 1;
const uint16_t InverterModel::I10X_SIZE_VAr     = 1;
const uint16_t InverterModel::I10X_SIZE_VAr_SF  = 1;
const uint16_t InverterModel::I10X_SIZE_PF      = 1;
const uint16_t InverterModel::I10X_SIZE_PF_SF   = 1;
const uint16_t InverterModel::I10X_SIZE_WH      = 2;
const uint16_t InverterModel::I10X_SIZE_WH_SF   = 1;
const uint16_t InverterModel::I10X_SIZE_DCA     = 1;
const uint16_t InverterModel::I10X_SIZE_DCA_SF  = 1;
const uint16_t InverterModel::I10X_SIZE_DCV     = 1;
const uint16_t InverterModel::I10X_SIZE_DCV_SF  = 1;
const uint16_t InverterModel::I10X_SIZE_DCW     = 1;
const uint16_t InverterModel::I10X_SIZE_DCW_SF  = 1;
const uint16_t InverterModel::I10X_SIZE_TmpCab  = 1;
const uint16_t InverterModel::I10X_SIZE_TmpSnk  = 1;
const uint16_t InverterModel::I10X_SIZE_TmpTrns = 1;
const uint16_t InverterModel::I10X_SIZE_TmpOt   = 1;
const uint16_t InverterModel::I10X_SIZE_Tmp_SF  = 1;
const uint16_t InverterModel::I10X_SIZE_St      = 1;
const uint16_t InverterModel::I10X_SIZE_StVnd   = 1;
const uint16_t InverterModel::I10X_SIZE_Evt1    = 2;
const uint16_t InverterModel::I10X_SIZE_Evt2    = 2;
const uint16_t InverterModel::I10X_SIZE_EvtVnd1 = 2;
const uint16_t InverterModel::I10X_SIZE_EvtVnd2 = 2;
const uint16_t InverterModel::I10X_SIZE_EvtVnd3 = 2;
const uint16_t InverterModel::I10X_SIZE_EvtVnd4 = 2;




