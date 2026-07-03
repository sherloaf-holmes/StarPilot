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
void err_fun(double *nom_x, double *delta_x, double *out_5453162044416851201) {
   out_5453162044416851201[0] = delta_x[0] + nom_x[0];
   out_5453162044416851201[1] = delta_x[1] + nom_x[1];
   out_5453162044416851201[2] = delta_x[2] + nom_x[2];
   out_5453162044416851201[3] = delta_x[3] + nom_x[3];
   out_5453162044416851201[4] = delta_x[4] + nom_x[4];
   out_5453162044416851201[5] = delta_x[5] + nom_x[5];
   out_5453162044416851201[6] = delta_x[6] + nom_x[6];
   out_5453162044416851201[7] = delta_x[7] + nom_x[7];
   out_5453162044416851201[8] = delta_x[8] + nom_x[8];
   out_5453162044416851201[9] = delta_x[9] + nom_x[9];
   out_5453162044416851201[10] = delta_x[10] + nom_x[10];
   out_5453162044416851201[11] = delta_x[11] + nom_x[11];
   out_5453162044416851201[12] = delta_x[12] + nom_x[12];
   out_5453162044416851201[13] = delta_x[13] + nom_x[13];
   out_5453162044416851201[14] = delta_x[14] + nom_x[14];
   out_5453162044416851201[15] = delta_x[15] + nom_x[15];
   out_5453162044416851201[16] = delta_x[16] + nom_x[16];
   out_5453162044416851201[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2848752773381496345) {
   out_2848752773381496345[0] = -nom_x[0] + true_x[0];
   out_2848752773381496345[1] = -nom_x[1] + true_x[1];
   out_2848752773381496345[2] = -nom_x[2] + true_x[2];
   out_2848752773381496345[3] = -nom_x[3] + true_x[3];
   out_2848752773381496345[4] = -nom_x[4] + true_x[4];
   out_2848752773381496345[5] = -nom_x[5] + true_x[5];
   out_2848752773381496345[6] = -nom_x[6] + true_x[6];
   out_2848752773381496345[7] = -nom_x[7] + true_x[7];
   out_2848752773381496345[8] = -nom_x[8] + true_x[8];
   out_2848752773381496345[9] = -nom_x[9] + true_x[9];
   out_2848752773381496345[10] = -nom_x[10] + true_x[10];
   out_2848752773381496345[11] = -nom_x[11] + true_x[11];
   out_2848752773381496345[12] = -nom_x[12] + true_x[12];
   out_2848752773381496345[13] = -nom_x[13] + true_x[13];
   out_2848752773381496345[14] = -nom_x[14] + true_x[14];
   out_2848752773381496345[15] = -nom_x[15] + true_x[15];
   out_2848752773381496345[16] = -nom_x[16] + true_x[16];
   out_2848752773381496345[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4906589349598379822) {
   out_4906589349598379822[0] = 1.0;
   out_4906589349598379822[1] = 0.0;
   out_4906589349598379822[2] = 0.0;
   out_4906589349598379822[3] = 0.0;
   out_4906589349598379822[4] = 0.0;
   out_4906589349598379822[5] = 0.0;
   out_4906589349598379822[6] = 0.0;
   out_4906589349598379822[7] = 0.0;
   out_4906589349598379822[8] = 0.0;
   out_4906589349598379822[9] = 0.0;
   out_4906589349598379822[10] = 0.0;
   out_4906589349598379822[11] = 0.0;
   out_4906589349598379822[12] = 0.0;
   out_4906589349598379822[13] = 0.0;
   out_4906589349598379822[14] = 0.0;
   out_4906589349598379822[15] = 0.0;
   out_4906589349598379822[16] = 0.0;
   out_4906589349598379822[17] = 0.0;
   out_4906589349598379822[18] = 0.0;
   out_4906589349598379822[19] = 1.0;
   out_4906589349598379822[20] = 0.0;
   out_4906589349598379822[21] = 0.0;
   out_4906589349598379822[22] = 0.0;
   out_4906589349598379822[23] = 0.0;
   out_4906589349598379822[24] = 0.0;
   out_4906589349598379822[25] = 0.0;
   out_4906589349598379822[26] = 0.0;
   out_4906589349598379822[27] = 0.0;
   out_4906589349598379822[28] = 0.0;
   out_4906589349598379822[29] = 0.0;
   out_4906589349598379822[30] = 0.0;
   out_4906589349598379822[31] = 0.0;
   out_4906589349598379822[32] = 0.0;
   out_4906589349598379822[33] = 0.0;
   out_4906589349598379822[34] = 0.0;
   out_4906589349598379822[35] = 0.0;
   out_4906589349598379822[36] = 0.0;
   out_4906589349598379822[37] = 0.0;
   out_4906589349598379822[38] = 1.0;
   out_4906589349598379822[39] = 0.0;
   out_4906589349598379822[40] = 0.0;
   out_4906589349598379822[41] = 0.0;
   out_4906589349598379822[42] = 0.0;
   out_4906589349598379822[43] = 0.0;
   out_4906589349598379822[44] = 0.0;
   out_4906589349598379822[45] = 0.0;
   out_4906589349598379822[46] = 0.0;
   out_4906589349598379822[47] = 0.0;
   out_4906589349598379822[48] = 0.0;
   out_4906589349598379822[49] = 0.0;
   out_4906589349598379822[50] = 0.0;
   out_4906589349598379822[51] = 0.0;
   out_4906589349598379822[52] = 0.0;
   out_4906589349598379822[53] = 0.0;
   out_4906589349598379822[54] = 0.0;
   out_4906589349598379822[55] = 0.0;
   out_4906589349598379822[56] = 0.0;
   out_4906589349598379822[57] = 1.0;
   out_4906589349598379822[58] = 0.0;
   out_4906589349598379822[59] = 0.0;
   out_4906589349598379822[60] = 0.0;
   out_4906589349598379822[61] = 0.0;
   out_4906589349598379822[62] = 0.0;
   out_4906589349598379822[63] = 0.0;
   out_4906589349598379822[64] = 0.0;
   out_4906589349598379822[65] = 0.0;
   out_4906589349598379822[66] = 0.0;
   out_4906589349598379822[67] = 0.0;
   out_4906589349598379822[68] = 0.0;
   out_4906589349598379822[69] = 0.0;
   out_4906589349598379822[70] = 0.0;
   out_4906589349598379822[71] = 0.0;
   out_4906589349598379822[72] = 0.0;
   out_4906589349598379822[73] = 0.0;
   out_4906589349598379822[74] = 0.0;
   out_4906589349598379822[75] = 0.0;
   out_4906589349598379822[76] = 1.0;
   out_4906589349598379822[77] = 0.0;
   out_4906589349598379822[78] = 0.0;
   out_4906589349598379822[79] = 0.0;
   out_4906589349598379822[80] = 0.0;
   out_4906589349598379822[81] = 0.0;
   out_4906589349598379822[82] = 0.0;
   out_4906589349598379822[83] = 0.0;
   out_4906589349598379822[84] = 0.0;
   out_4906589349598379822[85] = 0.0;
   out_4906589349598379822[86] = 0.0;
   out_4906589349598379822[87] = 0.0;
   out_4906589349598379822[88] = 0.0;
   out_4906589349598379822[89] = 0.0;
   out_4906589349598379822[90] = 0.0;
   out_4906589349598379822[91] = 0.0;
   out_4906589349598379822[92] = 0.0;
   out_4906589349598379822[93] = 0.0;
   out_4906589349598379822[94] = 0.0;
   out_4906589349598379822[95] = 1.0;
   out_4906589349598379822[96] = 0.0;
   out_4906589349598379822[97] = 0.0;
   out_4906589349598379822[98] = 0.0;
   out_4906589349598379822[99] = 0.0;
   out_4906589349598379822[100] = 0.0;
   out_4906589349598379822[101] = 0.0;
   out_4906589349598379822[102] = 0.0;
   out_4906589349598379822[103] = 0.0;
   out_4906589349598379822[104] = 0.0;
   out_4906589349598379822[105] = 0.0;
   out_4906589349598379822[106] = 0.0;
   out_4906589349598379822[107] = 0.0;
   out_4906589349598379822[108] = 0.0;
   out_4906589349598379822[109] = 0.0;
   out_4906589349598379822[110] = 0.0;
   out_4906589349598379822[111] = 0.0;
   out_4906589349598379822[112] = 0.0;
   out_4906589349598379822[113] = 0.0;
   out_4906589349598379822[114] = 1.0;
   out_4906589349598379822[115] = 0.0;
   out_4906589349598379822[116] = 0.0;
   out_4906589349598379822[117] = 0.0;
   out_4906589349598379822[118] = 0.0;
   out_4906589349598379822[119] = 0.0;
   out_4906589349598379822[120] = 0.0;
   out_4906589349598379822[121] = 0.0;
   out_4906589349598379822[122] = 0.0;
   out_4906589349598379822[123] = 0.0;
   out_4906589349598379822[124] = 0.0;
   out_4906589349598379822[125] = 0.0;
   out_4906589349598379822[126] = 0.0;
   out_4906589349598379822[127] = 0.0;
   out_4906589349598379822[128] = 0.0;
   out_4906589349598379822[129] = 0.0;
   out_4906589349598379822[130] = 0.0;
   out_4906589349598379822[131] = 0.0;
   out_4906589349598379822[132] = 0.0;
   out_4906589349598379822[133] = 1.0;
   out_4906589349598379822[134] = 0.0;
   out_4906589349598379822[135] = 0.0;
   out_4906589349598379822[136] = 0.0;
   out_4906589349598379822[137] = 0.0;
   out_4906589349598379822[138] = 0.0;
   out_4906589349598379822[139] = 0.0;
   out_4906589349598379822[140] = 0.0;
   out_4906589349598379822[141] = 0.0;
   out_4906589349598379822[142] = 0.0;
   out_4906589349598379822[143] = 0.0;
   out_4906589349598379822[144] = 0.0;
   out_4906589349598379822[145] = 0.0;
   out_4906589349598379822[146] = 0.0;
   out_4906589349598379822[147] = 0.0;
   out_4906589349598379822[148] = 0.0;
   out_4906589349598379822[149] = 0.0;
   out_4906589349598379822[150] = 0.0;
   out_4906589349598379822[151] = 0.0;
   out_4906589349598379822[152] = 1.0;
   out_4906589349598379822[153] = 0.0;
   out_4906589349598379822[154] = 0.0;
   out_4906589349598379822[155] = 0.0;
   out_4906589349598379822[156] = 0.0;
   out_4906589349598379822[157] = 0.0;
   out_4906589349598379822[158] = 0.0;
   out_4906589349598379822[159] = 0.0;
   out_4906589349598379822[160] = 0.0;
   out_4906589349598379822[161] = 0.0;
   out_4906589349598379822[162] = 0.0;
   out_4906589349598379822[163] = 0.0;
   out_4906589349598379822[164] = 0.0;
   out_4906589349598379822[165] = 0.0;
   out_4906589349598379822[166] = 0.0;
   out_4906589349598379822[167] = 0.0;
   out_4906589349598379822[168] = 0.0;
   out_4906589349598379822[169] = 0.0;
   out_4906589349598379822[170] = 0.0;
   out_4906589349598379822[171] = 1.0;
   out_4906589349598379822[172] = 0.0;
   out_4906589349598379822[173] = 0.0;
   out_4906589349598379822[174] = 0.0;
   out_4906589349598379822[175] = 0.0;
   out_4906589349598379822[176] = 0.0;
   out_4906589349598379822[177] = 0.0;
   out_4906589349598379822[178] = 0.0;
   out_4906589349598379822[179] = 0.0;
   out_4906589349598379822[180] = 0.0;
   out_4906589349598379822[181] = 0.0;
   out_4906589349598379822[182] = 0.0;
   out_4906589349598379822[183] = 0.0;
   out_4906589349598379822[184] = 0.0;
   out_4906589349598379822[185] = 0.0;
   out_4906589349598379822[186] = 0.0;
   out_4906589349598379822[187] = 0.0;
   out_4906589349598379822[188] = 0.0;
   out_4906589349598379822[189] = 0.0;
   out_4906589349598379822[190] = 1.0;
   out_4906589349598379822[191] = 0.0;
   out_4906589349598379822[192] = 0.0;
   out_4906589349598379822[193] = 0.0;
   out_4906589349598379822[194] = 0.0;
   out_4906589349598379822[195] = 0.0;
   out_4906589349598379822[196] = 0.0;
   out_4906589349598379822[197] = 0.0;
   out_4906589349598379822[198] = 0.0;
   out_4906589349598379822[199] = 0.0;
   out_4906589349598379822[200] = 0.0;
   out_4906589349598379822[201] = 0.0;
   out_4906589349598379822[202] = 0.0;
   out_4906589349598379822[203] = 0.0;
   out_4906589349598379822[204] = 0.0;
   out_4906589349598379822[205] = 0.0;
   out_4906589349598379822[206] = 0.0;
   out_4906589349598379822[207] = 0.0;
   out_4906589349598379822[208] = 0.0;
   out_4906589349598379822[209] = 1.0;
   out_4906589349598379822[210] = 0.0;
   out_4906589349598379822[211] = 0.0;
   out_4906589349598379822[212] = 0.0;
   out_4906589349598379822[213] = 0.0;
   out_4906589349598379822[214] = 0.0;
   out_4906589349598379822[215] = 0.0;
   out_4906589349598379822[216] = 0.0;
   out_4906589349598379822[217] = 0.0;
   out_4906589349598379822[218] = 0.0;
   out_4906589349598379822[219] = 0.0;
   out_4906589349598379822[220] = 0.0;
   out_4906589349598379822[221] = 0.0;
   out_4906589349598379822[222] = 0.0;
   out_4906589349598379822[223] = 0.0;
   out_4906589349598379822[224] = 0.0;
   out_4906589349598379822[225] = 0.0;
   out_4906589349598379822[226] = 0.0;
   out_4906589349598379822[227] = 0.0;
   out_4906589349598379822[228] = 1.0;
   out_4906589349598379822[229] = 0.0;
   out_4906589349598379822[230] = 0.0;
   out_4906589349598379822[231] = 0.0;
   out_4906589349598379822[232] = 0.0;
   out_4906589349598379822[233] = 0.0;
   out_4906589349598379822[234] = 0.0;
   out_4906589349598379822[235] = 0.0;
   out_4906589349598379822[236] = 0.0;
   out_4906589349598379822[237] = 0.0;
   out_4906589349598379822[238] = 0.0;
   out_4906589349598379822[239] = 0.0;
   out_4906589349598379822[240] = 0.0;
   out_4906589349598379822[241] = 0.0;
   out_4906589349598379822[242] = 0.0;
   out_4906589349598379822[243] = 0.0;
   out_4906589349598379822[244] = 0.0;
   out_4906589349598379822[245] = 0.0;
   out_4906589349598379822[246] = 0.0;
   out_4906589349598379822[247] = 1.0;
   out_4906589349598379822[248] = 0.0;
   out_4906589349598379822[249] = 0.0;
   out_4906589349598379822[250] = 0.0;
   out_4906589349598379822[251] = 0.0;
   out_4906589349598379822[252] = 0.0;
   out_4906589349598379822[253] = 0.0;
   out_4906589349598379822[254] = 0.0;
   out_4906589349598379822[255] = 0.0;
   out_4906589349598379822[256] = 0.0;
   out_4906589349598379822[257] = 0.0;
   out_4906589349598379822[258] = 0.0;
   out_4906589349598379822[259] = 0.0;
   out_4906589349598379822[260] = 0.0;
   out_4906589349598379822[261] = 0.0;
   out_4906589349598379822[262] = 0.0;
   out_4906589349598379822[263] = 0.0;
   out_4906589349598379822[264] = 0.0;
   out_4906589349598379822[265] = 0.0;
   out_4906589349598379822[266] = 1.0;
   out_4906589349598379822[267] = 0.0;
   out_4906589349598379822[268] = 0.0;
   out_4906589349598379822[269] = 0.0;
   out_4906589349598379822[270] = 0.0;
   out_4906589349598379822[271] = 0.0;
   out_4906589349598379822[272] = 0.0;
   out_4906589349598379822[273] = 0.0;
   out_4906589349598379822[274] = 0.0;
   out_4906589349598379822[275] = 0.0;
   out_4906589349598379822[276] = 0.0;
   out_4906589349598379822[277] = 0.0;
   out_4906589349598379822[278] = 0.0;
   out_4906589349598379822[279] = 0.0;
   out_4906589349598379822[280] = 0.0;
   out_4906589349598379822[281] = 0.0;
   out_4906589349598379822[282] = 0.0;
   out_4906589349598379822[283] = 0.0;
   out_4906589349598379822[284] = 0.0;
   out_4906589349598379822[285] = 1.0;
   out_4906589349598379822[286] = 0.0;
   out_4906589349598379822[287] = 0.0;
   out_4906589349598379822[288] = 0.0;
   out_4906589349598379822[289] = 0.0;
   out_4906589349598379822[290] = 0.0;
   out_4906589349598379822[291] = 0.0;
   out_4906589349598379822[292] = 0.0;
   out_4906589349598379822[293] = 0.0;
   out_4906589349598379822[294] = 0.0;
   out_4906589349598379822[295] = 0.0;
   out_4906589349598379822[296] = 0.0;
   out_4906589349598379822[297] = 0.0;
   out_4906589349598379822[298] = 0.0;
   out_4906589349598379822[299] = 0.0;
   out_4906589349598379822[300] = 0.0;
   out_4906589349598379822[301] = 0.0;
   out_4906589349598379822[302] = 0.0;
   out_4906589349598379822[303] = 0.0;
   out_4906589349598379822[304] = 1.0;
   out_4906589349598379822[305] = 0.0;
   out_4906589349598379822[306] = 0.0;
   out_4906589349598379822[307] = 0.0;
   out_4906589349598379822[308] = 0.0;
   out_4906589349598379822[309] = 0.0;
   out_4906589349598379822[310] = 0.0;
   out_4906589349598379822[311] = 0.0;
   out_4906589349598379822[312] = 0.0;
   out_4906589349598379822[313] = 0.0;
   out_4906589349598379822[314] = 0.0;
   out_4906589349598379822[315] = 0.0;
   out_4906589349598379822[316] = 0.0;
   out_4906589349598379822[317] = 0.0;
   out_4906589349598379822[318] = 0.0;
   out_4906589349598379822[319] = 0.0;
   out_4906589349598379822[320] = 0.0;
   out_4906589349598379822[321] = 0.0;
   out_4906589349598379822[322] = 0.0;
   out_4906589349598379822[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2760483319111957401) {
   out_2760483319111957401[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2760483319111957401[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2760483319111957401[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2760483319111957401[3] = dt*state[12] + state[3];
   out_2760483319111957401[4] = dt*state[13] + state[4];
   out_2760483319111957401[5] = dt*state[14] + state[5];
   out_2760483319111957401[6] = state[6];
   out_2760483319111957401[7] = state[7];
   out_2760483319111957401[8] = state[8];
   out_2760483319111957401[9] = state[9];
   out_2760483319111957401[10] = state[10];
   out_2760483319111957401[11] = state[11];
   out_2760483319111957401[12] = state[12];
   out_2760483319111957401[13] = state[13];
   out_2760483319111957401[14] = state[14];
   out_2760483319111957401[15] = state[15];
   out_2760483319111957401[16] = state[16];
   out_2760483319111957401[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2462794523887094837) {
   out_2462794523887094837[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2462794523887094837[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2462794523887094837[2] = 0;
   out_2462794523887094837[3] = 0;
   out_2462794523887094837[4] = 0;
   out_2462794523887094837[5] = 0;
   out_2462794523887094837[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2462794523887094837[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2462794523887094837[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2462794523887094837[9] = 0;
   out_2462794523887094837[10] = 0;
   out_2462794523887094837[11] = 0;
   out_2462794523887094837[12] = 0;
   out_2462794523887094837[13] = 0;
   out_2462794523887094837[14] = 0;
   out_2462794523887094837[15] = 0;
   out_2462794523887094837[16] = 0;
   out_2462794523887094837[17] = 0;
   out_2462794523887094837[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2462794523887094837[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2462794523887094837[20] = 0;
   out_2462794523887094837[21] = 0;
   out_2462794523887094837[22] = 0;
   out_2462794523887094837[23] = 0;
   out_2462794523887094837[24] = 0;
   out_2462794523887094837[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2462794523887094837[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2462794523887094837[27] = 0;
   out_2462794523887094837[28] = 0;
   out_2462794523887094837[29] = 0;
   out_2462794523887094837[30] = 0;
   out_2462794523887094837[31] = 0;
   out_2462794523887094837[32] = 0;
   out_2462794523887094837[33] = 0;
   out_2462794523887094837[34] = 0;
   out_2462794523887094837[35] = 0;
   out_2462794523887094837[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2462794523887094837[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2462794523887094837[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2462794523887094837[39] = 0;
   out_2462794523887094837[40] = 0;
   out_2462794523887094837[41] = 0;
   out_2462794523887094837[42] = 0;
   out_2462794523887094837[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2462794523887094837[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2462794523887094837[45] = 0;
   out_2462794523887094837[46] = 0;
   out_2462794523887094837[47] = 0;
   out_2462794523887094837[48] = 0;
   out_2462794523887094837[49] = 0;
   out_2462794523887094837[50] = 0;
   out_2462794523887094837[51] = 0;
   out_2462794523887094837[52] = 0;
   out_2462794523887094837[53] = 0;
   out_2462794523887094837[54] = 0;
   out_2462794523887094837[55] = 0;
   out_2462794523887094837[56] = 0;
   out_2462794523887094837[57] = 1;
   out_2462794523887094837[58] = 0;
   out_2462794523887094837[59] = 0;
   out_2462794523887094837[60] = 0;
   out_2462794523887094837[61] = 0;
   out_2462794523887094837[62] = 0;
   out_2462794523887094837[63] = 0;
   out_2462794523887094837[64] = 0;
   out_2462794523887094837[65] = 0;
   out_2462794523887094837[66] = dt;
   out_2462794523887094837[67] = 0;
   out_2462794523887094837[68] = 0;
   out_2462794523887094837[69] = 0;
   out_2462794523887094837[70] = 0;
   out_2462794523887094837[71] = 0;
   out_2462794523887094837[72] = 0;
   out_2462794523887094837[73] = 0;
   out_2462794523887094837[74] = 0;
   out_2462794523887094837[75] = 0;
   out_2462794523887094837[76] = 1;
   out_2462794523887094837[77] = 0;
   out_2462794523887094837[78] = 0;
   out_2462794523887094837[79] = 0;
   out_2462794523887094837[80] = 0;
   out_2462794523887094837[81] = 0;
   out_2462794523887094837[82] = 0;
   out_2462794523887094837[83] = 0;
   out_2462794523887094837[84] = 0;
   out_2462794523887094837[85] = dt;
   out_2462794523887094837[86] = 0;
   out_2462794523887094837[87] = 0;
   out_2462794523887094837[88] = 0;
   out_2462794523887094837[89] = 0;
   out_2462794523887094837[90] = 0;
   out_2462794523887094837[91] = 0;
   out_2462794523887094837[92] = 0;
   out_2462794523887094837[93] = 0;
   out_2462794523887094837[94] = 0;
   out_2462794523887094837[95] = 1;
   out_2462794523887094837[96] = 0;
   out_2462794523887094837[97] = 0;
   out_2462794523887094837[98] = 0;
   out_2462794523887094837[99] = 0;
   out_2462794523887094837[100] = 0;
   out_2462794523887094837[101] = 0;
   out_2462794523887094837[102] = 0;
   out_2462794523887094837[103] = 0;
   out_2462794523887094837[104] = dt;
   out_2462794523887094837[105] = 0;
   out_2462794523887094837[106] = 0;
   out_2462794523887094837[107] = 0;
   out_2462794523887094837[108] = 0;
   out_2462794523887094837[109] = 0;
   out_2462794523887094837[110] = 0;
   out_2462794523887094837[111] = 0;
   out_2462794523887094837[112] = 0;
   out_2462794523887094837[113] = 0;
   out_2462794523887094837[114] = 1;
   out_2462794523887094837[115] = 0;
   out_2462794523887094837[116] = 0;
   out_2462794523887094837[117] = 0;
   out_2462794523887094837[118] = 0;
   out_2462794523887094837[119] = 0;
   out_2462794523887094837[120] = 0;
   out_2462794523887094837[121] = 0;
   out_2462794523887094837[122] = 0;
   out_2462794523887094837[123] = 0;
   out_2462794523887094837[124] = 0;
   out_2462794523887094837[125] = 0;
   out_2462794523887094837[126] = 0;
   out_2462794523887094837[127] = 0;
   out_2462794523887094837[128] = 0;
   out_2462794523887094837[129] = 0;
   out_2462794523887094837[130] = 0;
   out_2462794523887094837[131] = 0;
   out_2462794523887094837[132] = 0;
   out_2462794523887094837[133] = 1;
   out_2462794523887094837[134] = 0;
   out_2462794523887094837[135] = 0;
   out_2462794523887094837[136] = 0;
   out_2462794523887094837[137] = 0;
   out_2462794523887094837[138] = 0;
   out_2462794523887094837[139] = 0;
   out_2462794523887094837[140] = 0;
   out_2462794523887094837[141] = 0;
   out_2462794523887094837[142] = 0;
   out_2462794523887094837[143] = 0;
   out_2462794523887094837[144] = 0;
   out_2462794523887094837[145] = 0;
   out_2462794523887094837[146] = 0;
   out_2462794523887094837[147] = 0;
   out_2462794523887094837[148] = 0;
   out_2462794523887094837[149] = 0;
   out_2462794523887094837[150] = 0;
   out_2462794523887094837[151] = 0;
   out_2462794523887094837[152] = 1;
   out_2462794523887094837[153] = 0;
   out_2462794523887094837[154] = 0;
   out_2462794523887094837[155] = 0;
   out_2462794523887094837[156] = 0;
   out_2462794523887094837[157] = 0;
   out_2462794523887094837[158] = 0;
   out_2462794523887094837[159] = 0;
   out_2462794523887094837[160] = 0;
   out_2462794523887094837[161] = 0;
   out_2462794523887094837[162] = 0;
   out_2462794523887094837[163] = 0;
   out_2462794523887094837[164] = 0;
   out_2462794523887094837[165] = 0;
   out_2462794523887094837[166] = 0;
   out_2462794523887094837[167] = 0;
   out_2462794523887094837[168] = 0;
   out_2462794523887094837[169] = 0;
   out_2462794523887094837[170] = 0;
   out_2462794523887094837[171] = 1;
   out_2462794523887094837[172] = 0;
   out_2462794523887094837[173] = 0;
   out_2462794523887094837[174] = 0;
   out_2462794523887094837[175] = 0;
   out_2462794523887094837[176] = 0;
   out_2462794523887094837[177] = 0;
   out_2462794523887094837[178] = 0;
   out_2462794523887094837[179] = 0;
   out_2462794523887094837[180] = 0;
   out_2462794523887094837[181] = 0;
   out_2462794523887094837[182] = 0;
   out_2462794523887094837[183] = 0;
   out_2462794523887094837[184] = 0;
   out_2462794523887094837[185] = 0;
   out_2462794523887094837[186] = 0;
   out_2462794523887094837[187] = 0;
   out_2462794523887094837[188] = 0;
   out_2462794523887094837[189] = 0;
   out_2462794523887094837[190] = 1;
   out_2462794523887094837[191] = 0;
   out_2462794523887094837[192] = 0;
   out_2462794523887094837[193] = 0;
   out_2462794523887094837[194] = 0;
   out_2462794523887094837[195] = 0;
   out_2462794523887094837[196] = 0;
   out_2462794523887094837[197] = 0;
   out_2462794523887094837[198] = 0;
   out_2462794523887094837[199] = 0;
   out_2462794523887094837[200] = 0;
   out_2462794523887094837[201] = 0;
   out_2462794523887094837[202] = 0;
   out_2462794523887094837[203] = 0;
   out_2462794523887094837[204] = 0;
   out_2462794523887094837[205] = 0;
   out_2462794523887094837[206] = 0;
   out_2462794523887094837[207] = 0;
   out_2462794523887094837[208] = 0;
   out_2462794523887094837[209] = 1;
   out_2462794523887094837[210] = 0;
   out_2462794523887094837[211] = 0;
   out_2462794523887094837[212] = 0;
   out_2462794523887094837[213] = 0;
   out_2462794523887094837[214] = 0;
   out_2462794523887094837[215] = 0;
   out_2462794523887094837[216] = 0;
   out_2462794523887094837[217] = 0;
   out_2462794523887094837[218] = 0;
   out_2462794523887094837[219] = 0;
   out_2462794523887094837[220] = 0;
   out_2462794523887094837[221] = 0;
   out_2462794523887094837[222] = 0;
   out_2462794523887094837[223] = 0;
   out_2462794523887094837[224] = 0;
   out_2462794523887094837[225] = 0;
   out_2462794523887094837[226] = 0;
   out_2462794523887094837[227] = 0;
   out_2462794523887094837[228] = 1;
   out_2462794523887094837[229] = 0;
   out_2462794523887094837[230] = 0;
   out_2462794523887094837[231] = 0;
   out_2462794523887094837[232] = 0;
   out_2462794523887094837[233] = 0;
   out_2462794523887094837[234] = 0;
   out_2462794523887094837[235] = 0;
   out_2462794523887094837[236] = 0;
   out_2462794523887094837[237] = 0;
   out_2462794523887094837[238] = 0;
   out_2462794523887094837[239] = 0;
   out_2462794523887094837[240] = 0;
   out_2462794523887094837[241] = 0;
   out_2462794523887094837[242] = 0;
   out_2462794523887094837[243] = 0;
   out_2462794523887094837[244] = 0;
   out_2462794523887094837[245] = 0;
   out_2462794523887094837[246] = 0;
   out_2462794523887094837[247] = 1;
   out_2462794523887094837[248] = 0;
   out_2462794523887094837[249] = 0;
   out_2462794523887094837[250] = 0;
   out_2462794523887094837[251] = 0;
   out_2462794523887094837[252] = 0;
   out_2462794523887094837[253] = 0;
   out_2462794523887094837[254] = 0;
   out_2462794523887094837[255] = 0;
   out_2462794523887094837[256] = 0;
   out_2462794523887094837[257] = 0;
   out_2462794523887094837[258] = 0;
   out_2462794523887094837[259] = 0;
   out_2462794523887094837[260] = 0;
   out_2462794523887094837[261] = 0;
   out_2462794523887094837[262] = 0;
   out_2462794523887094837[263] = 0;
   out_2462794523887094837[264] = 0;
   out_2462794523887094837[265] = 0;
   out_2462794523887094837[266] = 1;
   out_2462794523887094837[267] = 0;
   out_2462794523887094837[268] = 0;
   out_2462794523887094837[269] = 0;
   out_2462794523887094837[270] = 0;
   out_2462794523887094837[271] = 0;
   out_2462794523887094837[272] = 0;
   out_2462794523887094837[273] = 0;
   out_2462794523887094837[274] = 0;
   out_2462794523887094837[275] = 0;
   out_2462794523887094837[276] = 0;
   out_2462794523887094837[277] = 0;
   out_2462794523887094837[278] = 0;
   out_2462794523887094837[279] = 0;
   out_2462794523887094837[280] = 0;
   out_2462794523887094837[281] = 0;
   out_2462794523887094837[282] = 0;
   out_2462794523887094837[283] = 0;
   out_2462794523887094837[284] = 0;
   out_2462794523887094837[285] = 1;
   out_2462794523887094837[286] = 0;
   out_2462794523887094837[287] = 0;
   out_2462794523887094837[288] = 0;
   out_2462794523887094837[289] = 0;
   out_2462794523887094837[290] = 0;
   out_2462794523887094837[291] = 0;
   out_2462794523887094837[292] = 0;
   out_2462794523887094837[293] = 0;
   out_2462794523887094837[294] = 0;
   out_2462794523887094837[295] = 0;
   out_2462794523887094837[296] = 0;
   out_2462794523887094837[297] = 0;
   out_2462794523887094837[298] = 0;
   out_2462794523887094837[299] = 0;
   out_2462794523887094837[300] = 0;
   out_2462794523887094837[301] = 0;
   out_2462794523887094837[302] = 0;
   out_2462794523887094837[303] = 0;
   out_2462794523887094837[304] = 1;
   out_2462794523887094837[305] = 0;
   out_2462794523887094837[306] = 0;
   out_2462794523887094837[307] = 0;
   out_2462794523887094837[308] = 0;
   out_2462794523887094837[309] = 0;
   out_2462794523887094837[310] = 0;
   out_2462794523887094837[311] = 0;
   out_2462794523887094837[312] = 0;
   out_2462794523887094837[313] = 0;
   out_2462794523887094837[314] = 0;
   out_2462794523887094837[315] = 0;
   out_2462794523887094837[316] = 0;
   out_2462794523887094837[317] = 0;
   out_2462794523887094837[318] = 0;
   out_2462794523887094837[319] = 0;
   out_2462794523887094837[320] = 0;
   out_2462794523887094837[321] = 0;
   out_2462794523887094837[322] = 0;
   out_2462794523887094837[323] = 1;
}
void h_4(double *state, double *unused, double *out_3872084989267929897) {
   out_3872084989267929897[0] = state[6] + state[9];
   out_3872084989267929897[1] = state[7] + state[10];
   out_3872084989267929897[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2518858984437369523) {
   out_2518858984437369523[0] = 0;
   out_2518858984437369523[1] = 0;
   out_2518858984437369523[2] = 0;
   out_2518858984437369523[3] = 0;
   out_2518858984437369523[4] = 0;
   out_2518858984437369523[5] = 0;
   out_2518858984437369523[6] = 1;
   out_2518858984437369523[7] = 0;
   out_2518858984437369523[8] = 0;
   out_2518858984437369523[9] = 1;
   out_2518858984437369523[10] = 0;
   out_2518858984437369523[11] = 0;
   out_2518858984437369523[12] = 0;
   out_2518858984437369523[13] = 0;
   out_2518858984437369523[14] = 0;
   out_2518858984437369523[15] = 0;
   out_2518858984437369523[16] = 0;
   out_2518858984437369523[17] = 0;
   out_2518858984437369523[18] = 0;
   out_2518858984437369523[19] = 0;
   out_2518858984437369523[20] = 0;
   out_2518858984437369523[21] = 0;
   out_2518858984437369523[22] = 0;
   out_2518858984437369523[23] = 0;
   out_2518858984437369523[24] = 0;
   out_2518858984437369523[25] = 1;
   out_2518858984437369523[26] = 0;
   out_2518858984437369523[27] = 0;
   out_2518858984437369523[28] = 1;
   out_2518858984437369523[29] = 0;
   out_2518858984437369523[30] = 0;
   out_2518858984437369523[31] = 0;
   out_2518858984437369523[32] = 0;
   out_2518858984437369523[33] = 0;
   out_2518858984437369523[34] = 0;
   out_2518858984437369523[35] = 0;
   out_2518858984437369523[36] = 0;
   out_2518858984437369523[37] = 0;
   out_2518858984437369523[38] = 0;
   out_2518858984437369523[39] = 0;
   out_2518858984437369523[40] = 0;
   out_2518858984437369523[41] = 0;
   out_2518858984437369523[42] = 0;
   out_2518858984437369523[43] = 0;
   out_2518858984437369523[44] = 1;
   out_2518858984437369523[45] = 0;
   out_2518858984437369523[46] = 0;
   out_2518858984437369523[47] = 1;
   out_2518858984437369523[48] = 0;
   out_2518858984437369523[49] = 0;
   out_2518858984437369523[50] = 0;
   out_2518858984437369523[51] = 0;
   out_2518858984437369523[52] = 0;
   out_2518858984437369523[53] = 0;
}
void h_10(double *state, double *unused, double *out_3895192167056429518) {
   out_3895192167056429518[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_3895192167056429518[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_3895192167056429518[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5406689180752611899) {
   out_5406689180752611899[0] = 0;
   out_5406689180752611899[1] = 9.8100000000000005*cos(state[1]);
   out_5406689180752611899[2] = 0;
   out_5406689180752611899[3] = 0;
   out_5406689180752611899[4] = -state[8];
   out_5406689180752611899[5] = state[7];
   out_5406689180752611899[6] = 0;
   out_5406689180752611899[7] = state[5];
   out_5406689180752611899[8] = -state[4];
   out_5406689180752611899[9] = 0;
   out_5406689180752611899[10] = 0;
   out_5406689180752611899[11] = 0;
   out_5406689180752611899[12] = 1;
   out_5406689180752611899[13] = 0;
   out_5406689180752611899[14] = 0;
   out_5406689180752611899[15] = 1;
   out_5406689180752611899[16] = 0;
   out_5406689180752611899[17] = 0;
   out_5406689180752611899[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5406689180752611899[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5406689180752611899[20] = 0;
   out_5406689180752611899[21] = state[8];
   out_5406689180752611899[22] = 0;
   out_5406689180752611899[23] = -state[6];
   out_5406689180752611899[24] = -state[5];
   out_5406689180752611899[25] = 0;
   out_5406689180752611899[26] = state[3];
   out_5406689180752611899[27] = 0;
   out_5406689180752611899[28] = 0;
   out_5406689180752611899[29] = 0;
   out_5406689180752611899[30] = 0;
   out_5406689180752611899[31] = 1;
   out_5406689180752611899[32] = 0;
   out_5406689180752611899[33] = 0;
   out_5406689180752611899[34] = 1;
   out_5406689180752611899[35] = 0;
   out_5406689180752611899[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5406689180752611899[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5406689180752611899[38] = 0;
   out_5406689180752611899[39] = -state[7];
   out_5406689180752611899[40] = state[6];
   out_5406689180752611899[41] = 0;
   out_5406689180752611899[42] = state[4];
   out_5406689180752611899[43] = -state[3];
   out_5406689180752611899[44] = 0;
   out_5406689180752611899[45] = 0;
   out_5406689180752611899[46] = 0;
   out_5406689180752611899[47] = 0;
   out_5406689180752611899[48] = 0;
   out_5406689180752611899[49] = 0;
   out_5406689180752611899[50] = 1;
   out_5406689180752611899[51] = 0;
   out_5406689180752611899[52] = 0;
   out_5406689180752611899[53] = 1;
}
void h_13(double *state, double *unused, double *out_6846163796915800555) {
   out_6846163796915800555[0] = state[3];
   out_6846163796915800555[1] = state[4];
   out_6846163796915800555[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5731132809769702324) {
   out_5731132809769702324[0] = 0;
   out_5731132809769702324[1] = 0;
   out_5731132809769702324[2] = 0;
   out_5731132809769702324[3] = 1;
   out_5731132809769702324[4] = 0;
   out_5731132809769702324[5] = 0;
   out_5731132809769702324[6] = 0;
   out_5731132809769702324[7] = 0;
   out_5731132809769702324[8] = 0;
   out_5731132809769702324[9] = 0;
   out_5731132809769702324[10] = 0;
   out_5731132809769702324[11] = 0;
   out_5731132809769702324[12] = 0;
   out_5731132809769702324[13] = 0;
   out_5731132809769702324[14] = 0;
   out_5731132809769702324[15] = 0;
   out_5731132809769702324[16] = 0;
   out_5731132809769702324[17] = 0;
   out_5731132809769702324[18] = 0;
   out_5731132809769702324[19] = 0;
   out_5731132809769702324[20] = 0;
   out_5731132809769702324[21] = 0;
   out_5731132809769702324[22] = 1;
   out_5731132809769702324[23] = 0;
   out_5731132809769702324[24] = 0;
   out_5731132809769702324[25] = 0;
   out_5731132809769702324[26] = 0;
   out_5731132809769702324[27] = 0;
   out_5731132809769702324[28] = 0;
   out_5731132809769702324[29] = 0;
   out_5731132809769702324[30] = 0;
   out_5731132809769702324[31] = 0;
   out_5731132809769702324[32] = 0;
   out_5731132809769702324[33] = 0;
   out_5731132809769702324[34] = 0;
   out_5731132809769702324[35] = 0;
   out_5731132809769702324[36] = 0;
   out_5731132809769702324[37] = 0;
   out_5731132809769702324[38] = 0;
   out_5731132809769702324[39] = 0;
   out_5731132809769702324[40] = 0;
   out_5731132809769702324[41] = 1;
   out_5731132809769702324[42] = 0;
   out_5731132809769702324[43] = 0;
   out_5731132809769702324[44] = 0;
   out_5731132809769702324[45] = 0;
   out_5731132809769702324[46] = 0;
   out_5731132809769702324[47] = 0;
   out_5731132809769702324[48] = 0;
   out_5731132809769702324[49] = 0;
   out_5731132809769702324[50] = 0;
   out_5731132809769702324[51] = 0;
   out_5731132809769702324[52] = 0;
   out_5731132809769702324[53] = 0;
}
void h_14(double *state, double *unused, double *out_4572829225510058656) {
   out_4572829225510058656[0] = state[6];
   out_4572829225510058656[1] = state[7];
   out_4572829225510058656[2] = state[8];
}
void H_14(double *state, double *unused, double *out_563929447858002773) {
   out_563929447858002773[0] = 0;
   out_563929447858002773[1] = 0;
   out_563929447858002773[2] = 0;
   out_563929447858002773[3] = 0;
   out_563929447858002773[4] = 0;
   out_563929447858002773[5] = 0;
   out_563929447858002773[6] = 1;
   out_563929447858002773[7] = 0;
   out_563929447858002773[8] = 0;
   out_563929447858002773[9] = 0;
   out_563929447858002773[10] = 0;
   out_563929447858002773[11] = 0;
   out_563929447858002773[12] = 0;
   out_563929447858002773[13] = 0;
   out_563929447858002773[14] = 0;
   out_563929447858002773[15] = 0;
   out_563929447858002773[16] = 0;
   out_563929447858002773[17] = 0;
   out_563929447858002773[18] = 0;
   out_563929447858002773[19] = 0;
   out_563929447858002773[20] = 0;
   out_563929447858002773[21] = 0;
   out_563929447858002773[22] = 0;
   out_563929447858002773[23] = 0;
   out_563929447858002773[24] = 0;
   out_563929447858002773[25] = 1;
   out_563929447858002773[26] = 0;
   out_563929447858002773[27] = 0;
   out_563929447858002773[28] = 0;
   out_563929447858002773[29] = 0;
   out_563929447858002773[30] = 0;
   out_563929447858002773[31] = 0;
   out_563929447858002773[32] = 0;
   out_563929447858002773[33] = 0;
   out_563929447858002773[34] = 0;
   out_563929447858002773[35] = 0;
   out_563929447858002773[36] = 0;
   out_563929447858002773[37] = 0;
   out_563929447858002773[38] = 0;
   out_563929447858002773[39] = 0;
   out_563929447858002773[40] = 0;
   out_563929447858002773[41] = 0;
   out_563929447858002773[42] = 0;
   out_563929447858002773[43] = 0;
   out_563929447858002773[44] = 1;
   out_563929447858002773[45] = 0;
   out_563929447858002773[46] = 0;
   out_563929447858002773[47] = 0;
   out_563929447858002773[48] = 0;
   out_563929447858002773[49] = 0;
   out_563929447858002773[50] = 0;
   out_563929447858002773[51] = 0;
   out_563929447858002773[52] = 0;
   out_563929447858002773[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5453162044416851201) {
  err_fun(nom_x, delta_x, out_5453162044416851201);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2848752773381496345) {
  inv_err_fun(nom_x, true_x, out_2848752773381496345);
}
void pose_H_mod_fun(double *state, double *out_4906589349598379822) {
  H_mod_fun(state, out_4906589349598379822);
}
void pose_f_fun(double *state, double dt, double *out_2760483319111957401) {
  f_fun(state,  dt, out_2760483319111957401);
}
void pose_F_fun(double *state, double dt, double *out_2462794523887094837) {
  F_fun(state,  dt, out_2462794523887094837);
}
void pose_h_4(double *state, double *unused, double *out_3872084989267929897) {
  h_4(state, unused, out_3872084989267929897);
}
void pose_H_4(double *state, double *unused, double *out_2518858984437369523) {
  H_4(state, unused, out_2518858984437369523);
}
void pose_h_10(double *state, double *unused, double *out_3895192167056429518) {
  h_10(state, unused, out_3895192167056429518);
}
void pose_H_10(double *state, double *unused, double *out_5406689180752611899) {
  H_10(state, unused, out_5406689180752611899);
}
void pose_h_13(double *state, double *unused, double *out_6846163796915800555) {
  h_13(state, unused, out_6846163796915800555);
}
void pose_H_13(double *state, double *unused, double *out_5731132809769702324) {
  H_13(state, unused, out_5731132809769702324);
}
void pose_h_14(double *state, double *unused, double *out_4572829225510058656) {
  h_14(state, unused, out_4572829225510058656);
}
void pose_H_14(double *state, double *unused, double *out_563929447858002773) {
  H_14(state, unused, out_563929447858002773);
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
