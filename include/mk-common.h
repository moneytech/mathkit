/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef mk_common_h
#define mk_common_h

/* since C99 or compiler ext */
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>

#if defined(_WIN32)
#  ifdef _mathkit_dll
#    define MK_EXPORT __declspec(dllexport)
#  else
#    define MK_EXPORT __declspec(dllimport)
#  endif
#  define _mathkit_hide
#else
#  define MK_EXPORT      __attribute__((visibility("default")))
#  define _mathkit_hide __attribute__((visibility("hidden")))
#endif

#define MK_ARRAY_LEN(ARR) sizeof(ARR) / sizeof(ARR[0]);

#endif /* mk_common_h */
