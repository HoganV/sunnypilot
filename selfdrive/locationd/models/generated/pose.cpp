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
void err_fun(double *nom_x, double *delta_x, double *out_6053087006272086738) {
   out_6053087006272086738[0] = delta_x[0] + nom_x[0];
   out_6053087006272086738[1] = delta_x[1] + nom_x[1];
   out_6053087006272086738[2] = delta_x[2] + nom_x[2];
   out_6053087006272086738[3] = delta_x[3] + nom_x[3];
   out_6053087006272086738[4] = delta_x[4] + nom_x[4];
   out_6053087006272086738[5] = delta_x[5] + nom_x[5];
   out_6053087006272086738[6] = delta_x[6] + nom_x[6];
   out_6053087006272086738[7] = delta_x[7] + nom_x[7];
   out_6053087006272086738[8] = delta_x[8] + nom_x[8];
   out_6053087006272086738[9] = delta_x[9] + nom_x[9];
   out_6053087006272086738[10] = delta_x[10] + nom_x[10];
   out_6053087006272086738[11] = delta_x[11] + nom_x[11];
   out_6053087006272086738[12] = delta_x[12] + nom_x[12];
   out_6053087006272086738[13] = delta_x[13] + nom_x[13];
   out_6053087006272086738[14] = delta_x[14] + nom_x[14];
   out_6053087006272086738[15] = delta_x[15] + nom_x[15];
   out_6053087006272086738[16] = delta_x[16] + nom_x[16];
   out_6053087006272086738[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1848428975880805561) {
   out_1848428975880805561[0] = -nom_x[0] + true_x[0];
   out_1848428975880805561[1] = -nom_x[1] + true_x[1];
   out_1848428975880805561[2] = -nom_x[2] + true_x[2];
   out_1848428975880805561[3] = -nom_x[3] + true_x[3];
   out_1848428975880805561[4] = -nom_x[4] + true_x[4];
   out_1848428975880805561[5] = -nom_x[5] + true_x[5];
   out_1848428975880805561[6] = -nom_x[6] + true_x[6];
   out_1848428975880805561[7] = -nom_x[7] + true_x[7];
   out_1848428975880805561[8] = -nom_x[8] + true_x[8];
   out_1848428975880805561[9] = -nom_x[9] + true_x[9];
   out_1848428975880805561[10] = -nom_x[10] + true_x[10];
   out_1848428975880805561[11] = -nom_x[11] + true_x[11];
   out_1848428975880805561[12] = -nom_x[12] + true_x[12];
   out_1848428975880805561[13] = -nom_x[13] + true_x[13];
   out_1848428975880805561[14] = -nom_x[14] + true_x[14];
   out_1848428975880805561[15] = -nom_x[15] + true_x[15];
   out_1848428975880805561[16] = -nom_x[16] + true_x[16];
   out_1848428975880805561[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3183080408274160777) {
   out_3183080408274160777[0] = 1.0;
   out_3183080408274160777[1] = 0.0;
   out_3183080408274160777[2] = 0.0;
   out_3183080408274160777[3] = 0.0;
   out_3183080408274160777[4] = 0.0;
   out_3183080408274160777[5] = 0.0;
   out_3183080408274160777[6] = 0.0;
   out_3183080408274160777[7] = 0.0;
   out_3183080408274160777[8] = 0.0;
   out_3183080408274160777[9] = 0.0;
   out_3183080408274160777[10] = 0.0;
   out_3183080408274160777[11] = 0.0;
   out_3183080408274160777[12] = 0.0;
   out_3183080408274160777[13] = 0.0;
   out_3183080408274160777[14] = 0.0;
   out_3183080408274160777[15] = 0.0;
   out_3183080408274160777[16] = 0.0;
   out_3183080408274160777[17] = 0.0;
   out_3183080408274160777[18] = 0.0;
   out_3183080408274160777[19] = 1.0;
   out_3183080408274160777[20] = 0.0;
   out_3183080408274160777[21] = 0.0;
   out_3183080408274160777[22] = 0.0;
   out_3183080408274160777[23] = 0.0;
   out_3183080408274160777[24] = 0.0;
   out_3183080408274160777[25] = 0.0;
   out_3183080408274160777[26] = 0.0;
   out_3183080408274160777[27] = 0.0;
   out_3183080408274160777[28] = 0.0;
   out_3183080408274160777[29] = 0.0;
   out_3183080408274160777[30] = 0.0;
   out_3183080408274160777[31] = 0.0;
   out_3183080408274160777[32] = 0.0;
   out_3183080408274160777[33] = 0.0;
   out_3183080408274160777[34] = 0.0;
   out_3183080408274160777[35] = 0.0;
   out_3183080408274160777[36] = 0.0;
   out_3183080408274160777[37] = 0.0;
   out_3183080408274160777[38] = 1.0;
   out_3183080408274160777[39] = 0.0;
   out_3183080408274160777[40] = 0.0;
   out_3183080408274160777[41] = 0.0;
   out_3183080408274160777[42] = 0.0;
   out_3183080408274160777[43] = 0.0;
   out_3183080408274160777[44] = 0.0;
   out_3183080408274160777[45] = 0.0;
   out_3183080408274160777[46] = 0.0;
   out_3183080408274160777[47] = 0.0;
   out_3183080408274160777[48] = 0.0;
   out_3183080408274160777[49] = 0.0;
   out_3183080408274160777[50] = 0.0;
   out_3183080408274160777[51] = 0.0;
   out_3183080408274160777[52] = 0.0;
   out_3183080408274160777[53] = 0.0;
   out_3183080408274160777[54] = 0.0;
   out_3183080408274160777[55] = 0.0;
   out_3183080408274160777[56] = 0.0;
   out_3183080408274160777[57] = 1.0;
   out_3183080408274160777[58] = 0.0;
   out_3183080408274160777[59] = 0.0;
   out_3183080408274160777[60] = 0.0;
   out_3183080408274160777[61] = 0.0;
   out_3183080408274160777[62] = 0.0;
   out_3183080408274160777[63] = 0.0;
   out_3183080408274160777[64] = 0.0;
   out_3183080408274160777[65] = 0.0;
   out_3183080408274160777[66] = 0.0;
   out_3183080408274160777[67] = 0.0;
   out_3183080408274160777[68] = 0.0;
   out_3183080408274160777[69] = 0.0;
   out_3183080408274160777[70] = 0.0;
   out_3183080408274160777[71] = 0.0;
   out_3183080408274160777[72] = 0.0;
   out_3183080408274160777[73] = 0.0;
   out_3183080408274160777[74] = 0.0;
   out_3183080408274160777[75] = 0.0;
   out_3183080408274160777[76] = 1.0;
   out_3183080408274160777[77] = 0.0;
   out_3183080408274160777[78] = 0.0;
   out_3183080408274160777[79] = 0.0;
   out_3183080408274160777[80] = 0.0;
   out_3183080408274160777[81] = 0.0;
   out_3183080408274160777[82] = 0.0;
   out_3183080408274160777[83] = 0.0;
   out_3183080408274160777[84] = 0.0;
   out_3183080408274160777[85] = 0.0;
   out_3183080408274160777[86] = 0.0;
   out_3183080408274160777[87] = 0.0;
   out_3183080408274160777[88] = 0.0;
   out_3183080408274160777[89] = 0.0;
   out_3183080408274160777[90] = 0.0;
   out_3183080408274160777[91] = 0.0;
   out_3183080408274160777[92] = 0.0;
   out_3183080408274160777[93] = 0.0;
   out_3183080408274160777[94] = 0.0;
   out_3183080408274160777[95] = 1.0;
   out_3183080408274160777[96] = 0.0;
   out_3183080408274160777[97] = 0.0;
   out_3183080408274160777[98] = 0.0;
   out_3183080408274160777[99] = 0.0;
   out_3183080408274160777[100] = 0.0;
   out_3183080408274160777[101] = 0.0;
   out_3183080408274160777[102] = 0.0;
   out_3183080408274160777[103] = 0.0;
   out_3183080408274160777[104] = 0.0;
   out_3183080408274160777[105] = 0.0;
   out_3183080408274160777[106] = 0.0;
   out_3183080408274160777[107] = 0.0;
   out_3183080408274160777[108] = 0.0;
   out_3183080408274160777[109] = 0.0;
   out_3183080408274160777[110] = 0.0;
   out_3183080408274160777[111] = 0.0;
   out_3183080408274160777[112] = 0.0;
   out_3183080408274160777[113] = 0.0;
   out_3183080408274160777[114] = 1.0;
   out_3183080408274160777[115] = 0.0;
   out_3183080408274160777[116] = 0.0;
   out_3183080408274160777[117] = 0.0;
   out_3183080408274160777[118] = 0.0;
   out_3183080408274160777[119] = 0.0;
   out_3183080408274160777[120] = 0.0;
   out_3183080408274160777[121] = 0.0;
   out_3183080408274160777[122] = 0.0;
   out_3183080408274160777[123] = 0.0;
   out_3183080408274160777[124] = 0.0;
   out_3183080408274160777[125] = 0.0;
   out_3183080408274160777[126] = 0.0;
   out_3183080408274160777[127] = 0.0;
   out_3183080408274160777[128] = 0.0;
   out_3183080408274160777[129] = 0.0;
   out_3183080408274160777[130] = 0.0;
   out_3183080408274160777[131] = 0.0;
   out_3183080408274160777[132] = 0.0;
   out_3183080408274160777[133] = 1.0;
   out_3183080408274160777[134] = 0.0;
   out_3183080408274160777[135] = 0.0;
   out_3183080408274160777[136] = 0.0;
   out_3183080408274160777[137] = 0.0;
   out_3183080408274160777[138] = 0.0;
   out_3183080408274160777[139] = 0.0;
   out_3183080408274160777[140] = 0.0;
   out_3183080408274160777[141] = 0.0;
   out_3183080408274160777[142] = 0.0;
   out_3183080408274160777[143] = 0.0;
   out_3183080408274160777[144] = 0.0;
   out_3183080408274160777[145] = 0.0;
   out_3183080408274160777[146] = 0.0;
   out_3183080408274160777[147] = 0.0;
   out_3183080408274160777[148] = 0.0;
   out_3183080408274160777[149] = 0.0;
   out_3183080408274160777[150] = 0.0;
   out_3183080408274160777[151] = 0.0;
   out_3183080408274160777[152] = 1.0;
   out_3183080408274160777[153] = 0.0;
   out_3183080408274160777[154] = 0.0;
   out_3183080408274160777[155] = 0.0;
   out_3183080408274160777[156] = 0.0;
   out_3183080408274160777[157] = 0.0;
   out_3183080408274160777[158] = 0.0;
   out_3183080408274160777[159] = 0.0;
   out_3183080408274160777[160] = 0.0;
   out_3183080408274160777[161] = 0.0;
   out_3183080408274160777[162] = 0.0;
   out_3183080408274160777[163] = 0.0;
   out_3183080408274160777[164] = 0.0;
   out_3183080408274160777[165] = 0.0;
   out_3183080408274160777[166] = 0.0;
   out_3183080408274160777[167] = 0.0;
   out_3183080408274160777[168] = 0.0;
   out_3183080408274160777[169] = 0.0;
   out_3183080408274160777[170] = 0.0;
   out_3183080408274160777[171] = 1.0;
   out_3183080408274160777[172] = 0.0;
   out_3183080408274160777[173] = 0.0;
   out_3183080408274160777[174] = 0.0;
   out_3183080408274160777[175] = 0.0;
   out_3183080408274160777[176] = 0.0;
   out_3183080408274160777[177] = 0.0;
   out_3183080408274160777[178] = 0.0;
   out_3183080408274160777[179] = 0.0;
   out_3183080408274160777[180] = 0.0;
   out_3183080408274160777[181] = 0.0;
   out_3183080408274160777[182] = 0.0;
   out_3183080408274160777[183] = 0.0;
   out_3183080408274160777[184] = 0.0;
   out_3183080408274160777[185] = 0.0;
   out_3183080408274160777[186] = 0.0;
   out_3183080408274160777[187] = 0.0;
   out_3183080408274160777[188] = 0.0;
   out_3183080408274160777[189] = 0.0;
   out_3183080408274160777[190] = 1.0;
   out_3183080408274160777[191] = 0.0;
   out_3183080408274160777[192] = 0.0;
   out_3183080408274160777[193] = 0.0;
   out_3183080408274160777[194] = 0.0;
   out_3183080408274160777[195] = 0.0;
   out_3183080408274160777[196] = 0.0;
   out_3183080408274160777[197] = 0.0;
   out_3183080408274160777[198] = 0.0;
   out_3183080408274160777[199] = 0.0;
   out_3183080408274160777[200] = 0.0;
   out_3183080408274160777[201] = 0.0;
   out_3183080408274160777[202] = 0.0;
   out_3183080408274160777[203] = 0.0;
   out_3183080408274160777[204] = 0.0;
   out_3183080408274160777[205] = 0.0;
   out_3183080408274160777[206] = 0.0;
   out_3183080408274160777[207] = 0.0;
   out_3183080408274160777[208] = 0.0;
   out_3183080408274160777[209] = 1.0;
   out_3183080408274160777[210] = 0.0;
   out_3183080408274160777[211] = 0.0;
   out_3183080408274160777[212] = 0.0;
   out_3183080408274160777[213] = 0.0;
   out_3183080408274160777[214] = 0.0;
   out_3183080408274160777[215] = 0.0;
   out_3183080408274160777[216] = 0.0;
   out_3183080408274160777[217] = 0.0;
   out_3183080408274160777[218] = 0.0;
   out_3183080408274160777[219] = 0.0;
   out_3183080408274160777[220] = 0.0;
   out_3183080408274160777[221] = 0.0;
   out_3183080408274160777[222] = 0.0;
   out_3183080408274160777[223] = 0.0;
   out_3183080408274160777[224] = 0.0;
   out_3183080408274160777[225] = 0.0;
   out_3183080408274160777[226] = 0.0;
   out_3183080408274160777[227] = 0.0;
   out_3183080408274160777[228] = 1.0;
   out_3183080408274160777[229] = 0.0;
   out_3183080408274160777[230] = 0.0;
   out_3183080408274160777[231] = 0.0;
   out_3183080408274160777[232] = 0.0;
   out_3183080408274160777[233] = 0.0;
   out_3183080408274160777[234] = 0.0;
   out_3183080408274160777[235] = 0.0;
   out_3183080408274160777[236] = 0.0;
   out_3183080408274160777[237] = 0.0;
   out_3183080408274160777[238] = 0.0;
   out_3183080408274160777[239] = 0.0;
   out_3183080408274160777[240] = 0.0;
   out_3183080408274160777[241] = 0.0;
   out_3183080408274160777[242] = 0.0;
   out_3183080408274160777[243] = 0.0;
   out_3183080408274160777[244] = 0.0;
   out_3183080408274160777[245] = 0.0;
   out_3183080408274160777[246] = 0.0;
   out_3183080408274160777[247] = 1.0;
   out_3183080408274160777[248] = 0.0;
   out_3183080408274160777[249] = 0.0;
   out_3183080408274160777[250] = 0.0;
   out_3183080408274160777[251] = 0.0;
   out_3183080408274160777[252] = 0.0;
   out_3183080408274160777[253] = 0.0;
   out_3183080408274160777[254] = 0.0;
   out_3183080408274160777[255] = 0.0;
   out_3183080408274160777[256] = 0.0;
   out_3183080408274160777[257] = 0.0;
   out_3183080408274160777[258] = 0.0;
   out_3183080408274160777[259] = 0.0;
   out_3183080408274160777[260] = 0.0;
   out_3183080408274160777[261] = 0.0;
   out_3183080408274160777[262] = 0.0;
   out_3183080408274160777[263] = 0.0;
   out_3183080408274160777[264] = 0.0;
   out_3183080408274160777[265] = 0.0;
   out_3183080408274160777[266] = 1.0;
   out_3183080408274160777[267] = 0.0;
   out_3183080408274160777[268] = 0.0;
   out_3183080408274160777[269] = 0.0;
   out_3183080408274160777[270] = 0.0;
   out_3183080408274160777[271] = 0.0;
   out_3183080408274160777[272] = 0.0;
   out_3183080408274160777[273] = 0.0;
   out_3183080408274160777[274] = 0.0;
   out_3183080408274160777[275] = 0.0;
   out_3183080408274160777[276] = 0.0;
   out_3183080408274160777[277] = 0.0;
   out_3183080408274160777[278] = 0.0;
   out_3183080408274160777[279] = 0.0;
   out_3183080408274160777[280] = 0.0;
   out_3183080408274160777[281] = 0.0;
   out_3183080408274160777[282] = 0.0;
   out_3183080408274160777[283] = 0.0;
   out_3183080408274160777[284] = 0.0;
   out_3183080408274160777[285] = 1.0;
   out_3183080408274160777[286] = 0.0;
   out_3183080408274160777[287] = 0.0;
   out_3183080408274160777[288] = 0.0;
   out_3183080408274160777[289] = 0.0;
   out_3183080408274160777[290] = 0.0;
   out_3183080408274160777[291] = 0.0;
   out_3183080408274160777[292] = 0.0;
   out_3183080408274160777[293] = 0.0;
   out_3183080408274160777[294] = 0.0;
   out_3183080408274160777[295] = 0.0;
   out_3183080408274160777[296] = 0.0;
   out_3183080408274160777[297] = 0.0;
   out_3183080408274160777[298] = 0.0;
   out_3183080408274160777[299] = 0.0;
   out_3183080408274160777[300] = 0.0;
   out_3183080408274160777[301] = 0.0;
   out_3183080408274160777[302] = 0.0;
   out_3183080408274160777[303] = 0.0;
   out_3183080408274160777[304] = 1.0;
   out_3183080408274160777[305] = 0.0;
   out_3183080408274160777[306] = 0.0;
   out_3183080408274160777[307] = 0.0;
   out_3183080408274160777[308] = 0.0;
   out_3183080408274160777[309] = 0.0;
   out_3183080408274160777[310] = 0.0;
   out_3183080408274160777[311] = 0.0;
   out_3183080408274160777[312] = 0.0;
   out_3183080408274160777[313] = 0.0;
   out_3183080408274160777[314] = 0.0;
   out_3183080408274160777[315] = 0.0;
   out_3183080408274160777[316] = 0.0;
   out_3183080408274160777[317] = 0.0;
   out_3183080408274160777[318] = 0.0;
   out_3183080408274160777[319] = 0.0;
   out_3183080408274160777[320] = 0.0;
   out_3183080408274160777[321] = 0.0;
   out_3183080408274160777[322] = 0.0;
   out_3183080408274160777[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2001410838433046702) {
   out_2001410838433046702[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2001410838433046702[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2001410838433046702[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2001410838433046702[3] = dt*state[12] + state[3];
   out_2001410838433046702[4] = dt*state[13] + state[4];
   out_2001410838433046702[5] = dt*state[14] + state[5];
   out_2001410838433046702[6] = state[6];
   out_2001410838433046702[7] = state[7];
   out_2001410838433046702[8] = state[8];
   out_2001410838433046702[9] = state[9];
   out_2001410838433046702[10] = state[10];
   out_2001410838433046702[11] = state[11];
   out_2001410838433046702[12] = state[12];
   out_2001410838433046702[13] = state[13];
   out_2001410838433046702[14] = state[14];
   out_2001410838433046702[15] = state[15];
   out_2001410838433046702[16] = state[16];
   out_2001410838433046702[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2415085859123987111) {
   out_2415085859123987111[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2415085859123987111[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2415085859123987111[2] = 0;
   out_2415085859123987111[3] = 0;
   out_2415085859123987111[4] = 0;
   out_2415085859123987111[5] = 0;
   out_2415085859123987111[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2415085859123987111[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2415085859123987111[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2415085859123987111[9] = 0;
   out_2415085859123987111[10] = 0;
   out_2415085859123987111[11] = 0;
   out_2415085859123987111[12] = 0;
   out_2415085859123987111[13] = 0;
   out_2415085859123987111[14] = 0;
   out_2415085859123987111[15] = 0;
   out_2415085859123987111[16] = 0;
   out_2415085859123987111[17] = 0;
   out_2415085859123987111[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2415085859123987111[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2415085859123987111[20] = 0;
   out_2415085859123987111[21] = 0;
   out_2415085859123987111[22] = 0;
   out_2415085859123987111[23] = 0;
   out_2415085859123987111[24] = 0;
   out_2415085859123987111[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2415085859123987111[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2415085859123987111[27] = 0;
   out_2415085859123987111[28] = 0;
   out_2415085859123987111[29] = 0;
   out_2415085859123987111[30] = 0;
   out_2415085859123987111[31] = 0;
   out_2415085859123987111[32] = 0;
   out_2415085859123987111[33] = 0;
   out_2415085859123987111[34] = 0;
   out_2415085859123987111[35] = 0;
   out_2415085859123987111[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2415085859123987111[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2415085859123987111[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2415085859123987111[39] = 0;
   out_2415085859123987111[40] = 0;
   out_2415085859123987111[41] = 0;
   out_2415085859123987111[42] = 0;
   out_2415085859123987111[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2415085859123987111[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2415085859123987111[45] = 0;
   out_2415085859123987111[46] = 0;
   out_2415085859123987111[47] = 0;
   out_2415085859123987111[48] = 0;
   out_2415085859123987111[49] = 0;
   out_2415085859123987111[50] = 0;
   out_2415085859123987111[51] = 0;
   out_2415085859123987111[52] = 0;
   out_2415085859123987111[53] = 0;
   out_2415085859123987111[54] = 0;
   out_2415085859123987111[55] = 0;
   out_2415085859123987111[56] = 0;
   out_2415085859123987111[57] = 1;
   out_2415085859123987111[58] = 0;
   out_2415085859123987111[59] = 0;
   out_2415085859123987111[60] = 0;
   out_2415085859123987111[61] = 0;
   out_2415085859123987111[62] = 0;
   out_2415085859123987111[63] = 0;
   out_2415085859123987111[64] = 0;
   out_2415085859123987111[65] = 0;
   out_2415085859123987111[66] = dt;
   out_2415085859123987111[67] = 0;
   out_2415085859123987111[68] = 0;
   out_2415085859123987111[69] = 0;
   out_2415085859123987111[70] = 0;
   out_2415085859123987111[71] = 0;
   out_2415085859123987111[72] = 0;
   out_2415085859123987111[73] = 0;
   out_2415085859123987111[74] = 0;
   out_2415085859123987111[75] = 0;
   out_2415085859123987111[76] = 1;
   out_2415085859123987111[77] = 0;
   out_2415085859123987111[78] = 0;
   out_2415085859123987111[79] = 0;
   out_2415085859123987111[80] = 0;
   out_2415085859123987111[81] = 0;
   out_2415085859123987111[82] = 0;
   out_2415085859123987111[83] = 0;
   out_2415085859123987111[84] = 0;
   out_2415085859123987111[85] = dt;
   out_2415085859123987111[86] = 0;
   out_2415085859123987111[87] = 0;
   out_2415085859123987111[88] = 0;
   out_2415085859123987111[89] = 0;
   out_2415085859123987111[90] = 0;
   out_2415085859123987111[91] = 0;
   out_2415085859123987111[92] = 0;
   out_2415085859123987111[93] = 0;
   out_2415085859123987111[94] = 0;
   out_2415085859123987111[95] = 1;
   out_2415085859123987111[96] = 0;
   out_2415085859123987111[97] = 0;
   out_2415085859123987111[98] = 0;
   out_2415085859123987111[99] = 0;
   out_2415085859123987111[100] = 0;
   out_2415085859123987111[101] = 0;
   out_2415085859123987111[102] = 0;
   out_2415085859123987111[103] = 0;
   out_2415085859123987111[104] = dt;
   out_2415085859123987111[105] = 0;
   out_2415085859123987111[106] = 0;
   out_2415085859123987111[107] = 0;
   out_2415085859123987111[108] = 0;
   out_2415085859123987111[109] = 0;
   out_2415085859123987111[110] = 0;
   out_2415085859123987111[111] = 0;
   out_2415085859123987111[112] = 0;
   out_2415085859123987111[113] = 0;
   out_2415085859123987111[114] = 1;
   out_2415085859123987111[115] = 0;
   out_2415085859123987111[116] = 0;
   out_2415085859123987111[117] = 0;
   out_2415085859123987111[118] = 0;
   out_2415085859123987111[119] = 0;
   out_2415085859123987111[120] = 0;
   out_2415085859123987111[121] = 0;
   out_2415085859123987111[122] = 0;
   out_2415085859123987111[123] = 0;
   out_2415085859123987111[124] = 0;
   out_2415085859123987111[125] = 0;
   out_2415085859123987111[126] = 0;
   out_2415085859123987111[127] = 0;
   out_2415085859123987111[128] = 0;
   out_2415085859123987111[129] = 0;
   out_2415085859123987111[130] = 0;
   out_2415085859123987111[131] = 0;
   out_2415085859123987111[132] = 0;
   out_2415085859123987111[133] = 1;
   out_2415085859123987111[134] = 0;
   out_2415085859123987111[135] = 0;
   out_2415085859123987111[136] = 0;
   out_2415085859123987111[137] = 0;
   out_2415085859123987111[138] = 0;
   out_2415085859123987111[139] = 0;
   out_2415085859123987111[140] = 0;
   out_2415085859123987111[141] = 0;
   out_2415085859123987111[142] = 0;
   out_2415085859123987111[143] = 0;
   out_2415085859123987111[144] = 0;
   out_2415085859123987111[145] = 0;
   out_2415085859123987111[146] = 0;
   out_2415085859123987111[147] = 0;
   out_2415085859123987111[148] = 0;
   out_2415085859123987111[149] = 0;
   out_2415085859123987111[150] = 0;
   out_2415085859123987111[151] = 0;
   out_2415085859123987111[152] = 1;
   out_2415085859123987111[153] = 0;
   out_2415085859123987111[154] = 0;
   out_2415085859123987111[155] = 0;
   out_2415085859123987111[156] = 0;
   out_2415085859123987111[157] = 0;
   out_2415085859123987111[158] = 0;
   out_2415085859123987111[159] = 0;
   out_2415085859123987111[160] = 0;
   out_2415085859123987111[161] = 0;
   out_2415085859123987111[162] = 0;
   out_2415085859123987111[163] = 0;
   out_2415085859123987111[164] = 0;
   out_2415085859123987111[165] = 0;
   out_2415085859123987111[166] = 0;
   out_2415085859123987111[167] = 0;
   out_2415085859123987111[168] = 0;
   out_2415085859123987111[169] = 0;
   out_2415085859123987111[170] = 0;
   out_2415085859123987111[171] = 1;
   out_2415085859123987111[172] = 0;
   out_2415085859123987111[173] = 0;
   out_2415085859123987111[174] = 0;
   out_2415085859123987111[175] = 0;
   out_2415085859123987111[176] = 0;
   out_2415085859123987111[177] = 0;
   out_2415085859123987111[178] = 0;
   out_2415085859123987111[179] = 0;
   out_2415085859123987111[180] = 0;
   out_2415085859123987111[181] = 0;
   out_2415085859123987111[182] = 0;
   out_2415085859123987111[183] = 0;
   out_2415085859123987111[184] = 0;
   out_2415085859123987111[185] = 0;
   out_2415085859123987111[186] = 0;
   out_2415085859123987111[187] = 0;
   out_2415085859123987111[188] = 0;
   out_2415085859123987111[189] = 0;
   out_2415085859123987111[190] = 1;
   out_2415085859123987111[191] = 0;
   out_2415085859123987111[192] = 0;
   out_2415085859123987111[193] = 0;
   out_2415085859123987111[194] = 0;
   out_2415085859123987111[195] = 0;
   out_2415085859123987111[196] = 0;
   out_2415085859123987111[197] = 0;
   out_2415085859123987111[198] = 0;
   out_2415085859123987111[199] = 0;
   out_2415085859123987111[200] = 0;
   out_2415085859123987111[201] = 0;
   out_2415085859123987111[202] = 0;
   out_2415085859123987111[203] = 0;
   out_2415085859123987111[204] = 0;
   out_2415085859123987111[205] = 0;
   out_2415085859123987111[206] = 0;
   out_2415085859123987111[207] = 0;
   out_2415085859123987111[208] = 0;
   out_2415085859123987111[209] = 1;
   out_2415085859123987111[210] = 0;
   out_2415085859123987111[211] = 0;
   out_2415085859123987111[212] = 0;
   out_2415085859123987111[213] = 0;
   out_2415085859123987111[214] = 0;
   out_2415085859123987111[215] = 0;
   out_2415085859123987111[216] = 0;
   out_2415085859123987111[217] = 0;
   out_2415085859123987111[218] = 0;
   out_2415085859123987111[219] = 0;
   out_2415085859123987111[220] = 0;
   out_2415085859123987111[221] = 0;
   out_2415085859123987111[222] = 0;
   out_2415085859123987111[223] = 0;
   out_2415085859123987111[224] = 0;
   out_2415085859123987111[225] = 0;
   out_2415085859123987111[226] = 0;
   out_2415085859123987111[227] = 0;
   out_2415085859123987111[228] = 1;
   out_2415085859123987111[229] = 0;
   out_2415085859123987111[230] = 0;
   out_2415085859123987111[231] = 0;
   out_2415085859123987111[232] = 0;
   out_2415085859123987111[233] = 0;
   out_2415085859123987111[234] = 0;
   out_2415085859123987111[235] = 0;
   out_2415085859123987111[236] = 0;
   out_2415085859123987111[237] = 0;
   out_2415085859123987111[238] = 0;
   out_2415085859123987111[239] = 0;
   out_2415085859123987111[240] = 0;
   out_2415085859123987111[241] = 0;
   out_2415085859123987111[242] = 0;
   out_2415085859123987111[243] = 0;
   out_2415085859123987111[244] = 0;
   out_2415085859123987111[245] = 0;
   out_2415085859123987111[246] = 0;
   out_2415085859123987111[247] = 1;
   out_2415085859123987111[248] = 0;
   out_2415085859123987111[249] = 0;
   out_2415085859123987111[250] = 0;
   out_2415085859123987111[251] = 0;
   out_2415085859123987111[252] = 0;
   out_2415085859123987111[253] = 0;
   out_2415085859123987111[254] = 0;
   out_2415085859123987111[255] = 0;
   out_2415085859123987111[256] = 0;
   out_2415085859123987111[257] = 0;
   out_2415085859123987111[258] = 0;
   out_2415085859123987111[259] = 0;
   out_2415085859123987111[260] = 0;
   out_2415085859123987111[261] = 0;
   out_2415085859123987111[262] = 0;
   out_2415085859123987111[263] = 0;
   out_2415085859123987111[264] = 0;
   out_2415085859123987111[265] = 0;
   out_2415085859123987111[266] = 1;
   out_2415085859123987111[267] = 0;
   out_2415085859123987111[268] = 0;
   out_2415085859123987111[269] = 0;
   out_2415085859123987111[270] = 0;
   out_2415085859123987111[271] = 0;
   out_2415085859123987111[272] = 0;
   out_2415085859123987111[273] = 0;
   out_2415085859123987111[274] = 0;
   out_2415085859123987111[275] = 0;
   out_2415085859123987111[276] = 0;
   out_2415085859123987111[277] = 0;
   out_2415085859123987111[278] = 0;
   out_2415085859123987111[279] = 0;
   out_2415085859123987111[280] = 0;
   out_2415085859123987111[281] = 0;
   out_2415085859123987111[282] = 0;
   out_2415085859123987111[283] = 0;
   out_2415085859123987111[284] = 0;
   out_2415085859123987111[285] = 1;
   out_2415085859123987111[286] = 0;
   out_2415085859123987111[287] = 0;
   out_2415085859123987111[288] = 0;
   out_2415085859123987111[289] = 0;
   out_2415085859123987111[290] = 0;
   out_2415085859123987111[291] = 0;
   out_2415085859123987111[292] = 0;
   out_2415085859123987111[293] = 0;
   out_2415085859123987111[294] = 0;
   out_2415085859123987111[295] = 0;
   out_2415085859123987111[296] = 0;
   out_2415085859123987111[297] = 0;
   out_2415085859123987111[298] = 0;
   out_2415085859123987111[299] = 0;
   out_2415085859123987111[300] = 0;
   out_2415085859123987111[301] = 0;
   out_2415085859123987111[302] = 0;
   out_2415085859123987111[303] = 0;
   out_2415085859123987111[304] = 1;
   out_2415085859123987111[305] = 0;
   out_2415085859123987111[306] = 0;
   out_2415085859123987111[307] = 0;
   out_2415085859123987111[308] = 0;
   out_2415085859123987111[309] = 0;
   out_2415085859123987111[310] = 0;
   out_2415085859123987111[311] = 0;
   out_2415085859123987111[312] = 0;
   out_2415085859123987111[313] = 0;
   out_2415085859123987111[314] = 0;
   out_2415085859123987111[315] = 0;
   out_2415085859123987111[316] = 0;
   out_2415085859123987111[317] = 0;
   out_2415085859123987111[318] = 0;
   out_2415085859123987111[319] = 0;
   out_2415085859123987111[320] = 0;
   out_2415085859123987111[321] = 0;
   out_2415085859123987111[322] = 0;
   out_2415085859123987111[323] = 1;
}
void h_4(double *state, double *unused, double *out_7740735704804213850) {
   out_7740735704804213850[0] = state[6] + state[9];
   out_7740735704804213850[1] = state[7] + state[10];
   out_7740735704804213850[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5761281257783660565) {
   out_5761281257783660565[0] = 0;
   out_5761281257783660565[1] = 0;
   out_5761281257783660565[2] = 0;
   out_5761281257783660565[3] = 0;
   out_5761281257783660565[4] = 0;
   out_5761281257783660565[5] = 0;
   out_5761281257783660565[6] = 1;
   out_5761281257783660565[7] = 0;
   out_5761281257783660565[8] = 0;
   out_5761281257783660565[9] = 1;
   out_5761281257783660565[10] = 0;
   out_5761281257783660565[11] = 0;
   out_5761281257783660565[12] = 0;
   out_5761281257783660565[13] = 0;
   out_5761281257783660565[14] = 0;
   out_5761281257783660565[15] = 0;
   out_5761281257783660565[16] = 0;
   out_5761281257783660565[17] = 0;
   out_5761281257783660565[18] = 0;
   out_5761281257783660565[19] = 0;
   out_5761281257783660565[20] = 0;
   out_5761281257783660565[21] = 0;
   out_5761281257783660565[22] = 0;
   out_5761281257783660565[23] = 0;
   out_5761281257783660565[24] = 0;
   out_5761281257783660565[25] = 1;
   out_5761281257783660565[26] = 0;
   out_5761281257783660565[27] = 0;
   out_5761281257783660565[28] = 1;
   out_5761281257783660565[29] = 0;
   out_5761281257783660565[30] = 0;
   out_5761281257783660565[31] = 0;
   out_5761281257783660565[32] = 0;
   out_5761281257783660565[33] = 0;
   out_5761281257783660565[34] = 0;
   out_5761281257783660565[35] = 0;
   out_5761281257783660565[36] = 0;
   out_5761281257783660565[37] = 0;
   out_5761281257783660565[38] = 0;
   out_5761281257783660565[39] = 0;
   out_5761281257783660565[40] = 0;
   out_5761281257783660565[41] = 0;
   out_5761281257783660565[42] = 0;
   out_5761281257783660565[43] = 0;
   out_5761281257783660565[44] = 1;
   out_5761281257783660565[45] = 0;
   out_5761281257783660565[46] = 0;
   out_5761281257783660565[47] = 1;
   out_5761281257783660565[48] = 0;
   out_5761281257783660565[49] = 0;
   out_5761281257783660565[50] = 0;
   out_5761281257783660565[51] = 0;
   out_5761281257783660565[52] = 0;
   out_5761281257783660565[53] = 0;
}
void h_10(double *state, double *unused, double *out_97048509807628744) {
   out_97048509807628744[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_97048509807628744[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_97048509807628744[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4447383680712310759) {
   out_4447383680712310759[0] = 0;
   out_4447383680712310759[1] = 9.8100000000000005*cos(state[1]);
   out_4447383680712310759[2] = 0;
   out_4447383680712310759[3] = 0;
   out_4447383680712310759[4] = -state[8];
   out_4447383680712310759[5] = state[7];
   out_4447383680712310759[6] = 0;
   out_4447383680712310759[7] = state[5];
   out_4447383680712310759[8] = -state[4];
   out_4447383680712310759[9] = 0;
   out_4447383680712310759[10] = 0;
   out_4447383680712310759[11] = 0;
   out_4447383680712310759[12] = 1;
   out_4447383680712310759[13] = 0;
   out_4447383680712310759[14] = 0;
   out_4447383680712310759[15] = 1;
   out_4447383680712310759[16] = 0;
   out_4447383680712310759[17] = 0;
   out_4447383680712310759[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4447383680712310759[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4447383680712310759[20] = 0;
   out_4447383680712310759[21] = state[8];
   out_4447383680712310759[22] = 0;
   out_4447383680712310759[23] = -state[6];
   out_4447383680712310759[24] = -state[5];
   out_4447383680712310759[25] = 0;
   out_4447383680712310759[26] = state[3];
   out_4447383680712310759[27] = 0;
   out_4447383680712310759[28] = 0;
   out_4447383680712310759[29] = 0;
   out_4447383680712310759[30] = 0;
   out_4447383680712310759[31] = 1;
   out_4447383680712310759[32] = 0;
   out_4447383680712310759[33] = 0;
   out_4447383680712310759[34] = 1;
   out_4447383680712310759[35] = 0;
   out_4447383680712310759[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4447383680712310759[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4447383680712310759[38] = 0;
   out_4447383680712310759[39] = -state[7];
   out_4447383680712310759[40] = state[6];
   out_4447383680712310759[41] = 0;
   out_4447383680712310759[42] = state[4];
   out_4447383680712310759[43] = -state[3];
   out_4447383680712310759[44] = 0;
   out_4447383680712310759[45] = 0;
   out_4447383680712310759[46] = 0;
   out_4447383680712310759[47] = 0;
   out_4447383680712310759[48] = 0;
   out_4447383680712310759[49] = 0;
   out_4447383680712310759[50] = 1;
   out_4447383680712310759[51] = 0;
   out_4447383680712310759[52] = 0;
   out_4447383680712310759[53] = 1;
}
void h_13(double *state, double *unused, double *out_756955009987038658) {
   out_756955009987038658[0] = state[3];
   out_756955009987038658[1] = state[4];
   out_756955009987038658[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2549007432451327764) {
   out_2549007432451327764[0] = 0;
   out_2549007432451327764[1] = 0;
   out_2549007432451327764[2] = 0;
   out_2549007432451327764[3] = 1;
   out_2549007432451327764[4] = 0;
   out_2549007432451327764[5] = 0;
   out_2549007432451327764[6] = 0;
   out_2549007432451327764[7] = 0;
   out_2549007432451327764[8] = 0;
   out_2549007432451327764[9] = 0;
   out_2549007432451327764[10] = 0;
   out_2549007432451327764[11] = 0;
   out_2549007432451327764[12] = 0;
   out_2549007432451327764[13] = 0;
   out_2549007432451327764[14] = 0;
   out_2549007432451327764[15] = 0;
   out_2549007432451327764[16] = 0;
   out_2549007432451327764[17] = 0;
   out_2549007432451327764[18] = 0;
   out_2549007432451327764[19] = 0;
   out_2549007432451327764[20] = 0;
   out_2549007432451327764[21] = 0;
   out_2549007432451327764[22] = 1;
   out_2549007432451327764[23] = 0;
   out_2549007432451327764[24] = 0;
   out_2549007432451327764[25] = 0;
   out_2549007432451327764[26] = 0;
   out_2549007432451327764[27] = 0;
   out_2549007432451327764[28] = 0;
   out_2549007432451327764[29] = 0;
   out_2549007432451327764[30] = 0;
   out_2549007432451327764[31] = 0;
   out_2549007432451327764[32] = 0;
   out_2549007432451327764[33] = 0;
   out_2549007432451327764[34] = 0;
   out_2549007432451327764[35] = 0;
   out_2549007432451327764[36] = 0;
   out_2549007432451327764[37] = 0;
   out_2549007432451327764[38] = 0;
   out_2549007432451327764[39] = 0;
   out_2549007432451327764[40] = 0;
   out_2549007432451327764[41] = 1;
   out_2549007432451327764[42] = 0;
   out_2549007432451327764[43] = 0;
   out_2549007432451327764[44] = 0;
   out_2549007432451327764[45] = 0;
   out_2549007432451327764[46] = 0;
   out_2549007432451327764[47] = 0;
   out_2549007432451327764[48] = 0;
   out_2549007432451327764[49] = 0;
   out_2549007432451327764[50] = 0;
   out_2549007432451327764[51] = 0;
   out_2549007432451327764[52] = 0;
   out_2549007432451327764[53] = 0;
}
void h_14(double *state, double *unused, double *out_3752798373710015968) {
   out_3752798373710015968[0] = state[6];
   out_3752798373710015968[1] = state[7];
   out_3752798373710015968[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1798040401444176036) {
   out_1798040401444176036[0] = 0;
   out_1798040401444176036[1] = 0;
   out_1798040401444176036[2] = 0;
   out_1798040401444176036[3] = 0;
   out_1798040401444176036[4] = 0;
   out_1798040401444176036[5] = 0;
   out_1798040401444176036[6] = 1;
   out_1798040401444176036[7] = 0;
   out_1798040401444176036[8] = 0;
   out_1798040401444176036[9] = 0;
   out_1798040401444176036[10] = 0;
   out_1798040401444176036[11] = 0;
   out_1798040401444176036[12] = 0;
   out_1798040401444176036[13] = 0;
   out_1798040401444176036[14] = 0;
   out_1798040401444176036[15] = 0;
   out_1798040401444176036[16] = 0;
   out_1798040401444176036[17] = 0;
   out_1798040401444176036[18] = 0;
   out_1798040401444176036[19] = 0;
   out_1798040401444176036[20] = 0;
   out_1798040401444176036[21] = 0;
   out_1798040401444176036[22] = 0;
   out_1798040401444176036[23] = 0;
   out_1798040401444176036[24] = 0;
   out_1798040401444176036[25] = 1;
   out_1798040401444176036[26] = 0;
   out_1798040401444176036[27] = 0;
   out_1798040401444176036[28] = 0;
   out_1798040401444176036[29] = 0;
   out_1798040401444176036[30] = 0;
   out_1798040401444176036[31] = 0;
   out_1798040401444176036[32] = 0;
   out_1798040401444176036[33] = 0;
   out_1798040401444176036[34] = 0;
   out_1798040401444176036[35] = 0;
   out_1798040401444176036[36] = 0;
   out_1798040401444176036[37] = 0;
   out_1798040401444176036[38] = 0;
   out_1798040401444176036[39] = 0;
   out_1798040401444176036[40] = 0;
   out_1798040401444176036[41] = 0;
   out_1798040401444176036[42] = 0;
   out_1798040401444176036[43] = 0;
   out_1798040401444176036[44] = 1;
   out_1798040401444176036[45] = 0;
   out_1798040401444176036[46] = 0;
   out_1798040401444176036[47] = 0;
   out_1798040401444176036[48] = 0;
   out_1798040401444176036[49] = 0;
   out_1798040401444176036[50] = 0;
   out_1798040401444176036[51] = 0;
   out_1798040401444176036[52] = 0;
   out_1798040401444176036[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6053087006272086738) {
  err_fun(nom_x, delta_x, out_6053087006272086738);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1848428975880805561) {
  inv_err_fun(nom_x, true_x, out_1848428975880805561);
}
void pose_H_mod_fun(double *state, double *out_3183080408274160777) {
  H_mod_fun(state, out_3183080408274160777);
}
void pose_f_fun(double *state, double dt, double *out_2001410838433046702) {
  f_fun(state,  dt, out_2001410838433046702);
}
void pose_F_fun(double *state, double dt, double *out_2415085859123987111) {
  F_fun(state,  dt, out_2415085859123987111);
}
void pose_h_4(double *state, double *unused, double *out_7740735704804213850) {
  h_4(state, unused, out_7740735704804213850);
}
void pose_H_4(double *state, double *unused, double *out_5761281257783660565) {
  H_4(state, unused, out_5761281257783660565);
}
void pose_h_10(double *state, double *unused, double *out_97048509807628744) {
  h_10(state, unused, out_97048509807628744);
}
void pose_H_10(double *state, double *unused, double *out_4447383680712310759) {
  H_10(state, unused, out_4447383680712310759);
}
void pose_h_13(double *state, double *unused, double *out_756955009987038658) {
  h_13(state, unused, out_756955009987038658);
}
void pose_H_13(double *state, double *unused, double *out_2549007432451327764) {
  H_13(state, unused, out_2549007432451327764);
}
void pose_h_14(double *state, double *unused, double *out_3752798373710015968) {
  h_14(state, unused, out_3752798373710015968);
}
void pose_H_14(double *state, double *unused, double *out_1798040401444176036) {
  H_14(state, unused, out_1798040401444176036);
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
