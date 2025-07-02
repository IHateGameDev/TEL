#include "ExtensionInfo.h"
#include <TEL/Extension.h>
#include <stdio.h>

int main(void) {
  TELExtension* extension = telExtensionLoad(
      "./extensions/printHello.te", "setup", sizeof(BaseExtensionInfo));

  BaseExtensionInfo* info = (BaseExtensionInfo*)extension->info;

  printf("%d, %d, %d\n", info->vMajor, info->vMinor, info->vPatch);

  telExtensionUnload(extension, "");
  return 0;
}
