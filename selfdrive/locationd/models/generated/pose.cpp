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
void err_fun(double *nom_x, double *delta_x, double *out_793421623727173718) {
   out_793421623727173718[0] = delta_x[0] + nom_x[0];
   out_793421623727173718[1] = delta_x[1] + nom_x[1];
   out_793421623727173718[2] = delta_x[2] + nom_x[2];
   out_793421623727173718[3] = delta_x[3] + nom_x[3];
   out_793421623727173718[4] = delta_x[4] + nom_x[4];
   out_793421623727173718[5] = delta_x[5] + nom_x[5];
   out_793421623727173718[6] = delta_x[6] + nom_x[6];
   out_793421623727173718[7] = delta_x[7] + nom_x[7];
   out_793421623727173718[8] = delta_x[8] + nom_x[8];
   out_793421623727173718[9] = delta_x[9] + nom_x[9];
   out_793421623727173718[10] = delta_x[10] + nom_x[10];
   out_793421623727173718[11] = delta_x[11] + nom_x[11];
   out_793421623727173718[12] = delta_x[12] + nom_x[12];
   out_793421623727173718[13] = delta_x[13] + nom_x[13];
   out_793421623727173718[14] = delta_x[14] + nom_x[14];
   out_793421623727173718[15] = delta_x[15] + nom_x[15];
   out_793421623727173718[16] = delta_x[16] + nom_x[16];
   out_793421623727173718[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6937176692902514454) {
   out_6937176692902514454[0] = -nom_x[0] + true_x[0];
   out_6937176692902514454[1] = -nom_x[1] + true_x[1];
   out_6937176692902514454[2] = -nom_x[2] + true_x[2];
   out_6937176692902514454[3] = -nom_x[3] + true_x[3];
   out_6937176692902514454[4] = -nom_x[4] + true_x[4];
   out_6937176692902514454[5] = -nom_x[5] + true_x[5];
   out_6937176692902514454[6] = -nom_x[6] + true_x[6];
   out_6937176692902514454[7] = -nom_x[7] + true_x[7];
   out_6937176692902514454[8] = -nom_x[8] + true_x[8];
   out_6937176692902514454[9] = -nom_x[9] + true_x[9];
   out_6937176692902514454[10] = -nom_x[10] + true_x[10];
   out_6937176692902514454[11] = -nom_x[11] + true_x[11];
   out_6937176692902514454[12] = -nom_x[12] + true_x[12];
   out_6937176692902514454[13] = -nom_x[13] + true_x[13];
   out_6937176692902514454[14] = -nom_x[14] + true_x[14];
   out_6937176692902514454[15] = -nom_x[15] + true_x[15];
   out_6937176692902514454[16] = -nom_x[16] + true_x[16];
   out_6937176692902514454[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1217280767504544402) {
   out_1217280767504544402[0] = 1.0;
   out_1217280767504544402[1] = 0.0;
   out_1217280767504544402[2] = 0.0;
   out_1217280767504544402[3] = 0.0;
   out_1217280767504544402[4] = 0.0;
   out_1217280767504544402[5] = 0.0;
   out_1217280767504544402[6] = 0.0;
   out_1217280767504544402[7] = 0.0;
   out_1217280767504544402[8] = 0.0;
   out_1217280767504544402[9] = 0.0;
   out_1217280767504544402[10] = 0.0;
   out_1217280767504544402[11] = 0.0;
   out_1217280767504544402[12] = 0.0;
   out_1217280767504544402[13] = 0.0;
   out_1217280767504544402[14] = 0.0;
   out_1217280767504544402[15] = 0.0;
   out_1217280767504544402[16] = 0.0;
   out_1217280767504544402[17] = 0.0;
   out_1217280767504544402[18] = 0.0;
   out_1217280767504544402[19] = 1.0;
   out_1217280767504544402[20] = 0.0;
   out_1217280767504544402[21] = 0.0;
   out_1217280767504544402[22] = 0.0;
   out_1217280767504544402[23] = 0.0;
   out_1217280767504544402[24] = 0.0;
   out_1217280767504544402[25] = 0.0;
   out_1217280767504544402[26] = 0.0;
   out_1217280767504544402[27] = 0.0;
   out_1217280767504544402[28] = 0.0;
   out_1217280767504544402[29] = 0.0;
   out_1217280767504544402[30] = 0.0;
   out_1217280767504544402[31] = 0.0;
   out_1217280767504544402[32] = 0.0;
   out_1217280767504544402[33] = 0.0;
   out_1217280767504544402[34] = 0.0;
   out_1217280767504544402[35] = 0.0;
   out_1217280767504544402[36] = 0.0;
   out_1217280767504544402[37] = 0.0;
   out_1217280767504544402[38] = 1.0;
   out_1217280767504544402[39] = 0.0;
   out_1217280767504544402[40] = 0.0;
   out_1217280767504544402[41] = 0.0;
   out_1217280767504544402[42] = 0.0;
   out_1217280767504544402[43] = 0.0;
   out_1217280767504544402[44] = 0.0;
   out_1217280767504544402[45] = 0.0;
   out_1217280767504544402[46] = 0.0;
   out_1217280767504544402[47] = 0.0;
   out_1217280767504544402[48] = 0.0;
   out_1217280767504544402[49] = 0.0;
   out_1217280767504544402[50] = 0.0;
   out_1217280767504544402[51] = 0.0;
   out_1217280767504544402[52] = 0.0;
   out_1217280767504544402[53] = 0.0;
   out_1217280767504544402[54] = 0.0;
   out_1217280767504544402[55] = 0.0;
   out_1217280767504544402[56] = 0.0;
   out_1217280767504544402[57] = 1.0;
   out_1217280767504544402[58] = 0.0;
   out_1217280767504544402[59] = 0.0;
   out_1217280767504544402[60] = 0.0;
   out_1217280767504544402[61] = 0.0;
   out_1217280767504544402[62] = 0.0;
   out_1217280767504544402[63] = 0.0;
   out_1217280767504544402[64] = 0.0;
   out_1217280767504544402[65] = 0.0;
   out_1217280767504544402[66] = 0.0;
   out_1217280767504544402[67] = 0.0;
   out_1217280767504544402[68] = 0.0;
   out_1217280767504544402[69] = 0.0;
   out_1217280767504544402[70] = 0.0;
   out_1217280767504544402[71] = 0.0;
   out_1217280767504544402[72] = 0.0;
   out_1217280767504544402[73] = 0.0;
   out_1217280767504544402[74] = 0.0;
   out_1217280767504544402[75] = 0.0;
   out_1217280767504544402[76] = 1.0;
   out_1217280767504544402[77] = 0.0;
   out_1217280767504544402[78] = 0.0;
   out_1217280767504544402[79] = 0.0;
   out_1217280767504544402[80] = 0.0;
   out_1217280767504544402[81] = 0.0;
   out_1217280767504544402[82] = 0.0;
   out_1217280767504544402[83] = 0.0;
   out_1217280767504544402[84] = 0.0;
   out_1217280767504544402[85] = 0.0;
   out_1217280767504544402[86] = 0.0;
   out_1217280767504544402[87] = 0.0;
   out_1217280767504544402[88] = 0.0;
   out_1217280767504544402[89] = 0.0;
   out_1217280767504544402[90] = 0.0;
   out_1217280767504544402[91] = 0.0;
   out_1217280767504544402[92] = 0.0;
   out_1217280767504544402[93] = 0.0;
   out_1217280767504544402[94] = 0.0;
   out_1217280767504544402[95] = 1.0;
   out_1217280767504544402[96] = 0.0;
   out_1217280767504544402[97] = 0.0;
   out_1217280767504544402[98] = 0.0;
   out_1217280767504544402[99] = 0.0;
   out_1217280767504544402[100] = 0.0;
   out_1217280767504544402[101] = 0.0;
   out_1217280767504544402[102] = 0.0;
   out_1217280767504544402[103] = 0.0;
   out_1217280767504544402[104] = 0.0;
   out_1217280767504544402[105] = 0.0;
   out_1217280767504544402[106] = 0.0;
   out_1217280767504544402[107] = 0.0;
   out_1217280767504544402[108] = 0.0;
   out_1217280767504544402[109] = 0.0;
   out_1217280767504544402[110] = 0.0;
   out_1217280767504544402[111] = 0.0;
   out_1217280767504544402[112] = 0.0;
   out_1217280767504544402[113] = 0.0;
   out_1217280767504544402[114] = 1.0;
   out_1217280767504544402[115] = 0.0;
   out_1217280767504544402[116] = 0.0;
   out_1217280767504544402[117] = 0.0;
   out_1217280767504544402[118] = 0.0;
   out_1217280767504544402[119] = 0.0;
   out_1217280767504544402[120] = 0.0;
   out_1217280767504544402[121] = 0.0;
   out_1217280767504544402[122] = 0.0;
   out_1217280767504544402[123] = 0.0;
   out_1217280767504544402[124] = 0.0;
   out_1217280767504544402[125] = 0.0;
   out_1217280767504544402[126] = 0.0;
   out_1217280767504544402[127] = 0.0;
   out_1217280767504544402[128] = 0.0;
   out_1217280767504544402[129] = 0.0;
   out_1217280767504544402[130] = 0.0;
   out_1217280767504544402[131] = 0.0;
   out_1217280767504544402[132] = 0.0;
   out_1217280767504544402[133] = 1.0;
   out_1217280767504544402[134] = 0.0;
   out_1217280767504544402[135] = 0.0;
   out_1217280767504544402[136] = 0.0;
   out_1217280767504544402[137] = 0.0;
   out_1217280767504544402[138] = 0.0;
   out_1217280767504544402[139] = 0.0;
   out_1217280767504544402[140] = 0.0;
   out_1217280767504544402[141] = 0.0;
   out_1217280767504544402[142] = 0.0;
   out_1217280767504544402[143] = 0.0;
   out_1217280767504544402[144] = 0.0;
   out_1217280767504544402[145] = 0.0;
   out_1217280767504544402[146] = 0.0;
   out_1217280767504544402[147] = 0.0;
   out_1217280767504544402[148] = 0.0;
   out_1217280767504544402[149] = 0.0;
   out_1217280767504544402[150] = 0.0;
   out_1217280767504544402[151] = 0.0;
   out_1217280767504544402[152] = 1.0;
   out_1217280767504544402[153] = 0.0;
   out_1217280767504544402[154] = 0.0;
   out_1217280767504544402[155] = 0.0;
   out_1217280767504544402[156] = 0.0;
   out_1217280767504544402[157] = 0.0;
   out_1217280767504544402[158] = 0.0;
   out_1217280767504544402[159] = 0.0;
   out_1217280767504544402[160] = 0.0;
   out_1217280767504544402[161] = 0.0;
   out_1217280767504544402[162] = 0.0;
   out_1217280767504544402[163] = 0.0;
   out_1217280767504544402[164] = 0.0;
   out_1217280767504544402[165] = 0.0;
   out_1217280767504544402[166] = 0.0;
   out_1217280767504544402[167] = 0.0;
   out_1217280767504544402[168] = 0.0;
   out_1217280767504544402[169] = 0.0;
   out_1217280767504544402[170] = 0.0;
   out_1217280767504544402[171] = 1.0;
   out_1217280767504544402[172] = 0.0;
   out_1217280767504544402[173] = 0.0;
   out_1217280767504544402[174] = 0.0;
   out_1217280767504544402[175] = 0.0;
   out_1217280767504544402[176] = 0.0;
   out_1217280767504544402[177] = 0.0;
   out_1217280767504544402[178] = 0.0;
   out_1217280767504544402[179] = 0.0;
   out_1217280767504544402[180] = 0.0;
   out_1217280767504544402[181] = 0.0;
   out_1217280767504544402[182] = 0.0;
   out_1217280767504544402[183] = 0.0;
   out_1217280767504544402[184] = 0.0;
   out_1217280767504544402[185] = 0.0;
   out_1217280767504544402[186] = 0.0;
   out_1217280767504544402[187] = 0.0;
   out_1217280767504544402[188] = 0.0;
   out_1217280767504544402[189] = 0.0;
   out_1217280767504544402[190] = 1.0;
   out_1217280767504544402[191] = 0.0;
   out_1217280767504544402[192] = 0.0;
   out_1217280767504544402[193] = 0.0;
   out_1217280767504544402[194] = 0.0;
   out_1217280767504544402[195] = 0.0;
   out_1217280767504544402[196] = 0.0;
   out_1217280767504544402[197] = 0.0;
   out_1217280767504544402[198] = 0.0;
   out_1217280767504544402[199] = 0.0;
   out_1217280767504544402[200] = 0.0;
   out_1217280767504544402[201] = 0.0;
   out_1217280767504544402[202] = 0.0;
   out_1217280767504544402[203] = 0.0;
   out_1217280767504544402[204] = 0.0;
   out_1217280767504544402[205] = 0.0;
   out_1217280767504544402[206] = 0.0;
   out_1217280767504544402[207] = 0.0;
   out_1217280767504544402[208] = 0.0;
   out_1217280767504544402[209] = 1.0;
   out_1217280767504544402[210] = 0.0;
   out_1217280767504544402[211] = 0.0;
   out_1217280767504544402[212] = 0.0;
   out_1217280767504544402[213] = 0.0;
   out_1217280767504544402[214] = 0.0;
   out_1217280767504544402[215] = 0.0;
   out_1217280767504544402[216] = 0.0;
   out_1217280767504544402[217] = 0.0;
   out_1217280767504544402[218] = 0.0;
   out_1217280767504544402[219] = 0.0;
   out_1217280767504544402[220] = 0.0;
   out_1217280767504544402[221] = 0.0;
   out_1217280767504544402[222] = 0.0;
   out_1217280767504544402[223] = 0.0;
   out_1217280767504544402[224] = 0.0;
   out_1217280767504544402[225] = 0.0;
   out_1217280767504544402[226] = 0.0;
   out_1217280767504544402[227] = 0.0;
   out_1217280767504544402[228] = 1.0;
   out_1217280767504544402[229] = 0.0;
   out_1217280767504544402[230] = 0.0;
   out_1217280767504544402[231] = 0.0;
   out_1217280767504544402[232] = 0.0;
   out_1217280767504544402[233] = 0.0;
   out_1217280767504544402[234] = 0.0;
   out_1217280767504544402[235] = 0.0;
   out_1217280767504544402[236] = 0.0;
   out_1217280767504544402[237] = 0.0;
   out_1217280767504544402[238] = 0.0;
   out_1217280767504544402[239] = 0.0;
   out_1217280767504544402[240] = 0.0;
   out_1217280767504544402[241] = 0.0;
   out_1217280767504544402[242] = 0.0;
   out_1217280767504544402[243] = 0.0;
   out_1217280767504544402[244] = 0.0;
   out_1217280767504544402[245] = 0.0;
   out_1217280767504544402[246] = 0.0;
   out_1217280767504544402[247] = 1.0;
   out_1217280767504544402[248] = 0.0;
   out_1217280767504544402[249] = 0.0;
   out_1217280767504544402[250] = 0.0;
   out_1217280767504544402[251] = 0.0;
   out_1217280767504544402[252] = 0.0;
   out_1217280767504544402[253] = 0.0;
   out_1217280767504544402[254] = 0.0;
   out_1217280767504544402[255] = 0.0;
   out_1217280767504544402[256] = 0.0;
   out_1217280767504544402[257] = 0.0;
   out_1217280767504544402[258] = 0.0;
   out_1217280767504544402[259] = 0.0;
   out_1217280767504544402[260] = 0.0;
   out_1217280767504544402[261] = 0.0;
   out_1217280767504544402[262] = 0.0;
   out_1217280767504544402[263] = 0.0;
   out_1217280767504544402[264] = 0.0;
   out_1217280767504544402[265] = 0.0;
   out_1217280767504544402[266] = 1.0;
   out_1217280767504544402[267] = 0.0;
   out_1217280767504544402[268] = 0.0;
   out_1217280767504544402[269] = 0.0;
   out_1217280767504544402[270] = 0.0;
   out_1217280767504544402[271] = 0.0;
   out_1217280767504544402[272] = 0.0;
   out_1217280767504544402[273] = 0.0;
   out_1217280767504544402[274] = 0.0;
   out_1217280767504544402[275] = 0.0;
   out_1217280767504544402[276] = 0.0;
   out_1217280767504544402[277] = 0.0;
   out_1217280767504544402[278] = 0.0;
   out_1217280767504544402[279] = 0.0;
   out_1217280767504544402[280] = 0.0;
   out_1217280767504544402[281] = 0.0;
   out_1217280767504544402[282] = 0.0;
   out_1217280767504544402[283] = 0.0;
   out_1217280767504544402[284] = 0.0;
   out_1217280767504544402[285] = 1.0;
   out_1217280767504544402[286] = 0.0;
   out_1217280767504544402[287] = 0.0;
   out_1217280767504544402[288] = 0.0;
   out_1217280767504544402[289] = 0.0;
   out_1217280767504544402[290] = 0.0;
   out_1217280767504544402[291] = 0.0;
   out_1217280767504544402[292] = 0.0;
   out_1217280767504544402[293] = 0.0;
   out_1217280767504544402[294] = 0.0;
   out_1217280767504544402[295] = 0.0;
   out_1217280767504544402[296] = 0.0;
   out_1217280767504544402[297] = 0.0;
   out_1217280767504544402[298] = 0.0;
   out_1217280767504544402[299] = 0.0;
   out_1217280767504544402[300] = 0.0;
   out_1217280767504544402[301] = 0.0;
   out_1217280767504544402[302] = 0.0;
   out_1217280767504544402[303] = 0.0;
   out_1217280767504544402[304] = 1.0;
   out_1217280767504544402[305] = 0.0;
   out_1217280767504544402[306] = 0.0;
   out_1217280767504544402[307] = 0.0;
   out_1217280767504544402[308] = 0.0;
   out_1217280767504544402[309] = 0.0;
   out_1217280767504544402[310] = 0.0;
   out_1217280767504544402[311] = 0.0;
   out_1217280767504544402[312] = 0.0;
   out_1217280767504544402[313] = 0.0;
   out_1217280767504544402[314] = 0.0;
   out_1217280767504544402[315] = 0.0;
   out_1217280767504544402[316] = 0.0;
   out_1217280767504544402[317] = 0.0;
   out_1217280767504544402[318] = 0.0;
   out_1217280767504544402[319] = 0.0;
   out_1217280767504544402[320] = 0.0;
   out_1217280767504544402[321] = 0.0;
   out_1217280767504544402[322] = 0.0;
   out_1217280767504544402[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4609271159637541739) {
   out_4609271159637541739[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4609271159637541739[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4609271159637541739[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4609271159637541739[3] = dt*state[12] + state[3];
   out_4609271159637541739[4] = dt*state[13] + state[4];
   out_4609271159637541739[5] = dt*state[14] + state[5];
   out_4609271159637541739[6] = state[6];
   out_4609271159637541739[7] = state[7];
   out_4609271159637541739[8] = state[8];
   out_4609271159637541739[9] = state[9];
   out_4609271159637541739[10] = state[10];
   out_4609271159637541739[11] = state[11];
   out_4609271159637541739[12] = state[12];
   out_4609271159637541739[13] = state[13];
   out_4609271159637541739[14] = state[14];
   out_4609271159637541739[15] = state[15];
   out_4609271159637541739[16] = state[16];
   out_4609271159637541739[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5279488839905480126) {
   out_5279488839905480126[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5279488839905480126[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5279488839905480126[2] = 0;
   out_5279488839905480126[3] = 0;
   out_5279488839905480126[4] = 0;
   out_5279488839905480126[5] = 0;
   out_5279488839905480126[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5279488839905480126[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5279488839905480126[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5279488839905480126[9] = 0;
   out_5279488839905480126[10] = 0;
   out_5279488839905480126[11] = 0;
   out_5279488839905480126[12] = 0;
   out_5279488839905480126[13] = 0;
   out_5279488839905480126[14] = 0;
   out_5279488839905480126[15] = 0;
   out_5279488839905480126[16] = 0;
   out_5279488839905480126[17] = 0;
   out_5279488839905480126[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5279488839905480126[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5279488839905480126[20] = 0;
   out_5279488839905480126[21] = 0;
   out_5279488839905480126[22] = 0;
   out_5279488839905480126[23] = 0;
   out_5279488839905480126[24] = 0;
   out_5279488839905480126[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5279488839905480126[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5279488839905480126[27] = 0;
   out_5279488839905480126[28] = 0;
   out_5279488839905480126[29] = 0;
   out_5279488839905480126[30] = 0;
   out_5279488839905480126[31] = 0;
   out_5279488839905480126[32] = 0;
   out_5279488839905480126[33] = 0;
   out_5279488839905480126[34] = 0;
   out_5279488839905480126[35] = 0;
   out_5279488839905480126[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5279488839905480126[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5279488839905480126[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5279488839905480126[39] = 0;
   out_5279488839905480126[40] = 0;
   out_5279488839905480126[41] = 0;
   out_5279488839905480126[42] = 0;
   out_5279488839905480126[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5279488839905480126[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5279488839905480126[45] = 0;
   out_5279488839905480126[46] = 0;
   out_5279488839905480126[47] = 0;
   out_5279488839905480126[48] = 0;
   out_5279488839905480126[49] = 0;
   out_5279488839905480126[50] = 0;
   out_5279488839905480126[51] = 0;
   out_5279488839905480126[52] = 0;
   out_5279488839905480126[53] = 0;
   out_5279488839905480126[54] = 0;
   out_5279488839905480126[55] = 0;
   out_5279488839905480126[56] = 0;
   out_5279488839905480126[57] = 1;
   out_5279488839905480126[58] = 0;
   out_5279488839905480126[59] = 0;
   out_5279488839905480126[60] = 0;
   out_5279488839905480126[61] = 0;
   out_5279488839905480126[62] = 0;
   out_5279488839905480126[63] = 0;
   out_5279488839905480126[64] = 0;
   out_5279488839905480126[65] = 0;
   out_5279488839905480126[66] = dt;
   out_5279488839905480126[67] = 0;
   out_5279488839905480126[68] = 0;
   out_5279488839905480126[69] = 0;
   out_5279488839905480126[70] = 0;
   out_5279488839905480126[71] = 0;
   out_5279488839905480126[72] = 0;
   out_5279488839905480126[73] = 0;
   out_5279488839905480126[74] = 0;
   out_5279488839905480126[75] = 0;
   out_5279488839905480126[76] = 1;
   out_5279488839905480126[77] = 0;
   out_5279488839905480126[78] = 0;
   out_5279488839905480126[79] = 0;
   out_5279488839905480126[80] = 0;
   out_5279488839905480126[81] = 0;
   out_5279488839905480126[82] = 0;
   out_5279488839905480126[83] = 0;
   out_5279488839905480126[84] = 0;
   out_5279488839905480126[85] = dt;
   out_5279488839905480126[86] = 0;
   out_5279488839905480126[87] = 0;
   out_5279488839905480126[88] = 0;
   out_5279488839905480126[89] = 0;
   out_5279488839905480126[90] = 0;
   out_5279488839905480126[91] = 0;
   out_5279488839905480126[92] = 0;
   out_5279488839905480126[93] = 0;
   out_5279488839905480126[94] = 0;
   out_5279488839905480126[95] = 1;
   out_5279488839905480126[96] = 0;
   out_5279488839905480126[97] = 0;
   out_5279488839905480126[98] = 0;
   out_5279488839905480126[99] = 0;
   out_5279488839905480126[100] = 0;
   out_5279488839905480126[101] = 0;
   out_5279488839905480126[102] = 0;
   out_5279488839905480126[103] = 0;
   out_5279488839905480126[104] = dt;
   out_5279488839905480126[105] = 0;
   out_5279488839905480126[106] = 0;
   out_5279488839905480126[107] = 0;
   out_5279488839905480126[108] = 0;
   out_5279488839905480126[109] = 0;
   out_5279488839905480126[110] = 0;
   out_5279488839905480126[111] = 0;
   out_5279488839905480126[112] = 0;
   out_5279488839905480126[113] = 0;
   out_5279488839905480126[114] = 1;
   out_5279488839905480126[115] = 0;
   out_5279488839905480126[116] = 0;
   out_5279488839905480126[117] = 0;
   out_5279488839905480126[118] = 0;
   out_5279488839905480126[119] = 0;
   out_5279488839905480126[120] = 0;
   out_5279488839905480126[121] = 0;
   out_5279488839905480126[122] = 0;
   out_5279488839905480126[123] = 0;
   out_5279488839905480126[124] = 0;
   out_5279488839905480126[125] = 0;
   out_5279488839905480126[126] = 0;
   out_5279488839905480126[127] = 0;
   out_5279488839905480126[128] = 0;
   out_5279488839905480126[129] = 0;
   out_5279488839905480126[130] = 0;
   out_5279488839905480126[131] = 0;
   out_5279488839905480126[132] = 0;
   out_5279488839905480126[133] = 1;
   out_5279488839905480126[134] = 0;
   out_5279488839905480126[135] = 0;
   out_5279488839905480126[136] = 0;
   out_5279488839905480126[137] = 0;
   out_5279488839905480126[138] = 0;
   out_5279488839905480126[139] = 0;
   out_5279488839905480126[140] = 0;
   out_5279488839905480126[141] = 0;
   out_5279488839905480126[142] = 0;
   out_5279488839905480126[143] = 0;
   out_5279488839905480126[144] = 0;
   out_5279488839905480126[145] = 0;
   out_5279488839905480126[146] = 0;
   out_5279488839905480126[147] = 0;
   out_5279488839905480126[148] = 0;
   out_5279488839905480126[149] = 0;
   out_5279488839905480126[150] = 0;
   out_5279488839905480126[151] = 0;
   out_5279488839905480126[152] = 1;
   out_5279488839905480126[153] = 0;
   out_5279488839905480126[154] = 0;
   out_5279488839905480126[155] = 0;
   out_5279488839905480126[156] = 0;
   out_5279488839905480126[157] = 0;
   out_5279488839905480126[158] = 0;
   out_5279488839905480126[159] = 0;
   out_5279488839905480126[160] = 0;
   out_5279488839905480126[161] = 0;
   out_5279488839905480126[162] = 0;
   out_5279488839905480126[163] = 0;
   out_5279488839905480126[164] = 0;
   out_5279488839905480126[165] = 0;
   out_5279488839905480126[166] = 0;
   out_5279488839905480126[167] = 0;
   out_5279488839905480126[168] = 0;
   out_5279488839905480126[169] = 0;
   out_5279488839905480126[170] = 0;
   out_5279488839905480126[171] = 1;
   out_5279488839905480126[172] = 0;
   out_5279488839905480126[173] = 0;
   out_5279488839905480126[174] = 0;
   out_5279488839905480126[175] = 0;
   out_5279488839905480126[176] = 0;
   out_5279488839905480126[177] = 0;
   out_5279488839905480126[178] = 0;
   out_5279488839905480126[179] = 0;
   out_5279488839905480126[180] = 0;
   out_5279488839905480126[181] = 0;
   out_5279488839905480126[182] = 0;
   out_5279488839905480126[183] = 0;
   out_5279488839905480126[184] = 0;
   out_5279488839905480126[185] = 0;
   out_5279488839905480126[186] = 0;
   out_5279488839905480126[187] = 0;
   out_5279488839905480126[188] = 0;
   out_5279488839905480126[189] = 0;
   out_5279488839905480126[190] = 1;
   out_5279488839905480126[191] = 0;
   out_5279488839905480126[192] = 0;
   out_5279488839905480126[193] = 0;
   out_5279488839905480126[194] = 0;
   out_5279488839905480126[195] = 0;
   out_5279488839905480126[196] = 0;
   out_5279488839905480126[197] = 0;
   out_5279488839905480126[198] = 0;
   out_5279488839905480126[199] = 0;
   out_5279488839905480126[200] = 0;
   out_5279488839905480126[201] = 0;
   out_5279488839905480126[202] = 0;
   out_5279488839905480126[203] = 0;
   out_5279488839905480126[204] = 0;
   out_5279488839905480126[205] = 0;
   out_5279488839905480126[206] = 0;
   out_5279488839905480126[207] = 0;
   out_5279488839905480126[208] = 0;
   out_5279488839905480126[209] = 1;
   out_5279488839905480126[210] = 0;
   out_5279488839905480126[211] = 0;
   out_5279488839905480126[212] = 0;
   out_5279488839905480126[213] = 0;
   out_5279488839905480126[214] = 0;
   out_5279488839905480126[215] = 0;
   out_5279488839905480126[216] = 0;
   out_5279488839905480126[217] = 0;
   out_5279488839905480126[218] = 0;
   out_5279488839905480126[219] = 0;
   out_5279488839905480126[220] = 0;
   out_5279488839905480126[221] = 0;
   out_5279488839905480126[222] = 0;
   out_5279488839905480126[223] = 0;
   out_5279488839905480126[224] = 0;
   out_5279488839905480126[225] = 0;
   out_5279488839905480126[226] = 0;
   out_5279488839905480126[227] = 0;
   out_5279488839905480126[228] = 1;
   out_5279488839905480126[229] = 0;
   out_5279488839905480126[230] = 0;
   out_5279488839905480126[231] = 0;
   out_5279488839905480126[232] = 0;
   out_5279488839905480126[233] = 0;
   out_5279488839905480126[234] = 0;
   out_5279488839905480126[235] = 0;
   out_5279488839905480126[236] = 0;
   out_5279488839905480126[237] = 0;
   out_5279488839905480126[238] = 0;
   out_5279488839905480126[239] = 0;
   out_5279488839905480126[240] = 0;
   out_5279488839905480126[241] = 0;
   out_5279488839905480126[242] = 0;
   out_5279488839905480126[243] = 0;
   out_5279488839905480126[244] = 0;
   out_5279488839905480126[245] = 0;
   out_5279488839905480126[246] = 0;
   out_5279488839905480126[247] = 1;
   out_5279488839905480126[248] = 0;
   out_5279488839905480126[249] = 0;
   out_5279488839905480126[250] = 0;
   out_5279488839905480126[251] = 0;
   out_5279488839905480126[252] = 0;
   out_5279488839905480126[253] = 0;
   out_5279488839905480126[254] = 0;
   out_5279488839905480126[255] = 0;
   out_5279488839905480126[256] = 0;
   out_5279488839905480126[257] = 0;
   out_5279488839905480126[258] = 0;
   out_5279488839905480126[259] = 0;
   out_5279488839905480126[260] = 0;
   out_5279488839905480126[261] = 0;
   out_5279488839905480126[262] = 0;
   out_5279488839905480126[263] = 0;
   out_5279488839905480126[264] = 0;
   out_5279488839905480126[265] = 0;
   out_5279488839905480126[266] = 1;
   out_5279488839905480126[267] = 0;
   out_5279488839905480126[268] = 0;
   out_5279488839905480126[269] = 0;
   out_5279488839905480126[270] = 0;
   out_5279488839905480126[271] = 0;
   out_5279488839905480126[272] = 0;
   out_5279488839905480126[273] = 0;
   out_5279488839905480126[274] = 0;
   out_5279488839905480126[275] = 0;
   out_5279488839905480126[276] = 0;
   out_5279488839905480126[277] = 0;
   out_5279488839905480126[278] = 0;
   out_5279488839905480126[279] = 0;
   out_5279488839905480126[280] = 0;
   out_5279488839905480126[281] = 0;
   out_5279488839905480126[282] = 0;
   out_5279488839905480126[283] = 0;
   out_5279488839905480126[284] = 0;
   out_5279488839905480126[285] = 1;
   out_5279488839905480126[286] = 0;
   out_5279488839905480126[287] = 0;
   out_5279488839905480126[288] = 0;
   out_5279488839905480126[289] = 0;
   out_5279488839905480126[290] = 0;
   out_5279488839905480126[291] = 0;
   out_5279488839905480126[292] = 0;
   out_5279488839905480126[293] = 0;
   out_5279488839905480126[294] = 0;
   out_5279488839905480126[295] = 0;
   out_5279488839905480126[296] = 0;
   out_5279488839905480126[297] = 0;
   out_5279488839905480126[298] = 0;
   out_5279488839905480126[299] = 0;
   out_5279488839905480126[300] = 0;
   out_5279488839905480126[301] = 0;
   out_5279488839905480126[302] = 0;
   out_5279488839905480126[303] = 0;
   out_5279488839905480126[304] = 1;
   out_5279488839905480126[305] = 0;
   out_5279488839905480126[306] = 0;
   out_5279488839905480126[307] = 0;
   out_5279488839905480126[308] = 0;
   out_5279488839905480126[309] = 0;
   out_5279488839905480126[310] = 0;
   out_5279488839905480126[311] = 0;
   out_5279488839905480126[312] = 0;
   out_5279488839905480126[313] = 0;
   out_5279488839905480126[314] = 0;
   out_5279488839905480126[315] = 0;
   out_5279488839905480126[316] = 0;
   out_5279488839905480126[317] = 0;
   out_5279488839905480126[318] = 0;
   out_5279488839905480126[319] = 0;
   out_5279488839905480126[320] = 0;
   out_5279488839905480126[321] = 0;
   out_5279488839905480126[322] = 0;
   out_5279488839905480126[323] = 1;
}
void h_4(double *state, double *unused, double *out_301709123607443688) {
   out_301709123607443688[0] = state[6] + state[9];
   out_301709123607443688[1] = state[7] + state[10];
   out_301709123607443688[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4417690668606014426) {
   out_4417690668606014426[0] = 0;
   out_4417690668606014426[1] = 0;
   out_4417690668606014426[2] = 0;
   out_4417690668606014426[3] = 0;
   out_4417690668606014426[4] = 0;
   out_4417690668606014426[5] = 0;
   out_4417690668606014426[6] = 1;
   out_4417690668606014426[7] = 0;
   out_4417690668606014426[8] = 0;
   out_4417690668606014426[9] = 1;
   out_4417690668606014426[10] = 0;
   out_4417690668606014426[11] = 0;
   out_4417690668606014426[12] = 0;
   out_4417690668606014426[13] = 0;
   out_4417690668606014426[14] = 0;
   out_4417690668606014426[15] = 0;
   out_4417690668606014426[16] = 0;
   out_4417690668606014426[17] = 0;
   out_4417690668606014426[18] = 0;
   out_4417690668606014426[19] = 0;
   out_4417690668606014426[20] = 0;
   out_4417690668606014426[21] = 0;
   out_4417690668606014426[22] = 0;
   out_4417690668606014426[23] = 0;
   out_4417690668606014426[24] = 0;
   out_4417690668606014426[25] = 1;
   out_4417690668606014426[26] = 0;
   out_4417690668606014426[27] = 0;
   out_4417690668606014426[28] = 1;
   out_4417690668606014426[29] = 0;
   out_4417690668606014426[30] = 0;
   out_4417690668606014426[31] = 0;
   out_4417690668606014426[32] = 0;
   out_4417690668606014426[33] = 0;
   out_4417690668606014426[34] = 0;
   out_4417690668606014426[35] = 0;
   out_4417690668606014426[36] = 0;
   out_4417690668606014426[37] = 0;
   out_4417690668606014426[38] = 0;
   out_4417690668606014426[39] = 0;
   out_4417690668606014426[40] = 0;
   out_4417690668606014426[41] = 0;
   out_4417690668606014426[42] = 0;
   out_4417690668606014426[43] = 0;
   out_4417690668606014426[44] = 1;
   out_4417690668606014426[45] = 0;
   out_4417690668606014426[46] = 0;
   out_4417690668606014426[47] = 1;
   out_4417690668606014426[48] = 0;
   out_4417690668606014426[49] = 0;
   out_4417690668606014426[50] = 0;
   out_4417690668606014426[51] = 0;
   out_4417690668606014426[52] = 0;
   out_4417690668606014426[53] = 0;
}
void h_10(double *state, double *unused, double *out_7106035581154739398) {
   out_7106035581154739398[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7106035581154739398[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7106035581154739398[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5716162753714162166) {
   out_5716162753714162166[0] = 0;
   out_5716162753714162166[1] = 9.8100000000000005*cos(state[1]);
   out_5716162753714162166[2] = 0;
   out_5716162753714162166[3] = 0;
   out_5716162753714162166[4] = -state[8];
   out_5716162753714162166[5] = state[7];
   out_5716162753714162166[6] = 0;
   out_5716162753714162166[7] = state[5];
   out_5716162753714162166[8] = -state[4];
   out_5716162753714162166[9] = 0;
   out_5716162753714162166[10] = 0;
   out_5716162753714162166[11] = 0;
   out_5716162753714162166[12] = 1;
   out_5716162753714162166[13] = 0;
   out_5716162753714162166[14] = 0;
   out_5716162753714162166[15] = 1;
   out_5716162753714162166[16] = 0;
   out_5716162753714162166[17] = 0;
   out_5716162753714162166[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5716162753714162166[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5716162753714162166[20] = 0;
   out_5716162753714162166[21] = state[8];
   out_5716162753714162166[22] = 0;
   out_5716162753714162166[23] = -state[6];
   out_5716162753714162166[24] = -state[5];
   out_5716162753714162166[25] = 0;
   out_5716162753714162166[26] = state[3];
   out_5716162753714162166[27] = 0;
   out_5716162753714162166[28] = 0;
   out_5716162753714162166[29] = 0;
   out_5716162753714162166[30] = 0;
   out_5716162753714162166[31] = 1;
   out_5716162753714162166[32] = 0;
   out_5716162753714162166[33] = 0;
   out_5716162753714162166[34] = 1;
   out_5716162753714162166[35] = 0;
   out_5716162753714162166[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5716162753714162166[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5716162753714162166[38] = 0;
   out_5716162753714162166[39] = -state[7];
   out_5716162753714162166[40] = state[6];
   out_5716162753714162166[41] = 0;
   out_5716162753714162166[42] = state[4];
   out_5716162753714162166[43] = -state[3];
   out_5716162753714162166[44] = 0;
   out_5716162753714162166[45] = 0;
   out_5716162753714162166[46] = 0;
   out_5716162753714162166[47] = 0;
   out_5716162753714162166[48] = 0;
   out_5716162753714162166[49] = 0;
   out_5716162753714162166[50] = 1;
   out_5716162753714162166[51] = 0;
   out_5716162753714162166[52] = 0;
   out_5716162753714162166[53] = 1;
}
void h_13(double *state, double *unused, double *out_9094498493959954093) {
   out_9094498493959954093[0] = state[3];
   out_9094498493959954093[1] = state[4];
   out_9094498493959954093[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3853088748924170322) {
   out_3853088748924170322[0] = 0;
   out_3853088748924170322[1] = 0;
   out_3853088748924170322[2] = 0;
   out_3853088748924170322[3] = 1;
   out_3853088748924170322[4] = 0;
   out_3853088748924170322[5] = 0;
   out_3853088748924170322[6] = 0;
   out_3853088748924170322[7] = 0;
   out_3853088748924170322[8] = 0;
   out_3853088748924170322[9] = 0;
   out_3853088748924170322[10] = 0;
   out_3853088748924170322[11] = 0;
   out_3853088748924170322[12] = 0;
   out_3853088748924170322[13] = 0;
   out_3853088748924170322[14] = 0;
   out_3853088748924170322[15] = 0;
   out_3853088748924170322[16] = 0;
   out_3853088748924170322[17] = 0;
   out_3853088748924170322[18] = 0;
   out_3853088748924170322[19] = 0;
   out_3853088748924170322[20] = 0;
   out_3853088748924170322[21] = 0;
   out_3853088748924170322[22] = 1;
   out_3853088748924170322[23] = 0;
   out_3853088748924170322[24] = 0;
   out_3853088748924170322[25] = 0;
   out_3853088748924170322[26] = 0;
   out_3853088748924170322[27] = 0;
   out_3853088748924170322[28] = 0;
   out_3853088748924170322[29] = 0;
   out_3853088748924170322[30] = 0;
   out_3853088748924170322[31] = 0;
   out_3853088748924170322[32] = 0;
   out_3853088748924170322[33] = 0;
   out_3853088748924170322[34] = 0;
   out_3853088748924170322[35] = 0;
   out_3853088748924170322[36] = 0;
   out_3853088748924170322[37] = 0;
   out_3853088748924170322[38] = 0;
   out_3853088748924170322[39] = 0;
   out_3853088748924170322[40] = 0;
   out_3853088748924170322[41] = 1;
   out_3853088748924170322[42] = 0;
   out_3853088748924170322[43] = 0;
   out_3853088748924170322[44] = 0;
   out_3853088748924170322[45] = 0;
   out_3853088748924170322[46] = 0;
   out_3853088748924170322[47] = 0;
   out_3853088748924170322[48] = 0;
   out_3853088748924170322[49] = 0;
   out_3853088748924170322[50] = 0;
   out_3853088748924170322[51] = 0;
   out_3853088748924170322[52] = 0;
   out_3853088748924170322[53] = 0;
}
void h_14(double *state, double *unused, double *out_5269288261350591165) {
   out_5269288261350591165[0] = state[6];
   out_5269288261350591165[1] = state[7];
   out_5269288261350591165[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7500479100901386722) {
   out_7500479100901386722[0] = 0;
   out_7500479100901386722[1] = 0;
   out_7500479100901386722[2] = 0;
   out_7500479100901386722[3] = 0;
   out_7500479100901386722[4] = 0;
   out_7500479100901386722[5] = 0;
   out_7500479100901386722[6] = 1;
   out_7500479100901386722[7] = 0;
   out_7500479100901386722[8] = 0;
   out_7500479100901386722[9] = 0;
   out_7500479100901386722[10] = 0;
   out_7500479100901386722[11] = 0;
   out_7500479100901386722[12] = 0;
   out_7500479100901386722[13] = 0;
   out_7500479100901386722[14] = 0;
   out_7500479100901386722[15] = 0;
   out_7500479100901386722[16] = 0;
   out_7500479100901386722[17] = 0;
   out_7500479100901386722[18] = 0;
   out_7500479100901386722[19] = 0;
   out_7500479100901386722[20] = 0;
   out_7500479100901386722[21] = 0;
   out_7500479100901386722[22] = 0;
   out_7500479100901386722[23] = 0;
   out_7500479100901386722[24] = 0;
   out_7500479100901386722[25] = 1;
   out_7500479100901386722[26] = 0;
   out_7500479100901386722[27] = 0;
   out_7500479100901386722[28] = 0;
   out_7500479100901386722[29] = 0;
   out_7500479100901386722[30] = 0;
   out_7500479100901386722[31] = 0;
   out_7500479100901386722[32] = 0;
   out_7500479100901386722[33] = 0;
   out_7500479100901386722[34] = 0;
   out_7500479100901386722[35] = 0;
   out_7500479100901386722[36] = 0;
   out_7500479100901386722[37] = 0;
   out_7500479100901386722[38] = 0;
   out_7500479100901386722[39] = 0;
   out_7500479100901386722[40] = 0;
   out_7500479100901386722[41] = 0;
   out_7500479100901386722[42] = 0;
   out_7500479100901386722[43] = 0;
   out_7500479100901386722[44] = 1;
   out_7500479100901386722[45] = 0;
   out_7500479100901386722[46] = 0;
   out_7500479100901386722[47] = 0;
   out_7500479100901386722[48] = 0;
   out_7500479100901386722[49] = 0;
   out_7500479100901386722[50] = 0;
   out_7500479100901386722[51] = 0;
   out_7500479100901386722[52] = 0;
   out_7500479100901386722[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_793421623727173718) {
  err_fun(nom_x, delta_x, out_793421623727173718);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6937176692902514454) {
  inv_err_fun(nom_x, true_x, out_6937176692902514454);
}
void pose_H_mod_fun(double *state, double *out_1217280767504544402) {
  H_mod_fun(state, out_1217280767504544402);
}
void pose_f_fun(double *state, double dt, double *out_4609271159637541739) {
  f_fun(state,  dt, out_4609271159637541739);
}
void pose_F_fun(double *state, double dt, double *out_5279488839905480126) {
  F_fun(state,  dt, out_5279488839905480126);
}
void pose_h_4(double *state, double *unused, double *out_301709123607443688) {
  h_4(state, unused, out_301709123607443688);
}
void pose_H_4(double *state, double *unused, double *out_4417690668606014426) {
  H_4(state, unused, out_4417690668606014426);
}
void pose_h_10(double *state, double *unused, double *out_7106035581154739398) {
  h_10(state, unused, out_7106035581154739398);
}
void pose_H_10(double *state, double *unused, double *out_5716162753714162166) {
  H_10(state, unused, out_5716162753714162166);
}
void pose_h_13(double *state, double *unused, double *out_9094498493959954093) {
  h_13(state, unused, out_9094498493959954093);
}
void pose_H_13(double *state, double *unused, double *out_3853088748924170322) {
  H_13(state, unused, out_3853088748924170322);
}
void pose_h_14(double *state, double *unused, double *out_5269288261350591165) {
  h_14(state, unused, out_5269288261350591165);
}
void pose_H_14(double *state, double *unused, double *out_7500479100901386722) {
  H_14(state, unused, out_7500479100901386722);
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
