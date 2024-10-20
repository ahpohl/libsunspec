#include "MeterModel.h"
#include "SunSpec.h"
#include "SunSpecModelFloat.h"

#ifdef MODEL_FLOAT

using namespace MeterRegisterMapFloat;

bool MeterModel::IsMeterRegisterMap(void) {
  if (!GetRegister(M21X_ID.res, M21X_ID.reg, M21X_ID.nb)) {
    return false;
  }
  if (!((M21X_ID.res == 211) || (M21X_ID.res == 212) || (M21X_ID.res = 213))) {
    ErrorMessage = std::string("Invalid ID of Meter Model block (") +
                   std::to_string(M21X_ID.res) + ")";
    return false;
  }
  if (!GetRegister(M21X_L.res, M21X_L.reg, M21X_L.nb)) {
    return false;
  }
  if (M21X_L.res != 65) {
    ErrorMessage = std::string("Invalid length of Meter Model block (") +
                   std::to_string(M21X_L.res) + ")";
    return false;
  }

  return true;
}

bool MeterModel::GetAcCurrent(double &res) {
  if (!GetRegister(M21X_A.res, M21X_A.reg, M21X_A.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_A.res);

  return true;
}

bool MeterModel::GetAcCurrentPhase(double &res, const char &ph) {
  switch (ph) {
  case 'A':
    if (!GetRegister(M21X_AphA.res, M21X_AphA.reg, M21X_AphA.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_AphA.res);
    break;
  case 'B':
    if (!GetRegister(M21X_AphB.res, M21X_AphB.reg, M21X_AphB.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_AphB.res);
    break;
  case 'C':
    if (!GetRegister(M21X_AphC.res, M21X_AphC.reg, M21X_AphC.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_AphC.res);
    break;
  default:
    ErrorMessage = "Invalid phase " + ph;
    return false;
  }

  return true;
}

bool MeterModel::GetAcVoltage(double &res, const char &ph) {
  switch (ph) {
  case 'A':
    if (!GetRegister(M21X_PhVphA.res, M21X_PhVphA.reg, M21X_PhVphA.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_PhVphA.res);
    break;
  case 'B':
    if (!GetRegister(M21X_PhVphB.res, M21X_PhVphB.reg, M21X_PhVphB.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_PhVphB.res);
    break;
  case 'C':
    if (!GetRegister(M21X_PhVphC.res, M21X_PhVphC.reg, M21X_PhVphC.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_PhVphC.res);
    break;
  default:
    ErrorMessage = "Invalid phase " + ph;
    return false;
  }

  return true;
}

bool MeterModel::GetAcVoltagePhaseToPhase(double &res,
                                          const std::string &ph_pair) {
  if (ph_pair == "AB") {
    if (!GetRegister(M21X_PPVphAB.res, M21X_PPVphAB.reg, M21X_PPVphAB.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_PPVphAB.res);
  } else if (ph_pair == "BC") {
    if (!GetRegister(M21X_PPVphBC.res, M21X_PPVphBC.reg, M21X_PPVphBC.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_PPVphBC.res);
  } else if (ph_pair == "CA") {
    if (!GetRegister(M21X_PPVphCA.res, M21X_PPVphCA.reg, M21X_PPVphCA.nb)) {
      return false;
    }
    res = static_cast<double>(M21X_PPVphCA.res);
  } else {
    ErrorMessage = "Invalid phase pair " + ph_pair;
    return false;
  }

  return true;
}

bool MeterModel::GetAcPower(double &res) {
  if (!GetRegister(M21X_W.res, M21X_W.reg, M21X_W.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_W.res);

  return true;
}

bool MeterModel::GetAcFrequency(double &res) {
  if (!GetRegister(M21X_Hz.res, M21X_Hz.reg, M21X_Hz.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_Hz.res);

  return true;
}

bool MeterModel::GetAcPowerApparent(double &res) {
  if (!GetRegister(M21X_VA.res, M21X_VA.reg, M21X_VA.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_VA.res);

  return true;
}

bool MeterModel::GetAcPowerReactive(double &res) {
  if (!GetRegister(M21X_VAR.res, M21X_VAR.reg, M21X_VAR.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_VAR.res);

  return true;
}

bool MeterModel::GetAcPowerFactor(double &res) {
  if (!GetRegister(M21X_PF.res, M21X_PF.reg, M21X_PF.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_PF.res);

  return true;
}

bool MeterModel::GetAcEnergyExport(double &res) {
  if (!GetRegister(M21X_TotWhExp.res, M21X_TotWhExp.reg, M21X_TotWhExp.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_TotWhExp.res) * 0.001f;

  return true;
}

bool MeterModel::GetAcEnergyImport(double &res) {
  if (!GetRegister(M21X_TotWhImp.res, M21X_TotWhImp.reg, M21X_TotWhImp.nb)) {
    return false;
  }
  res = static_cast<double>(M21X_TotWhImp.res) * 0.001f;

  return true;
}

#endif
