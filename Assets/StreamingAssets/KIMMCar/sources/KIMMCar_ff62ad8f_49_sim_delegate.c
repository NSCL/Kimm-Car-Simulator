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

void KIMMCar_ff62ad8f_49_resetSimStateVector(const void *mech, double *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = xx[0];
  state[4] = xx[0];
  state[5] = xx[0];
  state[6] = 1.0;
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
}

static void perturbSimJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbSimJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[3] = state[3] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_0_1(double mag, double *state)
{
  state[1] = state[1] + mag;
}

static void perturbSimJointPrimitiveState_0_1v(double mag, double *state)
{
  state[1] = state[1] + mag;
  state[4] = state[4] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_0_2(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbSimJointPrimitiveState_0_2v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[5] = state[5] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_1_0(double mag, double *state)
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
  xx[0] = state[6];
  xx[1] = state[7];
  xx[2] = state[8];
  xx[3] = state[9];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 0, xx + 4);
  state[6] = xx[4];
  state[7] = xx[5];
  state[8] = xx[6];
  state[9] = xx[7];
}

static void perturbSimJointPrimitiveState_1_0v(double mag, double *state)
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
  xx[3] = state[6];
  xx[4] = state[7];
  xx[5] = state[8];
  xx[6] = state[9];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 3, xx + 7);
  state[6] = xx[7];
  state[7] = xx[8];
  state[8] = xx[9];
  state[9] = xx[10];
  state[10] = state[10] + 1.2 * mag;
  state[11] = state[11] - xx[2];
  state[12] = state[12] + 0.9 * mag;
}

static void perturbSimJointPrimitiveState_2_0(double mag, double *state)
{
  state[13] = state[13] + mag;
}

static void perturbSimJointPrimitiveState_2_0v(double mag, double *state)
{
  state[13] = state[13] + mag;
  state[16] = state[16] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_2_1(double mag, double *state)
{
  state[14] = state[14] + mag;
}

static void perturbSimJointPrimitiveState_2_1v(double mag, double *state)
{
  state[14] = state[14] + mag;
  state[17] = state[17] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_2_2(double mag, double *state)
{
  state[15] = state[15] + mag;
}

static void perturbSimJointPrimitiveState_2_2v(double mag, double *state)
{
  state[15] = state[15] + mag;
  state[18] = state[18] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_3_0(double mag, double *state)
{
  state[19] = state[19] + mag;
}

static void perturbSimJointPrimitiveState_3_0v(double mag, double *state)
{
  state[19] = state[19] + mag;
  state[20] = state[20] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_4_0(double mag, double *state)
{
  state[21] = state[21] + mag;
}

static void perturbSimJointPrimitiveState_4_0v(double mag, double *state)
{
  state[21] = state[21] + mag;
  state[22] = state[22] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_5_0(double mag, double *state)
{
  state[23] = state[23] + mag;
}

static void perturbSimJointPrimitiveState_5_0v(double mag, double *state)
{
  state[23] = state[23] + mag;
  state[24] = state[24] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_6_0(double mag, double *state)
{
  state[25] = state[25] + mag;
}

static void perturbSimJointPrimitiveState_6_0v(double mag, double *state)
{
  state[25] = state[25] + mag;
  state[28] = state[28] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_6_1(double mag, double *state)
{
  state[26] = state[26] + mag;
}

static void perturbSimJointPrimitiveState_6_1v(double mag, double *state)
{
  state[26] = state[26] + mag;
  state[29] = state[29] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_6_2(double mag, double *state)
{
  state[27] = state[27] + mag;
}

static void perturbSimJointPrimitiveState_6_2v(double mag, double *state)
{
  state[27] = state[27] + mag;
  state[30] = state[30] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_7_0(double mag, double *state)
{
  state[31] = state[31] + mag;
}

static void perturbSimJointPrimitiveState_7_0v(double mag, double *state)
{
  state[31] = state[31] + mag;
  state[32] = state[32] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_8_0(double mag, double *state)
{
  state[33] = state[33] + mag;
}

static void perturbSimJointPrimitiveState_8_0v(double mag, double *state)
{
  state[33] = state[33] + mag;
  state[34] = state[34] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_9_0(double mag, double *state)
{
  state[35] = state[35] + mag;
}

static void perturbSimJointPrimitiveState_9_0v(double mag, double *state)
{
  state[35] = state[35] + mag;
  state[36] = state[36] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_10_0(double mag, double *state)
{
  state[37] = state[37] + mag;
}

static void perturbSimJointPrimitiveState_10_0v(double mag, double *state)
{
  state[37] = state[37] + mag;
  state[40] = state[40] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_10_1(double mag, double *state)
{
  state[38] = state[38] + mag;
}

static void perturbSimJointPrimitiveState_10_1v(double mag, double *state)
{
  state[38] = state[38] + mag;
  state[41] = state[41] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_10_2(double mag, double *state)
{
  state[39] = state[39] + mag;
}

static void perturbSimJointPrimitiveState_10_2v(double mag, double *state)
{
  state[39] = state[39] + mag;
  state[42] = state[42] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_11_0(double mag, double *state)
{
  state[43] = state[43] + mag;
}

static void perturbSimJointPrimitiveState_11_0v(double mag, double *state)
{
  state[43] = state[43] + mag;
  state[44] = state[44] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_12_0(double mag, double *state)
{
  state[45] = state[45] + mag;
}

static void perturbSimJointPrimitiveState_12_0v(double mag, double *state)
{
  state[45] = state[45] + mag;
  state[46] = state[46] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_13_0(double mag, double *state)
{
  state[47] = state[47] + mag;
}

static void perturbSimJointPrimitiveState_13_0v(double mag, double *state)
{
  state[47] = state[47] + mag;
  state[48] = state[48] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_14_0(double mag, double *state)
{
  state[49] = state[49] + mag;
}

static void perturbSimJointPrimitiveState_14_0v(double mag, double *state)
{
  state[49] = state[49] + mag;
  state[52] = state[52] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_14_1(double mag, double *state)
{
  state[50] = state[50] + mag;
}

static void perturbSimJointPrimitiveState_14_1v(double mag, double *state)
{
  state[50] = state[50] + mag;
  state[53] = state[53] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_14_2(double mag, double *state)
{
  state[51] = state[51] + mag;
}

static void perturbSimJointPrimitiveState_14_2v(double mag, double *state)
{
  state[51] = state[51] + mag;
  state[54] = state[54] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_15_0(double mag, double *state)
{
  state[55] = state[55] + mag;
}

static void perturbSimJointPrimitiveState_15_0v(double mag, double *state)
{
  state[55] = state[55] + mag;
  state[56] = state[56] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_16_0(double mag, double *state)
{
  state[57] = state[57] + mag;
}

static void perturbSimJointPrimitiveState_16_0v(double mag, double *state)
{
  state[57] = state[57] + mag;
  state[58] = state[58] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_17_0(double mag, double *state)
{
  state[59] = state[59] + mag;
}

static void perturbSimJointPrimitiveState_17_0v(double mag, double *state)
{
  state[59] = state[59] + mag;
  state[60] = state[60] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_18_0(double mag, double *state)
{
  state[61] = state[61] + mag;
}

static void perturbSimJointPrimitiveState_18_0v(double mag, double *state)
{
  state[61] = state[61] + mag;
  state[64] = state[64] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_18_1(double mag, double *state)
{
  state[62] = state[62] + mag;
}

static void perturbSimJointPrimitiveState_18_1v(double mag, double *state)
{
  state[62] = state[62] + mag;
  state[65] = state[65] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_18_2(double mag, double *state)
{
  state[63] = state[63] + mag;
}

static void perturbSimJointPrimitiveState_18_2v(double mag, double *state)
{
  state[63] = state[63] + mag;
  state[66] = state[66] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_19_0(double mag, double *state)
{
  state[67] = state[67] + mag;
}

static void perturbSimJointPrimitiveState_19_0v(double mag, double *state)
{
  state[67] = state[67] + mag;
  state[68] = state[68] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_20_0(double mag, double *state)
{
  state[69] = state[69] + mag;
}

static void perturbSimJointPrimitiveState_20_0v(double mag, double *state)
{
  state[69] = state[69] + mag;
  state[70] = state[70] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_21_0(double mag, double *state)
{
  state[71] = state[71] + mag;
}

static void perturbSimJointPrimitiveState_21_0v(double mag, double *state)
{
  state[71] = state[71] + mag;
  state[72] = state[72] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_22_0(double mag, double *state)
{
  state[73] = state[73] + mag;
}

static void perturbSimJointPrimitiveState_22_0v(double mag, double *state)
{
  state[73] = state[73] + mag;
  state[76] = state[76] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_22_1(double mag, double *state)
{
  state[74] = state[74] + mag;
}

static void perturbSimJointPrimitiveState_22_1v(double mag, double *state)
{
  state[74] = state[74] + mag;
  state[77] = state[77] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_22_2(double mag, double *state)
{
  state[75] = state[75] + mag;
}

static void perturbSimJointPrimitiveState_22_2v(double mag, double *state)
{
  state[75] = state[75] + mag;
  state[78] = state[78] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_23_0(double mag, double *state)
{
  state[79] = state[79] + mag;
}

static void perturbSimJointPrimitiveState_23_0v(double mag, double *state)
{
  state[79] = state[79] + mag;
  state[80] = state[80] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_24_0(double mag, double *state)
{
  state[81] = state[81] + mag;
}

static void perturbSimJointPrimitiveState_24_0v(double mag, double *state)
{
  state[81] = state[81] + mag;
  state[82] = state[82] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_25_0(double mag, double *state)
{
  state[83] = state[83] + mag;
}

static void perturbSimJointPrimitiveState_25_0v(double mag, double *state)
{
  state[83] = state[83] + mag;
  state[84] = state[84] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_26_0(double mag, double *state)
{
  state[85] = state[85] + mag;
}

static void perturbSimJointPrimitiveState_26_0v(double mag, double *state)
{
  state[85] = state[85] + mag;
  state[88] = state[88] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_26_1(double mag, double *state)
{
  state[86] = state[86] + mag;
}

static void perturbSimJointPrimitiveState_26_1v(double mag, double *state)
{
  state[86] = state[86] + mag;
  state[89] = state[89] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_26_2(double mag, double *state)
{
  state[87] = state[87] + mag;
}

static void perturbSimJointPrimitiveState_26_2v(double mag, double *state)
{
  state[87] = state[87] + mag;
  state[90] = state[90] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_27_0(double mag, double *state)
{
  state[91] = state[91] + mag;
}

static void perturbSimJointPrimitiveState_27_0v(double mag, double *state)
{
  state[91] = state[91] + mag;
  state[92] = state[92] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_28_0(double mag, double *state)
{
  state[93] = state[93] + mag;
}

static void perturbSimJointPrimitiveState_28_0v(double mag, double *state)
{
  state[93] = state[93] + mag;
  state[94] = state[94] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_29_0(double mag, double *state)
{
  state[95] = state[95] + mag;
}

static void perturbSimJointPrimitiveState_29_0v(double mag, double *state)
{
  state[95] = state[95] + mag;
  state[96] = state[96] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_30_0(double mag, double *state)
{
  state[97] = state[97] + mag;
}

static void perturbSimJointPrimitiveState_30_0v(double mag, double *state)
{
  state[97] = state[97] + mag;
  state[100] = state[100] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_30_1(double mag, double *state)
{
  state[98] = state[98] + mag;
}

static void perturbSimJointPrimitiveState_30_1v(double mag, double *state)
{
  state[98] = state[98] + mag;
  state[101] = state[101] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_30_2(double mag, double *state)
{
  state[99] = state[99] + mag;
}

static void perturbSimJointPrimitiveState_30_2v(double mag, double *state)
{
  state[99] = state[99] + mag;
  state[102] = state[102] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_31_0(double mag, double *state)
{
  state[103] = state[103] + mag;
}

static void perturbSimJointPrimitiveState_31_0v(double mag, double *state)
{
  state[103] = state[103] + mag;
  state[104] = state[104] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_32_0(double mag, double *state)
{
  state[105] = state[105] + mag;
}

static void perturbSimJointPrimitiveState_32_0v(double mag, double *state)
{
  state[105] = state[105] + mag;
  state[106] = state[106] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_33_0(double mag, double *state)
{
  state[107] = state[107] + mag;
}

static void perturbSimJointPrimitiveState_33_0v(double mag, double *state)
{
  state[107] = state[107] + mag;
  state[108] = state[108] - 0.875 * mag;
}

void KIMMCar_ff62ad8f_49_perturbSimJointPrimitiveState(const void *mech, size_t
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
    perturbSimJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbSimJointPrimitiveState_0_0v(mag, state);
    break;

   case 2:
    perturbSimJointPrimitiveState_0_1(mag, state);
    break;

   case 3:
    perturbSimJointPrimitiveState_0_1v(mag, state);
    break;

   case 4:
    perturbSimJointPrimitiveState_0_2(mag, state);
    break;

   case 5:
    perturbSimJointPrimitiveState_0_2v(mag, state);
    break;

   case 12:
    perturbSimJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbSimJointPrimitiveState_1_0v(mag, state);
    break;

   case 24:
    perturbSimJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbSimJointPrimitiveState_2_0v(mag, state);
    break;

   case 26:
    perturbSimJointPrimitiveState_2_1(mag, state);
    break;

   case 27:
    perturbSimJointPrimitiveState_2_1v(mag, state);
    break;

   case 28:
    perturbSimJointPrimitiveState_2_2(mag, state);
    break;

   case 29:
    perturbSimJointPrimitiveState_2_2v(mag, state);
    break;

   case 36:
    perturbSimJointPrimitiveState_3_0(mag, state);
    break;

   case 37:
    perturbSimJointPrimitiveState_3_0v(mag, state);
    break;

   case 48:
    perturbSimJointPrimitiveState_4_0(mag, state);
    break;

   case 49:
    perturbSimJointPrimitiveState_4_0v(mag, state);
    break;

   case 60:
    perturbSimJointPrimitiveState_5_0(mag, state);
    break;

   case 61:
    perturbSimJointPrimitiveState_5_0v(mag, state);
    break;

   case 72:
    perturbSimJointPrimitiveState_6_0(mag, state);
    break;

   case 73:
    perturbSimJointPrimitiveState_6_0v(mag, state);
    break;

   case 74:
    perturbSimJointPrimitiveState_6_1(mag, state);
    break;

   case 75:
    perturbSimJointPrimitiveState_6_1v(mag, state);
    break;

   case 76:
    perturbSimJointPrimitiveState_6_2(mag, state);
    break;

   case 77:
    perturbSimJointPrimitiveState_6_2v(mag, state);
    break;

   case 84:
    perturbSimJointPrimitiveState_7_0(mag, state);
    break;

   case 85:
    perturbSimJointPrimitiveState_7_0v(mag, state);
    break;

   case 96:
    perturbSimJointPrimitiveState_8_0(mag, state);
    break;

   case 97:
    perturbSimJointPrimitiveState_8_0v(mag, state);
    break;

   case 108:
    perturbSimJointPrimitiveState_9_0(mag, state);
    break;

   case 109:
    perturbSimJointPrimitiveState_9_0v(mag, state);
    break;

   case 120:
    perturbSimJointPrimitiveState_10_0(mag, state);
    break;

   case 121:
    perturbSimJointPrimitiveState_10_0v(mag, state);
    break;

   case 122:
    perturbSimJointPrimitiveState_10_1(mag, state);
    break;

   case 123:
    perturbSimJointPrimitiveState_10_1v(mag, state);
    break;

   case 124:
    perturbSimJointPrimitiveState_10_2(mag, state);
    break;

   case 125:
    perturbSimJointPrimitiveState_10_2v(mag, state);
    break;

   case 132:
    perturbSimJointPrimitiveState_11_0(mag, state);
    break;

   case 133:
    perturbSimJointPrimitiveState_11_0v(mag, state);
    break;

   case 144:
    perturbSimJointPrimitiveState_12_0(mag, state);
    break;

   case 145:
    perturbSimJointPrimitiveState_12_0v(mag, state);
    break;

   case 156:
    perturbSimJointPrimitiveState_13_0(mag, state);
    break;

   case 157:
    perturbSimJointPrimitiveState_13_0v(mag, state);
    break;

   case 168:
    perturbSimJointPrimitiveState_14_0(mag, state);
    break;

   case 169:
    perturbSimJointPrimitiveState_14_0v(mag, state);
    break;

   case 170:
    perturbSimJointPrimitiveState_14_1(mag, state);
    break;

   case 171:
    perturbSimJointPrimitiveState_14_1v(mag, state);
    break;

   case 172:
    perturbSimJointPrimitiveState_14_2(mag, state);
    break;

   case 173:
    perturbSimJointPrimitiveState_14_2v(mag, state);
    break;

   case 180:
    perturbSimJointPrimitiveState_15_0(mag, state);
    break;

   case 181:
    perturbSimJointPrimitiveState_15_0v(mag, state);
    break;

   case 192:
    perturbSimJointPrimitiveState_16_0(mag, state);
    break;

   case 193:
    perturbSimJointPrimitiveState_16_0v(mag, state);
    break;

   case 204:
    perturbSimJointPrimitiveState_17_0(mag, state);
    break;

   case 205:
    perturbSimJointPrimitiveState_17_0v(mag, state);
    break;

   case 216:
    perturbSimJointPrimitiveState_18_0(mag, state);
    break;

   case 217:
    perturbSimJointPrimitiveState_18_0v(mag, state);
    break;

   case 218:
    perturbSimJointPrimitiveState_18_1(mag, state);
    break;

   case 219:
    perturbSimJointPrimitiveState_18_1v(mag, state);
    break;

   case 220:
    perturbSimJointPrimitiveState_18_2(mag, state);
    break;

   case 221:
    perturbSimJointPrimitiveState_18_2v(mag, state);
    break;

   case 228:
    perturbSimJointPrimitiveState_19_0(mag, state);
    break;

   case 229:
    perturbSimJointPrimitiveState_19_0v(mag, state);
    break;

   case 240:
    perturbSimJointPrimitiveState_20_0(mag, state);
    break;

   case 241:
    perturbSimJointPrimitiveState_20_0v(mag, state);
    break;

   case 252:
    perturbSimJointPrimitiveState_21_0(mag, state);
    break;

   case 253:
    perturbSimJointPrimitiveState_21_0v(mag, state);
    break;

   case 264:
    perturbSimJointPrimitiveState_22_0(mag, state);
    break;

   case 265:
    perturbSimJointPrimitiveState_22_0v(mag, state);
    break;

   case 266:
    perturbSimJointPrimitiveState_22_1(mag, state);
    break;

   case 267:
    perturbSimJointPrimitiveState_22_1v(mag, state);
    break;

   case 268:
    perturbSimJointPrimitiveState_22_2(mag, state);
    break;

   case 269:
    perturbSimJointPrimitiveState_22_2v(mag, state);
    break;

   case 276:
    perturbSimJointPrimitiveState_23_0(mag, state);
    break;

   case 277:
    perturbSimJointPrimitiveState_23_0v(mag, state);
    break;

   case 288:
    perturbSimJointPrimitiveState_24_0(mag, state);
    break;

   case 289:
    perturbSimJointPrimitiveState_24_0v(mag, state);
    break;

   case 300:
    perturbSimJointPrimitiveState_25_0(mag, state);
    break;

   case 301:
    perturbSimJointPrimitiveState_25_0v(mag, state);
    break;

   case 312:
    perturbSimJointPrimitiveState_26_0(mag, state);
    break;

   case 313:
    perturbSimJointPrimitiveState_26_0v(mag, state);
    break;

   case 314:
    perturbSimJointPrimitiveState_26_1(mag, state);
    break;

   case 315:
    perturbSimJointPrimitiveState_26_1v(mag, state);
    break;

   case 316:
    perturbSimJointPrimitiveState_26_2(mag, state);
    break;

   case 317:
    perturbSimJointPrimitiveState_26_2v(mag, state);
    break;

   case 324:
    perturbSimJointPrimitiveState_27_0(mag, state);
    break;

   case 325:
    perturbSimJointPrimitiveState_27_0v(mag, state);
    break;

   case 336:
    perturbSimJointPrimitiveState_28_0(mag, state);
    break;

   case 337:
    perturbSimJointPrimitiveState_28_0v(mag, state);
    break;

   case 348:
    perturbSimJointPrimitiveState_29_0(mag, state);
    break;

   case 349:
    perturbSimJointPrimitiveState_29_0v(mag, state);
    break;

   case 360:
    perturbSimJointPrimitiveState_30_0(mag, state);
    break;

   case 361:
    perturbSimJointPrimitiveState_30_0v(mag, state);
    break;

   case 362:
    perturbSimJointPrimitiveState_30_1(mag, state);
    break;

   case 363:
    perturbSimJointPrimitiveState_30_1v(mag, state);
    break;

   case 364:
    perturbSimJointPrimitiveState_30_2(mag, state);
    break;

   case 365:
    perturbSimJointPrimitiveState_30_2v(mag, state);
    break;

   case 372:
    perturbSimJointPrimitiveState_31_0(mag, state);
    break;

   case 373:
    perturbSimJointPrimitiveState_31_0v(mag, state);
    break;

   case 384:
    perturbSimJointPrimitiveState_32_0(mag, state);
    break;

   case 385:
    perturbSimJointPrimitiveState_32_0v(mag, state);
    break;

   case 396:
    perturbSimJointPrimitiveState_33_0(mag, state);
    break;

   case 397:
    perturbSimJointPrimitiveState_33_0v(mag, state);
    break;
  }
}

void KIMMCar_ff62ad8f_49_perturbFlexibleBodyState(const void *mech, size_t
  stageIdx, double mag, boolean_T doPerturbVelocity, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch (stageIdx * 2 + (doPerturbVelocity ? 1 : 0))
  {
  }
}

void KIMMCar_ff62ad8f_49_constructStateVector(const void *mech, const double
  *solverState, const double *u, const double *uDot, double *discreteState,
  double *fullState)
{
  (void) mech;
  (void) discreteState;
  fullState[0] = solverState[0];
  fullState[1] = solverState[1];
  fullState[2] = solverState[2];
  fullState[3] = solverState[3];
  fullState[4] = solverState[4];
  fullState[5] = solverState[5];
  fullState[6] = solverState[6];
  fullState[7] = solverState[7];
  fullState[8] = solverState[8];
  fullState[9] = solverState[9];
  fullState[10] = solverState[10];
  fullState[11] = solverState[11];
  fullState[12] = solverState[12];
  fullState[13] = u[5];
  fullState[14] = u[6];
  fullState[15] = solverState[13];
  fullState[16] = uDot[5];
  fullState[17] = uDot[6];
  fullState[18] = solverState[14];
  fullState[19] = u[4];
  fullState[20] = uDot[4];
  fullState[21] = u[7];
  fullState[22] = uDot[7];
  fullState[23] = solverState[15];
  fullState[24] = solverState[16];
  fullState[25] = u[9];
  fullState[26] = u[10];
  fullState[27] = solverState[17];
  fullState[28] = uDot[9];
  fullState[29] = uDot[10];
  fullState[30] = solverState[18];
  fullState[31] = u[8];
  fullState[32] = uDot[8];
  fullState[33] = u[11];
  fullState[34] = uDot[11];
  fullState[35] = solverState[19];
  fullState[36] = solverState[20];
  fullState[37] = u[13];
  fullState[38] = u[14];
  fullState[39] = solverState[21];
  fullState[40] = uDot[13];
  fullState[41] = uDot[14];
  fullState[42] = solverState[22];
  fullState[43] = u[12];
  fullState[44] = uDot[12];
  fullState[45] = u[15];
  fullState[46] = uDot[15];
  fullState[47] = solverState[23];
  fullState[48] = solverState[24];
  fullState[49] = u[17];
  fullState[50] = u[18];
  fullState[51] = solverState[25];
  fullState[52] = uDot[17];
  fullState[53] = uDot[18];
  fullState[54] = solverState[26];
  fullState[55] = u[16];
  fullState[56] = uDot[16];
  fullState[57] = u[19];
  fullState[58] = uDot[19];
  fullState[59] = solverState[27];
  fullState[60] = solverState[28];
  fullState[61] = u[20];
  fullState[62] = u[21];
  fullState[63] = u[22];
  fullState[64] = uDot[20];
  fullState[65] = uDot[21];
  fullState[66] = uDot[22];
  fullState[67] = u[24];
  fullState[68] = uDot[24];
  fullState[69] = u[25];
  fullState[70] = uDot[25];
  fullState[71] = u[23];
  fullState[72] = uDot[23];
  fullState[73] = u[26];
  fullState[74] = u[27];
  fullState[75] = u[28];
  fullState[76] = uDot[26];
  fullState[77] = uDot[27];
  fullState[78] = uDot[28];
  fullState[79] = u[30];
  fullState[80] = uDot[30];
  fullState[81] = u[31];
  fullState[82] = uDot[31];
  fullState[83] = u[29];
  fullState[84] = uDot[29];
  fullState[85] = u[32];
  fullState[86] = u[33];
  fullState[87] = u[34];
  fullState[88] = uDot[32];
  fullState[89] = uDot[33];
  fullState[90] = uDot[34];
  fullState[91] = u[36];
  fullState[92] = uDot[36];
  fullState[93] = u[37];
  fullState[94] = uDot[37];
  fullState[95] = u[35];
  fullState[96] = uDot[35];
  fullState[97] = u[38];
  fullState[98] = u[39];
  fullState[99] = u[40];
  fullState[100] = uDot[38];
  fullState[101] = uDot[39];
  fullState[102] = uDot[40];
  fullState[103] = u[42];
  fullState[104] = uDot[42];
  fullState[105] = u[43];
  fullState[106] = uDot[43];
  fullState[107] = u[41];
  fullState[108] = uDot[41];
}

void KIMMCar_ff62ad8f_49_extractSolverStateVector(const void *mech, const double
  *fullState, double *solverState)
{
  (void) mech;
  solverState[0] = fullState[0];
  solverState[1] = fullState[1];
  solverState[2] = fullState[2];
  solverState[3] = fullState[3];
  solverState[4] = fullState[4];
  solverState[5] = fullState[5];
  solverState[6] = fullState[6];
  solverState[7] = fullState[7];
  solverState[8] = fullState[8];
  solverState[9] = fullState[9];
  solverState[10] = fullState[10];
  solverState[11] = fullState[11];
  solverState[12] = fullState[12];
  solverState[13] = fullState[15];
  solverState[14] = fullState[18];
  solverState[15] = fullState[23];
  solverState[16] = fullState[24];
  solverState[17] = fullState[27];
  solverState[18] = fullState[30];
  solverState[19] = fullState[35];
  solverState[20] = fullState[36];
  solverState[21] = fullState[39];
  solverState[22] = fullState[42];
  solverState[23] = fullState[47];
  solverState[24] = fullState[48];
  solverState[25] = fullState[51];
  solverState[26] = fullState[54];
  solverState[27] = fullState[59];
  solverState[28] = fullState[60];
}

void KIMMCar_ff62ad8f_49_extractDiscreteStateVector(const void *mech, const
  double *fullState, double *discreteState)
{
  (void) mech;
  (void) fullState;
  (void) discreteState;
}

boolean_T KIMMCar_ff62ad8f_49_isPositionViolation(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  return 0;
}

boolean_T KIMMCar_ff62ad8f_49_isVelocityViolation(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  return 0;
}

PmfMessageId KIMMCar_ff62ad8f_49_projectStateSim(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const int
  *modeVector, double *state, void *neDiagMgr0)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  double xx[1];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) neDiagMgr;
  xx[0] = sqrt(state[6] * state[6] + state[7] * state[7] + state[8] * state[8] +
               state[9] * state[9]);
  state[6] = state[6] / xx[0];
  state[7] = state[7] / xx[0];
  state[8] = state[8] / xx[0];
  state[9] = state[9] / xx[0];
  return NULL;
}

void KIMMCar_ff62ad8f_49_computeConstraintError(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, const int *modeVector,
  double *error)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) error;
}

void KIMMCar_ff62ad8f_49_resetModeVector(const void *mech, int *modeVector)
{
  (void) mech;
  (void) modeVector;
}

boolean_T KIMMCar_ff62ad8f_49_hasJointUpwardModeChange(const void *mech, const
  int *prevModeVector, const int *modeVector)
{
  (void) mech;
  (void) prevModeVector;
  (void) modeVector;
  return 0;
}

PmfMessageId KIMMCar_ff62ad8f_49_performJointUpwardModeChange(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const int
  *prevModeVector, const int *modeVector, const double *input, double *state,
  void *neDiagMgr0)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) prevModeVector;
  (void) modeVector;
  (void) input;
  (void) state;
  (void) neDiagMgr;
  return NULL;
}

void KIMMCar_ff62ad8f_49_onModeChangedCutJoints(const void *mech, const int
  *prevModeVector, const int *modeVector, double *state)
{
  (void) mech;
  (void) prevModeVector;
  (void) modeVector;
  (void) state;
}

void KIMMCar_ff62ad8f_49_setVariableModeJointsToLocked(const void *mech, int
  *modeVector)
{
  (void) mech;
  (void) modeVector;
}
