/**
 * @file Extension.h
 * @brief Add extension structure and functions.
 *
 * This file contains the basic functions and structures of TEM.
 * It allows you to load and unload extensions.
 *
 * @author IHateGameDev(semenovihandrey)
 * @version 0.1.0 - v2
 */

#ifndef TEM_EXTENSION_H
#define TEM_EXTENSION_H

#include <APIMacros/api.h>
#include <stddef.h>

/**
 * @brief The structure that represents the extension.
 */
typedef struct {
  void* info;     /**< Pointer to a custom structure representing information about the extension (the structure is provided by the program developer). */
  void* library;  /**< Pointer to a shared library representing the extension. */
} TEMExtension;

/**
 * @brief Function that loads the extension.
 *
 * The function that loads the extension,
 * processes the setup function,
 * and allocates memory for the extension information.
 *
 * @param path Path to extension (shared library).
 * @param setupFunctionName Name of the setup function in the extension (requires the information parameter in the setup function of the extension).
 * @param infoSize Size of extension info for allocate memory (use sizeof(ExtensionInfoStruct)).
 *
 * @return Pointer to TEMExtension
 */
API TEMExtension* temExtensionLoad(const char* restrict path, const char* restrict setupFunctionName, size_t infoSize);

/**
 * @brief Function that unload the extension
 *
 * The function unloads the extension frees the associated memory
 * and calls the cleanup function, which is used to clean
 * the allocated memory by the extension itself.
 *
 * @param self Extension over which actions are performed.
 * @param cleanupFunctionName Name of cleanup function in the extension (requires the information parameter in the cleanup function of the extension).
 */
API void temExtensionUnload(TEMExtension* self, const char* restrict cleanupFunctionName);

#endif // !TEM_EXTENSION_H
