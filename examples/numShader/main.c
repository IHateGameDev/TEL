#include "ExtensionInfo.h"
#include <TEL/Extension.h>
#include <stdio.h>

int main(void) {
  TELExtension* extension = telExtensionLoad("./extensions/random.te", "setup",
                                             sizeof(NumShaderExtensionInfo));
  long long num           = 32000;

  for (unsigned char i = 0; i < 10; i++) {
    ((NumShaderExtensionInfo*)extension->info)->shader(&num);
    printf("Number after use shader: %lld\n", num);
  }

  telExtensionUnload(extension, "");
  return 0;
}
