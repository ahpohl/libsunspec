#ifndef SUNSPEC_IMPL_CPP_
#define SUNSPEC_IMPL_CPP_

#include <cstring>
#include <cmath>
#include <Sunspec.h>

template <typename T>
T Sunspec::ConvertRegister(const uint16_t *tab_reg, const uint16_t &size)
{
	T res = 0;
    memcpy(&res, tab_reg, sizeof(uint16_t) * size);
    return res;
}

template <typename T>
bool Sunspec::GetIntSf(double &res, const uint16_t &reg_addr, const uint16_t &reg_size,
	const uint16_t &sf_addr)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(reg_addr, reg_size);
	if (!tab_reg) {
		return false;
	}
	T num = ConvertRegister<T>(tab_reg, reg_size);
	delete tab_reg;

	tab_reg = ReadRegister(sf_addr, sizeof(int16_t));
	if (!tab_reg) {
		return false;
	}
	int16_t sf = ConvertRegister<int16_t>(tab_reg, sizeof(int16_t));
	delete tab_reg;

	res = static_cast<double>(num) * pow(10, sf);

    return res;
}

#endif /* SUNSPEC_IMPL_CPP_ */
