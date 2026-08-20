#ifndef KIMMCar_h_
#define KIMMCar_h_
#ifndef KIMMCar_COMMON_INCLUDES_
#define KIMMCar_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw_rtp.h"
#include "KIMMCar_ff62ad8f_1_gateway.h"
#include "nesl_rtw.h"
#include "RTWCG_FMU_util.h"
#endif

#include "KIMMCar_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeDeltaY
#define rtmGetOdeDeltaY(rtm)           ((rtm)->OdeDeltaY)
#endif

#ifndef rtmSetOdeDeltaY
#define rtmSetOdeDeltaY(rtm, val)      ((rtm)->OdeDeltaY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

typedef struct {
  real_T Gain7;
  real_T INPUT_7_1_1[4];
  real_T Add2;
  real_T INPUT_8_1_1[4];
  real_T Add;
  real_T INPUT_9_1_1[4];
  real_T Sum;
  real_T INPUT_14_1_1[4];
  real_T Gain;
  real_T INPUT_10_1_1[4];
  real_T Add3;
  real_T INPUT_11_1_1[4];
  real_T Add1;
  real_T INPUT_12_1_1[4];
  real_T Sum1;
  real_T INPUT_13_1_1[4];
  real_T Gain7_n;
  real_T INPUT_15_1_1[4];
  real_T Add2_k;
  real_T INPUT_16_1_1[4];
  real_T Add_b;
  real_T INPUT_17_1_1[4];
  real_T Gain3;
  real_T INPUT_21_1_1[4];
  real_T Gain_i;
  real_T INPUT_18_1_1[4];
  real_T Add3_p;
  real_T INPUT_19_1_1[4];
  real_T Add1_b;
  real_T INPUT_20_1_1[4];
  real_T Gain6;
  real_T INPUT_22_1_1[4];
  real_T px;
  real_T INPUT_23_1_1[4];
  real_T py;
  real_T INPUT_24_1_1[4];
  real_T pz;
  real_T INPUT_25_1_1[4];
  real_T qx;
  real_T INPUT_28_1_1[4];
  real_T qz;
  real_T INPUT_26_1_1[4];
  real_T qy;
  real_T INPUT_27_1_1[4];
  real_T px_h;
  real_T INPUT_31_1_1[4];
  real_T py_l;
  real_T INPUT_32_1_1[4];
  real_T pz_b;
  real_T INPUT_33_1_1[4];
  real_T qx_k;
  real_T INPUT_36_1_1[4];
  real_T qz_b;
  real_T INPUT_34_1_1[4];
  real_T qy_p;
  real_T INPUT_35_1_1[4];
  real_T px_m;
  real_T INPUT_39_1_1[4];
  real_T py_le;
  real_T INPUT_40_1_1[4];
  real_T pz_m;
  real_T INPUT_41_1_1[4];
  real_T qx_m;
  real_T INPUT_44_1_1[4];
  real_T qz_f;
  real_T INPUT_42_1_1[4];
  real_T qy_j;
  real_T INPUT_43_1_1[4];
  real_T px_f;
  real_T INPUT_47_1_1[4];
  real_T py_m;
  real_T INPUT_48_1_1[4];
  real_T pz_h;
  real_T INPUT_49_1_1[4];
  real_T qx_g;
  real_T INPUT_52_1_1[4];
  real_T qz_n;
  real_T INPUT_50_1_1[4];
  real_T qy_o;
  real_T INPUT_51_1_1[4];
  real_T RTP_1;
  real_T STATE_1[29];
  real_T OUTPUT_1_0[112];
  real_T Add_g;
  real_T Add1_o;
  real_T Gain6_f;
  real_T Gain8;
  real_T Atan1;
  real_T Atan1_l;
  real_T Atan1_i;
  real_T Atan1_k;
  real_T Sum_k;
  real_T Sum1_p;
  real_T Gain_g;
  real_T Gain1;
  real_T Sum_a;
  real_T Sum1_pm;
  real_T INPUT_3_1_1[4];
  real_T INPUT_4_1_1[4];
  real_T INPUT_5_1_1[4];
  real_T INPUT_6_1_1[4];
  real_T INPUT_1_1_1[4];
  real_T INPUT_2_1_1[4];
  real_T INPUT_29_1_1[4];
  real_T INPUT_30_1_1[4];
  real_T INPUT_37_1_1[4];
  real_T INPUT_38_1_1[4];
  real_T INPUT_45_1_1[4];
  real_T INPUT_46_1_1[4];
  real_T INPUT_53_1_1[4];
  real_T INPUT_54_1_1[4];
} B_KIMMCar_T;

typedef struct {
  real_T UnitDelay_DSTATE;
  real_T INPUT_7_1_1_Discrete;
  real_T INPUT_7_1_1_FirstOutput;
  real_T INPUT_8_1_1_Discrete;
  real_T INPUT_8_1_1_FirstOutput;
  real_T INPUT_9_1_1_Discrete;
  real_T INPUT_9_1_1_FirstOutput;
  real_T INPUT_14_1_1_Discrete;
  real_T INPUT_14_1_1_FirstOutput;
  real_T UnitDelay1_DSTATE;
  real_T INPUT_10_1_1_Discrete;
  real_T INPUT_10_1_1_FirstOutput;
  real_T INPUT_11_1_1_Discrete;
  real_T INPUT_11_1_1_FirstOutput;
  real_T INPUT_12_1_1_Discrete;
  real_T INPUT_12_1_1_FirstOutput;
  real_T INPUT_13_1_1_Discrete;
  real_T INPUT_13_1_1_FirstOutput;
  real_T UnitDelay_DSTATE_c;
  real_T INPUT_15_1_1_Discrete;
  real_T INPUT_15_1_1_FirstOutput;
  real_T INPUT_16_1_1_Discrete;
  real_T INPUT_16_1_1_FirstOutput;
  real_T INPUT_17_1_1_Discrete;
  real_T INPUT_17_1_1_FirstOutput;
  real_T INPUT_21_1_1_Discrete;
  real_T INPUT_21_1_1_FirstOutput;
  real_T UnitDelay1_DSTATE_e;
  real_T INPUT_18_1_1_Discrete;
  real_T INPUT_18_1_1_FirstOutput;
  real_T INPUT_19_1_1_Discrete;
  real_T INPUT_19_1_1_FirstOutput;
  real_T INPUT_20_1_1_Discrete;
  real_T INPUT_20_1_1_FirstOutput;
  real_T INPUT_22_1_1_Discrete;
  real_T INPUT_22_1_1_FirstOutput;
  real_T DiscreteTransferFcn1_states;
  real_T INPUT_23_1_1_Discrete[2];
  real_T DiscreteTransferFcn2_states;
  real_T INPUT_24_1_1_Discrete[2];
  real_T INPUT_25_1_1_Discrete[2];
  real_T INPUT_28_1_1_Discrete[2];
  real_T DiscreteTransferFcn3_states;
  real_T INPUT_26_1_1_Discrete[2];
  real_T INPUT_27_1_1_Discrete[2];
  real_T DiscreteTransferFcn1_states_e;
  real_T INPUT_31_1_1_Discrete[2];
  real_T DiscreteTransferFcn2_states_o;
  real_T INPUT_32_1_1_Discrete[2];
  real_T INPUT_33_1_1_Discrete[2];
  real_T INPUT_36_1_1_Discrete[2];
  real_T DiscreteTransferFcn3_states_k;
  real_T INPUT_34_1_1_Discrete[2];
  real_T INPUT_35_1_1_Discrete[2];
  real_T DiscreteTransferFcn1_states_i;
  real_T INPUT_39_1_1_Discrete[2];
  real_T DiscreteTransferFcn2_states_b;
  real_T INPUT_40_1_1_Discrete[2];
  real_T INPUT_41_1_1_Discrete[2];
  real_T INPUT_44_1_1_Discrete[2];
  real_T DiscreteTransferFcn3_states_n;
  real_T INPUT_42_1_1_Discrete[2];
  real_T INPUT_43_1_1_Discrete[2];
  real_T DiscreteTransferFcn1_states_g;
  real_T INPUT_47_1_1_Discrete[2];
  real_T DiscreteTransferFcn2_states_j;
  real_T INPUT_48_1_1_Discrete[2];
  real_T INPUT_49_1_1_Discrete[2];
  real_T INPUT_52_1_1_Discrete[2];
  real_T DiscreteTransferFcn3_states_n1;
  real_T INPUT_50_1_1_Discrete[2];
  real_T INPUT_51_1_1_Discrete[2];
  real_T UnitDelay_DSTATE_f;
  real_T UnitDelay_DSTATE_i[4];
  real_T UnitDelay1_1_DSTATE;
  real_T UnitDelay1_2_DSTATE;
  real_T UnitDelay1_3_DSTATE;
  real_T UnitDelay1_4_DSTATE;
  real_T INPUT_3_1_1_Discrete[2];
  real_T INPUT_4_1_1_Discrete[2];
  real_T INPUT_5_1_1_Discrete[2];
  real_T INPUT_6_1_1_Discrete[2];
  real_T INPUT_1_1_1_Discrete[2];
  real_T INPUT_2_1_1_Discrete[2];
  real_T INPUT_29_1_1_Discrete[2];
  real_T INPUT_30_1_1_Discrete[2];
  real_T INPUT_37_1_1_Discrete[2];
  real_T INPUT_38_1_1_Discrete[2];
  real_T INPUT_45_1_1_Discrete[2];
  real_T INPUT_46_1_1_Discrete[2];
  real_T INPUT_53_1_1_Discrete[2];
  real_T INPUT_54_1_1_Discrete[2];
  real_T STATE_1_Discrete;
  real_T STATE_1_ZcValueStore;
  real_T OUTPUT_1_0_Discrete;
  real_T OUTPUT_1_0_ZcValueStore;
  real_T PrevY;
  real_T PrevY_o;
  real_T OUTPUT_1_1_Discrete;
  real_T OUTPUT_1_1_ZcValueStore;
  real_T integratorState;
  real_T filteredVelocity;
  real_T absScale[4];
  real_T travelDirection;
  void* RTP_1_RtpManager;
  void* STATE_1_Simulator;
  void* STATE_1_SimData;
  void* STATE_1_DiagMgr;
  void* STATE_1_ZcLogger;
  void* STATE_1_TsInfo;
  void* OUTPUT_1_0_Simulator;
  void* OUTPUT_1_0_SimData;
  void* OUTPUT_1_0_DiagMgr;
  void* OUTPUT_1_0_ZcLogger;
  void* OUTPUT_1_0_TsInfo;
  void* SINK_1_RtwLogger;
  void* SINK_1_RtwLogBuffer;
  void* SINK_1_RtwLogFcnManager;
  void* SINK_1_InstRtwLogger;
  void* SINK_1_InstRtwLogBuffer;
  void* OUTPUT_1_1_Simulator;
  void* OUTPUT_1_1_SimData;
  void* OUTPUT_1_1_DiagMgr;
  void* OUTPUT_1_1_ZcLogger;
  void* OUTPUT_1_1_TsInfo;
  int_T STATE_1_Modes;
  int_T OUTPUT_1_0_Modes;
  int_T OUTPUT_1_1_Modes;
  uint8_T STATE_1_ZcSignalDir;
  uint8_T STATE_1_ZcStateStore;
  uint8_T OUTPUT_1_0_ZcSignalDir;
  uint8_T OUTPUT_1_0_ZcStateStore;
  uint8_T OUTPUT_1_1_ZcSignalDir;
  uint8_T OUTPUT_1_1_ZcStateStore;
  boolean_T RTP_1_SetParametersNeeded;
  boolean_T STATE_1_FirstOutput;
  boolean_T OUTPUT_1_0_FirstOutput;
  boolean_T OUTPUT_1_1_FirstOutput;
  boolean_T signGuardActive;
  boolean_T zeroGuard[4];
} DW_KIMMCar_T;

typedef struct {
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
    [2];
  real_T KIMMCarVehicleCamera_FramesCartesian_JointPxp[29];
} X_KIMMCar_T;

typedef struct {
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
    [2];
  real_T
    KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
    [2];
  real_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
    [2];
  real_T KIMMCarVehicleCamera_FramesCartesian_JointPxp[29];
} XDot_KIMMCar_T;

typedef struct {
  boolean_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
    [2];
  boolean_T
    KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
    [2];
  boolean_T KIMMCarVehicleCamera_FramesCartesian_JointPxp[29];
} XDis_KIMMCar_T;

#ifndef ODE8_INTG
#define ODE8_INTG

typedef struct {
  real_T *deltaY;
  real_T *f[13];
  real_T *x0;
} ODE8_IntgData;

#endif

typedef struct {
  real_T Steer_in;
  real_T Throttle;
  real_T Gear;
  real_T Brake;
  real_T pz;
  real_T qx;
  real_T qy;
  real_T pz_o;
  real_T qx_g;
  real_T qy_i;
  real_T pz_f;
  real_T qx_l;
  real_T qy_a;
  real_T pz_i;
  real_T qx_m;
  real_T qy_b;
} ExtU_KIMMCar_T;

typedef struct {
  real_T body_x;
  real_T body_y;
  real_T body_z;
  real_T body_q[4];
  real_T body_vx;
  real_T body_vy;
  real_T FLWheelOutput;
  real_T FRWheelOutput;
  real_T RLWheelOutput;
  real_T RRWheelOutput;
  real_T FL_x;
  real_T FL_y;
  real_T FL_z;
  real_T FR_x;
  real_T FR_y;
  real_T FR_z;
  real_T RL_x;
  real_T RL_y;
  real_T RL_z;
  real_T RR_x;
  real_T RR_y;
  real_T RR_z;
  real_T ToeLeft;
  real_T ToeRight;
} ExtY_KIMMCar_T;

struct P_KIMMCar_T_ {
  real_T SuspensionRear_lUnsprungMass;
  real_T SuspensionFront_lUnsprungMass;
  real_T LookupwithLinearPointslopeInterpolation_tableData[4];
  real_T LookupwithLinearPointslopeInterpolation_bp01Data[4];
  real_T LookupwithLinearPointslopeInterpolation1_tableData[4];
  real_T LookupwithLinearPointslopeInterpolation1_bp01Data[4];
  real_T UnitDelay_InitialCondition;
  real_T camber_tableData[22];
  real_T camber_bp01Data[22];
  real_T Gain7_Gain;
  real_T LookupwithLinearLagrangeInterpolation_tableData[22];
  real_T LookupwithLinearLagrangeInterpolation_bp01Data[22];
  real_T Gain1_Gain;
  real_T LookupwithLinearLagrangeInterpolation1_tableData[22];
  real_T LookupwithLinearLagrangeInterpolation1_bp01Data[22];
  real_T Gain2_Gain;
  real_T toe_tableData[22];
  real_T toe_bp01Data[22];
  real_T Gain3_Gain;
  real_T unitiydirection_Gain;
  real_T UnitDelay1_InitialCondition;
  real_T camber1_tableData[22];
  real_T camber1_bp01Data[22];
  real_T Gain_Gain;
  real_T LookupwithLinearLagrangeInterpolation2_tableData[22];
  real_T LookupwithLinearLagrangeInterpolation2_bp01Data[22];
  real_T Gain4_Gain;
  real_T LookupwithLinearLagrangeInterpolation3_tableData[22];
  real_T LookupwithLinearLagrangeInterpolation3_bp01Data[22];
  real_T Gain5_Gain;
  real_T toe1_tableData[22];
  real_T toe1_bp01Data[22];
  real_T Gain6_Gain;
  real_T UnitDelay_InitialCondition_a;
  real_T camber_tableData_b[68];
  real_T camber_bp01Data_o[68];
  real_T Gain7_Gain_m;
  real_T LookupwithLinearLagrangeInterpolation_tableData_p[68];
  real_T LookupwithLinearLagrangeInterpolation_bp01Data_o[68];
  real_T Gain1_Gain_b;
  real_T LookupwithLinearLagrangeInterpolation1_tableData_d[68];
  real_T LookupwithLinearLagrangeInterpolation1_bp01Data_n[68];
  real_T Gain2_Gain_k;
  real_T toe_tableData_d[68];
  real_T toe_bp01Data_d[68];
  real_T Gain3_Gain_n;
  real_T UnitDelay1_InitialCondition_f;
  real_T camber1_tableData_a[68];
  real_T camber1_bp01Data_h[68];
  real_T Gain_Gain_f;
  real_T LookupwithLinearLagrangeInterpolation2_tableData_c[68];
  real_T LookupwithLinearLagrangeInterpolation2_bp01Data_a[68];
  real_T Gain4_Gain_o;
  real_T LookupwithLinearLagrangeInterpolation3_tableData_i[68];
  real_T LookupwithLinearLagrangeInterpolation3_bp01Data_n[68];
  real_T Gain5_Gain_j;
  real_T toe1_tableData_d[68];
  real_T toe1_bp01Data_h[68];
  real_T Gain6_Gain_g;
  real_T DiscreteTransferFcn1_NumCoef;
  real_T DiscreteTransferFcn1_DenCoef[2];
  real_T DiscreteTransferFcn1_InitialStates;
  real_T Constant_Value;
  real_T Constant1_Value;
  real_T DiscreteTransferFcn2_NumCoef;
  real_T DiscreteTransferFcn2_DenCoef[2];
  real_T DiscreteTransferFcn2_InitialStates;
  real_T Constant2_Value;
  real_T Constant3_Value;
  real_T DiscreteTransferFcn3_NumCoef;
  real_T DiscreteTransferFcn3_DenCoef[2];
  real_T DiscreteTransferFcn3_InitialStates;
  real_T DiscreteTransferFcn1_NumCoef_c;
  real_T DiscreteTransferFcn1_DenCoef_e[2];
  real_T DiscreteTransferFcn1_InitialStates_b;
  real_T Constant_Value_h;
  real_T Constant1_Value_c;
  real_T DiscreteTransferFcn2_NumCoef_b;
  real_T DiscreteTransferFcn2_DenCoef_l[2];
  real_T DiscreteTransferFcn2_InitialStates_o;
  real_T Constant2_Value_i;
  real_T Constant3_Value_p;
  real_T DiscreteTransferFcn3_NumCoef_i;
  real_T DiscreteTransferFcn3_DenCoef_d[2];
  real_T DiscreteTransferFcn3_InitialStates_k;
  real_T DiscreteTransferFcn1_NumCoef_l;
  real_T DiscreteTransferFcn1_DenCoef_o[2];
  real_T DiscreteTransferFcn1_InitialStates_f;
  real_T Constant_Value_k;
  real_T Constant1_Value_a;
  real_T DiscreteTransferFcn2_NumCoef_n;
  real_T DiscreteTransferFcn2_DenCoef_p[2];
  real_T DiscreteTransferFcn2_InitialStates_g;
  real_T Constant2_Value_h;
  real_T Constant3_Value_f;
  real_T DiscreteTransferFcn3_NumCoef_i0;
  real_T DiscreteTransferFcn3_DenCoef_j[2];
  real_T DiscreteTransferFcn3_InitialStates_kk;
  real_T DiscreteTransferFcn1_NumCoef_e;
  real_T DiscreteTransferFcn1_DenCoef_a[2];
  real_T DiscreteTransferFcn1_InitialStates_l;
  real_T Constant_Value_b;
  real_T Constant1_Value_h;
  real_T DiscreteTransferFcn2_NumCoef_p;
  real_T DiscreteTransferFcn2_DenCoef_j[2];
  real_T DiscreteTransferFcn2_InitialStates_p;
  real_T Constant2_Value_j;
  real_T Constant3_Value_k;
  real_T DiscreteTransferFcn3_NumCoef_g;
  real_T DiscreteTransferFcn3_DenCoef_k[2];
  real_T DiscreteTransferFcn3_InitialStates_e;
  real_T RTP_041AAD1B_VelocityTargetValue_Value;
  real_T RTP_087BC81F_VelocityTargetValue_Value;
  real_T RTP_0ABA0B7C_RotationAngle_Value;
  real_T RTP_0ABA0B7C_TranslationStandardOffset_Value;
  real_T RTP_15BC236D_CylinderRadius_Value;
  real_T RTP_2D46EB53_TranslationCartesianOffset_Value[3];
  real_T RTP_5BD4A88C_VelocityTargetValue_Value;
  real_T RTP_6A570A4D_CylinderRadius_Value;
  real_T RTP_6D3ACE54_CylinderRadius_Value;
  real_T RTP_73B42110_TranslationCartesianOffset_Value[3];
  real_T RTP_73B42110_TranslationStandardOffset_Value;
  real_T RTP_7DBD3BEA_CenterOfMass_Value[3];
  real_T RTP_7DBD3BEA_Mass_Value;
  real_T RTP_7DBD3BEA_MomentsOfInertia_Value[3];
  real_T RTP_7DBD3BEA_ProductsOfInertia_Value[3];
  real_T RTP_9CB22C5A_VelocityTargetValue_Value;
  real_T RTP_A11E2A99_RotationAngle_Value;
  real_T RTP_A11E2A99_TranslationStandardOffset_Value;
  real_T RTP_A5036385_CenterOfMass_Value[3];
  real_T RTP_A5036385_Mass_Value;
  real_T RTP_A5036385_MomentsOfInertia_Value[3];
  real_T RTP_A5036385_ProductsOfInertia_Value[3];
  real_T RTP_B27877C6_CenterOfMass_Value[3];
  real_T RTP_B27877C6_Mass_Value;
  real_T RTP_B27877C6_MomentsOfInertia_Value[3];
  real_T RTP_B27877C6_ProductsOfInertia_Value[3];
  real_T RTP_C019A91A_TranslationCartesianOffset_Value[3];
  real_T RTP_C019A91A_TranslationStandardOffset_Value;
  real_T RTP_C57F4750_RotationAngle_Value;
  real_T RTP_C57F4750_TranslationStandardOffset_Value;
  real_T RTP_D2045313_RotationAngle_Value;
  real_T RTP_D2045313_TranslationStandardOffset_Value;
  real_T RTP_D6191A0F_CenterOfMass_Value[3];
  real_T RTP_D6191A0F_Mass_Value;
  real_T RTP_D6191A0F_MomentsOfInertia_Value[3];
  real_T RTP_D6191A0F_ProductsOfInertia_Value[3];
  real_T RTP_F6ED1E1D_CylinderRadius_Value;
  real_T Gain_Gain_j;
  real_T Gain_Gain_fv;
  real_T Gain_Gain_m;
  real_T Gain_Gain_k;
  real_T Gain_Gain_g;
  real_T unitydir_Gain;
  real_T unitydir1_Gain;
  real_T FL_Lmux_Value;
  real_T FL_Lmuy_Value;
  real_T FR_Lmux_Value;
  real_T FR_Lmuy_Value;
  real_T RL_Lmux_Value;
  real_T RL_Lmuy_Value;
  real_T RR_Lmux_Value;
  real_T RR_Lmuy_Value;
  real_T UnitDelay_InitialCondition_i;
  real_T UnitDelay_InitialCondition_f;
  real_T UnitDelay1_1_InitialCondition;
  real_T UnitDelay1_2_InitialCondition;
  real_T UnitDelay1_3_InitialCondition;
  real_T UnitDelay1_4_InitialCondition;
  real_T Brake_Rate_Limiter_RisingLim;
  real_T Brake_Rate_Limiter_FallingLim;
  real_T Brake_Rate_Limiter_IC;
  real_T Parking_Demand_Vector_Gain[4];
  real_T Brake_Demand_Vector_Limit_UpperSat;
  real_T Brake_Demand_Vector_Limit_LowerSat;
  real_T Gain5_Gain_b;
  real_T Gain_Gain_d;
  real_T RateLimiter_RisingLim;
  real_T RateLimiter_FallingLim;
  real_T RateLimiter_IC;
  real_T Switch_Threshold;
  real_T Gain1_Gain_d;
  real_T Gain2_Gain_p;
  real_T Gain7_Gain_b;
  real_T Gain6_Gain_d;
  real_T Gain8_Gain;
  real_T Constant_Value_n;
  real_T Constant1_Value_m;
  real_T Constant_Value_p;
  real_T Constant1_Value_o;
};

struct tag_RTM_KIMMCar_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_KIMMCar_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_KIMMCar_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T OdeDeltaY[61];
  real_T odeF[13][61];
  real_T odeX0[61];
  ODE8_IntgData intgData;
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[3];
      uint8_T cLimit[3];
    } TaskCounters;

    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

extern P_KIMMCar_T KIMMCar_P;
extern B_KIMMCar_T KIMMCar_B;
extern X_KIMMCar_T KIMMCar_X;
extern XDis_KIMMCar_T KIMMCar_XDis;
extern DW_KIMMCar_T KIMMCar_DW;
extern ExtU_KIMMCar_T KIMMCar_U;
extern ExtY_KIMMCar_T KIMMCar_Y;
extern real_T Veh_AeroArea;
extern real_T Veh_AeroCd;
extern real_T Veh_AeroCl;
extern real_T Veh_AeroRho;
extern real_T Veh_BodyInertia[3];
extern real_T Veh_BodyMass;
extern real_T Veh_BodyRefZ0;
extern real_T Veh_BodytoWheelCenter;
extern real_T Veh_FrontAxleX;
extern real_T Veh_RearAxleX;
extern real_T Veh_SteerRatio;
extern real_T Veh_SuspF_BumpC;
extern real_T Veh_SuspF_BumpK;
extern real_T Veh_SuspF_BumpLimit;
extern real_T Veh_SuspF_BumpWidth;
extern real_T Veh_SuspF_C;
extern real_T Veh_SuspF_EqPos;
extern real_T Veh_SuspF_K;
extern real_T Veh_SuspF_ReboundC;
extern real_T Veh_SuspF_ReboundK;
extern real_T Veh_SuspF_ReboundLimit;
extern real_T Veh_SuspF_ReboundWidth;
extern real_T Veh_SuspF_UnsprungInertia[3];
extern real_T Veh_SuspF_UnsprungMass;
extern real_T Veh_SuspR_BumpC;
extern real_T Veh_SuspR_BumpK;
extern real_T Veh_SuspR_BumpLimit;
extern real_T Veh_SuspR_BumpWidth;
extern real_T Veh_SuspR_C;
extern real_T Veh_SuspR_EqPos;
extern real_T Veh_SuspR_K;
extern real_T Veh_SuspR_ReboundC;
extern real_T Veh_SuspR_ReboundK;
extern real_T Veh_SuspR_ReboundLimit;
extern real_T Veh_SuspR_ReboundWidth;
extern real_T Veh_SuspR_UnsprungInertia[3];
extern real_T Veh_SuspR_UnsprungMass;
extern real_T Veh_TrackF;
extern real_T Veh_TrackR;
extern void KIMMCar_initialize(void);
extern void KIMMCar_step0(void);
extern void KIMMCar_step2(void);
extern void KIMMCar_terminate(void);
extern RT_MODEL_KIMMCar_T *const KIMMCar_M;
extern void fmu_LogOutput(void);

#endif
