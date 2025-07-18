/*
 * Use MIT License
 * Copyright (c) 2025 semenovihandrei
 */

/**
 * @file Extension.h
 * @brief Add extension structure and functions.
 *
 * This file contains the basic functions and structures of TEL.
 * It allows you to load and unload extensions.
 *
 * @author IHateGameDev(semenovihandrey)
 * @version 0.1.5 - v5
 */

#ifndef TEL_EXTENSION_H
#define TEL_EXTENSION_H

#include <APIMacros/api.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief The structure that represents the error on return.
 */
typedef struct {
  unsigned char code; /**< Error code. Can be compared with TEL_ERROR_*. */
  void* ret;          /**< Return value of the function. */
} TelError;

#define TEL_ERROR_NO       0
#define TEL_ERROR_GET_FUNC 1
#define TEL_ERROR_EXT_LOAD 2

/**
 * @brief The structure that represents the extension.
 */
typedef struct {
  void* info; /**< Pointer to a custom structure representing information about
                 the extension (the structure is provided by the program
                 developer). */
  void* library; /**< Pointer to a shared library representing the extension. */
} TelExtension;

/**
 * @macro TEL_NEW_EXTENSION
 *
 * @brief Macro that create TelExtension.
 *
 * The macro that allocate memory for extension and info.
 *
 * @param extension Name of TelExtension variable.
 *
 * @param struct Name of info structure.
 *
 * @return Pointer to TelExtension.
 */
#define TEL_NEW_EXTENSION(extension, struct)                                   \
  TelExtension* extension = (TelExtension*)malloc(sizeof(TelExtension));       \
  extension->info         = (struct*)malloc(sizeof(struct))

/**
 * @brief Function that loads the extension.
 *
 * The function that loads the extension,
 * processes the setup function,
 * and allocates memory for the extension information.
 *
 * @param self Extension over which actions are performed.
 *
 * @param path Path to extension (shared library).
 *
 * @param setupFunctionName Name of the setup function in the extension
 * (requires the information parameter in the setup function of the extension).
 *
 * @param infoSize Size of extension info for allocate memory (use
 * sizeof(ExtensionInfoStruct)).
 *
 * @return TelError structure.
 */
API TelError telExtensionLoad(TelExtension* self, const char* restrict path,
                              const char* restrict setupFunctionName);

/**
 * @brief Function that unload the extension
 *
 * The function unloads the extension frees the associated memory
 * and calls the cleanup function, which is used to clean
 * the allocated memory by the extension itself.
 *
 * @param self Extension over which actions are performed.
 *
 * @param cleanupInfo Pointer that is the second argument to "setupFunction"
 *
 * @param cleanupFunctionName Name of cleanup function in the extension
 * (requires the information parameter in the cleanup function of the
 * extension).
 *
 * @return TelError structure.
 */
API TelError telExtensionUnload(TelExtension* self,
                                const char* restrict cleanupFunctionName);

#endif // !TEL_EXTENSION_H
