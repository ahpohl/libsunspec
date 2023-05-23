/*
 *  Common Models
 */

#ifndef COMMONMODEL_H_
#define COMMONMODEL_H_

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

#endif /* COMMONMODEL_H_ */
