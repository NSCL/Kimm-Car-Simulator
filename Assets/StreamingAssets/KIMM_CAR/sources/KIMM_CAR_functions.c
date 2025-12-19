#include "omc_simulation_settings.h"
#include "KIMM_CAR_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "KIMM_CAR_includes.h"


DLLExport
real_array omc_calc__coordinate(threadData_t *threadData, real_array _yaw_pitch_roll)
{
  real_array _coord;
  real_array _rotmat_yaw;
  real_array _rotmat_pitch;
  real_array _rotmat_roll;
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  real_array tmp4;
  real_array tmp5;
  real_array tmp6;
  real_array tmp7;
  real_array tmp8;
  real_array tmp9;
  real_array tmp10;
  real_array tmp11;
  real_array tmp12;
  real_array tmp13;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_coord), 2, (_index_t)3, (_index_t)3); // _coord has no default value.
  alloc_real_array(&(_rotmat_yaw), 2, (_index_t)3, (_index_t)3); // _rotmat_yaw has no default value.
  alloc_real_array(&(_rotmat_pitch), 2, (_index_t)3, (_index_t)3); // _rotmat_pitch has no default value.
  alloc_real_array(&(_rotmat_roll), 2, (_index_t)3, (_index_t)3); // _rotmat_roll has no default value.
  array_alloc_scalar_real_array(&tmp2, 3, (modelica_real)cos(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 1), ((modelica_integer) 1))), (modelica_real)(-sin(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 1), ((modelica_integer) 1)))), (modelica_real)0.0);
  array_alloc_scalar_real_array(&tmp3, 3, (modelica_real)sin(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 1), ((modelica_integer) 1))), (modelica_real)cos(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 1), ((modelica_integer) 1))), (modelica_real)0.0);
  array_alloc_real_array(&tmp1, 3, tmp2, tmp3, _OMC_LIT0);
  real_array_copy_data(tmp1, _rotmat_yaw);

  array_alloc_scalar_real_array(&tmp5, 3, (modelica_real)cos(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 2), ((modelica_integer) 1))), (modelica_real)0.0, (modelica_real)sin(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 2), ((modelica_integer) 1))));
  array_alloc_scalar_real_array(&tmp6, 3, (modelica_real)(-sin(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 2), ((modelica_integer) 1)))), (modelica_real)0.0, (modelica_real)cos(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 2), ((modelica_integer) 1))));
  array_alloc_real_array(&tmp4, 3, tmp5, _OMC_LIT1, tmp6);
  real_array_copy_data(tmp4, _rotmat_pitch);

  array_alloc_scalar_real_array(&tmp8, 3, (modelica_real)0.0, (modelica_real)cos(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 3), ((modelica_integer) 1))), (modelica_real)(-sin(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 3), ((modelica_integer) 1)))));
  array_alloc_scalar_real_array(&tmp9, 3, (modelica_real)0.0, (modelica_real)sin(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 3), ((modelica_integer) 1))), (modelica_real)cos(real_array_get(_yaw_pitch_roll, 2, ((modelica_integer) 3), ((modelica_integer) 1))));
  array_alloc_real_array(&tmp7, 3, _OMC_LIT2, tmp8, tmp9);
  real_array_copy_data(tmp7, _rotmat_roll);

  array_alloc_scalar_real_array(&tmp11, 3, (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 1))), (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 2))), (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 1), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp12, 3, (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 1))), (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 2))), (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 2), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 3))));
  array_alloc_scalar_real_array(&tmp13, 3, (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 1))), (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 2))), (modelica_real)((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 1))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 1)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 2))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 2)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + ((real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 1))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 1), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 2))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 2), ((modelica_integer) 3))) + (real_array_get(_rotmat_yaw, 2, ((modelica_integer) 3), ((modelica_integer) 3))) * (real_array_get(_rotmat_pitch, 2, ((modelica_integer) 3), ((modelica_integer) 3)))) * (real_array_get(_rotmat_roll, 2, ((modelica_integer) 3), ((modelica_integer) 3))));
  array_alloc_real_array(&tmp10, 3, tmp11, tmp12, tmp13);
  real_array_copy_data(tmp10, _coord);
  _return: OMC_LABEL_UNUSED
  return _coord;
}
modelica_metatype boxptr_calc__coordinate(threadData_t *threadData, modelica_metatype _yaw_pitch_roll)
{
  real_array _coord;
  modelica_metatype out_coord;
  _coord = omc_calc__coordinate(threadData, *((base_array_t*)_yaw_pitch_roll));
  out_coord = mmc_mk_modelica_array(_coord);
  return out_coord;
}

DLLExport
real_array omc_change__of__coordinate(threadData_t *threadData, real_array _target_coordinate, real_array _vector_wrt_world)
{
  real_array _vector_wrt_target_coordinate;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_vector_wrt_target_coordinate), 2, (_index_t)3, (_index_t)1); // _vector_wrt_target_coordinate has no default value.
  real_array_copy_data(mul_alloc_real_matrix_product_smart(omc_Modelica_Math_Matrices_inv(threadData, _target_coordinate), _vector_wrt_world), _vector_wrt_target_coordinate);
  _return: OMC_LABEL_UNUSED
  return _vector_wrt_target_coordinate;
}
modelica_metatype boxptr_change__of__coordinate(threadData_t *threadData, modelica_metatype _target_coordinate, modelica_metatype _vector_wrt_world)
{
  real_array _vector_wrt_target_coordinate;
  modelica_metatype out_vector_wrt_target_coordinate;
  _vector_wrt_target_coordinate = omc_change__of__coordinate(threadData, *((base_array_t*)_target_coordinate), *((base_array_t*)_vector_wrt_world));
  out_vector_wrt_target_coordinate = mmc_mk_modelica_array(_vector_wrt_target_coordinate);
  return out_vector_wrt_target_coordinate;
}

DLLExport
real_array omc_normalized__tire__force__coordinate(threadData_t *threadData, real_array _forward, real_array _left)
{
  real_array _norm_coord;
  real_array _normalized_forward;
  real_array _normalized_left;
  real_array _normalized_up;
  real_array tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  real_array tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  real_array tmp27;
  real_array tmp28;
  real_array tmp29;
  real_array tmp30;
  real_array tmp31;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_norm_coord), 2, (_index_t)3, (_index_t)3); // _norm_coord has no default value.
  alloc_real_array(&(_normalized_forward), 1, (_index_t)3); // _normalized_forward has no default value.
  alloc_real_array(&(_normalized_left), 1, (_index_t)3); // _normalized_left has no default value.
  alloc_real_array(&(_normalized_up), 1, (_index_t)3); // _normalized_up has no default value.
  tmp2 = real_array_get(_forward, 1, ((modelica_integer) 1));
  tmp3 = real_array_get(_forward, 1, ((modelica_integer) 2));
  tmp4 = real_array_get(_forward, 1, ((modelica_integer) 3));
  tmp5 = sqrt((tmp2 * tmp2) + (tmp3 * tmp3) + (tmp4 * tmp4));
  if (tmp5 == 0) {throwStreamPrint(threadData, "Division by zero %s", "forward[1] / sqrt(forward[1] ^ 2.0 + forward[2] ^ 2.0 + forward[3] ^ 2.0)");}
  tmp6 = real_array_get(_forward, 1, ((modelica_integer) 1));
  tmp7 = real_array_get(_forward, 1, ((modelica_integer) 2));
  tmp8 = real_array_get(_forward, 1, ((modelica_integer) 3));
  tmp9 = sqrt((tmp6 * tmp6) + (tmp7 * tmp7) + (tmp8 * tmp8));
  if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s", "forward[2] / sqrt(forward[1] ^ 2.0 + forward[2] ^ 2.0 + forward[3] ^ 2.0)");}
  tmp10 = real_array_get(_forward, 1, ((modelica_integer) 1));
  tmp11 = real_array_get(_forward, 1, ((modelica_integer) 2));
  tmp12 = real_array_get(_forward, 1, ((modelica_integer) 3));
  tmp13 = sqrt((tmp10 * tmp10) + (tmp11 * tmp11) + (tmp12 * tmp12));
  if (tmp13 == 0) {throwStreamPrint(threadData, "Division by zero %s", "forward[3] / sqrt(forward[1] ^ 2.0 + forward[2] ^ 2.0 + forward[3] ^ 2.0)");}
  array_alloc_scalar_real_array(&tmp1, 3, (modelica_real)(real_array_get(_forward, 1, ((modelica_integer) 1))) / tmp5, (modelica_real)(real_array_get(_forward, 1, ((modelica_integer) 2))) / tmp9, (modelica_real)(real_array_get(_forward, 1, ((modelica_integer) 3))) / tmp13);
  real_array_copy_data(tmp1, _normalized_forward);

  tmp15 = real_array_get(_left, 1, ((modelica_integer) 1));
  tmp16 = real_array_get(_left, 1, ((modelica_integer) 2));
  tmp17 = real_array_get(_left, 1, ((modelica_integer) 3));
  tmp18 = sqrt((tmp15 * tmp15) + (tmp16 * tmp16) + (tmp17 * tmp17));
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "left[1] / sqrt(left[1] ^ 2.0 + left[2] ^ 2.0 + left[3] ^ 2.0)");}
  tmp19 = real_array_get(_left, 1, ((modelica_integer) 1));
  tmp20 = real_array_get(_left, 1, ((modelica_integer) 2));
  tmp21 = real_array_get(_left, 1, ((modelica_integer) 3));
  tmp22 = sqrt((tmp19 * tmp19) + (tmp20 * tmp20) + (tmp21 * tmp21));
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "left[2] / sqrt(left[1] ^ 2.0 + left[2] ^ 2.0 + left[3] ^ 2.0)");}
  tmp23 = real_array_get(_left, 1, ((modelica_integer) 1));
  tmp24 = real_array_get(_left, 1, ((modelica_integer) 2));
  tmp25 = real_array_get(_left, 1, ((modelica_integer) 3));
  tmp26 = sqrt((tmp23 * tmp23) + (tmp24 * tmp24) + (tmp25 * tmp25));
  if (tmp26 == 0) {throwStreamPrint(threadData, "Division by zero %s", "left[3] / sqrt(left[1] ^ 2.0 + left[2] ^ 2.0 + left[3] ^ 2.0)");}
  array_alloc_scalar_real_array(&tmp14, 3, (modelica_real)(real_array_get(_left, 1, ((modelica_integer) 1))) / tmp18, (modelica_real)(real_array_get(_left, 1, ((modelica_integer) 2))) / tmp22, (modelica_real)(real_array_get(_left, 1, ((modelica_integer) 3))) / tmp26);
  real_array_copy_data(tmp14, _normalized_left);

  array_alloc_scalar_real_array(&tmp27, 3, (modelica_real)(real_array_get(_normalized_forward, 1, ((modelica_integer) 2))) * (real_array_get(_normalized_left, 1, ((modelica_integer) 3))) - ((real_array_get(_normalized_forward, 1, ((modelica_integer) 3))) * (real_array_get(_normalized_left, 1, ((modelica_integer) 2)))), (modelica_real)(real_array_get(_normalized_forward, 1, ((modelica_integer) 3))) * (real_array_get(_normalized_left, 1, ((modelica_integer) 1))) - ((real_array_get(_normalized_forward, 1, ((modelica_integer) 1))) * (real_array_get(_normalized_left, 1, ((modelica_integer) 3)))), (modelica_real)(real_array_get(_normalized_forward, 1, ((modelica_integer) 1))) * (real_array_get(_normalized_left, 1, ((modelica_integer) 2))) - ((real_array_get(_normalized_forward, 1, ((modelica_integer) 2))) * (real_array_get(_normalized_left, 1, ((modelica_integer) 1)))));
  real_array_copy_data(tmp27, _normalized_up);

  array_alloc_scalar_real_array(&tmp29, 3, (modelica_real)real_array_get(_normalized_forward, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_normalized_left, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(_normalized_up, 1, ((modelica_integer) 1)));
  array_alloc_scalar_real_array(&tmp30, 3, (modelica_real)real_array_get(_normalized_forward, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_normalized_left, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(_normalized_up, 1, ((modelica_integer) 2)));
  array_alloc_scalar_real_array(&tmp31, 3, (modelica_real)real_array_get(_normalized_forward, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(_normalized_left, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(_normalized_up, 1, ((modelica_integer) 3)));
  array_alloc_real_array(&tmp28, 3, tmp29, tmp30, tmp31);
  real_array_copy_data(tmp28, _norm_coord);
  _return: OMC_LABEL_UNUSED
  return _norm_coord;
}
modelica_metatype boxptr_normalized__tire__force__coordinate(threadData_t *threadData, modelica_metatype _forward, modelica_metatype _left)
{
  real_array _norm_coord;
  modelica_metatype out_norm_coord;
  _norm_coord = omc_normalized__tire__force__coordinate(threadData, *((base_array_t*)_forward), *((base_array_t*)_left));
  out_norm_coord = mmc_mk_modelica_array(_norm_coord);
  return out_norm_coord;
}

DLLExport
real_array omc_Modelica_Math_Matrices_inv(threadData_t *threadData, real_array _A)
{
  real_array _invA;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _info;
  integer_array _pivots;
  modelica_integer tmp3;
  real_array _LU;
  modelica_integer tmp4;
  modelica_integer tmp5;
  static int tmp6 = 0;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = size_of_dimension_base_array(_A, ((modelica_integer) 1));
  tmp2 = size_of_dimension_base_array(_A, ((modelica_integer) 2));
  alloc_real_array(&(_invA), 2, (_index_t)tmp1, (_index_t)tmp2); // _invA has no default value.
  // _info has no default value.
  tmp3 = size_of_dimension_base_array(_A, ((modelica_integer) 1));
  alloc_integer_array(&(_pivots), 1, (_index_t)tmp3); // _pivots has no default value.
  tmp4 = size_of_dimension_base_array(_A, ((modelica_integer) 1));
  tmp5 = size_of_dimension_base_array(_A, ((modelica_integer) 2));
  alloc_real_array(&(_LU), 2, (_index_t)tmp4, (_index_t)tmp5); // _LU has no default value.
  real_array_copy_data(omc_Modelica_Math_Matrices_LAPACK_dgetrf(threadData, _A ,&_pivots ,&_info), _LU);

  {
    if(!(_info == ((modelica_integer) 0)))
    {
      {
        FILE_INFO info = {"C:/Program Files/OpenModelica1.19.2-64bit/lib/omlibrary/Modelica 4.0.0/Math/package.mo",2603,5,2604,64,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT3));
      }
    }
  }

  real_array_copy_data(omc_Modelica_Math_Matrices_LAPACK_dgetri(threadData, _LU, _pivots, NULL), _invA);
  _return: OMC_LABEL_UNUSED
  return _invA;
}
modelica_metatype boxptr_Modelica_Math_Matrices_inv(threadData_t *threadData, modelica_metatype _A)
{
  real_array _invA;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_metatype out_invA;
  _invA = omc_Modelica_Math_Matrices_inv(threadData, *((base_array_t*)_A));
  out_invA = mmc_mk_modelica_array(_invA);
  return out_invA;
}

real_array omc_Modelica_Math_Matrices_LAPACK_dgetrf(threadData_t *threadData, real_array _A, integer_array *out_pivots, modelica_integer *out_info)
{
  /* extFunCallF77: varDecs */
  real_array _LU_ext;
  integer_array _pivots_ext;
  int _info_ext = 0;
  /* extFunCallF77: biVarDecs */
  modelica_integer _m;
  modelica_integer _m_ext;
  modelica_integer tmp1;
  modelica_integer _n;
  modelica_integer _n_ext;
  modelica_integer tmp2;
  modelica_integer _lda;
  modelica_integer _lda_ext;
  modelica_integer tmp3;
  /* extFunCallF77: args */
  real_array _LU;
  modelica_integer tmp4;
  modelica_integer tmp5;
  integer_array _pivots;
  modelica_integer tmp6;
  modelica_integer tmp7;
  modelica_integer _info;
  tmp1 = size_of_dimension_base_array(_A, ((modelica_integer) 1));
  _m = tmp1;
  tmp2 = size_of_dimension_base_array(_A, ((modelica_integer) 2));
  _n = tmp2;
  tmp3 = size_of_dimension_base_array(_A, ((modelica_integer) 1));
  _lda = modelica_integer_max((modelica_integer)(((modelica_integer) 1)),(modelica_integer)(tmp3));
  tmp4 = size_of_dimension_base_array(_A, ((modelica_integer) 1));
  tmp5 = size_of_dimension_base_array(_A, ((modelica_integer) 2));
  alloc_real_array(&(_LU), 2, (_index_t)tmp4, (_index_t)tmp5);
  real_array_copy_data(_A, _LU);
  
  tmp6 = size_of_dimension_base_array(_A, ((modelica_integer) 1));
  tmp7 = size_of_dimension_base_array(_A, ((modelica_integer) 2));
  alloc_integer_array(&(_pivots), 1, (_index_t)modelica_integer_min((modelica_integer)(tmp6),(modelica_integer)(tmp7))); // _pivots has no default value.
  // _info has no default value.
  /* extFunCallF77: biVarDecs */
  /* extFunCallF77: args */
  /* extFunCallF77: end args */
  convert_alloc_real_array_to_f77(&_LU, &_LU_ext);
  convert_alloc_integer_array_to_f77(&_pivots, &_pivots_ext);
  /* extFunCallF77: extReturn */
  /* extFunCallF77: CALL */
  dgetrf_((int*) &_m, (int*) &_n, data_of_real_f77_array(_LU_ext), (int*) &_lda, data_of_integer_f77_array(_pivots_ext), (int*) &_info_ext);
  /* extFunCallF77: copy args */
  convert_alloc_real_array_from_f77(&_LU_ext, &_LU);
  convert_alloc_integer_array_from_f77(&_pivots_ext, &_pivots);
  _info = (modelica_integer)_info_ext;
  /* extFunCallF77: copy return */
  if (out_pivots) { if (out_pivots->dim_size == NULL) {copy_integer_array(_pivots, out_pivots);} else {integer_array_copy_data(_pivots, *out_pivots);} }
  if (out_info) { *out_info = _info; }
  return _LU;
}
modelica_metatype boxptr_Modelica_Math_Matrices_LAPACK_dgetrf(threadData_t *threadData, modelica_metatype _A, modelica_metatype *out_pivots, modelica_metatype *out_info)
{
  integer_array _pivots;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _info;
  real_array _LU;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_metatype out_LU;
  _LU = omc_Modelica_Math_Matrices_LAPACK_dgetrf(threadData, *((base_array_t*)_A), &_pivots, &_info);
  out_LU = mmc_mk_modelica_array(_LU);
  if (out_pivots) { *out_pivots = mmc_mk_modelica_array(_pivots); }
  if (out_info) { *out_info = mmc_mk_icon(_info); }
  return out_LU;
}

real_array omc_Modelica_Math_Matrices_LAPACK_dgetri(threadData_t *threadData, real_array _LU, integer_array _pivots, modelica_integer *out_info)
{
  /* extFunCallF77: varDecs */
  real_array _inv_ext;
  integer_array _pivots_ext;
  int _info_ext = 0;
  /* extFunCallF77: biVarDecs */
  modelica_integer _n;
  modelica_integer _n_ext;
  modelica_integer tmp1;
  modelica_integer _lda;
  modelica_integer _lda_ext;
  modelica_integer tmp2;
  modelica_integer _lwork;
  modelica_integer _lwork_ext;
  modelica_integer tmp3;
  modelica_integer tmp4;
  real_array _work;
  real_array _work_ext;
  modelica_integer tmp5;
  modelica_integer tmp6;
  /* extFunCallF77: args */
  real_array _inv;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer _info;
  tmp1 = size_of_dimension_base_array(_LU, ((modelica_integer) 1));
  _n = tmp1;
  tmp2 = size_of_dimension_base_array(_LU, ((modelica_integer) 1));
  _lda = modelica_integer_max((modelica_integer)(((modelica_integer) 1)),(modelica_integer)(tmp2));
  tmp3 = size_of_dimension_base_array(_LU, ((modelica_integer) 1));
  tmp4 = size_of_dimension_base_array(_LU, ((modelica_integer) 1));
  _lwork = modelica_integer_max((modelica_integer)(((modelica_integer) 1)),(modelica_integer)((modelica_integer_min((modelica_integer)(((modelica_integer) 10)),(modelica_integer)(tmp3))) * (tmp4)));
  tmp5 = size_of_dimension_base_array(_LU, ((modelica_integer) 1));
  tmp6 = size_of_dimension_base_array(_LU, ((modelica_integer) 1));
  alloc_real_array(&_work, 1, (_index_t)modelica_integer_max((modelica_integer)(((modelica_integer) 1)),(modelica_integer)((modelica_integer_min((modelica_integer)(((modelica_integer) 10)),(modelica_integer)(tmp5))) * (tmp6))));
  convert_alloc_real_array_to_f77(&_work, &_work_ext);
  tmp7 = size_of_dimension_base_array(_LU, ((modelica_integer) 1));
  tmp8 = size_of_dimension_base_array(_LU, ((modelica_integer) 2));
  alloc_real_array(&(_inv), 2, (_index_t)tmp7, (_index_t)tmp8);
  real_array_copy_data(_LU, _inv);
  
  // _info has no default value.
  /* extFunCallF77: biVarDecs */
  /* extFunCallF77: args */
  /* extFunCallF77: end args */
  convert_alloc_real_array_to_f77(&_inv, &_inv_ext);
  convert_alloc_integer_array_to_f77(&_pivots, &_pivots_ext);
  /* extFunCallF77: extReturn */
  /* extFunCallF77: CALL */
  dgetri_((int*) &_n, data_of_real_f77_array(_inv_ext), (int*) &_lda, data_of_integer_f77_array(_pivots_ext), data_of_real_f77_array(_work_ext), (int*) &_lwork, (int*) &_info_ext);
  /* extFunCallF77: copy args */
  convert_alloc_real_array_from_f77(&_inv_ext, &_inv);
  _info = (modelica_integer)_info_ext;
  /* extFunCallF77: copy return */
  if (out_info) { *out_info = _info; }
  return _inv;
}
modelica_metatype boxptr_Modelica_Math_Matrices_LAPACK_dgetri(threadData_t *threadData, modelica_metatype _LU, modelica_metatype _pivots, modelica_metatype *out_info)
{
  modelica_integer _info;
  real_array _inv;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_metatype out_inv;
  _inv = omc_Modelica_Math_Matrices_LAPACK_dgetri(threadData, *((base_array_t*)_LU), *((base_array_t*)_pivots), &_info);
  out_inv = mmc_mk_modelica_array(_inv);
  if (out_info) { *out_info = mmc_mk_icon(_info); }
  return out_inv;
}

#ifdef __cplusplus
}
#endif
