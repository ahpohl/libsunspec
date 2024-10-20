#include "MeterModel.h"
#include "SunSpec.h"
#include "SunSpecModelIntSf.h"
#include <cmath>

#ifdef MODEL_INTSF

using namespace MeterRegisterMapIntSf;

bool MeterModel::IsMeterRegisterMap(void) {
  if (!GetRegister(M20X_ID.res, M20X_ID.reg, M20X_ID.nb)) {
    return false;
  }
  if (!((M20X_ID.res == 201) || (M20X_ID.res == 202) || (M20X_ID.res = 203))) {
    ErrorMessage = std::string("Invalid ID of Meter Model block (") +
                   std::to_string(M20X_ID.res) + ")";
    return false;
  }
  if (!GetRegister(M20X_L.res, M20X_L.reg, M20X_L.nb)) {
    return false;
  }
  if (M20X_L.res != 105) {
    ErrorMessage = std::string("Invalid length of Meter Model block (") +
                   std::to_string(M20X_L.res) + ")";
    return false;
  }

  return true;
}

bool MeterModel::GetAcCurrent(double &res) {
  if (!GetRegister(M20X_A.res, M20X_A.reg, M20X_A.nb)) {
    return false;
  }
  if (!GetRegister(M20X_A_SF.res, M20X_A_SF.reg, M20X_A_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_A.res) * pow(10, M20X_A_SF.res);

  return true;
}

bool MeterModel::GetAcCurrentPhase(double &res, const char &ph) {
  switch (ph) {
  case 'A':
    if (!GetRegister(M20X_AphA.res, M20X_AphA.reg, M20X_AphA.nb)) {
      return false;
    }
    if (!GetRegister(M20X_A_SF.res, M20X_A_SF.reg, M20X_A_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_AphA.res) * pow(10, M20X_A_SF.res);
    break;
  case 'B':
    if (!GetRegister(M20X_AphB.res, M20X_AphB.reg, M20X_AphB.nb)) {
      return false;
    }
    if (!GetRegister(M20X_A_SF.res, M20X_A_SF.reg, M20X_A_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_AphB.res) * pow(10, M20X_A_SF.res);
    break;
  case 'C':
    if (!GetRegister(M20X_AphC.res, M20X_AphC.reg, M20X_AphC.nb)) {
      return false;
    }
    if (!GetRegister(M20X_A_SF.res, M20X_A_SF.reg, M20X_A_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_AphC.res) * pow(10, M20X_A_SF.res);
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
    if (!GetRegister(M20X_PhVphA.res, M20X_PhVphA.reg, M20X_PhVphA.nb)) {
      return false;
    }
    if (!GetRegister(M20X_V_SF.res, M20X_V_SF.reg, M20X_V_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_PhVphA.res) * pow(10, M20X_V_SF.res);
    break;
  case 'B':
    if (!GetRegister(M20X_PhVphB.res, M20X_PhVphB.reg, M20X_PhVphB.nb)) {
      return false;
    }
    if (!GetRegister(M20X_V_SF.res, M20X_V_SF.reg, M20X_V_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_PhVphB.res) * pow(10, M20X_V_SF.res);
    break;
  case 'C':
    if (!GetRegister(M20X_PhVphC.res, M20X_PhVphC.reg, M20X_PhVphC.nb)) {
      return false;
    }
    if (!GetRegister(M20X_V_SF.res, M20X_V_SF.reg, M20X_V_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_PhVphC.res) * pow(10, M20X_V_SF.res);
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
    if (!GetRegister(M20X_PPVphAB.res, M20X_PPVphAB.reg, M20X_PPVphAB.nb)) {
      return false;
    }
    if (!GetRegister(M20X_V_SF.res, M20X_V_SF.reg, M20X_V_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_PPVphAB.res) * pow(10, M20X_V_SF.res);
  } else if (ph_pair == "BC") {
    if (!GetRegister(M20X_PPVphBC.res, M20X_PPVphBC.reg, M20X_PPVphBC.nb)) {
      return false;
    }
    if (!GetRegister(M20X_V_SF.res, M20X_V_SF.reg, M20X_V_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_PPVphBC.res) * pow(10, M20X_V_SF.res);
  } else if (ph_pair == "CA") {
    if (!GetRegister(M20X_PPVphCA.res, M20X_PPVphCA.reg, M20X_PPVphCA.nb)) {
      return false;
    }
    if (!GetRegister(M20X_V_SF.res, M20X_V_SF.reg, M20X_V_SF.nb)) {
      return false;
    }
    res = static_cast<double>(M20X_PPVphCA.res) * pow(10, M20X_V_SF.res);
  } else {
    ErrorMessage = "Invalid phase pair " + ph_pair;
    return false;
  }

  return true;
}

bool MeterModel::GetAcPower(double &res) {
  if (!GetRegister(M20X_W.res, M20X_W.reg, M20X_W.nb)) {
    return false;
  }
  if (!GetRegister(M20X_W_SF.res, M20X_W_SF.reg, M20X_W_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_W.res) * pow(10, M20X_W_SF.res);

  return true;
}

bool MeterModel::GetAcFrequency(double &res) {
  if (!GetRegister(M20X_Hz.res, M20X_Hz.reg, M20X_Hz.nb)) {
    return false;
  }
  if (!GetRegister(M20X_Hz_SF.res, M20X_Hz_SF.reg, M20X_Hz_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_Hz.res) * pow(10, M20X_Hz_SF.res);

  return true;
}

bool MeterModel::GetAcPowerApparent(double &res) {
  if (!GetRegister(M20X_VA.res, M20X_VA.reg, M20X_VA.nb)) {
    return false;
  }
  if (!GetRegister(M20X_VA_SF.res, M20X_VA_SF.reg, M20X_VA_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_VA.res) * pow(10, M20X_VA_SF.res);

  return true;
}

bool MeterModel::GetAcPowerReactive(double &res) {
  if (!GetRegister(M20X_VAR.res, M20X_VAR.reg, M20X_VAR.nb)) {
    return false;
  }
  if (!GetRegister(M20X_VAR_SF.res, M20X_VAR_SF.reg, M20X_VAR_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_VAR.res) * pow(10, M20X_VAR_SF.res);

  return true;
}

bool MeterModel::GetAcPowerFactor(double &res) {
  if (!GetRegister(M20X_PF.res, M20X_PF.reg, M20X_PF.nb)) {
    return false;
  }
  if (!GetRegister(M20X_PF_SF.res, M20X_PF_SF.reg, M20X_PF_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_PF.res) * pow(10, M20X_PF_SF.res);

  return true;
}

bool MeterModel::GetAcEnergyExport(double &res) {
  if (!GetRegister(M20X_TotWhExp.res, M20X_TotWhExp.reg, M20X_TotWhExp.nb)) {
    return false;
  }
  if (!GetRegister(M20X_TotWh_SF.res, M20X_TotWh_SF.reg, M20X_TotWh_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_TotWhExp.res) * pow(10, M20X_TotWh_SF.res) *
        0.001f;

  return true;
}

bool MeterModel::GetAcEnergyImport(double &res) {
  if (!GetRegister(M20X_TotWhImp.res, M20X_TotWhImp.reg, M20X_TotWhImp.nb)) {
    return false;
  }
  if (!GetRegister(M20X_TotWh_SF.res, M20X_TotWh_SF.reg, M20X_TotWh_SF.nb)) {
    return false;
  }
  res = static_cast<double>(M20X_TotWhImp.res) * pow(10, M20X_TotWh_SF.res) *
        0.001f;

  return true;
}

#endif
