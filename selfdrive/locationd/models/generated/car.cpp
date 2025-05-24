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
void err_fun(double *nom_x, double *delta_x, double *out_3891823301120817358) {
   out_3891823301120817358[0] = delta_x[0] + nom_x[0];
   out_3891823301120817358[1] = delta_x[1] + nom_x[1];
   out_3891823301120817358[2] = delta_x[2] + nom_x[2];
   out_3891823301120817358[3] = delta_x[3] + nom_x[3];
   out_3891823301120817358[4] = delta_x[4] + nom_x[4];
   out_3891823301120817358[5] = delta_x[5] + nom_x[5];
   out_3891823301120817358[6] = delta_x[6] + nom_x[6];
   out_3891823301120817358[7] = delta_x[7] + nom_x[7];
   out_3891823301120817358[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7078103695220120208) {
   out_7078103695220120208[0] = -nom_x[0] + true_x[0];
   out_7078103695220120208[1] = -nom_x[1] + true_x[1];
   out_7078103695220120208[2] = -nom_x[2] + true_x[2];
   out_7078103695220120208[3] = -nom_x[3] + true_x[3];
   out_7078103695220120208[4] = -nom_x[4] + true_x[4];
   out_7078103695220120208[5] = -nom_x[5] + true_x[5];
   out_7078103695220120208[6] = -nom_x[6] + true_x[6];
   out_7078103695220120208[7] = -nom_x[7] + true_x[7];
   out_7078103695220120208[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7605334782961292562) {
   out_7605334782961292562[0] = 1.0;
   out_7605334782961292562[1] = 0.0;
   out_7605334782961292562[2] = 0.0;
   out_7605334782961292562[3] = 0.0;
   out_7605334782961292562[4] = 0.0;
   out_7605334782961292562[5] = 0.0;
   out_7605334782961292562[6] = 0.0;
   out_7605334782961292562[7] = 0.0;
   out_7605334782961292562[8] = 0.0;
   out_7605334782961292562[9] = 0.0;
   out_7605334782961292562[10] = 1.0;
   out_7605334782961292562[11] = 0.0;
   out_7605334782961292562[12] = 0.0;
   out_7605334782961292562[13] = 0.0;
   out_7605334782961292562[14] = 0.0;
   out_7605334782961292562[15] = 0.0;
   out_7605334782961292562[16] = 0.0;
   out_7605334782961292562[17] = 0.0;
   out_7605334782961292562[18] = 0.0;
   out_7605334782961292562[19] = 0.0;
   out_7605334782961292562[20] = 1.0;
   out_7605334782961292562[21] = 0.0;
   out_7605334782961292562[22] = 0.0;
   out_7605334782961292562[23] = 0.0;
   out_7605334782961292562[24] = 0.0;
   out_7605334782961292562[25] = 0.0;
   out_7605334782961292562[26] = 0.0;
   out_7605334782961292562[27] = 0.0;
   out_7605334782961292562[28] = 0.0;
   out_7605334782961292562[29] = 0.0;
   out_7605334782961292562[30] = 1.0;
   out_7605334782961292562[31] = 0.0;
   out_7605334782961292562[32] = 0.0;
   out_7605334782961292562[33] = 0.0;
   out_7605334782961292562[34] = 0.0;
   out_7605334782961292562[35] = 0.0;
   out_7605334782961292562[36] = 0.0;
   out_7605334782961292562[37] = 0.0;
   out_7605334782961292562[38] = 0.0;
   out_7605334782961292562[39] = 0.0;
   out_7605334782961292562[40] = 1.0;
   out_7605334782961292562[41] = 0.0;
   out_7605334782961292562[42] = 0.0;
   out_7605334782961292562[43] = 0.0;
   out_7605334782961292562[44] = 0.0;
   out_7605334782961292562[45] = 0.0;
   out_7605334782961292562[46] = 0.0;
   out_7605334782961292562[47] = 0.0;
   out_7605334782961292562[48] = 0.0;
   out_7605334782961292562[49] = 0.0;
   out_7605334782961292562[50] = 1.0;
   out_7605334782961292562[51] = 0.0;
   out_7605334782961292562[52] = 0.0;
   out_7605334782961292562[53] = 0.0;
   out_7605334782961292562[54] = 0.0;
   out_7605334782961292562[55] = 0.0;
   out_7605334782961292562[56] = 0.0;
   out_7605334782961292562[57] = 0.0;
   out_7605334782961292562[58] = 0.0;
   out_7605334782961292562[59] = 0.0;
   out_7605334782961292562[60] = 1.0;
   out_7605334782961292562[61] = 0.0;
   out_7605334782961292562[62] = 0.0;
   out_7605334782961292562[63] = 0.0;
   out_7605334782961292562[64] = 0.0;
   out_7605334782961292562[65] = 0.0;
   out_7605334782961292562[66] = 0.0;
   out_7605334782961292562[67] = 0.0;
   out_7605334782961292562[68] = 0.0;
   out_7605334782961292562[69] = 0.0;
   out_7605334782961292562[70] = 1.0;
   out_7605334782961292562[71] = 0.0;
   out_7605334782961292562[72] = 0.0;
   out_7605334782961292562[73] = 0.0;
   out_7605334782961292562[74] = 0.0;
   out_7605334782961292562[75] = 0.0;
   out_7605334782961292562[76] = 0.0;
   out_7605334782961292562[77] = 0.0;
   out_7605334782961292562[78] = 0.0;
   out_7605334782961292562[79] = 0.0;
   out_7605334782961292562[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_285885356126369333) {
   out_285885356126369333[0] = state[0];
   out_285885356126369333[1] = state[1];
   out_285885356126369333[2] = state[2];
   out_285885356126369333[3] = state[3];
   out_285885356126369333[4] = state[4];
   out_285885356126369333[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_285885356126369333[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_285885356126369333[7] = state[7];
   out_285885356126369333[8] = state[8];
}
void F_fun(double *state, double dt, double *out_9130501085059811902) {
   out_9130501085059811902[0] = 1;
   out_9130501085059811902[1] = 0;
   out_9130501085059811902[2] = 0;
   out_9130501085059811902[3] = 0;
   out_9130501085059811902[4] = 0;
   out_9130501085059811902[5] = 0;
   out_9130501085059811902[6] = 0;
   out_9130501085059811902[7] = 0;
   out_9130501085059811902[8] = 0;
   out_9130501085059811902[9] = 0;
   out_9130501085059811902[10] = 1;
   out_9130501085059811902[11] = 0;
   out_9130501085059811902[12] = 0;
   out_9130501085059811902[13] = 0;
   out_9130501085059811902[14] = 0;
   out_9130501085059811902[15] = 0;
   out_9130501085059811902[16] = 0;
   out_9130501085059811902[17] = 0;
   out_9130501085059811902[18] = 0;
   out_9130501085059811902[19] = 0;
   out_9130501085059811902[20] = 1;
   out_9130501085059811902[21] = 0;
   out_9130501085059811902[22] = 0;
   out_9130501085059811902[23] = 0;
   out_9130501085059811902[24] = 0;
   out_9130501085059811902[25] = 0;
   out_9130501085059811902[26] = 0;
   out_9130501085059811902[27] = 0;
   out_9130501085059811902[28] = 0;
   out_9130501085059811902[29] = 0;
   out_9130501085059811902[30] = 1;
   out_9130501085059811902[31] = 0;
   out_9130501085059811902[32] = 0;
   out_9130501085059811902[33] = 0;
   out_9130501085059811902[34] = 0;
   out_9130501085059811902[35] = 0;
   out_9130501085059811902[36] = 0;
   out_9130501085059811902[37] = 0;
   out_9130501085059811902[38] = 0;
   out_9130501085059811902[39] = 0;
   out_9130501085059811902[40] = 1;
   out_9130501085059811902[41] = 0;
   out_9130501085059811902[42] = 0;
   out_9130501085059811902[43] = 0;
   out_9130501085059811902[44] = 0;
   out_9130501085059811902[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_9130501085059811902[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_9130501085059811902[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9130501085059811902[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9130501085059811902[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_9130501085059811902[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_9130501085059811902[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_9130501085059811902[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_9130501085059811902[53] = -9.8000000000000007*dt;
   out_9130501085059811902[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_9130501085059811902[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_9130501085059811902[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9130501085059811902[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9130501085059811902[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_9130501085059811902[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_9130501085059811902[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_9130501085059811902[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9130501085059811902[62] = 0;
   out_9130501085059811902[63] = 0;
   out_9130501085059811902[64] = 0;
   out_9130501085059811902[65] = 0;
   out_9130501085059811902[66] = 0;
   out_9130501085059811902[67] = 0;
   out_9130501085059811902[68] = 0;
   out_9130501085059811902[69] = 0;
   out_9130501085059811902[70] = 1;
   out_9130501085059811902[71] = 0;
   out_9130501085059811902[72] = 0;
   out_9130501085059811902[73] = 0;
   out_9130501085059811902[74] = 0;
   out_9130501085059811902[75] = 0;
   out_9130501085059811902[76] = 0;
   out_9130501085059811902[77] = 0;
   out_9130501085059811902[78] = 0;
   out_9130501085059811902[79] = 0;
   out_9130501085059811902[80] = 1;
}
void h_25(double *state, double *unused, double *out_7426870835523995815) {
   out_7426870835523995815[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6780537292649003006) {
   out_6780537292649003006[0] = 0;
   out_6780537292649003006[1] = 0;
   out_6780537292649003006[2] = 0;
   out_6780537292649003006[3] = 0;
   out_6780537292649003006[4] = 0;
   out_6780537292649003006[5] = 0;
   out_6780537292649003006[6] = 1;
   out_6780537292649003006[7] = 0;
   out_6780537292649003006[8] = 0;
}
void h_24(double *state, double *unused, double *out_5827732866319639362) {
   out_5827732866319639362[0] = state[4];
   out_5827732866319639362[1] = state[5];
}
void H_24(double *state, double *unused, double *out_637854341027923887) {
   out_637854341027923887[0] = 0;
   out_637854341027923887[1] = 0;
   out_637854341027923887[2] = 0;
   out_637854341027923887[3] = 0;
   out_637854341027923887[4] = 1;
   out_637854341027923887[5] = 0;
   out_637854341027923887[6] = 0;
   out_637854341027923887[7] = 0;
   out_637854341027923887[8] = 0;
   out_637854341027923887[9] = 0;
   out_637854341027923887[10] = 0;
   out_637854341027923887[11] = 0;
   out_637854341027923887[12] = 0;
   out_637854341027923887[13] = 0;
   out_637854341027923887[14] = 1;
   out_637854341027923887[15] = 0;
   out_637854341027923887[16] = 0;
   out_637854341027923887[17] = 0;
}
void h_30(double *state, double *unused, double *out_3138600587431506616) {
   out_3138600587431506616[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7138510450932940412) {
   out_7138510450932940412[0] = 0;
   out_7138510450932940412[1] = 0;
   out_7138510450932940412[2] = 0;
   out_7138510450932940412[3] = 0;
   out_7138510450932940412[4] = 1;
   out_7138510450932940412[5] = 0;
   out_7138510450932940412[6] = 0;
   out_7138510450932940412[7] = 0;
   out_7138510450932940412[8] = 0;
}
void h_26(double *state, double *unused, double *out_8140273855092352261) {
   out_8140273855092352261[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7924703462186492386) {
   out_7924703462186492386[0] = 0;
   out_7924703462186492386[1] = 0;
   out_7924703462186492386[2] = 0;
   out_7924703462186492386[3] = 0;
   out_7924703462186492386[4] = 0;
   out_7924703462186492386[5] = 0;
   out_7924703462186492386[6] = 0;
   out_7924703462186492386[7] = 1;
   out_7924703462186492386[8] = 0;
}
void h_27(double *state, double *unused, double *out_8030186720200473332) {
   out_8030186720200473332[0] = state[3];
}
void H_27(double *state, double *unused, double *out_9084639551592667987) {
   out_9084639551592667987[0] = 0;
   out_9084639551592667987[1] = 0;
   out_9084639551592667987[2] = 0;
   out_9084639551592667987[3] = 1;
   out_9084639551592667987[4] = 0;
   out_9084639551592667987[5] = 0;
   out_9084639551592667987[6] = 0;
   out_9084639551592667987[7] = 0;
   out_9084639551592667987[8] = 0;
}
void h_29(double *state, double *unused, double *out_2504129283649450219) {
   out_2504129283649450219[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7648741795247332596) {
   out_7648741795247332596[0] = 0;
   out_7648741795247332596[1] = 1;
   out_7648741795247332596[2] = 0;
   out_7648741795247332596[3] = 0;
   out_7648741795247332596[4] = 0;
   out_7648741795247332596[5] = 0;
   out_7648741795247332596[6] = 0;
   out_7648741795247332596[7] = 0;
   out_7648741795247332596[8] = 0;
}
void h_28(double *state, double *unused, double *out_7086676867298810897) {
   out_7086676867298810897[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2566342778177802022) {
   out_2566342778177802022[0] = 1;
   out_2566342778177802022[1] = 0;
   out_2566342778177802022[2] = 0;
   out_2566342778177802022[3] = 0;
   out_2566342778177802022[4] = 0;
   out_2566342778177802022[5] = 0;
   out_2566342778177802022[6] = 0;
   out_2566342778177802022[7] = 0;
   out_2566342778177802022[8] = 0;
}
void h_31(double *state, double *unused, double *out_3256607981364883360) {
   out_3256607981364883360[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7298495359953140910) {
   out_7298495359953140910[0] = 0;
   out_7298495359953140910[1] = 0;
   out_7298495359953140910[2] = 0;
   out_7298495359953140910[3] = 0;
   out_7298495359953140910[4] = 0;
   out_7298495359953140910[5] = 0;
   out_7298495359953140910[6] = 0;
   out_7298495359953140910[7] = 0;
   out_7298495359953140910[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3891823301120817358) {
  err_fun(nom_x, delta_x, out_3891823301120817358);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7078103695220120208) {
  inv_err_fun(nom_x, true_x, out_7078103695220120208);
}
void car_H_mod_fun(double *state, double *out_7605334782961292562) {
  H_mod_fun(state, out_7605334782961292562);
}
void car_f_fun(double *state, double dt, double *out_285885356126369333) {
  f_fun(state,  dt, out_285885356126369333);
}
void car_F_fun(double *state, double dt, double *out_9130501085059811902) {
  F_fun(state,  dt, out_9130501085059811902);
}
void car_h_25(double *state, double *unused, double *out_7426870835523995815) {
  h_25(state, unused, out_7426870835523995815);
}
void car_H_25(double *state, double *unused, double *out_6780537292649003006) {
  H_25(state, unused, out_6780537292649003006);
}
void car_h_24(double *state, double *unused, double *out_5827732866319639362) {
  h_24(state, unused, out_5827732866319639362);
}
void car_H_24(double *state, double *unused, double *out_637854341027923887) {
  H_24(state, unused, out_637854341027923887);
}
void car_h_30(double *state, double *unused, double *out_3138600587431506616) {
  h_30(state, unused, out_3138600587431506616);
}
void car_H_30(double *state, double *unused, double *out_7138510450932940412) {
  H_30(state, unused, out_7138510450932940412);
}
void car_h_26(double *state, double *unused, double *out_8140273855092352261) {
  h_26(state, unused, out_8140273855092352261);
}
void car_H_26(double *state, double *unused, double *out_7924703462186492386) {
  H_26(state, unused, out_7924703462186492386);
}
void car_h_27(double *state, double *unused, double *out_8030186720200473332) {
  h_27(state, unused, out_8030186720200473332);
}
void car_H_27(double *state, double *unused, double *out_9084639551592667987) {
  H_27(state, unused, out_9084639551592667987);
}
void car_h_29(double *state, double *unused, double *out_2504129283649450219) {
  h_29(state, unused, out_2504129283649450219);
}
void car_H_29(double *state, double *unused, double *out_7648741795247332596) {
  H_29(state, unused, out_7648741795247332596);
}
void car_h_28(double *state, double *unused, double *out_7086676867298810897) {
  h_28(state, unused, out_7086676867298810897);
}
void car_H_28(double *state, double *unused, double *out_2566342778177802022) {
  H_28(state, unused, out_2566342778177802022);
}
void car_h_31(double *state, double *unused, double *out_3256607981364883360) {
  h_31(state, unused, out_3256607981364883360);
}
void car_H_31(double *state, double *unused, double *out_7298495359953140910) {
  H_31(state, unused, out_7298495359953140910);
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
