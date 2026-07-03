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
void err_fun(double *nom_x, double *delta_x, double *out_8735210990522162572) {
   out_8735210990522162572[0] = delta_x[0] + nom_x[0];
   out_8735210990522162572[1] = delta_x[1] + nom_x[1];
   out_8735210990522162572[2] = delta_x[2] + nom_x[2];
   out_8735210990522162572[3] = delta_x[3] + nom_x[3];
   out_8735210990522162572[4] = delta_x[4] + nom_x[4];
   out_8735210990522162572[5] = delta_x[5] + nom_x[5];
   out_8735210990522162572[6] = delta_x[6] + nom_x[6];
   out_8735210990522162572[7] = delta_x[7] + nom_x[7];
   out_8735210990522162572[8] = delta_x[8] + nom_x[8];
   out_8735210990522162572[9] = delta_x[9] + nom_x[9];
   out_8735210990522162572[10] = delta_x[10] + nom_x[10];
   out_8735210990522162572[11] = delta_x[11] + nom_x[11];
   out_8735210990522162572[12] = delta_x[12] + nom_x[12];
   out_8735210990522162572[13] = delta_x[13] + nom_x[13];
   out_8735210990522162572[14] = delta_x[14] + nom_x[14];
   out_8735210990522162572[15] = delta_x[15] + nom_x[15];
   out_8735210990522162572[16] = delta_x[16] + nom_x[16];
   out_8735210990522162572[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7512947709845212137) {
   out_7512947709845212137[0] = -nom_x[0] + true_x[0];
   out_7512947709845212137[1] = -nom_x[1] + true_x[1];
   out_7512947709845212137[2] = -nom_x[2] + true_x[2];
   out_7512947709845212137[3] = -nom_x[3] + true_x[3];
   out_7512947709845212137[4] = -nom_x[4] + true_x[4];
   out_7512947709845212137[5] = -nom_x[5] + true_x[5];
   out_7512947709845212137[6] = -nom_x[6] + true_x[6];
   out_7512947709845212137[7] = -nom_x[7] + true_x[7];
   out_7512947709845212137[8] = -nom_x[8] + true_x[8];
   out_7512947709845212137[9] = -nom_x[9] + true_x[9];
   out_7512947709845212137[10] = -nom_x[10] + true_x[10];
   out_7512947709845212137[11] = -nom_x[11] + true_x[11];
   out_7512947709845212137[12] = -nom_x[12] + true_x[12];
   out_7512947709845212137[13] = -nom_x[13] + true_x[13];
   out_7512947709845212137[14] = -nom_x[14] + true_x[14];
   out_7512947709845212137[15] = -nom_x[15] + true_x[15];
   out_7512947709845212137[16] = -nom_x[16] + true_x[16];
   out_7512947709845212137[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5447571817541560059) {
   out_5447571817541560059[0] = 1.0;
   out_5447571817541560059[1] = 0.0;
   out_5447571817541560059[2] = 0.0;
   out_5447571817541560059[3] = 0.0;
   out_5447571817541560059[4] = 0.0;
   out_5447571817541560059[5] = 0.0;
   out_5447571817541560059[6] = 0.0;
   out_5447571817541560059[7] = 0.0;
   out_5447571817541560059[8] = 0.0;
   out_5447571817541560059[9] = 0.0;
   out_5447571817541560059[10] = 0.0;
   out_5447571817541560059[11] = 0.0;
   out_5447571817541560059[12] = 0.0;
   out_5447571817541560059[13] = 0.0;
   out_5447571817541560059[14] = 0.0;
   out_5447571817541560059[15] = 0.0;
   out_5447571817541560059[16] = 0.0;
   out_5447571817541560059[17] = 0.0;
   out_5447571817541560059[18] = 0.0;
   out_5447571817541560059[19] = 1.0;
   out_5447571817541560059[20] = 0.0;
   out_5447571817541560059[21] = 0.0;
   out_5447571817541560059[22] = 0.0;
   out_5447571817541560059[23] = 0.0;
   out_5447571817541560059[24] = 0.0;
   out_5447571817541560059[25] = 0.0;
   out_5447571817541560059[26] = 0.0;
   out_5447571817541560059[27] = 0.0;
   out_5447571817541560059[28] = 0.0;
   out_5447571817541560059[29] = 0.0;
   out_5447571817541560059[30] = 0.0;
   out_5447571817541560059[31] = 0.0;
   out_5447571817541560059[32] = 0.0;
   out_5447571817541560059[33] = 0.0;
   out_5447571817541560059[34] = 0.0;
   out_5447571817541560059[35] = 0.0;
   out_5447571817541560059[36] = 0.0;
   out_5447571817541560059[37] = 0.0;
   out_5447571817541560059[38] = 1.0;
   out_5447571817541560059[39] = 0.0;
   out_5447571817541560059[40] = 0.0;
   out_5447571817541560059[41] = 0.0;
   out_5447571817541560059[42] = 0.0;
   out_5447571817541560059[43] = 0.0;
   out_5447571817541560059[44] = 0.0;
   out_5447571817541560059[45] = 0.0;
   out_5447571817541560059[46] = 0.0;
   out_5447571817541560059[47] = 0.0;
   out_5447571817541560059[48] = 0.0;
   out_5447571817541560059[49] = 0.0;
   out_5447571817541560059[50] = 0.0;
   out_5447571817541560059[51] = 0.0;
   out_5447571817541560059[52] = 0.0;
   out_5447571817541560059[53] = 0.0;
   out_5447571817541560059[54] = 0.0;
   out_5447571817541560059[55] = 0.0;
   out_5447571817541560059[56] = 0.0;
   out_5447571817541560059[57] = 1.0;
   out_5447571817541560059[58] = 0.0;
   out_5447571817541560059[59] = 0.0;
   out_5447571817541560059[60] = 0.0;
   out_5447571817541560059[61] = 0.0;
   out_5447571817541560059[62] = 0.0;
   out_5447571817541560059[63] = 0.0;
   out_5447571817541560059[64] = 0.0;
   out_5447571817541560059[65] = 0.0;
   out_5447571817541560059[66] = 0.0;
   out_5447571817541560059[67] = 0.0;
   out_5447571817541560059[68] = 0.0;
   out_5447571817541560059[69] = 0.0;
   out_5447571817541560059[70] = 0.0;
   out_5447571817541560059[71] = 0.0;
   out_5447571817541560059[72] = 0.0;
   out_5447571817541560059[73] = 0.0;
   out_5447571817541560059[74] = 0.0;
   out_5447571817541560059[75] = 0.0;
   out_5447571817541560059[76] = 1.0;
   out_5447571817541560059[77] = 0.0;
   out_5447571817541560059[78] = 0.0;
   out_5447571817541560059[79] = 0.0;
   out_5447571817541560059[80] = 0.0;
   out_5447571817541560059[81] = 0.0;
   out_5447571817541560059[82] = 0.0;
   out_5447571817541560059[83] = 0.0;
   out_5447571817541560059[84] = 0.0;
   out_5447571817541560059[85] = 0.0;
   out_5447571817541560059[86] = 0.0;
   out_5447571817541560059[87] = 0.0;
   out_5447571817541560059[88] = 0.0;
   out_5447571817541560059[89] = 0.0;
   out_5447571817541560059[90] = 0.0;
   out_5447571817541560059[91] = 0.0;
   out_5447571817541560059[92] = 0.0;
   out_5447571817541560059[93] = 0.0;
   out_5447571817541560059[94] = 0.0;
   out_5447571817541560059[95] = 1.0;
   out_5447571817541560059[96] = 0.0;
   out_5447571817541560059[97] = 0.0;
   out_5447571817541560059[98] = 0.0;
   out_5447571817541560059[99] = 0.0;
   out_5447571817541560059[100] = 0.0;
   out_5447571817541560059[101] = 0.0;
   out_5447571817541560059[102] = 0.0;
   out_5447571817541560059[103] = 0.0;
   out_5447571817541560059[104] = 0.0;
   out_5447571817541560059[105] = 0.0;
   out_5447571817541560059[106] = 0.0;
   out_5447571817541560059[107] = 0.0;
   out_5447571817541560059[108] = 0.0;
   out_5447571817541560059[109] = 0.0;
   out_5447571817541560059[110] = 0.0;
   out_5447571817541560059[111] = 0.0;
   out_5447571817541560059[112] = 0.0;
   out_5447571817541560059[113] = 0.0;
   out_5447571817541560059[114] = 1.0;
   out_5447571817541560059[115] = 0.0;
   out_5447571817541560059[116] = 0.0;
   out_5447571817541560059[117] = 0.0;
   out_5447571817541560059[118] = 0.0;
   out_5447571817541560059[119] = 0.0;
   out_5447571817541560059[120] = 0.0;
   out_5447571817541560059[121] = 0.0;
   out_5447571817541560059[122] = 0.0;
   out_5447571817541560059[123] = 0.0;
   out_5447571817541560059[124] = 0.0;
   out_5447571817541560059[125] = 0.0;
   out_5447571817541560059[126] = 0.0;
   out_5447571817541560059[127] = 0.0;
   out_5447571817541560059[128] = 0.0;
   out_5447571817541560059[129] = 0.0;
   out_5447571817541560059[130] = 0.0;
   out_5447571817541560059[131] = 0.0;
   out_5447571817541560059[132] = 0.0;
   out_5447571817541560059[133] = 1.0;
   out_5447571817541560059[134] = 0.0;
   out_5447571817541560059[135] = 0.0;
   out_5447571817541560059[136] = 0.0;
   out_5447571817541560059[137] = 0.0;
   out_5447571817541560059[138] = 0.0;
   out_5447571817541560059[139] = 0.0;
   out_5447571817541560059[140] = 0.0;
   out_5447571817541560059[141] = 0.0;
   out_5447571817541560059[142] = 0.0;
   out_5447571817541560059[143] = 0.0;
   out_5447571817541560059[144] = 0.0;
   out_5447571817541560059[145] = 0.0;
   out_5447571817541560059[146] = 0.0;
   out_5447571817541560059[147] = 0.0;
   out_5447571817541560059[148] = 0.0;
   out_5447571817541560059[149] = 0.0;
   out_5447571817541560059[150] = 0.0;
   out_5447571817541560059[151] = 0.0;
   out_5447571817541560059[152] = 1.0;
   out_5447571817541560059[153] = 0.0;
   out_5447571817541560059[154] = 0.0;
   out_5447571817541560059[155] = 0.0;
   out_5447571817541560059[156] = 0.0;
   out_5447571817541560059[157] = 0.0;
   out_5447571817541560059[158] = 0.0;
   out_5447571817541560059[159] = 0.0;
   out_5447571817541560059[160] = 0.0;
   out_5447571817541560059[161] = 0.0;
   out_5447571817541560059[162] = 0.0;
   out_5447571817541560059[163] = 0.0;
   out_5447571817541560059[164] = 0.0;
   out_5447571817541560059[165] = 0.0;
   out_5447571817541560059[166] = 0.0;
   out_5447571817541560059[167] = 0.0;
   out_5447571817541560059[168] = 0.0;
   out_5447571817541560059[169] = 0.0;
   out_5447571817541560059[170] = 0.0;
   out_5447571817541560059[171] = 1.0;
   out_5447571817541560059[172] = 0.0;
   out_5447571817541560059[173] = 0.0;
   out_5447571817541560059[174] = 0.0;
   out_5447571817541560059[175] = 0.0;
   out_5447571817541560059[176] = 0.0;
   out_5447571817541560059[177] = 0.0;
   out_5447571817541560059[178] = 0.0;
   out_5447571817541560059[179] = 0.0;
   out_5447571817541560059[180] = 0.0;
   out_5447571817541560059[181] = 0.0;
   out_5447571817541560059[182] = 0.0;
   out_5447571817541560059[183] = 0.0;
   out_5447571817541560059[184] = 0.0;
   out_5447571817541560059[185] = 0.0;
   out_5447571817541560059[186] = 0.0;
   out_5447571817541560059[187] = 0.0;
   out_5447571817541560059[188] = 0.0;
   out_5447571817541560059[189] = 0.0;
   out_5447571817541560059[190] = 1.0;
   out_5447571817541560059[191] = 0.0;
   out_5447571817541560059[192] = 0.0;
   out_5447571817541560059[193] = 0.0;
   out_5447571817541560059[194] = 0.0;
   out_5447571817541560059[195] = 0.0;
   out_5447571817541560059[196] = 0.0;
   out_5447571817541560059[197] = 0.0;
   out_5447571817541560059[198] = 0.0;
   out_5447571817541560059[199] = 0.0;
   out_5447571817541560059[200] = 0.0;
   out_5447571817541560059[201] = 0.0;
   out_5447571817541560059[202] = 0.0;
   out_5447571817541560059[203] = 0.0;
   out_5447571817541560059[204] = 0.0;
   out_5447571817541560059[205] = 0.0;
   out_5447571817541560059[206] = 0.0;
   out_5447571817541560059[207] = 0.0;
   out_5447571817541560059[208] = 0.0;
   out_5447571817541560059[209] = 1.0;
   out_5447571817541560059[210] = 0.0;
   out_5447571817541560059[211] = 0.0;
   out_5447571817541560059[212] = 0.0;
   out_5447571817541560059[213] = 0.0;
   out_5447571817541560059[214] = 0.0;
   out_5447571817541560059[215] = 0.0;
   out_5447571817541560059[216] = 0.0;
   out_5447571817541560059[217] = 0.0;
   out_5447571817541560059[218] = 0.0;
   out_5447571817541560059[219] = 0.0;
   out_5447571817541560059[220] = 0.0;
   out_5447571817541560059[221] = 0.0;
   out_5447571817541560059[222] = 0.0;
   out_5447571817541560059[223] = 0.0;
   out_5447571817541560059[224] = 0.0;
   out_5447571817541560059[225] = 0.0;
   out_5447571817541560059[226] = 0.0;
   out_5447571817541560059[227] = 0.0;
   out_5447571817541560059[228] = 1.0;
   out_5447571817541560059[229] = 0.0;
   out_5447571817541560059[230] = 0.0;
   out_5447571817541560059[231] = 0.0;
   out_5447571817541560059[232] = 0.0;
   out_5447571817541560059[233] = 0.0;
   out_5447571817541560059[234] = 0.0;
   out_5447571817541560059[235] = 0.0;
   out_5447571817541560059[236] = 0.0;
   out_5447571817541560059[237] = 0.0;
   out_5447571817541560059[238] = 0.0;
   out_5447571817541560059[239] = 0.0;
   out_5447571817541560059[240] = 0.0;
   out_5447571817541560059[241] = 0.0;
   out_5447571817541560059[242] = 0.0;
   out_5447571817541560059[243] = 0.0;
   out_5447571817541560059[244] = 0.0;
   out_5447571817541560059[245] = 0.0;
   out_5447571817541560059[246] = 0.0;
   out_5447571817541560059[247] = 1.0;
   out_5447571817541560059[248] = 0.0;
   out_5447571817541560059[249] = 0.0;
   out_5447571817541560059[250] = 0.0;
   out_5447571817541560059[251] = 0.0;
   out_5447571817541560059[252] = 0.0;
   out_5447571817541560059[253] = 0.0;
   out_5447571817541560059[254] = 0.0;
   out_5447571817541560059[255] = 0.0;
   out_5447571817541560059[256] = 0.0;
   out_5447571817541560059[257] = 0.0;
   out_5447571817541560059[258] = 0.0;
   out_5447571817541560059[259] = 0.0;
   out_5447571817541560059[260] = 0.0;
   out_5447571817541560059[261] = 0.0;
   out_5447571817541560059[262] = 0.0;
   out_5447571817541560059[263] = 0.0;
   out_5447571817541560059[264] = 0.0;
   out_5447571817541560059[265] = 0.0;
   out_5447571817541560059[266] = 1.0;
   out_5447571817541560059[267] = 0.0;
   out_5447571817541560059[268] = 0.0;
   out_5447571817541560059[269] = 0.0;
   out_5447571817541560059[270] = 0.0;
   out_5447571817541560059[271] = 0.0;
   out_5447571817541560059[272] = 0.0;
   out_5447571817541560059[273] = 0.0;
   out_5447571817541560059[274] = 0.0;
   out_5447571817541560059[275] = 0.0;
   out_5447571817541560059[276] = 0.0;
   out_5447571817541560059[277] = 0.0;
   out_5447571817541560059[278] = 0.0;
   out_5447571817541560059[279] = 0.0;
   out_5447571817541560059[280] = 0.0;
   out_5447571817541560059[281] = 0.0;
   out_5447571817541560059[282] = 0.0;
   out_5447571817541560059[283] = 0.0;
   out_5447571817541560059[284] = 0.0;
   out_5447571817541560059[285] = 1.0;
   out_5447571817541560059[286] = 0.0;
   out_5447571817541560059[287] = 0.0;
   out_5447571817541560059[288] = 0.0;
   out_5447571817541560059[289] = 0.0;
   out_5447571817541560059[290] = 0.0;
   out_5447571817541560059[291] = 0.0;
   out_5447571817541560059[292] = 0.0;
   out_5447571817541560059[293] = 0.0;
   out_5447571817541560059[294] = 0.0;
   out_5447571817541560059[295] = 0.0;
   out_5447571817541560059[296] = 0.0;
   out_5447571817541560059[297] = 0.0;
   out_5447571817541560059[298] = 0.0;
   out_5447571817541560059[299] = 0.0;
   out_5447571817541560059[300] = 0.0;
   out_5447571817541560059[301] = 0.0;
   out_5447571817541560059[302] = 0.0;
   out_5447571817541560059[303] = 0.0;
   out_5447571817541560059[304] = 1.0;
   out_5447571817541560059[305] = 0.0;
   out_5447571817541560059[306] = 0.0;
   out_5447571817541560059[307] = 0.0;
   out_5447571817541560059[308] = 0.0;
   out_5447571817541560059[309] = 0.0;
   out_5447571817541560059[310] = 0.0;
   out_5447571817541560059[311] = 0.0;
   out_5447571817541560059[312] = 0.0;
   out_5447571817541560059[313] = 0.0;
   out_5447571817541560059[314] = 0.0;
   out_5447571817541560059[315] = 0.0;
   out_5447571817541560059[316] = 0.0;
   out_5447571817541560059[317] = 0.0;
   out_5447571817541560059[318] = 0.0;
   out_5447571817541560059[319] = 0.0;
   out_5447571817541560059[320] = 0.0;
   out_5447571817541560059[321] = 0.0;
   out_5447571817541560059[322] = 0.0;
   out_5447571817541560059[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8475410656787984151) {
   out_8475410656787984151[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8475410656787984151[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8475410656787984151[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8475410656787984151[3] = dt*state[12] + state[3];
   out_8475410656787984151[4] = dt*state[13] + state[4];
   out_8475410656787984151[5] = dt*state[14] + state[5];
   out_8475410656787984151[6] = state[6];
   out_8475410656787984151[7] = state[7];
   out_8475410656787984151[8] = state[8];
   out_8475410656787984151[9] = state[9];
   out_8475410656787984151[10] = state[10];
   out_8475410656787984151[11] = state[11];
   out_8475410656787984151[12] = state[12];
   out_8475410656787984151[13] = state[13];
   out_8475410656787984151[14] = state[14];
   out_8475410656787984151[15] = state[15];
   out_8475410656787984151[16] = state[16];
   out_8475410656787984151[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1772783662641610101) {
   out_1772783662641610101[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1772783662641610101[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1772783662641610101[2] = 0;
   out_1772783662641610101[3] = 0;
   out_1772783662641610101[4] = 0;
   out_1772783662641610101[5] = 0;
   out_1772783662641610101[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1772783662641610101[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1772783662641610101[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1772783662641610101[9] = 0;
   out_1772783662641610101[10] = 0;
   out_1772783662641610101[11] = 0;
   out_1772783662641610101[12] = 0;
   out_1772783662641610101[13] = 0;
   out_1772783662641610101[14] = 0;
   out_1772783662641610101[15] = 0;
   out_1772783662641610101[16] = 0;
   out_1772783662641610101[17] = 0;
   out_1772783662641610101[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1772783662641610101[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1772783662641610101[20] = 0;
   out_1772783662641610101[21] = 0;
   out_1772783662641610101[22] = 0;
   out_1772783662641610101[23] = 0;
   out_1772783662641610101[24] = 0;
   out_1772783662641610101[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1772783662641610101[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1772783662641610101[27] = 0;
   out_1772783662641610101[28] = 0;
   out_1772783662641610101[29] = 0;
   out_1772783662641610101[30] = 0;
   out_1772783662641610101[31] = 0;
   out_1772783662641610101[32] = 0;
   out_1772783662641610101[33] = 0;
   out_1772783662641610101[34] = 0;
   out_1772783662641610101[35] = 0;
   out_1772783662641610101[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1772783662641610101[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1772783662641610101[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1772783662641610101[39] = 0;
   out_1772783662641610101[40] = 0;
   out_1772783662641610101[41] = 0;
   out_1772783662641610101[42] = 0;
   out_1772783662641610101[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1772783662641610101[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1772783662641610101[45] = 0;
   out_1772783662641610101[46] = 0;
   out_1772783662641610101[47] = 0;
   out_1772783662641610101[48] = 0;
   out_1772783662641610101[49] = 0;
   out_1772783662641610101[50] = 0;
   out_1772783662641610101[51] = 0;
   out_1772783662641610101[52] = 0;
   out_1772783662641610101[53] = 0;
   out_1772783662641610101[54] = 0;
   out_1772783662641610101[55] = 0;
   out_1772783662641610101[56] = 0;
   out_1772783662641610101[57] = 1;
   out_1772783662641610101[58] = 0;
   out_1772783662641610101[59] = 0;
   out_1772783662641610101[60] = 0;
   out_1772783662641610101[61] = 0;
   out_1772783662641610101[62] = 0;
   out_1772783662641610101[63] = 0;
   out_1772783662641610101[64] = 0;
   out_1772783662641610101[65] = 0;
   out_1772783662641610101[66] = dt;
   out_1772783662641610101[67] = 0;
   out_1772783662641610101[68] = 0;
   out_1772783662641610101[69] = 0;
   out_1772783662641610101[70] = 0;
   out_1772783662641610101[71] = 0;
   out_1772783662641610101[72] = 0;
   out_1772783662641610101[73] = 0;
   out_1772783662641610101[74] = 0;
   out_1772783662641610101[75] = 0;
   out_1772783662641610101[76] = 1;
   out_1772783662641610101[77] = 0;
   out_1772783662641610101[78] = 0;
   out_1772783662641610101[79] = 0;
   out_1772783662641610101[80] = 0;
   out_1772783662641610101[81] = 0;
   out_1772783662641610101[82] = 0;
   out_1772783662641610101[83] = 0;
   out_1772783662641610101[84] = 0;
   out_1772783662641610101[85] = dt;
   out_1772783662641610101[86] = 0;
   out_1772783662641610101[87] = 0;
   out_1772783662641610101[88] = 0;
   out_1772783662641610101[89] = 0;
   out_1772783662641610101[90] = 0;
   out_1772783662641610101[91] = 0;
   out_1772783662641610101[92] = 0;
   out_1772783662641610101[93] = 0;
   out_1772783662641610101[94] = 0;
   out_1772783662641610101[95] = 1;
   out_1772783662641610101[96] = 0;
   out_1772783662641610101[97] = 0;
   out_1772783662641610101[98] = 0;
   out_1772783662641610101[99] = 0;
   out_1772783662641610101[100] = 0;
   out_1772783662641610101[101] = 0;
   out_1772783662641610101[102] = 0;
   out_1772783662641610101[103] = 0;
   out_1772783662641610101[104] = dt;
   out_1772783662641610101[105] = 0;
   out_1772783662641610101[106] = 0;
   out_1772783662641610101[107] = 0;
   out_1772783662641610101[108] = 0;
   out_1772783662641610101[109] = 0;
   out_1772783662641610101[110] = 0;
   out_1772783662641610101[111] = 0;
   out_1772783662641610101[112] = 0;
   out_1772783662641610101[113] = 0;
   out_1772783662641610101[114] = 1;
   out_1772783662641610101[115] = 0;
   out_1772783662641610101[116] = 0;
   out_1772783662641610101[117] = 0;
   out_1772783662641610101[118] = 0;
   out_1772783662641610101[119] = 0;
   out_1772783662641610101[120] = 0;
   out_1772783662641610101[121] = 0;
   out_1772783662641610101[122] = 0;
   out_1772783662641610101[123] = 0;
   out_1772783662641610101[124] = 0;
   out_1772783662641610101[125] = 0;
   out_1772783662641610101[126] = 0;
   out_1772783662641610101[127] = 0;
   out_1772783662641610101[128] = 0;
   out_1772783662641610101[129] = 0;
   out_1772783662641610101[130] = 0;
   out_1772783662641610101[131] = 0;
   out_1772783662641610101[132] = 0;
   out_1772783662641610101[133] = 1;
   out_1772783662641610101[134] = 0;
   out_1772783662641610101[135] = 0;
   out_1772783662641610101[136] = 0;
   out_1772783662641610101[137] = 0;
   out_1772783662641610101[138] = 0;
   out_1772783662641610101[139] = 0;
   out_1772783662641610101[140] = 0;
   out_1772783662641610101[141] = 0;
   out_1772783662641610101[142] = 0;
   out_1772783662641610101[143] = 0;
   out_1772783662641610101[144] = 0;
   out_1772783662641610101[145] = 0;
   out_1772783662641610101[146] = 0;
   out_1772783662641610101[147] = 0;
   out_1772783662641610101[148] = 0;
   out_1772783662641610101[149] = 0;
   out_1772783662641610101[150] = 0;
   out_1772783662641610101[151] = 0;
   out_1772783662641610101[152] = 1;
   out_1772783662641610101[153] = 0;
   out_1772783662641610101[154] = 0;
   out_1772783662641610101[155] = 0;
   out_1772783662641610101[156] = 0;
   out_1772783662641610101[157] = 0;
   out_1772783662641610101[158] = 0;
   out_1772783662641610101[159] = 0;
   out_1772783662641610101[160] = 0;
   out_1772783662641610101[161] = 0;
   out_1772783662641610101[162] = 0;
   out_1772783662641610101[163] = 0;
   out_1772783662641610101[164] = 0;
   out_1772783662641610101[165] = 0;
   out_1772783662641610101[166] = 0;
   out_1772783662641610101[167] = 0;
   out_1772783662641610101[168] = 0;
   out_1772783662641610101[169] = 0;
   out_1772783662641610101[170] = 0;
   out_1772783662641610101[171] = 1;
   out_1772783662641610101[172] = 0;
   out_1772783662641610101[173] = 0;
   out_1772783662641610101[174] = 0;
   out_1772783662641610101[175] = 0;
   out_1772783662641610101[176] = 0;
   out_1772783662641610101[177] = 0;
   out_1772783662641610101[178] = 0;
   out_1772783662641610101[179] = 0;
   out_1772783662641610101[180] = 0;
   out_1772783662641610101[181] = 0;
   out_1772783662641610101[182] = 0;
   out_1772783662641610101[183] = 0;
   out_1772783662641610101[184] = 0;
   out_1772783662641610101[185] = 0;
   out_1772783662641610101[186] = 0;
   out_1772783662641610101[187] = 0;
   out_1772783662641610101[188] = 0;
   out_1772783662641610101[189] = 0;
   out_1772783662641610101[190] = 1;
   out_1772783662641610101[191] = 0;
   out_1772783662641610101[192] = 0;
   out_1772783662641610101[193] = 0;
   out_1772783662641610101[194] = 0;
   out_1772783662641610101[195] = 0;
   out_1772783662641610101[196] = 0;
   out_1772783662641610101[197] = 0;
   out_1772783662641610101[198] = 0;
   out_1772783662641610101[199] = 0;
   out_1772783662641610101[200] = 0;
   out_1772783662641610101[201] = 0;
   out_1772783662641610101[202] = 0;
   out_1772783662641610101[203] = 0;
   out_1772783662641610101[204] = 0;
   out_1772783662641610101[205] = 0;
   out_1772783662641610101[206] = 0;
   out_1772783662641610101[207] = 0;
   out_1772783662641610101[208] = 0;
   out_1772783662641610101[209] = 1;
   out_1772783662641610101[210] = 0;
   out_1772783662641610101[211] = 0;
   out_1772783662641610101[212] = 0;
   out_1772783662641610101[213] = 0;
   out_1772783662641610101[214] = 0;
   out_1772783662641610101[215] = 0;
   out_1772783662641610101[216] = 0;
   out_1772783662641610101[217] = 0;
   out_1772783662641610101[218] = 0;
   out_1772783662641610101[219] = 0;
   out_1772783662641610101[220] = 0;
   out_1772783662641610101[221] = 0;
   out_1772783662641610101[222] = 0;
   out_1772783662641610101[223] = 0;
   out_1772783662641610101[224] = 0;
   out_1772783662641610101[225] = 0;
   out_1772783662641610101[226] = 0;
   out_1772783662641610101[227] = 0;
   out_1772783662641610101[228] = 1;
   out_1772783662641610101[229] = 0;
   out_1772783662641610101[230] = 0;
   out_1772783662641610101[231] = 0;
   out_1772783662641610101[232] = 0;
   out_1772783662641610101[233] = 0;
   out_1772783662641610101[234] = 0;
   out_1772783662641610101[235] = 0;
   out_1772783662641610101[236] = 0;
   out_1772783662641610101[237] = 0;
   out_1772783662641610101[238] = 0;
   out_1772783662641610101[239] = 0;
   out_1772783662641610101[240] = 0;
   out_1772783662641610101[241] = 0;
   out_1772783662641610101[242] = 0;
   out_1772783662641610101[243] = 0;
   out_1772783662641610101[244] = 0;
   out_1772783662641610101[245] = 0;
   out_1772783662641610101[246] = 0;
   out_1772783662641610101[247] = 1;
   out_1772783662641610101[248] = 0;
   out_1772783662641610101[249] = 0;
   out_1772783662641610101[250] = 0;
   out_1772783662641610101[251] = 0;
   out_1772783662641610101[252] = 0;
   out_1772783662641610101[253] = 0;
   out_1772783662641610101[254] = 0;
   out_1772783662641610101[255] = 0;
   out_1772783662641610101[256] = 0;
   out_1772783662641610101[257] = 0;
   out_1772783662641610101[258] = 0;
   out_1772783662641610101[259] = 0;
   out_1772783662641610101[260] = 0;
   out_1772783662641610101[261] = 0;
   out_1772783662641610101[262] = 0;
   out_1772783662641610101[263] = 0;
   out_1772783662641610101[264] = 0;
   out_1772783662641610101[265] = 0;
   out_1772783662641610101[266] = 1;
   out_1772783662641610101[267] = 0;
   out_1772783662641610101[268] = 0;
   out_1772783662641610101[269] = 0;
   out_1772783662641610101[270] = 0;
   out_1772783662641610101[271] = 0;
   out_1772783662641610101[272] = 0;
   out_1772783662641610101[273] = 0;
   out_1772783662641610101[274] = 0;
   out_1772783662641610101[275] = 0;
   out_1772783662641610101[276] = 0;
   out_1772783662641610101[277] = 0;
   out_1772783662641610101[278] = 0;
   out_1772783662641610101[279] = 0;
   out_1772783662641610101[280] = 0;
   out_1772783662641610101[281] = 0;
   out_1772783662641610101[282] = 0;
   out_1772783662641610101[283] = 0;
   out_1772783662641610101[284] = 0;
   out_1772783662641610101[285] = 1;
   out_1772783662641610101[286] = 0;
   out_1772783662641610101[287] = 0;
   out_1772783662641610101[288] = 0;
   out_1772783662641610101[289] = 0;
   out_1772783662641610101[290] = 0;
   out_1772783662641610101[291] = 0;
   out_1772783662641610101[292] = 0;
   out_1772783662641610101[293] = 0;
   out_1772783662641610101[294] = 0;
   out_1772783662641610101[295] = 0;
   out_1772783662641610101[296] = 0;
   out_1772783662641610101[297] = 0;
   out_1772783662641610101[298] = 0;
   out_1772783662641610101[299] = 0;
   out_1772783662641610101[300] = 0;
   out_1772783662641610101[301] = 0;
   out_1772783662641610101[302] = 0;
   out_1772783662641610101[303] = 0;
   out_1772783662641610101[304] = 1;
   out_1772783662641610101[305] = 0;
   out_1772783662641610101[306] = 0;
   out_1772783662641610101[307] = 0;
   out_1772783662641610101[308] = 0;
   out_1772783662641610101[309] = 0;
   out_1772783662641610101[310] = 0;
   out_1772783662641610101[311] = 0;
   out_1772783662641610101[312] = 0;
   out_1772783662641610101[313] = 0;
   out_1772783662641610101[314] = 0;
   out_1772783662641610101[315] = 0;
   out_1772783662641610101[316] = 0;
   out_1772783662641610101[317] = 0;
   out_1772783662641610101[318] = 0;
   out_1772783662641610101[319] = 0;
   out_1772783662641610101[320] = 0;
   out_1772783662641610101[321] = 0;
   out_1772783662641610101[322] = 0;
   out_1772783662641610101[323] = 1;
}
void h_4(double *state, double *unused, double *out_6916116063039855928) {
   out_6916116063039855928[0] = state[6] + state[9];
   out_6916116063039855928[1] = state[7] + state[10];
   out_6916116063039855928[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4133444241626837871) {
   out_4133444241626837871[0] = 0;
   out_4133444241626837871[1] = 0;
   out_4133444241626837871[2] = 0;
   out_4133444241626837871[3] = 0;
   out_4133444241626837871[4] = 0;
   out_4133444241626837871[5] = 0;
   out_4133444241626837871[6] = 1;
   out_4133444241626837871[7] = 0;
   out_4133444241626837871[8] = 0;
   out_4133444241626837871[9] = 1;
   out_4133444241626837871[10] = 0;
   out_4133444241626837871[11] = 0;
   out_4133444241626837871[12] = 0;
   out_4133444241626837871[13] = 0;
   out_4133444241626837871[14] = 0;
   out_4133444241626837871[15] = 0;
   out_4133444241626837871[16] = 0;
   out_4133444241626837871[17] = 0;
   out_4133444241626837871[18] = 0;
   out_4133444241626837871[19] = 0;
   out_4133444241626837871[20] = 0;
   out_4133444241626837871[21] = 0;
   out_4133444241626837871[22] = 0;
   out_4133444241626837871[23] = 0;
   out_4133444241626837871[24] = 0;
   out_4133444241626837871[25] = 1;
   out_4133444241626837871[26] = 0;
   out_4133444241626837871[27] = 0;
   out_4133444241626837871[28] = 1;
   out_4133444241626837871[29] = 0;
   out_4133444241626837871[30] = 0;
   out_4133444241626837871[31] = 0;
   out_4133444241626837871[32] = 0;
   out_4133444241626837871[33] = 0;
   out_4133444241626837871[34] = 0;
   out_4133444241626837871[35] = 0;
   out_4133444241626837871[36] = 0;
   out_4133444241626837871[37] = 0;
   out_4133444241626837871[38] = 0;
   out_4133444241626837871[39] = 0;
   out_4133444241626837871[40] = 0;
   out_4133444241626837871[41] = 0;
   out_4133444241626837871[42] = 0;
   out_4133444241626837871[43] = 0;
   out_4133444241626837871[44] = 1;
   out_4133444241626837871[45] = 0;
   out_4133444241626837871[46] = 0;
   out_4133444241626837871[47] = 1;
   out_4133444241626837871[48] = 0;
   out_4133444241626837871[49] = 0;
   out_4133444241626837871[50] = 0;
   out_4133444241626837871[51] = 0;
   out_4133444241626837871[52] = 0;
   out_4133444241626837871[53] = 0;
}
void h_10(double *state, double *unused, double *out_2205799671886878540) {
   out_2205799671886878540[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2205799671886878540[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2205799671886878540[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5975290705310221044) {
   out_5975290705310221044[0] = 0;
   out_5975290705310221044[1] = 9.8100000000000005*cos(state[1]);
   out_5975290705310221044[2] = 0;
   out_5975290705310221044[3] = 0;
   out_5975290705310221044[4] = -state[8];
   out_5975290705310221044[5] = state[7];
   out_5975290705310221044[6] = 0;
   out_5975290705310221044[7] = state[5];
   out_5975290705310221044[8] = -state[4];
   out_5975290705310221044[9] = 0;
   out_5975290705310221044[10] = 0;
   out_5975290705310221044[11] = 0;
   out_5975290705310221044[12] = 1;
   out_5975290705310221044[13] = 0;
   out_5975290705310221044[14] = 0;
   out_5975290705310221044[15] = 1;
   out_5975290705310221044[16] = 0;
   out_5975290705310221044[17] = 0;
   out_5975290705310221044[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5975290705310221044[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5975290705310221044[20] = 0;
   out_5975290705310221044[21] = state[8];
   out_5975290705310221044[22] = 0;
   out_5975290705310221044[23] = -state[6];
   out_5975290705310221044[24] = -state[5];
   out_5975290705310221044[25] = 0;
   out_5975290705310221044[26] = state[3];
   out_5975290705310221044[27] = 0;
   out_5975290705310221044[28] = 0;
   out_5975290705310221044[29] = 0;
   out_5975290705310221044[30] = 0;
   out_5975290705310221044[31] = 1;
   out_5975290705310221044[32] = 0;
   out_5975290705310221044[33] = 0;
   out_5975290705310221044[34] = 1;
   out_5975290705310221044[35] = 0;
   out_5975290705310221044[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5975290705310221044[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5975290705310221044[38] = 0;
   out_5975290705310221044[39] = -state[7];
   out_5975290705310221044[40] = state[6];
   out_5975290705310221044[41] = 0;
   out_5975290705310221044[42] = state[4];
   out_5975290705310221044[43] = -state[3];
   out_5975290705310221044[44] = 0;
   out_5975290705310221044[45] = 0;
   out_5975290705310221044[46] = 0;
   out_5975290705310221044[47] = 0;
   out_5975290705310221044[48] = 0;
   out_5975290705310221044[49] = 0;
   out_5975290705310221044[50] = 1;
   out_5975290705310221044[51] = 0;
   out_5975290705310221044[52] = 0;
   out_5975290705310221044[53] = 1;
}
void h_13(double *state, double *unused, double *out_1493083868240557826) {
   out_1493083868240557826[0] = state[3];
   out_1493083868240557826[1] = state[4];
   out_1493083868240557826[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7345718066959170672) {
   out_7345718066959170672[0] = 0;
   out_7345718066959170672[1] = 0;
   out_7345718066959170672[2] = 0;
   out_7345718066959170672[3] = 1;
   out_7345718066959170672[4] = 0;
   out_7345718066959170672[5] = 0;
   out_7345718066959170672[6] = 0;
   out_7345718066959170672[7] = 0;
   out_7345718066959170672[8] = 0;
   out_7345718066959170672[9] = 0;
   out_7345718066959170672[10] = 0;
   out_7345718066959170672[11] = 0;
   out_7345718066959170672[12] = 0;
   out_7345718066959170672[13] = 0;
   out_7345718066959170672[14] = 0;
   out_7345718066959170672[15] = 0;
   out_7345718066959170672[16] = 0;
   out_7345718066959170672[17] = 0;
   out_7345718066959170672[18] = 0;
   out_7345718066959170672[19] = 0;
   out_7345718066959170672[20] = 0;
   out_7345718066959170672[21] = 0;
   out_7345718066959170672[22] = 1;
   out_7345718066959170672[23] = 0;
   out_7345718066959170672[24] = 0;
   out_7345718066959170672[25] = 0;
   out_7345718066959170672[26] = 0;
   out_7345718066959170672[27] = 0;
   out_7345718066959170672[28] = 0;
   out_7345718066959170672[29] = 0;
   out_7345718066959170672[30] = 0;
   out_7345718066959170672[31] = 0;
   out_7345718066959170672[32] = 0;
   out_7345718066959170672[33] = 0;
   out_7345718066959170672[34] = 0;
   out_7345718066959170672[35] = 0;
   out_7345718066959170672[36] = 0;
   out_7345718066959170672[37] = 0;
   out_7345718066959170672[38] = 0;
   out_7345718066959170672[39] = 0;
   out_7345718066959170672[40] = 0;
   out_7345718066959170672[41] = 1;
   out_7345718066959170672[42] = 0;
   out_7345718066959170672[43] = 0;
   out_7345718066959170672[44] = 0;
   out_7345718066959170672[45] = 0;
   out_7345718066959170672[46] = 0;
   out_7345718066959170672[47] = 0;
   out_7345718066959170672[48] = 0;
   out_7345718066959170672[49] = 0;
   out_7345718066959170672[50] = 0;
   out_7345718066959170672[51] = 0;
   out_7345718066959170672[52] = 0;
   out_7345718066959170672[53] = 0;
}
void h_14(double *state, double *unused, double *out_3088699159055375359) {
   out_3088699159055375359[0] = state[6];
   out_3088699159055375359[1] = state[7];
   out_3088699159055375359[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8096685097966322400) {
   out_8096685097966322400[0] = 0;
   out_8096685097966322400[1] = 0;
   out_8096685097966322400[2] = 0;
   out_8096685097966322400[3] = 0;
   out_8096685097966322400[4] = 0;
   out_8096685097966322400[5] = 0;
   out_8096685097966322400[6] = 1;
   out_8096685097966322400[7] = 0;
   out_8096685097966322400[8] = 0;
   out_8096685097966322400[9] = 0;
   out_8096685097966322400[10] = 0;
   out_8096685097966322400[11] = 0;
   out_8096685097966322400[12] = 0;
   out_8096685097966322400[13] = 0;
   out_8096685097966322400[14] = 0;
   out_8096685097966322400[15] = 0;
   out_8096685097966322400[16] = 0;
   out_8096685097966322400[17] = 0;
   out_8096685097966322400[18] = 0;
   out_8096685097966322400[19] = 0;
   out_8096685097966322400[20] = 0;
   out_8096685097966322400[21] = 0;
   out_8096685097966322400[22] = 0;
   out_8096685097966322400[23] = 0;
   out_8096685097966322400[24] = 0;
   out_8096685097966322400[25] = 1;
   out_8096685097966322400[26] = 0;
   out_8096685097966322400[27] = 0;
   out_8096685097966322400[28] = 0;
   out_8096685097966322400[29] = 0;
   out_8096685097966322400[30] = 0;
   out_8096685097966322400[31] = 0;
   out_8096685097966322400[32] = 0;
   out_8096685097966322400[33] = 0;
   out_8096685097966322400[34] = 0;
   out_8096685097966322400[35] = 0;
   out_8096685097966322400[36] = 0;
   out_8096685097966322400[37] = 0;
   out_8096685097966322400[38] = 0;
   out_8096685097966322400[39] = 0;
   out_8096685097966322400[40] = 0;
   out_8096685097966322400[41] = 0;
   out_8096685097966322400[42] = 0;
   out_8096685097966322400[43] = 0;
   out_8096685097966322400[44] = 1;
   out_8096685097966322400[45] = 0;
   out_8096685097966322400[46] = 0;
   out_8096685097966322400[47] = 0;
   out_8096685097966322400[48] = 0;
   out_8096685097966322400[49] = 0;
   out_8096685097966322400[50] = 0;
   out_8096685097966322400[51] = 0;
   out_8096685097966322400[52] = 0;
   out_8096685097966322400[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8735210990522162572) {
  err_fun(nom_x, delta_x, out_8735210990522162572);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7512947709845212137) {
  inv_err_fun(nom_x, true_x, out_7512947709845212137);
}
void pose_H_mod_fun(double *state, double *out_5447571817541560059) {
  H_mod_fun(state, out_5447571817541560059);
}
void pose_f_fun(double *state, double dt, double *out_8475410656787984151) {
  f_fun(state,  dt, out_8475410656787984151);
}
void pose_F_fun(double *state, double dt, double *out_1772783662641610101) {
  F_fun(state,  dt, out_1772783662641610101);
}
void pose_h_4(double *state, double *unused, double *out_6916116063039855928) {
  h_4(state, unused, out_6916116063039855928);
}
void pose_H_4(double *state, double *unused, double *out_4133444241626837871) {
  H_4(state, unused, out_4133444241626837871);
}
void pose_h_10(double *state, double *unused, double *out_2205799671886878540) {
  h_10(state, unused, out_2205799671886878540);
}
void pose_H_10(double *state, double *unused, double *out_5975290705310221044) {
  H_10(state, unused, out_5975290705310221044);
}
void pose_h_13(double *state, double *unused, double *out_1493083868240557826) {
  h_13(state, unused, out_1493083868240557826);
}
void pose_H_13(double *state, double *unused, double *out_7345718066959170672) {
  H_13(state, unused, out_7345718066959170672);
}
void pose_h_14(double *state, double *unused, double *out_3088699159055375359) {
  h_14(state, unused, out_3088699159055375359);
}
void pose_H_14(double *state, double *unused, double *out_8096685097966322400) {
  H_14(state, unused, out_8096685097966322400);
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
