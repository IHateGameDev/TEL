<div align="center">

# TEM - create your extensible application

</div>

<div align="center">
  <img align="center" src="./logo.webp" alt="Logo" />
</div>

## Features
- Quick creation of extension system based on shared libraries
- Easy and tiny API
- Few depends:
  - std c lib,
  - [APIMacros](https://github.com/IHateGameDev/APIMacros), without use "APIMacros/override"
    - dlfcn.h / windows.h

## Build
Default install and build commands:
```bash
git clone https://github.com/IHateGameDev/TEM.git
cd TEM
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release .. -g Ninja # -DBUILD_DOC=ON (optional)
ninja

ninja install
#ninja doc (optional)
```

You can safely use `make` instead of `ninja`:
```bash
git clone https://github.com/IHAteGameDev/TEM.git
cd TEM
mkdir build cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make

make install
#make doc (optional)
```

## Guidelines
See the [Guidelines.md](./Guidelines.md) for implementing TEM in a project and standard specification for creating extensions.
