# Guidelines

## Table of contents:
- [Install Guide](#installGuide)
- [TEM Implementing in Project for Developers](#applicationsDevelopersGuide)
- [Standard Specification for Extensions Developers](#extensionsDevelopersGuide)

<a name="installGuide"></a>

## Install and Build guide

<a name="installAPIMacros"></a>

### Install APIMacros

Before building TEM, you need to download or get [APIMacros](https://github.com/IHateGameDev/APIMacros).

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

Get only the needed dependencies(RECOMMENDED):<br>
[Download TEM](#downloadTEM) and write this in terminal:

```bash
mkdir APIMacros
cd APIMacros
# Downloading
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/api.h
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/shared.h
cd ..
```

You have successfully obtained APIMacros!

<a name="downloadTEM"></a>

### Download TEM

To download TEM, run the following commands in the terminal:

```bash
git clone https://github.com/IHateGameDev/TEM.git
cd TEM
```

### Build and Install TEM

Before building, you need [install APIMacros](#installAPIMacros) and [download TEM](#downloadTEM).<br>
To build TEM, run the following commands in the terminal:

```bash
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=OFF .. # -G Ninja
make # or ninja

make install # or ninja install
```

You can configure the build options; see "CMake options" in [Readme.md](./Readme.md).<br>
These steps will install TEM on your PC.

### Summary

Example commands in the terminal:
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

## TEM Implementing in project

If you want to implementing TEM in your project:

### Extension info

You need to create a structure for your extension info:

```c
// ExampleExtensionInfo.h
#ifndef EXAMPLE_EXTENSION_INFO_H
#define EXAMPLE_EXTENSION_INFO_H

typedef void(ExampleUpdateFn*)(ExampleExtensionInfo*)

typedef struct {
  const char * name;
  ExampleUpdateFn update;
} ExampleExtensionInfo;

#endif // !EXAMPLE_EXTENSION_INFO_H
```

This structure is used to communicate between the application and the extension, and all extensions have their own info.

Add useful functions for extension developers if needed:

```c
// SomeHeader.h
#ifndef EXAMPLE_SOME_HEADER_H
#define EXAMPLE_SOME_HEADER_H

extern char* ExampleNewString(const char* restrict src);

#endif // !EXAMPLE_SOME_HEADER_H

// SomeRealisation.c
#include "SomeHeader.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char* ExampleNewString(const char* restrict src) {
  char* out = malloc(strlen(src) + 1);
  strcpy(out, src);
  return out;
}
```

And construct you application source file:
```c
#include "ExtensionInfo.h"
#include <TEM/Extension.h>
#include <stdio.h>

int main() {
  puts("Hello from my application!\n");
  
  TEMExtension* extension = temExtensionLoad("./extension.te", "setup"/* setup function name */, sizeof(ExampleExtensionInfo));

  ExampleExtensionInfo* info = (ExampleExtensionInfo*)extension->info;

  puts("Extension: ");
  puts(info->name);
  puts(", successuflly loaded!\n");

  for (unsigned char i = 0; i < 255; i++)
    info->update();

  temExtensionUnload(extension, "cleanup"/* cleanup function name '\0' or "" for not using cleanup function */);
}
```

This code loads the extension [extension.te](#extensionsDevelopersGuide), prints its name,<br>
calls the `update` function 255 times, and calls the `cleanup` function to free `info->name`.

NOTE: If you use the shared TEM library, don't forget to add compile flag: `-DAPI_SHARED_USE`.

<a name="extensionsDevelopersGuide"></a>

## Standard Specification

We use example [this](#applicationsDevelopersGuide) application.

Create the extension's main file:

```c
#include "ExampleExtensionInfo.h"
#include "SomeHeader.h"

#include "APIMacros/api.h" // optional but recommended
#include <stdio.h>
#include <stdlib.h>

// Create the update function:
void someUpdate(ExampleExtensionInfo* info) {
  puts("Update: ");
  puts(info->name);
  puts("!\n")
}

// Add setup function:
API/*optional but recommended*/ void setup(ExampleExtensionInfo* info) {
  info->name = ExampleNewString("ExampleExtension (;o;)");
  info->update = someUpdate;
}

//Add the cleanup function to free allocated memory:
API/*optional but recommended*/ void cleanup(ExampleExtensionInfo* info) {
  free(info->name);
}
```

NOTE: Don't forget to add `-fPIC` and, if you use "APIMacros/api.h", also add `-DAPI_SHARED_BUILD`.
