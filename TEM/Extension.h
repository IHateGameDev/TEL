#ifndef TEM_EXTENSION_H
#define TEM_EXTENSION_H

#include <APIMacros/api.h>
#include <stddef.h>

typedef struct {
  void* info;
  void* library;
} TEMExtension;

API TEMExtension* temExtensionLoad(const char* restrict path, const char* restrict setupFunctionName, size_t infoSize);
API void temExtensionUnload(TEMExtension* self, const char* restrict cleanupFunctionName);

#endif // !TEM_EXTENSION_H
