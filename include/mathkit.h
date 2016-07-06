/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef mathkit_h
#  define mathkit_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mk-common.h"

#define MkMatrixGet(_matrix, _i, _j)                                          \
  ((char *)_matrix->base.value                                                \
        + (_i * _matrix->columns + _j) * (_matrix->base.itemSize))

#define MkMatrixSet(_matrix, _i, _j, _val)                                    \
  memcpy(MkMatrixGet(_matrix, _i, _j),                                        \
         _val,                                                                \
         sizeof(_matrix->base.itemSize))

#define MkMatrixSet2(_matrix, _matrixPos, _val)                               \
  memcpy(_matrixPos,                                                          \
         _val,                                                                \
         sizeof(_matrix->base.itemSize))


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

typedef struct MkVector {
  size_t itemSize;
  size_t itemCount;
  void   *value;
} MkVector;

typedef struct MkMatrix {
  MkVector base;
  size_t   rows;
  size_t   columns;
} MkMatrix;

MkMatrix *
mkMatrixNew(size_t itemSize,
            size_t rows,
            size_t columns,
            void  *zeroVal,
            void  *oneVal);

MkMatrix *
mkMatrixNew4x4f(bool identity);

MkMatrix *
mkMatrixNew4x4d(bool identity);

MkMatrix *
mkMatrixNewFromf(size_t rows,
                 size_t columns,
                 float * data);

MkMatrix *
mkMatrixNewFromd(size_t rows,
                 size_t columns,
                 double * data);

MkMatrix *
mkMatrixNewFrom4x4f(float * data);

MkMatrix *
mkMatrixNewFrom4x4d(double * data);

void
mkMatrixPrint(MkMatrix * matrix,
              MkPrintFn itemPrinter,
              FILE * __restrict ostream);

void
mkMatrixTranspose(MkMatrix * matrix);

bool
mkMatrixIsIdentity(MkMatrix * matrix);

void
mkMatrixApplyScalarL(void * __restrict other,
                     MkMatrix * matrix,
                     MkOp * __restrict op);

void
mkMatrixApplyMatrixL(MkMatrix * __restrict destMatrix,
                     MkMatrix * __restrict matrixL,
                     MkOp * __restrict op);

void
mkMatrixApplyMatrixR(MkMatrix * __restrict destMatrix,
                     MkMatrix * __restrict matrixR,
                     MkOp * __restrict op);

MkMatrix *
mkMatrixApplyMatrix(MkMatrix * __restrict matrixL,
                    MkMatrix * __restrict matrixR,
                    MkOp * __restrict op);

/* buit-in operators
 *
 * mkOp [OpType][Param1 Type][Param2 Type]
 * mkOp [OpType][Param1 and Param2 Type]
 */

/* multiplication operators */

MK_EXTERN
MkOp * const mkOpMultiplyF;

MK_EXTERN
MkOp * const mkOpMultiplyD;

MK_EXTERN
MkOp * const mkOpMultiplyInt32;

MK_EXTERN
MkOp * const mkOpMultiplyInt64;

/* addition operators */

MK_EXTERN
MkOp * const mkOpAdditionF;

MK_EXTERN
MkOp * const mkOpAdditionD;

MK_EXTERN
MkOp * const mkOpAdditionInt32;

MK_EXTERN
MkOp * const mkOpAdditionInt64;

/* buit-in printers */

MK_EXTERN
MkPrintFn mkFloatPrinter;

MK_EXTERN
MkPrintFn mkDoublePrinter;

MK_EXTERN void * const MkFloatZero;
MK_EXTERN void * const MkDoubleZero;
MK_EXTERN void * const MkInt32Zero;
MK_EXTERN void * const MkInt64Zero;

MK_EXTERN void * const MkFloatOne;
MK_EXTERN void * const MkDoubleOne;
MK_EXTERN void * const MkInt32One;
MK_EXTERN void * const MkInt64One;

#endif /* mathkit_h */
