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
void err_fun(double *nom_x, double *delta_x, double *out_6370189939875573224) {
   out_6370189939875573224[0] = delta_x[0] + nom_x[0];
   out_6370189939875573224[1] = delta_x[1] + nom_x[1];
   out_6370189939875573224[2] = delta_x[2] + nom_x[2];
   out_6370189939875573224[3] = delta_x[3] + nom_x[3];
   out_6370189939875573224[4] = delta_x[4] + nom_x[4];
   out_6370189939875573224[5] = delta_x[5] + nom_x[5];
   out_6370189939875573224[6] = delta_x[6] + nom_x[6];
   out_6370189939875573224[7] = delta_x[7] + nom_x[7];
   out_6370189939875573224[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1449584800308972156) {
   out_1449584800308972156[0] = -nom_x[0] + true_x[0];
   out_1449584800308972156[1] = -nom_x[1] + true_x[1];
   out_1449584800308972156[2] = -nom_x[2] + true_x[2];
   out_1449584800308972156[3] = -nom_x[3] + true_x[3];
   out_1449584800308972156[4] = -nom_x[4] + true_x[4];
   out_1449584800308972156[5] = -nom_x[5] + true_x[5];
   out_1449584800308972156[6] = -nom_x[6] + true_x[6];
   out_1449584800308972156[7] = -nom_x[7] + true_x[7];
   out_1449584800308972156[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5694264357373947516) {
   out_5694264357373947516[0] = 1.0;
   out_5694264357373947516[1] = 0.0;
   out_5694264357373947516[2] = 0.0;
   out_5694264357373947516[3] = 0.0;
   out_5694264357373947516[4] = 0.0;
   out_5694264357373947516[5] = 0.0;
   out_5694264357373947516[6] = 0.0;
   out_5694264357373947516[7] = 0.0;
   out_5694264357373947516[8] = 0.0;
   out_5694264357373947516[9] = 0.0;
   out_5694264357373947516[10] = 1.0;
   out_5694264357373947516[11] = 0.0;
   out_5694264357373947516[12] = 0.0;
   out_5694264357373947516[13] = 0.0;
   out_5694264357373947516[14] = 0.0;
   out_5694264357373947516[15] = 0.0;
   out_5694264357373947516[16] = 0.0;
   out_5694264357373947516[17] = 0.0;
   out_5694264357373947516[18] = 0.0;
   out_5694264357373947516[19] = 0.0;
   out_5694264357373947516[20] = 1.0;
   out_5694264357373947516[21] = 0.0;
   out_5694264357373947516[22] = 0.0;
   out_5694264357373947516[23] = 0.0;
   out_5694264357373947516[24] = 0.0;
   out_5694264357373947516[25] = 0.0;
   out_5694264357373947516[26] = 0.0;
   out_5694264357373947516[27] = 0.0;
   out_5694264357373947516[28] = 0.0;
   out_5694264357373947516[29] = 0.0;
   out_5694264357373947516[30] = 1.0;
   out_5694264357373947516[31] = 0.0;
   out_5694264357373947516[32] = 0.0;
   out_5694264357373947516[33] = 0.0;
   out_5694264357373947516[34] = 0.0;
   out_5694264357373947516[35] = 0.0;
   out_5694264357373947516[36] = 0.0;
   out_5694264357373947516[37] = 0.0;
   out_5694264357373947516[38] = 0.0;
   out_5694264357373947516[39] = 0.0;
   out_5694264357373947516[40] = 1.0;
   out_5694264357373947516[41] = 0.0;
   out_5694264357373947516[42] = 0.0;
   out_5694264357373947516[43] = 0.0;
   out_5694264357373947516[44] = 0.0;
   out_5694264357373947516[45] = 0.0;
   out_5694264357373947516[46] = 0.0;
   out_5694264357373947516[47] = 0.0;
   out_5694264357373947516[48] = 0.0;
   out_5694264357373947516[49] = 0.0;
   out_5694264357373947516[50] = 1.0;
   out_5694264357373947516[51] = 0.0;
   out_5694264357373947516[52] = 0.0;
   out_5694264357373947516[53] = 0.0;
   out_5694264357373947516[54] = 0.0;
   out_5694264357373947516[55] = 0.0;
   out_5694264357373947516[56] = 0.0;
   out_5694264357373947516[57] = 0.0;
   out_5694264357373947516[58] = 0.0;
   out_5694264357373947516[59] = 0.0;
   out_5694264357373947516[60] = 1.0;
   out_5694264357373947516[61] = 0.0;
   out_5694264357373947516[62] = 0.0;
   out_5694264357373947516[63] = 0.0;
   out_5694264357373947516[64] = 0.0;
   out_5694264357373947516[65] = 0.0;
   out_5694264357373947516[66] = 0.0;
   out_5694264357373947516[67] = 0.0;
   out_5694264357373947516[68] = 0.0;
   out_5694264357373947516[69] = 0.0;
   out_5694264357373947516[70] = 1.0;
   out_5694264357373947516[71] = 0.0;
   out_5694264357373947516[72] = 0.0;
   out_5694264357373947516[73] = 0.0;
   out_5694264357373947516[74] = 0.0;
   out_5694264357373947516[75] = 0.0;
   out_5694264357373947516[76] = 0.0;
   out_5694264357373947516[77] = 0.0;
   out_5694264357373947516[78] = 0.0;
   out_5694264357373947516[79] = 0.0;
   out_5694264357373947516[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5354864285430328391) {
   out_5354864285430328391[0] = state[0];
   out_5354864285430328391[1] = state[1];
   out_5354864285430328391[2] = state[2];
   out_5354864285430328391[3] = state[3];
   out_5354864285430328391[4] = state[4];
   out_5354864285430328391[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5354864285430328391[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5354864285430328391[7] = state[7];
   out_5354864285430328391[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8387330887260154280) {
   out_8387330887260154280[0] = 1;
   out_8387330887260154280[1] = 0;
   out_8387330887260154280[2] = 0;
   out_8387330887260154280[3] = 0;
   out_8387330887260154280[4] = 0;
   out_8387330887260154280[5] = 0;
   out_8387330887260154280[6] = 0;
   out_8387330887260154280[7] = 0;
   out_8387330887260154280[8] = 0;
   out_8387330887260154280[9] = 0;
   out_8387330887260154280[10] = 1;
   out_8387330887260154280[11] = 0;
   out_8387330887260154280[12] = 0;
   out_8387330887260154280[13] = 0;
   out_8387330887260154280[14] = 0;
   out_8387330887260154280[15] = 0;
   out_8387330887260154280[16] = 0;
   out_8387330887260154280[17] = 0;
   out_8387330887260154280[18] = 0;
   out_8387330887260154280[19] = 0;
   out_8387330887260154280[20] = 1;
   out_8387330887260154280[21] = 0;
   out_8387330887260154280[22] = 0;
   out_8387330887260154280[23] = 0;
   out_8387330887260154280[24] = 0;
   out_8387330887260154280[25] = 0;
   out_8387330887260154280[26] = 0;
   out_8387330887260154280[27] = 0;
   out_8387330887260154280[28] = 0;
   out_8387330887260154280[29] = 0;
   out_8387330887260154280[30] = 1;
   out_8387330887260154280[31] = 0;
   out_8387330887260154280[32] = 0;
   out_8387330887260154280[33] = 0;
   out_8387330887260154280[34] = 0;
   out_8387330887260154280[35] = 0;
   out_8387330887260154280[36] = 0;
   out_8387330887260154280[37] = 0;
   out_8387330887260154280[38] = 0;
   out_8387330887260154280[39] = 0;
   out_8387330887260154280[40] = 1;
   out_8387330887260154280[41] = 0;
   out_8387330887260154280[42] = 0;
   out_8387330887260154280[43] = 0;
   out_8387330887260154280[44] = 0;
   out_8387330887260154280[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8387330887260154280[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8387330887260154280[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8387330887260154280[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8387330887260154280[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8387330887260154280[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8387330887260154280[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8387330887260154280[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8387330887260154280[53] = -9.8000000000000007*dt;
   out_8387330887260154280[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8387330887260154280[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8387330887260154280[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8387330887260154280[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8387330887260154280[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8387330887260154280[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8387330887260154280[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8387330887260154280[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8387330887260154280[62] = 0;
   out_8387330887260154280[63] = 0;
   out_8387330887260154280[64] = 0;
   out_8387330887260154280[65] = 0;
   out_8387330887260154280[66] = 0;
   out_8387330887260154280[67] = 0;
   out_8387330887260154280[68] = 0;
   out_8387330887260154280[69] = 0;
   out_8387330887260154280[70] = 1;
   out_8387330887260154280[71] = 0;
   out_8387330887260154280[72] = 0;
   out_8387330887260154280[73] = 0;
   out_8387330887260154280[74] = 0;
   out_8387330887260154280[75] = 0;
   out_8387330887260154280[76] = 0;
   out_8387330887260154280[77] = 0;
   out_8387330887260154280[78] = 0;
   out_8387330887260154280[79] = 0;
   out_8387330887260154280[80] = 1;
}
void h_25(double *state, double *unused, double *out_8511299206176653652) {
   out_8511299206176653652[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4831141683361744295) {
   out_4831141683361744295[0] = 0;
   out_4831141683361744295[1] = 0;
   out_4831141683361744295[2] = 0;
   out_4831141683361744295[3] = 0;
   out_4831141683361744295[4] = 0;
   out_4831141683361744295[5] = 0;
   out_4831141683361744295[6] = 1;
   out_4831141683361744295[7] = 0;
   out_4831141683361744295[8] = 0;
}
void h_24(double *state, double *unused, double *out_2240178381642551870) {
   out_2240178381642551870[0] = state[4];
   out_2240178381642551870[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1823063774746441462) {
   out_1823063774746441462[0] = 0;
   out_1823063774746441462[1] = 0;
   out_1823063774746441462[2] = 0;
   out_1823063774746441462[3] = 0;
   out_1823063774746441462[4] = 1;
   out_1823063774746441462[5] = 0;
   out_1823063774746441462[6] = 0;
   out_1823063774746441462[7] = 0;
   out_1823063774746441462[8] = 0;
   out_1823063774746441462[9] = 0;
   out_1823063774746441462[10] = 0;
   out_1823063774746441462[11] = 0;
   out_1823063774746441462[12] = 0;
   out_1823063774746441462[13] = 0;
   out_1823063774746441462[14] = 1;
   out_1823063774746441462[15] = 0;
   out_1823063774746441462[16] = 0;
   out_1823063774746441462[17] = 0;
}
void h_30(double *state, double *unused, double *out_9112717363790017206) {
   out_9112717363790017206[0] = state[4];
}
void H_30(double *state, double *unused, double *out_9087906060220199123) {
   out_9087906060220199123[0] = 0;
   out_9087906060220199123[1] = 0;
   out_9087906060220199123[2] = 0;
   out_9087906060220199123[3] = 0;
   out_9087906060220199123[4] = 1;
   out_9087906060220199123[5] = 0;
   out_9087906060220199123[6] = 0;
   out_9087906060220199123[7] = 0;
   out_9087906060220199123[8] = 0;
}
void h_26(double *state, double *unused, double *out_4108119494084209463) {
   out_4108119494084209463[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8572645002235800519) {
   out_8572645002235800519[0] = 0;
   out_8572645002235800519[1] = 0;
   out_8572645002235800519[2] = 0;
   out_8572645002235800519[3] = 0;
   out_8572645002235800519[4] = 0;
   out_8572645002235800519[5] = 0;
   out_8572645002235800519[6] = 0;
   out_8572645002235800519[7] = 1;
   out_8572645002235800519[8] = 0;
}
void h_27(double *state, double *unused, double *out_3509625938515808007) {
   out_3509625938515808007[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6913142748419774212) {
   out_6913142748419774212[0] = 0;
   out_6913142748419774212[1] = 0;
   out_6913142748419774212[2] = 0;
   out_6913142748419774212[3] = 1;
   out_6913142748419774212[4] = 0;
   out_6913142748419774212[5] = 0;
   out_6913142748419774212[6] = 0;
   out_6913142748419774212[7] = 0;
   out_6913142748419774212[8] = 0;
}
void h_29(double *state, double *unused, double *out_8166282908843392673) {
   out_8166282908843392673[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8848606669174960309) {
   out_8848606669174960309[0] = 0;
   out_8848606669174960309[1] = 1;
   out_8848606669174960309[2] = 0;
   out_8848606669174960309[3] = 0;
   out_8848606669174960309[4] = 0;
   out_8848606669174960309[5] = 0;
   out_8848606669174960309[6] = 0;
   out_8848606669174960309[7] = 0;
   out_8848606669174960309[8] = 0;
}
void h_28(double *state, double *unused, double *out_2406004815218054329) {
   out_2406004815218054329[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6884976397609634058) {
   out_6884976397609634058[0] = 1;
   out_6884976397609634058[1] = 0;
   out_6884976397609634058[2] = 0;
   out_6884976397609634058[3] = 0;
   out_6884976397609634058[4] = 0;
   out_6884976397609634058[5] = 0;
   out_6884976397609634058[6] = 0;
   out_6884976397609634058[7] = 0;
   out_6884976397609634058[8] = 0;
}
void h_31(double *state, double *unused, double *out_748033949355981211) {
   out_748033949355981211[0] = state[8];
}
void H_31(double *state, double *unused, double *out_9198853104469151995) {
   out_9198853104469151995[0] = 0;
   out_9198853104469151995[1] = 0;
   out_9198853104469151995[2] = 0;
   out_9198853104469151995[3] = 0;
   out_9198853104469151995[4] = 0;
   out_9198853104469151995[5] = 0;
   out_9198853104469151995[6] = 0;
   out_9198853104469151995[7] = 0;
   out_9198853104469151995[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6370189939875573224) {
  err_fun(nom_x, delta_x, out_6370189939875573224);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1449584800308972156) {
  inv_err_fun(nom_x, true_x, out_1449584800308972156);
}
void car_H_mod_fun(double *state, double *out_5694264357373947516) {
  H_mod_fun(state, out_5694264357373947516);
}
void car_f_fun(double *state, double dt, double *out_5354864285430328391) {
  f_fun(state,  dt, out_5354864285430328391);
}
void car_F_fun(double *state, double dt, double *out_8387330887260154280) {
  F_fun(state,  dt, out_8387330887260154280);
}
void car_h_25(double *state, double *unused, double *out_8511299206176653652) {
  h_25(state, unused, out_8511299206176653652);
}
void car_H_25(double *state, double *unused, double *out_4831141683361744295) {
  H_25(state, unused, out_4831141683361744295);
}
void car_h_24(double *state, double *unused, double *out_2240178381642551870) {
  h_24(state, unused, out_2240178381642551870);
}
void car_H_24(double *state, double *unused, double *out_1823063774746441462) {
  H_24(state, unused, out_1823063774746441462);
}
void car_h_30(double *state, double *unused, double *out_9112717363790017206) {
  h_30(state, unused, out_9112717363790017206);
}
void car_H_30(double *state, double *unused, double *out_9087906060220199123) {
  H_30(state, unused, out_9087906060220199123);
}
void car_h_26(double *state, double *unused, double *out_4108119494084209463) {
  h_26(state, unused, out_4108119494084209463);
}
void car_H_26(double *state, double *unused, double *out_8572645002235800519) {
  H_26(state, unused, out_8572645002235800519);
}
void car_h_27(double *state, double *unused, double *out_3509625938515808007) {
  h_27(state, unused, out_3509625938515808007);
}
void car_H_27(double *state, double *unused, double *out_6913142748419774212) {
  H_27(state, unused, out_6913142748419774212);
}
void car_h_29(double *state, double *unused, double *out_8166282908843392673) {
  h_29(state, unused, out_8166282908843392673);
}
void car_H_29(double *state, double *unused, double *out_8848606669174960309) {
  H_29(state, unused, out_8848606669174960309);
}
void car_h_28(double *state, double *unused, double *out_2406004815218054329) {
  h_28(state, unused, out_2406004815218054329);
}
void car_H_28(double *state, double *unused, double *out_6884976397609634058) {
  H_28(state, unused, out_6884976397609634058);
}
void car_h_31(double *state, double *unused, double *out_748033949355981211) {
  h_31(state, unused, out_748033949355981211);
}
void car_H_31(double *state, double *unused, double *out_9198853104469151995) {
  H_31(state, unused, out_9198853104469151995);
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
