#include "MultiMpptModel.h"
#include "SunSpec.h"
#include "SunSpecModelIntSf.h"
#include "SunSpecModelFloat.h"
#include <cmath>

#ifdef MODEL_INTSF
using namespace MultiMpptRegisterMapIntSf;
#endif

#ifdef MODEL_FLOAT
using namespace MultiMpptRegisterMapFloat;
#endif

bool MultiMpptModel::IsMultiMpptRegisterMap(void) {
  if (!GetRegister(I160_ID.res, I160_ID.reg, I160_ID.nb)) {
    return false;
  }
  if (I160_ID.res != 160) {
    ErrorMessage = std::string("Invalid ID of Multi MPPT Model block (")
        + std::to_string(I160_ID.res) + ")";
    return false;
  }
  if (!GetRegister(I160_L.res, I160_L.reg, I160_L.nb)) {
    return false;
  }
  if (I160_L.res != 48) {
    ErrorMessage = std::string("Invalid length of Multi MPPT Model block (")
        + std::to_string(I160_L.res) + ")";
    return false;
  }

  return true;
}

bool MultiMpptModel::GetDcCurrent(double &res, const int string_id) {
  switch (string_id) {
    case 1:
      if (!GetRegister(I160_1_DCA.res, I160_1_DCA.reg, I160_1_DCA.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCA_SF.res, I160_DCA_SF.reg, I160_DCA_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_1_DCA.res) * pow(10, I160_DCA_SF.res);
      break;
    case 2:
      if (!GetRegister(I160_2_DCA.res, I160_2_DCA.reg, I160_2_DCA.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCA_SF.res, I160_DCA_SF.reg, I160_DCA_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_2_DCA.res) * pow(10, I160_DCA_SF.res);
      break;
    default:
      ErrorMessage = std::string("Invalid string ID (")
          + std::to_string(string_id) + ")";
      return false;
  }

  return true;
}

bool MultiMpptModel::GetDcVoltage(double &res, const int string_id) {
  switch (string_id) {
    case 1:
      if (!GetRegister(I160_1_DCV.res, I160_1_DCV.reg, I160_1_DCV.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCV_SF.res, I160_DCV_SF.reg, I160_DCV_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_1_DCV.res) * pow(10, I160_DCV_SF.res);
      break;
    case 2:
      if (!GetRegister(I160_2_DCV.res, I160_2_DCV.reg, I160_2_DCV.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCV_SF.res, I160_DCV_SF.reg, I160_DCV_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_2_DCV.res) * pow(10, I160_DCV_SF.res);
      break;
    default:
      ErrorMessage = std::string("Invalid string ID (")
          + std::to_string(string_id) + ")";
      return false;
  }

  return true;
}

bool MultiMpptModel::GetDcPower(double &res, const int string_id) {
  switch (string_id) {
    case 1:
      if (!GetRegister(I160_1_DCW.res, I160_1_DCW.reg, I160_1_DCW.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCW_SF.res, I160_DCW_SF.reg, I160_DCW_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_1_DCW.res) * pow(10, I160_DCW_SF.res);
      break;
    case 2:
      if (!GetRegister(I160_2_DCW.res, I160_2_DCW.reg, I160_2_DCW.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCW_SF.res, I160_DCW_SF.reg, I160_DCW_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_2_DCW.res) * pow(10, I160_DCW_SF.res);
      break;
    default:
      ErrorMessage = std::string("Invalid string ID (")
          + std::to_string(string_id) + ")";
      return false;
  }

  return true;
}

bool MultiMpptModel::GetDcEnergyLifetime(double &res, const int string_id) {
  switch (string_id) {
    case 1:
      if (!GetRegister(I160_1_DCWH.res, I160_1_DCWH.reg, I160_1_DCWH.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCWH_SF.res, I160_DCWH_SF.reg, I160_DCWH_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_1_DCWH.res) * pow(10, I160_DCWH_SF.res)
          * 0.001f;
      break;
    case 2:
      if (!GetRegister(I160_2_DCWH.res, I160_2_DCWH.reg, I160_2_DCWH.nb)) {
        return false;
      }
      if (!GetRegister(I160_DCWH_SF.res, I160_DCWH_SF.reg, I160_DCWH_SF.nb)) {
        return false;
      }
      res = static_cast<double>(I160_2_DCWH.res) * pow(10, I160_DCWH_SF.res)
          * 0.001f;
      break;
    default:
      ErrorMessage = std::string("Invalid string ID (")
          + std::to_string(string_id) + ")";
      return false;
  }

  return true;
}
