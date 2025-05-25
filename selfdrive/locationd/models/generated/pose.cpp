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
void err_fun(double *nom_x, double *delta_x, double *out_3885858244012813024) {
   out_3885858244012813024[0] = delta_x[0] + nom_x[0];
   out_3885858244012813024[1] = delta_x[1] + nom_x[1];
   out_3885858244012813024[2] = delta_x[2] + nom_x[2];
   out_3885858244012813024[3] = delta_x[3] + nom_x[3];
   out_3885858244012813024[4] = delta_x[4] + nom_x[4];
   out_3885858244012813024[5] = delta_x[5] + nom_x[5];
   out_3885858244012813024[6] = delta_x[6] + nom_x[6];
   out_3885858244012813024[7] = delta_x[7] + nom_x[7];
   out_3885858244012813024[8] = delta_x[8] + nom_x[8];
   out_3885858244012813024[9] = delta_x[9] + nom_x[9];
   out_3885858244012813024[10] = delta_x[10] + nom_x[10];
   out_3885858244012813024[11] = delta_x[11] + nom_x[11];
   out_3885858244012813024[12] = delta_x[12] + nom_x[12];
   out_3885858244012813024[13] = delta_x[13] + nom_x[13];
   out_3885858244012813024[14] = delta_x[14] + nom_x[14];
   out_3885858244012813024[15] = delta_x[15] + nom_x[15];
   out_3885858244012813024[16] = delta_x[16] + nom_x[16];
   out_3885858244012813024[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7758055863153927741) {
   out_7758055863153927741[0] = -nom_x[0] + true_x[0];
   out_7758055863153927741[1] = -nom_x[1] + true_x[1];
   out_7758055863153927741[2] = -nom_x[2] + true_x[2];
   out_7758055863153927741[3] = -nom_x[3] + true_x[3];
   out_7758055863153927741[4] = -nom_x[4] + true_x[4];
   out_7758055863153927741[5] = -nom_x[5] + true_x[5];
   out_7758055863153927741[6] = -nom_x[6] + true_x[6];
   out_7758055863153927741[7] = -nom_x[7] + true_x[7];
   out_7758055863153927741[8] = -nom_x[8] + true_x[8];
   out_7758055863153927741[9] = -nom_x[9] + true_x[9];
   out_7758055863153927741[10] = -nom_x[10] + true_x[10];
   out_7758055863153927741[11] = -nom_x[11] + true_x[11];
   out_7758055863153927741[12] = -nom_x[12] + true_x[12];
   out_7758055863153927741[13] = -nom_x[13] + true_x[13];
   out_7758055863153927741[14] = -nom_x[14] + true_x[14];
   out_7758055863153927741[15] = -nom_x[15] + true_x[15];
   out_7758055863153927741[16] = -nom_x[16] + true_x[16];
   out_7758055863153927741[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4317949509398023693) {
   out_4317949509398023693[0] = 1.0;
   out_4317949509398023693[1] = 0.0;
   out_4317949509398023693[2] = 0.0;
   out_4317949509398023693[3] = 0.0;
   out_4317949509398023693[4] = 0.0;
   out_4317949509398023693[5] = 0.0;
   out_4317949509398023693[6] = 0.0;
   out_4317949509398023693[7] = 0.0;
   out_4317949509398023693[8] = 0.0;
   out_4317949509398023693[9] = 0.0;
   out_4317949509398023693[10] = 0.0;
   out_4317949509398023693[11] = 0.0;
   out_4317949509398023693[12] = 0.0;
   out_4317949509398023693[13] = 0.0;
   out_4317949509398023693[14] = 0.0;
   out_4317949509398023693[15] = 0.0;
   out_4317949509398023693[16] = 0.0;
   out_4317949509398023693[17] = 0.0;
   out_4317949509398023693[18] = 0.0;
   out_4317949509398023693[19] = 1.0;
   out_4317949509398023693[20] = 0.0;
   out_4317949509398023693[21] = 0.0;
   out_4317949509398023693[22] = 0.0;
   out_4317949509398023693[23] = 0.0;
   out_4317949509398023693[24] = 0.0;
   out_4317949509398023693[25] = 0.0;
   out_4317949509398023693[26] = 0.0;
   out_4317949509398023693[27] = 0.0;
   out_4317949509398023693[28] = 0.0;
   out_4317949509398023693[29] = 0.0;
   out_4317949509398023693[30] = 0.0;
   out_4317949509398023693[31] = 0.0;
   out_4317949509398023693[32] = 0.0;
   out_4317949509398023693[33] = 0.0;
   out_4317949509398023693[34] = 0.0;
   out_4317949509398023693[35] = 0.0;
   out_4317949509398023693[36] = 0.0;
   out_4317949509398023693[37] = 0.0;
   out_4317949509398023693[38] = 1.0;
   out_4317949509398023693[39] = 0.0;
   out_4317949509398023693[40] = 0.0;
   out_4317949509398023693[41] = 0.0;
   out_4317949509398023693[42] = 0.0;
   out_4317949509398023693[43] = 0.0;
   out_4317949509398023693[44] = 0.0;
   out_4317949509398023693[45] = 0.0;
   out_4317949509398023693[46] = 0.0;
   out_4317949509398023693[47] = 0.0;
   out_4317949509398023693[48] = 0.0;
   out_4317949509398023693[49] = 0.0;
   out_4317949509398023693[50] = 0.0;
   out_4317949509398023693[51] = 0.0;
   out_4317949509398023693[52] = 0.0;
   out_4317949509398023693[53] = 0.0;
   out_4317949509398023693[54] = 0.0;
   out_4317949509398023693[55] = 0.0;
   out_4317949509398023693[56] = 0.0;
   out_4317949509398023693[57] = 1.0;
   out_4317949509398023693[58] = 0.0;
   out_4317949509398023693[59] = 0.0;
   out_4317949509398023693[60] = 0.0;
   out_4317949509398023693[61] = 0.0;
   out_4317949509398023693[62] = 0.0;
   out_4317949509398023693[63] = 0.0;
   out_4317949509398023693[64] = 0.0;
   out_4317949509398023693[65] = 0.0;
   out_4317949509398023693[66] = 0.0;
   out_4317949509398023693[67] = 0.0;
   out_4317949509398023693[68] = 0.0;
   out_4317949509398023693[69] = 0.0;
   out_4317949509398023693[70] = 0.0;
   out_4317949509398023693[71] = 0.0;
   out_4317949509398023693[72] = 0.0;
   out_4317949509398023693[73] = 0.0;
   out_4317949509398023693[74] = 0.0;
   out_4317949509398023693[75] = 0.0;
   out_4317949509398023693[76] = 1.0;
   out_4317949509398023693[77] = 0.0;
   out_4317949509398023693[78] = 0.0;
   out_4317949509398023693[79] = 0.0;
   out_4317949509398023693[80] = 0.0;
   out_4317949509398023693[81] = 0.0;
   out_4317949509398023693[82] = 0.0;
   out_4317949509398023693[83] = 0.0;
   out_4317949509398023693[84] = 0.0;
   out_4317949509398023693[85] = 0.0;
   out_4317949509398023693[86] = 0.0;
   out_4317949509398023693[87] = 0.0;
   out_4317949509398023693[88] = 0.0;
   out_4317949509398023693[89] = 0.0;
   out_4317949509398023693[90] = 0.0;
   out_4317949509398023693[91] = 0.0;
   out_4317949509398023693[92] = 0.0;
   out_4317949509398023693[93] = 0.0;
   out_4317949509398023693[94] = 0.0;
   out_4317949509398023693[95] = 1.0;
   out_4317949509398023693[96] = 0.0;
   out_4317949509398023693[97] = 0.0;
   out_4317949509398023693[98] = 0.0;
   out_4317949509398023693[99] = 0.0;
   out_4317949509398023693[100] = 0.0;
   out_4317949509398023693[101] = 0.0;
   out_4317949509398023693[102] = 0.0;
   out_4317949509398023693[103] = 0.0;
   out_4317949509398023693[104] = 0.0;
   out_4317949509398023693[105] = 0.0;
   out_4317949509398023693[106] = 0.0;
   out_4317949509398023693[107] = 0.0;
   out_4317949509398023693[108] = 0.0;
   out_4317949509398023693[109] = 0.0;
   out_4317949509398023693[110] = 0.0;
   out_4317949509398023693[111] = 0.0;
   out_4317949509398023693[112] = 0.0;
   out_4317949509398023693[113] = 0.0;
   out_4317949509398023693[114] = 1.0;
   out_4317949509398023693[115] = 0.0;
   out_4317949509398023693[116] = 0.0;
   out_4317949509398023693[117] = 0.0;
   out_4317949509398023693[118] = 0.0;
   out_4317949509398023693[119] = 0.0;
   out_4317949509398023693[120] = 0.0;
   out_4317949509398023693[121] = 0.0;
   out_4317949509398023693[122] = 0.0;
   out_4317949509398023693[123] = 0.0;
   out_4317949509398023693[124] = 0.0;
   out_4317949509398023693[125] = 0.0;
   out_4317949509398023693[126] = 0.0;
   out_4317949509398023693[127] = 0.0;
   out_4317949509398023693[128] = 0.0;
   out_4317949509398023693[129] = 0.0;
   out_4317949509398023693[130] = 0.0;
   out_4317949509398023693[131] = 0.0;
   out_4317949509398023693[132] = 0.0;
   out_4317949509398023693[133] = 1.0;
   out_4317949509398023693[134] = 0.0;
   out_4317949509398023693[135] = 0.0;
   out_4317949509398023693[136] = 0.0;
   out_4317949509398023693[137] = 0.0;
   out_4317949509398023693[138] = 0.0;
   out_4317949509398023693[139] = 0.0;
   out_4317949509398023693[140] = 0.0;
   out_4317949509398023693[141] = 0.0;
   out_4317949509398023693[142] = 0.0;
   out_4317949509398023693[143] = 0.0;
   out_4317949509398023693[144] = 0.0;
   out_4317949509398023693[145] = 0.0;
   out_4317949509398023693[146] = 0.0;
   out_4317949509398023693[147] = 0.0;
   out_4317949509398023693[148] = 0.0;
   out_4317949509398023693[149] = 0.0;
   out_4317949509398023693[150] = 0.0;
   out_4317949509398023693[151] = 0.0;
   out_4317949509398023693[152] = 1.0;
   out_4317949509398023693[153] = 0.0;
   out_4317949509398023693[154] = 0.0;
   out_4317949509398023693[155] = 0.0;
   out_4317949509398023693[156] = 0.0;
   out_4317949509398023693[157] = 0.0;
   out_4317949509398023693[158] = 0.0;
   out_4317949509398023693[159] = 0.0;
   out_4317949509398023693[160] = 0.0;
   out_4317949509398023693[161] = 0.0;
   out_4317949509398023693[162] = 0.0;
   out_4317949509398023693[163] = 0.0;
   out_4317949509398023693[164] = 0.0;
   out_4317949509398023693[165] = 0.0;
   out_4317949509398023693[166] = 0.0;
   out_4317949509398023693[167] = 0.0;
   out_4317949509398023693[168] = 0.0;
   out_4317949509398023693[169] = 0.0;
   out_4317949509398023693[170] = 0.0;
   out_4317949509398023693[171] = 1.0;
   out_4317949509398023693[172] = 0.0;
   out_4317949509398023693[173] = 0.0;
   out_4317949509398023693[174] = 0.0;
   out_4317949509398023693[175] = 0.0;
   out_4317949509398023693[176] = 0.0;
   out_4317949509398023693[177] = 0.0;
   out_4317949509398023693[178] = 0.0;
   out_4317949509398023693[179] = 0.0;
   out_4317949509398023693[180] = 0.0;
   out_4317949509398023693[181] = 0.0;
   out_4317949509398023693[182] = 0.0;
   out_4317949509398023693[183] = 0.0;
   out_4317949509398023693[184] = 0.0;
   out_4317949509398023693[185] = 0.0;
   out_4317949509398023693[186] = 0.0;
   out_4317949509398023693[187] = 0.0;
   out_4317949509398023693[188] = 0.0;
   out_4317949509398023693[189] = 0.0;
   out_4317949509398023693[190] = 1.0;
   out_4317949509398023693[191] = 0.0;
   out_4317949509398023693[192] = 0.0;
   out_4317949509398023693[193] = 0.0;
   out_4317949509398023693[194] = 0.0;
   out_4317949509398023693[195] = 0.0;
   out_4317949509398023693[196] = 0.0;
   out_4317949509398023693[197] = 0.0;
   out_4317949509398023693[198] = 0.0;
   out_4317949509398023693[199] = 0.0;
   out_4317949509398023693[200] = 0.0;
   out_4317949509398023693[201] = 0.0;
   out_4317949509398023693[202] = 0.0;
   out_4317949509398023693[203] = 0.0;
   out_4317949509398023693[204] = 0.0;
   out_4317949509398023693[205] = 0.0;
   out_4317949509398023693[206] = 0.0;
   out_4317949509398023693[207] = 0.0;
   out_4317949509398023693[208] = 0.0;
   out_4317949509398023693[209] = 1.0;
   out_4317949509398023693[210] = 0.0;
   out_4317949509398023693[211] = 0.0;
   out_4317949509398023693[212] = 0.0;
   out_4317949509398023693[213] = 0.0;
   out_4317949509398023693[214] = 0.0;
   out_4317949509398023693[215] = 0.0;
   out_4317949509398023693[216] = 0.0;
   out_4317949509398023693[217] = 0.0;
   out_4317949509398023693[218] = 0.0;
   out_4317949509398023693[219] = 0.0;
   out_4317949509398023693[220] = 0.0;
   out_4317949509398023693[221] = 0.0;
   out_4317949509398023693[222] = 0.0;
   out_4317949509398023693[223] = 0.0;
   out_4317949509398023693[224] = 0.0;
   out_4317949509398023693[225] = 0.0;
   out_4317949509398023693[226] = 0.0;
   out_4317949509398023693[227] = 0.0;
   out_4317949509398023693[228] = 1.0;
   out_4317949509398023693[229] = 0.0;
   out_4317949509398023693[230] = 0.0;
   out_4317949509398023693[231] = 0.0;
   out_4317949509398023693[232] = 0.0;
   out_4317949509398023693[233] = 0.0;
   out_4317949509398023693[234] = 0.0;
   out_4317949509398023693[235] = 0.0;
   out_4317949509398023693[236] = 0.0;
   out_4317949509398023693[237] = 0.0;
   out_4317949509398023693[238] = 0.0;
   out_4317949509398023693[239] = 0.0;
   out_4317949509398023693[240] = 0.0;
   out_4317949509398023693[241] = 0.0;
   out_4317949509398023693[242] = 0.0;
   out_4317949509398023693[243] = 0.0;
   out_4317949509398023693[244] = 0.0;
   out_4317949509398023693[245] = 0.0;
   out_4317949509398023693[246] = 0.0;
   out_4317949509398023693[247] = 1.0;
   out_4317949509398023693[248] = 0.0;
   out_4317949509398023693[249] = 0.0;
   out_4317949509398023693[250] = 0.0;
   out_4317949509398023693[251] = 0.0;
   out_4317949509398023693[252] = 0.0;
   out_4317949509398023693[253] = 0.0;
   out_4317949509398023693[254] = 0.0;
   out_4317949509398023693[255] = 0.0;
   out_4317949509398023693[256] = 0.0;
   out_4317949509398023693[257] = 0.0;
   out_4317949509398023693[258] = 0.0;
   out_4317949509398023693[259] = 0.0;
   out_4317949509398023693[260] = 0.0;
   out_4317949509398023693[261] = 0.0;
   out_4317949509398023693[262] = 0.0;
   out_4317949509398023693[263] = 0.0;
   out_4317949509398023693[264] = 0.0;
   out_4317949509398023693[265] = 0.0;
   out_4317949509398023693[266] = 1.0;
   out_4317949509398023693[267] = 0.0;
   out_4317949509398023693[268] = 0.0;
   out_4317949509398023693[269] = 0.0;
   out_4317949509398023693[270] = 0.0;
   out_4317949509398023693[271] = 0.0;
   out_4317949509398023693[272] = 0.0;
   out_4317949509398023693[273] = 0.0;
   out_4317949509398023693[274] = 0.0;
   out_4317949509398023693[275] = 0.0;
   out_4317949509398023693[276] = 0.0;
   out_4317949509398023693[277] = 0.0;
   out_4317949509398023693[278] = 0.0;
   out_4317949509398023693[279] = 0.0;
   out_4317949509398023693[280] = 0.0;
   out_4317949509398023693[281] = 0.0;
   out_4317949509398023693[282] = 0.0;
   out_4317949509398023693[283] = 0.0;
   out_4317949509398023693[284] = 0.0;
   out_4317949509398023693[285] = 1.0;
   out_4317949509398023693[286] = 0.0;
   out_4317949509398023693[287] = 0.0;
   out_4317949509398023693[288] = 0.0;
   out_4317949509398023693[289] = 0.0;
   out_4317949509398023693[290] = 0.0;
   out_4317949509398023693[291] = 0.0;
   out_4317949509398023693[292] = 0.0;
   out_4317949509398023693[293] = 0.0;
   out_4317949509398023693[294] = 0.0;
   out_4317949509398023693[295] = 0.0;
   out_4317949509398023693[296] = 0.0;
   out_4317949509398023693[297] = 0.0;
   out_4317949509398023693[298] = 0.0;
   out_4317949509398023693[299] = 0.0;
   out_4317949509398023693[300] = 0.0;
   out_4317949509398023693[301] = 0.0;
   out_4317949509398023693[302] = 0.0;
   out_4317949509398023693[303] = 0.0;
   out_4317949509398023693[304] = 1.0;
   out_4317949509398023693[305] = 0.0;
   out_4317949509398023693[306] = 0.0;
   out_4317949509398023693[307] = 0.0;
   out_4317949509398023693[308] = 0.0;
   out_4317949509398023693[309] = 0.0;
   out_4317949509398023693[310] = 0.0;
   out_4317949509398023693[311] = 0.0;
   out_4317949509398023693[312] = 0.0;
   out_4317949509398023693[313] = 0.0;
   out_4317949509398023693[314] = 0.0;
   out_4317949509398023693[315] = 0.0;
   out_4317949509398023693[316] = 0.0;
   out_4317949509398023693[317] = 0.0;
   out_4317949509398023693[318] = 0.0;
   out_4317949509398023693[319] = 0.0;
   out_4317949509398023693[320] = 0.0;
   out_4317949509398023693[321] = 0.0;
   out_4317949509398023693[322] = 0.0;
   out_4317949509398023693[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8188623410399122820) {
   out_8188623410399122820[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8188623410399122820[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8188623410399122820[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8188623410399122820[3] = dt*state[12] + state[3];
   out_8188623410399122820[4] = dt*state[13] + state[4];
   out_8188623410399122820[5] = dt*state[14] + state[5];
   out_8188623410399122820[6] = state[6];
   out_8188623410399122820[7] = state[7];
   out_8188623410399122820[8] = state[8];
   out_8188623410399122820[9] = state[9];
   out_8188623410399122820[10] = state[10];
   out_8188623410399122820[11] = state[11];
   out_8188623410399122820[12] = state[12];
   out_8188623410399122820[13] = state[13];
   out_8188623410399122820[14] = state[14];
   out_8188623410399122820[15] = state[15];
   out_8188623410399122820[16] = state[16];
   out_8188623410399122820[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5523207584579487610) {
   out_5523207584579487610[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5523207584579487610[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5523207584579487610[2] = 0;
   out_5523207584579487610[3] = 0;
   out_5523207584579487610[4] = 0;
   out_5523207584579487610[5] = 0;
   out_5523207584579487610[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5523207584579487610[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5523207584579487610[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5523207584579487610[9] = 0;
   out_5523207584579487610[10] = 0;
   out_5523207584579487610[11] = 0;
   out_5523207584579487610[12] = 0;
   out_5523207584579487610[13] = 0;
   out_5523207584579487610[14] = 0;
   out_5523207584579487610[15] = 0;
   out_5523207584579487610[16] = 0;
   out_5523207584579487610[17] = 0;
   out_5523207584579487610[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5523207584579487610[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5523207584579487610[20] = 0;
   out_5523207584579487610[21] = 0;
   out_5523207584579487610[22] = 0;
   out_5523207584579487610[23] = 0;
   out_5523207584579487610[24] = 0;
   out_5523207584579487610[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5523207584579487610[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5523207584579487610[27] = 0;
   out_5523207584579487610[28] = 0;
   out_5523207584579487610[29] = 0;
   out_5523207584579487610[30] = 0;
   out_5523207584579487610[31] = 0;
   out_5523207584579487610[32] = 0;
   out_5523207584579487610[33] = 0;
   out_5523207584579487610[34] = 0;
   out_5523207584579487610[35] = 0;
   out_5523207584579487610[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5523207584579487610[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5523207584579487610[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5523207584579487610[39] = 0;
   out_5523207584579487610[40] = 0;
   out_5523207584579487610[41] = 0;
   out_5523207584579487610[42] = 0;
   out_5523207584579487610[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5523207584579487610[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5523207584579487610[45] = 0;
   out_5523207584579487610[46] = 0;
   out_5523207584579487610[47] = 0;
   out_5523207584579487610[48] = 0;
   out_5523207584579487610[49] = 0;
   out_5523207584579487610[50] = 0;
   out_5523207584579487610[51] = 0;
   out_5523207584579487610[52] = 0;
   out_5523207584579487610[53] = 0;
   out_5523207584579487610[54] = 0;
   out_5523207584579487610[55] = 0;
   out_5523207584579487610[56] = 0;
   out_5523207584579487610[57] = 1;
   out_5523207584579487610[58] = 0;
   out_5523207584579487610[59] = 0;
   out_5523207584579487610[60] = 0;
   out_5523207584579487610[61] = 0;
   out_5523207584579487610[62] = 0;
   out_5523207584579487610[63] = 0;
   out_5523207584579487610[64] = 0;
   out_5523207584579487610[65] = 0;
   out_5523207584579487610[66] = dt;
   out_5523207584579487610[67] = 0;
   out_5523207584579487610[68] = 0;
   out_5523207584579487610[69] = 0;
   out_5523207584579487610[70] = 0;
   out_5523207584579487610[71] = 0;
   out_5523207584579487610[72] = 0;
   out_5523207584579487610[73] = 0;
   out_5523207584579487610[74] = 0;
   out_5523207584579487610[75] = 0;
   out_5523207584579487610[76] = 1;
   out_5523207584579487610[77] = 0;
   out_5523207584579487610[78] = 0;
   out_5523207584579487610[79] = 0;
   out_5523207584579487610[80] = 0;
   out_5523207584579487610[81] = 0;
   out_5523207584579487610[82] = 0;
   out_5523207584579487610[83] = 0;
   out_5523207584579487610[84] = 0;
   out_5523207584579487610[85] = dt;
   out_5523207584579487610[86] = 0;
   out_5523207584579487610[87] = 0;
   out_5523207584579487610[88] = 0;
   out_5523207584579487610[89] = 0;
   out_5523207584579487610[90] = 0;
   out_5523207584579487610[91] = 0;
   out_5523207584579487610[92] = 0;
   out_5523207584579487610[93] = 0;
   out_5523207584579487610[94] = 0;
   out_5523207584579487610[95] = 1;
   out_5523207584579487610[96] = 0;
   out_5523207584579487610[97] = 0;
   out_5523207584579487610[98] = 0;
   out_5523207584579487610[99] = 0;
   out_5523207584579487610[100] = 0;
   out_5523207584579487610[101] = 0;
   out_5523207584579487610[102] = 0;
   out_5523207584579487610[103] = 0;
   out_5523207584579487610[104] = dt;
   out_5523207584579487610[105] = 0;
   out_5523207584579487610[106] = 0;
   out_5523207584579487610[107] = 0;
   out_5523207584579487610[108] = 0;
   out_5523207584579487610[109] = 0;
   out_5523207584579487610[110] = 0;
   out_5523207584579487610[111] = 0;
   out_5523207584579487610[112] = 0;
   out_5523207584579487610[113] = 0;
   out_5523207584579487610[114] = 1;
   out_5523207584579487610[115] = 0;
   out_5523207584579487610[116] = 0;
   out_5523207584579487610[117] = 0;
   out_5523207584579487610[118] = 0;
   out_5523207584579487610[119] = 0;
   out_5523207584579487610[120] = 0;
   out_5523207584579487610[121] = 0;
   out_5523207584579487610[122] = 0;
   out_5523207584579487610[123] = 0;
   out_5523207584579487610[124] = 0;
   out_5523207584579487610[125] = 0;
   out_5523207584579487610[126] = 0;
   out_5523207584579487610[127] = 0;
   out_5523207584579487610[128] = 0;
   out_5523207584579487610[129] = 0;
   out_5523207584579487610[130] = 0;
   out_5523207584579487610[131] = 0;
   out_5523207584579487610[132] = 0;
   out_5523207584579487610[133] = 1;
   out_5523207584579487610[134] = 0;
   out_5523207584579487610[135] = 0;
   out_5523207584579487610[136] = 0;
   out_5523207584579487610[137] = 0;
   out_5523207584579487610[138] = 0;
   out_5523207584579487610[139] = 0;
   out_5523207584579487610[140] = 0;
   out_5523207584579487610[141] = 0;
   out_5523207584579487610[142] = 0;
   out_5523207584579487610[143] = 0;
   out_5523207584579487610[144] = 0;
   out_5523207584579487610[145] = 0;
   out_5523207584579487610[146] = 0;
   out_5523207584579487610[147] = 0;
   out_5523207584579487610[148] = 0;
   out_5523207584579487610[149] = 0;
   out_5523207584579487610[150] = 0;
   out_5523207584579487610[151] = 0;
   out_5523207584579487610[152] = 1;
   out_5523207584579487610[153] = 0;
   out_5523207584579487610[154] = 0;
   out_5523207584579487610[155] = 0;
   out_5523207584579487610[156] = 0;
   out_5523207584579487610[157] = 0;
   out_5523207584579487610[158] = 0;
   out_5523207584579487610[159] = 0;
   out_5523207584579487610[160] = 0;
   out_5523207584579487610[161] = 0;
   out_5523207584579487610[162] = 0;
   out_5523207584579487610[163] = 0;
   out_5523207584579487610[164] = 0;
   out_5523207584579487610[165] = 0;
   out_5523207584579487610[166] = 0;
   out_5523207584579487610[167] = 0;
   out_5523207584579487610[168] = 0;
   out_5523207584579487610[169] = 0;
   out_5523207584579487610[170] = 0;
   out_5523207584579487610[171] = 1;
   out_5523207584579487610[172] = 0;
   out_5523207584579487610[173] = 0;
   out_5523207584579487610[174] = 0;
   out_5523207584579487610[175] = 0;
   out_5523207584579487610[176] = 0;
   out_5523207584579487610[177] = 0;
   out_5523207584579487610[178] = 0;
   out_5523207584579487610[179] = 0;
   out_5523207584579487610[180] = 0;
   out_5523207584579487610[181] = 0;
   out_5523207584579487610[182] = 0;
   out_5523207584579487610[183] = 0;
   out_5523207584579487610[184] = 0;
   out_5523207584579487610[185] = 0;
   out_5523207584579487610[186] = 0;
   out_5523207584579487610[187] = 0;
   out_5523207584579487610[188] = 0;
   out_5523207584579487610[189] = 0;
   out_5523207584579487610[190] = 1;
   out_5523207584579487610[191] = 0;
   out_5523207584579487610[192] = 0;
   out_5523207584579487610[193] = 0;
   out_5523207584579487610[194] = 0;
   out_5523207584579487610[195] = 0;
   out_5523207584579487610[196] = 0;
   out_5523207584579487610[197] = 0;
   out_5523207584579487610[198] = 0;
   out_5523207584579487610[199] = 0;
   out_5523207584579487610[200] = 0;
   out_5523207584579487610[201] = 0;
   out_5523207584579487610[202] = 0;
   out_5523207584579487610[203] = 0;
   out_5523207584579487610[204] = 0;
   out_5523207584579487610[205] = 0;
   out_5523207584579487610[206] = 0;
   out_5523207584579487610[207] = 0;
   out_5523207584579487610[208] = 0;
   out_5523207584579487610[209] = 1;
   out_5523207584579487610[210] = 0;
   out_5523207584579487610[211] = 0;
   out_5523207584579487610[212] = 0;
   out_5523207584579487610[213] = 0;
   out_5523207584579487610[214] = 0;
   out_5523207584579487610[215] = 0;
   out_5523207584579487610[216] = 0;
   out_5523207584579487610[217] = 0;
   out_5523207584579487610[218] = 0;
   out_5523207584579487610[219] = 0;
   out_5523207584579487610[220] = 0;
   out_5523207584579487610[221] = 0;
   out_5523207584579487610[222] = 0;
   out_5523207584579487610[223] = 0;
   out_5523207584579487610[224] = 0;
   out_5523207584579487610[225] = 0;
   out_5523207584579487610[226] = 0;
   out_5523207584579487610[227] = 0;
   out_5523207584579487610[228] = 1;
   out_5523207584579487610[229] = 0;
   out_5523207584579487610[230] = 0;
   out_5523207584579487610[231] = 0;
   out_5523207584579487610[232] = 0;
   out_5523207584579487610[233] = 0;
   out_5523207584579487610[234] = 0;
   out_5523207584579487610[235] = 0;
   out_5523207584579487610[236] = 0;
   out_5523207584579487610[237] = 0;
   out_5523207584579487610[238] = 0;
   out_5523207584579487610[239] = 0;
   out_5523207584579487610[240] = 0;
   out_5523207584579487610[241] = 0;
   out_5523207584579487610[242] = 0;
   out_5523207584579487610[243] = 0;
   out_5523207584579487610[244] = 0;
   out_5523207584579487610[245] = 0;
   out_5523207584579487610[246] = 0;
   out_5523207584579487610[247] = 1;
   out_5523207584579487610[248] = 0;
   out_5523207584579487610[249] = 0;
   out_5523207584579487610[250] = 0;
   out_5523207584579487610[251] = 0;
   out_5523207584579487610[252] = 0;
   out_5523207584579487610[253] = 0;
   out_5523207584579487610[254] = 0;
   out_5523207584579487610[255] = 0;
   out_5523207584579487610[256] = 0;
   out_5523207584579487610[257] = 0;
   out_5523207584579487610[258] = 0;
   out_5523207584579487610[259] = 0;
   out_5523207584579487610[260] = 0;
   out_5523207584579487610[261] = 0;
   out_5523207584579487610[262] = 0;
   out_5523207584579487610[263] = 0;
   out_5523207584579487610[264] = 0;
   out_5523207584579487610[265] = 0;
   out_5523207584579487610[266] = 1;
   out_5523207584579487610[267] = 0;
   out_5523207584579487610[268] = 0;
   out_5523207584579487610[269] = 0;
   out_5523207584579487610[270] = 0;
   out_5523207584579487610[271] = 0;
   out_5523207584579487610[272] = 0;
   out_5523207584579487610[273] = 0;
   out_5523207584579487610[274] = 0;
   out_5523207584579487610[275] = 0;
   out_5523207584579487610[276] = 0;
   out_5523207584579487610[277] = 0;
   out_5523207584579487610[278] = 0;
   out_5523207584579487610[279] = 0;
   out_5523207584579487610[280] = 0;
   out_5523207584579487610[281] = 0;
   out_5523207584579487610[282] = 0;
   out_5523207584579487610[283] = 0;
   out_5523207584579487610[284] = 0;
   out_5523207584579487610[285] = 1;
   out_5523207584579487610[286] = 0;
   out_5523207584579487610[287] = 0;
   out_5523207584579487610[288] = 0;
   out_5523207584579487610[289] = 0;
   out_5523207584579487610[290] = 0;
   out_5523207584579487610[291] = 0;
   out_5523207584579487610[292] = 0;
   out_5523207584579487610[293] = 0;
   out_5523207584579487610[294] = 0;
   out_5523207584579487610[295] = 0;
   out_5523207584579487610[296] = 0;
   out_5523207584579487610[297] = 0;
   out_5523207584579487610[298] = 0;
   out_5523207584579487610[299] = 0;
   out_5523207584579487610[300] = 0;
   out_5523207584579487610[301] = 0;
   out_5523207584579487610[302] = 0;
   out_5523207584579487610[303] = 0;
   out_5523207584579487610[304] = 1;
   out_5523207584579487610[305] = 0;
   out_5523207584579487610[306] = 0;
   out_5523207584579487610[307] = 0;
   out_5523207584579487610[308] = 0;
   out_5523207584579487610[309] = 0;
   out_5523207584579487610[310] = 0;
   out_5523207584579487610[311] = 0;
   out_5523207584579487610[312] = 0;
   out_5523207584579487610[313] = 0;
   out_5523207584579487610[314] = 0;
   out_5523207584579487610[315] = 0;
   out_5523207584579487610[316] = 0;
   out_5523207584579487610[317] = 0;
   out_5523207584579487610[318] = 0;
   out_5523207584579487610[319] = 0;
   out_5523207584579487610[320] = 0;
   out_5523207584579487610[321] = 0;
   out_5523207584579487610[322] = 0;
   out_5523207584579487610[323] = 1;
}
void h_4(double *state, double *unused, double *out_2098647727660446226) {
   out_2098647727660446226[0] = state[6] + state[9];
   out_2098647727660446226[1] = state[7] + state[10];
   out_2098647727660446226[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7592171588188972946) {
   out_7592171588188972946[0] = 0;
   out_7592171588188972946[1] = 0;
   out_7592171588188972946[2] = 0;
   out_7592171588188972946[3] = 0;
   out_7592171588188972946[4] = 0;
   out_7592171588188972946[5] = 0;
   out_7592171588188972946[6] = 1;
   out_7592171588188972946[7] = 0;
   out_7592171588188972946[8] = 0;
   out_7592171588188972946[9] = 1;
   out_7592171588188972946[10] = 0;
   out_7592171588188972946[11] = 0;
   out_7592171588188972946[12] = 0;
   out_7592171588188972946[13] = 0;
   out_7592171588188972946[14] = 0;
   out_7592171588188972946[15] = 0;
   out_7592171588188972946[16] = 0;
   out_7592171588188972946[17] = 0;
   out_7592171588188972946[18] = 0;
   out_7592171588188972946[19] = 0;
   out_7592171588188972946[20] = 0;
   out_7592171588188972946[21] = 0;
   out_7592171588188972946[22] = 0;
   out_7592171588188972946[23] = 0;
   out_7592171588188972946[24] = 0;
   out_7592171588188972946[25] = 1;
   out_7592171588188972946[26] = 0;
   out_7592171588188972946[27] = 0;
   out_7592171588188972946[28] = 1;
   out_7592171588188972946[29] = 0;
   out_7592171588188972946[30] = 0;
   out_7592171588188972946[31] = 0;
   out_7592171588188972946[32] = 0;
   out_7592171588188972946[33] = 0;
   out_7592171588188972946[34] = 0;
   out_7592171588188972946[35] = 0;
   out_7592171588188972946[36] = 0;
   out_7592171588188972946[37] = 0;
   out_7592171588188972946[38] = 0;
   out_7592171588188972946[39] = 0;
   out_7592171588188972946[40] = 0;
   out_7592171588188972946[41] = 0;
   out_7592171588188972946[42] = 0;
   out_7592171588188972946[43] = 0;
   out_7592171588188972946[44] = 1;
   out_7592171588188972946[45] = 0;
   out_7592171588188972946[46] = 0;
   out_7592171588188972946[47] = 1;
   out_7592171588188972946[48] = 0;
   out_7592171588188972946[49] = 0;
   out_7592171588188972946[50] = 0;
   out_7592171588188972946[51] = 0;
   out_7592171588188972946[52] = 0;
   out_7592171588188972946[53] = 0;
}
void h_10(double *state, double *unused, double *out_5052239660944612817) {
   out_5052239660944612817[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5052239660944612817[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5052239660944612817[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8850730047157910148) {
   out_8850730047157910148[0] = 0;
   out_8850730047157910148[1] = 9.8100000000000005*cos(state[1]);
   out_8850730047157910148[2] = 0;
   out_8850730047157910148[3] = 0;
   out_8850730047157910148[4] = -state[8];
   out_8850730047157910148[5] = state[7];
   out_8850730047157910148[6] = 0;
   out_8850730047157910148[7] = state[5];
   out_8850730047157910148[8] = -state[4];
   out_8850730047157910148[9] = 0;
   out_8850730047157910148[10] = 0;
   out_8850730047157910148[11] = 0;
   out_8850730047157910148[12] = 1;
   out_8850730047157910148[13] = 0;
   out_8850730047157910148[14] = 0;
   out_8850730047157910148[15] = 1;
   out_8850730047157910148[16] = 0;
   out_8850730047157910148[17] = 0;
   out_8850730047157910148[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8850730047157910148[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8850730047157910148[20] = 0;
   out_8850730047157910148[21] = state[8];
   out_8850730047157910148[22] = 0;
   out_8850730047157910148[23] = -state[6];
   out_8850730047157910148[24] = -state[5];
   out_8850730047157910148[25] = 0;
   out_8850730047157910148[26] = state[3];
   out_8850730047157910148[27] = 0;
   out_8850730047157910148[28] = 0;
   out_8850730047157910148[29] = 0;
   out_8850730047157910148[30] = 0;
   out_8850730047157910148[31] = 1;
   out_8850730047157910148[32] = 0;
   out_8850730047157910148[33] = 0;
   out_8850730047157910148[34] = 1;
   out_8850730047157910148[35] = 0;
   out_8850730047157910148[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8850730047157910148[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8850730047157910148[38] = 0;
   out_8850730047157910148[39] = -state[7];
   out_8850730047157910148[40] = state[6];
   out_8850730047157910148[41] = 0;
   out_8850730047157910148[42] = state[4];
   out_8850730047157910148[43] = -state[3];
   out_8850730047157910148[44] = 0;
   out_8850730047157910148[45] = 0;
   out_8850730047157910148[46] = 0;
   out_8850730047157910148[47] = 0;
   out_8850730047157910148[48] = 0;
   out_8850730047157910148[49] = 0;
   out_8850730047157910148[50] = 1;
   out_8850730047157910148[51] = 0;
   out_8850730047157910148[52] = 0;
   out_8850730047157910148[53] = 1;
}
void h_13(double *state, double *unused, double *out_6619314201641466470) {
   out_6619314201641466470[0] = state[3];
   out_6619314201641466470[1] = state[4];
   out_6619314201641466470[2] = state[5];
}
void H_13(double *state, double *unused, double *out_18459620127727983) {
   out_18459620127727983[0] = 0;
   out_18459620127727983[1] = 0;
   out_18459620127727983[2] = 0;
   out_18459620127727983[3] = 1;
   out_18459620127727983[4] = 0;
   out_18459620127727983[5] = 0;
   out_18459620127727983[6] = 0;
   out_18459620127727983[7] = 0;
   out_18459620127727983[8] = 0;
   out_18459620127727983[9] = 0;
   out_18459620127727983[10] = 0;
   out_18459620127727983[11] = 0;
   out_18459620127727983[12] = 0;
   out_18459620127727983[13] = 0;
   out_18459620127727983[14] = 0;
   out_18459620127727983[15] = 0;
   out_18459620127727983[16] = 0;
   out_18459620127727983[17] = 0;
   out_18459620127727983[18] = 0;
   out_18459620127727983[19] = 0;
   out_18459620127727983[20] = 0;
   out_18459620127727983[21] = 0;
   out_18459620127727983[22] = 1;
   out_18459620127727983[23] = 0;
   out_18459620127727983[24] = 0;
   out_18459620127727983[25] = 0;
   out_18459620127727983[26] = 0;
   out_18459620127727983[27] = 0;
   out_18459620127727983[28] = 0;
   out_18459620127727983[29] = 0;
   out_18459620127727983[30] = 0;
   out_18459620127727983[31] = 0;
   out_18459620127727983[32] = 0;
   out_18459620127727983[33] = 0;
   out_18459620127727983[34] = 0;
   out_18459620127727983[35] = 0;
   out_18459620127727983[36] = 0;
   out_18459620127727983[37] = 0;
   out_18459620127727983[38] = 0;
   out_18459620127727983[39] = 0;
   out_18459620127727983[40] = 0;
   out_18459620127727983[41] = 1;
   out_18459620127727983[42] = 0;
   out_18459620127727983[43] = 0;
   out_18459620127727983[44] = 0;
   out_18459620127727983[45] = 0;
   out_18459620127727983[46] = 0;
   out_18459620127727983[47] = 0;
   out_18459620127727983[48] = 0;
   out_18459620127727983[49] = 0;
   out_18459620127727983[50] = 0;
   out_18459620127727983[51] = 0;
   out_18459620127727983[52] = 0;
   out_18459620127727983[53] = 0;
}
void h_14(double *state, double *unused, double *out_1585921583011697059) {
   out_1585921583011697059[0] = state[6];
   out_1585921583011697059[1] = state[7];
   out_1585921583011697059[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3628930731849488417) {
   out_3628930731849488417[0] = 0;
   out_3628930731849488417[1] = 0;
   out_3628930731849488417[2] = 0;
   out_3628930731849488417[3] = 0;
   out_3628930731849488417[4] = 0;
   out_3628930731849488417[5] = 0;
   out_3628930731849488417[6] = 1;
   out_3628930731849488417[7] = 0;
   out_3628930731849488417[8] = 0;
   out_3628930731849488417[9] = 0;
   out_3628930731849488417[10] = 0;
   out_3628930731849488417[11] = 0;
   out_3628930731849488417[12] = 0;
   out_3628930731849488417[13] = 0;
   out_3628930731849488417[14] = 0;
   out_3628930731849488417[15] = 0;
   out_3628930731849488417[16] = 0;
   out_3628930731849488417[17] = 0;
   out_3628930731849488417[18] = 0;
   out_3628930731849488417[19] = 0;
   out_3628930731849488417[20] = 0;
   out_3628930731849488417[21] = 0;
   out_3628930731849488417[22] = 0;
   out_3628930731849488417[23] = 0;
   out_3628930731849488417[24] = 0;
   out_3628930731849488417[25] = 1;
   out_3628930731849488417[26] = 0;
   out_3628930731849488417[27] = 0;
   out_3628930731849488417[28] = 0;
   out_3628930731849488417[29] = 0;
   out_3628930731849488417[30] = 0;
   out_3628930731849488417[31] = 0;
   out_3628930731849488417[32] = 0;
   out_3628930731849488417[33] = 0;
   out_3628930731849488417[34] = 0;
   out_3628930731849488417[35] = 0;
   out_3628930731849488417[36] = 0;
   out_3628930731849488417[37] = 0;
   out_3628930731849488417[38] = 0;
   out_3628930731849488417[39] = 0;
   out_3628930731849488417[40] = 0;
   out_3628930731849488417[41] = 0;
   out_3628930731849488417[42] = 0;
   out_3628930731849488417[43] = 0;
   out_3628930731849488417[44] = 1;
   out_3628930731849488417[45] = 0;
   out_3628930731849488417[46] = 0;
   out_3628930731849488417[47] = 0;
   out_3628930731849488417[48] = 0;
   out_3628930731849488417[49] = 0;
   out_3628930731849488417[50] = 0;
   out_3628930731849488417[51] = 0;
   out_3628930731849488417[52] = 0;
   out_3628930731849488417[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3885858244012813024) {
  err_fun(nom_x, delta_x, out_3885858244012813024);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7758055863153927741) {
  inv_err_fun(nom_x, true_x, out_7758055863153927741);
}
void pose_H_mod_fun(double *state, double *out_4317949509398023693) {
  H_mod_fun(state, out_4317949509398023693);
}
void pose_f_fun(double *state, double dt, double *out_8188623410399122820) {
  f_fun(state,  dt, out_8188623410399122820);
}
void pose_F_fun(double *state, double dt, double *out_5523207584579487610) {
  F_fun(state,  dt, out_5523207584579487610);
}
void pose_h_4(double *state, double *unused, double *out_2098647727660446226) {
  h_4(state, unused, out_2098647727660446226);
}
void pose_H_4(double *state, double *unused, double *out_7592171588188972946) {
  H_4(state, unused, out_7592171588188972946);
}
void pose_h_10(double *state, double *unused, double *out_5052239660944612817) {
  h_10(state, unused, out_5052239660944612817);
}
void pose_H_10(double *state, double *unused, double *out_8850730047157910148) {
  H_10(state, unused, out_8850730047157910148);
}
void pose_h_13(double *state, double *unused, double *out_6619314201641466470) {
  h_13(state, unused, out_6619314201641466470);
}
void pose_H_13(double *state, double *unused, double *out_18459620127727983) {
  H_13(state, unused, out_18459620127727983);
}
void pose_h_14(double *state, double *unused, double *out_1585921583011697059) {
  h_14(state, unused, out_1585921583011697059);
}
void pose_H_14(double *state, double *unused, double *out_3628930731849488417) {
  H_14(state, unused, out_3628930731849488417);
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
