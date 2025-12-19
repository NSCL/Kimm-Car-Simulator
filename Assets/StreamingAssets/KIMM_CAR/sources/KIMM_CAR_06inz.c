/* Initialization */
#include "KIMM_CAR_model.h"
#include "KIMM_CAR_11mix.h"
#include "KIMM_CAR_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void KIMM_CAR_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
body_Model.x = $START.body_Model.x
*/
void KIMM_CAR_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[10]/* body_Model.x STATE(1,body_Model.dx) */)  = (data->modelData->realVarsData[10]/* body_Model.x STATE(1,body_Model.dx) */).attribute .start;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
body_Model.y = $START.body_Model.y
*/
void KIMM_CAR_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[11]/* body_Model.y STATE(1,body_Model.dy) */)  = (data->modelData->realVarsData[11]/* body_Model.y STATE(1,body_Model.dy) */).attribute .start;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
tire_front_left.roll = $START.tire_front_left.roll
*/
void KIMM_CAR_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[22]/* tire_front_left.roll STATE(1,tire_front_left.d_roll) */)  = (data->modelData->realVarsData[22]/* tire_front_left.roll STATE(1,tire_front_left.d_roll) */).attribute .start;
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
tire_front_right.roll = $START.tire_front_right.roll
*/
void KIMM_CAR_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[27]/* tire_front_right.roll STATE(1,tire_front_right.d_roll) */)  = (data->modelData->realVarsData[27]/* tire_front_right.roll STATE(1,tire_front_right.d_roll) */).attribute .start;
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
tire_rear_right.roll = $START.tire_rear_right.roll
*/
void KIMM_CAR_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[37]/* tire_rear_right.roll STATE(1,tire_rear_right.d_roll) */)  = (data->modelData->realVarsData[37]/* tire_rear_right.roll STATE(1,tire_rear_right.d_roll) */).attribute .start;
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
tire_rear_left.roll = $START.tire_rear_left.roll
*/
void KIMM_CAR_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[32]/* tire_rear_left.roll STATE(1,tire_rear_left.d_roll) */)  = (data->modelData->realVarsData[32]/* tire_rear_left.roll STATE(1,tire_rear_left.d_roll) */).attribute .start;
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
body_Model.cg_to_front_wheel = sqrt((0.5 * body_Model.tread_front) ^ 2.0 + body_Model.distance_front ^ 2.0)
*/
void KIMM_CAR_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = (0.5) * ((data->simulationInfo->realParameter[18]/* body_Model.tread_front PARAM */) );
  tmp1 = (data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ;
  (data->localData[0]->realVars[220]/* body_Model.cg_to_front_wheel variable */)  = sqrt((tmp0 * tmp0) + (tmp1 * tmp1));
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
body_Model.cg_to_rear_wheel = sqrt((0.5 * body_Model.tread_rear) ^ 2.0 + body_Model.distance_rear ^ 2.0)
*/
void KIMM_CAR_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_real tmp2;
  modelica_real tmp3;
  tmp2 = (0.5) * ((data->simulationInfo->realParameter[19]/* body_Model.tread_rear PARAM */) );
  tmp3 = (data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ;
  (data->localData[0]->realVars[222]/* body_Model.cg_to_rear_wheel variable */)  = sqrt((tmp2 * tmp2) + (tmp3 * tmp3));
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
body_Model.cg_to_front_angle = atan(0.5 * body_Model.tread_front / body_Model.distance_front)
*/
void KIMM_CAR_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[219]/* body_Model.cg_to_front_angle variable */)  = atan(DIVISION_SIM((0.5) * ((data->simulationInfo->realParameter[18]/* body_Model.tread_front PARAM */) ),(data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ,"body_Model.distance_front",equationIndexes));
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
body_Model.cg_to_rear_angle = atan(0.5 * body_Model.tread_rear / body_Model.distance_rear)
*/
void KIMM_CAR_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[221]/* body_Model.cg_to_rear_angle variable */)  = atan(DIVISION_SIM((0.5) * ((data->simulationInfo->realParameter[19]/* body_Model.tread_rear PARAM */) ),(data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ,"body_Model.distance_rear",equationIndexes));
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
tire_front_left.mu_s = 1.2
*/
void KIMM_CAR_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[299]/* tire_front_left.mu_s variable */)  = 1.2;
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
tire_front_left.mu_k = 0.2
*/
void KIMM_CAR_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[298]/* tire_front_left.mu_k variable */)  = 0.2;
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
tire_front_left.inch2m = 0.0254
*/
void KIMM_CAR_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[295]/* tire_front_left.inch2m variable */)  = 0.0254;
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
tire_front_left.N2lb = 0.2248090795
*/
void KIMM_CAR_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[284]/* tire_front_left.N2lb variable */)  = 0.2248090795;
  TRACE_POP
}

/*
equation index: 15
type: SIMPLE_ASSIGN
tire_front_left.rad2deg = 57.29577951308232
*/
void KIMM_CAR_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[302]/* tire_front_left.rad2deg variable */)  = 57.29577951308232;
  TRACE_POP
}

/*
equation index: 16
type: SIMPLE_ASSIGN
tire_front_left.pi = 3.141592653589793
*/
void KIMM_CAR_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[301]/* tire_front_left.pi variable */)  = 3.141592653589793;
  TRACE_POP
}

/*
equation index: 17
type: SIMPLE_ASSIGN
tire_front_right.mu_s = 1.2
*/
void KIMM_CAR_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[333]/* tire_front_right.mu_s variable */)  = 1.2;
  TRACE_POP
}

/*
equation index: 18
type: SIMPLE_ASSIGN
tire_front_right.mu_k = 0.2
*/
void KIMM_CAR_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[332]/* tire_front_right.mu_k variable */)  = 0.2;
  TRACE_POP
}

/*
equation index: 19
type: SIMPLE_ASSIGN
tire_front_right.inch2m = 0.0254
*/
void KIMM_CAR_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[329]/* tire_front_right.inch2m variable */)  = 0.0254;
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
tire_front_right.N2lb = 0.2248090795
*/
void KIMM_CAR_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[318]/* tire_front_right.N2lb variable */)  = 0.2248090795;
  TRACE_POP
}

/*
equation index: 21
type: SIMPLE_ASSIGN
tire_front_right.rad2deg = 57.29577951308232
*/
void KIMM_CAR_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[336]/* tire_front_right.rad2deg variable */)  = 57.29577951308232;
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
tire_front_right.pi = 3.141592653589793
*/
void KIMM_CAR_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[335]/* tire_front_right.pi variable */)  = 3.141592653589793;
  TRACE_POP
}

/*
equation index: 23
type: SIMPLE_ASSIGN
tire_rear_right.mu_s = 1.2
*/
void KIMM_CAR_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[401]/* tire_rear_right.mu_s variable */)  = 1.2;
  TRACE_POP
}

/*
equation index: 24
type: SIMPLE_ASSIGN
tire_rear_right.mu_k = 0.2
*/
void KIMM_CAR_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[400]/* tire_rear_right.mu_k variable */)  = 0.2;
  TRACE_POP
}

/*
equation index: 25
type: SIMPLE_ASSIGN
tire_rear_right.inch2m = 0.0254
*/
void KIMM_CAR_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[397]/* tire_rear_right.inch2m variable */)  = 0.0254;
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
tire_rear_right.N2lb = 0.2248090795
*/
void KIMM_CAR_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[386]/* tire_rear_right.N2lb variable */)  = 0.2248090795;
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
tire_rear_right.rad2deg = 57.29577951308232
*/
void KIMM_CAR_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->localData[0]->realVars[404]/* tire_rear_right.rad2deg variable */)  = 57.29577951308232;
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
tire_rear_right.pi = 3.141592653589793
*/
void KIMM_CAR_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[403]/* tire_rear_right.pi variable */)  = 3.141592653589793;
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
tire_rear_left.mu_s = 1.2
*/
void KIMM_CAR_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->localData[0]->realVars[367]/* tire_rear_left.mu_s variable */)  = 1.2;
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
tire_rear_left.mu_k = 0.2
*/
void KIMM_CAR_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[366]/* tire_rear_left.mu_k variable */)  = 0.2;
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
tire_rear_left.inch2m = 0.0254
*/
void KIMM_CAR_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[363]/* tire_rear_left.inch2m variable */)  = 0.0254;
  TRACE_POP
}

/*
equation index: 32
type: SIMPLE_ASSIGN
tire_rear_left.N2lb = 0.2248090795
*/
void KIMM_CAR_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  (data->localData[0]->realVars[352]/* tire_rear_left.N2lb variable */)  = 0.2248090795;
  TRACE_POP
}

/*
equation index: 33
type: SIMPLE_ASSIGN
tire_rear_left.rad2deg = 57.29577951308232
*/
void KIMM_CAR_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  (data->localData[0]->realVars[370]/* tire_rear_left.rad2deg variable */)  = 57.29577951308232;
  TRACE_POP
}

/*
equation index: 34
type: SIMPLE_ASSIGN
tire_rear_left.pi = 3.141592653589793
*/
void KIMM_CAR_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  (data->localData[0]->realVars[369]/* tire_rear_left.pi variable */)  = 3.141592653589793;
  TRACE_POP
}

/*
equation index: 35
type: SIMPLE_ASSIGN
ackerman_Steering_Model.rotation_radius_min = 5.99
*/
void KIMM_CAR_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  (data->localData[0]->realVars[131]/* ackerman_Steering_Model.rotation_radius_min variable */)  = 5.99;
  TRACE_POP
}

/*
equation index: 36
type: SIMPLE_ASSIGN
ackerman_Steering_Model.wheel_base = 3.0
*/
void KIMM_CAR_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[139]/* ackerman_Steering_Model.wheel_base variable */)  = 3.0;
  TRACE_POP
}

/*
equation index: 37
type: SIMPLE_ASSIGN
ackerman_Steering_Model.tread_rear = 1.651
*/
void KIMM_CAR_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  (data->localData[0]->realVars[138]/* ackerman_Steering_Model.tread_rear variable */)  = 1.651;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_344(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_345(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_346(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_347(DATA *data, threadData_t *threadData);


/*
equation index: 42
type: SIMPLE_ASSIGN
body_Model.dx = $START.body_Model.dx
*/
void KIMM_CAR_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  (data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */)  = (data->modelData->realVarsData[5]/* body_Model.dx STATE(1,body_Model.ddx) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_337(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_336(DATA *data, threadData_t *threadData);


/*
equation index: 45
type: SIMPLE_ASSIGN
body_Model.dy = $START.body_Model.dy
*/
void KIMM_CAR_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  (data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */)  = (data->modelData->realVarsData[6]/* body_Model.dy STATE(1,body_Model.ddy) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_338(DATA *data, threadData_t *threadData);


/*
equation index: 47
type: SIMPLE_ASSIGN
body_Model.z = $START.body_Model.z
*/
void KIMM_CAR_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  = (data->modelData->realVarsData[13]/* body_Model.z STATE(1,body_Model.dz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_343(DATA *data, threadData_t *threadData);


/*
equation index: 49
type: SIMPLE_ASSIGN
body_Model.dz = $START.body_Model.dz
*/
void KIMM_CAR_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  = (data->modelData->realVarsData[7]/* body_Model.dz STATE(1,body_Model.ddz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_339(DATA *data, threadData_t *threadData);


/*
equation index: 51
type: SIMPLE_ASSIGN
body_Model.roll = $START.body_Model.roll
*/
void KIMM_CAR_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  (data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */)  = (data->modelData->realVarsData[9]/* body_Model.roll STATE(1,body_Model.d_roll) */).attribute .start;
  TRACE_POP
}

/*
equation index: 52
type: SIMPLE_ASSIGN
body_Model.pitch = $START.body_Model.pitch
*/
void KIMM_CAR_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */)  = (data->modelData->realVarsData[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */).attribute .start;
  TRACE_POP
}

/*
equation index: 53
type: SIMPLE_ASSIGN
suspension_front_left.body_z_pos = body_Model.z + body_Model.distance_left * sin(body_Model.roll) * cos(body_Model.pitch) - body_Model.distance_front * sin(body_Model.pitch)
*/
void KIMM_CAR_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  (data->localData[0]->realVars[260]/* suspension_front_left.body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )));
  TRACE_POP
}

/*
equation index: 54
type: SIMPLE_ASSIGN
suspension_front_right.body_z_pos = body_Model.z + (-body_Model.distance_right) * sin(body_Model.roll) * cos(body_Model.pitch) - body_Model.distance_front * sin(body_Model.pitch)
*/
void KIMM_CAR_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  (data->localData[0]->realVars[263]/* suspension_front_right.body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((-(data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) )) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )));
  TRACE_POP
}

/*
equation index: 55
type: SIMPLE_ASSIGN
body_Model.rear_right_body_z_pos = body_Model.z + body_Model.distance_rear * sin(body_Model.pitch) - body_Model.distance_right * sin(body_Model.roll) * cos(body_Model.pitch)
*/
void KIMM_CAR_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
  (data->localData[0]->realVars[248]/* body_Model.rear_right_body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) - (((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))));
  TRACE_POP
}

/*
equation index: 56
type: SIMPLE_ASSIGN
body_Model.rear_left_body_z_pos = body_Model.z + body_Model.distance_left * sin(body_Model.roll) * cos(body_Model.pitch) + body_Model.distance_rear * sin(body_Model.pitch)
*/
void KIMM_CAR_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  (data->localData[0]->realVars[244]/* body_Model.rear_left_body_z_pos DUMMY_STATE */)  = (data->localData[0]->realVars[13]/* body_Model.z STATE(1,body_Model.dz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ));
  TRACE_POP
}

/*
equation index: 57
type: SIMPLE_ASSIGN
body_Model.yaw = $START.body_Model.yaw
*/
void KIMM_CAR_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  (data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */)  = (data->modelData->realVarsData[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */).attribute .start;
  TRACE_POP
}

/*
equation index: 58
type: SIMPLE_ASSIGN
body_Model.body_fixed_dx = cos(body_Model.pitch) * (body_Model.dx * cos(body_Model.yaw) + body_Model.dy * sin(body_Model.yaw)) - body_Model.dz * sin(body_Model.pitch)
*/
void KIMM_CAR_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  (data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */)  = (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) - (((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )));
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
body_Model.body_fixed_dy = body_Model.dx * (cos(body_Model.yaw) * sin(body_Model.pitch) * sin(body_Model.roll) - cos(body_Model.roll) * sin(body_Model.yaw)) + body_Model.dy * (cos(body_Model.roll) * cos(body_Model.yaw) + sin(body_Model.pitch) * sin(body_Model.roll) * sin(body_Model.yaw)) + body_Model.dz * cos(body_Model.pitch) * sin(body_Model.roll)
*/
void KIMM_CAR_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  (data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) ))) - ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) + (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_485(DATA *data, threadData_t *threadData);


/*
equation index: 61
type: SIMPLE_ASSIGN
body_Model.body_fixed_dz = body_Model.dx * (sin(body_Model.roll) * sin(body_Model.yaw) + cos(body_Model.roll) * cos(body_Model.yaw) * sin(body_Model.pitch)) + body_Model.dy * (cos(body_Model.roll) * sin(body_Model.pitch) * sin(body_Model.yaw) - cos(body_Model.yaw) * sin(body_Model.roll)) + body_Model.dz * cos(body_Model.pitch) * cos(body_Model.roll)
*/
void KIMM_CAR_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  (data->localData[0]->realVars[217]/* body_Model.body_fixed_dz DUMMY_STATE */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) - ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_348(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_464(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_463(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_462(DATA *data, threadData_t *threadData);


/*
equation index: 66
type: SIMPLE_ASSIGN
body_Model.d_roll = $START.body_Model.d_roll
*/
void KIMM_CAR_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  (data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */)  = (data->modelData->realVarsData[3]/* body_Model.d_roll STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_340(DATA *data, threadData_t *threadData);


/*
equation index: 68
type: SIMPLE_ASSIGN
body_Model.d_pitch = $START.body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  (data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */)  = (data->modelData->realVarsData[2]/* body_Model.d_pitch STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 69
type: SIMPLE_ASSIGN
suspension_rear_left.body_z_vel = body_Model.dz + body_Model.distance_left * (sin(body_Model.roll) * (-sin(body_Model.pitch)) * body_Model.d_pitch + cos(body_Model.roll) * body_Model.d_roll * cos(body_Model.pitch)) + body_Model.distance_rear * cos(body_Model.pitch) * body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  (data->localData[0]->realVars[266]/* suspension_rear_left.body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((-sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )))) + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_537(DATA *data, threadData_t *threadData);


/*
equation index: 71
type: SIMPLE_ASSIGN
suspension_rear_right.body_z_vel = body_Model.dz + body_Model.distance_rear * cos(body_Model.pitch) * body_Model.d_pitch - body_Model.distance_right * (sin(body_Model.roll) * (-sin(body_Model.pitch)) * body_Model.d_pitch + cos(body_Model.roll) * body_Model.d_roll * cos(body_Model.pitch))
*/
void KIMM_CAR_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  (data->localData[0]->realVars[269]/* suspension_rear_right.body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((data->simulationInfo->realParameter[13]/* body_Model.distance_rear PARAM */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) - (((data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((-sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )))));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_546(DATA *data, threadData_t *threadData);


/*
equation index: 73
type: SIMPLE_ASSIGN
body_Model.front_right_body_z_vel = body_Model.dz + (-body_Model.distance_right) * (sin(body_Model.roll) * (-sin(body_Model.pitch)) * body_Model.d_pitch + cos(body_Model.roll) * body_Model.d_roll * cos(body_Model.pitch)) - body_Model.distance_front * cos(body_Model.pitch) * body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  (data->localData[0]->realVars[231]/* body_Model.front_right_body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((-(data->simulationInfo->realParameter[14]/* body_Model.distance_right PARAM */) )) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((-sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )))) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_555(DATA *data, threadData_t *threadData);


/*
equation index: 75
type: SIMPLE_ASSIGN
body_Model.front_left_body_z_vel = body_Model.dz + body_Model.distance_left * (sin(body_Model.roll) * (-sin(body_Model.pitch)) * body_Model.d_pitch + cos(body_Model.roll) * body_Model.d_roll * cos(body_Model.pitch)) - body_Model.distance_front * cos(body_Model.pitch) * body_Model.d_pitch
*/
void KIMM_CAR_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  (data->localData[0]->realVars[227]/* body_Model.front_left_body_z_vel variable */)  = (data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */)  + ((data->simulationInfo->realParameter[12]/* body_Model.distance_left PARAM */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((-sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )))) - (((data->simulationInfo->realParameter[11]/* body_Model.distance_front PARAM */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_579(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_341(DATA *data, threadData_t *threadData);


/*
equation index: 78
type: SIMPLE_ASSIGN
body_Model.d_yaw = $START.body_Model.d_yaw
*/
void KIMM_CAR_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  (data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */)  = (data->modelData->realVarsData[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_486(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_465(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_487(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_501(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_470(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_494(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_342(DATA *data, threadData_t *threadData);


/*
equation index: 86
type: SIMPLE_ASSIGN
suspension_front_right.tire_z_pos = $START.suspension_front_right.tire_z_pos
*/
void KIMM_CAR_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  (data->localData[0]->realVars[15]/* suspension_front_right.tire_z_pos STATE(1,tire_front_right.dz) */)  = (data->modelData->realVarsData[15]/* suspension_front_right.tire_z_pos STATE(1,tire_front_right.dz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_479(DATA *data, threadData_t *threadData);


/*
equation index: 88
type: SIMPLE_ASSIGN
suspension_front_left.tire_z_pos = $START.suspension_front_left.tire_z_pos
*/
void KIMM_CAR_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  (data->localData[0]->realVars[14]/* suspension_front_left.tire_z_pos STATE(1,tire_front_left.dz) */)  = (data->modelData->realVarsData[14]/* suspension_front_left.tire_z_pos STATE(1,tire_front_left.dz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_477(DATA *data, threadData_t *threadData);


/*
equation index: 90
type: SIMPLE_ASSIGN
suspension_rear_right.tire_z_pos = $START.suspension_rear_right.tire_z_pos
*/
void KIMM_CAR_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  (data->localData[0]->realVars[17]/* suspension_rear_right.tire_z_pos STATE(1,tire_rear_right.dz) */)  = (data->modelData->realVarsData[17]/* suspension_rear_right.tire_z_pos STATE(1,tire_rear_right.dz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_481(DATA *data, threadData_t *threadData);


/*
equation index: 92
type: SIMPLE_ASSIGN
suspension_rear_left.tire_z_pos = $START.suspension_rear_left.tire_z_pos
*/
void KIMM_CAR_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  (data->localData[0]->realVars[16]/* suspension_rear_left.tire_z_pos STATE(1,tire_rear_left.dz) */)  = (data->modelData->realVarsData[16]/* suspension_rear_left.tire_z_pos STATE(1,tire_rear_left.dz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_483(DATA *data, threadData_t *threadData);


/*
equation index: 94
type: SIMPLE_ASSIGN
tire_front_left.d_roll = $START.tire_front_left.d_roll
*/
void KIMM_CAR_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  (data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */)  = (data->modelData->realVarsData[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_354(DATA *data, threadData_t *threadData);


/*
equation index: 96
type: SIMPLE_ASSIGN
tire_front_right.d_roll = $START.tire_front_right.d_roll
*/
void KIMM_CAR_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  (data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */)  = (data->modelData->realVarsData[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_358(DATA *data, threadData_t *threadData);


/*
equation index: 98
type: SIMPLE_ASSIGN
ackerman_Steering_Model.theta = $START.ackerman_Steering_Model.theta
*/
void KIMM_CAR_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  (data->localData[0]->realVars[1]/* ackerman_Steering_Model.theta STATE(1,ackerman_Steering_Model.d_theta) */)  = (data->modelData->realVarsData[1]/* ackerman_Steering_Model.theta STATE(1,ackerman_Steering_Model.d_theta) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_375(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_382(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_383(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_384(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_385(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_521(DATA *data, threadData_t *threadData);


/*
equation index: 105
type: SIMPLE_ASSIGN
body_Model.front_left_vy = body_Model.front_right_dy * cos(ackerman_Steering_Model.left_steer_angle) - body_Model.rear_left_dx * sin(ackerman_Steering_Model.left_steer_angle)
*/
void KIMM_CAR_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  (data->localData[0]->realVars[230]/* body_Model.front_left_vy variable */)  = ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * (cos((data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */) )) - (((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ) * (sin((data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */) )));
  TRACE_POP
}

/*
equation index: 106
type: SIMPLE_ASSIGN
body_Model.front_left_vx = body_Model.rear_left_dx * cos(ackerman_Steering_Model.left_steer_angle) + body_Model.front_right_dy * sin(ackerman_Steering_Model.left_steer_angle)
*/
void KIMM_CAR_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */)  = ((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ) * (cos((data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */) )) + ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * (sin((data->localData[0]->realVars[126]/* ackerman_Steering_Model.left_steer_angle variable */) ));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_519(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_376(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_377(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_378(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_379(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_508(DATA *data, threadData_t *threadData);


/*
equation index: 113
type: SIMPLE_ASSIGN
body_Model.front_right_vy = body_Model.front_right_dy * cos(ackerman_Steering_Model.right_steer_angle) - body_Model.rear_right_dx * sin(ackerman_Steering_Model.right_steer_angle)
*/
void KIMM_CAR_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  (data->localData[0]->realVars[235]/* body_Model.front_right_vy variable */)  = ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * (cos((data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */) )) - (((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ) * (sin((data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */) )));
  TRACE_POP
}

/*
equation index: 114
type: SIMPLE_ASSIGN
body_Model.front_right_vx = body_Model.rear_right_dx * cos(ackerman_Steering_Model.right_steer_angle) + body_Model.front_right_dy * sin(ackerman_Steering_Model.right_steer_angle)
*/
void KIMM_CAR_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */)  = ((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ) * (cos((data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */) )) + ((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) * (sin((data->localData[0]->realVars[130]/* ackerman_Steering_Model.right_steer_angle variable */) ));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_506(DATA *data, threadData_t *threadData);


/*
equation index: 116
type: SIMPLE_ASSIGN
ackerman_Steering_Model.d_theta = $START.ackerman_Steering_Model.d_theta
*/
void KIMM_CAR_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  (data->localData[0]->realVars[0]/* ackerman_Steering_Model.d_theta STATE(1) */)  = (data->modelData->realVarsData[0]/* ackerman_Steering_Model.d_theta STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_374(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_373(DATA *data, threadData_t *threadData);


/*
equation index: 119
type: SIMPLE_ASSIGN
tire_rear_left.d_roll = $START.tire_rear_left.d_roll
*/
void KIMM_CAR_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  (data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */)  = (data->modelData->realVarsData[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_474(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_366(DATA *data, threadData_t *threadData);


/*
equation index: 122
type: SIMPLE_ASSIGN
tire_rear_left.d_brake = $START.tire_rear_left.d_brake
*/
void KIMM_CAR_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  (data->localData[0]->realVars[29]/* tire_rear_left.d_brake STATE(1) */)  = (data->modelData->realVarsData[29]/* tire_rear_left.d_brake STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_365(DATA *data, threadData_t *threadData);


/*
equation index: 124
type: SIMPLE_ASSIGN
tire_rear_left.brake = $START.tire_rear_left.brake
*/
void KIMM_CAR_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  (data->localData[0]->realVars[28]/* tire_rear_left.brake STATE(1,tire_rear_left.d_brake) */)  = (data->modelData->realVarsData[28]/* tire_rear_left.brake STATE(1,tire_rear_left.d_brake) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_368(DATA *data, threadData_t *threadData);


/*
equation index: 126
type: SIMPLE_ASSIGN
tire_rear_left.brake_force = tire_rear_left.brake_force_max * tire_rear_left.brake_out * sin(tire_rear_left.magic_C * atan(tire_rear_left.magic_B * tire_rear_left.d_roll - tire_rear_left.magic_E * (tire_rear_left.magic_B * tire_rear_left.d_roll - atan(tire_rear_left.magic_B * tire_rear_left.d_roll))))
*/
void KIMM_CAR_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
  (data->localData[0]->realVars[354]/* tire_rear_left.brake_force variable */)  = ((data->simulationInfo->realParameter[212]/* tire_rear_left.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[356]/* tire_rear_left.brake_out variable */) ) * (sin(((data->simulationInfo->realParameter[218]/* tire_rear_left.magic_C PARAM */) ) * (atan(((data->simulationInfo->realParameter[217]/* tire_rear_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) - (((data->simulationInfo->realParameter[219]/* tire_rear_left.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[217]/* tire_rear_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) - atan(((data->simulationInfo->realParameter[217]/* tire_rear_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) )))))))));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_367(DATA *data, threadData_t *threadData);


/*
equation index: 128
type: SIMPLE_ASSIGN
tire_rear_left.dz = $START.tire_rear_left.dz
*/
void KIMM_CAR_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  (data->localData[0]->realVars[31]/* tire_rear_left.dz STATE(1,tire_rear_left.ddz) */)  = (data->modelData->realVarsData[31]/* tire_rear_left.dz STATE(1,tire_rear_left.ddz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_530(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_352(DATA *data, threadData_t *threadData);


/*
equation index: 131
type: SIMPLE_ASSIGN
tire_rear_right.d_roll = $START.tire_rear_right.d_roll
*/
void KIMM_CAR_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
  (data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */)  = (data->modelData->realVarsData[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_469(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_369(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_370(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_371(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_372(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_362(DATA *data, threadData_t *threadData);


/*
equation index: 138
type: SIMPLE_ASSIGN
tire_rear_right.d_brake = $START.tire_rear_right.d_brake
*/
void KIMM_CAR_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  (data->localData[0]->realVars[34]/* tire_rear_right.d_brake STATE(1) */)  = (data->modelData->realVarsData[34]/* tire_rear_right.d_brake STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_361(DATA *data, threadData_t *threadData);


/*
equation index: 140
type: SIMPLE_ASSIGN
tire_rear_right.brake = $START.tire_rear_right.brake
*/
void KIMM_CAR_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  (data->localData[0]->realVars[33]/* tire_rear_right.brake STATE(1,tire_rear_right.d_brake) */)  = (data->modelData->realVarsData[33]/* tire_rear_right.brake STATE(1,tire_rear_right.d_brake) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_364(DATA *data, threadData_t *threadData);


/*
equation index: 142
type: SIMPLE_ASSIGN
tire_rear_right.brake_force = tire_rear_right.brake_force_max * tire_rear_right.brake_out * sin(tire_rear_right.magic_C * atan(tire_rear_right.magic_B * tire_rear_right.d_roll - tire_rear_right.magic_E * (tire_rear_right.magic_B * tire_rear_right.d_roll - atan(tire_rear_right.magic_B * tire_rear_right.d_roll))))
*/
void KIMM_CAR_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  (data->localData[0]->realVars[388]/* tire_rear_right.brake_force variable */)  = ((data->simulationInfo->realParameter[230]/* tire_rear_right.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[390]/* tire_rear_right.brake_out variable */) ) * (sin(((data->simulationInfo->realParameter[236]/* tire_rear_right.magic_C PARAM */) ) * (atan(((data->simulationInfo->realParameter[235]/* tire_rear_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) - (((data->simulationInfo->realParameter[237]/* tire_rear_right.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[235]/* tire_rear_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) - atan(((data->simulationInfo->realParameter[235]/* tire_rear_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) )))))))));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_363(DATA *data, threadData_t *threadData);


/*
equation index: 144
type: SIMPLE_ASSIGN
tire_rear_right.dz = $START.tire_rear_right.dz
*/
void KIMM_CAR_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  (data->localData[0]->realVars[36]/* tire_rear_right.dz STATE(1,tire_rear_right.ddz) */)  = (data->modelData->realVarsData[36]/* tire_rear_right.dz STATE(1,tire_rear_right.ddz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_539(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_351(DATA *data, threadData_t *threadData);


/*
equation index: 147
type: SIMPLE_ASSIGN
tire_front_right.d_brake = $START.tire_front_right.d_brake
*/
void KIMM_CAR_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
  (data->localData[0]->realVars[24]/* tire_front_right.d_brake STATE(1) */)  = (data->modelData->realVarsData[24]/* tire_front_right.d_brake STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_357(DATA *data, threadData_t *threadData);


/*
equation index: 149
type: SIMPLE_ASSIGN
tire_front_right.brake = $START.tire_front_right.brake
*/
void KIMM_CAR_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  (data->localData[0]->realVars[23]/* tire_front_right.brake STATE(1,tire_front_right.d_brake) */)  = (data->modelData->realVarsData[23]/* tire_front_right.brake STATE(1,tire_front_right.d_brake) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_360(DATA *data, threadData_t *threadData);


/*
equation index: 151
type: SIMPLE_ASSIGN
tire_front_right.brake_force = tire_front_right.brake_force_max * tire_front_right.brake_out * sin(tire_front_right.magic_C * atan(tire_front_right.magic_B * tire_front_right.d_roll - tire_front_right.magic_E * (tire_front_right.magic_B * tire_front_right.d_roll - atan(tire_front_right.magic_B * tire_front_right.d_roll))))
*/
void KIMM_CAR_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
  (data->localData[0]->realVars[320]/* tire_front_right.brake_force variable */)  = ((data->simulationInfo->realParameter[194]/* tire_front_right.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[322]/* tire_front_right.brake_out variable */) ) * (sin(((data->simulationInfo->realParameter[200]/* tire_front_right.magic_C PARAM */) ) * (atan(((data->simulationInfo->realParameter[199]/* tire_front_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) - (((data->simulationInfo->realParameter[201]/* tire_front_right.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[199]/* tire_front_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) - atan(((data->simulationInfo->realParameter[199]/* tire_front_right.magic_B PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) )))))))));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_359(DATA *data, threadData_t *threadData);


/*
equation index: 153
type: SIMPLE_ASSIGN
tire_front_right.dz = $START.tire_front_right.dz
*/
void KIMM_CAR_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
  (data->localData[0]->realVars[26]/* tire_front_right.dz STATE(1,tire_front_right.ddz) */)  = (data->modelData->realVarsData[26]/* tire_front_right.dz STATE(1,tire_front_right.ddz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_548(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_349(DATA *data, threadData_t *threadData);


/*
equation index: 156
type: SIMPLE_ASSIGN
tire_front_left.d_brake = $START.tire_front_left.d_brake
*/
void KIMM_CAR_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
  (data->localData[0]->realVars[19]/* tire_front_left.d_brake STATE(1) */)  = (data->modelData->realVarsData[19]/* tire_front_left.d_brake STATE(1) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_353(DATA *data, threadData_t *threadData);


/*
equation index: 158
type: SIMPLE_ASSIGN
tire_front_left.brake = $START.tire_front_left.brake
*/
void KIMM_CAR_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
  (data->localData[0]->realVars[18]/* tire_front_left.brake STATE(1,tire_front_left.d_brake) */)  = (data->modelData->realVarsData[18]/* tire_front_left.brake STATE(1,tire_front_left.d_brake) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_356(DATA *data, threadData_t *threadData);


/*
equation index: 160
type: SIMPLE_ASSIGN
tire_front_left.brake_force = tire_front_left.brake_force_max * tire_front_left.brake_out * sin(tire_front_left.magic_C * atan(tire_front_left.magic_B * tire_front_left.d_roll - tire_front_left.magic_E * (tire_front_left.magic_B * tire_front_left.d_roll - atan(tire_front_left.magic_B * tire_front_left.d_roll))))
*/
void KIMM_CAR_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
  (data->localData[0]->realVars[286]/* tire_front_left.brake_force variable */)  = ((data->simulationInfo->realParameter[176]/* tire_front_left.brake_force_max PARAM */) ) * (((data->localData[0]->realVars[288]/* tire_front_left.brake_out variable */) ) * (sin(((data->simulationInfo->realParameter[182]/* tire_front_left.magic_C PARAM */) ) * (atan(((data->simulationInfo->realParameter[181]/* tire_front_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) - (((data->simulationInfo->realParameter[183]/* tire_front_left.magic_E PARAM */) ) * (((data->simulationInfo->realParameter[181]/* tire_front_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) - atan(((data->simulationInfo->realParameter[181]/* tire_front_left.magic_B PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) )))))))));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_355(DATA *data, threadData_t *threadData);


/*
equation index: 162
type: SIMPLE_ASSIGN
tire_front_left.dz = $START.tire_front_left.dz
*/
void KIMM_CAR_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
  (data->localData[0]->realVars[21]/* tire_front_left.dz STATE(1,tire_front_left.ddz) */)  = (data->modelData->realVarsData[21]/* tire_front_left.dz STATE(1,tire_front_left.ddz) */).attribute .start;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_557(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_350(DATA *data, threadData_t *threadData);


/*
equation index: 165
type: SIMPLE_ASSIGN
body_Model.gnd_pitch_RL = asin(front_z_rl.k)
*/
void KIMM_CAR_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
  modelica_real tmp4;
  tmp4 = (data->simulationInfo->realParameter[69]/* front_z_rl.k PARAM */) ;
  if(!(tmp4 >= -1.0 && tmp4 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of asin(front_z_rl.k) outside the domain -1.0 <= %g <= 1.0", tmp4);
    }
  }
  (data->localData[0]->realVars[238]/* body_Model.gnd_pitch_RL variable */)  = asin(tmp4);
  TRACE_POP
}

/*
equation index: 166
type: SIMPLE_ASSIGN
tire_rear_left.gap = (suspension_rear_left.tire_z_pos - ray_rear_left.k) * cos(body_Model.gnd_pitch_RL - body_Model.pitch) - tire_rear_left.radius
*/
void KIMM_CAR_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  (data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[16]/* suspension_rear_left.tire_z_pos STATE(1,tire_rear_left.dz) */)  - (data->simulationInfo->realParameter[149]/* ray_rear_left.k PARAM */) ) * (cos((data->localData[0]->realVars[238]/* body_Model.gnd_pitch_RL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) - (data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_495(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_496(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_471(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_472(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_473(DATA *data, threadData_t *threadData);


/*
equation index: 172
type: SIMPLE_ASSIGN
tire_rear_left.d_gap = (suspension_rear_left.tire_z_pos - ray_rear_left.k) * sin(body_Model.gnd_pitch_RL - body_Model.pitch) * body_Model.d_pitch + tire_rear_left.dz * cos(body_Model.gnd_pitch_RL - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  (data->localData[0]->realVars[358]/* tire_rear_left.d_gap variable */)  = ((data->localData[0]->realVars[16]/* suspension_rear_left.tire_z_pos STATE(1,tire_rear_left.dz) */)  - (data->simulationInfo->realParameter[149]/* ray_rear_left.k PARAM */) ) * ((sin((data->localData[0]->realVars[238]/* body_Model.gnd_pitch_RL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[31]/* tire_rear_left.dz STATE(1,tire_rear_left.ddz) */) ) * (cos((data->localData[0]->realVars[238]/* body_Model.gnd_pitch_RL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_396(DATA *data, threadData_t *threadData);


/*
equation index: 174
type: SIMPLE_ASSIGN
tire_rear_left.ddz = (tire_rear_left.tire_normal_force + suspension_rear_left.suspension_force + 9.81 * (-tire_rear_left.mass) * cos(body_Model.pitch) * cos(body_Model.roll)) / tire_rear_left.mass
*/
void KIMM_CAR_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
  (data->localData[0]->realVars[360]/* tire_rear_left.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[373]/* tire_rear_left.tire_normal_force variable */)  + (data->localData[0]->realVars[268]/* suspension_rear_left.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[220]/* tire_rear_left.mass PARAM */) )) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))),(data->simulationInfo->realParameter[220]/* tire_rear_left.mass PARAM */) ,"tire_rear_left.mass",equationIndexes);
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_536(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_397(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_399(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_402(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_403(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_500(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_398(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_400(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_401(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_497(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_498(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_499(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_533(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_532(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_531(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_534(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_404(DATA *data, threadData_t *threadData);


/*
equation index: 192
type: SIMPLE_ASSIGN
body_Model.gnd_pitch_RR = asin(front_z_rr.k)
*/
void KIMM_CAR_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  modelica_real tmp5;
  tmp5 = (data->simulationInfo->realParameter[71]/* front_z_rr.k PARAM */) ;
  if(!(tmp5 >= -1.0 && tmp5 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of asin(front_z_rr.k) outside the domain -1.0 <= %g <= 1.0", tmp5);
    }
  }
  (data->localData[0]->realVars[239]/* body_Model.gnd_pitch_RR variable */)  = asin(tmp5);
  TRACE_POP
}

/*
equation index: 193
type: SIMPLE_ASSIGN
tire_rear_right.gap = (suspension_rear_right.tire_z_pos - ray_rear_right.k) * cos(body_Model.gnd_pitch_RR - body_Model.pitch) - tire_rear_right.radius
*/
void KIMM_CAR_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
  (data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[17]/* suspension_rear_right.tire_z_pos STATE(1,tire_rear_right.dz) */)  - (data->simulationInfo->realParameter[151]/* ray_rear_right.k PARAM */) ) * (cos((data->localData[0]->realVars[239]/* body_Model.gnd_pitch_RR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) - (data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_488(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_489(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_466(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_467(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_468(DATA *data, threadData_t *threadData);


/*
equation index: 199
type: SIMPLE_ASSIGN
tire_rear_right.d_gap = (suspension_rear_right.tire_z_pos - ray_rear_right.k) * sin(body_Model.gnd_pitch_RR - body_Model.pitch) * body_Model.d_pitch + tire_rear_right.dz * cos(body_Model.gnd_pitch_RR - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,199};
  (data->localData[0]->realVars[392]/* tire_rear_right.d_gap variable */)  = ((data->localData[0]->realVars[17]/* suspension_rear_right.tire_z_pos STATE(1,tire_rear_right.dz) */)  - (data->simulationInfo->realParameter[151]/* ray_rear_right.k PARAM */) ) * ((sin((data->localData[0]->realVars[239]/* body_Model.gnd_pitch_RR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[36]/* tire_rear_right.dz STATE(1,tire_rear_right.ddz) */) ) * (cos((data->localData[0]->realVars[239]/* body_Model.gnd_pitch_RR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_413(DATA *data, threadData_t *threadData);


/*
equation index: 201
type: SIMPLE_ASSIGN
tire_rear_right.ddz = (tire_rear_right.tire_normal_force + suspension_rear_right.suspension_force + 9.81 * (-tire_rear_right.mass) * cos(body_Model.pitch) * cos(body_Model.roll)) / tire_rear_right.mass
*/
void KIMM_CAR_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  (data->localData[0]->realVars[394]/* tire_rear_right.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[407]/* tire_rear_right.tire_normal_force variable */)  + (data->localData[0]->realVars[271]/* suspension_rear_right.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[238]/* tire_rear_right.mass PARAM */) )) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))),(data->simulationInfo->realParameter[238]/* tire_rear_right.mass PARAM */) ,"tire_rear_right.mass",equationIndexes);
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_545(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_414(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_416(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_419(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_420(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_493(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_415(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_417(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_418(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_490(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_491(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_492(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_542(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_541(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_540(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_543(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_421(DATA *data, threadData_t *threadData);


/*
equation index: 219
type: SIMPLE_ASSIGN
body_Model.gnd_pitch_FR = asin(front_z_fr.k)
*/
void KIMM_CAR_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  modelica_real tmp6;
  tmp6 = (data->simulationInfo->realParameter[67]/* front_z_fr.k PARAM */) ;
  if(!(tmp6 >= -1.0 && tmp6 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of asin(front_z_fr.k) outside the domain -1.0 <= %g <= 1.0", tmp6);
    }
  }
  (data->localData[0]->realVars[237]/* body_Model.gnd_pitch_FR variable */)  = asin(tmp6);
  TRACE_POP
}

/*
equation index: 220
type: SIMPLE_ASSIGN
tire_front_right.gap = (suspension_front_right.tire_z_pos - ray_front_right.k) * cos(body_Model.gnd_pitch_FR - body_Model.pitch) - tire_front_right.radius
*/
void KIMM_CAR_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  (data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[15]/* suspension_front_right.tire_z_pos STATE(1,tire_front_right.dz) */)  - (data->simulationInfo->realParameter[147]/* ray_front_right.k PARAM */) ) * (cos((data->localData[0]->realVars[237]/* body_Model.gnd_pitch_FR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) - (data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_509(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_510(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_503(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_504(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_505(DATA *data, threadData_t *threadData);


/*
equation index: 226
type: SIMPLE_ASSIGN
tire_front_right.d_gap = (suspension_front_right.tire_z_pos - ray_front_right.k) * sin(body_Model.gnd_pitch_FR - body_Model.pitch) * body_Model.d_pitch + tire_front_right.dz * cos(body_Model.gnd_pitch_FR - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  (data->localData[0]->realVars[324]/* tire_front_right.d_gap variable */)  = ((data->localData[0]->realVars[15]/* suspension_front_right.tire_z_pos STATE(1,tire_front_right.dz) */)  - (data->simulationInfo->realParameter[147]/* ray_front_right.k PARAM */) ) * ((sin((data->localData[0]->realVars[237]/* body_Model.gnd_pitch_FR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[26]/* tire_front_right.dz STATE(1,tire_front_right.ddz) */) ) * (cos((data->localData[0]->realVars[237]/* body_Model.gnd_pitch_FR variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_430(DATA *data, threadData_t *threadData);


/*
equation index: 228
type: SIMPLE_ASSIGN
tire_front_right.ddz = (tire_front_right.tire_normal_force + suspension_front_right.suspension_force + 9.81 * (-tire_front_right.mass) * cos(body_Model.pitch) * cos(body_Model.roll)) / tire_front_right.mass
*/
void KIMM_CAR_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  (data->localData[0]->realVars[326]/* tire_front_right.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[339]/* tire_front_right.tire_normal_force variable */)  + (data->localData[0]->realVars[265]/* suspension_front_right.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[202]/* tire_front_right.mass PARAM */) )) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))),(data->simulationInfo->realParameter[202]/* tire_front_right.mass PARAM */) ,"tire_front_right.mass",equationIndexes);
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_554(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_431(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_433(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_436(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_437(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_514(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_432(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_434(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_435(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_511(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_512(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_513(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_551(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_550(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_549(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_552(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_438(DATA *data, threadData_t *threadData);


/*
equation index: 246
type: SIMPLE_ASSIGN
body_Model.gnd_pitch_FL = asin(front_z_fl.k)
*/
void KIMM_CAR_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  modelica_real tmp7;
  tmp7 = (data->simulationInfo->realParameter[65]/* front_z_fl.k PARAM */) ;
  if(!(tmp7 >= -1.0 && tmp7 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of asin(front_z_fl.k) outside the domain -1.0 <= %g <= 1.0", tmp7);
    }
  }
  (data->localData[0]->realVars[236]/* body_Model.gnd_pitch_FL variable */)  = asin(tmp7);
  TRACE_POP
}

/*
equation index: 247
type: SIMPLE_ASSIGN
tire_front_left.gap = (suspension_front_left.tire_z_pos - ray_front_left.k) * cos(body_Model.gnd_pitch_FL - body_Model.pitch) - tire_front_left.radius
*/
void KIMM_CAR_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  (data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */)  = ((data->localData[0]->realVars[14]/* suspension_front_left.tire_z_pos STATE(1,tire_front_left.dz) */)  - (data->simulationInfo->realParameter[145]/* ray_front_left.k PARAM */) ) * (cos((data->localData[0]->realVars[236]/* body_Model.gnd_pitch_FL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) - (data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ;
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_522(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_523(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_516(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_517(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_518(DATA *data, threadData_t *threadData);


/*
equation index: 253
type: SIMPLE_ASSIGN
tire_front_left.d_gap = (suspension_front_left.tire_z_pos - ray_front_left.k) * sin(body_Model.gnd_pitch_FL - body_Model.pitch) * body_Model.d_pitch + tire_front_left.dz * cos(body_Model.gnd_pitch_FL - body_Model.pitch)
*/
void KIMM_CAR_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  (data->localData[0]->realVars[290]/* tire_front_left.d_gap variable */)  = ((data->localData[0]->realVars[14]/* suspension_front_left.tire_z_pos STATE(1,tire_front_left.dz) */)  - (data->simulationInfo->realParameter[145]/* ray_front_left.k PARAM */) ) * ((sin((data->localData[0]->realVars[236]/* body_Model.gnd_pitch_FL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) + ((data->localData[0]->realVars[21]/* tire_front_left.dz STATE(1,tire_front_left.ddz) */) ) * (cos((data->localData[0]->realVars[236]/* body_Model.gnd_pitch_FL variable */)  - (data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_447(DATA *data, threadData_t *threadData);


/*
equation index: 255
type: SIMPLE_ASSIGN
tire_front_left.ddz = (tire_front_left.tire_normal_force + suspension_front_left.suspension_force + 9.81 * (-tire_front_left.mass) * cos(body_Model.pitch) * cos(body_Model.roll)) / tire_front_left.mass
*/
void KIMM_CAR_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  (data->localData[0]->realVars[292]/* tire_front_left.ddz variable */)  = DIVISION_SIM((data->localData[0]->realVars[305]/* tire_front_left.tire_normal_force variable */)  + (data->localData[0]->realVars[262]/* suspension_front_left.suspension_force variable */)  + (9.81) * (((-(data->simulationInfo->realParameter[184]/* tire_front_left.mass PARAM */) )) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))),(data->simulationInfo->realParameter[184]/* tire_front_left.mass PARAM */) ,"tire_front_left.mass",equationIndexes);
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_578(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_448(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_450(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_453(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_454(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_527(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_449(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_451(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_452(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_524(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_525(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_526(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_566(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_567(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_562(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_563(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_558(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_572(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_573(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_574(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_576(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_575(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_559(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_455(DATA *data, threadData_t *threadData);


/*
equation index: 280
type: SIMPLE_ASSIGN
body_Model.mass_total = body_Model.mass_body + body_Model.mass_tire * 4.0
*/
void KIMM_CAR_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  (data->localData[0]->realVars[240]/* body_Model.mass_total variable */)  = (data->simulationInfo->realParameter[15]/* body_Model.mass_body PARAM */)  + ((data->simulationInfo->realParameter[16]/* body_Model.mass_tire PARAM */) ) * (4.0);
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_568(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_571(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_564(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_565(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_560(DATA *data, threadData_t *threadData);


/*
equation index: 286
type: SIMPLE_ASSIGN
body_Model.body_fixed_ddz = body_Model.dx * (sin(body_Model.roll) * cos(body_Model.yaw) * body_Model.d_yaw + cos(body_Model.roll) * body_Model.d_roll * sin(body_Model.yaw) + cos(body_Model.roll) * (cos(body_Model.yaw) * cos(body_Model.pitch) * body_Model.d_pitch - sin(body_Model.yaw) * body_Model.d_yaw * sin(body_Model.pitch)) - sin(body_Model.roll) * body_Model.d_roll * cos(body_Model.yaw) * sin(body_Model.pitch)) + body_Model.ddx * (sin(body_Model.roll) * sin(body_Model.yaw) + cos(body_Model.roll) * cos(body_Model.yaw) * sin(body_Model.pitch)) + body_Model.dy * (cos(body_Model.roll) * (sin(body_Model.pitch) * cos(body_Model.yaw) * body_Model.d_yaw + cos(body_Model.pitch) * body_Model.d_pitch * sin(body_Model.yaw)) + sin(body_Model.yaw) * body_Model.d_yaw * sin(body_Model.roll) - cos(body_Model.yaw) * cos(body_Model.roll) * body_Model.d_roll - sin(body_Model.roll) * body_Model.d_roll * sin(body_Model.pitch) * sin(body_Model.yaw)) + body_Model.ddy * (cos(body_Model.roll) * sin(body_Model.pitch) * sin(body_Model.yaw) - cos(body_Model.yaw) * sin(body_Model.roll)) + body_Model.dz * (cos(body_Model.pitch) * (-sin(body_Model.roll)) * body_Model.d_roll - sin(body_Model.pitch) * body_Model.d_pitch * cos(body_Model.roll)) + body_Model.ddz * cos(body_Model.pitch) * cos(body_Model.roll)
*/
void KIMM_CAR_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  (data->localData[0]->realVars[214]/* body_Model.body_fixed_ddz variable */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) - ((sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))))) - ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )))))) + ((data->localData[0]->realVars[224]/* body_Model.ddx variable */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))) + (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) ))) - ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ))) - ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))))) + ((data->localData[0]->realVars[225]/* body_Model.ddy variable */) ) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) - ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((-sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) ))) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) )) - ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) ))))) + ((data->localData[0]->realVars[226]/* body_Model.ddz variable */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_583(DATA *data, threadData_t *threadData);


/*
equation index: 288
type: SIMPLE_ASSIGN
body_Model.body_fixed_ddy = body_Model.dx * (cos(body_Model.yaw) * (sin(body_Model.pitch) * cos(body_Model.roll) * body_Model.d_roll + cos(body_Model.pitch) * body_Model.d_pitch * sin(body_Model.roll)) + sin(body_Model.roll) * body_Model.d_roll * sin(body_Model.yaw) - cos(body_Model.roll) * cos(body_Model.yaw) * body_Model.d_yaw - sin(body_Model.yaw) * body_Model.d_yaw * sin(body_Model.pitch) * sin(body_Model.roll)) + body_Model.ddx * (cos(body_Model.yaw) * sin(body_Model.pitch) * sin(body_Model.roll) - cos(body_Model.roll) * sin(body_Model.yaw)) + body_Model.dy * (cos(body_Model.roll) * (-sin(body_Model.yaw)) * body_Model.d_yaw + sin(body_Model.pitch) * (sin(body_Model.roll) * cos(body_Model.yaw) * body_Model.d_yaw + cos(body_Model.roll) * body_Model.d_roll * sin(body_Model.yaw)) + cos(body_Model.pitch) * body_Model.d_pitch * sin(body_Model.roll) * sin(body_Model.yaw) - sin(body_Model.roll) * body_Model.d_roll * cos(body_Model.yaw)) + body_Model.ddy * (cos(body_Model.roll) * cos(body_Model.yaw) + sin(body_Model.pitch) * sin(body_Model.roll) * sin(body_Model.yaw)) + body_Model.dz * (cos(body_Model.pitch) * cos(body_Model.roll) * body_Model.d_roll - sin(body_Model.pitch) * body_Model.d_pitch * sin(body_Model.roll)) + body_Model.ddz * cos(body_Model.pitch) * sin(body_Model.roll)
*/
void KIMM_CAR_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  (data->localData[0]->realVars[213]/* body_Model.body_fixed_ddy variable */)  = ((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) )) + (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))) + (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) - ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ))) - ((sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * (((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) ) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )))))) + ((data->localData[0]->realVars[224]/* body_Model.ddx variable */) ) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) ))) - ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((-sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + (cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))) + (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))) - ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) ) * (cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))))) + ((data->localData[0]->realVars[225]/* body_Model.ddy variable */) ) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) + (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))) + ((data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((cos((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )) * ((data->localData[0]->realVars[3]/* body_Model.d_roll STATE(1) */) )) - ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) ))))) + ((data->localData[0]->realVars[226]/* body_Model.ddz variable */) ) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (sin((data->localData[0]->realVars[9]/* body_Model.roll STATE(1,body_Model.d_roll) */) )));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_581(DATA *data, threadData_t *threadData);


/*
equation index: 290
type: SIMPLE_ASSIGN
body_Model.body_fixed_ddx = cos(body_Model.pitch) * (body_Model.dx * (-sin(body_Model.yaw)) * body_Model.d_yaw + body_Model.ddx * cos(body_Model.yaw) + body_Model.dy * cos(body_Model.yaw) * body_Model.d_yaw + body_Model.ddy * sin(body_Model.yaw)) + (-body_Model.dz) * cos(body_Model.pitch) * body_Model.d_pitch - body_Model.ddz * sin(body_Model.pitch) - sin(body_Model.pitch) * body_Model.d_pitch * (body_Model.dx * cos(body_Model.yaw) + body_Model.dy * sin(body_Model.yaw))
*/
void KIMM_CAR_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  (data->localData[0]->realVars[212]/* body_Model.body_fixed_ddx variable */)  = (cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (((-sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[224]/* body_Model.ddx variable */) ) * (cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * ((cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) * ((data->localData[0]->realVars[4]/* body_Model.d_yaw STATE(1,body_Model.dd_yaw) */) )) + ((data->localData[0]->realVars[225]/* body_Model.ddy variable */) ) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) ))) + ((-(data->localData[0]->realVars[7]/* body_Model.dz STATE(1,body_Model.ddz) */) )) * ((cos((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * ((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) )) - (((data->localData[0]->realVars[226]/* body_Model.ddz variable */) ) * (sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) ))) - ((sin((data->localData[0]->realVars[8]/* body_Model.pitch STATE(1,body_Model.d_pitch) */) )) * (((data->localData[0]->realVars[2]/* body_Model.d_pitch STATE(1) */) ) * (((data->localData[0]->realVars[5]/* body_Model.dx STATE(1,body_Model.ddx) */) ) * (cos((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )) + ((data->localData[0]->realVars[6]/* body_Model.dy STATE(1,body_Model.ddy) */) ) * (sin((data->localData[0]->realVars[12]/* body_Model.yaw STATE(1,body_Model.d_yaw) */) )))));
  TRACE_POP
}
extern void KIMM_CAR_eqFunction_570(DATA *data, threadData_t *threadData);

extern void KIMM_CAR_eqFunction_561(DATA *data, threadData_t *threadData);


/*
equation index: 293
type: SIMPLE_ASSIGN
tire_front_left.Cx = 1.579
*/
void KIMM_CAR_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  (data->localData[0]->realVars[276]/* tire_front_left.Cx variable */)  = 1.579;
  TRACE_POP
}

/*
equation index: 294
type: SIMPLE_ASSIGN
tire_front_left.Cy = 1.338
*/
void KIMM_CAR_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  (data->localData[0]->realVars[278]/* tire_front_left.Cy variable */)  = 1.338;
  TRACE_POP
}

/*
equation index: 295
type: SIMPLE_ASSIGN
tire_front_left.Cxa = 0.2995
*/
void KIMM_CAR_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
  (data->localData[0]->realVars[277]/* tire_front_left.Cxa variable */)  = 0.2995;
  TRACE_POP
}

/*
equation index: 296
type: SIMPLE_ASSIGN
tire_front_left.Cyk = 0.85
*/
void KIMM_CAR_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  (data->localData[0]->realVars[279]/* tire_front_left.Cyk variable */)  = 0.85;
  TRACE_POP
}

/*
equation index: 297
type: SIMPLE_ASSIGN
tire_front_left.brake_spring_coefficient = 15000.0
*/
void KIMM_CAR_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  (data->localData[0]->realVars[289]/* tire_front_left.brake_spring_coefficient variable */)  = 15000.0;
  TRACE_POP
}

/*
equation index: 298
type: SIMPLE_ASSIGN
tire_front_left.brake_damper_coefficient = 100.0
*/
void KIMM_CAR_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  (data->localData[0]->realVars[285]/* tire_front_left.brake_damper_coefficient variable */)  = 100.0;
  TRACE_POP
}

/*
equation index: 299
type: SIMPLE_ASSIGN
tire_front_left.brake_mass = 0.1
*/
void KIMM_CAR_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  (data->localData[0]->realVars[287]/* tire_front_left.brake_mass variable */)  = 0.1;
  TRACE_POP
}

/*
equation index: 300
type: SIMPLE_ASSIGN
tire_front_right.Cx = 1.579
*/
void KIMM_CAR_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  (data->localData[0]->realVars[310]/* tire_front_right.Cx variable */)  = 1.579;
  TRACE_POP
}

/*
equation index: 301
type: SIMPLE_ASSIGN
tire_front_right.Cy = 1.338
*/
void KIMM_CAR_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  (data->localData[0]->realVars[312]/* tire_front_right.Cy variable */)  = 1.338;
  TRACE_POP
}

/*
equation index: 302
type: SIMPLE_ASSIGN
tire_front_right.Cxa = 0.2995
*/
void KIMM_CAR_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  (data->localData[0]->realVars[311]/* tire_front_right.Cxa variable */)  = 0.2995;
  TRACE_POP
}

/*
equation index: 303
type: SIMPLE_ASSIGN
tire_front_right.Cyk = 0.85
*/
void KIMM_CAR_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  (data->localData[0]->realVars[313]/* tire_front_right.Cyk variable */)  = 0.85;
  TRACE_POP
}

/*
equation index: 304
type: SIMPLE_ASSIGN
tire_front_right.brake_spring_coefficient = 15000.0
*/
void KIMM_CAR_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  (data->localData[0]->realVars[323]/* tire_front_right.brake_spring_coefficient variable */)  = 15000.0;
  TRACE_POP
}

/*
equation index: 305
type: SIMPLE_ASSIGN
tire_front_right.brake_damper_coefficient = 100.0
*/
void KIMM_CAR_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  (data->localData[0]->realVars[319]/* tire_front_right.brake_damper_coefficient variable */)  = 100.0;
  TRACE_POP
}

/*
equation index: 306
type: SIMPLE_ASSIGN
tire_front_right.brake_mass = 0.1
*/
void KIMM_CAR_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  (data->localData[0]->realVars[321]/* tire_front_right.brake_mass variable */)  = 0.1;
  TRACE_POP
}

/*
equation index: 307
type: SIMPLE_ASSIGN
tire_rear_right.Cx = 1.579
*/
void KIMM_CAR_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
  (data->localData[0]->realVars[378]/* tire_rear_right.Cx variable */)  = 1.579;
  TRACE_POP
}

/*
equation index: 308
type: SIMPLE_ASSIGN
tire_rear_right.Cy = 1.338
*/
void KIMM_CAR_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  (data->localData[0]->realVars[380]/* tire_rear_right.Cy variable */)  = 1.338;
  TRACE_POP
}

/*
equation index: 309
type: SIMPLE_ASSIGN
tire_rear_right.Cxa = 0.2995
*/
void KIMM_CAR_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  (data->localData[0]->realVars[379]/* tire_rear_right.Cxa variable */)  = 0.2995;
  TRACE_POP
}

/*
equation index: 310
type: SIMPLE_ASSIGN
tire_rear_right.Cyk = 0.85
*/
void KIMM_CAR_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  (data->localData[0]->realVars[381]/* tire_rear_right.Cyk variable */)  = 0.85;
  TRACE_POP
}

/*
equation index: 311
type: SIMPLE_ASSIGN
tire_rear_right.brake_spring_coefficient = 15000.0
*/
void KIMM_CAR_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  (data->localData[0]->realVars[391]/* tire_rear_right.brake_spring_coefficient variable */)  = 15000.0;
  TRACE_POP
}

/*
equation index: 312
type: SIMPLE_ASSIGN
tire_rear_right.brake_damper_coefficient = 100.0
*/
void KIMM_CAR_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
  (data->localData[0]->realVars[387]/* tire_rear_right.brake_damper_coefficient variable */)  = 100.0;
  TRACE_POP
}

/*
equation index: 313
type: SIMPLE_ASSIGN
tire_rear_right.brake_mass = 0.1
*/
void KIMM_CAR_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
  (data->localData[0]->realVars[389]/* tire_rear_right.brake_mass variable */)  = 0.1;
  TRACE_POP
}

/*
equation index: 314
type: SIMPLE_ASSIGN
tire_rear_left.Cx = 1.579
*/
void KIMM_CAR_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  (data->localData[0]->realVars[344]/* tire_rear_left.Cx variable */)  = 1.579;
  TRACE_POP
}

/*
equation index: 315
type: SIMPLE_ASSIGN
tire_rear_left.Cy = 1.338
*/
void KIMM_CAR_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  (data->localData[0]->realVars[346]/* tire_rear_left.Cy variable */)  = 1.338;
  TRACE_POP
}

/*
equation index: 316
type: SIMPLE_ASSIGN
tire_rear_left.Cxa = 0.2995
*/
void KIMM_CAR_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  (data->localData[0]->realVars[345]/* tire_rear_left.Cxa variable */)  = 0.2995;
  TRACE_POP
}

/*
equation index: 317
type: SIMPLE_ASSIGN
tire_rear_left.Cyk = 0.85
*/
void KIMM_CAR_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  (data->localData[0]->realVars[347]/* tire_rear_left.Cyk variable */)  = 0.85;
  TRACE_POP
}

/*
equation index: 318
type: SIMPLE_ASSIGN
tire_rear_left.brake_spring_coefficient = 15000.0
*/
void KIMM_CAR_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  (data->localData[0]->realVars[357]/* tire_rear_left.brake_spring_coefficient variable */)  = 15000.0;
  TRACE_POP
}

/*
equation index: 319
type: SIMPLE_ASSIGN
tire_rear_left.brake_damper_coefficient = 100.0
*/
void KIMM_CAR_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  (data->localData[0]->realVars[353]/* tire_rear_left.brake_damper_coefficient variable */)  = 100.0;
  TRACE_POP
}

/*
equation index: 320
type: SIMPLE_ASSIGN
tire_rear_left.brake_mass = 0.1
*/
void KIMM_CAR_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  (data->localData[0]->realVars[355]/* tire_rear_left.brake_mass variable */)  = 0.1;
  TRACE_POP
}

/*
equation index: 321
type: SIMPLE_ASSIGN
realExpression4.y = 0.0
*/
void KIMM_CAR_eqFunction_321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,321};
  (data->localData[0]->realVars[254]/* realExpression4.y variable */)  = 0.0;
  TRACE_POP
}

/*
equation index: 322
type: SIMPLE_ASSIGN
realExpression5.y = 0.0
*/
void KIMM_CAR_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  (data->localData[0]->realVars[255]/* realExpression5.y variable */)  = 0.0;
  TRACE_POP
}

/*
equation index: 323
type: SIMPLE_ASSIGN
rear_open_differential.Gear_Ratio = 10.649678
*/
void KIMM_CAR_eqFunction_323(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,323};
  (data->localData[0]->realVars[256]/* rear_open_differential.Gear_Ratio variable */)  = 10.649678;
  TRACE_POP
}

/*
equation index: 324
type: SIMPLE_ASSIGN
rear_open_differential.rad_per_sec_to_rpm = 9.54929658551373
*/
void KIMM_CAR_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,324};
  (data->localData[0]->realVars[258]/* rear_open_differential.rad_per_sec_to_rpm variable */)  = 9.54929658551373;
  TRACE_POP
}

/*
equation index: 325
type: SIMPLE_ASSIGN
ackerman_Steering_Model.tread_front = 1.64084
*/
void KIMM_CAR_eqFunction_325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,325};
  (data->localData[0]->realVars[137]/* ackerman_Steering_Model.tread_front variable */)  = 1.64084;
  TRACE_POP
}

/*
equation index: 326
type: SIMPLE_ASSIGN
ackerman_Steering_Model.pi = 3.14159265358979
*/
void KIMM_CAR_eqFunction_326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,326};
  (data->localData[0]->realVars[128]/* ackerman_Steering_Model.pi variable */)  = 3.14159265358979;
  TRACE_POP
}

/*
equation index: 327
type: SIMPLE_ASSIGN
ackerman_Steering_Model.steer_spring_coefficient = 35000.0
*/
void KIMM_CAR_eqFunction_327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,327};
  (data->localData[0]->realVars[134]/* ackerman_Steering_Model.steer_spring_coefficient variable */)  = 35000.0;
  TRACE_POP
}

/*
equation index: 328
type: SIMPLE_ASSIGN
ackerman_Steering_Model.steer_damper_coefficient = 100.0
*/
void KIMM_CAR_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  (data->localData[0]->realVars[132]/* ackerman_Steering_Model.steer_damper_coefficient variable */)  = 100.0;
  TRACE_POP
}

/*
equation index: 329
type: SIMPLE_ASSIGN
ackerman_Steering_Model.steer_inertia = 0.1
*/
void KIMM_CAR_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  (data->localData[0]->realVars[133]/* ackerman_Steering_Model.steer_inertia variable */)  = 0.1;
  TRACE_POP
}

/*
equation index: 330
type: SIMPLE_ASSIGN
ackerman_Steering_Model.D = 0.3
*/
void KIMM_CAR_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  (data->localData[0]->realVars[117]/* ackerman_Steering_Model.D variable */)  = 0.3;
  TRACE_POP
}

/*
equation index: 331
type: SIMPLE_ASSIGN
ackerman_Steering_Model.l_rack = 1.04084
*/
void KIMM_CAR_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  (data->localData[0]->realVars[124]/* ackerman_Steering_Model.l_rack variable */)  = 1.04084;
  TRACE_POP
}

/*
equation index: 332
type: SIMPLE_ASSIGN
ackerman_Steering_Model.l_rod = 0.45
*/
void KIMM_CAR_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  (data->localData[0]->realVars[125]/* ackerman_Steering_Model.l_rod variable */)  = 0.45;
  TRACE_POP
}

/*
equation index: 333
type: SIMPLE_ASSIGN
ackerman_Steering_Model.l_arm = 0.35514
*/
void KIMM_CAR_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,333};
  (data->localData[0]->realVars[123]/* ackerman_Steering_Model.l_arm variable */)  = 0.35514;
  TRACE_POP
}

/*
equation index: 334
type: SIMPLE_ASSIGN
ackerman_Steering_Model.pinion_radius = 0.03067
*/
void KIMM_CAR_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  (data->localData[0]->realVars[129]/* ackerman_Steering_Model.pinion_radius variable */)  = 0.03067;
  TRACE_POP
}

/*
equation index: 335
type: SIMPLE_ASSIGN
ackerman_Steering_Model.neutral_tilt_angle = 0.434358023466495
*/
void KIMM_CAR_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  (data->localData[0]->realVars[127]/* ackerman_Steering_Model.neutral_tilt_angle variable */)  = 0.434358023466495;
  TRACE_POP
}
OMC_DISABLE_OPT
void KIMM_CAR_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  KIMM_CAR_eqFunction_1(data, threadData);
  KIMM_CAR_eqFunction_2(data, threadData);
  KIMM_CAR_eqFunction_3(data, threadData);
  KIMM_CAR_eqFunction_4(data, threadData);
  KIMM_CAR_eqFunction_5(data, threadData);
  KIMM_CAR_eqFunction_6(data, threadData);
  KIMM_CAR_eqFunction_7(data, threadData);
  KIMM_CAR_eqFunction_8(data, threadData);
  KIMM_CAR_eqFunction_9(data, threadData);
  KIMM_CAR_eqFunction_10(data, threadData);
  KIMM_CAR_eqFunction_11(data, threadData);
  KIMM_CAR_eqFunction_12(data, threadData);
  KIMM_CAR_eqFunction_13(data, threadData);
  KIMM_CAR_eqFunction_14(data, threadData);
  KIMM_CAR_eqFunction_15(data, threadData);
  KIMM_CAR_eqFunction_16(data, threadData);
  KIMM_CAR_eqFunction_17(data, threadData);
  KIMM_CAR_eqFunction_18(data, threadData);
  KIMM_CAR_eqFunction_19(data, threadData);
  KIMM_CAR_eqFunction_20(data, threadData);
  KIMM_CAR_eqFunction_21(data, threadData);
  KIMM_CAR_eqFunction_22(data, threadData);
  KIMM_CAR_eqFunction_23(data, threadData);
  KIMM_CAR_eqFunction_24(data, threadData);
  KIMM_CAR_eqFunction_25(data, threadData);
  KIMM_CAR_eqFunction_26(data, threadData);
  KIMM_CAR_eqFunction_27(data, threadData);
  KIMM_CAR_eqFunction_28(data, threadData);
  KIMM_CAR_eqFunction_29(data, threadData);
  KIMM_CAR_eqFunction_30(data, threadData);
  KIMM_CAR_eqFunction_31(data, threadData);
  KIMM_CAR_eqFunction_32(data, threadData);
  KIMM_CAR_eqFunction_33(data, threadData);
  KIMM_CAR_eqFunction_34(data, threadData);
  KIMM_CAR_eqFunction_35(data, threadData);
  KIMM_CAR_eqFunction_36(data, threadData);
  KIMM_CAR_eqFunction_37(data, threadData);
  KIMM_CAR_eqFunction_344(data, threadData);
  KIMM_CAR_eqFunction_345(data, threadData);
  KIMM_CAR_eqFunction_346(data, threadData);
  KIMM_CAR_eqFunction_347(data, threadData);
  KIMM_CAR_eqFunction_42(data, threadData);
  KIMM_CAR_eqFunction_337(data, threadData);
  KIMM_CAR_eqFunction_336(data, threadData);
  KIMM_CAR_eqFunction_45(data, threadData);
  KIMM_CAR_eqFunction_338(data, threadData);
  KIMM_CAR_eqFunction_47(data, threadData);
  KIMM_CAR_eqFunction_343(data, threadData);
  KIMM_CAR_eqFunction_49(data, threadData);
  KIMM_CAR_eqFunction_339(data, threadData);
  KIMM_CAR_eqFunction_51(data, threadData);
  KIMM_CAR_eqFunction_52(data, threadData);
  KIMM_CAR_eqFunction_53(data, threadData);
  KIMM_CAR_eqFunction_54(data, threadData);
  KIMM_CAR_eqFunction_55(data, threadData);
  KIMM_CAR_eqFunction_56(data, threadData);
  KIMM_CAR_eqFunction_57(data, threadData);
  KIMM_CAR_eqFunction_58(data, threadData);
  KIMM_CAR_eqFunction_59(data, threadData);
  KIMM_CAR_eqFunction_485(data, threadData);
  KIMM_CAR_eqFunction_61(data, threadData);
  KIMM_CAR_eqFunction_348(data, threadData);
  KIMM_CAR_eqFunction_464(data, threadData);
  KIMM_CAR_eqFunction_463(data, threadData);
  KIMM_CAR_eqFunction_462(data, threadData);
  KIMM_CAR_eqFunction_66(data, threadData);
  KIMM_CAR_eqFunction_340(data, threadData);
  KIMM_CAR_eqFunction_68(data, threadData);
  KIMM_CAR_eqFunction_69(data, threadData);
  KIMM_CAR_eqFunction_537(data, threadData);
  KIMM_CAR_eqFunction_71(data, threadData);
  KIMM_CAR_eqFunction_546(data, threadData);
  KIMM_CAR_eqFunction_73(data, threadData);
  KIMM_CAR_eqFunction_555(data, threadData);
  KIMM_CAR_eqFunction_75(data, threadData);
  KIMM_CAR_eqFunction_579(data, threadData);
  KIMM_CAR_eqFunction_341(data, threadData);
  KIMM_CAR_eqFunction_78(data, threadData);
  KIMM_CAR_eqFunction_486(data, threadData);
  KIMM_CAR_eqFunction_465(data, threadData);
  KIMM_CAR_eqFunction_487(data, threadData);
  KIMM_CAR_eqFunction_501(data, threadData);
  KIMM_CAR_eqFunction_470(data, threadData);
  KIMM_CAR_eqFunction_494(data, threadData);
  KIMM_CAR_eqFunction_342(data, threadData);
  KIMM_CAR_eqFunction_86(data, threadData);
  KIMM_CAR_eqFunction_479(data, threadData);
  KIMM_CAR_eqFunction_88(data, threadData);
  KIMM_CAR_eqFunction_477(data, threadData);
  KIMM_CAR_eqFunction_90(data, threadData);
  KIMM_CAR_eqFunction_481(data, threadData);
  KIMM_CAR_eqFunction_92(data, threadData);
  KIMM_CAR_eqFunction_483(data, threadData);
  KIMM_CAR_eqFunction_94(data, threadData);
  KIMM_CAR_eqFunction_354(data, threadData);
  KIMM_CAR_eqFunction_96(data, threadData);
  KIMM_CAR_eqFunction_358(data, threadData);
  KIMM_CAR_eqFunction_98(data, threadData);
  KIMM_CAR_eqFunction_375(data, threadData);
  KIMM_CAR_eqFunction_382(data, threadData);
  KIMM_CAR_eqFunction_383(data, threadData);
  KIMM_CAR_eqFunction_384(data, threadData);
  KIMM_CAR_eqFunction_385(data, threadData);
  KIMM_CAR_eqFunction_521(data, threadData);
  KIMM_CAR_eqFunction_105(data, threadData);
  KIMM_CAR_eqFunction_106(data, threadData);
  KIMM_CAR_eqFunction_519(data, threadData);
  KIMM_CAR_eqFunction_376(data, threadData);
  KIMM_CAR_eqFunction_377(data, threadData);
  KIMM_CAR_eqFunction_378(data, threadData);
  KIMM_CAR_eqFunction_379(data, threadData);
  KIMM_CAR_eqFunction_508(data, threadData);
  KIMM_CAR_eqFunction_113(data, threadData);
  KIMM_CAR_eqFunction_114(data, threadData);
  KIMM_CAR_eqFunction_506(data, threadData);
  KIMM_CAR_eqFunction_116(data, threadData);
  KIMM_CAR_eqFunction_374(data, threadData);
  KIMM_CAR_eqFunction_373(data, threadData);
  KIMM_CAR_eqFunction_119(data, threadData);
  KIMM_CAR_eqFunction_474(data, threadData);
  KIMM_CAR_eqFunction_366(data, threadData);
  KIMM_CAR_eqFunction_122(data, threadData);
  KIMM_CAR_eqFunction_365(data, threadData);
  KIMM_CAR_eqFunction_124(data, threadData);
  KIMM_CAR_eqFunction_368(data, threadData);
  KIMM_CAR_eqFunction_126(data, threadData);
  KIMM_CAR_eqFunction_367(data, threadData);
  KIMM_CAR_eqFunction_128(data, threadData);
  KIMM_CAR_eqFunction_530(data, threadData);
  KIMM_CAR_eqFunction_352(data, threadData);
  KIMM_CAR_eqFunction_131(data, threadData);
  KIMM_CAR_eqFunction_469(data, threadData);
  KIMM_CAR_eqFunction_369(data, threadData);
  KIMM_CAR_eqFunction_370(data, threadData);
  KIMM_CAR_eqFunction_371(data, threadData);
  KIMM_CAR_eqFunction_372(data, threadData);
  KIMM_CAR_eqFunction_362(data, threadData);
  KIMM_CAR_eqFunction_138(data, threadData);
  KIMM_CAR_eqFunction_361(data, threadData);
  KIMM_CAR_eqFunction_140(data, threadData);
  KIMM_CAR_eqFunction_364(data, threadData);
  KIMM_CAR_eqFunction_142(data, threadData);
  KIMM_CAR_eqFunction_363(data, threadData);
  KIMM_CAR_eqFunction_144(data, threadData);
  KIMM_CAR_eqFunction_539(data, threadData);
  KIMM_CAR_eqFunction_351(data, threadData);
  KIMM_CAR_eqFunction_147(data, threadData);
  KIMM_CAR_eqFunction_357(data, threadData);
  KIMM_CAR_eqFunction_149(data, threadData);
  KIMM_CAR_eqFunction_360(data, threadData);
  KIMM_CAR_eqFunction_151(data, threadData);
  KIMM_CAR_eqFunction_359(data, threadData);
  KIMM_CAR_eqFunction_153(data, threadData);
  KIMM_CAR_eqFunction_548(data, threadData);
  KIMM_CAR_eqFunction_349(data, threadData);
  KIMM_CAR_eqFunction_156(data, threadData);
  KIMM_CAR_eqFunction_353(data, threadData);
  KIMM_CAR_eqFunction_158(data, threadData);
  KIMM_CAR_eqFunction_356(data, threadData);
  KIMM_CAR_eqFunction_160(data, threadData);
  KIMM_CAR_eqFunction_355(data, threadData);
  KIMM_CAR_eqFunction_162(data, threadData);
  KIMM_CAR_eqFunction_557(data, threadData);
  KIMM_CAR_eqFunction_350(data, threadData);
  KIMM_CAR_eqFunction_165(data, threadData);
  KIMM_CAR_eqFunction_166(data, threadData);
  KIMM_CAR_eqFunction_495(data, threadData);
  KIMM_CAR_eqFunction_496(data, threadData);
  KIMM_CAR_eqFunction_471(data, threadData);
  KIMM_CAR_eqFunction_472(data, threadData);
  KIMM_CAR_eqFunction_473(data, threadData);
  KIMM_CAR_eqFunction_172(data, threadData);
  KIMM_CAR_eqFunction_396(data, threadData);
  KIMM_CAR_eqFunction_174(data, threadData);
  KIMM_CAR_eqFunction_536(data, threadData);
  KIMM_CAR_eqFunction_397(data, threadData);
  KIMM_CAR_eqFunction_399(data, threadData);
  KIMM_CAR_eqFunction_402(data, threadData);
  KIMM_CAR_eqFunction_403(data, threadData);
  KIMM_CAR_eqFunction_500(data, threadData);
  KIMM_CAR_eqFunction_398(data, threadData);
  KIMM_CAR_eqFunction_400(data, threadData);
  KIMM_CAR_eqFunction_401(data, threadData);
  KIMM_CAR_eqFunction_497(data, threadData);
  KIMM_CAR_eqFunction_498(data, threadData);
  KIMM_CAR_eqFunction_499(data, threadData);
  KIMM_CAR_eqFunction_533(data, threadData);
  KIMM_CAR_eqFunction_532(data, threadData);
  KIMM_CAR_eqFunction_531(data, threadData);
  KIMM_CAR_eqFunction_534(data, threadData);
  KIMM_CAR_eqFunction_404(data, threadData);
  KIMM_CAR_eqFunction_192(data, threadData);
  KIMM_CAR_eqFunction_193(data, threadData);
  KIMM_CAR_eqFunction_488(data, threadData);
  KIMM_CAR_eqFunction_489(data, threadData);
  KIMM_CAR_eqFunction_466(data, threadData);
  KIMM_CAR_eqFunction_467(data, threadData);
  KIMM_CAR_eqFunction_468(data, threadData);
  KIMM_CAR_eqFunction_199(data, threadData);
  KIMM_CAR_eqFunction_413(data, threadData);
  KIMM_CAR_eqFunction_201(data, threadData);
  KIMM_CAR_eqFunction_545(data, threadData);
  KIMM_CAR_eqFunction_414(data, threadData);
  KIMM_CAR_eqFunction_416(data, threadData);
  KIMM_CAR_eqFunction_419(data, threadData);
  KIMM_CAR_eqFunction_420(data, threadData);
  KIMM_CAR_eqFunction_493(data, threadData);
  KIMM_CAR_eqFunction_415(data, threadData);
  KIMM_CAR_eqFunction_417(data, threadData);
  KIMM_CAR_eqFunction_418(data, threadData);
  KIMM_CAR_eqFunction_490(data, threadData);
  KIMM_CAR_eqFunction_491(data, threadData);
  KIMM_CAR_eqFunction_492(data, threadData);
  KIMM_CAR_eqFunction_542(data, threadData);
  KIMM_CAR_eqFunction_541(data, threadData);
  KIMM_CAR_eqFunction_540(data, threadData);
  KIMM_CAR_eqFunction_543(data, threadData);
  KIMM_CAR_eqFunction_421(data, threadData);
  KIMM_CAR_eqFunction_219(data, threadData);
  KIMM_CAR_eqFunction_220(data, threadData);
  KIMM_CAR_eqFunction_509(data, threadData);
  KIMM_CAR_eqFunction_510(data, threadData);
  KIMM_CAR_eqFunction_503(data, threadData);
  KIMM_CAR_eqFunction_504(data, threadData);
  KIMM_CAR_eqFunction_505(data, threadData);
  KIMM_CAR_eqFunction_226(data, threadData);
  KIMM_CAR_eqFunction_430(data, threadData);
  KIMM_CAR_eqFunction_228(data, threadData);
  KIMM_CAR_eqFunction_554(data, threadData);
  KIMM_CAR_eqFunction_431(data, threadData);
  KIMM_CAR_eqFunction_433(data, threadData);
  KIMM_CAR_eqFunction_436(data, threadData);
  KIMM_CAR_eqFunction_437(data, threadData);
  KIMM_CAR_eqFunction_514(data, threadData);
  KIMM_CAR_eqFunction_432(data, threadData);
  KIMM_CAR_eqFunction_434(data, threadData);
  KIMM_CAR_eqFunction_435(data, threadData);
  KIMM_CAR_eqFunction_511(data, threadData);
  KIMM_CAR_eqFunction_512(data, threadData);
  KIMM_CAR_eqFunction_513(data, threadData);
  KIMM_CAR_eqFunction_551(data, threadData);
  KIMM_CAR_eqFunction_550(data, threadData);
  KIMM_CAR_eqFunction_549(data, threadData);
  KIMM_CAR_eqFunction_552(data, threadData);
  KIMM_CAR_eqFunction_438(data, threadData);
  KIMM_CAR_eqFunction_246(data, threadData);
  KIMM_CAR_eqFunction_247(data, threadData);
  KIMM_CAR_eqFunction_522(data, threadData);
  KIMM_CAR_eqFunction_523(data, threadData);
  KIMM_CAR_eqFunction_516(data, threadData);
  KIMM_CAR_eqFunction_517(data, threadData);
  KIMM_CAR_eqFunction_518(data, threadData);
  KIMM_CAR_eqFunction_253(data, threadData);
  KIMM_CAR_eqFunction_447(data, threadData);
  KIMM_CAR_eqFunction_255(data, threadData);
  KIMM_CAR_eqFunction_578(data, threadData);
  KIMM_CAR_eqFunction_448(data, threadData);
  KIMM_CAR_eqFunction_450(data, threadData);
  KIMM_CAR_eqFunction_453(data, threadData);
  KIMM_CAR_eqFunction_454(data, threadData);
  KIMM_CAR_eqFunction_527(data, threadData);
  KIMM_CAR_eqFunction_449(data, threadData);
  KIMM_CAR_eqFunction_451(data, threadData);
  KIMM_CAR_eqFunction_452(data, threadData);
  KIMM_CAR_eqFunction_524(data, threadData);
  KIMM_CAR_eqFunction_525(data, threadData);
  KIMM_CAR_eqFunction_526(data, threadData);
  KIMM_CAR_eqFunction_566(data, threadData);
  KIMM_CAR_eqFunction_567(data, threadData);
  KIMM_CAR_eqFunction_562(data, threadData);
  KIMM_CAR_eqFunction_563(data, threadData);
  KIMM_CAR_eqFunction_558(data, threadData);
  KIMM_CAR_eqFunction_572(data, threadData);
  KIMM_CAR_eqFunction_573(data, threadData);
  KIMM_CAR_eqFunction_574(data, threadData);
  KIMM_CAR_eqFunction_576(data, threadData);
  KIMM_CAR_eqFunction_575(data, threadData);
  KIMM_CAR_eqFunction_559(data, threadData);
  KIMM_CAR_eqFunction_455(data, threadData);
  KIMM_CAR_eqFunction_280(data, threadData);
  KIMM_CAR_eqFunction_568(data, threadData);
  KIMM_CAR_eqFunction_571(data, threadData);
  KIMM_CAR_eqFunction_564(data, threadData);
  KIMM_CAR_eqFunction_565(data, threadData);
  KIMM_CAR_eqFunction_560(data, threadData);
  KIMM_CAR_eqFunction_286(data, threadData);
  KIMM_CAR_eqFunction_583(data, threadData);
  KIMM_CAR_eqFunction_288(data, threadData);
  KIMM_CAR_eqFunction_581(data, threadData);
  KIMM_CAR_eqFunction_290(data, threadData);
  KIMM_CAR_eqFunction_570(data, threadData);
  KIMM_CAR_eqFunction_561(data, threadData);
  KIMM_CAR_eqFunction_293(data, threadData);
  KIMM_CAR_eqFunction_294(data, threadData);
  KIMM_CAR_eqFunction_295(data, threadData);
  KIMM_CAR_eqFunction_296(data, threadData);
  KIMM_CAR_eqFunction_297(data, threadData);
  KIMM_CAR_eqFunction_298(data, threadData);
  KIMM_CAR_eqFunction_299(data, threadData);
  KIMM_CAR_eqFunction_300(data, threadData);
  KIMM_CAR_eqFunction_301(data, threadData);
  KIMM_CAR_eqFunction_302(data, threadData);
  KIMM_CAR_eqFunction_303(data, threadData);
  KIMM_CAR_eqFunction_304(data, threadData);
  KIMM_CAR_eqFunction_305(data, threadData);
  KIMM_CAR_eqFunction_306(data, threadData);
  KIMM_CAR_eqFunction_307(data, threadData);
  KIMM_CAR_eqFunction_308(data, threadData);
  KIMM_CAR_eqFunction_309(data, threadData);
  KIMM_CAR_eqFunction_310(data, threadData);
  KIMM_CAR_eqFunction_311(data, threadData);
  KIMM_CAR_eqFunction_312(data, threadData);
  KIMM_CAR_eqFunction_313(data, threadData);
  KIMM_CAR_eqFunction_314(data, threadData);
  KIMM_CAR_eqFunction_315(data, threadData);
  KIMM_CAR_eqFunction_316(data, threadData);
  KIMM_CAR_eqFunction_317(data, threadData);
  KIMM_CAR_eqFunction_318(data, threadData);
  KIMM_CAR_eqFunction_319(data, threadData);
  KIMM_CAR_eqFunction_320(data, threadData);
  KIMM_CAR_eqFunction_321(data, threadData);
  KIMM_CAR_eqFunction_322(data, threadData);
  KIMM_CAR_eqFunction_323(data, threadData);
  KIMM_CAR_eqFunction_324(data, threadData);
  KIMM_CAR_eqFunction_325(data, threadData);
  KIMM_CAR_eqFunction_326(data, threadData);
  KIMM_CAR_eqFunction_327(data, threadData);
  KIMM_CAR_eqFunction_328(data, threadData);
  KIMM_CAR_eqFunction_329(data, threadData);
  KIMM_CAR_eqFunction_330(data, threadData);
  KIMM_CAR_eqFunction_331(data, threadData);
  KIMM_CAR_eqFunction_332(data, threadData);
  KIMM_CAR_eqFunction_333(data, threadData);
  KIMM_CAR_eqFunction_334(data, threadData);
  KIMM_CAR_eqFunction_335(data, threadData);
  TRACE_POP
}

int KIMM_CAR_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  KIMM_CAR_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No KIMM_CAR_functionInitialEquations_lambda0 function */

int KIMM_CAR_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

