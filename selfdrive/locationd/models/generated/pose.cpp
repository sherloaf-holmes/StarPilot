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
void err_fun(double *nom_x, double *delta_x, double *out_3780223817999612054) {
   out_3780223817999612054[0] = delta_x[0] + nom_x[0];
   out_3780223817999612054[1] = delta_x[1] + nom_x[1];
   out_3780223817999612054[2] = delta_x[2] + nom_x[2];
   out_3780223817999612054[3] = delta_x[3] + nom_x[3];
   out_3780223817999612054[4] = delta_x[4] + nom_x[4];
   out_3780223817999612054[5] = delta_x[5] + nom_x[5];
   out_3780223817999612054[6] = delta_x[6] + nom_x[6];
   out_3780223817999612054[7] = delta_x[7] + nom_x[7];
   out_3780223817999612054[8] = delta_x[8] + nom_x[8];
   out_3780223817999612054[9] = delta_x[9] + nom_x[9];
   out_3780223817999612054[10] = delta_x[10] + nom_x[10];
   out_3780223817999612054[11] = delta_x[11] + nom_x[11];
   out_3780223817999612054[12] = delta_x[12] + nom_x[12];
   out_3780223817999612054[13] = delta_x[13] + nom_x[13];
   out_3780223817999612054[14] = delta_x[14] + nom_x[14];
   out_3780223817999612054[15] = delta_x[15] + nom_x[15];
   out_3780223817999612054[16] = delta_x[16] + nom_x[16];
   out_3780223817999612054[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7482788729204437735) {
   out_7482788729204437735[0] = -nom_x[0] + true_x[0];
   out_7482788729204437735[1] = -nom_x[1] + true_x[1];
   out_7482788729204437735[2] = -nom_x[2] + true_x[2];
   out_7482788729204437735[3] = -nom_x[3] + true_x[3];
   out_7482788729204437735[4] = -nom_x[4] + true_x[4];
   out_7482788729204437735[5] = -nom_x[5] + true_x[5];
   out_7482788729204437735[6] = -nom_x[6] + true_x[6];
   out_7482788729204437735[7] = -nom_x[7] + true_x[7];
   out_7482788729204437735[8] = -nom_x[8] + true_x[8];
   out_7482788729204437735[9] = -nom_x[9] + true_x[9];
   out_7482788729204437735[10] = -nom_x[10] + true_x[10];
   out_7482788729204437735[11] = -nom_x[11] + true_x[11];
   out_7482788729204437735[12] = -nom_x[12] + true_x[12];
   out_7482788729204437735[13] = -nom_x[13] + true_x[13];
   out_7482788729204437735[14] = -nom_x[14] + true_x[14];
   out_7482788729204437735[15] = -nom_x[15] + true_x[15];
   out_7482788729204437735[16] = -nom_x[16] + true_x[16];
   out_7482788729204437735[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_559578409299766791) {
   out_559578409299766791[0] = 1.0;
   out_559578409299766791[1] = 0.0;
   out_559578409299766791[2] = 0.0;
   out_559578409299766791[3] = 0.0;
   out_559578409299766791[4] = 0.0;
   out_559578409299766791[5] = 0.0;
   out_559578409299766791[6] = 0.0;
   out_559578409299766791[7] = 0.0;
   out_559578409299766791[8] = 0.0;
   out_559578409299766791[9] = 0.0;
   out_559578409299766791[10] = 0.0;
   out_559578409299766791[11] = 0.0;
   out_559578409299766791[12] = 0.0;
   out_559578409299766791[13] = 0.0;
   out_559578409299766791[14] = 0.0;
   out_559578409299766791[15] = 0.0;
   out_559578409299766791[16] = 0.0;
   out_559578409299766791[17] = 0.0;
   out_559578409299766791[18] = 0.0;
   out_559578409299766791[19] = 1.0;
   out_559578409299766791[20] = 0.0;
   out_559578409299766791[21] = 0.0;
   out_559578409299766791[22] = 0.0;
   out_559578409299766791[23] = 0.0;
   out_559578409299766791[24] = 0.0;
   out_559578409299766791[25] = 0.0;
   out_559578409299766791[26] = 0.0;
   out_559578409299766791[27] = 0.0;
   out_559578409299766791[28] = 0.0;
   out_559578409299766791[29] = 0.0;
   out_559578409299766791[30] = 0.0;
   out_559578409299766791[31] = 0.0;
   out_559578409299766791[32] = 0.0;
   out_559578409299766791[33] = 0.0;
   out_559578409299766791[34] = 0.0;
   out_559578409299766791[35] = 0.0;
   out_559578409299766791[36] = 0.0;
   out_559578409299766791[37] = 0.0;
   out_559578409299766791[38] = 1.0;
   out_559578409299766791[39] = 0.0;
   out_559578409299766791[40] = 0.0;
   out_559578409299766791[41] = 0.0;
   out_559578409299766791[42] = 0.0;
   out_559578409299766791[43] = 0.0;
   out_559578409299766791[44] = 0.0;
   out_559578409299766791[45] = 0.0;
   out_559578409299766791[46] = 0.0;
   out_559578409299766791[47] = 0.0;
   out_559578409299766791[48] = 0.0;
   out_559578409299766791[49] = 0.0;
   out_559578409299766791[50] = 0.0;
   out_559578409299766791[51] = 0.0;
   out_559578409299766791[52] = 0.0;
   out_559578409299766791[53] = 0.0;
   out_559578409299766791[54] = 0.0;
   out_559578409299766791[55] = 0.0;
   out_559578409299766791[56] = 0.0;
   out_559578409299766791[57] = 1.0;
   out_559578409299766791[58] = 0.0;
   out_559578409299766791[59] = 0.0;
   out_559578409299766791[60] = 0.0;
   out_559578409299766791[61] = 0.0;
   out_559578409299766791[62] = 0.0;
   out_559578409299766791[63] = 0.0;
   out_559578409299766791[64] = 0.0;
   out_559578409299766791[65] = 0.0;
   out_559578409299766791[66] = 0.0;
   out_559578409299766791[67] = 0.0;
   out_559578409299766791[68] = 0.0;
   out_559578409299766791[69] = 0.0;
   out_559578409299766791[70] = 0.0;
   out_559578409299766791[71] = 0.0;
   out_559578409299766791[72] = 0.0;
   out_559578409299766791[73] = 0.0;
   out_559578409299766791[74] = 0.0;
   out_559578409299766791[75] = 0.0;
   out_559578409299766791[76] = 1.0;
   out_559578409299766791[77] = 0.0;
   out_559578409299766791[78] = 0.0;
   out_559578409299766791[79] = 0.0;
   out_559578409299766791[80] = 0.0;
   out_559578409299766791[81] = 0.0;
   out_559578409299766791[82] = 0.0;
   out_559578409299766791[83] = 0.0;
   out_559578409299766791[84] = 0.0;
   out_559578409299766791[85] = 0.0;
   out_559578409299766791[86] = 0.0;
   out_559578409299766791[87] = 0.0;
   out_559578409299766791[88] = 0.0;
   out_559578409299766791[89] = 0.0;
   out_559578409299766791[90] = 0.0;
   out_559578409299766791[91] = 0.0;
   out_559578409299766791[92] = 0.0;
   out_559578409299766791[93] = 0.0;
   out_559578409299766791[94] = 0.0;
   out_559578409299766791[95] = 1.0;
   out_559578409299766791[96] = 0.0;
   out_559578409299766791[97] = 0.0;
   out_559578409299766791[98] = 0.0;
   out_559578409299766791[99] = 0.0;
   out_559578409299766791[100] = 0.0;
   out_559578409299766791[101] = 0.0;
   out_559578409299766791[102] = 0.0;
   out_559578409299766791[103] = 0.0;
   out_559578409299766791[104] = 0.0;
   out_559578409299766791[105] = 0.0;
   out_559578409299766791[106] = 0.0;
   out_559578409299766791[107] = 0.0;
   out_559578409299766791[108] = 0.0;
   out_559578409299766791[109] = 0.0;
   out_559578409299766791[110] = 0.0;
   out_559578409299766791[111] = 0.0;
   out_559578409299766791[112] = 0.0;
   out_559578409299766791[113] = 0.0;
   out_559578409299766791[114] = 1.0;
   out_559578409299766791[115] = 0.0;
   out_559578409299766791[116] = 0.0;
   out_559578409299766791[117] = 0.0;
   out_559578409299766791[118] = 0.0;
   out_559578409299766791[119] = 0.0;
   out_559578409299766791[120] = 0.0;
   out_559578409299766791[121] = 0.0;
   out_559578409299766791[122] = 0.0;
   out_559578409299766791[123] = 0.0;
   out_559578409299766791[124] = 0.0;
   out_559578409299766791[125] = 0.0;
   out_559578409299766791[126] = 0.0;
   out_559578409299766791[127] = 0.0;
   out_559578409299766791[128] = 0.0;
   out_559578409299766791[129] = 0.0;
   out_559578409299766791[130] = 0.0;
   out_559578409299766791[131] = 0.0;
   out_559578409299766791[132] = 0.0;
   out_559578409299766791[133] = 1.0;
   out_559578409299766791[134] = 0.0;
   out_559578409299766791[135] = 0.0;
   out_559578409299766791[136] = 0.0;
   out_559578409299766791[137] = 0.0;
   out_559578409299766791[138] = 0.0;
   out_559578409299766791[139] = 0.0;
   out_559578409299766791[140] = 0.0;
   out_559578409299766791[141] = 0.0;
   out_559578409299766791[142] = 0.0;
   out_559578409299766791[143] = 0.0;
   out_559578409299766791[144] = 0.0;
   out_559578409299766791[145] = 0.0;
   out_559578409299766791[146] = 0.0;
   out_559578409299766791[147] = 0.0;
   out_559578409299766791[148] = 0.0;
   out_559578409299766791[149] = 0.0;
   out_559578409299766791[150] = 0.0;
   out_559578409299766791[151] = 0.0;
   out_559578409299766791[152] = 1.0;
   out_559578409299766791[153] = 0.0;
   out_559578409299766791[154] = 0.0;
   out_559578409299766791[155] = 0.0;
   out_559578409299766791[156] = 0.0;
   out_559578409299766791[157] = 0.0;
   out_559578409299766791[158] = 0.0;
   out_559578409299766791[159] = 0.0;
   out_559578409299766791[160] = 0.0;
   out_559578409299766791[161] = 0.0;
   out_559578409299766791[162] = 0.0;
   out_559578409299766791[163] = 0.0;
   out_559578409299766791[164] = 0.0;
   out_559578409299766791[165] = 0.0;
   out_559578409299766791[166] = 0.0;
   out_559578409299766791[167] = 0.0;
   out_559578409299766791[168] = 0.0;
   out_559578409299766791[169] = 0.0;
   out_559578409299766791[170] = 0.0;
   out_559578409299766791[171] = 1.0;
   out_559578409299766791[172] = 0.0;
   out_559578409299766791[173] = 0.0;
   out_559578409299766791[174] = 0.0;
   out_559578409299766791[175] = 0.0;
   out_559578409299766791[176] = 0.0;
   out_559578409299766791[177] = 0.0;
   out_559578409299766791[178] = 0.0;
   out_559578409299766791[179] = 0.0;
   out_559578409299766791[180] = 0.0;
   out_559578409299766791[181] = 0.0;
   out_559578409299766791[182] = 0.0;
   out_559578409299766791[183] = 0.0;
   out_559578409299766791[184] = 0.0;
   out_559578409299766791[185] = 0.0;
   out_559578409299766791[186] = 0.0;
   out_559578409299766791[187] = 0.0;
   out_559578409299766791[188] = 0.0;
   out_559578409299766791[189] = 0.0;
   out_559578409299766791[190] = 1.0;
   out_559578409299766791[191] = 0.0;
   out_559578409299766791[192] = 0.0;
   out_559578409299766791[193] = 0.0;
   out_559578409299766791[194] = 0.0;
   out_559578409299766791[195] = 0.0;
   out_559578409299766791[196] = 0.0;
   out_559578409299766791[197] = 0.0;
   out_559578409299766791[198] = 0.0;
   out_559578409299766791[199] = 0.0;
   out_559578409299766791[200] = 0.0;
   out_559578409299766791[201] = 0.0;
   out_559578409299766791[202] = 0.0;
   out_559578409299766791[203] = 0.0;
   out_559578409299766791[204] = 0.0;
   out_559578409299766791[205] = 0.0;
   out_559578409299766791[206] = 0.0;
   out_559578409299766791[207] = 0.0;
   out_559578409299766791[208] = 0.0;
   out_559578409299766791[209] = 1.0;
   out_559578409299766791[210] = 0.0;
   out_559578409299766791[211] = 0.0;
   out_559578409299766791[212] = 0.0;
   out_559578409299766791[213] = 0.0;
   out_559578409299766791[214] = 0.0;
   out_559578409299766791[215] = 0.0;
   out_559578409299766791[216] = 0.0;
   out_559578409299766791[217] = 0.0;
   out_559578409299766791[218] = 0.0;
   out_559578409299766791[219] = 0.0;
   out_559578409299766791[220] = 0.0;
   out_559578409299766791[221] = 0.0;
   out_559578409299766791[222] = 0.0;
   out_559578409299766791[223] = 0.0;
   out_559578409299766791[224] = 0.0;
   out_559578409299766791[225] = 0.0;
   out_559578409299766791[226] = 0.0;
   out_559578409299766791[227] = 0.0;
   out_559578409299766791[228] = 1.0;
   out_559578409299766791[229] = 0.0;
   out_559578409299766791[230] = 0.0;
   out_559578409299766791[231] = 0.0;
   out_559578409299766791[232] = 0.0;
   out_559578409299766791[233] = 0.0;
   out_559578409299766791[234] = 0.0;
   out_559578409299766791[235] = 0.0;
   out_559578409299766791[236] = 0.0;
   out_559578409299766791[237] = 0.0;
   out_559578409299766791[238] = 0.0;
   out_559578409299766791[239] = 0.0;
   out_559578409299766791[240] = 0.0;
   out_559578409299766791[241] = 0.0;
   out_559578409299766791[242] = 0.0;
   out_559578409299766791[243] = 0.0;
   out_559578409299766791[244] = 0.0;
   out_559578409299766791[245] = 0.0;
   out_559578409299766791[246] = 0.0;
   out_559578409299766791[247] = 1.0;
   out_559578409299766791[248] = 0.0;
   out_559578409299766791[249] = 0.0;
   out_559578409299766791[250] = 0.0;
   out_559578409299766791[251] = 0.0;
   out_559578409299766791[252] = 0.0;
   out_559578409299766791[253] = 0.0;
   out_559578409299766791[254] = 0.0;
   out_559578409299766791[255] = 0.0;
   out_559578409299766791[256] = 0.0;
   out_559578409299766791[257] = 0.0;
   out_559578409299766791[258] = 0.0;
   out_559578409299766791[259] = 0.0;
   out_559578409299766791[260] = 0.0;
   out_559578409299766791[261] = 0.0;
   out_559578409299766791[262] = 0.0;
   out_559578409299766791[263] = 0.0;
   out_559578409299766791[264] = 0.0;
   out_559578409299766791[265] = 0.0;
   out_559578409299766791[266] = 1.0;
   out_559578409299766791[267] = 0.0;
   out_559578409299766791[268] = 0.0;
   out_559578409299766791[269] = 0.0;
   out_559578409299766791[270] = 0.0;
   out_559578409299766791[271] = 0.0;
   out_559578409299766791[272] = 0.0;
   out_559578409299766791[273] = 0.0;
   out_559578409299766791[274] = 0.0;
   out_559578409299766791[275] = 0.0;
   out_559578409299766791[276] = 0.0;
   out_559578409299766791[277] = 0.0;
   out_559578409299766791[278] = 0.0;
   out_559578409299766791[279] = 0.0;
   out_559578409299766791[280] = 0.0;
   out_559578409299766791[281] = 0.0;
   out_559578409299766791[282] = 0.0;
   out_559578409299766791[283] = 0.0;
   out_559578409299766791[284] = 0.0;
   out_559578409299766791[285] = 1.0;
   out_559578409299766791[286] = 0.0;
   out_559578409299766791[287] = 0.0;
   out_559578409299766791[288] = 0.0;
   out_559578409299766791[289] = 0.0;
   out_559578409299766791[290] = 0.0;
   out_559578409299766791[291] = 0.0;
   out_559578409299766791[292] = 0.0;
   out_559578409299766791[293] = 0.0;
   out_559578409299766791[294] = 0.0;
   out_559578409299766791[295] = 0.0;
   out_559578409299766791[296] = 0.0;
   out_559578409299766791[297] = 0.0;
   out_559578409299766791[298] = 0.0;
   out_559578409299766791[299] = 0.0;
   out_559578409299766791[300] = 0.0;
   out_559578409299766791[301] = 0.0;
   out_559578409299766791[302] = 0.0;
   out_559578409299766791[303] = 0.0;
   out_559578409299766791[304] = 1.0;
   out_559578409299766791[305] = 0.0;
   out_559578409299766791[306] = 0.0;
   out_559578409299766791[307] = 0.0;
   out_559578409299766791[308] = 0.0;
   out_559578409299766791[309] = 0.0;
   out_559578409299766791[310] = 0.0;
   out_559578409299766791[311] = 0.0;
   out_559578409299766791[312] = 0.0;
   out_559578409299766791[313] = 0.0;
   out_559578409299766791[314] = 0.0;
   out_559578409299766791[315] = 0.0;
   out_559578409299766791[316] = 0.0;
   out_559578409299766791[317] = 0.0;
   out_559578409299766791[318] = 0.0;
   out_559578409299766791[319] = 0.0;
   out_559578409299766791[320] = 0.0;
   out_559578409299766791[321] = 0.0;
   out_559578409299766791[322] = 0.0;
   out_559578409299766791[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2617827132714175645) {
   out_2617827132714175645[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2617827132714175645[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2617827132714175645[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2617827132714175645[3] = dt*state[12] + state[3];
   out_2617827132714175645[4] = dt*state[13] + state[4];
   out_2617827132714175645[5] = dt*state[14] + state[5];
   out_2617827132714175645[6] = state[6];
   out_2617827132714175645[7] = state[7];
   out_2617827132714175645[8] = state[8];
   out_2617827132714175645[9] = state[9];
   out_2617827132714175645[10] = state[10];
   out_2617827132714175645[11] = state[11];
   out_2617827132714175645[12] = state[12];
   out_2617827132714175645[13] = state[13];
   out_2617827132714175645[14] = state[14];
   out_2617827132714175645[15] = state[15];
   out_2617827132714175645[16] = state[16];
   out_2617827132714175645[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7803734003668636083) {
   out_7803734003668636083[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7803734003668636083[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7803734003668636083[2] = 0;
   out_7803734003668636083[3] = 0;
   out_7803734003668636083[4] = 0;
   out_7803734003668636083[5] = 0;
   out_7803734003668636083[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7803734003668636083[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7803734003668636083[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7803734003668636083[9] = 0;
   out_7803734003668636083[10] = 0;
   out_7803734003668636083[11] = 0;
   out_7803734003668636083[12] = 0;
   out_7803734003668636083[13] = 0;
   out_7803734003668636083[14] = 0;
   out_7803734003668636083[15] = 0;
   out_7803734003668636083[16] = 0;
   out_7803734003668636083[17] = 0;
   out_7803734003668636083[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7803734003668636083[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7803734003668636083[20] = 0;
   out_7803734003668636083[21] = 0;
   out_7803734003668636083[22] = 0;
   out_7803734003668636083[23] = 0;
   out_7803734003668636083[24] = 0;
   out_7803734003668636083[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7803734003668636083[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7803734003668636083[27] = 0;
   out_7803734003668636083[28] = 0;
   out_7803734003668636083[29] = 0;
   out_7803734003668636083[30] = 0;
   out_7803734003668636083[31] = 0;
   out_7803734003668636083[32] = 0;
   out_7803734003668636083[33] = 0;
   out_7803734003668636083[34] = 0;
   out_7803734003668636083[35] = 0;
   out_7803734003668636083[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7803734003668636083[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7803734003668636083[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7803734003668636083[39] = 0;
   out_7803734003668636083[40] = 0;
   out_7803734003668636083[41] = 0;
   out_7803734003668636083[42] = 0;
   out_7803734003668636083[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7803734003668636083[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7803734003668636083[45] = 0;
   out_7803734003668636083[46] = 0;
   out_7803734003668636083[47] = 0;
   out_7803734003668636083[48] = 0;
   out_7803734003668636083[49] = 0;
   out_7803734003668636083[50] = 0;
   out_7803734003668636083[51] = 0;
   out_7803734003668636083[52] = 0;
   out_7803734003668636083[53] = 0;
   out_7803734003668636083[54] = 0;
   out_7803734003668636083[55] = 0;
   out_7803734003668636083[56] = 0;
   out_7803734003668636083[57] = 1;
   out_7803734003668636083[58] = 0;
   out_7803734003668636083[59] = 0;
   out_7803734003668636083[60] = 0;
   out_7803734003668636083[61] = 0;
   out_7803734003668636083[62] = 0;
   out_7803734003668636083[63] = 0;
   out_7803734003668636083[64] = 0;
   out_7803734003668636083[65] = 0;
   out_7803734003668636083[66] = dt;
   out_7803734003668636083[67] = 0;
   out_7803734003668636083[68] = 0;
   out_7803734003668636083[69] = 0;
   out_7803734003668636083[70] = 0;
   out_7803734003668636083[71] = 0;
   out_7803734003668636083[72] = 0;
   out_7803734003668636083[73] = 0;
   out_7803734003668636083[74] = 0;
   out_7803734003668636083[75] = 0;
   out_7803734003668636083[76] = 1;
   out_7803734003668636083[77] = 0;
   out_7803734003668636083[78] = 0;
   out_7803734003668636083[79] = 0;
   out_7803734003668636083[80] = 0;
   out_7803734003668636083[81] = 0;
   out_7803734003668636083[82] = 0;
   out_7803734003668636083[83] = 0;
   out_7803734003668636083[84] = 0;
   out_7803734003668636083[85] = dt;
   out_7803734003668636083[86] = 0;
   out_7803734003668636083[87] = 0;
   out_7803734003668636083[88] = 0;
   out_7803734003668636083[89] = 0;
   out_7803734003668636083[90] = 0;
   out_7803734003668636083[91] = 0;
   out_7803734003668636083[92] = 0;
   out_7803734003668636083[93] = 0;
   out_7803734003668636083[94] = 0;
   out_7803734003668636083[95] = 1;
   out_7803734003668636083[96] = 0;
   out_7803734003668636083[97] = 0;
   out_7803734003668636083[98] = 0;
   out_7803734003668636083[99] = 0;
   out_7803734003668636083[100] = 0;
   out_7803734003668636083[101] = 0;
   out_7803734003668636083[102] = 0;
   out_7803734003668636083[103] = 0;
   out_7803734003668636083[104] = dt;
   out_7803734003668636083[105] = 0;
   out_7803734003668636083[106] = 0;
   out_7803734003668636083[107] = 0;
   out_7803734003668636083[108] = 0;
   out_7803734003668636083[109] = 0;
   out_7803734003668636083[110] = 0;
   out_7803734003668636083[111] = 0;
   out_7803734003668636083[112] = 0;
   out_7803734003668636083[113] = 0;
   out_7803734003668636083[114] = 1;
   out_7803734003668636083[115] = 0;
   out_7803734003668636083[116] = 0;
   out_7803734003668636083[117] = 0;
   out_7803734003668636083[118] = 0;
   out_7803734003668636083[119] = 0;
   out_7803734003668636083[120] = 0;
   out_7803734003668636083[121] = 0;
   out_7803734003668636083[122] = 0;
   out_7803734003668636083[123] = 0;
   out_7803734003668636083[124] = 0;
   out_7803734003668636083[125] = 0;
   out_7803734003668636083[126] = 0;
   out_7803734003668636083[127] = 0;
   out_7803734003668636083[128] = 0;
   out_7803734003668636083[129] = 0;
   out_7803734003668636083[130] = 0;
   out_7803734003668636083[131] = 0;
   out_7803734003668636083[132] = 0;
   out_7803734003668636083[133] = 1;
   out_7803734003668636083[134] = 0;
   out_7803734003668636083[135] = 0;
   out_7803734003668636083[136] = 0;
   out_7803734003668636083[137] = 0;
   out_7803734003668636083[138] = 0;
   out_7803734003668636083[139] = 0;
   out_7803734003668636083[140] = 0;
   out_7803734003668636083[141] = 0;
   out_7803734003668636083[142] = 0;
   out_7803734003668636083[143] = 0;
   out_7803734003668636083[144] = 0;
   out_7803734003668636083[145] = 0;
   out_7803734003668636083[146] = 0;
   out_7803734003668636083[147] = 0;
   out_7803734003668636083[148] = 0;
   out_7803734003668636083[149] = 0;
   out_7803734003668636083[150] = 0;
   out_7803734003668636083[151] = 0;
   out_7803734003668636083[152] = 1;
   out_7803734003668636083[153] = 0;
   out_7803734003668636083[154] = 0;
   out_7803734003668636083[155] = 0;
   out_7803734003668636083[156] = 0;
   out_7803734003668636083[157] = 0;
   out_7803734003668636083[158] = 0;
   out_7803734003668636083[159] = 0;
   out_7803734003668636083[160] = 0;
   out_7803734003668636083[161] = 0;
   out_7803734003668636083[162] = 0;
   out_7803734003668636083[163] = 0;
   out_7803734003668636083[164] = 0;
   out_7803734003668636083[165] = 0;
   out_7803734003668636083[166] = 0;
   out_7803734003668636083[167] = 0;
   out_7803734003668636083[168] = 0;
   out_7803734003668636083[169] = 0;
   out_7803734003668636083[170] = 0;
   out_7803734003668636083[171] = 1;
   out_7803734003668636083[172] = 0;
   out_7803734003668636083[173] = 0;
   out_7803734003668636083[174] = 0;
   out_7803734003668636083[175] = 0;
   out_7803734003668636083[176] = 0;
   out_7803734003668636083[177] = 0;
   out_7803734003668636083[178] = 0;
   out_7803734003668636083[179] = 0;
   out_7803734003668636083[180] = 0;
   out_7803734003668636083[181] = 0;
   out_7803734003668636083[182] = 0;
   out_7803734003668636083[183] = 0;
   out_7803734003668636083[184] = 0;
   out_7803734003668636083[185] = 0;
   out_7803734003668636083[186] = 0;
   out_7803734003668636083[187] = 0;
   out_7803734003668636083[188] = 0;
   out_7803734003668636083[189] = 0;
   out_7803734003668636083[190] = 1;
   out_7803734003668636083[191] = 0;
   out_7803734003668636083[192] = 0;
   out_7803734003668636083[193] = 0;
   out_7803734003668636083[194] = 0;
   out_7803734003668636083[195] = 0;
   out_7803734003668636083[196] = 0;
   out_7803734003668636083[197] = 0;
   out_7803734003668636083[198] = 0;
   out_7803734003668636083[199] = 0;
   out_7803734003668636083[200] = 0;
   out_7803734003668636083[201] = 0;
   out_7803734003668636083[202] = 0;
   out_7803734003668636083[203] = 0;
   out_7803734003668636083[204] = 0;
   out_7803734003668636083[205] = 0;
   out_7803734003668636083[206] = 0;
   out_7803734003668636083[207] = 0;
   out_7803734003668636083[208] = 0;
   out_7803734003668636083[209] = 1;
   out_7803734003668636083[210] = 0;
   out_7803734003668636083[211] = 0;
   out_7803734003668636083[212] = 0;
   out_7803734003668636083[213] = 0;
   out_7803734003668636083[214] = 0;
   out_7803734003668636083[215] = 0;
   out_7803734003668636083[216] = 0;
   out_7803734003668636083[217] = 0;
   out_7803734003668636083[218] = 0;
   out_7803734003668636083[219] = 0;
   out_7803734003668636083[220] = 0;
   out_7803734003668636083[221] = 0;
   out_7803734003668636083[222] = 0;
   out_7803734003668636083[223] = 0;
   out_7803734003668636083[224] = 0;
   out_7803734003668636083[225] = 0;
   out_7803734003668636083[226] = 0;
   out_7803734003668636083[227] = 0;
   out_7803734003668636083[228] = 1;
   out_7803734003668636083[229] = 0;
   out_7803734003668636083[230] = 0;
   out_7803734003668636083[231] = 0;
   out_7803734003668636083[232] = 0;
   out_7803734003668636083[233] = 0;
   out_7803734003668636083[234] = 0;
   out_7803734003668636083[235] = 0;
   out_7803734003668636083[236] = 0;
   out_7803734003668636083[237] = 0;
   out_7803734003668636083[238] = 0;
   out_7803734003668636083[239] = 0;
   out_7803734003668636083[240] = 0;
   out_7803734003668636083[241] = 0;
   out_7803734003668636083[242] = 0;
   out_7803734003668636083[243] = 0;
   out_7803734003668636083[244] = 0;
   out_7803734003668636083[245] = 0;
   out_7803734003668636083[246] = 0;
   out_7803734003668636083[247] = 1;
   out_7803734003668636083[248] = 0;
   out_7803734003668636083[249] = 0;
   out_7803734003668636083[250] = 0;
   out_7803734003668636083[251] = 0;
   out_7803734003668636083[252] = 0;
   out_7803734003668636083[253] = 0;
   out_7803734003668636083[254] = 0;
   out_7803734003668636083[255] = 0;
   out_7803734003668636083[256] = 0;
   out_7803734003668636083[257] = 0;
   out_7803734003668636083[258] = 0;
   out_7803734003668636083[259] = 0;
   out_7803734003668636083[260] = 0;
   out_7803734003668636083[261] = 0;
   out_7803734003668636083[262] = 0;
   out_7803734003668636083[263] = 0;
   out_7803734003668636083[264] = 0;
   out_7803734003668636083[265] = 0;
   out_7803734003668636083[266] = 1;
   out_7803734003668636083[267] = 0;
   out_7803734003668636083[268] = 0;
   out_7803734003668636083[269] = 0;
   out_7803734003668636083[270] = 0;
   out_7803734003668636083[271] = 0;
   out_7803734003668636083[272] = 0;
   out_7803734003668636083[273] = 0;
   out_7803734003668636083[274] = 0;
   out_7803734003668636083[275] = 0;
   out_7803734003668636083[276] = 0;
   out_7803734003668636083[277] = 0;
   out_7803734003668636083[278] = 0;
   out_7803734003668636083[279] = 0;
   out_7803734003668636083[280] = 0;
   out_7803734003668636083[281] = 0;
   out_7803734003668636083[282] = 0;
   out_7803734003668636083[283] = 0;
   out_7803734003668636083[284] = 0;
   out_7803734003668636083[285] = 1;
   out_7803734003668636083[286] = 0;
   out_7803734003668636083[287] = 0;
   out_7803734003668636083[288] = 0;
   out_7803734003668636083[289] = 0;
   out_7803734003668636083[290] = 0;
   out_7803734003668636083[291] = 0;
   out_7803734003668636083[292] = 0;
   out_7803734003668636083[293] = 0;
   out_7803734003668636083[294] = 0;
   out_7803734003668636083[295] = 0;
   out_7803734003668636083[296] = 0;
   out_7803734003668636083[297] = 0;
   out_7803734003668636083[298] = 0;
   out_7803734003668636083[299] = 0;
   out_7803734003668636083[300] = 0;
   out_7803734003668636083[301] = 0;
   out_7803734003668636083[302] = 0;
   out_7803734003668636083[303] = 0;
   out_7803734003668636083[304] = 1;
   out_7803734003668636083[305] = 0;
   out_7803734003668636083[306] = 0;
   out_7803734003668636083[307] = 0;
   out_7803734003668636083[308] = 0;
   out_7803734003668636083[309] = 0;
   out_7803734003668636083[310] = 0;
   out_7803734003668636083[311] = 0;
   out_7803734003668636083[312] = 0;
   out_7803734003668636083[313] = 0;
   out_7803734003668636083[314] = 0;
   out_7803734003668636083[315] = 0;
   out_7803734003668636083[316] = 0;
   out_7803734003668636083[317] = 0;
   out_7803734003668636083[318] = 0;
   out_7803734003668636083[319] = 0;
   out_7803734003668636083[320] = 0;
   out_7803734003668636083[321] = 0;
   out_7803734003668636083[322] = 0;
   out_7803734003668636083[323] = 1;
}
void h_4(double *state, double *unused, double *out_937302404657292548) {
   out_937302404657292548[0] = state[6] + state[9];
   out_937302404657292548[1] = state[7] + state[10];
   out_937302404657292548[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1757525891182664895) {
   out_1757525891182664895[0] = 0;
   out_1757525891182664895[1] = 0;
   out_1757525891182664895[2] = 0;
   out_1757525891182664895[3] = 0;
   out_1757525891182664895[4] = 0;
   out_1757525891182664895[5] = 0;
   out_1757525891182664895[6] = 1;
   out_1757525891182664895[7] = 0;
   out_1757525891182664895[8] = 0;
   out_1757525891182664895[9] = 1;
   out_1757525891182664895[10] = 0;
   out_1757525891182664895[11] = 0;
   out_1757525891182664895[12] = 0;
   out_1757525891182664895[13] = 0;
   out_1757525891182664895[14] = 0;
   out_1757525891182664895[15] = 0;
   out_1757525891182664895[16] = 0;
   out_1757525891182664895[17] = 0;
   out_1757525891182664895[18] = 0;
   out_1757525891182664895[19] = 0;
   out_1757525891182664895[20] = 0;
   out_1757525891182664895[21] = 0;
   out_1757525891182664895[22] = 0;
   out_1757525891182664895[23] = 0;
   out_1757525891182664895[24] = 0;
   out_1757525891182664895[25] = 1;
   out_1757525891182664895[26] = 0;
   out_1757525891182664895[27] = 0;
   out_1757525891182664895[28] = 1;
   out_1757525891182664895[29] = 0;
   out_1757525891182664895[30] = 0;
   out_1757525891182664895[31] = 0;
   out_1757525891182664895[32] = 0;
   out_1757525891182664895[33] = 0;
   out_1757525891182664895[34] = 0;
   out_1757525891182664895[35] = 0;
   out_1757525891182664895[36] = 0;
   out_1757525891182664895[37] = 0;
   out_1757525891182664895[38] = 0;
   out_1757525891182664895[39] = 0;
   out_1757525891182664895[40] = 0;
   out_1757525891182664895[41] = 0;
   out_1757525891182664895[42] = 0;
   out_1757525891182664895[43] = 0;
   out_1757525891182664895[44] = 1;
   out_1757525891182664895[45] = 0;
   out_1757525891182664895[46] = 0;
   out_1757525891182664895[47] = 1;
   out_1757525891182664895[48] = 0;
   out_1757525891182664895[49] = 0;
   out_1757525891182664895[50] = 0;
   out_1757525891182664895[51] = 0;
   out_1757525891182664895[52] = 0;
   out_1757525891182664895[53] = 0;
}
void h_10(double *state, double *unused, double *out_6324073732783034610) {
   out_6324073732783034610[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6324073732783034610[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6324073732783034610[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5216067087000817824) {
   out_5216067087000817824[0] = 0;
   out_5216067087000817824[1] = 9.8100000000000005*cos(state[1]);
   out_5216067087000817824[2] = 0;
   out_5216067087000817824[3] = 0;
   out_5216067087000817824[4] = -state[8];
   out_5216067087000817824[5] = state[7];
   out_5216067087000817824[6] = 0;
   out_5216067087000817824[7] = state[5];
   out_5216067087000817824[8] = -state[4];
   out_5216067087000817824[9] = 0;
   out_5216067087000817824[10] = 0;
   out_5216067087000817824[11] = 0;
   out_5216067087000817824[12] = 1;
   out_5216067087000817824[13] = 0;
   out_5216067087000817824[14] = 0;
   out_5216067087000817824[15] = 1;
   out_5216067087000817824[16] = 0;
   out_5216067087000817824[17] = 0;
   out_5216067087000817824[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5216067087000817824[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5216067087000817824[20] = 0;
   out_5216067087000817824[21] = state[8];
   out_5216067087000817824[22] = 0;
   out_5216067087000817824[23] = -state[6];
   out_5216067087000817824[24] = -state[5];
   out_5216067087000817824[25] = 0;
   out_5216067087000817824[26] = state[3];
   out_5216067087000817824[27] = 0;
   out_5216067087000817824[28] = 0;
   out_5216067087000817824[29] = 0;
   out_5216067087000817824[30] = 0;
   out_5216067087000817824[31] = 1;
   out_5216067087000817824[32] = 0;
   out_5216067087000817824[33] = 0;
   out_5216067087000817824[34] = 1;
   out_5216067087000817824[35] = 0;
   out_5216067087000817824[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5216067087000817824[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5216067087000817824[38] = 0;
   out_5216067087000817824[39] = -state[7];
   out_5216067087000817824[40] = state[6];
   out_5216067087000817824[41] = 0;
   out_5216067087000817824[42] = state[4];
   out_5216067087000817824[43] = -state[3];
   out_5216067087000817824[44] = 0;
   out_5216067087000817824[45] = 0;
   out_5216067087000817824[46] = 0;
   out_5216067087000817824[47] = 0;
   out_5216067087000817824[48] = 0;
   out_5216067087000817824[49] = 0;
   out_5216067087000817824[50] = 1;
   out_5216067087000817824[51] = 0;
   out_5216067087000817824[52] = 0;
   out_5216067087000817824[53] = 1;
}
void h_13(double *state, double *unused, double *out_255942539802975373) {
   out_255942539802975373[0] = state[3];
   out_255942539802975373[1] = state[4];
   out_255942539802975373[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2076229572119859129) {
   out_2076229572119859129[0] = 0;
   out_2076229572119859129[1] = 0;
   out_2076229572119859129[2] = 0;
   out_2076229572119859129[3] = 1;
   out_2076229572119859129[4] = 0;
   out_2076229572119859129[5] = 0;
   out_2076229572119859129[6] = 0;
   out_2076229572119859129[7] = 0;
   out_2076229572119859129[8] = 0;
   out_2076229572119859129[9] = 0;
   out_2076229572119859129[10] = 0;
   out_2076229572119859129[11] = 0;
   out_2076229572119859129[12] = 0;
   out_2076229572119859129[13] = 0;
   out_2076229572119859129[14] = 0;
   out_2076229572119859129[15] = 0;
   out_2076229572119859129[16] = 0;
   out_2076229572119859129[17] = 0;
   out_2076229572119859129[18] = 0;
   out_2076229572119859129[19] = 0;
   out_2076229572119859129[20] = 0;
   out_2076229572119859129[21] = 0;
   out_2076229572119859129[22] = 1;
   out_2076229572119859129[23] = 0;
   out_2076229572119859129[24] = 0;
   out_2076229572119859129[25] = 0;
   out_2076229572119859129[26] = 0;
   out_2076229572119859129[27] = 0;
   out_2076229572119859129[28] = 0;
   out_2076229572119859129[29] = 0;
   out_2076229572119859129[30] = 0;
   out_2076229572119859129[31] = 0;
   out_2076229572119859129[32] = 0;
   out_2076229572119859129[33] = 0;
   out_2076229572119859129[34] = 0;
   out_2076229572119859129[35] = 0;
   out_2076229572119859129[36] = 0;
   out_2076229572119859129[37] = 0;
   out_2076229572119859129[38] = 0;
   out_2076229572119859129[39] = 0;
   out_2076229572119859129[40] = 0;
   out_2076229572119859129[41] = 1;
   out_2076229572119859129[42] = 0;
   out_2076229572119859129[43] = 0;
   out_2076229572119859129[44] = 0;
   out_2076229572119859129[45] = 0;
   out_2076229572119859129[46] = 0;
   out_2076229572119859129[47] = 0;
   out_2076229572119859129[48] = 0;
   out_2076229572119859129[49] = 0;
   out_2076229572119859129[50] = 0;
   out_2076229572119859129[51] = 0;
   out_2076229572119859129[52] = 0;
   out_2076229572119859129[53] = 0;
}
void h_14(double *state, double *unused, double *out_3257165685410083893) {
   out_3257165685410083893[0] = state[6];
   out_3257165685410083893[1] = state[7];
   out_3257165685410083893[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1325262541112707401) {
   out_1325262541112707401[0] = 0;
   out_1325262541112707401[1] = 0;
   out_1325262541112707401[2] = 0;
   out_1325262541112707401[3] = 0;
   out_1325262541112707401[4] = 0;
   out_1325262541112707401[5] = 0;
   out_1325262541112707401[6] = 1;
   out_1325262541112707401[7] = 0;
   out_1325262541112707401[8] = 0;
   out_1325262541112707401[9] = 0;
   out_1325262541112707401[10] = 0;
   out_1325262541112707401[11] = 0;
   out_1325262541112707401[12] = 0;
   out_1325262541112707401[13] = 0;
   out_1325262541112707401[14] = 0;
   out_1325262541112707401[15] = 0;
   out_1325262541112707401[16] = 0;
   out_1325262541112707401[17] = 0;
   out_1325262541112707401[18] = 0;
   out_1325262541112707401[19] = 0;
   out_1325262541112707401[20] = 0;
   out_1325262541112707401[21] = 0;
   out_1325262541112707401[22] = 0;
   out_1325262541112707401[23] = 0;
   out_1325262541112707401[24] = 0;
   out_1325262541112707401[25] = 1;
   out_1325262541112707401[26] = 0;
   out_1325262541112707401[27] = 0;
   out_1325262541112707401[28] = 0;
   out_1325262541112707401[29] = 0;
   out_1325262541112707401[30] = 0;
   out_1325262541112707401[31] = 0;
   out_1325262541112707401[32] = 0;
   out_1325262541112707401[33] = 0;
   out_1325262541112707401[34] = 0;
   out_1325262541112707401[35] = 0;
   out_1325262541112707401[36] = 0;
   out_1325262541112707401[37] = 0;
   out_1325262541112707401[38] = 0;
   out_1325262541112707401[39] = 0;
   out_1325262541112707401[40] = 0;
   out_1325262541112707401[41] = 0;
   out_1325262541112707401[42] = 0;
   out_1325262541112707401[43] = 0;
   out_1325262541112707401[44] = 1;
   out_1325262541112707401[45] = 0;
   out_1325262541112707401[46] = 0;
   out_1325262541112707401[47] = 0;
   out_1325262541112707401[48] = 0;
   out_1325262541112707401[49] = 0;
   out_1325262541112707401[50] = 0;
   out_1325262541112707401[51] = 0;
   out_1325262541112707401[52] = 0;
   out_1325262541112707401[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3780223817999612054) {
  err_fun(nom_x, delta_x, out_3780223817999612054);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7482788729204437735) {
  inv_err_fun(nom_x, true_x, out_7482788729204437735);
}
void pose_H_mod_fun(double *state, double *out_559578409299766791) {
  H_mod_fun(state, out_559578409299766791);
}
void pose_f_fun(double *state, double dt, double *out_2617827132714175645) {
  f_fun(state,  dt, out_2617827132714175645);
}
void pose_F_fun(double *state, double dt, double *out_7803734003668636083) {
  F_fun(state,  dt, out_7803734003668636083);
}
void pose_h_4(double *state, double *unused, double *out_937302404657292548) {
  h_4(state, unused, out_937302404657292548);
}
void pose_H_4(double *state, double *unused, double *out_1757525891182664895) {
  H_4(state, unused, out_1757525891182664895);
}
void pose_h_10(double *state, double *unused, double *out_6324073732783034610) {
  h_10(state, unused, out_6324073732783034610);
}
void pose_H_10(double *state, double *unused, double *out_5216067087000817824) {
  H_10(state, unused, out_5216067087000817824);
}
void pose_h_13(double *state, double *unused, double *out_255942539802975373) {
  h_13(state, unused, out_255942539802975373);
}
void pose_H_13(double *state, double *unused, double *out_2076229572119859129) {
  H_13(state, unused, out_2076229572119859129);
}
void pose_h_14(double *state, double *unused, double *out_3257165685410083893) {
  h_14(state, unused, out_3257165685410083893);
}
void pose_H_14(double *state, double *unused, double *out_1325262541112707401) {
  H_14(state, unused, out_1325262541112707401);
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
