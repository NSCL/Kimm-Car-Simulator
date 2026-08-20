#include "KIMMCar_macros.h"
#include "pm_std.h"
struct sm_FAe_hLKRs0t1gPCNBVVtIR{size_t mSize;size_t mCap;int*mValues;};
typedef struct sm_FAe_hLKRs0t1gPCNBVVtIR sm_V7xsSSeDhNGdeHRBws_2Zg;void
sm_core_SmIntVector_create(sm_V7xsSSeDhNGdeHRBws_2Zg*vector,size_t n,int
pm_kpzAtHMD4_WnheH0UiioSE);void sm_core_SmIntVector_copy(
sm_V7xsSSeDhNGdeHRBws_2Zg*copy,const sm_V7xsSSeDhNGdeHRBws_2Zg*orig);void
sm_core_SmIntVector_destroy(sm_V7xsSSeDhNGdeHRBws_2Zg*vector);int
sm_core_SmIntVector_isEmpty(const sm_V7xsSSeDhNGdeHRBws_2Zg*vector);size_t
sm_core_SmIntVector_size(const sm_V7xsSSeDhNGdeHRBws_2Zg*vector);size_t
sm_core_SmIntVector_capacity(const sm_V7xsSSeDhNGdeHRBws_2Zg*vector);int
sm_core_SmIntVector_value(const sm_V7xsSSeDhNGdeHRBws_2Zg*vector,size_t index)
;void sm_core_SmIntVector_setValue(sm_V7xsSSeDhNGdeHRBws_2Zg*vector,size_t
index,int value);const int*sm_core_SmIntVector_values(const
sm_V7xsSSeDhNGdeHRBws_2Zg*vector);int*sm_core_SmIntVector_nonConstValues(
sm_V7xsSSeDhNGdeHRBws_2Zg*vector);void sm_core_SmIntVector_reserve(
sm_V7xsSSeDhNGdeHRBws_2Zg*vector,size_t n);void sm_core_SmIntVector_clear(
sm_V7xsSSeDhNGdeHRBws_2Zg*vector);void sm_core_SmIntVector_pushBack(
sm_V7xsSSeDhNGdeHRBws_2Zg*vector,int pm_kpzAtHMD4_WnheH0UiioSE);void
sm_core_SmIntVector_popBack(sm_V7xsSSeDhNGdeHRBws_2Zg*vector);
#include "string.h"
#include "pm_std.h"
#include "pm_std.h"
void sm_core_SmIntVector_create(sm_V7xsSSeDhNGdeHRBws_2Zg*vector,size_t n,int
pm_kpzAtHMD4_WnheH0UiioSE){size_t sm_kwrB3ZoKf7OufTHWaHJV7a;vector->mSize=n;
vector->mCap=n;vector->mValues=pmf_malloc(n*sizeof(int));(void)0;;for(
sm_kwrB3ZoKf7OufTHWaHJV7a=0;sm_kwrB3ZoKf7OufTHWaHJV7a<n;++
sm_kwrB3ZoKf7OufTHWaHJV7a)vector->mValues[sm_kwrB3ZoKf7OufTHWaHJV7a]=
pm_kpzAtHMD4_WnheH0UiioSE;}void sm_core_SmIntVector_copy(
sm_V7xsSSeDhNGdeHRBws_2Zg*copy,const sm_V7xsSSeDhNGdeHRBws_2Zg*orig){const
size_t n=orig->mSize;copy->mSize=n;copy->mCap=n;copy->mValues=pmf_malloc(n*
sizeof(int));(void)0;;memcpy(copy->mValues,orig->mValues,n*sizeof(int));}void
sm_core_SmIntVector_destroy(sm_V7xsSSeDhNGdeHRBws_2Zg*vector){vector->mSize=0;
vector->mCap=0;pmf_free(vector->mValues);}int sm_core_SmIntVector_isEmpty(
const sm_V7xsSSeDhNGdeHRBws_2Zg*vector){return vector->mSize==0;}size_t
sm_core_SmIntVector_size(const sm_V7xsSSeDhNGdeHRBws_2Zg*vector){return vector
->mSize;}size_t sm_core_SmIntVector_capacity(const sm_V7xsSSeDhNGdeHRBws_2Zg*
vector){return vector->mCap;}int sm_core_SmIntVector_value(const
sm_V7xsSSeDhNGdeHRBws_2Zg*vector,size_t index){return vector->mValues[index];}
void sm_core_SmIntVector_setValue(sm_V7xsSSeDhNGdeHRBws_2Zg*vector,size_t index
,int value){vector->mValues[index]=value;}const int*sm_core_SmIntVector_values
(const sm_V7xsSSeDhNGdeHRBws_2Zg*vector){return vector->mValues;}int*
sm_core_SmIntVector_nonConstValues(sm_V7xsSSeDhNGdeHRBws_2Zg*vector){return
vector->mValues;}void sm_core_SmIntVector_reserve(sm_V7xsSSeDhNGdeHRBws_2Zg*
vector,size_t n){if(vector->mCap<n){int*sm_V0NIpiHDZuOreH8HYF0R1c=pmf_malloc(n
*sizeof(int));(void)0;;memcpy(sm_V0NIpiHDZuOreH8HYF0R1c,vector->mValues,vector
->mSize*sizeof(int));pmf_free(vector->mValues);vector->mValues=
sm_V0NIpiHDZuOreH8HYF0R1c;vector->mCap=n;}}void sm_core_SmIntVector_clear(
sm_V7xsSSeDhNGdeHRBws_2Zg*vector){vector->mSize=0;}void
sm_core_SmIntVector_pushBack(sm_V7xsSSeDhNGdeHRBws_2Zg*vector,int
pm_kpzAtHMD4_WnheH0UiioSE){const size_t sm_FF4ljM6P4J09VTBr_9j0_n=vector->
mSize+1;if(sm_FF4ljM6P4J09VTBr_9j0_n>vector->mCap){int*
sm_V0NIpiHDZuOreH8HYF0R1c=NULL;size_t sm_kWBy9c3tvf0AfLsF3yPjEJ=1;while((
sm_kWBy9c3tvf0AfLsF3yPjEJ<sm_FF4ljM6P4J09VTBr_9j0_n)&&
sm_kWBy9c3tvf0AfLsF3yPjEJ)sm_kWBy9c3tvf0AfLsF3yPjEJ<<=1;(void)0;;
sm_V0NIpiHDZuOreH8HYF0R1c=pmf_malloc(sm_kWBy9c3tvf0AfLsF3yPjEJ*sizeof(int));(
void)0;;memcpy(sm_V0NIpiHDZuOreH8HYF0R1c,vector->mValues,vector->mSize*sizeof(
int));pmf_free(vector->mValues);vector->mValues=sm_V0NIpiHDZuOreH8HYF0R1c;
vector->mCap=sm_kWBy9c3tvf0AfLsF3yPjEJ;}vector->mValues[vector->mSize]=
pm_kpzAtHMD4_WnheH0UiioSE;++vector->mSize;}void sm_core_SmIntVector_popBack(
sm_V7xsSSeDhNGdeHRBws_2Zg*vector){(void)0;;--vector->mSize;}
