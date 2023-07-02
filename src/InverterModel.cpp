#include "InverterModel.h"
#include "SunSpec.h"
#include "SunSpecModelIntSf.h"
#include <cmath>

using namespace InverterRegisterMap;

bool InverterModel::IsInverterRegisterMap(void)
{
	if (!GetRegister(I10X_ID.res, I10X_ID.reg, I10X_ID.nb)) {
		return false;
	}
	if ( !((I10X_ID.res == 101) || (I10X_ID.res == 102) || (I10X_ID.res = 103)) ) {
		ErrorMessage = std::string("Invalid ID of Inverter Model block (") + std::to_string(I10X_ID.res) + ")";
		return false;
	}
	if (!GetRegister(I10X_L.res, I10X_L.reg, I10X_L.nb)) {
		return false;
	}
	if ( I10X_L.res != 50 ) {
		ErrorMessage = std::string("Invalid length of Inverter Model block (") + std::to_string(I10X_L.res) + ")";
		return false;
	}

	return true;
}

bool InverterModel::GetAcCurrent(double &res)
{
	if (!GetRegister(I10X_A.res, I10X_A.reg, I10X_A.nb)) {
		return false;
	}
	if (!GetRegister(I10X_A_SF.res, I10X_A_SF.reg, I10X_A_SF.nb)) {
		return false;
	}
	res = static_cast<double>(I10X_A.res) * pow(10, I10X_A_SF.res);

	return true;
}

bool InverterModel::GetAcCurrentPhase(double &res, const char &ph)
{
	switch (ph) {
	case 'A':
		if (!GetRegister(I10X_AphA.res, I10X_AphA.reg, I10X_AphA.nb)) {
			return false;
		}
		if (!GetRegister(I10X_A_SF.res, I10X_A_SF.reg, I10X_A_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_AphA.res) * pow(10, I10X_A_SF.res);
		break;
	case 'B':
		if (!GetRegister(I10X_AphB.res, I10X_AphB.reg, I10X_AphB.nb)) {
			return false;
		}
		if (!GetRegister(I10X_A_SF.res, I10X_A_SF.reg, I10X_A_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_AphB.res) * pow(10, I10X_A_SF.res);
		break;
	case 'C':
		if (!GetRegister(I10X_AphC.res, I10X_AphC.reg, I10X_AphC.nb)) {
			return false;
		}
		if (!GetRegister(I10X_A_SF.res, I10X_A_SF.reg, I10X_A_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_AphC.res) * pow(10, I10X_A_SF.res);
		break;
	default:
		ErrorMessage = "Invalid phase " + ph;
		return false;
	}

	return true;
}

bool InverterModel::GetAcVoltage(double &res, const char &ph)
{
	switch (ph) {
	case 'A':
		if (!GetRegister(I10X_PhVphA.res, I10X_PhVphA.reg, I10X_PhVphA.nb)) {
			return false;
		}
		if (!GetRegister(I10X_V_SF.res, I10X_V_SF.reg, I10X_V_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_PhVphA.res) * pow(10, I10X_V_SF.res);
		break;
	case 'B':
		if (!GetRegister(I10X_PhVphB.res, I10X_PhVphB.reg, I10X_PhVphB.nb)) {
			return false;
		}
		if (!GetRegister(I10X_V_SF.res, I10X_V_SF.reg, I10X_V_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_PhVphB.res) * pow(10, I10X_V_SF.res);
		break;
	case 'C':
		if (!GetRegister(I10X_PhVphC.res, I10X_PhVphC.reg, I10X_PhVphC.nb)) {
			return false;
		}
		if (!GetRegister(I10X_V_SF.res, I10X_V_SF.reg, I10X_V_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_PhVphC.res) * pow(10, I10X_V_SF.res);
		break;
	default:
		ErrorMessage = "Invalid phase " + ph;
		return false;
	}

	return true;
}

bool InverterModel::GetAcVoltagePhaseToPhase(double &res, const std::string &ph_pair)
{
	if (ph_pair == "AB") {
		if (!GetRegister(I10X_PPVphAB.res, I10X_PPVphAB.reg, I10X_PPVphAB.nb)) {
			return false;
		}
		if (!GetRegister(I10X_V_SF.res, I10X_V_SF.reg, I10X_V_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_PPVphAB.res) * pow(10, I10X_V_SF.res);
	} else if (ph_pair == "BC") {
		if (!GetRegister(I10X_PPVphBC.res, I10X_PPVphBC.reg, I10X_PPVphBC.nb)) {
			return false;
		}
		if (!GetRegister(I10X_V_SF.res, I10X_V_SF.reg, I10X_V_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_PPVphBC.res) * pow(10, I10X_V_SF.res);
	} else if (ph_pair == "CA") {
		if (!GetRegister(I10X_PPVphCA.res, I10X_PPVphCA.reg, I10X_PPVphCA.nb)) {
			return false;
		}
		if (!GetRegister(I10X_V_SF.res, I10X_V_SF.reg, I10X_V_SF.nb)) {
			return false;
		}
		res = static_cast<double>(I10X_PPVphCA.res) * pow(10, I10X_V_SF.res);
	} else {
		ErrorMessage = "Invalid phase pair " + ph_pair;
		return false;
	}

	return true;
}

bool InverterModel::GetAcPower(double &res)
{
	if (!GetRegister(I10X_W.res, I10X_W.reg, I10X_W.nb)) {
		return false;
	}
	if (!GetRegister(I10X_W_SF.res, I10X_W_SF.reg, I10X_W_SF.nb)) {
		return false;
	}
	res = static_cast<double>(I10X_W.res) * pow(10, I10X_W_SF.res);

	return true;
}

bool InverterModel::GetAcFrequency(double &res)
{
	if (!GetRegister(I10X_Hz.res, I10X_Hz.reg, I10X_Hz.nb)) {
		return false;
	}
	if (!GetRegister(I10X_Hz_SF.res, I10X_Hz_SF.reg, I10X_Hz_SF.nb)) {
		return false;
	}
	res = static_cast<double>(I10X_Hz.res) * pow(10, I10X_Hz_SF.res);

	return true;
}

bool InverterModel::GetAcPowerApparent(double &res)
{
	if (!GetRegister(I10X_VA.res, I10X_VA.reg, I10X_VA.nb)) {
		return false;
	}
	if (!GetRegister(I10X_VA_SF.res, I10X_VA_SF.reg, I10X_VA_SF.nb)) {
		return false;
	}
	res = static_cast<double>(I10X_VA.res) * pow(10, I10X_VA_SF.res);

	return true;
}

bool InverterModel::GetAcPowerReactive(double &res)
{
	if (!GetRegister(I10X_VAr.res, I10X_VAr.reg, I10X_VAr.nb)) {
		return false;
	}
	if (!GetRegister(I10X_VAr_SF.res, I10X_VAr_SF.reg, I10X_VAr_SF.nb)) {
		return false;
	}
	res = static_cast<double>(I10X_VAr.res) * pow(10, I10X_VAr_SF.res);

	return true;
}

bool InverterModel::GetAcPowerFactor(double &res)
{
	if (!GetRegister(I10X_PF.res, I10X_PF.reg, I10X_PF.nb)) {
		return false;
	}
	if (!GetRegister(I10X_PF_SF.res, I10X_PF_SF.reg, I10X_PF_SF.nb)) {
		return false;
	}
	res = static_cast<double>(I10X_PF.res) * pow(10, I10X_PF_SF.res);

	return true;
}

bool InverterModel::GetAcEnergyLifetime(double &res)
{
	if (!GetRegister(I10X_WH.res, I10X_WH.reg, I10X_WH.nb)) {
		return false;
	}
	if (!GetRegister(I10X_W_SF.res, I10X_W_SF.reg, I10X_W_SF.nb)) {
		return false;
	}
	res = static_cast<double>(I10X_WH.res) * pow(10, I10X_WH_SF.res) * 0.001f;

	return true;
}

bool InverterModel::ReadState(uint16_t &state)
{
	if (!GetRegister(I10X_St.res, I10X_St.reg, I10X_St.nb)) {
		return false;
	}
	state = I10X_St.res;

	return true;
}

bool InverterModel::ReadStateVendor(uint16_t &state)
{
	if (!GetRegister(I10X_StVnd.res, I10X_StVnd.reg, I10X_StVnd.nb)) {
		return false;
	}
	state = I10X_StVnd.res;

	return true;
}

bool InverterModel::ReadEventFlags(uint32_t &flag1, uint32_t &flag2)
{
	if (!GetRegister(I10X_Evt1.res, I10X_Evt1.reg, I10X_Evt1.nb)) {
		return false;
	}
	flag1 = I10X_Evt1.res;

	if (!GetRegister(I10X_Evt2.res, I10X_Evt2.reg, I10X_Evt2.nb)) {
		return false;
	}
	flag2 = I10X_Evt2.res;

	return true;
}

bool InverterModel::ReadEventFlagsVendor(uint32_t &flag1, uint32_t &flag2, uint32_t &flag3, uint32_t &flag4)
{
	if (!GetRegister(I10X_EvtVnd1.res, I10X_EvtVnd1.reg, I10X_EvtVnd1.nb)) {
		return false;
	}
	flag1 = I10X_EvtVnd1.res;

	if (!GetRegister(I10X_EvtVnd2.res, I10X_EvtVnd2.reg, I10X_EvtVnd2.nb)) {
		return false;
	}
	flag2 = I10X_EvtVnd2.res;

	if (!GetRegister(I10X_EvtVnd3.res, I10X_EvtVnd3.reg, I10X_EvtVnd3.nb)) {
		return false;
	}
	flag3 = I10X_EvtVnd3.res;

	if (!GetRegister(I10X_EvtVnd4.res, I10X_EvtVnd4.reg,I10X_EvtVnd4.nb)) {
		return false;
	}
	flag4 = I10X_EvtVnd4.res;

	return true;
}

bool InverterModel::GetStateEvtFlags(StateEvt_t &state_evt)
{
	if (!ReadStateVendor(state_evt.St)) {
		return false;
	}
	if (!ReadEventFlags(state_evt.Evt1, state_evt.Evt2)) {
		return false;
	}
	if (!ReadEventFlagsVendor(state_evt.EvtVnd1, state_evt.EvtVnd2, state_evt.EvtVnd3, state_evt.EvtVnd4)) {
		return false;
	}
	if (!SetStateEventsStr(state_evt)) {
		ErrorMessage = "Invalid operating state and/or event flag.";
		return false;
	}

	return true;
}
