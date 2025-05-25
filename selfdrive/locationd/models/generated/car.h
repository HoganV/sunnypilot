#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6370189939875573224);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1449584800308972156);
void car_H_mod_fun(double *state, double *out_5694264357373947516);
void car_f_fun(double *state, double dt, double *out_5354864285430328391);
void car_F_fun(double *state, double dt, double *out_8387330887260154280);
void car_h_25(double *state, double *unused, double *out_8511299206176653652);
void car_H_25(double *state, double *unused, double *out_4831141683361744295);
void car_h_24(double *state, double *unused, double *out_2240178381642551870);
void car_H_24(double *state, double *unused, double *out_1823063774746441462);
void car_h_30(double *state, double *unused, double *out_9112717363790017206);
void car_H_30(double *state, double *unused, double *out_9087906060220199123);
void car_h_26(double *state, double *unused, double *out_4108119494084209463);
void car_H_26(double *state, double *unused, double *out_8572645002235800519);
void car_h_27(double *state, double *unused, double *out_3509625938515808007);
void car_H_27(double *state, double *unused, double *out_6913142748419774212);
void car_h_29(double *state, double *unused, double *out_8166282908843392673);
void car_H_29(double *state, double *unused, double *out_8848606669174960309);
void car_h_28(double *state, double *unused, double *out_2406004815218054329);
void car_H_28(double *state, double *unused, double *out_6884976397609634058);
void car_h_31(double *state, double *unused, double *out_748033949355981211);
void car_H_31(double *state, double *unused, double *out_9198853104469151995);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}