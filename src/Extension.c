#include "../TEM/Extension.h"

#include <APIMacros/override/memorylib.h>
#include <APIMacros/override/stdio.h>
#include <APIMacros/shared.h>

#ifndef API_NI_MEMORYLIB_H
# include API_MEMORYLIB_H
#endif

#ifndef API_NI_STDIO_H
# include API_STDIO_H
#endif

typedef void(*TEMCallback)(void*);

static inline void processFunction(TEMExtension* extension, const char* functionName) {
  TEMCallback callback = (TEMCallback)API_GET_LIB_FUNC((API_LIBRARY)extension->library, functionName);
  if (!callback) {
    API_PRINTF("[TEM] Code of error on get function '%s': %d\n", functionName, API_GET_LIB_ERROR());
    return;
  }

  callback(extension->info);
}

API TEMExtension* temExtensionLoad(const char* path, const char* setupFunctionName) {
  TEMExtension* out = API_MALLOC(sizeof(TEMExtension));

  if (!out) {
    API_PUTS("[TEM] Memory allocation failed\n");
    return nullptr;
  }

  out->info = nullptr;
  out->library = API_LOAD_LIBRARY(path);

  if (!out->library) {
    API_PRINTF("[TEM] Code of error on extension load: %d\n", API_GET_LIB_ERROR());
    API_FREE(out);
    return nullptr;
  }

  processFunction(out, setupFunctionName);

  return out;
}

API void temExtensionUnload(TEMExtension* self, const char* cleanupFunctionName) {
  if (*cleanupFunctionName != '\0')
    processFunction(self, cleanupFunctionName);
  
  API_FREE(self->info);
  API_UNLOAD_LIBRARY((API_LIBRARY)self->library);

  API_FREE(self);
}
