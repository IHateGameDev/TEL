#include "ExtensionInfo.h"
#include <TEM/Extension.h>
#include <stdio.h>

int main(void) {
  TEMExtension* extension = temExtensionLoad("./extensions/printHello.te", "setup", sizeof(BaseExtensionInfo));

  BaseExtensionInfo* info = (BaseExtensionInfo*)extension->info;
  
  printf("%d, %d, %d\n", info->vMajor, info->vMinor, info->vPatch);

  temExtensionUnload(extension, "");
  return 0;
}
