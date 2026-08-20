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
#include "sm_CTarget.h"

static void setTargets_108(const RuntimeDerivedValuesBundle *rtdv, real_T
  *values, double *auxData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) rtdvi;
  (void) auxData;
  values[0] = rtdvd[260];
}

void KIMMCar_ff62ad8f_49_setTargets(const RuntimeDerivedValuesBundle *rtdv,
  CTarget *targets)
{
  setTargets_108(rtdv, sm_core_SmRealVector_nonConstValues(&targets[108].mValue),
                 targets[108].mAuxiliaryTargetData);
}

void KIMMCar_ff62ad8f_49_resetAsmStateVector(const void *mech, double *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = 1.0;
  state[4] = xx[0];
  state[5] = xx[0];
  state[6] = xx[0];
  state[7] = xx[0];
  state[8] = xx[0];
  state[9] = xx[0];
  state[10] = xx[0];
  state[11] = xx[0];
  state[12] = xx[0];
  state[13] = xx[0];
  state[14] = xx[0];
  state[15] = xx[0];
  state[16] = xx[0];
  state[17] = xx[0];
  state[18] = xx[0];
  state[19] = xx[0];
  state[20] = xx[0];
  state[21] = xx[0];
  state[22] = xx[0];
  state[23] = xx[0];
  state[24] = xx[0];
  state[25] = xx[0];
  state[26] = xx[0];
  state[27] = xx[0];
  state[28] = xx[0];
  state[29] = xx[0];
  state[30] = xx[0];
  state[31] = xx[0];
  state[32] = xx[0];
  state[33] = xx[0];
  state[34] = xx[0];
  state[35] = xx[0];
  state[36] = xx[0];
  state[37] = xx[0];
  state[38] = xx[0];
  state[39] = xx[0];
  state[40] = xx[0];
  state[41] = xx[0];
  state[42] = xx[0];
  state[43] = xx[0];
  state[44] = xx[0];
  state[45] = xx[0];
  state[46] = xx[0];
  state[47] = xx[0];
  state[48] = xx[0];
  state[49] = xx[0];
  state[50] = xx[0];
  state[51] = xx[0];
  state[52] = xx[0];
  state[53] = xx[0];
  state[54] = xx[0];
  state[55] = xx[0];
  state[56] = xx[0];
  state[57] = xx[0];
  state[58] = xx[0];
  state[59] = xx[0];
  state[60] = xx[0];
  state[61] = xx[0];
  state[62] = xx[0];
  state[63] = xx[0];
  state[64] = xx[0];
  state[65] = xx[0];
  state[66] = xx[0];
  state[67] = xx[0];
  state[68] = xx[0];
  state[69] = xx[0];
  state[70] = xx[0];
  state[71] = xx[0];
  state[72] = xx[0];
  state[73] = xx[0];
  state[74] = xx[0];
  state[75] = xx[0];
  state[76] = xx[0];
  state[77] = xx[0];
  state[78] = xx[0];
  state[79] = xx[0];
  state[80] = xx[0];
  state[81] = xx[0];
  state[82] = xx[0];
  state[83] = xx[0];
  state[84] = xx[0];
  state[85] = xx[0];
  state[86] = xx[0];
  state[87] = xx[0];
  state[88] = xx[0];
  state[89] = xx[0];
  state[90] = xx[0];
  state[91] = xx[0];
  state[92] = xx[0];
  state[93] = xx[0];
  state[94] = xx[0];
  state[95] = xx[0];
  state[96] = xx[0];
  state[97] = xx[0];
  state[98] = xx[0];
  state[99] = xx[0];
  state[100] = xx[0];
  state[101] = xx[0];
  state[102] = xx[0];
  state[103] = xx[0];
  state[104] = xx[0];
  state[105] = xx[0];
  state[106] = xx[0];
  state[107] = xx[0];
  state[108] = xx[0];
  state[109] = xx[0];
  state[110] = xx[0];
  state[111] = xx[0];
  state[112] = xx[0];
  state[113] = xx[0];
  state[114] = xx[0];
}

void KIMMCar_ff62ad8f_49_initializeTrackedAngleState(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *modeVector, const double
  *motionData, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
}

void KIMMCar_ff62ad8f_49_computeDiscreteState(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *modeVector, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
}

void KIMMCar_ff62ad8f_49_adjustPosition(const void *mech, const double
  *dofDeltas, double *state)
{
  double xx[11];
  (void) mech;
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  xx[4] = dofDeltas[3];
  xx[5] = dofDeltas[4];
  xx[6] = dofDeltas[5];
  pm_math_Quaternion_compDeriv_ra(xx + 0, xx + 4, xx + 7);
  xx[0] = state[3] + xx[7];
  xx[1] = state[4] + xx[8];
  xx[2] = state[5] + xx[9];
  xx[3] = state[6] + xx[10];
  xx[4] = sqrt(xx[0] * xx[0] + xx[1] * xx[1] + xx[2] * xx[2] + xx[3] * xx[3]);
  xx[5] = 1.0e-64;
  if (xx[5] > xx[4])
    xx[4] = xx[5];
  state[0] = state[0] + dofDeltas[0];
  state[1] = state[1] + dofDeltas[1];
  state[2] = state[2] + dofDeltas[2];
  state[3] = xx[0] / xx[4];
  state[4] = xx[1] / xx[4];
  state[5] = xx[2] / xx[4];
  state[6] = xx[3] / xx[4];
  state[13] = state[13] + dofDeltas[6];
  state[14] = state[14] + dofDeltas[7];
  state[15] = state[15] + dofDeltas[8];
  state[19] = state[19] + dofDeltas[9];
  state[21] = state[21] + dofDeltas[10];
  state[23] = state[23] + dofDeltas[11];
  state[25] = state[25] + dofDeltas[12];
  state[26] = state[26] + dofDeltas[13];
  state[27] = state[27] + dofDeltas[14];
  state[31] = state[31] + dofDeltas[15];
  state[33] = state[33] + dofDeltas[16];
  state[35] = state[35] + dofDeltas[17];
  state[37] = state[37] + dofDeltas[18];
  state[38] = state[38] + dofDeltas[19];
  state[39] = state[39] + dofDeltas[20];
  state[43] = state[43] + dofDeltas[21];
  state[45] = state[45] + dofDeltas[22];
  state[47] = state[47] + dofDeltas[23];
  state[49] = state[49] + dofDeltas[24];
  state[50] = state[50] + dofDeltas[25];
  state[51] = state[51] + dofDeltas[26];
  state[55] = state[55] + dofDeltas[27];
  state[57] = state[57] + dofDeltas[28];
  state[59] = state[59] + dofDeltas[29];
  state[61] = state[61] + dofDeltas[30];
  state[62] = state[62] + dofDeltas[31];
  state[63] = state[63] + dofDeltas[32];
  state[67] = state[67] + dofDeltas[33];
  state[68] = state[68] + dofDeltas[34];
  state[69] = state[69] + dofDeltas[35];
  state[73] = state[73] + dofDeltas[36];
  state[75] = state[75] + dofDeltas[37];
  state[77] = state[77] + dofDeltas[38];
  state[79] = state[79] + dofDeltas[39];
  state[80] = state[80] + dofDeltas[40];
  state[81] = state[81] + dofDeltas[41];
  state[85] = state[85] + dofDeltas[42];
  state[87] = state[87] + dofDeltas[43];
  state[89] = state[89] + dofDeltas[44];
  state[91] = state[91] + dofDeltas[45];
  state[92] = state[92] + dofDeltas[46];
  state[93] = state[93] + dofDeltas[47];
  state[97] = state[97] + dofDeltas[48];
  state[99] = state[99] + dofDeltas[49];
  state[101] = state[101] + dofDeltas[50];
  state[103] = state[103] + dofDeltas[51];
  state[104] = state[104] + dofDeltas[52];
  state[105] = state[105] + dofDeltas[53];
  state[109] = state[109] + dofDeltas[54];
  state[111] = state[111] + dofDeltas[55];
  state[113] = state[113] + dofDeltas[56];
}

static void perturbAsmJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbAsmJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[7] = state[7] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_1(double mag, double *state)
{
  state[1] = state[1] + mag;
}

static void perturbAsmJointPrimitiveState_0_1v(double mag, double *state)
{
  state[1] = state[1] + mag;
  state[8] = state[8] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_2(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbAsmJointPrimitiveState_0_2v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[9] = state[9] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_3(double mag, double *state)
{
  double xx[15];
  xx[0] = 1.0;
  xx[1] = fabs(mag);
  xx[2] = xx[0] / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = 0.0;
  xx[4] = cos(xx[2]);
  xx[5] = sin(2.0 * xx[2]);
  xx[2] = 0.5 * mag;
  xx[6] = sqrt(xx[1] * xx[1] + xx[4] * xx[4] + xx[5] * xx[5]);
  xx[7] = xx[6] == 0.0 ? 0.0 : xx[1] / xx[6];
  xx[8] = sin(xx[2]);
  xx[9] = xx[6] == 0.0 ? 0.0 : xx[4] / xx[6];
  xx[10] = xx[6] == 0.0 ? 0.0 : xx[5] / xx[6];
  xx[11] = xx[1] == xx[3] && xx[4] == xx[3] && xx[5] == xx[3] ? xx[0] : cos(xx[2]);
  xx[12] = xx[7] * xx[8];
  xx[13] = xx[9] * xx[8];
  xx[14] = xx[10] * xx[8];
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 0, xx + 4);
  state[3] = xx[4];
  state[4] = xx[5];
  state[5] = xx[6];
  state[6] = xx[7];
}

static void perturbAsmJointPrimitiveState_0_3v(double mag, double *state)
{
  double xx[15];
  xx[0] = 1.0;
  xx[1] = fabs(mag);
  xx[2] = xx[0] / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = 0.0;
  xx[4] = cos(xx[2]);
  xx[5] = sin(2.0 * xx[2]);
  xx[2] = 0.5 * mag;
  xx[6] = sqrt(xx[1] * xx[1] + xx[4] * xx[4] + xx[5] * xx[5]);
  xx[7] = xx[6] == 0.0 ? 0.0 : xx[1] / xx[6];
  xx[8] = sin(xx[2]);
  xx[9] = xx[6] == 0.0 ? 0.0 : xx[4] / xx[6];
  xx[10] = xx[6] == 0.0 ? 0.0 : xx[5] / xx[6];
  xx[11] = xx[1] == xx[3] && xx[4] == xx[3] && xx[5] == xx[3] ? xx[0] : cos(xx[2]);
  xx[12] = xx[7] * xx[8];
  xx[13] = xx[9] * xx[8];
  xx[14] = xx[10] * xx[8];
  xx[3] = state[3];
  xx[4] = state[4];
  xx[5] = state[5];
  xx[6] = state[6];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 3, xx + 7);
  state[3] = xx[7];
  state[4] = xx[8];
  state[5] = xx[9];
  state[6] = xx[10];
  state[10] = state[10] + 1.2 * mag;
  state[11] = state[11] - xx[2];
  state[12] = state[12] + 0.9 * mag;
}

static void perturbAsmJointPrimitiveState_1_0(double mag, double *state)
{
  state[13] = state[13] + mag;
}

static void perturbAsmJointPrimitiveState_1_0v(double mag, double *state)
{
  state[13] = state[13] + mag;
  state[16] = state[16] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_1_1(double mag, double *state)
{
  state[14] = state[14] + mag;
}

static void perturbAsmJointPrimitiveState_1_1v(double mag, double *state)
{
  state[14] = state[14] + mag;
  state[17] = state[17] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_1_2(double mag, double *state)
{
  state[15] = state[15] + mag;
}

static void perturbAsmJointPrimitiveState_1_2v(double mag, double *state)
{
  state[15] = state[15] + mag;
  state[18] = state[18] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_2_0(double mag, double *state)
{
  state[19] = state[19] + mag;
}

static void perturbAsmJointPrimitiveState_2_0v(double mag, double *state)
{
  state[19] = state[19] + mag;
  state[20] = state[20] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_3_0(double mag, double *state)
{
  state[21] = state[21] + mag;
}

static void perturbAsmJointPrimitiveState_3_0v(double mag, double *state)
{
  state[21] = state[21] + mag;
  state[22] = state[22] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_4_0(double mag, double *state)
{
  state[23] = state[23] + mag;
}

static void perturbAsmJointPrimitiveState_4_0v(double mag, double *state)
{
  state[23] = state[23] + mag;
  state[24] = state[24] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_5_0(double mag, double *state)
{
  state[25] = state[25] + mag;
}

static void perturbAsmJointPrimitiveState_5_0v(double mag, double *state)
{
  state[25] = state[25] + mag;
  state[28] = state[28] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_5_1(double mag, double *state)
{
  state[26] = state[26] + mag;
}

static void perturbAsmJointPrimitiveState_5_1v(double mag, double *state)
{
  state[26] = state[26] + mag;
  state[29] = state[29] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_5_2(double mag, double *state)
{
  state[27] = state[27] + mag;
}

static void perturbAsmJointPrimitiveState_5_2v(double mag, double *state)
{
  state[27] = state[27] + mag;
  state[30] = state[30] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_6_0(double mag, double *state)
{
  state[31] = state[31] + mag;
}

static void perturbAsmJointPrimitiveState_6_0v(double mag, double *state)
{
  state[31] = state[31] + mag;
  state[32] = state[32] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_7_0(double mag, double *state)
{
  state[33] = state[33] + mag;
}

static void perturbAsmJointPrimitiveState_7_0v(double mag, double *state)
{
  state[33] = state[33] + mag;
  state[34] = state[34] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_8_0(double mag, double *state)
{
  state[35] = state[35] + mag;
}

static void perturbAsmJointPrimitiveState_8_0v(double mag, double *state)
{
  state[35] = state[35] + mag;
  state[36] = state[36] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_9_0(double mag, double *state)
{
  state[37] = state[37] + mag;
}

static void perturbAsmJointPrimitiveState_9_0v(double mag, double *state)
{
  state[37] = state[37] + mag;
  state[40] = state[40] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_9_1(double mag, double *state)
{
  state[38] = state[38] + mag;
}

static void perturbAsmJointPrimitiveState_9_1v(double mag, double *state)
{
  state[38] = state[38] + mag;
  state[41] = state[41] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_9_2(double mag, double *state)
{
  state[39] = state[39] + mag;
}

static void perturbAsmJointPrimitiveState_9_2v(double mag, double *state)
{
  state[39] = state[39] + mag;
  state[42] = state[42] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_10_0(double mag, double *state)
{
  state[43] = state[43] + mag;
}

static void perturbAsmJointPrimitiveState_10_0v(double mag, double *state)
{
  state[43] = state[43] + mag;
  state[44] = state[44] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_11_0(double mag, double *state)
{
  state[45] = state[45] + mag;
}

static void perturbAsmJointPrimitiveState_11_0v(double mag, double *state)
{
  state[45] = state[45] + mag;
  state[46] = state[46] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_12_0(double mag, double *state)
{
  state[47] = state[47] + mag;
}

static void perturbAsmJointPrimitiveState_12_0v(double mag, double *state)
{
  state[47] = state[47] + mag;
  state[48] = state[48] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_13_0(double mag, double *state)
{
  state[49] = state[49] + mag;
}

static void perturbAsmJointPrimitiveState_13_0v(double mag, double *state)
{
  state[49] = state[49] + mag;
  state[52] = state[52] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_13_1(double mag, double *state)
{
  state[50] = state[50] + mag;
}

static void perturbAsmJointPrimitiveState_13_1v(double mag, double *state)
{
  state[50] = state[50] + mag;
  state[53] = state[53] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_13_2(double mag, double *state)
{
  state[51] = state[51] + mag;
}

static void perturbAsmJointPrimitiveState_13_2v(double mag, double *state)
{
  state[51] = state[51] + mag;
  state[54] = state[54] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_14_0(double mag, double *state)
{
  state[55] = state[55] + mag;
}

static void perturbAsmJointPrimitiveState_14_0v(double mag, double *state)
{
  state[55] = state[55] + mag;
  state[56] = state[56] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_15_0(double mag, double *state)
{
  state[57] = state[57] + mag;
}

static void perturbAsmJointPrimitiveState_15_0v(double mag, double *state)
{
  state[57] = state[57] + mag;
  state[58] = state[58] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_16_0(double mag, double *state)
{
  state[59] = state[59] + mag;
}

static void perturbAsmJointPrimitiveState_16_0v(double mag, double *state)
{
  state[59] = state[59] + mag;
  state[60] = state[60] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_17_0(double mag, double *state)
{
  state[61] = state[61] + mag;
}

static void perturbAsmJointPrimitiveState_17_0v(double mag, double *state)
{
  state[61] = state[61] + mag;
  state[64] = state[64] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_17_1(double mag, double *state)
{
  state[62] = state[62] + mag;
}

static void perturbAsmJointPrimitiveState_17_1v(double mag, double *state)
{
  state[62] = state[62] + mag;
  state[65] = state[65] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_17_2(double mag, double *state)
{
  state[63] = state[63] + mag;
}

static void perturbAsmJointPrimitiveState_17_2v(double mag, double *state)
{
  state[63] = state[63] + mag;
  state[66] = state[66] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_18_0(double mag, double *state)
{
  state[67] = state[67] + mag;
}

static void perturbAsmJointPrimitiveState_18_0v(double mag, double *state)
{
  state[67] = state[67] + mag;
  state[70] = state[70] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_18_1(double mag, double *state)
{
  state[68] = state[68] + mag;
}

static void perturbAsmJointPrimitiveState_18_1v(double mag, double *state)
{
  state[68] = state[68] + mag;
  state[71] = state[71] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_18_2(double mag, double *state)
{
  state[69] = state[69] + mag;
}

static void perturbAsmJointPrimitiveState_18_2v(double mag, double *state)
{
  state[69] = state[69] + mag;
  state[72] = state[72] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_19_0(double mag, double *state)
{
  state[73] = state[73] + mag;
}

static void perturbAsmJointPrimitiveState_19_0v(double mag, double *state)
{
  state[73] = state[73] + mag;
  state[74] = state[74] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_20_0(double mag, double *state)
{
  state[75] = state[75] + mag;
}

static void perturbAsmJointPrimitiveState_20_0v(double mag, double *state)
{
  state[75] = state[75] + mag;
  state[76] = state[76] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_21_0(double mag, double *state)
{
  state[77] = state[77] + mag;
}

static void perturbAsmJointPrimitiveState_21_0v(double mag, double *state)
{
  state[77] = state[77] + mag;
  state[78] = state[78] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_22_0(double mag, double *state)
{
  state[79] = state[79] + mag;
}

static void perturbAsmJointPrimitiveState_22_0v(double mag, double *state)
{
  state[79] = state[79] + mag;
  state[82] = state[82] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_22_1(double mag, double *state)
{
  state[80] = state[80] + mag;
}

static void perturbAsmJointPrimitiveState_22_1v(double mag, double *state)
{
  state[80] = state[80] + mag;
  state[83] = state[83] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_22_2(double mag, double *state)
{
  state[81] = state[81] + mag;
}

static void perturbAsmJointPrimitiveState_22_2v(double mag, double *state)
{
  state[81] = state[81] + mag;
  state[84] = state[84] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_23_0(double mag, double *state)
{
  state[85] = state[85] + mag;
}

static void perturbAsmJointPrimitiveState_23_0v(double mag, double *state)
{
  state[85] = state[85] + mag;
  state[86] = state[86] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_24_0(double mag, double *state)
{
  state[87] = state[87] + mag;
}

static void perturbAsmJointPrimitiveState_24_0v(double mag, double *state)
{
  state[87] = state[87] + mag;
  state[88] = state[88] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_25_0(double mag, double *state)
{
  state[89] = state[89] + mag;
}

static void perturbAsmJointPrimitiveState_25_0v(double mag, double *state)
{
  state[89] = state[89] + mag;
  state[90] = state[90] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_26_0(double mag, double *state)
{
  state[91] = state[91] + mag;
}

static void perturbAsmJointPrimitiveState_26_0v(double mag, double *state)
{
  state[91] = state[91] + mag;
  state[94] = state[94] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_26_1(double mag, double *state)
{
  state[92] = state[92] + mag;
}

static void perturbAsmJointPrimitiveState_26_1v(double mag, double *state)
{
  state[92] = state[92] + mag;
  state[95] = state[95] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_26_2(double mag, double *state)
{
  state[93] = state[93] + mag;
}

static void perturbAsmJointPrimitiveState_26_2v(double mag, double *state)
{
  state[93] = state[93] + mag;
  state[96] = state[96] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_27_0(double mag, double *state)
{
  state[97] = state[97] + mag;
}

static void perturbAsmJointPrimitiveState_27_0v(double mag, double *state)
{
  state[97] = state[97] + mag;
  state[98] = state[98] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_28_0(double mag, double *state)
{
  state[99] = state[99] + mag;
}

static void perturbAsmJointPrimitiveState_28_0v(double mag, double *state)
{
  state[99] = state[99] + mag;
  state[100] = state[100] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_29_0(double mag, double *state)
{
  state[101] = state[101] + mag;
}

static void perturbAsmJointPrimitiveState_29_0v(double mag, double *state)
{
  state[101] = state[101] + mag;
  state[102] = state[102] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_30_0(double mag, double *state)
{
  state[103] = state[103] + mag;
}

static void perturbAsmJointPrimitiveState_30_0v(double mag, double *state)
{
  state[103] = state[103] + mag;
  state[106] = state[106] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_30_1(double mag, double *state)
{
  state[104] = state[104] + mag;
}

static void perturbAsmJointPrimitiveState_30_1v(double mag, double *state)
{
  state[104] = state[104] + mag;
  state[107] = state[107] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_30_2(double mag, double *state)
{
  state[105] = state[105] + mag;
}

static void perturbAsmJointPrimitiveState_30_2v(double mag, double *state)
{
  state[105] = state[105] + mag;
  state[108] = state[108] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_31_0(double mag, double *state)
{
  state[109] = state[109] + mag;
}

static void perturbAsmJointPrimitiveState_31_0v(double mag, double *state)
{
  state[109] = state[109] + mag;
  state[110] = state[110] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_32_0(double mag, double *state)
{
  state[111] = state[111] + mag;
}

static void perturbAsmJointPrimitiveState_32_0v(double mag, double *state)
{
  state[111] = state[111] + mag;
  state[112] = state[112] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_33_0(double mag, double *state)
{
  state[113] = state[113] + mag;
}

static void perturbAsmJointPrimitiveState_33_0v(double mag, double *state)
{
  state[113] = state[113] + mag;
  state[114] = state[114] - 0.875 * mag;
}

void KIMMCar_ff62ad8f_49_perturbAsmJointPrimitiveState(const void *mech, size_t
  stageIdx, size_t primIdx, double mag, boolean_T doPerturbVelocity, double
  *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch ((stageIdx * 6 + primIdx) * 2 + (doPerturbVelocity ? 1 : 0))
  {
   case 0:
    perturbAsmJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbAsmJointPrimitiveState_0_0v(mag, state);
    break;

   case 2:
    perturbAsmJointPrimitiveState_0_1(mag, state);
    break;

   case 3:
    perturbAsmJointPrimitiveState_0_1v(mag, state);
    break;

   case 4:
    perturbAsmJointPrimitiveState_0_2(mag, state);
    break;

   case 5:
    perturbAsmJointPrimitiveState_0_2v(mag, state);
    break;

   case 6:
    perturbAsmJointPrimitiveState_0_3(mag, state);
    break;

   case 7:
    perturbAsmJointPrimitiveState_0_3v(mag, state);
    break;

   case 12:
    perturbAsmJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbAsmJointPrimitiveState_1_0v(mag, state);
    break;

   case 14:
    perturbAsmJointPrimitiveState_1_1(mag, state);
    break;

   case 15:
    perturbAsmJointPrimitiveState_1_1v(mag, state);
    break;

   case 16:
    perturbAsmJointPrimitiveState_1_2(mag, state);
    break;

   case 17:
    perturbAsmJointPrimitiveState_1_2v(mag, state);
    break;

   case 24:
    perturbAsmJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbAsmJointPrimitiveState_2_0v(mag, state);
    break;

   case 36:
    perturbAsmJointPrimitiveState_3_0(mag, state);
    break;

   case 37:
    perturbAsmJointPrimitiveState_3_0v(mag, state);
    break;

   case 48:
    perturbAsmJointPrimitiveState_4_0(mag, state);
    break;

   case 49:
    perturbAsmJointPrimitiveState_4_0v(mag, state);
    break;

   case 60:
    perturbAsmJointPrimitiveState_5_0(mag, state);
    break;

   case 61:
    perturbAsmJointPrimitiveState_5_0v(mag, state);
    break;

   case 62:
    perturbAsmJointPrimitiveState_5_1(mag, state);
    break;

   case 63:
    perturbAsmJointPrimitiveState_5_1v(mag, state);
    break;

   case 64:
    perturbAsmJointPrimitiveState_5_2(mag, state);
    break;

   case 65:
    perturbAsmJointPrimitiveState_5_2v(mag, state);
    break;

   case 72:
    perturbAsmJointPrimitiveState_6_0(mag, state);
    break;

   case 73:
    perturbAsmJointPrimitiveState_6_0v(mag, state);
    break;

   case 84:
    perturbAsmJointPrimitiveState_7_0(mag, state);
    break;

   case 85:
    perturbAsmJointPrimitiveState_7_0v(mag, state);
    break;

   case 96:
    perturbAsmJointPrimitiveState_8_0(mag, state);
    break;

   case 97:
    perturbAsmJointPrimitiveState_8_0v(mag, state);
    break;

   case 108:
    perturbAsmJointPrimitiveState_9_0(mag, state);
    break;

   case 109:
    perturbAsmJointPrimitiveState_9_0v(mag, state);
    break;

   case 110:
    perturbAsmJointPrimitiveState_9_1(mag, state);
    break;

   case 111:
    perturbAsmJointPrimitiveState_9_1v(mag, state);
    break;

   case 112:
    perturbAsmJointPrimitiveState_9_2(mag, state);
    break;

   case 113:
    perturbAsmJointPrimitiveState_9_2v(mag, state);
    break;

   case 120:
    perturbAsmJointPrimitiveState_10_0(mag, state);
    break;

   case 121:
    perturbAsmJointPrimitiveState_10_0v(mag, state);
    break;

   case 132:
    perturbAsmJointPrimitiveState_11_0(mag, state);
    break;

   case 133:
    perturbAsmJointPrimitiveState_11_0v(mag, state);
    break;

   case 144:
    perturbAsmJointPrimitiveState_12_0(mag, state);
    break;

   case 145:
    perturbAsmJointPrimitiveState_12_0v(mag, state);
    break;

   case 156:
    perturbAsmJointPrimitiveState_13_0(mag, state);
    break;

   case 157:
    perturbAsmJointPrimitiveState_13_0v(mag, state);
    break;

   case 158:
    perturbAsmJointPrimitiveState_13_1(mag, state);
    break;

   case 159:
    perturbAsmJointPrimitiveState_13_1v(mag, state);
    break;

   case 160:
    perturbAsmJointPrimitiveState_13_2(mag, state);
    break;

   case 161:
    perturbAsmJointPrimitiveState_13_2v(mag, state);
    break;

   case 168:
    perturbAsmJointPrimitiveState_14_0(mag, state);
    break;

   case 169:
    perturbAsmJointPrimitiveState_14_0v(mag, state);
    break;

   case 180:
    perturbAsmJointPrimitiveState_15_0(mag, state);
    break;

   case 181:
    perturbAsmJointPrimitiveState_15_0v(mag, state);
    break;

   case 192:
    perturbAsmJointPrimitiveState_16_0(mag, state);
    break;

   case 193:
    perturbAsmJointPrimitiveState_16_0v(mag, state);
    break;

   case 204:
    perturbAsmJointPrimitiveState_17_0(mag, state);
    break;

   case 205:
    perturbAsmJointPrimitiveState_17_0v(mag, state);
    break;

   case 206:
    perturbAsmJointPrimitiveState_17_1(mag, state);
    break;

   case 207:
    perturbAsmJointPrimitiveState_17_1v(mag, state);
    break;

   case 208:
    perturbAsmJointPrimitiveState_17_2(mag, state);
    break;

   case 209:
    perturbAsmJointPrimitiveState_17_2v(mag, state);
    break;

   case 216:
    perturbAsmJointPrimitiveState_18_0(mag, state);
    break;

   case 217:
    perturbAsmJointPrimitiveState_18_0v(mag, state);
    break;

   case 218:
    perturbAsmJointPrimitiveState_18_1(mag, state);
    break;

   case 219:
    perturbAsmJointPrimitiveState_18_1v(mag, state);
    break;

   case 220:
    perturbAsmJointPrimitiveState_18_2(mag, state);
    break;

   case 221:
    perturbAsmJointPrimitiveState_18_2v(mag, state);
    break;

   case 228:
    perturbAsmJointPrimitiveState_19_0(mag, state);
    break;

   case 229:
    perturbAsmJointPrimitiveState_19_0v(mag, state);
    break;

   case 240:
    perturbAsmJointPrimitiveState_20_0(mag, state);
    break;

   case 241:
    perturbAsmJointPrimitiveState_20_0v(mag, state);
    break;

   case 252:
    perturbAsmJointPrimitiveState_21_0(mag, state);
    break;

   case 253:
    perturbAsmJointPrimitiveState_21_0v(mag, state);
    break;

   case 264:
    perturbAsmJointPrimitiveState_22_0(mag, state);
    break;

   case 265:
    perturbAsmJointPrimitiveState_22_0v(mag, state);
    break;

   case 266:
    perturbAsmJointPrimitiveState_22_1(mag, state);
    break;

   case 267:
    perturbAsmJointPrimitiveState_22_1v(mag, state);
    break;

   case 268:
    perturbAsmJointPrimitiveState_22_2(mag, state);
    break;

   case 269:
    perturbAsmJointPrimitiveState_22_2v(mag, state);
    break;

   case 276:
    perturbAsmJointPrimitiveState_23_0(mag, state);
    break;

   case 277:
    perturbAsmJointPrimitiveState_23_0v(mag, state);
    break;

   case 288:
    perturbAsmJointPrimitiveState_24_0(mag, state);
    break;

   case 289:
    perturbAsmJointPrimitiveState_24_0v(mag, state);
    break;

   case 300:
    perturbAsmJointPrimitiveState_25_0(mag, state);
    break;

   case 301:
    perturbAsmJointPrimitiveState_25_0v(mag, state);
    break;

   case 312:
    perturbAsmJointPrimitiveState_26_0(mag, state);
    break;

   case 313:
    perturbAsmJointPrimitiveState_26_0v(mag, state);
    break;

   case 314:
    perturbAsmJointPrimitiveState_26_1(mag, state);
    break;

   case 315:
    perturbAsmJointPrimitiveState_26_1v(mag, state);
    break;

   case 316:
    perturbAsmJointPrimitiveState_26_2(mag, state);
    break;

   case 317:
    perturbAsmJointPrimitiveState_26_2v(mag, state);
    break;

   case 324:
    perturbAsmJointPrimitiveState_27_0(mag, state);
    break;

   case 325:
    perturbAsmJointPrimitiveState_27_0v(mag, state);
    break;

   case 336:
    perturbAsmJointPrimitiveState_28_0(mag, state);
    break;

   case 337:
    perturbAsmJointPrimitiveState_28_0v(mag, state);
    break;

   case 348:
    perturbAsmJointPrimitiveState_29_0(mag, state);
    break;

   case 349:
    perturbAsmJointPrimitiveState_29_0v(mag, state);
    break;

   case 360:
    perturbAsmJointPrimitiveState_30_0(mag, state);
    break;

   case 361:
    perturbAsmJointPrimitiveState_30_0v(mag, state);
    break;

   case 362:
    perturbAsmJointPrimitiveState_30_1(mag, state);
    break;

   case 363:
    perturbAsmJointPrimitiveState_30_1v(mag, state);
    break;

   case 364:
    perturbAsmJointPrimitiveState_30_2(mag, state);
    break;

   case 365:
    perturbAsmJointPrimitiveState_30_2v(mag, state);
    break;

   case 372:
    perturbAsmJointPrimitiveState_31_0(mag, state);
    break;

   case 373:
    perturbAsmJointPrimitiveState_31_0v(mag, state);
    break;

   case 384:
    perturbAsmJointPrimitiveState_32_0(mag, state);
    break;

   case 385:
    perturbAsmJointPrimitiveState_32_0v(mag, state);
    break;

   case 396:
    perturbAsmJointPrimitiveState_33_0(mag, state);
    break;

   case 397:
    perturbAsmJointPrimitiveState_33_0v(mag, state);
    break;
  }
}

static void computePosDofBlendMatrix_0_3(const double *state, int partialType,
  double *matrix)
{
  double xx[20];
  xx[0] = 9.87654321;
  xx[1] = 2.0;
  xx[2] = xx[1] * (state[4] * state[5] - state[3] * state[6]);
  xx[3] = xx[2] * xx[2];
  xx[4] = 1.0;
  xx[5] = (state[3] * state[3] + state[4] * state[4]) * xx[1] - xx[4];
  xx[6] = xx[5] * xx[5];
  xx[7] = sqrt(xx[3] + xx[6]);
  xx[8] = xx[7] == 0.0 ? 0.0 : - xx[2] / xx[7];
  xx[9] = xx[6] + xx[3];
  xx[3] = sqrt(xx[9]);
  xx[6] = xx[3] == 0.0 ? 0.0 : xx[5] / xx[3];
  xx[10] = 0.0;
  xx[11] = (state[4] * state[6] + state[3] * state[5]) * xx[1];
  xx[1] = sqrt(xx[9] + xx[11] * xx[11]);
  xx[12] = xx[1] == 0.0 ? 0.0 : xx[5] / xx[1];
  xx[14] = xx[8];
  xx[15] = xx[6];
  xx[16] = xx[10];
  xx[17] = xx[8];
  xx[18] = xx[8];
  xx[19] = xx[12];
  xx[6] = xx[13 + (partialType)];
  xx[8] = xx[7] == 0.0 ? 0.0 : xx[5] / xx[7];
  xx[7] = xx[3] == 0.0 ? 0.0 : xx[2] / xx[3];
  xx[3] = xx[1] == 0.0 ? 0.0 : xx[2] / xx[1];
  xx[13] = xx[8];
  xx[14] = xx[7];
  xx[15] = xx[10];
  xx[16] = xx[8];
  xx[17] = xx[8];
  xx[18] = xx[3];
  xx[2] = xx[12 + (partialType)];
  xx[3] = xx[1] == 0.0 ? 0.0 : xx[11] / xx[1];
  xx[13] = xx[10];
  xx[14] = xx[10];
  xx[15] = xx[4];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[18] = xx[3];
  xx[1] = xx[12 + (partialType)];
  xx[3] = xx[11] * xx[5];
  xx[5] = sqrt(xx[9] * xx[9] + xx[3] * xx[3]);
  xx[7] = xx[5] == 0.0 ? 0.0 : xx[9] / xx[5];
  xx[12] = xx[10];
  xx[13] = xx[10];
  xx[14] = xx[10];
  xx[15] = xx[7];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[7] = xx[11 + (partialType)];
  xx[12] = xx[10];
  xx[13] = xx[10];
  xx[14] = xx[10];
  xx[15] = xx[10];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[8] = xx[11 + (partialType)];
  xx[9] = xx[5] == 0.0 ? 0.0 : xx[3] / xx[5];
  xx[12] = xx[4];
  xx[13] = xx[4];
  xx[14] = xx[10];
  xx[15] = xx[9];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[0] = xx[11 + (partialType)];
  matrix[0] = xx[6];
  matrix[1] = xx[2];
  matrix[2] = xx[1];
  matrix[3] = xx[7];
  matrix[4] = xx[8];
  matrix[5] = xx[0];
  matrix[6] = xx[8];
  matrix[7] = xx[8];
  matrix[8] = xx[8];
}

void KIMMCar_ff62ad8f_49_computePosDofBlendMatrix(const void *mech, size_t
  stageIdx, size_t primIdx, const double *state, int partialType, double *matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
   case 3:
    computePosDofBlendMatrix_0_3(state, partialType, matrix);
    break;
  }
}

static void computeVelDofBlendMatrix_0_3(const double *state, int partialType,
  double *matrix)
{
  double xx[15];
  (void) state;
  xx[0] = 9.87654321;
  xx[1] = 0.0;
  xx[2] = 1.0;
  xx[4] = xx[1];
  xx[5] = xx[2];
  xx[6] = xx[1];
  xx[7] = xx[2];
  xx[8] = xx[1];
  xx[9] = xx[2];
  xx[10] = xx[3 + (partialType)];
  xx[4] = xx[2];
  xx[5] = xx[1];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[2];
  xx[9] = xx[1];
  xx[11] = xx[3 + (partialType)];
  xx[4] = xx[1];
  xx[5] = xx[1];
  xx[6] = xx[2];
  xx[7] = xx[1];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[12] = xx[3 + (partialType)];
  xx[4] = xx[1];
  xx[5] = xx[1];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[13] = xx[3 + (partialType)];
  xx[4] = xx[1];
  xx[5] = xx[1];
  xx[6] = xx[1];
  xx[7] = xx[2];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[14] = xx[3 + (partialType)];
  xx[4] = xx[2];
  xx[5] = xx[2];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[0] = xx[3 + (partialType)];
  matrix[0] = xx[10];
  matrix[1] = xx[11];
  matrix[2] = xx[12];
  matrix[3] = xx[13];
  matrix[4] = xx[14];
  matrix[5] = xx[0];
  matrix[6] = xx[13];
  matrix[7] = xx[13];
  matrix[8] = xx[13];
}

void KIMMCar_ff62ad8f_49_computeVelDofBlendMatrix(const void *mech, size_t
  stageIdx, size_t primIdx, const double *state, int partialType, double *matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
   case 3:
    computeVelDofBlendMatrix_0_3(state, partialType, matrix);
    break;
  }
}

static void projectPartiallyTargetedPos_0_3(const double *origState, int
  partialType, double *state)
{
  boolean_T bb[2];
  double xx[17];
  xx[0] = 2.0;
  xx[1] = (state[4] * state[6] + state[3] * state[5]) * xx[0];
  xx[2] = 0.99999999999999;
  bb[0] = fabs(xx[1]) > xx[2];
  xx[3] = 1.570796326794897;
  if (xx[1] < 0.0)
    xx[4] = -1.0;
  else if (xx[1] > 0.0)
    xx[4] = +1.0;
  else
    xx[4] = 0.0;
  xx[5] = fabs(xx[1]) > 1.0 ? atan2(xx[1], 0.0) : asin(xx[1]);
  xx[1] = bb[0] ? xx[3] * xx[4] : xx[5];
  xx[5] = (origState[4] * origState[6] + origState[3] * origState[5]) * xx[0];
  bb[1] = fabs(xx[5]) > xx[2];
  if (xx[5] < 0.0)
    xx[2] = -1.0;
  else if (xx[5] > 0.0)
    xx[2] = +1.0;
  else
    xx[2] = 0.0;
  xx[6] = fabs(xx[5]) > 1.0 ? atan2(xx[5], 0.0) : asin(xx[5]);
  xx[5] = bb[1] ? xx[3] * xx[2] : xx[6];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[5];
  xx[9] = xx[5];
  xx[10] = xx[1];
  xx[11] = xx[1];
  xx[12] = xx[5];
  xx[1] = xx[6 + (partialType)];
  xx[3] = cos(xx[1]);
  xx[5] = 0.5;
  xx[6] = state[5] * state[6];
  xx[7] = state[3] * state[4];
  xx[8] = state[3] * state[3];
  xx[9] = 1.0;
  xx[10] = (xx[8] + state[5] * state[5]) * xx[0] - xx[9];
  xx[11] = (xx[6] + xx[7]) * xx[0];
  xx[10] = (xx[11] == 0.0 && xx[10] == 0.0) ? 0.0 : atan2(xx[11], xx[10]);
  xx[11] = (xx[8] + state[6] * state[6]) * xx[0] - xx[9];
  xx[12] = - (xx[0] * (xx[6] - xx[7]));
  xx[11] = (xx[12] == 0.0 && xx[11] == 0.0) ? 0.0 : atan2(xx[12], xx[11]);
  xx[6] = bb[0] ? xx[5] * xx[10] : xx[11];
  xx[7] = (xx[8] + state[4] * state[4]) * xx[0] - xx[9];
  xx[10] = - (xx[0] * (state[4] * state[5] - state[3] * state[6]));
  xx[7] = (xx[10] == 0.0 && xx[7] == 0.0) ? 0.0 : atan2(xx[10], xx[7]);
  xx[8] = bb[0] ? xx[4] * xx[6] : xx[7];
  xx[4] = origState[5] * origState[6];
  xx[7] = origState[3] * origState[4];
  xx[10] = origState[3] * origState[3];
  xx[11] = (xx[10] + origState[5] * origState[5]) * xx[0] - xx[9];
  xx[12] = (xx[4] + xx[7]) * xx[0];
  xx[11] = (xx[12] == 0.0 && xx[11] == 0.0) ? 0.0 : atan2(xx[12], xx[11]);
  xx[12] = (xx[10] + origState[6] * origState[6]) * xx[0] - xx[9];
  xx[13] = - (xx[0] * (xx[4] - xx[7]));
  xx[12] = (xx[13] == 0.0 && xx[12] == 0.0) ? 0.0 : atan2(xx[13], xx[12]);
  xx[4] = bb[1] ? xx[5] * xx[11] : xx[12];
  xx[5] = (xx[10] + origState[4] * origState[4]) * xx[0] - xx[9];
  xx[7] = - (xx[0] * (origState[4] * origState[5] - origState[3] * origState[6]));
  xx[5] = (xx[7] == 0.0 && xx[5] == 0.0) ? 0.0 : atan2(xx[7], xx[5]);
  xx[0] = bb[1] ? xx[2] * xx[4] : xx[5];
  xx[9] = xx[8];
  xx[10] = xx[8];
  xx[11] = xx[8];
  xx[12] = xx[8];
  xx[13] = xx[0];
  xx[14] = xx[0];
  xx[15] = xx[0];
  xx[0] = xx[9 + (partialType)];
  xx[2] = cos(xx[0]);
  xx[7] = xx[6];
  xx[8] = xx[4];
  xx[9] = xx[6];
  xx[10] = xx[4];
  xx[11] = xx[6];
  xx[12] = xx[4];
  xx[13] = xx[6];
  xx[4] = xx[7 + (partialType)];
  xx[5] = cos(xx[4]);
  xx[6] = sin(xx[0]);
  xx[0] = sin(xx[4]);
  xx[4] = xx[2] * xx[0];
  xx[7] = sin(xx[1]);
  xx[1] = xx[5] * xx[2];
  xx[8] = xx[3] * xx[2];
  xx[9] = xx[5] * xx[6] + xx[4] * xx[7];
  xx[10] = xx[0] * xx[6] - xx[1] * xx[7];
  xx[11] = - (xx[3] * xx[6]);
  xx[12] = xx[1] - xx[0] * xx[7] * xx[6];
  xx[13] = xx[4] + xx[5] * xx[7] * xx[6];
  xx[14] = xx[7];
  xx[15] = - (xx[3] * xx[0]);
  xx[16] = xx[5] * xx[3];
  pm_math_Quaternion_Matrix3x3Ctor_ra(xx + 8, xx + 0);
  state[3] = xx[0];
  state[4] = xx[1];
  state[5] = xx[2];
  state[6] = xx[3];
}

void KIMMCar_ff62ad8f_49_projectPartiallyTargetedPos(const void *mech, size_t
  stageIdx, size_t primIdx, const double *origState, int partialType, double
  *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) origState;
  (void) partialType;
  (void) state;
  switch ((stageIdx * 6 + primIdx))
  {
   case 3:
    projectPartiallyTargetedPos_0_3(origState, partialType, state);
    break;
  }
}

void KIMMCar_ff62ad8f_49_propagateMotion(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[390];
  (void) mech;
  (void) rtdvi;
  xx[0] = - state[3];
  xx[1] = - state[4];
  xx[2] = - state[5];
  xx[3] = - state[6];
  xx[4] = 0.0;
  xx[5] = 0.7071067811865476;
  xx[6] = - xx[5];
  xx[7] = rtdvd[9] - state[13];
  xx[8] = - state[14];
  xx[9] = rtdvd[10] - state[15];
  xx[10] = 0.5;
  xx[11] = xx[10] * state[19];
  xx[12] = xx[5] * cos(xx[11]);
  xx[13] = - xx[12];
  xx[14] = xx[5] * sin(xx[11]);
  xx[11] = xx[14] * rtdvd[11];
  xx[15] = xx[12] * rtdvd[11];
  xx[16] = 2.0;
  xx[17] = (xx[12] * xx[11] + xx[14] * xx[15]) * xx[16];
  xx[18] = xx[14] * xx[11];
  xx[11] = xx[12] * xx[15];
  xx[15] = xx[16] * (xx[18] - xx[11]);
  xx[19] = - xx[15];
  xx[20] = rtdvd[11] - (xx[11] + xx[18]) * xx[16];
  xx[11] = - xx[20];
  xx[18] = xx[10] * state[21];
  xx[21] = cos(xx[18]);
  xx[22] = sin(xx[18]);
  xx[23] = rtdvd[42];
  xx[24] = rtdvd[43];
  xx[25] = rtdvd[44];
  xx[26] = rtdvd[45];
  xx[18] = xx[10] * state[23];
  xx[27] = sin(xx[18]);
  xx[28] = cos(xx[18]);
  xx[29] = xx[27] * rtdvd[33];
  xx[30] = xx[27] * rtdvd[34];
  xx[31] = xx[27] * rtdvd[35];
  pm_math_Quaternion_compose_ra(xx + 23, xx + 28, xx + 32);
  xx[23] = rtdvd[30];
  xx[24] = rtdvd[31];
  xx[25] = rtdvd[32];
  pm_math_Quaternion_xform_ra(xx + 32, xx + 23, xx + 26);
  xx[18] = - xx[26];
  xx[23] = - xx[27];
  xx[24] = - xx[28];
  xx[25] = rtdvd[74] - state[25];
  xx[26] = - state[26];
  xx[27] = rtdvd[75] - state[27];
  xx[28] = xx[10] * state[31];
  xx[29] = xx[5] * cos(xx[28]);
  xx[30] = - xx[29];
  xx[31] = xx[5] * sin(xx[28]);
  xx[28] = xx[31] * rtdvd[76];
  xx[36] = xx[29] * rtdvd[76];
  xx[37] = (xx[29] * xx[28] + xx[31] * xx[36]) * xx[16];
  xx[38] = xx[31] * xx[28];
  xx[28] = xx[29] * xx[36];
  xx[36] = xx[16] * (xx[38] - xx[28]);
  xx[39] = - xx[36];
  xx[40] = rtdvd[76] - (xx[28] + xx[38]) * xx[16];
  xx[28] = - xx[40];
  xx[38] = xx[10] * state[33];
  xx[41] = cos(xx[38]);
  xx[42] = sin(xx[38]);
  xx[43] = rtdvd[107];
  xx[44] = rtdvd[108];
  xx[45] = rtdvd[109];
  xx[46] = rtdvd[110];
  xx[38] = xx[10] * state[35];
  xx[47] = sin(xx[38]);
  xx[48] = cos(xx[38]);
  xx[49] = xx[47] * rtdvd[98];
  xx[50] = xx[47] * rtdvd[99];
  xx[51] = xx[47] * rtdvd[100];
  pm_math_Quaternion_compose_ra(xx + 43, xx + 48, xx + 52);
  xx[43] = rtdvd[95];
  xx[44] = rtdvd[96];
  xx[45] = rtdvd[97];
  pm_math_Quaternion_xform_ra(xx + 52, xx + 43, xx + 46);
  xx[38] = - xx[46];
  xx[43] = - xx[47];
  xx[44] = - xx[48];
  xx[45] = rtdvd[138] - state[37];
  xx[46] = - state[38];
  xx[47] = 0.2647;
  xx[48] = xx[47] + state[39];
  xx[49] = - xx[48];
  xx[50] = xx[10] * state[43];
  xx[51] = xx[5] * cos(xx[50]);
  xx[56] = - xx[51];
  xx[57] = xx[5] * sin(xx[50]);
  xx[50] = xx[57] * rtdvd[139];
  xx[58] = xx[51] * rtdvd[139];
  xx[59] = (xx[51] * xx[50] + xx[57] * xx[58]) * xx[16];
  xx[60] = xx[57] * xx[50];
  xx[50] = xx[51] * xx[58];
  xx[58] = xx[16] * (xx[60] - xx[50]);
  xx[61] = - xx[58];
  xx[62] = rtdvd[139] - (xx[50] + xx[60]) * xx[16];
  xx[50] = - xx[62];
  xx[60] = xx[10] * state[45];
  xx[63] = cos(xx[60]);
  xx[64] = sin(xx[60]);
  xx[65] = rtdvd[170];
  xx[66] = rtdvd[171];
  xx[67] = rtdvd[172];
  xx[68] = rtdvd[173];
  xx[60] = xx[10] * state[47];
  xx[69] = sin(xx[60]);
  xx[70] = cos(xx[60]);
  xx[71] = xx[69] * rtdvd[161];
  xx[72] = xx[69] * rtdvd[162];
  xx[73] = xx[69] * rtdvd[163];
  pm_math_Quaternion_compose_ra(xx + 65, xx + 70, xx + 74);
  xx[65] = rtdvd[158];
  xx[66] = rtdvd[159];
  xx[67] = rtdvd[160];
  pm_math_Quaternion_xform_ra(xx + 74, xx + 65, xx + 68);
  xx[60] = - xx[68];
  xx[65] = - xx[69];
  xx[66] = - xx[70];
  xx[67] = rtdvd[201] - state[49];
  xx[68] = - state[50];
  xx[69] = xx[47] + state[51];
  xx[47] = - xx[69];
  xx[70] = xx[10] * state[55];
  xx[71] = xx[5] * cos(xx[70]);
  xx[72] = - xx[71];
  xx[73] = xx[5] * sin(xx[70]);
  xx[70] = xx[73] * rtdvd[202];
  xx[78] = xx[71] * rtdvd[202];
  xx[79] = (xx[71] * xx[70] + xx[73] * xx[78]) * xx[16];
  xx[80] = xx[73] * xx[70];
  xx[70] = xx[71] * xx[78];
  xx[78] = xx[16] * (xx[80] - xx[70]);
  xx[81] = - xx[78];
  xx[82] = rtdvd[202] - (xx[70] + xx[80]) * xx[16];
  xx[70] = - xx[82];
  xx[80] = xx[10] * state[57];
  xx[83] = cos(xx[80]);
  xx[84] = sin(xx[80]);
  xx[85] = rtdvd[233];
  xx[86] = rtdvd[234];
  xx[87] = rtdvd[235];
  xx[88] = rtdvd[236];
  xx[80] = xx[10] * state[59];
  xx[89] = sin(xx[80]);
  xx[90] = cos(xx[80]);
  xx[91] = xx[89] * rtdvd[224];
  xx[92] = xx[89] * rtdvd[225];
  xx[93] = xx[89] * rtdvd[226];
  pm_math_Quaternion_compose_ra(xx + 85, xx + 90, xx + 94);
  xx[85] = rtdvd[221];
  xx[86] = rtdvd[222];
  xx[87] = rtdvd[223];
  pm_math_Quaternion_xform_ra(xx + 94, xx + 85, xx + 88);
  xx[80] = - xx[88];
  xx[85] = - xx[89];
  xx[86] = - xx[90];
  xx[87] = - 1.0;
  xx[88] = xx[10] * state[73];
  xx[89] = cos(xx[88]);
  xx[90] = sin(xx[88]);
  xx[88] = xx[10] * state[75];
  xx[91] = cos(xx[88]);
  xx[92] = sin(xx[88]);
  xx[88] = xx[10] * state[77];
  xx[93] = cos(xx[88]);
  xx[98] = sin(xx[88]);
  xx[88] = xx[10] * state[85];
  xx[99] = cos(xx[88]);
  xx[100] = sin(xx[88]);
  xx[88] = xx[10] * state[87];
  xx[101] = cos(xx[88]);
  xx[102] = sin(xx[88]);
  xx[88] = xx[10] * state[89];
  xx[103] = cos(xx[88]);
  xx[104] = sin(xx[88]);
  xx[88] = xx[10] * state[97];
  xx[105] = cos(xx[88]);
  xx[106] = sin(xx[88]);
  xx[88] = xx[10] * state[99];
  xx[107] = cos(xx[88]);
  xx[108] = sin(xx[88]);
  xx[88] = xx[10] * state[101];
  xx[109] = cos(xx[88]);
  xx[110] = sin(xx[88]);
  xx[88] = xx[10] * state[109];
  xx[111] = cos(xx[88]);
  xx[112] = sin(xx[88]);
  xx[88] = xx[10] * state[111];
  xx[113] = cos(xx[88]);
  xx[114] = sin(xx[88]);
  xx[88] = xx[10] * state[113];
  xx[10] = cos(xx[88]);
  xx[115] = sin(xx[88]);
  xx[88] = xx[89] * xx[91];
  xx[116] = xx[90] * xx[92];
  xx[117] = xx[89] * xx[92];
  xx[118] = xx[91] * xx[90];
  xx[119] = xx[5] * state[4];
  xx[120] = xx[5] * state[6];
  xx[121] = - (xx[119] + xx[120]);
  xx[122] = xx[5] * state[3];
  xx[123] = xx[5] * state[5];
  xx[124] = xx[122] + xx[123];
  xx[125] = xx[120] - xx[119];
  xx[119] = xx[122] - xx[123];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 7, xx + 126);
  xx[120] = xx[126] + state[0];
  xx[122] = xx[127] + state[1];
  xx[123] = xx[128] + state[2];
  xx[126] = xx[121];
  xx[127] = xx[124];
  xx[128] = xx[125];
  xx[129] = xx[119];
  xx[130] = xx[13];
  xx[131] = xx[13];
  xx[132] = xx[14];
  xx[133] = xx[14];
  pm_math_Quaternion_compose_ra(xx + 126, xx + 130, xx + 134);
  xx[138] = xx[17];
  xx[139] = xx[19];
  xx[140] = xx[11];
  pm_math_Quaternion_xform_ra(xx + 126, xx + 138, xx + 141);
  xx[144] = xx[141] + xx[120];
  xx[145] = xx[142] + xx[122];
  xx[141] = xx[143] + xx[123];
  xx[142] = xx[21] * xx[134] - xx[135] * xx[22];
  xx[143] = xx[134] * xx[22] + xx[21] * xx[135];
  xx[146] = xx[21] * xx[136] + xx[137] * xx[22];
  xx[147] = xx[21] * xx[137] - xx[136] * xx[22];
  xx[148] = xx[136] * rtdvd[22];
  xx[149] = xx[135] * rtdvd[22];
  xx[150] = (xx[134] * xx[148] + xx[137] * xx[149]) * xx[16] + xx[144];
  xx[151] = xx[16] * (xx[137] * xx[148] - xx[134] * xx[149]) + xx[145];
  xx[152] = rtdvd[22] - (xx[135] * xx[149] + xx[136] * xx[148]) * xx[16] + xx
    [141];
  xx[153] = xx[142];
  xx[154] = xx[143];
  xx[155] = xx[146];
  xx[156] = xx[147];
  pm_math_Quaternion_compose_ra(xx + 153, xx + 32, xx + 157);
  xx[161] = xx[18];
  xx[162] = xx[23];
  xx[163] = xx[24];
  pm_math_Quaternion_xform_ra(xx + 153, xx + 161, xx + 164);
  xx[148] = xx[99] * xx[101];
  xx[149] = xx[100] * xx[102];
  xx[153] = xx[99] * xx[102];
  xx[154] = xx[101] * xx[100];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 25, xx + 167);
  xx[155] = xx[167] + state[0];
  xx[156] = xx[168] + state[1];
  xx[167] = xx[169] + state[2];
  xx[168] = xx[30];
  xx[169] = xx[30];
  xx[170] = xx[31];
  xx[171] = xx[31];
  pm_math_Quaternion_compose_ra(xx + 126, xx + 168, xx + 172);
  xx[176] = xx[37];
  xx[177] = xx[39];
  xx[178] = xx[28];
  pm_math_Quaternion_xform_ra(xx + 126, xx + 176, xx + 179);
  xx[182] = xx[179] + xx[155];
  xx[183] = xx[180] + xx[156];
  xx[179] = xx[181] + xx[167];
  xx[180] = xx[41] * xx[172] - xx[173] * xx[42];
  xx[181] = xx[172] * xx[42] + xx[41] * xx[173];
  xx[184] = xx[41] * xx[174] + xx[175] * xx[42];
  xx[185] = xx[41] * xx[175] - xx[174] * xx[42];
  xx[186] = xx[174] * rtdvd[87];
  xx[187] = xx[173] * rtdvd[87];
  xx[188] = (xx[172] * xx[186] + xx[175] * xx[187]) * xx[16] + xx[182];
  xx[189] = xx[16] * (xx[175] * xx[186] - xx[172] * xx[187]) + xx[183];
  xx[190] = rtdvd[87] - (xx[173] * xx[187] + xx[174] * xx[186]) * xx[16] + xx
    [179];
  xx[191] = xx[180];
  xx[192] = xx[181];
  xx[193] = xx[184];
  xx[194] = xx[185];
  pm_math_Quaternion_compose_ra(xx + 191, xx + 52, xx + 195);
  xx[199] = xx[38];
  xx[200] = xx[43];
  xx[201] = xx[44];
  pm_math_Quaternion_xform_ra(xx + 191, xx + 199, xx + 202);
  xx[186] = xx[105] * xx[107];
  xx[187] = xx[106] * xx[108];
  xx[191] = xx[105] * xx[108];
  xx[192] = xx[107] * xx[106];
  xx[205] = xx[45];
  xx[206] = xx[46];
  xx[207] = xx[49];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 205, xx + 208);
  xx[193] = xx[208] + state[0];
  xx[194] = xx[209] + state[1];
  xx[208] = xx[210] + state[2];
  xx[209] = xx[56];
  xx[210] = xx[56];
  xx[211] = xx[57];
  xx[212] = xx[57];
  pm_math_Quaternion_compose_ra(xx + 126, xx + 209, xx + 213);
  xx[217] = xx[59];
  xx[218] = xx[61];
  xx[219] = xx[50];
  pm_math_Quaternion_xform_ra(xx + 126, xx + 217, xx + 220);
  xx[223] = xx[220] + xx[193];
  xx[224] = xx[221] + xx[194];
  xx[220] = xx[222] + xx[208];
  xx[221] = xx[63] * xx[213] - xx[214] * xx[64];
  xx[222] = xx[213] * xx[64] + xx[63] * xx[214];
  xx[225] = xx[63] * xx[215] + xx[216] * xx[64];
  xx[226] = xx[63] * xx[216] - xx[215] * xx[64];
  xx[227] = xx[215] * rtdvd[150];
  xx[228] = xx[214] * rtdvd[150];
  xx[229] = (xx[213] * xx[227] + xx[216] * xx[228]) * xx[16] + xx[223];
  xx[230] = xx[16] * (xx[216] * xx[227] - xx[213] * xx[228]) + xx[224];
  xx[231] = rtdvd[150] - (xx[214] * xx[228] + xx[215] * xx[227]) * xx[16] + xx
    [220];
  xx[232] = xx[221];
  xx[233] = xx[222];
  xx[234] = xx[225];
  xx[235] = xx[226];
  pm_math_Quaternion_compose_ra(xx + 232, xx + 74, xx + 236);
  xx[240] = xx[60];
  xx[241] = xx[65];
  xx[242] = xx[66];
  pm_math_Quaternion_xform_ra(xx + 232, xx + 240, xx + 243);
  xx[227] = xx[111] * xx[113];
  xx[228] = xx[112] * xx[114];
  xx[232] = xx[111] * xx[114];
  xx[233] = xx[113] * xx[112];
  xx[246] = xx[67];
  xx[247] = xx[68];
  xx[248] = xx[47];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 246, xx + 249);
  xx[234] = xx[249] + state[0];
  xx[235] = xx[250] + state[1];
  xx[249] = xx[251] + state[2];
  xx[250] = xx[72];
  xx[251] = xx[72];
  xx[252] = xx[73];
  xx[253] = xx[73];
  pm_math_Quaternion_compose_ra(xx + 126, xx + 250, xx + 254);
  xx[258] = xx[79];
  xx[259] = xx[81];
  xx[260] = xx[70];
  pm_math_Quaternion_xform_ra(xx + 126, xx + 258, xx + 261);
  xx[126] = xx[261] + xx[234];
  xx[127] = xx[262] + xx[235];
  xx[128] = xx[263] + xx[249];
  xx[129] = xx[83] * xx[254] - xx[255] * xx[84];
  xx[261] = xx[254] * xx[84] + xx[83] * xx[255];
  xx[262] = xx[83] * xx[256] + xx[257] * xx[84];
  xx[263] = xx[83] * xx[257] - xx[256] * xx[84];
  xx[264] = xx[256] * rtdvd[213];
  xx[265] = xx[255] * rtdvd[213];
  xx[266] = (xx[254] * xx[264] + xx[257] * xx[265]) * xx[16] + xx[126];
  xx[267] = xx[16] * (xx[257] * xx[264] - xx[254] * xx[265]) + xx[127];
  xx[268] = rtdvd[213] - (xx[255] * xx[265] + xx[256] * xx[264]) * xx[16] + xx
    [128];
  xx[269] = xx[129];
  xx[270] = xx[261];
  xx[271] = xx[262];
  xx[272] = xx[263];
  pm_math_Quaternion_compose_ra(xx + 269, xx + 94, xx + 273);
  xx[277] = xx[80];
  xx[278] = xx[85];
  xx[279] = xx[86];
  pm_math_Quaternion_xform_ra(xx + 269, xx + 277, xx + 280);
  xx[264] = xx[5] * xx[12];
  xx[12] = xx[5] * xx[14];
  xx[265] = xx[264] - xx[12];
  xx[269] = xx[264] + xx[12];
  xx[12] = 1.414213562373095;
  xx[264] = (xx[5] * xx[17] + xx[5] * xx[20]) * xx[12];
  xx[270] = xx[17] - xx[264] + xx[7];
  xx[271] = 0.5000000000000001;
  xx[272] = xx[271] * xx[15];
  xx[283] = (xx[272] + xx[272]) * xx[16] - xx[15] - state[14];
  xx[15] = xx[264] - xx[20] + xx[9];
  xx[20] = xx[21] * xx[265];
  xx[264] = xx[269] * xx[22];
  xx[272] = xx[269] * xx[21];
  xx[284] = xx[22] * xx[265];
  xx[285] = xx[269] * rtdvd[22];
  xx[286] = xx[285] * xx[265];
  xx[287] = xx[269] * xx[285];
  xx[285] = xx[5] * xx[29];
  xx[29] = xx[5] * xx[31];
  xx[288] = xx[285] - xx[29];
  xx[289] = xx[285] + xx[29];
  xx[29] = (xx[5] * xx[37] + xx[5] * xx[40]) * xx[12];
  xx[285] = xx[37] - xx[29] + xx[25];
  xx[290] = xx[271] * xx[36];
  xx[291] = (xx[290] + xx[290]) * xx[16] - xx[36] - state[26];
  xx[36] = xx[29] - xx[40] + xx[27];
  xx[29] = xx[41] * xx[288];
  xx[40] = xx[289] * xx[42];
  xx[290] = xx[289] * xx[41];
  xx[292] = xx[42] * xx[288];
  xx[293] = xx[289] * rtdvd[87];
  xx[294] = xx[293] * xx[288];
  xx[295] = xx[289] * xx[293];
  xx[293] = xx[5] * xx[51];
  xx[51] = xx[5] * xx[57];
  xx[296] = xx[293] - xx[51];
  xx[297] = xx[293] + xx[51];
  xx[51] = (xx[5] * xx[59] + xx[5] * xx[62]) * xx[12];
  xx[293] = xx[59] - xx[51] + xx[45];
  xx[298] = xx[271] * xx[58];
  xx[299] = (xx[298] + xx[298]) * xx[16] - xx[58] - state[38];
  xx[58] = xx[51] - xx[62] - xx[48];
  xx[48] = xx[63] * xx[296];
  xx[51] = xx[297] * xx[64];
  xx[62] = xx[297] * xx[63];
  xx[298] = xx[64] * xx[296];
  xx[300] = xx[297] * rtdvd[150];
  xx[301] = xx[300] * xx[296];
  xx[302] = xx[297] * xx[300];
  xx[300] = xx[5] * xx[71];
  xx[71] = xx[5] * xx[73];
  xx[303] = xx[300] - xx[71];
  xx[304] = xx[300] + xx[71];
  xx[71] = (xx[5] * xx[79] + xx[5] * xx[82]) * xx[12];
  xx[300] = xx[79] - xx[71] + xx[67];
  xx[305] = xx[271] * xx[78];
  xx[306] = (xx[305] + xx[305]) * xx[16] - xx[78] - state[50];
  xx[78] = xx[71] - xx[82] - xx[69];
  xx[69] = xx[83] * xx[303];
  xx[71] = xx[304] * xx[84];
  xx[82] = xx[304] * xx[83];
  xx[305] = xx[84] * xx[303];
  xx[307] = xx[304] * rtdvd[213];
  xx[308] = xx[307] * xx[303];
  xx[309] = xx[304] * xx[307];
  xx[310] = state[7];
  xx[311] = state[8];
  xx[312] = state[9];
  pm_math_Quaternion_inverseXform_ra(xx + 0, xx + 310, xx + 313);
  xx[307] = xx[12] * (xx[5] * state[12] - xx[5] * state[10]);
  xx[310] = state[10] + xx[307];
  xx[311] = xx[271] * state[11];
  xx[312] = state[11] - (xx[311] + xx[311]) * xx[16];
  xx[311] = state[12] - xx[307];
  xx[316] = state[10];
  xx[317] = state[11];
  xx[318] = state[12];
  pm_math_Vector3_cross_ra(xx + 316, xx + 7, xx + 319);
  xx[307] = xx[319] + xx[313];
  xx[322] = xx[321] + xx[315];
  xx[323] = xx[12] * (xx[322] * xx[5] - xx[307] * xx[5]);
  xx[324] = xx[307] + xx[323] - state[18];
  xx[307] = xx[320] + xx[314];
  xx[319] = xx[307] * xx[271];
  xx[320] = xx[307] - (xx[319] + xx[319]) * xx[16] + state[17];
  xx[307] = xx[322] - xx[323] - state[16];
  xx[321] = xx[310];
  xx[322] = xx[312];
  xx[323] = xx[311];
  pm_math_Quaternion_inverseXform_ra(xx + 130, xx + 321, xx + 325);
  xx[319] = xx[326] - state[20];
  pm_math_Vector3_cross_ra(xx + 321, xx + 138, xx + 328);
  xx[138] = xx[328] + xx[324];
  xx[139] = xx[329] + xx[320];
  xx[140] = xx[330] + xx[307];
  pm_math_Quaternion_inverseXform_ra(xx + 130, xx + 138, xx + 328);
  xx[130] = xx[328] + rtdvd[12] * state[20];
  xx[131] = xx[325] + state[22];
  xx[132] = xx[327] * xx[22];
  xx[133] = xx[22] * xx[319];
  xx[138] = xx[319] + xx[16] * (xx[21] * xx[132] - xx[133] * xx[22]);
  xx[139] = xx[327] - (xx[21] * xx[133] + xx[132] * xx[22]) * xx[16];
  xx[132] = xx[319] * rtdvd[22] + xx[130];
  xx[133] = xx[329] - xx[325] * rtdvd[22];
  xx[140] = xx[330] * xx[22];
  xx[326] = xx[22] * xx[133];
  xx[328] = xx[133] + xx[16] * (xx[21] * xx[140] - xx[326] * xx[22]);
  xx[133] = xx[330] - (xx[21] * xx[326] + xx[140] * xx[22]) * xx[16];
  xx[331] = xx[131];
  xx[332] = xx[138];
  xx[333] = xx[139];
  pm_math_Quaternion_inverseXform_ra(xx + 32, xx + 331, xx + 334);
  pm_math_Vector3_cross_ra(xx + 331, xx + 161, xx + 337);
  xx[161] = xx[337] + xx[132];
  xx[162] = xx[338] + xx[328];
  xx[163] = xx[339] + xx[133];
  pm_math_Quaternion_inverseXform_ra(xx + 32, xx + 161, xx + 331);
  pm_math_Vector3_cross_ra(xx + 316, xx + 25, xx + 161);
  xx[140] = xx[161] + xx[313];
  xx[326] = xx[163] + xx[315];
  xx[337] = xx[12] * (xx[326] * xx[5] - xx[140] * xx[5]);
  xx[338] = xx[140] + xx[337] - state[30];
  xx[140] = xx[162] + xx[314];
  xx[161] = xx[140] * xx[271];
  xx[162] = xx[140] - (xx[161] + xx[161]) * xx[16] + state[29];
  xx[140] = xx[326] - xx[337] - state[28];
  pm_math_Quaternion_inverseXform_ra(xx + 168, xx + 321, xx + 339);
  xx[161] = xx[340] - state[32];
  pm_math_Vector3_cross_ra(xx + 321, xx + 176, xx + 342);
  xx[176] = xx[342] + xx[338];
  xx[177] = xx[343] + xx[162];
  xx[178] = xx[344] + xx[140];
  pm_math_Quaternion_inverseXform_ra(xx + 168, xx + 176, xx + 342);
  xx[163] = xx[342] + rtdvd[77] * state[32];
  xx[168] = xx[339] + state[34];
  xx[169] = xx[341] * xx[42];
  xx[170] = xx[42] * xx[161];
  xx[171] = xx[161] + xx[16] * (xx[41] * xx[169] - xx[170] * xx[42]);
  xx[176] = xx[341] - (xx[41] * xx[170] + xx[169] * xx[42]) * xx[16];
  xx[169] = xx[161] * rtdvd[87] + xx[163];
  xx[170] = xx[343] - xx[339] * rtdvd[87];
  xx[177] = xx[344] * xx[42];
  xx[178] = xx[42] * xx[170];
  xx[326] = xx[170] + xx[16] * (xx[41] * xx[177] - xx[178] * xx[42]);
  xx[170] = xx[344] - (xx[41] * xx[178] + xx[177] * xx[42]) * xx[16];
  xx[345] = xx[168];
  xx[346] = xx[171];
  xx[347] = xx[176];
  pm_math_Quaternion_inverseXform_ra(xx + 52, xx + 345, xx + 348);
  pm_math_Vector3_cross_ra(xx + 345, xx + 199, xx + 351);
  xx[199] = xx[351] + xx[169];
  xx[200] = xx[352] + xx[326];
  xx[201] = xx[353] + xx[170];
  pm_math_Quaternion_inverseXform_ra(xx + 52, xx + 199, xx + 345);
  pm_math_Vector3_cross_ra(xx + 316, xx + 205, xx + 199);
  xx[177] = xx[199] + xx[313];
  xx[178] = xx[201] + xx[315];
  xx[205] = xx[12] * (xx[178] * xx[5] - xx[177] * xx[5]);
  xx[206] = xx[177] + xx[205] - state[42];
  xx[177] = xx[200] + xx[314];
  xx[199] = xx[177] * xx[271];
  xx[200] = xx[177] - (xx[199] + xx[199]) * xx[16] + state[41];
  xx[177] = xx[178] - xx[205] - state[40];
  pm_math_Quaternion_inverseXform_ra(xx + 209, xx + 321, xx + 351);
  xx[178] = xx[352] - state[44];
  pm_math_Vector3_cross_ra(xx + 321, xx + 217, xx + 354);
  xx[217] = xx[354] + xx[206];
  xx[218] = xx[355] + xx[200];
  xx[219] = xx[356] + xx[177];
  pm_math_Quaternion_inverseXform_ra(xx + 209, xx + 217, xx + 354);
  xx[199] = xx[354] + rtdvd[140] * state[44];
  xx[201] = xx[351] + state[46];
  xx[205] = xx[353] * xx[64];
  xx[207] = xx[64] * xx[178];
  xx[209] = xx[178] + xx[16] * (xx[63] * xx[205] - xx[207] * xx[64]);
  xx[210] = xx[353] - (xx[63] * xx[207] + xx[205] * xx[64]) * xx[16];
  xx[205] = xx[178] * rtdvd[150] + xx[199];
  xx[207] = xx[355] - xx[351] * rtdvd[150];
  xx[211] = xx[356] * xx[64];
  xx[212] = xx[64] * xx[207];
  xx[217] = xx[207] + xx[16] * (xx[63] * xx[211] - xx[212] * xx[64]);
  xx[207] = xx[356] - (xx[63] * xx[212] + xx[211] * xx[64]) * xx[16];
  xx[357] = xx[201];
  xx[358] = xx[209];
  xx[359] = xx[210];
  pm_math_Quaternion_inverseXform_ra(xx + 74, xx + 357, xx + 360);
  pm_math_Vector3_cross_ra(xx + 357, xx + 240, xx + 363);
  xx[240] = xx[363] + xx[205];
  xx[241] = xx[364] + xx[217];
  xx[242] = xx[365] + xx[207];
  pm_math_Quaternion_inverseXform_ra(xx + 74, xx + 240, xx + 357);
  pm_math_Vector3_cross_ra(xx + 316, xx + 246, xx + 240);
  xx[211] = xx[240] + xx[313];
  xx[212] = xx[242] + xx[315];
  xx[218] = xx[12] * (xx[212] * xx[5] - xx[211] * xx[5]);
  xx[5] = xx[211] + xx[218] - state[54];
  xx[12] = xx[241] + xx[314];
  xx[211] = xx[12] * xx[271];
  xx[219] = xx[12] - (xx[211] + xx[211]) * xx[16] + state[53];
  xx[12] = xx[212] - xx[218] - state[52];
  pm_math_Quaternion_inverseXform_ra(xx + 250, xx + 321, xx + 240);
  xx[211] = xx[241] - state[56];
  pm_math_Vector3_cross_ra(xx + 321, xx + 258, xx + 246);
  xx[258] = xx[246] + xx[5];
  xx[259] = xx[247] + xx[219];
  xx[260] = xx[248] + xx[12];
  pm_math_Quaternion_inverseXform_ra(xx + 250, xx + 258, xx + 246);
  xx[212] = xx[246] + rtdvd[203] * state[56];
  xx[218] = xx[240] + state[58];
  xx[241] = xx[242] * xx[84];
  xx[246] = xx[84] * xx[211];
  xx[250] = xx[211] + xx[16] * (xx[83] * xx[241] - xx[246] * xx[84]);
  xx[251] = xx[242] - (xx[83] * xx[246] + xx[241] * xx[84]) * xx[16];
  xx[241] = xx[211] * rtdvd[213] + xx[212];
  xx[246] = xx[247] - xx[240] * rtdvd[213];
  xx[252] = xx[248] * xx[84];
  xx[253] = xx[84] * xx[246];
  xx[258] = xx[246] + xx[16] * (xx[83] * xx[252] - xx[253] * xx[84]);
  xx[246] = xx[248] - (xx[83] * xx[253] + xx[252] * xx[84]) * xx[16];
  xx[316] = xx[218];
  xx[317] = xx[250];
  xx[318] = xx[251];
  pm_math_Quaternion_inverseXform_ra(xx + 94, xx + 316, xx + 321);
  pm_math_Vector3_cross_ra(xx + 316, xx + 277, xx + 363);
  xx[277] = xx[363] + xx[241];
  xx[278] = xx[364] + xx[258];
  xx[279] = xx[365] + xx[246];
  pm_math_Quaternion_inverseXform_ra(xx + 94, xx + 277, xx + 316);
  xx[252] = xx[90] * state[71];
  xx[253] = xx[90] * state[70];
  xx[259] = state[70] + xx[16] * (xx[89] * xx[252] - xx[253] * xx[90]);
  xx[260] = state[71] - (xx[89] * xx[253] + xx[252] * xx[90]) * xx[16];
  xx[252] = xx[92] * state[74];
  xx[253] = xx[16] * xx[91] * xx[252];
  xx[271] = state[74] - xx[16] * xx[252] * xx[92];
  xx[252] = xx[92] * state[72];
  xx[277] = xx[259] * xx[92];
  xx[278] = xx[259] - (xx[91] * xx[252] + xx[277] * xx[92]) * xx[16];
  xx[279] = state[72] + xx[16] * (xx[91] * xx[277] - xx[252] * xx[92]);
  xx[252] = xx[98] * xx[271];
  xx[277] = xx[98] * state[76];
  xx[337] = xx[279] * xx[98];
  xx[340] = xx[98] * xx[260];
  xx[342] = xx[100] * state[83];
  xx[352] = xx[100] * state[82];
  xx[354] = state[82] + xx[16] * (xx[99] * xx[342] - xx[352] * xx[100]);
  xx[363] = state[83] - (xx[99] * xx[352] + xx[342] * xx[100]) * xx[16];
  xx[342] = xx[102] * state[86];
  xx[352] = xx[16] * xx[101] * xx[342];
  xx[364] = state[86] - xx[16] * xx[342] * xx[102];
  xx[342] = xx[102] * state[84];
  xx[365] = xx[354] * xx[102];
  xx[366] = xx[354] - (xx[101] * xx[342] + xx[365] * xx[102]) * xx[16];
  xx[367] = state[84] + xx[16] * (xx[101] * xx[365] - xx[342] * xx[102]);
  xx[342] = xx[104] * xx[364];
  xx[365] = xx[104] * state[88];
  xx[368] = xx[367] * xx[104];
  xx[369] = xx[104] * xx[363];
  xx[370] = xx[106] * state[95];
  xx[371] = xx[106] * state[94];
  xx[372] = state[94] + xx[16] * (xx[105] * xx[370] - xx[371] * xx[106]);
  xx[373] = state[95] - (xx[105] * xx[371] + xx[370] * xx[106]) * xx[16];
  xx[370] = xx[108] * state[98];
  xx[371] = xx[16] * xx[107] * xx[370];
  xx[374] = state[98] - xx[16] * xx[370] * xx[108];
  xx[370] = xx[108] * state[96];
  xx[375] = xx[372] * xx[108];
  xx[376] = xx[372] - (xx[107] * xx[370] + xx[375] * xx[108]) * xx[16];
  xx[377] = state[96] + xx[16] * (xx[107] * xx[375] - xx[370] * xx[108]);
  xx[370] = xx[110] * xx[374];
  xx[375] = xx[110] * state[100];
  xx[378] = xx[377] * xx[110];
  xx[379] = xx[110] * xx[373];
  xx[380] = xx[112] * state[107];
  xx[381] = xx[112] * state[106];
  xx[382] = state[106] + xx[16] * (xx[111] * xx[380] - xx[381] * xx[112]);
  xx[383] = state[107] - (xx[111] * xx[381] + xx[380] * xx[112]) * xx[16];
  xx[380] = xx[114] * state[110];
  xx[381] = xx[16] * xx[113] * xx[380];
  xx[384] = state[110] - xx[16] * xx[380] * xx[114];
  xx[380] = xx[114] * state[108];
  xx[385] = xx[382] * xx[114];
  xx[386] = xx[382] - (xx[113] * xx[380] + xx[385] * xx[114]) * xx[16];
  xx[387] = state[108] + xx[16] * (xx[113] * xx[385] - xx[380] * xx[114]);
  xx[380] = xx[115] * xx[384];
  xx[385] = xx[115] * state[112];
  xx[388] = xx[387] * xx[115];
  xx[389] = xx[115] * xx[383];
  motionData[0] = xx[0];
  motionData[1] = xx[1];
  motionData[2] = xx[2];
  motionData[3] = xx[3];
  motionData[4] = state[0];
  motionData[5] = state[1];
  motionData[6] = state[2];
  motionData[7] = xx[4];
  motionData[8] = xx[6];
  motionData[9] = xx[4];
  motionData[10] = xx[6];
  motionData[11] = xx[7];
  motionData[12] = xx[8];
  motionData[13] = xx[9];
  motionData[14] = xx[13];
  motionData[15] = xx[13];
  motionData[16] = xx[14];
  motionData[17] = xx[14];
  motionData[18] = xx[17];
  motionData[19] = xx[19];
  motionData[20] = xx[11];
  motionData[21] = xx[21];
  motionData[22] = xx[22];
  motionData[23] = xx[4];
  motionData[24] = xx[4];
  motionData[25] = xx[4];
  motionData[26] = xx[4];
  motionData[27] = rtdvd[22];
  motionData[28] = xx[32];
  motionData[29] = xx[33];
  motionData[30] = xx[34];
  motionData[31] = xx[35];
  motionData[32] = xx[18];
  motionData[33] = xx[23];
  motionData[34] = xx[24];
  motionData[35] = xx[4];
  motionData[36] = xx[6];
  motionData[37] = xx[4];
  motionData[38] = xx[6];
  motionData[39] = xx[25];
  motionData[40] = xx[26];
  motionData[41] = xx[27];
  motionData[42] = xx[30];
  motionData[43] = xx[30];
  motionData[44] = xx[31];
  motionData[45] = xx[31];
  motionData[46] = xx[37];
  motionData[47] = xx[39];
  motionData[48] = xx[28];
  motionData[49] = xx[41];
  motionData[50] = xx[42];
  motionData[51] = xx[4];
  motionData[52] = xx[4];
  motionData[53] = xx[4];
  motionData[54] = xx[4];
  motionData[55] = rtdvd[87];
  motionData[56] = xx[52];
  motionData[57] = xx[53];
  motionData[58] = xx[54];
  motionData[59] = xx[55];
  motionData[60] = xx[38];
  motionData[61] = xx[43];
  motionData[62] = xx[44];
  motionData[63] = xx[4];
  motionData[64] = xx[6];
  motionData[65] = xx[4];
  motionData[66] = xx[6];
  motionData[67] = xx[45];
  motionData[68] = xx[46];
  motionData[69] = xx[49];
  motionData[70] = xx[56];
  motionData[71] = xx[56];
  motionData[72] = xx[57];
  motionData[73] = xx[57];
  motionData[74] = xx[59];
  motionData[75] = xx[61];
  motionData[76] = xx[50];
  motionData[77] = xx[63];
  motionData[78] = xx[64];
  motionData[79] = xx[4];
  motionData[80] = xx[4];
  motionData[81] = xx[4];
  motionData[82] = xx[4];
  motionData[83] = rtdvd[150];
  motionData[84] = xx[74];
  motionData[85] = xx[75];
  motionData[86] = xx[76];
  motionData[87] = xx[77];
  motionData[88] = xx[60];
  motionData[89] = xx[65];
  motionData[90] = xx[66];
  motionData[91] = xx[4];
  motionData[92] = xx[6];
  motionData[93] = xx[4];
  motionData[94] = xx[6];
  motionData[95] = xx[67];
  motionData[96] = xx[68];
  motionData[97] = xx[47];
  motionData[98] = xx[72];
  motionData[99] = xx[72];
  motionData[100] = xx[73];
  motionData[101] = xx[73];
  motionData[102] = xx[79];
  motionData[103] = xx[81];
  motionData[104] = xx[70];
  motionData[105] = xx[83];
  motionData[106] = xx[84];
  motionData[107] = xx[4];
  motionData[108] = xx[4];
  motionData[109] = xx[4];
  motionData[110] = xx[4];
  motionData[111] = rtdvd[213];
  motionData[112] = xx[94];
  motionData[113] = xx[95];
  motionData[114] = xx[96];
  motionData[115] = xx[97];
  motionData[116] = xx[80];
  motionData[117] = xx[85];
  motionData[118] = xx[86];
  motionData[119] = 0.338430610991899;
  motionData[120] = 0.1016374984694517;
  motionData[121] = 0.03679784973285759;
  motionData[122] = - 0.934762247153553;
  motionData[123] = 3.840000000000002 + state[61];
  motionData[124] = 3.2 + state[62];
  motionData[125] = 1.1 + state[63];
  motionData[126] = xx[87];
  motionData[127] = xx[4];
  motionData[128] = xx[4];
  motionData[129] = xx[4];
  motionData[130] = state[67];
  motionData[131] = state[68];
  motionData[132] = state[69];
  motionData[133] = - xx[89];
  motionData[134] = xx[4];
  motionData[135] = xx[4];
  motionData[136] = - xx[90];
  motionData[137] = xx[4];
  motionData[138] = xx[4];
  motionData[139] = xx[4];
  motionData[140] = xx[91];
  motionData[141] = xx[4];
  motionData[142] = xx[92];
  motionData[143] = xx[4];
  motionData[144] = xx[4];
  motionData[145] = xx[4];
  motionData[146] = xx[4];
  motionData[147] = xx[93];
  motionData[148] = xx[98];
  motionData[149] = xx[4];
  motionData[150] = xx[4];
  motionData[151] = xx[4];
  motionData[152] = xx[4];
  motionData[153] = xx[4];
  motionData[154] = xx[87];
  motionData[155] = xx[4];
  motionData[156] = xx[4];
  motionData[157] = xx[4];
  motionData[158] = state[79];
  motionData[159] = state[80];
  motionData[160] = state[81];
  motionData[161] = - xx[99];
  motionData[162] = xx[4];
  motionData[163] = xx[4];
  motionData[164] = - xx[100];
  motionData[165] = xx[4];
  motionData[166] = xx[4];
  motionData[167] = xx[4];
  motionData[168] = xx[101];
  motionData[169] = xx[4];
  motionData[170] = xx[102];
  motionData[171] = xx[4];
  motionData[172] = xx[4];
  motionData[173] = xx[4];
  motionData[174] = xx[4];
  motionData[175] = xx[103];
  motionData[176] = xx[104];
  motionData[177] = xx[4];
  motionData[178] = xx[4];
  motionData[179] = xx[4];
  motionData[180] = xx[4];
  motionData[181] = xx[4];
  motionData[182] = xx[87];
  motionData[183] = xx[4];
  motionData[184] = xx[4];
  motionData[185] = xx[4];
  motionData[186] = state[91];
  motionData[187] = state[92];
  motionData[188] = state[93];
  motionData[189] = - xx[105];
  motionData[190] = xx[4];
  motionData[191] = xx[4];
  motionData[192] = - xx[106];
  motionData[193] = xx[4];
  motionData[194] = xx[4];
  motionData[195] = xx[4];
  motionData[196] = xx[107];
  motionData[197] = xx[4];
  motionData[198] = xx[108];
  motionData[199] = xx[4];
  motionData[200] = xx[4];
  motionData[201] = xx[4];
  motionData[202] = xx[4];
  motionData[203] = xx[109];
  motionData[204] = xx[110];
  motionData[205] = xx[4];
  motionData[206] = xx[4];
  motionData[207] = xx[4];
  motionData[208] = xx[4];
  motionData[209] = xx[4];
  motionData[210] = xx[87];
  motionData[211] = xx[4];
  motionData[212] = xx[4];
  motionData[213] = xx[4];
  motionData[214] = state[103];
  motionData[215] = state[104];
  motionData[216] = state[105];
  motionData[217] = - xx[111];
  motionData[218] = xx[4];
  motionData[219] = xx[4];
  motionData[220] = - xx[112];
  motionData[221] = xx[4];
  motionData[222] = xx[4];
  motionData[223] = xx[4];
  motionData[224] = xx[113];
  motionData[225] = xx[4];
  motionData[226] = xx[114];
  motionData[227] = xx[4];
  motionData[228] = xx[4];
  motionData[229] = xx[4];
  motionData[230] = xx[4];
  motionData[231] = xx[10];
  motionData[232] = xx[115];
  motionData[233] = xx[4];
  motionData[234] = xx[4];
  motionData[235] = xx[4];
  motionData[236] = xx[4];
  motionData[237] = xx[4];
  motionData[238] = xx[89];
  motionData[239] = xx[4];
  motionData[240] = xx[4];
  motionData[241] = xx[90];
  motionData[242] = state[67];
  motionData[243] = state[68];
  motionData[244] = state[69];
  motionData[245] = xx[88];
  motionData[246] = - xx[116];
  motionData[247] = xx[117];
  motionData[248] = xx[118];
  motionData[249] = state[67];
  motionData[250] = state[68];
  motionData[251] = state[69];
  motionData[252] = xx[93] * xx[88] + xx[116] * xx[98];
  motionData[253] = xx[88] * xx[98] - xx[93] * xx[116];
  motionData[254] = xx[93] * xx[117] + xx[118] * xx[98];
  motionData[255] = xx[93] * xx[118] - xx[117] * xx[98];
  motionData[256] = state[67];
  motionData[257] = state[68];
  motionData[258] = state[69];
  motionData[259] = xx[121];
  motionData[260] = xx[124];
  motionData[261] = xx[125];
  motionData[262] = xx[119];
  motionData[263] = xx[120];
  motionData[264] = xx[122];
  motionData[265] = xx[123];
  motionData[266] = xx[134];
  motionData[267] = xx[135];
  motionData[268] = xx[136];
  motionData[269] = xx[137];
  motionData[270] = xx[144];
  motionData[271] = xx[145];
  motionData[272] = xx[141];
  motionData[273] = xx[142];
  motionData[274] = xx[143];
  motionData[275] = xx[146];
  motionData[276] = xx[147];
  motionData[277] = xx[150];
  motionData[278] = xx[151];
  motionData[279] = xx[152];
  motionData[280] = xx[157];
  motionData[281] = xx[158];
  motionData[282] = xx[159];
  motionData[283] = xx[160];
  motionData[284] = xx[164] + xx[150];
  motionData[285] = xx[165] + xx[151];
  motionData[286] = xx[166] + xx[152];
  motionData[287] = xx[99];
  motionData[288] = xx[4];
  motionData[289] = xx[4];
  motionData[290] = xx[100];
  motionData[291] = state[79];
  motionData[292] = state[80];
  motionData[293] = state[81];
  motionData[294] = xx[148];
  motionData[295] = - xx[149];
  motionData[296] = xx[153];
  motionData[297] = xx[154];
  motionData[298] = state[79];
  motionData[299] = state[80];
  motionData[300] = state[81];
  motionData[301] = xx[103] * xx[148] + xx[149] * xx[104];
  motionData[302] = xx[148] * xx[104] - xx[103] * xx[149];
  motionData[303] = xx[103] * xx[153] + xx[154] * xx[104];
  motionData[304] = xx[103] * xx[154] - xx[153] * xx[104];
  motionData[305] = state[79];
  motionData[306] = state[80];
  motionData[307] = state[81];
  motionData[308] = xx[121];
  motionData[309] = xx[124];
  motionData[310] = xx[125];
  motionData[311] = xx[119];
  motionData[312] = xx[155];
  motionData[313] = xx[156];
  motionData[314] = xx[167];
  motionData[315] = xx[172];
  motionData[316] = xx[173];
  motionData[317] = xx[174];
  motionData[318] = xx[175];
  motionData[319] = xx[182];
  motionData[320] = xx[183];
  motionData[321] = xx[179];
  motionData[322] = xx[180];
  motionData[323] = xx[181];
  motionData[324] = xx[184];
  motionData[325] = xx[185];
  motionData[326] = xx[188];
  motionData[327] = xx[189];
  motionData[328] = xx[190];
  motionData[329] = xx[195];
  motionData[330] = xx[196];
  motionData[331] = xx[197];
  motionData[332] = xx[198];
  motionData[333] = xx[202] + xx[188];
  motionData[334] = xx[203] + xx[189];
  motionData[335] = xx[204] + xx[190];
  motionData[336] = xx[105];
  motionData[337] = xx[4];
  motionData[338] = xx[4];
  motionData[339] = xx[106];
  motionData[340] = state[91];
  motionData[341] = state[92];
  motionData[342] = state[93];
  motionData[343] = xx[186];
  motionData[344] = - xx[187];
  motionData[345] = xx[191];
  motionData[346] = xx[192];
  motionData[347] = state[91];
  motionData[348] = state[92];
  motionData[349] = state[93];
  motionData[350] = xx[109] * xx[186] + xx[187] * xx[110];
  motionData[351] = xx[186] * xx[110] - xx[109] * xx[187];
  motionData[352] = xx[109] * xx[191] + xx[192] * xx[110];
  motionData[353] = xx[109] * xx[192] - xx[191] * xx[110];
  motionData[354] = state[91];
  motionData[355] = state[92];
  motionData[356] = state[93];
  motionData[357] = xx[121];
  motionData[358] = xx[124];
  motionData[359] = xx[125];
  motionData[360] = xx[119];
  motionData[361] = xx[193];
  motionData[362] = xx[194];
  motionData[363] = xx[208];
  motionData[364] = xx[213];
  motionData[365] = xx[214];
  motionData[366] = xx[215];
  motionData[367] = xx[216];
  motionData[368] = xx[223];
  motionData[369] = xx[224];
  motionData[370] = xx[220];
  motionData[371] = xx[221];
  motionData[372] = xx[222];
  motionData[373] = xx[225];
  motionData[374] = xx[226];
  motionData[375] = xx[229];
  motionData[376] = xx[230];
  motionData[377] = xx[231];
  motionData[378] = xx[236];
  motionData[379] = xx[237];
  motionData[380] = xx[238];
  motionData[381] = xx[239];
  motionData[382] = xx[243] + xx[229];
  motionData[383] = xx[244] + xx[230];
  motionData[384] = xx[245] + xx[231];
  motionData[385] = xx[111];
  motionData[386] = xx[4];
  motionData[387] = xx[4];
  motionData[388] = xx[112];
  motionData[389] = state[103];
  motionData[390] = state[104];
  motionData[391] = state[105];
  motionData[392] = xx[227];
  motionData[393] = - xx[228];
  motionData[394] = xx[232];
  motionData[395] = xx[233];
  motionData[396] = state[103];
  motionData[397] = state[104];
  motionData[398] = state[105];
  motionData[399] = xx[10] * xx[227] + xx[228] * xx[115];
  motionData[400] = xx[227] * xx[115] - xx[10] * xx[228];
  motionData[401] = xx[10] * xx[232] + xx[233] * xx[115];
  motionData[402] = xx[10] * xx[233] - xx[232] * xx[115];
  motionData[403] = state[103];
  motionData[404] = state[104];
  motionData[405] = state[105];
  motionData[406] = xx[121];
  motionData[407] = xx[124];
  motionData[408] = xx[125];
  motionData[409] = xx[119];
  motionData[410] = xx[234];
  motionData[411] = xx[235];
  motionData[412] = xx[249];
  motionData[413] = xx[254];
  motionData[414] = xx[255];
  motionData[415] = xx[256];
  motionData[416] = xx[257];
  motionData[417] = xx[126];
  motionData[418] = xx[127];
  motionData[419] = xx[128];
  motionData[420] = xx[129];
  motionData[421] = xx[261];
  motionData[422] = xx[262];
  motionData[423] = xx[263];
  motionData[424] = xx[266];
  motionData[425] = xx[267];
  motionData[426] = xx[268];
  motionData[427] = xx[273];
  motionData[428] = xx[274];
  motionData[429] = xx[275];
  motionData[430] = xx[276];
  motionData[431] = xx[280] + xx[266];
  motionData[432] = xx[281] + xx[267];
  motionData[433] = xx[282] + xx[268];
  motionData[434] = - xx[265];
  motionData[435] = xx[269];
  motionData[436] = xx[269];
  motionData[437] = xx[265];
  motionData[438] = xx[270];
  motionData[439] = xx[283];
  motionData[440] = xx[15];
  motionData[441] = - (xx[20] + xx[264]);
  motionData[442] = xx[272] - xx[284];
  motionData[443] = xx[272] + xx[284];
  motionData[444] = xx[20] - xx[264];
  motionData[445] = xx[16] * (xx[286] - xx[286]) + xx[270];
  motionData[446] = (xx[286] + xx[286]) * xx[16] + xx[283];
  motionData[447] = rtdvd[22] - (xx[287] + xx[287]) * xx[16] + xx[15];
  motionData[448] = - xx[288];
  motionData[449] = xx[289];
  motionData[450] = xx[289];
  motionData[451] = xx[288];
  motionData[452] = xx[285];
  motionData[453] = xx[291];
  motionData[454] = xx[36];
  motionData[455] = - (xx[29] + xx[40]);
  motionData[456] = xx[290] - xx[292];
  motionData[457] = xx[290] + xx[292];
  motionData[458] = xx[29] - xx[40];
  motionData[459] = xx[16] * (xx[294] - xx[294]) + xx[285];
  motionData[460] = (xx[294] + xx[294]) * xx[16] + xx[291];
  motionData[461] = rtdvd[87] - (xx[295] + xx[295]) * xx[16] + xx[36];
  motionData[462] = - xx[296];
  motionData[463] = xx[297];
  motionData[464] = xx[297];
  motionData[465] = xx[296];
  motionData[466] = xx[293];
  motionData[467] = xx[299];
  motionData[468] = xx[58];
  motionData[469] = - (xx[48] + xx[51]);
  motionData[470] = xx[62] - xx[298];
  motionData[471] = xx[62] + xx[298];
  motionData[472] = xx[48] - xx[51];
  motionData[473] = xx[16] * (xx[301] - xx[301]) + xx[293];
  motionData[474] = (xx[301] + xx[301]) * xx[16] + xx[299];
  motionData[475] = rtdvd[150] - (xx[302] + xx[302]) * xx[16] + xx[58];
  motionData[476] = - xx[303];
  motionData[477] = xx[304];
  motionData[478] = xx[304];
  motionData[479] = xx[303];
  motionData[480] = xx[300];
  motionData[481] = xx[306];
  motionData[482] = xx[78];
  motionData[483] = - (xx[69] + xx[71]);
  motionData[484] = xx[82] - xx[305];
  motionData[485] = xx[82] + xx[305];
  motionData[486] = xx[69] - xx[71];
  motionData[487] = xx[16] * (xx[308] - xx[308]) + xx[300];
  motionData[488] = (xx[308] + xx[308]) * xx[16] + xx[306];
  motionData[489] = rtdvd[213] - (xx[309] + xx[309]) * xx[16] + xx[78];
  motionData[490] = state[10];
  motionData[491] = state[11];
  motionData[492] = state[12];
  motionData[493] = xx[313];
  motionData[494] = xx[314];
  motionData[495] = xx[315];
  motionData[496] = xx[310];
  motionData[497] = xx[312];
  motionData[498] = xx[311];
  motionData[499] = xx[324];
  motionData[500] = xx[320];
  motionData[501] = xx[307];
  motionData[502] = xx[325];
  motionData[503] = xx[319];
  motionData[504] = xx[327];
  motionData[505] = xx[130];
  motionData[506] = xx[329];
  motionData[507] = xx[330];
  motionData[508] = xx[131];
  motionData[509] = xx[138];
  motionData[510] = xx[139];
  motionData[511] = xx[132];
  motionData[512] = xx[328];
  motionData[513] = xx[133];
  motionData[514] = xx[334] + rtdvd[33] * state[24];
  motionData[515] = xx[335] + rtdvd[34] * state[24];
  motionData[516] = xx[336] + rtdvd[35] * state[24];
  motionData[517] = xx[331] + rtdvd[36] * state[24];
  motionData[518] = xx[332] + rtdvd[37] * state[24];
  motionData[519] = xx[333] + rtdvd[38] * state[24];
  motionData[520] = xx[310];
  motionData[521] = xx[312];
  motionData[522] = xx[311];
  motionData[523] = xx[338];
  motionData[524] = xx[162];
  motionData[525] = xx[140];
  motionData[526] = xx[339];
  motionData[527] = xx[161];
  motionData[528] = xx[341];
  motionData[529] = xx[163];
  motionData[530] = xx[343];
  motionData[531] = xx[344];
  motionData[532] = xx[168];
  motionData[533] = xx[171];
  motionData[534] = xx[176];
  motionData[535] = xx[169];
  motionData[536] = xx[326];
  motionData[537] = xx[170];
  motionData[538] = xx[348] + rtdvd[98] * state[36];
  motionData[539] = xx[349] + rtdvd[99] * state[36];
  motionData[540] = xx[350] + rtdvd[100] * state[36];
  motionData[541] = xx[345] + rtdvd[101] * state[36];
  motionData[542] = xx[346] + rtdvd[102] * state[36];
  motionData[543] = xx[347] + rtdvd[103] * state[36];
  motionData[544] = xx[310];
  motionData[545] = xx[312];
  motionData[546] = xx[311];
  motionData[547] = xx[206];
  motionData[548] = xx[200];
  motionData[549] = xx[177];
  motionData[550] = xx[351];
  motionData[551] = xx[178];
  motionData[552] = xx[353];
  motionData[553] = xx[199];
  motionData[554] = xx[355];
  motionData[555] = xx[356];
  motionData[556] = xx[201];
  motionData[557] = xx[209];
  motionData[558] = xx[210];
  motionData[559] = xx[205];
  motionData[560] = xx[217];
  motionData[561] = xx[207];
  motionData[562] = xx[360] + rtdvd[161] * state[48];
  motionData[563] = xx[361] + rtdvd[162] * state[48];
  motionData[564] = xx[362] + rtdvd[163] * state[48];
  motionData[565] = xx[357] + rtdvd[164] * state[48];
  motionData[566] = xx[358] + rtdvd[165] * state[48];
  motionData[567] = xx[359] + rtdvd[166] * state[48];
  motionData[568] = xx[310];
  motionData[569] = xx[312];
  motionData[570] = xx[311];
  motionData[571] = xx[5];
  motionData[572] = xx[219];
  motionData[573] = xx[12];
  motionData[574] = xx[240];
  motionData[575] = xx[211];
  motionData[576] = xx[242];
  motionData[577] = xx[212];
  motionData[578] = xx[247];
  motionData[579] = xx[248];
  motionData[580] = xx[218];
  motionData[581] = xx[250];
  motionData[582] = xx[251];
  motionData[583] = xx[241];
  motionData[584] = xx[258];
  motionData[585] = xx[246];
  motionData[586] = xx[321] + rtdvd[224] * state[60];
  motionData[587] = xx[322] + rtdvd[225] * state[60];
  motionData[588] = xx[323] + rtdvd[226] * state[60];
  motionData[589] = xx[316] + rtdvd[227] * state[60];
  motionData[590] = xx[317] + rtdvd[228] * state[60];
  motionData[591] = xx[318] + rtdvd[229] * state[60];
  motionData[592] = xx[4];
  motionData[593] = xx[4];
  motionData[594] = xx[4];
  motionData[595] = - (0.7502690808970445 * state[64] + 0.62522423408087 *
                       state[65] + 0.2149208304652991 * state[66]);
  motionData[596] = 0.6401843996644798 * state[64] - 0.7682212795973762 * state
    [65];
  motionData[597] = 0.9766314743198204 * state[66] - (0.1651067553921828 *
    state[64] + 0.1375889628268189 * state[65]);
  motionData[598] = xx[4];
  motionData[599] = xx[4];
  motionData[600] = xx[4];
  motionData[601] = state[70];
  motionData[602] = state[71];
  motionData[603] = state[72];
  motionData[604] = xx[4];
  motionData[605] = xx[4];
  motionData[606] = state[74];
  motionData[607] = xx[259];
  motionData[608] = xx[260];
  motionData[609] = state[72];
  motionData[610] = - xx[253];
  motionData[611] = state[76];
  motionData[612] = xx[271];
  motionData[613] = xx[278];
  motionData[614] = xx[260];
  motionData[615] = xx[279];
  motionData[616] = state[78] - xx[253];
  motionData[617] = state[76] + xx[16] * (xx[93] * xx[252] - xx[277] * xx[98]);
  motionData[618] = xx[271] - (xx[93] * xx[277] + xx[252] * xx[98]) * xx[16];
  motionData[619] = xx[278];
  motionData[620] = xx[260] + xx[16] * (xx[93] * xx[337] - xx[340] * xx[98]);
  motionData[621] = xx[279] - (xx[93] * xx[340] + xx[337] * xx[98]) * xx[16];
  motionData[622] = xx[4];
  motionData[623] = xx[4];
  motionData[624] = xx[4];
  motionData[625] = state[82];
  motionData[626] = state[83];
  motionData[627] = state[84];
  motionData[628] = xx[4];
  motionData[629] = xx[4];
  motionData[630] = state[86];
  motionData[631] = xx[354];
  motionData[632] = xx[363];
  motionData[633] = state[84];
  motionData[634] = - xx[352];
  motionData[635] = state[88];
  motionData[636] = xx[364];
  motionData[637] = xx[366];
  motionData[638] = xx[363];
  motionData[639] = xx[367];
  motionData[640] = state[90] - xx[352];
  motionData[641] = state[88] + xx[16] * (xx[103] * xx[342] - xx[365] * xx[104]);
  motionData[642] = xx[364] - (xx[103] * xx[365] + xx[342] * xx[104]) * xx[16];
  motionData[643] = xx[366];
  motionData[644] = xx[363] + xx[16] * (xx[103] * xx[368] - xx[369] * xx[104]);
  motionData[645] = xx[367] - (xx[103] * xx[369] + xx[368] * xx[104]) * xx[16];
  motionData[646] = xx[4];
  motionData[647] = xx[4];
  motionData[648] = xx[4];
  motionData[649] = state[94];
  motionData[650] = state[95];
  motionData[651] = state[96];
  motionData[652] = xx[4];
  motionData[653] = xx[4];
  motionData[654] = state[98];
  motionData[655] = xx[372];
  motionData[656] = xx[373];
  motionData[657] = state[96];
  motionData[658] = - xx[371];
  motionData[659] = state[100];
  motionData[660] = xx[374];
  motionData[661] = xx[376];
  motionData[662] = xx[373];
  motionData[663] = xx[377];
  motionData[664] = state[102] - xx[371];
  motionData[665] = state[100] + xx[16] * (xx[109] * xx[370] - xx[375] * xx[110]);
  motionData[666] = xx[374] - (xx[109] * xx[375] + xx[370] * xx[110]) * xx[16];
  motionData[667] = xx[376];
  motionData[668] = xx[373] + xx[16] * (xx[109] * xx[378] - xx[379] * xx[110]);
  motionData[669] = xx[377] - (xx[109] * xx[379] + xx[378] * xx[110]) * xx[16];
  motionData[670] = xx[4];
  motionData[671] = xx[4];
  motionData[672] = xx[4];
  motionData[673] = state[106];
  motionData[674] = state[107];
  motionData[675] = state[108];
  motionData[676] = xx[4];
  motionData[677] = xx[4];
  motionData[678] = state[110];
  motionData[679] = xx[382];
  motionData[680] = xx[383];
  motionData[681] = state[108];
  motionData[682] = - xx[381];
  motionData[683] = state[112];
  motionData[684] = xx[384];
  motionData[685] = xx[386];
  motionData[686] = xx[383];
  motionData[687] = xx[387];
  motionData[688] = state[114] - xx[381];
  motionData[689] = state[112] + xx[16] * (xx[10] * xx[380] - xx[385] * xx[115]);
  motionData[690] = xx[384] - (xx[10] * xx[385] + xx[380] * xx[115]) * xx[16];
  motionData[691] = xx[386];
  motionData[692] = xx[383] + xx[16] * (xx[10] * xx[388] - xx[389] * xx[115]);
  motionData[693] = xx[387] - (xx[10] * xx[389] + xx[388] * xx[115]) * xx[16];
}

static size_t computeAssemblyPosError_0(const RuntimeDerivedValuesBundle *rtdv,
  const int *modeVector, const double *motionData, double *error)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[4];
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  xx[0] = 5.118163733215264;
  xx[1] = xx[0] * motionData[121];
  xx[2] = xx[0] * motionData[122];
  xx[3] = 2.0;
  error[0] = motionData[4] - (motionData[123] - (xx[1] * motionData[121] + xx[2]
    * motionData[122]) * xx[3]) - xx[0];
  error[1] = motionData[5] - ((xx[2] * motionData[119] + xx[1] * motionData[120])
    * xx[3] + motionData[124]);
  error[2] = motionData[6] - (xx[3] * (xx[2] * motionData[120] - xx[1] *
    motionData[119]) + motionData[125]);
  return 3;
}

size_t KIMMCar_ff62ad8f_49_computeAssemblyPosError(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const int *modeVector,
  const double *motionData, double *error)
{
  (void) mech;
  (void)rtdv;
  (void) modeVector;
  (void) motionData;
  (void) error;
  switch (constraintIdx)
  {
   case 0:
    return computeAssemblyPosError_0(rtdv, modeVector, motionData, error);
  }

  return 0;
}

static size_t computeAssemblyJacobian_0(const RuntimeDerivedValuesBundle *rtdv,
  const double *state, const int *modeVector, const double *motionData, double
  *J)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[4];
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
  xx[0] = 1.0;
  xx[1] = 0.0;
  xx[2] = 9.87654321;
  xx[3] = - xx[0];
  J[0] = xx[0];
  J[1] = xx[1];
  J[2] = xx[1];
  J[3] = xx[1];
  J[4] = xx[1];
  J[5] = xx[1];
  J[30] = xx[3];
  J[31] = xx[1];
  J[32] = xx[1];
  J[57] = xx[1];
  J[58] = xx[0];
  J[59] = xx[1];
  J[60] = xx[1];
  J[61] = xx[1];
  J[62] = xx[1];
  J[87] = xx[1];
  J[88] = xx[3];
  J[89] = xx[1];
  J[114] = xx[1];
  J[115] = xx[1];
  J[116] = xx[0];
  J[117] = xx[1];
  J[118] = xx[1];
  J[119] = xx[1];
  J[144] = xx[1];
  J[145] = xx[1];
  J[146] = xx[3];
  return 3;
}

size_t KIMMCar_ff62ad8f_49_computeAssemblyJacobian(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, boolean_T
  forVelocitySatisfaction, const double *state, const int *modeVector, const
  double *motionData, double *J)
{
  (void) mech;
  (void) rtdv;
  (void) state;
  (void) modeVector;
  (void) forVelocitySatisfaction;
  (void) motionData;
  (void) J;
  switch (constraintIdx)
  {
   case 0:
    return computeAssemblyJacobian_0(rtdv, state, modeVector, motionData, J);
  }

  return 0;
}

size_t KIMMCar_ff62ad8f_49_computeFullAssemblyJacobian(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, const int *modeVector,
  const double *motionData, double *J)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[4];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
  xx[0] = 1.0;
  xx[1] = 0.0;
  xx[2] = 9.87654321;
  xx[3] = - xx[0];
  J[0] = xx[0];
  J[1] = xx[1];
  J[2] = xx[1];
  J[3] = xx[1];
  J[4] = xx[1];
  J[5] = xx[1];
  J[30] = xx[3];
  J[31] = xx[1];
  J[32] = xx[1];
  J[57] = xx[1];
  J[58] = xx[0];
  J[59] = xx[1];
  J[60] = xx[1];
  J[61] = xx[1];
  J[62] = xx[1];
  J[87] = xx[1];
  J[88] = xx[3];
  J[89] = xx[1];
  J[114] = xx[1];
  J[115] = xx[1];
  J[116] = xx[0];
  J[117] = xx[1];
  J[118] = xx[1];
  J[119] = xx[1];
  J[144] = xx[1];
  J[145] = xx[1];
  J[146] = xx[3];
  return 3;
}

static boolean_T isInKinematicSingularity_0(const RuntimeDerivedValuesBundle
  *rtdv, const int *modeVector, const double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  (void) motionData;
  return 0;
}

boolean_T KIMMCar_ff62ad8f_49_isInKinematicSingularity(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const int *modeVector,
  const double *motionData)
{
  (void) mech;
  (void) rtdv;
  (void) modeVector;
  (void) motionData;
  switch (constraintIdx)
  {
   case 0:
    return isInKinematicSingularity_0(rtdv, modeVector, motionData);
  }

  return 0;
}

void KIMMCar_ff62ad8f_49_convertStateVector(const void *asmMech, const
  RuntimeDerivedValuesBundle *rtdv, const void *simMech, const double *asmState,
  const int *asmModeVector, const int *simModeVector, double *simState)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[16];
  (void) asmMech;
  (void) rtdvd;
  (void) rtdvi;
  (void) simMech;
  (void) asmModeVector;
  (void) simModeVector;
  xx[0] = 0.338430610991899;
  xx[1] = 0.1016374984694517;
  xx[2] = 0.03679784973285759;
  xx[3] = - 0.934762247153553;
  xx[4] = - xx[0];
  xx[5] = xx[1];
  xx[6] = xx[2];
  xx[7] = xx[3];
  xx[8] = - asmState[3];
  xx[9] = - asmState[4];
  xx[10] = - asmState[5];
  xx[11] = - asmState[6];
  pm_math_Quaternion_inverseCompose_ra(xx + 0, xx + 8, xx + 12);
  pm_math_Quaternion_inverseCompose_ra(xx + 4, xx + 12, xx + 0);
  simState[0] = asmState[61];
  simState[1] = asmState[62];
  simState[2] = asmState[63];
  simState[3] = asmState[64];
  simState[4] = asmState[65];
  simState[5] = asmState[66];
  simState[6] = xx[0];
  simState[7] = xx[1];
  simState[8] = xx[2];
  simState[9] = xx[3];
  simState[10] = asmState[10];
  simState[11] = asmState[11];
  simState[12] = asmState[12];
  simState[13] = asmState[13];
  simState[14] = asmState[14];
  simState[15] = asmState[15];
  simState[16] = asmState[16];
  simState[17] = asmState[17];
  simState[18] = asmState[18];
  simState[19] = asmState[19];
  simState[20] = asmState[20];
  simState[21] = asmState[21];
  simState[22] = asmState[22];
  simState[23] = asmState[23];
  simState[24] = asmState[24];
  simState[25] = asmState[25];
  simState[26] = asmState[26];
  simState[27] = asmState[27];
  simState[28] = asmState[28];
  simState[29] = asmState[29];
  simState[30] = asmState[30];
  simState[31] = asmState[31];
  simState[32] = asmState[32];
  simState[33] = asmState[33];
  simState[34] = asmState[34];
  simState[35] = asmState[35];
  simState[36] = asmState[36];
  simState[37] = asmState[37];
  simState[38] = asmState[38];
  simState[39] = asmState[39];
  simState[40] = asmState[40];
  simState[41] = asmState[41];
  simState[42] = asmState[42];
  simState[43] = asmState[43];
  simState[44] = asmState[44];
  simState[45] = asmState[45];
  simState[46] = asmState[46];
  simState[47] = asmState[47];
  simState[48] = asmState[48];
  simState[49] = asmState[49];
  simState[50] = asmState[50];
  simState[51] = asmState[51];
  simState[52] = asmState[52];
  simState[53] = asmState[53];
  simState[54] = asmState[54];
  simState[55] = asmState[55];
  simState[56] = asmState[56];
  simState[57] = asmState[57];
  simState[58] = asmState[58];
  simState[59] = asmState[59];
  simState[60] = asmState[60];
  simState[61] = asmState[67];
  simState[62] = asmState[68];
  simState[63] = asmState[69];
  simState[64] = asmState[70];
  simState[65] = asmState[71];
  simState[66] = asmState[72];
  simState[67] = asmState[73];
  simState[68] = asmState[74];
  simState[69] = asmState[75];
  simState[70] = asmState[76];
  simState[71] = asmState[77];
  simState[72] = asmState[78];
  simState[73] = asmState[79];
  simState[74] = asmState[80];
  simState[75] = asmState[81];
  simState[76] = asmState[82];
  simState[77] = asmState[83];
  simState[78] = asmState[84];
  simState[79] = asmState[85];
  simState[80] = asmState[86];
  simState[81] = asmState[87];
  simState[82] = asmState[88];
  simState[83] = asmState[89];
  simState[84] = asmState[90];
  simState[85] = asmState[91];
  simState[86] = asmState[92];
  simState[87] = asmState[93];
  simState[88] = asmState[94];
  simState[89] = asmState[95];
  simState[90] = asmState[96];
  simState[91] = asmState[97];
  simState[92] = asmState[98];
  simState[93] = asmState[99];
  simState[94] = asmState[100];
  simState[95] = asmState[101];
  simState[96] = asmState[102];
  simState[97] = asmState[103];
  simState[98] = asmState[104];
  simState[99] = asmState[105];
  simState[100] = asmState[106];
  simState[101] = asmState[107];
  simState[102] = asmState[108];
  simState[103] = asmState[109];
  simState[104] = asmState[110];
  simState[105] = asmState[111];
  simState[106] = asmState[112];
  simState[107] = asmState[113];
  simState[108] = asmState[114];
}
