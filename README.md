[![Build Status](https://app.travis-ci.com/ahpohl/libsunspec.svg?token=PqpcagUybwzKsd39Gz54&branch=master)](https://app.travis-ci.com/ahpohl/libsunspec)

# Overview

Libsunspec is a C++ library which implements the basic methods to communicate with a Fronius inverter or energy meter. It depends only on [libmodbus](https://libmodbus.org/) for low level methods. Although the [register maps](https://www.fronius.com/en/solar-energy/installers-partners/technical-data/all-products/system-monitoring/open-interfaces/modbus-tcp) used are the ones provided by Fronius, the methods are SunSpec compatible and should also work for any other inverter which adheres to the SunSpec standard.

The library supports Modbus TCP and Modbus RTU communication protocols and float and integer + scale factor data formats. The choice between either data format needs to be done during compile time of the library and cannot be changed afterwards.

The library currently supports Fronius string inverters with up to two 2 strings and also the Fronius energy meter (although not tested). The example folder contains basic demonstrations how to use the library. The full API documentation of all classes, methods and namespaces is provided [here](https://ahpohl.github.io/libsunspec/).

## Native compilation

A Makefile is provided and compilation is done by the usual `make` and `make install` commands. By default, the library uses the float data format. This can be changed to the integer + scale factor format with `make MODEL=int+sf`. The examples are built with `make examples`.

## Cross compilation

The Makefile supports cross compilation with `make CROSS_COMPILE=aarch64-unknown-linux-gnu`. A cross toolchain can be easily built with [Crosstool-NG](https://crosstool-ng.github.io/) as it provides pre-configured toolchains for all kinds of target architectures. For example, to compile a toolchain for aarch64:

```
ct-ng list-samples
ct-ng aarch64-unknown-linux-gnu
ct-ng build
```

The final toolchain is copied to the `/home/user/x-tools/aarch64-unknown-linux-gnu` folder and needs to be added to the PATH:

```
export PATH=$PATH:/home/alex/x-tools/aarch64-unknown-linux-gnu/bin
```

Libsunspec depends on libmodbus. Therefore libmodbus needs to be compiled for the target architeture and copied to sysroot folder of the cross toolchain:

```
cd libmodbus
./configure --prefix=/home/alex/x-tools/aarch64-unknown-linux-gnu/aarch64-unknown-linux-gnu/sysroot/usr --host=aarch64-unknown-linux-gnu
make install
```