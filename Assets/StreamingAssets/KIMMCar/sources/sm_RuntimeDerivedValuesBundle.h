#ifndef __sm_RuntimeDerivedValuesBundle_h__
#define __sm_RuntimeDerivedValuesBundle_h__
#include "sm_SmRealVector.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
struct SmIntVectorTag{size_t mSize;size_t mCap;int*mValues;};typedef struct
SmIntVectorTag SmIntVector;void sm_core_SmIntVector_create(SmIntVector*vector,
size_t n,int val);void sm_core_SmIntVector_copy(SmIntVector*copy,const
SmIntVector*orig);void sm_core_SmIntVector_destroy(SmIntVector*vector);int
sm_core_SmIntVector_isEmpty(const SmIntVector*vector);size_t
sm_core_SmIntVector_size(const SmIntVector*vector);size_t
sm_core_SmIntVector_capacity(const SmIntVector*vector);int
sm_core_SmIntVector_value(const SmIntVector*vector,size_t index);void
sm_core_SmIntVector_setValue(SmIntVector*vector,size_t index,int value);const
int*sm_core_SmIntVector_values(const SmIntVector*vector);int*
sm_core_SmIntVector_nonConstValues(SmIntVector*vector);void
sm_core_SmIntVector_reserve(SmIntVector*vector,size_t n);void
sm_core_SmIntVector_clear(SmIntVector*vector);void sm_core_SmIntVector_pushBack
(SmIntVector*vector,int val);void sm_core_SmIntVector_popBack(SmIntVector*
vector);struct RuntimeDerivedValuesBundleTag{SmRealVector mDoubles;SmIntVector
mInts;};typedef struct RuntimeDerivedValuesBundleTag RuntimeDerivedValuesBundle
;void sm_core_RuntimeDerivedValuesBundle_create(RuntimeDerivedValuesBundle*
bundle,size_t nDoubles,size_t nInts);void
sm_core_RuntimeDerivedValuesBundle_copy(const RuntimeDerivedValuesBundle*orig,
RuntimeDerivedValuesBundle*copy);void
sm_core_RuntimeDerivedValuesBundle_destroy(RuntimeDerivedValuesBundle*bundle);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __sm_RuntimeDerivedValuesBundle_h__ */
