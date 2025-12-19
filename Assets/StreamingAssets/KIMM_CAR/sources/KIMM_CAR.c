/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "KIMM_CAR_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int KIMM_CAR_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KIMM_CAR_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KIMM_CAR_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KIMM_CAR_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KIMM_CAR_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int KIMM_CAR_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KIMM_CAR_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int KIMM_CAR_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 336
type: SIMPLE_ASSIGN
$DER.body_Model.x = body_Model.dx
*/
void KIMM_CAR_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  (data->localData[0]->realVars[48]/* der(body_Model.x) STATE_DER */)  = (data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ;
  TRACE_POP
}
/*
equation index: 337
type: SIMPLE_ASSIGN
body_Model.body_vx_km_per_hour = 3.6 * body_Model.dx
*/
void KIMM_CAR_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  (data->localData[0]->realVars[218]/* body_Model.body_vx_km_per_hour variable */)  = (3.6) * ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) );
  TRACE_POP
}
/*
equation index: 338
type: SIMPLE_ASSIGN
$DER.body_Model.y = body_Model.dy
*/
void KIMM_CAR_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  (data->localData[0]->realVars[49]/* der(body_Model.y) STATE_DER */)  = (data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ;
  TRACE_POP
}
/*
equation index: 339
type: SIMPLE_ASSIGN
$DER.body_Model.z = body_Model.dz
*/
void KIMM_CAR_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  (data->localData[0]->realVars[51]/* der(body_Model.z) STATE_DER */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ;
  TRACE_POP
}
/*
equation index: 340
type: SIMPLE_ASSIGN
$DER.body_Model.roll = body_Model.d_roll
*/
void KIMM_CAR_eqFunction_340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,340};
  (data->localData[0]->realVars[47]/* der(body_Model.roll) STATE_DER */)  = (data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ;
  TRACE_POP
}
/*
equation index: 341
type: SIMPLE_ASSIGN
$DER.body_Model.pitch = body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_341(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,341};
  (data->localData[0]->realVars[46]/* der(body_Model.pitch) STATE_DER */)  = (data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ;
  TRACE_POP
}
/*
equation index: 342
type: SIMPLE_ASSIGN
$DER.body_Model.yaw = body_Model.d_yaw
*/
void KIMM_CAR_eqFunction_342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,342};
  (data->localData[0]->realVars[50]/* der(body_Model.yaw) STATE_DER */)  = (data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ;
  TRACE_POP
}
/*
equation index: 343
type: SIMPLE_ASSIGN
body_Model.z_out = body_Model.z + body_Model.chassis_to_body_distance
*/
void KIMM_CAR_eqFunction_343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,343};
  (data->localData[0]->realVars[251]/* body_Model.z_out variable */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + (data->simulationInfo->realParameter[9]/* body_Model.chassis_to_body_distance PARAM */) ;
  TRACE_POP
}
/*
equation index: 344
type: ARRAY_CALL_ASSIGN

body_Model.T_coord_FL = normalized_tire_force_coordinate({front_x_fl.k, front_y_fl.k, front_z_fl.k}, {left_x_fl.k, left_y_fl.k, left_z_fl.k})
*/
void KIMM_CAR_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,344};
  real_array tmp0;
  real_array tmp1;
  real_array tmp2;
  array_alloc_scalar_real_array(&tmp0, 3, (modelica_real)(data->simulationInfo->realParameter[49]/* front_x_fl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[57]/* front_y_fl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[65]/* front_z_fl.k PARAM */) );
  array_alloc_scalar_real_array(&tmp1, 3, (modelica_real)(data->simulationInfo->realParameter[73]/* left_x_fl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[81]/* left_y_fl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[89]/* left_z_fl.k PARAM */) );
  real_array_create(&tmp2, ((modelica_real*)&((&(data->localData[0]->realVars[164]/* body_Model.T_coord_FL[1,1] variable */) )[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(omc_normalized__tire__force__coordinate(threadData, tmp0, tmp1), tmp2);
  TRACE_POP
}
/*
equation index: 345
type: ARRAY_CALL_ASSIGN

body_Model.T_coord_FR = normalized_tire_force_coordinate({front_x_fr.k, front_y_fr.k, front_z_fr.k}, {left_x_fr.k, left_y_fr.k, left_z_fr.k})
*/
void KIMM_CAR_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  real_array tmp3;
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp3, 3, (modelica_real)(data->simulationInfo->realParameter[51]/* front_x_fr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[59]/* front_y_fr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[67]/* front_z_fr.k PARAM */) );
  array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)(data->simulationInfo->realParameter[75]/* left_x_fr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[83]/* left_y_fr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[91]/* left_z_fr.k PARAM */) );
  real_array_create(&tmp5, ((modelica_real*)&((&(data->localData[0]->realVars[173]/* body_Model.T_coord_FR[1,1] variable */) )[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(omc_normalized__tire__force__coordinate(threadData, tmp3, tmp4), tmp5);
  TRACE_POP
}
/*
equation index: 346
type: ARRAY_CALL_ASSIGN

body_Model.T_coord_RR = normalized_tire_force_coordinate({front_x_rr.k, front_y_rr.k, front_z_rr.k}, {left_x_rr.k, left_y_rr.k, left_z_rr.k})
*/
void KIMM_CAR_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  real_array tmp6;
  real_array tmp7;
  real_array tmp8;
  array_alloc_scalar_real_array(&tmp6, 3, (modelica_real)(data->simulationInfo->realParameter[55]/* front_x_rr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[63]/* front_y_rr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[71]/* front_z_rr.k PARAM */) );
  array_alloc_scalar_real_array(&tmp7, 3, (modelica_real)(data->simulationInfo->realParameter[79]/* left_x_rr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[87]/* left_y_rr.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[95]/* left_z_rr.k PARAM */) );
  real_array_create(&tmp8, ((modelica_real*)&((&(data->localData[0]->realVars[191]/* body_Model.T_coord_RR[1,1] variable */) )[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(omc_normalized__tire__force__coordinate(threadData, tmp6, tmp7), tmp8);
  TRACE_POP
}
/*
equation index: 347
type: ARRAY_CALL_ASSIGN

body_Model.T_coord_RL = normalized_tire_force_coordinate({front_x_rl.k, front_y_rl.k, front_z_rl.k}, {left_x_rl.k, left_y_rl.k, left_z_rl.k})
*/
void KIMM_CAR_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
  real_array tmp9;
  real_array tmp10;
  real_array tmp11;
  array_alloc_scalar_real_array(&tmp9, 3, (modelica_real)(data->simulationInfo->realParameter[53]/* front_x_rl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[61]/* front_y_rl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[69]/* front_z_rl.k PARAM */) );
  array_alloc_scalar_real_array(&tmp10, 3, (modelica_real)(data->simulationInfo->realParameter[77]/* left_x_rl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[85]/* left_y_rl.k PARAM */) , (modelica_real)(data->simulationInfo->realParameter[93]/* left_z_rl.k PARAM */) );
  real_array_create(&tmp11, ((modelica_real*)&((&(data->localData[0]->realVars[182]/* body_Model.T_coord_RL[1,1] variable */) )[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(omc_normalized__tire__force__coordinate(threadData, tmp9, tmp10), tmp11);
  TRACE_POP
}
/*
equation index: 348
type: ARRAY_CALL_ASSIGN

body_Model.B_coord = calc_coordinate({{body_Model.yaw}, {body_Model.pitch}, {body_Model.roll}})
*/
void KIMM_CAR_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,348};
  real_array tmp12;
  real_array tmp13;
  real_array tmp14;
  real_array tmp15;
  real_array tmp16;
  array_alloc_scalar_real_array(&tmp13, 1, (modelica_real)(data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) );
  array_alloc_scalar_real_array(&tmp14, 1, (modelica_real)(data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  array_alloc_scalar_real_array(&tmp15, 1, (modelica_real)(data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) );
  array_alloc_real_array(&tmp12, 3, tmp13, tmp14, tmp15);
  real_array_create(&tmp16, ((modelica_real*)&((&(data->localData[0]->realVars[140]/* body_Model.B_coord[1,1] variable */) )[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)3);
  real_array_copy_data(omc_calc__coordinate(threadData, tmp12), tmp16);
  TRACE_POP
}
/*
equation index: 349
type: SIMPLE_ASSIGN
$DER.suspension_front_right.tire_z_pos = tire_front_right.dz
*/
void KIMM_CAR_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
  (data->localData[0]->realVars[53]/* der(suspension_front_right.tire_z_pos) STATE_DER */)  = (data->localData[0]->realVars[26]/* tire_front_right.dz STATE(1,tire_front_right.ddz) */) ;
  TRACE_POP
}
/*
equation index: 350
type: SIMPLE_ASSIGN
$DER.suspension_front_left.tire_z_pos = tire_front_left.dz
*/
void KIMM_CAR_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
  (data->localData[0]->realVars[52]/* der(suspension_front_left.tire_z_pos) STATE_DER */)  = (data->localData[0]->realVars[21]/* tire_front_left.dz STATE(1,tire_front_left.ddz) */) ;
  TRACE_POP
}
/*
equation index: 351
type: SIMPLE_ASSIGN
$DER.suspension_rear_right.tire_z_pos = tire_rear_right.dz
*/
void KIMM_CAR_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  (data->localData[0]->realVars[55]/* der(suspension_rear_right.tire_z_pos) STATE_DER */)  = (data->localData[0]->realVars[36]/* tire_rear_right.dz STATE(1,tire_rear_right.ddz) */) ;
  TRACE_POP
}
/*
equation index: 352
type: SIMPLE_ASSIGN
$DER.suspension_rear_left.tire_z_pos = tire_rear_left.dz
*/
void KIMM_CAR_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  (data->localData[0]->realVars[54]/* der(suspension_rear_left.tire_z_pos) STATE_DER */)  = (data->localData[0]->realVars[31]/* tire_rear_left.dz STATE(1,tire_rear_left.ddz) */) ;
  TRACE_POP
}
/*
equation index: 353
type: SIMPLE_ASSIGN
$DER.tire_front_left.brake = tire_front_left.d_brake
*/
void KIMM_CAR_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  (data->localData[0]->realVars[56]/* der(tire_front_left.brake) STATE_DER */)  = (data->localData[0]->realVars[19]/* tire_front_left.d_brake STATE(1) */) ;
  TRACE_POP
}
/*
equation index: 354
type: SIMPLE_ASSIGN
$DER.tire_front_left.roll = tire_front_left.d_roll
*/
void KIMM_CAR_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  (data->localData[0]->realVars[60]/* der(tire_front_left.roll) STATE_DER */)  = (data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ;
  TRACE_POP
}
/*
equation index: 355
type: SIMPLE_ASSIGN
$DER.tire_front_left.d_brake = 10.0 * brake.k - (1000.0 * tire_front_left.d_brake + 150000.0 * tire_front_left.brake)
*/
void KIMM_CAR_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
  (data->localData[0]->realVars[57]/* der(tire_front_left.d_brake) STATE_DER */)  = (10.0) * ((data->simulationInfo->realParameter[45]/* brake.k PARAM */) ) - ((1000.0) * ((data->localData[0]->realVars[19]/* tire_front_left.d_brake STATE(1) */) ) + (150000.0) * ((data->localData[0]->realVars[18]/* tire_front_left.brake STATE(1,tire_front_left.d_brake) */) ));
  TRACE_POP
}
/*
equation index: 356
type: SIMPLE_ASSIGN
tire_front_left.brake_out = 15000.0 * tire_front_left.brake
*/
void KIMM_CAR_eqFunction_356(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,356};
  (data->localData[0]->realVars[288]/* tire_front_left.brake_out variable */)  = (15000.0) * ((data->localData[0]->realVars[18]/* tire_front_left.brake STATE(1,tire_front_left.d_brake) */) );
  TRACE_POP
}
/*
equation index: 357
type: SIMPLE_ASSIGN
$DER.tire_front_right.brake = tire_front_right.d_brake
*/
void KIMM_CAR_eqFunction_357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,357};
  (data->localData[0]->realVars[61]/* der(tire_front_right.brake) STATE_DER */)  = (data->localData[0]->realVars[24]/* tire_front_right.d_brake STATE(1) */) ;
  TRACE_POP
}
/*
equation index: 358
type: SIMPLE_ASSIGN
$DER.tire_front_right.roll = tire_front_right.d_roll
*/
void KIMM_CAR_eqFunction_358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,358};
  (data->localData[0]->realVars[65]/* der(tire_front_right.roll) STATE_DER */)  = (data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ;
  TRACE_POP
}
/*
equation index: 359
type: SIMPLE_ASSIGN
$DER.tire_front_right.d_brake = 10.0 * brake.k - (1000.0 * tire_front_right.d_brake + 150000.0 * tire_front_right.brake)
*/
void KIMM_CAR_eqFunction_359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,359};
  (data->localData[0]->realVars[62]/* der(tire_front_right.d_brake) STATE_DER */)  = (10.0) * ((data->simulationInfo->realParameter[45]/* brake.k PARAM */) ) - ((1000.0) * ((data->localData[0]->realVars[24]/* tire_front_right.d_brake STATE(1) */) ) + (150000.0) * ((data->localData[0]->realVars[23]/* tire_front_right.brake STATE(1,tire_front_right.d_brake) */) ));
  TRACE_POP
}
/*
equation index: 360
type: SIMPLE_ASSIGN
tire_front_right.brake_out = 15000.0 * tire_front_right.brake
*/
void KIMM_CAR_eqFunction_360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,360};
  (data->localData[0]->realVars[322]/* tire_front_right.brake_out variable */)  = (15000.0) * ((data->localData[0]->realVars[23]/* tire_front_right.brake STATE(1,tire_front_right.d_brake) */) );
  TRACE_POP
}
/*
equation index: 361
type: SIMPLE_ASSIGN
$DER.tire_rear_right.brake = tire_rear_right.d_brake
*/
void KIMM_CAR_eqFunction_361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,361};
  (data->localData[0]->realVars[71]/* der(tire_rear_right.brake) STATE_DER */)  = (data->localData[0]->realVars[34]/* tire_rear_right.d_brake STATE(1) */) ;
  TRACE_POP
}
/*
equation index: 362
type: SIMPLE_ASSIGN
$DER.tire_rear_right.roll = tire_rear_right.d_roll
*/
void KIMM_CAR_eqFunction_362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,362};
  (data->localData[0]->realVars[75]/* der(tire_rear_right.roll) STATE_DER */)  = (data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ;
  TRACE_POP
}
/*
equation index: 363
type: SIMPLE_ASSIGN
$DER.tire_rear_right.d_brake = 10.0 * brake.k - (1000.0 * tire_rear_right.d_brake + 150000.0 * tire_rear_right.brake)
*/
void KIMM_CAR_eqFunction_363(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,363};
  (data->localData[0]->realVars[72]/* der(tire_rear_right.d_brake) STATE_DER */)  = (10.0) * ((data->simulationInfo->realParameter[45]/* brake.k PARAM */) ) - ((1000.0) * ((data->localData[0]->realVars[34]/* tire_rear_right.d_brake STATE(1) */) ) + (150000.0) * ((data->localData[0]->realVars[33]/* tire_rear_right.brake STATE(1,tire_rear_right.d_brake) */) ));
  TRACE_POP
}
/*
equation index: 364
type: SIMPLE_ASSIGN
tire_rear_right.brake_out = 15000.0 * tire_rear_right.brake
*/
void KIMM_CAR_eqFunction_364(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,364};
  (data->localData[0]->realVars[390]/* tire_rear_right.brake_out variable */)  = (15000.0) * ((data->localData[0]->realVars[33]/* tire_rear_right.brake STATE(1,tire_rear_right.d_brake) */) );
  TRACE_POP
}
/*
equation index: 365
type: SIMPLE_ASSIGN
$DER.tire_rear_left.brake = tire_rear_left.d_brake
*/
void KIMM_CAR_eqFunction_365(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,365};
  (data->localData[0]->realVars[66]/* der(tire_rear_left.brake) STATE_DER */)  = (data->localData[0]->realVars[29]/* tire_rear_left.d_brake STATE(1) */) ;
  TRACE_POP
}
/*
equation index: 366
type: SIMPLE_ASSIGN
$DER.tire_rear_left.roll = tire_rear_left.d_roll
*/
void KIMM_CAR_eqFunction_366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,366};
  (data->localData[0]->realVars[70]/* der(tire_rear_left.roll) STATE_DER */)  = (data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ;
  TRACE_POP
}
/*
equation index: 367
type: SIMPLE_ASSIGN
$DER.tire_rear_left.d_brake = 10.0 * brake.k - (1000.0 * tire_rear_left.d_brake + 150000.0 * tire_rear_left.brake)
*/
void KIMM_CAR_eqFunction_367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,367};
  (data->localData[0]->realVars[67]/* der(tire_rear_left.d_brake) STATE_DER */)  = (10.0) * ((data->simulationInfo->realParameter[45]/* brake.k PARAM */) ) - ((1000.0) * ((data->localData[0]->realVars[29]/* tire_rear_left.d_brake STATE(1) */) ) + (150000.0) * ((data->localData[0]->realVars[28]/* tire_rear_left.brake STATE(1,tire_rear_left.d_brake) */) ));
  TRACE_POP
}
/*
equation index: 368
type: SIMPLE_ASSIGN
tire_rear_left.brake_out = 15000.0 * tire_rear_left.brake
*/
void KIMM_CAR_eqFunction_368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,368};
  (data->localData[0]->realVars[356]/* tire_rear_left.brake_out variable */)  = (15000.0) * ((data->localData[0]->realVars[28]/* tire_rear_left.brake STATE(1,tire_rear_left.d_brake) */) );
  TRACE_POP
}
/*
equation index: 369
type: SIMPLE_ASSIGN
rear_open_differential.motor_shaft_rotation_speed = 50.84846688111034 * (tire_rear_left.d_roll + tire_rear_right.d_roll)
*/
void KIMM_CAR_eqFunction_369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,369};
  (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */)  = (50.84846688111034) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */)  + (data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) );
  TRACE_POP
}
/*
equation index: 370
type: SIMPLE_ASSIGN
ev_motor_model.Torque_engine_max = if transmission.k < 1.0 then if abs(rear_open_differential.motor_shaft_rotation_speed) < 4000.0 then 350.0 else if abs(rear_open_differential.motor_shaft_rotation_speed) < 4500.0 then 18279.20000042394 + (-19.22496666710867) * rear_open_differential.motor_shaft_rotation_speed + 0.008043000000164001 * rear_open_differential.motor_shaft_rotation_speed ^ 2.0 + (-1.633333333366181e-06) * rear_open_differential.motor_shaft_rotation_speed ^ 3.0 + 1.600000000027887e-10 * rear_open_differential.motor_shaft_rotation_speed ^ 4.0 + (-6.000000000094284e-15) * rear_open_differential.motor_shaft_rotation_speed ^ 5.0 else if abs(rear_open_differential.motor_shaft_rotation_speed) < 9000.0 then 1.0 / (-1.745986849227381e-06 + 6.568790523869775e-07 * rear_open_differential.motor_shaft_rotation_speed) else 970.6717080756198 + (-0.08902163423062399) * rear_open_differential.motor_shaft_rotation_speed else if transmission.k < 2.0 then if abs(rear_open_differential.motor_shaft_rotation_speed) < 4000.0 then -350.0 else if abs(rear_open_differential.motor_shaft_rotation_speed) < 4500.0 then (-6.000000000094284e-15) * rear_open_differential.motor_shaft_rotation_speed ^ 5.0 - (18279.20000042394 - (-19.22496666710867) * rear_open_differential.motor_shaft_rotation_speed + 0.008043000000164001 * rear_open_differential.motor_shaft_rotation_speed ^ 2.0 - (-1.633333333366181e-06) * rear_open_differential.motor_shaft_rotation_speed ^ 3.0 + 1.600000000027887e-10 * rear_open_differential.motor_shaft_rotation_speed ^ 4.0) else if abs(rear_open_differential.motor_shaft_rotation_speed) < 9000.0 then (-1.0) / (-1.745986849227381e-06 - 6.568790523869775e-07 * rear_open_differential.motor_shaft_rotation_speed) else -970.6717080756198 + (-0.08902163423062399) * rear_open_differential.motor_shaft_rotation_speed else 0.0
*/
void KIMM_CAR_eqFunction_370(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,370};
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  modelica_boolean tmp26;
  modelica_real tmp27;
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_boolean tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  modelica_boolean tmp34;
  modelica_boolean tmp35;
  modelica_real tmp36;
  modelica_boolean tmp37;
  modelica_real tmp38;
  modelica_boolean tmp39;
  modelica_real tmp40;
  modelica_boolean tmp41;
  modelica_real tmp42;
  tmp17 = Less((data->simulationInfo->realParameter[247]/* transmission.k PARAM */) ,1.0);
  tmp41 = (modelica_boolean)tmp17;
  if(tmp41)
  {
    relationhysteresis(data, &tmp18, fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4000.0, 4, Less, LessZC);
    tmp26 = (modelica_boolean)tmp18;
    if(tmp26)
    {
      tmp27 = 350.0;
    }
    else
    {
      relationhysteresis(data, &tmp19, fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4500.0, 5, Less, LessZC);
      tmp24 = (modelica_boolean)tmp19;
      if(tmp24)
      {
        tmp20 = (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ;
        tmp21 = (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ;
        tmp22 = (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ;
        tmp22 *= tmp22;
        tmp25 = 18279.20000042394 + (-19.22496666710867) * ((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ) + (0.008043000000164001) * ((tmp20 * tmp20)) + (-1.633333333366181e-06) * ((tmp21 * tmp21 * tmp21)) + (1.600000000027887e-10) * ((tmp22 * tmp22)) + (-6.000000000094284e-15) * (real_int_pow(threadData, (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) , 5));
      }
      else
      {
        relationhysteresis(data, &tmp23, fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 9000.0, 6, Less, LessZC);
        tmp25 = (tmp23?DIVISION_SIM(1.0,-1.745986849227381e-06 + (6.568790523869775e-07) * ((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ),"-1.745986849227381e-06 + 6.568790523869775e-07 * rear_open_differential.motor_shaft_rotation_speed",equationIndexes):970.6717080756198 + (-0.08902163423062399) * ((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ));
      }
      tmp27 = tmp25;
    }
    tmp42 = tmp27;
  }
  else
  {
    tmp28 = Less((data->simulationInfo->realParameter[247]/* transmission.k PARAM */) ,2.0);
    tmp39 = (modelica_boolean)tmp28;
    if(tmp39)
    {
      relationhysteresis(data, &tmp29, fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4000.0, 4, Less, LessZC);
      tmp37 = (modelica_boolean)tmp29;
      if(tmp37)
      {
        tmp38 = -350.0;
      }
      else
      {
        relationhysteresis(data, &tmp30, fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4500.0, 5, Less, LessZC);
        tmp35 = (modelica_boolean)tmp30;
        if(tmp35)
        {
          tmp31 = (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ;
          tmp32 = (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ;
          tmp33 = (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ;
          tmp33 *= tmp33;
          tmp36 = (-6.000000000094284e-15) * (real_int_pow(threadData, (data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) , 5)) - (18279.20000042394 - ((-19.22496666710867) * ((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) )) + (0.008043000000164001) * ((tmp31 * tmp31)) - ((-1.633333333366181e-06) * ((tmp32 * tmp32 * tmp32))) + (1.600000000027887e-10) * ((tmp33 * tmp33)));
        }
        else
        {
          relationhysteresis(data, &tmp34, fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 9000.0, 6, Less, LessZC);
          tmp36 = (tmp34?DIVISION_SIM(-1.0,-1.745986849227381e-06 - ((6.568790523869775e-07) * ((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) )),"-1.745986849227381e-06 - 6.568790523869775e-07 * rear_open_differential.motor_shaft_rotation_speed",equationIndexes):-970.6717080756198 + (-0.08902163423062399) * ((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ));
        }
        tmp38 = tmp36;
      }
      tmp40 = tmp38;
    }
    else
    {
      tmp40 = 0.0;
    }
    tmp42 = tmp40;
  }
  (data->localData[0]->realVars[252]/* ev_motor_model.Torque_engine_max variable */)  = tmp42;
  TRACE_POP
}
/*
equation index: 371
type: SIMPLE_ASSIGN
ev_motor_model.motor_torque_out = ev_motor_model.Torque_engine_max * acceleration.k
*/
void KIMM_CAR_eqFunction_371(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,371};
  (data->localData[0]->realVars[253]/* ev_motor_model.motor_torque_out variable */)  = ((data->localData[0]->realVars[252]/* ev_motor_model.Torque_engine_max variable */) ) * ((data->simulationInfo->realParameter[0]/* acceleration.k PARAM */) );
  TRACE_POP
}
/*
equation index: 372
type: SIMPLE_ASSIGN
rear_open_differential.torque_to_right = 5.324839 * ev_motor_model.motor_torque_out
*/
void KIMM_CAR_eqFunction_372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,372};
  (data->localData[0]->realVars[259]/* rear_open_differential.torque_to_right variable */)  = (5.324839) * ((data->localData[0]->realVars[253]/* ev_motor_model.motor_torque_out variable */) );
  TRACE_POP
}
/*
equation index: 373
type: SIMPLE_ASSIGN
$DER.ackerman_Steering_Model.theta = ackerman_Steering_Model.d_theta
*/
void KIMM_CAR_eqFunction_373(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,373};
  (data->localData[0]->realVars[39]/* der(ackerman_Steering_Model.theta) STATE_DER */)  = (data->localData[0]->realVars[0]/* ackerman_Steering_Model.d_theta STATE(1) */) ;
  TRACE_POP
}
/*
equation index: 374
type: SIMPLE_ASSIGN
$DER.ackerman_Steering_Model.d_theta = 10.0 * angle_steer.k - (1000.0 * ackerman_Steering_Model.d_theta + 350000.0 * ackerman_Steering_Model.theta)
*/
void KIMM_CAR_eqFunction_374(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,374};
  (data->localData[0]->realVars[38]/* der(ackerman_Steering_Model.d_theta) STATE_DER */)  = (10.0) * ((data->simulationInfo->realParameter[3]/* angle_steer.k PARAM */) ) - ((1000.0) * ((data->localData[0]->realVars[0]/* ackerman_Steering_Model.d_theta STATE(1) */) ) + (350000.0) * ((data->localData[0]->realVars[1]/* ackerman_Steering_Model.theta STATE(1,ackerman_Steering_Model.d_theta) */) ));
  TRACE_POP
}
/*
equation index: 375
type: SIMPLE_ASSIGN
ackerman_Steering_Model.delta_P = 5058.513950993945 * ackerman_Steering_Model.theta
*/
void KIMM_CAR_eqFunction_375(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,375};
  (data->localData[0]->realVars[118]/* ackerman_Steering_Model.delta_P variable */)  = (5058.513950993945) * ((data->localData[0]->realVars[1]/* ackerman_Steering_Model.theta STATE(1,ackerman_Steering_Model.d_theta) */) );
  TRACE_POP
}
/*
equation index: 376
type: SIMPLE_ASSIGN
ackerman_Steering_Model.l_1_left = 0.3 + ackerman_Steering_Model.delta_P
*/
void KIMM_CAR_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,376};
  (data->localData[0]->realVars[119]/* ackerman_Steering_Model.l_1_left variable */)  = 0.3 + (data->localData[0]->realVars[118]/* ackerman_Steering_Model.delta_P variable */) ;
  TRACE_POP
}
/*
equation index: 377
type: SIMPLE_ASSIGN
ackerman_Steering_Model.l_2_left = sqrt(ackerman_Steering_Model.l_1_left ^ 2.0 + 0.09)
*/
void KIMM_CAR_eqFunction_377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,377};
  modelica_real tmp43;
  tmp43 = (data->localData[0]->realVars[119]/* ackerman_Steering_Model.l_1_left variable */) ;
  (data->localData[0]->realVars[121]/* ackerman_Steering_Model.l_2_left variable */)  = sqrt((tmp43 * tmp43) + 0.09);
  TRACE_POP
}
/*
equation index: 378
type: SIMPLE_ASSIGN
ackerman_Steering_Model.tmp_left = 0.5 * (0.1261244196 + ackerman_Steering_Model.l_2_left ^ 2.0 - 0.2025) / (ackerman_Steering_Model.l_2_left * 0.35514)
*/
void KIMM_CAR_eqFunction_378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,378};
  modelica_real tmp44;
  tmp44 = (data->localData[0]->realVars[121]/* ackerman_Steering_Model.l_2_left variable */) ;
  (data->localData[0]->realVars[135]/* ackerman_Steering_Model.tmp_left variable */)  = (0.5) * (DIVISION_SIM(0.1261244196 + (tmp44 * tmp44) - 0.2025,((data->localData[0]->realVars[121]/* ackerman_Steering_Model.l_2_left variable */) ) * (0.35514),"ackerman_Steering_Model.l_2_left * 0.35514",equationIndexes));
  TRACE_POP
}
/*
equation index: 379
type: SIMPLE_ASSIGN
ackerman_Steering_Model.right_steer_angle = if abs(ackerman_Steering_Model.tmp_left) < 0.99 then 1.570796326794895 - atan(0.3 / ackerman_Steering_Model.l_1_left) - acos((0.1261244196 + ackerman_Steering_Model.l_2_left ^ 2.0 - 0.2025) / (0.71028 * ackerman_Steering_Model.l_2_left)) + 0.434358023466495 else 1.570796326794895 - atan(0.3 / (ackerman_Steering_Model.l_1_left + 2e-06)) - acos((*Real*)(sign(ackerman_Steering_Model.tmp_left))) + 0.434358023466495
*/
void KIMM_CAR_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,379};
  modelica_boolean tmp45;
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_real tmp48;
  modelica_boolean tmp49;
  modelica_real tmp50;
  relationhysteresis(data, &tmp45, fabs((data->localData[0]->realVars[135]/* ackerman_Steering_Model.tmp_left variable */) ), 0.99, 2, Less, LessZC);
  tmp49 = (modelica_boolean)tmp45;
  if(tmp49)
  {
    tmp46 = (data->localData[0]->realVars[121]/* ackerman_Steering_Model.l_2_left variable */) ;
    tmp47 = DIVISION_SIM(0.1261244196 + (tmp46 * tmp46) - 0.2025,(0.71028) * ((data->localData[0]->realVars[121]/* ackerman_Steering_Model.l_2_left variable */) ),"0.71028 * ackerman_Steering_Model.l_2_left",equationIndexes);
    if(!(tmp47 >= -1.0 && tmp47 <= 1.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos((0.1261244196 + ackerman_Steering_Model.l_2_left ^ 2.0 - 0.2025) / (0.71028 * ackerman_Steering_Model.l_2_left)) outside the domain -1.0 <= %g <= 1.0", tmp47);
      }
    }
    tmp50 = 1.570796326794895 - atan(DIVISION_SIM(0.3,(data->localData[0]->realVars[119]/* ackerman_Steering_Model.l_1_left variable */) ,"ackerman_Steering_Model.l_1_left",equationIndexes)) - acos(tmp47) + 0.434358023466495;
  }
  else
  {
    tmp48 = ((modelica_real)sign((data->localData[0]->realVars[135]/* ackerman_Steering_Model.tmp_left variable */) ));
    if(!(tmp48 >= -1.0 && tmp48 <= 1.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos(/*Real*/(sign(ackerman_Steering_Model.tmp_left))) outside the domain -1.0 <= %g <= 1.0", tmp48);
      }
    }
    tmp50 = 1.570796326794895 - atan(DIVISION_SIM(0.3,(data->localData[0]->realVars[119]/* ackerman_Steering_Model.l_1_left variable */)  + 2e-06,"ackerman_Steering_Model.l_1_left + 2e-06",equationIndexes)) - acos(tmp48) + 0.434358023466495;
  }
  (data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */)  = tmp50;
  TRACE_POP
}
/*
equation index: 380
type: SIMPLE_ASSIGN
$cse8 = sin(ackerman_Steering_Model.right_steer_angle)
*/
void KIMM_CAR_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,380};
  (data->localData[0]->realVars[115]/* $cse8 variable */)  = sin((data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */) );
  TRACE_POP
}
/*
equation index: 381
type: SIMPLE_ASSIGN
$cse7 = cos(ackerman_Steering_Model.right_steer_angle)
*/
void KIMM_CAR_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
  (data->localData[0]->realVars[114]/* $cse7 variable */)  = cos((data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */) );
  TRACE_POP
}
/*
equation index: 382
type: SIMPLE_ASSIGN
ackerman_Steering_Model.l_1_right = 0.3 - ackerman_Steering_Model.delta_P
*/
void KIMM_CAR_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
  (data->localData[0]->realVars[120]/* ackerman_Steering_Model.l_1_right variable */)  = 0.3 - (data->localData[0]->realVars[118]/* ackerman_Steering_Model.delta_P variable */) ;
  TRACE_POP
}
/*
equation index: 383
type: SIMPLE_ASSIGN
ackerman_Steering_Model.l_2_right = sqrt(ackerman_Steering_Model.l_1_right ^ 2.0 + 0.09)
*/
void KIMM_CAR_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
  modelica_real tmp51;
  tmp51 = (data->localData[0]->realVars[120]/* ackerman_Steering_Model.l_1_right variable */) ;
  (data->localData[0]->realVars[122]/* ackerman_Steering_Model.l_2_right variable */)  = sqrt((tmp51 * tmp51) + 0.09);
  TRACE_POP
}
/*
equation index: 384
type: SIMPLE_ASSIGN
ackerman_Steering_Model.tmp_right = 0.5 * (0.1261244196 + ackerman_Steering_Model.l_2_right ^ 2.0 - 0.2025) / (ackerman_Steering_Model.l_2_right * 0.35514)
*/
void KIMM_CAR_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
  modelica_real tmp52;
  tmp52 = (data->localData[0]->realVars[122]/* ackerman_Steering_Model.l_2_right variable */) ;
  (data->localData[0]->realVars[136]/* ackerman_Steering_Model.tmp_right variable */)  = (0.5) * (DIVISION_SIM(0.1261244196 + (tmp52 * tmp52) - 0.2025,((data->localData[0]->realVars[122]/* ackerman_Steering_Model.l_2_right variable */) ) * (0.35514),"ackerman_Steering_Model.l_2_right * 0.35514",equationIndexes));
  TRACE_POP
}
/*
equation index: 385
type: SIMPLE_ASSIGN
ackerman_Steering_Model.left_steer_angle = if abs(ackerman_Steering_Model.tmp_right) < 0.99 then atan(0.3 / ackerman_Steering_Model.l_1_right) - 1.570796326794895 + acos((0.1261244196 + ackerman_Steering_Model.l_2_right ^ 2.0 - 0.2025) / (0.71028 * ackerman_Steering_Model.l_2_right)) - 0.434358023466495 else atan(0.3 / (ackerman_Steering_Model.l_1_right + 2e-06)) - 1.570796326794895 + acos((*Real*)(sign(ackerman_Steering_Model.tmp_right))) - 0.434358023466495
*/
void KIMM_CAR_eqFunction_385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,385};
  modelica_boolean tmp53;
  modelica_real tmp54;
  modelica_real tmp55;
  modelica_real tmp56;
  modelica_boolean tmp57;
  modelica_real tmp58;
  relationhysteresis(data, &tmp53, fabs((data->localData[0]->realVars[136]/* ackerman_Steering_Model.tmp_right variable */) ), 0.99, 3, Less, LessZC);
  tmp57 = (modelica_boolean)tmp53;
  if(tmp57)
  {
    tmp54 = (data->localData[0]->realVars[122]/* ackerman_Steering_Model.l_2_right variable */) ;
    tmp55 = DIVISION_SIM(0.1261244196 + (tmp54 * tmp54) - 0.2025,(0.71028) * ((data->localData[0]->realVars[122]/* ackerman_Steering_Model.l_2_right variable */) ),"0.71028 * ackerman_Steering_Model.l_2_right",equationIndexes);
    if(!(tmp55 >= -1.0 && tmp55 <= 1.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos((0.1261244196 + ackerman_Steering_Model.l_2_right ^ 2.0 - 0.2025) / (0.71028 * ackerman_Steering_Model.l_2_right)) outside the domain -1.0 <= %g <= 1.0", tmp55);
      }
    }
    tmp58 = atan(DIVISION_SIM(0.3,(data->localData[0]->realVars[120]/* ackerman_Steering_Model.l_1_right variable */) ,"ackerman_Steering_Model.l_1_right",equationIndexes)) - 1.570796326794895 + acos(tmp55) - 0.434358023466495;
  }
  else
  {
    tmp56 = ((modelica_real)sign((data->localData[0]->realVars[136]/* ackerman_Steering_Model.tmp_right variable */) ));
    if(!(tmp56 >= -1.0 && tmp56 <= 1.0))
    {
      if (data->simulationInfo->noThrowAsserts) {
        infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        data->simulationInfo->needToReThrow = 1;
      } else {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos(/*Real*/(sign(ackerman_Steering_Model.tmp_right))) outside the domain -1.0 <= %g <= 1.0", tmp56);
      }
    }
    tmp58 = atan(DIVISION_SIM(0.3,(data->localData[0]->realVars[120]/* ackerman_Steering_Model.l_1_right variable */)  + 2e-06,"ackerman_Steering_Model.l_1_right + 2e-06",equationIndexes)) - 1.570796326794895 + acos(tmp56) - 0.434358023466495;
  }
  (data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */)  = tmp58;
  TRACE_POP
}
/*
equation index: 386
type: SIMPLE_ASSIGN
$cse6 = sin(ackerman_Steering_Model.left_steer_angle)
*/
void KIMM_CAR_eqFunction_386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,386};
  (data->localData[0]->realVars[113]/* $cse6 variable */)  = sin((data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */) );
  TRACE_POP
}
/*
equation index: 387
type: SIMPLE_ASSIGN
$cse5 = cos(ackerman_Steering_Model.left_steer_angle)
*/
void KIMM_CAR_eqFunction_387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,387};
  (data->localData[0]->realVars[112]/* $cse5 variable */)  = cos((data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */) );
  TRACE_POP
}
/*
equation index: 388
type: SIMPLE_ASSIGN
$cse30 = atan(tire_rear_left.magic_B * tire_rear_left.d_roll)
*/
void KIMM_CAR_eqFunction_388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,388};
  (data->localData[0]->realVars[110]/* $cse30 variable */)  = atan(((data->simulationInfo->realParameter[217]/* tire_rear_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ));
  TRACE_POP
}
/*
equation index: 389
type: SIMPLE_ASSIGN
$cse29 = atan(tire_rear_left.magic_B * tire_rear_left.d_roll - tire_rear_left.magic_E * (tire_rear_left.magic_B * tire_rear_left.d_roll - $cse30))
*/
void KIMM_CAR_eqFunction_389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,389};
  (data->localData[0]->realVars[108]/* $cse29 variable */)  = atan(((data->simulationInfo->realParameter[217]/* tire_rear_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) - (((data->simulationInfo->realParameter[219]/* tire_rear_left.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[217]/* tire_rear_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) - (data->localData[0]->realVars[110]/* $cse30 variable */) )));
  TRACE_POP
}
/*
equation index: 390
type: SIMPLE_ASSIGN
$cse28 = sin(tire_rear_left.magic_C * $cse29)
*/
void KIMM_CAR_eqFunction_390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,390};
  (data->localData[0]->realVars[107]/* $cse28 variable */)  = sin(((data->simulationInfo->realParameter[218]/* tire_rear_left.magic_C PARAM */) ) * ((data->localData[0]->realVars[108]/* $cse29 variable */) ));
  TRACE_POP
}
/*
equation index: 391
type: SIMPLE_ASSIGN
tire_rear_left.brake_force = tire_rear_left.brake_force_max * tire_rear_left.brake_out * $cse28
*/
void KIMM_CAR_eqFunction_391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,391};
  (data->localData[0]->realVars[354]/* tire_rear_left.brake_force variable */)  = ((data->simulationInfo->realParameter[212]/* tire_rear_left.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[356]/* tire_rear_left.brake_out variable */) ) * ((data->localData[0]->realVars[107]/* $cse28 variable */) ));
  TRACE_POP
}
/*
equation index: 392
type: SIMPLE_ASSIGN
$cse27 = cos(body_Model.gnd_pitch_RL - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,392};
  (data->localData[0]->realVars[106]/* $cse27 variable */)  = cos((data->localData[0]->realVars[238]/* body_Model.gnd_pitch_RL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 393
type: SIMPLE_ASSIGN
tire_rear_left.gap = (suspension_rear_left.tire_z_pos - ray_rear_left.k) * $cse27 - tire_rear_left.radius
*/
void KIMM_CAR_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
  (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[16]/* suspension_rear_left.tire_z_pos STATE(1,tire_rear_left.dz) */)  - (data->simulationInfo->realParameter[149]/* ray_rear_left.k PARAM */) ) * ((data->localData[0]->realVars[106]/* $cse27 variable */) ) - (data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ;
  TRACE_POP
}
/*
equation index: 394
type: SIMPLE_ASSIGN
$cse26 = sin(body_Model.gnd_pitch_RL - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  (data->localData[0]->realVars[105]/* $cse26 variable */)  = sin((data->localData[0]->realVars[238]/* body_Model.gnd_pitch_RL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 395
type: SIMPLE_ASSIGN
tire_rear_left.d_gap = (suspension_rear_left.tire_z_pos - ray_rear_left.k) * $cse26 * body_Model.d_pitch + tire_rear_left.dz * $cse27
*/
void KIMM_CAR_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  (data->localData[0]->realVars[358]/* tire_rear_left.d_gap variable */)  = ((data->localData[0]->realVars[16]/* suspension_rear_left.tire_z_pos STATE(1,tire_rear_left.dz) */)  - (data->simulationInfo->realParameter[149]/* ray_rear_left.k PARAM */) ) * (((data->localData[0]->realVars[105]/* $cse26 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[31]/* tire_rear_left.dz STATE(1,tire_rear_left.ddz) */) ) * ((data->localData[0]->realVars[106]/* $cse27 variable */) );
  TRACE_POP
}
/*
equation index: 396
type: SIMPLE_ASSIGN
tire_rear_left.tire_normal_force = if tire_rear_left.gap < 0.0 then (-tire_rear_left.wheel_spring_stiff) * tire_rear_left.gap - tire_rear_left.wheel_damper_stiff * tire_rear_left.d_gap else 0.0
*/
void KIMM_CAR_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
  modelica_boolean tmp59;
  relationhysteresis(data, &tmp59, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */)  = (tmp59?((-(data->simulationInfo->realParameter[228]/* tire_rear_left.wheel_spring_stiff PARAM */) )) * ((data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) ) - (((data->simulationInfo->realParameter[227]/* tire_rear_left.wheel_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[358]/* tire_rear_left.d_gap variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 397
type: SIMPLE_ASSIGN
tire_rear_left.dfz = if tire_rear_left.gap < 0.0 then -1.0 + 0.0001666666666666667 * tire_rear_left.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
  modelica_boolean tmp60;
  relationhysteresis(data, &tmp60, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */)  = (tmp60?-1.0 + (0.0001666666666666667) * ((data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 398
type: SIMPLE_ASSIGN
tire_rear_left.Ex = if tire_rear_left.gap < 0.0 then 0.998281 * (0.11113 + 0.4143 * tire_rear_left.dfz + (-0.02) * tire_rear_left.dfz ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
  modelica_boolean tmp61;
  modelica_real tmp62;
  modelica_boolean tmp63;
  modelica_real tmp64;
  relationhysteresis(data, &tmp61, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  tmp63 = (modelica_boolean)tmp61;
  if(tmp63)
  {
    tmp62 = (data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */) ;
    tmp64 = (0.998281) * (0.11113 + (0.4143) * ((data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */) ) + (-0.02) * ((tmp62 * tmp62)));
  }
  else
  {
    tmp64 = 0.0;
  }
  (data->localData[0]->realVars[350]/* tire_rear_left.Ex variable */)  = tmp64;
  TRACE_POP
}
/*
equation index: 399
type: SIMPLE_ASSIGN
tire_rear_left.Ey = if tire_rear_left.gap < 0.0 then 0.90146 * (-0.8057 + (-0.6046) * tire_rear_left.dfz) else 0.0
*/
void KIMM_CAR_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
  modelica_boolean tmp65;
  relationhysteresis(data, &tmp65, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[351]/* tire_rear_left.Ey variable */)  = (tmp65?(0.90146) * (-0.8057 + (-0.6046) * ((data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 400
type: SIMPLE_ASSIGN
tire_rear_left.Dx = if tire_rear_left.gap < 0.0 then (1.0822 + (-0.08284999999999999) * tire_rear_left.dfz) * tire_rear_left.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
  modelica_boolean tmp66;
  relationhysteresis(data, &tmp66, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[348]/* tire_rear_left.Dx variable */)  = (tmp66?(1.0822 + (-0.08284999999999999) * ((data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */) )) * ((data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 401
type: SIMPLE_ASSIGN
tire_rear_left.Bx = if tire_rear_left.gap < 0.0 then tire_rear_left.tire_normal_force * (21.687 + 0.728 * tire_rear_left.dfz) * exp((-0.9089) * tire_rear_left.dfz) / (tire_rear_left.Dx * 1.579) else 0.0
*/
void KIMM_CAR_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
  modelica_boolean tmp67;
  relationhysteresis(data, &tmp67, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[340]/* tire_rear_left.Bx variable */)  = (tmp67?((data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */) ) * ((21.687 + (0.728) * ((data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */) )) * (DIVISION_SIM(exp((-0.9089) * ((data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */) )),((data->localData[0]->realVars[348]/* tire_rear_left.Dx variable */) ) * (1.579),"tire_rear_left.Dx * 1.579",equationIndexes))):0.0);
  TRACE_POP
}
/*
equation index: 402
type: SIMPLE_ASSIGN
tire_rear_left.Dy = if tire_rear_left.gap < 0.0 then (1.4785 + (-0.06451999999999999) * tire_rear_left.dfz) * tire_rear_left.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
  modelica_boolean tmp68;
  relationhysteresis(data, &tmp68, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[349]/* tire_rear_left.Dy variable */)  = (tmp68?(1.4785 + (-0.06451999999999999) * ((data->localData[0]->realVars[361]/* tire_rear_left.dfz variable */) )) * ((data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 403
type: SIMPLE_ASSIGN
tire_rear_left.By = if tire_rear_left.gap < 0.0 then (-91944.0) * sin(2.0 * atan(tire_rear_left.tire_normal_force / 10290.0)) / (tire_rear_left.Dy * 1.338) else 0.0
*/
void KIMM_CAR_eqFunction_403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,403};
  modelica_boolean tmp69;
  relationhysteresis(data, &tmp69, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[342]/* tire_rear_left.By variable */)  = (tmp69?(-91944.0) * (DIVISION_SIM(sin((2.0) * (atan(DIVISION_SIM((data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */) ,10290.0,"10290.0",equationIndexes)))),((data->localData[0]->realVars[349]/* tire_rear_left.Dy variable */) ) * (1.338),"tire_rear_left.Dy * 1.338",equationIndexes)):0.0);
  TRACE_POP
}
/*
equation index: 404
type: SIMPLE_ASSIGN
$DER.tire_rear_left.gap = tire_rear_left.d_gap
*/
void KIMM_CAR_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  (data->localData[0]->realVars[85]/* der(tire_rear_left.gap) DUMMY_DER */)  = (data->localData[0]->realVars[358]/* tire_rear_left.d_gap variable */) ;
  TRACE_POP
}
/*
equation index: 405
type: SIMPLE_ASSIGN
$cse25 = atan(tire_rear_right.magic_B * tire_rear_right.d_roll)
*/
void KIMM_CAR_eqFunction_405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,405};
  (data->localData[0]->realVars[104]/* $cse25 variable */)  = atan(((data->simulationInfo->realParameter[235]/* tire_rear_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ));
  TRACE_POP
}
/*
equation index: 406
type: SIMPLE_ASSIGN
$cse24 = atan(tire_rear_right.magic_B * tire_rear_right.d_roll - tire_rear_right.magic_E * (tire_rear_right.magic_B * tire_rear_right.d_roll - $cse25))
*/
void KIMM_CAR_eqFunction_406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,406};
  (data->localData[0]->realVars[103]/* $cse24 variable */)  = atan(((data->simulationInfo->realParameter[235]/* tire_rear_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) - (((data->simulationInfo->realParameter[237]/* tire_rear_right.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[235]/* tire_rear_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) - (data->localData[0]->realVars[104]/* $cse25 variable */) )));
  TRACE_POP
}
/*
equation index: 407
type: SIMPLE_ASSIGN
$cse23 = sin(tire_rear_right.magic_C * $cse24)
*/
void KIMM_CAR_eqFunction_407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,407};
  (data->localData[0]->realVars[102]/* $cse23 variable */)  = sin(((data->simulationInfo->realParameter[236]/* tire_rear_right.magic_C PARAM */) ) * ((data->localData[0]->realVars[103]/* $cse24 variable */) ));
  TRACE_POP
}
/*
equation index: 408
type: SIMPLE_ASSIGN
tire_rear_right.brake_force = tire_rear_right.brake_force_max * tire_rear_right.brake_out * $cse23
*/
void KIMM_CAR_eqFunction_408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,408};
  (data->localData[0]->realVars[388]/* tire_rear_right.brake_force variable */)  = ((data->simulationInfo->realParameter[230]/* tire_rear_right.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[390]/* tire_rear_right.brake_out variable */) ) * ((data->localData[0]->realVars[102]/* $cse23 variable */) ));
  TRACE_POP
}
/*
equation index: 409
type: SIMPLE_ASSIGN
$cse22 = cos(body_Model.gnd_pitch_RR - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,409};
  (data->localData[0]->realVars[101]/* $cse22 variable */)  = cos((data->localData[0]->realVars[239]/* body_Model.gnd_pitch_RR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 410
type: SIMPLE_ASSIGN
tire_rear_right.gap = (suspension_rear_right.tire_z_pos - ray_rear_right.k) * $cse22 - tire_rear_right.radius
*/
void KIMM_CAR_eqFunction_410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,410};
  (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[17]/* suspension_rear_right.tire_z_pos STATE(1,tire_rear_right.dz) */)  - (data->simulationInfo->realParameter[151]/* ray_rear_right.k PARAM */) ) * ((data->localData[0]->realVars[101]/* $cse22 variable */) ) - (data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ;
  TRACE_POP
}
/*
equation index: 411
type: SIMPLE_ASSIGN
$cse21 = sin(body_Model.gnd_pitch_RR - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,411};
  (data->localData[0]->realVars[100]/* $cse21 variable */)  = sin((data->localData[0]->realVars[239]/* body_Model.gnd_pitch_RR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 412
type: SIMPLE_ASSIGN
tire_rear_right.d_gap = (suspension_rear_right.tire_z_pos - ray_rear_right.k) * $cse21 * body_Model.d_pitch + tire_rear_right.dz * $cse22
*/
void KIMM_CAR_eqFunction_412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,412};
  (data->localData[0]->realVars[392]/* tire_rear_right.d_gap variable */)  = ((data->localData[0]->realVars[17]/* suspension_rear_right.tire_z_pos STATE(1,tire_rear_right.dz) */)  - (data->simulationInfo->realParameter[151]/* ray_rear_right.k PARAM */) ) * (((data->localData[0]->realVars[100]/* $cse21 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[36]/* tire_rear_right.dz STATE(1,tire_rear_right.ddz) */) ) * ((data->localData[0]->realVars[101]/* $cse22 variable */) );
  TRACE_POP
}
/*
equation index: 413
type: SIMPLE_ASSIGN
tire_rear_right.tire_normal_force = if tire_rear_right.gap < 0.0 then (-tire_rear_right.wheel_spring_stiff) * tire_rear_right.gap - tire_rear_right.wheel_damper_stiff * tire_rear_right.d_gap else 0.0
*/
void KIMM_CAR_eqFunction_413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,413};
  modelica_boolean tmp70;
  relationhysteresis(data, &tmp70, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */)  = (tmp70?((-(data->simulationInfo->realParameter[246]/* tire_rear_right.wheel_spring_stiff PARAM */) )) * ((data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) ) - (((data->simulationInfo->realParameter[245]/* tire_rear_right.wheel_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[392]/* tire_rear_right.d_gap variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 414
type: SIMPLE_ASSIGN
tire_rear_right.dfz = if tire_rear_right.gap < 0.0 then -1.0 + 0.0001666666666666667 * tire_rear_right.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,414};
  modelica_boolean tmp71;
  relationhysteresis(data, &tmp71, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */)  = (tmp71?-1.0 + (0.0001666666666666667) * ((data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 415
type: SIMPLE_ASSIGN
tire_rear_right.Ex = if tire_rear_right.gap < 0.0 then 0.998281 * (0.11113 + 0.4143 * tire_rear_right.dfz + (-0.02) * tire_rear_right.dfz ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,415};
  modelica_boolean tmp72;
  modelica_real tmp73;
  modelica_boolean tmp74;
  modelica_real tmp75;
  relationhysteresis(data, &tmp72, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  tmp74 = (modelica_boolean)tmp72;
  if(tmp74)
  {
    tmp73 = (data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */) ;
    tmp75 = (0.998281) * (0.11113 + (0.4143) * ((data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */) ) + (-0.02) * ((tmp73 * tmp73)));
  }
  else
  {
    tmp75 = 0.0;
  }
  (data->localData[0]->realVars[384]/* tire_rear_right.Ex variable */)  = tmp75;
  TRACE_POP
}
/*
equation index: 416
type: SIMPLE_ASSIGN
tire_rear_right.Ey = if tire_rear_right.gap < 0.0 then 0.90146 * (-0.8057 + (-0.6046) * tire_rear_right.dfz) else 0.0
*/
void KIMM_CAR_eqFunction_416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,416};
  modelica_boolean tmp76;
  relationhysteresis(data, &tmp76, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[385]/* tire_rear_right.Ey variable */)  = (tmp76?(0.90146) * (-0.8057 + (-0.6046) * ((data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 417
type: SIMPLE_ASSIGN
tire_rear_right.Dx = if tire_rear_right.gap < 0.0 then (1.0822 + (-0.08284999999999999) * tire_rear_right.dfz) * tire_rear_right.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,417};
  modelica_boolean tmp77;
  relationhysteresis(data, &tmp77, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[382]/* tire_rear_right.Dx variable */)  = (tmp77?(1.0822 + (-0.08284999999999999) * ((data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */) )) * ((data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 418
type: SIMPLE_ASSIGN
tire_rear_right.Bx = if tire_rear_right.gap < 0.0 then tire_rear_right.tire_normal_force * (21.687 + 0.728 * tire_rear_right.dfz) * exp((-0.9089) * tire_rear_right.dfz) / (tire_rear_right.Dx * 1.579) else 0.0
*/
void KIMM_CAR_eqFunction_418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,418};
  modelica_boolean tmp78;
  relationhysteresis(data, &tmp78, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[374]/* tire_rear_right.Bx variable */)  = (tmp78?((data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */) ) * ((21.687 + (0.728) * ((data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */) )) * (DIVISION_SIM(exp((-0.9089) * ((data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */) )),((data->localData[0]->realVars[382]/* tire_rear_right.Dx variable */) ) * (1.579),"tire_rear_right.Dx * 1.579",equationIndexes))):0.0);
  TRACE_POP
}
/*
equation index: 419
type: SIMPLE_ASSIGN
tire_rear_right.Dy = if tire_rear_right.gap < 0.0 then (1.4785 + (-0.06451999999999999) * tire_rear_right.dfz) * tire_rear_right.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,419};
  modelica_boolean tmp79;
  relationhysteresis(data, &tmp79, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[383]/* tire_rear_right.Dy variable */)  = (tmp79?(1.4785 + (-0.06451999999999999) * ((data->localData[0]->realVars[395]/* tire_rear_right.dfz variable */) )) * ((data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 420
type: SIMPLE_ASSIGN
tire_rear_right.By = if tire_rear_right.gap < 0.0 then (-91944.0) * sin(2.0 * atan(tire_rear_right.tire_normal_force / 10290.0)) / (tire_rear_right.Dy * 1.338) else 0.0
*/
void KIMM_CAR_eqFunction_420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,420};
  modelica_boolean tmp80;
  relationhysteresis(data, &tmp80, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[376]/* tire_rear_right.By variable */)  = (tmp80?(-91944.0) * (DIVISION_SIM(sin((2.0) * (atan(DIVISION_SIM((data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */) ,10290.0,"10290.0",equationIndexes)))),((data->localData[0]->realVars[383]/* tire_rear_right.Dy variable */) ) * (1.338),"tire_rear_right.Dy * 1.338",equationIndexes)):0.0);
  TRACE_POP
}
/*
equation index: 421
type: SIMPLE_ASSIGN
$DER.tire_rear_right.gap = tire_rear_right.d_gap
*/
void KIMM_CAR_eqFunction_421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,421};
  (data->localData[0]->realVars[86]/* der(tire_rear_right.gap) DUMMY_DER */)  = (data->localData[0]->realVars[392]/* tire_rear_right.d_gap variable */) ;
  TRACE_POP
}
/*
equation index: 422
type: SIMPLE_ASSIGN
$cse20 = atan(tire_front_right.magic_B * tire_front_right.d_roll)
*/
void KIMM_CAR_eqFunction_422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,422};
  (data->localData[0]->realVars[99]/* $cse20 variable */)  = atan(((data->simulationInfo->realParameter[199]/* tire_front_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ));
  TRACE_POP
}
/*
equation index: 423
type: SIMPLE_ASSIGN
$cse19 = atan(tire_front_right.magic_B * tire_front_right.d_roll - tire_front_right.magic_E * (tire_front_right.magic_B * tire_front_right.d_roll - $cse20))
*/
void KIMM_CAR_eqFunction_423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,423};
  (data->localData[0]->realVars[97]/* $cse19 variable */)  = atan(((data->simulationInfo->realParameter[199]/* tire_front_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) - (((data->simulationInfo->realParameter[201]/* tire_front_right.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[199]/* tire_front_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) - (data->localData[0]->realVars[99]/* $cse20 variable */) )));
  TRACE_POP
}
/*
equation index: 424
type: SIMPLE_ASSIGN
$cse18 = sin(tire_front_right.magic_C * $cse19)
*/
void KIMM_CAR_eqFunction_424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,424};
  (data->localData[0]->realVars[96]/* $cse18 variable */)  = sin(((data->simulationInfo->realParameter[200]/* tire_front_right.magic_C PARAM */) ) * ((data->localData[0]->realVars[97]/* $cse19 variable */) ));
  TRACE_POP
}
/*
equation index: 425
type: SIMPLE_ASSIGN
tire_front_right.brake_force = tire_front_right.brake_force_max * tire_front_right.brake_out * $cse18
*/
void KIMM_CAR_eqFunction_425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,425};
  (data->localData[0]->realVars[320]/* tire_front_right.brake_force variable */)  = ((data->simulationInfo->realParameter[194]/* tire_front_right.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[322]/* tire_front_right.brake_out variable */) ) * ((data->localData[0]->realVars[96]/* $cse18 variable */) ));
  TRACE_POP
}
/*
equation index: 426
type: SIMPLE_ASSIGN
$cse17 = cos(body_Model.gnd_pitch_FR - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,426};
  (data->localData[0]->realVars[95]/* $cse17 variable */)  = cos((data->localData[0]->realVars[237]/* body_Model.gnd_pitch_FR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 427
type: SIMPLE_ASSIGN
tire_front_right.gap = (suspension_front_right.tire_z_pos - ray_front_right.k) * $cse17 - tire_front_right.radius
*/
void KIMM_CAR_eqFunction_427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,427};
  (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[15]/* suspension_front_right.tire_z_pos STATE(1,tire_front_right.dz) */)  - (data->simulationInfo->realParameter[147]/* ray_front_right.k PARAM */) ) * ((data->localData[0]->realVars[95]/* $cse17 variable */) ) - (data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ;
  TRACE_POP
}
/*
equation index: 428
type: SIMPLE_ASSIGN
$cse16 = sin(body_Model.gnd_pitch_FR - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,428};
  (data->localData[0]->realVars[94]/* $cse16 variable */)  = sin((data->localData[0]->realVars[237]/* body_Model.gnd_pitch_FR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 429
type: SIMPLE_ASSIGN
tire_front_right.d_gap = (suspension_front_right.tire_z_pos - ray_front_right.k) * $cse16 * body_Model.d_pitch + tire_front_right.dz * $cse17
*/
void KIMM_CAR_eqFunction_429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,429};
  (data->localData[0]->realVars[324]/* tire_front_right.d_gap variable */)  = ((data->localData[0]->realVars[15]/* suspension_front_right.tire_z_pos STATE(1,tire_front_right.dz) */)  - (data->simulationInfo->realParameter[147]/* ray_front_right.k PARAM */) ) * (((data->localData[0]->realVars[94]/* $cse16 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[26]/* tire_front_right.dz STATE(1,tire_front_right.ddz) */) ) * ((data->localData[0]->realVars[95]/* $cse17 variable */) );
  TRACE_POP
}
/*
equation index: 430
type: SIMPLE_ASSIGN
tire_front_right.tire_normal_force = if tire_front_right.gap < 0.0 then (-tire_front_right.wheel_spring_stiff) * tire_front_right.gap - tire_front_right.wheel_damper_stiff * tire_front_right.d_gap else 0.0
*/
void KIMM_CAR_eqFunction_430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,430};
  modelica_boolean tmp81;
  relationhysteresis(data, &tmp81, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */)  = (tmp81?((-(data->simulationInfo->realParameter[210]/* tire_front_right.wheel_spring_stiff PARAM */) )) * ((data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) ) - (((data->simulationInfo->realParameter[209]/* tire_front_right.wheel_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[324]/* tire_front_right.d_gap variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 431
type: SIMPLE_ASSIGN
tire_front_right.dfz = if tire_front_right.gap < 0.0 then -1.0 + 0.0001666666666666667 * tire_front_right.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,431};
  modelica_boolean tmp82;
  relationhysteresis(data, &tmp82, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[327]/* tire_front_right.dfz variable */)  = (tmp82?-1.0 + (0.0001666666666666667) * ((data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 432
type: SIMPLE_ASSIGN
tire_front_right.Ex = if tire_front_right.gap < 0.0 then 0.998281 * (0.11113 + 0.4143 * tire_front_right.dfz + (-0.02) * tire_front_right.dfz ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,432};
  modelica_boolean tmp83;
  modelica_real tmp84;
  modelica_boolean tmp85;
  modelica_real tmp86;
  relationhysteresis(data, &tmp83, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  tmp85 = (modelica_boolean)tmp83;
  if(tmp85)
  {
    tmp84 = (data->localData[0]->realVars[327]/* tire_front_right.dfz variable */) ;
    tmp86 = (0.998281) * (0.11113 + (0.4143) * ((data->localData[0]->realVars[327]/* tire_front_right.dfz variable */) ) + (-0.02) * ((tmp84 * tmp84)));
  }
  else
  {
    tmp86 = 0.0;
  }
  (data->localData[0]->realVars[316]/* tire_front_right.Ex variable */)  = tmp86;
  TRACE_POP
}
/*
equation index: 433
type: SIMPLE_ASSIGN
tire_front_right.Ey = if tire_front_right.gap < 0.0 then 0.90146 * (-0.8057 + (-0.6046) * tire_front_right.dfz) else 0.0
*/
void KIMM_CAR_eqFunction_433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,433};
  modelica_boolean tmp87;
  relationhysteresis(data, &tmp87, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[317]/* tire_front_right.Ey variable */)  = (tmp87?(0.90146) * (-0.8057 + (-0.6046) * ((data->localData[0]->realVars[327]/* tire_front_right.dfz variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 434
type: SIMPLE_ASSIGN
tire_front_right.Dx = if tire_front_right.gap < 0.0 then (1.0822 + (-0.08284999999999999) * tire_front_right.dfz) * tire_front_right.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,434};
  modelica_boolean tmp88;
  relationhysteresis(data, &tmp88, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[314]/* tire_front_right.Dx variable */)  = (tmp88?(1.0822 + (-0.08284999999999999) * ((data->localData[0]->realVars[327]/* tire_front_right.dfz variable */) )) * ((data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 435
type: SIMPLE_ASSIGN
tire_front_right.Bx = if tire_front_right.gap < 0.0 then tire_front_right.tire_normal_force * (21.687 + 0.728 * tire_front_right.dfz) * exp((-0.9089) * tire_front_right.dfz) / (tire_front_right.Dx * 1.579) else 0.0
*/
void KIMM_CAR_eqFunction_435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,435};
  modelica_boolean tmp89;
  relationhysteresis(data, &tmp89, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[306]/* tire_front_right.Bx variable */)  = (tmp89?((data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */) ) * ((21.687 + (0.728) * ((data->localData[0]->realVars[327]/* tire_front_right.dfz variable */) )) * (DIVISION_SIM(exp((-0.9089) * ((data->localData[0]->realVars[327]/* tire_front_right.dfz variable */) )),((data->localData[0]->realVars[314]/* tire_front_right.Dx variable */) ) * (1.579),"tire_front_right.Dx * 1.579",equationIndexes))):0.0);
  TRACE_POP
}
/*
equation index: 436
type: SIMPLE_ASSIGN
tire_front_right.Dy = if tire_front_right.gap < 0.0 then (1.4785 + (-0.06451999999999999) * tire_front_right.dfz) * tire_front_right.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,436};
  modelica_boolean tmp90;
  relationhysteresis(data, &tmp90, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[315]/* tire_front_right.Dy variable */)  = (tmp90?(1.4785 + (-0.06451999999999999) * ((data->localData[0]->realVars[327]/* tire_front_right.dfz variable */) )) * ((data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 437
type: SIMPLE_ASSIGN
tire_front_right.By = if tire_front_right.gap < 0.0 then (-91944.0) * sin(2.0 * atan(tire_front_right.tire_normal_force / 10290.0)) / (tire_front_right.Dy * 1.338) else 0.0
*/
void KIMM_CAR_eqFunction_437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,437};
  modelica_boolean tmp91;
  relationhysteresis(data, &tmp91, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[308]/* tire_front_right.By variable */)  = (tmp91?(-91944.0) * (DIVISION_SIM(sin((2.0) * (atan(DIVISION_SIM((data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */) ,10290.0,"10290.0",equationIndexes)))),((data->localData[0]->realVars[315]/* tire_front_right.Dy variable */) ) * (1.338),"tire_front_right.Dy * 1.338",equationIndexes)):0.0);
  TRACE_POP
}
/*
equation index: 438
type: SIMPLE_ASSIGN
$DER.tire_front_right.gap = tire_front_right.d_gap
*/
void KIMM_CAR_eqFunction_438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,438};
  (data->localData[0]->realVars[84]/* der(tire_front_right.gap) DUMMY_DER */)  = (data->localData[0]->realVars[324]/* tire_front_right.d_gap variable */) ;
  TRACE_POP
}
/*
equation index: 439
type: SIMPLE_ASSIGN
$cse15 = atan(tire_front_left.magic_B * tire_front_left.d_roll)
*/
void KIMM_CAR_eqFunction_439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,439};
  (data->localData[0]->realVars[93]/* $cse15 variable */)  = atan(((data->simulationInfo->realParameter[181]/* tire_front_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ));
  TRACE_POP
}
/*
equation index: 440
type: SIMPLE_ASSIGN
$cse14 = atan(tire_front_left.magic_B * tire_front_left.d_roll - tire_front_left.magic_E * (tire_front_left.magic_B * tire_front_left.d_roll - $cse15))
*/
void KIMM_CAR_eqFunction_440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,440};
  (data->localData[0]->realVars[92]/* $cse14 variable */)  = atan(((data->simulationInfo->realParameter[181]/* tire_front_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) - (((data->simulationInfo->realParameter[183]/* tire_front_left.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[181]/* tire_front_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) - (data->localData[0]->realVars[93]/* $cse15 variable */) )));
  TRACE_POP
}
/*
equation index: 441
type: SIMPLE_ASSIGN
$cse13 = sin(tire_front_left.magic_C * $cse14)
*/
void KIMM_CAR_eqFunction_441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,441};
  (data->localData[0]->realVars[91]/* $cse13 variable */)  = sin(((data->simulationInfo->realParameter[182]/* tire_front_left.magic_C PARAM */) ) * ((data->localData[0]->realVars[92]/* $cse14 variable */) ));
  TRACE_POP
}
/*
equation index: 442
type: SIMPLE_ASSIGN
tire_front_left.brake_force = tire_front_left.brake_force_max * tire_front_left.brake_out * $cse13
*/
void KIMM_CAR_eqFunction_442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,442};
  (data->localData[0]->realVars[286]/* tire_front_left.brake_force variable */)  = ((data->simulationInfo->realParameter[176]/* tire_front_left.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[288]/* tire_front_left.brake_out variable */) ) * ((data->localData[0]->realVars[91]/* $cse13 variable */) ));
  TRACE_POP
}
/*
equation index: 443
type: SIMPLE_ASSIGN
$cse12 = cos(body_Model.gnd_pitch_FL - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,443};
  (data->localData[0]->realVars[90]/* $cse12 variable */)  = cos((data->localData[0]->realVars[236]/* body_Model.gnd_pitch_FL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 444
type: SIMPLE_ASSIGN
tire_front_left.gap = (suspension_front_left.tire_z_pos - ray_front_left.k) * $cse12 - tire_front_left.radius
*/
void KIMM_CAR_eqFunction_444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,444};
  (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[14]/* suspension_front_left.tire_z_pos STATE(1,tire_front_left.dz) */)  - (data->simulationInfo->realParameter[145]/* ray_front_left.k PARAM */) ) * ((data->localData[0]->realVars[90]/* $cse12 variable */) ) - (data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ;
  TRACE_POP
}
/*
equation index: 445
type: SIMPLE_ASSIGN
$cse11 = sin(body_Model.gnd_pitch_FL - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,445};
  (data->localData[0]->realVars[89]/* $cse11 variable */)  = sin((data->localData[0]->realVars[236]/* body_Model.gnd_pitch_FL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 446
type: SIMPLE_ASSIGN
tire_front_left.d_gap = (suspension_front_left.tire_z_pos - ray_front_left.k) * $cse11 * body_Model.d_pitch + tire_front_left.dz * $cse12
*/
void KIMM_CAR_eqFunction_446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,446};
  (data->localData[0]->realVars[290]/* tire_front_left.d_gap variable */)  = ((data->localData[0]->realVars[14]/* suspension_front_left.tire_z_pos STATE(1,tire_front_left.dz) */)  - (data->simulationInfo->realParameter[145]/* ray_front_left.k PARAM */) ) * (((data->localData[0]->realVars[89]/* $cse11 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[21]/* tire_front_left.dz STATE(1,tire_front_left.ddz) */) ) * ((data->localData[0]->realVars[90]/* $cse12 variable */) );
  TRACE_POP
}
/*
equation index: 447
type: SIMPLE_ASSIGN
tire_front_left.tire_normal_force = if tire_front_left.gap < 0.0 then (-tire_front_left.wheel_spring_stiff) * tire_front_left.gap - tire_front_left.wheel_damper_stiff * tire_front_left.d_gap else 0.0
*/
void KIMM_CAR_eqFunction_447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,447};
  modelica_boolean tmp92;
  relationhysteresis(data, &tmp92, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */)  = (tmp92?((-(data->simulationInfo->realParameter[192]/* tire_front_left.wheel_spring_stiff PARAM */) )) * ((data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) ) - (((data->simulationInfo->realParameter[191]/* tire_front_left.wheel_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[290]/* tire_front_left.d_gap variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 448
type: SIMPLE_ASSIGN
tire_front_left.dfz = if tire_front_left.gap < 0.0 then -1.0 + 0.0001666666666666667 * tire_front_left.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,448};
  modelica_boolean tmp93;
  relationhysteresis(data, &tmp93, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[293]/* tire_front_left.dfz variable */)  = (tmp93?-1.0 + (0.0001666666666666667) * ((data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 449
type: SIMPLE_ASSIGN
tire_front_left.Ex = if tire_front_left.gap < 0.0 then 0.998281 * (0.11113 + 0.4143 * tire_front_left.dfz + (-0.02) * tire_front_left.dfz ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,449};
  modelica_boolean tmp94;
  modelica_real tmp95;
  modelica_boolean tmp96;
  modelica_real tmp97;
  relationhysteresis(data, &tmp94, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  tmp96 = (modelica_boolean)tmp94;
  if(tmp96)
  {
    tmp95 = (data->localData[0]->realVars[293]/* tire_front_left.dfz variable */) ;
    tmp97 = (0.998281) * (0.11113 + (0.4143) * ((data->localData[0]->realVars[293]/* tire_front_left.dfz variable */) ) + (-0.02) * ((tmp95 * tmp95)));
  }
  else
  {
    tmp97 = 0.0;
  }
  (data->localData[0]->realVars[282]/* tire_front_left.Ex variable */)  = tmp97;
  TRACE_POP
}
/*
equation index: 450
type: SIMPLE_ASSIGN
tire_front_left.Ey = if tire_front_left.gap < 0.0 then 0.90146 * (-0.8057 + (-0.6046) * tire_front_left.dfz) else 0.0
*/
void KIMM_CAR_eqFunction_450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,450};
  modelica_boolean tmp98;
  relationhysteresis(data, &tmp98, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[283]/* tire_front_left.Ey variable */)  = (tmp98?(0.90146) * (-0.8057 + (-0.6046) * ((data->localData[0]->realVars[293]/* tire_front_left.dfz variable */) )):0.0);
  TRACE_POP
}
/*
equation index: 451
type: SIMPLE_ASSIGN
tire_front_left.Dx = if tire_front_left.gap < 0.0 then (1.0822 + (-0.08284999999999999) * tire_front_left.dfz) * tire_front_left.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,451};
  modelica_boolean tmp99;
  relationhysteresis(data, &tmp99, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[280]/* tire_front_left.Dx variable */)  = (tmp99?(1.0822 + (-0.08284999999999999) * ((data->localData[0]->realVars[293]/* tire_front_left.dfz variable */) )) * ((data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 452
type: SIMPLE_ASSIGN
tire_front_left.Bx = if tire_front_left.gap < 0.0 then tire_front_left.tire_normal_force * (21.687 + 0.728 * tire_front_left.dfz) * exp((-0.9089) * tire_front_left.dfz) / (tire_front_left.Dx * 1.579) else 0.0
*/
void KIMM_CAR_eqFunction_452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,452};
  modelica_boolean tmp100;
  relationhysteresis(data, &tmp100, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[272]/* tire_front_left.Bx variable */)  = (tmp100?((data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */) ) * ((21.687 + (0.728) * ((data->localData[0]->realVars[293]/* tire_front_left.dfz variable */) )) * (DIVISION_SIM(exp((-0.9089) * ((data->localData[0]->realVars[293]/* tire_front_left.dfz variable */) )),((data->localData[0]->realVars[280]/* tire_front_left.Dx variable */) ) * (1.579),"tire_front_left.Dx * 1.579",equationIndexes))):0.0);
  TRACE_POP
}
/*
equation index: 453
type: SIMPLE_ASSIGN
tire_front_left.Dy = if tire_front_left.gap < 0.0 then (1.4785 + (-0.06451999999999999) * tire_front_left.dfz) * tire_front_left.tire_normal_force else 0.0
*/
void KIMM_CAR_eqFunction_453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,453};
  modelica_boolean tmp101;
  relationhysteresis(data, &tmp101, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[281]/* tire_front_left.Dy variable */)  = (tmp101?(1.4785 + (-0.06451999999999999) * ((data->localData[0]->realVars[293]/* tire_front_left.dfz variable */) )) * ((data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */) ):0.0);
  TRACE_POP
}
/*
equation index: 454
type: SIMPLE_ASSIGN
tire_front_left.By = if tire_front_left.gap < 0.0 then (-91944.0) * sin(2.0 * atan(tire_front_left.tire_normal_force / 10290.0)) / (tire_front_left.Dy * 1.338) else 0.0
*/
void KIMM_CAR_eqFunction_454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,454};
  modelica_boolean tmp102;
  relationhysteresis(data, &tmp102, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[274]/* tire_front_left.By variable */)  = (tmp102?(-91944.0) * (DIVISION_SIM(sin((2.0) * (atan(DIVISION_SIM((data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */) ,10290.0,"10290.0",equationIndexes)))),((data->localData[0]->realVars[281]/* tire_front_left.Dy variable */) ) * (1.338),"tire_front_left.Dy * 1.338",equationIndexes)):0.0);
  TRACE_POP
}
/*
equation index: 455
type: SIMPLE_ASSIGN
$DER.tire_front_left.gap = tire_front_left.d_gap
*/
void KIMM_CAR_eqFunction_455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,455};
  (data->localData[0]->realVars[83]/* der(tire_front_left.gap) DUMMY_DER */)  = (data->localData[0]->realVars[290]/* tire_front_left.d_gap variable */) ;
  TRACE_POP
}
/*
equation index: 456
type: SIMPLE_ASSIGN
$cse10 = cos(body_Model.yaw)
*/
void KIMM_CAR_eqFunction_456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,456};
  (data->localData[0]->realVars[88]/* $cse10 variable */)  = cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) );
  TRACE_POP
}
/*
equation index: 457
type: SIMPLE_ASSIGN
$cse9 = sin(body_Model.yaw)
*/
void KIMM_CAR_eqFunction_457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,457};
  (data->localData[0]->realVars[116]/* $cse9 variable */)  = sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) );
  TRACE_POP
}
/*
equation index: 458
type: SIMPLE_ASSIGN
$cse4 = cos(body_Model.pitch)
*/
void KIMM_CAR_eqFunction_458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,458};
  (data->localData[0]->realVars[111]/* $cse4 variable */)  = cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 459
type: SIMPLE_ASSIGN
$cse3 = cos(body_Model.roll)
*/
void KIMM_CAR_eqFunction_459(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,459};
  (data->localData[0]->realVars[109]/* $cse3 variable */)  = cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) );
  TRACE_POP
}
/*
equation index: 460
type: SIMPLE_ASSIGN
$cse2 = sin(body_Model.pitch)
*/
void KIMM_CAR_eqFunction_460(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,460};
  (data->localData[0]->realVars[98]/* $cse2 variable */)  = sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) );
  TRACE_POP
}
/*
equation index: 461
type: SIMPLE_ASSIGN
body_Model.body_fixed_dx = $cse4 * (body_Model.dx * $cse10 + body_Model.dy * $cse9) - body_Model.dz * $cse2
*/
void KIMM_CAR_eqFunction_461(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,461};
  (data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */)  = ((data->localData[0]->realVars[111]/* $cse4 variable */) ) * (((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * ((data->localData[0]->realVars[88]/* $cse10 variable */) ) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) )) - (((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) ));
  TRACE_POP
}
/*
equation index: 462
type: SIMPLE_ASSIGN
body_Model.Drag_force_vector[3,1] = 1.512 * body_Model.B_coord[3,1] * body_Model.Cd * body_Model.body_fixed_dx ^ 2.0
*/
void KIMM_CAR_eqFunction_462(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,462};
  modelica_real tmp103;
  tmp103 = (data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */) ;
  (data->localData[0]->realVars[163]/* body_Model.Drag_force_vector[3,1] variable */)  = (1.512) * (((data->localData[0]->realVars[146]/* body_Model.B_coord[3,1] variable */) ) * (((data->simulationInfo->realParameter[5]/* body_Model.Cd PARAM */) ) * ((tmp103 * tmp103))));
  TRACE_POP
}
/*
equation index: 463
type: SIMPLE_ASSIGN
body_Model.Drag_force_vector[2,1] = 1.512 * body_Model.B_coord[2,1] * body_Model.Cd * body_Model.body_fixed_dx ^ 2.0
*/
void KIMM_CAR_eqFunction_463(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,463};
  modelica_real tmp104;
  tmp104 = (data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */) ;
  (data->localData[0]->realVars[162]/* body_Model.Drag_force_vector[2,1] variable */)  = (1.512) * (((data->localData[0]->realVars[143]/* body_Model.B_coord[2,1] variable */) ) * (((data->simulationInfo->realParameter[5]/* body_Model.Cd PARAM */) ) * ((tmp104 * tmp104))));
  TRACE_POP
}
/*
equation index: 464
type: SIMPLE_ASSIGN
body_Model.Drag_force_vector[1,1] = 1.512 * body_Model.B_coord[1,1] * body_Model.Cd * body_Model.body_fixed_dx ^ 2.0
*/
void KIMM_CAR_eqFunction_464(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,464};
  modelica_real tmp105;
  tmp105 = (data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */) ;
  (data->localData[0]->realVars[161]/* body_Model.Drag_force_vector[1,1] variable */)  = (1.512) * (((data->localData[0]->realVars[140]/* body_Model.B_coord[1,1] variable */) ) * (((data->simulationInfo->realParameter[5]/* body_Model.Cd PARAM */) ) * ((tmp105 * tmp105))));
  TRACE_POP
}
/*
equation index: 465
type: SIMPLE_ASSIGN
body_Model.rear_right_dx = body_Model.body_fixed_dx + body_Model.distance_right * body_Model.d_yaw
*/
void KIMM_CAR_eqFunction_465(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,465};
  (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */)  = (data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */)  + ((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) );
  TRACE_POP
}
/*
equation index: 466
type: SIMPLE_ASSIGN
tire_rear_right.longitudinal_slip_ratio = if tire_rear_right.gap < 0.0 then if tire_rear_right.radius * tire_rear_right.d_roll > body_Model.rear_right_dx then (tire_rear_right.radius * tire_rear_right.d_roll - body_Model.rear_right_dx) / (tire_rear_right.radius * tire_rear_right.d_roll + 10.5) else (tire_rear_right.radius * tire_rear_right.d_roll - body_Model.rear_right_dx) / (body_Model.rear_right_dx + 10.5) else 0.0
*/
void KIMM_CAR_eqFunction_466(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,466};
  modelica_boolean tmp106;
  modelica_boolean tmp107;
  modelica_boolean tmp108;
  modelica_real tmp109;
  relationhysteresis(data, &tmp106, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  tmp108 = (modelica_boolean)tmp106;
  if(tmp108)
  {
    relationhysteresis(data, &tmp107, ((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ), (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) , 13, Greater, GreaterZC);
    tmp109 = (tmp107?DIVISION_SIM(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) - (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ,((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) + 10.5,"tire_rear_right.radius * tire_rear_right.d_roll + 10.5",equationIndexes):DIVISION_SIM(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) - (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ,(data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */)  + 10.5,"body_Model.rear_right_dx + 10.5",equationIndexes));
  }
  else
  {
    tmp109 = 0.0;
  }
  (data->localData[0]->realVars[399]/* tire_rear_right.longitudinal_slip_ratio variable */)  = tmp109;
  TRACE_POP
}
/*
equation index: 467
type: SIMPLE_ASSIGN
tire_rear_right.slip_ratio = if tire_rear_right.gap < 0.0 then if abs(tire_rear_right.longitudinal_slip_ratio) > 1.0 then (*Real*)(sign(tire_rear_right.longitudinal_slip_ratio)) else tire_rear_right.longitudinal_slip_ratio else 0.0
*/
void KIMM_CAR_eqFunction_467(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,467};
  modelica_boolean tmp110;
  modelica_boolean tmp111;
  modelica_boolean tmp112;
  modelica_real tmp113;
  relationhysteresis(data, &tmp110, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  tmp112 = (modelica_boolean)tmp110;
  if(tmp112)
  {
    relationhysteresis(data, &tmp111, fabs((data->localData[0]->realVars[399]/* tire_rear_right.longitudinal_slip_ratio variable */) ), 1.0, 14, Greater, GreaterZC);
    tmp113 = (tmp111?((modelica_real)sign((data->localData[0]->realVars[399]/* tire_rear_right.longitudinal_slip_ratio variable */) )):(data->localData[0]->realVars[399]/* tire_rear_right.longitudinal_slip_ratio variable */) );
  }
  else
  {
    tmp113 = 0.0;
  }
  (data->localData[0]->realVars[406]/* tire_rear_right.slip_ratio variable */)  = tmp113;
  TRACE_POP
}
/*
equation index: 468
type: SIMPLE_ASSIGN
tire_rear_right.Bxa = if tire_rear_right.gap < 0.0 then 2.046 / sqrt(1.0 + (9.718 * tire_rear_right.slip_ratio) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_468(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,468};
  modelica_boolean tmp114;
  modelica_real tmp115;
  modelica_boolean tmp116;
  modelica_real tmp117;
  relationhysteresis(data, &tmp114, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  tmp116 = (modelica_boolean)tmp114;
  if(tmp116)
  {
    tmp115 = (9.718) * ((data->localData[0]->realVars[406]/* tire_rear_right.slip_ratio variable */) );
    tmp117 = DIVISION_SIM(2.046,sqrt(1.0 + (tmp115 * tmp115)),"sqrt(1.0 + (9.718 * tire_rear_right.slip_ratio) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp117 = 0.0;
  }
  (data->localData[0]->realVars[375]/* tire_rear_right.Bxa variable */)  = tmp117;
  TRACE_POP
}
/*
equation index: 469
type: SIMPLE_ASSIGN
$whenCondition4 = abs(body_Model.rear_right_dx) < 0.05 and abs(tire_rear_right.radius * tire_rear_right.d_roll) < 0.08
*/
void KIMM_CAR_eqFunction_469(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,469};
  modelica_boolean tmp118;
  modelica_boolean tmp119;
  relationhysteresis(data, &tmp118, fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ), 0.05, 15, Less, LessZC);
  relationhysteresis(data, &tmp119, fabs(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) )), 0.08, 16, Less, LessZC);
  (data->localData[0]->booleanVars[3]/* $whenCondition4 DISCRETE */)  = (tmp118 && tmp119);
  TRACE_POP
}
/*
equation index: 470
type: SIMPLE_ASSIGN
body_Model.rear_left_dx = body_Model.body_fixed_dx - body_Model.distance_left * body_Model.d_yaw
*/
void KIMM_CAR_eqFunction_470(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,470};
  (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */)  = (data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */)  - (((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ));
  TRACE_POP
}
/*
equation index: 471
type: SIMPLE_ASSIGN
tire_rear_left.longitudinal_slip_ratio = if tire_rear_left.gap < 0.0 then if tire_rear_left.radius * tire_rear_left.d_roll > body_Model.rear_left_dx then (tire_rear_left.radius * tire_rear_left.d_roll - body_Model.rear_left_dx) / (tire_rear_left.radius * tire_rear_left.d_roll + 10.5) else (tire_rear_left.radius * tire_rear_left.d_roll - body_Model.rear_left_dx) / (body_Model.rear_left_dx + 10.5) else 0.0
*/
void KIMM_CAR_eqFunction_471(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,471};
  modelica_boolean tmp120;
  modelica_boolean tmp121;
  modelica_boolean tmp122;
  modelica_real tmp123;
  relationhysteresis(data, &tmp120, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  tmp122 = (modelica_boolean)tmp120;
  if(tmp122)
  {
    relationhysteresis(data, &tmp121, ((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ), (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) , 27, Greater, GreaterZC);
    tmp123 = (tmp121?DIVISION_SIM(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) - (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ,((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) + 10.5,"tire_rear_left.radius * tire_rear_left.d_roll + 10.5",equationIndexes):DIVISION_SIM(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) - (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ,(data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */)  + 10.5,"body_Model.rear_left_dx + 10.5",equationIndexes));
  }
  else
  {
    tmp123 = 0.0;
  }
  (data->localData[0]->realVars[365]/* tire_rear_left.longitudinal_slip_ratio variable */)  = tmp123;
  TRACE_POP
}
/*
equation index: 472
type: SIMPLE_ASSIGN
tire_rear_left.slip_ratio = if tire_rear_left.gap < 0.0 then if abs(tire_rear_left.longitudinal_slip_ratio) > 1.0 then (*Real*)(sign(tire_rear_left.longitudinal_slip_ratio)) else tire_rear_left.longitudinal_slip_ratio else 0.0
*/
void KIMM_CAR_eqFunction_472(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,472};
  modelica_boolean tmp124;
  modelica_boolean tmp125;
  modelica_boolean tmp126;
  modelica_real tmp127;
  relationhysteresis(data, &tmp124, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  tmp126 = (modelica_boolean)tmp124;
  if(tmp126)
  {
    relationhysteresis(data, &tmp125, fabs((data->localData[0]->realVars[365]/* tire_rear_left.longitudinal_slip_ratio variable */) ), 1.0, 28, Greater, GreaterZC);
    tmp127 = (tmp125?((modelica_real)sign((data->localData[0]->realVars[365]/* tire_rear_left.longitudinal_slip_ratio variable */) )):(data->localData[0]->realVars[365]/* tire_rear_left.longitudinal_slip_ratio variable */) );
  }
  else
  {
    tmp127 = 0.0;
  }
  (data->localData[0]->realVars[372]/* tire_rear_left.slip_ratio variable */)  = tmp127;
  TRACE_POP
}
/*
equation index: 473
type: SIMPLE_ASSIGN
tire_rear_left.Bxa = if tire_rear_left.gap < 0.0 then 2.046 / sqrt(1.0 + (9.718 * tire_rear_left.slip_ratio) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_473(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,473};
  modelica_boolean tmp128;
  modelica_real tmp129;
  modelica_boolean tmp130;
  modelica_real tmp131;
  relationhysteresis(data, &tmp128, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  tmp130 = (modelica_boolean)tmp128;
  if(tmp130)
  {
    tmp129 = (9.718) * ((data->localData[0]->realVars[372]/* tire_rear_left.slip_ratio variable */) );
    tmp131 = DIVISION_SIM(2.046,sqrt(1.0 + (tmp129 * tmp129)),"sqrt(1.0 + (9.718 * tire_rear_left.slip_ratio) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp131 = 0.0;
  }
  (data->localData[0]->realVars[341]/* tire_rear_left.Bxa variable */)  = tmp131;
  TRACE_POP
}
/*
equation index: 474
type: SIMPLE_ASSIGN
$whenCondition5 = abs(body_Model.rear_left_dx) < 0.05 and abs(tire_rear_left.radius * tire_rear_left.d_roll) < 0.08
*/
void KIMM_CAR_eqFunction_474(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,474};
  modelica_boolean tmp132;
  modelica_boolean tmp133;
  relationhysteresis(data, &tmp132, fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ), 0.05, 29, Less, LessZC);
  relationhysteresis(data, &tmp133, fabs(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) )), 0.08, 30, Less, LessZC);
  (data->localData[0]->booleanVars[4]/* $whenCondition5 DISCRETE */)  = (tmp132 && tmp133);
  TRACE_POP
}
/*
equation index: 475
type: SIMPLE_ASSIGN
$cse1 = sin(body_Model.roll)
*/
void KIMM_CAR_eqFunction_475(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,475};
  (data->localData[0]->realVars[87]/* $cse1 variable */)  = sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) );
  TRACE_POP
}
/*
equation index: 476
type: SIMPLE_ASSIGN
suspension_front_left.body_z_pos = body_Model.z + body_Model.distance_left * $cse1 * $cse4 - body_Model.distance_front * $cse2
*/
void KIMM_CAR_eqFunction_476(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,476};
  (data->localData[0]->realVars[260]/* suspension_front_left.body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) )) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) ));
  TRACE_POP
}
/*
equation index: 477
type: SIMPLE_ASSIGN
suspension_front_left.suspension_comp_dist = suspension_front_left.body_z_pos - suspension_front_left.tire_z_pos
*/
void KIMM_CAR_eqFunction_477(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,477};
  (data->localData[0]->realVars[261]/* suspension_front_left.suspension_comp_dist variable */)  = (data->localData[0]->realVars[260]/* suspension_front_left.body_z_pos DUMMY_STATE */)  - (data->localData[0]->realVars[14]/* suspension_front_left.tire_z_pos STATE(1,tire_front_left.dz) */) ;
  TRACE_POP
}
/*
equation index: 478
type: SIMPLE_ASSIGN
suspension_front_right.body_z_pos = body_Model.z + (-body_Model.distance_right) * $cse1 * $cse4 - body_Model.distance_front * $cse2
*/
void KIMM_CAR_eqFunction_478(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,478};
  (data->localData[0]->realVars[263]/* suspension_front_right.body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((-(data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) )) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) )) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) ));
  TRACE_POP
}
/*
equation index: 479
type: SIMPLE_ASSIGN
suspension_front_right.suspension_comp_dist = suspension_front_right.body_z_pos - suspension_front_right.tire_z_pos
*/
void KIMM_CAR_eqFunction_479(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,479};
  (data->localData[0]->realVars[264]/* suspension_front_right.suspension_comp_dist variable */)  = (data->localData[0]->realVars[263]/* suspension_front_right.body_z_pos DUMMY_STATE */)  - (data->localData[0]->realVars[15]/* suspension_front_right.tire_z_pos STATE(1,tire_front_right.dz) */) ;
  TRACE_POP
}
/*
equation index: 480
type: SIMPLE_ASSIGN
body_Model.rear_right_body_z_pos = body_Model.z + body_Model.distance_rear * $cse2 - body_Model.distance_right * $cse1 * $cse4
*/
void KIMM_CAR_eqFunction_480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,480};
  (data->localData[0]->realVars[248]/* body_Model.rear_right_body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) ) - (((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) )));
  TRACE_POP
}
/*
equation index: 481
type: SIMPLE_ASSIGN
suspension_rear_right.suspension_comp_dist = body_Model.rear_right_body_z_pos - suspension_rear_right.tire_z_pos
*/
void KIMM_CAR_eqFunction_481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,481};
  (data->localData[0]->realVars[270]/* suspension_rear_right.suspension_comp_dist variable */)  = (data->localData[0]->realVars[248]/* body_Model.rear_right_body_z_pos DUMMY_STATE */)  - (data->localData[0]->realVars[17]/* suspension_rear_right.tire_z_pos STATE(1,tire_rear_right.dz) */) ;
  TRACE_POP
}
/*
equation index: 482
type: SIMPLE_ASSIGN
body_Model.rear_left_body_z_pos = body_Model.z + body_Model.distance_left * $cse1 * $cse4 + body_Model.distance_rear * $cse2
*/
void KIMM_CAR_eqFunction_482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,482};
  (data->localData[0]->realVars[244]/* body_Model.rear_left_body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) )) + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) );
  TRACE_POP
}
/*
equation index: 483
type: SIMPLE_ASSIGN
suspension_rear_left.suspension_comp_dist = body_Model.rear_left_body_z_pos - suspension_rear_left.tire_z_pos
*/
void KIMM_CAR_eqFunction_483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,483};
  (data->localData[0]->realVars[267]/* suspension_rear_left.suspension_comp_dist variable */)  = (data->localData[0]->realVars[244]/* body_Model.rear_left_body_z_pos DUMMY_STATE */)  - (data->localData[0]->realVars[16]/* suspension_rear_left.tire_z_pos STATE(1,tire_rear_left.dz) */) ;
  TRACE_POP
}
/*
equation index: 484
type: SIMPLE_ASSIGN
body_Model.body_fixed_dy = body_Model.dx * ($cse10 * $cse2 * $cse1 - $cse3 * $cse9) + body_Model.dy * ($cse3 * $cse10 + $cse2 * $cse1 * $cse9) + body_Model.dz * $cse4 * $cse1
*/
void KIMM_CAR_eqFunction_484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,484};
  (data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) )) - (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * ((data->localData[0]->realVars[88]/* $cse10 variable */) ) + ((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) ));
  TRACE_POP
}
/*
equation index: 485
type: SIMPLE_ASSIGN
$whenCondition1 = abs(body_Model.body_fixed_dx) < 0.05 and abs(body_Model.body_fixed_dy) < 0.05
*/
void KIMM_CAR_eqFunction_485(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,485};
  modelica_boolean tmp134;
  modelica_boolean tmp135;
  relationhysteresis(data, &tmp134, fabs((data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */) ), 0.05, 0, Less, LessZC);
  relationhysteresis(data, &tmp135, fabs((data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */) ), 0.05, 1, Less, LessZC);
  (data->localData[0]->booleanVars[0]/* $whenCondition1 DISCRETE */)  = (tmp134 && tmp135);
  TRACE_POP
}
/*
equation index: 486
type: SIMPLE_ASSIGN
body_Model.rear_left_dy = body_Model.body_fixed_dy - body_Model.distance_rear * body_Model.d_yaw
*/
void KIMM_CAR_eqFunction_486(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,486};
  (data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */)  = (data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */)  - (((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ));
  TRACE_POP
}
/*
equation index: 487
type: SIMPLE_ASSIGN
body_Model.rear_right_slip_angle = if abs(body_Model.rear_right_dx) > 1e-06 then atan(body_Model.rear_left_dy / abs(body_Model.rear_right_dx)) else if abs(body_Model.rear_left_dy) > 1e-06 then 0.5 * body_Model.pi * (*Real*)(sign(body_Model.rear_left_dy)) else 0.0
*/
void KIMM_CAR_eqFunction_487(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,487};
  modelica_boolean tmp136;
  modelica_boolean tmp137;
  modelica_boolean tmp138;
  modelica_real tmp139;
  relationhysteresis(data, &tmp136, fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ), 1e-06, 11, Greater, GreaterZC);
  tmp138 = (modelica_boolean)tmp136;
  if(tmp138)
  {
    tmp139 = atan(DIVISION_SIM((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) ,fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ),"abs(body_Model.rear_right_dx)",equationIndexes));
  }
  else
  {
    relationhysteresis(data, &tmp137, fabs((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) ), 1e-06, 12, Greater, GreaterZC);
    tmp139 = (tmp137?(0.5) * (((data->simulationInfo->realParameter[17]/* body_Model.pi PARAM */) ) * (((modelica_real)sign((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) )))):0.0);
  }
  (data->localData[0]->realVars[250]/* body_Model.rear_right_slip_angle variable */)  = tmp139;
  TRACE_POP
}
/*
equation index: 488
type: SIMPLE_ASSIGN
tire_rear_right.side_slip = if tire_rear_right.gap < 0.0 then body_Model.rear_right_slip_angle else 0.0
*/
void KIMM_CAR_eqFunction_488(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,488};
  modelica_boolean tmp140;
  relationhysteresis(data, &tmp140, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[405]/* tire_rear_right.side_slip variable */)  = (tmp140?(data->localData[0]->realVars[250]/* body_Model.rear_right_slip_angle variable */) :0.0);
  TRACE_POP
}
/*
equation index: 489
type: SIMPLE_ASSIGN
tire_rear_right.Byk = if tire_rear_right.gap < 0.0 then 2.622 / sqrt(1.0 + (7.82 * tire_rear_right.side_slip) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_489(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,489};
  modelica_boolean tmp141;
  modelica_real tmp142;
  modelica_boolean tmp143;
  modelica_real tmp144;
  relationhysteresis(data, &tmp141, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  tmp143 = (modelica_boolean)tmp141;
  if(tmp143)
  {
    tmp142 = (7.82) * ((data->localData[0]->realVars[405]/* tire_rear_right.side_slip variable */) );
    tmp144 = DIVISION_SIM(2.622,sqrt(1.0 + (tmp142 * tmp142)),"sqrt(1.0 + (7.82 * tire_rear_right.side_slip) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp144 = 0.0;
  }
  (data->localData[0]->realVars[377]/* tire_rear_right.Byk variable */)  = tmp144;
  TRACE_POP
}
/*
equation index: 490
type: SIMPLE_ASSIGN
tire_rear_right.longitudinal_force = if tire_rear_right.gap < 0.0 then tire_rear_right.Dx * sin(1.579 * atan(tire_rear_right.Bx * tire_rear_right.slip_ratio - tire_rear_right.Ex * (tire_rear_right.Bx * tire_rear_right.slip_ratio - atan(tire_rear_right.Bx * tire_rear_right.slip_ratio)))) * cos(0.2995 * atan(tire_rear_right.Bxa * tire_rear_right.side_slip)) else 0.0
*/
void KIMM_CAR_eqFunction_490(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,490};
  modelica_boolean tmp145;
  relationhysteresis(data, &tmp145, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[398]/* tire_rear_right.longitudinal_force variable */)  = (tmp145?((data->localData[0]->realVars[382]/* tire_rear_right.Dx variable */) ) * ((sin((1.579) * (atan(((data->localData[0]->realVars[374]/* tire_rear_right.Bx variable */) ) * ((data->localData[0]->realVars[406]/* tire_rear_right.slip_ratio variable */) ) - (((data->localData[0]->realVars[384]/* tire_rear_right.Ex variable */) ) * (((data->localData[0]->realVars[374]/* tire_rear_right.Bx variable */) ) * ((data->localData[0]->realVars[406]/* tire_rear_right.slip_ratio variable */) ) - atan(((data->localData[0]->realVars[374]/* tire_rear_right.Bx variable */) ) * ((data->localData[0]->realVars[406]/* tire_rear_right.slip_ratio variable */) )))))))) * (cos((0.2995) * (atan(((data->localData[0]->realVars[375]/* tire_rear_right.Bxa variable */) ) * ((data->localData[0]->realVars[405]/* tire_rear_right.side_slip variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 491
type: SIMPLE_ASSIGN
tire_rear_right.dd_roll = (rear_open_differential.torque_to_right + ((-tire_rear_right.longitudinal_force) - tire_rear_right.brake_force) * tire_rear_right.radius) / tire_rear_right.inertia
*/
void KIMM_CAR_eqFunction_491(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,491};
  (data->localData[0]->realVars[393]/* tire_rear_right.dd_roll variable */)  = DIVISION_SIM((data->localData[0]->realVars[259]/* rear_open_differential.torque_to_right variable */)  + ((-(data->localData[0]->realVars[398]/* tire_rear_right.longitudinal_force variable */) ) - (data->localData[0]->realVars[388]/* tire_rear_right.brake_force variable */) ) * ((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ),(data->simulationInfo->realParameter[233]/* tire_rear_right.inertia PARAM */) ,"tire_rear_right.inertia",equationIndexes);
  TRACE_POP
}
/*
equation index: 492
type: SIMPLE_ASSIGN
$DER.tire_rear_right.d_roll = tire_rear_right.dd_roll
*/
void KIMM_CAR_eqFunction_492(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,492};
  (data->localData[0]->realVars[73]/* der(tire_rear_right.d_roll) STATE_DER */)  = (data->localData[0]->realVars[393]/* tire_rear_right.dd_roll variable */) ;
  TRACE_POP
}
/*
equation index: 493
type: SIMPLE_ASSIGN
tire_rear_right.net_lateral_force = if tire_rear_right.gap < 0.0 then tire_rear_right.Dy * sin(1.338 * atan(tire_rear_right.By * tire_rear_right.side_slip - tire_rear_right.Ey * (tire_rear_right.By * tire_rear_right.side_slip - atan(tire_rear_right.By * tire_rear_right.side_slip)))) * cos(0.85 * atan(tire_rear_right.Byk * tire_rear_right.slip_ratio)) else 0.0
*/
void KIMM_CAR_eqFunction_493(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,493};
  modelica_boolean tmp146;
  relationhysteresis(data, &tmp146, (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, 8, Less, LessZC);
  (data->localData[0]->realVars[402]/* tire_rear_right.net_lateral_force variable */)  = (tmp146?((data->localData[0]->realVars[383]/* tire_rear_right.Dy variable */) ) * ((sin((1.338) * (atan(((data->localData[0]->realVars[376]/* tire_rear_right.By variable */) ) * ((data->localData[0]->realVars[405]/* tire_rear_right.side_slip variable */) ) - (((data->localData[0]->realVars[385]/* tire_rear_right.Ey variable */) ) * (((data->localData[0]->realVars[376]/* tire_rear_right.By variable */) ) * ((data->localData[0]->realVars[405]/* tire_rear_right.side_slip variable */) ) - atan(((data->localData[0]->realVars[376]/* tire_rear_right.By variable */) ) * ((data->localData[0]->realVars[405]/* tire_rear_right.side_slip variable */) )))))))) * (cos((0.85) * (atan(((data->localData[0]->realVars[377]/* tire_rear_right.Byk variable */) ) * ((data->localData[0]->realVars[406]/* tire_rear_right.slip_ratio variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 494
type: SIMPLE_ASSIGN
body_Model.rear_left_slip_angle = if abs(body_Model.rear_left_dx) > 1e-06 then atan(body_Model.rear_left_dy / abs(body_Model.rear_left_dx)) else if abs(body_Model.rear_left_dy) > 1e-06 then 0.5 * body_Model.pi * (*Real*)(sign(body_Model.rear_left_dy)) else 0.0
*/
void KIMM_CAR_eqFunction_494(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,494};
  modelica_boolean tmp147;
  modelica_boolean tmp148;
  modelica_boolean tmp149;
  modelica_real tmp150;
  relationhysteresis(data, &tmp147, fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ), 1e-06, 26, Greater, GreaterZC);
  tmp149 = (modelica_boolean)tmp147;
  if(tmp149)
  {
    tmp150 = atan(DIVISION_SIM((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) ,fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ),"abs(body_Model.rear_left_dx)",equationIndexes));
  }
  else
  {
    relationhysteresis(data, &tmp148, fabs((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) ), 1e-06, 12, Greater, GreaterZC);
    tmp150 = (tmp148?(0.5) * (((data->simulationInfo->realParameter[17]/* body_Model.pi PARAM */) ) * (((modelica_real)sign((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) )))):0.0);
  }
  (data->localData[0]->realVars[247]/* body_Model.rear_left_slip_angle variable */)  = tmp150;
  TRACE_POP
}
/*
equation index: 495
type: SIMPLE_ASSIGN
tire_rear_left.side_slip = if tire_rear_left.gap < 0.0 then body_Model.rear_left_slip_angle else 0.0
*/
void KIMM_CAR_eqFunction_495(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,495};
  modelica_boolean tmp151;
  relationhysteresis(data, &tmp151, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[371]/* tire_rear_left.side_slip variable */)  = (tmp151?(data->localData[0]->realVars[247]/* body_Model.rear_left_slip_angle variable */) :0.0);
  TRACE_POP
}
/*
equation index: 496
type: SIMPLE_ASSIGN
tire_rear_left.Byk = if tire_rear_left.gap < 0.0 then 2.622 / sqrt(1.0 + (7.82 * tire_rear_left.side_slip) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_496(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,496};
  modelica_boolean tmp152;
  modelica_real tmp153;
  modelica_boolean tmp154;
  modelica_real tmp155;
  relationhysteresis(data, &tmp152, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  tmp154 = (modelica_boolean)tmp152;
  if(tmp154)
  {
    tmp153 = (7.82) * ((data->localData[0]->realVars[371]/* tire_rear_left.side_slip variable */) );
    tmp155 = DIVISION_SIM(2.622,sqrt(1.0 + (tmp153 * tmp153)),"sqrt(1.0 + (7.82 * tire_rear_left.side_slip) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp155 = 0.0;
  }
  (data->localData[0]->realVars[343]/* tire_rear_left.Byk variable */)  = tmp155;
  TRACE_POP
}
/*
equation index: 497
type: SIMPLE_ASSIGN
tire_rear_left.longitudinal_force = if tire_rear_left.gap < 0.0 then tire_rear_left.Dx * sin(1.579 * atan(tire_rear_left.Bx * tire_rear_left.slip_ratio - tire_rear_left.Ex * (tire_rear_left.Bx * tire_rear_left.slip_ratio - atan(tire_rear_left.Bx * tire_rear_left.slip_ratio)))) * cos(0.2995 * atan(tire_rear_left.Bxa * tire_rear_left.side_slip)) else 0.0
*/
void KIMM_CAR_eqFunction_497(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,497};
  modelica_boolean tmp156;
  relationhysteresis(data, &tmp156, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[364]/* tire_rear_left.longitudinal_force variable */)  = (tmp156?((data->localData[0]->realVars[348]/* tire_rear_left.Dx variable */) ) * ((sin((1.579) * (atan(((data->localData[0]->realVars[340]/* tire_rear_left.Bx variable */) ) * ((data->localData[0]->realVars[372]/* tire_rear_left.slip_ratio variable */) ) - (((data->localData[0]->realVars[350]/* tire_rear_left.Ex variable */) ) * (((data->localData[0]->realVars[340]/* tire_rear_left.Bx variable */) ) * ((data->localData[0]->realVars[372]/* tire_rear_left.slip_ratio variable */) ) - atan(((data->localData[0]->realVars[340]/* tire_rear_left.Bx variable */) ) * ((data->localData[0]->realVars[372]/* tire_rear_left.slip_ratio variable */) )))))))) * (cos((0.2995) * (atan(((data->localData[0]->realVars[341]/* tire_rear_left.Bxa variable */) ) * ((data->localData[0]->realVars[371]/* tire_rear_left.side_slip variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 498
type: SIMPLE_ASSIGN
tire_rear_left.dd_roll = (rear_open_differential.torque_to_right + ((-tire_rear_left.longitudinal_force) - tire_rear_left.brake_force) * tire_rear_left.radius) / tire_rear_left.inertia
*/
void KIMM_CAR_eqFunction_498(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,498};
  (data->localData[0]->realVars[359]/* tire_rear_left.dd_roll variable */)  = DIVISION_SIM((data->localData[0]->realVars[259]/* rear_open_differential.torque_to_right variable */)  + ((-(data->localData[0]->realVars[364]/* tire_rear_left.longitudinal_force variable */) ) - (data->localData[0]->realVars[354]/* tire_rear_left.brake_force variable */) ) * ((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ),(data->simulationInfo->realParameter[215]/* tire_rear_left.inertia PARAM */) ,"tire_rear_left.inertia",equationIndexes);
  TRACE_POP
}
/*
equation index: 499
type: SIMPLE_ASSIGN
$DER.tire_rear_left.d_roll = tire_rear_left.dd_roll
*/
void KIMM_CAR_eqFunction_499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,499};
  (data->localData[0]->realVars[68]/* der(tire_rear_left.d_roll) STATE_DER */)  = (data->localData[0]->realVars[359]/* tire_rear_left.dd_roll variable */) ;
  TRACE_POP
}
/*
equation index: 500
type: SIMPLE_ASSIGN
tire_rear_left.net_lateral_force = if tire_rear_left.gap < 0.0 then tire_rear_left.Dy * sin(1.338 * atan(tire_rear_left.By * tire_rear_left.side_slip - tire_rear_left.Ey * (tire_rear_left.By * tire_rear_left.side_slip - atan(tire_rear_left.By * tire_rear_left.side_slip)))) * cos(0.85 * atan(tire_rear_left.Byk * tire_rear_left.slip_ratio)) else 0.0
*/
void KIMM_CAR_eqFunction_500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,500};
  modelica_boolean tmp157;
  relationhysteresis(data, &tmp157, (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, 7, Less, LessZC);
  (data->localData[0]->realVars[368]/* tire_rear_left.net_lateral_force variable */)  = (tmp157?((data->localData[0]->realVars[349]/* tire_rear_left.Dy variable */) ) * ((sin((1.338) * (atan(((data->localData[0]->realVars[342]/* tire_rear_left.By variable */) ) * ((data->localData[0]->realVars[371]/* tire_rear_left.side_slip variable */) ) - (((data->localData[0]->realVars[351]/* tire_rear_left.Ey variable */) ) * (((data->localData[0]->realVars[342]/* tire_rear_left.By variable */) ) * ((data->localData[0]->realVars[371]/* tire_rear_left.side_slip variable */) ) - atan(((data->localData[0]->realVars[342]/* tire_rear_left.By variable */) ) * ((data->localData[0]->realVars[371]/* tire_rear_left.side_slip variable */) )))))))) * (cos((0.85) * (atan(((data->localData[0]->realVars[343]/* tire_rear_left.Byk variable */) ) * ((data->localData[0]->realVars[372]/* tire_rear_left.slip_ratio variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 501
type: SIMPLE_ASSIGN
body_Model.front_right_dy = body_Model.body_fixed_dy + body_Model.distance_front * body_Model.d_yaw
*/
void KIMM_CAR_eqFunction_501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,501};
  (data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */)  = (data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */)  + ((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) );
  TRACE_POP
}
/*
equation index: 502
type: SIMPLE_ASSIGN
body_Model.front_right_vx = body_Model.rear_right_dx * $cse7 + body_Model.front_right_dy * $cse8
*/
void KIMM_CAR_eqFunction_502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,502};
  (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */)  = ((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ) * ((data->localData[0]->realVars[114]/* $cse7 variable */) ) + ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * ((data->localData[0]->realVars[115]/* $cse8 variable */) );
  TRACE_POP
}
/*
equation index: 503
type: SIMPLE_ASSIGN
tire_front_right.longitudinal_slip_ratio = if tire_front_right.gap < 0.0 then if tire_front_right.radius * tire_front_right.d_roll > body_Model.front_right_vx then (tire_front_right.radius * tire_front_right.d_roll - body_Model.front_right_vx) / (tire_front_right.radius * tire_front_right.d_roll + 10.5) else (tire_front_right.radius * tire_front_right.d_roll - body_Model.front_right_vx) / (body_Model.front_right_vx + 10.5) else 0.0
*/
void KIMM_CAR_eqFunction_503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,503};
  modelica_boolean tmp158;
  modelica_boolean tmp159;
  modelica_boolean tmp160;
  modelica_real tmp161;
  relationhysteresis(data, &tmp158, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  tmp160 = (modelica_boolean)tmp158;
  if(tmp160)
  {
    relationhysteresis(data, &tmp159, ((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ), (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) , 17, Greater, GreaterZC);
    tmp161 = (tmp159?DIVISION_SIM(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) - (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) ,((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) + 10.5,"tire_front_right.radius * tire_front_right.d_roll + 10.5",equationIndexes):DIVISION_SIM(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) - (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) ,(data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */)  + 10.5,"body_Model.front_right_vx + 10.5",equationIndexes));
  }
  else
  {
    tmp161 = 0.0;
  }
  (data->localData[0]->realVars[331]/* tire_front_right.longitudinal_slip_ratio variable */)  = tmp161;
  TRACE_POP
}
/*
equation index: 504
type: SIMPLE_ASSIGN
tire_front_right.slip_ratio = if tire_front_right.gap < 0.0 then if abs(tire_front_right.longitudinal_slip_ratio) > 1.0 then (*Real*)(sign(tire_front_right.longitudinal_slip_ratio)) else tire_front_right.longitudinal_slip_ratio else 0.0
*/
void KIMM_CAR_eqFunction_504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,504};
  modelica_boolean tmp162;
  modelica_boolean tmp163;
  modelica_boolean tmp164;
  modelica_real tmp165;
  relationhysteresis(data, &tmp162, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  tmp164 = (modelica_boolean)tmp162;
  if(tmp164)
  {
    relationhysteresis(data, &tmp163, fabs((data->localData[0]->realVars[331]/* tire_front_right.longitudinal_slip_ratio variable */) ), 1.0, 18, Greater, GreaterZC);
    tmp165 = (tmp163?((modelica_real)sign((data->localData[0]->realVars[331]/* tire_front_right.longitudinal_slip_ratio variable */) )):(data->localData[0]->realVars[331]/* tire_front_right.longitudinal_slip_ratio variable */) );
  }
  else
  {
    tmp165 = 0.0;
  }
  (data->localData[0]->realVars[338]/* tire_front_right.slip_ratio variable */)  = tmp165;
  TRACE_POP
}
/*
equation index: 505
type: SIMPLE_ASSIGN
tire_front_right.Bxa = if tire_front_right.gap < 0.0 then 2.046 / sqrt(1.0 + (9.718 * tire_front_right.slip_ratio) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,505};
  modelica_boolean tmp166;
  modelica_real tmp167;
  modelica_boolean tmp168;
  modelica_real tmp169;
  relationhysteresis(data, &tmp166, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  tmp168 = (modelica_boolean)tmp166;
  if(tmp168)
  {
    tmp167 = (9.718) * ((data->localData[0]->realVars[338]/* tire_front_right.slip_ratio variable */) );
    tmp169 = DIVISION_SIM(2.046,sqrt(1.0 + (tmp167 * tmp167)),"sqrt(1.0 + (9.718 * tire_front_right.slip_ratio) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp169 = 0.0;
  }
  (data->localData[0]->realVars[307]/* tire_front_right.Bxa variable */)  = tmp169;
  TRACE_POP
}
/*
equation index: 506
type: SIMPLE_ASSIGN
$whenCondition3 = abs(body_Model.front_right_vx) < 0.05 and abs(tire_front_right.radius * tire_front_right.d_roll) < 0.08
*/
void KIMM_CAR_eqFunction_506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,506};
  modelica_boolean tmp170;
  modelica_boolean tmp171;
  relationhysteresis(data, &tmp170, fabs((data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) ), 0.05, 19, Less, LessZC);
  relationhysteresis(data, &tmp171, fabs(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) )), 0.08, 20, Less, LessZC);
  (data->localData[0]->booleanVars[2]/* $whenCondition3 DISCRETE */)  = (tmp170 && tmp171);
  TRACE_POP
}
/*
equation index: 507
type: SIMPLE_ASSIGN
body_Model.front_right_vy = body_Model.front_right_dy * $cse7 - body_Model.rear_right_dx * $cse8
*/
void KIMM_CAR_eqFunction_507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,507};
  (data->localData[0]->realVars[235]/* body_Model.front_right_vy variable */)  = ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * ((data->localData[0]->realVars[114]/* $cse7 variable */) ) - (((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ) * ((data->localData[0]->realVars[115]/* $cse8 variable */) ));
  TRACE_POP
}
/*
equation index: 508
type: SIMPLE_ASSIGN
body_Model.front_right_slip_angle = if abs(body_Model.rear_right_dx) > 1e-06 then atan(body_Model.front_right_dy / abs(body_Model.rear_right_dx)) - ackerman_Steering_Model.right_steer_angle * sign(body_Model.rear_right_dx) else if abs(body_Model.front_right_dy) > 1e-06 then 0.5 * body_Model.pi * (*Real*)(sign(body_Model.front_right_dy)) else 0.0
*/
void KIMM_CAR_eqFunction_508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,508};
  modelica_boolean tmp172;
  modelica_boolean tmp173;
  modelica_boolean tmp174;
  modelica_real tmp175;
  relationhysteresis(data, &tmp172, fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ), 1e-06, 11, Greater, GreaterZC);
  tmp174 = (modelica_boolean)tmp172;
  if(tmp174)
  {
    tmp175 = atan(DIVISION_SIM((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ,fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ),"abs(body_Model.rear_right_dx)",equationIndexes)) - (((data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */) ) * (sign((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) )));
  }
  else
  {
    relationhysteresis(data, &tmp173, fabs((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ), 1e-06, 21, Greater, GreaterZC);
    tmp175 = (tmp173?(0.5) * (((data->simulationInfo->realParameter[17]/* body_Model.pi PARAM */) ) * (((modelica_real)sign((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) )))):0.0);
  }
  (data->localData[0]->realVars[233]/* body_Model.front_right_slip_angle variable */)  = tmp175;
  TRACE_POP
}
/*
equation index: 509
type: SIMPLE_ASSIGN
tire_front_right.side_slip = if tire_front_right.gap < 0.0 then body_Model.front_right_slip_angle else 0.0
*/
void KIMM_CAR_eqFunction_509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,509};
  modelica_boolean tmp176;
  relationhysteresis(data, &tmp176, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[337]/* tire_front_right.side_slip variable */)  = (tmp176?(data->localData[0]->realVars[233]/* body_Model.front_right_slip_angle variable */) :0.0);
  TRACE_POP
}
/*
equation index: 510
type: SIMPLE_ASSIGN
tire_front_right.Byk = if tire_front_right.gap < 0.0 then 2.622 / sqrt(1.0 + (7.82 * tire_front_right.side_slip) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,510};
  modelica_boolean tmp177;
  modelica_real tmp178;
  modelica_boolean tmp179;
  modelica_real tmp180;
  relationhysteresis(data, &tmp177, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  tmp179 = (modelica_boolean)tmp177;
  if(tmp179)
  {
    tmp178 = (7.82) * ((data->localData[0]->realVars[337]/* tire_front_right.side_slip variable */) );
    tmp180 = DIVISION_SIM(2.622,sqrt(1.0 + (tmp178 * tmp178)),"sqrt(1.0 + (7.82 * tire_front_right.side_slip) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp180 = 0.0;
  }
  (data->localData[0]->realVars[309]/* tire_front_right.Byk variable */)  = tmp180;
  TRACE_POP
}
/*
equation index: 511
type: SIMPLE_ASSIGN
tire_front_right.longitudinal_force = if tire_front_right.gap < 0.0 then tire_front_right.Dx * sin(1.579 * atan(tire_front_right.Bx * tire_front_right.slip_ratio - tire_front_right.Ex * (tire_front_right.Bx * tire_front_right.slip_ratio - atan(tire_front_right.Bx * tire_front_right.slip_ratio)))) * cos(0.2995 * atan(tire_front_right.Bxa * tire_front_right.side_slip)) else 0.0
*/
void KIMM_CAR_eqFunction_511(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,511};
  modelica_boolean tmp181;
  relationhysteresis(data, &tmp181, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[330]/* tire_front_right.longitudinal_force variable */)  = (tmp181?((data->localData[0]->realVars[314]/* tire_front_right.Dx variable */) ) * ((sin((1.579) * (atan(((data->localData[0]->realVars[306]/* tire_front_right.Bx variable */) ) * ((data->localData[0]->realVars[338]/* tire_front_right.slip_ratio variable */) ) - (((data->localData[0]->realVars[316]/* tire_front_right.Ex variable */) ) * (((data->localData[0]->realVars[306]/* tire_front_right.Bx variable */) ) * ((data->localData[0]->realVars[338]/* tire_front_right.slip_ratio variable */) ) - atan(((data->localData[0]->realVars[306]/* tire_front_right.Bx variable */) ) * ((data->localData[0]->realVars[338]/* tire_front_right.slip_ratio variable */) )))))))) * (cos((0.2995) * (atan(((data->localData[0]->realVars[307]/* tire_front_right.Bxa variable */) ) * ((data->localData[0]->realVars[337]/* tire_front_right.side_slip variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 512
type: SIMPLE_ASSIGN
tire_front_right.dd_roll = ((-tire_front_right.longitudinal_force) - tire_front_right.brake_force) * tire_front_right.radius / tire_front_right.inertia
*/
void KIMM_CAR_eqFunction_512(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,512};
  (data->localData[0]->realVars[325]/* tire_front_right.dd_roll variable */)  = DIVISION_SIM(((-(data->localData[0]->realVars[330]/* tire_front_right.longitudinal_force variable */) ) - (data->localData[0]->realVars[320]/* tire_front_right.brake_force variable */) ) * ((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ),(data->simulationInfo->realParameter[197]/* tire_front_right.inertia PARAM */) ,"tire_front_right.inertia",equationIndexes);
  TRACE_POP
}
/*
equation index: 513
type: SIMPLE_ASSIGN
$DER.tire_front_right.d_roll = tire_front_right.dd_roll
*/
void KIMM_CAR_eqFunction_513(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,513};
  (data->localData[0]->realVars[63]/* der(tire_front_right.d_roll) STATE_DER */)  = (data->localData[0]->realVars[325]/* tire_front_right.dd_roll variable */) ;
  TRACE_POP
}
/*
equation index: 514
type: SIMPLE_ASSIGN
tire_front_right.net_lateral_force = if tire_front_right.gap < 0.0 then tire_front_right.Dy * sin(1.338 * atan(tire_front_right.By * tire_front_right.side_slip - tire_front_right.Ey * (tire_front_right.By * tire_front_right.side_slip - atan(tire_front_right.By * tire_front_right.side_slip)))) * cos(0.85 * atan(tire_front_right.Byk * tire_front_right.slip_ratio)) else 0.0
*/
void KIMM_CAR_eqFunction_514(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,514};
  modelica_boolean tmp182;
  relationhysteresis(data, &tmp182, (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, 9, Less, LessZC);
  (data->localData[0]->realVars[334]/* tire_front_right.net_lateral_force variable */)  = (tmp182?((data->localData[0]->realVars[315]/* tire_front_right.Dy variable */) ) * ((sin((1.338) * (atan(((data->localData[0]->realVars[308]/* tire_front_right.By variable */) ) * ((data->localData[0]->realVars[337]/* tire_front_right.side_slip variable */) ) - (((data->localData[0]->realVars[317]/* tire_front_right.Ey variable */) ) * (((data->localData[0]->realVars[308]/* tire_front_right.By variable */) ) * ((data->localData[0]->realVars[337]/* tire_front_right.side_slip variable */) ) - atan(((data->localData[0]->realVars[308]/* tire_front_right.By variable */) ) * ((data->localData[0]->realVars[337]/* tire_front_right.side_slip variable */) )))))))) * (cos((0.85) * (atan(((data->localData[0]->realVars[309]/* tire_front_right.Byk variable */) ) * ((data->localData[0]->realVars[338]/* tire_front_right.slip_ratio variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 515
type: SIMPLE_ASSIGN
body_Model.front_left_vx = body_Model.rear_left_dx * $cse5 + body_Model.front_right_dy * $cse6
*/
void KIMM_CAR_eqFunction_515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,515};
  (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */)  = ((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ) * ((data->localData[0]->realVars[112]/* $cse5 variable */) ) + ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * ((data->localData[0]->realVars[113]/* $cse6 variable */) );
  TRACE_POP
}
/*
equation index: 516
type: SIMPLE_ASSIGN
tire_front_left.longitudinal_slip_ratio = if tire_front_left.gap < 0.0 then if tire_front_left.radius * tire_front_left.d_roll > body_Model.front_left_vx then (tire_front_left.radius * tire_front_left.d_roll - body_Model.front_left_vx) / (tire_front_left.radius * tire_front_left.d_roll + 10.5) else (tire_front_left.radius * tire_front_left.d_roll - body_Model.front_left_vx) / (body_Model.front_left_vx + 10.5) else 0.0
*/
void KIMM_CAR_eqFunction_516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,516};
  modelica_boolean tmp183;
  modelica_boolean tmp184;
  modelica_boolean tmp185;
  modelica_real tmp186;
  relationhysteresis(data, &tmp183, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  tmp185 = (modelica_boolean)tmp183;
  if(tmp185)
  {
    relationhysteresis(data, &tmp184, ((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ), (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) , 22, Greater, GreaterZC);
    tmp186 = (tmp184?DIVISION_SIM(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) - (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) ,((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) + 10.5,"tire_front_left.radius * tire_front_left.d_roll + 10.5",equationIndexes):DIVISION_SIM(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) - (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) ,(data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */)  + 10.5,"body_Model.front_left_vx + 10.5",equationIndexes));
  }
  else
  {
    tmp186 = 0.0;
  }
  (data->localData[0]->realVars[297]/* tire_front_left.longitudinal_slip_ratio variable */)  = tmp186;
  TRACE_POP
}
/*
equation index: 517
type: SIMPLE_ASSIGN
tire_front_left.slip_ratio = if tire_front_left.gap < 0.0 then if abs(tire_front_left.longitudinal_slip_ratio) > 1.0 then (*Real*)(sign(tire_front_left.longitudinal_slip_ratio)) else tire_front_left.longitudinal_slip_ratio else 0.0
*/
void KIMM_CAR_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,517};
  modelica_boolean tmp187;
  modelica_boolean tmp188;
  modelica_boolean tmp189;
  modelica_real tmp190;
  relationhysteresis(data, &tmp187, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  tmp189 = (modelica_boolean)tmp187;
  if(tmp189)
  {
    relationhysteresis(data, &tmp188, fabs((data->localData[0]->realVars[297]/* tire_front_left.longitudinal_slip_ratio variable */) ), 1.0, 23, Greater, GreaterZC);
    tmp190 = (tmp188?((modelica_real)sign((data->localData[0]->realVars[297]/* tire_front_left.longitudinal_slip_ratio variable */) )):(data->localData[0]->realVars[297]/* tire_front_left.longitudinal_slip_ratio variable */) );
  }
  else
  {
    tmp190 = 0.0;
  }
  (data->localData[0]->realVars[304]/* tire_front_left.slip_ratio variable */)  = tmp190;
  TRACE_POP
}
/*
equation index: 518
type: SIMPLE_ASSIGN
tire_front_left.Bxa = if tire_front_left.gap < 0.0 then 2.046 / sqrt(1.0 + (9.718 * tire_front_left.slip_ratio) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,518};
  modelica_boolean tmp191;
  modelica_real tmp192;
  modelica_boolean tmp193;
  modelica_real tmp194;
  relationhysteresis(data, &tmp191, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  tmp193 = (modelica_boolean)tmp191;
  if(tmp193)
  {
    tmp192 = (9.718) * ((data->localData[0]->realVars[304]/* tire_front_left.slip_ratio variable */) );
    tmp194 = DIVISION_SIM(2.046,sqrt(1.0 + (tmp192 * tmp192)),"sqrt(1.0 + (9.718 * tire_front_left.slip_ratio) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp194 = 0.0;
  }
  (data->localData[0]->realVars[273]/* tire_front_left.Bxa variable */)  = tmp194;
  TRACE_POP
}
/*
equation index: 519
type: SIMPLE_ASSIGN
$whenCondition2 = abs(body_Model.front_left_vx) < 0.05 and abs(tire_front_left.radius * tire_front_left.d_roll) < 0.08
*/
void KIMM_CAR_eqFunction_519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,519};
  modelica_boolean tmp195;
  modelica_boolean tmp196;
  relationhysteresis(data, &tmp195, fabs((data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) ), 0.05, 24, Less, LessZC);
  relationhysteresis(data, &tmp196, fabs(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) )), 0.08, 25, Less, LessZC);
  (data->localData[0]->booleanVars[1]/* $whenCondition2 DISCRETE */)  = (tmp195 && tmp196);
  TRACE_POP
}
/*
equation index: 520
type: SIMPLE_ASSIGN
body_Model.front_left_vy = body_Model.front_right_dy * $cse5 - body_Model.rear_left_dx * $cse6
*/
void KIMM_CAR_eqFunction_520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,520};
  (data->localData[0]->realVars[230]/* body_Model.front_left_vy variable */)  = ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * ((data->localData[0]->realVars[112]/* $cse5 variable */) ) - (((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ) * ((data->localData[0]->realVars[113]/* $cse6 variable */) ));
  TRACE_POP
}
/*
equation index: 521
type: SIMPLE_ASSIGN
body_Model.front_left_slip_angle = if abs(body_Model.rear_left_dx) > 1e-06 then atan(body_Model.front_right_dy / abs(body_Model.rear_left_dx)) - ackerman_Steering_Model.left_steer_angle * sign(body_Model.rear_left_dx) else if abs(body_Model.front_right_dy) > 1e-06 then 0.5 * body_Model.pi * (*Real*)(sign(body_Model.front_right_dy)) else 0.0
*/
void KIMM_CAR_eqFunction_521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,521};
  modelica_boolean tmp197;
  modelica_boolean tmp198;
  modelica_boolean tmp199;
  modelica_real tmp200;
  relationhysteresis(data, &tmp197, fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ), 1e-06, 26, Greater, GreaterZC);
  tmp199 = (modelica_boolean)tmp197;
  if(tmp199)
  {
    tmp200 = atan(DIVISION_SIM((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ,fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ),"abs(body_Model.rear_left_dx)",equationIndexes)) - (((data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */) ) * (sign((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) )));
  }
  else
  {
    relationhysteresis(data, &tmp198, fabs((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ), 1e-06, 21, Greater, GreaterZC);
    tmp200 = (tmp198?(0.5) * (((data->simulationInfo->realParameter[17]/* body_Model.pi PARAM */) ) * (((modelica_real)sign((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) )))):0.0);
  }
  (data->localData[0]->realVars[228]/* body_Model.front_left_slip_angle variable */)  = tmp200;
  TRACE_POP
}
/*
equation index: 522
type: SIMPLE_ASSIGN
tire_front_left.side_slip = if tire_front_left.gap < 0.0 then body_Model.front_left_slip_angle else 0.0
*/
void KIMM_CAR_eqFunction_522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,522};
  modelica_boolean tmp201;
  relationhysteresis(data, &tmp201, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[303]/* tire_front_left.side_slip variable */)  = (tmp201?(data->localData[0]->realVars[228]/* body_Model.front_left_slip_angle variable */) :0.0);
  TRACE_POP
}
/*
equation index: 523
type: SIMPLE_ASSIGN
tire_front_left.Byk = if tire_front_left.gap < 0.0 then 2.622 / sqrt(1.0 + (7.82 * tire_front_left.side_slip) ^ 2.0) else 0.0
*/
void KIMM_CAR_eqFunction_523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,523};
  modelica_boolean tmp202;
  modelica_real tmp203;
  modelica_boolean tmp204;
  modelica_real tmp205;
  relationhysteresis(data, &tmp202, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  tmp204 = (modelica_boolean)tmp202;
  if(tmp204)
  {
    tmp203 = (7.82) * ((data->localData[0]->realVars[303]/* tire_front_left.side_slip variable */) );
    tmp205 = DIVISION_SIM(2.622,sqrt(1.0 + (tmp203 * tmp203)),"sqrt(1.0 + (7.82 * tire_front_left.side_slip) ^ 2.0)",equationIndexes);
  }
  else
  {
    tmp205 = 0.0;
  }
  (data->localData[0]->realVars[275]/* tire_front_left.Byk variable */)  = tmp205;
  TRACE_POP
}
/*
equation index: 524
type: SIMPLE_ASSIGN
tire_front_left.longitudinal_force = if tire_front_left.gap < 0.0 then tire_front_left.Dx * sin(1.579 * atan(tire_front_left.Bx * tire_front_left.slip_ratio - tire_front_left.Ex * (tire_front_left.Bx * tire_front_left.slip_ratio - atan(tire_front_left.Bx * tire_front_left.slip_ratio)))) * cos(0.2995 * atan(tire_front_left.Bxa * tire_front_left.side_slip)) else 0.0
*/
void KIMM_CAR_eqFunction_524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,524};
  modelica_boolean tmp206;
  relationhysteresis(data, &tmp206, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[296]/* tire_front_left.longitudinal_force variable */)  = (tmp206?((data->localData[0]->realVars[280]/* tire_front_left.Dx variable */) ) * ((sin((1.579) * (atan(((data->localData[0]->realVars[272]/* tire_front_left.Bx variable */) ) * ((data->localData[0]->realVars[304]/* tire_front_left.slip_ratio variable */) ) - (((data->localData[0]->realVars[282]/* tire_front_left.Ex variable */) ) * (((data->localData[0]->realVars[272]/* tire_front_left.Bx variable */) ) * ((data->localData[0]->realVars[304]/* tire_front_left.slip_ratio variable */) ) - atan(((data->localData[0]->realVars[272]/* tire_front_left.Bx variable */) ) * ((data->localData[0]->realVars[304]/* tire_front_left.slip_ratio variable */) )))))))) * (cos((0.2995) * (atan(((data->localData[0]->realVars[273]/* tire_front_left.Bxa variable */) ) * ((data->localData[0]->realVars[303]/* tire_front_left.side_slip variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 525
type: SIMPLE_ASSIGN
tire_front_left.dd_roll = ((-tire_front_left.longitudinal_force) - tire_front_left.brake_force) * tire_front_left.radius / tire_front_left.inertia
*/
void KIMM_CAR_eqFunction_525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,525};
  (data->localData[0]->realVars[291]/* tire_front_left.dd_roll variable */)  = DIVISION_SIM(((-(data->localData[0]->realVars[296]/* tire_front_left.longitudinal_force variable */) ) - (data->localData[0]->realVars[286]/* tire_front_left.brake_force variable */) ) * ((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ),(data->simulationInfo->realParameter[179]/* tire_front_left.inertia PARAM */) ,"tire_front_left.inertia",equationIndexes);
  TRACE_POP
}
/*
equation index: 526
type: SIMPLE_ASSIGN
$DER.tire_front_left.d_roll = tire_front_left.dd_roll
*/
void KIMM_CAR_eqFunction_526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,526};
  (data->localData[0]->realVars[58]/* der(tire_front_left.d_roll) STATE_DER */)  = (data->localData[0]->realVars[291]/* tire_front_left.dd_roll variable */) ;
  TRACE_POP
}
/*
equation index: 527
type: SIMPLE_ASSIGN
tire_front_left.net_lateral_force = if tire_front_left.gap < 0.0 then tire_front_left.Dy * sin(1.338 * atan(tire_front_left.By * tire_front_left.side_slip - tire_front_left.Ey * (tire_front_left.By * tire_front_left.side_slip - atan(tire_front_left.By * tire_front_left.side_slip)))) * cos(0.85 * atan(tire_front_left.Byk * tire_front_left.slip_ratio)) else 0.0
*/
void KIMM_CAR_eqFunction_527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,527};
  modelica_boolean tmp207;
  relationhysteresis(data, &tmp207, (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, 10, Less, LessZC);
  (data->localData[0]->realVars[300]/* tire_front_left.net_lateral_force variable */)  = (tmp207?((data->localData[0]->realVars[281]/* tire_front_left.Dy variable */) ) * ((sin((1.338) * (atan(((data->localData[0]->realVars[274]/* tire_front_left.By variable */) ) * ((data->localData[0]->realVars[303]/* tire_front_left.side_slip variable */) ) - (((data->localData[0]->realVars[283]/* tire_front_left.Ey variable */) ) * (((data->localData[0]->realVars[274]/* tire_front_left.By variable */) ) * ((data->localData[0]->realVars[303]/* tire_front_left.side_slip variable */) ) - atan(((data->localData[0]->realVars[274]/* tire_front_left.By variable */) ) * ((data->localData[0]->realVars[303]/* tire_front_left.side_slip variable */) )))))))) * (cos((0.85) * (atan(((data->localData[0]->realVars[275]/* tire_front_left.Byk variable */) ) * ((data->localData[0]->realVars[304]/* tire_front_left.slip_ratio variable */) )))))):0.0);
  TRACE_POP
}
/*
equation index: 528
type: SIMPLE_ASSIGN
body_Model.body_fixed_dz = body_Model.dx * ($cse1 * $cse9 + $cse3 * $cse10 * $cse2) + body_Model.dy * ($cse3 * $cse2 * $cse9 - $cse10 * $cse1) + body_Model.dz * $cse4 * $cse3
*/
void KIMM_CAR_eqFunction_528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,528};
  (data->localData[0]->realVars[217]/* body_Model.body_fixed_dz DUMMY_STATE */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) ))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) )) - (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) ))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[109]/* $cse3 variable */) ));
  TRACE_POP
}
/*
equation index: 529
type: SIMPLE_ASSIGN
suspension_rear_left.body_z_vel = body_Model.dz + body_Model.distance_left * ($cse1 * (-$cse2) * body_Model.d_pitch + $cse3 * body_Model.d_roll * $cse4) + body_Model.distance_rear * $cse4 * body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,529};
  (data->localData[0]->realVars[266]/* suspension_rear_left.body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((-(data->localData[0]->realVars[98]/* $cse2 variable */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) ))) + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ));
  TRACE_POP
}
/*
equation index: 530
type: SIMPLE_ASSIGN
suspension_rear_left.suspension_force = suspension_rear_left.suspension_damper_stiff * (suspension_rear_left.body_z_vel - tire_rear_left.dz) + suspension_rear_left.suspension_spring_stiff * suspension_rear_left.suspension_comp_dist
*/
void KIMM_CAR_eqFunction_530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,530};
  (data->localData[0]->realVars[268]/* suspension_rear_left.suspension_force variable */)  = ((data->simulationInfo->realParameter[169]/* suspension_rear_left.suspension_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[266]/* suspension_rear_left.body_z_vel variable */)  - (data->localData[0]->realVars[31]/* tire_rear_left.dz STATE(1,tire_rear_left.ddz) */) ) + ((data->simulationInfo->realParameter[171]/* suspension_rear_left.suspension_spring_stiff PARAM */) ) * ((data->localData[0]->realVars[267]/* suspension_rear_left.suspension_comp_dist variable */) );
  TRACE_POP
}
/*
equation index: 531
type: SIMPLE_ASSIGN
body_Model.T_force_vector_RL[1,1] = body_Model.T_coord_RL[1,1] * tire_rear_left.longitudinal_force + body_Model.T_coord_RL[1,2] * tire_rear_left.net_lateral_force - body_Model.T_coord_RL[1,3] * suspension_rear_left.suspension_force
*/
void KIMM_CAR_eqFunction_531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,531};
  (data->localData[0]->realVars[206]/* body_Model.T_force_vector_RL[1,1] variable */)  = ((data->localData[0]->realVars[182]/* body_Model.T_coord_RL[1,1] variable */) ) * ((data->localData[0]->realVars[364]/* tire_rear_left.longitudinal_force variable */) ) + ((data->localData[0]->realVars[183]/* body_Model.T_coord_RL[1,2] variable */) ) * ((data->localData[0]->realVars[368]/* tire_rear_left.net_lateral_force variable */) ) - (((data->localData[0]->realVars[184]/* body_Model.T_coord_RL[1,3] variable */) ) * ((data->localData[0]->realVars[268]/* suspension_rear_left.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 532
type: SIMPLE_ASSIGN
body_Model.T_force_vector_RL[2,1] = body_Model.T_coord_RL[2,1] * tire_rear_left.longitudinal_force + body_Model.T_coord_RL[2,2] * tire_rear_left.net_lateral_force - body_Model.T_coord_RL[2,3] * suspension_rear_left.suspension_force
*/
void KIMM_CAR_eqFunction_532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,532};
  (data->localData[0]->realVars[207]/* body_Model.T_force_vector_RL[2,1] variable */)  = ((data->localData[0]->realVars[185]/* body_Model.T_coord_RL[2,1] variable */) ) * ((data->localData[0]->realVars[364]/* tire_rear_left.longitudinal_force variable */) ) + ((data->localData[0]->realVars[186]/* body_Model.T_coord_RL[2,2] variable */) ) * ((data->localData[0]->realVars[368]/* tire_rear_left.net_lateral_force variable */) ) - (((data->localData[0]->realVars[187]/* body_Model.T_coord_RL[2,3] variable */) ) * ((data->localData[0]->realVars[268]/* suspension_rear_left.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 533
type: SIMPLE_ASSIGN
body_Model.T_force_vector_RL[3,1] = body_Model.T_coord_RL[3,1] * tire_rear_left.longitudinal_force + body_Model.T_coord_RL[3,2] * tire_rear_left.net_lateral_force - body_Model.T_coord_RL[3,3] * suspension_rear_left.suspension_force
*/
void KIMM_CAR_eqFunction_533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,533};
  (data->localData[0]->realVars[208]/* body_Model.T_force_vector_RL[3,1] variable */)  = ((data->localData[0]->realVars[188]/* body_Model.T_coord_RL[3,1] variable */) ) * ((data->localData[0]->realVars[364]/* tire_rear_left.longitudinal_force variable */) ) + ((data->localData[0]->realVars[189]/* body_Model.T_coord_RL[3,2] variable */) ) * ((data->localData[0]->realVars[368]/* tire_rear_left.net_lateral_force variable */) ) - (((data->localData[0]->realVars[190]/* body_Model.T_coord_RL[3,3] variable */) ) * ((data->localData[0]->realVars[268]/* suspension_rear_left.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 534
type: ARRAY_CALL_ASSIGN

body_Model.B_force_vector_RL = change_of_coordinate(body_Model.B_coord, body_Model.T_force_vector_RL)
*/
void KIMM_CAR_eqFunction_534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,534};
  real_array tmp208;
  real_array tmp209;
  real_array tmp210;
  real_array_create(&tmp208, ((modelica_real*)&((&data->localData[0]->realVars[140]/* body_Model.B_coord[1,1] variable */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)3);
  real_array_create(&tmp209, ((modelica_real*)&((&data->localData[0]->realVars[206]/* body_Model.T_force_vector_RL[1,1] variable */)[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)1);
  real_array_create(&tmp210, ((modelica_real*)&((&(data->localData[0]->realVars[155]/* body_Model.B_force_vector_RL[1,1] variable */) )[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)1);
  real_array_copy_data(omc_change__of__coordinate(threadData, tmp208, tmp209), tmp210);
  TRACE_POP
}
/*
equation index: 535
type: SIMPLE_ASSIGN
tire_rear_left.ddz = (tire_rear_left.tire_normal_force + suspension_rear_left.suspension_force + 9.81 * (-tire_rear_left.mass) * $cse4 * $cse3) / tire_rear_left.mass
*/
void KIMM_CAR_eqFunction_535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,535};
  (data->localData[0]->realVars[360]/* tire_rear_left.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */)  + (data->localData[0]->realVars[268]/* suspension_rear_left.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[220]/* tire_rear_left.mass PARAM */) )) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[109]/* $cse3 variable */) ))),(data->simulationInfo->realParameter[220]/* tire_rear_left.mass PARAM */) ,"tire_rear_left.mass",equationIndexes);
  TRACE_POP
}
/*
equation index: 536
type: SIMPLE_ASSIGN
$DER.tire_rear_left.dz = tire_rear_left.ddz
*/
void KIMM_CAR_eqFunction_536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,536};
  (data->localData[0]->realVars[69]/* der(tire_rear_left.dz) STATE_DER */)  = (data->localData[0]->realVars[360]/* tire_rear_left.ddz variable */) ;
  TRACE_POP
}
/*
equation index: 537
type: SIMPLE_ASSIGN
$DER.body_Model.rear_left_body_z_pos = suspension_rear_left.body_z_vel
*/
void KIMM_CAR_eqFunction_537(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,537};
  (data->localData[0]->realVars[79]/* der(body_Model.rear_left_body_z_pos) DUMMY_DER */)  = (data->localData[0]->realVars[266]/* suspension_rear_left.body_z_vel variable */) ;
  TRACE_POP
}
/*
equation index: 538
type: SIMPLE_ASSIGN
suspension_rear_right.body_z_vel = body_Model.dz + body_Model.distance_rear * $cse4 * body_Model.d_pitch - body_Model.distance_right * ($cse1 * (-$cse2) * body_Model.d_pitch + $cse3 * body_Model.d_roll * $cse4)
*/
void KIMM_CAR_eqFunction_538(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,538};
  (data->localData[0]->realVars[269]/* suspension_rear_right.body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) - (((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((-(data->localData[0]->realVars[98]/* $cse2 variable */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) ))));
  TRACE_POP
}
/*
equation index: 539
type: SIMPLE_ASSIGN
suspension_rear_right.suspension_force = suspension_rear_right.suspension_damper_stiff * (suspension_rear_right.body_z_vel - tire_rear_right.dz) + suspension_rear_right.suspension_spring_stiff * suspension_rear_right.suspension_comp_dist
*/
void KIMM_CAR_eqFunction_539(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,539};
  (data->localData[0]->realVars[271]/* suspension_rear_right.suspension_force variable */)  = ((data->simulationInfo->realParameter[172]/* suspension_rear_right.suspension_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[269]/* suspension_rear_right.body_z_vel variable */)  - (data->localData[0]->realVars[36]/* tire_rear_right.dz STATE(1,tire_rear_right.ddz) */) ) + ((data->simulationInfo->realParameter[174]/* suspension_rear_right.suspension_spring_stiff PARAM */) ) * ((data->localData[0]->realVars[270]/* suspension_rear_right.suspension_comp_dist variable */) );
  TRACE_POP
}
/*
equation index: 540
type: SIMPLE_ASSIGN
body_Model.T_force_vector_RR[1,1] = body_Model.T_coord_RR[1,1] * tire_rear_right.longitudinal_force + body_Model.T_coord_RR[1,2] * tire_rear_right.net_lateral_force - body_Model.T_coord_RR[1,3] * suspension_rear_right.suspension_force
*/
void KIMM_CAR_eqFunction_540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,540};
  (data->localData[0]->realVars[209]/* body_Model.T_force_vector_RR[1,1] variable */)  = ((data->localData[0]->realVars[191]/* body_Model.T_coord_RR[1,1] variable */) ) * ((data->localData[0]->realVars[398]/* tire_rear_right.longitudinal_force variable */) ) + ((data->localData[0]->realVars[192]/* body_Model.T_coord_RR[1,2] variable */) ) * ((data->localData[0]->realVars[402]/* tire_rear_right.net_lateral_force variable */) ) - (((data->localData[0]->realVars[193]/* body_Model.T_coord_RR[1,3] variable */) ) * ((data->localData[0]->realVars[271]/* suspension_rear_right.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 541
type: SIMPLE_ASSIGN
body_Model.T_force_vector_RR[2,1] = body_Model.T_coord_RR[2,1] * tire_rear_right.longitudinal_force + body_Model.T_coord_RR[2,2] * tire_rear_right.net_lateral_force - body_Model.T_coord_RR[2,3] * suspension_rear_right.suspension_force
*/
void KIMM_CAR_eqFunction_541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,541};
  (data->localData[0]->realVars[210]/* body_Model.T_force_vector_RR[2,1] variable */)  = ((data->localData[0]->realVars[194]/* body_Model.T_coord_RR[2,1] variable */) ) * ((data->localData[0]->realVars[398]/* tire_rear_right.longitudinal_force variable */) ) + ((data->localData[0]->realVars[195]/* body_Model.T_coord_RR[2,2] variable */) ) * ((data->localData[0]->realVars[402]/* tire_rear_right.net_lateral_force variable */) ) - (((data->localData[0]->realVars[196]/* body_Model.T_coord_RR[2,3] variable */) ) * ((data->localData[0]->realVars[271]/* suspension_rear_right.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 542
type: SIMPLE_ASSIGN
body_Model.T_force_vector_RR[3,1] = body_Model.T_coord_RR[3,1] * tire_rear_right.longitudinal_force + body_Model.T_coord_RR[3,2] * tire_rear_right.net_lateral_force - body_Model.T_coord_RR[3,3] * suspension_rear_right.suspension_force
*/
void KIMM_CAR_eqFunction_542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,542};
  (data->localData[0]->realVars[211]/* body_Model.T_force_vector_RR[3,1] variable */)  = ((data->localData[0]->realVars[197]/* body_Model.T_coord_RR[3,1] variable */) ) * ((data->localData[0]->realVars[398]/* tire_rear_right.longitudinal_force variable */) ) + ((data->localData[0]->realVars[198]/* body_Model.T_coord_RR[3,2] variable */) ) * ((data->localData[0]->realVars[402]/* tire_rear_right.net_lateral_force variable */) ) - (((data->localData[0]->realVars[199]/* body_Model.T_coord_RR[3,3] variable */) ) * ((data->localData[0]->realVars[271]/* suspension_rear_right.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 543
type: ARRAY_CALL_ASSIGN

body_Model.B_force_vector_RR = change_of_coordinate(body_Model.B_coord, body_Model.T_force_vector_RR)
*/
void KIMM_CAR_eqFunction_543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,543};
  real_array tmp211;
  real_array tmp212;
  real_array tmp213;
  real_array_create(&tmp211, ((modelica_real*)&((&data->localData[0]->realVars[140]/* body_Model.B_coord[1,1] variable */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)3);
  real_array_create(&tmp212, ((modelica_real*)&((&data->localData[0]->realVars[209]/* body_Model.T_force_vector_RR[1,1] variable */)[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)1);
  real_array_create(&tmp213, ((modelica_real*)&((&(data->localData[0]->realVars[158]/* body_Model.B_force_vector_RR[1,1] variable */) )[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)1);
  real_array_copy_data(omc_change__of__coordinate(threadData, tmp211, tmp212), tmp213);
  TRACE_POP
}
/*
equation index: 544
type: SIMPLE_ASSIGN
tire_rear_right.ddz = (tire_rear_right.tire_normal_force + suspension_rear_right.suspension_force + 9.81 * (-tire_rear_right.mass) * $cse4 * $cse3) / tire_rear_right.mass
*/
void KIMM_CAR_eqFunction_544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,544};
  (data->localData[0]->realVars[394]/* tire_rear_right.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */)  + (data->localData[0]->realVars[271]/* suspension_rear_right.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[238]/* tire_rear_right.mass PARAM */) )) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[109]/* $cse3 variable */) ))),(data->simulationInfo->realParameter[238]/* tire_rear_right.mass PARAM */) ,"tire_rear_right.mass",equationIndexes);
  TRACE_POP
}
/*
equation index: 545
type: SIMPLE_ASSIGN
$DER.tire_rear_right.dz = tire_rear_right.ddz
*/
void KIMM_CAR_eqFunction_545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,545};
  (data->localData[0]->realVars[74]/* der(tire_rear_right.dz) STATE_DER */)  = (data->localData[0]->realVars[394]/* tire_rear_right.ddz variable */) ;
  TRACE_POP
}
/*
equation index: 546
type: SIMPLE_ASSIGN
$DER.body_Model.rear_right_body_z_pos = suspension_rear_right.body_z_vel
*/
void KIMM_CAR_eqFunction_546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,546};
  (data->localData[0]->realVars[80]/* der(body_Model.rear_right_body_z_pos) DUMMY_DER */)  = (data->localData[0]->realVars[269]/* suspension_rear_right.body_z_vel variable */) ;
  TRACE_POP
}
/*
equation index: 547
type: SIMPLE_ASSIGN
body_Model.front_right_body_z_vel = body_Model.dz + (-body_Model.distance_right) * ($cse1 * (-$cse2) * body_Model.d_pitch + $cse3 * body_Model.d_roll * $cse4) - body_Model.distance_front * $cse4 * body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,547};
  (data->localData[0]->realVars[231]/* body_Model.front_right_body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((-(data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) )) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((-(data->localData[0]->realVars[98]/* $cse2 variable */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) ))) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )));
  TRACE_POP
}
/*
equation index: 548
type: SIMPLE_ASSIGN
suspension_front_right.suspension_force = suspension_front_right.suspension_damper_stiff * (body_Model.front_right_body_z_vel - tire_front_right.dz) + suspension_front_right.suspension_spring_stiff * suspension_front_right.suspension_comp_dist
*/
void KIMM_CAR_eqFunction_548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,548};
  (data->localData[0]->realVars[265]/* suspension_front_right.suspension_force variable */)  = ((data->simulationInfo->realParameter[166]/* suspension_front_right.suspension_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[231]/* body_Model.front_right_body_z_vel variable */)  - (data->localData[0]->realVars[26]/* tire_front_right.dz STATE(1,tire_front_right.ddz) */) ) + ((data->simulationInfo->realParameter[168]/* suspension_front_right.suspension_spring_stiff PARAM */) ) * ((data->localData[0]->realVars[264]/* suspension_front_right.suspension_comp_dist variable */) );
  TRACE_POP
}
/*
equation index: 549
type: SIMPLE_ASSIGN
body_Model.T_force_vector_FR[1,1] = body_Model.T_coord_FR[1,1] * tire_front_right.longitudinal_force + body_Model.T_coord_FR[1,2] * tire_front_right.net_lateral_force - body_Model.T_coord_FR[1,3] * suspension_front_right.suspension_force
*/
void KIMM_CAR_eqFunction_549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  (data->localData[0]->realVars[203]/* body_Model.T_force_vector_FR[1,1] variable */)  = ((data->localData[0]->realVars[173]/* body_Model.T_coord_FR[1,1] variable */) ) * ((data->localData[0]->realVars[330]/* tire_front_right.longitudinal_force variable */) ) + ((data->localData[0]->realVars[174]/* body_Model.T_coord_FR[1,2] variable */) ) * ((data->localData[0]->realVars[334]/* tire_front_right.net_lateral_force variable */) ) - (((data->localData[0]->realVars[175]/* body_Model.T_coord_FR[1,3] variable */) ) * ((data->localData[0]->realVars[265]/* suspension_front_right.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 550
type: SIMPLE_ASSIGN
body_Model.T_force_vector_FR[2,1] = body_Model.T_coord_FR[2,1] * tire_front_right.longitudinal_force + body_Model.T_coord_FR[2,2] * tire_front_right.net_lateral_force - body_Model.T_coord_FR[2,3] * suspension_front_right.suspension_force
*/
void KIMM_CAR_eqFunction_550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  (data->localData[0]->realVars[204]/* body_Model.T_force_vector_FR[2,1] variable */)  = ((data->localData[0]->realVars[176]/* body_Model.T_coord_FR[2,1] variable */) ) * ((data->localData[0]->realVars[330]/* tire_front_right.longitudinal_force variable */) ) + ((data->localData[0]->realVars[177]/* body_Model.T_coord_FR[2,2] variable */) ) * ((data->localData[0]->realVars[334]/* tire_front_right.net_lateral_force variable */) ) - (((data->localData[0]->realVars[178]/* body_Model.T_coord_FR[2,3] variable */) ) * ((data->localData[0]->realVars[265]/* suspension_front_right.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 551
type: SIMPLE_ASSIGN
body_Model.T_force_vector_FR[3,1] = body_Model.T_coord_FR[3,1] * tire_front_right.longitudinal_force + body_Model.T_coord_FR[3,2] * tire_front_right.net_lateral_force - body_Model.T_coord_FR[3,3] * suspension_front_right.suspension_force
*/
void KIMM_CAR_eqFunction_551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  (data->localData[0]->realVars[205]/* body_Model.T_force_vector_FR[3,1] variable */)  = ((data->localData[0]->realVars[179]/* body_Model.T_coord_FR[3,1] variable */) ) * ((data->localData[0]->realVars[330]/* tire_front_right.longitudinal_force variable */) ) + ((data->localData[0]->realVars[180]/* body_Model.T_coord_FR[3,2] variable */) ) * ((data->localData[0]->realVars[334]/* tire_front_right.net_lateral_force variable */) ) - (((data->localData[0]->realVars[181]/* body_Model.T_coord_FR[3,3] variable */) ) * ((data->localData[0]->realVars[265]/* suspension_front_right.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 552
type: ARRAY_CALL_ASSIGN

body_Model.B_force_vector_FR = change_of_coordinate(body_Model.B_coord, body_Model.T_force_vector_FR)
*/
void KIMM_CAR_eqFunction_552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  real_array tmp214;
  real_array tmp215;
  real_array tmp216;
  real_array_create(&tmp214, ((modelica_real*)&((&data->localData[0]->realVars[140]/* body_Model.B_coord[1,1] variable */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)3);
  real_array_create(&tmp215, ((modelica_real*)&((&data->localData[0]->realVars[203]/* body_Model.T_force_vector_FR[1,1] variable */)[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)1);
  real_array_create(&tmp216, ((modelica_real*)&((&(data->localData[0]->realVars[152]/* body_Model.B_force_vector_FR[1,1] variable */) )[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)1);
  real_array_copy_data(omc_change__of__coordinate(threadData, tmp214, tmp215), tmp216);
  TRACE_POP
}
/*
equation index: 553
type: SIMPLE_ASSIGN
tire_front_right.ddz = (tire_front_right.tire_normal_force + suspension_front_right.suspension_force + 9.81 * (-tire_front_right.mass) * $cse4 * $cse3) / tire_front_right.mass
*/
void KIMM_CAR_eqFunction_553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
  (data->localData[0]->realVars[326]/* tire_front_right.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */)  + (data->localData[0]->realVars[265]/* suspension_front_right.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[202]/* tire_front_right.mass PARAM */) )) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[109]/* $cse3 variable */) ))),(data->simulationInfo->realParameter[202]/* tire_front_right.mass PARAM */) ,"tire_front_right.mass",equationIndexes);
  TRACE_POP
}
/*
equation index: 554
type: SIMPLE_ASSIGN
$DER.tire_front_right.dz = tire_front_right.ddz
*/
void KIMM_CAR_eqFunction_554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  (data->localData[0]->realVars[64]/* der(tire_front_right.dz) STATE_DER */)  = (data->localData[0]->realVars[326]/* tire_front_right.ddz variable */) ;
  TRACE_POP
}
/*
equation index: 555
type: SIMPLE_ASSIGN
$DER.suspension_front_right.body_z_pos = body_Model.front_right_body_z_vel
*/
void KIMM_CAR_eqFunction_555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
  (data->localData[0]->realVars[82]/* der(suspension_front_right.body_z_pos) DUMMY_DER */)  = (data->localData[0]->realVars[231]/* body_Model.front_right_body_z_vel variable */) ;
  TRACE_POP
}
/*
equation index: 556
type: SIMPLE_ASSIGN
body_Model.front_left_body_z_vel = body_Model.dz + body_Model.distance_left * ($cse1 * (-$cse2) * body_Model.d_pitch + $cse3 * body_Model.d_roll * $cse4) - body_Model.distance_front * $cse4 * body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  (data->localData[0]->realVars[227]/* body_Model.front_left_body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((-(data->localData[0]->realVars[98]/* $cse2 variable */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[111]/* $cse4 variable */) ))) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )));
  TRACE_POP
}
/*
equation index: 557
type: SIMPLE_ASSIGN
suspension_front_left.suspension_force = suspension_front_left.suspension_damper_stiff * (body_Model.front_left_body_z_vel - tire_front_left.dz) + suspension_front_left.suspension_spring_stiff * suspension_front_left.suspension_comp_dist
*/
void KIMM_CAR_eqFunction_557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
  (data->localData[0]->realVars[262]/* suspension_front_left.suspension_force variable */)  = ((data->simulationInfo->realParameter[163]/* suspension_front_left.suspension_damper_stiff PARAM */) ) * ((data->localData[0]->realVars[227]/* body_Model.front_left_body_z_vel variable */)  - (data->localData[0]->realVars[21]/* tire_front_left.dz STATE(1,tire_front_left.ddz) */) ) + ((data->simulationInfo->realParameter[165]/* suspension_front_left.suspension_spring_stiff PARAM */) ) * ((data->localData[0]->realVars[261]/* suspension_front_left.suspension_comp_dist variable */) );
  TRACE_POP
}
/*
equation index: 558
type: SIMPLE_ASSIGN
body_Model.T_force_vector_FL[1,1] = body_Model.T_coord_FL[1,1] * tire_front_left.longitudinal_force + body_Model.T_coord_FL[1,2] * tire_front_left.net_lateral_force - body_Model.T_coord_FL[1,3] * suspension_front_left.suspension_force
*/
void KIMM_CAR_eqFunction_558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  (data->localData[0]->realVars[200]/* body_Model.T_force_vector_FL[1,1] variable */)  = ((data->localData[0]->realVars[164]/* body_Model.T_coord_FL[1,1] variable */) ) * ((data->localData[0]->realVars[296]/* tire_front_left.longitudinal_force variable */) ) + ((data->localData[0]->realVars[165]/* body_Model.T_coord_FL[1,2] variable */) ) * ((data->localData[0]->realVars[300]/* tire_front_left.net_lateral_force variable */) ) - (((data->localData[0]->realVars[166]/* body_Model.T_coord_FL[1,3] variable */) ) * ((data->localData[0]->realVars[262]/* suspension_front_left.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 559
type: SIMPLE_ASSIGN
body_Model.net_force[1,1] = body_Model.T_force_vector_FL[1,1] + body_Model.T_force_vector_FR[1,1] + body_Model.T_force_vector_RR[1,1] + body_Model.T_force_vector_RL[1,1] - body_Model.Drag_force_vector[1,1]
*/
void KIMM_CAR_eqFunction_559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
  (data->localData[0]->realVars[241]/* body_Model.net_force[1,1] variable */)  = (data->localData[0]->realVars[200]/* body_Model.T_force_vector_FL[1,1] variable */)  + (data->localData[0]->realVars[203]/* body_Model.T_force_vector_FR[1,1] variable */)  + (data->localData[0]->realVars[209]/* body_Model.T_force_vector_RR[1,1] variable */)  + (data->localData[0]->realVars[206]/* body_Model.T_force_vector_RL[1,1] variable */)  - (data->localData[0]->realVars[161]/* body_Model.Drag_force_vector[1,1] variable */) ;
  TRACE_POP
}
/*
equation index: 560
type: SIMPLE_ASSIGN
body_Model.ddx = body_Model.net_force[1,1] / body_Model.mass_total
*/
void KIMM_CAR_eqFunction_560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  (data->localData[0]->realVars[224]/* body_Model.ddx variable */)  = DIVISION_SIM((data->localData[0]->realVars[241]/* body_Model.net_force[1,1] variable */) ,(data->localData[0]->realVars[240]/* body_Model.mass_total variable */) ,"body_Model.mass_total",equationIndexes);
  TRACE_POP
}
/*
equation index: 561
type: SIMPLE_ASSIGN
$DER.body_Model.dx = body_Model.ddx
*/
void KIMM_CAR_eqFunction_561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,561};
  (data->localData[0]->realVars[43]/* der(body_Model.dx) STATE_DER */)  = (data->localData[0]->realVars[224]/* body_Model.ddx variable */) ;
  TRACE_POP
}
/*
equation index: 562
type: SIMPLE_ASSIGN
body_Model.T_force_vector_FL[2,1] = body_Model.T_coord_FL[2,1] * tire_front_left.longitudinal_force + body_Model.T_coord_FL[2,2] * tire_front_left.net_lateral_force - body_Model.T_coord_FL[2,3] * suspension_front_left.suspension_force
*/
void KIMM_CAR_eqFunction_562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  (data->localData[0]->realVars[201]/* body_Model.T_force_vector_FL[2,1] variable */)  = ((data->localData[0]->realVars[167]/* body_Model.T_coord_FL[2,1] variable */) ) * ((data->localData[0]->realVars[296]/* tire_front_left.longitudinal_force variable */) ) + ((data->localData[0]->realVars[168]/* body_Model.T_coord_FL[2,2] variable */) ) * ((data->localData[0]->realVars[300]/* tire_front_left.net_lateral_force variable */) ) - (((data->localData[0]->realVars[169]/* body_Model.T_coord_FL[2,3] variable */) ) * ((data->localData[0]->realVars[262]/* suspension_front_left.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 563
type: SIMPLE_ASSIGN
body_Model.net_force[2,1] = body_Model.T_force_vector_FL[2,1] + body_Model.T_force_vector_FR[2,1] + body_Model.T_force_vector_RR[2,1] + body_Model.T_force_vector_RL[2,1] - body_Model.Drag_force_vector[2,1]
*/
void KIMM_CAR_eqFunction_563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
  (data->localData[0]->realVars[242]/* body_Model.net_force[2,1] variable */)  = (data->localData[0]->realVars[201]/* body_Model.T_force_vector_FL[2,1] variable */)  + (data->localData[0]->realVars[204]/* body_Model.T_force_vector_FR[2,1] variable */)  + (data->localData[0]->realVars[210]/* body_Model.T_force_vector_RR[2,1] variable */)  + (data->localData[0]->realVars[207]/* body_Model.T_force_vector_RL[2,1] variable */)  - (data->localData[0]->realVars[162]/* body_Model.Drag_force_vector[2,1] variable */) ;
  TRACE_POP
}
/*
equation index: 564
type: SIMPLE_ASSIGN
body_Model.ddy = body_Model.net_force[2,1] / body_Model.mass_total
*/
void KIMM_CAR_eqFunction_564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  (data->localData[0]->realVars[225]/* body_Model.ddy variable */)  = DIVISION_SIM((data->localData[0]->realVars[242]/* body_Model.net_force[2,1] variable */) ,(data->localData[0]->realVars[240]/* body_Model.mass_total variable */) ,"body_Model.mass_total",equationIndexes);
  TRACE_POP
}
/*
equation index: 565
type: SIMPLE_ASSIGN
$DER.body_Model.dy = body_Model.ddy
*/
void KIMM_CAR_eqFunction_565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
  (data->localData[0]->realVars[44]/* der(body_Model.dy) STATE_DER */)  = (data->localData[0]->realVars[225]/* body_Model.ddy variable */) ;
  TRACE_POP
}
/*
equation index: 566
type: SIMPLE_ASSIGN
body_Model.T_force_vector_FL[3,1] = body_Model.T_coord_FL[3,1] * tire_front_left.longitudinal_force + body_Model.T_coord_FL[3,2] * tire_front_left.net_lateral_force - body_Model.T_coord_FL[3,3] * suspension_front_left.suspension_force
*/
void KIMM_CAR_eqFunction_566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
  (data->localData[0]->realVars[202]/* body_Model.T_force_vector_FL[3,1] variable */)  = ((data->localData[0]->realVars[170]/* body_Model.T_coord_FL[3,1] variable */) ) * ((data->localData[0]->realVars[296]/* tire_front_left.longitudinal_force variable */) ) + ((data->localData[0]->realVars[171]/* body_Model.T_coord_FL[3,2] variable */) ) * ((data->localData[0]->realVars[300]/* tire_front_left.net_lateral_force variable */) ) - (((data->localData[0]->realVars[172]/* body_Model.T_coord_FL[3,3] variable */) ) * ((data->localData[0]->realVars[262]/* suspension_front_left.suspension_force variable */) ));
  TRACE_POP
}
/*
equation index: 567
type: SIMPLE_ASSIGN
body_Model.net_force[3,1] = body_Model.T_force_vector_FL[3,1] + body_Model.T_force_vector_FR[3,1] + body_Model.T_force_vector_RR[3,1] + body_Model.T_force_vector_RL[3,1] - body_Model.Drag_force_vector[3,1]
*/
void KIMM_CAR_eqFunction_567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,567};
  (data->localData[0]->realVars[243]/* body_Model.net_force[3,1] variable */)  = (data->localData[0]->realVars[202]/* body_Model.T_force_vector_FL[3,1] variable */)  + (data->localData[0]->realVars[205]/* body_Model.T_force_vector_FR[3,1] variable */)  + (data->localData[0]->realVars[211]/* body_Model.T_force_vector_RR[3,1] variable */)  + (data->localData[0]->realVars[208]/* body_Model.T_force_vector_RL[3,1] variable */)  - (data->localData[0]->realVars[163]/* body_Model.Drag_force_vector[3,1] variable */) ;
  TRACE_POP
}
/*
equation index: 568
type: SIMPLE_ASSIGN
body_Model.ddz = body_Model.net_force[3,1] / body_Model.mass_total + -9.81
*/
void KIMM_CAR_eqFunction_568(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,568};
  (data->localData[0]->realVars[226]/* body_Model.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[243]/* body_Model.net_force[3,1] variable */) ,(data->localData[0]->realVars[240]/* body_Model.mass_total variable */) ,"body_Model.mass_total",equationIndexes) + -9.81;
  TRACE_POP
}
/*
equation index: 569
type: SIMPLE_ASSIGN
body_Model.body_fixed_ddx = $cse4 * (body_Model.dx * (-$cse9) * body_Model.d_yaw + body_Model.ddx * $cse10 + body_Model.dy * $cse10 * body_Model.d_yaw + body_Model.ddy * $cse9) + (-body_Model.dz) * $cse4 * body_Model.d_pitch - body_Model.ddz * $cse2 - $cse2 * body_Model.d_pitch * (body_Model.dx * $cse10 + body_Model.dy * $cse9)
*/
void KIMM_CAR_eqFunction_569(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,569};
  (data->localData[0]->realVars[212]/* body_Model.body_fixed_ddx variable */)  = ((data->localData[0]->realVars[111]/* $cse4 variable */) ) * (((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (((-(data->localData[0]->realVars[116]/* $cse9 variable */) )) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[224]/* body_Model.ddx variable */) ) * ((data->localData[0]->realVars[88]/* $cse10 variable */) ) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[225]/* body_Model.ddy variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) )) + ((-(data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) )) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) - (((data->localData[0]->realVars[226]/* body_Model.ddz variable */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) )) - (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * (((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * ((data->localData[0]->realVars[88]/* $cse10 variable */) ) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))));
  TRACE_POP
}
/*
equation index: 570
type: SIMPLE_ASSIGN
$DER.body_Model.body_fixed_dx = body_Model.body_fixed_ddx
*/
void KIMM_CAR_eqFunction_570(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,570};
  (data->localData[0]->realVars[76]/* der(body_Model.body_fixed_dx) DUMMY_DER */)  = (data->localData[0]->realVars[212]/* body_Model.body_fixed_ddx variable */) ;
  TRACE_POP
}
/*
equation index: 571
type: SIMPLE_ASSIGN
$DER.body_Model.dz = body_Model.ddz
*/
void KIMM_CAR_eqFunction_571(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,571};
  (data->localData[0]->realVars[45]/* der(body_Model.dz) STATE_DER */)  = (data->localData[0]->realVars[226]/* body_Model.ddz variable */) ;
  TRACE_POP
}
/*
equation index: 572
type: ARRAY_CALL_ASSIGN

body_Model.B_force_vector_FL = change_of_coordinate(body_Model.B_coord, body_Model.T_force_vector_FL)
*/
void KIMM_CAR_eqFunction_572(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,572};
  real_array tmp217;
  real_array tmp218;
  real_array tmp219;
  real_array_create(&tmp217, ((modelica_real*)&((&data->localData[0]->realVars[140]/* body_Model.B_coord[1,1] variable */)[(((modelica_integer) 1) - 1) * 3 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)3);
  real_array_create(&tmp218, ((modelica_real*)&((&data->localData[0]->realVars[200]/* body_Model.T_force_vector_FL[1,1] variable */)[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)] )), 2, (_index_t)3, (_index_t)1);
  real_array_create(&tmp219, ((modelica_real*)&((&(data->localData[0]->realVars[149]/* body_Model.B_force_vector_FL[1,1] variable */) )[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)])), 2, (_index_t)3, (_index_t)1);
  real_array_copy_data(omc_change__of__coordinate(threadData, tmp217, tmp218), tmp219);
  TRACE_POP
}
/*
equation index: 573
type: SIMPLE_ASSIGN
body_Model.dd_yaw = (body_Model.distance_right * body_Model.B_force_vector_FR[1,1] + body_Model.distance_right * body_Model.B_force_vector_RR[1,1] + body_Model.distance_front * body_Model.B_force_vector_FL[2,1] + body_Model.distance_front * body_Model.B_force_vector_FR[2,1] - body_Model.distance_rear * (body_Model.B_force_vector_RR[2,1] + body_Model.B_force_vector_RL[2,1]) - body_Model.distance_left * body_Model.B_force_vector_RL[1,1] - body_Model.distance_left * body_Model.B_force_vector_FL[1,1]) / body_Model.I_z
*/
void KIMM_CAR_eqFunction_573(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,573};
  (data->localData[0]->realVars[223]/* body_Model.dd_yaw variable */)  = DIVISION_SIM(((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * ((data->localData[0]->realVars[152]/* body_Model.B_force_vector_FR[1,1] variable */) ) + ((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * ((data->localData[0]->realVars[158]/* body_Model.B_force_vector_RR[1,1] variable */) ) + ((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((data->localData[0]->realVars[150]/* body_Model.B_force_vector_FL[2,1] variable */) ) + ((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((data->localData[0]->realVars[153]/* body_Model.B_force_vector_FR[2,1] variable */) ) - (((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((data->localData[0]->realVars[159]/* body_Model.B_force_vector_RR[2,1] variable */)  + (data->localData[0]->realVars[156]/* body_Model.B_force_vector_RL[2,1] variable */) )) - (((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((data->localData[0]->realVars[155]/* body_Model.B_force_vector_RL[1,1] variable */) )) - (((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((data->localData[0]->realVars[149]/* body_Model.B_force_vector_FL[1,1] variable */) )),(data->simulationInfo->realParameter[8]/* body_Model.I_z PARAM */) ,"body_Model.I_z",equationIndexes);
  TRACE_POP
}
/*
equation index: 574
type: SIMPLE_ASSIGN
$DER.body_Model.d_yaw = body_Model.dd_yaw
*/
void KIMM_CAR_eqFunction_574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,574};
  (data->localData[0]->realVars[42]/* der(body_Model.d_yaw) STATE_DER */)  = (data->localData[0]->realVars[223]/* body_Model.dd_yaw variable */) ;
  TRACE_POP
}
/*
equation index: 575
type: SIMPLE_ASSIGN
$DER.body_Model.d_roll = (body_Model.distance_left * body_Model.B_force_vector_FL[3,1] + body_Model.distance_left * body_Model.B_force_vector_RL[3,1] + body_Model.distance_chassis * (body_Model.B_force_vector_FL[2,1] + body_Model.B_force_vector_FR[2,1] + body_Model.B_force_vector_RR[2,1] + body_Model.B_force_vector_RL[2,1]) - body_Model.distance_right * body_Model.B_force_vector_RR[3,1] - body_Model.distance_right * body_Model.B_force_vector_FR[3,1]) / body_Model.I_x
*/
void KIMM_CAR_eqFunction_575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,575};
  (data->localData[0]->realVars[41]/* der(body_Model.d_roll) STATE_DER */)  = DIVISION_SIM(((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((data->localData[0]->realVars[151]/* body_Model.B_force_vector_FL[3,1] variable */) ) + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((data->localData[0]->realVars[157]/* body_Model.B_force_vector_RL[3,1] variable */) ) + ((data->simulationInfo->realParameter[10]/* body_Model.distance_chassis PARAM */) ) * ((data->localData[0]->realVars[150]/* body_Model.B_force_vector_FL[2,1] variable */)  + (data->localData[0]->realVars[153]/* body_Model.B_force_vector_FR[2,1] variable */)  + (data->localData[0]->realVars[159]/* body_Model.B_force_vector_RR[2,1] variable */)  + (data->localData[0]->realVars[156]/* body_Model.B_force_vector_RL[2,1] variable */) ) - (((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * ((data->localData[0]->realVars[160]/* body_Model.B_force_vector_RR[3,1] variable */) )) - (((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * ((data->localData[0]->realVars[154]/* body_Model.B_force_vector_FR[3,1] variable */) )),(data->simulationInfo->realParameter[6]/* body_Model.I_x PARAM */) ,"body_Model.I_x",equationIndexes);
  TRACE_POP
}
/*
equation index: 576
type: SIMPLE_ASSIGN
$DER.body_Model.d_pitch = (body_Model.distance_rear * body_Model.B_force_vector_RR[3,1] + body_Model.distance_rear * body_Model.B_force_vector_RL[3,1] - body_Model.distance_chassis * (body_Model.B_force_vector_RR[1,1] + body_Model.B_force_vector_RL[1,1] + body_Model.B_force_vector_FR[1,1] + body_Model.B_force_vector_FL[1,1]) - body_Model.distance_front * (body_Model.B_force_vector_FL[3,1] + body_Model.B_force_vector_FR[3,1])) / body_Model.I_y
*/
void KIMM_CAR_eqFunction_576(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,576};
  (data->localData[0]->realVars[40]/* der(body_Model.d_pitch) STATE_DER */)  = DIVISION_SIM(((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((data->localData[0]->realVars[160]/* body_Model.B_force_vector_RR[3,1] variable */) ) + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((data->localData[0]->realVars[157]/* body_Model.B_force_vector_RL[3,1] variable */) ) - (((data->simulationInfo->realParameter[10]/* body_Model.distance_chassis PARAM */) ) * ((data->localData[0]->realVars[158]/* body_Model.B_force_vector_RR[1,1] variable */)  + (data->localData[0]->realVars[155]/* body_Model.B_force_vector_RL[1,1] variable */)  + (data->localData[0]->realVars[152]/* body_Model.B_force_vector_FR[1,1] variable */)  + (data->localData[0]->realVars[149]/* body_Model.B_force_vector_FL[1,1] variable */) )) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((data->localData[0]->realVars[151]/* body_Model.B_force_vector_FL[3,1] variable */)  + (data->localData[0]->realVars[154]/* body_Model.B_force_vector_FR[3,1] variable */) )),(data->simulationInfo->realParameter[7]/* body_Model.I_y PARAM */) ,"body_Model.I_y",equationIndexes);
  TRACE_POP
}
/*
equation index: 577
type: SIMPLE_ASSIGN
tire_front_left.ddz = (tire_front_left.tire_normal_force + suspension_front_left.suspension_force + 9.81 * (-tire_front_left.mass) * $cse4 * $cse3) / tire_front_left.mass
*/
void KIMM_CAR_eqFunction_577(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,577};
  (data->localData[0]->realVars[292]/* tire_front_left.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */)  + (data->localData[0]->realVars[262]/* suspension_front_left.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[184]/* tire_front_left.mass PARAM */) )) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[109]/* $cse3 variable */) ))),(data->simulationInfo->realParameter[184]/* tire_front_left.mass PARAM */) ,"tire_front_left.mass",equationIndexes);
  TRACE_POP
}
/*
equation index: 578
type: SIMPLE_ASSIGN
$DER.tire_front_left.dz = tire_front_left.ddz
*/
void KIMM_CAR_eqFunction_578(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,578};
  (data->localData[0]->realVars[59]/* der(tire_front_left.dz) STATE_DER */)  = (data->localData[0]->realVars[292]/* tire_front_left.ddz variable */) ;
  TRACE_POP
}
/*
equation index: 579
type: SIMPLE_ASSIGN
$DER.suspension_front_left.body_z_pos = body_Model.front_left_body_z_vel
*/
void KIMM_CAR_eqFunction_579(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,579};
  (data->localData[0]->realVars[81]/* der(suspension_front_left.body_z_pos) DUMMY_DER */)  = (data->localData[0]->realVars[227]/* body_Model.front_left_body_z_vel variable */) ;
  TRACE_POP
}
/*
equation index: 580
type: SIMPLE_ASSIGN
body_Model.body_fixed_ddy = body_Model.dx * ($cse10 * ($cse2 * $cse3 * body_Model.d_roll + $cse4 * body_Model.d_pitch * $cse1) + $cse1 * body_Model.d_roll * $cse9 - $cse3 * $cse10 * body_Model.d_yaw - $cse9 * body_Model.d_yaw * $cse2 * $cse1) + body_Model.ddx * ($cse10 * $cse2 * $cse1 - $cse3 * $cse9) + body_Model.dy * ($cse3 * (-$cse9) * body_Model.d_yaw + $cse2 * ($cse1 * $cse10 * body_Model.d_yaw + $cse3 * body_Model.d_roll * $cse9) + $cse4 * body_Model.d_pitch * $cse1 * $cse9 - $cse1 * body_Model.d_roll * $cse10) + body_Model.ddy * ($cse3 * $cse10 + $cse2 * $cse1 * $cse9) + body_Model.dz * ($cse4 * $cse3 * body_Model.d_roll - $cse2 * body_Model.d_pitch * $cse1) + body_Model.ddz * $cse4 * $cse1
*/
void KIMM_CAR_eqFunction_580(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,580};
  (data->localData[0]->realVars[213]/* body_Model.body_fixed_ddy variable */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) )) + ((data->localData[0]->realVars[111]/* $cse4 variable */) ) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) ))) + ((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) )) - (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ))) - (((data->localData[0]->realVars[116]/* $cse9 variable */) ) * (((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) ))))) + ((data->localData[0]->realVars[224]/* body_Model.ddx variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) )) - (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((-(data->localData[0]->realVars[116]/* $cse9 variable */) )) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))) + ((data->localData[0]->realVars[111]/* $cse4 variable */) ) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))) - (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[88]/* $cse10 variable */) )))) + ((data->localData[0]->realVars[225]/* body_Model.ddy variable */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * ((data->localData[0]->realVars[88]/* $cse10 variable */) ) + ((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) )) - (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) )))) + ((data->localData[0]->realVars[226]/* body_Model.ddz variable */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) ));
  TRACE_POP
}
/*
equation index: 581
type: SIMPLE_ASSIGN
$DER.body_Model.body_fixed_dy = body_Model.body_fixed_ddy
*/
void KIMM_CAR_eqFunction_581(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,581};
  (data->localData[0]->realVars[77]/* der(body_Model.body_fixed_dy) DUMMY_DER */)  = (data->localData[0]->realVars[213]/* body_Model.body_fixed_ddy variable */) ;
  TRACE_POP
}
/*
equation index: 582
type: SIMPLE_ASSIGN
body_Model.body_fixed_ddz = body_Model.dx * ($cse1 * $cse10 * body_Model.d_yaw + $cse3 * body_Model.d_roll * $cse9 + $cse3 * ($cse10 * $cse4 * body_Model.d_pitch - $cse9 * body_Model.d_yaw * $cse2) - $cse1 * body_Model.d_roll * $cse10 * $cse2) + body_Model.ddx * ($cse1 * $cse9 + $cse3 * $cse10 * $cse2) + body_Model.dy * ($cse3 * ($cse2 * $cse10 * body_Model.d_yaw + $cse4 * body_Model.d_pitch * $cse9) + $cse9 * body_Model.d_yaw * $cse1 - $cse10 * $cse3 * body_Model.d_roll - $cse1 * body_Model.d_roll * $cse2 * $cse9) + body_Model.ddy * ($cse3 * $cse2 * $cse9 - $cse10 * $cse1) + body_Model.dz * ($cse4 * (-$cse1) * body_Model.d_roll - $cse2 * body_Model.d_pitch * $cse3) + body_Model.ddz * $cse4 * $cse3
*/
void KIMM_CAR_eqFunction_582(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,582};
  (data->localData[0]->realVars[214]/* body_Model.body_fixed_ddz variable */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) )) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) - (((data->localData[0]->realVars[116]/* $cse9 variable */) ) * (((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) )))) - (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) ))))) + ((data->localData[0]->realVars[224]/* body_Model.ddx variable */) ) * (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ) + ((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[98]/* $cse2 variable */) ))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[111]/* $cse4 variable */) ) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))) + ((data->localData[0]->realVars[116]/* $cse9 variable */) ) * (((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) )) - (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ))) - (((data->localData[0]->realVars[87]/* $cse1 variable */) ) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) ))))) + ((data->localData[0]->realVars[225]/* body_Model.ddy variable */) ) * (((data->localData[0]->realVars[109]/* $cse3 variable */) ) * (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * ((data->localData[0]->realVars[116]/* $cse9 variable */) )) - (((data->localData[0]->realVars[88]/* $cse10 variable */) ) * ((data->localData[0]->realVars[87]/* $cse1 variable */) ))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * (((-(data->localData[0]->realVars[87]/* $cse1 variable */) )) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) )) - (((data->localData[0]->realVars[98]/* $cse2 variable */) ) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * ((data->localData[0]->realVars[109]/* $cse3 variable */) )))) + ((data->localData[0]->realVars[226]/* body_Model.ddz variable */) ) * (((data->localData[0]->realVars[111]/* $cse4 variable */) ) * ((data->localData[0]->realVars[109]/* $cse3 variable */) ));
  TRACE_POP
}
/*
equation index: 583
type: SIMPLE_ASSIGN
$DER.body_Model.body_fixed_dz = body_Model.body_fixed_ddz
*/
void KIMM_CAR_eqFunction_583(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,583};
  (data->localData[0]->realVars[78]/* der(body_Model.body_fixed_dz) DUMMY_DER */)  = (data->localData[0]->realVars[214]/* body_Model.body_fixed_ddz variable */) ;
  TRACE_POP
}
/*
equation index: 601
type: WHEN

when {$whenCondition1} then
  reinit(body_Model.dd_yaw,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_601(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,601};
  if(((data->localData[0]->booleanVars[0]/* $whenCondition1 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[0]/* $whenCondition1 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[223]/* body_Model.dd_yaw variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.dd_yaw = %g", (data->localData[0]->realVars[223]/* body_Model.dd_yaw variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 600
type: WHEN

when {$whenCondition1} then
  reinit(body_Model.ddy,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_600(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,600};
  if(((data->localData[0]->booleanVars[0]/* $whenCondition1 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[0]/* $whenCondition1 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[225]/* body_Model.ddy variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.ddy = %g", (data->localData[0]->realVars[225]/* body_Model.ddy variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 599
type: WHEN

when {$whenCondition1} then
  reinit(body_Model.ddx,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_599(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
  if(((data->localData[0]->booleanVars[0]/* $whenCondition1 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[0]/* $whenCondition1 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[224]/* body_Model.ddx variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.ddx = %g", (data->localData[0]->realVars[224]/* body_Model.ddx variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 598
type: WHEN

when {$whenCondition1} then
  reinit(body_Model.d_yaw,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_598(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
  if(((data->localData[0]->booleanVars[0]/* $whenCondition1 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[0]/* $whenCondition1 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.d_yaw = %g", (data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 597
type: WHEN

when {$whenCondition1} then
  reinit(body_Model.dy,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_597(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,597};
  if(((data->localData[0]->booleanVars[0]/* $whenCondition1 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[0]/* $whenCondition1 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.dy = %g", (data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 596
type: WHEN

when {$whenCondition1} then
  reinit(body_Model.dx,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_596(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,596};
  if(((data->localData[0]->booleanVars[0]/* $whenCondition1 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[0]/* $whenCondition1 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.dx = %g", (data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 595
type: WHEN

when {$whenCondition2} then
  reinit(body_Model.front_left_vx,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_595(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,595};
  if(((data->localData[0]->booleanVars[1]/* $whenCondition2 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[1]/* $whenCondition2 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.front_left_vx = %g", (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 594
type: WHEN

when {$whenCondition2} then
  reinit(tire_front_left.dd_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_594(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,594};
  if(((data->localData[0]->booleanVars[1]/* $whenCondition2 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[1]/* $whenCondition2 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[291]/* tire_front_left.dd_roll variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_front_left.dd_roll = %g", (data->localData[0]->realVars[291]/* tire_front_left.dd_roll variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 593
type: WHEN

when {$whenCondition2} then
  reinit(tire_front_left.d_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_593(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,593};
  if(((data->localData[0]->booleanVars[1]/* $whenCondition2 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[1]/* $whenCondition2 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_front_left.d_roll = %g", (data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 592
type: WHEN

when {$whenCondition3} then
  reinit(body_Model.front_right_vx,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_592(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,592};
  if(((data->localData[0]->booleanVars[2]/* $whenCondition3 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[2]/* $whenCondition3 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.front_right_vx = %g", (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 591
type: WHEN

when {$whenCondition3} then
  reinit(tire_front_right.dd_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_591(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,591};
  if(((data->localData[0]->booleanVars[2]/* $whenCondition3 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[2]/* $whenCondition3 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[325]/* tire_front_right.dd_roll variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_front_right.dd_roll = %g", (data->localData[0]->realVars[325]/* tire_front_right.dd_roll variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 590
type: WHEN

when {$whenCondition3} then
  reinit(tire_front_right.d_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_590(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,590};
  if(((data->localData[0]->booleanVars[2]/* $whenCondition3 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[2]/* $whenCondition3 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_front_right.d_roll = %g", (data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 589
type: WHEN

when {$whenCondition4} then
  reinit(body_Model.rear_right_dx,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,589};
  if(((data->localData[0]->booleanVars[3]/* $whenCondition4 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[3]/* $whenCondition4 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.rear_right_dx = %g", (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 588
type: WHEN

when {$whenCondition4} then
  reinit(tire_rear_right.dd_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,588};
  if(((data->localData[0]->booleanVars[3]/* $whenCondition4 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[3]/* $whenCondition4 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[393]/* tire_rear_right.dd_roll variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_rear_right.dd_roll = %g", (data->localData[0]->realVars[393]/* tire_rear_right.dd_roll variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 587
type: WHEN

when {$whenCondition4} then
  reinit(tire_rear_right.d_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_587(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,587};
  if(((data->localData[0]->booleanVars[3]/* $whenCondition4 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[3]/* $whenCondition4 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_rear_right.d_roll = %g", (data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 586
type: WHEN

when {$whenCondition5} then
  reinit(body_Model.rear_left_dx,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_586(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,586};
  if(((data->localData[0]->booleanVars[4]/* $whenCondition5 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[4]/* $whenCondition5 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit body_Model.rear_left_dx = %g", (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 585
type: WHEN

when {$whenCondition5} then
  reinit(tire_rear_left.dd_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,585};
  if(((data->localData[0]->booleanVars[4]/* $whenCondition5 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[4]/* $whenCondition5 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[359]/* tire_rear_left.dd_roll variable */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_rear_left.dd_roll = %g", (data->localData[0]->realVars[359]/* tire_rear_left.dd_roll variable */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 584
type: WHEN

when {$whenCondition5} then
  reinit(tire_rear_left.d_roll,  0.0);
end when;
*/
void KIMM_CAR_eqFunction_584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,584};
  if(((data->localData[0]->booleanVars[4]/* $whenCondition5 DISCRETE */)  && !(data->simulationInfo->booleanVarsPre[4]/* $whenCondition5 DISCRETE */)  /* edge */))
  {
    (data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */)  = 0.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit tire_rear_left.d_roll = %g", (data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) );
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int KIMM_CAR_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  KIMM_CAR_functionLocalKnownVars(data, threadData);
  KIMM_CAR_eqFunction_336(data, threadData);

  KIMM_CAR_eqFunction_337(data, threadData);

  KIMM_CAR_eqFunction_338(data, threadData);

  KIMM_CAR_eqFunction_339(data, threadData);

  KIMM_CAR_eqFunction_340(data, threadData);

  KIMM_CAR_eqFunction_341(data, threadData);

  KIMM_CAR_eqFunction_342(data, threadData);

  KIMM_CAR_eqFunction_343(data, threadData);

  KIMM_CAR_eqFunction_344(data, threadData);

  KIMM_CAR_eqFunction_345(data, threadData);

  KIMM_CAR_eqFunction_346(data, threadData);

  KIMM_CAR_eqFunction_347(data, threadData);

  KIMM_CAR_eqFunction_348(data, threadData);

  KIMM_CAR_eqFunction_349(data, threadData);

  KIMM_CAR_eqFunction_350(data, threadData);

  KIMM_CAR_eqFunction_351(data, threadData);

  KIMM_CAR_eqFunction_352(data, threadData);

  KIMM_CAR_eqFunction_353(data, threadData);

  KIMM_CAR_eqFunction_354(data, threadData);

  KIMM_CAR_eqFunction_355(data, threadData);

  KIMM_CAR_eqFunction_356(data, threadData);

  KIMM_CAR_eqFunction_357(data, threadData);

  KIMM_CAR_eqFunction_358(data, threadData);

  KIMM_CAR_eqFunction_359(data, threadData);

  KIMM_CAR_eqFunction_360(data, threadData);

  KIMM_CAR_eqFunction_361(data, threadData);

  KIMM_CAR_eqFunction_362(data, threadData);

  KIMM_CAR_eqFunction_363(data, threadData);

  KIMM_CAR_eqFunction_364(data, threadData);

  KIMM_CAR_eqFunction_365(data, threadData);

  KIMM_CAR_eqFunction_366(data, threadData);

  KIMM_CAR_eqFunction_367(data, threadData);

  KIMM_CAR_eqFunction_368(data, threadData);

  KIMM_CAR_eqFunction_369(data, threadData);

  KIMM_CAR_eqFunction_370(data, threadData);

  KIMM_CAR_eqFunction_371(data, threadData);

  KIMM_CAR_eqFunction_372(data, threadData);

  KIMM_CAR_eqFunction_373(data, threadData);

  KIMM_CAR_eqFunction_374(data, threadData);

  KIMM_CAR_eqFunction_375(data, threadData);

  KIMM_CAR_eqFunction_376(data, threadData);

  KIMM_CAR_eqFunction_377(data, threadData);

  KIMM_CAR_eqFunction_378(data, threadData);

  KIMM_CAR_eqFunction_379(data, threadData);

  KIMM_CAR_eqFunction_380(data, threadData);

  KIMM_CAR_eqFunction_381(data, threadData);

  KIMM_CAR_eqFunction_382(data, threadData);

  KIMM_CAR_eqFunction_383(data, threadData);

  KIMM_CAR_eqFunction_384(data, threadData);

  KIMM_CAR_eqFunction_385(data, threadData);

  KIMM_CAR_eqFunction_386(data, threadData);

  KIMM_CAR_eqFunction_387(data, threadData);

  KIMM_CAR_eqFunction_388(data, threadData);

  KIMM_CAR_eqFunction_389(data, threadData);

  KIMM_CAR_eqFunction_390(data, threadData);

  KIMM_CAR_eqFunction_391(data, threadData);

  KIMM_CAR_eqFunction_392(data, threadData);

  KIMM_CAR_eqFunction_393(data, threadData);

  KIMM_CAR_eqFunction_394(data, threadData);

  KIMM_CAR_eqFunction_395(data, threadData);

  KIMM_CAR_eqFunction_396(data, threadData);

  KIMM_CAR_eqFunction_397(data, threadData);

  KIMM_CAR_eqFunction_398(data, threadData);

  KIMM_CAR_eqFunction_399(data, threadData);

  KIMM_CAR_eqFunction_400(data, threadData);

  KIMM_CAR_eqFunction_401(data, threadData);

  KIMM_CAR_eqFunction_402(data, threadData);

  KIMM_CAR_eqFunction_403(data, threadData);

  KIMM_CAR_eqFunction_404(data, threadData);

  KIMM_CAR_eqFunction_405(data, threadData);

  KIMM_CAR_eqFunction_406(data, threadData);

  KIMM_CAR_eqFunction_407(data, threadData);

  KIMM_CAR_eqFunction_408(data, threadData);

  KIMM_CAR_eqFunction_409(data, threadData);

  KIMM_CAR_eqFunction_410(data, threadData);

  KIMM_CAR_eqFunction_411(data, threadData);

  KIMM_CAR_eqFunction_412(data, threadData);

  KIMM_CAR_eqFunction_413(data, threadData);

  KIMM_CAR_eqFunction_414(data, threadData);

  KIMM_CAR_eqFunction_415(data, threadData);

  KIMM_CAR_eqFunction_416(data, threadData);

  KIMM_CAR_eqFunction_417(data, threadData);

  KIMM_CAR_eqFunction_418(data, threadData);

  KIMM_CAR_eqFunction_419(data, threadData);

  KIMM_CAR_eqFunction_420(data, threadData);

  KIMM_CAR_eqFunction_421(data, threadData);

  KIMM_CAR_eqFunction_422(data, threadData);

  KIMM_CAR_eqFunction_423(data, threadData);

  KIMM_CAR_eqFunction_424(data, threadData);

  KIMM_CAR_eqFunction_425(data, threadData);

  KIMM_CAR_eqFunction_426(data, threadData);

  KIMM_CAR_eqFunction_427(data, threadData);

  KIMM_CAR_eqFunction_428(data, threadData);

  KIMM_CAR_eqFunction_429(data, threadData);

  KIMM_CAR_eqFunction_430(data, threadData);

  KIMM_CAR_eqFunction_431(data, threadData);

  KIMM_CAR_eqFunction_432(data, threadData);

  KIMM_CAR_eqFunction_433(data, threadData);

  KIMM_CAR_eqFunction_434(data, threadData);

  KIMM_CAR_eqFunction_435(data, threadData);

  KIMM_CAR_eqFunction_436(data, threadData);

  KIMM_CAR_eqFunction_437(data, threadData);

  KIMM_CAR_eqFunction_438(data, threadData);

  KIMM_CAR_eqFunction_439(data, threadData);

  KIMM_CAR_eqFunction_440(data, threadData);

  KIMM_CAR_eqFunction_441(data, threadData);

  KIMM_CAR_eqFunction_442(data, threadData);

  KIMM_CAR_eqFunction_443(data, threadData);

  KIMM_CAR_eqFunction_444(data, threadData);

  KIMM_CAR_eqFunction_445(data, threadData);

  KIMM_CAR_eqFunction_446(data, threadData);

  KIMM_CAR_eqFunction_447(data, threadData);

  KIMM_CAR_eqFunction_448(data, threadData);

  KIMM_CAR_eqFunction_449(data, threadData);

  KIMM_CAR_eqFunction_450(data, threadData);

  KIMM_CAR_eqFunction_451(data, threadData);

  KIMM_CAR_eqFunction_452(data, threadData);

  KIMM_CAR_eqFunction_453(data, threadData);

  KIMM_CAR_eqFunction_454(data, threadData);

  KIMM_CAR_eqFunction_455(data, threadData);

  KIMM_CAR_eqFunction_456(data, threadData);

  KIMM_CAR_eqFunction_457(data, threadData);

  KIMM_CAR_eqFunction_458(data, threadData);

  KIMM_CAR_eqFunction_459(data, threadData);

  KIMM_CAR_eqFunction_460(data, threadData);

  KIMM_CAR_eqFunction_461(data, threadData);

  KIMM_CAR_eqFunction_462(data, threadData);

  KIMM_CAR_eqFunction_463(data, threadData);

  KIMM_CAR_eqFunction_464(data, threadData);

  KIMM_CAR_eqFunction_465(data, threadData);

  KIMM_CAR_eqFunction_466(data, threadData);

  KIMM_CAR_eqFunction_467(data, threadData);

  KIMM_CAR_eqFunction_468(data, threadData);

  KIMM_CAR_eqFunction_469(data, threadData);

  KIMM_CAR_eqFunction_470(data, threadData);

  KIMM_CAR_eqFunction_471(data, threadData);

  KIMM_CAR_eqFunction_472(data, threadData);

  KIMM_CAR_eqFunction_473(data, threadData);

  KIMM_CAR_eqFunction_474(data, threadData);

  KIMM_CAR_eqFunction_475(data, threadData);

  KIMM_CAR_eqFunction_476(data, threadData);

  KIMM_CAR_eqFunction_477(data, threadData);

  KIMM_CAR_eqFunction_478(data, threadData);

  KIMM_CAR_eqFunction_479(data, threadData);

  KIMM_CAR_eqFunction_480(data, threadData);

  KIMM_CAR_eqFunction_481(data, threadData);

  KIMM_CAR_eqFunction_482(data, threadData);

  KIMM_CAR_eqFunction_483(data, threadData);

  KIMM_CAR_eqFunction_484(data, threadData);

  KIMM_CAR_eqFunction_485(data, threadData);

  KIMM_CAR_eqFunction_486(data, threadData);

  KIMM_CAR_eqFunction_487(data, threadData);

  KIMM_CAR_eqFunction_488(data, threadData);

  KIMM_CAR_eqFunction_489(data, threadData);

  KIMM_CAR_eqFunction_490(data, threadData);

  KIMM_CAR_eqFunction_491(data, threadData);

  KIMM_CAR_eqFunction_492(data, threadData);

  KIMM_CAR_eqFunction_493(data, threadData);

  KIMM_CAR_eqFunction_494(data, threadData);

  KIMM_CAR_eqFunction_495(data, threadData);

  KIMM_CAR_eqFunction_496(data, threadData);

  KIMM_CAR_eqFunction_497(data, threadData);

  KIMM_CAR_eqFunction_498(data, threadData);

  KIMM_CAR_eqFunction_499(data, threadData);

  KIMM_CAR_eqFunction_500(data, threadData);

  KIMM_CAR_eqFunction_501(data, threadData);

  KIMM_CAR_eqFunction_502(data, threadData);

  KIMM_CAR_eqFunction_503(data, threadData);

  KIMM_CAR_eqFunction_504(data, threadData);

  KIMM_CAR_eqFunction_505(data, threadData);

  KIMM_CAR_eqFunction_506(data, threadData);

  KIMM_CAR_eqFunction_507(data, threadData);

  KIMM_CAR_eqFunction_508(data, threadData);

  KIMM_CAR_eqFunction_509(data, threadData);

  KIMM_CAR_eqFunction_510(data, threadData);

  KIMM_CAR_eqFunction_511(data, threadData);

  KIMM_CAR_eqFunction_512(data, threadData);

  KIMM_CAR_eqFunction_513(data, threadData);

  KIMM_CAR_eqFunction_514(data, threadData);

  KIMM_CAR_eqFunction_515(data, threadData);

  KIMM_CAR_eqFunction_516(data, threadData);

  KIMM_CAR_eqFunction_517(data, threadData);

  KIMM_CAR_eqFunction_518(data, threadData);

  KIMM_CAR_eqFunction_519(data, threadData);

  KIMM_CAR_eqFunction_520(data, threadData);

  KIMM_CAR_eqFunction_521(data, threadData);

  KIMM_CAR_eqFunction_522(data, threadData);

  KIMM_CAR_eqFunction_523(data, threadData);

  KIMM_CAR_eqFunction_524(data, threadData);

  KIMM_CAR_eqFunction_525(data, threadData);

  KIMM_CAR_eqFunction_526(data, threadData);

  KIMM_CAR_eqFunction_527(data, threadData);

  KIMM_CAR_eqFunction_528(data, threadData);

  KIMM_CAR_eqFunction_529(data, threadData);

  KIMM_CAR_eqFunction_530(data, threadData);

  KIMM_CAR_eqFunction_531(data, threadData);

  KIMM_CAR_eqFunction_532(data, threadData);

  KIMM_CAR_eqFunction_533(data, threadData);

  KIMM_CAR_eqFunction_534(data, threadData);

  KIMM_CAR_eqFunction_535(data, threadData);

  KIMM_CAR_eqFunction_536(data, threadData);

  KIMM_CAR_eqFunction_537(data, threadData);

  KIMM_CAR_eqFunction_538(data, threadData);

  KIMM_CAR_eqFunction_539(data, threadData);

  KIMM_CAR_eqFunction_540(data, threadData);

  KIMM_CAR_eqFunction_541(data, threadData);

  KIMM_CAR_eqFunction_542(data, threadData);

  KIMM_CAR_eqFunction_543(data, threadData);

  KIMM_CAR_eqFunction_544(data, threadData);

  KIMM_CAR_eqFunction_545(data, threadData);

  KIMM_CAR_eqFunction_546(data, threadData);

  KIMM_CAR_eqFunction_547(data, threadData);

  KIMM_CAR_eqFunction_548(data, threadData);

  KIMM_CAR_eqFunction_549(data, threadData);

  KIMM_CAR_eqFunction_550(data, threadData);

  KIMM_CAR_eqFunction_551(data, threadData);

  KIMM_CAR_eqFunction_552(data, threadData);

  KIMM_CAR_eqFunction_553(data, threadData);

  KIMM_CAR_eqFunction_554(data, threadData);

  KIMM_CAR_eqFunction_555(data, threadData);

  KIMM_CAR_eqFunction_556(data, threadData);

  KIMM_CAR_eqFunction_557(data, threadData);

  KIMM_CAR_eqFunction_558(data, threadData);

  KIMM_CAR_eqFunction_559(data, threadData);

  KIMM_CAR_eqFunction_560(data, threadData);

  KIMM_CAR_eqFunction_561(data, threadData);

  KIMM_CAR_eqFunction_562(data, threadData);

  KIMM_CAR_eqFunction_563(data, threadData);

  KIMM_CAR_eqFunction_564(data, threadData);

  KIMM_CAR_eqFunction_565(data, threadData);

  KIMM_CAR_eqFunction_566(data, threadData);

  KIMM_CAR_eqFunction_567(data, threadData);

  KIMM_CAR_eqFunction_568(data, threadData);

  KIMM_CAR_eqFunction_569(data, threadData);

  KIMM_CAR_eqFunction_570(data, threadData);

  KIMM_CAR_eqFunction_571(data, threadData);

  KIMM_CAR_eqFunction_572(data, threadData);

  KIMM_CAR_eqFunction_573(data, threadData);

  KIMM_CAR_eqFunction_574(data, threadData);

  KIMM_CAR_eqFunction_575(data, threadData);

  KIMM_CAR_eqFunction_576(data, threadData);

  KIMM_CAR_eqFunction_577(data, threadData);

  KIMM_CAR_eqFunction_578(data, threadData);

  KIMM_CAR_eqFunction_579(data, threadData);

  KIMM_CAR_eqFunction_580(data, threadData);

  KIMM_CAR_eqFunction_581(data, threadData);

  KIMM_CAR_eqFunction_582(data, threadData);

  KIMM_CAR_eqFunction_583(data, threadData);

  KIMM_CAR_eqFunction_601(data, threadData);

  KIMM_CAR_eqFunction_600(data, threadData);

  KIMM_CAR_eqFunction_599(data, threadData);

  KIMM_CAR_eqFunction_598(data, threadData);

  KIMM_CAR_eqFunction_597(data, threadData);

  KIMM_CAR_eqFunction_596(data, threadData);

  KIMM_CAR_eqFunction_595(data, threadData);

  KIMM_CAR_eqFunction_594(data, threadData);

  KIMM_CAR_eqFunction_593(data, threadData);

  KIMM_CAR_eqFunction_592(data, threadData);

  KIMM_CAR_eqFunction_591(data, threadData);

  KIMM_CAR_eqFunction_590(data, threadData);

  KIMM_CAR_eqFunction_589(data, threadData);

  KIMM_CAR_eqFunction_588(data, threadData);

  KIMM_CAR_eqFunction_587(data, threadData);

  KIMM_CAR_eqFunction_586(data, threadData);

  KIMM_CAR_eqFunction_585(data, threadData);

  KIMM_CAR_eqFunction_584(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int KIMM_CAR_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void KIMM_CAR_eqFunction_336(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_338(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_339(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_340(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_341(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_342(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_344(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_345(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_346(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_347(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_348(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_349(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_350(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_351(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_352(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_353(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_354(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_355(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_356(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_357(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_358(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_359(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_360(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_361(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_362(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_363(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_364(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_365(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_366(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_367(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_368(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_369(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_370(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_371(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_372(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_373(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_374(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_375(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_376(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_377(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_378(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_379(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_380(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_381(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_382(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_383(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_384(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_385(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_386(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_387(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_388(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_389(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_390(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_391(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_392(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_393(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_394(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_395(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_396(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_397(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_398(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_399(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_400(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_401(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_402(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_403(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_405(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_406(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_407(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_408(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_409(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_410(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_411(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_412(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_413(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_414(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_415(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_416(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_417(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_418(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_419(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_420(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_422(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_423(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_424(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_425(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_426(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_427(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_428(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_429(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_430(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_431(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_432(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_433(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_434(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_435(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_436(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_437(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_439(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_440(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_441(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_442(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_443(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_444(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_445(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_446(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_447(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_448(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_449(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_450(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_451(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_452(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_453(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_454(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_456(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_457(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_458(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_459(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_460(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_461(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_462(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_463(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_464(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_465(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_466(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_467(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_468(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_470(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_471(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_472(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_473(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_475(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_476(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_477(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_478(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_479(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_480(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_481(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_482(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_483(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_484(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_486(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_487(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_488(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_489(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_490(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_491(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_492(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_493(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_494(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_495(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_496(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_497(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_498(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_499(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_500(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_501(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_502(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_503(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_504(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_505(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_508(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_509(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_510(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_511(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_512(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_513(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_514(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_515(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_516(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_517(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_518(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_521(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_522(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_523(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_524(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_525(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_526(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_527(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_529(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_530(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_531(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_532(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_533(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_534(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_535(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_536(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_538(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_539(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_540(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_541(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_542(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_543(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_544(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_545(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_547(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_548(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_549(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_550(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_551(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_552(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_553(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_554(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_556(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_557(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_558(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_559(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_560(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_561(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_562(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_563(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_564(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_565(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_566(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_567(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_568(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_571(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_572(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_573(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_574(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_575(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_576(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_577(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_578(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  {
    KIMM_CAR_eqFunction_336(data, threadData);
    threadData->lastEquationSolved = 336;
  }
  {
    KIMM_CAR_eqFunction_338(data, threadData);
    threadData->lastEquationSolved = 338;
  }
  {
    KIMM_CAR_eqFunction_339(data, threadData);
    threadData->lastEquationSolved = 339;
  }
  {
    KIMM_CAR_eqFunction_340(data, threadData);
    threadData->lastEquationSolved = 340;
  }
  {
    KIMM_CAR_eqFunction_341(data, threadData);
    threadData->lastEquationSolved = 341;
  }
  {
    KIMM_CAR_eqFunction_342(data, threadData);
    threadData->lastEquationSolved = 342;
  }
  {
    KIMM_CAR_eqFunction_344(data, threadData);
    threadData->lastEquationSolved = 344;
  }
  {
    KIMM_CAR_eqFunction_345(data, threadData);
    threadData->lastEquationSolved = 345;
  }
  {
    KIMM_CAR_eqFunction_346(data, threadData);
    threadData->lastEquationSolved = 346;
  }
  {
    KIMM_CAR_eqFunction_347(data, threadData);
    threadData->lastEquationSolved = 347;
  }
  {
    KIMM_CAR_eqFunction_348(data, threadData);
    threadData->lastEquationSolved = 348;
  }
  {
    KIMM_CAR_eqFunction_349(data, threadData);
    threadData->lastEquationSolved = 349;
  }
  {
    KIMM_CAR_eqFunction_350(data, threadData);
    threadData->lastEquationSolved = 350;
  }
  {
    KIMM_CAR_eqFunction_351(data, threadData);
    threadData->lastEquationSolved = 351;
  }
  {
    KIMM_CAR_eqFunction_352(data, threadData);
    threadData->lastEquationSolved = 352;
  }
  {
    KIMM_CAR_eqFunction_353(data, threadData);
    threadData->lastEquationSolved = 353;
  }
  {
    KIMM_CAR_eqFunction_354(data, threadData);
    threadData->lastEquationSolved = 354;
  }
  {
    KIMM_CAR_eqFunction_355(data, threadData);
    threadData->lastEquationSolved = 355;
  }
  {
    KIMM_CAR_eqFunction_356(data, threadData);
    threadData->lastEquationSolved = 356;
  }
  {
    KIMM_CAR_eqFunction_357(data, threadData);
    threadData->lastEquationSolved = 357;
  }
  {
    KIMM_CAR_eqFunction_358(data, threadData);
    threadData->lastEquationSolved = 358;
  }
  {
    KIMM_CAR_eqFunction_359(data, threadData);
    threadData->lastEquationSolved = 359;
  }
  {
    KIMM_CAR_eqFunction_360(data, threadData);
    threadData->lastEquationSolved = 360;
  }
  {
    KIMM_CAR_eqFunction_361(data, threadData);
    threadData->lastEquationSolved = 361;
  }
  {
    KIMM_CAR_eqFunction_362(data, threadData);
    threadData->lastEquationSolved = 362;
  }
  {
    KIMM_CAR_eqFunction_363(data, threadData);
    threadData->lastEquationSolved = 363;
  }
  {
    KIMM_CAR_eqFunction_364(data, threadData);
    threadData->lastEquationSolved = 364;
  }
  {
    KIMM_CAR_eqFunction_365(data, threadData);
    threadData->lastEquationSolved = 365;
  }
  {
    KIMM_CAR_eqFunction_366(data, threadData);
    threadData->lastEquationSolved = 366;
  }
  {
    KIMM_CAR_eqFunction_367(data, threadData);
    threadData->lastEquationSolved = 367;
  }
  {
    KIMM_CAR_eqFunction_368(data, threadData);
    threadData->lastEquationSolved = 368;
  }
  {
    KIMM_CAR_eqFunction_369(data, threadData);
    threadData->lastEquationSolved = 369;
  }
  {
    KIMM_CAR_eqFunction_370(data, threadData);
    threadData->lastEquationSolved = 370;
  }
  {
    KIMM_CAR_eqFunction_371(data, threadData);
    threadData->lastEquationSolved = 371;
  }
  {
    KIMM_CAR_eqFunction_372(data, threadData);
    threadData->lastEquationSolved = 372;
  }
  {
    KIMM_CAR_eqFunction_373(data, threadData);
    threadData->lastEquationSolved = 373;
  }
  {
    KIMM_CAR_eqFunction_374(data, threadData);
    threadData->lastEquationSolved = 374;
  }
  {
    KIMM_CAR_eqFunction_375(data, threadData);
    threadData->lastEquationSolved = 375;
  }
  {
    KIMM_CAR_eqFunction_376(data, threadData);
    threadData->lastEquationSolved = 376;
  }
  {
    KIMM_CAR_eqFunction_377(data, threadData);
    threadData->lastEquationSolved = 377;
  }
  {
    KIMM_CAR_eqFunction_378(data, threadData);
    threadData->lastEquationSolved = 378;
  }
  {
    KIMM_CAR_eqFunction_379(data, threadData);
    threadData->lastEquationSolved = 379;
  }
  {
    KIMM_CAR_eqFunction_380(data, threadData);
    threadData->lastEquationSolved = 380;
  }
  {
    KIMM_CAR_eqFunction_381(data, threadData);
    threadData->lastEquationSolved = 381;
  }
  {
    KIMM_CAR_eqFunction_382(data, threadData);
    threadData->lastEquationSolved = 382;
  }
  {
    KIMM_CAR_eqFunction_383(data, threadData);
    threadData->lastEquationSolved = 383;
  }
  {
    KIMM_CAR_eqFunction_384(data, threadData);
    threadData->lastEquationSolved = 384;
  }
  {
    KIMM_CAR_eqFunction_385(data, threadData);
    threadData->lastEquationSolved = 385;
  }
  {
    KIMM_CAR_eqFunction_386(data, threadData);
    threadData->lastEquationSolved = 386;
  }
  {
    KIMM_CAR_eqFunction_387(data, threadData);
    threadData->lastEquationSolved = 387;
  }
  {
    KIMM_CAR_eqFunction_388(data, threadData);
    threadData->lastEquationSolved = 388;
  }
  {
    KIMM_CAR_eqFunction_389(data, threadData);
    threadData->lastEquationSolved = 389;
  }
  {
    KIMM_CAR_eqFunction_390(data, threadData);
    threadData->lastEquationSolved = 390;
  }
  {
    KIMM_CAR_eqFunction_391(data, threadData);
    threadData->lastEquationSolved = 391;
  }
  {
    KIMM_CAR_eqFunction_392(data, threadData);
    threadData->lastEquationSolved = 392;
  }
  {
    KIMM_CAR_eqFunction_393(data, threadData);
    threadData->lastEquationSolved = 393;
  }
  {
    KIMM_CAR_eqFunction_394(data, threadData);
    threadData->lastEquationSolved = 394;
  }
  {
    KIMM_CAR_eqFunction_395(data, threadData);
    threadData->lastEquationSolved = 395;
  }
  {
    KIMM_CAR_eqFunction_396(data, threadData);
    threadData->lastEquationSolved = 396;
  }
  {
    KIMM_CAR_eqFunction_397(data, threadData);
    threadData->lastEquationSolved = 397;
  }
  {
    KIMM_CAR_eqFunction_398(data, threadData);
    threadData->lastEquationSolved = 398;
  }
  {
    KIMM_CAR_eqFunction_399(data, threadData);
    threadData->lastEquationSolved = 399;
  }
  {
    KIMM_CAR_eqFunction_400(data, threadData);
    threadData->lastEquationSolved = 400;
  }
  {
    KIMM_CAR_eqFunction_401(data, threadData);
    threadData->lastEquationSolved = 401;
  }
  {
    KIMM_CAR_eqFunction_402(data, threadData);
    threadData->lastEquationSolved = 402;
  }
  {
    KIMM_CAR_eqFunction_403(data, threadData);
    threadData->lastEquationSolved = 403;
  }
  {
    KIMM_CAR_eqFunction_405(data, threadData);
    threadData->lastEquationSolved = 405;
  }
  {
    KIMM_CAR_eqFunction_406(data, threadData);
    threadData->lastEquationSolved = 406;
  }
  {
    KIMM_CAR_eqFunction_407(data, threadData);
    threadData->lastEquationSolved = 407;
  }
  {
    KIMM_CAR_eqFunction_408(data, threadData);
    threadData->lastEquationSolved = 408;
  }
  {
    KIMM_CAR_eqFunction_409(data, threadData);
    threadData->lastEquationSolved = 409;
  }
  {
    KIMM_CAR_eqFunction_410(data, threadData);
    threadData->lastEquationSolved = 410;
  }
  {
    KIMM_CAR_eqFunction_411(data, threadData);
    threadData->lastEquationSolved = 411;
  }
  {
    KIMM_CAR_eqFunction_412(data, threadData);
    threadData->lastEquationSolved = 412;
  }
  {
    KIMM_CAR_eqFunction_413(data, threadData);
    threadData->lastEquationSolved = 413;
  }
  {
    KIMM_CAR_eqFunction_414(data, threadData);
    threadData->lastEquationSolved = 414;
  }
  {
    KIMM_CAR_eqFunction_415(data, threadData);
    threadData->lastEquationSolved = 415;
  }
  {
    KIMM_CAR_eqFunction_416(data, threadData);
    threadData->lastEquationSolved = 416;
  }
  {
    KIMM_CAR_eqFunction_417(data, threadData);
    threadData->lastEquationSolved = 417;
  }
  {
    KIMM_CAR_eqFunction_418(data, threadData);
    threadData->lastEquationSolved = 418;
  }
  {
    KIMM_CAR_eqFunction_419(data, threadData);
    threadData->lastEquationSolved = 419;
  }
  {
    KIMM_CAR_eqFunction_420(data, threadData);
    threadData->lastEquationSolved = 420;
  }
  {
    KIMM_CAR_eqFunction_422(data, threadData);
    threadData->lastEquationSolved = 422;
  }
  {
    KIMM_CAR_eqFunction_423(data, threadData);
    threadData->lastEquationSolved = 423;
  }
  {
    KIMM_CAR_eqFunction_424(data, threadData);
    threadData->lastEquationSolved = 424;
  }
  {
    KIMM_CAR_eqFunction_425(data, threadData);
    threadData->lastEquationSolved = 425;
  }
  {
    KIMM_CAR_eqFunction_426(data, threadData);
    threadData->lastEquationSolved = 426;
  }
  {
    KIMM_CAR_eqFunction_427(data, threadData);
    threadData->lastEquationSolved = 427;
  }
  {
    KIMM_CAR_eqFunction_428(data, threadData);
    threadData->lastEquationSolved = 428;
  }
  {
    KIMM_CAR_eqFunction_429(data, threadData);
    threadData->lastEquationSolved = 429;
  }
  {
    KIMM_CAR_eqFunction_430(data, threadData);
    threadData->lastEquationSolved = 430;
  }
  {
    KIMM_CAR_eqFunction_431(data, threadData);
    threadData->lastEquationSolved = 431;
  }
  {
    KIMM_CAR_eqFunction_432(data, threadData);
    threadData->lastEquationSolved = 432;
  }
  {
    KIMM_CAR_eqFunction_433(data, threadData);
    threadData->lastEquationSolved = 433;
  }
  {
    KIMM_CAR_eqFunction_434(data, threadData);
    threadData->lastEquationSolved = 434;
  }
  {
    KIMM_CAR_eqFunction_435(data, threadData);
    threadData->lastEquationSolved = 435;
  }
  {
    KIMM_CAR_eqFunction_436(data, threadData);
    threadData->lastEquationSolved = 436;
  }
  {
    KIMM_CAR_eqFunction_437(data, threadData);
    threadData->lastEquationSolved = 437;
  }
  {
    KIMM_CAR_eqFunction_439(data, threadData);
    threadData->lastEquationSolved = 439;
  }
  {
    KIMM_CAR_eqFunction_440(data, threadData);
    threadData->lastEquationSolved = 440;
  }
  {
    KIMM_CAR_eqFunction_441(data, threadData);
    threadData->lastEquationSolved = 441;
  }
  {
    KIMM_CAR_eqFunction_442(data, threadData);
    threadData->lastEquationSolved = 442;
  }
  {
    KIMM_CAR_eqFunction_443(data, threadData);
    threadData->lastEquationSolved = 443;
  }
  {
    KIMM_CAR_eqFunction_444(data, threadData);
    threadData->lastEquationSolved = 444;
  }
  {
    KIMM_CAR_eqFunction_445(data, threadData);
    threadData->lastEquationSolved = 445;
  }
  {
    KIMM_CAR_eqFunction_446(data, threadData);
    threadData->lastEquationSolved = 446;
  }
  {
    KIMM_CAR_eqFunction_447(data, threadData);
    threadData->lastEquationSolved = 447;
  }
  {
    KIMM_CAR_eqFunction_448(data, threadData);
    threadData->lastEquationSolved = 448;
  }
  {
    KIMM_CAR_eqFunction_449(data, threadData);
    threadData->lastEquationSolved = 449;
  }
  {
    KIMM_CAR_eqFunction_450(data, threadData);
    threadData->lastEquationSolved = 450;
  }
  {
    KIMM_CAR_eqFunction_451(data, threadData);
    threadData->lastEquationSolved = 451;
  }
  {
    KIMM_CAR_eqFunction_452(data, threadData);
    threadData->lastEquationSolved = 452;
  }
  {
    KIMM_CAR_eqFunction_453(data, threadData);
    threadData->lastEquationSolved = 453;
  }
  {
    KIMM_CAR_eqFunction_454(data, threadData);
    threadData->lastEquationSolved = 454;
  }
  {
    KIMM_CAR_eqFunction_456(data, threadData);
    threadData->lastEquationSolved = 456;
  }
  {
    KIMM_CAR_eqFunction_457(data, threadData);
    threadData->lastEquationSolved = 457;
  }
  {
    KIMM_CAR_eqFunction_458(data, threadData);
    threadData->lastEquationSolved = 458;
  }
  {
    KIMM_CAR_eqFunction_459(data, threadData);
    threadData->lastEquationSolved = 459;
  }
  {
    KIMM_CAR_eqFunction_460(data, threadData);
    threadData->lastEquationSolved = 460;
  }
  {
    KIMM_CAR_eqFunction_461(data, threadData);
    threadData->lastEquationSolved = 461;
  }
  {
    KIMM_CAR_eqFunction_462(data, threadData);
    threadData->lastEquationSolved = 462;
  }
  {
    KIMM_CAR_eqFunction_463(data, threadData);
    threadData->lastEquationSolved = 463;
  }
  {
    KIMM_CAR_eqFunction_464(data, threadData);
    threadData->lastEquationSolved = 464;
  }
  {
    KIMM_CAR_eqFunction_465(data, threadData);
    threadData->lastEquationSolved = 465;
  }
  {
    KIMM_CAR_eqFunction_466(data, threadData);
    threadData->lastEquationSolved = 466;
  }
  {
    KIMM_CAR_eqFunction_467(data, threadData);
    threadData->lastEquationSolved = 467;
  }
  {
    KIMM_CAR_eqFunction_468(data, threadData);
    threadData->lastEquationSolved = 468;
  }
  {
    KIMM_CAR_eqFunction_470(data, threadData);
    threadData->lastEquationSolved = 470;
  }
  {
    KIMM_CAR_eqFunction_471(data, threadData);
    threadData->lastEquationSolved = 471;
  }
  {
    KIMM_CAR_eqFunction_472(data, threadData);
    threadData->lastEquationSolved = 472;
  }
  {
    KIMM_CAR_eqFunction_473(data, threadData);
    threadData->lastEquationSolved = 473;
  }
  {
    KIMM_CAR_eqFunction_475(data, threadData);
    threadData->lastEquationSolved = 475;
  }
  {
    KIMM_CAR_eqFunction_476(data, threadData);
    threadData->lastEquationSolved = 476;
  }
  {
    KIMM_CAR_eqFunction_477(data, threadData);
    threadData->lastEquationSolved = 477;
  }
  {
    KIMM_CAR_eqFunction_478(data, threadData);
    threadData->lastEquationSolved = 478;
  }
  {
    KIMM_CAR_eqFunction_479(data, threadData);
    threadData->lastEquationSolved = 479;
  }
  {
    KIMM_CAR_eqFunction_480(data, threadData);
    threadData->lastEquationSolved = 480;
  }
  {
    KIMM_CAR_eqFunction_481(data, threadData);
    threadData->lastEquationSolved = 481;
  }
  {
    KIMM_CAR_eqFunction_482(data, threadData);
    threadData->lastEquationSolved = 482;
  }
  {
    KIMM_CAR_eqFunction_483(data, threadData);
    threadData->lastEquationSolved = 483;
  }
  {
    KIMM_CAR_eqFunction_484(data, threadData);
    threadData->lastEquationSolved = 484;
  }
  {
    KIMM_CAR_eqFunction_486(data, threadData);
    threadData->lastEquationSolved = 486;
  }
  {
    KIMM_CAR_eqFunction_487(data, threadData);
    threadData->lastEquationSolved = 487;
  }
  {
    KIMM_CAR_eqFunction_488(data, threadData);
    threadData->lastEquationSolved = 488;
  }
  {
    KIMM_CAR_eqFunction_489(data, threadData);
    threadData->lastEquationSolved = 489;
  }
  {
    KIMM_CAR_eqFunction_490(data, threadData);
    threadData->lastEquationSolved = 490;
  }
  {
    KIMM_CAR_eqFunction_491(data, threadData);
    threadData->lastEquationSolved = 491;
  }
  {
    KIMM_CAR_eqFunction_492(data, threadData);
    threadData->lastEquationSolved = 492;
  }
  {
    KIMM_CAR_eqFunction_493(data, threadData);
    threadData->lastEquationSolved = 493;
  }
  {
    KIMM_CAR_eqFunction_494(data, threadData);
    threadData->lastEquationSolved = 494;
  }
  {
    KIMM_CAR_eqFunction_495(data, threadData);
    threadData->lastEquationSolved = 495;
  }
  {
    KIMM_CAR_eqFunction_496(data, threadData);
    threadData->lastEquationSolved = 496;
  }
  {
    KIMM_CAR_eqFunction_497(data, threadData);
    threadData->lastEquationSolved = 497;
  }
  {
    KIMM_CAR_eqFunction_498(data, threadData);
    threadData->lastEquationSolved = 498;
  }
  {
    KIMM_CAR_eqFunction_499(data, threadData);
    threadData->lastEquationSolved = 499;
  }
  {
    KIMM_CAR_eqFunction_500(data, threadData);
    threadData->lastEquationSolved = 500;
  }
  {
    KIMM_CAR_eqFunction_501(data, threadData);
    threadData->lastEquationSolved = 501;
  }
  {
    KIMM_CAR_eqFunction_502(data, threadData);
    threadData->lastEquationSolved = 502;
  }
  {
    KIMM_CAR_eqFunction_503(data, threadData);
    threadData->lastEquationSolved = 503;
  }
  {
    KIMM_CAR_eqFunction_504(data, threadData);
    threadData->lastEquationSolved = 504;
  }
  {
    KIMM_CAR_eqFunction_505(data, threadData);
    threadData->lastEquationSolved = 505;
  }
  {
    KIMM_CAR_eqFunction_508(data, threadData);
    threadData->lastEquationSolved = 508;
  }
  {
    KIMM_CAR_eqFunction_509(data, threadData);
    threadData->lastEquationSolved = 509;
  }
  {
    KIMM_CAR_eqFunction_510(data, threadData);
    threadData->lastEquationSolved = 510;
  }
  {
    KIMM_CAR_eqFunction_511(data, threadData);
    threadData->lastEquationSolved = 511;
  }
  {
    KIMM_CAR_eqFunction_512(data, threadData);
    threadData->lastEquationSolved = 512;
  }
  {
    KIMM_CAR_eqFunction_513(data, threadData);
    threadData->lastEquationSolved = 513;
  }
  {
    KIMM_CAR_eqFunction_514(data, threadData);
    threadData->lastEquationSolved = 514;
  }
  {
    KIMM_CAR_eqFunction_515(data, threadData);
    threadData->lastEquationSolved = 515;
  }
  {
    KIMM_CAR_eqFunction_516(data, threadData);
    threadData->lastEquationSolved = 516;
  }
  {
    KIMM_CAR_eqFunction_517(data, threadData);
    threadData->lastEquationSolved = 517;
  }
  {
    KIMM_CAR_eqFunction_518(data, threadData);
    threadData->lastEquationSolved = 518;
  }
  {
    KIMM_CAR_eqFunction_521(data, threadData);
    threadData->lastEquationSolved = 521;
  }
  {
    KIMM_CAR_eqFunction_522(data, threadData);
    threadData->lastEquationSolved = 522;
  }
  {
    KIMM_CAR_eqFunction_523(data, threadData);
    threadData->lastEquationSolved = 523;
  }
  {
    KIMM_CAR_eqFunction_524(data, threadData);
    threadData->lastEquationSolved = 524;
  }
  {
    KIMM_CAR_eqFunction_525(data, threadData);
    threadData->lastEquationSolved = 525;
  }
  {
    KIMM_CAR_eqFunction_526(data, threadData);
    threadData->lastEquationSolved = 526;
  }
  {
    KIMM_CAR_eqFunction_527(data, threadData);
    threadData->lastEquationSolved = 527;
  }
  {
    KIMM_CAR_eqFunction_529(data, threadData);
    threadData->lastEquationSolved = 529;
  }
  {
    KIMM_CAR_eqFunction_530(data, threadData);
    threadData->lastEquationSolved = 530;
  }
  {
    KIMM_CAR_eqFunction_531(data, threadData);
    threadData->lastEquationSolved = 531;
  }
  {
    KIMM_CAR_eqFunction_532(data, threadData);
    threadData->lastEquationSolved = 532;
  }
  {
    KIMM_CAR_eqFunction_533(data, threadData);
    threadData->lastEquationSolved = 533;
  }
  {
    KIMM_CAR_eqFunction_534(data, threadData);
    threadData->lastEquationSolved = 534;
  }
  {
    KIMM_CAR_eqFunction_535(data, threadData);
    threadData->lastEquationSolved = 535;
  }
  {
    KIMM_CAR_eqFunction_536(data, threadData);
    threadData->lastEquationSolved = 536;
  }
  {
    KIMM_CAR_eqFunction_538(data, threadData);
    threadData->lastEquationSolved = 538;
  }
  {
    KIMM_CAR_eqFunction_539(data, threadData);
    threadData->lastEquationSolved = 539;
  }
  {
    KIMM_CAR_eqFunction_540(data, threadData);
    threadData->lastEquationSolved = 540;
  }
  {
    KIMM_CAR_eqFunction_541(data, threadData);
    threadData->lastEquationSolved = 541;
  }
  {
    KIMM_CAR_eqFunction_542(data, threadData);
    threadData->lastEquationSolved = 542;
  }
  {
    KIMM_CAR_eqFunction_543(data, threadData);
    threadData->lastEquationSolved = 543;
  }
  {
    KIMM_CAR_eqFunction_544(data, threadData);
    threadData->lastEquationSolved = 544;
  }
  {
    KIMM_CAR_eqFunction_545(data, threadData);
    threadData->lastEquationSolved = 545;
  }
  {
    KIMM_CAR_eqFunction_547(data, threadData);
    threadData->lastEquationSolved = 547;
  }
  {
    KIMM_CAR_eqFunction_548(data, threadData);
    threadData->lastEquationSolved = 548;
  }
  {
    KIMM_CAR_eqFunction_549(data, threadData);
    threadData->lastEquationSolved = 549;
  }
  {
    KIMM_CAR_eqFunction_550(data, threadData);
    threadData->lastEquationSolved = 550;
  }
  {
    KIMM_CAR_eqFunction_551(data, threadData);
    threadData->lastEquationSolved = 551;
  }
  {
    KIMM_CAR_eqFunction_552(data, threadData);
    threadData->lastEquationSolved = 552;
  }
  {
    KIMM_CAR_eqFunction_553(data, threadData);
    threadData->lastEquationSolved = 553;
  }
  {
    KIMM_CAR_eqFunction_554(data, threadData);
    threadData->lastEquationSolved = 554;
  }
  {
    KIMM_CAR_eqFunction_556(data, threadData);
    threadData->lastEquationSolved = 556;
  }
  {
    KIMM_CAR_eqFunction_557(data, threadData);
    threadData->lastEquationSolved = 557;
  }
  {
    KIMM_CAR_eqFunction_558(data, threadData);
    threadData->lastEquationSolved = 558;
  }
  {
    KIMM_CAR_eqFunction_559(data, threadData);
    threadData->lastEquationSolved = 559;
  }
  {
    KIMM_CAR_eqFunction_560(data, threadData);
    threadData->lastEquationSolved = 560;
  }
  {
    KIMM_CAR_eqFunction_561(data, threadData);
    threadData->lastEquationSolved = 561;
  }
  {
    KIMM_CAR_eqFunction_562(data, threadData);
    threadData->lastEquationSolved = 562;
  }
  {
    KIMM_CAR_eqFunction_563(data, threadData);
    threadData->lastEquationSolved = 563;
  }
  {
    KIMM_CAR_eqFunction_564(data, threadData);
    threadData->lastEquationSolved = 564;
  }
  {
    KIMM_CAR_eqFunction_565(data, threadData);
    threadData->lastEquationSolved = 565;
  }
  {
    KIMM_CAR_eqFunction_566(data, threadData);
    threadData->lastEquationSolved = 566;
  }
  {
    KIMM_CAR_eqFunction_567(data, threadData);
    threadData->lastEquationSolved = 567;
  }
  {
    KIMM_CAR_eqFunction_568(data, threadData);
    threadData->lastEquationSolved = 568;
  }
  {
    KIMM_CAR_eqFunction_571(data, threadData);
    threadData->lastEquationSolved = 571;
  }
  {
    KIMM_CAR_eqFunction_572(data, threadData);
    threadData->lastEquationSolved = 572;
  }
  {
    KIMM_CAR_eqFunction_573(data, threadData);
    threadData->lastEquationSolved = 573;
  }
  {
    KIMM_CAR_eqFunction_574(data, threadData);
    threadData->lastEquationSolved = 574;
  }
  {
    KIMM_CAR_eqFunction_575(data, threadData);
    threadData->lastEquationSolved = 575;
  }
  {
    KIMM_CAR_eqFunction_576(data, threadData);
    threadData->lastEquationSolved = 576;
  }
  {
    KIMM_CAR_eqFunction_577(data, threadData);
    threadData->lastEquationSolved = 577;
  }
  {
    KIMM_CAR_eqFunction_578(data, threadData);
    threadData->lastEquationSolved = 578;
  }
}

int KIMM_CAR_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  KIMM_CAR_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "KIMM_CAR_12jac.h"
#include "KIMM_CAR_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks KIMM_CAR_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   KIMM_CAR_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   KIMM_CAR_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   KIMM_CAR_initializeDAEmodeData,
   KIMM_CAR_functionODE,
   KIMM_CAR_functionAlgebraics,
   KIMM_CAR_functionDAE,
   KIMM_CAR_functionLocalKnownVars,
   KIMM_CAR_input_function,
   KIMM_CAR_input_function_init,
   KIMM_CAR_input_function_updateStartValues,
   KIMM_CAR_data_function,
   KIMM_CAR_output_function,
   KIMM_CAR_setc_function,
   KIMM_CAR_function_storeDelayed,
   KIMM_CAR_function_storeSpatialDistribution,
   KIMM_CAR_function_initSpatialDistribution,
   KIMM_CAR_updateBoundVariableAttributes,
   KIMM_CAR_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   KIMM_CAR_functionRemovedInitialEquations,
   KIMM_CAR_updateBoundParameters,
   KIMM_CAR_checkForAsserts,
   KIMM_CAR_function_ZeroCrossingsEquations,
   KIMM_CAR_function_ZeroCrossings,
   KIMM_CAR_function_updateRelations,
   KIMM_CAR_zeroCrossingDescription,
   KIMM_CAR_relationDescription,
   KIMM_CAR_function_initSample,
   KIMM_CAR_INDEX_JAC_A,
   KIMM_CAR_INDEX_JAC_B,
   KIMM_CAR_INDEX_JAC_C,
   KIMM_CAR_INDEX_JAC_D,
   KIMM_CAR_INDEX_JAC_F,
   KIMM_CAR_initialAnalyticJacobianA,
   KIMM_CAR_initialAnalyticJacobianB,
   KIMM_CAR_initialAnalyticJacobianC,
   KIMM_CAR_initialAnalyticJacobianD,
   KIMM_CAR_initialAnalyticJacobianF,
   KIMM_CAR_functionJacA_column,
   KIMM_CAR_functionJacB_column,
   KIMM_CAR_functionJacC_column,
   KIMM_CAR_functionJacD_column,
   KIMM_CAR_functionJacF_column,
   KIMM_CAR_linear_model_frame,
   KIMM_CAR_linear_model_datarecovery_frame,
   KIMM_CAR_mayer,
   KIMM_CAR_lagrange,
   KIMM_CAR_pickUpBoundsForInputsInOptimization,
   KIMM_CAR_setInputData,
   KIMM_CAR_getTimeGrid,
   KIMM_CAR_symbolicInlineSystem,
   KIMM_CAR_function_initSynchronous,
   KIMM_CAR_function_updateSynchronous,
   KIMM_CAR_function_equationsSynchronous,
   KIMM_CAR_inputNames,
   KIMM_CAR_dataReconciliationInputNames,
   KIMM_CAR_read_input_fmu,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Ackerman_Steering_Model"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,23,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,53,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Body_Model"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,10,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,53,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Complex"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/Program Files/OpenModelica1.19.2-64bit/lib/omlibrary"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,7,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,55,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "EV_Motor_Model"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,14,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,53,_OMC_LIT_RESOURCE_3_dir_data);

#define _OMC_LIT_RESOURCE_4_name_data "EV_Motor_Test"
#define _OMC_LIT_RESOURCE_4_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_name,13,_OMC_LIT_RESOURCE_4_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir,53,_OMC_LIT_RESOURCE_4_dir_data);

#define _OMC_LIT_RESOURCE_5_name_data "KIMM_CAR"
#define _OMC_LIT_RESOURCE_5_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_5_name,8,_OMC_LIT_RESOURCE_5_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_5_dir,53,_OMC_LIT_RESOURCE_5_dir_data);

#define _OMC_LIT_RESOURCE_6_name_data "Modelica"
#define _OMC_LIT_RESOURCE_6_dir_data "C:/Program Files/OpenModelica1.19.2-64bit/lib/omlibrary/Modelica 4.0.0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_6_name,8,_OMC_LIT_RESOURCE_6_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_6_dir,70,_OMC_LIT_RESOURCE_6_dir_data);

#define _OMC_LIT_RESOURCE_7_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_7_dir_data "C:/Program Files/OpenModelica1.19.2-64bit/lib/omlibrary/ModelicaServices 4.0.0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_7_name,16,_OMC_LIT_RESOURCE_7_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_7_dir,78,_OMC_LIT_RESOURCE_7_dir_data);

#define _OMC_LIT_RESOURCE_8_name_data "Open_Differential_Model"
#define _OMC_LIT_RESOURCE_8_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_8_name,23,_OMC_LIT_RESOURCE_8_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_8_dir,53,_OMC_LIT_RESOURCE_8_dir_data);

#define _OMC_LIT_RESOURCE_9_name_data "Suspension_Model"
#define _OMC_LIT_RESOURCE_9_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_9_name,16,_OMC_LIT_RESOURCE_9_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_9_dir,53,_OMC_LIT_RESOURCE_9_dir_data);

#define _OMC_LIT_RESOURCE_10_name_data "Tire_Model"
#define _OMC_LIT_RESOURCE_10_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_10_name,10,_OMC_LIT_RESOURCE_10_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_10_dir,53,_OMC_LIT_RESOURCE_10_dir_data);

#define _OMC_LIT_RESOURCE_11_name_data "calc_coordinate"
#define _OMC_LIT_RESOURCE_11_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_11_name,15,_OMC_LIT_RESOURCE_11_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_11_dir,53,_OMC_LIT_RESOURCE_11_dir_data);

#define _OMC_LIT_RESOURCE_12_name_data "change_of_coordinate"
#define _OMC_LIT_RESOURCE_12_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_12_name,20,_OMC_LIT_RESOURCE_12_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_12_dir,53,_OMC_LIT_RESOURCE_12_dir_data);

#define _OMC_LIT_RESOURCE_13_name_data "normalized_tire_force_coordinate"
#define _OMC_LIT_RESOURCE_13_dir_data "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_13_name,32,_OMC_LIT_RESOURCE_13_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_13_dir,53,_OMC_LIT_RESOURCE_13_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,28,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_5_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_5_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_6_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_6_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_7_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_7_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_8_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_8_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_9_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_9_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_10_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_10_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_11_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_11_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_12_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_12_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_13_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_13_dir)}};
void KIMM_CAR_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &KIMM_CAR_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "KIMM_CAR";
  data->modelData->modelFilePrefix = "KIMM_CAR";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/ehsdl/Desktop/Modelica_Models/KIMM_CAR_MODEL";
  data->modelData->modelGUID = "{879ffc5b-6fb2-4cc0-8758-488c2f6bd8ea}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 38;
  data->modelData->nVariablesReal = 408;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 5;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 249;
  data->modelData->nParametersInteger = 24;
  data->modelData->nParametersBoolean = 4;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 91;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 26;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 31;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/KIMM_CAR_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 6;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 830;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 5;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nBaseClocks = 0;
  
  data->modelData->nSpatialDistributions = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->linearizationDumpLanguage =
  OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

