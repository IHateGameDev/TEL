#include <TEM/Extension.h>
#include <stdio.h>
#include "wrapper.h"

int main(void) {
  TEMExtension* extension = temExtensionLoad("./numShader.te", "setup", sizeof(NumShader));
  long long num = 32'000;

  for (unsigned char i = 0; i < 10; i++) {
    ((NumShaderExtensionInfo*)extension->info)->shader(&num);
    printf("Number after use shader: %lld\n", num);
  }
  temExtensionUnload(extension, "");
  return 0;
}
