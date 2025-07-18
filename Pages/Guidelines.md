# Guidelines

## Table of contents:
- [Install Guide](#installGuide)
- - [Summary](#installSummary)
- [TEL Implementing in Project for Developers](#applicationsDevelopersGuide)
- [Standard Specification for Extensions Developers](#extensionsDevelopersGuide)

<a name="installGuide"></a>

## Install and Build guide

<a name="installAPIMacros"></a>

### Install APIMacros

Before building TEL, you need to download or get [APIMacros](https://github.com/IHateGameDev/APIMacros).

Download and install:

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

Get only the needed dependencies:<br>
[Download TEL](#downloadTEL) and write this in terminal:

```bash
mkdir APIMacros
cd APIMacros

# Downloading
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/api.h
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/shared.h
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/nullptr.h
cd ..
```

You have successfully obtained APIMacros!

<a name="downloadTEL"></a>

### Download TEL

To download TEL, run the following commands in the terminal:

```bash
git clone https://github.com/IHateGameDev/TEL.git
cd TEL
```

### Build and Install TEL

Before building, you need [install APIMacros](#installAPIMacros) and [download TEL](#downloadTEL).<br>
To build TEL, run the following commands in the terminal:

```bash
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=OFF .. # -G Ninja
make # or ninja

make install # or ninja install
```

You can configure the build options; see [CMake options](#cmakeOptions).<br>
These steps will install TEL on your PC.

<a name="cmakeOptions"></a>

### CMake options

| **Option**     | **Description**                         | **Default value** |
| :------------- | :-------------------------------------: | ----------------: |
| BUILD_STATIC   | Add static library to targets           | ON                |
| BUILD_SHARED   | Add shared library to targets           | OFF               |
| BUILD_EXAMPLES | Enable building examples                | OFF               |
| EXAMPLES_USE   | Type of library use on compile examples | "Static"          |

<a name="installSummary"></a>

### Summary

Example commands in the terminal:
```bash
git clone https://github.com/IHateGameDev/TEL.git
cd TEL

mkdir APIMacros
cd APIMacros

wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/api.h
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/shared.h
wget https://raw.githubusercontent.com/IHateGameDev/APIMacros/main/APIMacros/nullptr.h

cd ..
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=ON .. -G Ninja
ninja

ninja install
```

<a name="applicationsDevelopersGuide"></a>

## TEL Implementing in project

If you want to implementing TEL in your project:

### Extension info

You need to create a structure for your extension info:

```c
// ExampleExtensionInfo.h
#ifndef EXAMPLE_EXTENSION_INFO_H
#define EXAMPLE_EXTENSION_INFO_H

typedef void(ExampleUpdateFn*)(ExampleExtensionInfo*)

typedef struct {
  const char* name;
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
} // strdup
```

And construct you application source file:
```c
#include "ExtensionInfo.h"
#include <TEL/Extension.h>
#include <stdio.h>

int main() {
  puts("Hello from my application!\n");
  
  TEL_NEW_EXTENSION(extension, ExampleExtensionInfo);
  telExtensionLoad(extension, "./extension.te", "setup"/* setup function name */);

  ExampleExtensionInfo* info = (ExampleExtensionInfo*)extension->info;

  puts("Extension: ");
  puts(info->name);
  puts(", successuflly loaded!\n");

  for (unsigned char i = 0; i < 255; i++)
    info->update();

  telExtensionUnload(extension, "cleanup"/* cleanup function name '\0' / "" / 0 / nullptr for not using cleanup function */);
}
```

This code loads the extension [extension.te](#extensionsDevelopersGuide), prints its name,<br>
calls the `update` function 255 times, and calls the `cleanup` function to free `info->name`.

***NOTE***: If you use the shared TEL library, don't forget to add compile flag: `-DAPI_SHARED_USE`.

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

// Add the cleanup function to free allocated memory:
API/*optional but recommended*/ void cleanup(ExampleExtensionInfo* info) {
  free(info->name);
}
```

***NOTE*** Don't forget to add `-fPIC` and, if you use "APIMacros/api.h", also add `-DAPI_SHARED_BUILD`.
