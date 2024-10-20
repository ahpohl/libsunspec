#include "InverterModel.h"
#include "SunSpec.h"
#include "SunSpecModelFloat.h"

#ifdef MODEL_FLOAT

using namespace InverterRegisterMapFloat;

bool InverterModel::IsInverterRegisterMap(void) {
  if (!GetRegister(I11X_ID.res, I11X_ID.reg, I11X_ID.nb)) {
    return false;
  }
  if (!((I11X_ID.res == 111) || (I11X_ID.res == 112) || (I11X_ID.res = 113))) {
    ErrorMessage = std::string("Invalid ID of Inverter Model block (")
        + std::to_string(I11X_ID.res) + ")";
    return false;
  }
  if (!GetRegister(I11X_L.res, I11X_L.reg, I11X_L.nb)) {
    return false;
  }
  if (I11X_L.res != 60) {
    ErrorMessage = std::string("Invalid length of Inverter Model block (")
        + std::to_string(I11X_L.res) + ")";
    return false;
  }

  return true;
}

bool InverterModel::GetAcCurrent(double &res) {
  if (!GetRegister(I11X_A.res, I11X_A.reg, I11X_A.nb)) {
    return false;
  }
  res = static_cast<double>(I11X_A.res);

  return true;
}

bool InverterModel::GetAcCurrentPhase(double &res, const char &ph) {
  switch (ph) {
    case 'A':
      if (!GetRegister(I11X_AphA.res, I11X_AphA.reg, I11X_AphA.nb)) {
        return false;
      }
      res = static_cast<double>(I11X_AphA.res);
      break;
    case 'B':
      if (!GetRegister(I11X_AphB.res, I11X_AphB.reg, I11X_AphB.nb)) {
        return false;
      }
      res = static_cast<double>(I11X_AphB.res);
      break;
    case 'C':
      if (!GetRegister(I11X_AphC.res, I11X_AphC.reg, I11X_AphC.nb)) {
        return false;
      }
      res = static_cast<double>(I11X_AphC.res);
      break;
    default:
      ErrorMessage = "Invalid phase " + ph;
      return false;
  }

  return true;
}

bool InverterModel::GetAcVoltage(double &res, const char &ph) {
  switch (ph) {
    case 'A':
      if (!GetRegister(I11X_PhVphA.res, I11X_PhVphA.reg, I11X_PhVphA.nb)) {
        return false;
      }
      res = static_cast<double>(I11X_PhVphA.res);
      break;
    case 'B':
      if (!GetRegister(I11X_PhVphB.res, I11X_PhVphB.reg, I11X_PhVphB.nb)) {
        return false;
      }
      res = static_cast<double>(I11X_PhVphB.res);
      break;
    case 'C':
      if (!GetRegister(I11X_PhVphC.res, I11X_PhVphC.reg, I11X_PhVphC.nb)) {
        return false;
      }
      res = static_cast<double>(I11X_PhVphC.res);
      break;
    default:
      ErrorMessage = "Invalid phase " + ph;
      return false;
  }

  return true;
}

bool InverterModel::GetAcVoltagePhaseToPhase(double &res,
                                             const std::string &ph_pair) {
  if (ph_pair == "AB") {
    if (!GetRegister(I11X_PPVphAB.res, I11X_PPVphAB.reg, I11X_PPVphAB.nb)) {
      return false;
    }
    res = static_cast<double>(I11X_PPVphAB.res);
  } else if (ph_pair == "BC") {
    if (!GetRegister(I11X_PPVphBC.res, I11X_PPVphBC.reg, I11X_PPVphBC.nb)) {
      return false;
    }
    res = static_cast<double>(I11X_PPVphBC.res);
  } else if (ph_pair == "CA") {
    if (!GetRegister(I11X_PPVphCA.res, I11X_PPVphCA.reg, I11X_PPVphCA.nb)) {
      return false;
    }
    res = static_cast<double>(I11X_PPVphCA.res);
  } else {
    ErrorMessage = "Invalid phase pair " + ph_pair;
    return false;
  }

  return true;
}

bool InverterModel::GetAcPower(double &res) {
  if (!GetRegister(I11X_W.res, I11X_W.reg, I11X_W.nb)) {
    return false;
  }
  res = static_cast<double>(I11X_W.res);

  return true;
}

bool InverterModel::GetAcFrequency(double &res) {
  if (!GetRegister(I11X_Hz.res, I11X_Hz.reg, I11X_Hz.nb)) {
    return false;
  }
  res = static_cast<double>(I11X_Hz.res);

  return true;
}

bool InverterModel::GetAcPowerApparent(double &res) {
  if (!GetRegister(I11X_VA.res, I11X_VA.reg, I11X_VA.nb)) {
    return false;
  }
  res = static_cast<double>(I11X_VA.res);

  return true;
}

bool InverterModel::GetAcPowerReactive(double &res) {
  if (!GetRegister(I11X_VAr.res, I11X_VAr.reg, I11X_VAr.nb)) {
    return false;
  }
  res = static_cast<double>(I11X_VAr.res);

  return true;
}

bool InverterModel::GetAcPowerFactor(double &res) {
  if (!GetRegister(I11X_PF.res, I11X_PF.reg, I11X_PF.nb)) {
    return false;
  }
  res = static_cast<double>(I11X_PF.res);

  return true;
}

bool InverterModel::GetAcEnergyLifetime(double &res) {
  if (!GetRegister(I11X_WH.res, I11X_WH.reg, I11X_WH.nb)) {
    return false;
  }
  res = static_cast<double>(I11X_WH.res) * 0.001f;

  return true;
}

bool InverterModel::ReadState(uint16_t &state) {
  if (!GetRegister(I11X_St.res, I11X_St.reg, I11X_St.nb)) {
    return false;
  }
  state = I11X_St.res;

  return true;
}

bool InverterModel::ReadStateVendor(uint16_t &state) {
  if (!GetRegister(I11X_StVnd.res, I11X_StVnd.reg, I11X_StVnd.nb)) {
    return false;
  }
  state = I11X_StVnd.res;

  return true;
}

bool InverterModel::ReadEventFlags(uint32_t &flag1, uint32_t &flag2) {
  if (!GetRegister(I11X_Evt1.res, I11X_Evt1.reg, I11X_Evt1.nb)) {
    return false;
  }
  flag1 = I11X_Evt1.res;

  if (!GetRegister(I11X_Evt2.res, I11X_Evt2.reg, I11X_Evt2.nb)) {
    return false;
  }
  flag2 = I11X_Evt2.res;

  return true;
}

bool InverterModel::ReadEventFlagsVendor(uint32_t &flag1, uint32_t &flag2,
                                         uint32_t &flag3, uint32_t &flag4) {
  if (!GetRegister(I11X_EvtVnd1.res, I11X_EvtVnd1.reg, I11X_EvtVnd1.nb)) {
    return false;
  }
  flag1 = I11X_EvtVnd1.res;

  if (!GetRegister(I11X_EvtVnd2.res, I11X_EvtVnd2.reg, I11X_EvtVnd2.nb)) {
    return false;
  }
  flag2 = I11X_EvtVnd2.res;

  if (!GetRegister(I11X_EvtVnd3.res, I11X_EvtVnd3.reg, I11X_EvtVnd3.nb)) {
    return false;
  }
  flag3 = I11X_EvtVnd3.res;

  if (!GetRegister(I11X_EvtVnd4.res, I11X_EvtVnd4.reg, I11X_EvtVnd4.nb)) {
    return false;
  }
  flag4 = I11X_EvtVnd4.res;

  return true;
}

bool InverterModel::GetStateEvtFlags(StateEvt_t &state_evt) {
  if (!ReadStateVendor(state_evt.St)) {
    return false;
  }
  if (!ReadEventFlags(state_evt.Evt1, state_evt.Evt2)) {
    return false;
  }
  if (!ReadEventFlagsVendor(state_evt.EvtVnd1, state_evt.EvtVnd2,
                            state_evt.EvtVnd3, state_evt.EvtVnd4)) {
    return false;
  }
  if (!SetStateEventsStr(state_evt)) {
    ErrorMessage = StateEvents::ErrorStr;
    return false;
  }

  return true;
}

#endif
