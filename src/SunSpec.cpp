#include <SunSpec.h>
#include <SunSpecModelFloat.h>
#include <SunSpecModelIntSf.h>
#include <cmath>
#include <cstring>
#include <iostream>
#include <modbus/modbus.h>
#include <string>

#ifdef MODEL_INTSF
using namespace CommonRegisterMapIntSf;
#endif

#ifdef MODEL_FLOAT
using namespace CommonRegisterMapFloat;
#endif

SunSpec::SunSpec(void) : Ctx(nullptr) {}

SunSpec::~SunSpec(void) {
  modbus_close(Ctx);
  modbus_free(Ctx);
}

std::string SunSpec::GetErrorMessage(void) const { return ErrorMessage; }

bool SunSpec::ConnectModbusTcp(const std::string &node,
                               const std::string &service) {
  if (node.empty()) {
    ErrorMessage = "Node argument empty";
    return false;
  }
  Ctx = modbus_new_tcp_pi(node.c_str(), service.c_str());
  if (Ctx == nullptr) {
    ErrorMessage = "Unable to create the libmodbus context";
    return false;
  }
  if (modbus_connect(Ctx)) {
    ErrorMessage = std::string("Connection to \"") + node +
                   "\" failed: " + modbus_strerror(errno) + " (" +
                   std::to_string(errno) + ")";
    return false;
  }
  return true;
}

bool SunSpec::ConnectModbusRtu(const std::string &device,
                               const int &baud_rate) {
  if (device.empty()) {
    ErrorMessage = "Serial device argument empty";
    return false;
  }
  Ctx = modbus_new_rtu(device.c_str(), baud_rate, 'N', 8, 1);
  if (Ctx == nullptr) {
    ErrorMessage = "Unable to create the libmodbus context";
    return false;
  }
  if (modbus_connect(Ctx) == -1) {
    ErrorMessage = std::string("Connection to \"") + device +
                   "\" failed: " + modbus_strerror(errno) + " (" +
                   std::to_string(errno) + ")";
    return false;
  }
  if (!SetModbusAddress()) {
    return false;
  }

  return true;
}

void SunSpec::SetModbusDebug(const bool &debug) {
  modbus_set_debug(Ctx, debug);
}

bool SunSpec::SetModbusAddress(const int &slave_id) {
  if ((slave_id < 1) || (slave_id > 247)) {
    ErrorMessage = std::string("Invalid slave ID (") +
                   std::to_string(slave_id) +
                   "). ID must be in the range (1-247)";
    return false;
  }
  if (modbus_set_slave(Ctx, slave_id)) {
    ErrorMessage = "Setting Modbus address failed: Invalid slave ID";
    return false;
  }
  return true;
}

bool SunSpec::GetModbusAddress(int &slave_id) {
  if ((slave_id = modbus_get_slave(Ctx)) == -1) {
    ErrorMessage =
        "Getting Modbus address failed: The Modbus context is undefined.";
    return false;
  }
  return true;
}

bool SunSpec::SetResponseTimeout(const int &millis) {
  uint32_t sec = millis / 1000;
  uint32_t usec = (millis % 1000) * 1000;

  if (modbus_set_response_timeout(Ctx, sec, usec) == -1) {
    ErrorMessage = std::string("Setting response timeout failed: ") +
                   modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
    return false;
  }
  return true;
}

bool SunSpec::GetResponseTimeout(int &millis) {
  uint32_t sec = 0;
  uint32_t usec = 0;

  if (modbus_get_response_timeout(Ctx, &sec, &usec) == -1) {
    ErrorMessage = std::string("Getting response timeout failed: ") +
                   modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
    return false;
  }
  millis = sec * 1000 + usec / 1000;

  return true;
}

bool SunSpec::SetByteTimeout(const int &millis) {
  uint32_t sec = millis / 1000;
  uint32_t usec = (millis % 1000) * 1000;

  if (modbus_set_byte_timeout(Ctx, sec, usec) == -1) {
    ErrorMessage = std::string("Setting byte timeout failed: ") +
                   modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
    return false;
  }
  return true;
}

bool SunSpec::GetByteTimeout(int &millis) {
  uint32_t sec = 0;
  uint32_t usec = 0;

  if (modbus_get_byte_timeout(Ctx, &sec, &usec) == -1) {
    ErrorMessage = std::string("Getting byte timeout failed: ") +
                   modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
    return false;
  }
  millis = sec * 1000 + usec / 1000;

  return true;
}

bool SunSpec::SetIndicationTimeout(const int &millis) {
  uint32_t sec = millis / 1000;
  uint32_t usec = (millis % 1000) * 1000;

  if (modbus_set_indication_timeout(Ctx, sec, usec) == -1) {
    ErrorMessage = std::string("Setting indication timeout failed: ") +
                   modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
    return false;
  }
  return true;
}

bool SunSpec::GetIndicationTimeout(int &millis) {
  uint32_t sec = 0;
  uint32_t usec = 0;

  if (modbus_get_indication_timeout(Ctx, &sec, &usec) == -1) {
    ErrorMessage = std::string("Getting indication timeout failed: ") +
                   modbus_strerror(errno) + " (" + std::to_string(errno) + ")";
    return false;
  }
  millis = sec * 1000 + usec / 1000;

  return true;
}

bool SunSpec::SetErrorRecovery(const bool recovery) {
  if (recovery) {
    if (modbus_set_error_recovery(Ctx, static_cast<modbus_error_recovery_mode>(
                                           MODBUS_ERROR_RECOVERY_LINK |
                                           MODBUS_ERROR_RECOVERY_PROTOCOL)) ==
        -1) {
      ErrorMessage = std::string("Setting error recovery mode failed: ") +
                     modbus_strerror(errno) + " (" + std::to_string(errno) +
                     ")";
      return false;
    }

  } else {
    if (modbus_set_error_recovery(Ctx, MODBUS_ERROR_RECOVERY_NONE) == -1) {
      ErrorMessage = std::string("Setting error recovery mode failed: ") +
                     modbus_strerror(errno) + " (" + std::to_string(errno) +
                     ")";
      return false;
    }
  }

  return true;
}

uint16_t *SunSpec::ReadRegister(const uint16_t &address, const uint16_t &size) {
  uint16_t *tab_reg = (uint16_t *)malloc(sizeof(uint16_t) * size);
  if (!tab_reg) {
    return nullptr;
  }

  int rc = 0;
  rc = modbus_read_registers(Ctx, address, size, tab_reg);
  if (rc == -1) {
    ErrorMessage = std::string("Read register ") + std::to_string(address) +
                   " failed: " + modbus_strerror(errno) + " (" +
                   std::to_string(errno) + ")";
    return nullptr;
  }
  return tab_reg;
}

template <typename T>
T SunSpec::ConvertRegister(const uint16_t *tab_reg, const uint16_t &size) {
  uint16_t tab_rev[size] = {0};
  uint16_t *ptr = (uint16_t *)&tab_reg[size - 1];
  for (int i = 0; i < size; i++) {
    tab_rev[i] = *ptr--;
  }
  T res = 0;
  memcpy(&res, tab_rev, sizeof(uint16_t) * size);

  return res;
}

/** Convert raw Modbus registers to string */
template <>
std::string SunSpec::ConvertRegister(const uint16_t *tab_reg,
                                     const uint16_t &size) {
  std::string str;

  for (int i = 0; i < size; i++) {
    str.push_back((tab_reg[i] >> 8) & 0xFF);
    str.push_back(tab_reg[i]);
  }
  return str;
}

/** Convert raw Modbus registers to float */
template <>
float SunSpec::ConvertRegister(const uint16_t *tab_reg, const uint16_t &size) {
  if (size == 2)
    return modbus_get_float_abcd(tab_reg);
  else
    return 0;
}

template <typename T>
bool SunSpec::GetRegister(T &res, const uint16_t &reg_addr,
                          const uint16_t &size) {
  uint16_t *tab_reg = nullptr;

  tab_reg = ReadRegister(reg_addr, size);
  if (!tab_reg) {
    return false;
  }
  res = ConvertRegister<T>(tab_reg, size);
  delete tab_reg;

  return true;
}

template bool SunSpec::GetRegister(int16_t &, const uint16_t &,
                                   const uint16_t &);
template bool SunSpec::GetRegister(uint16_t &, const uint16_t &,
                                   const uint16_t &);
template bool SunSpec::GetRegister(uint32_t &, const uint16_t &,
                                   const uint16_t &);
template bool SunSpec::GetRegister(uint64_t &, const uint16_t &,
                                   const uint16_t &);
template bool SunSpec::GetRegister(std::string &, const uint16_t &,
                                   const uint16_t &);
template bool SunSpec::GetRegister(float &, const uint16_t &, const uint16_t &);

bool SunSpec::SetRegister(const uint16_t &value, const uint16_t &reg_addr) {
  int rc = 0;

  rc = modbus_write_register(Ctx, reg_addr, value);
  if (rc == -1) {
    ErrorMessage = std::string("Write register ") + std::to_string(reg_addr) +
                   " failed: " + modbus_strerror(errno) + " (" +
                   std::to_string(errno) + ")";
    return false;
  }

  return true;
}
