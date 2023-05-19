/*
 *  Common Models
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>

const uint16_t C001_REG_OFFSET = 0x9C3F;

/* common model register start address */

const uint16_t C001_ADDR_SID =  1 + C001_REG_OFFSET;
const uint16_t C001_ADDR_ID  =  3 + C001_REG_OFFSET;
const uint16_t C001_ADDR_L   =  4 + C001_REG_OFFSET;
const uint16_t C001_ADDR_Mn  =  5 + C001_REG_OFFSET;
const uint16_t C001_ADDR_Md  = 21 + C001_REG_OFFSET;
const uint16_t C001_ADDR_Opt = 37 + C001_REG_OFFSET;
const uint16_t C001_ADDR_Vr  = 45 + C001_REG_OFFSET;
const uint16_t C001_ADDR_SN  = 53 + C001_REG_OFFSET;
const uint16_t C001_ADDR_DA  = 69 + C001_REG_OFFSET;

/* common model register size */

const uint16_t C001_SIZE_SID = 2;
const uint16_t C001_SIZE_ID  = 1;
const uint16_t C001_SIZE_L   = 1;
const uint16_t C001_SIZE_Mn  = 16;
const uint16_t C001_SIZE_Md  = 16;
const uint16_t C001_SIZE_Opt = 8;
const uint16_t C001_SIZE_Vr  = 8;
const uint16_t C001_SIZE_SN  = 16;
const uint16_t C001_SIZE_DA  = 1;

#endif /* COMMON_H_ */
