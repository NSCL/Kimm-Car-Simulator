#ifndef __sm_SmRealVector_h__
#define __sm_SmRealVector_h__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
struct SmRealVectorTag{size_t mSize;size_t mCap;real_T*mValues;};typedef struct
SmRealVectorTag SmRealVector;void sm_core_SmRealVector_create(SmRealVector*
vector,size_t n,real_T val);void sm_core_SmRealVector_copy(SmRealVector*copy,
const SmRealVector*orig);void sm_core_SmRealVector_destroy(SmRealVector*vector
);int sm_core_SmRealVector_isEmpty(const SmRealVector*vector);size_t
sm_core_SmRealVector_size(const SmRealVector*vector);size_t
sm_core_SmRealVector_capacity(const SmRealVector*vector);real_T
sm_core_SmRealVector_value(const SmRealVector*vector,size_t index);void
sm_core_SmRealVector_setValue(SmRealVector*vector,size_t index,real_T value);
const real_T*sm_core_SmRealVector_values(const SmRealVector*vector);real_T*
sm_core_SmRealVector_nonConstValues(SmRealVector*vector);void
sm_core_SmRealVector_reserve(SmRealVector*vector,size_t n);void
sm_core_SmRealVector_clear(SmRealVector*vector);void
sm_core_SmRealVector_pushBack(SmRealVector*vector,real_T val);void
sm_core_SmRealVector_popBack(SmRealVector*vector);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __sm_SmRealVector_h__ */
