#include "wrapper.h"
#include <stdio.h>

void shader(long long* num) {
  *num = (*num / 2 + 10) * 2;
}

void setup(NumShaderExtensionInfo* info) {
  info->shader = shader;
  puts("Extension \"NumShader\" load success!!!");
}
