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
void car_err_fun(double *nom_x, double *delta_x, double *out_3891823301120817358);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7078103695220120208);
void car_H_mod_fun(double *state, double *out_7605334782961292562);
void car_f_fun(double *state, double dt, double *out_285885356126369333);
void car_F_fun(double *state, double dt, double *out_9130501085059811902);
void car_h_25(double *state, double *unused, double *out_7426870835523995815);
void car_H_25(double *state, double *unused, double *out_6780537292649003006);
void car_h_24(double *state, double *unused, double *out_5827732866319639362);
void car_H_24(double *state, double *unused, double *out_637854341027923887);
void car_h_30(double *state, double *unused, double *out_3138600587431506616);
void car_H_30(double *state, double *unused, double *out_7138510450932940412);
void car_h_26(double *state, double *unused, double *out_8140273855092352261);
void car_H_26(double *state, double *unused, double *out_7924703462186492386);
void car_h_27(double *state, double *unused, double *out_8030186720200473332);
void car_H_27(double *state, double *unused, double *out_9084639551592667987);
void car_h_29(double *state, double *unused, double *out_2504129283649450219);
void car_H_29(double *state, double *unused, double *out_7648741795247332596);
void car_h_28(double *state, double *unused, double *out_7086676867298810897);
void car_H_28(double *state, double *unused, double *out_2566342778177802022);
void car_h_31(double *state, double *unused, double *out_3256607981364883360);
void car_H_31(double *state, double *unused, double *out_7298495359953140910);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}