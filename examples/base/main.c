#include "ExtensionInfo.h"
#include <TEL/Extension.h>
#include <stdio.h>

int main(void) {
  TEL_NEW_EXTENSION(extension, BaseExtensionInfo);

  telExtensionLoad(extension, "./extensions/printHello.te", "setup");

  BaseExtensionInfo* info = (BaseExtensionInfo*)extension->info;

  printf("%d, %d, %d\n", info->vMajor, info->vMinor, info->vPatch);

  telExtensionUnload(extension, "");
  return 0;
}
