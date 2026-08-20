#include "KIMMCar_macros.h"
/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'KIMMCar/Vehicle/World/Solver Configuration1'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "pm_default_allocator.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"

const sm_core_compiler_Plane *KIMMCar_ff62ad8f_49_geometry_0(const
  RuntimeDerivedValuesBundle *rtdv)
{
  static const sm_core_compiler_Plane plane = { 0 };

  (void) rtdv;
  return &plane;
}

void KIMMCar_ff62ad8f_49_initializeGeometries(const struct
  RuntimeDerivedValuesBundleTag *rtdv)
{
  KIMMCar_ff62ad8f_49_geometry_0(rtdv);
}
