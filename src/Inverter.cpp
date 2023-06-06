#include <cmath>
#include <modbus/modbus.h>

#include "Sunspec.h"
#include "Inverter.h"

using namespace CommonModel;
using namespace InverterModel;

Inverter::Inverter(void) {
	// TODO Auto-generated constructor stub

}

Inverter::~Inverter(void) {
	// TODO Auto-generated destructor stub
}

bool Inverter::GetManufacturer(std::string &mfg)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(C001_ADDR_Mn, C001_SIZE_Mn);
	if (!tab_reg) {
		return false;
	}
	mfg = Register2String(tab_reg, C001_SIZE_Mn);
	free(tab_reg);

	return true;
}

bool Inverter::GetAcPower(double &pwr)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(I10X_ADDR_W, I10X_SIZE_W);
	if (!tab_reg) {
		return false;
	}
	int16_t num = Register2s16(tab_reg);
	free(tab_reg);

	tab_reg = ReadRegister(I10X_ADDR_W_SF, I10X_SIZE_W_SF);
	if (!tab_reg) {
		return false;
	}
	int16_t sf = Register2s16(tab_reg);
	free(tab_reg);

	pwr = static_cast<double>(num) * pow(10, sf);

	return true;
}

bool Inverter::GetAcLifetimeEnergy(double &energy_lifetime)
{
	uint16_t *tab_reg = nullptr;

	tab_reg = ReadRegister(I10X_ADDR_WH, I10X_SIZE_WH);
	if (!tab_reg) {
		return false;
	}
	int16_t num = Register2s16(tab_reg);
	free(tab_reg);

	tab_reg = ReadRegister(I10X_ADDR_WH_SF, I10X_SIZE_WH_SF);
	if (!tab_reg) {
		return false;
	}
	int16_t sf = Register2s16(tab_reg);
	free(tab_reg);

	energy_lifetime = static_cast<double>(num) * pow(10, sf);

	return true;
}

