# Raspberry Pi Pico Driver class collection
A Collection of the Raspberry Pi [Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/)/[Pico2](https://www.raspberrypi.com/products/raspberry-pi-pico-2/) classes. Also, the [SDK API](https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#group_sm_config_1gaed7a6e7dc4f1979c7c62e4773df8c79b) wrapper class is provided. 

[HTML documentation](https://suikan4github.github.io/rpp_driver/) is available. 

# Details
This class collection ( or class library ) encapsule the certain data inside class. And it also allows you to use the dependency-injection inside your project. So, you can test your code with [Google Test](https://github.com/google/googletest) before testing on the target hardware. 

These classes are provided in this version. 

| class                                                  | Description |
|---------------------------------                       |----------------------------- |
| ::rpp_driver::[SdkWrapper](doc/sdkwrapper.md)         | Wrapper class of Pico SDK    |
| ::rpp_driver::[GpioBasic](doc/gpiobasic.md)           | Basic GPIO controller        |
| ::rpp_driver::[I2cMaster](doc/i2cmaster.md)           | I2C Master controller        |
| ::rpp_driver::[I2sSlaveDuplex](doc/duplexslavei2s.md) | Polling based PIO I2S driver |
| ::rpp_driver::[Adau1361](doc/adau1361.md)             | Audio CODEC driver           |


## How to obtain this project

The newest copy of this project is found in the [GitHub repository](https://github.com/suikan4github/rpp_driver). 

## How to obtain the sample programs

The newest copy of the sample program project is found in the [GitHub repository](https://github.com/suikan4github/rpp_driver-sample). 

## Sample codes
You can obtain sample applications from [rpp-driver_sample](https://github.com/suikan4github/rpp_driver-sample) repository.


# Tools and building
## Installing tool
To build the samples or test, you need to install the build tools. 
The installation of Ubuntu is : 

```sh
apt-get -y update
apt-get -y install build-essential cmake ninja-build git doxygen
apt-get -y install gcc-arm-none-eabi libnewlib-arm-none-eabi
```

## Building tests
The sample program and I2S drivers are tested by GoogleTest and fff. Follow the procedure to build the test. 

From the repository root ( where this README.md stays), run the following commands. 
```sh
mkdir build
cmake -B build -S . -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ 
cmake --build build --config Debug --target all
```

## Building document
An API document are provided by HTML files. 
To obtain it, run doxygen at the project root ( where this README.md exists).

```sh
doxygen
```

The documentation will be generated under html subdirectory. 

# License
This project is provided under [MIT License](LICENSE). 