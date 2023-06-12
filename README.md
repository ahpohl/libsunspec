[![Build Status](https://travis-ci.com/ahpohl/libsunspec.svg?branch=master)](https://travis-ci.com/ahpohl/libsunspec)
# Overview

Libsunspec provides methods to read data from SunSpec compatible inverters, meters and batteries. Currently only Fronius 2-string inverters such as Primo and Symo are implemeted, but the classes were designed in such a way that extension to other SunSpec compatible inverters such as SMA Sunny Boy is easy. The library supports both ModBus TCP and ModBus RTU connections. It implements the [INT+SF register map](.docs/sunspec/Inverter_Register_Map_Int&SF_v1.0_with_SYMOHYBRID_MODEL_124.xlsx), but could be easily adopted to the float model as well.

The library is written in plain C++ and implements the basic functions to communicate with the inverter. It depends only on [libmodbus](https://libmodbus.org/) for low level methods and supports cross compilation on x86_64 for aarch64.

# Documentation

The library API documentation including some basic examples is located [here](https://ahpohl.github.io/libsunspec/).

# Related projects

* [libfronius](https://github.com/mhei/libfronius) by Michael Heimpold, only supports the old Fronius protocol

# Changelog

All notable changes and releases are documented in the [CHANGELOG](CHANGELOG.md).

# License

The library is licensed under the GNU Public License - see the [LICENSE](LICENSE) file for details. The library is provided as-is without any warranty given.
