#include <TEM/Extension.h>

int main(void) {
  TEMExtension* printExtension = temExtensionLoad("./printHello", "setup");

  temExtensionUnload(printExtension, "");
  return 0;
}
