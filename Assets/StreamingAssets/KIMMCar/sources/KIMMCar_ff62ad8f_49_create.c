#include "KIMMCar_macros.h"
/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'KIMMCar/Vehicle/World/Solver Configuration1'.
 */

#include "pm_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "pm_default_allocator.h"
#include "sm_ssci_NeDaePrivateData.h"
#include "sm_CTarget.h"
#define NULL_INDEX                     ((size_t) -1)

PmfMessageId sm_ssci_recordRunTimeError(
  const char *errorId, const char *errorMsg, NeuDiagnosticManager* mgr);

#define pm_allocator_alloc(_allocator, _m, _n) ((_allocator)->mCallocFcn((_allocator), (_m), (_n)))
#define PM_ALLOCATE_ARRAY(_name, _type, _size, _allocator)\
 _name = (_type *) pm_allocator_alloc(_allocator, sizeof(_type), _size)
#define pm_size_to_int(_size)          ((int32_T) (_size))

extern const NeAssertData KIMMCar_ff62ad8f_49_assertData[];
extern const NeZCData KIMMCar_ff62ad8f_49_ZCData[];
void KIMMCar_ff62ad8f_49_computeRuntimeParameters(
  const double *runtimeRootVariables,
  double *runtimeParameters);
void KIMMCar_ff62ad8f_49_validateRuntimeParameters(
  const double *runtimeParameters,
  int32_T *assertSatisfactionFlags);
void KIMMCar_ff62ad8f_49_computeAsmRuntimeDerivedValues(
  const double *runtimeParameters,
  RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle);
void KIMMCar_ff62ad8f_49_computeSimRuntimeDerivedValues(
  const double *runtimeParameters,
  RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle);
void KIMMCar_ff62ad8f_49_initializeGeometries(
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle);
PmfMessageId KIMMCar_ff62ad8f_49_compDerivs(
  const RuntimeDerivedValuesBundle *,
  const int *,
  const double *,
  const int *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_numJacPerturbLoBounds(
  const RuntimeDerivedValuesBundle *,
  const int *,
  const double *,
  const int *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_numJacPerturbHiBounds(
  const RuntimeDerivedValuesBundle *,
  const int *,
  const double *,
  const int *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_checkDynamics(
  const RuntimeDerivedValuesBundle *,
  const double *,
  const double *, const double *, const double *,
  const double *,
  const int *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_compOutputsDyn(
  const RuntimeDerivedValuesBundle *,
  const int *,
  const double *,
  const int *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  int *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_compOutputsKin(
  const RuntimeDerivedValuesBundle *,
  const double *,
  const int *,
  const double *, const double *, const double *,
  const double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_compOutputs (
  const RuntimeDerivedValuesBundle *,
  const int *,
  const double *,
  const int *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  int *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_computeAsmModeVector(
  const double *, const double *, const double *,
  int *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_computeSimModeVector(
  const double *, const double *, const double *,
  int *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_computeZeroCrossings(
  const RuntimeDerivedValuesBundle *,
  const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId KIMMCar_ff62ad8f_49_recordLog(
  const RuntimeDerivedValuesBundle *,
  const int *,
  const double *,
  const int *,
  const double *, const double *, const double *,
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
void KIMMCar_ff62ad8f_49_setTargets(
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  CTarget *targets);
void KIMMCar_ff62ad8f_49_resetAsmStateVector(const void *mech, double
  *stateVector);
void KIMMCar_ff62ad8f_49_resetSimStateVector(const void *mech, double
  *stateVector);
void KIMMCar_ff62ad8f_49_initializeTrackedAngleState(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const int *modeVector,
  const double *motionData,
  double *stateVector);
void KIMMCar_ff62ad8f_49_computeDiscreteState(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const int *modeVector,
  double *stateVector);
void KIMMCar_ff62ad8f_49_adjustPosition(
  const void *mech,
  const double *dofDeltas,
  double *stateVector);
void KIMMCar_ff62ad8f_49_perturbAsmJointPrimitiveState(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  double magnitude,
  boolean_T doPerturbVelocity,
  double *stateVector);
void KIMMCar_ff62ad8f_49_perturbSimJointPrimitiveState(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  double magnitude,
  boolean_T doPerturbVelocity,
  double *stateVector);
void KIMMCar_ff62ad8f_49_perturbFlexibleBodyState(
  const void *mech,
  size_t stageIdx,
  double magnitude,
  boolean_T doPerturbVelocity,
  double *stateVector);
void KIMMCar_ff62ad8f_49_computePosDofBlendMatrix(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  const double *stateVector,
  int partialType,
  double *matrix);
void KIMMCar_ff62ad8f_49_computeVelDofBlendMatrix(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  const double *stateVector,
  int partialType,
  double *matrix);
void KIMMCar_ff62ad8f_49_projectPartiallyTargetedPos(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  const double *origStateVector,
  int partialType,
  double *stateVector);
void KIMMCar_ff62ad8f_49_propagateMotion(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const double *stateVector,
  double *motionData);
size_t KIMMCar_ff62ad8f_49_computeAssemblyPosError(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  size_t constraintIdx,
  const int *modeVector,
  const double *motionData,
  double *error);
size_t KIMMCar_ff62ad8f_49_computeAssemblyJacobian(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  size_t constraintIdx,
  boolean_T forVelocitySatisfaction,
  const double *stateVector,
  const int *modeVector,
  const double *motionData,
  double *J);
size_t KIMMCar_ff62ad8f_49_computeFullAssemblyJacobian(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const double *stateVector,
  const int *modeVector,
  const double *motionData,
  double *J);
boolean_T KIMMCar_ff62ad8f_49_isInKinematicSingularity(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  size_t constraintIdx,
  const int *modeVector,
  const double *motionData);
void KIMMCar_ff62ad8f_49_convertStateVector(
  const void *asmMech,
  const RuntimeDerivedValuesBundle *asmRuntimeDerivedValuesBundle,
  const void *simMech,
  const double *asmStateVector,
  const int *asmModeVector,
  const int *simModeVector,
  double *simStateVector);
void KIMMCar_ff62ad8f_49_constructStateVector(
  const void *mech,
  const double *solverStateVector,
  const double *u,
  const double *uDot,
  const double *discreteStateVector,
  double *fullStateVector);
void KIMMCar_ff62ad8f_49_extractSolverStateVector(
  const void *mech,
  const double *fullStateVector,
  double *solverStateVector);
void KIMMCar_ff62ad8f_49_extractDiscreteStateVector(
  const void *mech,
  const double *fullStateVector,
  double *discreteStateVector);
boolean_T KIMMCar_ff62ad8f_49_isPositionViolation(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const int *constraintEqnEnableFlags,
  const double *stateVector,
  const int *modeVector);
boolean_T KIMMCar_ff62ad8f_49_isVelocityViolation(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const int *constraintEqnEnableFlags,
  const double *stateVector,
  const int *modeVector);
PmfMessageId KIMMCar_ff62ad8f_49_projectStateSim(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const int *constraintEqnEnableFlags,
  const int *modeVector,
  double *stateVector,
  void *neDiagMgr);
void KIMMCar_ff62ad8f_49_computeConstraintError(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const double *stateVector,
  const int *modeVector,
  double *error);
void KIMMCar_ff62ad8f_49_resetModeVector(const void *mech, int *modeVector);
boolean_T KIMMCar_ff62ad8f_49_hasJointUpwardModeChange(
  const void *mech,
  const int *prevModeVector,
  const int *modeVector);
PmfMessageId KIMMCar_ff62ad8f_49_performJointUpwardModeChange(
  const void *mech,
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle,
  const int *constraintEqnEnableFlags,
  const int *prevModeVector,
  const int *modeVector,
  const double *inputVector,
  double *stateVector,
  void *neDiagMgr);
void KIMMCar_ff62ad8f_49_onModeChangedCutJoints(
  const void *mech,
  const int *prevModeVector,
  const int *modeVector,
  double *stateVector);
void KIMMCar_ff62ad8f_49_setVariableModeJointsToLocked(
  const void *mech,
  int *modeVector);
PmfMessageId KIMMCar_ff62ad8f_49_assemble(const double *u, double *udot, double *
  x,
  NeuDiagnosticManager *neDiagMgr)
{
  (void) x;
  (void) u;
  (void) udot;
  (void) neDiagMgr;
  return NULL;
}

static
  void dae_cg_setParameters_function(const NeDae *dae,
  const NeParameterBundle *paramBundle)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  const double *runtimeRootVariables = paramBundle->mRealParameters.mX;
  if (smData->mRuntimeParameterScalars.mN == 0)
    return;
  KIMMCar_ff62ad8f_49_computeRuntimeParameters(
    runtimeRootVariables,
    smData->mRuntimeParameterScalars.mX);
  KIMMCar_ff62ad8f_49_computeAsmRuntimeDerivedValues(
    smData->mRuntimeParameterScalars.mX,
    &dae->mPrivateData->mAsmRuntimeDerivedValuesBundle);
  KIMMCar_ff62ad8f_49_computeSimRuntimeDerivedValues(
    smData->mRuntimeParameterScalars.mX,
    &dae->mPrivateData->mSimRuntimeDerivedValuesBundle);
  KIMMCar_ff62ad8f_49_initializeGeometries
    (&smData->mSimRuntimeDerivedValuesBundle);
  sm_core_computeRedundantConstraintEquations(
    &dae->mPrivateData->mSimulationDelegate,
    &smData->mSimRuntimeDerivedValuesBundle);

#if 0

  {
    size_t i;
    const size_t n = smData->mSimulationDelegate.mRunTimeEnabledEquations.mSize;
    pmf_printf("\nRuntime Enabled Equations (%lu)\n", n);
    for (i = 0; i < n; ++i)
      pmf_printf("  %2lu:  %d\n", i,
                 smData->mSimulationDelegate.mRunTimeEnabledEquations.mValues[i]);
  }

#endif

}

static
  PmfMessageId dae_cg_pAssert_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  const double *runtimeParams = smData->mRuntimeParameterScalars.mX;
  int32_T *assertSatisfactionFlags = daeMethodOutput->mPASSERT.mX;
  (void) systemInput;
  (void) neDiagMgr;
  KIMMCar_ff62ad8f_49_validateRuntimeParameters(
    runtimeParams, assertSatisfactionFlags);
  return NULL;
}

static
  PmfMessageId dae_cg_deriv_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  double errorResult = 0.0;
  if (smData->mCachedDerivativesAvailable)
    memcpy(daeMethodOutput->mXP0.mX, smData->mCachedDerivatives.mX,
           29 * sizeof(real_T));
  else
    errorId = KIMMCar_ff62ad8f_49_compDerivs(
      &smData->mSimRuntimeDerivedValuesBundle,
      smData->mSimulationDelegate
      .mRunTimeEnabledEquations.mValues,
      systemInput->mX.mX,
      systemInput->mM.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 54,
      systemInput->mV.mX + 54,
      systemInput->mD.mX,
      daeMethodOutput->mXP0.mX,
      &errorResult,
      neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_cg_numJacPerturbLoBounds_method(
  const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  double errorResult = 0.0;
  errorId = KIMMCar_ff62ad8f_49_numJacPerturbLoBounds(
    &smData->mSimRuntimeDerivedValuesBundle,
    smData->mSimulationDelegate
    .mRunTimeEnabledEquations.mValues,
    systemInput->mX.mX,
    systemInput->mM.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mV.mX + 54,
    systemInput->mD.mX,
    daeMethodOutput->mNUMJAC_DX_LO.mX,
    &errorResult,
    neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_cg_numJacPerturbHiBounds_method(
  const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  double errorResult = 0.0;
  errorId = KIMMCar_ff62ad8f_49_numJacPerturbHiBounds(
    &smData->mSimRuntimeDerivedValuesBundle,
    smData->mSimulationDelegate
    .mRunTimeEnabledEquations.mValues,
    systemInput->mX.mX,
    systemInput->mM.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mV.mX + 54,
    systemInput->mD.mX,
    daeMethodOutput->mNUMJAC_DX_HI.mX,
    &errorResult,
    neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_cg_compOutputs_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  PmfMessageId errorId = NULL;
  NeDaePrivateData *smData = dae->mPrivateData;
  if (smData->mDoComputeDynamicOutputs) {
    int derivErr = 0;
    double errorResult = 0.0;
    errorId = KIMMCar_ff62ad8f_49_compOutputsDyn(
      &smData->mSimRuntimeDerivedValuesBundle,
      smData->mSimulationDelegate
      .mRunTimeEnabledEquations.mValues,
      systemInput->mX.mX,
      systemInput->mM.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 54,
      systemInput->mV.mX + 54,
      systemInput->mD.mX,
      smData->mCachedDerivatives.mX, daeMethodOutput->mY.mX,
      &derivErr, &errorResult, neDiagMgr);
    smData->mCachedDerivativesAvailable = (derivErr == 0);
  } else
    errorId = KIMMCar_ff62ad8f_49_compOutputsKin(
      &smData->mSimRuntimeDerivedValuesBundle,
      systemInput->mX.mX,
      systemInput->mM.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 54,
      systemInput->mV.mX + 54,
      systemInput->mD.mX,
      daeMethodOutput->mY.mX, neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_cg_mode_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  double errorResult = 0.0;
  errorId = KIMMCar_ff62ad8f_49_computeSimModeVector(
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mV.mX + 54,
    daeMethodOutput->mMODE.mX,
    &errorResult,
    neDiagMgr);
  memcpy(smData->mCachedModeVector.mX, daeMethodOutput->mMODE.mX,
         0 * sizeof(int32_T));
  return errorId;
}

static
  PmfMessageId dae_cg_zeroCrossing_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  double errorResult = 0.0;
  return
    KIMMCar_ff62ad8f_49_computeZeroCrossings(
    &smData->mSimRuntimeDerivedValuesBundle,
    systemInput->mX.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mV.mX + 54,
    systemInput->mD.mX,
    daeMethodOutput->mZC.mX,
    &errorResult,
    neDiagMgr);
}

static
  void dae_cg_setupLoggerFcn(const NeDae *dae,
  NeLoggerBuilder *neLoggerBuilder)
{
  (void) dae;
  (void) neLoggerBuilder;
}

static
  PmfMessageId dae_cg_recordLog_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  PmRealVector *output,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  double errorResult = 0.0;
  double *fullStateVector = smData->mSimulationFullStateVector.mX;
  KIMMCar_ff62ad8f_49_constructStateVector(
    NULL,
    systemInput->mX.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mD.mX,
    fullStateVector);
  errorId = KIMMCar_ff62ad8f_49_recordLog(
    &smData->mSimRuntimeDerivedValuesBundle,
    smData->mSimulationDelegate
    .mRunTimeEnabledEquations.mValues,
    fullStateVector,
    systemInput->mM.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mV.mX + 54,
    output->mX,
    &errorResult,
    neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_cg_project_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  return
    sm_core_projectState(
    false,
    &smData->mSimulationDelegate,
    &smData->mSimRuntimeDerivedValuesBundle,
    systemInput->mM.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mD.mX,
    systemInput->mX.mX, neDiagMgr);
}

static
  PmfMessageId dae_cg_check_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  if (smData->mNumConstraintEqns > 0)
    errorId = sm_core_projectState(
      false,
      &smData->mSimulationDelegate,
      &smData->mSimRuntimeDerivedValuesBundle,
      systemInput->mM.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 54,
      systemInput->mD.mX,
      systemInput->mX.mX, neDiagMgr);
  if (errorId == NULL) {
    double result = 0.0;
    errorId = KIMMCar_ff62ad8f_49_checkDynamics(
      &smData->mSimRuntimeDerivedValuesBundle,
      systemInput->mX.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 54,
      systemInput->mV.mX + 54,
      systemInput->mD.mX,
      systemInput->mM.mX,
      &result, neDiagMgr);
  }

  return errorId;
}

static
  PmfMessageId dae_cg_CIC_MODE_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  double errorResult = 0.0;
  const size_t mvSize = smData->mModeVectorSize;
  boolean_T modeChanged = false;
  if (mvSize > 0) {
    errorId = KIMMCar_ff62ad8f_49_computeSimModeVector(
      systemInput->mU.mX,
      systemInput->mU.mX + 54,
      systemInput->mV.mX + 54,
      systemInput->mM.mX,
      &errorResult,
      neDiagMgr);
    if (errorId != NULL)
      return errorId;

    {
      size_t i;
      for (i = 0; i < mvSize; ++i)
        if (systemInput->mM.mX[i] != smData->mCachedModeVector.mX[i]) {
          modeChanged = true;
          break;
        }
    }
  }

  if (modeChanged) {
    errorId = sm_core_onModeChanged(
      &smData->mSimulationDelegate,
      &smData->mSimRuntimeDerivedValuesBundle,
      systemInput->mU.mX,
      systemInput->mU.mX + 54,
      smData->mCachedModeVector.mX,
      systemInput->mM.mX,
      systemInput->mX.mX,
      systemInput->mD.mX,
      neDiagMgr);
    if (errorId != NULL)
      return errorId;
    memcpy(smData->mCachedModeVector.mX, systemInput->mM.mX,
           0 * sizeof(int32_T));
  }

  errorId =
    sm_core_projectState(
    true,
    &smData->mSimulationDelegate,
    &smData->mSimRuntimeDerivedValuesBundle,
    systemInput->mM.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 54,
    systemInput->mD.mX,
    systemInput->mX.mX, neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_cg_assemble_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  const SmMechanismDelegate *delegate = &smData->mAssemblyDelegate;
  const RuntimeDerivedValuesBundle *runtimeDerivedValuesBundle =
    &smData->mAsmRuntimeDerivedValuesBundle;
  PmfMessageId errorId = NULL;
  size_t i;
  double errorResult = 0.0;
  const size_t numTargets = 192;
  unsigned int asmStatus = 0;
  double *assemblyFullStateVector = smData->mAssemblyFullStateVector.mX;
  double *simulationFullStateVector = smData->mSimulationFullStateVector.mX;
  const double *u = systemInput->mU.mX;
  const double *uDot = u + smData->mInputVectorSize;
  const double *uDDot = systemInput->mV.mX +
    smData->mInputVectorSize;
  if (smData->mAssemblyModeVector.mN > 0) {
    errorId = KIMMCar_ff62ad8f_49_computeAsmModeVector(
      u, uDot, uDDot, smData->mAssemblyModeVector.mX, &errorResult, neDiagMgr);
    if (errorId != NULL)
      return errorId;
  }

  if (smData->mModeVectorSize > 0) {
    errorId = KIMMCar_ff62ad8f_49_computeSimModeVector(
      u, uDot, uDDot, systemInput->mM.mX, &errorResult, neDiagMgr);
    if (errorId != NULL)
      return errorId;
    memcpy(smData->mCachedModeVector.mX, systemInput->mM.mX,
           0 * sizeof(int32_T));
  }

  (*delegate->mSetTargets)(runtimeDerivedValuesBundle, smData->mTargets);

  {
    CTarget *target = smData->mTargets + smData->mNumInternalTargets;
    for (i = 0; i < smData->mNumMotionInputPrimitives; ++i) {
      const size_t inputOffset = smData->mMotionInputOffsets.mX[i];
      sm_compiler_CTarget_setValue( &u[inputOffset], 1, target++);
      sm_compiler_CTarget_setValue(&uDot[inputOffset], 1, target++);
    }

    for (i = 0; i < smData->mNumMaybeLockedPrimitives; ++i) {
      const boolean_T hasMode = smData->mMaybeLockedPrimHasModes.mX[i];
      const size_t modeOffset = smData->mMaybeLockedPrimModeOffsets.mX[i];
      if (hasMode && systemInput->mM.mX[modeOffset] != 1)
        target->mStrength = 0;
      else
        target->mStrength = 3;
      ++target;
    }
  }

  sm_core_computeStateVector(
    delegate, runtimeDerivedValuesBundle, smData->mAssemblyModeVector.mX,
    numTargets, smData->mTargets, assemblyFullStateVector);
  asmStatus = sm_core_checkAssembly(
    delegate, runtimeDerivedValuesBundle, assemblyFullStateVector,
    smData->mAssemblyModeVector.mX,
    NULL, NULL, NULL);
  if (asmStatus != 1) {
    return sm_ssci_recordRunTimeError(
      "physmod:sm:ssci:core:dae:dae:assemblyFailure",
      asmStatus == 2 ?
      "Model not assembled. The following violation occurred: Position Violation. The failure occurred during the attempt to assemble all joints in the system and satisfy any motion inputs. If an Update Diagram operation completes successfully, the failure is likely caused by motion inputs. Consider adjusting the motion inputs to specify a different starting configuration. Also consider adjusting or adding joint targets to better guide the assembly."
      :
      (asmStatus == 3 ?
       "Model not assembled. The following violation occurred: Velocity Violation. The failure occurred during the attempt to assemble all joints in the system and satisfy any motion inputs. If an Update Diagram operation completes successfully, the failure is likely caused by motion inputs. Consider adjusting the motion inputs to specify a different starting configuration. Also consider adjusting or adding joint targets to better guide the assembly."
       :
       "Model not assembled. The following violation occurred: Singularity Violation. The failure occurred during the attempt to assemble all joints in the system and satisfy any motion inputs. If an Update Diagram operation completes successfully, the failure is likely caused by motion inputs. Consider adjusting the motion inputs to specify a different starting configuration. Also consider adjusting or adding joint targets to better guide the assembly."),
      neDiagMgr);
  }

#if 0

  KIMMCar_ff62ad8f_49_checkTargets(
    &smData->mSimRuntimeDerivedValuesBundle,
    assemblyFullStateVector);

#endif

  (*delegate->mConvertStateVector)(
    NULL, runtimeDerivedValuesBundle, NULL, assemblyFullStateVector,
    smData->mAssemblyModeVector.mX, systemInput->mM.mX,
    simulationFullStateVector);
  for (i = 0; i < smData->mStateVectorSize; ++i)
    systemInput->mX.mX[i] = simulationFullStateVector[smData->
      mStateVectorMap.mX[i]];
  memcpy(systemInput->mD.mX,
         simulationFullStateVector +
         smData->mFullStateVectorSize - smData->mDiscreteStateSize,
         smData->mDiscreteStateSize * sizeof(double));
  return errorId;
}

typedef struct {
  size_t first;
  size_t second;
} SizePair;

static void checkMemAllocStatus(int_T status)
{
  (void) status;
}

static
  PmCharVector cStringToCharVector(const char *src)
{
  const size_t n = strlen(src);
  PmCharVector charVect;
  const int_T status =
    pm_create_char_vector_fields(&charVect, n + 1, pm_default_allocator());
  checkMemAllocStatus(status);
  strcpy(charVect.mX, src);
  return charVect;
}

static
  void initBasicAttributes(NeDaePrivateData *smData)
{
  size_t i;
  smData->mStateVectorSize = 29;
  smData->mFullStateVectorSize = 109;
  smData->mDiscreteStateSize = 0;
  smData->mModeVectorSize = 0;
  smData->mNumZeroCrossings = 0;
  smData->mInputVectorSize = 54;
  smData->mOutputVectorSize = 139;
  smData->mNumConstraintEqns = 0;
  smData->mFundamentalSampleTime = +0.000000000000000000e+00;
  for (i = 0; i < 4; ++i)
    smData->mChecksum[i] = 0;
}

static
  void initStateVector(NeDaePrivateData *smData)
{
  PmAllocator *alloc = pm_default_allocator();
  static const int32_T stateVectorMap[29] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 15, 18, 23, 24, 27, 30, 35,
    36, 39, 42, 47, 48, 51, 54, 59, 60
  };

  static real_T targetVals[202] = {
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +1.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +6.147000000000000242e-01,
    +0.000000000000000000e+00, +1.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +0.000000000000000000e+00, +0.000000000000000000e+00
  };

  static const CTarget targets[192] = {
    { 0, 72, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[0] }, { +0.000000000000000000e+00 } },

    { 0, 72, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[1] }, { +0.000000000000000000e+00 } },

    { 0, 72, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[2] }, { +0.000000000000000000e+00 } },

    { 0, 72, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[3] }, { +0.000000000000000000e+00 } },

    { 0, 72, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[4] }, { +0.000000000000000000e+00 } },

    { 0, 72, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[5] }, { +0.000000000000000000e+00 } },

    { 1, 103, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 4, 4, &targetVals[6] }, { +0.000000000000000000e+00 } },

    { 2, 103, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 3, 3, &targetVals[10] }, { +0.000000000000000000e+00 } },

    { 0, 285, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[13] }, { +0.000000000000000000e+00 } },

    { 0, 285, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[14] }, { +0.000000000000000000e+00 } },

    { 0, 286, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[15] }, { +0.000000000000000000e+00 } },

    { 0, 286, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[16] }, { +0.000000000000000000e+00 } },

    { 0, 298, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[17] }, { +0.000000000000000000e+00 } },

    { 0, 298, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[18] }, { +0.000000000000000000e+00 } },

    { 0, 299, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[19] }, { +0.000000000000000000e+00 } },

    { 0, 299, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[20] }, { +0.000000000000000000e+00 } },

    { 0, 359, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[21] }, { +0.000000000000000000e+00 } },

    { 0, 359, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[22] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[23] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[24] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[25] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[26] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[27] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[28] }, { +0.000000000000000000e+00 } },

    { 0, 363, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[29] }, { +0.000000000000000000e+00 } },

    { 0, 363, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[30] }, { +0.000000000000000000e+00 } },

    { 0, 367, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[31] }, { +0.000000000000000000e+00 } },

    { 0, 367, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[32] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[33] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[34] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[35] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[36] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[37] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[38] }, { +0.000000000000000000e+00 } },

    { 0, 371, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[39] }, { +0.000000000000000000e+00 } },

    { 0, 371, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[40] }, { +0.000000000000000000e+00 } },

    { 0, 402, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[41] }, { +0.000000000000000000e+00 } },

    { 0, 402, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[42] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[43] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[44] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[45] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[46] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[47] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[48] }, { +0.000000000000000000e+00 } },

    { 0, 406, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[49] }, { +0.000000000000000000e+00 } },

    { 0, 406, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[50] }, { +0.000000000000000000e+00 } },

    { 0, 410, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[51] }, { +0.000000000000000000e+00 } },

    { 0, 410, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[52] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[53] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[54] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[55] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[56] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[57] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[58] }, { +0.000000000000000000e+00 } },

    { 0, 414, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[59] }, { +0.000000000000000000e+00 } },

    { 0, 414, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[60] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[61] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[62] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[63] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[64] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[65] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[66] }, { +0.000000000000000000e+00 } },

    { 0, 445, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[67] }, { +0.000000000000000000e+00 } },

    { 0, 445, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[68] }, { +0.000000000000000000e+00 } },

    { 0, 446, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[69] }, { +0.000000000000000000e+00 } },

    { 0, 446, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[70] }, { +0.000000000000000000e+00 } },

    { 0, 447, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[71] }, { +0.000000000000000000e+00 } },

    { 0, 447, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[72] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[73] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[74] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[75] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[76] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[77] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[78] }, { +0.000000000000000000e+00 } },

    { 0, 479, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[79] }, { +0.000000000000000000e+00 } },

    { 0, 479, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[80] }, { +0.000000000000000000e+00 } },

    { 0, 480, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[81] }, { +0.000000000000000000e+00 } },

    { 0, 480, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[82] }, { +0.000000000000000000e+00 } },

    { 0, 481, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[83] }, { +0.000000000000000000e+00 } },

    { 0, 481, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[84] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[85] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[86] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[87] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[88] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[89] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[90] }, { +0.000000000000000000e+00 } },

    { 0, 513, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[91] }, { +0.000000000000000000e+00 } },

    { 0, 513, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[92] }, { +0.000000000000000000e+00 } },

    { 0, 514, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[93] }, { +0.000000000000000000e+00 } },

    { 0, 514, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[94] }, { +0.000000000000000000e+00 } },

    { 0, 515, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[95] }, { +0.000000000000000000e+00 } },

    { 0, 515, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[96] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[97] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[98] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[99] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[100] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 0, "1", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[101] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[102] }, { +0.000000000000000000e+00 } },

    { 0, 547, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[103] }, { +0.000000000000000000e+00 } },

    { 0, 547, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[104] }, { +0.000000000000000000e+00 } },

    { 0, 548, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[105] }, { +0.000000000000000000e+00 } },

    { 0, 548, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[106] }, { +0.000000000000000000e+00 } },

    { 0, 549, false, 0, 0, "1", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[107] }, { +0.000000000000000000e+00 } },

    { 0, 549, false, 0, 0, "1", 0, true, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[108] }, { +0.000000000000000000e+00 } },

    { 0, 570, false, 0, 0, "1", 0, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[109] }, { +0.000000000000000000e+00 } },

    { 0, 570, false, 0, 0, "1", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[110] }, { +0.000000000000000000e+00 } },

    { 0, 570, false, 0, 0, "1", 1, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[111] }, { +0.000000000000000000e+00 } },

    { 0, 570, false, 0, 0, "1", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[112] }, { +0.000000000000000000e+00 } },

    { 0, 570, false, 0, 1, "m", 2, false, false, +1.000000000000000000e+00,
      false, { 1, 1, &targetVals[113] }, { +0.000000000000000000e+00 } },

    { 0, 570, false, 0, 0, "1", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[114] }, { +0.000000000000000000e+00 } },

    { 1, 570, false, 0, 0, "1", 3, false, false, +1.000000000000000000e+00,
      false, { 4, 4, &targetVals[115] }, { +0.000000000000000000e+00 } },

    { 2, 570, false, 0, 0, "1", 3, true, false, +1.000000000000000000e+00, false,
      { 3, 3, &targetVals[119] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[122] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[123] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[124] }, { +0.000000000000000000e+00 } },

    { 0, 362, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[125] }, { +0.000000000000000000e+00 } },

    { 0, 359, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[126] }, { +0.000000000000000000e+00 } },

    { 0, 359, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[127] }, { +0.000000000000000000e+00 } },

    { 0, 363, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[128] }, { +0.000000000000000000e+00 } },

    { 0, 363, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[129] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[130] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[131] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[132] }, { +0.000000000000000000e+00 } },

    { 0, 370, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[133] }, { +0.000000000000000000e+00 } },

    { 0, 367, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[134] }, { +0.000000000000000000e+00 } },

    { 0, 367, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[135] }, { +0.000000000000000000e+00 } },

    { 0, 371, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[136] }, { +0.000000000000000000e+00 } },

    { 0, 371, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[137] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[138] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[139] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[140] }, { +0.000000000000000000e+00 } },

    { 0, 405, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[141] }, { +0.000000000000000000e+00 } },

    { 0, 402, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[142] }, { +0.000000000000000000e+00 } },

    { 0, 402, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[143] }, { +0.000000000000000000e+00 } },

    { 0, 406, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[144] }, { +0.000000000000000000e+00 } },

    { 0, 406, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[145] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[146] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[147] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[148] }, { +0.000000000000000000e+00 } },

    { 0, 413, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[149] }, { +0.000000000000000000e+00 } },

    { 0, 410, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[150] }, { +0.000000000000000000e+00 } },

    { 0, 410, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[151] }, { +0.000000000000000000e+00 } },

    { 0, 414, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[152] }, { +0.000000000000000000e+00 } },

    { 0, 414, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[153] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[154] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[155] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[156] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[157] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 3, "", 2, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[158] }, { +0.000000000000000000e+00 } },

    { 0, 444, false, 0, 3, "", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[159] }, { +0.000000000000000000e+00 } },

    { 0, 446, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[160] }, { +0.000000000000000000e+00 } },

    { 0, 446, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[161] }, { +0.000000000000000000e+00 } },

    { 0, 447, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[162] }, { +0.000000000000000000e+00 } },

    { 0, 447, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[163] }, { +0.000000000000000000e+00 } },

    { 0, 445, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[164] }, { +0.000000000000000000e+00 } },

    { 0, 445, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[165] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[166] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[167] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[168] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[169] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 3, "", 2, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[170] }, { +0.000000000000000000e+00 } },

    { 0, 478, false, 0, 3, "", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[171] }, { +0.000000000000000000e+00 } },

    { 0, 480, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[172] }, { +0.000000000000000000e+00 } },

    { 0, 480, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[173] }, { +0.000000000000000000e+00 } },

    { 0, 481, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[174] }, { +0.000000000000000000e+00 } },

    { 0, 481, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[175] }, { +0.000000000000000000e+00 } },

    { 0, 479, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[176] }, { +0.000000000000000000e+00 } },

    { 0, 479, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[177] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[178] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[179] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[180] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[181] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 3, "", 2, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[182] }, { +0.000000000000000000e+00 } },

    { 0, 512, false, 0, 3, "", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[183] }, { +0.000000000000000000e+00 } },

    { 0, 514, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[184] }, { +0.000000000000000000e+00 } },

    { 0, 514, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[185] }, { +0.000000000000000000e+00 } },

    { 0, 515, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[186] }, { +0.000000000000000000e+00 } },

    { 0, 515, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[187] }, { +0.000000000000000000e+00 } },

    { 0, 513, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[188] }, { +0.000000000000000000e+00 } },

    { 0, 513, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[189] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 3, "", 0, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[190] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 3, "", 0, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[191] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 3, "", 1, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[192] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 3, "", 1, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[193] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 3, "", 2, false, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[194] }, { +0.000000000000000000e+00 } },

    { 0, 546, false, 0, 3, "", 2, true, false, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[195] }, { +0.000000000000000000e+00 } },

    { 0, 548, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[196] }, { +0.000000000000000000e+00 } },

    { 0, 548, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[197] }, { +0.000000000000000000e+00 } },

    { 0, 549, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[198] }, { +0.000000000000000000e+00 } },

    { 0, 549, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[199] }, { +0.000000000000000000e+00 } },

    { 0, 547, false, 0, 3, "", 0, false, true, +1.000000000000000000e+00, false,
      { 1, 1, &targetVals[200] }, { +0.000000000000000000e+00 } },

    { 0, 547, false, 0, 3, "", 0, true, true, +1.000000000000000000e+00, false,
        { 1, 1, &targetVals[201] }, { +0.000000000000000000e+00 } }
  };

  int_T status;
  size_t i;
  status = pm_create_real_vector_fields(
    &smData->mAssemblyFullStateVector, 115, alloc);
  checkMemAllocStatus(status);
  status = pm_create_real_vector_fields(
    &smData->mSimulationFullStateVector, 109, alloc);
  checkMemAllocStatus(status);
  status = pm_create_int_vector_fields(
    &smData->mStateVectorMap, smData->mStateVectorSize, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mStateVectorMap.mX, stateVectorMap,
         smData->mStateVectorSize * sizeof(int32_T));
  smData->mNumInternalTargets = 112;
  smData->mNumMotionInputPrimitives = 40;
  smData->mNumMaybeLockedPrimitives = 0;
  smData->mNumTargets = 192;
  PM_ALLOCATE_ARRAY(smData->mTargets, CTarget, smData->mNumTargets, alloc);
  for (i = 0; i < smData->mNumTargets; ++i)
    sm_compiler_CTarget_copy(targets + i, smData->mTargets + i);
}

static void initAsserts(NeDaePrivateData *smData)
{
  PmAllocator *alloc = pm_default_allocator();
  int_T status = 0;
  smData->mNumParamAsserts = 146;
  smData->mParamAssertObjects = NULL;
  smData->mParamAssertPaths = NULL;
  smData->mParamAssertDescriptors = NULL;
  smData->mParamAssertMessages = NULL;
  smData->mParamAssertMessageIds = NULL;
  status = pm_create_bool_vector_fields(
    &smData->mParamAssertIsWarnings, smData->mNumParamAsserts, alloc);
  checkMemAllocStatus(status);
  if (smData->mNumParamAsserts > 0) {
    const NeAssertData *ad = KIMMCar_ff62ad8f_49_assertData;
    size_t i;
    PM_ALLOCATE_ARRAY(smData->mParamAssertObjects,
                      PmCharVector, 146, alloc);
    PM_ALLOCATE_ARRAY(smData->mParamAssertPaths,
                      PmCharVector, 146, alloc);
    PM_ALLOCATE_ARRAY(smData->mParamAssertDescriptors,
                      PmCharVector, 146, alloc);
    PM_ALLOCATE_ARRAY(smData->mParamAssertMessages,
                      PmCharVector, 146, alloc);
    PM_ALLOCATE_ARRAY(smData->mParamAssertMessageIds,
                      PmCharVector, 146, alloc);
    for (i = 0; i < smData->mNumParamAsserts; ++i, ++ad) {
      smData->mParamAssertObjects [i] = cStringToCharVector(ad->mObject );
      smData->mParamAssertPaths [i] = cStringToCharVector(ad->mPath );
      smData->mParamAssertDescriptors[i] = cStringToCharVector(ad->mDescriptor);
      smData->mParamAssertMessages [i] = cStringToCharVector(ad->mMessage );
      smData->mParamAssertMessageIds [i] = cStringToCharVector(ad->mMessageID );
      smData->mParamAssertIsWarnings.mX[i] = ad->mIsWarn;
    }
  }
}

static
  void initModeVector(NeDaePrivateData *smData)
{
  {
    size_t i;
    const int_T status = pm_create_int_vector_fields(
      &smData->mAssemblyModeVector, 0,
      pm_default_allocator());
    checkMemAllocStatus(status);
    for (i = 0; i < smData->mAssemblyModeVector.mN; ++i)
      smData->mAssemblyModeVector.mX[i] = 0;
  }

  {
    size_t i;
    const int_T status = pm_create_int_vector_fields(
      &smData->mCachedModeVector, 0, pm_default_allocator());
    checkMemAllocStatus(status);
    for (i = 0; i < smData->mModeVectorSize; ++i)
      smData->mCachedModeVector.mX[i] = 0;
  }
}

static void initZeroCrossings(NeDaePrivateData *smData)
{
  PmAllocator *alloc = pm_default_allocator();
  int_T status = 0;
  smData->mZeroCrossingObjects = NULL;
  smData->mZeroCrossingPaths = NULL;
  smData->mZeroCrossingDescriptors = NULL;
  status = pm_create_int_vector_fields(
    &smData->mZeroCrossingTypes, 0, alloc);
  checkMemAllocStatus(status);
  if (smData->mNumZeroCrossings > 0) {
    const NeZCData *zcd = KIMMCar_ff62ad8f_49_ZCData;
    size_t i;
    PM_ALLOCATE_ARRAY(smData->mZeroCrossingObjects,
                      PmCharVector, 0, alloc);
    PM_ALLOCATE_ARRAY(smData->mZeroCrossingPaths,
                      PmCharVector, 0, alloc);
    PM_ALLOCATE_ARRAY(smData->mZeroCrossingDescriptors,
                      PmCharVector, 0, alloc);
    for (i = 0; i < smData->mNumZeroCrossings; ++i, ++zcd) {
      smData->mZeroCrossingObjects [i] = cStringToCharVector(zcd->mObject);
      smData->mZeroCrossingPaths [i] = cStringToCharVector(zcd->mPath );
      smData->mZeroCrossingDescriptors[i] = cStringToCharVector(zcd->mDescriptor);
      smData->mZeroCrossingTypes.mX[i] = zcd->mType;
    }
  }
}

static
  void initVariables(NeDaePrivateData *smData)
{
  static const char *varFullPaths[29] = {
    "Vehicle.Camera_Frames.Cartesian_Joint.Px.p",
    "Vehicle.Camera_Frames.Cartesian_Joint.Py.p",
    "Vehicle.Camera_Frames.Cartesian_Joint.Pz.p",
    "Vehicle.Camera_Frames.Cartesian_Joint.Px.v",
    "Vehicle.Camera_Frames.Cartesian_Joint.Py.v",
    "Vehicle.Camera_Frames.Cartesian_Joint.Pz.v",
    "Vehicle.Camera_Frames.Spherical_Joint.S.Q",
    "Vehicle.Camera_Frames.Spherical_Joint.S.Q",
    "Vehicle.Camera_Frames.Spherical_Joint.S.Q",
    "Vehicle.Camera_Frames.Spherical_Joint.S.Q",
    "Vehicle.Camera_Frames.Spherical_Joint.S.w",
    "Vehicle.Camera_Frames.Spherical_Joint.S.w",
    "Vehicle.Camera_Frames.Spherical_Joint.S.w",
    "Vehicle.Suspension_Front.Left_Spring_Damper.Pz.p",
    "Vehicle.Suspension_Front.Left_Spring_Damper.Pz.v",
    "Vehicle.FL_Revolute.Rz.q",
    "Vehicle.FL_Revolute.Rz.w",
    "Vehicle.Suspension_Front.Right_Spring_Damper.Pz.p",
    "Vehicle.Suspension_Front.Right_Spring_Damper.Pz.v",
    "Vehicle.FR_Revolute.Rz.q",
    "Vehicle.FR_Revolute.Rz.w",
    "Vehicle.Suspension_Rear.Left_Spring_Damper.Pz.p",
    "Vehicle.Suspension_Rear.Left_Spring_Damper.Pz.v",
    "Vehicle.RL_Revolute.Rz.q",
    "Vehicle.RL_Revolute.Rz.w",
    "Vehicle.Suspension_Rear.Right_Spring_Damper.Pz.p",
    "Vehicle.Suspension_Rear.Right_Spring_Damper.Pz.v",
    "Vehicle.RR_Revolute.Rz.q",
    "Vehicle.RR_Revolute.Rz.w"
  };

  static const char *varObjects[29] = {
    "KIMMCar/Vehicle/Camera Frames/Cartesian Joint",
    "KIMMCar/Vehicle/Camera Frames/Cartesian Joint",
    "KIMMCar/Vehicle/Camera Frames/Cartesian Joint",
    "KIMMCar/Vehicle/Camera Frames/Cartesian Joint",
    "KIMMCar/Vehicle/Camera Frames/Cartesian Joint",
    "KIMMCar/Vehicle/Camera Frames/Cartesian Joint",
    "KIMMCar/Vehicle/Camera Frames/Spherical Joint",
    "KIMMCar/Vehicle/Camera Frames/Spherical Joint",
    "KIMMCar/Vehicle/Camera Frames/Spherical Joint",
    "KIMMCar/Vehicle/Camera Frames/Spherical Joint",
    "KIMMCar/Vehicle/Camera Frames/Spherical Joint",
    "KIMMCar/Vehicle/Camera Frames/Spherical Joint",
    "KIMMCar/Vehicle/Camera Frames/Spherical Joint",
    "KIMMCar/Vehicle/Suspension Front/Left Spring Damper",
    "KIMMCar/Vehicle/Suspension Front/Left Spring Damper",
    "KIMMCar/Vehicle/FL Revolute",
    "KIMMCar/Vehicle/FL Revolute",
    "KIMMCar/Vehicle/Suspension Front/Right Spring Damper",
    "KIMMCar/Vehicle/Suspension Front/Right Spring Damper",
    "KIMMCar/Vehicle/FR Revolute",
    "KIMMCar/Vehicle/FR Revolute",
    "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper",
    "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper",
    "KIMMCar/Vehicle/RL Revolute",
    "KIMMCar/Vehicle/RL Revolute",
    "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper",
    "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper",
    "KIMMCar/Vehicle/RR Revolute",
    "KIMMCar/Vehicle/RR Revolute"
  };

  static const char *varEncodedDims[29] = {
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "4x1",
    "4x1",
    "4x1",
    "4x1",
    "3x1",
    "3x1",
    "3x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1",
    "1x1"
  };

  static const size_t varNumels[29] = {
    1, 1, 1, 1, 1, 1, 4, 4, 4, 4,
    3, 3, 3, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1
  };

  smData->mNumVarScalars = 29;
  smData->mVarFullPaths = NULL;
  smData->mVarObjects = NULL;
  smData->mVarEncodedDims = NULL;
  if (smData->mNumVarScalars > 0) {
    size_t s;
    PmAllocator *alloc = pm_default_allocator();
    int_T status = 0;
    PM_ALLOCATE_ARRAY(smData->mVarFullPaths, PmCharVector, 29, alloc);
    PM_ALLOCATE_ARRAY(smData->mVarObjects, PmCharVector, 29, alloc);
    PM_ALLOCATE_ARRAY(smData->mVarEncodedDims, PmCharVector, 29, alloc);
    for (s = 0; s < smData->mNumVarScalars; ++s) {
      smData->mVarFullPaths[s] = cStringToCharVector(varFullPaths[s]);
      smData->mVarObjects[s] = cStringToCharVector(varObjects[s]);
      smData->mVarEncodedDims[s] = cStringToCharVector(varEncodedDims[s]);
    }

    status = pm_create_size_vector_fields(
      &smData->mVarNumels, smData->mNumVarScalars, alloc);
    checkMemAllocStatus(status);
    memcpy(smData->mVarNumels.mX, varNumels,
           29 * sizeof(size_t));
  }
}

static
  void initRuntimeParameters(NeDaePrivateData *smData)
{
  PmAllocator *alloc = pm_default_allocator();
  int_T status = 0;
  size_t i = 0;
  static const int32_T rtpRootVarNumels[97] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 3, 3,
    1, 1, 1, 1, 1, 3, 1, 1, 1, 3,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 3, 1, 1, 3, 3, 1, 3, 3, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 3, 1, 3, 3, 3, 1, 3,
    3, 1, 3, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
    1, 3, 3, 1, 1, 1, 3
  };

  static const char *rtpFullPaths [97] = {
    "RTP_041AAD1B_VelocityTargetValue",
    "RTP_082E27ED_PzDampingCoefficient",
    "RTP_082E27ED_PzEquilibriumPosition",
    "RTP_082E27ED_PzLowerLimitBound",
    "RTP_082E27ED_PzLowerLimitDamping",
    "RTP_082E27ED_PzLowerLimitStiffness",
    "RTP_082E27ED_PzLowerLimitTransitionRegionWidth",
    "RTP_082E27ED_PzSpringStiffness",
    "RTP_082E27ED_PzUpperLimitBound",
    "RTP_082E27ED_PzUpperLimitDamping",
    "RTP_082E27ED_PzUpperLimitStiffness",
    "RTP_082E27ED_PzUpperLimitTransitionRegionWidth",
    "RTP_087BC81F_VelocityTargetValue",
    "RTP_0ABA0B7C_RotationAngle",
    "RTP_0ABA0B7C_TranslationStandardOffset",
    "RTP_15BC236D_CylinderLength",
    "RTP_15BC236D_CylinderRadius",
    "RTP_15BC236D_Mass",
    "RTP_15BC236D_MomentsOfInertia",
    "RTP_2D46EB53_TranslationCartesianOffset",
    "RTP_414226C5_PzPositionTargetValue",
    "RTP_5BD4A88C_VelocityTargetValue",
    "RTP_6A570A4D_CylinderLength",
    "RTP_6A570A4D_CylinderRadius",
    "RTP_6A570A4D_Mass",
    "RTP_6A570A4D_MomentsOfInertia",
    "RTP_6D3ACE54_CylinderLength",
    "RTP_6D3ACE54_CylinderRadius",
    "RTP_6D3ACE54_Mass",
    "RTP_6D3ACE54_MomentsOfInertia",
    "RTP_7030F57E_PzDampingCoefficient",
    "RTP_7030F57E_PzEquilibriumPosition",
    "RTP_7030F57E_PzLowerLimitBound",
    "RTP_7030F57E_PzLowerLimitDamping",
    "RTP_7030F57E_PzLowerLimitStiffness",
    "RTP_7030F57E_PzLowerLimitTransitionRegionWidth",
    "RTP_7030F57E_PzSpringStiffness",
    "RTP_7030F57E_PzUpperLimitBound",
    "RTP_7030F57E_PzUpperLimitDamping",
    "RTP_7030F57E_PzUpperLimitStiffness",
    "RTP_7030F57E_PzUpperLimitTransitionRegionWidth",
    "RTP_73B42110_TranslationCartesianOffset",
    "RTP_73B42110_TranslationStandardOffset",
    "RTP_7A507D97_Mass",
    "RTP_7A507D97_MomentsOfInertia",
    "RTP_7DBD3BEA_CenterOfMass",
    "RTP_7DBD3BEA_Mass",
    "RTP_7DBD3BEA_MomentsOfInertia",
    "RTP_7DBD3BEA_ProductsOfInertia",
    "RTP_7F29177B_PzDampingCoefficient",
    "RTP_7F29177B_PzEquilibriumPosition",
    "RTP_7F29177B_PzLowerLimitBound",
    "RTP_7F29177B_PzLowerLimitDamping",
    "RTP_7F29177B_PzLowerLimitStiffness",
    "RTP_7F29177B_PzLowerLimitTransitionRegionWidth",
    "RTP_7F29177B_PzSpringStiffness",
    "RTP_7F29177B_PzUpperLimitBound",
    "RTP_7F29177B_PzUpperLimitDamping",
    "RTP_7F29177B_PzUpperLimitStiffness",
    "RTP_7F29177B_PzUpperLimitTransitionRegionWidth",
    "RTP_9CB22C5A_VelocityTargetValue",
    "RTP_A11E2A99_RotationAngle",
    "RTP_A11E2A99_TranslationStandardOffset",
    "RTP_A5036385_CenterOfMass",
    "RTP_A5036385_Mass",
    "RTP_A5036385_MomentsOfInertia",
    "RTP_A5036385_ProductsOfInertia",
    "RTP_B27877C6_CenterOfMass",
    "RTP_B27877C6_Mass",
    "RTP_B27877C6_MomentsOfInertia",
    "RTP_B27877C6_ProductsOfInertia",
    "RTP_B8077B89_TranslationStandardOffset",
    "RTP_C019A91A_TranslationCartesianOffset",
    "RTP_C019A91A_TranslationStandardOffset",
    "RTP_C556BF9F_PzDampingCoefficient",
    "RTP_C556BF9F_PzEquilibriumPosition",
    "RTP_C556BF9F_PzLowerLimitBound",
    "RTP_C556BF9F_PzLowerLimitDamping",
    "RTP_C556BF9F_PzLowerLimitStiffness",
    "RTP_C556BF9F_PzLowerLimitTransitionRegionWidth",
    "RTP_C556BF9F_PzSpringStiffness",
    "RTP_C556BF9F_PzUpperLimitBound",
    "RTP_C556BF9F_PzUpperLimitDamping",
    "RTP_C556BF9F_PzUpperLimitStiffness",
    "RTP_C556BF9F_PzUpperLimitTransitionRegionWidth",
    "RTP_C57F4750_RotationAngle",
    "RTP_C57F4750_TranslationStandardOffset",
    "RTP_D2045313_RotationAngle",
    "RTP_D2045313_TranslationStandardOffset",
    "RTP_D6191A0F_CenterOfMass",
    "RTP_D6191A0F_Mass",
    "RTP_D6191A0F_MomentsOfInertia",
    "RTP_D6191A0F_ProductsOfInertia",
    "RTP_F6ED1E1D_CylinderLength",
    "RTP_F6ED1E1D_CylinderRadius",
    "RTP_F6ED1E1D_Mass",
    "RTP_F6ED1E1D_MomentsOfInertia"
  };

  smData->mNumRtpRootVars = 97;
  status = pm_create_int_vector_fields(
    &smData->mRtpRootVarNumels, smData->mNumRtpRootVars, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mRtpRootVarNumels.mX, rtpRootVarNumels,
         smData->mNumRtpRootVars * sizeof(int32_T));
  smData->mRtpFullPaths = NULL;
  if (smData->mNumRtpRootVars > 0) {
    size_t v;
    PM_ALLOCATE_ARRAY(smData->mRtpFullPaths, PmCharVector, 97, alloc);
    for (v = 0; v < smData->mNumRtpRootVars; ++v) {
      smData->mRtpFullPaths[v] = cStringToCharVector(rtpFullPaths[v]);
    }
  }

  smData->mNumRuntimeRootVarScalars = 137;
  status = pm_create_real_vector_fields(
    &smData->mRuntimeParameterScalars, 137,
    alloc);
  checkMemAllocStatus(status);
  for (i = 0; i < smData->mRuntimeParameterScalars.mN; ++i)
    smData->mRuntimeParameterScalars.mX[i] = 0.0;
  sm_core_RuntimeDerivedValuesBundle_create(
    &smData->mAsmRuntimeDerivedValuesBundle,
    296,
    0);
  sm_core_RuntimeDerivedValuesBundle_create(
    &smData->mSimRuntimeDerivedValuesBundle,
    294,
    0);
}

static
  void initIoInfoHelper(
  size_t n,
  const char *portPathsSource[],
  const char *unitsSource[],
  const SscArraySize dimensions[],
  boolean_T doInputs,
  NeDaePrivateData *smData)
{
  PmCharVector *portPaths = NULL;
  PmCharVector *units = NULL;
  SscIoInfo *infos = NULL;
  if (n > 0) {
    size_t s;
    PmAllocator *alloc = pm_default_allocator();
    PM_ALLOCATE_ARRAY(portPaths, PmCharVector, n, alloc);
    PM_ALLOCATE_ARRAY(units, PmCharVector, n, alloc);
    PM_ALLOCATE_ARRAY(infos, SscIoInfo, n, alloc);
    for (s = 0; s < n; ++s) {
      portPaths[s] = cStringToCharVector(portPathsSource[s]);
      units[s] = cStringToCharVector(unitsSource[s]);

      {
        SscIoInfo *info = infos + s;
        info->name = info->identifier = portPaths[s].mX;
        info->size = dimensions[s];
        info->unit = units[s].mX;
      }
    }
  }

  if (doInputs) {
    smData->mNumInputs = n;
    smData->mInputPortPaths = portPaths;
    smData->mInputUnits = units;
    smData->mInputInfos = infos;
  } else {
    smData->mNumOutputs = n;
    smData->mOutputPortPaths = portPaths;
    smData->mOutputUnits = units;
    smData->mOutputInfos = infos;
  }
}

static
  void initIoInfo(NeDaePrivateData *smData)
{
  static const char *inputPortPaths[54] = {
    "Vehicle.FL_Revolute.ti",
    "Vehicle.FR_Revolute.ti",
    "Vehicle.RL_Revolute.ti",
    "Vehicle.RR_Revolute.ti",
    "Vehicle.Suspension_Front.Left_Camber_Revolute.qi",
    "Vehicle.Suspension_Front.Left_Spring_Damper.pxi",
    "Vehicle.Suspension_Front.Left_Spring_Damper.pyi",
    "Vehicle.Suspension_Front.Left_Steer_Revolute.qi",
    "Vehicle.Suspension_Front.Right_Camber_Revolute.qi",
    "Vehicle.Suspension_Front.Right_Spring_Damper.pxi",
    "Vehicle.Suspension_Front.Right_Spring_Damper.pyi",
    "Vehicle.Suspension_Front.Right_Steer_Revolute.qi",
    "Vehicle.Suspension_Rear.Left_Camber_Revolute.qi",
    "Vehicle.Suspension_Rear.Left_Spring_Damper.pxi",
    "Vehicle.Suspension_Rear.Left_Spring_Damper.pyi",
    "Vehicle.Suspension_Rear.Left_Steer_Revolute.qi",
    "Vehicle.Suspension_Rear.Rifht_Camber_Revolute.qi",
    "Vehicle.Suspension_Rear.Right_Spring_Damper.pxi",
    "Vehicle.Suspension_Rear.Right_Spring_Damper.pyi",
    "Vehicle.Suspension_Rear.Right_Steer_Revolute.qi",
    "Vehicle.Tire_FL.Road_Motion.Cartesian_Joint.pxi",
    "Vehicle.Tire_FL.Road_Motion.Cartesian_Joint.pyi",
    "Vehicle.Tire_FL.Road_Motion.Cartesian_Joint.pzi",
    "Vehicle.Tire_FL.Road_Motion.Revolute_Bank.qi",
    "Vehicle.Tire_FL.Road_Motion.Revolute_Heading.qi",
    "Vehicle.Tire_FL.Road_Motion.Revolute_Slope.qi",
    "Vehicle.Tire_FR.Road_Motion.Cartesian_Joint.pxi",
    "Vehicle.Tire_FR.Road_Motion.Cartesian_Joint.pyi",
    "Vehicle.Tire_FR.Road_Motion.Cartesian_Joint.pzi",
    "Vehicle.Tire_FR.Road_Motion.Revolute_Bank.qi",
    "Vehicle.Tire_FR.Road_Motion.Revolute_Heading.qi",
    "Vehicle.Tire_FR.Road_Motion.Revolute_Slope.qi",
    "Vehicle.Tire_RL.Road_Motion.Cartesian_Joint.pxi",
    "Vehicle.Tire_RL.Road_Motion.Cartesian_Joint.pyi",
    "Vehicle.Tire_RL.Road_Motion.Cartesian_Joint.pzi",
    "Vehicle.Tire_RL.Road_Motion.Revolute_Bank.qi",
    "Vehicle.Tire_RL.Road_Motion.Revolute_Heading.qi",
    "Vehicle.Tire_RL.Road_Motion.Revolute_Slope.qi",
    "Vehicle.Tire_RR.Road_Motion.Cartesian_Joint.pxi",
    "Vehicle.Tire_RR.Road_Motion.Cartesian_Joint.pyi",
    "Vehicle.Tire_RR.Road_Motion.Cartesian_Joint.pzi",
    "Vehicle.Tire_RR.Road_Motion.Revolute_Bank.qi",
    "Vehicle.Tire_RR.Road_Motion.Revolute_Heading.qi",
    "Vehicle.Tire_RR.Road_Motion.Revolute_Slope.qi",
    "Vehicle.Aero.External_Force_and_Torque.fx",
    "Vehicle.Aero.External_Force_and_Torque.fz",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.lmux",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.lmuy",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.lmux",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.lmuy",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.lmux",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.lmuy",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.lmux",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.lmuy"
  };

  static const char *inputUnits[54] = {
    "kg*m^2/s^2",
    "kg*m^2/s^2",
    "kg*m^2/s^2",
    "kg*m^2/s^2",
    "rad",
    "m",
    "m",
    "rad",
    "rad",
    "m",
    "m",
    "rad",
    "rad",
    "m",
    "m",
    "rad",
    "rad",
    "m",
    "m",
    "rad",
    "m",
    "m",
    "m",
    "rad",
    "rad",
    "rad",
    "m",
    "m",
    "m",
    "rad",
    "rad",
    "rad",
    "m",
    "m",
    "m",
    "rad",
    "rad",
    "rad",
    "m",
    "m",
    "m",
    "rad",
    "rad",
    "rad",
    "kg*m/s^2",
    "kg*m/s^2",
    "1",
    "1",
    "1",
    "1",
    "1",
    "1",
    "1",
    "1"
  };

  static const SscArraySize inputDimensions[54] = {
    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }
  };

  static const char *outputPortPaths[72] = {
    "Vehicle.FL_Revolute.q",
    "Vehicle.FL_Revolute.w",
    "Vehicle.FR_Revolute.q",
    "Vehicle.FR_Revolute.w",
    "Vehicle.RL_Revolute.q",
    "Vehicle.RL_Revolute.w",
    "Vehicle.RR_Revolute.q",
    "Vehicle.RR_Revolute.w",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.ft",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.tt",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.kappa",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.alpha",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.omega",
    "Vehicle.Tire_FL.Magic_Formula_Tire_Force_and_Torque.pb",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.ft",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.tt",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.kappa",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.alpha",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.omega",
    "Vehicle.Tire_FR.Magic_Formula_Tire_Force_and_Torque.pb",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.ft",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.tt",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.kappa",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.alpha",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.omega",
    "Vehicle.Tire_RL.Magic_Formula_Tire_Force_and_Torque.pb",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.ft",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.tt",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.kappa",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.alpha",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.omega",
    "Vehicle.Tire_RR.Magic_Formula_Tire_Force_and_Torque.pb",
    "Vehicle.Aero.Transform_Sensor.vx",
    "Vehicle.Subsystem1.Transform_Sensor.x",
    "Vehicle.Subsystem1.Transform_Sensor.y",
    "Vehicle.Subsystem1.Transform_Sensor1.R",
    "Vehicle.Subsystem2.Transform_Sensor.x",
    "Vehicle.Subsystem2.Transform_Sensor.y",
    "Vehicle.Subsystem2.Transform_Sensor1.R",
    "Vehicle.Subsystem3.Transform_Sensor.x",
    "Vehicle.Subsystem3.Transform_Sensor.y",
    "Vehicle.Subsystem3.Transform_Sensor1.R",
    "Vehicle.Subsystem4.Transform_Sensor.x",
    "Vehicle.Subsystem4.Transform_Sensor.y",
    "Vehicle.Subsystem4.Transform_Sensor1.R",
    "Vehicle.Suspension_Front.Transform_Sensor.z",
    "Vehicle.Suspension_Front.Transform_Sensor1.z",
    "Vehicle.Suspension_Rear.Transform_Sensor.z",
    "Vehicle.Suspension_Rear.Transform_Sensor1.z",
    "Vehicle.World_to_Body.Transform_Sensor.R",
    "Vehicle.World_to_Body.Transform_Sensor.vx",
    "Vehicle.World_to_Body.Transform_Sensor.vy",
    "Vehicle.World_to_Body.Transform_Sensor.vz",
    "Vehicle.World_to_Body.Transform_Sensor.ax",
    "Vehicle.World_to_Body.Transform_Sensor.ay",
    "Vehicle.World_to_Body.Transform_Sensor.az",
    "Vehicle.World_to_Body.Transform_Sensor1.Q",
    "Vehicle.World_to_Body.Transform_Sensor1.x",
    "Vehicle.World_to_Body.Transform_Sensor1.y",
    "Vehicle.World_to_Body.Transform_Sensor1.z",
    "Vehicle.World_to_Unity_FL.Transform_Sensor.x",
    "Vehicle.World_to_Unity_FL.Transform_Sensor.y",
    "Vehicle.World_to_Unity_FL.Transform_Sensor.z",
    "Vehicle.World_to_Unity_FR.Transform_Sensor.x",
    "Vehicle.World_to_Unity_FR.Transform_Sensor.y",
    "Vehicle.World_to_Unity_FR.Transform_Sensor.z",
    "Vehicle.World_to_Unity_RL.Transform_Sensor.x",
    "Vehicle.World_to_Unity_RL.Transform_Sensor.y",
    "Vehicle.World_to_Unity_RL.Transform_Sensor.z",
    "Vehicle.World_to_Unity_RR.Transform_Sensor.x",
    "Vehicle.World_to_Unity_RR.Transform_Sensor.y",
    "Vehicle.World_to_Unity_RR.Transform_Sensor.z"
  };

  static const char *outputUnits[72] = {
    "rad",
    "rad/s",
    "rad",
    "rad/s",
    "rad",
    "rad/s",
    "rad",
    "rad/s",
    "kg*m/s^2",
    "kg*m^2/s^2",
    "1",
    "rad",
    "rad/s",
    "m",
    "kg*m/s^2",
    "kg*m^2/s^2",
    "1",
    "rad",
    "rad/s",
    "m",
    "kg*m/s^2",
    "kg*m^2/s^2",
    "1",
    "rad",
    "rad/s",
    "m",
    "kg*m/s^2",
    "kg*m^2/s^2",
    "1",
    "rad",
    "rad/s",
    "m",
    "m/s",
    "m",
    "m",
    "1",
    "m",
    "m",
    "1",
    "m",
    "m",
    "1",
    "m",
    "m",
    "1",
    "m",
    "m",
    "m",
    "m",
    "1",
    "m/s",
    "m/s",
    "m/s",
    "m/s^2",
    "m/s^2",
    "m/s^2",
    "1",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m",
    "m"
  };

  static const SscArraySize outputDimensions[72] = {
    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 3, "3x1" }, { 3, "3x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 3, "3x1" }, { 3, "3x1" }, { 3, "3x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 3, "3x1" },

    { 3, "3x1" }, { 3, "3x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 3, "3x1" }, { 3, "3x1" }, { 3, "3x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 3, "3x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 9, "3x3" },

    { 1, "1x1" }, { 1, "1x1" }, { 9, "3x3" }, { 1, "1x1" },

    { 1, "1x1" }, { 9, "3x3" }, { 1, "1x1" }, { 1, "1x1" },

    { 9, "3x3" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 9, "3x3" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 4, "4x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" },

    { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }, { 1, "1x1" }
  };

  initIoInfoHelper(54, inputPortPaths, inputUnits, inputDimensions,
                   true, smData);
  initIoInfoHelper(72, outputPortPaths, outputUnits, outputDimensions,
                   false, smData);
}

static
  void initInputDerivs(NeDaePrivateData *smData)
{
  static const int32_T numInputDerivs[54] = {
    0, 0, 0, 0, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0
  };

  PmAllocator *alloc = pm_default_allocator();
  const int_T status = pm_create_int_vector_fields(
    &smData->mNumInputDerivs, smData->mInputVectorSize, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mNumInputDerivs.mX, numInputDerivs,
         54 * sizeof(int32_T));
  smData->mInputOrder = 2;
}

static
  void initDirectFeedthrough(NeDaePrivateData *smData)
{
  static const boolean_T directFeedthroughVector[54] = {
    false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false,
    false, false, false, false
  };

  static const boolean_T directFeedthroughMatrix[15012] = {
    false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true,
    true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true,
    true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true,
    true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true,
    true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    true, true, true, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, true,
    true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, false, false,
    false, false, false, false, true, true, true, true, true, true,
    false, false, false, false, false, false, true, true, true, true,
    true, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, false, false, false,
    false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, false, true, true, true, true, true,
    true, false, false, false, false, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false,
    false, false
  };

  PmAllocator *alloc = pm_default_allocator();

  {
    const int_T status = pm_create_bool_vector_fields(
      &smData->mDirectFeedthroughVector, 54, alloc);
    checkMemAllocStatus(status);
    memcpy(smData->mDirectFeedthroughVector.mX, directFeedthroughVector,
           54 * sizeof(boolean_T));
  }

  {
    const int_T status = pm_create_bool_vector_fields(
      &smData->mDirectFeedthroughMatrix, 15012, alloc);
    checkMemAllocStatus(status);
    memcpy(smData->mDirectFeedthroughMatrix.mX, directFeedthroughMatrix,
           15012 * sizeof(boolean_T));
  }
}

static
  void initOutputDerivProc(NeDaePrivateData *smData)
{
  PmAllocator *alloc = pm_default_allocator();
  static const int32_T outputFunctionMap[139] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0
  };

  smData->mOutputFunctionMap = pm_create_int_vector(139, alloc);
  memcpy(smData->mOutputFunctionMap->mX, outputFunctionMap,
         139 * sizeof(int32_T));
  smData->mNumOutputClasses = 2;
  smData->mHasKinematicOutputs = true;
  smData->mHasDynamicOutputs = true;
  smData->mIsOutputClass0Dynamic = false;
  smData->mDoComputeDynamicOutputs = false;
  smData->mCachedDerivativesAvailable = false;

  {
    size_t i = 0;
    const int_T status = pm_create_real_vector_fields(
      &smData->mCachedDerivatives, 29, pm_default_allocator());
    checkMemAllocStatus(status);
    for (i = 0; i < smData->mCachedDerivatives.mN; ++i)
      smData->mCachedDerivatives.mX[i] = 0.0;
  }
}

#if 0

static void initializeSizePairVector(const SmSizePair *data,
  SmSizePairVector *vector)
{
  const size_t n = sm_core_SmSizePairVector_size(vector);
  size_t i;
  for (i = 0; i < n; ++i, ++data)
    sm_core_SmSizePairVector_setValue(vector, i, data++);
}

#endif

static
  void initAssemblyDelegate(SmMechanismDelegate *delegate)
{
  SmMechanismDelegateScratchpad *scratchpad = NULL;
  static const SmSizePair jointToStageIdx[34] = {
    { 72, 17 }, { 285, 4 }, { 286, 8 }, { 298, 12 }, { 299, 16 }, { 359, 2 },

    { 362, 1 }, { 363, 3 }, { 367, 6 }, { 370, 5 }, { 371, 7 }, { 402, 10 },

    { 405, 9 }, { 406, 11 }, { 410, 14 }, { 413, 13 }, { 414, 15 }, { 444, 18 },

    { 445, 21 }, { 446, 19 }, { 447, 20 }, { 478, 22 }, { 479, 25 }, { 480, 23 },

    { 481, 24 }, { 512, 26 }, { 513, 29 }, { 514, 27 }, { 515, 28 }, { 546, 30 },

    { 547, 33 }, { 548, 31 }, { 549, 32 }, { 570, 0 }
  };

  static const size_t primitiveIndices[34 + 1] = {
    0, 4, 7, 8, 9, 10, 13, 14, 15, 16,
    19, 20, 21, 22, 25, 26, 27, 28, 31, 34,
    35, 36, 37, 40, 41, 42, 43, 46, 47, 48,
    49, 52, 53, 54, 55
  };

  static const SmSizePair stateOffsets[55] = {
    { 0, 7 }, { 1, 8 }, { 2, 9 }, { 3, 10 }, { 13, 16 }, { 14, 17 },

    { 15, 18 }, { 19, 20 }, { 21, 22 }, { 23, 24 }, { 25, 28 }, { 26, 29 },

    { 27, 30 }, { 31, 32 }, { 33, 34 }, { 35, 36 }, { 37, 40 }, { 38, 41 },

    { 39, 42 }, { 43, 44 }, { 45, 46 }, { 47, 48 }, { 49, 52 }, { 50, 53 },

    { 51, 54 }, { 55, 56 }, { 57, 58 }, { 59, 60 }, { 61, 64 }, { 62, 65 },

    { 63, 66 }, { 67, 70 }, { 68, 71 }, { 69, 72 }, { 73, 74 }, { 75, 76 },

    { 77, 78 }, { 79, 82 }, { 80, 83 }, { 81, 84 }, { 85, 86 }, { 87, 88 },

    { 89, 90 }, { 91, 94 }, { 92, 95 }, { 93, 96 }, { 97, 98 }, { 99, 100 },

    { 101, 102 }, { 103, 106 }, { 104, 107 }, { 105, 108 }, { 109, 110 }, { 111,
      112 },

    { 113, 114 }
  };

  static const SmSizePair dofOffsets[55] = {
    { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 6 }, { 6, 7 }, { 7, 8 },

    { 8, 9 }, { 9, 10 }, { 10, 11 }, { 11, 12 }, { 12, 13 }, { 13, 14 },

    { 14, 15 }, { 15, 16 }, { 16, 17 }, { 17, 18 }, { 18, 19 }, { 19, 20 },

    { 20, 21 }, { 21, 22 }, { 22, 23 }, { 23, 24 }, { 24, 25 }, { 25, 26 },

    { 26, 27 }, { 27, 28 }, { 28, 29 }, { 29, 30 }, { 30, 31 }, { 31, 32 },

    { 32, 33 }, { 33, 34 }, { 34, 35 }, { 35, 36 }, { 36, 37 }, { 37, 38 },

    { 38, 39 }, { 39, 40 }, { 40, 41 }, { 41, 42 }, { 42, 43 }, { 43, 44 },

    { 44, 45 }, { 45, 46 }, { 46, 47 }, { 47, 48 }, { 48, 49 }, { 49, 50 },

    { 50, 51 }, { 51, 52 }, { 52, 53 }, { 53, 54 }, { 54, 55 }, { 55, 56 },

    { 56, 57 }
  };

  static const SmSizePair *flexBodyToStageIdx = NULL;
  static const SmSizePair *flexStateOffsets = NULL;
  static const size_t *flexibleStages = NULL;
  static const size_t remodIndices[24] = {
    19, 21, 23, 31, 33, 35, 43, 45, 47, 55,
    57, 59, 73, 75, 77, 85, 87, 89, 97, 99,
    101, 109, 111, 113
  };

  static const size_t equationsPerConstraint[1] = {
    3
  };

  static const int32_T hasAllVelocityDisabledEquations[1] = {
    0
  };

  static const int32_T runtimeEnabledEquations[3] = {
    1, 1, 1
  };

  static const size_t dofToVelSlot[57] = {
    7, 8, 9, 10, 11, 12, 16, 17, 18, 20,
    22, 24, 28, 29, 30, 32, 34, 36, 40, 41,
    42, 44, 46, 48, 52, 53, 54, 56, 58, 60,
    64, 65, 66, 70, 71, 72, 74, 76, 78, 82,
    83, 84, 86, 88, 90, 94, 95, 96, 98, 100,
    102, 106, 107, 108, 110, 112, 114
  };

  static const size_t constraintDofs[9] = {
    30, 31, 32, 0, 1, 2, 3, 4, 5
  };

  static const size_t constraintDofOffsets[1 + 1] = {
    0, 9
  };

  const size_t Jm = 3;
  const size_t Jn = 57;
  SmSizePair zeroSizePair;
  zeroSizePair.mFirst = zeroSizePair.mSecond = 0;
  sm_core_MechanismDelegate_allocScratchpad(delegate);
  scratchpad = delegate->mScratchpad;
  delegate->mTargetStrengthFree = 0;
  delegate->mTargetStrengthSuggested = 1;
  delegate->mTargetStrengthDesired = 2;
  delegate->mTargetStrengthRequired = 3;
  delegate->mConsistencyTol = +1.000000000000000078e-15;
  delegate->mTreeJointDof = 57;
  delegate->mDof = 57;
  delegate->mStateSize = 115;
  delegate->mContinuousStateSize = 115;
  delegate->mModeVectorSize = 0;
  delegate->mNumStages = 34;
  delegate->mNumConstraints = 1;
  delegate->mNumAllConstraintEquations = 3;
  sm_core_SmSizePairVector_create(
    &delegate->mJointToStageIdx, 34, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mJointToStageIdx),
         jointToStageIdx, 34 * sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &delegate->mPrimitiveIndices, delegate->mNumStages + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mPrimitiveIndices),
         primitiveIndices, (delegate->mNumStages + 1) * sizeof(size_t));
  sm_core_SmSizePairVector_create(
    &delegate->mStateOffsets, 55, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mStateOffsets),
         stateOffsets, 55 * sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &delegate->mDofOffsets, 55, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mDofOffsets),
         dofOffsets, 55 * sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &delegate->mFlexBodyToStageIdx, 0, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mFlexBodyToStageIdx),
         flexBodyToStageIdx, 0 *sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &delegate->mFlexStateOffsets, 0, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mFlexStateOffsets),
         flexStateOffsets, 0 *sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &delegate->mFlexibleStages, 0, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mFlexibleStages),
         flexibleStages, 0 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mRemodIndices, 24, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mRemodIndices),
         remodIndices, 24 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mEquationsPerConstraint, delegate->mNumConstraints, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mEquationsPerConstraint),
         equationsPerConstraint, delegate->mNumConstraints * sizeof(size_t));
  sm_core_SmIntVector_create(
    &delegate->mHasAllVelocityDisabledEquations, delegate->mNumConstraints, 0);
  memcpy(
         sm_core_SmIntVector_nonConstValues
         (&delegate->mHasAllVelocityDisabledEquations),
         hasAllVelocityDisabledEquations, delegate->mNumConstraints * sizeof
         (int32_T));
  sm_core_SmIntVector_create(
    &delegate->mRunTimeEnabledEquations,
    delegate->mNumAllConstraintEquations, 0);
  memcpy(
         sm_core_SmIntVector_nonConstValues(&delegate->mRunTimeEnabledEquations),
         runtimeEnabledEquations, delegate->mNumAllConstraintEquations *
         sizeof(int32_T));
  sm_core_SmSizeTVector_create(
    &delegate->mDofToVelSlot, delegate->mDof, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mDofToVelSlot),
         dofToVelSlot, delegate->mDof * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mConstraintDofs, 9, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mConstraintDofs),
         constraintDofs, 9 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mConstraintDofOffsets, delegate->mNumConstraints + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mConstraintDofOffsets),
         constraintDofOffsets, (delegate->mNumConstraints + 1) * sizeof(size_t));
  sm_core_SmBoundedSet_create(&scratchpad->mPosRequired, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mPosDesired, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mPosSuggested, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mPosFree, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mPosNonRequired, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mPosSuggAndFree, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mVelRequired, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mVelDesired, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mVelSuggested, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mVelFree, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mVelNonRequired, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mVelSuggAndFree, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mConstraintFilter, 1);
  sm_core_SmBoundedSet_create(&scratchpad->mActiveConstraints, 1);
  sm_core_SmBoundedSet_create(&scratchpad->mActiveDofs, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mActiveDofs0, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mNewConstraints, 1);
  sm_core_SmBoundedSet_create(&scratchpad->mNewDofs, 57);
  sm_core_SmBoundedSet_create(&scratchpad->mUnsatisfiedConstraints, 1);
  sm_core_SmSizeTVector_create(&scratchpad->mActiveConstraintsVect,
    1, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mActiveDofsVect, 57, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mFullDofToActiveDof, 57, 0);
  sm_core_SmSizePairVector_create(
    &scratchpad->mPartiallyPosTargetedPrims, 55, &zeroSizePair);
  sm_core_SmSizePairVector_create(
    &scratchpad->mPartiallyVelTargetedPrims, 55, &zeroSizePair);
  sm_core_SmSizeTVector_create(&scratchpad->mPosPartialTypes, 55, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mVelPartialTypes, 55, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mPartiallyActivePrims, 55, 0);
  sm_core_SmSizePairVector_create(
    &scratchpad->mBaseFrameVelOffsets, 1, &zeroSizePair);
  sm_core_SmSizePairVector_create(&scratchpad->mCvQuaternionVelOffsets,
    0,
    &zeroSizePair);
  sm_core_SmRealVector_create(&scratchpad->mCvQuaternionAzimuthValues,
    0, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mInitialState, 115, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mStartState, 115, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mTestState, 115, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mFullStateVector, 115, 0.0);
  sm_core_SmIntVector_create(&scratchpad->mModeVector, 0, 0);
  sm_core_SmRealVector_create(&scratchpad->mJacobianRowMaj, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mJacobian, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mJacobianPrimSubmatrix, Jm * 6, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mConstraintNonhomoTerms, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mBestConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mDeltas,
    Jn * (Jm <= Jn ? Jm : Jn), 0.0);
  sm_core_SmRealVector_create(&scratchpad->mSvdWork, 3727, 0.0);
  sm_core_SmRealVector_create(
    &scratchpad->mLineSearchScaledDeltaVect, 57, 0.0);
  sm_core_SmRealVector_create(
    &scratchpad->mLineSearchTestStateVect, 115, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mLineSearchErrorVect, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mActiveDofVelsVect, 57, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mVelSystemRhs, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mMotionData, 694, 0.0);
  delegate->mSetTargets = KIMMCar_ff62ad8f_49_setTargets;
  delegate->mResetStateVector = KIMMCar_ff62ad8f_49_resetAsmStateVector;
  delegate->mInitializeTrackedAngleState =
    KIMMCar_ff62ad8f_49_initializeTrackedAngleState;
  delegate->mComputeDiscreteState = KIMMCar_ff62ad8f_49_computeDiscreteState;
  delegate->mAdjustPosition = KIMMCar_ff62ad8f_49_adjustPosition;
  delegate->mPerturbJointPrimitiveState =
    KIMMCar_ff62ad8f_49_perturbAsmJointPrimitiveState;
  delegate->mPerturbFlexibleBodyState = NULL;
  delegate->mComputePosDofBlendMatrix =
    KIMMCar_ff62ad8f_49_computePosDofBlendMatrix;
  delegate->mComputeVelDofBlendMatrix =
    KIMMCar_ff62ad8f_49_computeVelDofBlendMatrix;
  delegate->mProjectPartiallyTargetedPos =
    KIMMCar_ff62ad8f_49_projectPartiallyTargetedPos;
  delegate->mPropagateMotion = KIMMCar_ff62ad8f_49_propagateMotion;
  delegate->mComputeAssemblyPosError =
    KIMMCar_ff62ad8f_49_computeAssemblyPosError;
  delegate->mComputeAssemblyJacobian =
    KIMMCar_ff62ad8f_49_computeAssemblyJacobian;
  delegate->mComputeFullAssemblyJacobian =
    KIMMCar_ff62ad8f_49_computeFullAssemblyJacobian;
  delegate->mIsInKinematicSingularity =
    KIMMCar_ff62ad8f_49_isInKinematicSingularity;
  delegate->mConvertStateVector = KIMMCar_ff62ad8f_49_convertStateVector;
  delegate->mConstructStateVector = NULL;
  delegate->mExtractSolverStateVector = NULL;
  delegate->mExtractDiscreteStateVector = NULL;
  delegate->mIsPositionViolation = NULL;
  delegate->mIsVelocityViolation = NULL;
  delegate->mProjectStateSim = NULL;
  delegate->mComputeConstraintError = NULL;
  delegate->mResetModeVector = NULL;
  delegate->mHasJointUpwardModeChange = NULL;
  delegate->mPerformJointUpwardModeChange = NULL;
  delegate->mOnModeChangedCutJoints = NULL;
  delegate->mSetVariableModeJointsToLocked = NULL;
  delegate->mMech = NULL;
}

static
  void initSimulationDelegate(SmMechanismDelegate *delegate)
{
  SmMechanismDelegateScratchpad *scratchpad = NULL;
  static const SmSizePair jointToStageIdx[34] = {
    { 72, 0 }, { 103, 1 }, { 285, 5 }, { 286, 9 }, { 298, 13 }, { 299, 17 },

    { 359, 3 }, { 362, 2 }, { 363, 4 }, { 367, 7 }, { 370, 6 }, { 371, 8 },

    { 402, 11 }, { 405, 10 }, { 406, 12 }, { 410, 15 }, { 413, 14 }, { 414, 16 },

    { 444, 18 }, { 445, 21 }, { 446, 19 }, { 447, 20 }, { 478, 22 }, { 479, 25 },

    { 480, 23 }, { 481, 24 }, { 512, 26 }, { 513, 29 }, { 514, 27 }, { 515, 28 },

    { 546, 30 }, { 547, 33 }, { 548, 31 }, { 549, 32 }
  };

  static const size_t primitiveIndices[34 + 1] = {
    0, 3, 4, 7, 8, 9, 10, 13, 14, 15,
    16, 19, 20, 21, 22, 25, 26, 27, 28, 31,
    32, 33, 34, 37, 38, 39, 40, 43, 44, 45,
    46, 49, 50, 51, 52
  };

  static const SmSizePair stateOffsets[52] = {
    { 0, 3 }, { 1, 4 }, { 2, 5 }, { 6, 10 }, { 13, 16 }, { 14, 17 },

    { 15, 18 }, { 19, 20 }, { 21, 22 }, { 23, 24 }, { 25, 28 }, { 26, 29 },

    { 27, 30 }, { 31, 32 }, { 33, 34 }, { 35, 36 }, { 37, 40 }, { 38, 41 },

    { 39, 42 }, { 43, 44 }, { 45, 46 }, { 47, 48 }, { 49, 52 }, { 50, 53 },

    { 51, 54 }, { 55, 56 }, { 57, 58 }, { 59, 60 }, { 61, 64 }, { 62, 65 },

    { 63, 66 }, { 67, 68 }, { 69, 70 }, { 71, 72 }, { 73, 76 }, { 74, 77 },

    { 75, 78 }, { 79, 80 }, { 81, 82 }, { 83, 84 }, { 85, 88 }, { 86, 89 },

    { 87, 90 }, { 91, 92 }, { 93, 94 }, { 95, 96 }, { 97, 100 }, { 98, 101 },

    { 99, 102 }, { 103, 104 }, { 105, 106 }, { 107, 108 }
  };

  static const SmSizePair dofOffsets[52] = {
    { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 6 }, { 6, 7 }, { 7, 8 },

    { 8, 9 }, { 9, 10 }, { 10, 11 }, { 11, 12 }, { 12, 13 }, { 13, 14 },

    { 14, 15 }, { 15, 16 }, { 16, 17 }, { 17, 18 }, { 18, 19 }, { 19, 20 },

    { 20, 21 }, { 21, 22 }, { 22, 23 }, { 23, 24 }, { 24, 25 }, { 25, 26 },

    { 26, 27 }, { 27, 28 }, { 28, 29 }, { 29, 30 }, { 30, 31 }, { 31, 32 },

    { 32, 33 }, { 33, 34 }, { 34, 35 }, { 35, 36 }, { 36, 37 }, { 37, 38 },

    { 38, 39 }, { 39, 40 }, { 40, 41 }, { 41, 42 }, { 42, 43 }, { 43, 44 },

    { 44, 45 }, { 45, 46 }, { 46, 47 }, { 47, 48 }, { 48, 49 }, { 49, 50 },

    { 50, 51 }, { 51, 52 }, { 52, 53 }, { 53, 54 }
  };

  static const SmSizePair *flexBodyToStageIdx = NULL;
  static const SmSizePair *flexStateOffsets = NULL;
  static const size_t *flexibleStages = NULL;
  static const size_t remodIndices[24] = {
    19, 21, 23, 31, 33, 35, 43, 45, 47, 55,
    57, 59, 67, 69, 71, 79, 81, 83, 91, 93,
    95, 103, 105, 107
  };

  static const size_t equationsPerConstraint[1] = {
    0
  };

  static const int32_T hasAllVelocityDisabledEquations[1] = {
    0
  };

  static const int32_T *runtimeEnabledEquations = NULL;
  static const size_t dofToVelSlot[54] = {
    3, 4, 5, 10, 11, 12, 16, 17, 18, 20,
    22, 24, 28, 29, 30, 32, 34, 36, 40, 41,
    42, 44, 46, 48, 52, 53, 54, 56, 58, 60,
    64, 65, 66, 68, 70, 72, 76, 77, 78, 80,
    82, 84, 88, 89, 90, 92, 94, 96, 100, 101,
    102, 104, 106, 108
  };

  static const size_t constraintDofs[6] = {
    0, 1, 2, 3, 4, 5
  };

  static const size_t constraintDofOffsets[1 + 1] = {
    0, 6
  };

  const size_t Jm = 0;
  const size_t Jn = 54;
  SmSizePair zeroSizePair;
  zeroSizePair.mFirst = zeroSizePair.mSecond = 0;
  sm_core_MechanismDelegate_allocScratchpad(delegate);
  scratchpad = delegate->mScratchpad;
  delegate->mTargetStrengthFree = 0;
  delegate->mTargetStrengthSuggested = 1;
  delegate->mTargetStrengthDesired = 2;
  delegate->mTargetStrengthRequired = 3;
  delegate->mConsistencyTol = +1.000000000000000078e-15;
  delegate->mTreeJointDof = 54;
  delegate->mDof = 54;
  delegate->mStateSize = 109;
  delegate->mContinuousStateSize = 109;
  delegate->mModeVectorSize = 0;
  delegate->mNumStages = 34;
  delegate->mNumConstraints = 1;
  delegate->mNumAllConstraintEquations = 0;
  sm_core_SmSizePairVector_create(
    &delegate->mJointToStageIdx, 34, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mJointToStageIdx),
         jointToStageIdx, 34 * sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &delegate->mPrimitiveIndices, delegate->mNumStages + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mPrimitiveIndices),
         primitiveIndices, (delegate->mNumStages + 1) * sizeof(size_t));
  sm_core_SmSizePairVector_create(
    &delegate->mStateOffsets, 52, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mStateOffsets),
         stateOffsets, 52 * sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &delegate->mDofOffsets, 52, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mDofOffsets),
         dofOffsets, 52 * sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &delegate->mFlexBodyToStageIdx, 0, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mFlexBodyToStageIdx),
         flexBodyToStageIdx, 0 *sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &delegate->mFlexStateOffsets, 0, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mFlexStateOffsets),
         flexStateOffsets, 0 *sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &delegate->mFlexibleStages, 0, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mFlexibleStages),
         flexibleStages, 0 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mRemodIndices, 24, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mRemodIndices),
         remodIndices, 24 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mEquationsPerConstraint, delegate->mNumConstraints, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mEquationsPerConstraint),
         equationsPerConstraint, delegate->mNumConstraints * sizeof(size_t));
  sm_core_SmIntVector_create(
    &delegate->mHasAllVelocityDisabledEquations, delegate->mNumConstraints, 0);
  memcpy(sm_core_SmIntVector_nonConstValues
         (&delegate->mHasAllVelocityDisabledEquations),
         hasAllVelocityDisabledEquations, delegate->mNumConstraints * sizeof
         (int32_T));
  sm_core_SmIntVector_create(
    &delegate->mRunTimeEnabledEquations,
    delegate->mNumAllConstraintEquations, 0);
  memcpy(
         sm_core_SmIntVector_nonConstValues(&delegate->mRunTimeEnabledEquations),
         runtimeEnabledEquations, delegate->mNumAllConstraintEquations *
         sizeof(int32_T));
  sm_core_SmSizeTVector_create(
    &delegate->mDofToVelSlot, delegate->mDof, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mDofToVelSlot),
         dofToVelSlot, delegate->mDof * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mConstraintDofs, 6, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mConstraintDofs),
         constraintDofs, 6 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mConstraintDofOffsets, delegate->mNumConstraints + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mConstraintDofOffsets),
         constraintDofOffsets, (delegate->mNumConstraints + 1) * sizeof(size_t));
  sm_core_SmBoundedSet_create(&scratchpad->mPosRequired, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mPosDesired, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mPosSuggested, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mPosFree, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mPosNonRequired, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mPosSuggAndFree, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mVelRequired, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mVelDesired, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mVelSuggested, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mVelFree, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mVelNonRequired, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mVelSuggAndFree, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mConstraintFilter, 1);
  sm_core_SmBoundedSet_create(&scratchpad->mActiveConstraints, 1);
  sm_core_SmBoundedSet_create(&scratchpad->mActiveDofs, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mActiveDofs0, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mNewConstraints, 1);
  sm_core_SmBoundedSet_create(&scratchpad->mNewDofs, 54);
  sm_core_SmBoundedSet_create(&scratchpad->mUnsatisfiedConstraints, 1);
  sm_core_SmSizeTVector_create(&scratchpad->mActiveConstraintsVect,
    1, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mActiveDofsVect, 54, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mFullDofToActiveDof, 54, 0);
  sm_core_SmSizePairVector_create(
    &scratchpad->mPartiallyPosTargetedPrims, 52, &zeroSizePair);
  sm_core_SmSizePairVector_create(
    &scratchpad->mPartiallyVelTargetedPrims, 52, &zeroSizePair);
  sm_core_SmSizeTVector_create(&scratchpad->mPosPartialTypes, 52, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mVelPartialTypes, 52, 0);
  sm_core_SmSizeTVector_create(&scratchpad->mPartiallyActivePrims, 52, 0);
  sm_core_SmSizePairVector_create(
    &scratchpad->mBaseFrameVelOffsets, 1, &zeroSizePair);
  sm_core_SmSizePairVector_create(&scratchpad->mCvQuaternionVelOffsets,
    0,
    &zeroSizePair);
  sm_core_SmRealVector_create(&scratchpad->mCvQuaternionAzimuthValues,
    0, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mInitialState, 109, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mStartState, 109, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mTestState, 109, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mFullStateVector, 109, 0.0);
  sm_core_SmIntVector_create(&scratchpad->mModeVector, 0, 0);
  sm_core_SmRealVector_create(&scratchpad->mJacobianRowMaj, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mJacobian, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mJacobianPrimSubmatrix, Jm * 6, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mConstraintNonhomoTerms, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mBestConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mDeltas,
    Jn * (Jm <= Jn ? Jm : Jn), 0.0);
  sm_core_SmRealVector_create(&scratchpad->mSvdWork, 3025, 0.0);
  sm_core_SmRealVector_create(
    &scratchpad->mLineSearchScaledDeltaVect, 54, 0.0);
  sm_core_SmRealVector_create(
    &scratchpad->mLineSearchTestStateVect, 109, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mLineSearchErrorVect, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mActiveDofVelsVect, 54, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mVelSystemRhs, Jm, 0.0);
  sm_core_SmRealVector_create(&scratchpad->mMotionData, 701, 0.0);
  delegate->mSetTargets = NULL;
  delegate->mResetStateVector = KIMMCar_ff62ad8f_49_resetSimStateVector;
  delegate->mInitializeTrackedAngleState = NULL;
  delegate->mComputeDiscreteState = NULL;
  delegate->mAdjustPosition = NULL;
  delegate->mPerturbJointPrimitiveState =
    KIMMCar_ff62ad8f_49_perturbSimJointPrimitiveState;
  delegate->mPerturbFlexibleBodyState =
    KIMMCar_ff62ad8f_49_perturbFlexibleBodyState;
  delegate->mComputePosDofBlendMatrix = NULL;
  delegate->mComputeVelDofBlendMatrix = NULL;
  delegate->mProjectPartiallyTargetedPos = NULL;
  delegate->mPropagateMotion = NULL;
  delegate->mComputeAssemblyPosError = NULL;
  delegate->mComputeAssemblyJacobian = NULL;
  delegate->mComputeFullAssemblyJacobian = NULL;
  delegate->mIsInKinematicSingularity = NULL;
  delegate->mConvertStateVector = NULL;
  delegate->mConstructStateVector = KIMMCar_ff62ad8f_49_constructStateVector;
  delegate->mExtractSolverStateVector =
    KIMMCar_ff62ad8f_49_extractSolverStateVector;
  delegate->mExtractDiscreteStateVector =
    KIMMCar_ff62ad8f_49_extractDiscreteStateVector;
  delegate->mIsPositionViolation = KIMMCar_ff62ad8f_49_isPositionViolation;
  delegate->mIsVelocityViolation = KIMMCar_ff62ad8f_49_isVelocityViolation;
  delegate->mProjectStateSim = KIMMCar_ff62ad8f_49_projectStateSim;
  delegate->mComputeConstraintError = KIMMCar_ff62ad8f_49_computeConstraintError;
  delegate->mResetModeVector = KIMMCar_ff62ad8f_49_resetModeVector;
  delegate->mHasJointUpwardModeChange =
    KIMMCar_ff62ad8f_49_hasJointUpwardModeChange;
  delegate->mPerformJointUpwardModeChange =
    KIMMCar_ff62ad8f_49_performJointUpwardModeChange;
  delegate->mOnModeChangedCutJoints = KIMMCar_ff62ad8f_49_onModeChangedCutJoints;
  delegate->mSetVariableModeJointsToLocked =
    KIMMCar_ff62ad8f_49_setVariableModeJointsToLocked;
  delegate->mMech = NULL;
}

static
  void initMechanismDelegates(NeDaePrivateData *smData)
{
  PmAllocator *alloc = pm_default_allocator();
  static const size_t motionInputOffsets[40] = {
    5, 6, 4, 7, 9, 10, 8, 11, 13, 14,
    12, 15, 17, 18, 16, 19, 20, 21, 22, 24,
    25, 23, 26, 27, 28, 30, 31, 29, 32, 33,
    34, 36, 37, 35, 38, 39, 40, 42, 43, 41
  };

  static const boolean_T *maybeLockedPrimHasModes = NULL;
  static const size_t *maybeLockedPrimModeOffsets = NULL;
  int_T status = 0;
  initAssemblyDelegate(&smData->mAssemblyDelegate);
  initSimulationDelegate(&smData->mSimulationDelegate);
  status = pm_create_size_vector_fields(
    &smData->mMotionInputOffsets, smData->mNumMotionInputPrimitives, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mMotionInputOffsets.mX, motionInputOffsets,
         40 * sizeof(size_t));
  status = pm_create_bool_vector_fields(
    &smData->mMaybeLockedPrimHasModes, smData->mNumMaybeLockedPrimitives,
    alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mMaybeLockedPrimHasModes.mX, maybeLockedPrimHasModes,
         0 * sizeof(boolean_T));
  status = pm_create_size_vector_fields(
    &smData->mMaybeLockedPrimModeOffsets, smData->mNumMaybeLockedPrimitives,
    alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mMaybeLockedPrimModeOffsets.mX, maybeLockedPrimModeOffsets,
         0 * sizeof(size_t));
}

static
  void initComputationFcnPtrs(NeDaePrivateData *smData)
{
  smData->mSetParametersFcn = dae_cg_setParameters_function;
  smData->mPAssertFcn = dae_cg_pAssert_method;
  smData->mDerivativeFcn = dae_cg_deriv_method;
  smData->mNumJacPerturbLoBoundsFcn = dae_cg_numJacPerturbLoBounds_method;
  smData->mNumJacPerturbHiBoundsFcn = dae_cg_numJacPerturbHiBounds_method;
  smData->mOutputFcn = dae_cg_compOutputs_method;
  smData->mModeFcn = dae_cg_mode_method;
  smData->mZeroCrossingFcn = dae_cg_zeroCrossing_method;
  smData->mProjectionFcn = dae_cg_project_solve;
  smData->mCIC_MODE_Fcn = dae_cg_CIC_MODE_solve;
  smData->mCheckFcn =
    (smData->mStateVectorSize == 0) ? dae_cg_check_solve : NULL;
  smData->mAssemblyFcn = dae_cg_assemble_solve;
  smData->mSetupLoggerFcn = dae_cg_setupLoggerFcn;
  smData->mLogFcn = dae_cg_recordLog_method;
  smData->mResidualsFcn = NULL;
  smData->mLinearizeFcn = NULL;
  smData->mGenerateFcn = NULL;
}

static
  void initLiveLinkToSm(NeDaePrivateData *smData)
{
  smData->mLiveSmLink = NULL;
  smData->mLiveSmLink_destroy = NULL;
  smData->mLiveSmLink_copy = NULL;
}

void KIMMCar_ff62ad8f_49_NeDaePrivateData_create(NeDaePrivateData *smData)
{
  initBasicAttributes (smData);
  initStateVector (smData);
  initAsserts (smData);
  initModeVector (smData);
  initZeroCrossings (smData);
  initVariables (smData);
  initRuntimeParameters (smData);
  initIoInfo (smData);
  initInputDerivs (smData);
  initDirectFeedthrough (smData);
  initOutputDerivProc (smData);
  initMechanismDelegates (smData);
  initComputationFcnPtrs (smData);
  initLiveLinkToSm (smData);
}
