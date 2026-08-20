#ifndef ___nesl_rtw_h__
#define ___nesl_rtw_h__
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
int_T pm_create_sparsity_pattern_fields(PmSparsityPattern*patternPtr,size_t
nNzMax,size_t nRow,size_t nCol,PmAllocator*allocator);PmSparsityPattern*
pm_create_sparsity_pattern(size_t nNzMax,size_t nRow,size_t nCol,PmAllocator*
allocatorPtr);void pm_sp_equals_sp(PmSparsityPattern*Ap,const PmSparsityPattern
*Bp);boolean_T pm_sp_equalequals_sp(const PmSparsityPattern*Ap,const
PmSparsityPattern*Bp);PmSparsityPattern*pm_copy_sparsity_pattern(const
PmSparsityPattern*input_pattern,PmAllocator*allocatorPtr);void
pm_destroy_sparsity_pattern_fields(PmSparsityPattern*patternPtr,PmAllocator*
allocator);void pm_destroy_sparsity_pattern(PmSparsityPattern*patternPtr,
PmAllocator*allocatorPtr);PmSparsityPattern*pm_create_full_sparsity_pattern(
size_t nrows,size_t ncols,PmAllocator*allocatorPtr);PmSparsityPattern*
pm_create_empty_sparsity_pattern(size_t nrows,size_t ncols,PmAllocator*
allocatorPtr);PmSparsityPattern*pm_create_partial_identity_sparsity_pattern(
size_t p,size_t n,PmAllocator*allocatorPtr);PmSparsityPattern*
pm_create_identity_sparsity_pattern(size_t n,PmAllocator*allocatorPtr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
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
#include "mc_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
const McLinearAlgebraFactory*mc_get_csparse_linear_algebra(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "mc_std.h"
#include "pm_std.h"
#include "ne_std_fwd.h"
#include "pm_std.h"
#include "stdarg.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef NeuDiagnosticTree*NeuDiagnosticId;typedef struct
NeuDiagnosticManagerPrivateDataTag NeuDiagnosticManagerPrivateData;struct
NeuDiagnosticManagerTag{NeuDiagnosticManagerPrivateData*mPrivateData;
NeuDiagnosticId(*mStartSubtree)(const NeuDiagnosticManager*mgr);void(*
mFinishSubtree)(const NeuDiagnosticManager*mgr,NeuDiagnosticId diagId,
NeuDiagnosticLevel verbosity,PmfMessageId msgId,va_list args);void(*
mFinishSubtreeUser)(const NeuDiagnosticManager*mgr,NeuDiagnosticId diagId,
NeuDiagnosticLevel verbosity,PmfMessageId msgId,va_list args);void(*
mClearSubtree)(const NeuDiagnosticManager*mgr,NeuDiagnosticId diagId);void(*
mTransferTree)(const NeuDiagnosticManager*dest,const NeuDiagnosticManager*src)
;const NeuDiagnosticTree*(*mGetInitialTree)(const NeuDiagnosticManager*mgr);
void(*mDestroy)(NeuDiagnosticManager*mgr);};PmfMessageId
neu_diagnostic_finish_subtree(const NeuDiagnosticManager*mgr,NeuDiagnosticId
diagId,NeuDiagnosticLevel verbosity,PmfMessageId msgId,...);PmfMessageId
neu_diagnostic_finish_subtree_user(const NeuDiagnosticManager*mgr,
NeuDiagnosticId diagId,NeuDiagnosticLevel verbosity,PmfMessageId msgId,...);
PmfMessageId neu_diagnostic_one_node_subtree(const NeuDiagnosticManager*mgr,
NeuDiagnosticLevel verbosity,PmfMessageId msgId,...);PmfMessageId
neu_diagnostic_finish_subtree_preformatted(const NeuDiagnosticManager*mgr,
NeuDiagnosticId diagId,NeuDiagnosticLevel verbosity,PmfMessageId msgId,const
char*msg);PmfMessageId neu_diagnostic_one_node_subtree_preformatted(const
NeuDiagnosticManager*mgr,NeuDiagnosticLevel verbosity,PmfMessageId msgId,const
char*msg);NeuDiagnosticManager*neu_create_diagnostic_manager(PmAllocator*alloc
);void neu_destroy_diagnostic_manager(NeuDiagnosticManager*mgr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "ne_std_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeuDiagnosticTreePrinterTag NeuDiagnosticTreePrinter;typedef
struct NeuDiagnosticTreePrinterPrivateDataTag
NeuDiagnosticTreePrinterPrivateData;struct NeuDiagnosticTreePrinterTag{
NeuDiagnosticTreePrinterPrivateData*mPrivateData;const char*(*mPrint)(
NeuDiagnosticTreePrinter*printer,const NeuDiagnosticTree*tree);void(*mDestroy)
(NeuDiagnosticTreePrinter*printer);};NeuDiagnosticTreePrinter*
neu_create_diagnostic_tree_printer(PmAllocator*alloc);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "ne_std_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
const char*neu_tree_viewer_get_id(const NeuDiagnosticTree*tree);const char*
neu_tree_viewer_get_msg(const NeuDiagnosticTree*tree);NeuDiagnosticLevel
neu_tree_viewer_get_level(const NeuDiagnosticTree*tree);size_t
neu_tree_viewer_get_num_causes(const NeuDiagnosticTree*tree);const
NeuDiagnosticTree*neu_tree_viewer_get_cause_k(const NeuDiagnosticTree*tree,
size_t k);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
void neu_diagnostic_tree_warning(const NeuDiagnosticTree*tree);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std_fwd.h"
#include "ssc_dae_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeSolverSystemTag NeSolverSystem;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "ssc_dae_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
void nes_dae_get_base_methods(NeDae*dae_ptr);PmIntVector*
nes_compute_output_function_map(const PmSparsityPattern*duy,uint32_T inputOrder
);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "ne_std.h"
#include "ne_ds.h"
#include "pm_std.h"
#include "pm_std.h"
#include "mc_std_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef enum{MC_SOLVER_STATUS_INVALID= -1,MC_SOLVER_SUCCESS,MC_SOLVER_FAILURE,
MC_SOLVER_SINGULAR_MATRIX,MC_SOLVER_NO_CONVERGENCE,MC_SOLVER_TOLERANCE_UNMET,
MC_SOLVER_LINEAR_INCONSISTENT,MC_SOLVER_STATUS_COUNT}McSolverStatus;typedef
struct McRealFunctionPrivateDataTag McRealFunctionPrivateData;struct
McRealFunctionTag{McRealFunctionPrivateData*mPrivateDataPtr;McSolverStatus(*
mFunctionPtr)(const void*input,const PmRealVector*output,
McRealFunctionPrivateData*data);const void*(*mGetDefaultInput)(const
McRealFunction*function);void(*mDestroy)(McRealFunction*function);};typedef
struct McIntFunctionPrivateDataTag McIntFunctionPrivateData;struct
McIntFunctionTag{McIntFunctionPrivateData*mPrivateDataPtr;void(*mFunctionPtr)(
const void*input,const PmIntVector*output,McIntFunctionPrivateData*data);const
void*(*mGetDefaultInput)(const McIntFunction*function);void(*mDestroy)(
McIntFunction*function);};typedef struct McMatrixFunctionPrivateDataTag
McMatrixFunctionPrivateData;struct McMatrixFunctionTag{
McMatrixFunctionPrivateData*mPrivateDataPtr;const PmSparsityPattern*
mPatternPtr;void(*mFunctionPtr)(const void*input,const PmRealVector*output,
McMatrixFunctionPrivateData*data);const void*(*mGetDefaultInput)(const
McMatrixFunction*function);void(*mDestroy)(McMatrixFunction*function);};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct DDIWrapperPrivateDataTag DDIWrapperPrivateData;typedef struct
DaeDynamicInfoWrapperTag DaeDynamicInfoWrapper;struct DaeDynamicInfoWrapperTag
{DDIWrapperPrivateData*mPrivateData;void(*mReportIC)(const
DaeDynamicInfoWrapper*,const NeSystemInput*,const NeParameterBundle*,const
NeDerivedParameterBundle*,size_t,boolean_T,boolean_T);void(*mReportMode)(const
DaeDynamicInfoWrapper*,const NeSystemInput*,boolean_T,boolean_T,boolean_T,
int16_T);void(*mPushInfo)(const DaeDynamicInfoWrapper*,size_t);void(*
mInitializeState)(DaeDynamicInfoWrapper*,McMatrixFunction*,McMatrixFunction*,
McMatrixFunction*,McMatrixFunction*,McMatrixFunction*,McRealFunction*,
McRealFunction*,size_t,size_t,size_t,size_t);void(*mDestroy)(
DaeDynamicInfoWrapper*);};DaeDynamicInfoWrapper*ddi_wrapper_create(const char*
solverPath);typedef enum{DAEMON_CHOICE_INVALID= -1,DAEMON_CHOICE_NONE,
DAEMON_CHOICE_LOG_NUM_ITERATIONS,DAEMON_CHOICE_SSC2HDL,NUM_DAEMON_CHOICES}
DaemonChoice;NeSolverSystem*nes_create_crude_solver_system(NeDynamicSystem*
dynamicsystemPtr,NeModelParameters modelParameters,NeSolverParameters
solverParameters,PmAllocator*allocatorPtr);NeSolverSystem*
nes_create_crude_solver_system_daemon(NeDynamicSystem*dynamicsystemPtr,
NeModelParameters modelParameters,NeSolverParameters solverParameters,
PmAllocator*allocatorPtr,DaeDynamicInfoWrapper*ddiWrapper);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeConstraintStatTag NeConstraintStat;struct NeConstraintStatTag
{void(*mVariable)(const NeConstraintStat*,const NeVariableData*);struct
NeConstraintStatData*mData;};typedef struct NeCompStatsTag NeCompStats;struct
NeCompStatsTag{const NeConstraintStat*(*mConstraint)(const NeCompStats*);
struct NeCompStatsData*mData;};NeSolverSystem*
nes_create_index_reduced_solver_system(NeSolverSystem*basePtr,
NeSolverParameters sp,const NeCompStats*compStats,PmAllocator*allocatorPtr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
NeSolverSystem*nes_create_optimized_solver_system(NeSolverSystem*
solverSystemPtr,PmAllocator*allocatorPtr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
NeSolverSystem*nes_create_regularized_solver_system(NeSolverSystem*ss,
NeSolverParameters sp,PmAllocator*allocator);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std_fwd.h"
#include "ne_ds.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeProfilingServiceTag{NeDynamicSystem*(*mProfileDs)(const
NeProfiler*,NeDynamicSystem*);NeSolverSystem*(*mProfileSs)(const NeProfiler*,
NeSolverSystem*,const char*);NeDae*(*mProfileDae)(const NeProfiler*,NeDae*);}
NeProfilingService;boolean_T nes_set_profiling_service(NeProfilingService*);
NeDynamicSystem*nes_profile_dynamic_system(const NeProfiler*,NeDynamicSystem*)
;NeSolverSystem*nes_profile_solver_system(const NeProfiler*,NeSolverSystem*,
const char*);NeDae*nes_profile_dae(const NeProfiler*,NeDae*);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "mc_std.h"
#include "ne_std.h"
#include "pm_std.h"
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct McStateTracerInfoTag McStateTracerInfo;struct
McStateTracerInfoTag{void*mPrivateData;void(*mLogSolveInfo)(McStateTracerInfo*
,const char*solveId,const char*label);void(*mLogSolveInfoR)(McStateTracerInfo*
,const char*solveId,const char*label,real_T data);void(*mLogSolveInfoRv)(
McStateTracerInfo*,const char*solveId,const char*label,const PmRealVector*data
);void(*mLogSolveInfoPr)(McStateTracerInfo*,const char*solveId,const char*
label,const PmSparsityPattern*pattern,const PmRealVector*data);};typedef struct
McNonlinearEquationTag McNonlinearEquation;typedef struct
McNonlinearEquationPrivateDataTag McNonlinearEquationPrivateData;typedef struct
McNonlinearStateTracerTag McNonlinearStateTracer;struct
McNonlinearStateTracerTag{McStateTracerInfo*mInfoTracer;void(*mLogSolveValues)
(const McNonlinearEquation*eq,const PmRealVector*in,const char*solveId);};
struct McNonlinearEquationTag{McNonlinearEquationPrivateData*mPrivateData;
const PmSparsityPattern*mPattern;McNonlinearStateTracer mStateTracer;void(*
mEvaluateFunction)(const McNonlinearEquation*eq,const PmRealVector*in,
PmRealVector*out);void(*mEvaluateJacobian)(const McNonlinearEquation*eq,const
PmRealVector*in,PmRealVector*out);void(*mEvaluateTolerances)(const
McNonlinearEquation*eq,const PmRealVector*in,PmRealVector*out);void(*mDestroy)
(McNonlinearEquation*eq);};typedef struct McNonlinearSolverTag
McNonlinearSolver;typedef struct McNonlinearSolverPrivateDataTag
McNonlinearSolverPrivateData;typedef struct McSolverDiagnosticTag
McSolverDiagnostic;struct McSolverDiagnosticTag{int32_T mBadEquations[5];};
PMF_DEPLOY_STATIC McSolverDiagnostic mc_get_default_diagnostic(void){int32_T i
=0;McSolverDiagnostic result;for(i=0;i<5;i++){result.mBadEquations[i]= -1;}
return result;}struct McNonlinearSolverTag{McNonlinearSolverPrivateData*
mPrivateData;McSolverDiagnostic(*mGetDiagnostic)(const McNonlinearSolver*nls);
McSolverStatus(*mSolve)(const McNonlinearSolver*nls,PmRealVector*rv);void(*
mSetFactor)(const McNonlinearSolver*nls,real_T factor);void(*mUpdateCache)(
const McNonlinearSolver*nls);void(*mDestroy)(McNonlinearSolver*nls);};typedef
struct McNonlinearSolverFactoryTag McNonlinearSolverFactory;typedef struct
McNonlinearSolverFactoryPrivateDataTag McNonlinearSolverFactoryPrivateData;
struct McNonlinearSolverFactoryTag{McNonlinearSolverFactoryPrivateData*
mPrivateData;McNonlinearSolver*(*mCreateSolver)(const McNonlinearSolverFactory
*nlsf,const McNonlinearEquation*eq);void(*mDestroy)(McNonlinearSolverFactory*
nlsf);};typedef struct McHybridEquationTag McHybridEquation;typedef struct
McHybridEquationPrivateDataTag McHybridEquationPrivateData;typedef struct
McHybridStateTracerTag McHybridStateTracer;struct McHybridStateTracerTag{
McStateTracerInfo*mInfoTracer;void(*mLogSolveValues)(const McHybridEquation*eq
,const PmIntVector*modes,const PmRealVector*in,const char*solveId);};struct
McHybridEquationTag{McHybridEquationPrivateData*mPrivateData;const
PmSparsityPattern*mPattern;size_t mNumModes;McHybridStateTracer mStateTracer;
void(*mEvaluateFunction)(const McHybridEquation*eq,const PmIntVector*modes,
const PmRealVector*in,PmRealVector*out);void(*mEvaluateJacobian)(const
McHybridEquation*eq,const PmIntVector*modes,const PmRealVector*in,PmRealVector
*out);void(*mEvaluateTolerances)(const McHybridEquation*eq,const PmIntVector*
modes,const PmRealVector*in,PmRealVector*out);void(*mComputeModes)(const
McHybridEquation*eq,const PmIntVector*modes,const PmRealVector*in,PmIntVector*
out);void(*mDestroy)(McHybridEquation*eq);};typedef struct McHybridSolverTag
McHybridSolver;typedef struct McHybridSolverPrivateDataTag
McHybridSolverPrivateData;struct McHybridSolverTag{McHybridSolverPrivateData*
mPrivateData;McSolverStatus(*mSolve)(const McHybridSolver*,PmIntVector*,
PmRealVector*);McSolverDiagnostic(*mGetDiagnostic)(const McHybridSolver*nls);
void(*mSetFactor)(const McHybridSolver*nls,real_T factor);void(*mUpdateCache)(
const McHybridSolver*);void(*mDestroy)(McHybridSolver*nls);};typedef struct
McHybridSolverFactoryTag McHybridSolverFactory;typedef struct
McHybridSolverFactoryPrivateDataTag McHybridSolverFactoryPrivateData;struct
McHybridSolverFactoryTag{McHybridSolverFactoryPrivateData*mPrivateData;
McHybridSolver*(*mCreateSolver)(const McHybridSolverFactory*nlsf,const
McHybridEquation*eq);void(*mDestroy)(McHybridSolverFactory*nlsf);};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeuSystemEquationPrivateDataTag NeuSystemEquationPrivateData;
typedef struct NeuSystemEquationTag NeuSystemEquation;struct
NeuSystemEquationTag{const McHybridEquation*mGenericEquation;const PmBoolVector
*mLinearEquations;const PmRealVector*mMin;const PmRealVector*mMax;
NeuSystemEquationPrivateData*mPrivateData;void(*mInitialize)(const
NeuSystemEquation*eq,const NeSystemInput*si,PmRealVector*state);void(*
mTerminate)(const NeuSystemEquation*eq,const NeSystemInput*si,const
PmRealVector*state,PmRealVector*out);NeSystemInputSizes(*mSizes)(const
NeuSystemEquation*eq);McSolverDiagnostic(*mConvertDiagnostic)(const
NeuSystemEquation*eq,McSolverDiagnostic genericEqnDiag);void(*mDestroy)(
NeuSystemEquation*);};typedef struct NeuSystemSolverPrivateDataTag
NeuSystemSolverPrivateData;typedef struct NeuSystemSolverTag NeuSystemSolver;
struct NeuSystemSolverTag{NeuSystemSolverPrivateData*mPrivateData;
McSolverStatus(*mSolve)(const NeuSystemSolver*sol,const NeSystemInput*si);
McSolverDiagnostic(*mGetDiagnostic)(const NeuSystemSolver*sol);void(*
mSetFactor)(const NeuSystemSolver*sol,real_T factor);void(*mUpdateCache)(const
NeuSystemSolver*sol);void(*mDestroy)(NeuSystemSolver*sol);};typedef struct
NeuAdvanceableTag NeuAdvanceable;typedef struct NeuAdvanceablePrivateDataTag
NeuAdvanceablePrivateData;struct NeuAdvanceableTag{McRealFunction*mFF;
McMatrixFunction*mMM;McMatrixFunction*mDxf;McRealFunction*mTol;McRealFunction*
mXdDot;McIntFunction*mModes;McHybridSolverFactory*mSolverFactory;
McHybridSolverFactory*mRobustFactory;real_T mH;};typedef struct
NeuAdvancingSolverTag NeuAdvancingSolver;typedef struct
NeuAdvancingSolverPrivateDataTag NeuAdvancingSolverPrivateData;struct
NeuAdvancingSolverTag{NeuAdvancingSolverPrivateData*mPrivateData;
NeuSystemSolver*mStep;boolean_T mNeedsEventNotify;McSolverStatus(*
mInitSolverState)(const NeuAdvancingSolver*solver,const NeSystemInput*si);
size_t(*mGetSolverStateSize)(const NeuAdvancingSolver*solver);void(*mReset)(
const NeuAdvancingSolver*solver);void(*mPutSolverState)(const
NeuAdvancingSolver*solver,const PmRealVector*state);void(*mGetSolverState)(
const NeuAdvancingSolver*solver,const PmRealVector*state);void(*mDestroy)(
NeuAdvancingSolver*solver);};typedef enum LinearizationFormatTag{
SS_FORMAT_MODE,DSS_NORMAL_MODE,DSS_SWL_MODE}LinearizationFormat;typedef int32_T
(*DiagnosisSupportMethod)(const NeSolverSystem*topSys,const NeSystemInput*
topInput,real_T,PmCharVector,boolean_T);typedef PmfMessageId(*
StiffDiagnosticMethod)(const NeSolverSystem*sys,const NeSystemInput*input,void
*st);typedef PmfMessageId(*LinearizationSupportMethod)(const NeSolverSystem*,
const NeSystemInput*,PmRealVector*,const LinearizationFormat);typedef
PmfMessageId(*VslsSupportMethod)(const PmRealVector*);typedef void(*
EventIterationDiagMethod)(const NeSolverSystem*,const NeSystemInput*,const
PmRealVector*d,const PmIntVector*q,PmCharVector);typedef struct
NeSolverSupportMethodsTag{DiagnosisSupportMethod mDcDiagnosisSupportMethod;
DiagnosisSupportMethod mTrDiagnosisSupportMethod;DiagnosisSupportMethod
mAdvSolDiagnosisSupportMethod;DiagnosisSupportMethod mInconsistentIcMethod;
DiagnosisSupportMethod mIcJacobianDiagnosticsMethod;DiagnosisSupportMethod
mMassMatrixDiagnosticsMethod;LinearizationSupportMethod
mLinearizationSupportMethod;StiffDiagnosticMethod mStiffDiagnosticMethod;
VslsSupportMethod mVslsSupportMethod;EventIterationDiagMethod
mEventIterationDiagMethod;}NeSolverSupportMethods;void
nes_register_solver_support(const NeSolverSupportMethods*methods);const
NeSolverSupportMethods*nes_get_support_methods(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "ssc_dae_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct SscRTWLogFcnManagerTag SscRTWLogFcnManager;typedef struct
SscRTWLogFcnManagerObjectTag SscRTWLogFcnManagerObject;struct
SscRTWLogFcnManagerTag{void(*mRtwSetupLogFcn)(SscRTWLogFcnManager*);void(*
mRtwLogFcn)(SscRTWLogFcnManager*,double timeStep,double const*voidInputs,
double*buffer);void(*mRtwDestroy)(SscRTWLogFcnManager*);
SscRTWLogFcnManagerObject*mRtwObject;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std_fwd.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeOutputParametersTag NeOutputParameters;struct
NeOutputParametersTag{size_t mDaeIndex;size_t mOutputFunctionIndex;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "pm_std.h"
#include "ne_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeslRtpManagerTag NeslRtpManager;typedef struct
NeslRtpManagerUserDataTag NeslRtpManagerUserData;struct NeslRtpManagerTag{
NeslRtpManagerUserData*mUserData;void(*mDestroy)(NeslRtpManager*);
NeParameterInfo(*mParameterInfo)(const NeslRtpManager*);boolean_T(*
mSetParameters)(const NeslRtpManager*,double,const NeParameterBundle*,
NeuDiagnosticManager*);};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "ne_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeslSolverHitManagerTag NeslSolverHitManager;typedef struct
NeslSolverHitManagerUserDataTag NeslSolverHitManagerUserData;struct
NeslSolverHitManagerTag{NeslSolverHitManagerUserData*mUserData;void(*mDestroy)
(NeslSolverHitManager*);void(*mGetSolverHits)(const NeslSolverHitManager*,
NeuDiagnosticManager*,PmRealVector*);size_t(*mSolverHitsSize)(const
NeslSolverHitManager*);};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_inline.h"
#include "mc_std.h"
#include "ne_std_fwd.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "ssc_dae_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
struct NeCustomDataSizeTag{size_t mDoubleSize;size_t mIntegerSize;};struct
NeCustomDataTag{double*mDouble;int32_T*mInteger;NeCustomDataSize mSizes;
NeCustomData*mChildData;};NeCustomDataSize ne_get_zero_custom_data_size(void);
NeCustomData*ne_allocate_custom_data(NeCustomDataSize sizes);NeCustomData*
ne_allocate_empty_custom_data(void);void ne_free_custom_data(NeCustomData*ncd)
;size_t ne_measure_packed_custom_data(const NeCustomData*ncd);void
ne_pack_custom_data(const NeCustomData*ncd,char*store);NeCustomData*
ne_recreate_custom_data(const char*store,size_t len);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_stiffness_fwd.h"
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct McSparseMatrixTag McSparseMatrix;struct McSparseMatrixTag{
PmSparsityPattern*mPattern;PmRealVector*mPr;};McSparseMatrix*
mc_assemble_sparse_matrix(const PmSparsityPattern*patternPtr,const PmRealVector
*prPtr,PmAllocator*allocatorPtr);void mc_disassemble_sparse_matrix(
McSparseMatrix*matrix,PmAllocator*allocatorPtr);McSparseMatrix*
mc_create_sparse_matrix(size_t nNzMax,size_t nRow,size_t nCol,PmAllocator*
allocatorPtr);McSparseMatrix*mc_copy_sparse_matrix(const McSparseMatrix*
matrixPtr,PmAllocator*allocatorPtr);McSparseMatrix*
mc_create_identity_sparse_matrix(size_t n,PmAllocator*allocatorPtr);
McSparseMatrix*mc_create_hcat_sparse_matrix(const McSparseMatrix*a,const
McSparseMatrix*b,PmAllocator*allocatorPtr);McSparseMatrix*
mc_create_vcat_sparse_matrix(const McSparseMatrix*a,const McSparseMatrix*b,
PmAllocator*allocatorPtr);McSparseMatrix*mc_create_section_sparse_matrix(const
McSparseMatrix*matrix,size_t rowStart,size_t rowEndPlusOne,size_t colStart,
size_t colEndPlusOne,PmAllocator*allocatorPtr);McSparseMatrix*
mc_create_transpose_sparse_matrix(const McSparseMatrix*matrix,PmAllocator*
allocatorPtr);McSparseMatrix*mc_create_colperm_sparse_matrix(const
McSparseMatrix*matrix,const PmIntVector*perm,PmAllocator*allocatorPtr);
McSparseMatrix*mc_create_rowperm_sparse_matrix(const McSparseMatrix*matrix,
const PmIntVector*perm,PmAllocator*allocatorPtr);McSparseMatrix*
mc_create_right_padded_sparse_matrix(const McSparseMatrix*matrix,size_t padding
,PmAllocator*allocatorPtr);McSparseMatrix*
mc_create_bottom_padded_sparse_matrix(const McSparseMatrix*matrix,size_t
padding,PmAllocator*allocatorPtr);McSparseMatrix*
mc_create_product_sparse_matrix(const McSparseMatrix*A,const McSparseMatrix*B,
PmAllocator*allocatorPtr);McSparseMatrix*mc_create_sum_sparse_matrix(const
McSparseMatrix*A,const McSparseMatrix*B,PmAllocator*allocatorPtr);
McSparseMatrix*mc_create_sparse_submatrix(const McSparseMatrix*matrix,const
PmBoolVector*selectedRows,const PmBoolVector*selectedCols,PmAllocator*
allocatorPtr);McSparseMatrix*mc_create_sparse_supermatrix(const McSparseMatrix
*matrix,const PmBoolVector*rows,const PmBoolVector*cols,PmAllocator*al);
McSparseMatrix*mc_create_sparse_restriction(const McSparseMatrix*matrix,const
PmBoolVector*selectedRows,const PmBoolVector*selectedCols,PmAllocator*
allocatorPtr);McSparseMatrix*mc_extract_col(const McSparseMatrix*matrix,size_t
col,PmAllocator*allocatorPtr);McSparseMatrix*mc_extract_row(const
McSparseMatrix*matrix,size_t row,PmAllocator*allocatorPtr);McSparseMatrix*
mc_remove_col(const McSparseMatrix*matrix,size_t col,PmAllocator*allocatorPtr)
;McSparseMatrix*mc_remove_row(const McSparseMatrix*matrix,size_t row,
PmAllocator*allocatorPtr);void mc_destroy_sparse_matrix(McSparseMatrix*
matrixPtr,PmAllocator*allocatorPtr);McSparseMatrix*mc_remove_element(const
McSparseMatrix*matrix,size_t element,PmAllocator*allocator);McSparseMatrix*
mc_clean_sparse_matrix(const McSparseMatrix*in,PmAllocator*allocator);typedef
struct NeslContLtiDataTag NeslContLtiData;struct NeslContLtiDataTag{
PmRealVector*mLtiFlatU;McSparseMatrix mDx;McSparseMatrix mDu;PmRealVector mC0;
boolean_T mEmptyDx;boolean_T mEmptyDu;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_inline.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeslSimulationDataTag NeslSimulationData;typedef struct
NeslSimulationDataDataTag NeslSimulationDataData;struct NeslSimulationDataTag{
PmRealVector*(*mTime)(const NeslSimulationData*);PmRealVector*(*mContStates)(
const NeslSimulationData*);PmIntVector*(*mModeVector)(const NeslSimulationData
*);PmRealVector*(*mDiscStates)(const NeslSimulationData*);PmIntVector*(*
mSampleHits)(const NeslSimulationData*);PmRealVector*(*mOutputs)(const
NeslSimulationData*);PmRealVector*(*mDx)(const NeslSimulationData*);
PmRealVector*(*mNonSampledZCs)(const NeslSimulationData*);PmRealVector*(*
mResiduals)(const NeslSimulationData*);PmRealVector*(*mTolerances)(const
NeslSimulationData*);PmSparsityPattern*(*mM_P)(const NeslSimulationData*);
PmRealVector*(*mMassMatrixPr)(const NeslSimulationData*);PmSparsityPattern*(*
mLinJacobianPattern)(const NeslSimulationData*);PmRealVector*(*mLinJacobian)(
const NeslSimulationData*);PmSparsityPattern*(*mSolJacobianPattern)(const
NeslSimulationData*);PmRealVector*(*mSolJacobianPr)(const NeslSimulationData*)
;PmRealVector*(*mNumjacDxLo)(const NeslSimulationData*);PmRealVector*(*
mNumjacDxHi)(const NeslSimulationData*);PmRealVector*(*mInputValues)(const
NeslSimulationData*);PmIntVector*(*mInputOffsets)(const NeslSimulationData*);
boolean_T*(*mFoundZcEvents)(const NeslSimulationData*);boolean_T*(*mHadEvents)
(const NeslSimulationData*);boolean_T*(*mIsMajorTimeStep)(const
NeslSimulationData*);boolean_T*(*mIsSolverAssertCheck)(const NeslSimulationData
*);boolean_T*(*mIsSolverCheckingCIC)(const NeslSimulationData*);boolean_T*(*
mIsComputingJacobian)(const NeslSimulationData*);boolean_T*(*mIsEvaluatingF0)(
const NeslSimulationData*);boolean_T*(*mIsSolverRequestingReset)(const
NeslSimulationData*);boolean_T*(*mIsFundamentalSampleHit)(const
NeslSimulationData*);boolean_T*(*mIsModeUpdateTimeStep)(const
NeslSimulationData*);boolean_T*(*mCstateHasChanged)(const NeslSimulationData*)
;boolean_T*(*mDstateHasChanged)(const NeslSimulationData*);void(*mDestroy)(
NeslSimulationData*);NeslSimulationDataData*mData;};PMF_DEPLOY_STATIC
PmRealVector nesl_get_time(const NeslSimulationData*sd){return*(sd->mTime(sd))
;}PMF_DEPLOY_STATIC PmRealVector nesl_get_cont_states(const NeslSimulationData
*sd){return*(sd->mContStates(sd));}PMF_DEPLOY_STATIC PmIntVector
nesl_get_mode_vector(const NeslSimulationData*sd){return*(sd->mModeVector(sd))
;}PMF_DEPLOY_STATIC PmRealVector nesl_get_disc_states(const NeslSimulationData
*sd){return*(sd->mDiscStates(sd));}PMF_DEPLOY_STATIC PmIntVector
nesl_get_sample_hits(const NeslSimulationData*sd){return*(sd->mSampleHits(sd))
;}PMF_DEPLOY_STATIC PmRealVector nesl_get_outputs(const NeslSimulationData*sd)
{return*(sd->mOutputs(sd));}PMF_DEPLOY_STATIC PmRealVector nesl_get_dx(const
NeslSimulationData*sd){return*(sd->mDx(sd));}PMF_DEPLOY_STATIC PmRealVector
nesl_get_nonsampled_zcs(const NeslSimulationData*sd){return*(sd->
mNonSampledZCs(sd));}PMF_DEPLOY_STATIC PmRealVector nesl_get_residuals(const
NeslSimulationData*sd){return*(sd->mResiduals(sd));}PMF_DEPLOY_STATIC
PmRealVector nesl_get_tolerances(const NeslSimulationData*sd){return*(sd->
mTolerances(sd));}PMF_DEPLOY_STATIC PmSparsityPattern
nesl_get_mass_matrix_pattern(const NeslSimulationData*sd){return*(sd->mM_P(sd)
);}PMF_DEPLOY_STATIC PmRealVector nesl_get_mass_matrix_pr(const
NeslSimulationData*sd){return*(sd->mMassMatrixPr(sd));}PMF_DEPLOY_STATIC
PmSparsityPattern nesl_get_lin_jacobian_pattern(const NeslSimulationData*sd){
return*(sd->mLinJacobianPattern(sd));}PMF_DEPLOY_STATIC PmRealVector
nesl_get_lin_jacobian(const NeslSimulationData*sd){return*(sd->mLinJacobian(sd
));}PMF_DEPLOY_STATIC PmSparsityPattern nesl_get_sol_jacobian_pattern(const
NeslSimulationData*sd){return*(sd->mSolJacobianPattern(sd));}PMF_DEPLOY_STATIC
PmRealVector nesl_get_sol_jacobian_pr(const NeslSimulationData*sd){return*(sd
->mSolJacobianPr(sd));}PMF_DEPLOY_STATIC PmRealVector nesl_get_numjac_dx_lo(
const NeslSimulationData*sd){return*(sd->mNumjacDxLo(sd));}PMF_DEPLOY_STATIC
PmRealVector nesl_get_numjac_dx_hi(const NeslSimulationData*sd){return*(sd->
mNumjacDxHi(sd));}PMF_DEPLOY_STATIC PmRealVector nesl_get_input_values(const
NeslSimulationData*sd){return*(sd->mInputValues(sd));}PMF_DEPLOY_STATIC
PmIntVector nesl_get_input_offsets(const NeslSimulationData*sd){return*(sd->
mInputOffsets(sd));}PMF_DEPLOY_STATIC boolean_T nesl_found_zcs(const
NeslSimulationData*sd){return*(sd->mFoundZcEvents(sd));}PMF_DEPLOY_STATIC
boolean_T nesl_had_events(const NeslSimulationData*sd){return*(sd->mHadEvents(
sd));}PMF_DEPLOY_STATIC boolean_T nesl_is_major_time_step(const
NeslSimulationData*sd){return*(sd->mIsMajorTimeStep(sd));}PMF_DEPLOY_STATIC
boolean_T nesl_is_solver_assert_check(const NeslSimulationData*sd){return*(sd
->mIsSolverAssertCheck(sd));}PMF_DEPLOY_STATIC boolean_T
nesl_is_solver_checking_cic(const NeslSimulationData*sd){return*(sd->
mIsSolverCheckingCIC(sd));}PMF_DEPLOY_STATIC boolean_T
nesl_is_computing_jacobian(const NeslSimulationData*sd){return*(sd->
mIsComputingJacobian(sd));}PMF_DEPLOY_STATIC boolean_T nesl_is_evaluating_f0(
const NeslSimulationData*sd){return*(sd->mIsEvaluatingF0(sd));}
PMF_DEPLOY_STATIC boolean_T nesl_is_solver_requesting_reset(const
NeslSimulationData*sd){return*(sd->mIsSolverRequestingReset(sd));}
PMF_DEPLOY_STATIC boolean_T nesl_is_fundamental_sample_hit(const
NeslSimulationData*sd){return*(sd->mIsFundamentalSampleHit(sd));}
PMF_DEPLOY_STATIC boolean_T nesl_is_mode_update_time_step(const
NeslSimulationData*sd){return*(sd->mIsModeUpdateTimeStep(sd));}
PMF_DEPLOY_STATIC void nesl_set_cstate_has_changed(const NeslSimulationData*sd
,boolean_T value){*(sd->mCstateHasChanged(sd))=value;}PMF_DEPLOY_STATIC
boolean_T nesl_get_cstate_has_changed(const NeslSimulationData*sd){return*(sd
->mCstateHasChanged(sd));}PMF_DEPLOY_STATIC void nesl_set_dstate_has_changed(
const NeslSimulationData*sd,boolean_T value){*(sd->mDstateHasChanged(sd))=
value;}PMF_DEPLOY_STATIC boolean_T nesl_get_dstate_has_changed(const
NeslSimulationData*sd){return*(sd->mDstateHasChanged(sd));}PMF_DEPLOY_STATIC
boolean_T nesl_has_sample_hits(const NeslSimulationData*sd){size_t i;
PmIntVector sample_hits=nesl_get_sample_hits(sd);for(i=0;i<sample_hits.mN;i++)
{if(sample_hits.mX[i]){return true;}}return false;}typedef struct
NeslSimulationSizesTag{size_t mNumContStates;size_t mNumDiscStates;size_t
mNumModes;size_t mNumOutputs;size_t mNumZCs;size_t mNumRanges;size_t
mNumSamples;size_t mNumMassMatrixNzMax;size_t mNumLinJacobianNzMax;size_t
mNumSolJacobianNzMax;size_t mNumTrimResiduals;boolean_T mDisableProjection;
boolean_T mDefaultLinJacobian;boolean_T mDisableSolJacobian;boolean_T
mIsMConstant;boolean_T mUpdateJacobianAtReset;boolean_T mIsDae;boolean_T
mRegistersStateNames;boolean_T mHasUpdate;const PmIntVector*mNumInputs;const
PmBoolVector*mDirectFeedthrough;}NeslSimulationSizes;typedef struct
NeslStateNameDataTag{size_t mWidth;const char*mStateName;const char*mBlockName
;}NeslStateNameData;typedef struct NeslStateNameVectorTag{NeslStateNameData*
mStateNames;size_t mNumStates;}NeslStateNameVector;typedef enum
NeslSimulatorMethodIdTag{NESL_SIM_INVALID= -1,NESL_SIM_INITIALIZEONCE,
NESL_SIM_INITSYSTEMMATRICES,NESL_SIM_OUTPUTS,NESL_SIM_UPDATE,
NESL_SIM_PROJECTION,NESL_SIM_MASSMATRIX,NESL_SIM_DERIVATIVES,
NESL_SIM_FORCINGFUNCTION,NESL_SIM_ZEROCROSSINGS,NESL_SIM_LINJACOBIAN,
NESL_SIM_LINJACOBIAN_DSS,NESL_SIM_SOLJACOBIAN,NESL_SIM_LINJACOBIANIRJC,
NESL_SIM_LINJACOBIANIRJC_DSS,NESL_SIM_SOLJACOBIANIRJC,NESL_SIM_RESIDUALS,
NESL_SIM_TOLERANCES,NESL_SIM_REINIT,NESL_SIM_NUMJAC_DX_BOUNDS,
NESL_SIM_PUSHINFO,NESL_NUM_SIMULATOR_METHODS}NeslSimulatorMethodId;typedef
struct NeslSimulatorTag NeslSimulator;typedef struct NeslSimulatorUserDataTag
NeslSimulatorUserData;typedef enum NeslSimulatorStatusTag{NESL_SIM_ERROR= -1,
NESL_SIM_OK}NeslSimulatorStatus;typedef NeslSimulatorStatus(*
NeslSimulatorMethod)(const NeslSimulator*,const NeslSimulationData*,
NeuDiagnosticManager*);typedef void(*NeslSimulatorInitializeStartStatus)(void*
);typedef void(*NeslSimulatorInitializeEndStatus)(void*);struct
NeslSimulatorTag{NeslSimulatorUserData*mUserData;NeslSimulatorMethod mMethods[
NESL_NUM_SIMULATOR_METHODS];NeslSimulationSizes(*mSizes)(const NeslSimulator*s
);void(*mStateNames)(const NeslSimulator*s,const NeslStateNameVector*snv);void
(*mSampleTimes)(const NeslSimulator*s,PmRealVector*periods,PmRealVector*
offsets);NeslSimulatorStatus(*mInitialize)(const NeslSimulator*s,const
NeModelParameters*mp,NeuDiagnosticManager*mgr,
NeslSimulatorInitializeStartStatus start,NeslSimulatorInitializeEndStatus end,
void*rb);const NeslContLtiData*(*mGetContLtiData)(const NeslSimulator*s);const
SLMatrices**(*mGetSLMatrices)(const NeslSimulator*s);NeslSimulatorStatus(*
mGetStiffness)(const NeslSimulator*s,const NeslSimulationData*sim_data,void*st
,NeuDiagnosticManager*);NeStiffness*mStiffness;void(*mLogIterations)(const
NeslSimulator*s,const NeslSimulationData*sim_data,IterationsLogCore*il);
NeslSimulatorStatus(*mGetMaxFreq)(const NeslSimulator*simulator_ptr,double*out
);void(*mDestroy)(NeslSimulator*);NeCustomData*(*mGetCustomData)(const
NeslSimulator*);NeslSimulatorStatus(*mSetCustomData)(const NeCustomData*,const
NeslSimulator*,NeuDiagnosticManager*);const NeZCData*mZCData;const NeRange*
mRanges;NeParameterInfo mParameterInfo;void(*mSetParameters)(const
NeslSimulator*,const NeParameterBundle*);};PMF_DEPLOY_STATIC
NeslSimulatorStatus ne_simulator_method(const NeslSimulator*simulator_ptr,
NeslSimulatorMethodId method_id,const NeslSimulationData*sim_data,
NeuDiagnosticManager*mgr){return simulator_ptr->mMethods[method_id](
simulator_ptr,sim_data,mgr);}typedef enum NeslSimulatorCategoryTag{
NESL_SIMULATOR_CATEGORY_INVALID= -1,NESL_SIMULATOR_CATEGORY_STATE,
NESL_SIMULATOR_CATEGORY_OUTPUT,NESL_SIMULATOR_CATEGORY_NUM}
NeslSimulatorCategory;typedef struct NeslSimulatorGroupTag NeslSimulatorGroup;
typedef struct NeslSimulatorGroupDataTag NeslSimulatorGroupData;struct
NeslSimulatorGroupTag{const NeslSimulator*(*mSimulator)(const
NeslSimulatorGroup*g,NeslSimulatorCategory c,size_t i);const NeslRtpManager*(*
mRtpManager)(const NeslSimulatorGroup*g,size_t i);const SscRTWLogFcnManager*(*
mRtwLogFcnManager)(const NeslSimulatorGroup*g,size_t i);const
NeslSolverHitManager*(*mSolverHitManager)(const NeslSimulatorGroup*g,size_t i)
;NeslSimulatorGroup*(*mClone)(const NeslSimulatorGroup*g);void(*mGetReference)
(NeslSimulatorGroup*g);void(*mReleaseReference)(NeslSimulatorGroup*g);const
NeProfiler*mProfiler;NeslSimulatorGroupData*mData;size_t mNumSimulators[
NESL_SIMULATOR_CATEGORY_NUM];size_t mNumRtpManagers;size_t
mNumRtwLogFcnManagers;size_t mNumSolverHitManagers;};PmfMessageId
nesl_register_simulator_group(const char*key,const size_t numDae,NeDae*const*
dae,const NeSolverParameters*sp,const NeModelParameters*mp,const size_t
numOutputs,const NeOutputParameters*op,const size_t numRtpDaes,const int*
rtpDaes,const size_t numRtwLoggingDaes,const int*rtwLoggingDaes,const size_t
numSolverHitDaes,const int*solverhitDaes);typedef struct
NeslSimulatorGroupRegistryTag NeslSimulatorGroupRegistry;typedef struct
NeslSimulatorGroupRegistryDataTag NeslSimulatorGroupRegistryData;struct
NeslSimulatorGroupRegistryTag{void(*mInsert)(const NeslSimulatorGroupRegistry*
registry,const char*key,NeslSimulatorGroup*group);void(*mErase)(const
NeslSimulatorGroupRegistry*registry,const char*key);void(*mEraseModel)(const
NeslSimulatorGroupRegistry*registry,const char*model);NeslSimulatorGroup*(*
mLookup)(const NeslSimulatorGroupRegistry*registry,const char*key);const
NeslSimulator*(*mLeaseSimulator)(const NeslSimulatorGroupRegistry*registry,
const char*key,NeslSimulatorCategory cat,size_t idx);const NeslRtpManager*(*
mLeaseRtpManager)(const NeslSimulatorGroupRegistry*registry,const char*key,
size_t idx);const SscRTWLogFcnManager*(*mLeaseRtwLogFcnManager)(const
NeslSimulatorGroupRegistry*registry,const char*key,size_t idx);const
NeslSolverHitManager*(*mLeaseSolverHitManager)(const NeslSimulatorGroupRegistry
*registry,const char*key,size_t idx);boolean_T(*mHasBeenCloned)(const
NeslSimulatorGroupRegistry*registry,const char*key);void(*mClear)(const
NeslSimulatorGroupRegistry*registry);void(*mDestroy)(
NeslSimulatorGroupRegistry*registry);NeslSimulatorGroupRegistryData*mData;};
const NeslSimulatorGroupRegistry*nesl_get_registry(void);void
nesl_destroy_current_registry(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
struct LtiIcDataTag{PmSparsityPattern mStatesPattern;PmRealVector mStatesPr;
PmSparsityPattern mInputsPattern;PmRealVector mInputsPr;PmRealVector mConsts;}
;typedef struct LtiIcDataTag LtiIcData;struct LtiDcDataTag{PmSparsityPattern
mAPattern;PmRealVector mAPr;PmSparsityPattern mBPattern;PmRealVector mBPr;
PmRealVector mFa;};typedef struct LtiDcDataTag LtiDcData;struct LtiIcParamsTag
{LtiIcData mFirstSolve,mSecondSolve;LtiDcData mDcSolve;PmRealVector mGuess;
real_T mResTol;boolean_T mDoDC;};typedef struct LtiIcParamsTag LtiIcParams;
typedef void(*LtiDiagnosisMethod)(void*,PmCharVector);typedef struct
LtiSupportMethodsTag{void*mLtiDiagnosisData;LtiDiagnosisMethod
mIcDiagnosisMethod;LtiDiagnosisMethod mDcDiagnosisMethod;}LtiSupportMethods;
boolean_T ic_solve_impl(PmRealVector*x,const PmRealVector*u,const LtiIcParams*
ltiIcParams,const LtiSupportMethods*methods,NeuDiagnosticManager*mgr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
struct LtiRtwLogDataTag{PmSparsityPattern mCPattern;PmRealVector mCPr;
PmSparsityPattern mDPattern;PmRealVector mDPr;PmRealVector mYa;};typedef struct
LtiRtwLogDataTag LtiRtwLogData;struct LtiRtwLogParamsTag{LtiRtwLogData mLogData
;};typedef struct LtiRtwLogParamsTag LtiRtwLogParams;void rtw_log_obs_solve(
const LtiRtwLogParams*ltiLogParams,const NeDynamicSystemInput*input,
PmRealVector*output,NeuDiagnosticManager*mgr);SscRTWLogFcnManager*
ssc_lti_create_rtw_log_fcn_manager(const LtiRtwLogParams*logParams,real_T
startTime,unsigned int numInputs,unsigned int numStates,unsigned int
inputPortWidth,unsigned int bufferWidth,NeuDiagnosticManager*diagMgr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "pm_std.h"
#include "mc_std.h"
#include "mc_std_fwd.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "pm_std.h"
#include "pm_std.h"
#include "mc_std_fwd.h"
#include "ne_std_fwd.h"
#include "ne_std_fwd.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "ne_initer_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct SscIniterDataTag SscIniterData;typedef struct
SscComputeSimDataTag SscComputeSimData;typedef struct SscComputeSimTag
SscComputeSim;struct SscComputeSimTag{SscComputeSimData*mData;void(*
mComputeSim)(const SscComputeSim*cs,const NeSystemInput*simSI,const
NeRealFunctor*obsIniter,const NeSystemInput*initerSI);void(*mDestroy)(
SscComputeSim*cs);};struct SscComputeStateTag{SscComputeSimData*mData;void(*
mComputeState)(const SscComputeState*cs,const NeSystemInput*initerSI,const
NeSystemInput*simSI);void(*mDestroy)(SscComputeState*cs);};struct SscIniterTag
{PmfMessageId(*mSolve)(const SscIniter*initer,const SscComputeSim*cs,const
NeSystemInput*simSI,NeuDiagnosticManager*mgr);void(*mSetParameters)(const
SscIniter*initer,const NeParameterBundle*bundle);void(*mGenerate)(const
SscIniter*initer,const NeCgParams*cgParams,NeCgResults*cgResults);void(*
mSetDiagPtr)(const SscIniter*initer,void*st);const NeObservableData*
mObservableData;size_t mNumObservables;SscIniter*(*mCloneFcn)(const SscIniter*
initer);void(*mDestroy)(SscIniter*initer);size_t mRefCount;SscIniterData*mData
;};PMF_DEPLOY_STATIC void ssc_initer_get_reference(SscIniter*initer){if(initer
){++(initer->mRefCount);}}PMF_DEPLOY_STATIC void ssc_initer_release_reference(
SscIniter*initer){if(initer){(void)0;;if(--(initer->mRefCount)==0){initer->
mDestroy(initer);}}}
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_stiffness_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeStiffnessDataTag NeStiffnessData;struct NeStiffnessTag{
NeStiffnessData*mData;void(*mSetTimes)(NeStiffness*s,const PmRealVector*ts);
PmRealVector*(*mGetTimes)(NeStiffness*s);void(*mStart)(NeStiffness*s);void(*
mSetState)(NeStiffness*s,NeSystemInput*input);size_t(*mGetNumStates)(
NeStiffness*s);PmfMessageId(*mComputeStiffness)(NeStiffness*s,void*stiff,
size_t k,NeuDiagnosticManager*mgr);void(*mDestroy)(NeStiffness*s);};
NeStiffness*stiffness_create(NeDae*dae,SscComputeState*cs,NeSystemInputSizes*
sizes);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct _McNDTree{int32_T st,sz,id;struct _McNDTree*lt,*rt;}McNDTree;
typedef struct _McNDPermData{McNDTree*mNd;PmIntVector*mP;PmIntVector*mQ;}
McNDPermData;typedef struct _McNDPermDataFlat{size_t m,n;int32_T*st,*sz,*lt,*
rt;int32_T*p,*q;}McNDPermDataFlat;PmIntVector*mc_basker_column_permute(const
McNDTree*bt,const PmSparsityPattern*pat,PmAllocator*alloc);void
mc_basker_tree_free(McNDTree*nd);McNDTree*mc_basker_tree_copy(McNDTree*nd);
void mc_basker_tree_shift(McNDTree*nd,int32_T st);int32_T mc_basker_tree_level
(McNDTree*bt);void mc_free_perm_data(McNDPermData*pd);McNDPermDataFlat*
mc_perm_data_to_flat(const McNDPermData*pd);McNDPermData*
mc_perm_data_from_flat(const McNDPermDataFlat*pdf);void mc_free_perm_data_flat
(McNDPermDataFlat*pdf);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_initer_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef enum{INVALID_CARDINALITY= -1,SWL_FINITE,SWL_COUNTABLE,SWL_UNCOUNTABLE,
SWL_NONLINEAR,NUM_CARDINALITY}ModeCardinality;typedef struct
GlobalMethodTableTag GlobalMethodTable;typedef union GmtMethodOutputTag{
PmIntVector mMODE;PmRealVector mY;PmRealVector mOBS;PmIntVector mASSERT;
PmIntVector mIASSERT;PmRealVector mINIT_R;PmIntVector mINIT_I;PmRealVector
mCACHE_R;PmIntVector mCACHE_I;PmRealVector mUPDATE_R;PmIntVector mUPDATE_I;
PmBoolVector mLOCK_R;PmBoolVector mLOCK_I;PmRealVector mUPDATE2_R;PmIntVector
mUPDATE2_I;PmBoolVector mLOCK2_R;PmBoolVector mLOCK2_I;PmIntVector mDP_L;
PmIntVector mDP_I;PmIntVector mDP_J;PmRealVector mDP_R;PmRealVector mINIT_DIFF
;PmRealVector mLOG;}GmtMethodOutput;typedef enum GmtMethodIdTag{
GMT_INVALID_METHOD_ID= -1,GMT_METHOD_MODE,GMT_METHOD_Y,GMT_METHOD_OBS,
GMT_METHOD_ASSERT,GMT_METHOD_IASSERT,GMT_METHOD_INIT_R,GMT_METHOD_INIT_I,
GMT_METHOD_CACHE_R,GMT_METHOD_CACHE_I,GMT_METHOD_UPDATE_R,GMT_METHOD_UPDATE_I,
GMT_METHOD_LOCK_R,GMT_METHOD_LOCK_I,GMT_METHOD_UPDATE2_R,GMT_METHOD_UPDATE2_I,
GMT_METHOD_LOCK2_R,GMT_METHOD_LOCK2_I,GMT_METHOD_DP_L,GMT_METHOD_DP_I,
GMT_METHOD_DP_J,GMT_METHOD_DP_R,GMT_METHOD_INIT_DIFF,GMT_METHOD_LOG,
GMT_NUM_METHODS}GmtMethodId;typedef int32_T(*GmtMethod)(const GlobalMethodTable
*,const NeDynamicSystemInput*,GmtMethodOutput*);struct GlobalMethodTableTag{
GmtMethod mMethods[GMT_NUM_METHODS];size_t mNumY;size_t mNumObsElts;size_t
mNumAsserts;const NeAssertData*mAssertData;size_t mNumAssertRanges;const
NeRange*mAssertRanges;size_t mNumInitialAsserts;const NeAssertData*
mInitialAssertData;size_t mNumInitialAssertRanges;const NeRange*
mInitialAssertRanges;NeParameterInfo mParameterInfo;PmIntVector*mModeIndices;
PmIntVector*mObsIsLinear;};typedef struct SwitchedLinearClumpTag
SwitchedLinearClump;typedef union SlcMethodOutputTag{PmSparsityPattern mM_P;
PmRealVector mM;PmSparsityPattern mJ_P;PmRealVector mJ;PmRealVector mFX;
PmRealVector mF;PmRealVector mXNPLUS1;PmIntVector mMODE;}SlcMethodOutput;
typedef enum SlcMethodIdTag{SLC_INVALID_METHOD_ID= -1,SLC_METHOD_M_P,
SLC_METHOD_M,SLC_METHOD_J_P,SLC_METHOD_J,SLC_METHOD_FX,SLC_METHOD_F,
SLC_METHOD_XNPLUS1,SLC_METHOD_MODE,SLC_NUM_METHODS}SlcMethodId;typedef int32_T
(*SlcMethod)(const SwitchedLinearClump*,const NeDynamicSystemInput*,
SlcMethodOutput*);typedef PmSizeVector*SizeVectorPtr;struct
SwitchedLinearClumpTag{SlcMethod mMethods[SLC_NUM_METHODS];size_t mMNnz;size_t
mJNnz;size_t mNEqs;boolean_T mIsLti;NeDynamicSystemInputSizes mSizes;
SizeVectorPtr mSelectors[NE_NUM_DYNAMIC_SYSTEM_INPUT_ID];PmIntVector*
mStateIndices;PmIntVector*mStateIndicesOut;PmIntVector*mModeIndices;
PmIntVector*mMRefIndices;PmIntVector*mQRefIndices;boolean_T mIsModeBoolean;
ModeCardinality mModeCardinality;McSparseMatrix*mConstantM;McSparseMatrix*
mConstantJ;};typedef struct DifferentialClumpTag DifferentialClump;typedef
union DcMethodOutputTag{PmSparsityPattern mM_P;PmRealVector mM;PmRealVector mF
;}DcMethodOutput;typedef enum DcMethodIdTag{DC_INVALID_METHOD_ID= -1,
DC_METHOD_M_P,DC_METHOD_M,DC_METHOD_F,DC_NUM_METHODS}DcMethodId;typedef int32_T
(*DcMethod)(const DifferentialClump*,const NeDynamicSystemInput*,
DcMethodOutput*);struct DifferentialClumpTag{DcMethod mMethods[DC_NUM_METHODS]
;size_t mMNnz;PmIntVector*mStateIndices;PmIntVector*mMRefIndices;PmIntVector*
mQRefIndices;ModeCardinality mModeCardinality;};typedef struct
SwitchedLinearSystemTag SwitchedLinearSystem;struct SwitchedLinearSystemTag{
NeDynamicSystemInputSizes mSizes;PmIntVector*mDiffStateIndices;
GlobalMethodTable*mGlobalMethodTable;size_t mNumClumps;SwitchedLinearClump**
mClumps;DifferentialClump*mDiffClump;SscIniter*mIniter;SscIniter*mDaeIniter;
McNDPermData*(*mGetNDPermData)(const PmSparsityPattern*pat,size_t nLev);void(*
mDestroy)(SwitchedLinearSystem*sls);};typedef struct SimulatorTag Simulator;
typedef struct SimulatorDataTag SimulatorData;typedef void(*
SimulatorInitializeStartStatus)(void*);typedef void(*
SimulatorInitializeEndStatus)(void*);struct SimulatorTag{size_t mNumInputs;
size_t mNumStates;size_t mNumOutputs;double mStepSize;const NeParameterInfo*
mParameterInfo;SimulatorData*mData;const PmSizeVector*mMemEstimates;void(*
mSetReInit)(const Simulator*solver,boolean_T reInit);boolean_T(*mGetReInit)(
const Simulator*solver);boolean_T(*mSetParameters)(const Simulator*solver,
const NeParameterBundle*bundle);boolean_T(*mStart)(const Simulator*solver,
const NeuDiagnosticManager*mgr);NeDynamicSystemInput(*mGetDsi)(const Simulator
*simulator,const PmRealVector*inputs,const PmRealVector*states,real_T time);
void(*mRtwLogFcn)(const Simulator*simulator,const NeDynamicSystemInput*input,
PmRealVector*output);boolean_T(*mSolve)(const Simulator*solver,const
PmRealVector*inputs,const PmRealVector*states,const PmRealVector*outputs,
real_T time,void*st,const NeuDiagnosticManager*mgr,boolean_T firstOutput);
boolean_T(*mCheck)(const Simulator*solver,const PmRealVector*inputs,const
PmRealVector*states,real_T time,const NeuDiagnosticManager*mgr);void(*
mInitialize)(const Simulator*s,SimulatorInitializeStartStatus start,
SimulatorInitializeEndStatus end,void*rb);void(*mPushInfo)(const Simulator*s,
IterationsLogCore*il);const McNDPermData*(*mGetNDPermData)(const Simulator*s);
NeStiffness*(*mGetStiffness)(const Simulator*s);void(*mDestroy)(Simulator*
solver);};Simulator*simulator_create(SwitchedLinearSystem*sls,const
NeSolverParameters param,const McLinearAlgebraFactory*la,const NeVariableData*
vardata,const NeObservableData*obsdata,const size_t numObservables,const
DaemonChoice dc);NeslRtpManager*rtp_manager_create(const Simulator*simulator);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
SscRTWLogFcnManager*ssc_swl_create_rtw_log_fcn_manager(const Simulator*
simulator,unsigned int inputPortWidth,unsigned int bufferWidth,
NeuDiagnosticManager*diagMgr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_initer_fwd.h"
#include "pm_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct LocalDaeMethodTableTag LocalDaeMethodTable;typedef struct
LocalDaeMethodCacheTag LocalDaeMethodCache;typedef enum LocalDaeMethodIdTag{
LOCAL_DAE_INVALID_METHOD_ID= -1,LOCAL_DAE_METHOD_MCON_P,LOCAL_DAE_METHOD_MCON,
LOCAL_DAE_METHOD_MPAR_P,LOCAL_DAE_METHOD_MPAR,LOCAL_DAE_METHOD_MNL_P,
LOCAL_DAE_METHOD_MNL,LOCAL_DAE_METHOD_DXFCON_P,LOCAL_DAE_METHOD_DXFCON,
LOCAL_DAE_METHOD_DXFPAR_P,LOCAL_DAE_METHOD_DXFPAR,LOCAL_DAE_METHOD_DXFNL_P,
LOCAL_DAE_METHOD_DXFNL,LOCAL_DAE_METHOD_DXM,LOCAL_DAE_METHOD_DXM_P,
LOCAL_DAE_METHOD_DDM,LOCAL_DAE_METHOD_DDM_P,LOCAL_DAE_METHOD_F,
LOCAL_DAE_METHOD_CER,LOCAL_DAE_METHOD_DXCER_P,LOCAL_DAE_METHOD_DXCER,
LOCAL_DAE_METHOD_MODE,LOCAL_DAE_METHOD_Y,LOCAL_DAE_METHOD_DUF_P,
LOCAL_DAE_METHOD_DUF,LOCAL_DAE_METHOD_DDF_P,LOCAL_DAE_METHOD_DDF,
LOCAL_DAE_METHOD_DTF_P,LOCAL_DAE_METHOD_DTF,LOCAL_DAE_METHOD_DELAY_V,
LOCAL_DAE_METHOD_DELAY_V0,LOCAL_DAE_METHOD_DELAY_TAU,
LOCAL_DAE_METHOD_DELAY_TAUMAX,LOCAL_DAE_METHOD_DXY_P,LOCAL_DAE_METHOD_DXY,
LOCAL_DAE_METHOD_DUY_P,LOCAL_DAE_METHOD_DUY,LOCAL_DAE_METHOD_OBS,
LOCAL_DAE_METHOD_ASSERT,LOCAL_DAE_METHOD_IASSERT,LOCAL_DAE_METHOD_INIT_R,
LOCAL_DAE_METHOD_INIT_I,LOCAL_DAE_METHOD_CACHE_R,LOCAL_DAE_METHOD_CACHE_I,
LOCAL_DAE_METHOD_UPDATE_R,LOCAL_DAE_METHOD_UPDATE_I,LOCAL_DAE_METHOD_LOCK_R,
LOCAL_DAE_METHOD_LOCK_I,LOCAL_DAE_METHOD_UPDATE2_R,LOCAL_DAE_METHOD_UPDATE2_I,
LOCAL_DAE_METHOD_LOCK2_R,LOCAL_DAE_METHOD_LOCK2_I,LOCAL_DAE_METHOD_IC,
LOCAL_DAE_METHOD_ICR_IM,LOCAL_DAE_METHOD_ICR_IL,LOCAL_DAE_METHOD_DDCER_P,
LOCAL_DAE_METHOD_DDCER,LOCAL_DAE_METHOD_ICR,LOCAL_DAE_METHOD_DXICR_P,
LOCAL_DAE_METHOD_DXICR,LOCAL_DAE_METHOD_DDICR_P,LOCAL_DAE_METHOD_DDICR,
LOCAL_DAE_METHOD_ICRM_P,LOCAL_DAE_METHOD_ICRM,LOCAL_DAE_METHOD_DXICRM_P,
LOCAL_DAE_METHOD_DXICRM,LOCAL_DAE_METHOD_DDICRM_P,LOCAL_DAE_METHOD_DDICRM,
LOCAL_DAE_METHOD_EQ_TOL,LOCAL_DAE_METHOD_DP_L,LOCAL_DAE_METHOD_DP_I,
LOCAL_DAE_METHOD_DP_J,LOCAL_DAE_METHOD_DP_R,LOCAL_DAE_METHOD_IMIN,
LOCAL_DAE_METHOD_IMAX,LOCAL_DAE_METHOD_DIMIN,LOCAL_DAE_METHOD_DIMAX,
LOCAL_DAE_METHOD_VMF,LOCAL_DAE_METHOD_VMM,LOCAL_DAE_METHOD_SLF,
LOCAL_DAE_METHOD_LOG,LOCAL_DAE_NUM_METHODS}LocalDaeMethodId;typedef union
LocalDaeMethodOutputTag{PmSparsityPattern mMCON_P;PmRealVector mMCON;
PmSparsityPattern mMPAR_P;PmRealVector mMPAR;PmSparsityPattern mMNL_P;
PmRealVector mMNL;PmSparsityPattern mDXFCON_P;PmRealVector mDXFCON;
PmSparsityPattern mDXFPAR_P;PmRealVector mDXFPAR;PmSparsityPattern mDXFNL_P;
PmRealVector mDXFNL;PmRealVector mDXM;PmSparsityPattern mDXM_P;PmRealVector
mDDM;PmSparsityPattern mDDM_P;PmRealVector mF;PmRealVector mCER;
PmSparsityPattern mDXCER_P;PmRealVector mDXCER;PmIntVector mMODE;PmRealVector
mY;PmSparsityPattern mDUF_P;PmRealVector mDUF;PmSparsityPattern mDDF_P;
PmRealVector mDDF;PmSparsityPattern mDTF_P;PmRealVector mDTF;PmRealVector
mDELAY_V;PmRealVector mDELAY_V0;PmRealVector mDELAY_TAU;PmRealVector
mDELAY_TAUMAX;PmSparsityPattern mDXY_P;PmRealVector mDXY;PmSparsityPattern
mDUY_P;PmRealVector mDUY;PmRealVector mOBS;PmIntVector mASSERT;PmIntVector
mIASSERT;PmRealVector mINIT_R;PmIntVector mINIT_I;PmRealVector mCACHE_R;
PmIntVector mCACHE_I;PmRealVector mUPDATE_R;PmIntVector mUPDATE_I;PmBoolVector
mLOCK_R;PmBoolVector mLOCK_I;PmRealVector mUPDATE2_R;PmIntVector mUPDATE2_I;
PmBoolVector mLOCK2_R;PmBoolVector mLOCK2_I;PmRealVector mIC;PmIntVector
mICR_IM;PmBoolVector mICR_IL;PmSparsityPattern mDDCER_P;PmRealVector mDDCER;
PmRealVector mICR;PmSparsityPattern mDXICR_P;PmRealVector mDXICR;
PmSparsityPattern mDDICR_P;PmRealVector mDDICR;PmSparsityPattern mICRM_P;
PmRealVector mICRM;PmSparsityPattern mDXICRM_P;PmRealVector mDXICRM;
PmSparsityPattern mDDICRM_P;PmRealVector mDDICRM;PmRealVector mEQ_TOL;
PmIntVector mDP_L;PmIntVector mDP_I;PmIntVector mDP_J;PmRealVector mDP_R;
PmRealVector mIMIN;PmRealVector mIMAX;PmRealVector mDIMIN;PmRealVector mDIMAX;
PmBoolVector mVMF;PmBoolVector mVMM;PmBoolVector mSLF;PmRealVector mLOG;}
LocalDaeMethodOutput;typedef int32_T(*LocalDaeMethod)(LocalDaeMethodTable const
*,NeDynamicSystemInput const*,LocalDaeMethodOutput*);typedef enum
LocalDaeCachedMethodIdTag{LOCAL_DAE_INVALID_CACHED_METHOD_ID= -1,
LOCAL_DAE_CACHED_METHOD_M,LOCAL_DAE_CACHED_METHOD_DXF,
LOCAL_DAE_NUM_CACHED_METHODS}LocalDaeCachedMethodId;struct
LocalDaeMethodCacheTag{PmRealVector*mConPr;PmSparsityPattern*mConPattern;
PmRealVector*mParPr;PmSparsityPattern*mParPattern;PmSparsityPattern*mNlPattern
;};struct LocalDaeMethodTableTag{LocalDaeMethod mMethods[LOCAL_DAE_NUM_METHODS
];LocalDaeMethodCache mMethodsCache[LOCAL_DAE_NUM_CACHED_METHODS];size_t
mMCONNnz;size_t mMPARNnz;size_t mMNLNnz;size_t mDXFCONNnz;size_t mDXFPARNnz;
size_t mDXFNLNnz;size_t mDXCERNnz;size_t mDUFNnz;size_t mDTFNnz;size_t mDXYNnz
;size_t mDUYNnz;size_t mDDFNnz;size_t mDXMNnz;size_t mDDMNnz;size_t mDDCERNnz;
size_t mDXICRNnz;size_t mDDICRNnz;size_t mICRMNnz;size_t mDXICRMNnz;size_t
mDDICRMNnz;size_t mNumDelays;size_t mNumY;size_t mNumEqs;size_t mNumVars;
size_t mNumConstraintEqs;size_t mNumInitialEqs;size_t mNumObsElts;size_t
mNumAsserts;const NeAssertData*mAssertData;size_t mNumAssertRanges;const
NeRange*mAssertRanges;size_t mNumInitialAsserts;const NeAssertData*
mInitialAssertData;size_t mNumInitialAssertRanges;const NeRange*
mInitialAssertRanges;NeParameterInfo mParameterInfo;PmIntVector*mObsIsLinear;
PmIntVector*mIsEqCapped;PmIntVector*mIsEqSlf;PmRealVector*mScalingFactors;
PmSparsityPattern*mScalingPattern;boolean_T mUseFullScaling;PmRealVector*
mDXFNLWorkPr;};typedef struct IRDataTag IRData;typedef struct
LocalDaePrivateDataTag LocalDaePrivateData;typedef struct LocalDaeTag LocalDae
;struct LocalDaeTag{NeDynamicSystemInputSizes mSizes;size_t
mNumDifferentialStates;LocalDaeMethodTable*mMethodTable;IRData*mIRData;
NeDynamicSystemInput*mSiToDsConversionFields;SscIniter*mIniter;SscIniter*
mDaeIniter;void(*mInitialize)(LocalDae const*ld,NeModelParameters const*const
mp,NeSolverParameters const*const sp);int32_T(*mUpdateDelays)(LocalDae const*
ld,NeDynamicSystemInput const*in);void(*mEvaluateDelays)(LocalDae const*ld,
NeDynamicSystemInput const*in);void(*mDestroy)(LocalDae*ld);void(*
mUpdateMethodCache)(LocalDae const*ld,NeDynamicSystemInput const*in);void(*
mComputeScaling)(LocalDae const*ld);LocalDaePrivateData*mData;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct LocalDaeSelectedSystemDataTag LocalDaeSelectedSystemData;struct
LocalDaeSelectedSystemDataTag{NeVariableData*mVariableData;NeVariableData*
mDiscreteData;NeICRData*mICRData;NeCERData*mCERData;size_t mICRSize;size_t
mCERSize;size_t mDiffSize;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
void local_dae_create_method_cache(LocalDaeMethodTable*mt);void
local_dae_update_method_cache(LocalDaeMethodTable const*mt,
NeDynamicSystemInput const*input);void local_dae_set_method_cache(LocalDae*
localDae);void local_dae_destroy_method_cache(LocalDaeMethodCache*mc);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "pm_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef enum NeuDelayedExpressionEvaluationStatusTag{
NEU_DELAYED_EXPRESSION_EVALUATION_INVALID= -2,
NEU_DELAYED_EXPRESSION_LEFT_EXTRAPOLATION,NEU_DELAYED_EXPRESSION_INTERPOLATION
,NEU_DELAYED_EXPRESSION_RIGHT_EXTRAPOLATION}
NeuDelayedExpressionEvaluationStatus;typedef enum NeuDelayExpressionsStatusTag
{NEU_DELAY_EXPRESSIONS_INVALID_STATUS= -1,NEU_DELAY_EXPRESSIONS_OK,
NEU_DELAY_EXPRESSIONS_ERROR,NEU_DELAY_EXPRESSIONS_INSUFFICIENT_INITIAL_MEMORY,
NEU_DELAY_EXPRESSIONS_INSUFFICIENT_REALLOC_MEMORY,
NEU_DELAY_EXPRESSIONS_INCONSISTENT_MODEL_PARAMETERS,
NEU_DELAY_EXPRESSIONS_INVALID_SIMSTATE_DATA}NeuDelayExpressionsStatus;typedef
struct NeuDelayExpressionsPrivateDataTag NeuDelayExpressionsPrivateData;
typedef struct NeuDelayExpressionsDataTag NeuDelayExpressionsData;struct
NeuDelayExpressionsDataTag{boolean_T(*mIsDataCreatedFcn)(const
NeuDelayExpressionsData*);boolean_T(*mIsDataInitializedFcn)(const
NeuDelayExpressionsData*);int32_T(*mDataCreateFcn)(NeuDelayExpressionsData*,
const real_T*);void(*mInitializeFcn)(NeuDelayExpressionsData*,
NeModelParameters);int32_T(*mUpdateFcn)(NeuDelayExpressionsData*,real_T,const
real_T*);void(*mEvaluateFcn)(const NeuDelayExpressionsData*,size_t,real_T,
real_T*,real_T*);void(*mDestroyFcn)(NeuDelayExpressionsData*,PmAllocator*);
NeCustomData*(*mGetCustomDataFcn)(const NeuDelayExpressionsData*);int32_T(*
mSetCustomDataFcn)(NeuDelayExpressionsData*,const NeCustomData*);
NeuDelayExpressionsPrivateData*mData;};NeuDelayExpressionsData*
neu_create_static_delay_expressions_data(size_t num_delays,real_T start_time,
size_t memory_budget,PmAllocator*allocator);NeuDelayExpressionsData*
neu_create_dynamic_delay_expressions_data(size_t num_delays,size_t
memory_budget,size_t block_numel,PmAllocator*allocator);typedef struct
NesDelayExpressionsTag NesDelayExpressions;struct NesDelayExpressionsTag{
real_T mStartTime;PmRealVector*mV0;PmRealVector*mTAU;PmRealVector*mTAUMAX;
PmRealVector*mVDEL;NeuDelayExpressionsData*mData;void(*mDestroyFcn)(
NesDelayExpressions*,PmAllocator*);};NesDelayExpressions*
nes_create_delay_expressions(size_t const numDelays,real_T startTime,
PmAllocator*allocator);void nes_destroy_delay_expressions(NesDelayExpressions*
delayExpr,PmAllocator*allocatorPtr);void nes_initialize_delay_expressions(
NesDelayExpressions*delayExpressions,NeModelParameters mp,NeSolverParameters sp
,boolean_T useStaticDataBuffers,PmAllocator*allocator);int32_T
nes_update_delay_expressions(NesDelayExpressions*delay_expr,real_T t,const
PmRealVector*vdel,const PmRealVector*del_tmax);void
nes_evaluate_delay_expressions(const NesDelayExpressions*delay_expr,real_T t,
const PmRealVector*tau,const PmRealVector*v0,const PmRealVector*vout);void
nes_evaluate_delay_expression_derivative(const NesDelayExpressions*delay_expr,
real_T t,const PmRealVector*tauVect,const PmRealVector*vderVect);NeCustomData*
nes_get_delay_expression_custom_data(const NesDelayExpressions*delay_expr);
int32_T nes_set_delay_expression_custom_data(NesDelayExpressions*delay_expr,
const NeCustomData*data);NesDelayExpressions*local_dae_create_delays(LocalDae
const*ld,NeModelParameters const*const mp);void local_dae_initialize_delays(
LocalDae const*ld,NesDelayExpressions*delay,NeModelParameters const*const mp,
NeSolverParameters const*const sp);int32_T local_dae_update_delays(LocalDae
const*ld,NesDelayExpressions*delay,NeDynamicSystemInput const*in);void
local_dae_evaluate_delays(LocalDae const*ld,NesDelayExpressions const*delay,
NeDynamicSystemInput const*in);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#include "pm_std.h"
#include "mc_std_fwd.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "ne_std.h"
#include "pm_std.h"
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef void(*LocalDaeDiagnosisMethod)(void*,PmCharVector);typedef void(*
LocalDaeEventIterationDiagnosisMethod)(void*,const PmRealVector*,const
PmIntVector*,PmCharVector);typedef struct LocalDaeSupportMethodsTag{void*
mLocalDaeDiagnosisData;LocalDaeDiagnosisMethod mIcDiagnosisMethod;
LocalDaeDiagnosisMethod mDcDiagnosisMethod;LocalDaeDiagnosisMethod
mTrDiagnosisMethod;LocalDaeDiagnosisMethod mIcJacDiagnosisMethod;
LocalDaeDiagnosisMethod mAdvSolDiagnosisMethod;
LocalDaeEventIterationDiagnosisMethod mEventIterationDiagnosisMethod;void(*
mSetSystemInput)(void*,const NeSystemInput*si);}LocalDaeSupportMethods;typedef
struct LocalDaeSimulatorTag LocalDaeSimulator;typedef struct
LocalDaeSimulatorDataTag LocalDaeSimulatorData;typedef void(*
LocalDaeSimulatorInitializeStartStatus)(void*);typedef void(*
LocalDaeSimulatorInitializeEndStatus)(void*);struct LocalDaeSimulatorTag{
size_t mNumInputs;size_t mNumStates;size_t mNumOutputs;size_t mNumVariables;
double mStepSize;NeParameterInfo const*mParameterInfo;LocalDaeSimulatorData*
mData;void(*mSetReInit)(const LocalDaeSimulator*simulator,boolean_T reInit);
boolean_T(*mGetReInit)(const LocalDaeSimulator*simulator);boolean_T(*
mSetParameters)(const LocalDaeSimulator*simulator,const NeParameterBundle*
bundle);boolean_T(*mStart)(const LocalDaeSimulator*simulator,const
NeuDiagnosticManager*mgr);NeDynamicSystemInput(*mGetDsi)(const
LocalDaeSimulator*simulator,const PmRealVector*inputs,const PmRealVector*
input_derivatives,const PmRealVector*states,real_T time);void(*mRtwLogFcn)(
const LocalDaeSimulator*simulator,const NeDynamicSystemInput*input,
PmRealVector*output);boolean_T(*mSolve)(const LocalDaeSimulator*simulator,
const PmRealVector*inputs,const PmRealVector*input_derivatives,const
PmRealVector*states,const PmRealVector*outputs,real_T time,void*st,const
NeuDiagnosticManager*mgr,boolean_T firstOutput,LocalDaeSupportMethods*
supMethods);boolean_T(*mConsistentize)(PmfMessageId*status,const
LocalDaeSimulator*simulator,const NeDynamicSystemInput*dsInput,const
NeuDiagnosticManager*mgr,const LocalDaeSupportMethods*supMethods,const
boolean_T doDiagnosis);boolean_T(*mCheck)(const LocalDaeSimulator*simulator,
const PmRealVector*inputs,const PmRealVector*input_derivatives,const
PmRealVector*states,real_T time,const NeuDiagnosticManager*mgr);void(*
mInitialize)(const LocalDaeSimulator*s,LocalDaeSimulatorInitializeStartStatus
start,LocalDaeSimulatorInitializeEndStatus end,void*rb);void(*mSetDaeIniter)(
const LocalDaeSimulator*simulator,SscIniter*daeiniter);void(*mDestroy)(
LocalDaeSimulator*simulator);};LocalDaeSimulator*local_dae_simulator_create(
LocalDae*dae,NeSolverParameters const sp,NeModelParameters const mp,
McLinearAlgebraFactory const*la,NeVariableData const*VarData,NeVariableData
const*DiscData,NeEquationData const*EquationData,NeRange const*RangeData,
NeICRData const*ICRData,NeCERData const*CERData,size_t const numICResiduals,
size_t const numCEResiduals,size_t const numDiffStates);NeslRtpManager*
local_dae_rtp_manager_create(const LocalDaeSimulator*simulator);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
SscRTWLogFcnManager*create_local_dae_ssc_rtw_log_fcn_manager(const
LocalDaeSimulator*simulator,unsigned int inputPortWidth,unsigned int
bufferWidth,NeuDiagnosticManager*diagMgr);void
local_dae_compute_scaling_factors(LocalDae const*ld);void
local_dae_flag_equations_for_scaling(LocalDae const*ld,PmAllocator*
allocatorPtr);typedef struct NeslInputHelperVectorsTag NeslInputHelperVectors;
struct NeslInputHelperVectorsTag{PmRealVector*mTimeVector;PmRealVector*
mInputValuesVector;PmIntVector*mInputOffsetsVector;void(*mDestroy)(
NeslInputHelperVectors*helper);};typedef struct NeslInputHelperTag
NeslInputHelper;typedef struct NeslInputHelperDataTag NeslInputHelperData;
struct NeslInputHelperTag{NeslInputHelperVectors*(*mCreateVectors)(const
NeslInputHelper*helper,size_t inputPortWidth);void(*mUpdate)(const
NeslInputHelper*helper,const NeslInputHelperVectors*vectors);void(*mDestroy)(
NeslInputHelper*helper);const NeSystemInput*mI;NeslInputHelperData*mData;};
NeslInputHelper*nesl_create_input_helper(NeSystemInputSizes sizes,boolean_T
overlap);struct SscRTWLogFcnManagerObjectTag{NeDae*mDaePtr;PmAllocator*
mAllocatorPtr;boolean_T*mDirectFeedThrough;unsigned int mNumInputPorts;
unsigned int mInputPortWidth;unsigned int mBufferWidth;NeslInputHelperVectors*
mInputHelperVectors;NeslInputHelper*mInputHelper;NeuDiagnosticManager*
mDiagnosticManager;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ___nesl_rtw_h__ */
