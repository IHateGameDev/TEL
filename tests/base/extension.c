#include "wrapper.h"
#include <stdio.h>

void setup(BaseExtensionInfo* info) {
  info->vMajor = 0;
  info->vMinor = 1;
  info-> vPatch = 0;

  puts("Hello from extension!!!\n");
}
