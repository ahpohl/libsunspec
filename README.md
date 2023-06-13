[![Build Status](https://travis-ci.com/ahpohl/libsunspec.svg?branch=master)](https://travis-ci.com/ahpohl/libsunspec)
# Overview

Libsunspec adheres to the SunSpec INT+SF register map but could be easily adapted to the float registers. Modbus TCP and Modbus RTU register maps were downloaded from the [Fronius website](https://www.fronius.com/en/solar-energy/installers-partners/technical-data/all-products/system-monitoring/open-interfaces/modbus-tcp). The libsunspec library currently supports string inverters with up to two 2 strings, and support for Modbus compatible smartmeters and batteries could be added later if needed (don't have such devices for testing). The example folder contains basic demo programs how to use the library. The full API documentation of all classes, methods and namespaces is provided [here]((https://ahpohl.github.io/libsunspec/))

The library is written in plain C++ and implements the basic functions to communicate with the inverter, meter or storage device. It depends only on [libmodbus](https://libmodbus.org/) for low level methods.

# Compilation

With a suitable [toolchain](https://archlinuxarm.org/wiki/Distcc_Cross-Compiling), (cross)-compilation of the library is done like this:

```
make CROSS_COMPILE=aarch64 examples
```

# Changelog

All notable changes and releases are documented in the [CHANGELOG](CHANGELOG.md).

# License

The library is licensed under the GNU Public License - see the [LICENSE](LICENSE) file for details. The library is provided as-is without any warranty given.
