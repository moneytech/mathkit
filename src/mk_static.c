/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#define __MATHKIT_SRC_

#include "../include/mk.h"

static
inline
void
mkFloatPrinterImpl(FILE * __restrict ostream,
                   void * __restrict item);

static
inline
void
mkDoublePrinterImpl(FILE * __restrict ostream,
                    void * __restrict item);

static
inline
void
mkInt32PrinterImpl(FILE * __restrict ostream,
                  void * __restrict item);

static
inline
void
mkInt64PrinterImpl(FILE * __restrict ostream,
                   void * __restrict item);

/* multiplication */

static
inline
void
mkOpMFltImpl(void * __restrict a,
             void * __restrict b);

static
inline
void
mkOpMDblImpl(void * __restrict a,
             void * __restrict b);

static
inline
void
mkOpMInt32Impl(void * __restrict a,
               void * __restrict b);

static
inline
void
mkOpMInt64Impl(void * __restrict a,
               void * __restrict b);

/* addition */

static
inline
void
mkOpAFltImpl(void * __restrict a,
             void * __restrict b);

static
inline
void
mkOpADblImpl(void * __restrict a,
             void * __restrict b);

static
inline
void
mkOpAInt32Impl(void * __restrict a,
               void * __restrict b);

static
inline
void
mkOpAInt64Impl(void * __restrict a,
               void * __restrict b);

/* ************************************************************************* */

/* Printers */
MK_EXTERN
MkPrintFn mkFloatPrinter = mkFloatPrinterImpl;

MK_EXTERN
MkPrintFn mkDoublePrinter = mkDoublePrinterImpl;

MK_EXTERN
MkPrintFn mkInt32Printer = mkInt32PrinterImpl;

MK_EXTERN
MkPrintFn mkInt64Printer = mkInt64PrinterImpl;

/* Op */
static
MkOp mkOpMultFImpl = {
  .type  = MK_OP_TYPE_MULTIPLY,
  .op    = mkOpMFltImpl,
  .addop = mkOpAFltImpl
};

static
MkOp mkOpMultDImpl = {
  .type  = MK_OP_TYPE_MULTIPLY,
  .op    = mkOpMDblImpl,
  .addop = mkOpADblImpl
};

static
MkOp mkOpMultInt32Impl = {
  .type  = MK_OP_TYPE_MULTIPLY,
  .op    = mkOpMInt32Impl,
  .addop = mkOpAInt32Impl
};

static
MkOp mkOpMultInt64Impl = {
  .type  = MK_OP_TYPE_MULTIPLY,
  .op    = mkOpMInt64Impl,
  .addop = mkOpAInt64Impl
};

/* addition */
static
MkOp mkOpAddFImpl = {
  .type  = MK_OP_TYPE_ADDITION,
  .op    = mkOpAFltImpl,
  .addop = mkOpAFltImpl
};

static
MkOp mkOpAddDImpl = {
  .type  = MK_OP_TYPE_ADDITION,
  .op    = mkOpADblImpl,
  .addop = mkOpADblImpl
};

static
MkOp mkOpAddInt32Impl = {
  .type  = MK_OP_TYPE_ADDITION,
  .op    = mkOpAInt32Impl,
  .addop = mkOpAInt32Impl
};

static
MkOp mkOpAddInt64Impl = {
  .type  = MK_OP_TYPE_ADDITION,
  .op    = mkOpAInt64Impl,
  .addop = mkOpAInt64Impl
};

MK_EXTERN
MkOp * const mkOpMultF = &mkOpMultFImpl;

MK_EXTERN
MkOp * const mkOpMultD = &mkOpMultDImpl;

MK_EXTERN
MkOp * const mkOpMultInt32 = &mkOpMultInt32Impl;

MK_EXTERN
MkOp * const mkOpMultInt64 = &mkOpMultInt64Impl;

MK_EXTERN
MkOp * const mkOpAddF = &mkOpAddFImpl;

MK_EXTERN
MkOp * const mkOpAddD = &mkOpAddDImpl;

MK_EXTERN
MkOp * const mkOpAddInt32 = &mkOpAddInt32Impl;

MK_EXTERN
MkOp * const mkOpAddInt64 = &mkOpAddInt64Impl;


static float   Mk__floatZero  = 0.0f;
static double  Mk__doubleZero = 0.0;
static int32_t Mk__int32Zero  = 0;
static int64_t Mk__int64Zero  = 0L;

static float   Mk__floatOne   = 1.0f;
static double  Mk__doubleOne  = 1.0;
static int32_t Mk__int32One   = 1;
static int64_t Mk__int64One   = 1L;


MK_EXTERN void * const MkFloatZero  = &Mk__floatZero;
MK_EXTERN void * const MkDoubleZero = &Mk__doubleZero;
MK_EXTERN void * const MkInt32Zero  = &Mk__int32Zero;
MK_EXTERN void * const MkInt64Zero  = &Mk__int64Zero;

MK_EXTERN void * const MkFloatOne   = &Mk__floatOne;
MK_EXTERN void * const MkDoubleOne  = &Mk__doubleOne;
MK_EXTERN void * const MkInt32One   = &Mk__int32One;
MK_EXTERN void * const MkInt64One   = &Mk__int64One;

/* ************************************************************************* */

static
inline
void
mkFloatPrinterImpl(FILE * __restrict ostream,
                   void * __restrict item) {
  fprintf(ostream, "\t%0.2ff,", *(float *)item);
}

static
inline
void
mkDoublePrinterImpl(FILE * __restrict ostream,
                    void * __restrict item) {
  fprintf(ostream, "\t%0.2f,", *(double *)item);
}

static
inline
void
mkInt32PrinterImpl(FILE * __restrict ostream,
                   void * __restrict item) {
  fprintf(ostream, "\t%d,", *(int32_t *)item);
}

static
inline
void
mkInt64PrinterImpl(FILE * __restrict ostream,
                   void * __restrict item) {
  fprintf(ostream, "\t%lld,", *(int64_t *)item);
}

/* multiplication */

static
inline
void
mkOpMFltImpl(void * __restrict a,
             void * __restrict b) {
  *(float *)a *= *(float *)b;
}

static
inline
void
mkOpMDblImpl(void * __restrict a,
             void * __restrict b) {
  *(double *)a *= *(double *)b;
}

static
inline
void
mkOpMInt32Impl(void * __restrict a,
               void * __restrict b) {
  *(int32_t *)a *= *(int32_t *)b;
}

static
inline
void
mkOpMInt64Impl(void * __restrict a,
               void * __restrict b) {
  *(int64_t *)a *= *(int64_t *)b;
}

/* addition */

static
inline
void
mkOpAFltImpl(void * __restrict a,
             void * __restrict b) {
  *(float *)a += *(float *)b;
}

static
inline
void
mkOpADblImpl(void * __restrict a,
             void * __restrict b) {
  *(double *)a += *(double *)b;
}

static
inline
void
mkOpAInt32Impl(void * __restrict a,
               void * __restrict b) {
  *(int32_t *)a += *(int32_t *)b;
}

static
inline
void
mkOpAInt64Impl(void * __restrict a,
               void * __restrict b) {
  *(int64_t *)a += *(int64_t *)b;
}
