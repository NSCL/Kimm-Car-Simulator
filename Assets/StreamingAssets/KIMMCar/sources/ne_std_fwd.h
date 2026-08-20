#ifndef __ne_std_fwd_h__
#define __ne_std_fwd_h__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeCgParamsTag NeCgParams;typedef struct NeCgResultsTag
NeCgResults;typedef struct NeuDiagnosticTreeTag NeuDiagnosticTree;typedef
struct NeuDiagnosticManagerTag NeuDiagnosticManager;typedef enum{
NEU_DIAGNOSTIC_LEVEL_INVALID= -1,NEU_DIAGNOSTIC_LEVEL_TERSE,
NEU_DIAGNOSTIC_LEVEL_VERBOSE,NEU_NUM_DIAGNOSTIC_LEVELS}NeuDiagnosticLevel;
typedef struct NeProfilerTag NeProfiler;typedef struct NeModelParametersTag
NeModelParameters;typedef struct NeSolverParametersTag NeSolverParameters;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __ne_std_fwd_h__ */
