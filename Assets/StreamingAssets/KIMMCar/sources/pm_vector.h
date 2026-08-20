#ifndef __pm_vector_h__
#define __pm_vector_h__
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
void pm_rv_equals_rv(const PmRealVector*xPtr,const PmRealVector*yPtr);void
pm_iv_equals_iv(const PmIntVector*xPtr,const PmIntVector*yPtr);void
pm_bv_equals_bv(const PmBoolVector*xPtr,const PmBoolVector*yPtr);void
pm_cv_equals_cv(const PmCharVector*xPtr,const PmCharVector*yPtr);boolean_T
pm_rv_equalequals_rv(const PmRealVector*xPtr,const PmRealVector*yPtr);
boolean_T pm_iv_equalequals_iv(const PmIntVector*xPtr,const PmIntVector*yPtr);
boolean_T pm_bv_equalequals_bv(const PmBoolVector*xPtr,const PmBoolVector*yPtr
);int_T pm_create_real_vector_fields(PmRealVector*vecPtr,size_t size,
PmAllocator*allocatorPtr);PmRealVector*pm_create_real_vector(size_t numElements
,PmAllocator*allocatorPtr);PmRealVector*pm_copy_real_vector(const PmRealVector
*vecPtr,PmAllocator*allocatorPtr);void pm_destroy_real_vector_fields(
PmRealVector*vecPtr,PmAllocator*allocatorPtr);void pm_destroy_real_vector(
PmRealVector*vecPtr,PmAllocator*allocatorPtr);int_T pm_create_int_vector_fields
(PmIntVector*vecPtr,size_t size,PmAllocator*allocatorPtr);PmIntVector*
pm_create_int_vector(size_t numElements,PmAllocator*allocatorPtr);PmIntVector*
pm_copy_int_vector(const PmIntVector*vecPtr,PmAllocator*allocatorPtr);void
pm_destroy_int_vector_fields(PmIntVector*vecPtr,PmAllocator*allocatorPtr);void
pm_destroy_int_vector(PmIntVector*vecPtr,PmAllocator*allocatorPtr);int_T
pm_create_bool_vector_fields(PmBoolVector*vecPtr,size_t size,PmAllocator*
allocatorPtr);PmBoolVector*pm_create_bool_vector(size_t numElements,
PmAllocator*allocatorPtr);void pm_destroy_bool_vector_fields(PmBoolVector*
vecPtr,PmAllocator*allocatorPtr);void pm_destroy_bool_vector(PmBoolVector*
vecPtr,PmAllocator*allocatorPtr);PmBoolVector*pm_copy_bool_vector(const
PmBoolVector*vecPtr,PmAllocator*allocatorPtr);int_T
pm_create_char_vector_fields(PmCharVector*vecPtr,size_t size,PmAllocator*
allocatorPtr);PmCharVector*pm_create_char_vector(size_t numElements,
PmAllocator*allocatorPtr);void pm_destroy_char_vector_fields(PmCharVector*
vecPtr,PmAllocator*allocatorPtr);void pm_destroy_char_vector(PmCharVector*
vecPtr,PmAllocator*allocatorPtr);int_T pm_create_size_vector_fields(
PmSizeVector*vecPtr,size_t size,PmAllocator*allocatorPtr);PmSizeVector*
pm_create_size_vector(size_t numElements,PmAllocator*allocatorPtr);void
pm_destroy_size_vector_fields(PmSizeVector*vecPtr,PmAllocator*allocatorPtr);
void pm_destroy_size_vector(PmSizeVector*vecPtr,PmAllocator*allocatorPtr);void
pm_sv_equals_sv(const PmSizeVector*xPtr,const PmSizeVector*yPtr);boolean_T
pm_sv_equalequals_sv(const PmSizeVector*xPtr,const PmSizeVector*yPtr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __pm_vector_h__ */
