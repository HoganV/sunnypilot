#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1216357632529856903) {
   out_1216357632529856903[0] = delta_x[0] + nom_x[0];
   out_1216357632529856903[1] = delta_x[1] + nom_x[1];
   out_1216357632529856903[2] = delta_x[2] + nom_x[2];
   out_1216357632529856903[3] = delta_x[3] + nom_x[3];
   out_1216357632529856903[4] = delta_x[4] + nom_x[4];
   out_1216357632529856903[5] = delta_x[5] + nom_x[5];
   out_1216357632529856903[6] = delta_x[6] + nom_x[6];
   out_1216357632529856903[7] = delta_x[7] + nom_x[7];
   out_1216357632529856903[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3660226024408498118) {
   out_3660226024408498118[0] = -nom_x[0] + true_x[0];
   out_3660226024408498118[1] = -nom_x[1] + true_x[1];
   out_3660226024408498118[2] = -nom_x[2] + true_x[2];
   out_3660226024408498118[3] = -nom_x[3] + true_x[3];
   out_3660226024408498118[4] = -nom_x[4] + true_x[4];
   out_3660226024408498118[5] = -nom_x[5] + true_x[5];
   out_3660226024408498118[6] = -nom_x[6] + true_x[6];
   out_3660226024408498118[7] = -nom_x[7] + true_x[7];
   out_3660226024408498118[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8050632600465675677) {
   out_8050632600465675677[0] = 1.0;
   out_8050632600465675677[1] = 0.0;
   out_8050632600465675677[2] = 0.0;
   out_8050632600465675677[3] = 0.0;
   out_8050632600465675677[4] = 0.0;
   out_8050632600465675677[5] = 0.0;
   out_8050632600465675677[6] = 0.0;
   out_8050632600465675677[7] = 0.0;
   out_8050632600465675677[8] = 0.0;
   out_8050632600465675677[9] = 0.0;
   out_8050632600465675677[10] = 1.0;
   out_8050632600465675677[11] = 0.0;
   out_8050632600465675677[12] = 0.0;
   out_8050632600465675677[13] = 0.0;
   out_8050632600465675677[14] = 0.0;
   out_8050632600465675677[15] = 0.0;
   out_8050632600465675677[16] = 0.0;
   out_8050632600465675677[17] = 0.0;
   out_8050632600465675677[18] = 0.0;
   out_8050632600465675677[19] = 0.0;
   out_8050632600465675677[20] = 1.0;
   out_8050632600465675677[21] = 0.0;
   out_8050632600465675677[22] = 0.0;
   out_8050632600465675677[23] = 0.0;
   out_8050632600465675677[24] = 0.0;
   out_8050632600465675677[25] = 0.0;
   out_8050632600465675677[26] = 0.0;
   out_8050632600465675677[27] = 0.0;
   out_8050632600465675677[28] = 0.0;
   out_8050632600465675677[29] = 0.0;
   out_8050632600465675677[30] = 1.0;
   out_8050632600465675677[31] = 0.0;
   out_8050632600465675677[32] = 0.0;
   out_8050632600465675677[33] = 0.0;
   out_8050632600465675677[34] = 0.0;
   out_8050632600465675677[35] = 0.0;
   out_8050632600465675677[36] = 0.0;
   out_8050632600465675677[37] = 0.0;
   out_8050632600465675677[38] = 0.0;
   out_8050632600465675677[39] = 0.0;
   out_8050632600465675677[40] = 1.0;
   out_8050632600465675677[41] = 0.0;
   out_8050632600465675677[42] = 0.0;
   out_8050632600465675677[43] = 0.0;
   out_8050632600465675677[44] = 0.0;
   out_8050632600465675677[45] = 0.0;
   out_8050632600465675677[46] = 0.0;
   out_8050632600465675677[47] = 0.0;
   out_8050632600465675677[48] = 0.0;
   out_8050632600465675677[49] = 0.0;
   out_8050632600465675677[50] = 1.0;
   out_8050632600465675677[51] = 0.0;
   out_8050632600465675677[52] = 0.0;
   out_8050632600465675677[53] = 0.0;
   out_8050632600465675677[54] = 0.0;
   out_8050632600465675677[55] = 0.0;
   out_8050632600465675677[56] = 0.0;
   out_8050632600465675677[57] = 0.0;
   out_8050632600465675677[58] = 0.0;
   out_8050632600465675677[59] = 0.0;
   out_8050632600465675677[60] = 1.0;
   out_8050632600465675677[61] = 0.0;
   out_8050632600465675677[62] = 0.0;
   out_8050632600465675677[63] = 0.0;
   out_8050632600465675677[64] = 0.0;
   out_8050632600465675677[65] = 0.0;
   out_8050632600465675677[66] = 0.0;
   out_8050632600465675677[67] = 0.0;
   out_8050632600465675677[68] = 0.0;
   out_8050632600465675677[69] = 0.0;
   out_8050632600465675677[70] = 1.0;
   out_8050632600465675677[71] = 0.0;
   out_8050632600465675677[72] = 0.0;
   out_8050632600465675677[73] = 0.0;
   out_8050632600465675677[74] = 0.0;
   out_8050632600465675677[75] = 0.0;
   out_8050632600465675677[76] = 0.0;
   out_8050632600465675677[77] = 0.0;
   out_8050632600465675677[78] = 0.0;
   out_8050632600465675677[79] = 0.0;
   out_8050632600465675677[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5799781428830426405) {
   out_5799781428830426405[0] = state[0];
   out_5799781428830426405[1] = state[1];
   out_5799781428830426405[2] = state[2];
   out_5799781428830426405[3] = state[3];
   out_5799781428830426405[4] = state[4];
   out_5799781428830426405[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5799781428830426405[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5799781428830426405[7] = state[7];
   out_5799781428830426405[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5731779610633491442) {
   out_5731779610633491442[0] = 1;
   out_5731779610633491442[1] = 0;
   out_5731779610633491442[2] = 0;
   out_5731779610633491442[3] = 0;
   out_5731779610633491442[4] = 0;
   out_5731779610633491442[5] = 0;
   out_5731779610633491442[6] = 0;
   out_5731779610633491442[7] = 0;
   out_5731779610633491442[8] = 0;
   out_5731779610633491442[9] = 0;
   out_5731779610633491442[10] = 1;
   out_5731779610633491442[11] = 0;
   out_5731779610633491442[12] = 0;
   out_5731779610633491442[13] = 0;
   out_5731779610633491442[14] = 0;
   out_5731779610633491442[15] = 0;
   out_5731779610633491442[16] = 0;
   out_5731779610633491442[17] = 0;
   out_5731779610633491442[18] = 0;
   out_5731779610633491442[19] = 0;
   out_5731779610633491442[20] = 1;
   out_5731779610633491442[21] = 0;
   out_5731779610633491442[22] = 0;
   out_5731779610633491442[23] = 0;
   out_5731779610633491442[24] = 0;
   out_5731779610633491442[25] = 0;
   out_5731779610633491442[26] = 0;
   out_5731779610633491442[27] = 0;
   out_5731779610633491442[28] = 0;
   out_5731779610633491442[29] = 0;
   out_5731779610633491442[30] = 1;
   out_5731779610633491442[31] = 0;
   out_5731779610633491442[32] = 0;
   out_5731779610633491442[33] = 0;
   out_5731779610633491442[34] = 0;
   out_5731779610633491442[35] = 0;
   out_5731779610633491442[36] = 0;
   out_5731779610633491442[37] = 0;
   out_5731779610633491442[38] = 0;
   out_5731779610633491442[39] = 0;
   out_5731779610633491442[40] = 1;
   out_5731779610633491442[41] = 0;
   out_5731779610633491442[42] = 0;
   out_5731779610633491442[43] = 0;
   out_5731779610633491442[44] = 0;
   out_5731779610633491442[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5731779610633491442[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5731779610633491442[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5731779610633491442[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5731779610633491442[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5731779610633491442[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5731779610633491442[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5731779610633491442[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5731779610633491442[53] = -9.8000000000000007*dt;
   out_5731779610633491442[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5731779610633491442[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5731779610633491442[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5731779610633491442[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5731779610633491442[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5731779610633491442[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5731779610633491442[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5731779610633491442[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5731779610633491442[62] = 0;
   out_5731779610633491442[63] = 0;
   out_5731779610633491442[64] = 0;
   out_5731779610633491442[65] = 0;
   out_5731779610633491442[66] = 0;
   out_5731779610633491442[67] = 0;
   out_5731779610633491442[68] = 0;
   out_5731779610633491442[69] = 0;
   out_5731779610633491442[70] = 1;
   out_5731779610633491442[71] = 0;
   out_5731779610633491442[72] = 0;
   out_5731779610633491442[73] = 0;
   out_5731779610633491442[74] = 0;
   out_5731779610633491442[75] = 0;
   out_5731779610633491442[76] = 0;
   out_5731779610633491442[77] = 0;
   out_5731779610633491442[78] = 0;
   out_5731779610633491442[79] = 0;
   out_5731779610633491442[80] = 1;
}
void h_25(double *state, double *unused, double *out_5328248241617488932) {
   out_5328248241617488932[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7545298158265378965) {
   out_7545298158265378965[0] = 0;
   out_7545298158265378965[1] = 0;
   out_7545298158265378965[2] = 0;
   out_7545298158265378965[3] = 0;
   out_7545298158265378965[4] = 0;
   out_7545298158265378965[5] = 0;
   out_7545298158265378965[6] = 1;
   out_7545298158265378965[7] = 0;
   out_7545298158265378965[8] = 0;
}
void h_24(double *state, double *unused, double *out_1519638865574766256) {
   out_1519638865574766256[0] = state[4];
   out_1519638865574766256[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8015755640308717689) {
   out_8015755640308717689[0] = 0;
   out_8015755640308717689[1] = 0;
   out_8015755640308717689[2] = 0;
   out_8015755640308717689[3] = 0;
   out_8015755640308717689[4] = 1;
   out_8015755640308717689[5] = 0;
   out_8015755640308717689[6] = 0;
   out_8015755640308717689[7] = 0;
   out_8015755640308717689[8] = 0;
   out_8015755640308717689[9] = 0;
   out_8015755640308717689[10] = 0;
   out_8015755640308717689[11] = 0;
   out_8015755640308717689[12] = 0;
   out_8015755640308717689[13] = 0;
   out_8015755640308717689[14] = 1;
   out_8015755640308717689[15] = 0;
   out_8015755640308717689[16] = 0;
   out_8015755640308717689[17] = 0;
}
void h_30(double *state, double *unused, double *out_8395045831279462596) {
   out_8395045831279462596[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7674637105408619035) {
   out_7674637105408619035[0] = 0;
   out_7674637105408619035[1] = 0;
   out_7674637105408619035[2] = 0;
   out_7674637105408619035[3] = 0;
   out_7674637105408619035[4] = 1;
   out_7674637105408619035[5] = 0;
   out_7674637105408619035[6] = 0;
   out_7674637105408619035[7] = 0;
   out_7674637105408619035[8] = 0;
}
void h_26(double *state, double *unused, double *out_7791729946602985079) {
   out_7791729946602985079[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7159942596570116427) {
   out_7159942596570116427[0] = 0;
   out_7159942596570116427[1] = 0;
   out_7159942596570116427[2] = 0;
   out_7159942596570116427[3] = 0;
   out_7159942596570116427[4] = 0;
   out_7159942596570116427[5] = 0;
   out_7159942596570116427[6] = 0;
   out_7159942596570116427[7] = 1;
   out_7159942596570116427[8] = 0;
}
void h_27(double *state, double *unused, double *out_429736672376249024) {
   out_429736672376249024[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8597343656500507670) {
   out_8597343656500507670[0] = 0;
   out_8597343656500507670[1] = 0;
   out_8597343656500507670[2] = 0;
   out_8597343656500507670[3] = 1;
   out_8597343656500507670[4] = 0;
   out_8597343656500507670[5] = 0;
   out_8597343656500507670[6] = 0;
   out_8597343656500507670[7] = 0;
   out_8597343656500507670[8] = 0;
}
void h_29(double *state, double *unused, double *out_1831701130526705992) {
   out_1831701130526705992[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7164405761094226851) {
   out_7164405761094226851[0] = 0;
   out_7164405761094226851[1] = 1;
   out_7164405761094226851[2] = 0;
   out_7164405761094226851[3] = 0;
   out_7164405761094226851[4] = 0;
   out_7164405761094226851[5] = 0;
   out_7164405761094226851[6] = 0;
   out_7164405761094226851[7] = 0;
   out_7164405761094226851[8] = 0;
}
void h_28(double *state, double *unused, double *out_3193621841167676208) {
   out_3193621841167676208[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5200775489528900600) {
   out_5200775489528900600[0] = 1;
   out_5200775489528900600[1] = 0;
   out_5200775489528900600[2] = 0;
   out_5200775489528900600[3] = 0;
   out_5200775489528900600[4] = 0;
   out_5200775489528900600[5] = 0;
   out_5200775489528900600[6] = 0;
   out_5200775489528900600[7] = 0;
   out_5200775489528900600[8] = 0;
}
void h_31(double *state, double *unused, double *out_3980778547408211502) {
   out_3980778547408211502[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7514652196388418537) {
   out_7514652196388418537[0] = 0;
   out_7514652196388418537[1] = 0;
   out_7514652196388418537[2] = 0;
   out_7514652196388418537[3] = 0;
   out_7514652196388418537[4] = 0;
   out_7514652196388418537[5] = 0;
   out_7514652196388418537[6] = 0;
   out_7514652196388418537[7] = 0;
   out_7514652196388418537[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1216357632529856903) {
  err_fun(nom_x, delta_x, out_1216357632529856903);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3660226024408498118) {
  inv_err_fun(nom_x, true_x, out_3660226024408498118);
}
void car_H_mod_fun(double *state, double *out_8050632600465675677) {
  H_mod_fun(state, out_8050632600465675677);
}
void car_f_fun(double *state, double dt, double *out_5799781428830426405) {
  f_fun(state,  dt, out_5799781428830426405);
}
void car_F_fun(double *state, double dt, double *out_5731779610633491442) {
  F_fun(state,  dt, out_5731779610633491442);
}
void car_h_25(double *state, double *unused, double *out_5328248241617488932) {
  h_25(state, unused, out_5328248241617488932);
}
void car_H_25(double *state, double *unused, double *out_7545298158265378965) {
  H_25(state, unused, out_7545298158265378965);
}
void car_h_24(double *state, double *unused, double *out_1519638865574766256) {
  h_24(state, unused, out_1519638865574766256);
}
void car_H_24(double *state, double *unused, double *out_8015755640308717689) {
  H_24(state, unused, out_8015755640308717689);
}
void car_h_30(double *state, double *unused, double *out_8395045831279462596) {
  h_30(state, unused, out_8395045831279462596);
}
void car_H_30(double *state, double *unused, double *out_7674637105408619035) {
  H_30(state, unused, out_7674637105408619035);
}
void car_h_26(double *state, double *unused, double *out_7791729946602985079) {
  h_26(state, unused, out_7791729946602985079);
}
void car_H_26(double *state, double *unused, double *out_7159942596570116427) {
  H_26(state, unused, out_7159942596570116427);
}
void car_h_27(double *state, double *unused, double *out_429736672376249024) {
  h_27(state, unused, out_429736672376249024);
}
void car_H_27(double *state, double *unused, double *out_8597343656500507670) {
  H_27(state, unused, out_8597343656500507670);
}
void car_h_29(double *state, double *unused, double *out_1831701130526705992) {
  h_29(state, unused, out_1831701130526705992);
}
void car_H_29(double *state, double *unused, double *out_7164405761094226851) {
  H_29(state, unused, out_7164405761094226851);
}
void car_h_28(double *state, double *unused, double *out_3193621841167676208) {
  h_28(state, unused, out_3193621841167676208);
}
void car_H_28(double *state, double *unused, double *out_5200775489528900600) {
  H_28(state, unused, out_5200775489528900600);
}
void car_h_31(double *state, double *unused, double *out_3980778547408211502) {
  h_31(state, unused, out_3980778547408211502);
}
void car_H_31(double *state, double *unused, double *out_7514652196388418537) {
  H_31(state, unused, out_7514652196388418537);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
