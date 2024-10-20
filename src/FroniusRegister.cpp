#include <FroniusRegister.h>
#include <SunSpec.h>
#include <SunSpecModelIntSf.h>
#include <SunSpecModelFloat.h>

#ifdef MODEL_INTSF
using namespace FroniusRegisterMapIntSf;
#endif

#ifdef MODEL_FLOAT
using namespace FroniusRegisterMapFloat;
#endif

bool FroniusRegister::GetActiveStateCode(uint16_t &code) {
  if (!GetRegister(F_Active_State_Code.res, F_Active_State_Code.reg,
                   F_Active_State_Code.nb)) {
    return false;
  }
  code = F_Active_State_Code.res;

  return true;
}

bool FroniusRegister::ResetEventFlags(void) {
  if (!SetRegister(0xFFFF, F_Reset_All_Event_Flags.reg)) {
    return false;
  }
  return true;
}

bool FroniusRegister::GetModelType(struct ModelType_t &model) {
  if (!GetRegister(F_ModelType.res, F_ModelType.reg, F_ModelType.nb)) {
    return false;
  }
  model.Type = F_ModelType.res;

  switch (model.Type) {
    case 1:
      model.TypeStr = "floating point";
      break;
    case 2:
      model.TypeStr = "integer + scale factor";
      break;
    default:
      ErrorMessage = "Invalid model type (" + std::to_string(model.Type) + ")";
      return false;
  }
  return true;
}

bool FroniusRegister::SetModelType(const int &value) {
  if (!((value == 1) || (value == 2))) {
    ErrorMessage = "Invalid model type (" + std::to_string(value) + ")";
    return false;
  }
  if (!SetRegister(value, F_ModelType.reg)) {
    return false;
  }
  if (!SetRegister(6, F_ModelType.reg)) {
    return false;
  }
  return true;
}

bool FroniusRegister::GetSitePower(double &res) {
  if (!GetRegister(F_Site_Power.res, F_Site_Power.reg, F_Site_Power.nb)) {
    return false;
  }
  res = static_cast<double>(F_Site_Power.res);

  return true;
}

bool FroniusRegister::GetSiteEnergyDay(double &res) {
  if (!GetRegister(F_Site_Energy_Day.res, F_Site_Energy_Day.reg,
                   F_Site_Energy_Day.nb)) {
    return false;
  }
  res = static_cast<double>(F_Site_Energy_Day.res) * 0.001f;

  return true;
}

bool FroniusRegister::GetSiteEnergyYear(double &res) {
  if (!GetRegister(F_Site_Energy_Year.res, F_Site_Energy_Year.reg,
                   F_Site_Energy_Year.nb)) {
    return false;
  }
  res = static_cast<double>(F_Site_Energy_Year.res) * 0.001f;

  return true;
}

bool FroniusRegister::GetSiteEnergyTotal(double &res) {
  if (!GetRegister(F_Site_Energy_Total.res, F_Site_Energy_Total.reg,
                   F_Site_Energy_Total.nb)) {
    return false;
  }
  res = static_cast<double>(F_Site_Energy_Total.res) * 0.001f;

  return true;
}
