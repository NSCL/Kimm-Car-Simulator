#include "KIMMCar_macros.h"
#include "KIMMCar.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include "KIMMCar_private.h"
#include <stddef.h>
#include "rt_defines.h"
#define KIMMCar_period                 (0.0005)

real_T Veh_AeroArea = 2.594;
real_T Veh_AeroCd = 0.2888;
real_T Veh_AeroCl = 0.149;
real_T Veh_AeroRho = 1.205;
real_T Veh_BodyInertia[3] = { 600.0, 3000.0, 3200.0 } ;

real_T Veh_BodyMass = 1600.0;
real_T Veh_BodyRefZ0 = 0.6147;
real_T Veh_BodytoWheelCenter = 0.2647;
real_T Veh_FrontAxleX = 1.5;
real_T Veh_RearAxleX = -1.5;
real_T Veh_SteerRatio = 16.0;
real_T Veh_SuspF_BumpC = 3000.0;
real_T Veh_SuspF_BumpK = 200000.0;
real_T Veh_SuspF_BumpLimit = -0.084;
real_T Veh_SuspF_BumpWidth = 0.003;
real_T Veh_SuspF_C = 1750.0;
real_T Veh_SuspF_EqPos = 0.1126;
real_T Veh_SuspF_K = 35000.0;
real_T Veh_SuspF_ReboundC = 3000.0;
real_T Veh_SuspF_ReboundK = 200000.0;
real_T Veh_SuspF_ReboundLimit = 0.056;
real_T Veh_SuspF_ReboundWidth = 0.003;
real_T Veh_SuspF_UnsprungInertia[3] = { 1.0, 1.0, 1.0 } ;

real_T Veh_SuspF_UnsprungMass = 48.0;
real_T Veh_SuspR_BumpC = 4000.0;
real_T Veh_SuspR_BumpK = 300000.0;
real_T Veh_SuspR_BumpLimit = -0.095;
real_T Veh_SuspR_BumpWidth = 0.003;
real_T Veh_SuspR_C = 2200.0;
real_T Veh_SuspR_EqPos = 0.0985;
real_T Veh_SuspR_K = 40000.0;
real_T Veh_SuspR_ReboundC = 4000.0;
real_T Veh_SuspR_ReboundK = 300000.0;
real_T Veh_SuspR_ReboundLimit = 0.04;
real_T Veh_SuspR_ReboundWidth = 0.003;
real_T Veh_SuspR_UnsprungInertia[3] = { 1.0, 1.0, 1.0 } ;

real_T Veh_SuspR_UnsprungMass = 45.0;
real_T Veh_TrackF = 1.6;
real_T Veh_TrackR = 1.6;
B_KIMMCar_T KIMMCar_B;
X_KIMMCar_T KIMMCar_X;
XDis_KIMMCar_T KIMMCar_XDis;
DW_KIMMCar_T KIMMCar_DW;
ExtU_KIMMCar_T KIMMCar_U;
ExtY_KIMMCar_T KIMMCar_Y;
static RT_MODEL_KIMMCar_T KIMMCar_M_;
RT_MODEL_KIMMCar_T *const KIMMCar_M = &KIMMCar_M_;
static void KIMMCar_xzlascl(real_T cfrom, real_T cto, real_T A[16]);
static real_T KIMMCar_xnrm2(int32_T n, const real_T x[16], int32_T ix0);
static void KIMMCar_xzgebal(real_T A[16], int32_T *ilo, int32_T *ihi, real_T
  scale[4]);
static real_T KIMMCar_xzlarfg(int32_T n, real_T *alpha1, real_T x[16], int32_T
  ix0);
static void KIMMCar_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[16], int32_T ic0, real_T work[4]);
static void KIMMCar_xzgehrd(real_T a[16], int32_T ilo, int32_T ihi, real_T tau[3]);
static void KIMMCar_xzunghr(int32_T ilo, int32_T ihi, real_T A[16], const real_T
  tau[3]);
static real_T KIMMCar_xnrm2_k(int32_T n, const real_T x[3]);
static real_T KIMMCar_xzlarfg_l(int32_T n, real_T *alpha1, real_T x[3]);
static void KIMMCar_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T
  *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn);
static void KIMMCar_xdlahqr(int32_T ilo, int32_T ihi, real_T h[16], int32_T iloz,
  int32_T ihiz, real_T z[16], int32_T *info, real_T wr[4], real_T wi[4]);
static void KIMMCar_xgemv(int32_T n, const real_T x[12], real_T beta1, real_T y
  [16], int32_T iy0);
static void KIMMCar_dladiv1(real_T a, real_T b, real_T c, real_T d, real_T *p,
  real_T *q);
static void KIMMCar_xdladiv(real_T a, real_T b, real_T c, real_T d, real_T *p,
  real_T *q);
static void KIMMCar_xdlaln2(int32_T na, int32_T nw, real_T smin, const real_T A
  [16], int32_T ia0, const real_T B[12], int32_T ib0, real_T wr, real_T wi,
  real_T X[4], real_T *scale, real_T *xnorm);
static void KIMMCar_xaxpy(int32_T n, real_T a, const real_T x[16], int32_T ix0,
  real_T y[12]);
static void KIMMCar_xdtrevc3(const real_T T[16], real_T vr[16]);
static void KIMMCar_xzlascl_e(real_T cfrom, real_T cto, int32_T m, real_T A[4],
  int32_T iA0);
static void KIMMCar_eigStandard(const real_T A[16], creal_T V[16], creal_T D[4]);
static void KIMMCar_xzlascl_eg(real_T cfrom, real_T cto, int32_T m, real_T A[3],
  int32_T iA0);
static void KIMMCar_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T
  *r);
static void KIMMCar_rotateRight_l(int32_T n, real_T z[16], int32_T iz0, const
  real_T cs[6], int32_T ic0, int32_T is0);
static void KIMMCar_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T
  *rt2, real_T *cs1, real_T *sn1);
static void KIMMCar_rotateRight(int32_T n, real_T z[16], int32_T iz0, const
  real_T cs[6], int32_T ic0, int32_T is0);
static int32_T KIMMCar_xzsteqr(real_T d[4], real_T e[3], real_T z[16]);
static void KIMMCar_eig(const real_T A[16], creal_T V[16], creal_T D[4]);
real_T look1_bingcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T frac;
  real_T y;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (1.0 - frac) * table[iLeft] + table[iLeft + 1U] * frac;
  }

  return y;
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

void KIMMCar_projection(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[216];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[55];
  boolean_T tmp;
  simulationData = (NeslSimulationData *)KIMMCar_DW.STATE_1_SimData;
  time = KIMMCar_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 29;
  simulationData->mData->mContStates.mX =
    &KIMMCar_X.KIMMCarVehicleCamera_FramesCartesian_JointPxp[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &KIMMCar_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &KIMMCar_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(KIMMCar_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&KIMMCar_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&KIMMCar_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = KIMMCar_B.INPUT_3_1_1[0];
  tmp_0[1] = KIMMCar_B.INPUT_3_1_1[1];
  tmp_0[2] = KIMMCar_B.INPUT_3_1_1[2];
  tmp_0[3] = KIMMCar_B.INPUT_3_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = KIMMCar_B.INPUT_4_1_1[0];
  tmp_0[5] = KIMMCar_B.INPUT_4_1_1[1];
  tmp_0[6] = KIMMCar_B.INPUT_4_1_1[2];
  tmp_0[7] = KIMMCar_B.INPUT_4_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = KIMMCar_B.INPUT_5_1_1[0];
  tmp_0[9] = KIMMCar_B.INPUT_5_1_1[1];
  tmp_0[10] = KIMMCar_B.INPUT_5_1_1[2];
  tmp_0[11] = KIMMCar_B.INPUT_5_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = KIMMCar_B.INPUT_6_1_1[0];
  tmp_0[13] = KIMMCar_B.INPUT_6_1_1[1];
  tmp_0[14] = KIMMCar_B.INPUT_6_1_1[2];
  tmp_0[15] = KIMMCar_B.INPUT_6_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = KIMMCar_B.INPUT_7_1_1[0];
  tmp_0[17] = KIMMCar_B.INPUT_7_1_1[1];
  tmp_0[18] = KIMMCar_B.INPUT_7_1_1[2];
  tmp_0[19] = KIMMCar_B.INPUT_7_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = KIMMCar_B.INPUT_8_1_1[0];
  tmp_0[21] = KIMMCar_B.INPUT_8_1_1[1];
  tmp_0[22] = KIMMCar_B.INPUT_8_1_1[2];
  tmp_0[23] = KIMMCar_B.INPUT_8_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = KIMMCar_B.INPUT_9_1_1[0];
  tmp_0[25] = KIMMCar_B.INPUT_9_1_1[1];
  tmp_0[26] = KIMMCar_B.INPUT_9_1_1[2];
  tmp_0[27] = KIMMCar_B.INPUT_9_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = KIMMCar_B.INPUT_14_1_1[0];
  tmp_0[29] = KIMMCar_B.INPUT_14_1_1[1];
  tmp_0[30] = KIMMCar_B.INPUT_14_1_1[2];
  tmp_0[31] = KIMMCar_B.INPUT_14_1_1[3];
  tmp_1[8] = 32;
  tmp_0[32] = KIMMCar_B.INPUT_10_1_1[0];
  tmp_0[33] = KIMMCar_B.INPUT_10_1_1[1];
  tmp_0[34] = KIMMCar_B.INPUT_10_1_1[2];
  tmp_0[35] = KIMMCar_B.INPUT_10_1_1[3];
  tmp_1[9] = 36;
  tmp_0[36] = KIMMCar_B.INPUT_11_1_1[0];
  tmp_0[37] = KIMMCar_B.INPUT_11_1_1[1];
  tmp_0[38] = KIMMCar_B.INPUT_11_1_1[2];
  tmp_0[39] = KIMMCar_B.INPUT_11_1_1[3];
  tmp_1[10] = 40;
  tmp_0[40] = KIMMCar_B.INPUT_12_1_1[0];
  tmp_0[41] = KIMMCar_B.INPUT_12_1_1[1];
  tmp_0[42] = KIMMCar_B.INPUT_12_1_1[2];
  tmp_0[43] = KIMMCar_B.INPUT_12_1_1[3];
  tmp_1[11] = 44;
  tmp_0[44] = KIMMCar_B.INPUT_13_1_1[0];
  tmp_0[45] = KIMMCar_B.INPUT_13_1_1[1];
  tmp_0[46] = KIMMCar_B.INPUT_13_1_1[2];
  tmp_0[47] = KIMMCar_B.INPUT_13_1_1[3];
  tmp_1[12] = 48;
  tmp_0[48] = KIMMCar_B.INPUT_15_1_1[0];
  tmp_0[49] = KIMMCar_B.INPUT_15_1_1[1];
  tmp_0[50] = KIMMCar_B.INPUT_15_1_1[2];
  tmp_0[51] = KIMMCar_B.INPUT_15_1_1[3];
  tmp_1[13] = 52;
  tmp_0[52] = KIMMCar_B.INPUT_16_1_1[0];
  tmp_0[53] = KIMMCar_B.INPUT_16_1_1[1];
  tmp_0[54] = KIMMCar_B.INPUT_16_1_1[2];
  tmp_0[55] = KIMMCar_B.INPUT_16_1_1[3];
  tmp_1[14] = 56;
  tmp_0[56] = KIMMCar_B.INPUT_17_1_1[0];
  tmp_0[57] = KIMMCar_B.INPUT_17_1_1[1];
  tmp_0[58] = KIMMCar_B.INPUT_17_1_1[2];
  tmp_0[59] = KIMMCar_B.INPUT_17_1_1[3];
  tmp_1[15] = 60;
  tmp_0[60] = KIMMCar_B.INPUT_21_1_1[0];
  tmp_0[61] = KIMMCar_B.INPUT_21_1_1[1];
  tmp_0[62] = KIMMCar_B.INPUT_21_1_1[2];
  tmp_0[63] = KIMMCar_B.INPUT_21_1_1[3];
  tmp_1[16] = 64;
  tmp_0[64] = KIMMCar_B.INPUT_18_1_1[0];
  tmp_0[65] = KIMMCar_B.INPUT_18_1_1[1];
  tmp_0[66] = KIMMCar_B.INPUT_18_1_1[2];
  tmp_0[67] = KIMMCar_B.INPUT_18_1_1[3];
  tmp_1[17] = 68;
  tmp_0[68] = KIMMCar_B.INPUT_19_1_1[0];
  tmp_0[69] = KIMMCar_B.INPUT_19_1_1[1];
  tmp_0[70] = KIMMCar_B.INPUT_19_1_1[2];
  tmp_0[71] = KIMMCar_B.INPUT_19_1_1[3];
  tmp_1[18] = 72;
  tmp_0[72] = KIMMCar_B.INPUT_20_1_1[0];
  tmp_0[73] = KIMMCar_B.INPUT_20_1_1[1];
  tmp_0[74] = KIMMCar_B.INPUT_20_1_1[2];
  tmp_0[75] = KIMMCar_B.INPUT_20_1_1[3];
  tmp_1[19] = 76;
  tmp_0[76] = KIMMCar_B.INPUT_22_1_1[0];
  tmp_0[77] = KIMMCar_B.INPUT_22_1_1[1];
  tmp_0[78] = KIMMCar_B.INPUT_22_1_1[2];
  tmp_0[79] = KIMMCar_B.INPUT_22_1_1[3];
  tmp_1[20] = 80;
  tmp_0[80] = KIMMCar_B.INPUT_23_1_1[0];
  tmp_0[81] = KIMMCar_B.INPUT_23_1_1[1];
  tmp_0[82] = KIMMCar_B.INPUT_23_1_1[2];
  tmp_0[83] = KIMMCar_B.INPUT_23_1_1[3];
  tmp_1[21] = 84;
  tmp_0[84] = KIMMCar_B.INPUT_24_1_1[0];
  tmp_0[85] = KIMMCar_B.INPUT_24_1_1[1];
  tmp_0[86] = KIMMCar_B.INPUT_24_1_1[2];
  tmp_0[87] = KIMMCar_B.INPUT_24_1_1[3];
  tmp_1[22] = 88;
  tmp_0[88] = KIMMCar_B.INPUT_25_1_1[0];
  tmp_0[89] = KIMMCar_B.INPUT_25_1_1[1];
  tmp_0[90] = KIMMCar_B.INPUT_25_1_1[2];
  tmp_0[91] = KIMMCar_B.INPUT_25_1_1[3];
  tmp_1[23] = 92;
  tmp_0[92] = KIMMCar_B.INPUT_28_1_1[0];
  tmp_0[93] = KIMMCar_B.INPUT_28_1_1[1];
  tmp_0[94] = KIMMCar_B.INPUT_28_1_1[2];
  tmp_0[95] = KIMMCar_B.INPUT_28_1_1[3];
  tmp_1[24] = 96;
  tmp_0[96] = KIMMCar_B.INPUT_26_1_1[0];
  tmp_0[97] = KIMMCar_B.INPUT_26_1_1[1];
  tmp_0[98] = KIMMCar_B.INPUT_26_1_1[2];
  tmp_0[99] = KIMMCar_B.INPUT_26_1_1[3];
  tmp_1[25] = 100;
  tmp_0[100] = KIMMCar_B.INPUT_27_1_1[0];
  tmp_0[101] = KIMMCar_B.INPUT_27_1_1[1];
  tmp_0[102] = KIMMCar_B.INPUT_27_1_1[2];
  tmp_0[103] = KIMMCar_B.INPUT_27_1_1[3];
  tmp_1[26] = 104;
  tmp_0[104] = KIMMCar_B.INPUT_31_1_1[0];
  tmp_0[105] = KIMMCar_B.INPUT_31_1_1[1];
  tmp_0[106] = KIMMCar_B.INPUT_31_1_1[2];
  tmp_0[107] = KIMMCar_B.INPUT_31_1_1[3];
  tmp_1[27] = 108;
  tmp_0[108] = KIMMCar_B.INPUT_32_1_1[0];
  tmp_0[109] = KIMMCar_B.INPUT_32_1_1[1];
  tmp_0[110] = KIMMCar_B.INPUT_32_1_1[2];
  tmp_0[111] = KIMMCar_B.INPUT_32_1_1[3];
  tmp_1[28] = 112;
  tmp_0[112] = KIMMCar_B.INPUT_33_1_1[0];
  tmp_0[113] = KIMMCar_B.INPUT_33_1_1[1];
  tmp_0[114] = KIMMCar_B.INPUT_33_1_1[2];
  tmp_0[115] = KIMMCar_B.INPUT_33_1_1[3];
  tmp_1[29] = 116;
  tmp_0[116] = KIMMCar_B.INPUT_36_1_1[0];
  tmp_0[117] = KIMMCar_B.INPUT_36_1_1[1];
  tmp_0[118] = KIMMCar_B.INPUT_36_1_1[2];
  tmp_0[119] = KIMMCar_B.INPUT_36_1_1[3];
  tmp_1[30] = 120;
  tmp_0[120] = KIMMCar_B.INPUT_34_1_1[0];
  tmp_0[121] = KIMMCar_B.INPUT_34_1_1[1];
  tmp_0[122] = KIMMCar_B.INPUT_34_1_1[2];
  tmp_0[123] = KIMMCar_B.INPUT_34_1_1[3];
  tmp_1[31] = 124;
  tmp_0[124] = KIMMCar_B.INPUT_35_1_1[0];
  tmp_0[125] = KIMMCar_B.INPUT_35_1_1[1];
  tmp_0[126] = KIMMCar_B.INPUT_35_1_1[2];
  tmp_0[127] = KIMMCar_B.INPUT_35_1_1[3];
  tmp_1[32] = 128;
  tmp_0[128] = KIMMCar_B.INPUT_39_1_1[0];
  tmp_0[129] = KIMMCar_B.INPUT_39_1_1[1];
  tmp_0[130] = KIMMCar_B.INPUT_39_1_1[2];
  tmp_0[131] = KIMMCar_B.INPUT_39_1_1[3];
  tmp_1[33] = 132;
  tmp_0[132] = KIMMCar_B.INPUT_40_1_1[0];
  tmp_0[133] = KIMMCar_B.INPUT_40_1_1[1];
  tmp_0[134] = KIMMCar_B.INPUT_40_1_1[2];
  tmp_0[135] = KIMMCar_B.INPUT_40_1_1[3];
  tmp_1[34] = 136;
  tmp_0[136] = KIMMCar_B.INPUT_41_1_1[0];
  tmp_0[137] = KIMMCar_B.INPUT_41_1_1[1];
  tmp_0[138] = KIMMCar_B.INPUT_41_1_1[2];
  tmp_0[139] = KIMMCar_B.INPUT_41_1_1[3];
  tmp_1[35] = 140;
  tmp_0[140] = KIMMCar_B.INPUT_44_1_1[0];
  tmp_0[141] = KIMMCar_B.INPUT_44_1_1[1];
  tmp_0[142] = KIMMCar_B.INPUT_44_1_1[2];
  tmp_0[143] = KIMMCar_B.INPUT_44_1_1[3];
  tmp_1[36] = 144;
  tmp_0[144] = KIMMCar_B.INPUT_42_1_1[0];
  tmp_0[145] = KIMMCar_B.INPUT_42_1_1[1];
  tmp_0[146] = KIMMCar_B.INPUT_42_1_1[2];
  tmp_0[147] = KIMMCar_B.INPUT_42_1_1[3];
  tmp_1[37] = 148;
  tmp_0[148] = KIMMCar_B.INPUT_43_1_1[0];
  tmp_0[149] = KIMMCar_B.INPUT_43_1_1[1];
  tmp_0[150] = KIMMCar_B.INPUT_43_1_1[2];
  tmp_0[151] = KIMMCar_B.INPUT_43_1_1[3];
  tmp_1[38] = 152;
  tmp_0[152] = KIMMCar_B.INPUT_47_1_1[0];
  tmp_0[153] = KIMMCar_B.INPUT_47_1_1[1];
  tmp_0[154] = KIMMCar_B.INPUT_47_1_1[2];
  tmp_0[155] = KIMMCar_B.INPUT_47_1_1[3];
  tmp_1[39] = 156;
  tmp_0[156] = KIMMCar_B.INPUT_48_1_1[0];
  tmp_0[157] = KIMMCar_B.INPUT_48_1_1[1];
  tmp_0[158] = KIMMCar_B.INPUT_48_1_1[2];
  tmp_0[159] = KIMMCar_B.INPUT_48_1_1[3];
  tmp_1[40] = 160;
  tmp_0[160] = KIMMCar_B.INPUT_49_1_1[0];
  tmp_0[161] = KIMMCar_B.INPUT_49_1_1[1];
  tmp_0[162] = KIMMCar_B.INPUT_49_1_1[2];
  tmp_0[163] = KIMMCar_B.INPUT_49_1_1[3];
  tmp_1[41] = 164;
  tmp_0[164] = KIMMCar_B.INPUT_52_1_1[0];
  tmp_0[165] = KIMMCar_B.INPUT_52_1_1[1];
  tmp_0[166] = KIMMCar_B.INPUT_52_1_1[2];
  tmp_0[167] = KIMMCar_B.INPUT_52_1_1[3];
  tmp_1[42] = 168;
  tmp_0[168] = KIMMCar_B.INPUT_50_1_1[0];
  tmp_0[169] = KIMMCar_B.INPUT_50_1_1[1];
  tmp_0[170] = KIMMCar_B.INPUT_50_1_1[2];
  tmp_0[171] = KIMMCar_B.INPUT_50_1_1[3];
  tmp_1[43] = 172;
  tmp_0[172] = KIMMCar_B.INPUT_51_1_1[0];
  tmp_0[173] = KIMMCar_B.INPUT_51_1_1[1];
  tmp_0[174] = KIMMCar_B.INPUT_51_1_1[2];
  tmp_0[175] = KIMMCar_B.INPUT_51_1_1[3];
  tmp_1[44] = 176;
  tmp_0[176] = KIMMCar_B.INPUT_1_1_1[0];
  tmp_0[177] = KIMMCar_B.INPUT_1_1_1[1];
  tmp_0[178] = KIMMCar_B.INPUT_1_1_1[2];
  tmp_0[179] = KIMMCar_B.INPUT_1_1_1[3];
  tmp_1[45] = 180;
  tmp_0[180] = KIMMCar_B.INPUT_2_1_1[0];
  tmp_0[181] = KIMMCar_B.INPUT_2_1_1[1];
  tmp_0[182] = KIMMCar_B.INPUT_2_1_1[2];
  tmp_0[183] = KIMMCar_B.INPUT_2_1_1[3];
  tmp_1[46] = 184;
  tmp_0[184] = KIMMCar_B.INPUT_29_1_1[0];
  tmp_0[185] = KIMMCar_B.INPUT_29_1_1[1];
  tmp_0[186] = KIMMCar_B.INPUT_29_1_1[2];
  tmp_0[187] = KIMMCar_B.INPUT_29_1_1[3];
  tmp_1[47] = 188;
  tmp_0[188] = KIMMCar_B.INPUT_30_1_1[0];
  tmp_0[189] = KIMMCar_B.INPUT_30_1_1[1];
  tmp_0[190] = KIMMCar_B.INPUT_30_1_1[2];
  tmp_0[191] = KIMMCar_B.INPUT_30_1_1[3];
  tmp_1[48] = 192;
  tmp_0[192] = KIMMCar_B.INPUT_37_1_1[0];
  tmp_0[193] = KIMMCar_B.INPUT_37_1_1[1];
  tmp_0[194] = KIMMCar_B.INPUT_37_1_1[2];
  tmp_0[195] = KIMMCar_B.INPUT_37_1_1[3];
  tmp_1[49] = 196;
  tmp_0[196] = KIMMCar_B.INPUT_38_1_1[0];
  tmp_0[197] = KIMMCar_B.INPUT_38_1_1[1];
  tmp_0[198] = KIMMCar_B.INPUT_38_1_1[2];
  tmp_0[199] = KIMMCar_B.INPUT_38_1_1[3];
  tmp_1[50] = 200;
  tmp_0[200] = KIMMCar_B.INPUT_45_1_1[0];
  tmp_0[201] = KIMMCar_B.INPUT_45_1_1[1];
  tmp_0[202] = KIMMCar_B.INPUT_45_1_1[2];
  tmp_0[203] = KIMMCar_B.INPUT_45_1_1[3];
  tmp_1[51] = 204;
  tmp_0[204] = KIMMCar_B.INPUT_46_1_1[0];
  tmp_0[205] = KIMMCar_B.INPUT_46_1_1[1];
  tmp_0[206] = KIMMCar_B.INPUT_46_1_1[2];
  tmp_0[207] = KIMMCar_B.INPUT_46_1_1[3];
  tmp_1[52] = 208;
  tmp_0[208] = KIMMCar_B.INPUT_53_1_1[0];
  tmp_0[209] = KIMMCar_B.INPUT_53_1_1[1];
  tmp_0[210] = KIMMCar_B.INPUT_53_1_1[2];
  tmp_0[211] = KIMMCar_B.INPUT_53_1_1[3];
  tmp_1[53] = 212;
  tmp_0[212] = KIMMCar_B.INPUT_54_1_1[0];
  tmp_0[213] = KIMMCar_B.INPUT_54_1_1[1];
  tmp_0[214] = KIMMCar_B.INPUT_54_1_1[2];
  tmp_0[215] = KIMMCar_B.INPUT_54_1_1[3];
  tmp_1[54] = 216;
  simulationData->mData->mInputValues.mN = 216;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 55;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  diagnosticManager = (NeuDiagnosticManager *)KIMMCar_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)KIMMCar_DW.STATE_1_Simulator,
    NESL_SIM_PROJECTION, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(KIMMCar_M, msg);
    }
  }
}

static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{

#define KIMMCar_NSTAGES                13

  static real_T rt_ODE8_B[13] = {
    4.174749114153025E-2, 0.0, 0.0, 0.0,
    0.0, -5.54523286112393E-2, 2.393128072011801E-1, 7.03510669403443E-1,
    -7.597596138144609E-1, 6.605630309222863E-1, 1.581874825101233E-1,
    -2.381095387528628E-1, 2.5E-1
  };

  static real_T rt_ODE8_C[13] = {
    0.0, 5.555555555555556E-2, 8.333333333333333E-2, 1.25E-1,
    3.125E-1, 3.75E-1, 1.475E-1, 4.65E-1,
    5.648654513822596E-1, 6.5E-1, 9.246562776405044E-1, 1.0, 1.0
  };

  static real_T rt_ODE8_A[13][13] = {

    { 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 5.555555555555556E-2, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 2.083333333333333E-2, 6.25E-2, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 3.125E-2, 0.0, 9.375E-2, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 3.125E-1, 0.0, -1.171875, 1.171875,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 3.75E-2, 0.0, 0.0, 1.875E-1,
      1.5E-1, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 4.791013711111111E-2, 0.0, 0.0, 1.122487127777778E-1,
      -2.550567377777778E-2, 1.284682388888889E-2, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 1.691798978729228E-2, 0.0, 0.0, 3.878482784860432E-1,
      3.597736985150033E-2, 1.969702142156661E-1, -1.727138523405018E-1, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 6.90957533591923E-2, 0.0, 0.0, -6.342479767288542E-1,
      -1.611975752246041E-1, 1.386503094588253E-1, 9.409286140357563E-1,
      2.11636326481944E-1,
      0.0, 0.0, 0.0, 0.0, 0.0 },


    { 1.835569968390454E-1, 0.0, 0.0, -2.468768084315592,
      -2.912868878163005E-1, -2.647302023311738E-2, 2.8478387641928,
      2.813873314698498E-1,
      1.237448998633147E-1, 0.0, 0.0, 0.0, 0.0 },


    { -1.215424817395888, 0.0, 0.0, 1.667260866594577E1,
      9.157418284168179E-1, -6.056605804357471, -1.600357359415618E1,
      1.484930308629766E1,
      -1.337157573528985E1, 5.134182648179638, 0.0, 0.0, 0.0 },


    { 2.588609164382643E-1, 0.0, 0.0, -4.774485785489205,
      -4.350930137770325E-1, -3.049483332072241, 5.577920039936099,
      6.155831589861039,
      -5.062104586736938, 2.193926173180679, 1.346279986593349E-1, 0.0, 0.0 },


    { 8.224275996265075E-1, 0.0, 0.0, -1.165867325727766E1,
      -7.576221166909362E-1, 7.139735881595818E-1, 1.207577498689006E1,
      -2.127659113920403,
      1.990166207048956, -2.342864715440405E-1, 1.758985777079423E-1, 0.0, 0.0 },
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE8_IntgData *intgData = (ODE8_IntgData *)rtsiGetSolverData(si);
  real_T *deltaY = intgData->deltaY;
  real_T *x0 = intgData->x0;
  real_T* f[KIMMCar_NSTAGES];
  int_T idx,stagesIdx,statesIdx;
  real_T deltaX;
  int_T nXc = 61;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  f[0] = intgData->f[0];
  f[1] = intgData->f[1];
  f[2] = intgData->f[2];
  f[3] = intgData->f[3];
  f[4] = intgData->f[4];
  f[5] = intgData->f[5];
  f[6] = intgData->f[6];
  f[7] = intgData->f[7];
  f[8] = intgData->f[8];
  f[9] = intgData->f[9];
  f[10] = intgData->f[10];
  f[11] = intgData->f[11];
  f[12] = intgData->f[12];
  (void) memset(deltaY, 0,
                (uint_T)nXc*sizeof(real_T));
  (void) memcpy(x0, x,
                nXc*sizeof(real_T));
  for (stagesIdx=0;stagesIdx<KIMMCar_NSTAGES;stagesIdx++) {
    (void) memcpy(x, x0,
                  (uint_T)nXc*sizeof(real_T));
    for (statesIdx=0;statesIdx<nXc;statesIdx++) {
      deltaX = 0;
      for (idx=0;idx<stagesIdx;idx++) {
        deltaX = deltaX + h*rt_ODE8_A[stagesIdx][idx]*f[idx][statesIdx];
      }

      x[statesIdx] = x0[statesIdx] + deltaX;
    }

    if (stagesIdx==0) {
      rtsiSetdX(si, f[stagesIdx]);
      KIMMCar_derivatives();
    } else {
      (stagesIdx==KIMMCar_NSTAGES-1)? rtsiSetT(si, tnew) : rtsiSetT(si, t + h*
          rt_ODE8_C[stagesIdx]);
      rtsiSetdX(si, f[stagesIdx]);
      KIMMCar_step0();
      KIMMCar_derivatives();
    }

    for (statesIdx=0;statesIdx<nXc;statesIdx++) {
      deltaY[statesIdx] = deltaY[statesIdx] + h*rt_ODE8_B[stagesIdx]*f[stagesIdx]
        [statesIdx];
    }
  }

  for (statesIdx=0;statesIdx<nXc;statesIdx++) {
    x[statesIdx] = x0[statesIdx] + deltaY[statesIdx];
  }

  KIMMCar_step0();
  KIMMCar_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static void KIMMCar_xzlascl(real_T cfrom, real_T cto, real_T A[16])
{
  real_T cfrom1;
  real_T cfromc;
  real_T cto1;
  real_T ctoc;
  real_T mul;
  int32_T j;
  int32_T tmp;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    for (j = 0; j < 4; j++) {
      tmp = j << 2;
      A[tmp] *= mul;
      A[tmp + 1] *= mul;
      A[tmp + 2] *= mul;
      A[tmp + 3] *= mul;
    }
  }
}

static real_T KIMMCar_xnrm2(int32_T n, const real_T x[16], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (k = ix0; k < kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

static void KIMMCar_xzgebal(real_T A[16], int32_T *ilo, int32_T *ihi, real_T
  scale[4])
{
  __m128d tmp;
  real_T absxk;
  real_T b_scale;
  real_T c;
  real_T g;
  real_T r;
  real_T s;
  real_T t;
  real_T y;
  real_T y_0;
  int32_T c_i;
  int32_T c_ix0;
  int32_T c_tmp;
  int32_T c_tmp_0;
  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg4;
  int32_T exitg5;
  int32_T f_ix;
  int32_T f_ix_tmp;
  int32_T ica;
  int32_T kend;
  boolean_T exitg3;
  boolean_T exitg6;
  boolean_T exitg7;
  boolean_T notdone;
  boolean_T skipThisColumn;
  scale[0] = 1.0;
  scale[1] = 1.0;
  scale[2] = 1.0;
  scale[3] = 1.0;
  *ilo = 1;
  *ihi = 4;
  notdone = true;
  do {
    exitg5 = 0;
    if (notdone) {
      notdone = false;
      c_i = *ihi;
      do {
        exitg4 = 0;
        if (c_i > 0) {
          skipThisColumn = false;
          f_ix = 0;
          exitg6 = false;
          while ((!exitg6) && (f_ix <= (uint8_T)*ihi - 1)) {
            if ((f_ix + 1 == c_i) || (!(A[((f_ix << 2) + c_i) - 1] != 0.0))) {
              f_ix++;
            } else {
              skipThisColumn = true;
              exitg6 = true;
            }
          }

          if (skipThisColumn) {
            c_i--;
          } else {
            scale[*ihi - 1] = c_i;
            if (c_i != *ihi) {
              ica = (c_i - 1) << 2;
              kend = (*ihi - 1) << 2;
              c_ix0 = (uint8_T)*ihi;
              for (f_ix = 0; f_ix < c_ix0; f_ix++) {
                c_tmp = ica + f_ix;
                c = A[c_tmp];
                f_ix_tmp = kend + f_ix;
                A[c_tmp] = A[f_ix_tmp];
                A[f_ix_tmp] = c;
              }

              c = A[c_i - 1];
              A[c_i - 1] = A[*ihi - 1];
              A[*ihi - 1] = c;
              c = A[c_i + 3];
              A[c_i + 3] = A[*ihi + 3];
              A[*ihi + 3] = c;
              c = A[c_i + 7];
              A[c_i + 7] = A[*ihi + 7];
              A[*ihi + 7] = c;
              c = A[c_i + 11];
              A[c_i + 11] = A[*ihi + 11];
              A[*ihi + 11] = c;
            }

            exitg4 = 1;
          }
        } else {
          exitg4 = 2;
        }
      } while (exitg4 == 0);

      if (exitg4 == 1) {
        if (*ihi == 1) {
          exitg5 = 1;
        } else {
          (*ihi)--;
          notdone = true;
        }
      }
    } else {
      notdone = true;
      while (notdone) {
        notdone = false;
        c_i = *ilo;
        exitg6 = false;
        while ((!exitg6) && (c_i <= *ihi)) {
          skipThisColumn = false;
          f_ix = *ilo;
          exitg7 = false;
          while ((!exitg7) && (f_ix <= *ihi)) {
            if ((f_ix == c_i) || (!(A[(((c_i - 1) << 2) + f_ix) - 1] != 0.0))) {
              f_ix++;
            } else {
              skipThisColumn = true;
              exitg7 = true;
            }
          }

          if (skipThisColumn) {
            c_i++;
          } else {
            scale[*ilo - 1] = c_i;
            if (c_i != *ilo) {
              ica = (c_i - 1) << 2;
              c_tmp_0 = (*ilo - 1) << 2;
              c_ix0 = (uint8_T)*ihi;
              for (f_ix = 0; f_ix < c_ix0; f_ix++) {
                c_tmp = ica + f_ix;
                c = A[c_tmp];
                f_ix_tmp = c_tmp_0 + f_ix;
                A[c_tmp] = A[f_ix_tmp];
                A[f_ix_tmp] = c;
              }

              f_ix = (c_tmp_0 + c_i) - 1;
              ica = (c_tmp_0 + *ilo) - 1;
              kend = (uint8_T)(5 - *ilo);
              for (c_i = 0; c_i < kend; c_i++) {
                c_tmp = c_i << 2;
                c_tmp_0 = c_tmp + f_ix;
                c = A[c_tmp_0];
                f_ix_tmp = c_tmp + ica;
                A[c_tmp_0] = A[f_ix_tmp];
                A[f_ix_tmp] = c;
              }
            }

            (*ilo)++;
            notdone = true;
            exitg6 = true;
          }
        }
      }

      exitg5 = 2;
    }
  } while (exitg5 == 0);

  if (exitg5 == 1) {
  } else {
    exitg3 = false;
    while ((!exitg3) && (!notdone)) {
      notdone = true;
      c_i = *ilo - 1;
      do {
        exitg2 = 0;
        if (c_i + 1 <= *ihi) {
          c_tmp = (*ihi - *ilo) + 1;
          c_tmp_0 = c_i << 2;
          c = KIMMCar_xnrm2(c_tmp, A, c_tmp_0 + *ilo);
          f_ix_tmp = ((*ilo - 1) << 2) + c_i;
          r = 0.0;
          if (c_tmp >= 1) {
            if (c_tmp == 1) {
              r = fabs(A[f_ix_tmp]);
            } else {
              b_scale = 3.3121686421112381E-170;
              kend = (((c_tmp - 1) << 2) + f_ix_tmp) + 1;
              for (ica = f_ix_tmp + 1; ica <= kend; ica += 4) {
                absxk = fabs(A[ica - 1]);
                if (absxk > b_scale) {
                  t = b_scale / absxk;
                  r = r * t * t + 1.0;
                  b_scale = absxk;
                } else {
                  t = absxk / b_scale;
                  r += t * t;
                }
              }

              r = b_scale * sqrt(r);
            }
          }

          ica = 1;
          if (*ihi > 1) {
            b_scale = fabs(A[c_tmp_0]);
            for (f_ix = 2; f_ix <= *ihi; f_ix++) {
              absxk = fabs(A[(c_tmp_0 + f_ix) - 1]);
              if (absxk > b_scale) {
                ica = f_ix;
                b_scale = absxk;
              }
            }
          }

          b_scale = fabs(A[(c_tmp_0 + ica) - 1]);
          f_ix = 5 - *ilo;
          if (5 - *ilo < 1) {
            ica = 0;
          } else {
            ica = 1;
            if (5 - *ilo > 1) {
              absxk = fabs(A[f_ix_tmp]);
              for (c_ix0 = 2; c_ix0 <= f_ix; c_ix0++) {
                t = fabs(A[((c_ix0 - 1) << 2) + f_ix_tmp]);
                if (t > absxk) {
                  ica = c_ix0;
                  absxk = t;
                }
              }
            }
          }

          t = fabs(A[(((ica + *ilo) - 2) << 2) + c_i]);
          if ((c == 0.0) || (r == 0.0)) {
            c_i++;
          } else {
            g = r / 2.0;
            absxk = 1.0;
            s = c + r;
            do {
              exitg1 = 0;
              if (c < g) {
                if ((c >= b_scale) || rtIsNaN(b_scale)) {
                  y = c;
                } else {
                  y = b_scale;
                }

                if (absxk >= y) {
                  y = absxk;
                }

                if (y < 4.9896007738368E+291) {
                  if ((g <= t) || rtIsNaN(t)) {
                    y = g;
                  } else {
                    y = t;
                  }

                  if (r <= y) {
                    y = r;
                  }

                  if (y > 2.0041683600089728E-292) {
                    if (rtIsNaN(((((c + absxk) + b_scale) + r) + g) + t)) {
                      exitg1 = 1;
                    } else {
                      absxk *= 2.0;
                      c *= 2.0;
                      b_scale *= 2.0;
                      r /= 2.0;
                      g /= 2.0;
                      t /= 2.0;
                    }
                  } else {
                    exitg1 = 2;
                  }
                } else {
                  exitg1 = 2;
                }
              } else {
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = 2;
            } else {
              g = c / 2.0;
              exitg6 = false;
              while ((!exitg6) && (g >= r)) {
                if ((r >= t) || rtIsNaN(t)) {
                  y = r;
                } else {
                  y = t;
                }

                if (y < 4.9896007738368E+291) {
                  if ((absxk <= c) || rtIsNaN(c)) {
                    y = absxk;
                  } else {
                    y = c;
                  }

                  if ((g <= b_scale) || rtIsNaN(b_scale)) {
                    y_0 = g;
                  } else {
                    y_0 = b_scale;
                  }

                  if (y <= y_0) {
                    y_0 = y;
                  }

                  if (y_0 > 2.0041683600089728E-292) {
                    absxk /= 2.0;
                    c /= 2.0;
                    g /= 2.0;
                    b_scale /= 2.0;
                    r *= 2.0;
                    t *= 2.0;
                  } else {
                    exitg6 = true;
                  }
                } else {
                  exitg6 = true;
                }
              }

              if ((c + r >= 0.95 * s) || ((absxk < 1.0) && (scale[c_i] < 1.0) &&
                   (absxk * scale[c_i] <= 1.0020841800044864E-292)) || ((absxk >
                    1.0) && (scale[c_i] > 1.0) && (scale[c_i] >=
                    9.9792015476736E+291 / absxk))) {
              } else {
                c = 1.0 / absxk;
                scale[c_i] *= absxk;
                ica = f_ix_tmp + 1;
                kend = (((4 - *ilo) << 2) + f_ix_tmp) + 1;
                for (f_ix = ica; f_ix <= kend; f_ix += 4) {
                  A[f_ix - 1] *= c;
                }

                kend = c_tmp_0 + *ihi;
                ica = ((((kend - c_tmp_0) / 2) << 1) + c_tmp_0) + 1;
                c_ix0 = ica - 2;
                for (f_ix = c_tmp_0 + 1; f_ix <= c_ix0; f_ix += 2) {
                  tmp = _mm_loadu_pd(&A[f_ix - 1]);
                  _mm_storeu_pd(&A[f_ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(absxk)));
                }

                for (f_ix = ica; f_ix <= kend; f_ix++) {
                  A[f_ix - 1] *= absxk;
                }

                notdone = false;
              }

              c_i++;
            }
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (exitg2 == 1) {
      } else {
        exitg3 = true;
      }
    }
  }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

static real_T KIMMCar_xzlarfg(int32_T n, real_T *alpha1, real_T x[16], int32_T
  ix0)
{
  __m128d tmp;
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c;
  int32_T knt;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  tau = 0.0;
  if (n > 0) {
    xnorm = KIMMCar_xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          scalarLB = (ix0 + n) - 2;
          vectorUB = ((((scalarLB - ix0) + 1) / 2) << 1) + ix0;
          vectorUB_tmp = vectorUB - 2;
          for (c = ix0; c <= vectorUB_tmp; c += 2) {
            tmp = _mm_loadu_pd(&x[c - 1]);
            _mm_storeu_pd(&x[c - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (c = vectorUB; c <= scalarLB; c++) {
            x[c - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(*alpha1, KIMMCar_xnrm2(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        for (c = ix0; c <= vectorUB_tmp; c += 2) {
          tmp = _mm_loadu_pd(&x[c - 1]);
          _mm_storeu_pd(&x[c - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (c = vectorUB; c <= scalarLB; c++) {
          x[c - 1] *= a;
        }

        for (c = 0; c < knt; c++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        c = (ix0 + n) - 2;
        scalarLB = ((((c - ix0) + 1) / 2) << 1) + ix0;
        vectorUB = scalarLB - 2;
        for (knt = ix0; knt <= vectorUB; knt += 2) {
          tmp = _mm_loadu_pd(&x[knt - 1]);
          _mm_storeu_pd(&x[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (knt = scalarLB; knt <= c; knt++) {
          x[knt - 1] *= a;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

static void KIMMCar_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[16], int32_T ic0, real_T work[4])
{
  real_T c;
  int32_T coltop;
  int32_T d;
  int32_T e;
  int32_T exitg1;
  int32_T jA;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = ((lastc - 1) << 2) + ic0;
      jA = coltop;
      do {
        exitg1 = 0;
        if (jA <= (coltop + lastv) - 1) {
          if (C[jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jA++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    if (lastc != 0) {
      memset(&work[0], 0, (uint8_T)lastc * sizeof(real_T));
      d = ((lastc - 1) << 2) + ic0;
      for (coltop = ic0; coltop <= d; coltop += 4) {
        c = 0.0;
        e = (coltop + lastv) - 1;
        for (jA = coltop; jA <= e; jA++) {
          c += C[((iv0 + jA) - coltop) - 1] * C[jA - 1];
        }

        jA = (coltop - ic0) >> 2;
        work[jA] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      d = (uint8_T)lastc - 1;
      for (lastc = 0; lastc <= d; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          e = (lastv + jA) - 1;
          for (coltop = jA; coltop <= e; coltop++) {
            C[coltop - 1] += C[((iv0 + coltop) - jA) - 1] * c;
          }
        }

        jA += 4;
      }
    }
  }
}

static void KIMMCar_xzgehrd(real_T a[16], int32_T ilo, int32_T ihi, real_T tau[3])
{
  __m128d tmp;
  __m128d tmp_0;
  real_T work[4];
  real_T alpha1;
  real_T tau_0;
  real_T temp;
  int32_T alpha1_tmp_tmp;
  int32_T b_ia;
  int32_T b_ix;
  int32_T e;
  int32_T exitg1;
  int32_T i;
  int32_T im1n;
  int32_T ix;
  int32_T lastc;
  int32_T lastv;
  int32_T rowleft;
  int32_T tau_tmp;
  int32_T work_tmp;
  boolean_T exitg2;
  if ((ihi - ilo) + 1 > 1) {
    if ((uint8_T)(ilo - 1) - 1 >= 0) {
      memset(&tau[0], 0, (uint8_T)(ilo - 1) * sizeof(real_T));
    }

    for (i = ihi; i < 4; i++) {
      tau[i - 1] = 0.0;
    }

    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    work[3] = 0.0;
    for (i = ilo; i < ihi; i++) {
      rowleft = (i - 1) << 2;
      im1n = i << 2;
      alpha1_tmp_tmp = rowleft + i;
      alpha1 = a[alpha1_tmp_tmp];
      if (i + 2 <= 4) {
        lastv = i + 2;
      } else {
        lastv = 4;
      }

      tau_tmp = ihi - i;
      tau_0 = KIMMCar_xzlarfg(tau_tmp, &alpha1, a, rowleft + lastv);
      tau[i - 1] = tau_0;
      a[alpha1_tmp_tmp] = 1.0;
      lastv = tau_tmp;
      if (tau_0 != 0.0) {
        lastc = alpha1_tmp_tmp + tau_tmp;
        while ((lastv > 0) && (a[lastc - 1] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = ihi;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          rowleft = im1n + lastc;
          b_ia = rowleft;
          do {
            exitg1 = 0;
            if (b_ia <= ((lastv - 1) << 2) + rowleft) {
              if (a[b_ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                b_ia += 4;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        if (lastc != 0) {
          memset(&work[0], 0, (uint8_T)lastc * sizeof(real_T));
          ix = alpha1_tmp_tmp;
          b_ix = (((lastv - 1) << 2) + im1n) + 1;
          for (rowleft = im1n + 1; rowleft <= b_ix; rowleft += 4) {
            e = (rowleft + lastc) - 1;
            for (b_ia = rowleft; b_ia <= e; b_ia++) {
              work_tmp = b_ia - rowleft;
              work[work_tmp] += a[b_ia - 1] * a[ix];
            }

            ix++;
          }
        }

        tau_0 = -tau[i - 1];
        if (!(tau_0 == 0.0)) {
          rowleft = im1n + 1;
          ix = (uint8_T)lastv;
          for (lastv = 0; lastv < ix; lastv++) {
            temp = a[alpha1_tmp_tmp + lastv];
            if (temp != 0.0) {
              temp *= tau_0;
              b_ix = (lastc + rowleft) - 1;
              e = ((((b_ix - rowleft) + 1) / 2) << 1) + rowleft;
              work_tmp = e - 2;
              for (b_ia = rowleft; b_ia <= work_tmp; b_ia += 2) {
                tmp = _mm_loadu_pd(&work[b_ia - rowleft]);
                tmp_0 = _mm_loadu_pd(&a[b_ia - 1]);
                _mm_storeu_pd(&a[b_ia - 1], _mm_add_pd(_mm_mul_pd(tmp,
                  _mm_set1_pd(temp)), tmp_0));
              }

              for (b_ia = e; b_ia <= b_ix; b_ia++) {
                a[b_ia - 1] += work[b_ia - rowleft] * temp;
              }
            }

            rowleft += 4;
          }
        }
      }

      KIMMCar_xzlarf(tau_tmp, 4 - i, alpha1_tmp_tmp + 1, tau[i - 1], a, (i +
        im1n) + 1, work);
      a[alpha1_tmp_tmp] = alpha1;
    }
  }
}

static void KIMMCar_xzunghr(int32_T ilo, int32_T ihi, real_T A[16], const real_T
  tau[3])
{
  __m128d tmp;
  real_T work[4];
  int32_T b_ia;
  int32_T e;
  int32_T f_i;
  int32_T ia;
  int32_T itau;
  int32_T k;
  int32_T nh;
  int32_T scalarLB;
  int32_T vectorUB;
  nh = ihi - ilo;
  for (itau = ihi; itau >= ilo + 1; itau--) {
    ia = (itau - 1) << 2;
    memset(&A[ia], 0, (uint8_T)(itau - 1) * sizeof(real_T));
    for (f_i = itau + 1; f_i <= ihi; f_i++) {
      k = ia + f_i;
      A[k - 1] = A[k - 5];
    }

    if (ihi + 1 <= 4) {
      memset(&A[ihi + ia], 0, (uint32_T)(((ia - ihi) - ia) + 4) * sizeof(real_T));
    }
  }

  b_ia = (uint8_T)ilo;
  for (itau = 0; itau < b_ia; itau++) {
    ia = itau << 2;
    A[ia] = 0.0;
    A[ia + 1] = 0.0;
    A[ia + 2] = 0.0;
    A[ia + 3] = 0.0;
    A[ia + itau] = 1.0;
  }

  for (itau = ihi + 1; itau < 5; itau++) {
    ia = (itau - 1) << 2;
    A[ia] = 0.0;
    A[ia + 1] = 0.0;
    A[ia + 2] = 0.0;
    A[ia + 3] = 0.0;
    A[(ia + itau) - 1] = 1.0;
  }

  ia = (ilo << 2) + ilo;
  if (nh >= 1) {
    for (itau = nh; itau < nh; itau++) {
      b_ia = (itau << 2) + ia;
      memset(&A[b_ia], 0, (uint32_T)nh * sizeof(real_T));
      A[b_ia + itau] = 1.0;
    }

    itau = (ilo + nh) - 2;
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    work[3] = 0.0;
    for (f_i = nh; f_i >= 1; f_i--) {
      b_ia = (((f_i - 1) << 2) + ia) + f_i;
      if (f_i < nh) {
        A[b_ia - 1] = 1.0;
        k = nh - f_i;
        KIMMCar_xzlarf(k + 1, k, b_ia, tau[itau], A, b_ia + 4, work);
        e = (b_ia + nh) - f_i;
        scalarLB = ((((e - b_ia) / 2) << 1) + b_ia) + 1;
        vectorUB = scalarLB - 2;
        for (k = b_ia + 1; k <= vectorUB; k += 2) {
          tmp = _mm_loadu_pd(&A[k - 1]);
          _mm_storeu_pd(&A[k - 1], _mm_mul_pd(tmp, _mm_set1_pd(-tau[itau])));
        }

        for (k = scalarLB; k <= e; k++) {
          A[k - 1] *= -tau[itau];
        }
      }

      A[b_ia - 1] = 1.0 - tau[itau];
      e = (uint8_T)(f_i - 1);
      for (k = 0; k < e; k++) {
        A[(b_ia - k) - 2] = 0.0;
      }

      itau--;
    }
  }
}

static real_T KIMMCar_xnrm2_k(int32_T n, const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      scale = 3.3121686421112381E-170;
      absxk = fabs(x[1]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }

      absxk = fabs(x[2]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

static real_T KIMMCar_xzlarfg_l(int32_T n, real_T *alpha1, real_T x[3])
{
  __m128d tmp;
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T knt;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  tau = 0.0;
  if (n > 0) {
    xnorm = KIMMCar_xnrm2_k(n - 1, x);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          vectorUB = (((n - 1) / 2) << 1) + 2;
          vectorUB_tmp = vectorUB - 2;
          for (scalarLB = 2; scalarLB <= vectorUB_tmp; scalarLB += 2) {
            tmp = _mm_loadu_pd(&x[scalarLB - 1]);
            _mm_storeu_pd(&x[scalarLB - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (scalarLB = vectorUB; scalarLB <= n; scalarLB++) {
            x[scalarLB - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(*alpha1, KIMMCar_xnrm2_k(n - 1, x));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        for (scalarLB = 2; scalarLB <= vectorUB_tmp; scalarLB += 2) {
          tmp = _mm_loadu_pd(&x[scalarLB - 1]);
          _mm_storeu_pd(&x[scalarLB - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (scalarLB = vectorUB; scalarLB <= n; scalarLB++) {
          x[scalarLB - 1] *= a;
        }

        for (scalarLB = 0; scalarLB < knt; scalarLB++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        scalarLB = (((n - 1) / 2) << 1) + 2;
        vectorUB = scalarLB - 2;
        for (knt = 2; knt <= vectorUB; knt += 2) {
          tmp = _mm_loadu_pd(&x[knt - 1]);
          _mm_storeu_pd(&x[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (knt = scalarLB; knt <= n; knt++) {
          x[knt - 1] *= a;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

static void KIMMCar_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T
  *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  real_T bcmax;
  real_T bcmis;
  real_T p;
  real_T scale;
  real_T temp;
  real_T z;
  int32_T count;
  int32_T tmp;
  boolean_T tmp_0;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    temp = *d;
    *d = *a;
    *a = temp;
    *b = -*c;
    *c = 0.0;
  } else {
    temp = *a - *d;
    if ((temp == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      p = 0.5 * temp;
      bcmis = fabs(*b);
      scale = fabs(*c);
      tmp_0 = rtIsNaN(scale);
      if ((bcmis >= scale) || tmp_0) {
        bcmax = bcmis;
      } else {
        bcmax = scale;
      }

      if ((bcmis <= scale) || tmp_0) {
        scale = bcmis;
      }

      if (!(*b < 0.0)) {
        count = 1;
      } else {
        count = -1;
      }

      if (!(*c < 0.0)) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      bcmis = scale * (real_T)count * (real_T)tmp;
      scale = fabs(p);
      if ((!(scale >= bcmax)) && (!rtIsNaN(bcmax))) {
        scale = bcmax;
      }

      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        if (!(p < 0.0)) {
          temp = sqrt(scale) * sqrt(z);
        } else {
          temp = -(sqrt(scale) * sqrt(z));
        }

        z = p + temp;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        bcmax = rt_hypotd_snf(*c, z);
        *cs = z / bcmax;
        *sn = *c / bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        p = *b + *c;
        bcmis = fabs(temp);
        scale = fabs(p);
        if ((bcmis >= scale) || rtIsNaN(scale)) {
          scale = bcmis;
        }

        count = 0;
        while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
          p *= 1.3435752215134178E-138;
          temp *= 1.3435752215134178E-138;
          bcmis = fabs(temp);
          scale = fabs(p);
          if ((bcmis >= scale) || rtIsNaN(scale)) {
            scale = bcmis;
          }

          count++;
        }

        while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
          p *= 7.4428285367870146E+137;
          temp *= 7.4428285367870146E+137;
          bcmis = fabs(temp);
          scale = fabs(p);
          if ((bcmis >= scale) || rtIsNaN(scale)) {
            scale = bcmis;
          }

          count++;
        }

        bcmax = rt_hypotd_snf(p, temp);
        *cs = sqrt((fabs(p) / bcmax + 1.0) * 0.5);
        if (!(p < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }

        *sn = -(0.5 * temp / (bcmax * *cs)) * (real_T)count;
        temp = *a * *cs + *b * *sn;
        p = -*a * *sn + *b * *cs;
        bcmax = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = p * *cs + bcmis * *sn;
        *c = -temp * *sn + bcmax * *cs;
        temp = ((temp * *cs + bcmax * *sn) + (-p * *sn + bcmis * *cs)) * 0.5;
        *a = temp;
        *d = temp;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              scale = sqrt(fabs(*b));
              bcmis = sqrt(fabs(*c));
              p = scale * bcmis;
              if (*c < 0.0) {
                p = -p;
              }

              bcmax = 1.0 / sqrt(fabs(*b + *c));
              *a = temp + p;
              *d = temp - p;
              *b -= *c;
              *c = 0.0;
              p = scale * bcmax;
              bcmax *= bcmis;
              temp = *cs * p - *sn * bcmax;
              *sn = *cs * bcmax + *sn * p;
              *cs = temp;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            temp = *cs;
            *cs = -*sn;
            *sn = temp;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

static void KIMMCar_xdlahqr(int32_T ilo, int32_T ihi, real_T h[16], int32_T iloz,
  int32_T ihiz, real_T z[16], int32_T *info, real_T wr[4], real_T wi[4])
{
  __m128d tmp;
  real_T v[3];
  real_T bb;
  real_T h12;
  real_T h21;
  real_T h22;
  real_T h_0;
  real_T s;
  real_T s_tmp;
  real_T s_tmp_tmp;
  real_T smlnum;
  real_T tst;
  int32_T c_ix;
  int32_T h_tmp;
  int32_T h_tmp_0;
  int32_T i;
  int32_T ix0;
  int32_T iy;
  int32_T k;
  int32_T kdefl;
  int32_T l;
  int32_T m;
  int32_T nr;
  int32_T nz;
  int32_T v_tmp;
  boolean_T converged;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T tmp_0;
  *info = 0;
  l = (uint8_T)(ilo - 1);
  for (nz = 0; nz < l; nz++) {
    wr[nz] = h[(nz << 2) + nz];
    wi[nz] = 0.0;
  }

  for (nz = ihi + 1; nz < 5; nz++) {
    wr[nz - 1] = h[(((nz - 1) << 2) + nz) - 1];
    wi[nz - 1] = 0.0;
  }

  if (ilo == ihi) {
    wr[ilo - 1] = h[(((ilo - 1) << 2) + ilo) - 1];
    wi[ilo - 1] = 0.0;
  } else {
    for (nz = ilo; nz <= ihi - 3; nz++) {
      h[2] = 0.0;
      h[3] = 0.0;
    }

    if (ilo <= ihi - 2) {
      h[(ihi + ((ihi - 3) << 2)) - 1] = 0.0;
    }

    nz = (ihiz - iloz) + 1;
    smlnum = (real_T)((ihi - ilo) + 1) / 2.2204460492503131E-16 *
      2.2250738585072014E-308;
    kdefl = 0;
    i = ihi - 1;
    exitg1 = false;
    while ((!exitg1) && (i + 1 >= ilo)) {
      l = ilo;
      converged = false;
      iy = 0;
      exitg2 = false;
      while ((!exitg2) && (iy < 301)) {
        k = i;
        exitg3 = false;
        while ((!exitg3) && (k + 1 > l)) {
          m = ((k - 1) << 2) + k;
          h22 = fabs(h[m]);
          if (h22 <= smlnum) {
            exitg3 = true;
          } else {
            c_ix = (k << 2) + k;
            s = fabs(h[c_ix]);
            bb = h[m - 1];
            tst = fabs(bb) + s;
            if (tst == 0.0) {
              if (k - 1 >= ilo) {
                tst = fabs(h[(((k - 2) << 2) + k) - 1]);
              }

              if (k + 2 <= ihi) {
                tst += fabs(h[c_ix + 1]);
              }
            }

            if (h22 <= 2.2204460492503131E-16 * tst) {
              h22 = fabs(bb - h[c_ix]);
              tmp_0 = rtIsNaN(h22);
              if ((s >= h22) || tmp_0) {
                tst = s;
              } else {
                tst = h22;
              }

              bb = fabs(h[c_ix]);
              if ((!(bb <= h22)) && (!tmp_0)) {
                bb = h22;
              }

              s = tst + bb;
              h22 = fabs(h[m]);
              h21 = fabs(h[c_ix - 1]);
              tst = tst / s * bb * 2.2204460492503131E-16;
              tmp_0 = rtIsNaN(h21);
              if ((h22 <= h21) || tmp_0) {
                bb = h22;
              } else {
                bb = h21;
              }

              if ((h22 >= h21) || tmp_0) {
                h21 = h22;
              }

              if ((smlnum >= tst) || rtIsNaN(tst)) {
                tst = smlnum;
              }

              if (h21 / s * bb <= tst) {
                exitg3 = true;
              } else {
                k--;
              }
            } else {
              k--;
            }
          }
        }

        l = k + 1;
        if (k + 1 > ilo) {
          h[k + ((k - 1) << 2)] = 0.0;
        }

        if (k + 1 >= i) {
          converged = true;
          exitg2 = true;
        } else {
          kdefl++;
          if (kdefl - kdefl / 20 * 20 == 0) {
            s = fabs(h[(((i - 2) << 2) + i) - 1]) + fabs(h[((i - 1) << 2) + i]);
            bb = h[(i << 2) + i] + 0.75 * s;
            h12 = -0.4375 * s;
            h21 = s;
            h22 = bb;
          } else if (kdefl - kdefl / 10 * 10 == 0) {
            c_ix = (k << 2) + k;
            s = fabs(h[(((k + 1) << 2) + k) + 2]) + fabs(h[c_ix + 1]);
            bb = 0.75 * s + h[c_ix];
            h12 = -0.4375 * s;
            h21 = s;
            h22 = bb;
          } else {
            c_ix = ((i - 1) << 2) + i;
            bb = h[c_ix - 1];
            h21 = h[c_ix];
            c_ix = (i << 2) + i;
            h12 = h[c_ix - 1];
            h22 = h[c_ix];
          }

          s = ((fabs(bb) + fabs(h12)) + fabs(h21)) + fabs(h22);
          if (s == 0.0) {
            bb = 0.0;
            h22 = 0.0;
            tst = 0.0;
            h21 = 0.0;
          } else {
            bb /= s;
            h22 /= s;
            tst = (bb + h22) / 2.0;
            bb = (bb - tst) * (h22 - tst) - h12 / s * (h21 / s);
            h21 = sqrt(fabs(bb));
            if (bb >= 0.0) {
              bb = tst * s;
              tst = bb;
              h22 = h21 * s;
              h21 = -h22;
            } else {
              bb = tst + h21;
              tst -= h21;
              if (fabs(bb - h22) <= fabs(tst - h22)) {
                bb *= s;
                tst = bb;
              } else {
                tst *= s;
                bb = tst;
              }

              h22 = 0.0;
              h21 = 0.0;
            }
          }

          m = i - 1;
          exitg3 = false;
          while ((!exitg3) && (m >= k + 1)) {
            c_ix = ((m - 1) << 2) + m;
            s_tmp_tmp = h[c_ix - 1];
            s_tmp = s_tmp_tmp - tst;
            s = (fabs(s_tmp) + fabs(h21)) + fabs(h[c_ix]);
            h12 = h[c_ix] / s;
            v_tmp = (m << 2) + m;
            v[0] = (s_tmp / s * s_tmp + h[v_tmp - 1] * h12) - h21 / s * h22;
            v[1] = (((s_tmp_tmp + h[v_tmp]) - bb) - tst) * h12;
            v[2] = h[v_tmp + 1] * h12;
            s = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
            tmp = _mm_div_pd(_mm_loadu_pd(&v[0]), _mm_set1_pd(s));
            _mm_storeu_pd(&v[0], tmp);
            v[2] /= s;
            if ((k + 1 == m) || (fabs(h[m - 1]) * (fabs(v[1]) + fabs(v[2])) <=
                                 ((fabs(h[c_ix - 1]) + fabs(h[0])) + fabs
                                  (h[v_tmp])) * (2.2204460492503131E-16 * fabs
                  (v[0])))) {
              exitg3 = true;
            } else {
              m--;
            }
          }

          for (c_ix = m; c_ix <= i; c_ix++) {
            nr = (i - c_ix) + 2;
            if (nr >= 3) {
              nr = 3;
            }

            if (c_ix > m) {
              ix0 = (((c_ix - 2) << 2) + c_ix) - 1;
              for (v_tmp = 0; v_tmp < nr; v_tmp++) {
                v[v_tmp] = h[ix0 + v_tmp];
              }
            }

            h22 = v[0];
            s = KIMMCar_xzlarfg_l(nr, &h22, v);
            if (c_ix > m) {
              v_tmp = ((c_ix - 2) << 2) + c_ix;
              h[v_tmp - 1] = h22;
              h[v_tmp] = 0.0;
              if (c_ix < i) {
                h[c_ix + 1] = 0.0;
              }
            } else if (m > k + 1) {
              h[c_ix - 1] *= 1.0 - s;
            }

            h22 = v[1];
            tst = s * v[1];
            if (nr == 3) {
              h21 = v[2];
              h12 = s * v[2];
              for (v_tmp = c_ix; v_tmp < 5; v_tmp++) {
                ix0 = ((v_tmp - 1) << 2) + c_ix;
                s_tmp_tmp = h[ix0 - 1];
                s_tmp = h[ix0];
                h_0 = h[ix0 + 1];
                bb = (h22 * s_tmp + s_tmp_tmp) + h21 * h_0;
                h[ix0 - 1] = s_tmp_tmp - bb * s;
                h[ix0] = s_tmp - bb * tst;
                h[ix0 + 1] = h_0 - bb * h12;
              }

              if (c_ix + 3 <= i + 1) {
                nr = (uint8_T)(c_ix + 3);
              } else {
                nr = (uint8_T)(i + 1);
              }

              for (v_tmp = 0; v_tmp < nr; v_tmp++) {
                ix0 = ((c_ix - 1) << 2) + v_tmp;
                s_tmp_tmp = h[ix0];
                h_tmp = (c_ix << 2) + v_tmp;
                s_tmp = h[h_tmp];
                h_tmp_0 = ((c_ix + 1) << 2) + v_tmp;
                h_0 = h[h_tmp_0];
                bb = (h22 * s_tmp + s_tmp_tmp) + h21 * h_0;
                h[ix0] = s_tmp_tmp - bb * s;
                h[h_tmp] = s_tmp - bb * tst;
                h[h_tmp_0] = h_0 - bb * h12;
              }

              for (v_tmp = iloz; v_tmp <= ihiz; v_tmp++) {
                nr = (((c_ix - 1) << 2) + v_tmp) - 1;
                s_tmp_tmp = z[nr];
                ix0 = ((c_ix << 2) + v_tmp) - 1;
                s_tmp = z[ix0];
                h_tmp = (((c_ix + 1) << 2) + v_tmp) - 1;
                h_0 = z[h_tmp];
                bb = (h22 * s_tmp + s_tmp_tmp) + h21 * h_0;
                z[nr] = s_tmp_tmp - bb * s;
                z[ix0] = s_tmp - bb * tst;
                z[h_tmp] = h_0 - bb * h12;
              }
            } else if (nr == 2) {
              for (v_tmp = c_ix; v_tmp < 5; v_tmp++) {
                ix0 = ((v_tmp - 1) << 2) + c_ix;
                s_tmp_tmp = h[ix0 - 1];
                s_tmp = h[ix0];
                bb = h22 * s_tmp + s_tmp_tmp;
                h[ix0 - 1] = s_tmp_tmp - bb * s;
                h[ix0] = s_tmp - bb * tst;
              }

              nr = (uint8_T)(i + 1);
              for (v_tmp = 0; v_tmp < nr; v_tmp++) {
                ix0 = ((c_ix - 1) << 2) + v_tmp;
                s_tmp_tmp = h[ix0];
                h_tmp = (c_ix << 2) + v_tmp;
                s_tmp = h[h_tmp];
                bb = h22 * s_tmp + s_tmp_tmp;
                h[ix0] = s_tmp_tmp - bb * s;
                h[h_tmp] = s_tmp - bb * tst;
              }

              for (v_tmp = iloz; v_tmp <= ihiz; v_tmp++) {
                nr = (((c_ix - 1) << 2) + v_tmp) - 1;
                s_tmp_tmp = z[nr];
                ix0 = ((c_ix << 2) + v_tmp) - 1;
                s_tmp = z[ix0];
                bb = h22 * s_tmp + s_tmp_tmp;
                z[nr] = s_tmp_tmp - bb * s;
                z[ix0] = s_tmp - bb * tst;
              }
            }
          }

          iy++;
        }
      }

      if (!converged) {
        *info = i + 1;
        exitg1 = true;
      } else {
        if (i + 1 == l) {
          wr[i] = h[(i << 2) + i];
          wi[i] = 0.0;
        } else if (l == i) {
          m = i << 2;
          iy = m + i;
          tst = h[iy - 1];
          kdefl = (i - 1) << 2;
          c_ix = kdefl + i;
          bb = h[c_ix];
          h21 = h[iy];
          KIMMCar_xdlanv2(&h[c_ix - 1], &tst, &bb, &h21, &wr[i - 1], &wi[i - 1],
                          &h12, &s_tmp_tmp, &s, &h22);
          wr[i] = h12;
          wi[i] = s_tmp_tmp;
          h[iy - 1] = tst;
          h[c_ix] = bb;
          h[iy] = h21;
          if (i + 1 < 4) {
            nr = ((i + 1) << 2) + i;
            k = (uint8_T)(3 - i);
            for (c_ix = 0; c_ix < k; c_ix++) {
              iy = c_ix << 2;
              v_tmp = iy + nr;
              tst = h[v_tmp];
              iy = (iy + nr) - 1;
              bb = h[iy];
              h[v_tmp] = tst * s - bb * h22;
              h[iy] = bb * s + tst * h22;
            }
          }

          if (i - 1 >= 1) {
            k = (uint8_T)(i - 1);
            for (c_ix = 0; c_ix < k; c_ix++) {
              v_tmp = m + c_ix;
              tst = h[v_tmp];
              iy = kdefl + c_ix;
              bb = h[iy];
              h[v_tmp] = tst * s - bb * h22;
              h[iy] = bb * s + tst * h22;
            }
          }

          if (nz >= 1) {
            c_ix = (kdefl + iloz) - 1;
            kdefl = (m + iloz) - 1;
            iy = (uint8_T)nz;
            for (i = 0; i < iy; i++) {
              m = kdefl + i;
              tst = z[m];
              v_tmp = c_ix + i;
              bb = z[v_tmp];
              z[m] = tst * s - bb * h22;
              z[v_tmp] = bb * s + tst * h22;
            }
          }
        }

        kdefl = 0;
        i = l - 2;
      }
    }

    for (nz = 0; nz < 2; nz++) {
      for (l = nz + 3; l < 5; l++) {
        h[(l + (nz << 2)) - 1] = 0.0;
      }
    }
  }
}

static void KIMMCar_xgemv(int32_T n, const real_T x[12], real_T beta1, real_T y
  [16], int32_T iy0)
{
  int32_T b;
  int32_T c_iy;
  int32_T ix;
  int32_T iyend;
  int32_T tmp;
  iyend = iy0 + 3;
  if (beta1 != 1.0) {
    for (c_iy = iy0; c_iy <= iyend; c_iy++) {
      if (beta1 == 0.0) {
        y[c_iy - 1] = 0.0;
      } else {
        y[c_iy - 1] *= beta1;
      }
    }
  }

  ix = 8;
  b = ((n - 1) << 2) + 1;
  for (iyend = 1; iyend <= b; iyend += 4) {
    for (c_iy = iyend; c_iy <= iyend + 3; c_iy++) {
      tmp = ((iy0 + c_iy) - iyend) - 1;
      y[tmp] += y[c_iy - 1] * x[ix];
    }

    ix++;
  }
}

static void KIMMCar_dladiv1(real_T a, real_T b, real_T c, real_T d, real_T *p,
  real_T *q)
{
  real_T br;
  real_T r;
  real_T t;
  r = d / c;
  t = 1.0 / (d * r + c);
  if (r != 0.0) {
    br = b * r;
    if (br != 0.0) {
      *p = (a + br) * t;
    } else {
      *p = b * t * r + a * t;
    }

    br = -a * r;
    if (br != 0.0) {
      *q = (b + br) * t;
    } else {
      *q = -a * t * r + b * t;
    }
  } else {
    *p = (b / c * d + a) * t;
    *q = (-a / c * d + b) * t;
  }
}

static void KIMMCar_xdladiv(real_T a, real_T b, real_T c, real_T d, real_T *p,
  real_T *q)
{
  real_T aa;
  real_T ab;
  real_T bb;
  real_T cc;
  real_T cd;
  real_T cd_tmp;
  real_T cd_tmp_0;
  real_T dd;
  real_T s;
  aa = a;
  bb = b;
  cc = c;
  dd = d;
  s = fabs(a);
  ab = fabs(b);
  if ((s >= ab) || rtIsNaN(ab)) {
    ab = s;
  }

  cd_tmp = fabs(d);
  cd_tmp_0 = fabs(c);
  if ((cd_tmp_0 >= cd_tmp) || rtIsNaN(cd_tmp)) {
    cd = cd_tmp_0;
  } else {
    cd = cd_tmp;
  }

  s = 1.0;
  if (ab >= 8.9884656743115785E+307) {
    aa = 0.5 * a;
    bb = 0.5 * b;
    s = 2.0;
  }

  if (cd >= 8.9884656743115785E+307) {
    cc = 0.5 * c;
    dd = 0.5 * d;
    s *= 0.5;
  }

  if (ab <= 2.0041683600089728E-292) {
    aa *= 4.0564819207303341E+31;
    bb *= 4.0564819207303341E+31;
    s /= 4.0564819207303341E+31;
  }

  if (cd <= 2.0041683600089728E-292) {
    cc *= 4.0564819207303341E+31;
    dd *= 4.0564819207303341E+31;
    s *= 4.0564819207303341E+31;
  }

  if (cd_tmp <= cd_tmp_0) {
    KIMMCar_dladiv1(aa, bb, cc, dd, p, q);
  } else {
    KIMMCar_dladiv1(bb, aa, dd, cc, p, &ab);
    *q = -ab;
  }

  *p *= s;
  *q *= s;
}

static void KIMMCar_xdlaln2(int32_T na, int32_T nw, real_T smin, const real_T A
  [16], int32_T ia0, const real_T B[12], int32_T ib0, real_T wr, real_T wi,
  real_T X[4], real_T *scale, real_T *xnorm)
{
  __m128d tmp_1;
  __m128d tmp_2;
  real_T ci[4];
  real_T cr[4];
  real_T tmp[2];
  real_T bi1;
  real_T bi2;
  real_T br2;
  real_T cmax;
  real_T li21;
  real_T lr21;
  real_T temp;
  real_T u22abs;
  real_T ui11r;
  real_T ui12s;
  real_T ui22;
  real_T ur11r;
  real_T ur12s;
  real_T ur22;
  int32_T icmax;
  int32_T lr21_tmp;
  int32_T tmp_0;
  static const int8_T b[16] = { 1, 2, 3, 4, 2, 1, 4, 3, 3, 4, 1, 2, 4, 3, 2, 1 };

  *scale = 1.0;
  if (na == 1) {
    if (nw == 1) {
      ur11r = A[ia0 - 1] - wr;
      ui11r = fabs(ur11r);
      if (ui11r < smin) {
        ur11r = smin;
        ui11r = smin;
      }

      lr21 = B[ib0 - 1];
      cmax = fabs(lr21);
      if ((ui11r < 1.0) && (cmax > 1.0) && (cmax > 2.2471164185778949E+307 *
           ui11r)) {
        *scale = 1.0 / cmax;
      }

      X[0] = lr21 * *scale / ur11r;
      *xnorm = fabs(X[0]);
    } else {
      ur11r = A[ia0 - 1] - wr;
      temp = -wi;
      ui11r = fabs(ur11r) + fabs(-wi);
      if (ui11r < smin) {
        ur11r = smin;
        temp = 0.0;
        ui11r = smin;
      }

      lr21 = B[ib0 - 1];
      ur22 = B[ib0 + 3];
      cmax = fabs(lr21) + fabs(ur22);
      if ((ui11r < 1.0) && (cmax > 1.0) && (cmax > 2.2471164185778949E+307 *
           ui11r)) {
        *scale = 1.0 / cmax;
      }

      KIMMCar_xdladiv(*scale * lr21, *scale * ur22, ur11r, temp, &X[0], &X[2]);
      *xnorm = fabs(X[0]) + fabs(X[2]);
    }
  } else {
    _mm_storeu_pd(&tmp[0], _mm_sub_pd(_mm_set_pd(A[ia0 + 4], A[ia0 - 1]),
      _mm_set1_pd(wr)));
    cr[0] = tmp[0];
    cr[3] = tmp[1];
    cr[1] = A[ia0];
    cr[2] = A[ia0 + 3];
    if (nw == 1) {
      cmax = 0.0;
      icmax = -1;
      ui11r = fabs(tmp[0]);
      if (ui11r > 0.0) {
        cmax = ui11r;
        icmax = 0;
      }

      ui11r = fabs(cr[1]);
      if (ui11r > cmax) {
        cmax = ui11r;
        icmax = 1;
      }

      ui11r = fabs(cr[2]);
      if (ui11r > cmax) {
        cmax = ui11r;
        icmax = 2;
      }

      ui11r = fabs(tmp[1]);
      if (ui11r > cmax) {
        cmax = ui11r;
        icmax = 3;
      }

      if (cmax < smin) {
        ur11r = B[ib0 - 1];
        li21 = fabs(ur11r);
        cmax = fabs(B[ib0]);
        if ((li21 >= cmax) || rtIsNaN(cmax)) {
          cmax = li21;
        }

        if ((smin < 1.0) && (cmax > 1.0) && (cmax > 2.2471164185778949E+307 *
             smin)) {
          *scale = 1.0 / cmax;
        }

        temp = *scale / smin;
        _mm_storeu_pd(&X[0], _mm_mul_pd(_mm_set_pd(temp, ur11r), _mm_set_pd
          (B[ib0], temp)));
        *xnorm = temp * cmax;
      } else {
        ur11r = 1.0 / cr[icmax];
        lr21_tmp = icmax << 2;
        lr21 = cr[b[lr21_tmp + 1] - 1] * ur11r;
        ur12s = cr[b[lr21_tmp + 2] - 1];
        ur22 = cr[b[lr21_tmp + 3] - 1] - ur12s * lr21;
        if (fabs(ur22) < smin) {
          ur22 = smin;
        }

        if ((icmax + 1 == 2) || (icmax + 1 == 4)) {
          temp = B[ib0];
          br2 = B[ib0 - 1];
        } else {
          temp = B[ib0 - 1];
          br2 = B[ib0];
        }

        br2 -= lr21 * temp;
        li21 = fabs(ur22 * ur11r * temp);
        lr21 = fabs(br2);
        if ((li21 >= lr21) || rtIsNaN(lr21)) {
          lr21 = li21;
        }

        if (lr21 > 1.0) {
          ui11r = fabs(ur22);
          if ((ui11r < 1.0) && (lr21 >= 2.2471164185778949E+307 * ui11r)) {
            *scale = 1.0 / lr21;
          }
        }

        ui11r = br2 * *scale / ur22;
        ur22 = *scale * temp * ur11r - ur12s * ur11r * ui11r;
        if ((icmax + 1 == 3) || (icmax + 1 == 4)) {
          X[0] = ui11r;
          X[1] = ur22;
        } else {
          X[0] = ur22;
          X[1] = ui11r;
        }

        li21 = fabs(ur22);
        *xnorm = fabs(ui11r);
        if ((li21 >= *xnorm) || rtIsNaN(*xnorm)) {
          *xnorm = li21;
        }

        if ((*xnorm > 1.0) && (cmax > 1.0) && (*xnorm > 2.2471164185778949E+307 /
             cmax)) {
          temp = cmax / 2.2471164185778949E+307;
          tmp_1 = _mm_mul_pd(_mm_set1_pd(temp), _mm_loadu_pd(&X[0]));
          _mm_storeu_pd(&X[0], tmp_1);
          *xnorm *= temp;
          *scale *= temp;
        }
      }
    } else {
      ci[0] = -wi;
      ci[1] = 0.0;
      ci[2] = 0.0;
      ci[3] = -wi;
      cmax = 0.0;
      icmax = -1;
      ur11r = fabs(-wi);
      temp = fabs(tmp[0]) + ur11r;
      if (temp > 0.0) {
        cmax = temp;
        icmax = 0;
      }

      temp = fabs(cr[1]);
      if (temp > cmax) {
        cmax = temp;
        icmax = 1;
      }

      temp = fabs(cr[2]);
      if (temp > cmax) {
        cmax = temp;
        icmax = 2;
      }

      temp = fabs(tmp[1]) + ur11r;
      if (temp > cmax) {
        cmax = temp;
        icmax = 3;
      }

      if (cmax < smin) {
        br2 = B[ib0 - 1];
        _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_set_pd(fabs(B[ib0 + 4]), fabs(br2)),
          _mm_set_pd(fabs(B[ib0]), fabs(B[ib0 + 3]))));
        if ((tmp[0] >= tmp[1]) || rtIsNaN(tmp[1])) {
          cmax = tmp[0];
        } else {
          cmax = tmp[1];
        }

        if ((smin < 1.0) && (cmax > 1.0) && (cmax > 2.2471164185778949E+307 *
             smin)) {
          *scale = 1.0 / cmax;
        }

        temp = *scale / smin;
        _mm_storeu_pd(&X[0], _mm_mul_pd(_mm_set_pd(temp, br2), _mm_set_pd(B[ib0],
          temp)));
        _mm_storeu_pd(&X[2], _mm_mul_pd(_mm_loadu_pd(&B[ib0 + 3]), _mm_set1_pd
          (temp)));
        *xnorm = temp * cmax;
      } else {
        if ((icmax + 1 == 1) || (icmax + 1 == 4)) {
          if (fabs(cr[icmax]) > fabs(ci[icmax])) {
            temp = ci[icmax] / cr[icmax];
            ur11r = 1.0 / ((temp * temp + 1.0) * cr[icmax]);
            ui11r = -temp * ur11r;
          } else {
            temp = cr[icmax] / ci[icmax];
            ui11r = -1.0 / ((temp * temp + 1.0) * ci[icmax]);
            ur11r = -temp * ui11r;
          }

          lr21_tmp = icmax << 2;
          tmp_1 = _mm_set_pd(ui11r, ur11r);
          _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set1_pd(cr[b[lr21_tmp + 1] - 1]),
            tmp_1));
          lr21 = tmp[0];
          li21 = tmp[1];
          tmp_2 = _mm_set1_pd(cr[b[lr21_tmp + 2] - 1]);
          _mm_storeu_pd(&tmp[0], _mm_mul_pd(tmp_2, tmp_1));
          ur12s = tmp[0];
          ui12s = tmp[1];
          lr21_tmp = b[lr21_tmp + 3] - 1;
          _mm_storeu_pd(&tmp[0], _mm_sub_pd(_mm_set_pd(ci[lr21_tmp], cr[lr21_tmp]),
            _mm_mul_pd(tmp_2, _mm_set_pd(li21, lr21))));
          ur22 = tmp[0];
          ui22 = tmp[1];
        } else {
          ur11r = 1.0 / cr[icmax];
          ui11r = 0.0;
          lr21_tmp = icmax << 2;
          tmp_0 = b[lr21_tmp + 1] - 1;
          tmp_1 = _mm_set1_pd(ur11r);
          _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set_pd(ci[tmp_0], cr[tmp_0]),
            tmp_1));
          lr21 = tmp[0];
          li21 = tmp[1];
          tmp_0 = b[lr21_tmp + 2] - 1;
          br2 = cr[tmp_0];
          temp = ci[tmp_0];
          _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set_pd(temp, br2), tmp_1));
          ur12s = tmp[0];
          ui12s = tmp[1];
          ur22 = (cr[b[lr21_tmp + 3] - 1] - br2 * lr21) + temp * li21;
          ui22 = -br2 * li21 - temp * lr21;
        }

        u22abs = fabs(ur22) + fabs(ui22);
        if (u22abs < smin) {
          ur22 = smin;
          ui22 = 0.0;
        }

        if ((icmax + 1 == 2) || (icmax + 1 == 4)) {
          br2 = B[ib0 - 1];
          temp = B[ib0];
          bi2 = B[ib0 + 3];
          bi1 = B[ib0 + 4];
        } else {
          temp = B[ib0 - 1];
          br2 = B[ib0];
          bi1 = B[ib0 + 3];
          bi2 = B[ib0 + 4];
        }

        br2 = (br2 - lr21 * temp) + li21 * bi1;
        bi2 = (bi2 - li21 * temp) - lr21 * bi1;
        li21 = (fabs(ur11r) + fabs(ui11r)) * u22abs * (fabs(temp) + fabs(bi1));
        lr21 = fabs(br2) + fabs(bi2);
        if ((li21 >= lr21) || rtIsNaN(lr21)) {
          lr21 = li21;
        }

        if ((lr21 > 1.0) && (u22abs < 1.0) && (lr21 >= 2.2471164185778949E+307 *
             u22abs)) {
          *scale = 1.0 / lr21;
          temp *= *scale;
          bi1 *= *scale;
          br2 *= *scale;
          bi2 *= *scale;
        }

        KIMMCar_xdladiv(br2, bi2, ur22, ui22, &u22abs, &lr21);
        ur22 = ((ur11r * temp - ui11r * bi1) - ur12s * u22abs) + ui12s * lr21;
        ur11r = ((ui11r * temp + ur11r * bi1) - ui12s * u22abs) - ur12s * lr21;
        if ((icmax + 1 == 3) || (icmax + 1 == 4)) {
          X[0] = u22abs;
          X[1] = ur22;
          X[2] = lr21;
          X[3] = ur11r;
        } else {
          X[0] = ur22;
          X[1] = u22abs;
          X[2] = ur11r;
          X[3] = lr21;
        }

        li21 = fabs(ur22) + fabs(ur11r);
        *xnorm = fabs(u22abs) + fabs(lr21);
        if ((li21 >= *xnorm) || rtIsNaN(*xnorm)) {
          *xnorm = li21;
        }

        if ((*xnorm > 1.0) && (cmax > 1.0) && (*xnorm > 2.2471164185778949E+307 /
             cmax)) {
          temp = cmax / 2.2471164185778949E+307;
          tmp_1 = _mm_set1_pd(temp);
          tmp_2 = _mm_mul_pd(tmp_1, _mm_loadu_pd(&X[0]));
          _mm_storeu_pd(&X[0], tmp_2);
          tmp_1 = _mm_mul_pd(tmp_1, _mm_loadu_pd(&X[2]));
          _mm_storeu_pd(&X[2], tmp_1);
          *xnorm *= temp;
          *scale *= temp;
        }
      }
    }
  }
}

static void KIMMCar_xaxpy(int32_T n, real_T a, const real_T x[16], int32_T ix0,
  real_T y[12])
{
  __m128d tmp;
  int32_T k;
  int32_T scalarLB;
  int32_T vectorUB;
  if ((n >= 1) && (!(a == 0.0))) {
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp = _mm_loadu_pd(&y[k + 8]);
      _mm_storeu_pd(&y[k + 8], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x[(ix0 + k) -
        1]), _mm_set1_pd(a)), tmp));
    }

    for (k = scalarLB; k < n; k++) {
      y[k + 8] += x[(ix0 + k) - 1] * a;
    }
  }
}

static void KIMMCar_xdtrevc3(const real_T T[16], real_T vr[16])
{
  __m128d tmp;
  real_T work[12];
  real_T x[4];
  real_T tmp_0[2];
  real_T rec;
  real_T scale;
  real_T smin;
  real_T u0;
  real_T wi;
  real_T wr;
  int32_T T_tmp;
  int32_T T_tmp_0;
  int32_T T_tmp_tmp;
  int32_T b_ix;
  int32_T b_j;
  int32_T exitg1;
  int32_T ip;
  int32_T iyend;
  int32_T j;
  int32_T scalarLB_tmp;
  int32_T vectorUB;
  boolean_T guard1;
  memset(&work[0], 0, 12U * sizeof(real_T));
  x[0] = 0.0;
  x[1] = 0.0;
  x[2] = 0.0;
  x[3] = 0.0;
  work[0] = 0.0;
  for (b_j = 0; b_j < 3; b_j++) {
    work[b_j + 1] = 0.0;
    for (ip = 0; ip <= b_j; ip++) {
      work[b_j + 1] += fabs(T[((b_j + 1) << 2) + ip]);
    }
  }

  ip = 0;
  for (b_j = 3; b_j >= 0; b_j--) {
    if (ip == -1) {
      ip = 1;
    } else {
      if ((b_j + 1 == 1) || (T[((b_j - 1) << 2) + b_j] == 0.0)) {
        ip = 0;
      } else {
        ip = -1;
      }

      T_tmp_tmp = b_j << 2;
      T_tmp = T_tmp_tmp + b_j;
      wr = T[T_tmp];
      wi = 0.0;
      if (ip != 0) {
        wi = sqrt(fabs(T[((b_j - 1) << 2) + b_j])) * sqrt(fabs(T[T_tmp - 1]));
      }

      smin = (fabs(wr) + wi) * 2.2204460492503131E-16;
      if (!(smin >= 4.0083367200179456E-292)) {
        smin = 4.0083367200179456E-292;
      }

      if (ip == 0) {
        work[b_j + 8] = 1.0;
        b_ix = (b_j / 2) << 1;
        vectorUB = b_ix - 2;
        for (j = 0; j <= vectorUB; j += 2) {
          _mm_storeu_pd(&work[j + 8], _mm_mul_pd(_mm_loadu_pd(&T[T_tmp_tmp + j]),
            _mm_set1_pd(-1.0)));
        }

        for (j = b_ix; j < b_j; j++) {
          work[j + 8] = -T[T_tmp_tmp + j];
        }

        j = b_j - 1;
        do {
          exitg1 = 0;
          if (j + 1 >= 1) {
            guard1 = false;
            if (j + 1 == 1) {
              guard1 = true;
            } else {
              T_tmp = (j - 1) << 2;
              T_tmp_0 = T_tmp + j;
              if (T[T_tmp_0] == 0.0) {
                guard1 = true;
              } else {
                KIMMCar_xdlaln2(2, 1, smin, T, T_tmp_0, work, j + 8, wr, 0.0, x,
                                &scale, &wi);
                if (wi > 1.0) {
                  u0 = work[j - 1];
                  rec = work[j];
                  if ((u0 >= rec) || rtIsNaN(rec)) {
                    rec = u0;
                  }

                  if (rec > 2.4948003869183992E+291 / wi) {
                    tmp = _mm_div_pd(_mm_loadu_pd(&x[0]), _mm_set1_pd(wi));
                    _mm_storeu_pd(&x[0], tmp);
                    scale /= wi;
                  }
                }

                if (scale != 1.0) {
                  b_ix = (((b_j + 1) / 2) << 1) + 9;
                  vectorUB = b_ix - 2;
                  for (iyend = 9; iyend <= vectorUB; iyend += 2) {
                    tmp = _mm_loadu_pd(&work[iyend - 1]);
                    _mm_storeu_pd(&work[iyend - 1], _mm_mul_pd(tmp, _mm_set1_pd
                      (scale)));
                  }

                  for (iyend = b_ix; iyend <= b_j + 9; iyend++) {
                    work[iyend - 1] *= scale;
                  }
                }

                work[j + 7] = x[0];
                work[j + 8] = x[1];
                KIMMCar_xaxpy(j - 1, -x[0], T, T_tmp + 1, work);
                KIMMCar_xaxpy(j - 1, -x[1], T, (j << 2) + 1, work);
                j -= 2;
              }
            }

            if (guard1) {
              T_tmp = j << 2;
              KIMMCar_xdlaln2(1, 1, smin, T, (T_tmp + j) + 1, work, j + 9, wr,
                              0.0, x, &scale, &wi);
              if ((wi > 1.0) && (work[j] > 2.4948003869183992E+291 / wi)) {
                x[0] /= wi;
                scale /= wi;
              }

              if (scale != 1.0) {
                b_ix = (((b_j + 1) / 2) << 1) + 9;
                vectorUB = b_ix - 2;
                for (iyend = 9; iyend <= vectorUB; iyend += 2) {
                  tmp = _mm_loadu_pd(&work[iyend - 1]);
                  _mm_storeu_pd(&work[iyend - 1], _mm_mul_pd(tmp, _mm_set1_pd
                    (scale)));
                }

                for (iyend = b_ix; iyend <= b_j + 9; iyend++) {
                  work[iyend - 1] *= scale;
                }
              }

              work[j + 8] = x[0];
              KIMMCar_xaxpy(j, -x[0], T, T_tmp + 1, work);
              j--;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        if (b_j + 1 > 1) {
          KIMMCar_xgemv(b_j, work, work[b_j + 8], vr, T_tmp_tmp + 1);
        }

        iyend = -1;
        wr = fabs(vr[T_tmp_tmp]);
        T_tmp_0 = T_tmp_tmp + 1;
        smin = fabs(vr[T_tmp_tmp + 1]);
        if (smin > wr) {
          iyend = 0;
          wr = smin;
        }

        smin = fabs(vr[T_tmp_tmp + 2]);
        if (smin > wr) {
          iyend = 1;
          wr = smin;
        }

        if (fabs(vr[T_tmp_tmp + 3]) > wr) {
          iyend = 2;
        }

        wr = 1.0 / fabs(vr[(T_tmp_tmp + iyend) + 1]);
        b_ix = T_tmp_tmp + 5;
        vectorUB = T_tmp_tmp + 3;
        for (j = T_tmp_0; j <= vectorUB; j += 2) {
          tmp = _mm_loadu_pd(&vr[j - 1]);
          _mm_storeu_pd(&vr[j - 1], _mm_mul_pd(tmp, _mm_set1_pd(wr)));
        }

        for (j = b_ix; j <= T_tmp_0 + 3; j++) {
          vr[j - 1] *= wr;
        }
      } else {
        T_tmp_0 = (b_j - 1) << 2;
        scale = T[T_tmp_0 + b_j];
        rec = T[T_tmp - 1];
        if (fabs(rec) >= fabs(scale)) {
          work[b_j + 3] = 1.0;
          work[b_j + 8] = wi / rec;
        } else {
          work[b_j + 3] = -wi / scale;
          work[b_j + 8] = 1.0;
        }

        work[b_j + 4] = 0.0;
        work[b_j + 7] = 0.0;
        for (j = 0; j <= b_j - 2; j++) {
          work[j + 4] = T[T_tmp_0 + j] * -work[b_j + 3];
          work[j + 8] = T[T_tmp_tmp + j] * -work[b_j + 8];
        }

        j = b_j - 2;
        while (j + 1 >= 1) {
          if ((j + 1 == 1) || (T[1] == 0.0)) {
            T_tmp = j << 2;
            KIMMCar_xdlaln2(1, 2, smin, T, (T_tmp + j) + 1, work, j + 5, wr, wi,
                            x, &scale, &rec);
            if ((rec > 1.0) && (work[j] > 2.4948003869183992E+291 / rec)) {
              _mm_storeu_pd(&tmp_0[0], _mm_div_pd(_mm_set_pd(x[2], x[0]),
                _mm_set1_pd(rec)));
              x[0] = tmp_0[0];
              x[2] = tmp_0[1];
              scale /= rec;
            }

            if (scale != 1.0) {
              scalarLB_tmp = ((b_j + 1) / 2) << 1;
              b_ix = scalarLB_tmp + 5;
              vectorUB = scalarLB_tmp + 3;
              for (iyend = 5; iyend <= vectorUB; iyend += 2) {
                tmp = _mm_loadu_pd(&work[iyend - 1]);
                _mm_storeu_pd(&work[iyend - 1], _mm_mul_pd(tmp, _mm_set1_pd
                  (scale)));
              }

              for (iyend = b_ix; iyend <= b_j + 5; iyend++) {
                work[iyend - 1] *= scale;
              }

              b_ix = scalarLB_tmp + 9;
              vectorUB = scalarLB_tmp + 7;
              for (iyend = 9; iyend <= vectorUB; iyend += 2) {
                tmp = _mm_loadu_pd(&work[iyend - 1]);
                _mm_storeu_pd(&work[iyend - 1], _mm_mul_pd(tmp, _mm_set1_pd
                  (scale)));
              }

              for (iyend = b_ix; iyend <= b_j + 9; iyend++) {
                work[iyend - 1] *= scale;
              }
            }

            work[j + 4] = x[0];
            work[j + 8] = x[2];
            if ((j >= 1) && (!(-x[0] == 0.0))) {
              work[4] += T[T_tmp] * -x[0];
            }

            KIMMCar_xaxpy(j, -x[2], T, T_tmp + 1, work);
            j--;
          } else {
            KIMMCar_xdlaln2(2, 2, smin, T, 1, work, 5, wr, wi, x, &scale, &rec);
            if (rec > 1.0) {
              if ((work[0] >= work[1]) || rtIsNaN(work[1])) {
                u0 = work[0];
              } else {
                u0 = work[1];
              }

              if (u0 > 2.4948003869183992E+291 / rec) {
                rec = 1.0 / rec;
                tmp = _mm_set1_pd(rec);
                _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_set_pd(x[2], x[0]), tmp));
                x[0] = tmp_0[0];
                x[2] = tmp_0[1];
                _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_set_pd(x[3], x[1]), tmp));
                x[1] = tmp_0[0];
                x[3] = tmp_0[1];
                scale *= rec;
              }
            }

            if (scale != 1.0) {
              scalarLB_tmp = ((b_j + 1) / 2) << 1;
              b_ix = scalarLB_tmp + 5;
              vectorUB = scalarLB_tmp + 3;
              for (j = 5; j <= vectorUB; j += 2) {
                tmp = _mm_loadu_pd(&work[j - 1]);
                _mm_storeu_pd(&work[j - 1], _mm_mul_pd(tmp, _mm_set1_pd(scale)));
              }

              for (j = b_ix; j <= b_j + 5; j++) {
                work[j - 1] *= scale;
              }

              b_ix = scalarLB_tmp + 9;
              vectorUB = scalarLB_tmp + 7;
              for (j = 9; j <= vectorUB; j += 2) {
                tmp = _mm_loadu_pd(&work[j - 1]);
                _mm_storeu_pd(&work[j - 1], _mm_mul_pd(tmp, _mm_set1_pd(scale)));
              }

              for (j = b_ix; j <= b_j + 9; j++) {
                work[j - 1] *= scale;
              }
            }

            work[4] = x[0];
            work[5] = x[1];
            work[8] = x[2];
            work[9] = x[3];
            KIMMCar_xaxpy(0, -x[2], T, 1, work);
            KIMMCar_xaxpy(0, -x[3], T, 5, work);
            j = -1;
          }
        }

        if (b_j + 1 > 2) {
          iyend = T_tmp_0 + 4;
          smin = work[b_j + 3];
          if (smin != 1.0) {
            for (j = T_tmp_0 + 1; j <= iyend; j++) {
              if (smin == 0.0) {
                vr[j - 1] = 0.0;
              } else {
                vr[j - 1] *= smin;
              }
            }
          }

          b_ix = 4;
          vectorUB = ((b_j - 2) << 2) + 1;
          for (iyend = 1; iyend <= vectorUB; iyend += 4) {
            for (j = iyend; j <= iyend + 3; j++) {
              T_tmp = (T_tmp_0 + j) - iyend;
              vr[T_tmp] += vr[j - 1] * work[b_ix];
            }

            b_ix++;
          }

          KIMMCar_xgemv(b_j - 1, work, work[b_j + 8], vr, T_tmp_tmp + 1);
        } else {
          iyend = T_tmp_0 + 1;
          b_ix = T_tmp_0 + 5;
          vectorUB = T_tmp_0 + 3;
          for (j = iyend; j <= vectorUB; j += 2) {
            tmp = _mm_loadu_pd(&vr[j - 1]);
            _mm_storeu_pd(&vr[j - 1], _mm_mul_pd(tmp, _mm_set1_pd(work[4])));
          }

          for (j = b_ix; j <= iyend + 3; j++) {
            vr[j - 1] *= work[4];
          }

          iyend = T_tmp_tmp + 1;
          b_ix = T_tmp_tmp + 5;
          vectorUB = T_tmp_tmp + 3;
          for (j = iyend; j <= vectorUB; j += 2) {
            tmp = _mm_loadu_pd(&vr[j - 1]);
            _mm_storeu_pd(&vr[j - 1], _mm_mul_pd(_mm_set1_pd(work[b_j + 8]), tmp));
          }

          for (j = b_ix; j <= iyend + 3; j++) {
            vr[j - 1] *= work[b_j + 8];
          }
        }

        wr = 0.0;
        rec = fabs(vr[T_tmp_0]) + fabs(vr[T_tmp_tmp]);
        if ((!(rec <= 0.0)) && (!rtIsNaN(rec))) {
          wr = rec;
        }

        T_tmp = T_tmp_0 + 1;
        iyend = T_tmp_tmp + 1;
        rec = fabs(vr[T_tmp_0 + 1]) + fabs(vr[T_tmp_tmp + 1]);
        if ((!(wr >= rec)) && (!rtIsNaN(rec))) {
          wr = rec;
        }

        rec = fabs(vr[T_tmp_0 + 2]) + fabs(vr[T_tmp_tmp + 2]);
        if ((!(wr >= rec)) && (!rtIsNaN(rec))) {
          wr = rec;
        }

        rec = fabs(vr[T_tmp_0 + 3]) + fabs(vr[T_tmp_tmp + 3]);
        if ((wr >= rec) || rtIsNaN(rec)) {
          rec = wr;
        }

        wr = 1.0 / rec;
        b_ix = T_tmp_0 + 5;
        vectorUB = T_tmp_0 + 3;
        for (j = T_tmp; j <= vectorUB; j += 2) {
          tmp = _mm_loadu_pd(&vr[j - 1]);
          _mm_storeu_pd(&vr[j - 1], _mm_mul_pd(tmp, _mm_set1_pd(wr)));
        }

        for (j = b_ix; j <= T_tmp + 3; j++) {
          vr[j - 1] *= wr;
        }

        b_ix = T_tmp_tmp + 5;
        vectorUB = T_tmp_tmp + 3;
        for (j = iyend; j <= vectorUB; j += 2) {
          tmp = _mm_loadu_pd(&vr[j - 1]);
          _mm_storeu_pd(&vr[j - 1], _mm_mul_pd(tmp, _mm_set1_pd(wr)));
        }

        for (j = b_ix; j <= iyend + 3; j++) {
          vr[j - 1] *= wr;
        }
      }
    }
  }
}

static void KIMMCar_xzlascl_e(real_T cfrom, real_T cto, int32_T m, real_T A[4],
  int32_T iA0)
{
  __m128d tmp;
  real_T cfrom1;
  real_T cfromc;
  real_T cto1;
  real_T ctoc;
  real_T mul;
  int32_T b_i;
  int32_T scalarLB;
  int32_T tmp_0;
  int32_T vectorUB;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    scalarLB = (m / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_i = 0; b_i <= vectorUB; b_i += 2) {
      tmp_0 = (b_i + iA0) - 1;
      tmp = _mm_loadu_pd(&A[tmp_0]);
      _mm_storeu_pd(&A[tmp_0], _mm_mul_pd(tmp, _mm_set1_pd(mul)));
    }

    for (b_i = scalarLB; b_i < m; b_i++) {
      tmp_0 = (b_i + iA0) - 1;
      A[tmp_0] *= mul;
    }
  }
}

static void KIMMCar_eigStandard(const real_T A[16], creal_T V[16], creal_T D[4])
{
  __m128d tmp;
  real_T b_A[16];
  real_T vr[16];
  real_T scale[4];
  real_T wi[4];
  real_T wr[4];
  real_T tau[3];
  real_T tmp_0[2];
  real_T absxk;
  real_T anrm;
  real_T b_temp;
  real_T gs;
  real_T gs_tmp;
  real_T gs_tmp_0;
  real_T s;
  real_T vr_0;
  real_T vr_tmp;
  real_T vr_tmp_0;
  real_T vr_tmp_1;
  int32_T b_k;
  int32_T b_temp_tmp;
  int32_T b_temp_tmp_tmp;
  int32_T b_temp_tmp_tmp_0;
  int32_T c_ix;
  int32_T ihi;
  int32_T info;
  int32_T k;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T exitg1;
  boolean_T scalea;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  anrm = 0.0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 16)) {
    absxk = fabs(A[b_k]);
    if (rtIsNaN(absxk)) {
      anrm = (rtNaN);
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      b_k++;
    }
  }

  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    D[0].re = (rtNaN);
    D[0].im = 0.0;
    D[1].re = (rtNaN);
    D[1].im = 0.0;
    D[2].re = (rtNaN);
    D[2].im = 0.0;
    D[3].re = (rtNaN);
    D[3].im = 0.0;
    for (b_temp_tmp_tmp = 0; b_temp_tmp_tmp < 16; b_temp_tmp_tmp++) {
      V[b_temp_tmp_tmp].re = (rtNaN);
      V[b_temp_tmp_tmp].im = 0.0;
    }
  } else {
    absxk = anrm;
    scalea = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      absxk = 6.7178761075670888E-139;
      KIMMCar_xzlascl(anrm, absxk, b_A);
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      absxk = 1.4885657073574029E+138;
      KIMMCar_xzlascl(anrm, absxk, b_A);
    }

    KIMMCar_xzgebal(b_A, &b_k, &ihi, scale);
    KIMMCar_xzgehrd(b_A, b_k, ihi, tau);
    memcpy(&vr[0], &b_A[0], sizeof(real_T) << 4U);
    KIMMCar_xzunghr(b_k, ihi, vr, tau);
    KIMMCar_xdlahqr(b_k, ihi, b_A, b_k, ihi, vr, &info, wr, wi);
    if (info == 0) {
      KIMMCar_xdtrevc3(b_A, vr);
      if (b_k != ihi) {
        for (k = b_k; k <= ihi; k++) {
          for (c_ix = k; c_ix <= k + 12; c_ix += 4) {
            vr[c_ix - 1] *= scale[k - 1];
          }
        }
      }

      for (k = b_k - 1; k >= 1; k--) {
        s = scale[k - 1];
        if ((int32_T)s != k) {
          b_temp = vr[k - 1];
          vr[k - 1] = vr[(int32_T)s - 1];
          vr[(int32_T)s - 1] = b_temp;
          b_temp = vr[k + 3];
          vr[k + 3] = vr[(int32_T)s + 3];
          vr[(int32_T)s + 3] = b_temp;
          b_temp = vr[k + 7];
          vr[k + 7] = vr[(int32_T)s + 7];
          vr[(int32_T)s + 7] = b_temp;
          b_temp = vr[k + 11];
          vr[k + 11] = vr[(int32_T)s + 11];
          vr[(int32_T)s + 11] = b_temp;
        }
      }

      for (k = ihi + 1; k < 5; k++) {
        s = scale[k - 1];
        if ((int32_T)s != k) {
          b_temp = vr[k - 1];
          vr[k - 1] = vr[(int32_T)s - 1];
          vr[(int32_T)s - 1] = b_temp;
          b_temp = vr[k + 3];
          vr[k + 3] = vr[(int32_T)s + 3];
          vr[(int32_T)s + 3] = b_temp;
          b_temp = vr[k + 7];
          vr[k + 7] = vr[(int32_T)s + 7];
          vr[(int32_T)s + 7] = b_temp;
          b_temp = vr[k + 11];
          vr[k + 11] = vr[(int32_T)s + 11];
          vr[(int32_T)s + 11] = b_temp;
        }
      }

      for (ihi = 0; ihi < 4; ihi++) {
        b_temp = wi[ihi];
        if (!(b_temp < 0.0)) {
          if ((ihi + 1 != 4) && (b_temp > 0.0)) {
            b_temp_tmp_tmp = ihi << 2;
            k = b_temp_tmp_tmp + 1;
            b_temp_tmp_tmp_0 = (ihi + 1) << 2;
            b_temp_tmp = b_temp_tmp_tmp_0 + 1;
            b_temp = 1.0 / rt_hypotd_snf(KIMMCar_xnrm2(4, vr, b_temp_tmp_tmp + 1),
              KIMMCar_xnrm2(4, vr, b_temp_tmp_tmp_0 + 1));
            scalarLB = b_temp_tmp_tmp + 5;
            vectorUB = b_temp_tmp_tmp + 3;
            for (c_ix = k; c_ix <= vectorUB; c_ix += 2) {
              tmp = _mm_loadu_pd(&vr[c_ix - 1]);
              _mm_storeu_pd(&vr[c_ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(b_temp)));
            }

            for (c_ix = scalarLB; c_ix <= k + 3; c_ix++) {
              vr[c_ix - 1] *= b_temp;
            }

            scalarLB = b_temp_tmp_tmp_0 + 5;
            vectorUB = b_temp_tmp_tmp_0 + 3;
            for (c_ix = b_temp_tmp; c_ix <= vectorUB; c_ix += 2) {
              tmp = _mm_loadu_pd(&vr[c_ix - 1]);
              _mm_storeu_pd(&vr[c_ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(b_temp)));
            }

            for (c_ix = scalarLB; c_ix <= b_temp_tmp + 3; c_ix++) {
              vr[c_ix - 1] *= b_temp;
            }

            gs = vr[b_temp_tmp_tmp];
            vr_0 = vr[b_temp_tmp_tmp_0];
            s = vr[b_temp_tmp_tmp + 1];
            vr_tmp = vr[b_temp_tmp_tmp_0 + 1];
            gs_tmp = vr[b_temp_tmp_tmp + 2];
            vr_tmp_0 = vr[b_temp_tmp_tmp_0 + 2];
            gs_tmp_0 = vr[b_temp_tmp_tmp + 3];
            vr_tmp_1 = vr[b_temp_tmp_tmp_0 + 3];
            k = 0;
            b_temp = fabs(gs * gs + vr_0 * vr_0);
            s = fabs(s * s + vr_tmp * vr_tmp);
            if (s > b_temp) {
              k = 1;
              b_temp = s;
            }

            s = fabs(gs_tmp * gs_tmp + vr_tmp_0 * vr_tmp_0);
            if (s > b_temp) {
              k = 2;
              b_temp = s;
            }

            if (fabs(gs_tmp_0 * gs_tmp_0 + vr_tmp_1 * vr_tmp_1) > b_temp) {
              k = 3;
            }

            gs = vr[b_temp_tmp_tmp + k];
            s = fabs(gs);
            c_ix = b_temp_tmp_tmp_0 + k;
            vr_0 = vr[c_ix];
            b_temp = fabs(vr_0);
            if (vr_0 == 0.0) {
              s = 1.0;
              b_temp = 0.0;
            } else if (gs == 0.0) {
              s = 0.0;
              if (vr_0 >= 0.0) {
                b_temp = 1.0;
              } else {
                b_temp = -1.0;
              }
            } else if ((s > 1.4916681462400413E-154) && (s <
                        4.7403759540545887E+153) && (b_temp >
                        1.4916681462400413E-154) && (b_temp <
                        4.7403759540545887E+153)) {
              b_temp = sqrt(vr_0 * vr_0 + gs * gs);
              s /= b_temp;
              if (!(gs >= 0.0)) {
                b_temp = -b_temp;
              }

              b_temp = vr_0 / b_temp;
            } else {
              if ((s >= b_temp) || rtIsNaN(b_temp)) {
                b_temp = s;
              }

              if ((b_temp <= 2.2250738585072014E-308) || rtIsNaN(b_temp)) {
                b_temp = 2.2250738585072014E-308;
              }

              if (b_temp >= 4.49423283715579E+307) {
                b_temp = 4.49423283715579E+307;
              }

              _mm_storeu_pd(&tmp_0[0], _mm_div_pd(_mm_set_pd(vr_0, gs),
                _mm_set1_pd(b_temp)));
              b_temp = sqrt(tmp_0[0] * tmp_0[0] + tmp_0[1] * tmp_0[1]);
              s = fabs(tmp_0[0]) / b_temp;
              if (!(gs >= 0.0)) {
                b_temp = -b_temp;
              }

              b_temp = tmp_0[1] / b_temp;
            }

            gs = s * vr[b_temp_tmp_tmp] + b_temp * vr[b_temp_tmp_tmp_0];
            vr[b_temp_tmp_tmp_0] = s * vr[b_temp_tmp_tmp_0] - b_temp *
              vr[b_temp_tmp_tmp];
            vr[b_temp_tmp_tmp] = gs;
            gs = vr[b_temp_tmp_tmp_0 + 1];
            vr_0 = vr[b_temp_tmp_tmp + 1];
            vr[b_temp_tmp_tmp_0 + 1] = gs * s - vr_0 * b_temp;
            vr[b_temp_tmp_tmp + 1] = vr_0 * s + gs * b_temp;
            gs = vr[b_temp_tmp_tmp_0 + 2];
            vr_0 = vr[b_temp_tmp_tmp + 2];
            vr[b_temp_tmp_tmp_0 + 2] = gs * s - vr_0 * b_temp;
            vr[b_temp_tmp_tmp + 2] = vr_0 * s + gs * b_temp;
            gs = vr[b_temp_tmp_tmp_0 + 3];
            vr_0 = vr[b_temp_tmp_tmp + 3];
            vr[b_temp_tmp_tmp_0 + 3] = gs * s - vr_0 * b_temp;
            vr[b_temp_tmp_tmp + 3] = vr_0 * s + gs * b_temp;
            vr[c_ix] = 0.0;
          } else {
            k = (ihi << 2) + 1;
            b_temp = 1.0 / KIMMCar_xnrm2(4, vr, k);
            scalarLB = 4 + k;
            vectorUB = k + 2;
            for (c_ix = k; c_ix <= vectorUB; c_ix += 2) {
              tmp = _mm_loadu_pd(&vr[c_ix - 1]);
              _mm_storeu_pd(&vr[c_ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(b_temp)));
            }

            for (c_ix = scalarLB; c_ix <= k + 3; c_ix++) {
              vr[c_ix - 1] *= b_temp;
            }
          }
        }
      }

      for (b_temp_tmp_tmp = 0; b_temp_tmp_tmp < 16; b_temp_tmp_tmp++) {
        V[b_temp_tmp_tmp].re = vr[b_temp_tmp_tmp];
        V[b_temp_tmp_tmp].im = 0.0;
      }

      for (ihi = 0; ihi < 3; ihi++) {
        if ((wi[ihi] > 0.0) && (wi[ihi + 1] < 0.0)) {
          b_temp_tmp_tmp = ihi << 2;
          b_temp_tmp_tmp_0 = (ihi + 1) << 2;
          s = V[b_temp_tmp_tmp_0].re;
          V[b_temp_tmp_tmp].im = s;
          V[b_temp_tmp_tmp_0].re = V[b_temp_tmp_tmp].re;
          V[b_temp_tmp_tmp_0].im = -s;
          s = V[b_temp_tmp_tmp_0 + 1].re;
          V[b_temp_tmp_tmp + 1].im = s;
          V[b_temp_tmp_tmp_0 + 1].re = V[b_temp_tmp_tmp + 1].re;
          V[b_temp_tmp_tmp_0 + 1].im = -s;
          s = V[b_temp_tmp_tmp_0 + 2].re;
          V[b_temp_tmp_tmp + 2].im = s;
          V[b_temp_tmp_tmp_0 + 2].re = V[b_temp_tmp_tmp + 2].re;
          V[b_temp_tmp_tmp_0 + 2].im = -s;
          s = V[b_temp_tmp_tmp_0 + 3].re;
          V[b_temp_tmp_tmp + 3].im = s;
          V[b_temp_tmp_tmp_0 + 3].re = V[b_temp_tmp_tmp + 3].re;
          V[b_temp_tmp_tmp_0 + 3].im = -s;
        }
      }
    } else {
      for (b_temp_tmp_tmp = 0; b_temp_tmp_tmp < 16; b_temp_tmp_tmp++) {
        V[b_temp_tmp_tmp].re = (rtNaN);
        V[b_temp_tmp_tmp].im = 0.0;
      }
    }

    if (scalea) {
      KIMMCar_xzlascl_e(absxk, anrm, 4 - info, wr, info + 1);
      KIMMCar_xzlascl_e(absxk, anrm, 4 - info, wi, info + 1);
      if (info != 0) {
        KIMMCar_xzlascl_e(absxk, anrm, b_k - 1, wr, 1);
        KIMMCar_xzlascl_e(absxk, anrm, b_k - 1, wi, 1);
      }
    }

    if (info != 0) {
      for (ihi = b_k; ihi <= info; ihi++) {
        wr[ihi - 1] = (rtNaN);
        wi[ihi - 1] = 0.0;
      }
    }

    D[0].re = wr[0];
    D[0].im = wi[0];
    D[1].re = wr[1];
    D[1].im = wi[1];
    D[2].re = wr[2];
    D[2].im = wi[2];
    D[3].re = wr[3];
    D[3].im = wi[3];
  }
}

static void KIMMCar_xzlascl_eg(real_T cfrom, real_T cto, int32_T m, real_T A[3],
  int32_T iA0)
{
  __m128d tmp;
  real_T cfrom1;
  real_T cfromc;
  real_T cto1;
  real_T ctoc;
  real_T mul;
  int32_T b_i;
  int32_T scalarLB;
  int32_T tmp_0;
  int32_T vectorUB;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    scalarLB = (m / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_i = 0; b_i <= vectorUB; b_i += 2) {
      tmp_0 = (b_i + iA0) - 1;
      tmp = _mm_loadu_pd(&A[tmp_0]);
      _mm_storeu_pd(&A[tmp_0], _mm_mul_pd(tmp, _mm_set1_pd(mul)));
    }

    for (b_i = scalarLB; b_i < m; b_i++) {
      tmp_0 = (b_i + iA0) - 1;
      A[tmp_0] *= mul;
    }
  }
}

static void KIMMCar_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T
  *r)
{
  real_T f1;
  real_T fs;
  real_T gs;
  f1 = fabs(f);
  *r = fabs(g);
  if (g == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
    *r = f;
  } else if (f == 0.0) {
    *cs = 0.0;
    if (g >= 0.0) {
      *sn = 1.0;
    } else {
      *sn = -1.0;
    }
  } else if ((f1 > 1.4916681462400413E-154) && (f1 < 4.7403759540545887E+153) &&
             (*r > 1.4916681462400413E-154) && (*r < 4.7403759540545887E+153)) {
    *r = sqrt(f * f + g * g);
    *cs = f1 / *r;
    if (!(f >= 0.0)) {
      *r = -*r;
    }

    *sn = g / *r;
  } else {
    if ((f1 >= *r) || rtIsNaN(*r)) {
      *r = f1;
    }

    if ((*r <= 2.2250738585072014E-308) || rtIsNaN(*r)) {
      *r = 2.2250738585072014E-308;
    }

    if (*r >= 4.49423283715579E+307) {
      f1 = 4.49423283715579E+307;
    } else {
      f1 = *r;
    }

    fs = f / f1;
    gs = g / f1;
    *r = sqrt(fs * fs + gs * gs);
    *cs = fabs(fs) / *r;
    if (!(f >= 0.0)) {
      *r = -*r;
    }

    *sn = gs / *r;
    *r *= f1;
  }
}

static void KIMMCar_rotateRight_l(int32_T n, real_T z[16], int32_T iz0, const
  real_T cs[6], int32_T ic0, int32_T is0)
{
  real_T ctemp;
  real_T stemp;
  real_T temp;
  real_T z_0;
  int32_T b_j;
  int32_T offsetj;
  int32_T offsetjp1;
  for (b_j = 0; b_j <= n - 2; b_j++) {
    ctemp = cs[(ic0 + b_j) - 1];
    stemp = cs[(is0 + b_j) - 1];
    offsetj = ((b_j << 2) + iz0) - 1;
    offsetjp1 = (((b_j + 1) << 2) + iz0) - 1;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      temp = z[offsetjp1];
      z_0 = z[offsetj];
      z[offsetjp1] = ctemp * temp - stemp * z_0;
      z[offsetj] = stemp * temp + ctemp * z_0;
      temp = z[offsetjp1 + 1];
      z_0 = z[offsetj + 1];
      z[offsetjp1 + 1] = ctemp * temp - z_0 * stemp;
      z[offsetj + 1] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 2];
      z_0 = z[offsetj + 2];
      z[offsetjp1 + 2] = ctemp * temp - z_0 * stemp;
      z[offsetj + 2] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 3];
      z_0 = z[offsetj + 3];
      z[offsetjp1 + 3] = ctemp * temp - z_0 * stemp;
      z[offsetj + 3] = z_0 * ctemp + stemp * temp;
    }
  }
}

static void KIMMCar_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T
  *rt2, real_T *cs1, real_T *sn1)
{
  real_T ab;
  real_T acmn;
  real_T acmx;
  real_T adf;
  real_T b_a;
  real_T df;
  real_T sm;
  real_T tb;
  int32_T sgn1;
  int32_T sgn2;
  sm = a + c;
  df = a - c;
  adf = fabs(df);
  tb = b + b;
  ab = fabs(tb);
  if (fabs(a) > fabs(c)) {
    acmx = a;
    acmn = c;
  } else {
    acmx = c;
    acmn = a;
  }

  if (adf > ab) {
    b_a = ab / adf;
    adf *= sqrt(b_a * b_a + 1.0);
  } else if (adf < ab) {
    adf /= ab;
    adf = sqrt(adf * adf + 1.0) * ab;
  } else {
    adf = ab * 1.4142135623730951;
  }

  if (sm < 0.0) {
    *rt1 = (sm - adf) * 0.5;
    sgn1 = -1;
    *rt2 = acmx / *rt1 * acmn - b / *rt1 * b;
  } else if (sm > 0.0) {
    *rt1 = (sm + adf) * 0.5;
    sgn1 = 1;
    *rt2 = acmx / *rt1 * acmn - b / *rt1 * b;
  } else {
    *rt1 = 0.5 * adf;
    *rt2 = -0.5 * adf;
    sgn1 = 1;
  }

  if (df >= 0.0) {
    df += adf;
    sgn2 = 1;
  } else {
    df -= adf;
    sgn2 = -1;
  }

  if (fabs(df) > ab) {
    tb = -tb / df;
    *sn1 = 1.0 / sqrt(tb * tb + 1.0);
    *cs1 = tb * *sn1;
  } else if (ab == 0.0) {
    *cs1 = 1.0;
    *sn1 = 0.0;
  } else {
    tb = -df / tb;
    *cs1 = 1.0 / sqrt(tb * tb + 1.0);
    *sn1 = tb * *cs1;
  }

  if (sgn1 == sgn2) {
    tb = *cs1;
    *cs1 = -*sn1;
    *sn1 = tb;
  }
}

static void KIMMCar_rotateRight(int32_T n, real_T z[16], int32_T iz0, const
  real_T cs[6], int32_T ic0, int32_T is0)
{
  real_T ctemp;
  real_T stemp;
  real_T temp;
  real_T z_0;
  int32_T j;
  int32_T offsetj;
  int32_T offsetjp1;
  for (j = n - 1; j >= 1; j--) {
    ctemp = cs[(ic0 + j) - 2];
    stemp = cs[(is0 + j) - 2];
    offsetj = (((j - 1) << 2) + iz0) - 1;
    offsetjp1 = ((j << 2) + iz0) - 1;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      temp = z[offsetjp1];
      z_0 = z[offsetj];
      z[offsetjp1] = ctemp * temp - stemp * z_0;
      z[offsetj] = stemp * temp + ctemp * z_0;
      temp = z[offsetjp1 + 1];
      z_0 = z[offsetj + 1];
      z[offsetjp1 + 1] = ctemp * temp - z_0 * stemp;
      z[offsetj + 1] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 2];
      z_0 = z[offsetj + 2];
      z[offsetjp1 + 2] = ctemp * temp - z_0 * stemp;
      z[offsetj + 2] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 3];
      z_0 = z[offsetj + 3];
      z[offsetjp1 + 3] = ctemp * temp - z_0 * stemp;
      z[offsetj + 3] = z_0 * ctemp + stemp * temp;
    }
  }
}

static int32_T KIMMCar_xzsteqr(real_T d[4], real_T e[3], real_T z[16])
{
  real_T work[6];
  real_T b;
  real_T b_anorm;
  real_T b_s;
  real_T c;
  real_T e_0;
  real_T p;
  real_T r;
  real_T s;
  real_T tst;
  int32_T b_anorm_tmp;
  int32_T exitg1;
  int32_T exitg3;
  int32_T exitg4;
  int32_T i;
  int32_T info;
  int32_T iscale;
  int32_T l;
  int32_T l1;
  int32_T lend;
  int32_T lendsv;
  int32_T lsv;
  int32_T m;
  int32_T n_tmp;
  boolean_T exitg2;
  info = 0;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  i = 0;
  l1 = 1;
  do {
    exitg1 = 0;
    if (l1 > 4) {
      for (i = 0; i < 3; i++) {
        l = i;
        p = d[i];
        for (l1 = i + 2; l1 < 5; l1++) {
          tst = d[l1 - 1];
          if (tst < p) {
            l = l1 - 1;
            p = tst;
          }
        }

        if (l != i) {
          d[l] = d[i];
          d[i] = p;
          m = i << 2;
          l <<= 2;
          tst = z[m];
          z[m] = z[l];
          z[l] = tst;
          tst = z[m + 1];
          z[m + 1] = z[l + 1];
          z[l + 1] = tst;
          tst = z[m + 2];
          z[m + 2] = z[l + 2];
          z[l + 2] = tst;
          tst = z[m + 3];
          z[m + 3] = z[l + 3];
          z[l + 3] = tst;
        }
      }

      exitg1 = 1;
    } else {
      if (l1 > 1) {
        e[l1 - 2] = 0.0;
      }

      m = l1;
      exitg2 = false;
      while ((!exitg2) && (m < 4)) {
        tst = fabs(e[m - 1]);
        if (tst == 0.0) {
          exitg2 = true;
        } else if (tst <= sqrt(fabs(d[m - 1])) * sqrt(fabs(d[m])) *
                   2.2204460492503131E-16) {
          e[m - 1] = 0.0;
          exitg2 = true;
        } else {
          m++;
        }
      }

      l = l1 - 1;
      lsv = l1;
      lend = m;
      lendsv = m;
      l1 = m + 1;
      if (l + 1 == m) {
      } else {
        n_tmp = m - l;
        if (n_tmp <= 0) {
          tst = 0.0;
        } else {
          tst = fabs(d[(l + n_tmp) - 1]);
          iscale = 0;
          exitg2 = false;
          while ((!exitg2) && (iscale <= n_tmp - 2)) {
            b_anorm_tmp = l + iscale;
            b_anorm = fabs(d[b_anorm_tmp]);
            if (rtIsNaN(b_anorm)) {
              tst = (rtNaN);
              exitg2 = true;
            } else {
              if (b_anorm > tst) {
                tst = b_anorm;
              }

              b_anorm = fabs(e[b_anorm_tmp]);
              if (rtIsNaN(b_anorm)) {
                tst = (rtNaN);
                exitg2 = true;
              } else {
                if (b_anorm > tst) {
                  tst = b_anorm;
                }

                iscale++;
              }
            }
          }
        }

        iscale = 0;
        if (tst == 0.0) {
        } else if (rtIsInf(tst) || rtIsNaN(tst)) {
          d[0] = (rtNaN);
          d[1] = (rtNaN);
          d[2] = (rtNaN);
          d[3] = (rtNaN);
          for (m = 0; m < 16; m++) {
            z[m] = (rtNaN);
          }

          exitg1 = 1;
        } else {
          if (tst > 2.2346346549904327E+153) {
            iscale = 1;
            KIMMCar_xzlascl_e(tst, 2.2346346549904327E+153, n_tmp, d, l + 1);
            KIMMCar_xzlascl_eg(tst, 2.2346346549904327E+153, n_tmp - 1, e, l + 1);
          } else if (tst < 3.02546243347603E-123) {
            iscale = 2;
            KIMMCar_xzlascl_e(tst, 3.02546243347603E-123, n_tmp, d, l + 1);
            KIMMCar_xzlascl_eg(tst, 3.02546243347603E-123, n_tmp - 1, e, l + 1);
          }

          if (fabs(d[m - 1]) < fabs(d[l])) {
            lend = lsv;
            l = m - 1;
          }

          if (lend > l + 1) {
            do {
              exitg4 = 0;
              if (l + 1 != lend) {
                m = l;
                exitg2 = false;
                while ((!exitg2) && (m + 1 < lend)) {
                  b_anorm = fabs(e[m]);
                  if (b_anorm * b_anorm <= 4.9303806576313238E-32 * fabs(d[m]) *
                      fabs(d[m + 1]) + 2.2250738585072014E-308) {
                    exitg2 = true;
                  } else {
                    m++;
                  }
                }
              } else {
                m = lend - 1;
              }

              if (m + 1 < lend) {
                e[m] = 0.0;
              }

              if (m + 1 == l + 1) {
                l++;
                if (l + 1 > lend) {
                  exitg4 = 1;
                }
              } else if (m + 1 == l + 2) {
                KIMMCar_xdlaev2(d[l], e[l], d[l + 1], &d[l], &b_anorm, &work[l],
                                &s);
                d[l + 1] = b_anorm;
                work[l + 3] = s;
                KIMMCar_rotateRight(2, z, (l << 2) + 1, work, l + 1, l + 4);
                e[l] = 0.0;
                l += 2;
                if (l + 1 > lend) {
                  exitg4 = 1;
                }
              } else if (i == 120) {
                exitg4 = 1;
              } else {
                i++;
                b_anorm = (d[l + 1] - d[l]) / (2.0 * e[l]);
                s = rt_hypotd_snf(b_anorm, 1.0);
                if (!(b_anorm >= 0.0)) {
                  s = -s;
                }

                b_anorm = e[l] / (b_anorm + s) + (d[m] - d[l]);
                s = 1.0;
                c = 1.0;
                p = 0.0;
                for (n_tmp = m; n_tmp >= l + 1; n_tmp--) {
                  e_0 = e[n_tmp - 1];
                  b = c * e_0;
                  KIMMCar_xzlartg(b_anorm, s * e_0, &c, &b_s, &r);
                  s = b_s;
                  if (n_tmp != m) {
                    e[n_tmp] = r;
                  }

                  b_anorm = d[n_tmp] - p;
                  r = (d[n_tmp - 1] - b_anorm) * b_s + 2.0 * c * b;
                  p = b_s * r;
                  d[n_tmp] = b_anorm + p;
                  b_anorm = c * r - b;
                  work[n_tmp - 1] = c;
                  work[n_tmp + 2] = -b_s;
                }

                KIMMCar_rotateRight((m - l) + 1, z, (l << 2) + 1, work, l + 1, l
                                    + 4);
                d[l] -= p;
                e[l] = b_anorm;
              }
            } while (exitg4 == 0);
          } else {
            do {
              exitg3 = 0;
              if (l + 1 != lend) {
                m = l + 1;
                exitg2 = false;
                while ((!exitg2) && (m > lend)) {
                  b_anorm = fabs(e[m - 2]);
                  if (b_anorm * b_anorm <= fabs(d[m - 1]) *
                      4.9303806576313238E-32 * fabs(d[m - 2]) +
                      2.2250738585072014E-308) {
                    exitg2 = true;
                  } else {
                    m--;
                  }
                }
              } else {
                m = lend;
              }

              if (m > lend) {
                e[m - 2] = 0.0;
              }

              if (l + 1 == m) {
                l--;
                if (l + 1 < lend) {
                  exitg3 = 1;
                }
              } else if (m == l) {
                KIMMCar_xdlaev2(d[l - 1], e[l - 1], d[l], &d[l - 1], &b_anorm,
                                &work[m - 1], &s);
                d[l] = b_anorm;
                work[m + 2] = s;
                KIMMCar_rotateRight_l(2, z, ((l - 1) << 2) + 1, work, m, m + 3);
                e[l - 1] = 0.0;
                l -= 2;
                if (l + 1 < lend) {
                  exitg3 = 1;
                }
              } else if (i == 120) {
                exitg3 = 1;
              } else {
                i++;
                p = e[l - 1];
                b_anorm = (d[l - 1] - d[l]) / (p * 2.0);
                s = rt_hypotd_snf(b_anorm, 1.0);
                if (!(b_anorm >= 0.0)) {
                  s = -s;
                }

                b_anorm = (d[m - 1] - d[l]) + p / (b_anorm + s);
                s = 1.0;
                c = 1.0;
                p = 0.0;
                for (n_tmp = m; n_tmp <= l; n_tmp++) {
                  e_0 = e[n_tmp - 1];
                  b = c * e_0;
                  KIMMCar_xzlartg(b_anorm, s * e_0, &c, &b_s, &r);
                  s = b_s;
                  if (n_tmp != m) {
                    e[n_tmp - 2] = r;
                  }

                  b_anorm = d[n_tmp - 1] - p;
                  r = (d[n_tmp] - b_anorm) * b_s + 2.0 * c * b;
                  p = b_s * r;
                  d[n_tmp - 1] = b_anorm + p;
                  b_anorm = c * r - b;
                  work[n_tmp - 1] = c;
                  work[n_tmp + 2] = b_s;
                }

                KIMMCar_rotateRight_l((l - m) + 2, z, ((m - 1) << 2) + 1, work,
                                      m, m + 3);
                d[l] -= p;
                e[l - 1] = b_anorm;
              }
            } while (exitg3 == 0);
          }

          if (iscale == 1) {
            m = lendsv - lsv;
            KIMMCar_xzlascl_e(2.2346346549904327E+153, tst, m + 1, d, lsv);
            KIMMCar_xzlascl_eg(2.2346346549904327E+153, tst, m, e, lsv);
          } else if (iscale == 2) {
            m = lendsv - lsv;
            KIMMCar_xzlascl_e(3.02546243347603E-123, tst, m + 1, d, lsv);
            KIMMCar_xzlascl_eg(3.02546243347603E-123, tst, m, e, lsv);
          }

          if (i >= 120) {
            if (e[0] != 0.0) {
              info = 1;
            }

            if (e[1] != 0.0) {
              info++;
            }

            if (e[2] != 0.0) {
              info++;
            }

            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);

  return info;
}

static void KIMMCar_eig(const real_T A[16], creal_T V[16], creal_T D[4])
{
  __m128d tmp;
  __m128d tmp_0;
  real_T Q[16];
  real_T b_A[16];
  real_T a__4[4];
  real_T work[4];
  real_T e[3];
  real_T tau[3];
  real_T tmp_1[2];
  real_T absx;
  real_T anrm;
  real_T b_A_tmp;
  real_T temp1;
  real_T temp2;
  int32_T b_ix;
  int32_T b_iy;
  int32_T b_iy_tmp;
  int32_T c_j;
  int32_T e_tmp;
  int32_T e_tmp_tmp;
  int32_T exitg1;
  int32_T ii;
  int32_T sgn;
  int32_T sgn_tmp;
  int32_T tau_tmp;
  boolean_T exitg2;
  boolean_T iscale;
  iscale = true;
  for (c_j = 0; c_j < 16; c_j++) {
    if (iscale) {
      anrm = A[c_j];
      if ((!rtIsInf(anrm)) && (!rtIsNaN(anrm))) {
      } else {
        iscale = false;
      }
    } else {
      iscale = false;
    }
  }

  if (!iscale) {
    for (b_iy = 0; b_iy < 16; b_iy++) {
      V[b_iy].re = (rtNaN);
      V[b_iy].im = 0.0;
    }

    D[0].re = (rtNaN);
    D[0].im = 0.0;
    D[1].re = (rtNaN);
    D[1].im = 0.0;
    D[2].re = (rtNaN);
    D[2].im = 0.0;
    D[3].re = (rtNaN);
    D[3].im = 0.0;
  } else {
    c_j = 0;
    exitg2 = false;
    while ((!exitg2) && (c_j < 4)) {
      sgn = 0;
      do {
        exitg1 = 0;
        if (sgn <= c_j) {
          if (!(A[(c_j << 2) + sgn] == A[(sgn << 2) + c_j])) {
            iscale = false;
            exitg1 = 1;
          } else {
            sgn++;
          }
        } else {
          c_j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (iscale) {
      memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
      anrm = 0.0;
      c_j = 0;
      exitg2 = false;
      while ((!exitg2) && (c_j < 4)) {
        sgn = 0;
        do {
          exitg1 = 0;
          if (sgn <= c_j) {
            absx = fabs(A[(c_j << 2) + sgn]);
            if (rtIsNaN(absx)) {
              anrm = (rtNaN);
              exitg1 = 1;
            } else {
              if (absx > anrm) {
                anrm = absx;
              }

              sgn++;
            }
          } else {
            c_j++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (rtIsInf(anrm) || rtIsNaN(anrm)) {
        a__4[0] = (rtNaN);
        a__4[1] = (rtNaN);
        a__4[2] = (rtNaN);
        a__4[3] = (rtNaN);
        for (b_iy = 0; b_iy < 16; b_iy++) {
          b_A[b_iy] = (rtNaN);
        }
      } else {
        iscale = false;
        if ((anrm > 0.0) && (anrm < 1.0010415475915505E-146)) {
          iscale = true;
          anrm = 1.0010415475915505E-146 / anrm;
          KIMMCar_xzlascl(1.0, anrm, b_A);
        } else if (anrm > 9.9895953610111751E+145) {
          iscale = true;
          anrm = 9.9895953610111751E+145 / anrm;
          KIMMCar_xzlascl(1.0, anrm, b_A);
        }

        for (c_j = 0; c_j < 3; c_j++) {
          e_tmp = c_j << 2;
          e_tmp_tmp = e_tmp + c_j;
          e[c_j] = b_A[e_tmp_tmp + 1];
          if (c_j + 3 <= 4) {
            b_iy = c_j + 3;
          } else {
            b_iy = 4;
          }

          absx = KIMMCar_xzlarfg(3 - c_j, &e[c_j], b_A, e_tmp + b_iy);
          if (absx != 0.0) {
            b_A[e_tmp_tmp + 1] = 1.0;
            for (sgn = c_j + 1; sgn < 4; sgn++) {
              tau[sgn - 1] = 0.0;
            }

            sgn_tmp = 2 - c_j;
            b_iy_tmp = 4 - c_j;
            for (b_ix = 0; b_ix <= sgn_tmp; b_ix++) {
              sgn = c_j + b_ix;
              temp1 = b_A[(sgn + e_tmp) + 1] * absx;
              temp2 = 0.0;
              tau_tmp = ((sgn + 1) << 2) + c_j;
              tau[sgn] += b_A[(tau_tmp + b_ix) + 1] * temp1;
              for (ii = b_ix + 2; ii < b_iy_tmp; ii++) {
                b_iy = c_j + ii;
                _mm_storeu_pd(&tmp_1[0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
                  (b_A[tau_tmp + ii]), _mm_set_pd(b_A[b_iy + e_tmp], temp1)),
                  _mm_set_pd(temp2, tau[b_iy - 1])));
                tau[b_iy - 1] = tmp_1[0];
                temp2 = tmp_1[1];
              }

              tau[sgn] += absx * temp2;
            }

            sgn = e_tmp_tmp + 1;
            b_iy = e_tmp_tmp + 1;
            temp1 = 0.0;
            for (ii = 0; ii <= sgn_tmp; ii++) {
              temp1 += tau[c_j + ii] * b_A[b_iy];
              b_iy++;
            }

            temp1 *= -0.5 * absx;
            if (!(temp1 == 0.0)) {
              b_iy = 3 - c_j;
              for (ii = 0; ii < b_iy; ii++) {
                tau_tmp = c_j + ii;
                tau[tau_tmp] += temp1 * b_A[sgn];
                sgn++;
              }
            }

            for (b_ix = 0; b_ix <= sgn_tmp; b_ix++) {
              sgn = c_j + b_ix;
              temp1 = b_A[(sgn + e_tmp) + 1];
              temp2 = tau[sgn];
              b_A_tmp = temp2 * temp1;
              b_iy = (sgn + 1) << 2;
              tau_tmp = b_iy + c_j;
              b_A[(sgn + b_iy) + 1] = (b_A[(tau_tmp + b_ix) + 1] - b_A_tmp) -
                b_A_tmp;
              for (ii = b_ix + 2; ii < b_iy_tmp; ii++) {
                sgn = c_j + ii;
                b_A[sgn + b_iy] = (b_A[tau_tmp + ii] - tau[sgn - 1] * temp1) -
                  b_A[sgn + e_tmp] * temp2;
              }
            }
          }

          b_A[e_tmp_tmp + 1] = e[c_j];
          a__4[c_j] = b_A[e_tmp_tmp];
          tau[c_j] = absx;
        }

        a__4[3] = b_A[15];
        for (c_j = 2; c_j >= 0; c_j--) {
          b_iy = (c_j + 1) << 2;
          b_A[b_iy] = 0.0;
          for (sgn = c_j + 3; sgn < 5; sgn++) {
            b_A[(sgn + b_iy) - 1] = b_A[((c_j << 2) + sgn) - 1];
          }
        }

        b_A[0] = 1.0;
        b_A[1] = 0.0;
        b_A[2] = 0.0;
        b_A[3] = 0.0;
        work[0] = 0.0;
        work[1] = 0.0;
        work[2] = 0.0;
        work[3] = 0.0;
        for (sgn = 2; sgn >= 0; sgn--) {
          b_ix = ((sgn << 2) + sgn) + 5;
          if (sgn + 1 < 3) {
            b_A[b_ix] = 1.0;
            KIMMCar_xzlarf(3 - sgn, 2 - sgn, b_ix + 1, tau[sgn], b_A, b_ix + 5,
                           work);
            b_iy = (b_ix - sgn) + 3;
            c_j = (((((b_iy - b_ix) - 1) / 2) << 1) + b_ix) + 2;
            e_tmp = c_j - 2;
            for (ii = b_ix + 2; ii <= e_tmp; ii += 2) {
              tmp = _mm_loadu_pd(&b_A[ii - 1]);
              _mm_storeu_pd(&b_A[ii - 1], _mm_mul_pd(tmp, _mm_set1_pd(-tau[sgn])));
            }

            for (ii = c_j; ii <= b_iy; ii++) {
              b_A[ii - 1] *= -tau[sgn];
            }
          }

          b_A[b_ix] = 1.0 - tau[sgn];
          for (b_iy = 0; b_iy < sgn; b_iy++) {
            b_A[(b_ix - b_iy) - 1] = 0.0;
          }
        }

        c_j = KIMMCar_xzsteqr(a__4, e, b_A);
        if (c_j != 0) {
          a__4[0] = (rtNaN);
          a__4[1] = (rtNaN);
          a__4[2] = (rtNaN);
          a__4[3] = (rtNaN);
          for (b_iy = 0; b_iy < 16; b_iy++) {
            b_A[b_iy] = (rtNaN);
          }
        } else if (iscale) {
          tmp = _mm_set1_pd(1.0 / anrm);
          tmp_0 = _mm_mul_pd(tmp, _mm_loadu_pd(&a__4[0]));
          _mm_storeu_pd(&a__4[0], tmp_0);
          tmp = _mm_mul_pd(tmp, _mm_loadu_pd(&a__4[2]));
          _mm_storeu_pd(&a__4[2], tmp);
        }
      }

      D[0].re = a__4[0];
      D[0].im = 0.0;
      D[1].re = a__4[1];
      D[1].im = 0.0;
      D[2].re = a__4[2];
      D[2].im = 0.0;
      D[3].re = a__4[3];
      D[3].im = 0.0;
      for (b_iy = 0; b_iy < 16; b_iy++) {
        V[b_iy].re = b_A[b_iy];
        V[b_iy].im = 0.0;
      }
    } else {
      iscale = true;
      c_j = 0;
      exitg2 = false;
      while ((!exitg2) && (c_j < 4)) {
        sgn = 0;
        do {
          exitg1 = 0;
          if (sgn <= c_j) {
            if (!(A[(c_j << 2) + sgn] == -A[(sgn << 2) + c_j])) {
              iscale = false;
              exitg1 = 1;
            } else {
              sgn++;
            }
          } else {
            c_j++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (iscale) {
        memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
        KIMMCar_xzgehrd(b_A, 1, 4, tau);
        memcpy(&Q[0], &b_A[0], sizeof(real_T) << 4U);
        KIMMCar_xzunghr(1, 4, Q, tau);
        KIMMCar_xdlahqr(1, 4, b_A, 1, 4, Q, &c_j, a__4, work);
        sgn = (uint8_T)c_j;
        for (b_ix = 0; b_ix < sgn; b_ix++) {
          D[b_ix].re = (rtNaN);
          D[b_ix].im = 0.0;
        }

        for (sgn = c_j + 1; sgn < 5; sgn++) {
          D[sgn - 1].re = 0.0;
          D[sgn - 1].im = work[sgn - 1];
        }

        if (c_j == 0) {
          for (b_iy = 0; b_iy < 16; b_iy++) {
            V[b_iy].re = Q[b_iy];
            V[b_iy].im = 0.0;
          }

          c_j = 1;
          do {
            exitg1 = 0;
            if (c_j <= 4) {
              if (c_j != 4) {
                b_iy = (c_j - 1) << 2;
                anrm = b_A[b_iy + c_j];
                if (anrm != 0.0) {
                  if (anrm < 0.0) {
                    sgn = 1;
                  } else {
                    sgn = -1;
                  }

                  anrm = V[b_iy].re;
                  b_ix = c_j << 2;
                  absx = V[b_ix].re * (real_T)sgn;
                  if (absx == 0.0) {
                    V[b_iy].re = anrm / 1.4142135623730951;
                    V[b_iy].im = 0.0;
                  } else if (anrm == 0.0) {
                    V[b_iy].re = 0.0;
                    V[b_iy].im = absx / 1.4142135623730951;
                  } else {
                    _mm_storeu_pd((real_T *)&V[b_iy], _mm_div_pd(_mm_set_pd(absx,
                      anrm), _mm_set1_pd(1.4142135623730951)));
                  }

                  V[b_ix].re = V[b_iy].re;
                  V[b_ix].im = -V[b_iy].im;
                  anrm = V[b_iy + 1].re;
                  absx = V[b_ix + 1].re * (real_T)sgn;
                  if (absx == 0.0) {
                    V[b_iy + 1].re = anrm / 1.4142135623730951;
                    V[b_iy + 1].im = 0.0;
                  } else if (anrm == 0.0) {
                    V[b_iy + 1].re = 0.0;
                    V[b_iy + 1].im = absx / 1.4142135623730951;
                  } else {
                    _mm_storeu_pd((real_T *)&V[b_iy + 1], _mm_div_pd(_mm_set_pd
                      (absx, anrm), _mm_set1_pd(1.4142135623730951)));
                  }

                  V[b_ix + 1].re = V[b_iy + 1].re;
                  V[b_ix + 1].im = -V[b_iy + 1].im;
                  anrm = V[b_iy + 2].re;
                  absx = V[b_ix + 2].re * (real_T)sgn;
                  if (absx == 0.0) {
                    V[b_iy + 2].re = anrm / 1.4142135623730951;
                    V[b_iy + 2].im = 0.0;
                  } else if (anrm == 0.0) {
                    V[b_iy + 2].re = 0.0;
                    V[b_iy + 2].im = absx / 1.4142135623730951;
                  } else {
                    _mm_storeu_pd((real_T *)&V[b_iy + 2], _mm_div_pd(_mm_set_pd
                      (absx, anrm), _mm_set1_pd(1.4142135623730951)));
                  }

                  V[b_ix + 2].re = V[b_iy + 2].re;
                  V[b_ix + 2].im = -V[b_iy + 2].im;
                  anrm = V[b_iy + 3].re;
                  absx = V[b_ix + 3].re * (real_T)sgn;
                  if (absx == 0.0) {
                    V[b_iy + 3].re = anrm / 1.4142135623730951;
                    V[b_iy + 3].im = 0.0;
                  } else if (anrm == 0.0) {
                    V[b_iy + 3].re = 0.0;
                    V[b_iy + 3].im = absx / 1.4142135623730951;
                  } else {
                    _mm_storeu_pd((real_T *)&V[b_iy + 3], _mm_div_pd(_mm_set_pd
                      (absx, anrm), _mm_set1_pd(1.4142135623730951)));
                  }

                  V[b_ix + 3].re = V[b_iy + 3].re;
                  V[b_ix + 3].im = -V[b_iy + 3].im;
                  c_j += 2;
                } else {
                  c_j++;
                }
              } else {
                c_j++;
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        } else {
          for (b_iy = 0; b_iy < 16; b_iy++) {
            V[b_iy].re = (rtNaN);
            V[b_iy].im = 0.0;
          }
        }
      } else {
        KIMMCar_eigStandard(A, V, D);
      }
    }
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void KIMMCar_step0(void)
{
  if (rtmIsMajorTimeStep(KIMMCar_M)) {
    if (!(KIMMCar_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&KIMMCar_M->solverInfo,
                            ((KIMMCar_M->Timing.clockTickH0 + 1) *
        KIMMCar_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&KIMMCar_M->solverInfo,
                            ((KIMMCar_M->Timing.clockTick0 + 1) *
        KIMMCar_M->Timing.stepSize0 + KIMMCar_M->Timing.clockTickH0 *
        KIMMCar_M->Timing.stepSize0 * 4294967296.0));
    }
  }

  if (rtmIsMinorTimeStep(KIMMCar_M)) {
    KIMMCar_M->Timing.t[0] = rtsiGetT(&KIMMCar_M->solverInfo);
  }

  {
    __m128d tmp_9;
    __m128d tmp_a;
    __m128d tmp_b;
    __m128d tmp_c;
    NeParameterBundle expl_temp;
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diag;
    NeuDiagnosticTree *diagTree;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    char *msg;
    char *msg_0;
    char *msg_1;
    char *msg_2;
    creal_T eigVec[16];
    creal_T eigVal[4];
    real_T tmp_3[245];
    real_T tmp_5[245];
    real_T tmp_0[216];
    real_T tmp[137];
    real_T rtb_OUTPUT_1_1[27];
    real_T catArgs[16];
    real_T R_sim[9];
    real_T a[9];
    real_T tempR[9];
    real_T q[4];
    real_T rtb_UnitDelay_c[4];
    real_T slip[4];
    real_T wheelAlong[4];
    real_T tmp_8[2];
    real_T K14;
    real_T K23;
    real_T K24;
    real_T rtb_Gain7;
    real_T rtb_Product2;
    real_T rtb_Switch;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_3;
    real_T time_4;
    real_T time_tmp;
    real_T u0;
    real_T u0_0;
    int32_T iindx;
    int32_T scaleRate;
    int32_T scaleRate_0;
    int_T tmp_4[56];
    int_T tmp_6[56];
    int_T tmp_1[55];
    int8_T a_0;
    int8_T a_1;
    int8_T a_2;
    boolean_T first_output;
    boolean_T tmp_2;
    boolean_T tmp_7;
    boolean_T zeroGuard;
    static const int8_T a_3[9] = { 0, 0, 1, -1, 0, 0, 0, 1, 0 };

    static const int8_T c[9] = { 0, -1, 0, 0, 0, 1, 1, 0, 0 };

    boolean_T exitg1;
    zeroGuard = rtmIsMajorTimeStep(KIMMCar_M);
    if (zeroGuard) {
      rtb_Switch = KIMMCar_DW.UnitDelay_DSTATE;
      rtb_Product2 = look1_bingcapw(rtb_Switch, KIMMCar_P.camber_bp01Data,
        KIMMCar_P.camber_tableData, 21U);
      KIMMCar_B.Gain7 = KIMMCar_P.Gain7_Gain * rtb_Product2;
    }

    tmp_7 = rtmIsMajorTimeStep(KIMMCar_M);
    if (tmp_7) {
      KIMMCar_DW.INPUT_7_1_1_Discrete = KIMMCar_B.Gain7;
    }

    if (KIMMCar_DW.INPUT_7_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_7_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
        [0] = KIMMCar_DW.INPUT_7_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_7_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
      [0];
    KIMMCar_B.INPUT_7_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
      [1];
    KIMMCar_B.INPUT_7_1_1[2] = ((KIMMCar_DW.INPUT_7_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_7_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Product2 = look1_bingcapw(rtb_Switch,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation_bp01Data,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation_tableData, 21U);
      KIMMCar_B.Add2 = KIMMCar_P.Gain1_Gain * rtb_Product2 - Veh_FrontAxleX;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_8_1_1_Discrete = KIMMCar_B.Add2;
    }

    if (KIMMCar_DW.INPUT_8_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_8_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
        [0] = KIMMCar_DW.INPUT_8_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_8_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
      [0];
    KIMMCar_B.INPUT_8_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
      [1];
    KIMMCar_B.INPUT_8_1_1[2] = ((KIMMCar_DW.INPUT_8_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_8_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Product2 = look1_bingcapw(rtb_Switch,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation1_bp01Data,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation1_tableData, 21U);
      KIMMCar_B.Add = -0.5 * Veh_TrackF + KIMMCar_P.Gain2_Gain * rtb_Product2;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_9_1_1_Discrete = KIMMCar_B.Add;
    }

    if (KIMMCar_DW.INPUT_9_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_9_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
        [0] = KIMMCar_DW.INPUT_9_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_9_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
      [0];
    KIMMCar_B.INPUT_9_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
      [1];
    KIMMCar_B.INPUT_9_1_1[2] = ((KIMMCar_DW.INPUT_9_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_9_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Switch = look1_bingcapw(rtb_Switch, KIMMCar_P.toe_bp01Data,
        KIMMCar_P.toe_tableData, 21U);
      rtb_Product2 = KIMMCar_P.unitiydirection_Gain * KIMMCar_U.Steer_in /
        Veh_SteerRatio;
      KIMMCar_B.Sum = atan(1.0 / (cos(rtb_Product2 + 2.2204460492503131e-16) /
        sin(rtb_Product2 + 2.2204460492503131e-16) - 0.26666666666666666)) +
        KIMMCar_P.Gain3_Gain * rtb_Switch;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_14_1_1_Discrete = KIMMCar_B.Sum;
    }

    if (KIMMCar_DW.INPUT_14_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_14_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
        [0] = KIMMCar_DW.INPUT_14_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_14_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
      [0];
    KIMMCar_B.INPUT_14_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
      [1];
    KIMMCar_B.INPUT_14_1_1[2] = ((KIMMCar_DW.INPUT_14_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
      [0]) * 100.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
      [1]) * 100.0;
    KIMMCar_B.INPUT_14_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Switch = KIMMCar_DW.UnitDelay1_DSTATE;
      rtb_Gain7 = look1_bingcapw(rtb_Switch, KIMMCar_P.camber1_bp01Data,
        KIMMCar_P.camber1_tableData, 21U);
      KIMMCar_B.Gain = KIMMCar_P.Gain_Gain * rtb_Gain7;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_10_1_1_Discrete = KIMMCar_B.Gain;
    }

    if (KIMMCar_DW.INPUT_10_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_10_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
        [0] = KIMMCar_DW.INPUT_10_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_10_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
      [0];
    KIMMCar_B.INPUT_10_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
      [1];
    KIMMCar_B.INPUT_10_1_1[2] = ((KIMMCar_DW.INPUT_10_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_10_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Gain7 = look1_bingcapw(rtb_Switch,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation2_bp01Data,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation2_tableData, 21U);
      KIMMCar_B.Add3 = KIMMCar_P.Gain4_Gain * rtb_Gain7 - Veh_FrontAxleX;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_11_1_1_Discrete = KIMMCar_B.Add3;
    }

    if (KIMMCar_DW.INPUT_11_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_11_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
        [0] = KIMMCar_DW.INPUT_11_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_11_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
      [0];
    KIMMCar_B.INPUT_11_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
      [1];
    KIMMCar_B.INPUT_11_1_1[2] = ((KIMMCar_DW.INPUT_11_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_11_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Gain7 = look1_bingcapw(rtb_Switch,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation3_bp01Data,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation3_tableData, 21U);
      KIMMCar_B.Add1 = 0.5 * Veh_TrackF + KIMMCar_P.Gain5_Gain * rtb_Gain7;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_12_1_1_Discrete = KIMMCar_B.Add1;
    }

    if (KIMMCar_DW.INPUT_12_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_12_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
        [0] = KIMMCar_DW.INPUT_12_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_12_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
      [0];
    KIMMCar_B.INPUT_12_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
      [1];
    KIMMCar_B.INPUT_12_1_1[2] = ((KIMMCar_DW.INPUT_12_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_12_1_1[3] = 0.0;
    if (zeroGuard) {
      KIMMCar_B.Sum1 = atan(1.0 / (cos(rtb_Product2 + 2.2204460492503131e-16) /
        sin(rtb_Product2 + 2.2204460492503131e-16) + 0.26666666666666666)) +
        KIMMCar_P.Gain6_Gain * look1_bingcapw(rtb_Switch,
        KIMMCar_P.toe1_bp01Data, KIMMCar_P.toe1_tableData, 21U);
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_13_1_1_Discrete = KIMMCar_B.Sum1;
    }

    if (KIMMCar_DW.INPUT_13_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_13_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
        [0] = KIMMCar_DW.INPUT_13_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_13_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
      [0];
    KIMMCar_B.INPUT_13_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
      [1];
    KIMMCar_B.INPUT_13_1_1[2] = ((KIMMCar_DW.INPUT_13_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
      [0]) * 100.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
      [1]) * 100.0;
    KIMMCar_B.INPUT_13_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Gain7 = KIMMCar_DW.UnitDelay_DSTATE_c;
      KIMMCar_B.Gain7_n = KIMMCar_P.Gain7_Gain_m * look1_bingcapw(rtb_Gain7,
        KIMMCar_P.camber_bp01Data_o, KIMMCar_P.camber_tableData_b, 67U);
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_15_1_1_Discrete = KIMMCar_B.Gain7_n;
    }

    if (KIMMCar_DW.INPUT_15_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_15_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
        [0] = KIMMCar_DW.INPUT_15_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_15_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
      [0];
    KIMMCar_B.INPUT_15_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
      [1];
    KIMMCar_B.INPUT_15_1_1[2] = ((KIMMCar_DW.INPUT_15_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_15_1_1[3] = 0.0;
    if (zeroGuard) {
      KIMMCar_B.Add2_k = KIMMCar_P.Gain1_Gain_b * look1_bingcapw(rtb_Gain7,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation_bp01Data_o,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation_tableData_p, 67U) -
        Veh_RearAxleX;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_16_1_1_Discrete = KIMMCar_B.Add2_k;
    }

    if (KIMMCar_DW.INPUT_16_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_16_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
        [0] = KIMMCar_DW.INPUT_16_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_16_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
      [0];
    KIMMCar_B.INPUT_16_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
      [1];
    KIMMCar_B.INPUT_16_1_1[2] = ((KIMMCar_DW.INPUT_16_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_16_1_1[3] = 0.0;
    if (zeroGuard) {
      KIMMCar_B.Add_b = -0.5 * Veh_TrackR + KIMMCar_P.Gain2_Gain_k *
        look1_bingcapw(rtb_Gain7,
                       KIMMCar_P.LookupwithLinearLagrangeInterpolation1_bp01Data_n,
                       KIMMCar_P.LookupwithLinearLagrangeInterpolation1_tableData_d,
                       67U);
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_17_1_1_Discrete = KIMMCar_B.Add_b;
    }

    if (KIMMCar_DW.INPUT_17_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_17_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
        [0] = KIMMCar_DW.INPUT_17_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_17_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
      [0];
    KIMMCar_B.INPUT_17_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
      [1];
    KIMMCar_B.INPUT_17_1_1[2] = ((KIMMCar_DW.INPUT_17_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_17_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Gain7 = look1_bingcapw(rtb_Gain7, KIMMCar_P.toe_bp01Data_d,
        KIMMCar_P.toe_tableData_d, 67U);
      KIMMCar_B.Gain3 = KIMMCar_P.Gain3_Gain_n * rtb_Gain7;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_21_1_1_Discrete = KIMMCar_B.Gain3;
    }

    if (KIMMCar_DW.INPUT_21_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_21_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
        [0] = KIMMCar_DW.INPUT_21_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_21_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
      [0];
    KIMMCar_B.INPUT_21_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
      [1];
    KIMMCar_B.INPUT_21_1_1[2] = ((KIMMCar_DW.INPUT_21_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_21_1_1[3] = 0.0;
    if (zeroGuard) {
      rtb_Gain7 = KIMMCar_DW.UnitDelay1_DSTATE_e;
      KIMMCar_B.Gain_i = KIMMCar_P.Gain_Gain_f * look1_bingcapw(rtb_Gain7,
        KIMMCar_P.camber1_bp01Data_h, KIMMCar_P.camber1_tableData_a, 67U);
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_18_1_1_Discrete = KIMMCar_B.Gain_i;
    }

    if (KIMMCar_DW.INPUT_18_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_18_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
        [0] = KIMMCar_DW.INPUT_18_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_18_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
      [0];
    KIMMCar_B.INPUT_18_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
      [1];
    KIMMCar_B.INPUT_18_1_1[2] = ((KIMMCar_DW.INPUT_18_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_18_1_1[3] = 0.0;
    if (zeroGuard) {
      KIMMCar_B.Add3_p = KIMMCar_P.Gain4_Gain_o * look1_bingcapw(rtb_Gain7,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation2_bp01Data_a,
        KIMMCar_P.LookupwithLinearLagrangeInterpolation2_tableData_c, 67U) -
        Veh_RearAxleX;
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_19_1_1_Discrete = KIMMCar_B.Add3_p;
    }

    if (KIMMCar_DW.INPUT_19_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_19_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
        [0] = KIMMCar_DW.INPUT_19_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_19_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
      [0];
    KIMMCar_B.INPUT_19_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
      [1];
    KIMMCar_B.INPUT_19_1_1[2] = ((KIMMCar_DW.INPUT_19_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_19_1_1[3] = 0.0;
    if (zeroGuard) {
      KIMMCar_B.Add1_b = 0.5 * Veh_TrackR + KIMMCar_P.Gain5_Gain_j *
        look1_bingcapw(rtb_Gain7,
                       KIMMCar_P.LookupwithLinearLagrangeInterpolation3_bp01Data_n,
                       KIMMCar_P.LookupwithLinearLagrangeInterpolation3_tableData_i,
                       67U);
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_20_1_1_Discrete = KIMMCar_B.Add1_b;
    }

    if (KIMMCar_DW.INPUT_20_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_20_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
        [0] = KIMMCar_DW.INPUT_20_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_20_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
      [0];
    KIMMCar_B.INPUT_20_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
      [1];
    KIMMCar_B.INPUT_20_1_1[2] = ((KIMMCar_DW.INPUT_20_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_20_1_1[3] = 0.0;
    if (zeroGuard) {
      KIMMCar_B.Gain6 = KIMMCar_P.Gain6_Gain_g * look1_bingcapw(rtb_Gain7,
        KIMMCar_P.toe1_bp01Data_h, KIMMCar_P.toe1_tableData_d, 67U);
    }

    if (tmp_7) {
      KIMMCar_DW.INPUT_22_1_1_Discrete = KIMMCar_B.Gain6;
    }

    if (KIMMCar_DW.INPUT_22_1_1_FirstOutput == 0.0) {
      KIMMCar_DW.INPUT_22_1_1_FirstOutput = 1.0;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
        [0] = KIMMCar_DW.INPUT_22_1_1_Discrete;
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
        [1] = 0.0;
    }

    KIMMCar_B.INPUT_22_1_1[0] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
      [0];
    KIMMCar_B.INPUT_22_1_1[1] =
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
      [1];
    KIMMCar_B.INPUT_22_1_1[2] = ((KIMMCar_DW.INPUT_22_1_1_Discrete -
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
      [0]) * 1000.0 - 2.0 *
      KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
      [1]) * 1000.0;
    KIMMCar_B.INPUT_22_1_1[3] = 0.0;
    if (zeroGuard) {
      KIMMCar_B.px = KIMMCar_P.DiscreteTransferFcn1_NumCoef *
        KIMMCar_DW.DiscreteTransferFcn1_states;
    }

    KIMMCar_B.INPUT_23_1_1[0] = KIMMCar_B.px;
    KIMMCar_B.INPUT_23_1_1[1] = KIMMCar_P.Constant_Value;
    KIMMCar_B.INPUT_23_1_1[2] = KIMMCar_P.Constant1_Value;
    if (tmp_7) {
      KIMMCar_DW.INPUT_23_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_23_1_1_Discrete[1]
        == KIMMCar_B.INPUT_23_1_1[2]);
      KIMMCar_DW.INPUT_23_1_1_Discrete[1] = KIMMCar_B.INPUT_23_1_1[2];
    }

    KIMMCar_B.INPUT_23_1_1[2] = KIMMCar_DW.INPUT_23_1_1_Discrete[1];
    KIMMCar_B.INPUT_23_1_1[3] = KIMMCar_DW.INPUT_23_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.py = KIMMCar_P.DiscreteTransferFcn2_NumCoef *
        KIMMCar_DW.DiscreteTransferFcn2_states;
    }

    KIMMCar_B.INPUT_24_1_1[0] = KIMMCar_B.py;
    KIMMCar_B.INPUT_24_1_1[1] = KIMMCar_P.Constant_Value;
    KIMMCar_B.INPUT_24_1_1[2] = KIMMCar_P.Constant1_Value;
    if (tmp_7) {
      KIMMCar_DW.INPUT_24_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_24_1_1_Discrete[1]
        == KIMMCar_B.INPUT_24_1_1[2]);
      KIMMCar_DW.INPUT_24_1_1_Discrete[1] = KIMMCar_B.INPUT_24_1_1[2];
    }

    KIMMCar_B.INPUT_24_1_1[2] = KIMMCar_DW.INPUT_24_1_1_Discrete[1];
    KIMMCar_B.INPUT_24_1_1[3] = KIMMCar_DW.INPUT_24_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.pz = KIMMCar_U.pz;
    }

    KIMMCar_B.INPUT_25_1_1[0] = KIMMCar_B.pz;
    KIMMCar_B.INPUT_25_1_1[1] = KIMMCar_P.Constant_Value;
    KIMMCar_B.INPUT_25_1_1[2] = KIMMCar_P.Constant1_Value;
    if (tmp_7) {
      KIMMCar_DW.INPUT_25_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_25_1_1_Discrete[1]
        == KIMMCar_B.INPUT_25_1_1[2]);
      KIMMCar_DW.INPUT_25_1_1_Discrete[1] = KIMMCar_B.INPUT_25_1_1[2];
    }

    KIMMCar_B.INPUT_25_1_1[2] = KIMMCar_DW.INPUT_25_1_1_Discrete[1];
    KIMMCar_B.INPUT_25_1_1[3] = KIMMCar_DW.INPUT_25_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qx = KIMMCar_U.qx;
    }

    KIMMCar_B.INPUT_28_1_1[0] = KIMMCar_B.qx;
    KIMMCar_B.INPUT_28_1_1[1] = KIMMCar_P.Constant2_Value;
    KIMMCar_B.INPUT_28_1_1[2] = KIMMCar_P.Constant3_Value;
    if (tmp_7) {
      KIMMCar_DW.INPUT_28_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_28_1_1_Discrete[1]
        == KIMMCar_B.INPUT_28_1_1[2]);
      KIMMCar_DW.INPUT_28_1_1_Discrete[1] = KIMMCar_B.INPUT_28_1_1[2];
    }

    KIMMCar_B.INPUT_28_1_1[2] = KIMMCar_DW.INPUT_28_1_1_Discrete[1];
    KIMMCar_B.INPUT_28_1_1[3] = KIMMCar_DW.INPUT_28_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qz = KIMMCar_P.DiscreteTransferFcn3_NumCoef *
        KIMMCar_DW.DiscreteTransferFcn3_states;
    }

    KIMMCar_B.INPUT_26_1_1[0] = KIMMCar_B.qz;
    KIMMCar_B.INPUT_26_1_1[1] = KIMMCar_P.Constant2_Value;
    KIMMCar_B.INPUT_26_1_1[2] = KIMMCar_P.Constant3_Value;
    if (tmp_7) {
      KIMMCar_DW.INPUT_26_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_26_1_1_Discrete[1]
        == KIMMCar_B.INPUT_26_1_1[2]);
      KIMMCar_DW.INPUT_26_1_1_Discrete[1] = KIMMCar_B.INPUT_26_1_1[2];
    }

    KIMMCar_B.INPUT_26_1_1[2] = KIMMCar_DW.INPUT_26_1_1_Discrete[1];
    KIMMCar_B.INPUT_26_1_1[3] = KIMMCar_DW.INPUT_26_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qy = KIMMCar_U.qy;
    }

    KIMMCar_B.INPUT_27_1_1[0] = KIMMCar_B.qy;
    KIMMCar_B.INPUT_27_1_1[1] = KIMMCar_P.Constant2_Value;
    KIMMCar_B.INPUT_27_1_1[2] = KIMMCar_P.Constant3_Value;
    if (tmp_7) {
      KIMMCar_DW.INPUT_27_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_27_1_1_Discrete[1]
        == KIMMCar_B.INPUT_27_1_1[2]);
      KIMMCar_DW.INPUT_27_1_1_Discrete[1] = KIMMCar_B.INPUT_27_1_1[2];
    }

    KIMMCar_B.INPUT_27_1_1[2] = KIMMCar_DW.INPUT_27_1_1_Discrete[1];
    KIMMCar_B.INPUT_27_1_1[3] = KIMMCar_DW.INPUT_27_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.px_h = KIMMCar_P.DiscreteTransferFcn1_NumCoef_c *
        KIMMCar_DW.DiscreteTransferFcn1_states_e;
    }

    KIMMCar_B.INPUT_31_1_1[0] = KIMMCar_B.px_h;
    KIMMCar_B.INPUT_31_1_1[1] = KIMMCar_P.Constant_Value_h;
    KIMMCar_B.INPUT_31_1_1[2] = KIMMCar_P.Constant1_Value_c;
    if (tmp_7) {
      KIMMCar_DW.INPUT_31_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_31_1_1_Discrete[1]
        == KIMMCar_B.INPUT_31_1_1[2]);
      KIMMCar_DW.INPUT_31_1_1_Discrete[1] = KIMMCar_B.INPUT_31_1_1[2];
    }

    KIMMCar_B.INPUT_31_1_1[2] = KIMMCar_DW.INPUT_31_1_1_Discrete[1];
    KIMMCar_B.INPUT_31_1_1[3] = KIMMCar_DW.INPUT_31_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.py_l = KIMMCar_P.DiscreteTransferFcn2_NumCoef_b *
        KIMMCar_DW.DiscreteTransferFcn2_states_o;
    }

    KIMMCar_B.INPUT_32_1_1[0] = KIMMCar_B.py_l;
    KIMMCar_B.INPUT_32_1_1[1] = KIMMCar_P.Constant_Value_h;
    KIMMCar_B.INPUT_32_1_1[2] = KIMMCar_P.Constant1_Value_c;
    if (tmp_7) {
      KIMMCar_DW.INPUT_32_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_32_1_1_Discrete[1]
        == KIMMCar_B.INPUT_32_1_1[2]);
      KIMMCar_DW.INPUT_32_1_1_Discrete[1] = KIMMCar_B.INPUT_32_1_1[2];
    }

    KIMMCar_B.INPUT_32_1_1[2] = KIMMCar_DW.INPUT_32_1_1_Discrete[1];
    KIMMCar_B.INPUT_32_1_1[3] = KIMMCar_DW.INPUT_32_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.pz_b = KIMMCar_U.pz_o;
    }

    KIMMCar_B.INPUT_33_1_1[0] = KIMMCar_B.pz_b;
    KIMMCar_B.INPUT_33_1_1[1] = KIMMCar_P.Constant_Value_h;
    KIMMCar_B.INPUT_33_1_1[2] = KIMMCar_P.Constant1_Value_c;
    if (tmp_7) {
      KIMMCar_DW.INPUT_33_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_33_1_1_Discrete[1]
        == KIMMCar_B.INPUT_33_1_1[2]);
      KIMMCar_DW.INPUT_33_1_1_Discrete[1] = KIMMCar_B.INPUT_33_1_1[2];
    }

    KIMMCar_B.INPUT_33_1_1[2] = KIMMCar_DW.INPUT_33_1_1_Discrete[1];
    KIMMCar_B.INPUT_33_1_1[3] = KIMMCar_DW.INPUT_33_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qx_k = KIMMCar_U.qx_g;
    }

    KIMMCar_B.INPUT_36_1_1[0] = KIMMCar_B.qx_k;
    KIMMCar_B.INPUT_36_1_1[1] = KIMMCar_P.Constant2_Value_i;
    KIMMCar_B.INPUT_36_1_1[2] = KIMMCar_P.Constant3_Value_p;
    if (tmp_7) {
      KIMMCar_DW.INPUT_36_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_36_1_1_Discrete[1]
        == KIMMCar_B.INPUT_36_1_1[2]);
      KIMMCar_DW.INPUT_36_1_1_Discrete[1] = KIMMCar_B.INPUT_36_1_1[2];
    }

    KIMMCar_B.INPUT_36_1_1[2] = KIMMCar_DW.INPUT_36_1_1_Discrete[1];
    KIMMCar_B.INPUT_36_1_1[3] = KIMMCar_DW.INPUT_36_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qz_b = KIMMCar_P.DiscreteTransferFcn3_NumCoef_i *
        KIMMCar_DW.DiscreteTransferFcn3_states_k;
    }

    KIMMCar_B.INPUT_34_1_1[0] = KIMMCar_B.qz_b;
    KIMMCar_B.INPUT_34_1_1[1] = KIMMCar_P.Constant2_Value_i;
    KIMMCar_B.INPUT_34_1_1[2] = KIMMCar_P.Constant3_Value_p;
    if (tmp_7) {
      KIMMCar_DW.INPUT_34_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_34_1_1_Discrete[1]
        == KIMMCar_B.INPUT_34_1_1[2]);
      KIMMCar_DW.INPUT_34_1_1_Discrete[1] = KIMMCar_B.INPUT_34_1_1[2];
    }

    KIMMCar_B.INPUT_34_1_1[2] = KIMMCar_DW.INPUT_34_1_1_Discrete[1];
    KIMMCar_B.INPUT_34_1_1[3] = KIMMCar_DW.INPUT_34_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qy_p = KIMMCar_U.qy_i;
    }

    KIMMCar_B.INPUT_35_1_1[0] = KIMMCar_B.qy_p;
    KIMMCar_B.INPUT_35_1_1[1] = KIMMCar_P.Constant2_Value_i;
    KIMMCar_B.INPUT_35_1_1[2] = KIMMCar_P.Constant3_Value_p;
    if (tmp_7) {
      KIMMCar_DW.INPUT_35_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_35_1_1_Discrete[1]
        == KIMMCar_B.INPUT_35_1_1[2]);
      KIMMCar_DW.INPUT_35_1_1_Discrete[1] = KIMMCar_B.INPUT_35_1_1[2];
    }

    KIMMCar_B.INPUT_35_1_1[2] = KIMMCar_DW.INPUT_35_1_1_Discrete[1];
    KIMMCar_B.INPUT_35_1_1[3] = KIMMCar_DW.INPUT_35_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.px_m = KIMMCar_P.DiscreteTransferFcn1_NumCoef_l *
        KIMMCar_DW.DiscreteTransferFcn1_states_i;
    }

    KIMMCar_B.INPUT_39_1_1[0] = KIMMCar_B.px_m;
    KIMMCar_B.INPUT_39_1_1[1] = KIMMCar_P.Constant_Value_k;
    KIMMCar_B.INPUT_39_1_1[2] = KIMMCar_P.Constant1_Value_a;
    if (tmp_7) {
      KIMMCar_DW.INPUT_39_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_39_1_1_Discrete[1]
        == KIMMCar_B.INPUT_39_1_1[2]);
      KIMMCar_DW.INPUT_39_1_1_Discrete[1] = KIMMCar_B.INPUT_39_1_1[2];
    }

    KIMMCar_B.INPUT_39_1_1[2] = KIMMCar_DW.INPUT_39_1_1_Discrete[1];
    KIMMCar_B.INPUT_39_1_1[3] = KIMMCar_DW.INPUT_39_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.py_le = KIMMCar_P.DiscreteTransferFcn2_NumCoef_n *
        KIMMCar_DW.DiscreteTransferFcn2_states_b;
    }

    KIMMCar_B.INPUT_40_1_1[0] = KIMMCar_B.py_le;
    KIMMCar_B.INPUT_40_1_1[1] = KIMMCar_P.Constant_Value_k;
    KIMMCar_B.INPUT_40_1_1[2] = KIMMCar_P.Constant1_Value_a;
    if (tmp_7) {
      KIMMCar_DW.INPUT_40_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_40_1_1_Discrete[1]
        == KIMMCar_B.INPUT_40_1_1[2]);
      KIMMCar_DW.INPUT_40_1_1_Discrete[1] = KIMMCar_B.INPUT_40_1_1[2];
    }

    KIMMCar_B.INPUT_40_1_1[2] = KIMMCar_DW.INPUT_40_1_1_Discrete[1];
    KIMMCar_B.INPUT_40_1_1[3] = KIMMCar_DW.INPUT_40_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.pz_m = KIMMCar_U.pz_f;
    }

    KIMMCar_B.INPUT_41_1_1[0] = KIMMCar_B.pz_m;
    KIMMCar_B.INPUT_41_1_1[1] = KIMMCar_P.Constant_Value_k;
    KIMMCar_B.INPUT_41_1_1[2] = KIMMCar_P.Constant1_Value_a;
    if (tmp_7) {
      KIMMCar_DW.INPUT_41_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_41_1_1_Discrete[1]
        == KIMMCar_B.INPUT_41_1_1[2]);
      KIMMCar_DW.INPUT_41_1_1_Discrete[1] = KIMMCar_B.INPUT_41_1_1[2];
    }

    KIMMCar_B.INPUT_41_1_1[2] = KIMMCar_DW.INPUT_41_1_1_Discrete[1];
    KIMMCar_B.INPUT_41_1_1[3] = KIMMCar_DW.INPUT_41_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qx_m = KIMMCar_U.qx_l;
    }

    KIMMCar_B.INPUT_44_1_1[0] = KIMMCar_B.qx_m;
    KIMMCar_B.INPUT_44_1_1[1] = KIMMCar_P.Constant2_Value_h;
    KIMMCar_B.INPUT_44_1_1[2] = KIMMCar_P.Constant3_Value_f;
    if (tmp_7) {
      KIMMCar_DW.INPUT_44_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_44_1_1_Discrete[1]
        == KIMMCar_B.INPUT_44_1_1[2]);
      KIMMCar_DW.INPUT_44_1_1_Discrete[1] = KIMMCar_B.INPUT_44_1_1[2];
    }

    KIMMCar_B.INPUT_44_1_1[2] = KIMMCar_DW.INPUT_44_1_1_Discrete[1];
    KIMMCar_B.INPUT_44_1_1[3] = KIMMCar_DW.INPUT_44_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qz_f = KIMMCar_P.DiscreteTransferFcn3_NumCoef_i0 *
        KIMMCar_DW.DiscreteTransferFcn3_states_n;
    }

    KIMMCar_B.INPUT_42_1_1[0] = KIMMCar_B.qz_f;
    KIMMCar_B.INPUT_42_1_1[1] = KIMMCar_P.Constant2_Value_h;
    KIMMCar_B.INPUT_42_1_1[2] = KIMMCar_P.Constant3_Value_f;
    if (tmp_7) {
      KIMMCar_DW.INPUT_42_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_42_1_1_Discrete[1]
        == KIMMCar_B.INPUT_42_1_1[2]);
      KIMMCar_DW.INPUT_42_1_1_Discrete[1] = KIMMCar_B.INPUT_42_1_1[2];
    }

    KIMMCar_B.INPUT_42_1_1[2] = KIMMCar_DW.INPUT_42_1_1_Discrete[1];
    KIMMCar_B.INPUT_42_1_1[3] = KIMMCar_DW.INPUT_42_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qy_j = KIMMCar_U.qy_a;
    }

    KIMMCar_B.INPUT_43_1_1[0] = KIMMCar_B.qy_j;
    KIMMCar_B.INPUT_43_1_1[1] = KIMMCar_P.Constant2_Value_h;
    KIMMCar_B.INPUT_43_1_1[2] = KIMMCar_P.Constant3_Value_f;
    if (tmp_7) {
      KIMMCar_DW.INPUT_43_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_43_1_1_Discrete[1]
        == KIMMCar_B.INPUT_43_1_1[2]);
      KIMMCar_DW.INPUT_43_1_1_Discrete[1] = KIMMCar_B.INPUT_43_1_1[2];
    }

    KIMMCar_B.INPUT_43_1_1[2] = KIMMCar_DW.INPUT_43_1_1_Discrete[1];
    KIMMCar_B.INPUT_43_1_1[3] = KIMMCar_DW.INPUT_43_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.px_f = KIMMCar_P.DiscreteTransferFcn1_NumCoef_e *
        KIMMCar_DW.DiscreteTransferFcn1_states_g;
    }

    KIMMCar_B.INPUT_47_1_1[0] = KIMMCar_B.px_f;
    KIMMCar_B.INPUT_47_1_1[1] = KIMMCar_P.Constant_Value_b;
    KIMMCar_B.INPUT_47_1_1[2] = KIMMCar_P.Constant1_Value_h;
    if (tmp_7) {
      KIMMCar_DW.INPUT_47_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_47_1_1_Discrete[1]
        == KIMMCar_B.INPUT_47_1_1[2]);
      KIMMCar_DW.INPUT_47_1_1_Discrete[1] = KIMMCar_B.INPUT_47_1_1[2];
    }

    KIMMCar_B.INPUT_47_1_1[2] = KIMMCar_DW.INPUT_47_1_1_Discrete[1];
    KIMMCar_B.INPUT_47_1_1[3] = KIMMCar_DW.INPUT_47_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.py_m = KIMMCar_P.DiscreteTransferFcn2_NumCoef_p *
        KIMMCar_DW.DiscreteTransferFcn2_states_j;
    }

    KIMMCar_B.INPUT_48_1_1[0] = KIMMCar_B.py_m;
    KIMMCar_B.INPUT_48_1_1[1] = KIMMCar_P.Constant_Value_b;
    KIMMCar_B.INPUT_48_1_1[2] = KIMMCar_P.Constant1_Value_h;
    if (tmp_7) {
      KIMMCar_DW.INPUT_48_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_48_1_1_Discrete[1]
        == KIMMCar_B.INPUT_48_1_1[2]);
      KIMMCar_DW.INPUT_48_1_1_Discrete[1] = KIMMCar_B.INPUT_48_1_1[2];
    }

    KIMMCar_B.INPUT_48_1_1[2] = KIMMCar_DW.INPUT_48_1_1_Discrete[1];
    KIMMCar_B.INPUT_48_1_1[3] = KIMMCar_DW.INPUT_48_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.pz_h = KIMMCar_U.pz_i;
    }

    KIMMCar_B.INPUT_49_1_1[0] = KIMMCar_B.pz_h;
    KIMMCar_B.INPUT_49_1_1[1] = KIMMCar_P.Constant_Value_b;
    KIMMCar_B.INPUT_49_1_1[2] = KIMMCar_P.Constant1_Value_h;
    if (tmp_7) {
      KIMMCar_DW.INPUT_49_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_49_1_1_Discrete[1]
        == KIMMCar_B.INPUT_49_1_1[2]);
      KIMMCar_DW.INPUT_49_1_1_Discrete[1] = KIMMCar_B.INPUT_49_1_1[2];
    }

    KIMMCar_B.INPUT_49_1_1[2] = KIMMCar_DW.INPUT_49_1_1_Discrete[1];
    KIMMCar_B.INPUT_49_1_1[3] = KIMMCar_DW.INPUT_49_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qx_g = KIMMCar_U.qx_m;
    }

    KIMMCar_B.INPUT_52_1_1[0] = KIMMCar_B.qx_g;
    KIMMCar_B.INPUT_52_1_1[1] = KIMMCar_P.Constant2_Value_j;
    KIMMCar_B.INPUT_52_1_1[2] = KIMMCar_P.Constant3_Value_k;
    if (tmp_7) {
      KIMMCar_DW.INPUT_52_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_52_1_1_Discrete[1]
        == KIMMCar_B.INPUT_52_1_1[2]);
      KIMMCar_DW.INPUT_52_1_1_Discrete[1] = KIMMCar_B.INPUT_52_1_1[2];
    }

    KIMMCar_B.INPUT_52_1_1[2] = KIMMCar_DW.INPUT_52_1_1_Discrete[1];
    KIMMCar_B.INPUT_52_1_1[3] = KIMMCar_DW.INPUT_52_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qz_n = KIMMCar_P.DiscreteTransferFcn3_NumCoef_g *
        KIMMCar_DW.DiscreteTransferFcn3_states_n1;
    }

    KIMMCar_B.INPUT_50_1_1[0] = KIMMCar_B.qz_n;
    KIMMCar_B.INPUT_50_1_1[1] = KIMMCar_P.Constant2_Value_j;
    KIMMCar_B.INPUT_50_1_1[2] = KIMMCar_P.Constant3_Value_k;
    if (tmp_7) {
      KIMMCar_DW.INPUT_50_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_50_1_1_Discrete[1]
        == KIMMCar_B.INPUT_50_1_1[2]);
      KIMMCar_DW.INPUT_50_1_1_Discrete[1] = KIMMCar_B.INPUT_50_1_1[2];
    }

    KIMMCar_B.INPUT_50_1_1[2] = KIMMCar_DW.INPUT_50_1_1_Discrete[1];
    KIMMCar_B.INPUT_50_1_1[3] = KIMMCar_DW.INPUT_50_1_1_Discrete[0];
    if (zeroGuard) {
      KIMMCar_B.qy_o = KIMMCar_U.qy_b;
    }

    KIMMCar_B.INPUT_51_1_1[0] = KIMMCar_B.qy_o;
    KIMMCar_B.INPUT_51_1_1[1] = KIMMCar_P.Constant2_Value_j;
    KIMMCar_B.INPUT_51_1_1[2] = KIMMCar_P.Constant3_Value_k;
    if (tmp_7) {
      KIMMCar_DW.INPUT_51_1_1_Discrete[0] = !(KIMMCar_DW.INPUT_51_1_1_Discrete[1]
        == KIMMCar_B.INPUT_51_1_1[2]);
      KIMMCar_DW.INPUT_51_1_1_Discrete[1] = KIMMCar_B.INPUT_51_1_1[2];
    }

    KIMMCar_B.INPUT_51_1_1[2] = KIMMCar_DW.INPUT_51_1_1_Discrete[1];
    KIMMCar_B.INPUT_51_1_1[3] = KIMMCar_DW.INPUT_51_1_1_Discrete[0];
    if (zeroGuard) {
      if (KIMMCar_DW.RTP_1_SetParametersNeeded) {
        tmp[0] = KIMMCar_P.RTP_041AAD1B_VelocityTargetValue_Value;
        tmp[1] = Veh_SuspR_C;
        tmp[2] = Veh_SuspR_EqPos;
        tmp[3] = Veh_SuspR_BumpLimit;
        tmp[4] = Veh_SuspR_BumpC;
        tmp[5] = Veh_SuspR_BumpK;
        tmp[6] = Veh_SuspR_BumpWidth;
        tmp[7] = Veh_SuspR_K;
        tmp[8] = Veh_SuspR_ReboundLimit;
        tmp[9] = Veh_SuspR_ReboundC;
        tmp[10] = Veh_SuspR_ReboundK;
        tmp[11] = Veh_SuspR_ReboundWidth;
        tmp[12] = KIMMCar_P.RTP_087BC81F_VelocityTargetValue_Value;
        tmp[13] = KIMMCar_P.RTP_0ABA0B7C_RotationAngle_Value;
        tmp[14] = KIMMCar_P.RTP_0ABA0B7C_TranslationStandardOffset_Value;
        tmp[15] = KIMMCar_P.SuspensionRear_lUnsprungMass;
        tmp[16] = KIMMCar_P.RTP_15BC236D_CylinderRadius_Value;
        tmp[17] = Veh_SuspR_UnsprungMass;
        tmp[18] = Veh_SuspR_UnsprungInertia[0];
        tmp[19] = Veh_SuspR_UnsprungInertia[1];
        tmp[20] = Veh_SuspR_UnsprungInertia[2];
        tmp[21] = KIMMCar_P.RTP_2D46EB53_TranslationCartesianOffset_Value[0];
        tmp[22] = KIMMCar_P.RTP_2D46EB53_TranslationCartesianOffset_Value[1];
        tmp[23] = KIMMCar_P.RTP_2D46EB53_TranslationCartesianOffset_Value[2];
        tmp[24] = Veh_BodyRefZ0;
        tmp[25] = KIMMCar_P.RTP_5BD4A88C_VelocityTargetValue_Value;
        tmp[26] = KIMMCar_P.SuspensionFront_lUnsprungMass;
        tmp[27] = KIMMCar_P.RTP_6A570A4D_CylinderRadius_Value;
        tmp[28] = Veh_SuspF_UnsprungMass;
        tmp[29] = Veh_SuspF_UnsprungInertia[0];
        tmp[30] = Veh_SuspF_UnsprungInertia[1];
        tmp[31] = Veh_SuspF_UnsprungInertia[2];
        tmp[32] = KIMMCar_P.SuspensionFront_lUnsprungMass;
        tmp[33] = KIMMCar_P.RTP_6D3ACE54_CylinderRadius_Value;
        tmp[34] = Veh_SuspF_UnsprungMass;
        tmp[35] = Veh_SuspF_UnsprungInertia[0];
        tmp[36] = Veh_SuspF_UnsprungInertia[1];
        tmp[37] = Veh_SuspF_UnsprungInertia[2];
        tmp[38] = Veh_SuspF_C;
        tmp[39] = Veh_SuspF_EqPos;
        tmp[40] = Veh_SuspF_BumpLimit;
        tmp[41] = Veh_SuspF_BumpC;
        tmp[42] = Veh_SuspF_BumpK;
        tmp[43] = Veh_SuspF_BumpWidth;
        tmp[44] = Veh_SuspF_K;
        tmp[45] = Veh_SuspF_ReboundLimit;
        tmp[46] = Veh_SuspF_ReboundC;
        tmp[47] = Veh_SuspF_ReboundK;
        tmp[48] = Veh_SuspF_ReboundWidth;
        tmp[49] = KIMMCar_P.RTP_73B42110_TranslationCartesianOffset_Value[0];
        tmp[50] = KIMMCar_P.RTP_73B42110_TranslationCartesianOffset_Value[1];
        tmp[51] = KIMMCar_P.RTP_73B42110_TranslationCartesianOffset_Value[2];
        tmp[52] = KIMMCar_P.RTP_73B42110_TranslationStandardOffset_Value;
        tmp[53] = Veh_BodyMass;
        tmp[54] = Veh_BodyInertia[0];
        tmp[55] = Veh_BodyInertia[1];
        tmp[56] = Veh_BodyInertia[2];
        tmp[57] = KIMMCar_P.RTP_7DBD3BEA_CenterOfMass_Value[0];
        tmp[58] = KIMMCar_P.RTP_7DBD3BEA_CenterOfMass_Value[1];
        tmp[59] = KIMMCar_P.RTP_7DBD3BEA_CenterOfMass_Value[2];
        tmp[60] = KIMMCar_P.RTP_7DBD3BEA_Mass_Value;
        tmp[61] = KIMMCar_P.RTP_7DBD3BEA_MomentsOfInertia_Value[0];
        tmp[62] = KIMMCar_P.RTP_7DBD3BEA_MomentsOfInertia_Value[1];
        tmp[63] = KIMMCar_P.RTP_7DBD3BEA_MomentsOfInertia_Value[2];
        tmp[64] = KIMMCar_P.RTP_7DBD3BEA_ProductsOfInertia_Value[0];
        tmp[65] = KIMMCar_P.RTP_7DBD3BEA_ProductsOfInertia_Value[1];
        tmp[66] = KIMMCar_P.RTP_7DBD3BEA_ProductsOfInertia_Value[2];
        tmp[67] = Veh_SuspR_C;
        tmp[68] = Veh_SuspR_EqPos;
        tmp[69] = Veh_SuspR_BumpLimit;
        tmp[70] = Veh_SuspR_BumpC;
        tmp[71] = Veh_SuspR_BumpK;
        tmp[72] = Veh_SuspR_BumpWidth;
        tmp[73] = Veh_SuspR_K;
        tmp[74] = Veh_SuspR_ReboundLimit;
        tmp[75] = Veh_SuspR_ReboundC;
        tmp[76] = Veh_SuspR_ReboundK;
        tmp[77] = Veh_SuspR_ReboundWidth;
        tmp[78] = KIMMCar_P.RTP_9CB22C5A_VelocityTargetValue_Value;
        tmp[79] = KIMMCar_P.RTP_A11E2A99_RotationAngle_Value;
        tmp[80] = KIMMCar_P.RTP_A11E2A99_TranslationStandardOffset_Value;
        tmp[81] = KIMMCar_P.RTP_A5036385_CenterOfMass_Value[0];
        tmp[82] = KIMMCar_P.RTP_A5036385_CenterOfMass_Value[1];
        tmp[83] = KIMMCar_P.RTP_A5036385_CenterOfMass_Value[2];
        tmp[84] = KIMMCar_P.RTP_A5036385_Mass_Value;
        tmp[85] = KIMMCar_P.RTP_A5036385_MomentsOfInertia_Value[0];
        tmp[86] = KIMMCar_P.RTP_A5036385_MomentsOfInertia_Value[1];
        tmp[87] = KIMMCar_P.RTP_A5036385_MomentsOfInertia_Value[2];
        tmp[88] = KIMMCar_P.RTP_A5036385_ProductsOfInertia_Value[0];
        tmp[89] = KIMMCar_P.RTP_A5036385_ProductsOfInertia_Value[1];
        tmp[90] = KIMMCar_P.RTP_A5036385_ProductsOfInertia_Value[2];
        tmp[91] = KIMMCar_P.RTP_B27877C6_CenterOfMass_Value[0];
        tmp[92] = KIMMCar_P.RTP_B27877C6_CenterOfMass_Value[1];
        tmp[93] = KIMMCar_P.RTP_B27877C6_CenterOfMass_Value[2];
        tmp[94] = KIMMCar_P.RTP_B27877C6_Mass_Value;
        tmp[95] = KIMMCar_P.RTP_B27877C6_MomentsOfInertia_Value[0];
        tmp[96] = KIMMCar_P.RTP_B27877C6_MomentsOfInertia_Value[1];
        tmp[97] = KIMMCar_P.RTP_B27877C6_MomentsOfInertia_Value[2];
        tmp[98] = KIMMCar_P.RTP_B27877C6_ProductsOfInertia_Value[0];
        tmp[99] = KIMMCar_P.RTP_B27877C6_ProductsOfInertia_Value[1];
        tmp[100] = KIMMCar_P.RTP_B27877C6_ProductsOfInertia_Value[2];
        tmp[101] = Veh_BodytoWheelCenter;
        tmp[102] = KIMMCar_P.RTP_C019A91A_TranslationCartesianOffset_Value[0];
        tmp[103] = KIMMCar_P.RTP_C019A91A_TranslationCartesianOffset_Value[1];
        tmp[104] = KIMMCar_P.RTP_C019A91A_TranslationCartesianOffset_Value[2];
        tmp[105] = KIMMCar_P.RTP_C019A91A_TranslationStandardOffset_Value;
        tmp[106] = Veh_SuspF_C;
        tmp[107] = Veh_SuspF_EqPos;
        tmp[108] = Veh_SuspF_BumpLimit;
        tmp[109] = Veh_SuspF_BumpC;
        tmp[110] = Veh_SuspF_BumpK;
        tmp[111] = Veh_SuspF_BumpWidth;
        tmp[112] = Veh_SuspF_K;
        tmp[113] = Veh_SuspF_ReboundLimit;
        tmp[114] = Veh_SuspF_ReboundC;
        tmp[115] = Veh_SuspF_ReboundK;
        tmp[116] = Veh_SuspF_ReboundWidth;
        tmp[117] = KIMMCar_P.RTP_C57F4750_RotationAngle_Value;
        tmp[118] = KIMMCar_P.RTP_C57F4750_TranslationStandardOffset_Value;
        tmp[119] = KIMMCar_P.RTP_D2045313_RotationAngle_Value;
        tmp[120] = KIMMCar_P.RTP_D2045313_TranslationStandardOffset_Value;
        tmp[121] = KIMMCar_P.RTP_D6191A0F_CenterOfMass_Value[0];
        tmp[122] = KIMMCar_P.RTP_D6191A0F_CenterOfMass_Value[1];
        tmp[123] = KIMMCar_P.RTP_D6191A0F_CenterOfMass_Value[2];
        tmp[124] = KIMMCar_P.RTP_D6191A0F_Mass_Value;
        tmp[125] = KIMMCar_P.RTP_D6191A0F_MomentsOfInertia_Value[0];
        tmp[126] = KIMMCar_P.RTP_D6191A0F_MomentsOfInertia_Value[1];
        tmp[127] = KIMMCar_P.RTP_D6191A0F_MomentsOfInertia_Value[2];
        tmp[128] = KIMMCar_P.RTP_D6191A0F_ProductsOfInertia_Value[0];
        tmp[129] = KIMMCar_P.RTP_D6191A0F_ProductsOfInertia_Value[1];
        tmp[130] = KIMMCar_P.RTP_D6191A0F_ProductsOfInertia_Value[2];
        tmp[131] = KIMMCar_P.SuspensionRear_lUnsprungMass;
        tmp[132] = KIMMCar_P.RTP_F6ED1E1D_CylinderRadius_Value;
        tmp[133] = Veh_SuspR_UnsprungMass;
        tmp[134] = Veh_SuspR_UnsprungInertia[0];
        tmp[135] = Veh_SuspR_UnsprungInertia[1];
        tmp[136] = Veh_SuspR_UnsprungInertia[2];
        diag = rtw_create_diagnostics();
        diagTree = neu_diagnostic_manager_get_initial_tree(diag);
        expl_temp.mRealParameters.mN = 137;
        expl_temp.mRealParameters.mX = &tmp[0];
        expl_temp.mLogicalParameters.mN = 0;
        expl_temp.mLogicalParameters.mX = NULL;
        expl_temp.mIntegerParameters.mN = 0;
        expl_temp.mIntegerParameters.mX = NULL;
        expl_temp.mIndexParameters.mN = 0;
        expl_temp.mIndexParameters.mX = NULL;
        first_output = nesl_rtp_manager_set_rtps((NeslRtpManager *)
          KIMMCar_DW.RTP_1_RtpManager, KIMMCar_M->Timing.t[0], expl_temp, diag);
        if (!first_output) {
          first_output = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
          if (first_output) {
            msg = rtw_diagnostics_msg(diagTree);
            rtmSetErrorStatus(KIMMCar_M, msg);
          }
        }
      }

      KIMMCar_DW.RTP_1_SetParametersNeeded = false;
    }

    simulationData = (NeslSimulationData *)KIMMCar_DW.STATE_1_SimData;
    rtb_Gain7 = KIMMCar_M->Timing.t[0];
    time = rtb_Gain7;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 29;
    simulationData->mData->mContStates.mX =
      &KIMMCar_X.KIMMCarVehicleCamera_FramesCartesian_JointPxp[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &KIMMCar_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &KIMMCar_DW.STATE_1_Modes;
    first_output = false;
    simulationData->mData->mFoundZcEvents = first_output;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = tmp_7;
    first_output = false;
    simulationData->mData->mIsSolverAssertCheck = first_output;
    simulationData->mData->mIsSolverCheckingCIC = false;
    first_output = rtsiIsSolverComputingJacobian(&KIMMCar_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = first_output;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    first_output = rtsiIsModeUpdateTimeStep(&KIMMCar_M->solverInfo);
    simulationData->mData->mIsModeUpdateTimeStep = first_output;
    tmp_1[0] = 0;
    tmp_0[0] = KIMMCar_B.INPUT_3_1_1[0];
    tmp_0[1] = KIMMCar_B.INPUT_3_1_1[1];
    tmp_0[2] = KIMMCar_B.INPUT_3_1_1[2];
    tmp_0[3] = KIMMCar_B.INPUT_3_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = KIMMCar_B.INPUT_4_1_1[0];
    tmp_0[5] = KIMMCar_B.INPUT_4_1_1[1];
    tmp_0[6] = KIMMCar_B.INPUT_4_1_1[2];
    tmp_0[7] = KIMMCar_B.INPUT_4_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = KIMMCar_B.INPUT_5_1_1[0];
    tmp_0[9] = KIMMCar_B.INPUT_5_1_1[1];
    tmp_0[10] = KIMMCar_B.INPUT_5_1_1[2];
    tmp_0[11] = KIMMCar_B.INPUT_5_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = KIMMCar_B.INPUT_6_1_1[0];
    tmp_0[13] = KIMMCar_B.INPUT_6_1_1[1];
    tmp_0[14] = KIMMCar_B.INPUT_6_1_1[2];
    tmp_0[15] = KIMMCar_B.INPUT_6_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = KIMMCar_B.INPUT_7_1_1[0];
    tmp_0[17] = KIMMCar_B.INPUT_7_1_1[1];
    tmp_0[18] = KIMMCar_B.INPUT_7_1_1[2];
    tmp_0[19] = KIMMCar_B.INPUT_7_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = KIMMCar_B.INPUT_8_1_1[0];
    tmp_0[21] = KIMMCar_B.INPUT_8_1_1[1];
    tmp_0[22] = KIMMCar_B.INPUT_8_1_1[2];
    tmp_0[23] = KIMMCar_B.INPUT_8_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = KIMMCar_B.INPUT_9_1_1[0];
    tmp_0[25] = KIMMCar_B.INPUT_9_1_1[1];
    tmp_0[26] = KIMMCar_B.INPUT_9_1_1[2];
    tmp_0[27] = KIMMCar_B.INPUT_9_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = KIMMCar_B.INPUT_14_1_1[0];
    tmp_0[29] = KIMMCar_B.INPUT_14_1_1[1];
    tmp_0[30] = KIMMCar_B.INPUT_14_1_1[2];
    tmp_0[31] = KIMMCar_B.INPUT_14_1_1[3];
    tmp_1[8] = 32;
    tmp_0[32] = KIMMCar_B.INPUT_10_1_1[0];
    tmp_0[33] = KIMMCar_B.INPUT_10_1_1[1];
    tmp_0[34] = KIMMCar_B.INPUT_10_1_1[2];
    tmp_0[35] = KIMMCar_B.INPUT_10_1_1[3];
    tmp_1[9] = 36;
    tmp_0[36] = KIMMCar_B.INPUT_11_1_1[0];
    tmp_0[37] = KIMMCar_B.INPUT_11_1_1[1];
    tmp_0[38] = KIMMCar_B.INPUT_11_1_1[2];
    tmp_0[39] = KIMMCar_B.INPUT_11_1_1[3];
    tmp_1[10] = 40;
    tmp_0[40] = KIMMCar_B.INPUT_12_1_1[0];
    tmp_0[41] = KIMMCar_B.INPUT_12_1_1[1];
    tmp_0[42] = KIMMCar_B.INPUT_12_1_1[2];
    tmp_0[43] = KIMMCar_B.INPUT_12_1_1[3];
    tmp_1[11] = 44;
    tmp_0[44] = KIMMCar_B.INPUT_13_1_1[0];
    tmp_0[45] = KIMMCar_B.INPUT_13_1_1[1];
    tmp_0[46] = KIMMCar_B.INPUT_13_1_1[2];
    tmp_0[47] = KIMMCar_B.INPUT_13_1_1[3];
    tmp_1[12] = 48;
    tmp_0[48] = KIMMCar_B.INPUT_15_1_1[0];
    tmp_0[49] = KIMMCar_B.INPUT_15_1_1[1];
    tmp_0[50] = KIMMCar_B.INPUT_15_1_1[2];
    tmp_0[51] = KIMMCar_B.INPUT_15_1_1[3];
    tmp_1[13] = 52;
    tmp_0[52] = KIMMCar_B.INPUT_16_1_1[0];
    tmp_0[53] = KIMMCar_B.INPUT_16_1_1[1];
    tmp_0[54] = KIMMCar_B.INPUT_16_1_1[2];
    tmp_0[55] = KIMMCar_B.INPUT_16_1_1[3];
    tmp_1[14] = 56;
    tmp_0[56] = KIMMCar_B.INPUT_17_1_1[0];
    tmp_0[57] = KIMMCar_B.INPUT_17_1_1[1];
    tmp_0[58] = KIMMCar_B.INPUT_17_1_1[2];
    tmp_0[59] = KIMMCar_B.INPUT_17_1_1[3];
    tmp_1[15] = 60;
    tmp_0[60] = KIMMCar_B.INPUT_21_1_1[0];
    tmp_0[61] = KIMMCar_B.INPUT_21_1_1[1];
    tmp_0[62] = KIMMCar_B.INPUT_21_1_1[2];
    tmp_0[63] = KIMMCar_B.INPUT_21_1_1[3];
    tmp_1[16] = 64;
    tmp_0[64] = KIMMCar_B.INPUT_18_1_1[0];
    tmp_0[65] = KIMMCar_B.INPUT_18_1_1[1];
    tmp_0[66] = KIMMCar_B.INPUT_18_1_1[2];
    tmp_0[67] = KIMMCar_B.INPUT_18_1_1[3];
    tmp_1[17] = 68;
    tmp_0[68] = KIMMCar_B.INPUT_19_1_1[0];
    tmp_0[69] = KIMMCar_B.INPUT_19_1_1[1];
    tmp_0[70] = KIMMCar_B.INPUT_19_1_1[2];
    tmp_0[71] = KIMMCar_B.INPUT_19_1_1[3];
    tmp_1[18] = 72;
    tmp_0[72] = KIMMCar_B.INPUT_20_1_1[0];
    tmp_0[73] = KIMMCar_B.INPUT_20_1_1[1];
    tmp_0[74] = KIMMCar_B.INPUT_20_1_1[2];
    tmp_0[75] = KIMMCar_B.INPUT_20_1_1[3];
    tmp_1[19] = 76;
    tmp_0[76] = KIMMCar_B.INPUT_22_1_1[0];
    tmp_0[77] = KIMMCar_B.INPUT_22_1_1[1];
    tmp_0[78] = KIMMCar_B.INPUT_22_1_1[2];
    tmp_0[79] = KIMMCar_B.INPUT_22_1_1[3];
    tmp_1[20] = 80;
    tmp_0[80] = KIMMCar_B.INPUT_23_1_1[0];
    tmp_0[81] = KIMMCar_B.INPUT_23_1_1[1];
    tmp_0[82] = KIMMCar_B.INPUT_23_1_1[2];
    tmp_0[83] = KIMMCar_B.INPUT_23_1_1[3];
    tmp_1[21] = 84;
    tmp_0[84] = KIMMCar_B.INPUT_24_1_1[0];
    tmp_0[85] = KIMMCar_B.INPUT_24_1_1[1];
    tmp_0[86] = KIMMCar_B.INPUT_24_1_1[2];
    tmp_0[87] = KIMMCar_B.INPUT_24_1_1[3];
    tmp_1[22] = 88;
    tmp_0[88] = KIMMCar_B.INPUT_25_1_1[0];
    tmp_0[89] = KIMMCar_B.INPUT_25_1_1[1];
    tmp_0[90] = KIMMCar_B.INPUT_25_1_1[2];
    tmp_0[91] = KIMMCar_B.INPUT_25_1_1[3];
    tmp_1[23] = 92;
    tmp_0[92] = KIMMCar_B.INPUT_28_1_1[0];
    tmp_0[93] = KIMMCar_B.INPUT_28_1_1[1];
    tmp_0[94] = KIMMCar_B.INPUT_28_1_1[2];
    tmp_0[95] = KIMMCar_B.INPUT_28_1_1[3];
    tmp_1[24] = 96;
    tmp_0[96] = KIMMCar_B.INPUT_26_1_1[0];
    tmp_0[97] = KIMMCar_B.INPUT_26_1_1[1];
    tmp_0[98] = KIMMCar_B.INPUT_26_1_1[2];
    tmp_0[99] = KIMMCar_B.INPUT_26_1_1[3];
    tmp_1[25] = 100;
    tmp_0[100] = KIMMCar_B.INPUT_27_1_1[0];
    tmp_0[101] = KIMMCar_B.INPUT_27_1_1[1];
    tmp_0[102] = KIMMCar_B.INPUT_27_1_1[2];
    tmp_0[103] = KIMMCar_B.INPUT_27_1_1[3];
    tmp_1[26] = 104;
    tmp_0[104] = KIMMCar_B.INPUT_31_1_1[0];
    tmp_0[105] = KIMMCar_B.INPUT_31_1_1[1];
    tmp_0[106] = KIMMCar_B.INPUT_31_1_1[2];
    tmp_0[107] = KIMMCar_B.INPUT_31_1_1[3];
    tmp_1[27] = 108;
    tmp_0[108] = KIMMCar_B.INPUT_32_1_1[0];
    tmp_0[109] = KIMMCar_B.INPUT_32_1_1[1];
    tmp_0[110] = KIMMCar_B.INPUT_32_1_1[2];
    tmp_0[111] = KIMMCar_B.INPUT_32_1_1[3];
    tmp_1[28] = 112;
    tmp_0[112] = KIMMCar_B.INPUT_33_1_1[0];
    tmp_0[113] = KIMMCar_B.INPUT_33_1_1[1];
    tmp_0[114] = KIMMCar_B.INPUT_33_1_1[2];
    tmp_0[115] = KIMMCar_B.INPUT_33_1_1[3];
    tmp_1[29] = 116;
    tmp_0[116] = KIMMCar_B.INPUT_36_1_1[0];
    tmp_0[117] = KIMMCar_B.INPUT_36_1_1[1];
    tmp_0[118] = KIMMCar_B.INPUT_36_1_1[2];
    tmp_0[119] = KIMMCar_B.INPUT_36_1_1[3];
    tmp_1[30] = 120;
    tmp_0[120] = KIMMCar_B.INPUT_34_1_1[0];
    tmp_0[121] = KIMMCar_B.INPUT_34_1_1[1];
    tmp_0[122] = KIMMCar_B.INPUT_34_1_1[2];
    tmp_0[123] = KIMMCar_B.INPUT_34_1_1[3];
    tmp_1[31] = 124;
    tmp_0[124] = KIMMCar_B.INPUT_35_1_1[0];
    tmp_0[125] = KIMMCar_B.INPUT_35_1_1[1];
    tmp_0[126] = KIMMCar_B.INPUT_35_1_1[2];
    tmp_0[127] = KIMMCar_B.INPUT_35_1_1[3];
    tmp_1[32] = 128;
    tmp_0[128] = KIMMCar_B.INPUT_39_1_1[0];
    tmp_0[129] = KIMMCar_B.INPUT_39_1_1[1];
    tmp_0[130] = KIMMCar_B.INPUT_39_1_1[2];
    tmp_0[131] = KIMMCar_B.INPUT_39_1_1[3];
    tmp_1[33] = 132;
    tmp_0[132] = KIMMCar_B.INPUT_40_1_1[0];
    tmp_0[133] = KIMMCar_B.INPUT_40_1_1[1];
    tmp_0[134] = KIMMCar_B.INPUT_40_1_1[2];
    tmp_0[135] = KIMMCar_B.INPUT_40_1_1[3];
    tmp_1[34] = 136;
    tmp_0[136] = KIMMCar_B.INPUT_41_1_1[0];
    tmp_0[137] = KIMMCar_B.INPUT_41_1_1[1];
    tmp_0[138] = KIMMCar_B.INPUT_41_1_1[2];
    tmp_0[139] = KIMMCar_B.INPUT_41_1_1[3];
    tmp_1[35] = 140;
    tmp_0[140] = KIMMCar_B.INPUT_44_1_1[0];
    tmp_0[141] = KIMMCar_B.INPUT_44_1_1[1];
    tmp_0[142] = KIMMCar_B.INPUT_44_1_1[2];
    tmp_0[143] = KIMMCar_B.INPUT_44_1_1[3];
    tmp_1[36] = 144;
    tmp_0[144] = KIMMCar_B.INPUT_42_1_1[0];
    tmp_0[145] = KIMMCar_B.INPUT_42_1_1[1];
    tmp_0[146] = KIMMCar_B.INPUT_42_1_1[2];
    tmp_0[147] = KIMMCar_B.INPUT_42_1_1[3];
    tmp_1[37] = 148;
    tmp_0[148] = KIMMCar_B.INPUT_43_1_1[0];
    tmp_0[149] = KIMMCar_B.INPUT_43_1_1[1];
    tmp_0[150] = KIMMCar_B.INPUT_43_1_1[2];
    tmp_0[151] = KIMMCar_B.INPUT_43_1_1[3];
    tmp_1[38] = 152;
    tmp_0[152] = KIMMCar_B.INPUT_47_1_1[0];
    tmp_0[153] = KIMMCar_B.INPUT_47_1_1[1];
    tmp_0[154] = KIMMCar_B.INPUT_47_1_1[2];
    tmp_0[155] = KIMMCar_B.INPUT_47_1_1[3];
    tmp_1[39] = 156;
    tmp_0[156] = KIMMCar_B.INPUT_48_1_1[0];
    tmp_0[157] = KIMMCar_B.INPUT_48_1_1[1];
    tmp_0[158] = KIMMCar_B.INPUT_48_1_1[2];
    tmp_0[159] = KIMMCar_B.INPUT_48_1_1[3];
    tmp_1[40] = 160;
    tmp_0[160] = KIMMCar_B.INPUT_49_1_1[0];
    tmp_0[161] = KIMMCar_B.INPUT_49_1_1[1];
    tmp_0[162] = KIMMCar_B.INPUT_49_1_1[2];
    tmp_0[163] = KIMMCar_B.INPUT_49_1_1[3];
    tmp_1[41] = 164;
    tmp_0[164] = KIMMCar_B.INPUT_52_1_1[0];
    tmp_0[165] = KIMMCar_B.INPUT_52_1_1[1];
    tmp_0[166] = KIMMCar_B.INPUT_52_1_1[2];
    tmp_0[167] = KIMMCar_B.INPUT_52_1_1[3];
    tmp_1[42] = 168;
    tmp_0[168] = KIMMCar_B.INPUT_50_1_1[0];
    tmp_0[169] = KIMMCar_B.INPUT_50_1_1[1];
    tmp_0[170] = KIMMCar_B.INPUT_50_1_1[2];
    tmp_0[171] = KIMMCar_B.INPUT_50_1_1[3];
    tmp_1[43] = 172;
    tmp_0[172] = KIMMCar_B.INPUT_51_1_1[0];
    tmp_0[173] = KIMMCar_B.INPUT_51_1_1[1];
    tmp_0[174] = KIMMCar_B.INPUT_51_1_1[2];
    tmp_0[175] = KIMMCar_B.INPUT_51_1_1[3];
    tmp_1[44] = 176;
    tmp_0[176] = KIMMCar_B.INPUT_1_1_1[0];
    tmp_0[177] = KIMMCar_B.INPUT_1_1_1[1];
    tmp_0[178] = KIMMCar_B.INPUT_1_1_1[2];
    tmp_0[179] = KIMMCar_B.INPUT_1_1_1[3];
    tmp_1[45] = 180;
    tmp_0[180] = KIMMCar_B.INPUT_2_1_1[0];
    tmp_0[181] = KIMMCar_B.INPUT_2_1_1[1];
    tmp_0[182] = KIMMCar_B.INPUT_2_1_1[2];
    tmp_0[183] = KIMMCar_B.INPUT_2_1_1[3];
    tmp_1[46] = 184;
    tmp_0[184] = KIMMCar_B.INPUT_29_1_1[0];
    tmp_0[185] = KIMMCar_B.INPUT_29_1_1[1];
    tmp_0[186] = KIMMCar_B.INPUT_29_1_1[2];
    tmp_0[187] = KIMMCar_B.INPUT_29_1_1[3];
    tmp_1[47] = 188;
    tmp_0[188] = KIMMCar_B.INPUT_30_1_1[0];
    tmp_0[189] = KIMMCar_B.INPUT_30_1_1[1];
    tmp_0[190] = KIMMCar_B.INPUT_30_1_1[2];
    tmp_0[191] = KIMMCar_B.INPUT_30_1_1[3];
    tmp_1[48] = 192;
    tmp_0[192] = KIMMCar_B.INPUT_37_1_1[0];
    tmp_0[193] = KIMMCar_B.INPUT_37_1_1[1];
    tmp_0[194] = KIMMCar_B.INPUT_37_1_1[2];
    tmp_0[195] = KIMMCar_B.INPUT_37_1_1[3];
    tmp_1[49] = 196;
    tmp_0[196] = KIMMCar_B.INPUT_38_1_1[0];
    tmp_0[197] = KIMMCar_B.INPUT_38_1_1[1];
    tmp_0[198] = KIMMCar_B.INPUT_38_1_1[2];
    tmp_0[199] = KIMMCar_B.INPUT_38_1_1[3];
    tmp_1[50] = 200;
    tmp_0[200] = KIMMCar_B.INPUT_45_1_1[0];
    tmp_0[201] = KIMMCar_B.INPUT_45_1_1[1];
    tmp_0[202] = KIMMCar_B.INPUT_45_1_1[2];
    tmp_0[203] = KIMMCar_B.INPUT_45_1_1[3];
    tmp_1[51] = 204;
    tmp_0[204] = KIMMCar_B.INPUT_46_1_1[0];
    tmp_0[205] = KIMMCar_B.INPUT_46_1_1[1];
    tmp_0[206] = KIMMCar_B.INPUT_46_1_1[2];
    tmp_0[207] = KIMMCar_B.INPUT_46_1_1[3];
    tmp_1[52] = 208;
    tmp_0[208] = KIMMCar_B.INPUT_53_1_1[0];
    tmp_0[209] = KIMMCar_B.INPUT_53_1_1[1];
    tmp_0[210] = KIMMCar_B.INPUT_53_1_1[2];
    tmp_0[211] = KIMMCar_B.INPUT_53_1_1[3];
    tmp_1[53] = 212;
    tmp_0[212] = KIMMCar_B.INPUT_54_1_1[0];
    tmp_0[213] = KIMMCar_B.INPUT_54_1_1[1];
    tmp_0[214] = KIMMCar_B.INPUT_54_1_1[2];
    tmp_0[215] = KIMMCar_B.INPUT_54_1_1[3];
    tmp_1[54] = 216;
    simulationData->mData->mInputValues.mN = 216;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 55;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulationData->mData->mOutputs.mN = 29;
    simulationData->mData->mOutputs.mX = &KIMMCar_B.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_tmp = KIMMCar_M->Timing.t[0];
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)KIMMCar_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diag);
    scaleRate = ne_simulator_method((NeslSimulator *)
      KIMMCar_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (scaleRate != 0) {
      tmp_2 = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
      if (tmp_2) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(KIMMCar_M, msg_0);
      }
    }

    simulationData = (NeslSimulationData *)KIMMCar_DW.OUTPUT_1_0_SimData;
    time_1 = rtb_Gain7;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &KIMMCar_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &KIMMCar_DW.OUTPUT_1_0_Modes;
    tmp_2 = false;
    simulationData->mData->mFoundZcEvents = tmp_2;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = tmp_7;
    tmp_2 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_2;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = first_output;
    tmp_4[0] = 0;
    tmp_3[0] = KIMMCar_B.INPUT_3_1_1[0];
    tmp_3[1] = KIMMCar_B.INPUT_3_1_1[1];
    tmp_3[2] = KIMMCar_B.INPUT_3_1_1[2];
    tmp_3[3] = KIMMCar_B.INPUT_3_1_1[3];
    tmp_4[1] = 4;
    tmp_3[4] = KIMMCar_B.INPUT_4_1_1[0];
    tmp_3[5] = KIMMCar_B.INPUT_4_1_1[1];
    tmp_3[6] = KIMMCar_B.INPUT_4_1_1[2];
    tmp_3[7] = KIMMCar_B.INPUT_4_1_1[3];
    tmp_4[2] = 8;
    tmp_3[8] = KIMMCar_B.INPUT_5_1_1[0];
    tmp_3[9] = KIMMCar_B.INPUT_5_1_1[1];
    tmp_3[10] = KIMMCar_B.INPUT_5_1_1[2];
    tmp_3[11] = KIMMCar_B.INPUT_5_1_1[3];
    tmp_4[3] = 12;
    tmp_3[12] = KIMMCar_B.INPUT_6_1_1[0];
    tmp_3[13] = KIMMCar_B.INPUT_6_1_1[1];
    tmp_3[14] = KIMMCar_B.INPUT_6_1_1[2];
    tmp_3[15] = KIMMCar_B.INPUT_6_1_1[3];
    tmp_4[4] = 16;
    tmp_3[16] = KIMMCar_B.INPUT_7_1_1[0];
    tmp_3[17] = KIMMCar_B.INPUT_7_1_1[1];
    tmp_3[18] = KIMMCar_B.INPUT_7_1_1[2];
    tmp_3[19] = KIMMCar_B.INPUT_7_1_1[3];
    tmp_4[5] = 20;
    tmp_3[20] = KIMMCar_B.INPUT_8_1_1[0];
    tmp_3[21] = KIMMCar_B.INPUT_8_1_1[1];
    tmp_3[22] = KIMMCar_B.INPUT_8_1_1[2];
    tmp_3[23] = KIMMCar_B.INPUT_8_1_1[3];
    tmp_4[6] = 24;
    tmp_3[24] = KIMMCar_B.INPUT_9_1_1[0];
    tmp_3[25] = KIMMCar_B.INPUT_9_1_1[1];
    tmp_3[26] = KIMMCar_B.INPUT_9_1_1[2];
    tmp_3[27] = KIMMCar_B.INPUT_9_1_1[3];
    tmp_4[7] = 28;
    tmp_3[28] = KIMMCar_B.INPUT_14_1_1[0];
    tmp_3[29] = KIMMCar_B.INPUT_14_1_1[1];
    tmp_3[30] = KIMMCar_B.INPUT_14_1_1[2];
    tmp_3[31] = KIMMCar_B.INPUT_14_1_1[3];
    tmp_4[8] = 32;
    tmp_3[32] = KIMMCar_B.INPUT_10_1_1[0];
    tmp_3[33] = KIMMCar_B.INPUT_10_1_1[1];
    tmp_3[34] = KIMMCar_B.INPUT_10_1_1[2];
    tmp_3[35] = KIMMCar_B.INPUT_10_1_1[3];
    tmp_4[9] = 36;
    tmp_3[36] = KIMMCar_B.INPUT_11_1_1[0];
    tmp_3[37] = KIMMCar_B.INPUT_11_1_1[1];
    tmp_3[38] = KIMMCar_B.INPUT_11_1_1[2];
    tmp_3[39] = KIMMCar_B.INPUT_11_1_1[3];
    tmp_4[10] = 40;
    tmp_3[40] = KIMMCar_B.INPUT_12_1_1[0];
    tmp_3[41] = KIMMCar_B.INPUT_12_1_1[1];
    tmp_3[42] = KIMMCar_B.INPUT_12_1_1[2];
    tmp_3[43] = KIMMCar_B.INPUT_12_1_1[3];
    tmp_4[11] = 44;
    tmp_3[44] = KIMMCar_B.INPUT_13_1_1[0];
    tmp_3[45] = KIMMCar_B.INPUT_13_1_1[1];
    tmp_3[46] = KIMMCar_B.INPUT_13_1_1[2];
    tmp_3[47] = KIMMCar_B.INPUT_13_1_1[3];
    tmp_4[12] = 48;
    tmp_3[48] = KIMMCar_B.INPUT_15_1_1[0];
    tmp_3[49] = KIMMCar_B.INPUT_15_1_1[1];
    tmp_3[50] = KIMMCar_B.INPUT_15_1_1[2];
    tmp_3[51] = KIMMCar_B.INPUT_15_1_1[3];
    tmp_4[13] = 52;
    tmp_3[52] = KIMMCar_B.INPUT_16_1_1[0];
    tmp_3[53] = KIMMCar_B.INPUT_16_1_1[1];
    tmp_3[54] = KIMMCar_B.INPUT_16_1_1[2];
    tmp_3[55] = KIMMCar_B.INPUT_16_1_1[3];
    tmp_4[14] = 56;
    tmp_3[56] = KIMMCar_B.INPUT_17_1_1[0];
    tmp_3[57] = KIMMCar_B.INPUT_17_1_1[1];
    tmp_3[58] = KIMMCar_B.INPUT_17_1_1[2];
    tmp_3[59] = KIMMCar_B.INPUT_17_1_1[3];
    tmp_4[15] = 60;
    tmp_3[60] = KIMMCar_B.INPUT_21_1_1[0];
    tmp_3[61] = KIMMCar_B.INPUT_21_1_1[1];
    tmp_3[62] = KIMMCar_B.INPUT_21_1_1[2];
    tmp_3[63] = KIMMCar_B.INPUT_21_1_1[3];
    tmp_4[16] = 64;
    tmp_3[64] = KIMMCar_B.INPUT_18_1_1[0];
    tmp_3[65] = KIMMCar_B.INPUT_18_1_1[1];
    tmp_3[66] = KIMMCar_B.INPUT_18_1_1[2];
    tmp_3[67] = KIMMCar_B.INPUT_18_1_1[3];
    tmp_4[17] = 68;
    tmp_3[68] = KIMMCar_B.INPUT_19_1_1[0];
    tmp_3[69] = KIMMCar_B.INPUT_19_1_1[1];
    tmp_3[70] = KIMMCar_B.INPUT_19_1_1[2];
    tmp_3[71] = KIMMCar_B.INPUT_19_1_1[3];
    tmp_4[18] = 72;
    tmp_3[72] = KIMMCar_B.INPUT_20_1_1[0];
    tmp_3[73] = KIMMCar_B.INPUT_20_1_1[1];
    tmp_3[74] = KIMMCar_B.INPUT_20_1_1[2];
    tmp_3[75] = KIMMCar_B.INPUT_20_1_1[3];
    tmp_4[19] = 76;
    tmp_3[76] = KIMMCar_B.INPUT_22_1_1[0];
    tmp_3[77] = KIMMCar_B.INPUT_22_1_1[1];
    tmp_3[78] = KIMMCar_B.INPUT_22_1_1[2];
    tmp_3[79] = KIMMCar_B.INPUT_22_1_1[3];
    tmp_4[20] = 80;
    tmp_3[80] = KIMMCar_B.INPUT_23_1_1[0];
    tmp_3[81] = KIMMCar_B.INPUT_23_1_1[1];
    tmp_3[82] = KIMMCar_B.INPUT_23_1_1[2];
    tmp_3[83] = KIMMCar_B.INPUT_23_1_1[3];
    tmp_4[21] = 84;
    tmp_3[84] = KIMMCar_B.INPUT_24_1_1[0];
    tmp_3[85] = KIMMCar_B.INPUT_24_1_1[1];
    tmp_3[86] = KIMMCar_B.INPUT_24_1_1[2];
    tmp_3[87] = KIMMCar_B.INPUT_24_1_1[3];
    tmp_4[22] = 88;
    tmp_3[88] = KIMMCar_B.INPUT_25_1_1[0];
    tmp_3[89] = KIMMCar_B.INPUT_25_1_1[1];
    tmp_3[90] = KIMMCar_B.INPUT_25_1_1[2];
    tmp_3[91] = KIMMCar_B.INPUT_25_1_1[3];
    tmp_4[23] = 92;
    tmp_3[92] = KIMMCar_B.INPUT_28_1_1[0];
    tmp_3[93] = KIMMCar_B.INPUT_28_1_1[1];
    tmp_3[94] = KIMMCar_B.INPUT_28_1_1[2];
    tmp_3[95] = KIMMCar_B.INPUT_28_1_1[3];
    tmp_4[24] = 96;
    tmp_3[96] = KIMMCar_B.INPUT_26_1_1[0];
    tmp_3[97] = KIMMCar_B.INPUT_26_1_1[1];
    tmp_3[98] = KIMMCar_B.INPUT_26_1_1[2];
    tmp_3[99] = KIMMCar_B.INPUT_26_1_1[3];
    tmp_4[25] = 100;
    tmp_3[100] = KIMMCar_B.INPUT_27_1_1[0];
    tmp_3[101] = KIMMCar_B.INPUT_27_1_1[1];
    tmp_3[102] = KIMMCar_B.INPUT_27_1_1[2];
    tmp_3[103] = KIMMCar_B.INPUT_27_1_1[3];
    tmp_4[26] = 104;
    tmp_3[104] = KIMMCar_B.INPUT_31_1_1[0];
    tmp_3[105] = KIMMCar_B.INPUT_31_1_1[1];
    tmp_3[106] = KIMMCar_B.INPUT_31_1_1[2];
    tmp_3[107] = KIMMCar_B.INPUT_31_1_1[3];
    tmp_4[27] = 108;
    tmp_3[108] = KIMMCar_B.INPUT_32_1_1[0];
    tmp_3[109] = KIMMCar_B.INPUT_32_1_1[1];
    tmp_3[110] = KIMMCar_B.INPUT_32_1_1[2];
    tmp_3[111] = KIMMCar_B.INPUT_32_1_1[3];
    tmp_4[28] = 112;
    tmp_3[112] = KIMMCar_B.INPUT_33_1_1[0];
    tmp_3[113] = KIMMCar_B.INPUT_33_1_1[1];
    tmp_3[114] = KIMMCar_B.INPUT_33_1_1[2];
    tmp_3[115] = KIMMCar_B.INPUT_33_1_1[3];
    tmp_4[29] = 116;
    tmp_3[116] = KIMMCar_B.INPUT_36_1_1[0];
    tmp_3[117] = KIMMCar_B.INPUT_36_1_1[1];
    tmp_3[118] = KIMMCar_B.INPUT_36_1_1[2];
    tmp_3[119] = KIMMCar_B.INPUT_36_1_1[3];
    tmp_4[30] = 120;
    tmp_3[120] = KIMMCar_B.INPUT_34_1_1[0];
    tmp_3[121] = KIMMCar_B.INPUT_34_1_1[1];
    tmp_3[122] = KIMMCar_B.INPUT_34_1_1[2];
    tmp_3[123] = KIMMCar_B.INPUT_34_1_1[3];
    tmp_4[31] = 124;
    tmp_3[124] = KIMMCar_B.INPUT_35_1_1[0];
    tmp_3[125] = KIMMCar_B.INPUT_35_1_1[1];
    tmp_3[126] = KIMMCar_B.INPUT_35_1_1[2];
    tmp_3[127] = KIMMCar_B.INPUT_35_1_1[3];
    tmp_4[32] = 128;
    tmp_3[128] = KIMMCar_B.INPUT_39_1_1[0];
    tmp_3[129] = KIMMCar_B.INPUT_39_1_1[1];
    tmp_3[130] = KIMMCar_B.INPUT_39_1_1[2];
    tmp_3[131] = KIMMCar_B.INPUT_39_1_1[3];
    tmp_4[33] = 132;
    tmp_3[132] = KIMMCar_B.INPUT_40_1_1[0];
    tmp_3[133] = KIMMCar_B.INPUT_40_1_1[1];
    tmp_3[134] = KIMMCar_B.INPUT_40_1_1[2];
    tmp_3[135] = KIMMCar_B.INPUT_40_1_1[3];
    tmp_4[34] = 136;
    tmp_3[136] = KIMMCar_B.INPUT_41_1_1[0];
    tmp_3[137] = KIMMCar_B.INPUT_41_1_1[1];
    tmp_3[138] = KIMMCar_B.INPUT_41_1_1[2];
    tmp_3[139] = KIMMCar_B.INPUT_41_1_1[3];
    tmp_4[35] = 140;
    tmp_3[140] = KIMMCar_B.INPUT_44_1_1[0];
    tmp_3[141] = KIMMCar_B.INPUT_44_1_1[1];
    tmp_3[142] = KIMMCar_B.INPUT_44_1_1[2];
    tmp_3[143] = KIMMCar_B.INPUT_44_1_1[3];
    tmp_4[36] = 144;
    tmp_3[144] = KIMMCar_B.INPUT_42_1_1[0];
    tmp_3[145] = KIMMCar_B.INPUT_42_1_1[1];
    tmp_3[146] = KIMMCar_B.INPUT_42_1_1[2];
    tmp_3[147] = KIMMCar_B.INPUT_42_1_1[3];
    tmp_4[37] = 148;
    tmp_3[148] = KIMMCar_B.INPUT_43_1_1[0];
    tmp_3[149] = KIMMCar_B.INPUT_43_1_1[1];
    tmp_3[150] = KIMMCar_B.INPUT_43_1_1[2];
    tmp_3[151] = KIMMCar_B.INPUT_43_1_1[3];
    tmp_4[38] = 152;
    tmp_3[152] = KIMMCar_B.INPUT_47_1_1[0];
    tmp_3[153] = KIMMCar_B.INPUT_47_1_1[1];
    tmp_3[154] = KIMMCar_B.INPUT_47_1_1[2];
    tmp_3[155] = KIMMCar_B.INPUT_47_1_1[3];
    tmp_4[39] = 156;
    tmp_3[156] = KIMMCar_B.INPUT_48_1_1[0];
    tmp_3[157] = KIMMCar_B.INPUT_48_1_1[1];
    tmp_3[158] = KIMMCar_B.INPUT_48_1_1[2];
    tmp_3[159] = KIMMCar_B.INPUT_48_1_1[3];
    tmp_4[40] = 160;
    tmp_3[160] = KIMMCar_B.INPUT_49_1_1[0];
    tmp_3[161] = KIMMCar_B.INPUT_49_1_1[1];
    tmp_3[162] = KIMMCar_B.INPUT_49_1_1[2];
    tmp_3[163] = KIMMCar_B.INPUT_49_1_1[3];
    tmp_4[41] = 164;
    tmp_3[164] = KIMMCar_B.INPUT_52_1_1[0];
    tmp_3[165] = KIMMCar_B.INPUT_52_1_1[1];
    tmp_3[166] = KIMMCar_B.INPUT_52_1_1[2];
    tmp_3[167] = KIMMCar_B.INPUT_52_1_1[3];
    tmp_4[42] = 168;
    tmp_3[168] = KIMMCar_B.INPUT_50_1_1[0];
    tmp_3[169] = KIMMCar_B.INPUT_50_1_1[1];
    tmp_3[170] = KIMMCar_B.INPUT_50_1_1[2];
    tmp_3[171] = KIMMCar_B.INPUT_50_1_1[3];
    tmp_4[43] = 172;
    tmp_3[172] = KIMMCar_B.INPUT_51_1_1[0];
    tmp_3[173] = KIMMCar_B.INPUT_51_1_1[1];
    tmp_3[174] = KIMMCar_B.INPUT_51_1_1[2];
    tmp_3[175] = KIMMCar_B.INPUT_51_1_1[3];
    tmp_4[44] = 176;
    tmp_3[176] = KIMMCar_B.INPUT_1_1_1[0];
    tmp_3[177] = KIMMCar_B.INPUT_1_1_1[1];
    tmp_3[178] = KIMMCar_B.INPUT_1_1_1[2];
    tmp_3[179] = KIMMCar_B.INPUT_1_1_1[3];
    tmp_4[45] = 180;
    tmp_3[180] = KIMMCar_B.INPUT_2_1_1[0];
    tmp_3[181] = KIMMCar_B.INPUT_2_1_1[1];
    tmp_3[182] = KIMMCar_B.INPUT_2_1_1[2];
    tmp_3[183] = KIMMCar_B.INPUT_2_1_1[3];
    tmp_4[46] = 184;
    tmp_3[184] = KIMMCar_B.INPUT_29_1_1[0];
    tmp_3[185] = KIMMCar_B.INPUT_29_1_1[1];
    tmp_3[186] = KIMMCar_B.INPUT_29_1_1[2];
    tmp_3[187] = KIMMCar_B.INPUT_29_1_1[3];
    tmp_4[47] = 188;
    tmp_3[188] = KIMMCar_B.INPUT_30_1_1[0];
    tmp_3[189] = KIMMCar_B.INPUT_30_1_1[1];
    tmp_3[190] = KIMMCar_B.INPUT_30_1_1[2];
    tmp_3[191] = KIMMCar_B.INPUT_30_1_1[3];
    tmp_4[48] = 192;
    tmp_3[192] = KIMMCar_B.INPUT_37_1_1[0];
    tmp_3[193] = KIMMCar_B.INPUT_37_1_1[1];
    tmp_3[194] = KIMMCar_B.INPUT_37_1_1[2];
    tmp_3[195] = KIMMCar_B.INPUT_37_1_1[3];
    tmp_4[49] = 196;
    tmp_3[196] = KIMMCar_B.INPUT_38_1_1[0];
    tmp_3[197] = KIMMCar_B.INPUT_38_1_1[1];
    tmp_3[198] = KIMMCar_B.INPUT_38_1_1[2];
    tmp_3[199] = KIMMCar_B.INPUT_38_1_1[3];
    tmp_4[50] = 200;
    tmp_3[200] = KIMMCar_B.INPUT_45_1_1[0];
    tmp_3[201] = KIMMCar_B.INPUT_45_1_1[1];
    tmp_3[202] = KIMMCar_B.INPUT_45_1_1[2];
    tmp_3[203] = KIMMCar_B.INPUT_45_1_1[3];
    tmp_4[51] = 204;
    tmp_3[204] = KIMMCar_B.INPUT_46_1_1[0];
    tmp_3[205] = KIMMCar_B.INPUT_46_1_1[1];
    tmp_3[206] = KIMMCar_B.INPUT_46_1_1[2];
    tmp_3[207] = KIMMCar_B.INPUT_46_1_1[3];
    tmp_4[52] = 208;
    tmp_3[208] = KIMMCar_B.INPUT_53_1_1[0];
    tmp_3[209] = KIMMCar_B.INPUT_53_1_1[1];
    tmp_3[210] = KIMMCar_B.INPUT_53_1_1[2];
    tmp_3[211] = KIMMCar_B.INPUT_53_1_1[3];
    tmp_4[53] = 212;
    tmp_3[212] = KIMMCar_B.INPUT_54_1_1[0];
    tmp_3[213] = KIMMCar_B.INPUT_54_1_1[1];
    tmp_3[214] = KIMMCar_B.INPUT_54_1_1[2];
    tmp_3[215] = KIMMCar_B.INPUT_54_1_1[3];
    tmp_4[54] = 216;
    memcpy(&tmp_3[216], &KIMMCar_B.STATE_1[0], 29U * sizeof(real_T));
    tmp_4[55] = 245;
    simulationData->mData->mInputValues.mN = 245;
    simulationData->mData->mInputValues.mX = &tmp_3[0];
    simulationData->mData->mInputOffsets.mN = 56;
    simulationData->mData->mInputOffsets.mX = &tmp_4[0];
    simulationData->mData->mOutputs.mN = 112;
    simulationData->mData->mOutputs.mX = &KIMMCar_B.OUTPUT_1_0[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_2 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)KIMMCar_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
    scaleRate = ne_simulator_method((NeslSimulator *)
      KIMMCar_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (scaleRate != 0) {
      tmp_2 = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
      if (tmp_2) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(KIMMCar_M, msg_1);
      }
    }

    KIMMCar_Y.body_x = KIMMCar_P.Gain_Gain_j * KIMMCar_B.OUTPUT_1_0[98];
    KIMMCar_Y.body_y = KIMMCar_B.OUTPUT_1_0[99];
    KIMMCar_Y.body_z = KIMMCar_B.OUTPUT_1_0[97];
    tmp_9 = _mm_mul_pd(_mm_loadu_pd(&KIMMCar_B.OUTPUT_1_0[93]), _mm_loadu_pd
                       (&KIMMCar_B.OUTPUT_1_0[93]));
    _mm_storeu_pd(&q[0], tmp_9);
    tmp_9 = _mm_mul_pd(_mm_loadu_pd(&KIMMCar_B.OUTPUT_1_0[95]), _mm_loadu_pd
                       (&KIMMCar_B.OUTPUT_1_0[95]));
    _mm_storeu_pd(&q[2], tmp_9);
    rtb_Switch = 1.0 / sqrt(((q[0] + q[1]) + q[2]) + q[3]);
    tmp_9 = _mm_set1_pd(rtb_Switch);
    tmp_a = _mm_mul_pd(_mm_loadu_pd(&KIMMCar_B.OUTPUT_1_0[93]), tmp_9);
    _mm_storeu_pd(&q[0], tmp_a);
    tmp_9 = _mm_mul_pd(_mm_loadu_pd(&KIMMCar_B.OUTPUT_1_0[95]), tmp_9);
    _mm_storeu_pd(&q[2], tmp_9);
    rtb_Switch = q[3] * q[3];
    rtb_Product2 = q[2] * q[2];
    tempR[0] = 1.0 - (rtb_Product2 + rtb_Switch) * 2.0;
    tmp_9 = _mm_set1_pd(q[0]);
    tmp_a = _mm_set1_pd(2.0);
    tmp_c = _mm_set_pd(1.0, -1.0);
    tmp_b = _mm_mul_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(q[1]), _mm_loadu_pd(&q
      [2])), _mm_mul_pd(_mm_mul_pd(tmp_9, _mm_set_pd(q[2], q[3])), tmp_c)),
                       tmp_a);
    _mm_storeu_pd(&tempR[1], tmp_b);
    tempR[3] = (q[1] * q[2] + q[0] * q[3]) * 2.0;
    K14 = q[1] * q[1];
    tempR[4] = 1.0 - (K14 + rtb_Switch) * 2.0;
    tmp_9 = _mm_mul_pd(_mm_sub_pd(_mm_mul_pd(_mm_set_pd(q[1], q[2]), _mm_set1_pd
      (q[3])), _mm_mul_pd(tmp_9, _mm_loadu_pd(&q[1]))), tmp_a);
    _mm_storeu_pd(&tempR[5], tmp_9);
    tempR[7] = (q[2] * q[3] + q[0] * q[1]) * 2.0;
    tempR[8] = 1.0 - (K14 + rtb_Product2) * 2.0;
    for (scaleRate = 0; scaleRate < 3; scaleRate++) {
      R_sim[scaleRate] = tempR[scaleRate * 3];
      R_sim[scaleRate + 3] = tempR[scaleRate * 3 + 1];
      R_sim[scaleRate + 6] = tempR[scaleRate * 3 + 2];
    }

    for (scaleRate = 0; scaleRate < 3; scaleRate++) {
      a_0 = a_3[scaleRate + 3];
      a_1 = a_3[scaleRate];
      a_2 = a_3[scaleRate + 6];
      for (scaleRate_0 = 0; scaleRate_0 < 3; scaleRate_0++) {
        a[scaleRate + 3 * scaleRate_0] = (R_sim[3 * scaleRate_0 + 1] * (real_T)
          a_0 + R_sim[3 * scaleRate_0] * (real_T)a_1) + R_sim[3 * scaleRate_0 +
          2] * (real_T)a_2;
      }

      rtb_Switch = a[scaleRate + 3];
      rtb_Product2 = a[scaleRate];
      K14 = a[scaleRate + 6];
      for (scaleRate_0 = 0; scaleRate_0 < 3; scaleRate_0++) {
        tempR[scaleRate + 3 * scaleRate_0] = ((real_T)c[3 * scaleRate_0 + 1] *
          rtb_Switch + (real_T)c[3 * scaleRate_0] * rtb_Product2) + (real_T)c[3 *
          scaleRate_0 + 2] * K14;
      }
    }

    tmp_9 = _mm_add_pd(_mm_loadu_pd(&tempR[1]), _mm_set_pd(tempR[6], tempR[3]));
    _mm_storeu_pd(&tmp_8[0], tmp_9);
    rtb_Switch = tmp_8[0];
    rtb_Product2 = tmp_8[1];
    _mm_storeu_pd(&tmp_8[0], _mm_add_pd(_mm_set1_pd(tempR[5]), _mm_mul_pd
      (_mm_set1_pd(tempR[7]), tmp_c)));
    K14 = tmp_8[0];
    K23 = tmp_8[1];
    tmp_9 = _mm_sub_pd(_mm_set_pd(tempR[1], tempR[6]), _mm_loadu_pd(&tempR[2]));
    _mm_storeu_pd(&tmp_8[0], tmp_9);
    catArgs[0] = ((tempR[0] - tempR[4]) - tempR[8]) / 3.0;
    catArgs[4] = rtb_Switch / 3.0;
    catArgs[8] = rtb_Product2 / 3.0;
    catArgs[12] = K14 / 3.0;
    catArgs[1] = rtb_Switch / 3.0;
    catArgs[5] = ((tempR[4] - tempR[0]) - tempR[8]) / 3.0;
    catArgs[9] = K23 / 3.0;
    catArgs[13] = tmp_8[0] / 3.0;
    catArgs[2] = rtb_Product2 / 3.0;
    catArgs[6] = K23 / 3.0;
    catArgs[10] = ((tempR[8] - tempR[0]) - tempR[4]) / 3.0;
    catArgs[14] = tmp_8[1] / 3.0;
    catArgs[3] = K14 / 3.0;
    catArgs[7] = tmp_8[0] / 3.0;
    catArgs[11] = tmp_8[1] / 3.0;
    catArgs[15] = ((tempR[0] + tempR[4]) + tempR[8]) / 3.0;
    KIMMCar_eig(catArgs, eigVec, eigVal);
    q[0] = eigVal[0].re;
    q[1] = eigVal[1].re;
    q[2] = eigVal[2].re;
    q[3] = eigVal[3].re;
    if (!rtIsNaN(eigVal[0].re)) {
      scaleRate_0 = 0;
    } else {
      scaleRate_0 = -1;
      scaleRate = 2;
      exitg1 = false;
      while ((!exitg1) && (scaleRate < 5)) {
        if (!rtIsNaN(q[scaleRate - 1])) {
          scaleRate_0 = scaleRate - 1;
          exitg1 = true;
        } else {
          scaleRate++;
        }
      }
    }

    if (scaleRate_0 + 1 == 0) {
      iindx = 0;
    } else {
      K23 = q[scaleRate_0];
      iindx = scaleRate_0;
      for (scaleRate = scaleRate_0 + 2; scaleRate < 5; scaleRate++) {
        rtb_Switch = q[scaleRate - 1];
        if (K23 < rtb_Switch) {
          K23 = rtb_Switch;
          iindx = scaleRate - 1;
        }
      }
    }

    scaleRate = iindx << 2;
    q[0] = eigVec[scaleRate + 3].re;
    q[1] = eigVec[scaleRate].re;
    q[2] = eigVec[scaleRate + 1].re;
    q[3] = eigVec[scaleRate + 2].re;
    if (q[0] < 0.0) {
      q[0] = -q[0];
      q[1] = -q[1];
      q[2] = -q[2];
      q[3] = -q[3];
    }

    KIMMCar_Y.body_q[0] = q[1];
    KIMMCar_Y.body_q[1] = q[2];
    KIMMCar_Y.body_q[2] = q[3];
    KIMMCar_Y.body_q[3] = q[0];
    KIMMCar_Y.body_vx = KIMMCar_B.OUTPUT_1_0[90];
    KIMMCar_Y.body_vy = KIMMCar_B.OUTPUT_1_0[91];
    KIMMCar_Y.FLWheelOutput = KIMMCar_B.OUTPUT_1_0[0];
    KIMMCar_Y.FRWheelOutput = KIMMCar_B.OUTPUT_1_0[2];
    KIMMCar_Y.RLWheelOutput = KIMMCar_B.OUTPUT_1_0[4];
    KIMMCar_Y.RRWheelOutput = KIMMCar_B.OUTPUT_1_0[6];
    KIMMCar_Y.FL_x = KIMMCar_P.Gain_Gain_fv * KIMMCar_B.OUTPUT_1_0[101];
    KIMMCar_Y.FL_y = KIMMCar_B.OUTPUT_1_0[102];
    KIMMCar_Y.FL_z = KIMMCar_B.OUTPUT_1_0[100];
    KIMMCar_Y.FR_x = KIMMCar_P.Gain_Gain_m * KIMMCar_B.OUTPUT_1_0[104];
    KIMMCar_Y.FR_y = KIMMCar_B.OUTPUT_1_0[105];
    KIMMCar_Y.FR_z = KIMMCar_B.OUTPUT_1_0[103];
    KIMMCar_Y.RL_x = KIMMCar_P.Gain_Gain_k * KIMMCar_B.OUTPUT_1_0[107];
    KIMMCar_Y.RL_y = KIMMCar_B.OUTPUT_1_0[108];
    KIMMCar_Y.RL_z = KIMMCar_B.OUTPUT_1_0[106];
    KIMMCar_Y.RR_x = KIMMCar_P.Gain_Gain_g * KIMMCar_B.OUTPUT_1_0[110];
    KIMMCar_Y.RR_y = KIMMCar_B.OUTPUT_1_0[111];
    KIMMCar_Y.RR_z = KIMMCar_B.OUTPUT_1_0[109];
    if (zeroGuard) {
      KIMMCar_Y.ToeLeft = KIMMCar_P.unitydir_Gain * KIMMCar_B.Sum;
      KIMMCar_Y.ToeRight = KIMMCar_P.unitydir1_Gain * KIMMCar_B.Sum1;
      rtb_Product2 = KIMMCar_DW.UnitDelay_DSTATE_f;
      K14 = KIMMCar_U.Brake - KIMMCar_DW.PrevY;
      if (K14 > KIMMCar_P.Brake_Rate_Limiter_RisingLim * KIMMCar_period) {
        rtb_Switch = KIMMCar_P.Brake_Rate_Limiter_RisingLim * KIMMCar_period +
          KIMMCar_DW.PrevY;
      } else if (K14 < KIMMCar_P.Brake_Rate_Limiter_FallingLim * KIMMCar_period)
      {
        rtb_Switch = KIMMCar_P.Brake_Rate_Limiter_FallingLim * KIMMCar_period +
          KIMMCar_DW.PrevY;
      } else {
        rtb_Switch = KIMMCar_U.Brake;
      }

      KIMMCar_DW.PrevY = rtb_Switch;
      q[0] = KIMMCar_DW.UnitDelay1_1_DSTATE;
      q[1] = KIMMCar_DW.UnitDelay1_2_DSTATE;
      q[2] = KIMMCar_DW.UnitDelay1_3_DSTATE;
      q[3] = KIMMCar_DW.UnitDelay1_4_DSTATE;
      if (!(rtb_Switch >= 0.0)) {
        rtb_Switch = 0.0;
      }

      if (rtb_Switch <= 1.0) {
        K14 = rtb_Switch;
      } else {
        K14 = 1.0;
      }

      rtb_Switch = fabs(rtb_Product2);
      if (rtb_Product2 > 0.3) {
        KIMMCar_DW.travelDirection = 1.0;
      } else if (rtb_Product2 < -0.3) {
        KIMMCar_DW.travelDirection = -1.0;
      } else if (rtb_Switch < 0.1) {
        wheelAlong[0] = fabs(q[0]);
        wheelAlong[1] = fabs(q[1]);
        wheelAlong[2] = fabs(q[2]);
        wheelAlong[3] = fabs(q[3]);
        if (!rtIsNaN(wheelAlong[0])) {
          scaleRate_0 = 1;
        } else {
          scaleRate_0 = 0;
          scaleRate = 2;
          exitg1 = false;
          while ((!exitg1) && (scaleRate < 5)) {
            if (!rtIsNaN(wheelAlong[scaleRate - 1])) {
              scaleRate_0 = scaleRate;
              exitg1 = true;
            } else {
              scaleRate++;
            }
          }
        }

        if (scaleRate_0 == 0) {
          K23 = wheelAlong[0];
        } else {
          K23 = wheelAlong[scaleRate_0 - 1];
          for (scaleRate = scaleRate_0 + 1; scaleRate < 5; scaleRate++) {
            K24 = wheelAlong[scaleRate - 1];
            if (K23 < K24) {
              K23 = K24;
            }
          }
        }

        if (K23 < 0.5) {
          KIMMCar_DW.travelDirection = 0.0;
        }
      }

      if (KIMMCar_DW.travelDirection == 0.0) {
        K23 = (((q[0] + q[1]) + q[2]) + q[3]) * 0.25;
        if (K23 > 0.5) {
          KIMMCar_DW.travelDirection = 1.0;
        } else if (K23 < -0.5) {
          KIMMCar_DW.travelDirection = -1.0;
        } else if (KIMMCar_U.Gear >= 0.5) {
          KIMMCar_DW.travelDirection = 1.0;
        } else if (KIMMCar_U.Gear <= -0.5) {
          KIMMCar_DW.travelDirection = -1.0;
        }
      }

      wheelAlong[0] = KIMMCar_DW.travelDirection * q[0];
      if (KIMMCar_DW.travelDirection != 0.0) {
        K23 = -KIMMCar_DW.travelDirection * KIMMCar_DW.UnitDelay_DSTATE_i[0];
        if ((K23 <= 0.0) || rtIsNaN(K23)) {
          slip[0] = 0.0;
        } else {
          slip[0] = K23;
        }
      } else {
        slip[0] = 0.0;
      }

      wheelAlong[1] = KIMMCar_DW.travelDirection * q[1];
      if (KIMMCar_DW.travelDirection != 0.0) {
        K23 = -KIMMCar_DW.travelDirection * KIMMCar_DW.UnitDelay_DSTATE_i[1];
        if ((K23 <= 0.0) || rtIsNaN(K23)) {
          slip[1] = 0.0;
        } else {
          slip[1] = K23;
        }
      } else {
        slip[1] = 0.0;
      }

      wheelAlong[2] = KIMMCar_DW.travelDirection * q[2];
      if (KIMMCar_DW.travelDirection != 0.0) {
        K23 = -KIMMCar_DW.travelDirection * KIMMCar_DW.UnitDelay_DSTATE_i[2];
        if ((K23 <= 0.0) || rtIsNaN(K23)) {
          slip[2] = 0.0;
        } else {
          slip[2] = K23;
        }
      } else {
        slip[2] = 0.0;
      }

      wheelAlong[3] = KIMMCar_DW.travelDirection * q[3];
      if (KIMMCar_DW.travelDirection != 0.0) {
        K23 = -KIMMCar_DW.travelDirection * KIMMCar_DW.UnitDelay_DSTATE_i[3];
        if ((K23 <= 0.0) || rtIsNaN(K23)) {
          slip[3] = 0.0;
        } else {
          slip[3] = K23;
        }
      } else {
        slip[3] = 0.0;
      }

      K23 = 0.25 * rtb_Switch / 0.35;
      if ((K23 >= 2.0) || rtIsNaN(K23)) {
        K23 = 2.0;
      }

      K24 = 0.5 * rtb_Switch / 0.35;
      if ((K24 >= 4.0) || rtIsNaN(K24)) {
        K24 = 4.0;
      }

      if (K23 + 0.5 >= K24) {
        K24 = K23 + 0.5;
      }

      for (scaleRate = 0; scaleRate < 4; scaleRate++) {
        if ((K14 > 0.02) && (rtb_Switch > 0.3) && (KIMMCar_DW.travelDirection !=
             0.0)) {
          zeroGuard = KIMMCar_DW.zeroGuard[scaleRate];
          if ((!zeroGuard) && (wheelAlong[scaleRate] <= K23)) {
            zeroGuard = true;
            KIMMCar_DW.zeroGuard[scaleRate] = true;
          } else if (zeroGuard && (wheelAlong[scaleRate] >= K24)) {
            zeroGuard = false;
            KIMMCar_DW.zeroGuard[scaleRate] = false;
          }
        } else {
          zeroGuard = false;
          KIMMCar_DW.zeroGuard[scaleRate] = false;
        }

        if (K14 <= 0.02) {
          u0_0 = 1.0;
          KIMMCar_DW.absScale[scaleRate] = 1.0;
        } else {
          if (zeroGuard) {
            scaleRate_0 = -200;
          } else if ((rtb_Switch >= 2.0) && (slip[scaleRate] >= 0.28)) {
            scaleRate_0 = -50;
          } else if ((rtb_Switch >= 2.0) && (slip[scaleRate] > 0.14)) {
            scaleRate_0 = -20;
          } else if ((rtb_Switch < 2.0) || (slip[scaleRate] < 0.06)) {
            scaleRate_0 = 10;
          } else {
            scaleRate_0 = 0;
          }

          u0_0 = (real_T)scaleRate_0 * 0.0005 + KIMMCar_DW.absScale[scaleRate];
          if (!(u0_0 >= 0.0)) {
            u0_0 = 0.0;
          }

          if (!(u0_0 <= 1.0)) {
            u0_0 = 1.0;
          }

          KIMMCar_DW.absScale[scaleRate] = u0_0;
        }

        u0 = q[scaleRate] / 0.5;
        if (!(u0 >= -1.0)) {
          u0 = -1.0;
        }

        if (!(u0 <= 1.0)) {
          u0 = 1.0;
        }

        rtb_UnitDelay_c[scaleRate] = K14 * u0_0 * u0;
      }

      KIMMCar_DW.filteredVelocity += (rtb_Product2 - KIMMCar_DW.filteredVelocity)
        * 0.024390243902439025;
      rtb_Product2 = fabs(KIMMCar_DW.filteredVelocity);
      if (!(fabs(KIMMCar_U.Gear) < 0.5)) {
        KIMMCar_DW.integratorState = 0.0;
        KIMMCar_DW.signGuardActive = false;
        rtb_Product2 = 0.0;
      } else if (rtb_Product2 >= 0.5) {
        KIMMCar_DW.integratorState = 0.0;
        KIMMCar_DW.signGuardActive = false;
        rtb_Product2 = 0.0;
      } else {
        K14 = 1.5 * KIMMCar_DW.filteredVelocity + KIMMCar_DW.integratorState;
        KIMMCar_DW.signGuardActive = (((rtb_Product2 > 0.04) && (K14 *
          KIMMCar_DW.filteredVelocity < 0.0)) || ((!(rtb_Product2 < 0.02)) &&
          KIMMCar_DW.signGuardActive));
        if (KIMMCar_DW.signGuardActive) {
          KIMMCar_DW.integratorState = 0.0;
          K14 = 1.5 * KIMMCar_DW.filteredVelocity;
        }

        if ((rtb_Product2 < 0.35) && ((fabs(K14) < 1.0) || (K14 *
              KIMMCar_DW.filteredVelocity < 0.0))) {
          KIMMCar_DW.integratorState += 0.004 * KIMMCar_DW.filteredVelocity;
          if (KIMMCar_DW.integratorState >= -0.8) {
            K14 = KIMMCar_DW.integratorState;
          } else {
            K14 = -0.8;
          }

          if (K14 <= 0.8) {
            KIMMCar_DW.integratorState = K14;
          } else {
            KIMMCar_DW.integratorState = 0.8;
          }
        }

        u0_0 = (0.5 - rtb_Product2) / 0.2;
        if (!(u0_0 >= 0.0)) {
          u0_0 = 0.0;
        }

        u0 = 1.5 * KIMMCar_DW.filteredVelocity + KIMMCar_DW.integratorState;
        if (!(u0 >= -1.0)) {
          u0 = -1.0;
        }

        if (!(u0_0 <= 1.0)) {
          u0_0 = 1.0;
        }

        if (!(u0 <= 1.0)) {
          u0 = 1.0;
        }

        rtb_Product2 = u0_0 * u0;
      }

      tmp_9 = _mm_set1_pd(rtb_Product2);
      tmp_a = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&KIMMCar_P.Parking_Demand_Vector_Gain[0]), tmp_9), _mm_loadu_pd
                         (&rtb_UnitDelay_c[0]));
      _mm_storeu_pd(&tmp_8[0], tmp_a);
      u0_0 = tmp_8[0];
      u0 = tmp_8[1];
      tmp_9 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&KIMMCar_P.Parking_Demand_Vector_Gain[2]), tmp_9), _mm_loadu_pd
                         (&rtb_UnitDelay_c[2]));
      _mm_storeu_pd(&tmp_8[0], tmp_9);
      rtb_Product2 = KIMMCar_P.Gain_Gain_d * KIMMCar_U.Throttle;
      K14 = rtb_Product2 - KIMMCar_DW.PrevY_o;
      if (K14 > KIMMCar_P.RateLimiter_RisingLim * KIMMCar_period) {
        rtb_Product2 = KIMMCar_P.RateLimiter_RisingLim * KIMMCar_period +
          KIMMCar_DW.PrevY_o;
      } else if (K14 < KIMMCar_P.RateLimiter_FallingLim * KIMMCar_period) {
        rtb_Product2 = KIMMCar_P.RateLimiter_FallingLim * KIMMCar_period +
          KIMMCar_DW.PrevY_o;
      }

      KIMMCar_DW.PrevY_o = rtb_Product2;
      if (KIMMCar_U.Gear >= KIMMCar_P.Switch_Threshold) {
        rtb_Switch = look1_binlxpw(rtb_Switch,
          KIMMCar_P.LookupwithLinearPointslopeInterpolation_bp01Data,
          KIMMCar_P.LookupwithLinearPointslopeInterpolation_tableData, 3U);
      } else {
        rtb_Switch = look1_binlxpw(rtb_Switch,
          KIMMCar_P.LookupwithLinearPointslopeInterpolation1_bp01Data,
          KIMMCar_P.LookupwithLinearPointslopeInterpolation1_tableData, 3U);
      }

      rtb_Product2 *= rtb_Switch;
      if (u0_0 > KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat) {
        u0_0 = KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat;
      } else if (u0_0 < KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat) {
        u0_0 = KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat;
      }

      KIMMCar_B.Add_g = KIMMCar_P.Gain1_Gain_d * rtb_Product2 * KIMMCar_U.Gear +
        KIMMCar_P.Gain5_Gain_b * u0_0;
      if (u0 > KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat) {
        u0 = KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat;
      } else if (u0 < KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat) {
        u0 = KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat;
      }

      KIMMCar_B.Add1_o = KIMMCar_P.Gain2_Gain_p * rtb_Product2 * KIMMCar_U.Gear
        + KIMMCar_P.Gain7_Gain_b * u0;
      if (tmp_8[0] > KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat) {
        rtb_Product2 = KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat;
      } else if (tmp_8[0] < KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat) {
        rtb_Product2 = KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat;
      } else {
        rtb_Product2 = tmp_8[0];
      }

      KIMMCar_B.Gain6_f = KIMMCar_P.Gain6_Gain_d * rtb_Product2;
      if (tmp_8[1] > KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat) {
        rtb_Product2 = KIMMCar_P.Brake_Demand_Vector_Limit_UpperSat;
      } else if (tmp_8[1] < KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat) {
        rtb_Product2 = KIMMCar_P.Brake_Demand_Vector_Limit_LowerSat;
      } else {
        rtb_Product2 = tmp_8[1];
      }

      KIMMCar_B.Gain8 = KIMMCar_P.Gain8_Gain * rtb_Product2;
    }

    memcpy(&R_sim[0], &KIMMCar_B.OUTPUT_1_0[35], 9U * sizeof(real_T));
    KIMMCar_B.Atan1 = rt_atan2d_snf(R_sim[1], R_sim[0]);
    memcpy(&R_sim[0], &KIMMCar_B.OUTPUT_1_0[46], 9U * sizeof(real_T));
    KIMMCar_B.Atan1_l = rt_atan2d_snf(R_sim[1], R_sim[0]);
    memcpy(&R_sim[0], &KIMMCar_B.OUTPUT_1_0[57], 9U * sizeof(real_T));
    KIMMCar_B.Atan1_i = rt_atan2d_snf(R_sim[1], R_sim[0]);
    memcpy(&R_sim[0], &KIMMCar_B.OUTPUT_1_0[68], 9U * sizeof(real_T));
    KIMMCar_B.Atan1_k = rt_atan2d_snf(R_sim[1], R_sim[0]);
    tmp_9 = _mm_sub_pd(_mm_loadu_pd(&KIMMCar_B.OUTPUT_1_0[77]), _mm_set_pd
                       (KIMMCar_P.Constant1_Value_m, KIMMCar_P.Constant_Value_n));
    _mm_storeu_pd(&tmp_8[0], tmp_9);
    KIMMCar_B.Sum_k = tmp_8[0];
    KIMMCar_B.Sum1_p = tmp_8[1];
    rtb_Switch = KIMMCar_B.OUTPUT_1_0[32] * KIMMCar_B.OUTPUT_1_0[32];
    KIMMCar_B.Gain_g = 0.5 * Veh_AeroRho * Veh_AeroCl * Veh_AeroArea *
      rtb_Switch;
    rtb_Product2 = KIMMCar_B.OUTPUT_1_0[32];
    if (rtIsNaN(rtb_Product2)) {
      rtb_Product2 = (rtNaN);
    } else if (rtb_Product2 < 0.0) {
      rtb_Product2 = -1.0;
    } else {
      rtb_Product2 = (rtb_Product2 > 0.0);
    }

    KIMMCar_B.Gain1 = -0.5 * Veh_AeroRho * Veh_AeroCd * Veh_AeroArea *
      (rtb_Switch * rtb_Product2);
    tmp_9 = _mm_sub_pd(_mm_loadu_pd(&KIMMCar_B.OUTPUT_1_0[79]), _mm_set_pd
                       (KIMMCar_P.Constant1_Value_o, KIMMCar_P.Constant_Value_p));
    _mm_storeu_pd(&tmp_8[0], tmp_9);
    KIMMCar_B.Sum_a = tmp_8[0];
    KIMMCar_B.Sum1_pm = tmp_8[1];
    KIMMCar_B.INPUT_3_1_1[0] = KIMMCar_B.Add_g;
    KIMMCar_B.INPUT_3_1_1[1] = 0.0;
    KIMMCar_B.INPUT_3_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_3_1_1_Discrete[0] = !(KIMMCar_B.INPUT_3_1_1[0] ==
        KIMMCar_DW.INPUT_3_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_3_1_1_Discrete[1] = KIMMCar_B.INPUT_3_1_1[0];
    }

    KIMMCar_B.INPUT_3_1_1[0] = KIMMCar_DW.INPUT_3_1_1_Discrete[1];
    KIMMCar_B.INPUT_3_1_1[3] = KIMMCar_DW.INPUT_3_1_1_Discrete[0];
    KIMMCar_B.INPUT_4_1_1[0] = KIMMCar_B.Add1_o;
    KIMMCar_B.INPUT_4_1_1[1] = 0.0;
    KIMMCar_B.INPUT_4_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_4_1_1_Discrete[0] = !(KIMMCar_B.INPUT_4_1_1[0] ==
        KIMMCar_DW.INPUT_4_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_4_1_1_Discrete[1] = KIMMCar_B.INPUT_4_1_1[0];
    }

    KIMMCar_B.INPUT_4_1_1[0] = KIMMCar_DW.INPUT_4_1_1_Discrete[1];
    KIMMCar_B.INPUT_4_1_1[3] = KIMMCar_DW.INPUT_4_1_1_Discrete[0];
    KIMMCar_B.INPUT_5_1_1[0] = KIMMCar_B.Gain6_f;
    KIMMCar_B.INPUT_5_1_1[1] = 0.0;
    KIMMCar_B.INPUT_5_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_5_1_1_Discrete[0] = !(KIMMCar_B.INPUT_5_1_1[0] ==
        KIMMCar_DW.INPUT_5_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_5_1_1_Discrete[1] = KIMMCar_B.INPUT_5_1_1[0];
    }

    KIMMCar_B.INPUT_5_1_1[0] = KIMMCar_DW.INPUT_5_1_1_Discrete[1];
    KIMMCar_B.INPUT_5_1_1[3] = KIMMCar_DW.INPUT_5_1_1_Discrete[0];
    KIMMCar_B.INPUT_6_1_1[0] = KIMMCar_B.Gain8;
    KIMMCar_B.INPUT_6_1_1[1] = 0.0;
    KIMMCar_B.INPUT_6_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_6_1_1_Discrete[0] = !(KIMMCar_B.INPUT_6_1_1[0] ==
        KIMMCar_DW.INPUT_6_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_6_1_1_Discrete[1] = KIMMCar_B.INPUT_6_1_1[0];
    }

    KIMMCar_B.INPUT_6_1_1[0] = KIMMCar_DW.INPUT_6_1_1_Discrete[1];
    KIMMCar_B.INPUT_6_1_1[3] = KIMMCar_DW.INPUT_6_1_1_Discrete[0];
    KIMMCar_B.INPUT_1_1_1[0] = KIMMCar_B.Gain1;
    KIMMCar_B.INPUT_1_1_1[1] = 0.0;
    KIMMCar_B.INPUT_1_1_1[2] = 0.0;
    KIMMCar_B.INPUT_1_1_1[3] = 0.0;
    KIMMCar_B.INPUT_2_1_1[0] = KIMMCar_B.Gain_g;
    KIMMCar_B.INPUT_2_1_1[1] = 0.0;
    KIMMCar_B.INPUT_2_1_1[2] = 0.0;
    KIMMCar_B.INPUT_2_1_1[3] = 0.0;
    KIMMCar_B.INPUT_29_1_1[0] = KIMMCar_P.FL_Lmux_Value;
    KIMMCar_B.INPUT_29_1_1[1] = 0.0;
    KIMMCar_B.INPUT_29_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_29_1_1_Discrete[0] = !(KIMMCar_B.INPUT_29_1_1[0] ==
        KIMMCar_DW.INPUT_29_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_29_1_1_Discrete[1] = KIMMCar_B.INPUT_29_1_1[0];
    }

    KIMMCar_B.INPUT_29_1_1[0] = KIMMCar_DW.INPUT_29_1_1_Discrete[1];
    KIMMCar_B.INPUT_29_1_1[3] = KIMMCar_DW.INPUT_29_1_1_Discrete[0];
    KIMMCar_B.INPUT_30_1_1[0] = KIMMCar_P.FL_Lmuy_Value;
    KIMMCar_B.INPUT_30_1_1[1] = 0.0;
    KIMMCar_B.INPUT_30_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_30_1_1_Discrete[0] = !(KIMMCar_B.INPUT_30_1_1[0] ==
        KIMMCar_DW.INPUT_30_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_30_1_1_Discrete[1] = KIMMCar_B.INPUT_30_1_1[0];
    }

    KIMMCar_B.INPUT_30_1_1[0] = KIMMCar_DW.INPUT_30_1_1_Discrete[1];
    KIMMCar_B.INPUT_30_1_1[3] = KIMMCar_DW.INPUT_30_1_1_Discrete[0];
    KIMMCar_B.INPUT_37_1_1[0] = KIMMCar_P.FR_Lmux_Value;
    KIMMCar_B.INPUT_37_1_1[1] = 0.0;
    KIMMCar_B.INPUT_37_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_37_1_1_Discrete[0] = !(KIMMCar_B.INPUT_37_1_1[0] ==
        KIMMCar_DW.INPUT_37_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_37_1_1_Discrete[1] = KIMMCar_B.INPUT_37_1_1[0];
    }

    KIMMCar_B.INPUT_37_1_1[0] = KIMMCar_DW.INPUT_37_1_1_Discrete[1];
    KIMMCar_B.INPUT_37_1_1[3] = KIMMCar_DW.INPUT_37_1_1_Discrete[0];
    KIMMCar_B.INPUT_38_1_1[0] = KIMMCar_P.FR_Lmuy_Value;
    KIMMCar_B.INPUT_38_1_1[1] = 0.0;
    KIMMCar_B.INPUT_38_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_38_1_1_Discrete[0] = !(KIMMCar_B.INPUT_38_1_1[0] ==
        KIMMCar_DW.INPUT_38_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_38_1_1_Discrete[1] = KIMMCar_B.INPUT_38_1_1[0];
    }

    KIMMCar_B.INPUT_38_1_1[0] = KIMMCar_DW.INPUT_38_1_1_Discrete[1];
    KIMMCar_B.INPUT_38_1_1[3] = KIMMCar_DW.INPUT_38_1_1_Discrete[0];
    KIMMCar_B.INPUT_45_1_1[0] = KIMMCar_P.RL_Lmux_Value;
    KIMMCar_B.INPUT_45_1_1[1] = 0.0;
    KIMMCar_B.INPUT_45_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_45_1_1_Discrete[0] = !(KIMMCar_B.INPUT_45_1_1[0] ==
        KIMMCar_DW.INPUT_45_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_45_1_1_Discrete[1] = KIMMCar_B.INPUT_45_1_1[0];
    }

    KIMMCar_B.INPUT_45_1_1[0] = KIMMCar_DW.INPUT_45_1_1_Discrete[1];
    KIMMCar_B.INPUT_45_1_1[3] = KIMMCar_DW.INPUT_45_1_1_Discrete[0];
    KIMMCar_B.INPUT_46_1_1[0] = KIMMCar_P.RL_Lmuy_Value;
    KIMMCar_B.INPUT_46_1_1[1] = 0.0;
    KIMMCar_B.INPUT_46_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_46_1_1_Discrete[0] = !(KIMMCar_B.INPUT_46_1_1[0] ==
        KIMMCar_DW.INPUT_46_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_46_1_1_Discrete[1] = KIMMCar_B.INPUT_46_1_1[0];
    }

    KIMMCar_B.INPUT_46_1_1[0] = KIMMCar_DW.INPUT_46_1_1_Discrete[1];
    KIMMCar_B.INPUT_46_1_1[3] = KIMMCar_DW.INPUT_46_1_1_Discrete[0];
    KIMMCar_B.INPUT_53_1_1[0] = KIMMCar_P.RR_Lmux_Value;
    KIMMCar_B.INPUT_53_1_1[1] = 0.0;
    KIMMCar_B.INPUT_53_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_53_1_1_Discrete[0] = !(KIMMCar_B.INPUT_53_1_1[0] ==
        KIMMCar_DW.INPUT_53_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_53_1_1_Discrete[1] = KIMMCar_B.INPUT_53_1_1[0];
    }

    KIMMCar_B.INPUT_53_1_1[0] = KIMMCar_DW.INPUT_53_1_1_Discrete[1];
    KIMMCar_B.INPUT_53_1_1[3] = KIMMCar_DW.INPUT_53_1_1_Discrete[0];
    KIMMCar_B.INPUT_54_1_1[0] = KIMMCar_P.RR_Lmuy_Value;
    KIMMCar_B.INPUT_54_1_1[1] = 0.0;
    KIMMCar_B.INPUT_54_1_1[2] = 0.0;
    if (tmp_7) {
      KIMMCar_DW.INPUT_54_1_1_Discrete[0] = !(KIMMCar_B.INPUT_54_1_1[0] ==
        KIMMCar_DW.INPUT_54_1_1_Discrete[1]);
      KIMMCar_DW.INPUT_54_1_1_Discrete[1] = KIMMCar_B.INPUT_54_1_1[0];
    }

    KIMMCar_B.INPUT_54_1_1[0] = KIMMCar_DW.INPUT_54_1_1_Discrete[1];
    KIMMCar_B.INPUT_54_1_1[3] = KIMMCar_DW.INPUT_54_1_1_Discrete[0];
    simulationData = (NeslSimulationData *)KIMMCar_DW.OUTPUT_1_1_SimData;
    time_3 = rtb_Gain7;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_3;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &KIMMCar_DW.OUTPUT_1_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &KIMMCar_DW.OUTPUT_1_1_Modes;
    zeroGuard = false;
    simulationData->mData->mFoundZcEvents = zeroGuard;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = tmp_7;
    zeroGuard = false;
    simulationData->mData->mIsSolverAssertCheck = zeroGuard;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = first_output;
    tmp_6[0] = 0;
    tmp_5[0] = KIMMCar_B.INPUT_3_1_1[0];
    tmp_5[1] = KIMMCar_B.INPUT_3_1_1[1];
    tmp_5[2] = KIMMCar_B.INPUT_3_1_1[2];
    tmp_5[3] = KIMMCar_B.INPUT_3_1_1[3];
    tmp_6[1] = 4;
    tmp_5[4] = KIMMCar_B.INPUT_4_1_1[0];
    tmp_5[5] = KIMMCar_B.INPUT_4_1_1[1];
    tmp_5[6] = KIMMCar_B.INPUT_4_1_1[2];
    tmp_5[7] = KIMMCar_B.INPUT_4_1_1[3];
    tmp_6[2] = 8;
    tmp_5[8] = KIMMCar_B.INPUT_5_1_1[0];
    tmp_5[9] = KIMMCar_B.INPUT_5_1_1[1];
    tmp_5[10] = KIMMCar_B.INPUT_5_1_1[2];
    tmp_5[11] = KIMMCar_B.INPUT_5_1_1[3];
    tmp_6[3] = 12;
    tmp_5[12] = KIMMCar_B.INPUT_6_1_1[0];
    tmp_5[13] = KIMMCar_B.INPUT_6_1_1[1];
    tmp_5[14] = KIMMCar_B.INPUT_6_1_1[2];
    tmp_5[15] = KIMMCar_B.INPUT_6_1_1[3];
    tmp_6[4] = 16;
    tmp_5[16] = KIMMCar_B.INPUT_7_1_1[0];
    tmp_5[17] = KIMMCar_B.INPUT_7_1_1[1];
    tmp_5[18] = KIMMCar_B.INPUT_7_1_1[2];
    tmp_5[19] = KIMMCar_B.INPUT_7_1_1[3];
    tmp_6[5] = 20;
    tmp_5[20] = KIMMCar_B.INPUT_8_1_1[0];
    tmp_5[21] = KIMMCar_B.INPUT_8_1_1[1];
    tmp_5[22] = KIMMCar_B.INPUT_8_1_1[2];
    tmp_5[23] = KIMMCar_B.INPUT_8_1_1[3];
    tmp_6[6] = 24;
    tmp_5[24] = KIMMCar_B.INPUT_9_1_1[0];
    tmp_5[25] = KIMMCar_B.INPUT_9_1_1[1];
    tmp_5[26] = KIMMCar_B.INPUT_9_1_1[2];
    tmp_5[27] = KIMMCar_B.INPUT_9_1_1[3];
    tmp_6[7] = 28;
    tmp_5[28] = KIMMCar_B.INPUT_14_1_1[0];
    tmp_5[29] = KIMMCar_B.INPUT_14_1_1[1];
    tmp_5[30] = KIMMCar_B.INPUT_14_1_1[2];
    tmp_5[31] = KIMMCar_B.INPUT_14_1_1[3];
    tmp_6[8] = 32;
    tmp_5[32] = KIMMCar_B.INPUT_10_1_1[0];
    tmp_5[33] = KIMMCar_B.INPUT_10_1_1[1];
    tmp_5[34] = KIMMCar_B.INPUT_10_1_1[2];
    tmp_5[35] = KIMMCar_B.INPUT_10_1_1[3];
    tmp_6[9] = 36;
    tmp_5[36] = KIMMCar_B.INPUT_11_1_1[0];
    tmp_5[37] = KIMMCar_B.INPUT_11_1_1[1];
    tmp_5[38] = KIMMCar_B.INPUT_11_1_1[2];
    tmp_5[39] = KIMMCar_B.INPUT_11_1_1[3];
    tmp_6[10] = 40;
    tmp_5[40] = KIMMCar_B.INPUT_12_1_1[0];
    tmp_5[41] = KIMMCar_B.INPUT_12_1_1[1];
    tmp_5[42] = KIMMCar_B.INPUT_12_1_1[2];
    tmp_5[43] = KIMMCar_B.INPUT_12_1_1[3];
    tmp_6[11] = 44;
    tmp_5[44] = KIMMCar_B.INPUT_13_1_1[0];
    tmp_5[45] = KIMMCar_B.INPUT_13_1_1[1];
    tmp_5[46] = KIMMCar_B.INPUT_13_1_1[2];
    tmp_5[47] = KIMMCar_B.INPUT_13_1_1[3];
    tmp_6[12] = 48;
    tmp_5[48] = KIMMCar_B.INPUT_15_1_1[0];
    tmp_5[49] = KIMMCar_B.INPUT_15_1_1[1];
    tmp_5[50] = KIMMCar_B.INPUT_15_1_1[2];
    tmp_5[51] = KIMMCar_B.INPUT_15_1_1[3];
    tmp_6[13] = 52;
    tmp_5[52] = KIMMCar_B.INPUT_16_1_1[0];
    tmp_5[53] = KIMMCar_B.INPUT_16_1_1[1];
    tmp_5[54] = KIMMCar_B.INPUT_16_1_1[2];
    tmp_5[55] = KIMMCar_B.INPUT_16_1_1[3];
    tmp_6[14] = 56;
    tmp_5[56] = KIMMCar_B.INPUT_17_1_1[0];
    tmp_5[57] = KIMMCar_B.INPUT_17_1_1[1];
    tmp_5[58] = KIMMCar_B.INPUT_17_1_1[2];
    tmp_5[59] = KIMMCar_B.INPUT_17_1_1[3];
    tmp_6[15] = 60;
    tmp_5[60] = KIMMCar_B.INPUT_21_1_1[0];
    tmp_5[61] = KIMMCar_B.INPUT_21_1_1[1];
    tmp_5[62] = KIMMCar_B.INPUT_21_1_1[2];
    tmp_5[63] = KIMMCar_B.INPUT_21_1_1[3];
    tmp_6[16] = 64;
    tmp_5[64] = KIMMCar_B.INPUT_18_1_1[0];
    tmp_5[65] = KIMMCar_B.INPUT_18_1_1[1];
    tmp_5[66] = KIMMCar_B.INPUT_18_1_1[2];
    tmp_5[67] = KIMMCar_B.INPUT_18_1_1[3];
    tmp_6[17] = 68;
    tmp_5[68] = KIMMCar_B.INPUT_19_1_1[0];
    tmp_5[69] = KIMMCar_B.INPUT_19_1_1[1];
    tmp_5[70] = KIMMCar_B.INPUT_19_1_1[2];
    tmp_5[71] = KIMMCar_B.INPUT_19_1_1[3];
    tmp_6[18] = 72;
    tmp_5[72] = KIMMCar_B.INPUT_20_1_1[0];
    tmp_5[73] = KIMMCar_B.INPUT_20_1_1[1];
    tmp_5[74] = KIMMCar_B.INPUT_20_1_1[2];
    tmp_5[75] = KIMMCar_B.INPUT_20_1_1[3];
    tmp_6[19] = 76;
    tmp_5[76] = KIMMCar_B.INPUT_22_1_1[0];
    tmp_5[77] = KIMMCar_B.INPUT_22_1_1[1];
    tmp_5[78] = KIMMCar_B.INPUT_22_1_1[2];
    tmp_5[79] = KIMMCar_B.INPUT_22_1_1[3];
    tmp_6[20] = 80;
    tmp_5[80] = KIMMCar_B.INPUT_23_1_1[0];
    tmp_5[81] = KIMMCar_B.INPUT_23_1_1[1];
    tmp_5[82] = KIMMCar_B.INPUT_23_1_1[2];
    tmp_5[83] = KIMMCar_B.INPUT_23_1_1[3];
    tmp_6[21] = 84;
    tmp_5[84] = KIMMCar_B.INPUT_24_1_1[0];
    tmp_5[85] = KIMMCar_B.INPUT_24_1_1[1];
    tmp_5[86] = KIMMCar_B.INPUT_24_1_1[2];
    tmp_5[87] = KIMMCar_B.INPUT_24_1_1[3];
    tmp_6[22] = 88;
    tmp_5[88] = KIMMCar_B.INPUT_25_1_1[0];
    tmp_5[89] = KIMMCar_B.INPUT_25_1_1[1];
    tmp_5[90] = KIMMCar_B.INPUT_25_1_1[2];
    tmp_5[91] = KIMMCar_B.INPUT_25_1_1[3];
    tmp_6[23] = 92;
    tmp_5[92] = KIMMCar_B.INPUT_28_1_1[0];
    tmp_5[93] = KIMMCar_B.INPUT_28_1_1[1];
    tmp_5[94] = KIMMCar_B.INPUT_28_1_1[2];
    tmp_5[95] = KIMMCar_B.INPUT_28_1_1[3];
    tmp_6[24] = 96;
    tmp_5[96] = KIMMCar_B.INPUT_26_1_1[0];
    tmp_5[97] = KIMMCar_B.INPUT_26_1_1[1];
    tmp_5[98] = KIMMCar_B.INPUT_26_1_1[2];
    tmp_5[99] = KIMMCar_B.INPUT_26_1_1[3];
    tmp_6[25] = 100;
    tmp_5[100] = KIMMCar_B.INPUT_27_1_1[0];
    tmp_5[101] = KIMMCar_B.INPUT_27_1_1[1];
    tmp_5[102] = KIMMCar_B.INPUT_27_1_1[2];
    tmp_5[103] = KIMMCar_B.INPUT_27_1_1[3];
    tmp_6[26] = 104;
    tmp_5[104] = KIMMCar_B.INPUT_31_1_1[0];
    tmp_5[105] = KIMMCar_B.INPUT_31_1_1[1];
    tmp_5[106] = KIMMCar_B.INPUT_31_1_1[2];
    tmp_5[107] = KIMMCar_B.INPUT_31_1_1[3];
    tmp_6[27] = 108;
    tmp_5[108] = KIMMCar_B.INPUT_32_1_1[0];
    tmp_5[109] = KIMMCar_B.INPUT_32_1_1[1];
    tmp_5[110] = KIMMCar_B.INPUT_32_1_1[2];
    tmp_5[111] = KIMMCar_B.INPUT_32_1_1[3];
    tmp_6[28] = 112;
    tmp_5[112] = KIMMCar_B.INPUT_33_1_1[0];
    tmp_5[113] = KIMMCar_B.INPUT_33_1_1[1];
    tmp_5[114] = KIMMCar_B.INPUT_33_1_1[2];
    tmp_5[115] = KIMMCar_B.INPUT_33_1_1[3];
    tmp_6[29] = 116;
    tmp_5[116] = KIMMCar_B.INPUT_36_1_1[0];
    tmp_5[117] = KIMMCar_B.INPUT_36_1_1[1];
    tmp_5[118] = KIMMCar_B.INPUT_36_1_1[2];
    tmp_5[119] = KIMMCar_B.INPUT_36_1_1[3];
    tmp_6[30] = 120;
    tmp_5[120] = KIMMCar_B.INPUT_34_1_1[0];
    tmp_5[121] = KIMMCar_B.INPUT_34_1_1[1];
    tmp_5[122] = KIMMCar_B.INPUT_34_1_1[2];
    tmp_5[123] = KIMMCar_B.INPUT_34_1_1[3];
    tmp_6[31] = 124;
    tmp_5[124] = KIMMCar_B.INPUT_35_1_1[0];
    tmp_5[125] = KIMMCar_B.INPUT_35_1_1[1];
    tmp_5[126] = KIMMCar_B.INPUT_35_1_1[2];
    tmp_5[127] = KIMMCar_B.INPUT_35_1_1[3];
    tmp_6[32] = 128;
    tmp_5[128] = KIMMCar_B.INPUT_39_1_1[0];
    tmp_5[129] = KIMMCar_B.INPUT_39_1_1[1];
    tmp_5[130] = KIMMCar_B.INPUT_39_1_1[2];
    tmp_5[131] = KIMMCar_B.INPUT_39_1_1[3];
    tmp_6[33] = 132;
    tmp_5[132] = KIMMCar_B.INPUT_40_1_1[0];
    tmp_5[133] = KIMMCar_B.INPUT_40_1_1[1];
    tmp_5[134] = KIMMCar_B.INPUT_40_1_1[2];
    tmp_5[135] = KIMMCar_B.INPUT_40_1_1[3];
    tmp_6[34] = 136;
    tmp_5[136] = KIMMCar_B.INPUT_41_1_1[0];
    tmp_5[137] = KIMMCar_B.INPUT_41_1_1[1];
    tmp_5[138] = KIMMCar_B.INPUT_41_1_1[2];
    tmp_5[139] = KIMMCar_B.INPUT_41_1_1[3];
    tmp_6[35] = 140;
    tmp_5[140] = KIMMCar_B.INPUT_44_1_1[0];
    tmp_5[141] = KIMMCar_B.INPUT_44_1_1[1];
    tmp_5[142] = KIMMCar_B.INPUT_44_1_1[2];
    tmp_5[143] = KIMMCar_B.INPUT_44_1_1[3];
    tmp_6[36] = 144;
    tmp_5[144] = KIMMCar_B.INPUT_42_1_1[0];
    tmp_5[145] = KIMMCar_B.INPUT_42_1_1[1];
    tmp_5[146] = KIMMCar_B.INPUT_42_1_1[2];
    tmp_5[147] = KIMMCar_B.INPUT_42_1_1[3];
    tmp_6[37] = 148;
    tmp_5[148] = KIMMCar_B.INPUT_43_1_1[0];
    tmp_5[149] = KIMMCar_B.INPUT_43_1_1[1];
    tmp_5[150] = KIMMCar_B.INPUT_43_1_1[2];
    tmp_5[151] = KIMMCar_B.INPUT_43_1_1[3];
    tmp_6[38] = 152;
    tmp_5[152] = KIMMCar_B.INPUT_47_1_1[0];
    tmp_5[153] = KIMMCar_B.INPUT_47_1_1[1];
    tmp_5[154] = KIMMCar_B.INPUT_47_1_1[2];
    tmp_5[155] = KIMMCar_B.INPUT_47_1_1[3];
    tmp_6[39] = 156;
    tmp_5[156] = KIMMCar_B.INPUT_48_1_1[0];
    tmp_5[157] = KIMMCar_B.INPUT_48_1_1[1];
    tmp_5[158] = KIMMCar_B.INPUT_48_1_1[2];
    tmp_5[159] = KIMMCar_B.INPUT_48_1_1[3];
    tmp_6[40] = 160;
    tmp_5[160] = KIMMCar_B.INPUT_49_1_1[0];
    tmp_5[161] = KIMMCar_B.INPUT_49_1_1[1];
    tmp_5[162] = KIMMCar_B.INPUT_49_1_1[2];
    tmp_5[163] = KIMMCar_B.INPUT_49_1_1[3];
    tmp_6[41] = 164;
    tmp_5[164] = KIMMCar_B.INPUT_52_1_1[0];
    tmp_5[165] = KIMMCar_B.INPUT_52_1_1[1];
    tmp_5[166] = KIMMCar_B.INPUT_52_1_1[2];
    tmp_5[167] = KIMMCar_B.INPUT_52_1_1[3];
    tmp_6[42] = 168;
    tmp_5[168] = KIMMCar_B.INPUT_50_1_1[0];
    tmp_5[169] = KIMMCar_B.INPUT_50_1_1[1];
    tmp_5[170] = KIMMCar_B.INPUT_50_1_1[2];
    tmp_5[171] = KIMMCar_B.INPUT_50_1_1[3];
    tmp_6[43] = 172;
    tmp_5[172] = KIMMCar_B.INPUT_51_1_1[0];
    tmp_5[173] = KIMMCar_B.INPUT_51_1_1[1];
    tmp_5[174] = KIMMCar_B.INPUT_51_1_1[2];
    tmp_5[175] = KIMMCar_B.INPUT_51_1_1[3];
    tmp_6[44] = 176;
    tmp_5[176] = KIMMCar_B.INPUT_1_1_1[0];
    tmp_5[177] = KIMMCar_B.INPUT_1_1_1[1];
    tmp_5[178] = KIMMCar_B.INPUT_1_1_1[2];
    tmp_5[179] = KIMMCar_B.INPUT_1_1_1[3];
    tmp_6[45] = 180;
    tmp_5[180] = KIMMCar_B.INPUT_2_1_1[0];
    tmp_5[181] = KIMMCar_B.INPUT_2_1_1[1];
    tmp_5[182] = KIMMCar_B.INPUT_2_1_1[2];
    tmp_5[183] = KIMMCar_B.INPUT_2_1_1[3];
    tmp_6[46] = 184;
    tmp_5[184] = KIMMCar_B.INPUT_29_1_1[0];
    tmp_5[185] = KIMMCar_B.INPUT_29_1_1[1];
    tmp_5[186] = KIMMCar_B.INPUT_29_1_1[2];
    tmp_5[187] = KIMMCar_B.INPUT_29_1_1[3];
    tmp_6[47] = 188;
    tmp_5[188] = KIMMCar_B.INPUT_30_1_1[0];
    tmp_5[189] = KIMMCar_B.INPUT_30_1_1[1];
    tmp_5[190] = KIMMCar_B.INPUT_30_1_1[2];
    tmp_5[191] = KIMMCar_B.INPUT_30_1_1[3];
    tmp_6[48] = 192;
    tmp_5[192] = KIMMCar_B.INPUT_37_1_1[0];
    tmp_5[193] = KIMMCar_B.INPUT_37_1_1[1];
    tmp_5[194] = KIMMCar_B.INPUT_37_1_1[2];
    tmp_5[195] = KIMMCar_B.INPUT_37_1_1[3];
    tmp_6[49] = 196;
    tmp_5[196] = KIMMCar_B.INPUT_38_1_1[0];
    tmp_5[197] = KIMMCar_B.INPUT_38_1_1[1];
    tmp_5[198] = KIMMCar_B.INPUT_38_1_1[2];
    tmp_5[199] = KIMMCar_B.INPUT_38_1_1[3];
    tmp_6[50] = 200;
    tmp_5[200] = KIMMCar_B.INPUT_45_1_1[0];
    tmp_5[201] = KIMMCar_B.INPUT_45_1_1[1];
    tmp_5[202] = KIMMCar_B.INPUT_45_1_1[2];
    tmp_5[203] = KIMMCar_B.INPUT_45_1_1[3];
    tmp_6[51] = 204;
    tmp_5[204] = KIMMCar_B.INPUT_46_1_1[0];
    tmp_5[205] = KIMMCar_B.INPUT_46_1_1[1];
    tmp_5[206] = KIMMCar_B.INPUT_46_1_1[2];
    tmp_5[207] = KIMMCar_B.INPUT_46_1_1[3];
    tmp_6[52] = 208;
    tmp_5[208] = KIMMCar_B.INPUT_53_1_1[0];
    tmp_5[209] = KIMMCar_B.INPUT_53_1_1[1];
    tmp_5[210] = KIMMCar_B.INPUT_53_1_1[2];
    tmp_5[211] = KIMMCar_B.INPUT_53_1_1[3];
    tmp_6[53] = 212;
    tmp_5[212] = KIMMCar_B.INPUT_54_1_1[0];
    tmp_5[213] = KIMMCar_B.INPUT_54_1_1[1];
    tmp_5[214] = KIMMCar_B.INPUT_54_1_1[2];
    tmp_5[215] = KIMMCar_B.INPUT_54_1_1[3];
    tmp_6[54] = 216;
    memcpy(&tmp_5[216], &KIMMCar_B.STATE_1[0], 29U * sizeof(real_T));
    tmp_6[55] = 245;
    simulationData->mData->mInputValues.mN = 245;
    simulationData->mData->mInputValues.mX = &tmp_5[0];
    simulationData->mData->mInputOffsets.mN = 56;
    simulationData->mData->mInputOffsets.mX = &tmp_6[0];
    simulationData->mData->mOutputs.mN = 27;
    simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_4 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_4;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)KIMMCar_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diag);
    scaleRate = ne_simulator_method((NeslSimulator *)
      KIMMCar_DW.OUTPUT_1_1_Simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (scaleRate != 0) {
      zeroGuard = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
      if (zeroGuard) {
        msg_2 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(KIMMCar_M, msg_2);
      }
    }
  }

  if (rtmIsMajorTimeStep(KIMMCar_M)) {
    fmu_LogOutput();
  }

  if (rtmIsMajorTimeStep(KIMMCar_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0[216];
    real_T tmp_3[2];
    real_T denAccum;
    real_T time;
    int32_T k;
    int_T tmp_1[55];
    boolean_T tmp;
    boolean_T tmp_2;
    tmp_2 = rtmIsMajorTimeStep(KIMMCar_M);
    if (tmp_2) {
      KIMMCar_DW.UnitDelay_DSTATE = KIMMCar_B.Sum_k;
      KIMMCar_DW.UnitDelay1_DSTATE = KIMMCar_B.Sum1_p;
      KIMMCar_DW.UnitDelay_DSTATE_c = KIMMCar_B.Sum_a;
      KIMMCar_DW.UnitDelay1_DSTATE_e = KIMMCar_B.Sum1_pm;
      denAccum = KIMMCar_B.OUTPUT_1_0[33];
      KIMMCar_DW.DiscreteTransferFcn1_states = (denAccum -
        KIMMCar_P.DiscreteTransferFcn1_DenCoef[1] *
        KIMMCar_DW.DiscreteTransferFcn1_states) /
        KIMMCar_P.DiscreteTransferFcn1_DenCoef[0];
      denAccum = KIMMCar_B.OUTPUT_1_0[34];
      _mm_storeu_pd(&tmp_3[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd(KIMMCar_B.Atan1,
        denAccum), _mm_mul_pd(_mm_set_pd(KIMMCar_P.DiscreteTransferFcn3_DenCoef
        [1], KIMMCar_P.DiscreteTransferFcn2_DenCoef[1]), _mm_set_pd
        (KIMMCar_DW.DiscreteTransferFcn3_states,
         KIMMCar_DW.DiscreteTransferFcn2_states))), _mm_set_pd
        (KIMMCar_P.DiscreteTransferFcn3_DenCoef[0],
         KIMMCar_P.DiscreteTransferFcn2_DenCoef[0])));
      KIMMCar_DW.DiscreteTransferFcn2_states = tmp_3[0];
      KIMMCar_DW.DiscreteTransferFcn3_states = tmp_3[1];
      denAccum = KIMMCar_B.OUTPUT_1_0[44];
      KIMMCar_DW.DiscreteTransferFcn1_states_e = (denAccum -
        KIMMCar_P.DiscreteTransferFcn1_DenCoef_e[1] *
        KIMMCar_DW.DiscreteTransferFcn1_states_e) /
        KIMMCar_P.DiscreteTransferFcn1_DenCoef_e[0];
      denAccum = KIMMCar_B.OUTPUT_1_0[45];
      _mm_storeu_pd(&tmp_3[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd
        (KIMMCar_B.Atan1_l, denAccum), _mm_mul_pd(_mm_set_pd
        (KIMMCar_P.DiscreteTransferFcn3_DenCoef_d[1],
         KIMMCar_P.DiscreteTransferFcn2_DenCoef_l[1]), _mm_set_pd
        (KIMMCar_DW.DiscreteTransferFcn3_states_k,
         KIMMCar_DW.DiscreteTransferFcn2_states_o))), _mm_set_pd
        (KIMMCar_P.DiscreteTransferFcn3_DenCoef_d[0],
         KIMMCar_P.DiscreteTransferFcn2_DenCoef_l[0])));
      KIMMCar_DW.DiscreteTransferFcn2_states_o = tmp_3[0];
      KIMMCar_DW.DiscreteTransferFcn3_states_k = tmp_3[1];
      denAccum = KIMMCar_B.OUTPUT_1_0[66];
      KIMMCar_DW.DiscreteTransferFcn1_states_i = (denAccum -
        KIMMCar_P.DiscreteTransferFcn1_DenCoef_o[1] *
        KIMMCar_DW.DiscreteTransferFcn1_states_i) /
        KIMMCar_P.DiscreteTransferFcn1_DenCoef_o[0];
      denAccum = KIMMCar_B.OUTPUT_1_0[67];
      _mm_storeu_pd(&tmp_3[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd
        (KIMMCar_B.Atan1_k, denAccum), _mm_mul_pd(_mm_set_pd
        (KIMMCar_P.DiscreteTransferFcn3_DenCoef_j[1],
         KIMMCar_P.DiscreteTransferFcn2_DenCoef_p[1]), _mm_set_pd
        (KIMMCar_DW.DiscreteTransferFcn3_states_n,
         KIMMCar_DW.DiscreteTransferFcn2_states_b))), _mm_set_pd
        (KIMMCar_P.DiscreteTransferFcn3_DenCoef_j[0],
         KIMMCar_P.DiscreteTransferFcn2_DenCoef_p[0])));
      KIMMCar_DW.DiscreteTransferFcn2_states_b = tmp_3[0];
      KIMMCar_DW.DiscreteTransferFcn3_states_n = tmp_3[1];
      denAccum = KIMMCar_B.OUTPUT_1_0[55];
      KIMMCar_DW.DiscreteTransferFcn1_states_g = (denAccum -
        KIMMCar_P.DiscreteTransferFcn1_DenCoef_a[1] *
        KIMMCar_DW.DiscreteTransferFcn1_states_g) /
        KIMMCar_P.DiscreteTransferFcn1_DenCoef_a[0];
      denAccum = KIMMCar_B.OUTPUT_1_0[56];
      _mm_storeu_pd(&tmp_3[0], _mm_div_pd(_mm_sub_pd(_mm_set_pd
        (KIMMCar_B.Atan1_i, denAccum), _mm_mul_pd(_mm_set_pd
        (KIMMCar_P.DiscreteTransferFcn3_DenCoef_k[1],
         KIMMCar_P.DiscreteTransferFcn2_DenCoef_j[1]), _mm_set_pd
        (KIMMCar_DW.DiscreteTransferFcn3_states_n1,
         KIMMCar_DW.DiscreteTransferFcn2_states_j))), _mm_set_pd
        (KIMMCar_P.DiscreteTransferFcn3_DenCoef_k[0],
         KIMMCar_P.DiscreteTransferFcn2_DenCoef_j[0])));
      KIMMCar_DW.DiscreteTransferFcn2_states_j = tmp_3[0];
      KIMMCar_DW.DiscreteTransferFcn3_states_n1 = tmp_3[1];
    }

    simulationData = (NeslSimulationData *)KIMMCar_DW.STATE_1_SimData;
    time = KIMMCar_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 29;
    simulationData->mData->mContStates.mX =
      &KIMMCar_X.KIMMCarVehicleCamera_FramesCartesian_JointPxp[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &KIMMCar_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &KIMMCar_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(KIMMCar_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&KIMMCar_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&KIMMCar_M->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = KIMMCar_B.INPUT_3_1_1[0];
    tmp_0[1] = KIMMCar_B.INPUT_3_1_1[1];
    tmp_0[2] = KIMMCar_B.INPUT_3_1_1[2];
    tmp_0[3] = KIMMCar_B.INPUT_3_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = KIMMCar_B.INPUT_4_1_1[0];
    tmp_0[5] = KIMMCar_B.INPUT_4_1_1[1];
    tmp_0[6] = KIMMCar_B.INPUT_4_1_1[2];
    tmp_0[7] = KIMMCar_B.INPUT_4_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = KIMMCar_B.INPUT_5_1_1[0];
    tmp_0[9] = KIMMCar_B.INPUT_5_1_1[1];
    tmp_0[10] = KIMMCar_B.INPUT_5_1_1[2];
    tmp_0[11] = KIMMCar_B.INPUT_5_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = KIMMCar_B.INPUT_6_1_1[0];
    tmp_0[13] = KIMMCar_B.INPUT_6_1_1[1];
    tmp_0[14] = KIMMCar_B.INPUT_6_1_1[2];
    tmp_0[15] = KIMMCar_B.INPUT_6_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = KIMMCar_B.INPUT_7_1_1[0];
    tmp_0[17] = KIMMCar_B.INPUT_7_1_1[1];
    tmp_0[18] = KIMMCar_B.INPUT_7_1_1[2];
    tmp_0[19] = KIMMCar_B.INPUT_7_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = KIMMCar_B.INPUT_8_1_1[0];
    tmp_0[21] = KIMMCar_B.INPUT_8_1_1[1];
    tmp_0[22] = KIMMCar_B.INPUT_8_1_1[2];
    tmp_0[23] = KIMMCar_B.INPUT_8_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = KIMMCar_B.INPUT_9_1_1[0];
    tmp_0[25] = KIMMCar_B.INPUT_9_1_1[1];
    tmp_0[26] = KIMMCar_B.INPUT_9_1_1[2];
    tmp_0[27] = KIMMCar_B.INPUT_9_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = KIMMCar_B.INPUT_14_1_1[0];
    tmp_0[29] = KIMMCar_B.INPUT_14_1_1[1];
    tmp_0[30] = KIMMCar_B.INPUT_14_1_1[2];
    tmp_0[31] = KIMMCar_B.INPUT_14_1_1[3];
    tmp_1[8] = 32;
    tmp_0[32] = KIMMCar_B.INPUT_10_1_1[0];
    tmp_0[33] = KIMMCar_B.INPUT_10_1_1[1];
    tmp_0[34] = KIMMCar_B.INPUT_10_1_1[2];
    tmp_0[35] = KIMMCar_B.INPUT_10_1_1[3];
    tmp_1[9] = 36;
    tmp_0[36] = KIMMCar_B.INPUT_11_1_1[0];
    tmp_0[37] = KIMMCar_B.INPUT_11_1_1[1];
    tmp_0[38] = KIMMCar_B.INPUT_11_1_1[2];
    tmp_0[39] = KIMMCar_B.INPUT_11_1_1[3];
    tmp_1[10] = 40;
    tmp_0[40] = KIMMCar_B.INPUT_12_1_1[0];
    tmp_0[41] = KIMMCar_B.INPUT_12_1_1[1];
    tmp_0[42] = KIMMCar_B.INPUT_12_1_1[2];
    tmp_0[43] = KIMMCar_B.INPUT_12_1_1[3];
    tmp_1[11] = 44;
    tmp_0[44] = KIMMCar_B.INPUT_13_1_1[0];
    tmp_0[45] = KIMMCar_B.INPUT_13_1_1[1];
    tmp_0[46] = KIMMCar_B.INPUT_13_1_1[2];
    tmp_0[47] = KIMMCar_B.INPUT_13_1_1[3];
    tmp_1[12] = 48;
    tmp_0[48] = KIMMCar_B.INPUT_15_1_1[0];
    tmp_0[49] = KIMMCar_B.INPUT_15_1_1[1];
    tmp_0[50] = KIMMCar_B.INPUT_15_1_1[2];
    tmp_0[51] = KIMMCar_B.INPUT_15_1_1[3];
    tmp_1[13] = 52;
    tmp_0[52] = KIMMCar_B.INPUT_16_1_1[0];
    tmp_0[53] = KIMMCar_B.INPUT_16_1_1[1];
    tmp_0[54] = KIMMCar_B.INPUT_16_1_1[2];
    tmp_0[55] = KIMMCar_B.INPUT_16_1_1[3];
    tmp_1[14] = 56;
    tmp_0[56] = KIMMCar_B.INPUT_17_1_1[0];
    tmp_0[57] = KIMMCar_B.INPUT_17_1_1[1];
    tmp_0[58] = KIMMCar_B.INPUT_17_1_1[2];
    tmp_0[59] = KIMMCar_B.INPUT_17_1_1[3];
    tmp_1[15] = 60;
    tmp_0[60] = KIMMCar_B.INPUT_21_1_1[0];
    tmp_0[61] = KIMMCar_B.INPUT_21_1_1[1];
    tmp_0[62] = KIMMCar_B.INPUT_21_1_1[2];
    tmp_0[63] = KIMMCar_B.INPUT_21_1_1[3];
    tmp_1[16] = 64;
    tmp_0[64] = KIMMCar_B.INPUT_18_1_1[0];
    tmp_0[65] = KIMMCar_B.INPUT_18_1_1[1];
    tmp_0[66] = KIMMCar_B.INPUT_18_1_1[2];
    tmp_0[67] = KIMMCar_B.INPUT_18_1_1[3];
    tmp_1[17] = 68;
    tmp_0[68] = KIMMCar_B.INPUT_19_1_1[0];
    tmp_0[69] = KIMMCar_B.INPUT_19_1_1[1];
    tmp_0[70] = KIMMCar_B.INPUT_19_1_1[2];
    tmp_0[71] = KIMMCar_B.INPUT_19_1_1[3];
    tmp_1[18] = 72;
    tmp_0[72] = KIMMCar_B.INPUT_20_1_1[0];
    tmp_0[73] = KIMMCar_B.INPUT_20_1_1[1];
    tmp_0[74] = KIMMCar_B.INPUT_20_1_1[2];
    tmp_0[75] = KIMMCar_B.INPUT_20_1_1[3];
    tmp_1[19] = 76;
    tmp_0[76] = KIMMCar_B.INPUT_22_1_1[0];
    tmp_0[77] = KIMMCar_B.INPUT_22_1_1[1];
    tmp_0[78] = KIMMCar_B.INPUT_22_1_1[2];
    tmp_0[79] = KIMMCar_B.INPUT_22_1_1[3];
    tmp_1[20] = 80;
    tmp_0[80] = KIMMCar_B.INPUT_23_1_1[0];
    tmp_0[81] = KIMMCar_B.INPUT_23_1_1[1];
    tmp_0[82] = KIMMCar_B.INPUT_23_1_1[2];
    tmp_0[83] = KIMMCar_B.INPUT_23_1_1[3];
    tmp_1[21] = 84;
    tmp_0[84] = KIMMCar_B.INPUT_24_1_1[0];
    tmp_0[85] = KIMMCar_B.INPUT_24_1_1[1];
    tmp_0[86] = KIMMCar_B.INPUT_24_1_1[2];
    tmp_0[87] = KIMMCar_B.INPUT_24_1_1[3];
    tmp_1[22] = 88;
    tmp_0[88] = KIMMCar_B.INPUT_25_1_1[0];
    tmp_0[89] = KIMMCar_B.INPUT_25_1_1[1];
    tmp_0[90] = KIMMCar_B.INPUT_25_1_1[2];
    tmp_0[91] = KIMMCar_B.INPUT_25_1_1[3];
    tmp_1[23] = 92;
    tmp_0[92] = KIMMCar_B.INPUT_28_1_1[0];
    tmp_0[93] = KIMMCar_B.INPUT_28_1_1[1];
    tmp_0[94] = KIMMCar_B.INPUT_28_1_1[2];
    tmp_0[95] = KIMMCar_B.INPUT_28_1_1[3];
    tmp_1[24] = 96;
    tmp_0[96] = KIMMCar_B.INPUT_26_1_1[0];
    tmp_0[97] = KIMMCar_B.INPUT_26_1_1[1];
    tmp_0[98] = KIMMCar_B.INPUT_26_1_1[2];
    tmp_0[99] = KIMMCar_B.INPUT_26_1_1[3];
    tmp_1[25] = 100;
    tmp_0[100] = KIMMCar_B.INPUT_27_1_1[0];
    tmp_0[101] = KIMMCar_B.INPUT_27_1_1[1];
    tmp_0[102] = KIMMCar_B.INPUT_27_1_1[2];
    tmp_0[103] = KIMMCar_B.INPUT_27_1_1[3];
    tmp_1[26] = 104;
    tmp_0[104] = KIMMCar_B.INPUT_31_1_1[0];
    tmp_0[105] = KIMMCar_B.INPUT_31_1_1[1];
    tmp_0[106] = KIMMCar_B.INPUT_31_1_1[2];
    tmp_0[107] = KIMMCar_B.INPUT_31_1_1[3];
    tmp_1[27] = 108;
    tmp_0[108] = KIMMCar_B.INPUT_32_1_1[0];
    tmp_0[109] = KIMMCar_B.INPUT_32_1_1[1];
    tmp_0[110] = KIMMCar_B.INPUT_32_1_1[2];
    tmp_0[111] = KIMMCar_B.INPUT_32_1_1[3];
    tmp_1[28] = 112;
    tmp_0[112] = KIMMCar_B.INPUT_33_1_1[0];
    tmp_0[113] = KIMMCar_B.INPUT_33_1_1[1];
    tmp_0[114] = KIMMCar_B.INPUT_33_1_1[2];
    tmp_0[115] = KIMMCar_B.INPUT_33_1_1[3];
    tmp_1[29] = 116;
    tmp_0[116] = KIMMCar_B.INPUT_36_1_1[0];
    tmp_0[117] = KIMMCar_B.INPUT_36_1_1[1];
    tmp_0[118] = KIMMCar_B.INPUT_36_1_1[2];
    tmp_0[119] = KIMMCar_B.INPUT_36_1_1[3];
    tmp_1[30] = 120;
    tmp_0[120] = KIMMCar_B.INPUT_34_1_1[0];
    tmp_0[121] = KIMMCar_B.INPUT_34_1_1[1];
    tmp_0[122] = KIMMCar_B.INPUT_34_1_1[2];
    tmp_0[123] = KIMMCar_B.INPUT_34_1_1[3];
    tmp_1[31] = 124;
    tmp_0[124] = KIMMCar_B.INPUT_35_1_1[0];
    tmp_0[125] = KIMMCar_B.INPUT_35_1_1[1];
    tmp_0[126] = KIMMCar_B.INPUT_35_1_1[2];
    tmp_0[127] = KIMMCar_B.INPUT_35_1_1[3];
    tmp_1[32] = 128;
    tmp_0[128] = KIMMCar_B.INPUT_39_1_1[0];
    tmp_0[129] = KIMMCar_B.INPUT_39_1_1[1];
    tmp_0[130] = KIMMCar_B.INPUT_39_1_1[2];
    tmp_0[131] = KIMMCar_B.INPUT_39_1_1[3];
    tmp_1[33] = 132;
    tmp_0[132] = KIMMCar_B.INPUT_40_1_1[0];
    tmp_0[133] = KIMMCar_B.INPUT_40_1_1[1];
    tmp_0[134] = KIMMCar_B.INPUT_40_1_1[2];
    tmp_0[135] = KIMMCar_B.INPUT_40_1_1[3];
    tmp_1[34] = 136;
    tmp_0[136] = KIMMCar_B.INPUT_41_1_1[0];
    tmp_0[137] = KIMMCar_B.INPUT_41_1_1[1];
    tmp_0[138] = KIMMCar_B.INPUT_41_1_1[2];
    tmp_0[139] = KIMMCar_B.INPUT_41_1_1[3];
    tmp_1[35] = 140;
    tmp_0[140] = KIMMCar_B.INPUT_44_1_1[0];
    tmp_0[141] = KIMMCar_B.INPUT_44_1_1[1];
    tmp_0[142] = KIMMCar_B.INPUT_44_1_1[2];
    tmp_0[143] = KIMMCar_B.INPUT_44_1_1[3];
    tmp_1[36] = 144;
    tmp_0[144] = KIMMCar_B.INPUT_42_1_1[0];
    tmp_0[145] = KIMMCar_B.INPUT_42_1_1[1];
    tmp_0[146] = KIMMCar_B.INPUT_42_1_1[2];
    tmp_0[147] = KIMMCar_B.INPUT_42_1_1[3];
    tmp_1[37] = 148;
    tmp_0[148] = KIMMCar_B.INPUT_43_1_1[0];
    tmp_0[149] = KIMMCar_B.INPUT_43_1_1[1];
    tmp_0[150] = KIMMCar_B.INPUT_43_1_1[2];
    tmp_0[151] = KIMMCar_B.INPUT_43_1_1[3];
    tmp_1[38] = 152;
    tmp_0[152] = KIMMCar_B.INPUT_47_1_1[0];
    tmp_0[153] = KIMMCar_B.INPUT_47_1_1[1];
    tmp_0[154] = KIMMCar_B.INPUT_47_1_1[2];
    tmp_0[155] = KIMMCar_B.INPUT_47_1_1[3];
    tmp_1[39] = 156;
    tmp_0[156] = KIMMCar_B.INPUT_48_1_1[0];
    tmp_0[157] = KIMMCar_B.INPUT_48_1_1[1];
    tmp_0[158] = KIMMCar_B.INPUT_48_1_1[2];
    tmp_0[159] = KIMMCar_B.INPUT_48_1_1[3];
    tmp_1[40] = 160;
    tmp_0[160] = KIMMCar_B.INPUT_49_1_1[0];
    tmp_0[161] = KIMMCar_B.INPUT_49_1_1[1];
    tmp_0[162] = KIMMCar_B.INPUT_49_1_1[2];
    tmp_0[163] = KIMMCar_B.INPUT_49_1_1[3];
    tmp_1[41] = 164;
    tmp_0[164] = KIMMCar_B.INPUT_52_1_1[0];
    tmp_0[165] = KIMMCar_B.INPUT_52_1_1[1];
    tmp_0[166] = KIMMCar_B.INPUT_52_1_1[2];
    tmp_0[167] = KIMMCar_B.INPUT_52_1_1[3];
    tmp_1[42] = 168;
    tmp_0[168] = KIMMCar_B.INPUT_50_1_1[0];
    tmp_0[169] = KIMMCar_B.INPUT_50_1_1[1];
    tmp_0[170] = KIMMCar_B.INPUT_50_1_1[2];
    tmp_0[171] = KIMMCar_B.INPUT_50_1_1[3];
    tmp_1[43] = 172;
    tmp_0[172] = KIMMCar_B.INPUT_51_1_1[0];
    tmp_0[173] = KIMMCar_B.INPUT_51_1_1[1];
    tmp_0[174] = KIMMCar_B.INPUT_51_1_1[2];
    tmp_0[175] = KIMMCar_B.INPUT_51_1_1[3];
    tmp_1[44] = 176;
    tmp_0[176] = KIMMCar_B.INPUT_1_1_1[0];
    tmp_0[177] = KIMMCar_B.INPUT_1_1_1[1];
    tmp_0[178] = KIMMCar_B.INPUT_1_1_1[2];
    tmp_0[179] = KIMMCar_B.INPUT_1_1_1[3];
    tmp_1[45] = 180;
    tmp_0[180] = KIMMCar_B.INPUT_2_1_1[0];
    tmp_0[181] = KIMMCar_B.INPUT_2_1_1[1];
    tmp_0[182] = KIMMCar_B.INPUT_2_1_1[2];
    tmp_0[183] = KIMMCar_B.INPUT_2_1_1[3];
    tmp_1[46] = 184;
    tmp_0[184] = KIMMCar_B.INPUT_29_1_1[0];
    tmp_0[185] = KIMMCar_B.INPUT_29_1_1[1];
    tmp_0[186] = KIMMCar_B.INPUT_29_1_1[2];
    tmp_0[187] = KIMMCar_B.INPUT_29_1_1[3];
    tmp_1[47] = 188;
    tmp_0[188] = KIMMCar_B.INPUT_30_1_1[0];
    tmp_0[189] = KIMMCar_B.INPUT_30_1_1[1];
    tmp_0[190] = KIMMCar_B.INPUT_30_1_1[2];
    tmp_0[191] = KIMMCar_B.INPUT_30_1_1[3];
    tmp_1[48] = 192;
    tmp_0[192] = KIMMCar_B.INPUT_37_1_1[0];
    tmp_0[193] = KIMMCar_B.INPUT_37_1_1[1];
    tmp_0[194] = KIMMCar_B.INPUT_37_1_1[2];
    tmp_0[195] = KIMMCar_B.INPUT_37_1_1[3];
    tmp_1[49] = 196;
    tmp_0[196] = KIMMCar_B.INPUT_38_1_1[0];
    tmp_0[197] = KIMMCar_B.INPUT_38_1_1[1];
    tmp_0[198] = KIMMCar_B.INPUT_38_1_1[2];
    tmp_0[199] = KIMMCar_B.INPUT_38_1_1[3];
    tmp_1[50] = 200;
    tmp_0[200] = KIMMCar_B.INPUT_45_1_1[0];
    tmp_0[201] = KIMMCar_B.INPUT_45_1_1[1];
    tmp_0[202] = KIMMCar_B.INPUT_45_1_1[2];
    tmp_0[203] = KIMMCar_B.INPUT_45_1_1[3];
    tmp_1[51] = 204;
    tmp_0[204] = KIMMCar_B.INPUT_46_1_1[0];
    tmp_0[205] = KIMMCar_B.INPUT_46_1_1[1];
    tmp_0[206] = KIMMCar_B.INPUT_46_1_1[2];
    tmp_0[207] = KIMMCar_B.INPUT_46_1_1[3];
    tmp_1[52] = 208;
    tmp_0[208] = KIMMCar_B.INPUT_53_1_1[0];
    tmp_0[209] = KIMMCar_B.INPUT_53_1_1[1];
    tmp_0[210] = KIMMCar_B.INPUT_53_1_1[2];
    tmp_0[211] = KIMMCar_B.INPUT_53_1_1[3];
    tmp_1[53] = 212;
    tmp_0[212] = KIMMCar_B.INPUT_54_1_1[0];
    tmp_0[213] = KIMMCar_B.INPUT_54_1_1[1];
    tmp_0[214] = KIMMCar_B.INPUT_54_1_1[2];
    tmp_0[215] = KIMMCar_B.INPUT_54_1_1[3];
    tmp_1[54] = 216;
    simulationData->mData->mInputValues.mN = 216;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 55;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)KIMMCar_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    k = ne_simulator_method((NeslSimulator *)KIMMCar_DW.STATE_1_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (k != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(KIMMCar_M, msg);
      }
    }

    if (tmp_2) {
      KIMMCar_DW.UnitDelay_DSTATE_f = KIMMCar_B.OUTPUT_1_0[90];
      KIMMCar_DW.UnitDelay_DSTATE_i[0] = KIMMCar_B.OUTPUT_1_0[8];
      KIMMCar_DW.UnitDelay_DSTATE_i[1] = KIMMCar_B.OUTPUT_1_0[14];
      KIMMCar_DW.UnitDelay_DSTATE_i[2] = KIMMCar_B.OUTPUT_1_0[20];
      KIMMCar_DW.UnitDelay_DSTATE_i[3] = KIMMCar_B.OUTPUT_1_0[26];
      KIMMCar_DW.UnitDelay1_1_DSTATE = KIMMCar_B.OUTPUT_1_0[1];
      KIMMCar_DW.UnitDelay1_2_DSTATE = KIMMCar_B.OUTPUT_1_0[3];
      KIMMCar_DW.UnitDelay1_3_DSTATE = KIMMCar_B.OUTPUT_1_0[5];
      KIMMCar_DW.UnitDelay1_4_DSTATE = KIMMCar_B.OUTPUT_1_0[7];
    }
  }

  if (rtmIsMajorTimeStep(KIMMCar_M)) {
    rt_ertODEUpdateContinuousStates(&KIMMCar_M->solverInfo);
    if (!(++KIMMCar_M->Timing.clockTick0)) {
      ++KIMMCar_M->Timing.clockTickH0;
    }

    KIMMCar_M->Timing.t[0] = rtsiGetSolverStopTime(&KIMMCar_M->solverInfo);
    KIMMCar_M->Timing.clockTick1++;
    if (!KIMMCar_M->Timing.clockTick1) {
      KIMMCar_M->Timing.clockTickH1++;
    }
  }
}

void KIMMCar_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_KIMMCar_T *_rtXdot;
  char *msg;
  real_T tmp_0[216];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[55];
  boolean_T tmp;
  _rtXdot = ((XDot_KIMMCar_T *) KIMMCar_M->derivs);
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
    [1] = ((KIMMCar_DW.INPUT_7_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter1outputFiltered_2546865205_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
    [1] = ((KIMMCar_DW.INPUT_8_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter2outputFiltered_362709988_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
    [1] = ((KIMMCar_DW.INPUT_9_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter3outputFiltered_687778388_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
    [1] = ((KIMMCar_DW.INPUT_14_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
            [0]) * 100.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter2outputFiltered_1569689471_0
           [1]) * 100.0;
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
    [1] = ((KIMMCar_DW.INPUT_10_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter4outputFiltered_2819566015_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
    [1] = ((KIMMCar_DW.INPUT_11_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter5outputFiltered_2507079695_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
    [1] = ((KIMMCar_DW.INPUT_12_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSimulink_PS_Converter6outputFiltered_3536812767_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
    [1] = ((KIMMCar_DW.INPUT_13_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
            [0]) * 100.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_FrontSteering_Wheel_to_Wheel_AngleSimulink_PS_Converter1outputFiltered_4021244783_0
           [1]) * 100.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
    [1] = ((KIMMCar_DW.INPUT_15_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter1outputFiltered_1626318543_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
    [1] = ((KIMMCar_DW.INPUT_16_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter2outputFiltered_659545119_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
    [1] = ((KIMMCar_DW.INPUT_17_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter3outputFiltered_439350703_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
    [1] = ((KIMMCar_DW.INPUT_21_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter7outputFiltered_335245985_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
    [1] = ((KIMMCar_DW.INPUT_18_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter4outputFiltered_2558485118_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
    [1] = ((KIMMCar_DW.INPUT_19_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter5outputFiltered_2770291662_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
    [1] = ((KIMMCar_DW.INPUT_20_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter6outputFiltered_781933329_0
           [1]) * 1000.0;
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
    [0] =
    KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
    [1];
  _rtXdot->KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
    [1] = ((KIMMCar_DW.INPUT_22_1_1_Discrete -
            KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
            [0]) * 1000.0 - 2.0 *
           KIMMCar_X.KIMMCarVehicleSuspension_RearSimulink_PS_Converter8outputFiltered_1415252081_0
           [1]) * 1000.0;
  simulationData = (NeslSimulationData *)KIMMCar_DW.STATE_1_SimData;
  time = KIMMCar_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 29;
  simulationData->mData->mContStates.mX =
    &KIMMCar_X.KIMMCarVehicleCamera_FramesCartesian_JointPxp[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &KIMMCar_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &KIMMCar_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(KIMMCar_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&KIMMCar_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&KIMMCar_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = KIMMCar_B.INPUT_3_1_1[0];
  tmp_0[1] = KIMMCar_B.INPUT_3_1_1[1];
  tmp_0[2] = KIMMCar_B.INPUT_3_1_1[2];
  tmp_0[3] = KIMMCar_B.INPUT_3_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = KIMMCar_B.INPUT_4_1_1[0];
  tmp_0[5] = KIMMCar_B.INPUT_4_1_1[1];
  tmp_0[6] = KIMMCar_B.INPUT_4_1_1[2];
  tmp_0[7] = KIMMCar_B.INPUT_4_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = KIMMCar_B.INPUT_5_1_1[0];
  tmp_0[9] = KIMMCar_B.INPUT_5_1_1[1];
  tmp_0[10] = KIMMCar_B.INPUT_5_1_1[2];
  tmp_0[11] = KIMMCar_B.INPUT_5_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = KIMMCar_B.INPUT_6_1_1[0];
  tmp_0[13] = KIMMCar_B.INPUT_6_1_1[1];
  tmp_0[14] = KIMMCar_B.INPUT_6_1_1[2];
  tmp_0[15] = KIMMCar_B.INPUT_6_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = KIMMCar_B.INPUT_7_1_1[0];
  tmp_0[17] = KIMMCar_B.INPUT_7_1_1[1];
  tmp_0[18] = KIMMCar_B.INPUT_7_1_1[2];
  tmp_0[19] = KIMMCar_B.INPUT_7_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = KIMMCar_B.INPUT_8_1_1[0];
  tmp_0[21] = KIMMCar_B.INPUT_8_1_1[1];
  tmp_0[22] = KIMMCar_B.INPUT_8_1_1[2];
  tmp_0[23] = KIMMCar_B.INPUT_8_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = KIMMCar_B.INPUT_9_1_1[0];
  tmp_0[25] = KIMMCar_B.INPUT_9_1_1[1];
  tmp_0[26] = KIMMCar_B.INPUT_9_1_1[2];
  tmp_0[27] = KIMMCar_B.INPUT_9_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = KIMMCar_B.INPUT_14_1_1[0];
  tmp_0[29] = KIMMCar_B.INPUT_14_1_1[1];
  tmp_0[30] = KIMMCar_B.INPUT_14_1_1[2];
  tmp_0[31] = KIMMCar_B.INPUT_14_1_1[3];
  tmp_1[8] = 32;
  tmp_0[32] = KIMMCar_B.INPUT_10_1_1[0];
  tmp_0[33] = KIMMCar_B.INPUT_10_1_1[1];
  tmp_0[34] = KIMMCar_B.INPUT_10_1_1[2];
  tmp_0[35] = KIMMCar_B.INPUT_10_1_1[3];
  tmp_1[9] = 36;
  tmp_0[36] = KIMMCar_B.INPUT_11_1_1[0];
  tmp_0[37] = KIMMCar_B.INPUT_11_1_1[1];
  tmp_0[38] = KIMMCar_B.INPUT_11_1_1[2];
  tmp_0[39] = KIMMCar_B.INPUT_11_1_1[3];
  tmp_1[10] = 40;
  tmp_0[40] = KIMMCar_B.INPUT_12_1_1[0];
  tmp_0[41] = KIMMCar_B.INPUT_12_1_1[1];
  tmp_0[42] = KIMMCar_B.INPUT_12_1_1[2];
  tmp_0[43] = KIMMCar_B.INPUT_12_1_1[3];
  tmp_1[11] = 44;
  tmp_0[44] = KIMMCar_B.INPUT_13_1_1[0];
  tmp_0[45] = KIMMCar_B.INPUT_13_1_1[1];
  tmp_0[46] = KIMMCar_B.INPUT_13_1_1[2];
  tmp_0[47] = KIMMCar_B.INPUT_13_1_1[3];
  tmp_1[12] = 48;
  tmp_0[48] = KIMMCar_B.INPUT_15_1_1[0];
  tmp_0[49] = KIMMCar_B.INPUT_15_1_1[1];
  tmp_0[50] = KIMMCar_B.INPUT_15_1_1[2];
  tmp_0[51] = KIMMCar_B.INPUT_15_1_1[3];
  tmp_1[13] = 52;
  tmp_0[52] = KIMMCar_B.INPUT_16_1_1[0];
  tmp_0[53] = KIMMCar_B.INPUT_16_1_1[1];
  tmp_0[54] = KIMMCar_B.INPUT_16_1_1[2];
  tmp_0[55] = KIMMCar_B.INPUT_16_1_1[3];
  tmp_1[14] = 56;
  tmp_0[56] = KIMMCar_B.INPUT_17_1_1[0];
  tmp_0[57] = KIMMCar_B.INPUT_17_1_1[1];
  tmp_0[58] = KIMMCar_B.INPUT_17_1_1[2];
  tmp_0[59] = KIMMCar_B.INPUT_17_1_1[3];
  tmp_1[15] = 60;
  tmp_0[60] = KIMMCar_B.INPUT_21_1_1[0];
  tmp_0[61] = KIMMCar_B.INPUT_21_1_1[1];
  tmp_0[62] = KIMMCar_B.INPUT_21_1_1[2];
  tmp_0[63] = KIMMCar_B.INPUT_21_1_1[3];
  tmp_1[16] = 64;
  tmp_0[64] = KIMMCar_B.INPUT_18_1_1[0];
  tmp_0[65] = KIMMCar_B.INPUT_18_1_1[1];
  tmp_0[66] = KIMMCar_B.INPUT_18_1_1[2];
  tmp_0[67] = KIMMCar_B.INPUT_18_1_1[3];
  tmp_1[17] = 68;
  tmp_0[68] = KIMMCar_B.INPUT_19_1_1[0];
  tmp_0[69] = KIMMCar_B.INPUT_19_1_1[1];
  tmp_0[70] = KIMMCar_B.INPUT_19_1_1[2];
  tmp_0[71] = KIMMCar_B.INPUT_19_1_1[3];
  tmp_1[18] = 72;
  tmp_0[72] = KIMMCar_B.INPUT_20_1_1[0];
  tmp_0[73] = KIMMCar_B.INPUT_20_1_1[1];
  tmp_0[74] = KIMMCar_B.INPUT_20_1_1[2];
  tmp_0[75] = KIMMCar_B.INPUT_20_1_1[3];
  tmp_1[19] = 76;
  tmp_0[76] = KIMMCar_B.INPUT_22_1_1[0];
  tmp_0[77] = KIMMCar_B.INPUT_22_1_1[1];
  tmp_0[78] = KIMMCar_B.INPUT_22_1_1[2];
  tmp_0[79] = KIMMCar_B.INPUT_22_1_1[3];
  tmp_1[20] = 80;
  tmp_0[80] = KIMMCar_B.INPUT_23_1_1[0];
  tmp_0[81] = KIMMCar_B.INPUT_23_1_1[1];
  tmp_0[82] = KIMMCar_B.INPUT_23_1_1[2];
  tmp_0[83] = KIMMCar_B.INPUT_23_1_1[3];
  tmp_1[21] = 84;
  tmp_0[84] = KIMMCar_B.INPUT_24_1_1[0];
  tmp_0[85] = KIMMCar_B.INPUT_24_1_1[1];
  tmp_0[86] = KIMMCar_B.INPUT_24_1_1[2];
  tmp_0[87] = KIMMCar_B.INPUT_24_1_1[3];
  tmp_1[22] = 88;
  tmp_0[88] = KIMMCar_B.INPUT_25_1_1[0];
  tmp_0[89] = KIMMCar_B.INPUT_25_1_1[1];
  tmp_0[90] = KIMMCar_B.INPUT_25_1_1[2];
  tmp_0[91] = KIMMCar_B.INPUT_25_1_1[3];
  tmp_1[23] = 92;
  tmp_0[92] = KIMMCar_B.INPUT_28_1_1[0];
  tmp_0[93] = KIMMCar_B.INPUT_28_1_1[1];
  tmp_0[94] = KIMMCar_B.INPUT_28_1_1[2];
  tmp_0[95] = KIMMCar_B.INPUT_28_1_1[3];
  tmp_1[24] = 96;
  tmp_0[96] = KIMMCar_B.INPUT_26_1_1[0];
  tmp_0[97] = KIMMCar_B.INPUT_26_1_1[1];
  tmp_0[98] = KIMMCar_B.INPUT_26_1_1[2];
  tmp_0[99] = KIMMCar_B.INPUT_26_1_1[3];
  tmp_1[25] = 100;
  tmp_0[100] = KIMMCar_B.INPUT_27_1_1[0];
  tmp_0[101] = KIMMCar_B.INPUT_27_1_1[1];
  tmp_0[102] = KIMMCar_B.INPUT_27_1_1[2];
  tmp_0[103] = KIMMCar_B.INPUT_27_1_1[3];
  tmp_1[26] = 104;
  tmp_0[104] = KIMMCar_B.INPUT_31_1_1[0];
  tmp_0[105] = KIMMCar_B.INPUT_31_1_1[1];
  tmp_0[106] = KIMMCar_B.INPUT_31_1_1[2];
  tmp_0[107] = KIMMCar_B.INPUT_31_1_1[3];
  tmp_1[27] = 108;
  tmp_0[108] = KIMMCar_B.INPUT_32_1_1[0];
  tmp_0[109] = KIMMCar_B.INPUT_32_1_1[1];
  tmp_0[110] = KIMMCar_B.INPUT_32_1_1[2];
  tmp_0[111] = KIMMCar_B.INPUT_32_1_1[3];
  tmp_1[28] = 112;
  tmp_0[112] = KIMMCar_B.INPUT_33_1_1[0];
  tmp_0[113] = KIMMCar_B.INPUT_33_1_1[1];
  tmp_0[114] = KIMMCar_B.INPUT_33_1_1[2];
  tmp_0[115] = KIMMCar_B.INPUT_33_1_1[3];
  tmp_1[29] = 116;
  tmp_0[116] = KIMMCar_B.INPUT_36_1_1[0];
  tmp_0[117] = KIMMCar_B.INPUT_36_1_1[1];
  tmp_0[118] = KIMMCar_B.INPUT_36_1_1[2];
  tmp_0[119] = KIMMCar_B.INPUT_36_1_1[3];
  tmp_1[30] = 120;
  tmp_0[120] = KIMMCar_B.INPUT_34_1_1[0];
  tmp_0[121] = KIMMCar_B.INPUT_34_1_1[1];
  tmp_0[122] = KIMMCar_B.INPUT_34_1_1[2];
  tmp_0[123] = KIMMCar_B.INPUT_34_1_1[3];
  tmp_1[31] = 124;
  tmp_0[124] = KIMMCar_B.INPUT_35_1_1[0];
  tmp_0[125] = KIMMCar_B.INPUT_35_1_1[1];
  tmp_0[126] = KIMMCar_B.INPUT_35_1_1[2];
  tmp_0[127] = KIMMCar_B.INPUT_35_1_1[3];
  tmp_1[32] = 128;
  tmp_0[128] = KIMMCar_B.INPUT_39_1_1[0];
  tmp_0[129] = KIMMCar_B.INPUT_39_1_1[1];
  tmp_0[130] = KIMMCar_B.INPUT_39_1_1[2];
  tmp_0[131] = KIMMCar_B.INPUT_39_1_1[3];
  tmp_1[33] = 132;
  tmp_0[132] = KIMMCar_B.INPUT_40_1_1[0];
  tmp_0[133] = KIMMCar_B.INPUT_40_1_1[1];
  tmp_0[134] = KIMMCar_B.INPUT_40_1_1[2];
  tmp_0[135] = KIMMCar_B.INPUT_40_1_1[3];
  tmp_1[34] = 136;
  tmp_0[136] = KIMMCar_B.INPUT_41_1_1[0];
  tmp_0[137] = KIMMCar_B.INPUT_41_1_1[1];
  tmp_0[138] = KIMMCar_B.INPUT_41_1_1[2];
  tmp_0[139] = KIMMCar_B.INPUT_41_1_1[3];
  tmp_1[35] = 140;
  tmp_0[140] = KIMMCar_B.INPUT_44_1_1[0];
  tmp_0[141] = KIMMCar_B.INPUT_44_1_1[1];
  tmp_0[142] = KIMMCar_B.INPUT_44_1_1[2];
  tmp_0[143] = KIMMCar_B.INPUT_44_1_1[3];
  tmp_1[36] = 144;
  tmp_0[144] = KIMMCar_B.INPUT_42_1_1[0];
  tmp_0[145] = KIMMCar_B.INPUT_42_1_1[1];
  tmp_0[146] = KIMMCar_B.INPUT_42_1_1[2];
  tmp_0[147] = KIMMCar_B.INPUT_42_1_1[3];
  tmp_1[37] = 148;
  tmp_0[148] = KIMMCar_B.INPUT_43_1_1[0];
  tmp_0[149] = KIMMCar_B.INPUT_43_1_1[1];
  tmp_0[150] = KIMMCar_B.INPUT_43_1_1[2];
  tmp_0[151] = KIMMCar_B.INPUT_43_1_1[3];
  tmp_1[38] = 152;
  tmp_0[152] = KIMMCar_B.INPUT_47_1_1[0];
  tmp_0[153] = KIMMCar_B.INPUT_47_1_1[1];
  tmp_0[154] = KIMMCar_B.INPUT_47_1_1[2];
  tmp_0[155] = KIMMCar_B.INPUT_47_1_1[3];
  tmp_1[39] = 156;
  tmp_0[156] = KIMMCar_B.INPUT_48_1_1[0];
  tmp_0[157] = KIMMCar_B.INPUT_48_1_1[1];
  tmp_0[158] = KIMMCar_B.INPUT_48_1_1[2];
  tmp_0[159] = KIMMCar_B.INPUT_48_1_1[3];
  tmp_1[40] = 160;
  tmp_0[160] = KIMMCar_B.INPUT_49_1_1[0];
  tmp_0[161] = KIMMCar_B.INPUT_49_1_1[1];
  tmp_0[162] = KIMMCar_B.INPUT_49_1_1[2];
  tmp_0[163] = KIMMCar_B.INPUT_49_1_1[3];
  tmp_1[41] = 164;
  tmp_0[164] = KIMMCar_B.INPUT_52_1_1[0];
  tmp_0[165] = KIMMCar_B.INPUT_52_1_1[1];
  tmp_0[166] = KIMMCar_B.INPUT_52_1_1[2];
  tmp_0[167] = KIMMCar_B.INPUT_52_1_1[3];
  tmp_1[42] = 168;
  tmp_0[168] = KIMMCar_B.INPUT_50_1_1[0];
  tmp_0[169] = KIMMCar_B.INPUT_50_1_1[1];
  tmp_0[170] = KIMMCar_B.INPUT_50_1_1[2];
  tmp_0[171] = KIMMCar_B.INPUT_50_1_1[3];
  tmp_1[43] = 172;
  tmp_0[172] = KIMMCar_B.INPUT_51_1_1[0];
  tmp_0[173] = KIMMCar_B.INPUT_51_1_1[1];
  tmp_0[174] = KIMMCar_B.INPUT_51_1_1[2];
  tmp_0[175] = KIMMCar_B.INPUT_51_1_1[3];
  tmp_1[44] = 176;
  tmp_0[176] = KIMMCar_B.INPUT_1_1_1[0];
  tmp_0[177] = KIMMCar_B.INPUT_1_1_1[1];
  tmp_0[178] = KIMMCar_B.INPUT_1_1_1[2];
  tmp_0[179] = KIMMCar_B.INPUT_1_1_1[3];
  tmp_1[45] = 180;
  tmp_0[180] = KIMMCar_B.INPUT_2_1_1[0];
  tmp_0[181] = KIMMCar_B.INPUT_2_1_1[1];
  tmp_0[182] = KIMMCar_B.INPUT_2_1_1[2];
  tmp_0[183] = KIMMCar_B.INPUT_2_1_1[3];
  tmp_1[46] = 184;
  tmp_0[184] = KIMMCar_B.INPUT_29_1_1[0];
  tmp_0[185] = KIMMCar_B.INPUT_29_1_1[1];
  tmp_0[186] = KIMMCar_B.INPUT_29_1_1[2];
  tmp_0[187] = KIMMCar_B.INPUT_29_1_1[3];
  tmp_1[47] = 188;
  tmp_0[188] = KIMMCar_B.INPUT_30_1_1[0];
  tmp_0[189] = KIMMCar_B.INPUT_30_1_1[1];
  tmp_0[190] = KIMMCar_B.INPUT_30_1_1[2];
  tmp_0[191] = KIMMCar_B.INPUT_30_1_1[3];
  tmp_1[48] = 192;
  tmp_0[192] = KIMMCar_B.INPUT_37_1_1[0];
  tmp_0[193] = KIMMCar_B.INPUT_37_1_1[1];
  tmp_0[194] = KIMMCar_B.INPUT_37_1_1[2];
  tmp_0[195] = KIMMCar_B.INPUT_37_1_1[3];
  tmp_1[49] = 196;
  tmp_0[196] = KIMMCar_B.INPUT_38_1_1[0];
  tmp_0[197] = KIMMCar_B.INPUT_38_1_1[1];
  tmp_0[198] = KIMMCar_B.INPUT_38_1_1[2];
  tmp_0[199] = KIMMCar_B.INPUT_38_1_1[3];
  tmp_1[50] = 200;
  tmp_0[200] = KIMMCar_B.INPUT_45_1_1[0];
  tmp_0[201] = KIMMCar_B.INPUT_45_1_1[1];
  tmp_0[202] = KIMMCar_B.INPUT_45_1_1[2];
  tmp_0[203] = KIMMCar_B.INPUT_45_1_1[3];
  tmp_1[51] = 204;
  tmp_0[204] = KIMMCar_B.INPUT_46_1_1[0];
  tmp_0[205] = KIMMCar_B.INPUT_46_1_1[1];
  tmp_0[206] = KIMMCar_B.INPUT_46_1_1[2];
  tmp_0[207] = KIMMCar_B.INPUT_46_1_1[3];
  tmp_1[52] = 208;
  tmp_0[208] = KIMMCar_B.INPUT_53_1_1[0];
  tmp_0[209] = KIMMCar_B.INPUT_53_1_1[1];
  tmp_0[210] = KIMMCar_B.INPUT_53_1_1[2];
  tmp_0[211] = KIMMCar_B.INPUT_53_1_1[3];
  tmp_1[53] = 212;
  tmp_0[212] = KIMMCar_B.INPUT_54_1_1[0];
  tmp_0[213] = KIMMCar_B.INPUT_54_1_1[1];
  tmp_0[214] = KIMMCar_B.INPUT_54_1_1[2];
  tmp_0[215] = KIMMCar_B.INPUT_54_1_1[3];
  tmp_1[54] = 216;
  simulationData->mData->mInputValues.mN = 216;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 55;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 29;
  simulationData->mData->mDx.mX =
    &_rtXdot->KIMMCarVehicleCamera_FramesCartesian_JointPxp[0];
  diagnosticManager = (NeuDiagnosticManager *)KIMMCar_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)KIMMCar_DW.STATE_1_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(KIMMCar_M, msg);
    }
  }
}

void KIMMCar_step2(void)
{
}

void KIMMCar_initialize(void)
{
  rt_InitInfAndNaN(sizeof(real_T));
  (void) memset((void *)KIMMCar_M, 0,
                sizeof(RT_MODEL_KIMMCar_T));
  (KIMMCar_M)->Timing.TaskCounters.cLimit[0] = 1;
  (KIMMCar_M)->Timing.TaskCounters.cLimit[1] = 1;
  (KIMMCar_M)->Timing.TaskCounters.cLimit[2] = 2;

  {
    rtsiSetSimTimeStepPtr(&KIMMCar_M->solverInfo, &KIMMCar_M->Timing.simTimeStep);
    rtsiSetTPtr(&KIMMCar_M->solverInfo, &rtmGetTPtr(KIMMCar_M));
    rtsiSetStepSizePtr(&KIMMCar_M->solverInfo, &KIMMCar_M->Timing.stepSize0);
    rtsiSetdXPtr(&KIMMCar_M->solverInfo, &KIMMCar_M->derivs);
    rtsiSetContStatesPtr(&KIMMCar_M->solverInfo, (real_T **)
                         &KIMMCar_M->contStates);
    rtsiSetNumContStatesPtr(&KIMMCar_M->solverInfo,
      &KIMMCar_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&KIMMCar_M->solverInfo,
      &KIMMCar_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&KIMMCar_M->solverInfo,
      &KIMMCar_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&KIMMCar_M->solverInfo,
      &KIMMCar_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&KIMMCar_M->solverInfo, (boolean_T**)
      &KIMMCar_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&KIMMCar_M->solverInfo, (&rtmGetErrorStatus(KIMMCar_M)));
    rtsiSetRTModelPtr(&KIMMCar_M->solverInfo, KIMMCar_M);
  }

  rtsiSetSimTimeStep(&KIMMCar_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&KIMMCar_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&KIMMCar_M->solverInfo, false);
  KIMMCar_M->intgData.deltaY= KIMMCar_M->OdeDeltaY;
  KIMMCar_M->intgData.f[0] = KIMMCar_M->odeF[0];
  KIMMCar_M->intgData.f[1] = KIMMCar_M->odeF[1];
  KIMMCar_M->intgData.f[2] = KIMMCar_M->odeF[2];
  KIMMCar_M->intgData.f[3] = KIMMCar_M->odeF[3];
  KIMMCar_M->intgData.f[4] = KIMMCar_M->odeF[4];
  KIMMCar_M->intgData.f[5] = KIMMCar_M->odeF[5];
  KIMMCar_M->intgData.f[6] = KIMMCar_M->odeF[6];
  KIMMCar_M->intgData.f[7] = KIMMCar_M->odeF[7];
  KIMMCar_M->intgData.f[8] = KIMMCar_M->odeF[8];
  KIMMCar_M->intgData.f[9] = KIMMCar_M->odeF[9];
  KIMMCar_M->intgData.f[10] = KIMMCar_M->odeF[10];
  KIMMCar_M->intgData.f[11] = KIMMCar_M->odeF[11];
  KIMMCar_M->intgData.f[12] = KIMMCar_M->odeF[12];
  KIMMCar_M->intgData.x0 = KIMMCar_M->odeX0;
  KIMMCar_M->contStates = ((X_KIMMCar_T *) &KIMMCar_X);
  KIMMCar_M->contStateDisabled = ((XDis_KIMMCar_T *) &KIMMCar_XDis);
  KIMMCar_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&KIMMCar_M->solverInfo, (void *)&KIMMCar_M->intgData);
  rtsiSetSolverName(&KIMMCar_M->solverInfo,"ode8");
  rtmSetTPtr(KIMMCar_M, &KIMMCar_M->Timing.tArray[0]);
  KIMMCar_M->Timing.stepSize0 = 0.0005;
  (void) memset(((void *) &KIMMCar_B), 0,
                sizeof(B_KIMMCar_T));

  {
    (void) memset((void *)&KIMMCar_X, 0,
                  sizeof(X_KIMMCar_T));
  }

  {
    (void) memset((void *)&KIMMCar_XDis, 0,
                  sizeof(XDis_KIMMCar_T));
  }

  (void) memset((void *)&KIMMCar_DW, 0,
                sizeof(DW_KIMMCar_T));
  (void)memset(&KIMMCar_U, 0, sizeof(ExtU_KIMMCar_T));
  (void)memset(&KIMMCar_Y, 0, sizeof(ExtY_KIMMCar_T));

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeslRtpManager *manager;
    NeslRtpManager *manager_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    char *msg;
    char *msg_0;
    char *msg_1;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp;
    manager_0 = nesl_lease_rtp_manager(
      "KIMMCar/Vehicle/World/Solver Configuration1_1", 0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      KIMMCar_ff62ad8f_1_gateway();
      manager = nesl_lease_rtp_manager(
        "KIMMCar/Vehicle/World/Solver Configuration1_1", 0);
    }

    KIMMCar_DW.RTP_1_RtpManager = (void *)manager;
    KIMMCar_DW.RTP_1_SetParametersNeeded = true;
    tmp_0 = nesl_lease_simulator("KIMMCar/Vehicle/World/Solver Configuration1_1",
      0, 0);
    KIMMCar_DW.STATE_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(KIMMCar_DW.STATE_1_Simulator);
    if (tmp) {
      KIMMCar_ff62ad8f_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "KIMMCar/Vehicle/World/Solver Configuration1_1", 0, 0);
      KIMMCar_DW.STATE_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    KIMMCar_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    KIMMCar_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 7.09105085E+8;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.0005;
    modelParameters.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters.mIsUsingODEN = tmp;
    tmp = fmu_restoreSimScapeInitialState();
    modelParameters.mLoadInitialState = tmp;
    tmp = fmu_restoreSimScapeInitialState();
    modelParameters.mUseSimState = tmp;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)KIMMCar_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      KIMMCar_DW.STATE_1_Simulator, &modelParameters, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(KIMMCar_M, msg);
      }
    }

    tmp_0 = nesl_lease_simulator("KIMMCar/Vehicle/World/Solver Configuration1_1",
      1, 0);
    KIMMCar_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(KIMMCar_DW.OUTPUT_1_0_Simulator);
    if (tmp) {
      KIMMCar_ff62ad8f_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "KIMMCar/Vehicle/World/Solver Configuration1_1", 1, 0);
      KIMMCar_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    KIMMCar_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    KIMMCar_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 7.09105085E+8;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.0005;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_0.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_0.mIsUsingODEN = tmp;
    tmp = fmu_restoreSimScapeInitialState();
    modelParameters_0.mLoadInitialState = tmp;
    tmp = fmu_restoreSimScapeInitialState();
    modelParameters_0.mUseSimState = tmp;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)KIMMCar_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      KIMMCar_DW.OUTPUT_1_0_Simulator, &modelParameters_0, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(KIMMCar_M, msg_0);
      }
    }

    tmp_0 = nesl_lease_simulator("KIMMCar/Vehicle/World/Solver Configuration1_1",
      1, 1);
    KIMMCar_DW.OUTPUT_1_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(KIMMCar_DW.OUTPUT_1_1_Simulator);
    if (tmp) {
      KIMMCar_ff62ad8f_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "KIMMCar/Vehicle/World/Solver Configuration1_1", 1, 1);
      KIMMCar_DW.OUTPUT_1_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    KIMMCar_DW.OUTPUT_1_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    KIMMCar_DW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_1.mRTWModifiedTimeStamp = 7.09105085E+8;
    modelParameters_1.mUseModelRefSolver = false;
    modelParameters_1.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 0.0005;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_1.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_1.mIsUsingODEN = tmp;
    tmp = fmu_restoreSimScapeInitialState();
    modelParameters_1.mLoadInitialState = tmp;
    tmp = fmu_restoreSimScapeInitialState();
    modelParameters_1.mUseSimState = tmp;
    modelParameters_1.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)KIMMCar_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      KIMMCar_DW.OUTPUT_1_1_Simulator, &modelParameters_1, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(KIMMCar_M));
      if (tmp) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(KIMMCar_M, msg_1);
      }
    }
  }

  KIMMCar_DW.UnitDelay_DSTATE = KIMMCar_P.UnitDelay_InitialCondition;
  KIMMCar_DW.UnitDelay1_DSTATE = KIMMCar_P.UnitDelay1_InitialCondition;
  KIMMCar_DW.UnitDelay_DSTATE_c = KIMMCar_P.UnitDelay_InitialCondition_a;
  KIMMCar_DW.UnitDelay1_DSTATE_e = KIMMCar_P.UnitDelay1_InitialCondition_f;
  KIMMCar_DW.DiscreteTransferFcn1_states =
    KIMMCar_P.DiscreteTransferFcn1_InitialStates;
  KIMMCar_DW.DiscreteTransferFcn2_states =
    KIMMCar_P.DiscreteTransferFcn2_InitialStates;
  KIMMCar_DW.DiscreteTransferFcn3_states =
    KIMMCar_P.DiscreteTransferFcn3_InitialStates;
  KIMMCar_DW.DiscreteTransferFcn1_states_e =
    KIMMCar_P.DiscreteTransferFcn1_InitialStates_b;
  KIMMCar_DW.DiscreteTransferFcn2_states_o =
    KIMMCar_P.DiscreteTransferFcn2_InitialStates_o;
  KIMMCar_DW.DiscreteTransferFcn3_states_k =
    KIMMCar_P.DiscreteTransferFcn3_InitialStates_k;
  KIMMCar_DW.DiscreteTransferFcn1_states_i =
    KIMMCar_P.DiscreteTransferFcn1_InitialStates_f;
  KIMMCar_DW.DiscreteTransferFcn2_states_b =
    KIMMCar_P.DiscreteTransferFcn2_InitialStates_g;
  KIMMCar_DW.DiscreteTransferFcn3_states_n =
    KIMMCar_P.DiscreteTransferFcn3_InitialStates_kk;
  KIMMCar_DW.DiscreteTransferFcn1_states_g =
    KIMMCar_P.DiscreteTransferFcn1_InitialStates_l;
  KIMMCar_DW.DiscreteTransferFcn2_states_j =
    KIMMCar_P.DiscreteTransferFcn2_InitialStates_p;
  KIMMCar_DW.DiscreteTransferFcn3_states_n1 =
    KIMMCar_P.DiscreteTransferFcn3_InitialStates_e;
  KIMMCar_DW.UnitDelay_DSTATE_f = KIMMCar_P.UnitDelay_InitialCondition_i;
  KIMMCar_DW.UnitDelay1_1_DSTATE = KIMMCar_P.UnitDelay1_1_InitialCondition;
  KIMMCar_DW.UnitDelay1_2_DSTATE = KIMMCar_P.UnitDelay1_2_InitialCondition;
  KIMMCar_DW.UnitDelay1_3_DSTATE = KIMMCar_P.UnitDelay1_3_InitialCondition;
  KIMMCar_DW.UnitDelay1_4_DSTATE = KIMMCar_P.UnitDelay1_4_InitialCondition;
  KIMMCar_DW.PrevY = KIMMCar_P.Brake_Rate_Limiter_IC;
  KIMMCar_DW.PrevY_o = KIMMCar_P.RateLimiter_IC;
  KIMMCar_DW.travelDirection = 0.0;
  KIMMCar_DW.UnitDelay_DSTATE_i[0] = KIMMCar_P.UnitDelay_InitialCondition_f;
  KIMMCar_DW.absScale[0] = 1.0;
  KIMMCar_DW.zeroGuard[0] = false;
  KIMMCar_DW.UnitDelay_DSTATE_i[1] = KIMMCar_P.UnitDelay_InitialCondition_f;
  KIMMCar_DW.absScale[1] = 1.0;
  KIMMCar_DW.zeroGuard[1] = false;
  KIMMCar_DW.UnitDelay_DSTATE_i[2] = KIMMCar_P.UnitDelay_InitialCondition_f;
  KIMMCar_DW.absScale[2] = 1.0;
  KIMMCar_DW.zeroGuard[2] = false;
  KIMMCar_DW.UnitDelay_DSTATE_i[3] = KIMMCar_P.UnitDelay_InitialCondition_f;
  KIMMCar_DW.absScale[3] = 1.0;
  KIMMCar_DW.zeroGuard[3] = false;
  KIMMCar_DW.integratorState = 0.0;
  KIMMCar_DW.filteredVelocity = 0.0;
  KIMMCar_DW.signGuardActive = false;
}

void KIMMCar_terminate(void)
{
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    KIMMCar_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)KIMMCar_DW.STATE_1_SimData);
  nesl_erase_simulator("KIMMCar/Vehicle/World/Solver Configuration1_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    KIMMCar_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    KIMMCar_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("KIMMCar/Vehicle/World/Solver Configuration1_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    KIMMCar_DW.OUTPUT_1_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    KIMMCar_DW.OUTPUT_1_1_SimData);
  nesl_erase_simulator("KIMMCar/Vehicle/World/Solver Configuration1_1");
  nesl_destroy_registry();
}
