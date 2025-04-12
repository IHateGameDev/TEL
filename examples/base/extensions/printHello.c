#include "../ExtensionInfo.h"
#include <APIMacros/api.h>
#include <stdio.h>

API void setup(BaseExtensionInfo* info) {
  info->vMajor = 0;
  info->vMinor = 1;
  info->vPatch = 0;

  puts("Hello from extension!!!\n");
}
