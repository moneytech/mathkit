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
#include <stdio.h>
#include <errno.h>

#if defined(_WIN32)
#  ifdef _mathkit_dll
#    define MK_EXPORT __declspec(dllexport)
#  else
#    define MK_EXPORT __declspec(dllimport)
#  endif
#  define _mathkit_hide
#  define MK_PRAGMA_UNROLL(n)
#else
#  define MK_EXPORT      __attribute__((visibility("default")))
#  define _mathkit_hide __attribute__((visibility("hidden")))
#  define MK_PRAGMA_UNROLL_4 _Pragma("unroll(4)")
#endif

#define MK_ARRAY_LEN(ARR) sizeof(ARR) / sizeof(ARR[0]);

#ifndef __MATHKIT_SRC_
#  define MK_EXTERN extern
#else
#  define MK_EXTERN
#endif

typedef void (*MkPrintFn)(FILE * __restrict ostream,
                          void * __restrict item);

typedef void (*MkOpFn)(void * __restrict a, void * __restrict b);

typedef enum MkOpType {
  MK_OP_TYPE_MULTIPLY,
  MK_OP_TYPE_ADDITION
} MkOpType;

typedef struct MkOp {
  MkOpType type;
  MkOpFn   op;
  MkOpFn   addop;
} MkOp;

typedef enum MkItemType {
   MK_FLOAT = 0,
   MK_DOUBLE,
   MK_INT32,
   MK_INT64
} MkItemType;

typedef struct MkBufLayout {
   MkItemType type;
   size_t     count[2];
   bool       runtime;
   bool       columnMajor;
} MkBufLayout;

#define MK_DEF_LAYOUT(MK__TYPE, MK__M, MK__N, MK__RT)                         \
  (MkBufLayout){MK__TYPE, MK__M, MK__N, MK__RT}

inline
size_t
mkItemSize(MkBufLayout * __restrict layout) {
   switch (layout->type) {
      case MK_FLOAT:  return sizeof(float);   break;
      case MK_DOUBLE: return sizeof(double);  break;
      case MK_INT32:  return sizeof(int32_t); break;
      case MK_INT64:  return sizeof(int64_t); break;
      default:        return 0;               break;
   }
}

#endif /* mk_common_h */
