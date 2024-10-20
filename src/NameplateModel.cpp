#include <cmath>
#include "NameplateModel.h"
#include "SunSpec.h"
#include "SunSpecModelIntSf.h"
#include "SunSpecModelFloat.h"

#ifdef MODEL_INTSF
using namespace NameplateRegisterMapIntSf;
#endif

#ifdef MODEL_FLOAT
using namespace NameplateRegisterMapFloat;
#endif

bool NameplateModel::IsNameplateRegisterMap(void) {
  if (!GetRegister(I120_ID.res, I120_ID.reg, I120_ID.nb)) {
    return false;
  }
  if (!(I120_ID.res == 120)) {
    ErrorMessage = std::string("Invalid ID of Nameplate Model block (")
        + std::to_string(I120_ID.res) + ")";
    return false;
  }
  if (!GetRegister(I120_L.res, I120_L.reg, I120_L.nb)) {
    return false;
  }
  if (I120_L.res != 26) {
    ErrorMessage = std::string("Invalid length of Nameplate Model block (")
        + std::to_string(I120_L.res) + ")";
    return false;
  }

  return true;
}

bool NameplateModel::GetPowerOutputMax(double &res) {
  if (!GetRegister(I120_WRtg.res, I120_WRtg.reg, I120_WRtg.nb)) {
    return false;
  }
  if (!GetRegister(I120_WRtg_SF.res, I120_WRtg_SF.reg, I120_WRtg_SF.nb)) {
    return false;
  }
  res = static_cast<double>(I120_WRtg.res) * pow(10, I120_WRtg_SF.res);

  return true;
}

bool NameplateModel::GetPowerApparentMax(double &res) {
  if (!GetRegister(I120_VARtg.res, I120_VARtg.reg, I120_VARtg.nb)) {
    return false;
  }
  if (!GetRegister(I120_VARtg_SF.res, I120_VARtg_SF.reg, I120_VARtg_SF.nb)) {
    return false;
  }
  res = static_cast<double>(I120_VARtg.res) * pow(10, I120_VARtg_SF.res);

  return true;
}

bool NameplateModel::GetPowerReactiveMax(double &res, const int quadrant) {
  if (!GetRegister(I120_VArRtg_SF.res, I120_VArRtg_SF.reg, I120_VArRtg_SF.nb)) {
    return false;
  }

  switch (quadrant) {
    case 1:
      if (!GetRegister(I120_VArRtgQ1.res, I120_VArRtgQ1.reg,
                       I120_VArRtgQ1.nb)) {
        return false;
      }
      res = static_cast<double>(I120_VArRtgQ1.res)
          * pow(10, I120_VArRtg_SF.res);
      break;
    case 2:
      if (!GetRegister(I120_VArRtgQ2.res, I120_VArRtgQ2.reg,
                       I120_VArRtgQ2.nb)) {
        return false;
      }
      res = static_cast<double>(I120_VArRtgQ2.res)
          * pow(10, I120_VArRtg_SF.res);
      break;
    case 3:
      if (!GetRegister(I120_VArRtgQ3.res, I120_VArRtgQ3.reg,
                       I120_VArRtgQ3.nb)) {
        return false;
      }
      res = static_cast<double>(I120_VArRtgQ3.res)
          * pow(10, I120_VArRtg_SF.res);
      break;
    case 4:
      if (!GetRegister(I120_VArRtgQ4.res, I120_VArRtgQ4.reg,
                       I120_VArRtgQ4.nb)) {
        return false;
      }
      res = static_cast<double>(I120_VArRtgQ4.res)
          * pow(10, I120_VArRtg_SF.res);
      break;
    default:
      ErrorMessage = std::string("Invalid quadrant (")
          + std::to_string(quadrant) + ")";
      return false;
  }

  return true;
}

bool NameplateModel::GetAcCurrentMax(double &res) {
  if (!GetRegister(I120_ARtg.res, I120_ARtg.reg, I120_ARtg.nb)) {
    return false;
  }
  if (!GetRegister(I120_ARtg_SF.res, I120_ARtg_SF.reg, I120_ARtg_SF.nb)) {
    return false;
  }
  res = static_cast<double>(I120_ARtg.res) * pow(10, I120_ARtg_SF.res);

  return true;
}

bool NameplateModel::GetPowerFactorMin(double &res, const int quadrant) {
  if (!GetRegister(I120_PFRtg_SF.res, I120_PFRtg_SF.reg, I120_PFRtg_SF.nb)) {
    return false;
  }

  switch (quadrant) {
    case 1:
      if (!GetRegister(I120_PFRtgQ1.res, I120_PFRtgQ1.reg, I120_PFRtgQ1.nb)) {
        return false;
      }
      res = static_cast<double>(I120_PFRtgQ1.res) * pow(10, I120_PFRtg_SF.res);
      break;
    case 2:
      if (!GetRegister(I120_PFRtgQ2.res, I120_PFRtgQ2.reg, I120_PFRtgQ2.nb)) {
        return false;
      }
      res = static_cast<double>(I120_PFRtgQ2.res) * pow(10, I120_PFRtg_SF.res);
      break;
    case 3:
      if (!GetRegister(I120_PFRtgQ3.res, I120_PFRtgQ3.reg, I120_PFRtgQ3.nb)) {
        return false;
      }
      res = static_cast<double>(I120_PFRtgQ3.res) * pow(10, I120_PFRtg_SF.res);
      break;
    case 4:
      if (!GetRegister(I120_PFRtgQ4.res, I120_PFRtgQ4.reg, I120_PFRtgQ4.nb)) {
        return false;
      }
      res = static_cast<double>(I120_PFRtgQ4.res) * pow(10, I120_PFRtg_SF.res);
      break;
    default:
      ErrorMessage = std::string("Invalid quadrant (")
          + std::to_string(quadrant) + ")";
      return false;
  }

  return true;
}
