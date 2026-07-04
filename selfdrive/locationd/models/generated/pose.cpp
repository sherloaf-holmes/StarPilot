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
void err_fun(double *nom_x, double *delta_x, double *out_4144373577117027043) {
   out_4144373577117027043[0] = delta_x[0] + nom_x[0];
   out_4144373577117027043[1] = delta_x[1] + nom_x[1];
   out_4144373577117027043[2] = delta_x[2] + nom_x[2];
   out_4144373577117027043[3] = delta_x[3] + nom_x[3];
   out_4144373577117027043[4] = delta_x[4] + nom_x[4];
   out_4144373577117027043[5] = delta_x[5] + nom_x[5];
   out_4144373577117027043[6] = delta_x[6] + nom_x[6];
   out_4144373577117027043[7] = delta_x[7] + nom_x[7];
   out_4144373577117027043[8] = delta_x[8] + nom_x[8];
   out_4144373577117027043[9] = delta_x[9] + nom_x[9];
   out_4144373577117027043[10] = delta_x[10] + nom_x[10];
   out_4144373577117027043[11] = delta_x[11] + nom_x[11];
   out_4144373577117027043[12] = delta_x[12] + nom_x[12];
   out_4144373577117027043[13] = delta_x[13] + nom_x[13];
   out_4144373577117027043[14] = delta_x[14] + nom_x[14];
   out_4144373577117027043[15] = delta_x[15] + nom_x[15];
   out_4144373577117027043[16] = delta_x[16] + nom_x[16];
   out_4144373577117027043[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6853650036846835829) {
   out_6853650036846835829[0] = -nom_x[0] + true_x[0];
   out_6853650036846835829[1] = -nom_x[1] + true_x[1];
   out_6853650036846835829[2] = -nom_x[2] + true_x[2];
   out_6853650036846835829[3] = -nom_x[3] + true_x[3];
   out_6853650036846835829[4] = -nom_x[4] + true_x[4];
   out_6853650036846835829[5] = -nom_x[5] + true_x[5];
   out_6853650036846835829[6] = -nom_x[6] + true_x[6];
   out_6853650036846835829[7] = -nom_x[7] + true_x[7];
   out_6853650036846835829[8] = -nom_x[8] + true_x[8];
   out_6853650036846835829[9] = -nom_x[9] + true_x[9];
   out_6853650036846835829[10] = -nom_x[10] + true_x[10];
   out_6853650036846835829[11] = -nom_x[11] + true_x[11];
   out_6853650036846835829[12] = -nom_x[12] + true_x[12];
   out_6853650036846835829[13] = -nom_x[13] + true_x[13];
   out_6853650036846835829[14] = -nom_x[14] + true_x[14];
   out_6853650036846835829[15] = -nom_x[15] + true_x[15];
   out_6853650036846835829[16] = -nom_x[16] + true_x[16];
   out_6853650036846835829[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3371818439070572688) {
   out_3371818439070572688[0] = 1.0;
   out_3371818439070572688[1] = 0.0;
   out_3371818439070572688[2] = 0.0;
   out_3371818439070572688[3] = 0.0;
   out_3371818439070572688[4] = 0.0;
   out_3371818439070572688[5] = 0.0;
   out_3371818439070572688[6] = 0.0;
   out_3371818439070572688[7] = 0.0;
   out_3371818439070572688[8] = 0.0;
   out_3371818439070572688[9] = 0.0;
   out_3371818439070572688[10] = 0.0;
   out_3371818439070572688[11] = 0.0;
   out_3371818439070572688[12] = 0.0;
   out_3371818439070572688[13] = 0.0;
   out_3371818439070572688[14] = 0.0;
   out_3371818439070572688[15] = 0.0;
   out_3371818439070572688[16] = 0.0;
   out_3371818439070572688[17] = 0.0;
   out_3371818439070572688[18] = 0.0;
   out_3371818439070572688[19] = 1.0;
   out_3371818439070572688[20] = 0.0;
   out_3371818439070572688[21] = 0.0;
   out_3371818439070572688[22] = 0.0;
   out_3371818439070572688[23] = 0.0;
   out_3371818439070572688[24] = 0.0;
   out_3371818439070572688[25] = 0.0;
   out_3371818439070572688[26] = 0.0;
   out_3371818439070572688[27] = 0.0;
   out_3371818439070572688[28] = 0.0;
   out_3371818439070572688[29] = 0.0;
   out_3371818439070572688[30] = 0.0;
   out_3371818439070572688[31] = 0.0;
   out_3371818439070572688[32] = 0.0;
   out_3371818439070572688[33] = 0.0;
   out_3371818439070572688[34] = 0.0;
   out_3371818439070572688[35] = 0.0;
   out_3371818439070572688[36] = 0.0;
   out_3371818439070572688[37] = 0.0;
   out_3371818439070572688[38] = 1.0;
   out_3371818439070572688[39] = 0.0;
   out_3371818439070572688[40] = 0.0;
   out_3371818439070572688[41] = 0.0;
   out_3371818439070572688[42] = 0.0;
   out_3371818439070572688[43] = 0.0;
   out_3371818439070572688[44] = 0.0;
   out_3371818439070572688[45] = 0.0;
   out_3371818439070572688[46] = 0.0;
   out_3371818439070572688[47] = 0.0;
   out_3371818439070572688[48] = 0.0;
   out_3371818439070572688[49] = 0.0;
   out_3371818439070572688[50] = 0.0;
   out_3371818439070572688[51] = 0.0;
   out_3371818439070572688[52] = 0.0;
   out_3371818439070572688[53] = 0.0;
   out_3371818439070572688[54] = 0.0;
   out_3371818439070572688[55] = 0.0;
   out_3371818439070572688[56] = 0.0;
   out_3371818439070572688[57] = 1.0;
   out_3371818439070572688[58] = 0.0;
   out_3371818439070572688[59] = 0.0;
   out_3371818439070572688[60] = 0.0;
   out_3371818439070572688[61] = 0.0;
   out_3371818439070572688[62] = 0.0;
   out_3371818439070572688[63] = 0.0;
   out_3371818439070572688[64] = 0.0;
   out_3371818439070572688[65] = 0.0;
   out_3371818439070572688[66] = 0.0;
   out_3371818439070572688[67] = 0.0;
   out_3371818439070572688[68] = 0.0;
   out_3371818439070572688[69] = 0.0;
   out_3371818439070572688[70] = 0.0;
   out_3371818439070572688[71] = 0.0;
   out_3371818439070572688[72] = 0.0;
   out_3371818439070572688[73] = 0.0;
   out_3371818439070572688[74] = 0.0;
   out_3371818439070572688[75] = 0.0;
   out_3371818439070572688[76] = 1.0;
   out_3371818439070572688[77] = 0.0;
   out_3371818439070572688[78] = 0.0;
   out_3371818439070572688[79] = 0.0;
   out_3371818439070572688[80] = 0.0;
   out_3371818439070572688[81] = 0.0;
   out_3371818439070572688[82] = 0.0;
   out_3371818439070572688[83] = 0.0;
   out_3371818439070572688[84] = 0.0;
   out_3371818439070572688[85] = 0.0;
   out_3371818439070572688[86] = 0.0;
   out_3371818439070572688[87] = 0.0;
   out_3371818439070572688[88] = 0.0;
   out_3371818439070572688[89] = 0.0;
   out_3371818439070572688[90] = 0.0;
   out_3371818439070572688[91] = 0.0;
   out_3371818439070572688[92] = 0.0;
   out_3371818439070572688[93] = 0.0;
   out_3371818439070572688[94] = 0.0;
   out_3371818439070572688[95] = 1.0;
   out_3371818439070572688[96] = 0.0;
   out_3371818439070572688[97] = 0.0;
   out_3371818439070572688[98] = 0.0;
   out_3371818439070572688[99] = 0.0;
   out_3371818439070572688[100] = 0.0;
   out_3371818439070572688[101] = 0.0;
   out_3371818439070572688[102] = 0.0;
   out_3371818439070572688[103] = 0.0;
   out_3371818439070572688[104] = 0.0;
   out_3371818439070572688[105] = 0.0;
   out_3371818439070572688[106] = 0.0;
   out_3371818439070572688[107] = 0.0;
   out_3371818439070572688[108] = 0.0;
   out_3371818439070572688[109] = 0.0;
   out_3371818439070572688[110] = 0.0;
   out_3371818439070572688[111] = 0.0;
   out_3371818439070572688[112] = 0.0;
   out_3371818439070572688[113] = 0.0;
   out_3371818439070572688[114] = 1.0;
   out_3371818439070572688[115] = 0.0;
   out_3371818439070572688[116] = 0.0;
   out_3371818439070572688[117] = 0.0;
   out_3371818439070572688[118] = 0.0;
   out_3371818439070572688[119] = 0.0;
   out_3371818439070572688[120] = 0.0;
   out_3371818439070572688[121] = 0.0;
   out_3371818439070572688[122] = 0.0;
   out_3371818439070572688[123] = 0.0;
   out_3371818439070572688[124] = 0.0;
   out_3371818439070572688[125] = 0.0;
   out_3371818439070572688[126] = 0.0;
   out_3371818439070572688[127] = 0.0;
   out_3371818439070572688[128] = 0.0;
   out_3371818439070572688[129] = 0.0;
   out_3371818439070572688[130] = 0.0;
   out_3371818439070572688[131] = 0.0;
   out_3371818439070572688[132] = 0.0;
   out_3371818439070572688[133] = 1.0;
   out_3371818439070572688[134] = 0.0;
   out_3371818439070572688[135] = 0.0;
   out_3371818439070572688[136] = 0.0;
   out_3371818439070572688[137] = 0.0;
   out_3371818439070572688[138] = 0.0;
   out_3371818439070572688[139] = 0.0;
   out_3371818439070572688[140] = 0.0;
   out_3371818439070572688[141] = 0.0;
   out_3371818439070572688[142] = 0.0;
   out_3371818439070572688[143] = 0.0;
   out_3371818439070572688[144] = 0.0;
   out_3371818439070572688[145] = 0.0;
   out_3371818439070572688[146] = 0.0;
   out_3371818439070572688[147] = 0.0;
   out_3371818439070572688[148] = 0.0;
   out_3371818439070572688[149] = 0.0;
   out_3371818439070572688[150] = 0.0;
   out_3371818439070572688[151] = 0.0;
   out_3371818439070572688[152] = 1.0;
   out_3371818439070572688[153] = 0.0;
   out_3371818439070572688[154] = 0.0;
   out_3371818439070572688[155] = 0.0;
   out_3371818439070572688[156] = 0.0;
   out_3371818439070572688[157] = 0.0;
   out_3371818439070572688[158] = 0.0;
   out_3371818439070572688[159] = 0.0;
   out_3371818439070572688[160] = 0.0;
   out_3371818439070572688[161] = 0.0;
   out_3371818439070572688[162] = 0.0;
   out_3371818439070572688[163] = 0.0;
   out_3371818439070572688[164] = 0.0;
   out_3371818439070572688[165] = 0.0;
   out_3371818439070572688[166] = 0.0;
   out_3371818439070572688[167] = 0.0;
   out_3371818439070572688[168] = 0.0;
   out_3371818439070572688[169] = 0.0;
   out_3371818439070572688[170] = 0.0;
   out_3371818439070572688[171] = 1.0;
   out_3371818439070572688[172] = 0.0;
   out_3371818439070572688[173] = 0.0;
   out_3371818439070572688[174] = 0.0;
   out_3371818439070572688[175] = 0.0;
   out_3371818439070572688[176] = 0.0;
   out_3371818439070572688[177] = 0.0;
   out_3371818439070572688[178] = 0.0;
   out_3371818439070572688[179] = 0.0;
   out_3371818439070572688[180] = 0.0;
   out_3371818439070572688[181] = 0.0;
   out_3371818439070572688[182] = 0.0;
   out_3371818439070572688[183] = 0.0;
   out_3371818439070572688[184] = 0.0;
   out_3371818439070572688[185] = 0.0;
   out_3371818439070572688[186] = 0.0;
   out_3371818439070572688[187] = 0.0;
   out_3371818439070572688[188] = 0.0;
   out_3371818439070572688[189] = 0.0;
   out_3371818439070572688[190] = 1.0;
   out_3371818439070572688[191] = 0.0;
   out_3371818439070572688[192] = 0.0;
   out_3371818439070572688[193] = 0.0;
   out_3371818439070572688[194] = 0.0;
   out_3371818439070572688[195] = 0.0;
   out_3371818439070572688[196] = 0.0;
   out_3371818439070572688[197] = 0.0;
   out_3371818439070572688[198] = 0.0;
   out_3371818439070572688[199] = 0.0;
   out_3371818439070572688[200] = 0.0;
   out_3371818439070572688[201] = 0.0;
   out_3371818439070572688[202] = 0.0;
   out_3371818439070572688[203] = 0.0;
   out_3371818439070572688[204] = 0.0;
   out_3371818439070572688[205] = 0.0;
   out_3371818439070572688[206] = 0.0;
   out_3371818439070572688[207] = 0.0;
   out_3371818439070572688[208] = 0.0;
   out_3371818439070572688[209] = 1.0;
   out_3371818439070572688[210] = 0.0;
   out_3371818439070572688[211] = 0.0;
   out_3371818439070572688[212] = 0.0;
   out_3371818439070572688[213] = 0.0;
   out_3371818439070572688[214] = 0.0;
   out_3371818439070572688[215] = 0.0;
   out_3371818439070572688[216] = 0.0;
   out_3371818439070572688[217] = 0.0;
   out_3371818439070572688[218] = 0.0;
   out_3371818439070572688[219] = 0.0;
   out_3371818439070572688[220] = 0.0;
   out_3371818439070572688[221] = 0.0;
   out_3371818439070572688[222] = 0.0;
   out_3371818439070572688[223] = 0.0;
   out_3371818439070572688[224] = 0.0;
   out_3371818439070572688[225] = 0.0;
   out_3371818439070572688[226] = 0.0;
   out_3371818439070572688[227] = 0.0;
   out_3371818439070572688[228] = 1.0;
   out_3371818439070572688[229] = 0.0;
   out_3371818439070572688[230] = 0.0;
   out_3371818439070572688[231] = 0.0;
   out_3371818439070572688[232] = 0.0;
   out_3371818439070572688[233] = 0.0;
   out_3371818439070572688[234] = 0.0;
   out_3371818439070572688[235] = 0.0;
   out_3371818439070572688[236] = 0.0;
   out_3371818439070572688[237] = 0.0;
   out_3371818439070572688[238] = 0.0;
   out_3371818439070572688[239] = 0.0;
   out_3371818439070572688[240] = 0.0;
   out_3371818439070572688[241] = 0.0;
   out_3371818439070572688[242] = 0.0;
   out_3371818439070572688[243] = 0.0;
   out_3371818439070572688[244] = 0.0;
   out_3371818439070572688[245] = 0.0;
   out_3371818439070572688[246] = 0.0;
   out_3371818439070572688[247] = 1.0;
   out_3371818439070572688[248] = 0.0;
   out_3371818439070572688[249] = 0.0;
   out_3371818439070572688[250] = 0.0;
   out_3371818439070572688[251] = 0.0;
   out_3371818439070572688[252] = 0.0;
   out_3371818439070572688[253] = 0.0;
   out_3371818439070572688[254] = 0.0;
   out_3371818439070572688[255] = 0.0;
   out_3371818439070572688[256] = 0.0;
   out_3371818439070572688[257] = 0.0;
   out_3371818439070572688[258] = 0.0;
   out_3371818439070572688[259] = 0.0;
   out_3371818439070572688[260] = 0.0;
   out_3371818439070572688[261] = 0.0;
   out_3371818439070572688[262] = 0.0;
   out_3371818439070572688[263] = 0.0;
   out_3371818439070572688[264] = 0.0;
   out_3371818439070572688[265] = 0.0;
   out_3371818439070572688[266] = 1.0;
   out_3371818439070572688[267] = 0.0;
   out_3371818439070572688[268] = 0.0;
   out_3371818439070572688[269] = 0.0;
   out_3371818439070572688[270] = 0.0;
   out_3371818439070572688[271] = 0.0;
   out_3371818439070572688[272] = 0.0;
   out_3371818439070572688[273] = 0.0;
   out_3371818439070572688[274] = 0.0;
   out_3371818439070572688[275] = 0.0;
   out_3371818439070572688[276] = 0.0;
   out_3371818439070572688[277] = 0.0;
   out_3371818439070572688[278] = 0.0;
   out_3371818439070572688[279] = 0.0;
   out_3371818439070572688[280] = 0.0;
   out_3371818439070572688[281] = 0.0;
   out_3371818439070572688[282] = 0.0;
   out_3371818439070572688[283] = 0.0;
   out_3371818439070572688[284] = 0.0;
   out_3371818439070572688[285] = 1.0;
   out_3371818439070572688[286] = 0.0;
   out_3371818439070572688[287] = 0.0;
   out_3371818439070572688[288] = 0.0;
   out_3371818439070572688[289] = 0.0;
   out_3371818439070572688[290] = 0.0;
   out_3371818439070572688[291] = 0.0;
   out_3371818439070572688[292] = 0.0;
   out_3371818439070572688[293] = 0.0;
   out_3371818439070572688[294] = 0.0;
   out_3371818439070572688[295] = 0.0;
   out_3371818439070572688[296] = 0.0;
   out_3371818439070572688[297] = 0.0;
   out_3371818439070572688[298] = 0.0;
   out_3371818439070572688[299] = 0.0;
   out_3371818439070572688[300] = 0.0;
   out_3371818439070572688[301] = 0.0;
   out_3371818439070572688[302] = 0.0;
   out_3371818439070572688[303] = 0.0;
   out_3371818439070572688[304] = 1.0;
   out_3371818439070572688[305] = 0.0;
   out_3371818439070572688[306] = 0.0;
   out_3371818439070572688[307] = 0.0;
   out_3371818439070572688[308] = 0.0;
   out_3371818439070572688[309] = 0.0;
   out_3371818439070572688[310] = 0.0;
   out_3371818439070572688[311] = 0.0;
   out_3371818439070572688[312] = 0.0;
   out_3371818439070572688[313] = 0.0;
   out_3371818439070572688[314] = 0.0;
   out_3371818439070572688[315] = 0.0;
   out_3371818439070572688[316] = 0.0;
   out_3371818439070572688[317] = 0.0;
   out_3371818439070572688[318] = 0.0;
   out_3371818439070572688[319] = 0.0;
   out_3371818439070572688[320] = 0.0;
   out_3371818439070572688[321] = 0.0;
   out_3371818439070572688[322] = 0.0;
   out_3371818439070572688[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5714706012790040296) {
   out_5714706012790040296[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5714706012790040296[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5714706012790040296[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5714706012790040296[3] = dt*state[12] + state[3];
   out_5714706012790040296[4] = dt*state[13] + state[4];
   out_5714706012790040296[5] = dt*state[14] + state[5];
   out_5714706012790040296[6] = state[6];
   out_5714706012790040296[7] = state[7];
   out_5714706012790040296[8] = state[8];
   out_5714706012790040296[9] = state[9];
   out_5714706012790040296[10] = state[10];
   out_5714706012790040296[11] = state[11];
   out_5714706012790040296[12] = state[12];
   out_5714706012790040296[13] = state[13];
   out_5714706012790040296[14] = state[14];
   out_5714706012790040296[15] = state[15];
   out_5714706012790040296[16] = state[16];
   out_5714706012790040296[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2453777362197051626) {
   out_2453777362197051626[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2453777362197051626[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2453777362197051626[2] = 0;
   out_2453777362197051626[3] = 0;
   out_2453777362197051626[4] = 0;
   out_2453777362197051626[5] = 0;
   out_2453777362197051626[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2453777362197051626[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2453777362197051626[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2453777362197051626[9] = 0;
   out_2453777362197051626[10] = 0;
   out_2453777362197051626[11] = 0;
   out_2453777362197051626[12] = 0;
   out_2453777362197051626[13] = 0;
   out_2453777362197051626[14] = 0;
   out_2453777362197051626[15] = 0;
   out_2453777362197051626[16] = 0;
   out_2453777362197051626[17] = 0;
   out_2453777362197051626[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2453777362197051626[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2453777362197051626[20] = 0;
   out_2453777362197051626[21] = 0;
   out_2453777362197051626[22] = 0;
   out_2453777362197051626[23] = 0;
   out_2453777362197051626[24] = 0;
   out_2453777362197051626[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2453777362197051626[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2453777362197051626[27] = 0;
   out_2453777362197051626[28] = 0;
   out_2453777362197051626[29] = 0;
   out_2453777362197051626[30] = 0;
   out_2453777362197051626[31] = 0;
   out_2453777362197051626[32] = 0;
   out_2453777362197051626[33] = 0;
   out_2453777362197051626[34] = 0;
   out_2453777362197051626[35] = 0;
   out_2453777362197051626[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2453777362197051626[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2453777362197051626[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2453777362197051626[39] = 0;
   out_2453777362197051626[40] = 0;
   out_2453777362197051626[41] = 0;
   out_2453777362197051626[42] = 0;
   out_2453777362197051626[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2453777362197051626[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2453777362197051626[45] = 0;
   out_2453777362197051626[46] = 0;
   out_2453777362197051626[47] = 0;
   out_2453777362197051626[48] = 0;
   out_2453777362197051626[49] = 0;
   out_2453777362197051626[50] = 0;
   out_2453777362197051626[51] = 0;
   out_2453777362197051626[52] = 0;
   out_2453777362197051626[53] = 0;
   out_2453777362197051626[54] = 0;
   out_2453777362197051626[55] = 0;
   out_2453777362197051626[56] = 0;
   out_2453777362197051626[57] = 1;
   out_2453777362197051626[58] = 0;
   out_2453777362197051626[59] = 0;
   out_2453777362197051626[60] = 0;
   out_2453777362197051626[61] = 0;
   out_2453777362197051626[62] = 0;
   out_2453777362197051626[63] = 0;
   out_2453777362197051626[64] = 0;
   out_2453777362197051626[65] = 0;
   out_2453777362197051626[66] = dt;
   out_2453777362197051626[67] = 0;
   out_2453777362197051626[68] = 0;
   out_2453777362197051626[69] = 0;
   out_2453777362197051626[70] = 0;
   out_2453777362197051626[71] = 0;
   out_2453777362197051626[72] = 0;
   out_2453777362197051626[73] = 0;
   out_2453777362197051626[74] = 0;
   out_2453777362197051626[75] = 0;
   out_2453777362197051626[76] = 1;
   out_2453777362197051626[77] = 0;
   out_2453777362197051626[78] = 0;
   out_2453777362197051626[79] = 0;
   out_2453777362197051626[80] = 0;
   out_2453777362197051626[81] = 0;
   out_2453777362197051626[82] = 0;
   out_2453777362197051626[83] = 0;
   out_2453777362197051626[84] = 0;
   out_2453777362197051626[85] = dt;
   out_2453777362197051626[86] = 0;
   out_2453777362197051626[87] = 0;
   out_2453777362197051626[88] = 0;
   out_2453777362197051626[89] = 0;
   out_2453777362197051626[90] = 0;
   out_2453777362197051626[91] = 0;
   out_2453777362197051626[92] = 0;
   out_2453777362197051626[93] = 0;
   out_2453777362197051626[94] = 0;
   out_2453777362197051626[95] = 1;
   out_2453777362197051626[96] = 0;
   out_2453777362197051626[97] = 0;
   out_2453777362197051626[98] = 0;
   out_2453777362197051626[99] = 0;
   out_2453777362197051626[100] = 0;
   out_2453777362197051626[101] = 0;
   out_2453777362197051626[102] = 0;
   out_2453777362197051626[103] = 0;
   out_2453777362197051626[104] = dt;
   out_2453777362197051626[105] = 0;
   out_2453777362197051626[106] = 0;
   out_2453777362197051626[107] = 0;
   out_2453777362197051626[108] = 0;
   out_2453777362197051626[109] = 0;
   out_2453777362197051626[110] = 0;
   out_2453777362197051626[111] = 0;
   out_2453777362197051626[112] = 0;
   out_2453777362197051626[113] = 0;
   out_2453777362197051626[114] = 1;
   out_2453777362197051626[115] = 0;
   out_2453777362197051626[116] = 0;
   out_2453777362197051626[117] = 0;
   out_2453777362197051626[118] = 0;
   out_2453777362197051626[119] = 0;
   out_2453777362197051626[120] = 0;
   out_2453777362197051626[121] = 0;
   out_2453777362197051626[122] = 0;
   out_2453777362197051626[123] = 0;
   out_2453777362197051626[124] = 0;
   out_2453777362197051626[125] = 0;
   out_2453777362197051626[126] = 0;
   out_2453777362197051626[127] = 0;
   out_2453777362197051626[128] = 0;
   out_2453777362197051626[129] = 0;
   out_2453777362197051626[130] = 0;
   out_2453777362197051626[131] = 0;
   out_2453777362197051626[132] = 0;
   out_2453777362197051626[133] = 1;
   out_2453777362197051626[134] = 0;
   out_2453777362197051626[135] = 0;
   out_2453777362197051626[136] = 0;
   out_2453777362197051626[137] = 0;
   out_2453777362197051626[138] = 0;
   out_2453777362197051626[139] = 0;
   out_2453777362197051626[140] = 0;
   out_2453777362197051626[141] = 0;
   out_2453777362197051626[142] = 0;
   out_2453777362197051626[143] = 0;
   out_2453777362197051626[144] = 0;
   out_2453777362197051626[145] = 0;
   out_2453777362197051626[146] = 0;
   out_2453777362197051626[147] = 0;
   out_2453777362197051626[148] = 0;
   out_2453777362197051626[149] = 0;
   out_2453777362197051626[150] = 0;
   out_2453777362197051626[151] = 0;
   out_2453777362197051626[152] = 1;
   out_2453777362197051626[153] = 0;
   out_2453777362197051626[154] = 0;
   out_2453777362197051626[155] = 0;
   out_2453777362197051626[156] = 0;
   out_2453777362197051626[157] = 0;
   out_2453777362197051626[158] = 0;
   out_2453777362197051626[159] = 0;
   out_2453777362197051626[160] = 0;
   out_2453777362197051626[161] = 0;
   out_2453777362197051626[162] = 0;
   out_2453777362197051626[163] = 0;
   out_2453777362197051626[164] = 0;
   out_2453777362197051626[165] = 0;
   out_2453777362197051626[166] = 0;
   out_2453777362197051626[167] = 0;
   out_2453777362197051626[168] = 0;
   out_2453777362197051626[169] = 0;
   out_2453777362197051626[170] = 0;
   out_2453777362197051626[171] = 1;
   out_2453777362197051626[172] = 0;
   out_2453777362197051626[173] = 0;
   out_2453777362197051626[174] = 0;
   out_2453777362197051626[175] = 0;
   out_2453777362197051626[176] = 0;
   out_2453777362197051626[177] = 0;
   out_2453777362197051626[178] = 0;
   out_2453777362197051626[179] = 0;
   out_2453777362197051626[180] = 0;
   out_2453777362197051626[181] = 0;
   out_2453777362197051626[182] = 0;
   out_2453777362197051626[183] = 0;
   out_2453777362197051626[184] = 0;
   out_2453777362197051626[185] = 0;
   out_2453777362197051626[186] = 0;
   out_2453777362197051626[187] = 0;
   out_2453777362197051626[188] = 0;
   out_2453777362197051626[189] = 0;
   out_2453777362197051626[190] = 1;
   out_2453777362197051626[191] = 0;
   out_2453777362197051626[192] = 0;
   out_2453777362197051626[193] = 0;
   out_2453777362197051626[194] = 0;
   out_2453777362197051626[195] = 0;
   out_2453777362197051626[196] = 0;
   out_2453777362197051626[197] = 0;
   out_2453777362197051626[198] = 0;
   out_2453777362197051626[199] = 0;
   out_2453777362197051626[200] = 0;
   out_2453777362197051626[201] = 0;
   out_2453777362197051626[202] = 0;
   out_2453777362197051626[203] = 0;
   out_2453777362197051626[204] = 0;
   out_2453777362197051626[205] = 0;
   out_2453777362197051626[206] = 0;
   out_2453777362197051626[207] = 0;
   out_2453777362197051626[208] = 0;
   out_2453777362197051626[209] = 1;
   out_2453777362197051626[210] = 0;
   out_2453777362197051626[211] = 0;
   out_2453777362197051626[212] = 0;
   out_2453777362197051626[213] = 0;
   out_2453777362197051626[214] = 0;
   out_2453777362197051626[215] = 0;
   out_2453777362197051626[216] = 0;
   out_2453777362197051626[217] = 0;
   out_2453777362197051626[218] = 0;
   out_2453777362197051626[219] = 0;
   out_2453777362197051626[220] = 0;
   out_2453777362197051626[221] = 0;
   out_2453777362197051626[222] = 0;
   out_2453777362197051626[223] = 0;
   out_2453777362197051626[224] = 0;
   out_2453777362197051626[225] = 0;
   out_2453777362197051626[226] = 0;
   out_2453777362197051626[227] = 0;
   out_2453777362197051626[228] = 1;
   out_2453777362197051626[229] = 0;
   out_2453777362197051626[230] = 0;
   out_2453777362197051626[231] = 0;
   out_2453777362197051626[232] = 0;
   out_2453777362197051626[233] = 0;
   out_2453777362197051626[234] = 0;
   out_2453777362197051626[235] = 0;
   out_2453777362197051626[236] = 0;
   out_2453777362197051626[237] = 0;
   out_2453777362197051626[238] = 0;
   out_2453777362197051626[239] = 0;
   out_2453777362197051626[240] = 0;
   out_2453777362197051626[241] = 0;
   out_2453777362197051626[242] = 0;
   out_2453777362197051626[243] = 0;
   out_2453777362197051626[244] = 0;
   out_2453777362197051626[245] = 0;
   out_2453777362197051626[246] = 0;
   out_2453777362197051626[247] = 1;
   out_2453777362197051626[248] = 0;
   out_2453777362197051626[249] = 0;
   out_2453777362197051626[250] = 0;
   out_2453777362197051626[251] = 0;
   out_2453777362197051626[252] = 0;
   out_2453777362197051626[253] = 0;
   out_2453777362197051626[254] = 0;
   out_2453777362197051626[255] = 0;
   out_2453777362197051626[256] = 0;
   out_2453777362197051626[257] = 0;
   out_2453777362197051626[258] = 0;
   out_2453777362197051626[259] = 0;
   out_2453777362197051626[260] = 0;
   out_2453777362197051626[261] = 0;
   out_2453777362197051626[262] = 0;
   out_2453777362197051626[263] = 0;
   out_2453777362197051626[264] = 0;
   out_2453777362197051626[265] = 0;
   out_2453777362197051626[266] = 1;
   out_2453777362197051626[267] = 0;
   out_2453777362197051626[268] = 0;
   out_2453777362197051626[269] = 0;
   out_2453777362197051626[270] = 0;
   out_2453777362197051626[271] = 0;
   out_2453777362197051626[272] = 0;
   out_2453777362197051626[273] = 0;
   out_2453777362197051626[274] = 0;
   out_2453777362197051626[275] = 0;
   out_2453777362197051626[276] = 0;
   out_2453777362197051626[277] = 0;
   out_2453777362197051626[278] = 0;
   out_2453777362197051626[279] = 0;
   out_2453777362197051626[280] = 0;
   out_2453777362197051626[281] = 0;
   out_2453777362197051626[282] = 0;
   out_2453777362197051626[283] = 0;
   out_2453777362197051626[284] = 0;
   out_2453777362197051626[285] = 1;
   out_2453777362197051626[286] = 0;
   out_2453777362197051626[287] = 0;
   out_2453777362197051626[288] = 0;
   out_2453777362197051626[289] = 0;
   out_2453777362197051626[290] = 0;
   out_2453777362197051626[291] = 0;
   out_2453777362197051626[292] = 0;
   out_2453777362197051626[293] = 0;
   out_2453777362197051626[294] = 0;
   out_2453777362197051626[295] = 0;
   out_2453777362197051626[296] = 0;
   out_2453777362197051626[297] = 0;
   out_2453777362197051626[298] = 0;
   out_2453777362197051626[299] = 0;
   out_2453777362197051626[300] = 0;
   out_2453777362197051626[301] = 0;
   out_2453777362197051626[302] = 0;
   out_2453777362197051626[303] = 0;
   out_2453777362197051626[304] = 1;
   out_2453777362197051626[305] = 0;
   out_2453777362197051626[306] = 0;
   out_2453777362197051626[307] = 0;
   out_2453777362197051626[308] = 0;
   out_2453777362197051626[309] = 0;
   out_2453777362197051626[310] = 0;
   out_2453777362197051626[311] = 0;
   out_2453777362197051626[312] = 0;
   out_2453777362197051626[313] = 0;
   out_2453777362197051626[314] = 0;
   out_2453777362197051626[315] = 0;
   out_2453777362197051626[316] = 0;
   out_2453777362197051626[317] = 0;
   out_2453777362197051626[318] = 0;
   out_2453777362197051626[319] = 0;
   out_2453777362197051626[320] = 0;
   out_2453777362197051626[321] = 0;
   out_2453777362197051626[322] = 0;
   out_2453777362197051626[323] = 1;
}
void h_4(double *state, double *unused, double *out_7475340564657993549) {
   out_7475340564657993549[0] = state[6] + state[9];
   out_7475340564657993549[1] = state[7] + state[10];
   out_7475340564657993549[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4569765920953470792) {
   out_4569765920953470792[0] = 0;
   out_4569765920953470792[1] = 0;
   out_4569765920953470792[2] = 0;
   out_4569765920953470792[3] = 0;
   out_4569765920953470792[4] = 0;
   out_4569765920953470792[5] = 0;
   out_4569765920953470792[6] = 1;
   out_4569765920953470792[7] = 0;
   out_4569765920953470792[8] = 0;
   out_4569765920953470792[9] = 1;
   out_4569765920953470792[10] = 0;
   out_4569765920953470792[11] = 0;
   out_4569765920953470792[12] = 0;
   out_4569765920953470792[13] = 0;
   out_4569765920953470792[14] = 0;
   out_4569765920953470792[15] = 0;
   out_4569765920953470792[16] = 0;
   out_4569765920953470792[17] = 0;
   out_4569765920953470792[18] = 0;
   out_4569765920953470792[19] = 0;
   out_4569765920953470792[20] = 0;
   out_4569765920953470792[21] = 0;
   out_4569765920953470792[22] = 0;
   out_4569765920953470792[23] = 0;
   out_4569765920953470792[24] = 0;
   out_4569765920953470792[25] = 1;
   out_4569765920953470792[26] = 0;
   out_4569765920953470792[27] = 0;
   out_4569765920953470792[28] = 1;
   out_4569765920953470792[29] = 0;
   out_4569765920953470792[30] = 0;
   out_4569765920953470792[31] = 0;
   out_4569765920953470792[32] = 0;
   out_4569765920953470792[33] = 0;
   out_4569765920953470792[34] = 0;
   out_4569765920953470792[35] = 0;
   out_4569765920953470792[36] = 0;
   out_4569765920953470792[37] = 0;
   out_4569765920953470792[38] = 0;
   out_4569765920953470792[39] = 0;
   out_4569765920953470792[40] = 0;
   out_4569765920953470792[41] = 0;
   out_4569765920953470792[42] = 0;
   out_4569765920953470792[43] = 0;
   out_4569765920953470792[44] = 1;
   out_4569765920953470792[45] = 0;
   out_4569765920953470792[46] = 0;
   out_4569765920953470792[47] = 1;
   out_4569765920953470792[48] = 0;
   out_4569765920953470792[49] = 0;
   out_4569765920953470792[50] = 0;
   out_4569765920953470792[51] = 0;
   out_4569765920953470792[52] = 0;
   out_4569765920953470792[53] = 0;
}
void h_10(double *state, double *unused, double *out_4511047330400710663) {
   out_4511047330400710663[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4511047330400710663[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4511047330400710663[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2217581622006004275) {
   out_2217581622006004275[0] = 0;
   out_2217581622006004275[1] = 9.8100000000000005*cos(state[1]);
   out_2217581622006004275[2] = 0;
   out_2217581622006004275[3] = 0;
   out_2217581622006004275[4] = -state[8];
   out_2217581622006004275[5] = state[7];
   out_2217581622006004275[6] = 0;
   out_2217581622006004275[7] = state[5];
   out_2217581622006004275[8] = -state[4];
   out_2217581622006004275[9] = 0;
   out_2217581622006004275[10] = 0;
   out_2217581622006004275[11] = 0;
   out_2217581622006004275[12] = 1;
   out_2217581622006004275[13] = 0;
   out_2217581622006004275[14] = 0;
   out_2217581622006004275[15] = 1;
   out_2217581622006004275[16] = 0;
   out_2217581622006004275[17] = 0;
   out_2217581622006004275[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2217581622006004275[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2217581622006004275[20] = 0;
   out_2217581622006004275[21] = state[8];
   out_2217581622006004275[22] = 0;
   out_2217581622006004275[23] = -state[6];
   out_2217581622006004275[24] = -state[5];
   out_2217581622006004275[25] = 0;
   out_2217581622006004275[26] = state[3];
   out_2217581622006004275[27] = 0;
   out_2217581622006004275[28] = 0;
   out_2217581622006004275[29] = 0;
   out_2217581622006004275[30] = 0;
   out_2217581622006004275[31] = 1;
   out_2217581622006004275[32] = 0;
   out_2217581622006004275[33] = 0;
   out_2217581622006004275[34] = 1;
   out_2217581622006004275[35] = 0;
   out_2217581622006004275[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2217581622006004275[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2217581622006004275[38] = 0;
   out_2217581622006004275[39] = -state[7];
   out_2217581622006004275[40] = state[6];
   out_2217581622006004275[41] = 0;
   out_2217581622006004275[42] = state[4];
   out_2217581622006004275[43] = -state[3];
   out_2217581622006004275[44] = 0;
   out_2217581622006004275[45] = 0;
   out_2217581622006004275[46] = 0;
   out_2217581622006004275[47] = 0;
   out_2217581622006004275[48] = 0;
   out_2217581622006004275[49] = 0;
   out_2217581622006004275[50] = 1;
   out_2217581622006004275[51] = 0;
   out_2217581622006004275[52] = 0;
   out_2217581622006004275[53] = 1;
}
void h_13(double *state, double *unused, double *out_5268165593067890584) {
   out_5268165593067890584[0] = state[3];
   out_5268165593067890584[1] = state[4];
   out_5268165593067890584[2] = state[5];
}
void H_13(double *state, double *unused, double *out_736010457650946768) {
   out_736010457650946768[0] = 0;
   out_736010457650946768[1] = 0;
   out_736010457650946768[2] = 0;
   out_736010457650946768[3] = 1;
   out_736010457650946768[4] = 0;
   out_736010457650946768[5] = 0;
   out_736010457650946768[6] = 0;
   out_736010457650946768[7] = 0;
   out_736010457650946768[8] = 0;
   out_736010457650946768[9] = 0;
   out_736010457650946768[10] = 0;
   out_736010457650946768[11] = 0;
   out_736010457650946768[12] = 0;
   out_736010457650946768[13] = 0;
   out_736010457650946768[14] = 0;
   out_736010457650946768[15] = 0;
   out_736010457650946768[16] = 0;
   out_736010457650946768[17] = 0;
   out_736010457650946768[18] = 0;
   out_736010457650946768[19] = 0;
   out_736010457650946768[20] = 0;
   out_736010457650946768[21] = 0;
   out_736010457650946768[22] = 1;
   out_736010457650946768[23] = 0;
   out_736010457650946768[24] = 0;
   out_736010457650946768[25] = 0;
   out_736010457650946768[26] = 0;
   out_736010457650946768[27] = 0;
   out_736010457650946768[28] = 0;
   out_736010457650946768[29] = 0;
   out_736010457650946768[30] = 0;
   out_736010457650946768[31] = 0;
   out_736010457650946768[32] = 0;
   out_736010457650946768[33] = 0;
   out_736010457650946768[34] = 0;
   out_736010457650946768[35] = 0;
   out_736010457650946768[36] = 0;
   out_736010457650946768[37] = 0;
   out_736010457650946768[38] = 0;
   out_736010457650946768[39] = 0;
   out_736010457650946768[40] = 0;
   out_736010457650946768[41] = 1;
   out_736010457650946768[42] = 0;
   out_736010457650946768[43] = 0;
   out_736010457650946768[44] = 0;
   out_736010457650946768[45] = 0;
   out_736010457650946768[46] = 0;
   out_736010457650946768[47] = 0;
   out_736010457650946768[48] = 0;
   out_736010457650946768[49] = 0;
   out_736010457650946768[50] = 0;
   out_736010457650946768[51] = 0;
   out_736010457650946768[52] = 0;
   out_736010457650946768[53] = 0;
}
void h_14(double *state, double *unused, double *out_7369017124756604631) {
   out_7369017124756604631[0] = state[6];
   out_7369017124756604631[1] = state[7];
   out_7369017124756604631[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1486977488658098496) {
   out_1486977488658098496[0] = 0;
   out_1486977488658098496[1] = 0;
   out_1486977488658098496[2] = 0;
   out_1486977488658098496[3] = 0;
   out_1486977488658098496[4] = 0;
   out_1486977488658098496[5] = 0;
   out_1486977488658098496[6] = 1;
   out_1486977488658098496[7] = 0;
   out_1486977488658098496[8] = 0;
   out_1486977488658098496[9] = 0;
   out_1486977488658098496[10] = 0;
   out_1486977488658098496[11] = 0;
   out_1486977488658098496[12] = 0;
   out_1486977488658098496[13] = 0;
   out_1486977488658098496[14] = 0;
   out_1486977488658098496[15] = 0;
   out_1486977488658098496[16] = 0;
   out_1486977488658098496[17] = 0;
   out_1486977488658098496[18] = 0;
   out_1486977488658098496[19] = 0;
   out_1486977488658098496[20] = 0;
   out_1486977488658098496[21] = 0;
   out_1486977488658098496[22] = 0;
   out_1486977488658098496[23] = 0;
   out_1486977488658098496[24] = 0;
   out_1486977488658098496[25] = 1;
   out_1486977488658098496[26] = 0;
   out_1486977488658098496[27] = 0;
   out_1486977488658098496[28] = 0;
   out_1486977488658098496[29] = 0;
   out_1486977488658098496[30] = 0;
   out_1486977488658098496[31] = 0;
   out_1486977488658098496[32] = 0;
   out_1486977488658098496[33] = 0;
   out_1486977488658098496[34] = 0;
   out_1486977488658098496[35] = 0;
   out_1486977488658098496[36] = 0;
   out_1486977488658098496[37] = 0;
   out_1486977488658098496[38] = 0;
   out_1486977488658098496[39] = 0;
   out_1486977488658098496[40] = 0;
   out_1486977488658098496[41] = 0;
   out_1486977488658098496[42] = 0;
   out_1486977488658098496[43] = 0;
   out_1486977488658098496[44] = 1;
   out_1486977488658098496[45] = 0;
   out_1486977488658098496[46] = 0;
   out_1486977488658098496[47] = 0;
   out_1486977488658098496[48] = 0;
   out_1486977488658098496[49] = 0;
   out_1486977488658098496[50] = 0;
   out_1486977488658098496[51] = 0;
   out_1486977488658098496[52] = 0;
   out_1486977488658098496[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4144373577117027043) {
  err_fun(nom_x, delta_x, out_4144373577117027043);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6853650036846835829) {
  inv_err_fun(nom_x, true_x, out_6853650036846835829);
}
void pose_H_mod_fun(double *state, double *out_3371818439070572688) {
  H_mod_fun(state, out_3371818439070572688);
}
void pose_f_fun(double *state, double dt, double *out_5714706012790040296) {
  f_fun(state,  dt, out_5714706012790040296);
}
void pose_F_fun(double *state, double dt, double *out_2453777362197051626) {
  F_fun(state,  dt, out_2453777362197051626);
}
void pose_h_4(double *state, double *unused, double *out_7475340564657993549) {
  h_4(state, unused, out_7475340564657993549);
}
void pose_H_4(double *state, double *unused, double *out_4569765920953470792) {
  H_4(state, unused, out_4569765920953470792);
}
void pose_h_10(double *state, double *unused, double *out_4511047330400710663) {
  h_10(state, unused, out_4511047330400710663);
}
void pose_H_10(double *state, double *unused, double *out_2217581622006004275) {
  H_10(state, unused, out_2217581622006004275);
}
void pose_h_13(double *state, double *unused, double *out_5268165593067890584) {
  h_13(state, unused, out_5268165593067890584);
}
void pose_H_13(double *state, double *unused, double *out_736010457650946768) {
  H_13(state, unused, out_736010457650946768);
}
void pose_h_14(double *state, double *unused, double *out_7369017124756604631) {
  h_14(state, unused, out_7369017124756604631);
}
void pose_H_14(double *state, double *unused, double *out_1486977488658098496) {
  H_14(state, unused, out_1486977488658098496);
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
