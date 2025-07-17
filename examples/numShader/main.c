#include "ExtensionInfo.h"
#include <TEL/Extension.h>
#include <stdio.h>

int main(void) {
  TEL_NEW_EXTENSION(extension, NumShaderExtensionInfo);

  telExtensionLoad(extension, "./extensions/random.te", "setup");

  long long num = 32000;

  for (unsigned char i = 0; i < 10; i++) {
    ((NumShaderExtensionInfo*)extension->info)->shader(&num);
    printf("Number after use shader: %lld\n", num);
  }

  telExtensionUnload(extension, "");
  return 0;
}
