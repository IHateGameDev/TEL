#include "../TEM/Extension.h"

#include <APIMacros/shared.h>

#include <stdlib.h>
#include <stdio.h>

typedef void(*TEMCallback)(void*);

static inline void processFunction(TEMExtension* extension, const char* functionName) {
  TEMCallback callback = (TEMCallback)API_GET_LIB_FUNC((API_LIBRARY)extension->library, functionName);
  if (!callback) {
    printf("[TEM] Code of error on get function '%s': %d\n", functionName, API_GET_LIB_ERROR());
    return;
  }

  callback(extension->info);
}

API TEMExtension* temExtensionLoad(const char* path, const char* setupFunctionName, size_t infoSize) {
  TEMExtension* out = malloc(sizeof(TEMExtension));

  if (!out) {
    puts("[TEM] Memory allocation for extension failed\n");
    return nullptr;
  }

  out->library = (void*)API_LOAD_LIBRARY(path);

  if (!out->library) {
    printf("[TEM] Code of error on extension load: %d\n", API_GET_LIB_ERROR());
    free(out);
    return nullptr;
  }
  
  out->info = malloc(infoSize);
  if (!out->info) {
    puts("[TEM] Memory allocation for extension info failed\n");
    return nullptr;
  }

  processFunction(out, setupFunctionName);
  return out;
}

API void temExtensionUnload(TEMExtension* self, const char* cleanupFunctionName) {
  if (*cleanupFunctionName != '\0')
    processFunction(self, cleanupFunctionName);
  
  free(self->info);
  API_UNLOAD_LIBRARY((API_LIBRARY)self->library);

  free(self);
}
