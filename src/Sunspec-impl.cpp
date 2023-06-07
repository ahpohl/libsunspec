#ifndef SUNSPEC_IMPL_CPP_
#define SUNSPEC_IMPL_CPP_

#include <cstring>
#include <cmath>
#include <Sunspec.h>

template <typename T>
T Sunspec::ConvertRegister(const uint16_t *tab_reg, const uint16_t &size)
{
	uint16_t tab_rev[size] = {0};
	uint16_t *ptr = (uint16_t*) &tab_reg[size - 1];
    for (int i = 0; i < size; i++) {
    	tab_rev[i] = *ptr--;
    }
	T res = 0;
	memcpy(&res, tab_rev, sizeof(uint16_t) * size);

    return res;
}

template <typename T>
bool Sunspec::GetRegister(T &res, const uint16_t &reg_addr, const uint16_t &size)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(reg_addr, size);
	if (!tab_reg) {
		return false;
	}
	res = ConvertRegister<T>(tab_reg, size);
	delete tab_reg;

	return true;
}

template <typename T>
bool Sunspec::GetRegister(double &res, const uint16_t &reg_addr, const uint16_t &reg_size,
	const uint16_t &sf_addr)
{
	T num;
	if (!GetRegister<T>(num, reg_addr, reg_size))
	{
		return false;
	}
	int16_t sf = 0;
	if (!GetRegister<int16_t>(sf, sf_addr, 1))
	{
		return false;
	}
	res = static_cast<double>(num) * pow(10, sf);

    return true;
}

#endif /* SUNSPEC_IMPL_CPP_ */
