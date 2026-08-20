#include "KIMMCar_macros.h"
/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'KIMMCar/Vehicle/World/Solver Configuration1'.
 */

#include "ne_std.h"
#include "pm_default_allocator.h"
#include "ssc_dae.h"
#include "sm_ssci_NeDaePrivateData.h"

NeDae *sm_ssci_constructDae(NeDaePrivateData *smData);
void KIMMCar_ff62ad8f_49_NeDaePrivateData_create(NeDaePrivateData *smData);
void KIMMCar_ff62ad8f_49_dae(
  NeDae **dae,
  const NeModelParameters *modelParams,
  const NeSolverParameters *solverParams)
{
  PmAllocator *alloc = pm_default_allocator();
  NeDaePrivateData *smData =
    (NeDaePrivateData *) alloc->mCallocFcn(alloc, sizeof(NeDaePrivateData), 1);
  (void) modelParams;
  (void) solverParams;
  KIMMCar_ff62ad8f_49_NeDaePrivateData_create(smData);
  *dae = sm_ssci_constructDae(smData);
}
