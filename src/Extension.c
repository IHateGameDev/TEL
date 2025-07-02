#include "../TEL/Extension.h"

#include <APIMacros/shared.h>

#include <stdio.h>
#include <stdlib.h>

typedef void (*TELCallback)(void *);

static inline void processFunction(TELExtension *extension,
                                   const char *functionName) {
  TELCallback callback = (TELCallback)API_GET_LIB_FUNC(
      (API_LIBRARY)extension->library, functionName);
  if (!callback) {
    printf("[TEL] Code of error on get function \"%s\": %s\n", functionName,
           API_GET_LIB_ERROR());
    return;
  }

  callback(extension->info);
}

API TELExtension *telExtensionLoad(const char *path,
                                   const char *setupFunctionName,
                                   size_t infoSize) {
  TELExtension *out = malloc(sizeof(TELExtension));

  if (!out) {
    puts("[TEL] Memory allocation for extension failed\n");
    return nullptr;
  }

  out->library = (void *)API_LOAD_LIBRARY(path);

  if (!out->library) {
    printf("[TEL] Code of error on extension load: %s\n", API_GET_LIB_ERROR());
    free(out);
    return nullptr;
  }

  out->info = malloc(infoSize);
  if (!out->info) {
    puts("[TEL] Memory allocation for extension info failed\n");
    return nullptr;
  }

  processFunction(out, setupFunctionName);
  return out;
}

API void telExtensionUnload(TELExtension *self,
                            const char *cleanupFunctionName) {
  if (*cleanupFunctionName != '\0')
    processFunction(self, cleanupFunctionName);

  free(self->info);
  API_UNLOAD_LIBRARY((API_LIBRARY)self->library);

  free(self);
}
