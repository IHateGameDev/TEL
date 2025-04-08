#include <TEM/Extension.h>
#include <stdio.h>
#include "wrapper.h"

int main(void) {
  TEMExtension* baseExtension = temExtensionLoad("./base.te", "setup", sizeof(BaseExtensionInfo));

  BaseExtensionInfo* info = (BaseExtensionInfo*)baseExtension->info;
  
  if(info)
    printf("%d, %d, %d\n", info->vMajor, info->vMinor, info->vPatch);
  else
    puts("unknown error");

  temExtensionUnload(baseExtension, "");
  return 0;
}
