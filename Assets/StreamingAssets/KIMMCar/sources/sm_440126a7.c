#include "KIMMCar_macros.h"
#include "pm_std.h"
#include "sm_SmRealVector.h"
#include "string.h"
#include "pm_std.h"
#include "pm_std.h"
void sm_core_SmRealVector_create(SmRealVector*vector,size_t n,real_T
pm_kpzAtHMD4_WnheH0UiioSE){size_t sm_kwrB3ZoKf7OufTHWaHJV7a;vector->mSize=n;
vector->mCap=n;vector->mValues=pmf_malloc(n*sizeof(real_T));(void)0;;for(
sm_kwrB3ZoKf7OufTHWaHJV7a=0;sm_kwrB3ZoKf7OufTHWaHJV7a<n;++
sm_kwrB3ZoKf7OufTHWaHJV7a)vector->mValues[sm_kwrB3ZoKf7OufTHWaHJV7a]=
pm_kpzAtHMD4_WnheH0UiioSE;}void sm_core_SmRealVector_copy(SmRealVector*copy,
const SmRealVector*orig){const size_t n=orig->mSize;copy->mSize=n;copy->mCap=n
;copy->mValues=pmf_malloc(n*sizeof(real_T));(void)0;;memcpy(copy->mValues,orig
->mValues,n*sizeof(real_T));}void sm_core_SmRealVector_destroy(SmRealVector*
vector){vector->mSize=0;vector->mCap=0;pmf_free(vector->mValues);}int
sm_core_SmRealVector_isEmpty(const SmRealVector*vector){return vector->mSize==
0;}size_t sm_core_SmRealVector_size(const SmRealVector*vector){return vector->
mSize;}size_t sm_core_SmRealVector_capacity(const SmRealVector*vector){return
vector->mCap;}real_T sm_core_SmRealVector_value(const SmRealVector*vector,
size_t index){return vector->mValues[index];}void sm_core_SmRealVector_setValue
(SmRealVector*vector,size_t index,real_T value){vector->mValues[index]=value;}
const real_T*sm_core_SmRealVector_values(const SmRealVector*vector){return
vector->mValues;}real_T*sm_core_SmRealVector_nonConstValues(SmRealVector*
vector){return vector->mValues;}void sm_core_SmRealVector_reserve(SmRealVector
*vector,size_t n){if(vector->mCap<n){real_T*sm_V0NIpiHDZuOreH8HYF0R1c=
pmf_malloc(n*sizeof(real_T));(void)0;;memcpy(sm_V0NIpiHDZuOreH8HYF0R1c,vector
->mValues,vector->mSize*sizeof(real_T));pmf_free(vector->mValues);vector->
mValues=sm_V0NIpiHDZuOreH8HYF0R1c;vector->mCap=n;}}void
sm_core_SmRealVector_clear(SmRealVector*vector){vector->mSize=0;}void
sm_core_SmRealVector_pushBack(SmRealVector*vector,real_T
pm_kpzAtHMD4_WnheH0UiioSE){const size_t sm_FF4ljM6P4J09VTBr_9j0_n=vector->
mSize+1;if(sm_FF4ljM6P4J09VTBr_9j0_n>vector->mCap){real_T*
sm_V0NIpiHDZuOreH8HYF0R1c=NULL;size_t sm_kWBy9c3tvf0AfLsF3yPjEJ=1;while((
sm_kWBy9c3tvf0AfLsF3yPjEJ<sm_FF4ljM6P4J09VTBr_9j0_n)&&
sm_kWBy9c3tvf0AfLsF3yPjEJ)sm_kWBy9c3tvf0AfLsF3yPjEJ<<=1;(void)0;;
sm_V0NIpiHDZuOreH8HYF0R1c=pmf_malloc(sm_kWBy9c3tvf0AfLsF3yPjEJ*sizeof(real_T))
;(void)0;;memcpy(sm_V0NIpiHDZuOreH8HYF0R1c,vector->mValues,vector->mSize*
sizeof(real_T));pmf_free(vector->mValues);vector->mValues=
sm_V0NIpiHDZuOreH8HYF0R1c;vector->mCap=sm_kWBy9c3tvf0AfLsF3yPjEJ;}vector->
mValues[vector->mSize]=pm_kpzAtHMD4_WnheH0UiioSE;++vector->mSize;}void
sm_core_SmRealVector_popBack(SmRealVector*vector){(void)0;;--vector->mSize;}
