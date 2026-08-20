#ifndef __sm_CTarget_h__
#define __sm_CTarget_h__
#include "sm_SmRealVector.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
struct CTargetTag{unsigned int mType;size_t mBlockContIdx;boolean_T mIsPartial
;int mPartialType;unsigned int mStrength;char*mSpecifiedUnit;size_t mPrimIdx;
boolean_T mIsVelocity;boolean_T mIsAngular;real_T mConversionFactor;boolean_T
mVelocityRequiresTransformation;SmRealVector mValue;real_T mAuxiliaryTargetData
[1];};typedef struct CTargetTag CTarget;void sm_compiler_CTarget_create(
CTarget*target);void sm_compiler_CTarget_copy(const CTarget*orig,CTarget*copy)
;void sm_compiler_CTarget_destroy(CTarget*target);void
sm_compiler_CTarget_setSpecifiedUnit(const char*unitString,CTarget*target);
void sm_compiler_CTarget_setValue(const double*val,size_t numElements,CTarget*
target);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __sm_CTarget_h__ */
