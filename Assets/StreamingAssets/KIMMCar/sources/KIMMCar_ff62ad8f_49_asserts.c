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

void KIMMCar_ff62ad8f_49_validateRuntimeParameters(const double *rtp, int32_T
  *satFlags)
{
  boolean_T bb[138];
  double xx[27];
  xx[0] = rtp[0];
  bb[0] = sm_core_math_anyIsInf(1, xx + 0);
  bb[1] = sm_core_math_anyIsNaN(1, xx + 0);
  xx[0] = rtp[1];
  xx[1] = rtp[2];
  xx[2] = rtp[3];
  bb[2] = sm_core_math_anyIsInf(3, xx + 0);
  bb[3] = sm_core_math_anyIsNaN(3, xx + 0);
  xx[0] = rtp[7];
  bb[4] = sm_core_math_anyIsInf(1, xx + 0);
  bb[5] = sm_core_math_anyIsNaN(1, xx + 0);
  xx[0] = rtp[8];
  xx[1] = rtp[9];
  xx[2] = rtp[10];
  bb[6] = sm_core_math_anyIsInf(3, xx + 0);
  bb[7] = sm_core_math_anyIsNaN(3, xx + 0);
  xx[0] = rtp[14];
  bb[8] = sm_core_math_anyIsInf(1, xx + 0);
  bb[9] = sm_core_math_anyIsNaN(1, xx + 0);
  xx[0] = rtp[19];
  bb[10] = sm_core_math_anyIsInf(1, xx + 0);
  bb[11] = sm_core_math_anyIsNaN(1, xx + 0);
  xx[0] = rtp[20];
  bb[12] = sm_core_math_anyIsInf(1, xx + 0);
  bb[13] = !bb[12];
  bb[12] = sm_core_math_anyIsNaN(1, xx + 0);
  bb[14] = !bb[12];
  xx[0] = 0.0;
  xx[1] = rtp[21];
  bb[12] = sm_core_math_anyIsInf(1, xx + 1);
  bb[15] = sm_core_math_anyIsNaN(1, xx + 1);
  xx[1] = rtp[26];
  bb[16] = sm_core_math_anyIsInf(1, xx + 1);
  bb[17] = !bb[16];
  bb[16] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[18] = !bb[16];
  xx[1] = rtp[31];
  bb[16] = sm_core_math_anyIsInf(1, xx + 1);
  bb[19] = !bb[16];
  bb[16] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[20] = !bb[16];
  bb[16] = bb[19] && bb[20];
  bb[21] = !bb[16] || rtp[31] > xx[0];
  xx[1] = rtp[32];
  bb[22] = sm_core_math_anyIsInf(1, xx + 1);
  bb[23] = !bb[22];
  bb[22] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[24] = !bb[22];
  xx[1] = rtp[33];
  bb[22] = sm_core_math_anyIsInf(1, xx + 1);
  bb[25] = !bb[22];
  bb[22] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[26] = !bb[22];
  xx[1] = rtp[34];
  xx[2] = rtp[35];
  xx[3] = rtp[36];
  bb[22] = sm_core_math_anyIsInf(3, xx + 1);
  bb[27] = sm_core_math_anyIsNaN(3, xx + 1);
  xx[1] = rtp[37];
  bb[28] = sm_core_math_anyIsInf(1, xx + 1);
  bb[29] = !bb[28];
  bb[28] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[30] = !bb[28];
  xx[1] = rtp[38];
  bb[28] = sm_core_math_anyIsInf(1, xx + 1);
  bb[31] = sm_core_math_anyIsNaN(1, xx + 1);
  xx[1] = rtp[43];
  bb[32] = sm_core_math_anyIsInf(1, xx + 1);
  bb[33] = !bb[32];
  bb[32] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[34] = !bb[32];
  xx[1] = rtp[48];
  bb[32] = sm_core_math_anyIsInf(1, xx + 1);
  bb[35] = !bb[32];
  bb[32] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[36] = !bb[32];
  bb[32] = bb[35] && bb[36];
  bb[37] = !bb[32] || rtp[48] > xx[0];
  xx[1] = rtp[49];
  bb[38] = sm_core_math_anyIsInf(1, xx + 1);
  bb[39] = !bb[38];
  bb[38] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[40] = !bb[38];
  xx[1] = rtp[50];
  bb[38] = sm_core_math_anyIsInf(1, xx + 1);
  bb[41] = !bb[38];
  bb[38] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[42] = !bb[38];
  xx[1] = rtp[51];
  xx[2] = rtp[52];
  xx[3] = rtp[53];
  bb[38] = sm_core_math_anyIsInf(3, xx + 1);
  bb[43] = sm_core_math_anyIsNaN(3, xx + 1);
  xx[1] = rtp[54];
  bb[44] = sm_core_math_anyIsInf(1, xx + 1);
  bb[45] = !bb[44];
  bb[44] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[46] = !bb[44];
  xx[1] = rtp[55];
  bb[44] = sm_core_math_anyIsInf(1, xx + 1);
  bb[47] = sm_core_math_anyIsNaN(1, xx + 1);
  xx[1] = rtp[60];
  bb[48] = sm_core_math_anyIsInf(1, xx + 1);
  bb[49] = !bb[48];
  bb[48] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[50] = !bb[48];
  xx[1] = rtp[65];
  bb[48] = sm_core_math_anyIsInf(1, xx + 1);
  bb[51] = !bb[48];
  bb[48] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[52] = !bb[48];
  bb[48] = bb[51] && bb[52];
  bb[53] = !bb[48] || rtp[65] > xx[0];
  xx[1] = rtp[66];
  bb[54] = sm_core_math_anyIsInf(1, xx + 1);
  bb[55] = !bb[54];
  bb[54] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[56] = !bb[54];
  xx[1] = rtp[67];
  bb[54] = sm_core_math_anyIsInf(1, xx + 1);
  bb[57] = !bb[54];
  bb[54] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[58] = !bb[54];
  xx[1] = rtp[68];
  xx[2] = rtp[69];
  xx[3] = rtp[70];
  bb[54] = sm_core_math_anyIsInf(3, xx + 1);
  bb[59] = sm_core_math_anyIsNaN(3, xx + 1);
  xx[1] = rtp[71];
  bb[60] = sm_core_math_anyIsInf(1, xx + 1);
  bb[61] = !bb[60];
  bb[60] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[62] = !bb[60];
  xx[1] = rtp[72];
  bb[60] = sm_core_math_anyIsInf(1, xx + 1);
  bb[63] = sm_core_math_anyIsNaN(1, xx + 1);
  xx[1] = rtp[77];
  bb[64] = sm_core_math_anyIsInf(1, xx + 1);
  bb[65] = !bb[64];
  bb[64] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[66] = !bb[64];
  xx[1] = rtp[82];
  bb[64] = sm_core_math_anyIsInf(1, xx + 1);
  bb[67] = !bb[64];
  bb[64] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[68] = !bb[64];
  bb[64] = bb[67] && bb[68];
  bb[69] = !bb[64] || rtp[82] > xx[0];
  xx[1] = rtp[83];
  bb[70] = sm_core_math_anyIsInf(1, xx + 1);
  bb[71] = !bb[70];
  bb[70] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[72] = !bb[70];
  xx[1] = rtp[84];
  bb[70] = sm_core_math_anyIsInf(1, xx + 1);
  bb[73] = !bb[70];
  bb[70] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[74] = !bb[70];
  xx[1] = rtp[85];
  xx[2] = rtp[86];
  xx[3] = rtp[87];
  bb[70] = sm_core_math_anyIsInf(3, xx + 1);
  bb[75] = sm_core_math_anyIsNaN(3, xx + 1);
  xx[1] = rtp[88];
  bb[76] = sm_core_math_anyIsInf(1, xx + 1);
  bb[77] = sm_core_math_anyIsNaN(1, xx + 1);
  xx[1] = rtp[89];
  bb[78] = sm_core_math_anyIsInf(1, xx + 1);
  bb[79] = sm_core_math_anyIsNaN(1, xx + 1);
  xx[1] = rtp[90];
  xx[2] = rtp[91];
  xx[3] = rtp[92];
  bb[80] = sm_core_math_anyIsInf(3, xx + 1);
  bb[81] = !bb[80];
  bb[80] = sm_core_math_anyIsNaN(3, xx + 1);
  bb[82] = !bb[80];
  xx[1] = rtp[93];
  bb[80] = sm_core_math_anyIsInf(1, xx + 1);
  bb[83] = !bb[80];
  bb[80] = sm_core_math_anyIsNaN(1, xx + 1);
  bb[84] = !bb[80];
  xx[1] = rtp[94];
  xx[2] = rtp[95];
  xx[3] = rtp[96];
  bb[80] = sm_core_math_anyIsInf(3, xx + 1);
  bb[85] = sm_core_math_anyIsNaN(3, xx + 1);
  xx[1] = rtp[97];
  xx[2] = rtp[98];
  xx[3] = rtp[99];
  bb[86] = sm_core_math_anyIsInf(3, xx + 1);
  bb[87] = sm_core_math_anyIsNaN(3, xx + 1);
  bb[88] = bb[83] && bb[84];
  bb[89] = bb[81] && bb[82];
  xx[1] = bb[88] ? rtp[93] : xx[0];
  xx[2] = bb[89] ? rtp[90] : xx[0];
  xx[3] = bb[89] ? rtp[91] : xx[0];
  xx[4] = bb[89] ? rtp[92] : xx[0];
  bb[90] = xx[1] != xx[0] || (xx[2] == xx[0] && xx[3] == xx[0] && xx[4] == xx[0]);
  xx[5] = rtp[100];
  bb[91] = sm_core_math_anyIsInf(1, xx + 5);
  bb[92] = sm_core_math_anyIsNaN(1, xx + 5);
  xx[5] = rtp[101];
  bb[93] = sm_core_math_anyIsInf(1, xx + 5);
  bb[94] = sm_core_math_anyIsNaN(1, xx + 5);
  xx[5] = rtp[102];
  xx[6] = rtp[103];
  xx[7] = rtp[104];
  bb[95] = sm_core_math_anyIsInf(3, xx + 5);
  bb[96] = !bb[95];
  bb[95] = sm_core_math_anyIsNaN(3, xx + 5);
  bb[97] = !bb[95];
  xx[5] = rtp[105];
  bb[95] = sm_core_math_anyIsInf(1, xx + 5);
  bb[98] = !bb[95];
  bb[95] = sm_core_math_anyIsNaN(1, xx + 5);
  bb[99] = !bb[95];
  xx[5] = rtp[106];
  xx[6] = rtp[107];
  xx[7] = rtp[108];
  bb[95] = sm_core_math_anyIsInf(3, xx + 5);
  bb[100] = sm_core_math_anyIsNaN(3, xx + 5);
  xx[5] = rtp[109];
  xx[6] = rtp[110];
  xx[7] = rtp[111];
  bb[101] = sm_core_math_anyIsInf(3, xx + 5);
  bb[102] = sm_core_math_anyIsNaN(3, xx + 5);
  bb[103] = bb[98] && bb[99];
  bb[104] = bb[96] && bb[97];
  xx[5] = bb[103] ? rtp[105] : xx[0];
  xx[6] = bb[104] ? rtp[102] : xx[0];
  xx[7] = bb[104] ? rtp[103] : xx[0];
  xx[8] = bb[104] ? rtp[104] : xx[0];
  bb[105] = xx[5] != xx[0] || (xx[6] == xx[0] && xx[7] == xx[0] && xx[8] == xx[0]);
  xx[9] = rtp[112];
  bb[106] = sm_core_math_anyIsInf(1, xx + 9);
  bb[107] = sm_core_math_anyIsNaN(1, xx + 9);
  xx[9] = rtp[113];
  bb[108] = sm_core_math_anyIsInf(1, xx + 9);
  bb[109] = sm_core_math_anyIsNaN(1, xx + 9);
  xx[9] = rtp[114];
  xx[10] = rtp[115];
  xx[11] = rtp[116];
  bb[110] = sm_core_math_anyIsInf(3, xx + 9);
  bb[111] = !bb[110];
  bb[110] = sm_core_math_anyIsNaN(3, xx + 9);
  bb[112] = !bb[110];
  xx[9] = rtp[117];
  bb[110] = sm_core_math_anyIsInf(1, xx + 9);
  bb[113] = !bb[110];
  bb[110] = sm_core_math_anyIsNaN(1, xx + 9);
  bb[114] = !bb[110];
  xx[9] = rtp[118];
  xx[10] = rtp[119];
  xx[11] = rtp[120];
  bb[110] = sm_core_math_anyIsInf(3, xx + 9);
  bb[115] = sm_core_math_anyIsNaN(3, xx + 9);
  xx[9] = rtp[121];
  xx[10] = rtp[122];
  xx[11] = rtp[123];
  bb[116] = sm_core_math_anyIsInf(3, xx + 9);
  bb[117] = sm_core_math_anyIsNaN(3, xx + 9);
  bb[118] = bb[113] && bb[114];
  bb[119] = bb[111] && bb[112];
  xx[9] = bb[118] ? rtp[117] : xx[0];
  xx[10] = bb[119] ? rtp[114] : xx[0];
  xx[11] = bb[119] ? rtp[115] : xx[0];
  xx[12] = bb[119] ? rtp[116] : xx[0];
  bb[120] = xx[9] != xx[0] || (xx[10] == xx[0] && xx[11] == xx[0] && xx[12] ==
    xx[0]);
  xx[13] = rtp[124];
  bb[121] = sm_core_math_anyIsInf(1, xx + 13);
  bb[122] = sm_core_math_anyIsNaN(1, xx + 13);
  xx[13] = rtp[125];
  bb[123] = sm_core_math_anyIsInf(1, xx + 13);
  bb[124] = sm_core_math_anyIsNaN(1, xx + 13);
  xx[13] = rtp[126];
  xx[14] = rtp[127];
  xx[15] = rtp[128];
  bb[125] = sm_core_math_anyIsInf(3, xx + 13);
  bb[126] = !bb[125];
  bb[125] = sm_core_math_anyIsNaN(3, xx + 13);
  bb[127] = !bb[125];
  xx[13] = rtp[129];
  bb[125] = sm_core_math_anyIsInf(1, xx + 13);
  bb[128] = !bb[125];
  bb[125] = sm_core_math_anyIsNaN(1, xx + 13);
  bb[129] = !bb[125];
  xx[13] = rtp[130];
  xx[14] = rtp[131];
  xx[15] = rtp[132];
  bb[125] = sm_core_math_anyIsInf(3, xx + 13);
  bb[130] = sm_core_math_anyIsNaN(3, xx + 13);
  xx[13] = rtp[133];
  xx[14] = rtp[134];
  xx[15] = rtp[135];
  bb[131] = sm_core_math_anyIsInf(3, xx + 13);
  bb[132] = sm_core_math_anyIsNaN(3, xx + 13);
  bb[133] = bb[128] && bb[129];
  bb[134] = bb[126] && bb[127];
  xx[13] = bb[133] ? rtp[129] : xx[0];
  xx[14] = bb[134] ? rtp[126] : xx[0];
  xx[15] = bb[134] ? rtp[127] : xx[0];
  xx[16] = bb[134] ? rtp[128] : xx[0];
  bb[135] = xx[13] != xx[0] || (xx[14] == xx[0] && xx[15] == xx[0] && xx[16] ==
    xx[0]);
  xx[17] = rtp[136];
  bb[136] = sm_core_math_anyIsInf(1, xx + 17);
  bb[137] = sm_core_math_anyIsNaN(1, xx + 17);
  xx[17] = bb[90] ? xx[1] : xx[0];
  xx[1] = bb[105] ? xx[5] : xx[0];
  xx[5] = bb[120] ? xx[9] : xx[0];
  xx[9] = bb[135] ? xx[13] : xx[0];
  xx[13] = bb[25] && bb[26] ? rtp[33] : xx[0];
  xx[18] = 0.05;
  xx[19] = 2.0;
  xx[20] = 0.5;
  xx[21] = 1.0;
  xx[22] = xx[20] * (bb[16] && bb[21] ? rtp[31] : xx[21]);
  xx[23] = bb[41] && bb[42] ? rtp[50] : xx[0];
  xx[24] = bb[57] && bb[58] ? rtp[67] : xx[0];
  xx[25] = xx[20] * (bb[48] && bb[53] ? rtp[65] : xx[21]);
  xx[26] = bb[73] && bb[74] ? rtp[84] : xx[0];
  satFlags[0] = !bb[0] ? 1 : 0;
  satFlags[1] = !bb[1] ? 1 : 0;
  satFlags[2] = !bb[2] ? 1 : 0;
  satFlags[3] = !bb[3] ? 1 : 0;
  satFlags[4] = !bb[4] ? 1 : 0;
  satFlags[5] = !bb[5] ? 1 : 0;
  satFlags[6] = !bb[6] ? 1 : 0;
  satFlags[7] = !bb[7] ? 1 : 0;
  satFlags[8] = !bb[8] ? 1 : 0;
  satFlags[9] = !bb[9] ? 1 : 0;
  satFlags[10] = !bb[10] ? 1 : 0;
  satFlags[11] = !bb[11] ? 1 : 0;
  satFlags[12] = bb[13] ? 1 : 0;
  satFlags[13] = bb[14] ? 1 : 0;
  satFlags[14] = !(bb[13] && bb[14]) || rtp[20] >= xx[0] ? 1 : 0;
  satFlags[15] = !bb[12] ? 1 : 0;
  satFlags[16] = !bb[15] ? 1 : 0;
  satFlags[17] = bb[17] ? 1 : 0;
  satFlags[18] = bb[18] ? 1 : 0;
  satFlags[19] = !(bb[17] && bb[18]) || rtp[26] >= xx[0] ? 1 : 0;
  satFlags[20] = bb[19] ? 1 : 0;
  satFlags[21] = bb[20] ? 1 : 0;
  satFlags[22] = bb[21] ? 1 : 0;
  satFlags[23] = bb[23] ? 1 : 0;
  satFlags[24] = bb[24] ? 1 : 0;
  satFlags[25] = !(bb[23] && bb[24]) || rtp[32] > xx[0] ? 1 : 0;
  satFlags[26] = bb[25] ? 1 : 0;
  satFlags[27] = bb[26] ? 1 : 0;
  satFlags[28] = !bb[22] ? 1 : 0;
  satFlags[29] = !bb[27] ? 1 : 0;
  satFlags[30] = bb[29] ? 1 : 0;
  satFlags[31] = bb[30] ? 1 : 0;
  satFlags[32] = !(bb[29] && bb[30]) || rtp[37] >= xx[0] ? 1 : 0;
  satFlags[33] = !bb[28] ? 1 : 0;
  satFlags[34] = !bb[31] ? 1 : 0;
  satFlags[35] = bb[33] ? 1 : 0;
  satFlags[36] = bb[34] ? 1 : 0;
  satFlags[37] = !(bb[33] && bb[34]) || rtp[43] >= xx[0] ? 1 : 0;
  satFlags[38] = bb[35] ? 1 : 0;
  satFlags[39] = bb[36] ? 1 : 0;
  satFlags[40] = bb[37] ? 1 : 0;
  satFlags[41] = bb[39] ? 1 : 0;
  satFlags[42] = bb[40] ? 1 : 0;
  satFlags[43] = !(bb[39] && bb[40]) || rtp[49] > xx[0] ? 1 : 0;
  satFlags[44] = bb[41] ? 1 : 0;
  satFlags[45] = bb[42] ? 1 : 0;
  satFlags[46] = !bb[38] ? 1 : 0;
  satFlags[47] = !bb[43] ? 1 : 0;
  satFlags[48] = bb[45] ? 1 : 0;
  satFlags[49] = bb[46] ? 1 : 0;
  satFlags[50] = !(bb[45] && bb[46]) || rtp[54] >= xx[0] ? 1 : 0;
  satFlags[51] = !bb[44] ? 1 : 0;
  satFlags[52] = !bb[47] ? 1 : 0;
  satFlags[53] = bb[49] ? 1 : 0;
  satFlags[54] = bb[50] ? 1 : 0;
  satFlags[55] = !(bb[49] && bb[50]) || rtp[60] >= xx[0] ? 1 : 0;
  satFlags[56] = bb[51] ? 1 : 0;
  satFlags[57] = bb[52] ? 1 : 0;
  satFlags[58] = bb[53] ? 1 : 0;
  satFlags[59] = bb[55] ? 1 : 0;
  satFlags[60] = bb[56] ? 1 : 0;
  satFlags[61] = !(bb[55] && bb[56]) || rtp[66] > xx[0] ? 1 : 0;
  satFlags[62] = bb[57] ? 1 : 0;
  satFlags[63] = bb[58] ? 1 : 0;
  satFlags[64] = !bb[54] ? 1 : 0;
  satFlags[65] = !bb[59] ? 1 : 0;
  satFlags[66] = bb[61] ? 1 : 0;
  satFlags[67] = bb[62] ? 1 : 0;
  satFlags[68] = !(bb[61] && bb[62]) || rtp[71] >= xx[0] ? 1 : 0;
  satFlags[69] = !bb[60] ? 1 : 0;
  satFlags[70] = !bb[63] ? 1 : 0;
  satFlags[71] = bb[65] ? 1 : 0;
  satFlags[72] = bb[66] ? 1 : 0;
  satFlags[73] = !(bb[65] && bb[66]) || rtp[77] >= xx[0] ? 1 : 0;
  satFlags[74] = bb[67] ? 1 : 0;
  satFlags[75] = bb[68] ? 1 : 0;
  satFlags[76] = bb[69] ? 1 : 0;
  satFlags[77] = bb[71] ? 1 : 0;
  satFlags[78] = bb[72] ? 1 : 0;
  satFlags[79] = !(bb[71] && bb[72]) || rtp[83] > xx[0] ? 1 : 0;
  satFlags[80] = bb[73] ? 1 : 0;
  satFlags[81] = bb[74] ? 1 : 0;
  satFlags[82] = !bb[70] ? 1 : 0;
  satFlags[83] = !bb[75] ? 1 : 0;
  satFlags[84] = !bb[76] ? 1 : 0;
  satFlags[85] = !bb[77] ? 1 : 0;
  satFlags[86] = !bb[78] ? 1 : 0;
  satFlags[87] = !bb[79] ? 1 : 0;
  satFlags[88] = bb[81] ? 1 : 0;
  satFlags[89] = bb[82] ? 1 : 0;
  satFlags[90] = bb[83] ? 1 : 0;
  satFlags[91] = bb[84] ? 1 : 0;
  satFlags[92] = !bb[80] ? 1 : 0;
  satFlags[93] = !bb[85] ? 1 : 0;
  satFlags[94] = !bb[86] ? 1 : 0;
  satFlags[95] = !bb[87] ? 1 : 0;
  satFlags[96] = !(bb[88] && bb[89]) || bb[90] ? 1 : 0;
  satFlags[97] = !bb[91] ? 1 : 0;
  satFlags[98] = !bb[92] ? 1 : 0;
  satFlags[99] = !bb[93] ? 1 : 0;
  satFlags[100] = !bb[94] ? 1 : 0;
  satFlags[101] = bb[96] ? 1 : 0;
  satFlags[102] = bb[97] ? 1 : 0;
  satFlags[103] = bb[98] ? 1 : 0;
  satFlags[104] = bb[99] ? 1 : 0;
  satFlags[105] = !bb[95] ? 1 : 0;
  satFlags[106] = !bb[100] ? 1 : 0;
  satFlags[107] = !bb[101] ? 1 : 0;
  satFlags[108] = !bb[102] ? 1 : 0;
  satFlags[109] = !(bb[103] && bb[104]) || bb[105] ? 1 : 0;
  satFlags[110] = !bb[106] ? 1 : 0;
  satFlags[111] = !bb[107] ? 1 : 0;
  satFlags[112] = !bb[108] ? 1 : 0;
  satFlags[113] = !bb[109] ? 1 : 0;
  satFlags[114] = bb[111] ? 1 : 0;
  satFlags[115] = bb[112] ? 1 : 0;
  satFlags[116] = bb[113] ? 1 : 0;
  satFlags[117] = bb[114] ? 1 : 0;
  satFlags[118] = !bb[110] ? 1 : 0;
  satFlags[119] = !bb[115] ? 1 : 0;
  satFlags[120] = !bb[116] ? 1 : 0;
  satFlags[121] = !bb[117] ? 1 : 0;
  satFlags[122] = !(bb[118] && bb[119]) || bb[120] ? 1 : 0;
  satFlags[123] = !bb[121] ? 1 : 0;
  satFlags[124] = !bb[122] ? 1 : 0;
  satFlags[125] = !bb[123] ? 1 : 0;
  satFlags[126] = !bb[124] ? 1 : 0;
  satFlags[127] = bb[126] ? 1 : 0;
  satFlags[128] = bb[127] ? 1 : 0;
  satFlags[129] = bb[128] ? 1 : 0;
  satFlags[130] = bb[129] ? 1 : 0;
  satFlags[131] = !bb[125] ? 1 : 0;
  satFlags[132] = !bb[130] ? 1 : 0;
  satFlags[133] = !bb[131] ? 1 : 0;
  satFlags[134] = !bb[132] ? 1 : 0;
  satFlags[135] = !(bb[133] && bb[134]) || bb[135] ? 1 : 0;
  satFlags[136] = !bb[136] ? 1 : 0;
  satFlags[137] = !bb[137] ? 1 : 0;
  satFlags[138] = xx[17] != xx[0] || (xx[17] * (bb[90] ? xx[2] : xx[0]) == xx[0]
    && xx[17] * (bb[90] ? xx[3] : xx[0]) == xx[0] && xx[17] * (bb[90] ? xx[4] :
    xx[0]) == xx[0]) ? 1 : 0;
  satFlags[139] = xx[1] != xx[0] || (xx[1] * (bb[105] ? xx[6] : xx[0]) == xx[0] &&
    xx[1] * (bb[105] ? xx[7] : xx[0]) == xx[0] && xx[1] * (bb[105] ? xx[8] : xx
    [0]) == xx[0]) ? 1 : 0;
  satFlags[140] = xx[5] != xx[0] || (xx[5] * (bb[120] ? xx[10] : xx[0]) == xx[0]
    && xx[5] * (bb[120] ? xx[11] : xx[0]) == xx[0] && xx[5] * (bb[120] ? xx[12] :
    xx[0]) == xx[0]) ? 1 : 0;
  satFlags[141] = xx[9] != xx[0] || (xx[9] * (bb[135] ? xx[14] : xx[0]) == xx[0]
    && xx[9] * (bb[135] ? xx[15] : xx[0]) == xx[0] && xx[9] * (bb[135] ? xx[16] :
    xx[0]) == xx[0]) ? 1 : 0;
  satFlags[142] = xx[13] != xx[0] || - (xx[18] * xx[13] + (xx[19] * xx[22] - xx
    [22]) * xx[13]) == xx[0] ? 1 : 0;
  satFlags[143] = xx[23] != xx[0] || xx[20] * (bb[32] && bb[37] ? rtp[48] : xx
    [21]) * xx[23] + xx[18] * xx[23] == xx[0] ? 1 : 0;
  satFlags[144] = xx[24] != xx[0] || - (xx[18] * xx[24] + (xx[19] * xx[25] - xx
    [25]) * xx[24]) == xx[0] ? 1 : 0;
  satFlags[145] = xx[26] != xx[0] || xx[20] * (bb[64] && bb[69] ? rtp[82] : xx
    [21]) * xx[26] + xx[18] * xx[26] == xx[0] ? 1 : 0;
}

const NeAssertData KIMMCar_ff62ad8f_49_assertData[146] = {
  { "KIMMCar/Vehicle/Body/Body Inertia", 0, 0, "Vehicle.Body.Body_Inertia", "",
    false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Body/Body Inertia", 0, 0, "Vehicle.Body.Body_Inertia", "",
    false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Body/Body Inertia", 0, 0, "Vehicle.Body.Body_Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Body/Body Inertia", 0, 0, "Vehicle.Body.Body_Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Body/Front Axle Transform", 0, 0,
    "Vehicle.Body.Front_Axle_Transform", "", false,
    "The parameter Offset contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Body/Front Axle Transform", 0, 0,
    "Vehicle.Body.Front_Axle_Transform", "", false,
    "The parameter Offset contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Body/Geometry Transform", 0, 0,
    "Vehicle.Body.Geometry_Transform", "", false,
    "The parameter XYZ contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Body/Geometry Transform", 0, 0,
    "Vehicle.Body.Geometry_Transform", "", false,
    "The parameter XYZ contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Body/Rear Axle Transform", 0, 0,
    "Vehicle.Body.Rear_Axle_Transform", "", false,
    "The parameter Offset contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Body/Rear Axle Transform", 0, 0,
    "Vehicle.Body.Rear_Axle_Transform", "", false,
    "The parameter Offset contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Ground Transform", 0, 0,
    "Vehicle.Suspension_Front.Ground_Transform", "", false,
    "The parameter Offset contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Ground Transform", 0, 0,
    "Vehicle.Suspension_Front.Ground_Transform", "", false,
    "The parameter Offset contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Left_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Length is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Front.Right_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Length is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Left_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Length is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Damper Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Equilibrium Position contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Spring Damper", 0, 0,
    "Vehicle.Suspension_Rear.Right_Spring_Damper", "", false,
    "The parameter Pz/Spring Constant is invalid; it must be nonnegative.",
    "sm:model:evaluate:NegativeScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Length contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Length is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Geometry/Radius is invalid; it must be positive.",
    "sm:model:evaluate:NonpositiveScalar" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Geometry Transform", 0, 0,
    "Vehicle.Tire_FL.Geometry_Transform", "", false,
    "The parameter Angle contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FL/Geometry Transform", 0, 0,
    "Vehicle.Tire_FL.Geometry_Transform", "", false,
    "The parameter Angle contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Geometry Transform", 0, 0,
    "Vehicle.Tire_FL.Geometry_Transform", "", false,
    "The parameter Offset contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FL/Geometry Transform", 0, 0,
    "Vehicle.Tire_FL.Geometry_Transform", "", false,
    "The parameter Offset contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "The zero total mass is incompatible with the nonzero center of mass.",
    "sm:model:inertia:InvalidZeroMass" },

  { "KIMMCar/Vehicle/Tire FR/Geometry Transform", 0, 0,
    "Vehicle.Tire_FR.Geometry_Transform", "", false,
    "The parameter Angle contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FR/Geometry Transform", 0, 0,
    "Vehicle.Tire_FR.Geometry_Transform", "", false,
    "The parameter Angle contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FR/Geometry Transform", 0, 0,
    "Vehicle.Tire_FR.Geometry_Transform", "", false,
    "The parameter Offset contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FR/Geometry Transform", 0, 0,
    "Vehicle.Tire_FR.Geometry_Transform", "", false,
    "The parameter Offset contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "The zero total mass is incompatible with the nonzero center of mass.",
    "sm:model:inertia:InvalidZeroMass" },

  { "KIMMCar/Vehicle/Tire RL/Geometry Transform", 0, 0,
    "Vehicle.Tire_RL.Geometry_Transform", "", false,
    "The parameter Angle contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RL/Geometry Transform", 0, 0,
    "Vehicle.Tire_RL.Geometry_Transform", "", false,
    "The parameter Angle contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RL/Geometry Transform", 0, 0,
    "Vehicle.Tire_RL.Geometry_Transform", "", false,
    "The parameter Offset contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RL/Geometry Transform", 0, 0,
    "Vehicle.Tire_RL.Geometry_Transform", "", false,
    "The parameter Offset contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "The zero total mass is incompatible with the nonzero center of mass.",
    "sm:model:inertia:InvalidZeroMass" },

  { "KIMMCar/Vehicle/Tire RR/Geometry Transform", 0, 0,
    "Vehicle.Tire_RR.Geometry_Transform", "", false,
    "The parameter Angle contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RR/Geometry Transform", 0, 0,
    "Vehicle.Tire_RR.Geometry_Transform", "", false,
    "The parameter Angle contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RR/Geometry Transform", 0, 0,
    "Vehicle.Tire_RR.Geometry_Transform", "", false,
    "The parameter Offset contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RR/Geometry Transform", 0, 0,
    "Vehicle.Tire_RR.Geometry_Transform", "", false,
    "The parameter Offset contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Center of Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Mass contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Mass contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Moments of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The parameter Inertia/Products of Inertia contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "The zero total mass is incompatible with the nonzero center of mass.",
    "sm:model:inertia:InvalidZeroMass" },

  { "KIMMCar/Vehicle/World to Body/6-DOF Joint", 0, 0,
    "Vehicle.World_to_Body.x6_DOF_Joint", "", false,
    "The parameter Pz/Position contains an Inf value, which is not allowed.",
    "sm:model:evaluate:InvalidValueInf" },

  { "KIMMCar/Vehicle/World to Body/6-DOF Joint", 0, 0,
    "Vehicle.World_to_Body.x6_DOF_Joint", "", false,
    "The parameter Pz/Position contains a NaN value, which is not allowed.",
    "sm:model:evaluate:InvalidValueNaN" },

  { "KIMMCar/Vehicle/Tire FL/Inertia", 0, 0, "Vehicle.Tire_FL.Inertia", "",
    false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Inertia 'KIMMCar/Vehicle/Tire FL/Inertia'\n  Solid 'KIMMCar/Vehicle/Tire FL/Tire'\n  Solid 'KIMMCar/Vehicle/Tire FL/Wheel'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" },

  { "KIMMCar/Vehicle/Tire FR/Inertia", 0, 0, "Vehicle.Tire_FR.Inertia", "",
    false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Inertia 'KIMMCar/Vehicle/Tire FR/Inertia'\n  Solid 'KIMMCar/Vehicle/Tire FR/Tire'\n  Solid 'KIMMCar/Vehicle/Tire FR/Wheel'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" },

  { "KIMMCar/Vehicle/Tire RL/Inertia", 0, 0, "Vehicle.Tire_RL.Inertia", "",
    false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Inertia 'KIMMCar/Vehicle/Tire RL/Inertia'\n  Solid 'KIMMCar/Vehicle/Tire RL/Tire'\n  Solid 'KIMMCar/Vehicle/Tire RL/Wheel'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" },

  { "KIMMCar/Vehicle/Tire RR/Inertia", 0, 0, "Vehicle.Tire_RR.Inertia", "",
    false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Inertia 'KIMMCar/Vehicle/Tire RR/Inertia'\n  Solid 'KIMMCar/Vehicle/Tire RR/Tire'\n  Solid 'KIMMCar/Vehicle/Tire RR/Wheel'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" },

  { "KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Front.Left_Unsprung_Mass", "", false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Solid 'KIMMCar/Vehicle/Suspension Front/Left Unsprung  Mass'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" },

  { "KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Front.Right_Unsprung_Mass", "", false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Solid 'KIMMCar/Vehicle/Suspension Front/Right Unsprung Mass'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" },

  { "KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass", 0, 0,
    "Vehicle.Suspension_Rear.Left_Unsprung_Mass", "", false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Solid 'KIMMCar/Vehicle/Suspension Rear/Left Unsprung  Mass'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" },

  { "KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass", 0, 0,
    "Vehicle.Suspension_Rear.Right_Unsprung_Mass", "", false,
    "Rigid component has invalid zero total mass and nonzero first moment of mass; mass distribution defined by:\n  Solid 'KIMMCar/Vehicle/Suspension Rear/Right Unsprung Mass'\n.",
    "physmod:sm:core:compiler:system:invalidMassDistribution" }
};
