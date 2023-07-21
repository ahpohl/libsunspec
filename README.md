[![Build Status](https://travis-ci.com/ahpohl/libsunspec.svg?branch=master)](https://travis-ci.com/ahpohl/libsunspec)
# Overview

Libsunspec supports both SunSpec float and integer + scale factor register maps. The library uses the float model by default, but can be compiled to use the integer and scale factor model instead. Modbus TCP and Modbus RTU register maps were downloaded from the [Fronius website](https://www.fronius.com/en/solar-energy/installers-partners/technical-data/all-products/system-monitoring/open-interfaces/modbus-tcp). The libsunspec library currently supports string inverters with up to two 2 strings and Modbus compatible smartmeters such as the ones made by Fronius. Energy storage devices (i.e. batteries) could be added later, but I currently don't have such devices for testing. The example folder contains basic demo programs how to use the library. The full API documentation of all classes, methods and namespaces is provided [here](https://ahpohl.github.io/libsunspec/).

The library is written in plain C++ and implements the basic functions to communicate with the inverter or energy meter. It depends only on [libmodbus](https://libmodbus.org/) for low level methods.

# Compilation

## Native compilation

The compilation of the library follows the usual `make install` procedure, and the examples can be optionally compiled with `make examples`. The library supports both SunSpec data models integer with a scale factor and float, the latter being the default. The make command accepts and optional paramter `MODEL=int+sf` to compile the library to use integer and scale factors instead of floats. 

## Cross compilation

The Makefile supports cross compilation for example if the library is used on a Raspberry 3/4 or simialar 64-bit single board computer (currently only ARM 64 bit supported). To enable cross-compilation, there is an optional make variable `CROSS_COMPILE=aarch64-unknown-linux-gnu`. The toolchain was built with [Crosstool-NG](https://crosstool-ng.github.io/) as it provides pre-configured and easy to install toolchains for all kinds of target architectures:

```
ct-ng list-samples
ct-ng aarch64-unknown-linux-gnu
ct-ng build
```

The compiled toolchain is copied to the `/home/user/x-tools/aarch64-unknown-linux-gnu` folder. To use the toolchain you need to add the bin folder to your environment:

```
export PATH=$PATH:/home/alex/x-tools/aarch64-unknown-linux-gnu/bin
```

You also need libmodbus for the target architecture added into the sysroot of the toolchain:

```
cd libmodbus
./configure --prefix=/home/alex/x-tools/aarch64-unknown-linux-gnu/aarch64-unknown-linux-gnu/sysroot/usr --host=aarch64-unknown-linux-gnu
make install
```

# Changelog

All notable changes and releases are documented in the [CHANGELOG](CHANGELOG.md).

# License

The library is licensed under the GNU Public License - see the [LICENSE](LICENSE) file for details. The library is provided as-is without any warranty given.
