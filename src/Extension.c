/*
 * Use MIT License
 * Copyright (c) 2025 semenovihandrei
 */

#include "../TEL/Extension.h"

#include <APIMacros/nullptr.h>
#include <APIMacros/shared.h>

#include <stdlib.h>

typedef void (*TelCallback)(void*);

static inline TelError processFunction(TelExtension* extension,
                                       const char* functionName) {
  TelCallback callback =
      (TelCallback)GET_LIB_FUNC((LIBRARY)extension->library, functionName);

  if (!callback) {
    return (TelError){TEL_ERROR_GET_FUNC, GET_LIB_ERROR()};
  }

  callback(extension->info);
  return (TelError){TEL_ERROR_NO, NULLPTR};
}

API TelError telExtensionLoad(TelExtension* self, const char* path,
                              const char* setupFunctionName) {
  self->library = (void*)LOAD_LIBRARY(path);

  if (!self->library) {
    free(self);
    return (TelError){TEL_ERROR_EXT_LOAD, GET_LIB_ERROR()};
  }

  return processFunction(self, setupFunctionName);
}

API TelError telExtensionUnload(TelExtension* self,
                                const char* cleanupFunctionName) {
  if (*cleanupFunctionName != '\0' && !cleanupFunctionName)
    return processFunction(self, cleanupFunctionName);

  free(self->info);
  UNLOAD_LIBRARY((LIBRARY)self->library);

  free(self);

  return (TelError){TEL_ERROR_NO, GET_LIB_ERROR()};
}
