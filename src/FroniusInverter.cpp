#include "FroniusInverter.h"

bool FroniusInverter::IsSunSpecInverter(void) {
  if (!IsCommonRegisterMap()) {
    return false;
  }
  if (!IsNameplateRegisterMap()) {
    return false;
  }
  if (!IsInverterRegisterMap()) {
    return false;
  }
  if (!IsExtendedRegisterMap()) {
    return false;
  }
  if (!IsImmediateRegisterMap()) {
    return false;
  }
  if (!IsMultiMpptRegisterMap()) {
    return false;
  }

  return true;
}

bool FroniusInverter::SetStateCodeStr(StateCode_t &state) {
  if (state.Model.find("Primo") != std::string::npos) {
    switch (state.St) {
      case 0:
        break;
      case 102:
        state.StStr = "AC voltage too high";
        break;
      case 103:
        state.StStr = "AC voltage too low";
        break;
      case 105:
        state.StStr = "AC frequency too high";
        break;
      case 106:
        state.StStr = "AC frequency too low";
        break;
      case 107:
        state.StStr = "No AC grid detected / Wrong AC Grid State detected";
        break;
      case 108:
        state.StStr = "Islanding detected";
        break;
      case 112:
        state.StStr = "Residual Current Detected";
        break;
      case 240:
        state.StStr = "Arc Detected";
        break;
      case 245:
        state.StStr = "Arc Fault Cicruit Interrupter (AFCI) Selftest failed";
        break;
      case 247:
        state.StStr =
            "Arc Fault Cicruit Interrupter (AFCI) current sensor error";
        break;
      case 249:
        state.StStr =
            "Arc Fault Cicruit Interrupter (AFCI) detected unplausibel measurement values";
        break;
      case 301:
        state.StStr = "Overcurrent AC";
        break;
      case 302:
        state.StStr = "Overcurrent DC";
        break;
      case 303:
        state.StStr = "Channel 1 Overtemperature";
        break;
      case 304:
        state.StStr = "Channel 2 Overtemperature";
        break;
      case 305:
        state.StStr = "Intermediate Circuit Undervoltage";
        break;
      case 306:
        state.StStr = "Power Low";
        break;
      case 307:
        state.StStr = "DC Voltage Low";
        break;
      case 308:
        state.StStr = "Intermediate circuit voltage too high";
        break;
      case 309:
        state.StStr = "DC1 Input Overvoltage";
        break;
      case 313:
        state.StStr = "DC2 Input Overvoltage";
        break;
      case 401:
        state.StStr = "Power Stack Communication Error";
        break;
      case 406:
        state.StStr = "Error temperature sensor on DC board";
        break;
      case 407:
        state.StStr = "Error temperature sensor on AC board";
        break;
      case 408:
        state.StStr = "DC detected in grid";
        break;
      case 412:
        state.StStr = "DC1 Fix Voltage Out Of Range";
        break;
      case 415:
        state.StStr = "Wired Shutdown Triggered";
        break;
      case 416:
        state.StStr = "RECERBO - Power Stack Communication Error";
        break;
      case 417:
        state.StStr = "Hardware-ID Collision";
        break;
      case 419:
        state.StStr = "Unique ID-collision";
        break;
      case 421:
        state.StStr = "Hardware ID-sequence error";
        break;
      case 425:
        state.StStr = "Data Exchange Timeout";
        break;
      case 426:
        state.StStr = "Intermediate Circuit Loading Timeout";
        break;
      case 427:
        state.StStr = "Power Stack Ready Timeout";
        break;
      case 428:
        state.StStr = "Possible hardware fault";
        break;
      case 431:
        state.StStr = "Power Stack In Bootmode";
        break;
      case 436:
        state.StStr = "Invalid Bitmap Received";
        break;
      case 437:
        state.StStr = "Power Stack Event Handling Error";
        break;
      case 438:
        state.StStr = "Functional incompatibility";
        break;
      case 443:
        state.StStr = "DC/DC energy transfer failure";
        break;
      case 445:
        state.StStr = "Invalid Parameters detected";
        break;
      case 447:
        state.StStr = "Isolation Error";
        break;
      case 450:
        state.StStr = "Guard Controller - Communication Error";
        break;
      case 451:
        state.StStr = "Memory Check Error";
        break;
      case 452:
        state.StStr = "Power Stack - Filter Communication Error";
        break;
      case 453:
        state.StStr = "Guard Controller - AC voltage error";
        break;
      case 454:
        state.StStr = "Guard Controller - AC Frequency Error";
        break;
      case 456:
        state.StStr = "Guard Controller - Anti Islanding Selftest Error";
        break;
      case 457:
        state.StStr = "Grid Relay Error";
        break;
      case 459:
        state.StStr = "Guard Controller - Isolation Selftest Error";
        break;
      case 460:
        state.StStr = "Power Stack / Filter Print Reference Voltage Error";
        break;
      case 461:
        state.StStr = "RAM Error / Collective Fault";
        break;
      case 462:
        state.StStr = "Guard Controller - DC injection into grid detected";
        break;
      case 463:
        state.StStr = "AC Poles reversed";
        break;
      case 474:
        state.StStr = "Residual Current Sensor defect";
        break;
      case 475:
        state.StStr = "Isolation Too Low Error";
        break;
      case 476:
        state.StStr = "Power Stack Supply Missing";
        break;
      case 482:
        state.StStr = "Installation wizard aborted";
        break;
      case 502:
        state.StStr = "Warning - Isolation Too Low";
        break;
      case 509:
        state.StStr = "No Feed In For 24 Hours";
        break;
      case 515:
        state.StStr = "No communication with filter";
        break;
      case 516:
        state.StStr = "Power Stack EEPROM Error";
        break;
      case 517:
        state.StStr = "Power Derating Due To Overtemperature";
        break;
      case 558:
        state.StStr = "Incompatible Power Stack Software";
        break;
      case 560:
        state.StStr = "Power Derating Due To High Grid Frequency";
        break;
      case 705:
        state.StStr = "Solar Net - Node Type Conflict";
        break;
      case 721:
        state.StStr = "EEPROM - Reinitialized";
        break;
      case 731:
        state.StStr = "USB Flash Drive Initializing Error";
        break;
      case 732:
        state.StStr = "USB Flash Drive Overcurrent";
        break;
      case 733:
        state.StStr = "No USB Flash Drive Inserted";
        break;
      case 734:
        state.StStr = "No Software Update Found On USB Flash Drive";
        break;
      case 735:
        state.StStr = "No Supported Software Update Found On USB Flash Drive";
        break;
      case 736:
        state.StStr = "USB Flash Drive Flash Drive Read/Write Error";
        break;
      case 738:
        state.StStr = "Log-File Can't Be Created On The USB Flash Drive";
        break;
      case 743:
        state.StStr = "Software Update Failed";
        break;
      case 745:
        state.StStr = "Software Update Checksum Wrong";
        break;
      case 751:
        state.StStr = "Real Time Clock - Time Lost";
        break;
      case 752:
        state.StStr = "Real Time Clock - Hardware Error";
        break;
      case 757:
        state.StStr = "Real Time Clock - Hardware Error";
        break;
      case 758:
        state.StStr = "Real Time Clock - Emergency Mode";
        break;
      case 766:
        state.StStr = "Power Limit Not Found";
        break;
      default:
        ErrorMessage = "Invalid Fronius Primo state code ("
            + std::to_string(state.St) + ")";
        return false;
    }

  } else if (state.Model.find("Symo") != std::string::npos) {
    switch (state.St) {
      case 0:
        break;
      default:
        ErrorMessage = "Invalid Fronius Symo state code ("
            + std::to_string(state.St) + ")";
        return false;
    }

  } else if (state.Model.find("Galvo") != std::string::npos) {
    switch (state.St) {
      case 0:
        break;
      default:
        ErrorMessage = "Invalid Fronius Galvo state code ("
            + std::to_string(state.St) + ")";
        return false;
    }

  } else if (state.Model.find("IGPlus") != std::string::npos) {
    switch (state.St) {
      case 0:
        break;
      default:
        ErrorMessage = "Invalid Fronius IG Plus state code ("
            + std::to_string(state.St) + ")";
        return false;
    }

  } else {
    ErrorMessage = "Invalid Fronius model: " + state.Model;
    return false;
  }

  return true;
}

bool FroniusInverter::GetStateCode(StateCode_t &state) {
  if (!GetActiveStateCode(state.St)) {
    return false;
  }
  if (!GetDeviceModel(state.Model)) {
    return false;
  }
  if (!SetStateCodeStr(state)) {
    return false;
  }

  return true;
}

