/*
 *  Common Models
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <cstdint>

class CommonModel
{
public:
	static const uint16_t C001_REG_OFFSET;

	/* common model register start address */

	static const uint16_t C001_ADDR_SID;
	static const uint16_t C001_ADDR_ID;
	static const uint16_t C001_ADDR_L ;
	static const uint16_t C001_ADDR_Mn;
	static const uint16_t C001_ADDR_Md;
	static const uint16_t C001_ADDR_Opt;
	static const uint16_t C001_ADDR_Vr;
	static const uint16_t C001_ADDR_SN;
	static const uint16_t C001_ADDR_DA;

	/* common model register size */

	static const uint16_t C001_SIZE_SID;
	static const uint16_t C001_SIZE_ID;
	static const uint16_t C001_SIZE_L;
	static const uint16_t C001_SIZE_Mn;
	static const uint16_t C001_SIZE_Md;
	static const uint16_t C001_SIZE_Opt;
	static const uint16_t C001_SIZE_Vr;
	static const uint16_t C001_SIZE_SN;
	static const uint16_t C001_SIZE_DA;

};

typedef enum {
	TYPE_INT16,
	TYPE_UINT16,
	TYPE_ACC16,
	TYPE_ENUM16,
	TYPE_BITFIELD16,
	TYPE_PAD,
	TYPE_INT32,
	TYPE_UINT32,
	TYPE_ACC32,
	TYPE_ENUM32,
	TYPE_BITFIELD32,
	TYPE_INT64,
	TYPE_UINT64,
	TYPE_ACC64,
	TYPE_STRING16,
	TYPE_STRING32,
	TYPE_FLOAT32,
	TYPE_SUNSSF
} sunspec_type_t;

#endif /* COMMON_H_ */
