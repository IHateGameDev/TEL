# Guidelines
## Table of contents:
- [Install guide](#installGuide)
- [TEM implementing in project for developers](#applicationsDevelopersGuide)
- [Standard specification for extensions developers](#extensionsDevelopersGuide)

<a name="installGuide"></a>

## Install and build guide

<a name="installAPIMacros"></a>

### Install APIMacros

Before buils TEM you need download or get [APIMacros](https://github.com/IHateGameDev/APIMacros).<br>

Download and install(NOT RECOMMENDED):
```bash
git clone https://github.com/IHateGameDev/APIMacros.git
cd APIMacros
mkdir build
cd build

cmake ..
sudo make install

# OR:
# cmake .. -G Ninja
# ninja install
```

Get only needed depends(RECOMMENDED):<br>
[Download TEM](#downloadTEM) and write this in terminal:

```bash
mkdir APIMacros
cd APIMacros
# Downloading
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/api.h
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/shared.h
cd ..
```

You finally got APIMacros!

<a name="downloadTEM"></a>

### Download TEM

For download TEM write this in terminal:

```bash
git clone https://github.com/IHateGameDev/TEM.git
cd TEM
```

### Build and install TEM

Before building you need [install APIMacros](#installAPIMacros) and [download TEM](#downloadTEM).<br>
For build TEM write this in terminal:

```bash
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=OFF .. # -G Ninja
make # ninja

make install # ninja install
```

You can configure building, see "CMake options" on [Readme.md](./Readme.md).<br>
This steps install TEM on you PC.

### Summary

Example text in terminal:
```bash
git clone https://github.com/IHateGameDev/TEM.git
cd TEM

mkdir APIMacros
cd APIMacros

wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/api.h
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/shared.h

cd ..
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=ON .. -G Ninja
ninja

ninja install
```

<a name="applicationsDevelopersGuide"></a>

## TEM implementing in project

```bash

```

Loadind library

<a name="extensionsDevelopersGuide"></a>

## Standard specification
