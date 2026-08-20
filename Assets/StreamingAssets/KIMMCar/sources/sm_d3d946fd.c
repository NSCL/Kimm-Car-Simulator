#include "KIMMCar_macros.h"
#include "pm_std.h"
struct sm_VyMyiCkswBGSVHKV7K9y0j{size_t sm_VBhXl5S3Ty0ke9eRVj3mN_;size_t
sm__fm2pPlxu3GriPdcqjJuuY;};typedef struct sm_VyMyiCkswBGSVHKV7K9y0j
sm__IBzIbjIoWxlgLAaUEJWn0;struct sm__KFB2mOHcJK7eDJLVGseV2{size_t mSize;size_t
mCap;sm__IBzIbjIoWxlgLAaUEJWn0*mValues;};typedef struct
sm__KFB2mOHcJK7eDJLVGseV2 sm_Vym5QKhuSApPdqzYzWmVo7;void
sm_core_SmSizePairVector_create(sm_Vym5QKhuSApPdqzYzWmVo7*vector,size_t n,
const sm__IBzIbjIoWxlgLAaUEJWn0*pm_kpzAtHMD4_WnheH0UiioSE);void
sm_core_SmSizePairVector_copy(sm_Vym5QKhuSApPdqzYzWmVo7*copy,const
sm_Vym5QKhuSApPdqzYzWmVo7*orig);void sm_core_SmSizePairVector_destroy(
sm_Vym5QKhuSApPdqzYzWmVo7*vector);int sm_core_SmSizePairVector_isEmpty(const
sm_Vym5QKhuSApPdqzYzWmVo7*vector);size_t sm_core_SmSizePairVector_size(const
sm_Vym5QKhuSApPdqzYzWmVo7*vector);size_t sm_core_SmSizePairVector_capacity(
const sm_Vym5QKhuSApPdqzYzWmVo7*vector);const sm__IBzIbjIoWxlgLAaUEJWn0*
sm_core_SmSizePairVector_value(const sm_Vym5QKhuSApPdqzYzWmVo7*vector,size_t
index);void sm_core_SmSizePairVector_setValue(sm_Vym5QKhuSApPdqzYzWmVo7*vector
,size_t index,const sm__IBzIbjIoWxlgLAaUEJWn0*value);const
sm__IBzIbjIoWxlgLAaUEJWn0*sm_core_SmSizePairVector_values(const
sm_Vym5QKhuSApPdqzYzWmVo7*vector);sm__IBzIbjIoWxlgLAaUEJWn0*
sm_core_SmSizePairVector_nonConstValues(sm_Vym5QKhuSApPdqzYzWmVo7*vector);void
sm_core_SmSizePairVector_reserve(sm_Vym5QKhuSApPdqzYzWmVo7*vector,size_t n);
void sm_core_SmSizePairVector_clear(sm_Vym5QKhuSApPdqzYzWmVo7*vector);void
sm_core_SmSizePairVector_pushBack(sm_Vym5QKhuSApPdqzYzWmVo7*vector,const
sm__IBzIbjIoWxlgLAaUEJWn0*pm_kpzAtHMD4_WnheH0UiioSE);void
sm_core_SmSizePairVector_popBack(sm_Vym5QKhuSApPdqzYzWmVo7*vector);size_t
sm_core_SmSizePairVector_find(const sm_Vym5QKhuSApPdqzYzWmVo7*
sm_kYVhBJKlndKGi9KvU7lJMg,size_t sm_kvBdBwVdJztaXPLz5_6q7C);
#include "string.h"
#include "pm_std.h"
#include "pm_std.h"
void sm_core_SmSizePairVector_create(sm_Vym5QKhuSApPdqzYzWmVo7*vector,size_t n
,const sm__IBzIbjIoWxlgLAaUEJWn0*pm_kpzAtHMD4_WnheH0UiioSE){size_t
sm_kwrB3ZoKf7OufTHWaHJV7a;vector->mSize=n;vector->mCap=n;vector->mValues=
pmf_malloc(n*sizeof(sm__IBzIbjIoWxlgLAaUEJWn0));(void)0;;for(
sm_kwrB3ZoKf7OufTHWaHJV7a=0;sm_kwrB3ZoKf7OufTHWaHJV7a<n;++
sm_kwrB3ZoKf7OufTHWaHJV7a)vector->mValues[sm_kwrB3ZoKf7OufTHWaHJV7a]= *(
pm_kpzAtHMD4_WnheH0UiioSE);}void sm_core_SmSizePairVector_copy(
sm_Vym5QKhuSApPdqzYzWmVo7*copy,const sm_Vym5QKhuSApPdqzYzWmVo7*orig){const
size_t n=orig->mSize;copy->mSize=n;copy->mCap=n;copy->mValues=pmf_malloc(n*
sizeof(sm__IBzIbjIoWxlgLAaUEJWn0));(void)0;;memcpy(copy->mValues,orig->mValues
,n*sizeof(sm__IBzIbjIoWxlgLAaUEJWn0));}void sm_core_SmSizePairVector_destroy(
sm_Vym5QKhuSApPdqzYzWmVo7*vector){vector->mSize=0;vector->mCap=0;pmf_free(
vector->mValues);}int sm_core_SmSizePairVector_isEmpty(const
sm_Vym5QKhuSApPdqzYzWmVo7*vector){return vector->mSize==0;}size_t
sm_core_SmSizePairVector_size(const sm_Vym5QKhuSApPdqzYzWmVo7*vector){return
vector->mSize;}size_t sm_core_SmSizePairVector_capacity(const
sm_Vym5QKhuSApPdqzYzWmVo7*vector){return vector->mCap;}const
sm__IBzIbjIoWxlgLAaUEJWn0*sm_core_SmSizePairVector_value(const
sm_Vym5QKhuSApPdqzYzWmVo7*vector,size_t index){return&(vector->mValues[index])
;}void sm_core_SmSizePairVector_setValue(sm_Vym5QKhuSApPdqzYzWmVo7*vector,
size_t index,const sm__IBzIbjIoWxlgLAaUEJWn0*value){vector->mValues[index]= *(
value);}const sm__IBzIbjIoWxlgLAaUEJWn0*sm_core_SmSizePairVector_values(const
sm_Vym5QKhuSApPdqzYzWmVo7*vector){return vector->mValues;}
sm__IBzIbjIoWxlgLAaUEJWn0*sm_core_SmSizePairVector_nonConstValues(
sm_Vym5QKhuSApPdqzYzWmVo7*vector){return vector->mValues;}void
sm_core_SmSizePairVector_reserve(sm_Vym5QKhuSApPdqzYzWmVo7*vector,size_t n){if
(vector->mCap<n){sm__IBzIbjIoWxlgLAaUEJWn0*sm_V0NIpiHDZuOreH8HYF0R1c=
pmf_malloc(n*sizeof(sm__IBzIbjIoWxlgLAaUEJWn0));(void)0;;memcpy(
sm_V0NIpiHDZuOreH8HYF0R1c,vector->mValues,vector->mSize*sizeof(
sm__IBzIbjIoWxlgLAaUEJWn0));pmf_free(vector->mValues);vector->mValues=
sm_V0NIpiHDZuOreH8HYF0R1c;vector->mCap=n;}}void sm_core_SmSizePairVector_clear
(sm_Vym5QKhuSApPdqzYzWmVo7*vector){vector->mSize=0;}void
sm_core_SmSizePairVector_pushBack(sm_Vym5QKhuSApPdqzYzWmVo7*vector,const
sm__IBzIbjIoWxlgLAaUEJWn0*pm_kpzAtHMD4_WnheH0UiioSE){const size_t
sm_FF4ljM6P4J09VTBr_9j0_n=vector->mSize+1;if(sm_FF4ljM6P4J09VTBr_9j0_n>vector
->mCap){sm__IBzIbjIoWxlgLAaUEJWn0*sm_V0NIpiHDZuOreH8HYF0R1c=NULL;size_t
sm_kWBy9c3tvf0AfLsF3yPjEJ=1;while((sm_kWBy9c3tvf0AfLsF3yPjEJ<
sm_FF4ljM6P4J09VTBr_9j0_n)&&sm_kWBy9c3tvf0AfLsF3yPjEJ)
sm_kWBy9c3tvf0AfLsF3yPjEJ<<=1;(void)0;;sm_V0NIpiHDZuOreH8HYF0R1c=pmf_malloc(
sm_kWBy9c3tvf0AfLsF3yPjEJ*sizeof(sm__IBzIbjIoWxlgLAaUEJWn0));(void)0;;memcpy(
sm_V0NIpiHDZuOreH8HYF0R1c,vector->mValues,vector->mSize*sizeof(
sm__IBzIbjIoWxlgLAaUEJWn0));pmf_free(vector->mValues);vector->mValues=
sm_V0NIpiHDZuOreH8HYF0R1c;vector->mCap=sm_kWBy9c3tvf0AfLsF3yPjEJ;}vector->
mValues[vector->mSize]= *(pm_kpzAtHMD4_WnheH0UiioSE);++vector->mSize;}void
sm_core_SmSizePairVector_popBack(sm_Vym5QKhuSApPdqzYzWmVo7*vector){(void)0;;--
vector->mSize;}size_t sm_core_SmSizePairVector_find(const
sm_Vym5QKhuSApPdqzYzWmVo7*sm_kYVhBJKlndKGi9KvU7lJMg,size_t
sm_kvBdBwVdJztaXPLz5_6q7C){size_t sm___aedK39Pax6Ziebprhh0i=0,
sm__7SfbnIfBcGZYinikDTuBC=sm_kYVhBJKlndKGi9KvU7lJMg->mSize;const
sm__IBzIbjIoWxlgLAaUEJWn0*sm_kdrHBeJXW48AfeJ__OW11R=sm_kYVhBJKlndKGi9KvU7lJMg
->mValues;while(sm___aedK39Pax6Ziebprhh0i<sm__7SfbnIfBcGZYinikDTuBC){size_t
sm_kkX5Np8moDtzfD62egX1Ls=(sm___aedK39Pax6Ziebprhh0i+sm__7SfbnIfBcGZYinikDTuBC
)/2;const size_t sm_V2__YrimeI4E_yWnhKofpy=sm_kdrHBeJXW48AfeJ__OW11R[
sm_kkX5Np8moDtzfD62egX1Ls].sm_VBhXl5S3Ty0ke9eRVj3mN_;if(
sm_V2__YrimeI4E_yWnhKofpy==sm_kvBdBwVdJztaXPLz5_6q7C)return
sm_kkX5Np8moDtzfD62egX1Ls;else if(sm_V2__YrimeI4E_yWnhKofpy<
sm_kvBdBwVdJztaXPLz5_6q7C)sm___aedK39Pax6Ziebprhh0i=sm_kkX5Np8moDtzfD62egX1Ls+
1;else sm__7SfbnIfBcGZYinikDTuBC=sm_kkX5Np8moDtzfD62egX1Ls;}return
sm_kYVhBJKlndKGi9KvU7lJMg->mSize;}
