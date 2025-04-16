<div align="center">

# TEM - create your extensible application

</div>

<div align="center">

![Static Badge](https://img.shields.io/badge/Release-v0.1.0-blue)
![Static Badge](https://img.shields.io/badge/Build%20status-passed-green)
[![Static Badge](https://img.shields.io/badge/License-MIT-orange)](../License)
[![Static Badge](https://img.shields.io/badge/Documentation-page-darkcyan)](https://ihategamedev.github.io/TEM/)

</div>

<div align="center">

<img align="center" src="./Assets/Logo.webp" alt="Logo" />

</div>

## Features

- Quick creation of extension system based on shared libraries
- Easy and tiny API
- Few depends:
  - std c lib,
  - [APIMacros](https://github.com/IHateGameDev/APIMacros), without use "APIMacros/override"
    - dlfcn.h / windows.h

## Guidelines

See the [Guidelines.md](./Guidelines.md) for implementing TEM in a project and standard specification for creating extensions.

## Build

### CMake options

| **Option**     | **Description**                         | **Default value** |
| :------------- | :-------------------------------------: | ----------------: |
| BUILD_STATIC   | Add static library to targets           | ON                |
| BUILD_SHARED   | Add shared library to targets           | OFF               |
| BUILD_EXAMPLES | Enable building examples                | OFF               |
| EXAMPLES_USE   | Type of library use on compile examples | "Static"          |

### Build with CMake

Default install and build commands:
```bash
git clone https://github.com/IHateGameDev/TEM.git
cd TEM
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release .. -g Ninja
ninja

ninja install
```

You can safely use `make` instead of `ninja`:
```bash
git clone https://github.com/IHAteGameDev/TEM.git
cd TEM
mkdir build cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make

make install
```

## Contributing

If you want to contribute see [Contributing.md](./Contributing.md).
