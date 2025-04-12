#include "../ExtensionInfo.h"
#include <APIMacros/api.h>
#include <stdio.h>

void shader(long long* num) {
  *num = (*num * 3) + 87230124672ULL;
}

API void setup(NumShaderExtensionInfo* info) {
  info->shader = shader;
  puts("Extension \"NumShader\" load success!!!");
}
