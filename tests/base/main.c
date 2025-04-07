#include <TEM/Extension.h>
#include <stdio.h>
#include "wrapper.h"

int main(void) {
  TEMExtension* printExtension = temExtensionLoad("./printExtension", "setup");
  
  BaseExtensionInfo* info = printExtension->info;

  printf("%d, %d, %d\n", info->vMajor, info->vMinor, info->vPatch);

  temExtensionUnload(printExtension, "");
  return 0;
}
