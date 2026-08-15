#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8853800063451770622) {
   out_8853800063451770622[0] = delta_x[0] + nom_x[0];
   out_8853800063451770622[1] = delta_x[1] + nom_x[1];
   out_8853800063451770622[2] = delta_x[2] + nom_x[2];
   out_8853800063451770622[3] = delta_x[3] + nom_x[3];
   out_8853800063451770622[4] = delta_x[4] + nom_x[4];
   out_8853800063451770622[5] = delta_x[5] + nom_x[5];
   out_8853800063451770622[6] = delta_x[6] + nom_x[6];
   out_8853800063451770622[7] = delta_x[7] + nom_x[7];
   out_8853800063451770622[8] = delta_x[8] + nom_x[8];
   out_8853800063451770622[9] = delta_x[9] + nom_x[9];
   out_8853800063451770622[10] = delta_x[10] + nom_x[10];
   out_8853800063451770622[11] = delta_x[11] + nom_x[11];
   out_8853800063451770622[12] = delta_x[12] + nom_x[12];
   out_8853800063451770622[13] = delta_x[13] + nom_x[13];
   out_8853800063451770622[14] = delta_x[14] + nom_x[14];
   out_8853800063451770622[15] = delta_x[15] + nom_x[15];
   out_8853800063451770622[16] = delta_x[16] + nom_x[16];
   out_8853800063451770622[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1474102248584144178) {
   out_1474102248584144178[0] = -nom_x[0] + true_x[0];
   out_1474102248584144178[1] = -nom_x[1] + true_x[1];
   out_1474102248584144178[2] = -nom_x[2] + true_x[2];
   out_1474102248584144178[3] = -nom_x[3] + true_x[3];
   out_1474102248584144178[4] = -nom_x[4] + true_x[4];
   out_1474102248584144178[5] = -nom_x[5] + true_x[5];
   out_1474102248584144178[6] = -nom_x[6] + true_x[6];
   out_1474102248584144178[7] = -nom_x[7] + true_x[7];
   out_1474102248584144178[8] = -nom_x[8] + true_x[8];
   out_1474102248584144178[9] = -nom_x[9] + true_x[9];
   out_1474102248584144178[10] = -nom_x[10] + true_x[10];
   out_1474102248584144178[11] = -nom_x[11] + true_x[11];
   out_1474102248584144178[12] = -nom_x[12] + true_x[12];
   out_1474102248584144178[13] = -nom_x[13] + true_x[13];
   out_1474102248584144178[14] = -nom_x[14] + true_x[14];
   out_1474102248584144178[15] = -nom_x[15] + true_x[15];
   out_1474102248584144178[16] = -nom_x[16] + true_x[16];
   out_1474102248584144178[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2871704563598328823) {
   out_2871704563598328823[0] = 1.0;
   out_2871704563598328823[1] = 0.0;
   out_2871704563598328823[2] = 0.0;
   out_2871704563598328823[3] = 0.0;
   out_2871704563598328823[4] = 0.0;
   out_2871704563598328823[5] = 0.0;
   out_2871704563598328823[6] = 0.0;
   out_2871704563598328823[7] = 0.0;
   out_2871704563598328823[8] = 0.0;
   out_2871704563598328823[9] = 0.0;
   out_2871704563598328823[10] = 0.0;
   out_2871704563598328823[11] = 0.0;
   out_2871704563598328823[12] = 0.0;
   out_2871704563598328823[13] = 0.0;
   out_2871704563598328823[14] = 0.0;
   out_2871704563598328823[15] = 0.0;
   out_2871704563598328823[16] = 0.0;
   out_2871704563598328823[17] = 0.0;
   out_2871704563598328823[18] = 0.0;
   out_2871704563598328823[19] = 1.0;
   out_2871704563598328823[20] = 0.0;
   out_2871704563598328823[21] = 0.0;
   out_2871704563598328823[22] = 0.0;
   out_2871704563598328823[23] = 0.0;
   out_2871704563598328823[24] = 0.0;
   out_2871704563598328823[25] = 0.0;
   out_2871704563598328823[26] = 0.0;
   out_2871704563598328823[27] = 0.0;
   out_2871704563598328823[28] = 0.0;
   out_2871704563598328823[29] = 0.0;
   out_2871704563598328823[30] = 0.0;
   out_2871704563598328823[31] = 0.0;
   out_2871704563598328823[32] = 0.0;
   out_2871704563598328823[33] = 0.0;
   out_2871704563598328823[34] = 0.0;
   out_2871704563598328823[35] = 0.0;
   out_2871704563598328823[36] = 0.0;
   out_2871704563598328823[37] = 0.0;
   out_2871704563598328823[38] = 1.0;
   out_2871704563598328823[39] = 0.0;
   out_2871704563598328823[40] = 0.0;
   out_2871704563598328823[41] = 0.0;
   out_2871704563598328823[42] = 0.0;
   out_2871704563598328823[43] = 0.0;
   out_2871704563598328823[44] = 0.0;
   out_2871704563598328823[45] = 0.0;
   out_2871704563598328823[46] = 0.0;
   out_2871704563598328823[47] = 0.0;
   out_2871704563598328823[48] = 0.0;
   out_2871704563598328823[49] = 0.0;
   out_2871704563598328823[50] = 0.0;
   out_2871704563598328823[51] = 0.0;
   out_2871704563598328823[52] = 0.0;
   out_2871704563598328823[53] = 0.0;
   out_2871704563598328823[54] = 0.0;
   out_2871704563598328823[55] = 0.0;
   out_2871704563598328823[56] = 0.0;
   out_2871704563598328823[57] = 1.0;
   out_2871704563598328823[58] = 0.0;
   out_2871704563598328823[59] = 0.0;
   out_2871704563598328823[60] = 0.0;
   out_2871704563598328823[61] = 0.0;
   out_2871704563598328823[62] = 0.0;
   out_2871704563598328823[63] = 0.0;
   out_2871704563598328823[64] = 0.0;
   out_2871704563598328823[65] = 0.0;
   out_2871704563598328823[66] = 0.0;
   out_2871704563598328823[67] = 0.0;
   out_2871704563598328823[68] = 0.0;
   out_2871704563598328823[69] = 0.0;
   out_2871704563598328823[70] = 0.0;
   out_2871704563598328823[71] = 0.0;
   out_2871704563598328823[72] = 0.0;
   out_2871704563598328823[73] = 0.0;
   out_2871704563598328823[74] = 0.0;
   out_2871704563598328823[75] = 0.0;
   out_2871704563598328823[76] = 1.0;
   out_2871704563598328823[77] = 0.0;
   out_2871704563598328823[78] = 0.0;
   out_2871704563598328823[79] = 0.0;
   out_2871704563598328823[80] = 0.0;
   out_2871704563598328823[81] = 0.0;
   out_2871704563598328823[82] = 0.0;
   out_2871704563598328823[83] = 0.0;
   out_2871704563598328823[84] = 0.0;
   out_2871704563598328823[85] = 0.0;
   out_2871704563598328823[86] = 0.0;
   out_2871704563598328823[87] = 0.0;
   out_2871704563598328823[88] = 0.0;
   out_2871704563598328823[89] = 0.0;
   out_2871704563598328823[90] = 0.0;
   out_2871704563598328823[91] = 0.0;
   out_2871704563598328823[92] = 0.0;
   out_2871704563598328823[93] = 0.0;
   out_2871704563598328823[94] = 0.0;
   out_2871704563598328823[95] = 1.0;
   out_2871704563598328823[96] = 0.0;
   out_2871704563598328823[97] = 0.0;
   out_2871704563598328823[98] = 0.0;
   out_2871704563598328823[99] = 0.0;
   out_2871704563598328823[100] = 0.0;
   out_2871704563598328823[101] = 0.0;
   out_2871704563598328823[102] = 0.0;
   out_2871704563598328823[103] = 0.0;
   out_2871704563598328823[104] = 0.0;
   out_2871704563598328823[105] = 0.0;
   out_2871704563598328823[106] = 0.0;
   out_2871704563598328823[107] = 0.0;
   out_2871704563598328823[108] = 0.0;
   out_2871704563598328823[109] = 0.0;
   out_2871704563598328823[110] = 0.0;
   out_2871704563598328823[111] = 0.0;
   out_2871704563598328823[112] = 0.0;
   out_2871704563598328823[113] = 0.0;
   out_2871704563598328823[114] = 1.0;
   out_2871704563598328823[115] = 0.0;
   out_2871704563598328823[116] = 0.0;
   out_2871704563598328823[117] = 0.0;
   out_2871704563598328823[118] = 0.0;
   out_2871704563598328823[119] = 0.0;
   out_2871704563598328823[120] = 0.0;
   out_2871704563598328823[121] = 0.0;
   out_2871704563598328823[122] = 0.0;
   out_2871704563598328823[123] = 0.0;
   out_2871704563598328823[124] = 0.0;
   out_2871704563598328823[125] = 0.0;
   out_2871704563598328823[126] = 0.0;
   out_2871704563598328823[127] = 0.0;
   out_2871704563598328823[128] = 0.0;
   out_2871704563598328823[129] = 0.0;
   out_2871704563598328823[130] = 0.0;
   out_2871704563598328823[131] = 0.0;
   out_2871704563598328823[132] = 0.0;
   out_2871704563598328823[133] = 1.0;
   out_2871704563598328823[134] = 0.0;
   out_2871704563598328823[135] = 0.0;
   out_2871704563598328823[136] = 0.0;
   out_2871704563598328823[137] = 0.0;
   out_2871704563598328823[138] = 0.0;
   out_2871704563598328823[139] = 0.0;
   out_2871704563598328823[140] = 0.0;
   out_2871704563598328823[141] = 0.0;
   out_2871704563598328823[142] = 0.0;
   out_2871704563598328823[143] = 0.0;
   out_2871704563598328823[144] = 0.0;
   out_2871704563598328823[145] = 0.0;
   out_2871704563598328823[146] = 0.0;
   out_2871704563598328823[147] = 0.0;
   out_2871704563598328823[148] = 0.0;
   out_2871704563598328823[149] = 0.0;
   out_2871704563598328823[150] = 0.0;
   out_2871704563598328823[151] = 0.0;
   out_2871704563598328823[152] = 1.0;
   out_2871704563598328823[153] = 0.0;
   out_2871704563598328823[154] = 0.0;
   out_2871704563598328823[155] = 0.0;
   out_2871704563598328823[156] = 0.0;
   out_2871704563598328823[157] = 0.0;
   out_2871704563598328823[158] = 0.0;
   out_2871704563598328823[159] = 0.0;
   out_2871704563598328823[160] = 0.0;
   out_2871704563598328823[161] = 0.0;
   out_2871704563598328823[162] = 0.0;
   out_2871704563598328823[163] = 0.0;
   out_2871704563598328823[164] = 0.0;
   out_2871704563598328823[165] = 0.0;
   out_2871704563598328823[166] = 0.0;
   out_2871704563598328823[167] = 0.0;
   out_2871704563598328823[168] = 0.0;
   out_2871704563598328823[169] = 0.0;
   out_2871704563598328823[170] = 0.0;
   out_2871704563598328823[171] = 1.0;
   out_2871704563598328823[172] = 0.0;
   out_2871704563598328823[173] = 0.0;
   out_2871704563598328823[174] = 0.0;
   out_2871704563598328823[175] = 0.0;
   out_2871704563598328823[176] = 0.0;
   out_2871704563598328823[177] = 0.0;
   out_2871704563598328823[178] = 0.0;
   out_2871704563598328823[179] = 0.0;
   out_2871704563598328823[180] = 0.0;
   out_2871704563598328823[181] = 0.0;
   out_2871704563598328823[182] = 0.0;
   out_2871704563598328823[183] = 0.0;
   out_2871704563598328823[184] = 0.0;
   out_2871704563598328823[185] = 0.0;
   out_2871704563598328823[186] = 0.0;
   out_2871704563598328823[187] = 0.0;
   out_2871704563598328823[188] = 0.0;
   out_2871704563598328823[189] = 0.0;
   out_2871704563598328823[190] = 1.0;
   out_2871704563598328823[191] = 0.0;
   out_2871704563598328823[192] = 0.0;
   out_2871704563598328823[193] = 0.0;
   out_2871704563598328823[194] = 0.0;
   out_2871704563598328823[195] = 0.0;
   out_2871704563598328823[196] = 0.0;
   out_2871704563598328823[197] = 0.0;
   out_2871704563598328823[198] = 0.0;
   out_2871704563598328823[199] = 0.0;
   out_2871704563598328823[200] = 0.0;
   out_2871704563598328823[201] = 0.0;
   out_2871704563598328823[202] = 0.0;
   out_2871704563598328823[203] = 0.0;
   out_2871704563598328823[204] = 0.0;
   out_2871704563598328823[205] = 0.0;
   out_2871704563598328823[206] = 0.0;
   out_2871704563598328823[207] = 0.0;
   out_2871704563598328823[208] = 0.0;
   out_2871704563598328823[209] = 1.0;
   out_2871704563598328823[210] = 0.0;
   out_2871704563598328823[211] = 0.0;
   out_2871704563598328823[212] = 0.0;
   out_2871704563598328823[213] = 0.0;
   out_2871704563598328823[214] = 0.0;
   out_2871704563598328823[215] = 0.0;
   out_2871704563598328823[216] = 0.0;
   out_2871704563598328823[217] = 0.0;
   out_2871704563598328823[218] = 0.0;
   out_2871704563598328823[219] = 0.0;
   out_2871704563598328823[220] = 0.0;
   out_2871704563598328823[221] = 0.0;
   out_2871704563598328823[222] = 0.0;
   out_2871704563598328823[223] = 0.0;
   out_2871704563598328823[224] = 0.0;
   out_2871704563598328823[225] = 0.0;
   out_2871704563598328823[226] = 0.0;
   out_2871704563598328823[227] = 0.0;
   out_2871704563598328823[228] = 1.0;
   out_2871704563598328823[229] = 0.0;
   out_2871704563598328823[230] = 0.0;
   out_2871704563598328823[231] = 0.0;
   out_2871704563598328823[232] = 0.0;
   out_2871704563598328823[233] = 0.0;
   out_2871704563598328823[234] = 0.0;
   out_2871704563598328823[235] = 0.0;
   out_2871704563598328823[236] = 0.0;
   out_2871704563598328823[237] = 0.0;
   out_2871704563598328823[238] = 0.0;
   out_2871704563598328823[239] = 0.0;
   out_2871704563598328823[240] = 0.0;
   out_2871704563598328823[241] = 0.0;
   out_2871704563598328823[242] = 0.0;
   out_2871704563598328823[243] = 0.0;
   out_2871704563598328823[244] = 0.0;
   out_2871704563598328823[245] = 0.0;
   out_2871704563598328823[246] = 0.0;
   out_2871704563598328823[247] = 1.0;
   out_2871704563598328823[248] = 0.0;
   out_2871704563598328823[249] = 0.0;
   out_2871704563598328823[250] = 0.0;
   out_2871704563598328823[251] = 0.0;
   out_2871704563598328823[252] = 0.0;
   out_2871704563598328823[253] = 0.0;
   out_2871704563598328823[254] = 0.0;
   out_2871704563598328823[255] = 0.0;
   out_2871704563598328823[256] = 0.0;
   out_2871704563598328823[257] = 0.0;
   out_2871704563598328823[258] = 0.0;
   out_2871704563598328823[259] = 0.0;
   out_2871704563598328823[260] = 0.0;
   out_2871704563598328823[261] = 0.0;
   out_2871704563598328823[262] = 0.0;
   out_2871704563598328823[263] = 0.0;
   out_2871704563598328823[264] = 0.0;
   out_2871704563598328823[265] = 0.0;
   out_2871704563598328823[266] = 1.0;
   out_2871704563598328823[267] = 0.0;
   out_2871704563598328823[268] = 0.0;
   out_2871704563598328823[269] = 0.0;
   out_2871704563598328823[270] = 0.0;
   out_2871704563598328823[271] = 0.0;
   out_2871704563598328823[272] = 0.0;
   out_2871704563598328823[273] = 0.0;
   out_2871704563598328823[274] = 0.0;
   out_2871704563598328823[275] = 0.0;
   out_2871704563598328823[276] = 0.0;
   out_2871704563598328823[277] = 0.0;
   out_2871704563598328823[278] = 0.0;
   out_2871704563598328823[279] = 0.0;
   out_2871704563598328823[280] = 0.0;
   out_2871704563598328823[281] = 0.0;
   out_2871704563598328823[282] = 0.0;
   out_2871704563598328823[283] = 0.0;
   out_2871704563598328823[284] = 0.0;
   out_2871704563598328823[285] = 1.0;
   out_2871704563598328823[286] = 0.0;
   out_2871704563598328823[287] = 0.0;
   out_2871704563598328823[288] = 0.0;
   out_2871704563598328823[289] = 0.0;
   out_2871704563598328823[290] = 0.0;
   out_2871704563598328823[291] = 0.0;
   out_2871704563598328823[292] = 0.0;
   out_2871704563598328823[293] = 0.0;
   out_2871704563598328823[294] = 0.0;
   out_2871704563598328823[295] = 0.0;
   out_2871704563598328823[296] = 0.0;
   out_2871704563598328823[297] = 0.0;
   out_2871704563598328823[298] = 0.0;
   out_2871704563598328823[299] = 0.0;
   out_2871704563598328823[300] = 0.0;
   out_2871704563598328823[301] = 0.0;
   out_2871704563598328823[302] = 0.0;
   out_2871704563598328823[303] = 0.0;
   out_2871704563598328823[304] = 1.0;
   out_2871704563598328823[305] = 0.0;
   out_2871704563598328823[306] = 0.0;
   out_2871704563598328823[307] = 0.0;
   out_2871704563598328823[308] = 0.0;
   out_2871704563598328823[309] = 0.0;
   out_2871704563598328823[310] = 0.0;
   out_2871704563598328823[311] = 0.0;
   out_2871704563598328823[312] = 0.0;
   out_2871704563598328823[313] = 0.0;
   out_2871704563598328823[314] = 0.0;
   out_2871704563598328823[315] = 0.0;
   out_2871704563598328823[316] = 0.0;
   out_2871704563598328823[317] = 0.0;
   out_2871704563598328823[318] = 0.0;
   out_2871704563598328823[319] = 0.0;
   out_2871704563598328823[320] = 0.0;
   out_2871704563598328823[321] = 0.0;
   out_2871704563598328823[322] = 0.0;
   out_2871704563598328823[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7815213456120633288) {
   out_7815213456120633288[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7815213456120633288[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7815213456120633288[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7815213456120633288[3] = dt*state[12] + state[3];
   out_7815213456120633288[4] = dt*state[13] + state[4];
   out_7815213456120633288[5] = dt*state[14] + state[5];
   out_7815213456120633288[6] = state[6];
   out_7815213456120633288[7] = state[7];
   out_7815213456120633288[8] = state[8];
   out_7815213456120633288[9] = state[9];
   out_7815213456120633288[10] = state[10];
   out_7815213456120633288[11] = state[11];
   out_7815213456120633288[12] = state[12];
   out_7815213456120633288[13] = state[13];
   out_7815213456120633288[14] = state[14];
   out_7815213456120633288[15] = state[15];
   out_7815213456120633288[16] = state[16];
   out_7815213456120633288[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5268289123395507135) {
   out_5268289123395507135[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5268289123395507135[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5268289123395507135[2] = 0;
   out_5268289123395507135[3] = 0;
   out_5268289123395507135[4] = 0;
   out_5268289123395507135[5] = 0;
   out_5268289123395507135[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5268289123395507135[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5268289123395507135[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5268289123395507135[9] = 0;
   out_5268289123395507135[10] = 0;
   out_5268289123395507135[11] = 0;
   out_5268289123395507135[12] = 0;
   out_5268289123395507135[13] = 0;
   out_5268289123395507135[14] = 0;
   out_5268289123395507135[15] = 0;
   out_5268289123395507135[16] = 0;
   out_5268289123395507135[17] = 0;
   out_5268289123395507135[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5268289123395507135[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5268289123395507135[20] = 0;
   out_5268289123395507135[21] = 0;
   out_5268289123395507135[22] = 0;
   out_5268289123395507135[23] = 0;
   out_5268289123395507135[24] = 0;
   out_5268289123395507135[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5268289123395507135[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5268289123395507135[27] = 0;
   out_5268289123395507135[28] = 0;
   out_5268289123395507135[29] = 0;
   out_5268289123395507135[30] = 0;
   out_5268289123395507135[31] = 0;
   out_5268289123395507135[32] = 0;
   out_5268289123395507135[33] = 0;
   out_5268289123395507135[34] = 0;
   out_5268289123395507135[35] = 0;
   out_5268289123395507135[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5268289123395507135[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5268289123395507135[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5268289123395507135[39] = 0;
   out_5268289123395507135[40] = 0;
   out_5268289123395507135[41] = 0;
   out_5268289123395507135[42] = 0;
   out_5268289123395507135[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5268289123395507135[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5268289123395507135[45] = 0;
   out_5268289123395507135[46] = 0;
   out_5268289123395507135[47] = 0;
   out_5268289123395507135[48] = 0;
   out_5268289123395507135[49] = 0;
   out_5268289123395507135[50] = 0;
   out_5268289123395507135[51] = 0;
   out_5268289123395507135[52] = 0;
   out_5268289123395507135[53] = 0;
   out_5268289123395507135[54] = 0;
   out_5268289123395507135[55] = 0;
   out_5268289123395507135[56] = 0;
   out_5268289123395507135[57] = 1;
   out_5268289123395507135[58] = 0;
   out_5268289123395507135[59] = 0;
   out_5268289123395507135[60] = 0;
   out_5268289123395507135[61] = 0;
   out_5268289123395507135[62] = 0;
   out_5268289123395507135[63] = 0;
   out_5268289123395507135[64] = 0;
   out_5268289123395507135[65] = 0;
   out_5268289123395507135[66] = dt;
   out_5268289123395507135[67] = 0;
   out_5268289123395507135[68] = 0;
   out_5268289123395507135[69] = 0;
   out_5268289123395507135[70] = 0;
   out_5268289123395507135[71] = 0;
   out_5268289123395507135[72] = 0;
   out_5268289123395507135[73] = 0;
   out_5268289123395507135[74] = 0;
   out_5268289123395507135[75] = 0;
   out_5268289123395507135[76] = 1;
   out_5268289123395507135[77] = 0;
   out_5268289123395507135[78] = 0;
   out_5268289123395507135[79] = 0;
   out_5268289123395507135[80] = 0;
   out_5268289123395507135[81] = 0;
   out_5268289123395507135[82] = 0;
   out_5268289123395507135[83] = 0;
   out_5268289123395507135[84] = 0;
   out_5268289123395507135[85] = dt;
   out_5268289123395507135[86] = 0;
   out_5268289123395507135[87] = 0;
   out_5268289123395507135[88] = 0;
   out_5268289123395507135[89] = 0;
   out_5268289123395507135[90] = 0;
   out_5268289123395507135[91] = 0;
   out_5268289123395507135[92] = 0;
   out_5268289123395507135[93] = 0;
   out_5268289123395507135[94] = 0;
   out_5268289123395507135[95] = 1;
   out_5268289123395507135[96] = 0;
   out_5268289123395507135[97] = 0;
   out_5268289123395507135[98] = 0;
   out_5268289123395507135[99] = 0;
   out_5268289123395507135[100] = 0;
   out_5268289123395507135[101] = 0;
   out_5268289123395507135[102] = 0;
   out_5268289123395507135[103] = 0;
   out_5268289123395507135[104] = dt;
   out_5268289123395507135[105] = 0;
   out_5268289123395507135[106] = 0;
   out_5268289123395507135[107] = 0;
   out_5268289123395507135[108] = 0;
   out_5268289123395507135[109] = 0;
   out_5268289123395507135[110] = 0;
   out_5268289123395507135[111] = 0;
   out_5268289123395507135[112] = 0;
   out_5268289123395507135[113] = 0;
   out_5268289123395507135[114] = 1;
   out_5268289123395507135[115] = 0;
   out_5268289123395507135[116] = 0;
   out_5268289123395507135[117] = 0;
   out_5268289123395507135[118] = 0;
   out_5268289123395507135[119] = 0;
   out_5268289123395507135[120] = 0;
   out_5268289123395507135[121] = 0;
   out_5268289123395507135[122] = 0;
   out_5268289123395507135[123] = 0;
   out_5268289123395507135[124] = 0;
   out_5268289123395507135[125] = 0;
   out_5268289123395507135[126] = 0;
   out_5268289123395507135[127] = 0;
   out_5268289123395507135[128] = 0;
   out_5268289123395507135[129] = 0;
   out_5268289123395507135[130] = 0;
   out_5268289123395507135[131] = 0;
   out_5268289123395507135[132] = 0;
   out_5268289123395507135[133] = 1;
   out_5268289123395507135[134] = 0;
   out_5268289123395507135[135] = 0;
   out_5268289123395507135[136] = 0;
   out_5268289123395507135[137] = 0;
   out_5268289123395507135[138] = 0;
   out_5268289123395507135[139] = 0;
   out_5268289123395507135[140] = 0;
   out_5268289123395507135[141] = 0;
   out_5268289123395507135[142] = 0;
   out_5268289123395507135[143] = 0;
   out_5268289123395507135[144] = 0;
   out_5268289123395507135[145] = 0;
   out_5268289123395507135[146] = 0;
   out_5268289123395507135[147] = 0;
   out_5268289123395507135[148] = 0;
   out_5268289123395507135[149] = 0;
   out_5268289123395507135[150] = 0;
   out_5268289123395507135[151] = 0;
   out_5268289123395507135[152] = 1;
   out_5268289123395507135[153] = 0;
   out_5268289123395507135[154] = 0;
   out_5268289123395507135[155] = 0;
   out_5268289123395507135[156] = 0;
   out_5268289123395507135[157] = 0;
   out_5268289123395507135[158] = 0;
   out_5268289123395507135[159] = 0;
   out_5268289123395507135[160] = 0;
   out_5268289123395507135[161] = 0;
   out_5268289123395507135[162] = 0;
   out_5268289123395507135[163] = 0;
   out_5268289123395507135[164] = 0;
   out_5268289123395507135[165] = 0;
   out_5268289123395507135[166] = 0;
   out_5268289123395507135[167] = 0;
   out_5268289123395507135[168] = 0;
   out_5268289123395507135[169] = 0;
   out_5268289123395507135[170] = 0;
   out_5268289123395507135[171] = 1;
   out_5268289123395507135[172] = 0;
   out_5268289123395507135[173] = 0;
   out_5268289123395507135[174] = 0;
   out_5268289123395507135[175] = 0;
   out_5268289123395507135[176] = 0;
   out_5268289123395507135[177] = 0;
   out_5268289123395507135[178] = 0;
   out_5268289123395507135[179] = 0;
   out_5268289123395507135[180] = 0;
   out_5268289123395507135[181] = 0;
   out_5268289123395507135[182] = 0;
   out_5268289123395507135[183] = 0;
   out_5268289123395507135[184] = 0;
   out_5268289123395507135[185] = 0;
   out_5268289123395507135[186] = 0;
   out_5268289123395507135[187] = 0;
   out_5268289123395507135[188] = 0;
   out_5268289123395507135[189] = 0;
   out_5268289123395507135[190] = 1;
   out_5268289123395507135[191] = 0;
   out_5268289123395507135[192] = 0;
   out_5268289123395507135[193] = 0;
   out_5268289123395507135[194] = 0;
   out_5268289123395507135[195] = 0;
   out_5268289123395507135[196] = 0;
   out_5268289123395507135[197] = 0;
   out_5268289123395507135[198] = 0;
   out_5268289123395507135[199] = 0;
   out_5268289123395507135[200] = 0;
   out_5268289123395507135[201] = 0;
   out_5268289123395507135[202] = 0;
   out_5268289123395507135[203] = 0;
   out_5268289123395507135[204] = 0;
   out_5268289123395507135[205] = 0;
   out_5268289123395507135[206] = 0;
   out_5268289123395507135[207] = 0;
   out_5268289123395507135[208] = 0;
   out_5268289123395507135[209] = 1;
   out_5268289123395507135[210] = 0;
   out_5268289123395507135[211] = 0;
   out_5268289123395507135[212] = 0;
   out_5268289123395507135[213] = 0;
   out_5268289123395507135[214] = 0;
   out_5268289123395507135[215] = 0;
   out_5268289123395507135[216] = 0;
   out_5268289123395507135[217] = 0;
   out_5268289123395507135[218] = 0;
   out_5268289123395507135[219] = 0;
   out_5268289123395507135[220] = 0;
   out_5268289123395507135[221] = 0;
   out_5268289123395507135[222] = 0;
   out_5268289123395507135[223] = 0;
   out_5268289123395507135[224] = 0;
   out_5268289123395507135[225] = 0;
   out_5268289123395507135[226] = 0;
   out_5268289123395507135[227] = 0;
   out_5268289123395507135[228] = 1;
   out_5268289123395507135[229] = 0;
   out_5268289123395507135[230] = 0;
   out_5268289123395507135[231] = 0;
   out_5268289123395507135[232] = 0;
   out_5268289123395507135[233] = 0;
   out_5268289123395507135[234] = 0;
   out_5268289123395507135[235] = 0;
   out_5268289123395507135[236] = 0;
   out_5268289123395507135[237] = 0;
   out_5268289123395507135[238] = 0;
   out_5268289123395507135[239] = 0;
   out_5268289123395507135[240] = 0;
   out_5268289123395507135[241] = 0;
   out_5268289123395507135[242] = 0;
   out_5268289123395507135[243] = 0;
   out_5268289123395507135[244] = 0;
   out_5268289123395507135[245] = 0;
   out_5268289123395507135[246] = 0;
   out_5268289123395507135[247] = 1;
   out_5268289123395507135[248] = 0;
   out_5268289123395507135[249] = 0;
   out_5268289123395507135[250] = 0;
   out_5268289123395507135[251] = 0;
   out_5268289123395507135[252] = 0;
   out_5268289123395507135[253] = 0;
   out_5268289123395507135[254] = 0;
   out_5268289123395507135[255] = 0;
   out_5268289123395507135[256] = 0;
   out_5268289123395507135[257] = 0;
   out_5268289123395507135[258] = 0;
   out_5268289123395507135[259] = 0;
   out_5268289123395507135[260] = 0;
   out_5268289123395507135[261] = 0;
   out_5268289123395507135[262] = 0;
   out_5268289123395507135[263] = 0;
   out_5268289123395507135[264] = 0;
   out_5268289123395507135[265] = 0;
   out_5268289123395507135[266] = 1;
   out_5268289123395507135[267] = 0;
   out_5268289123395507135[268] = 0;
   out_5268289123395507135[269] = 0;
   out_5268289123395507135[270] = 0;
   out_5268289123395507135[271] = 0;
   out_5268289123395507135[272] = 0;
   out_5268289123395507135[273] = 0;
   out_5268289123395507135[274] = 0;
   out_5268289123395507135[275] = 0;
   out_5268289123395507135[276] = 0;
   out_5268289123395507135[277] = 0;
   out_5268289123395507135[278] = 0;
   out_5268289123395507135[279] = 0;
   out_5268289123395507135[280] = 0;
   out_5268289123395507135[281] = 0;
   out_5268289123395507135[282] = 0;
   out_5268289123395507135[283] = 0;
   out_5268289123395507135[284] = 0;
   out_5268289123395507135[285] = 1;
   out_5268289123395507135[286] = 0;
   out_5268289123395507135[287] = 0;
   out_5268289123395507135[288] = 0;
   out_5268289123395507135[289] = 0;
   out_5268289123395507135[290] = 0;
   out_5268289123395507135[291] = 0;
   out_5268289123395507135[292] = 0;
   out_5268289123395507135[293] = 0;
   out_5268289123395507135[294] = 0;
   out_5268289123395507135[295] = 0;
   out_5268289123395507135[296] = 0;
   out_5268289123395507135[297] = 0;
   out_5268289123395507135[298] = 0;
   out_5268289123395507135[299] = 0;
   out_5268289123395507135[300] = 0;
   out_5268289123395507135[301] = 0;
   out_5268289123395507135[302] = 0;
   out_5268289123395507135[303] = 0;
   out_5268289123395507135[304] = 1;
   out_5268289123395507135[305] = 0;
   out_5268289123395507135[306] = 0;
   out_5268289123395507135[307] = 0;
   out_5268289123395507135[308] = 0;
   out_5268289123395507135[309] = 0;
   out_5268289123395507135[310] = 0;
   out_5268289123395507135[311] = 0;
   out_5268289123395507135[312] = 0;
   out_5268289123395507135[313] = 0;
   out_5268289123395507135[314] = 0;
   out_5268289123395507135[315] = 0;
   out_5268289123395507135[316] = 0;
   out_5268289123395507135[317] = 0;
   out_5268289123395507135[318] = 0;
   out_5268289123395507135[319] = 0;
   out_5268289123395507135[320] = 0;
   out_5268289123395507135[321] = 0;
   out_5268289123395507135[322] = 0;
   out_5268289123395507135[323] = 1;
}
void h_4(double *state, double *unused, double *out_3086539292408065832) {
   out_3086539292408065832[0] = state[6] + state[9];
   out_3086539292408065832[1] = state[7] + state[10];
   out_3086539292408065832[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2280813821440751912) {
   out_2280813821440751912[0] = 0;
   out_2280813821440751912[1] = 0;
   out_2280813821440751912[2] = 0;
   out_2280813821440751912[3] = 0;
   out_2280813821440751912[4] = 0;
   out_2280813821440751912[5] = 0;
   out_2280813821440751912[6] = 1;
   out_2280813821440751912[7] = 0;
   out_2280813821440751912[8] = 0;
   out_2280813821440751912[9] = 1;
   out_2280813821440751912[10] = 0;
   out_2280813821440751912[11] = 0;
   out_2280813821440751912[12] = 0;
   out_2280813821440751912[13] = 0;
   out_2280813821440751912[14] = 0;
   out_2280813821440751912[15] = 0;
   out_2280813821440751912[16] = 0;
   out_2280813821440751912[17] = 0;
   out_2280813821440751912[18] = 0;
   out_2280813821440751912[19] = 0;
   out_2280813821440751912[20] = 0;
   out_2280813821440751912[21] = 0;
   out_2280813821440751912[22] = 0;
   out_2280813821440751912[23] = 0;
   out_2280813821440751912[24] = 0;
   out_2280813821440751912[25] = 1;
   out_2280813821440751912[26] = 0;
   out_2280813821440751912[27] = 0;
   out_2280813821440751912[28] = 1;
   out_2280813821440751912[29] = 0;
   out_2280813821440751912[30] = 0;
   out_2280813821440751912[31] = 0;
   out_2280813821440751912[32] = 0;
   out_2280813821440751912[33] = 0;
   out_2280813821440751912[34] = 0;
   out_2280813821440751912[35] = 0;
   out_2280813821440751912[36] = 0;
   out_2280813821440751912[37] = 0;
   out_2280813821440751912[38] = 0;
   out_2280813821440751912[39] = 0;
   out_2280813821440751912[40] = 0;
   out_2280813821440751912[41] = 0;
   out_2280813821440751912[42] = 0;
   out_2280813821440751912[43] = 0;
   out_2280813821440751912[44] = 1;
   out_2280813821440751912[45] = 0;
   out_2280813821440751912[46] = 0;
   out_2280813821440751912[47] = 1;
   out_2280813821440751912[48] = 0;
   out_2280813821440751912[49] = 0;
   out_2280813821440751912[50] = 0;
   out_2280813821440751912[51] = 0;
   out_2280813821440751912[52] = 0;
   out_2280813821440751912[53] = 0;
}
void h_10(double *state, double *unused, double *out_7331610063879172077) {
   out_7331610063879172077[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7331610063879172077[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7331610063879172077[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1458363770220884896) {
   out_1458363770220884896[0] = 0;
   out_1458363770220884896[1] = 9.8100000000000005*cos(state[1]);
   out_1458363770220884896[2] = 0;
   out_1458363770220884896[3] = 0;
   out_1458363770220884896[4] = -state[8];
   out_1458363770220884896[5] = state[7];
   out_1458363770220884896[6] = 0;
   out_1458363770220884896[7] = state[5];
   out_1458363770220884896[8] = -state[4];
   out_1458363770220884896[9] = 0;
   out_1458363770220884896[10] = 0;
   out_1458363770220884896[11] = 0;
   out_1458363770220884896[12] = 1;
   out_1458363770220884896[13] = 0;
   out_1458363770220884896[14] = 0;
   out_1458363770220884896[15] = 1;
   out_1458363770220884896[16] = 0;
   out_1458363770220884896[17] = 0;
   out_1458363770220884896[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1458363770220884896[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1458363770220884896[20] = 0;
   out_1458363770220884896[21] = state[8];
   out_1458363770220884896[22] = 0;
   out_1458363770220884896[23] = -state[6];
   out_1458363770220884896[24] = -state[5];
   out_1458363770220884896[25] = 0;
   out_1458363770220884896[26] = state[3];
   out_1458363770220884896[27] = 0;
   out_1458363770220884896[28] = 0;
   out_1458363770220884896[29] = 0;
   out_1458363770220884896[30] = 0;
   out_1458363770220884896[31] = 1;
   out_1458363770220884896[32] = 0;
   out_1458363770220884896[33] = 0;
   out_1458363770220884896[34] = 1;
   out_1458363770220884896[35] = 0;
   out_1458363770220884896[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1458363770220884896[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1458363770220884896[38] = 0;
   out_1458363770220884896[39] = -state[7];
   out_1458363770220884896[40] = state[6];
   out_1458363770220884896[41] = 0;
   out_1458363770220884896[42] = state[4];
   out_1458363770220884896[43] = -state[3];
   out_1458363770220884896[44] = 0;
   out_1458363770220884896[45] = 0;
   out_1458363770220884896[46] = 0;
   out_1458363770220884896[47] = 0;
   out_1458363770220884896[48] = 0;
   out_1458363770220884896[49] = 0;
   out_1458363770220884896[50] = 1;
   out_1458363770220884896[51] = 0;
   out_1458363770220884896[52] = 0;
   out_1458363770220884896[53] = 1;
}
void h_13(double *state, double *unused, double *out_4988216010094665786) {
   out_4988216010094665786[0] = state[3];
   out_4988216010094665786[1] = state[4];
   out_4988216010094665786[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5493087646773084713) {
   out_5493087646773084713[0] = 0;
   out_5493087646773084713[1] = 0;
   out_5493087646773084713[2] = 0;
   out_5493087646773084713[3] = 1;
   out_5493087646773084713[4] = 0;
   out_5493087646773084713[5] = 0;
   out_5493087646773084713[6] = 0;
   out_5493087646773084713[7] = 0;
   out_5493087646773084713[8] = 0;
   out_5493087646773084713[9] = 0;
   out_5493087646773084713[10] = 0;
   out_5493087646773084713[11] = 0;
   out_5493087646773084713[12] = 0;
   out_5493087646773084713[13] = 0;
   out_5493087646773084713[14] = 0;
   out_5493087646773084713[15] = 0;
   out_5493087646773084713[16] = 0;
   out_5493087646773084713[17] = 0;
   out_5493087646773084713[18] = 0;
   out_5493087646773084713[19] = 0;
   out_5493087646773084713[20] = 0;
   out_5493087646773084713[21] = 0;
   out_5493087646773084713[22] = 1;
   out_5493087646773084713[23] = 0;
   out_5493087646773084713[24] = 0;
   out_5493087646773084713[25] = 0;
   out_5493087646773084713[26] = 0;
   out_5493087646773084713[27] = 0;
   out_5493087646773084713[28] = 0;
   out_5493087646773084713[29] = 0;
   out_5493087646773084713[30] = 0;
   out_5493087646773084713[31] = 0;
   out_5493087646773084713[32] = 0;
   out_5493087646773084713[33] = 0;
   out_5493087646773084713[34] = 0;
   out_5493087646773084713[35] = 0;
   out_5493087646773084713[36] = 0;
   out_5493087646773084713[37] = 0;
   out_5493087646773084713[38] = 0;
   out_5493087646773084713[39] = 0;
   out_5493087646773084713[40] = 0;
   out_5493087646773084713[41] = 1;
   out_5493087646773084713[42] = 0;
   out_5493087646773084713[43] = 0;
   out_5493087646773084713[44] = 0;
   out_5493087646773084713[45] = 0;
   out_5493087646773084713[46] = 0;
   out_5493087646773084713[47] = 0;
   out_5493087646773084713[48] = 0;
   out_5493087646773084713[49] = 0;
   out_5493087646773084713[50] = 0;
   out_5493087646773084713[51] = 0;
   out_5493087646773084713[52] = 0;
   out_5493087646773084713[53] = 0;
}
void h_14(double *state, double *unused, double *out_3365460086081990543) {
   out_3365460086081990543[0] = state[6];
   out_3365460086081990543[1] = state[7];
   out_3365460086081990543[2] = state[8];
}
void H_14(double *state, double *unused, double *out_801974610854620384) {
   out_801974610854620384[0] = 0;
   out_801974610854620384[1] = 0;
   out_801974610854620384[2] = 0;
   out_801974610854620384[3] = 0;
   out_801974610854620384[4] = 0;
   out_801974610854620384[5] = 0;
   out_801974610854620384[6] = 1;
   out_801974610854620384[7] = 0;
   out_801974610854620384[8] = 0;
   out_801974610854620384[9] = 0;
   out_801974610854620384[10] = 0;
   out_801974610854620384[11] = 0;
   out_801974610854620384[12] = 0;
   out_801974610854620384[13] = 0;
   out_801974610854620384[14] = 0;
   out_801974610854620384[15] = 0;
   out_801974610854620384[16] = 0;
   out_801974610854620384[17] = 0;
   out_801974610854620384[18] = 0;
   out_801974610854620384[19] = 0;
   out_801974610854620384[20] = 0;
   out_801974610854620384[21] = 0;
   out_801974610854620384[22] = 0;
   out_801974610854620384[23] = 0;
   out_801974610854620384[24] = 0;
   out_801974610854620384[25] = 1;
   out_801974610854620384[26] = 0;
   out_801974610854620384[27] = 0;
   out_801974610854620384[28] = 0;
   out_801974610854620384[29] = 0;
   out_801974610854620384[30] = 0;
   out_801974610854620384[31] = 0;
   out_801974610854620384[32] = 0;
   out_801974610854620384[33] = 0;
   out_801974610854620384[34] = 0;
   out_801974610854620384[35] = 0;
   out_801974610854620384[36] = 0;
   out_801974610854620384[37] = 0;
   out_801974610854620384[38] = 0;
   out_801974610854620384[39] = 0;
   out_801974610854620384[40] = 0;
   out_801974610854620384[41] = 0;
   out_801974610854620384[42] = 0;
   out_801974610854620384[43] = 0;
   out_801974610854620384[44] = 1;
   out_801974610854620384[45] = 0;
   out_801974610854620384[46] = 0;
   out_801974610854620384[47] = 0;
   out_801974610854620384[48] = 0;
   out_801974610854620384[49] = 0;
   out_801974610854620384[50] = 0;
   out_801974610854620384[51] = 0;
   out_801974610854620384[52] = 0;
   out_801974610854620384[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_8853800063451770622) {
  err_fun(nom_x, delta_x, out_8853800063451770622);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1474102248584144178) {
  inv_err_fun(nom_x, true_x, out_1474102248584144178);
}
void pose_H_mod_fun(double *state, double *out_2871704563598328823) {
  H_mod_fun(state, out_2871704563598328823);
}
void pose_f_fun(double *state, double dt, double *out_7815213456120633288) {
  f_fun(state,  dt, out_7815213456120633288);
}
void pose_F_fun(double *state, double dt, double *out_5268289123395507135) {
  F_fun(state,  dt, out_5268289123395507135);
}
void pose_h_4(double *state, double *unused, double *out_3086539292408065832) {
  h_4(state, unused, out_3086539292408065832);
}
void pose_H_4(double *state, double *unused, double *out_2280813821440751912) {
  H_4(state, unused, out_2280813821440751912);
}
void pose_h_10(double *state, double *unused, double *out_7331610063879172077) {
  h_10(state, unused, out_7331610063879172077);
}
void pose_H_10(double *state, double *unused, double *out_1458363770220884896) {
  H_10(state, unused, out_1458363770220884896);
}
void pose_h_13(double *state, double *unused, double *out_4988216010094665786) {
  h_13(state, unused, out_4988216010094665786);
}
void pose_H_13(double *state, double *unused, double *out_5493087646773084713) {
  H_13(state, unused, out_5493087646773084713);
}
void pose_h_14(double *state, double *unused, double *out_3365460086081990543) {
  h_14(state, unused, out_3365460086081990543);
}
void pose_H_14(double *state, double *unused, double *out_801974610854620384) {
  H_14(state, unused, out_801974610854620384);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
