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
void car_err_fun(double *nom_x, double *delta_x, double *out_1216357632529856903);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3660226024408498118);
void car_H_mod_fun(double *state, double *out_8050632600465675677);
void car_f_fun(double *state, double dt, double *out_5799781428830426405);
void car_F_fun(double *state, double dt, double *out_5731779610633491442);
void car_h_25(double *state, double *unused, double *out_5328248241617488932);
void car_H_25(double *state, double *unused, double *out_7545298158265378965);
void car_h_24(double *state, double *unused, double *out_1519638865574766256);
void car_H_24(double *state, double *unused, double *out_8015755640308717689);
void car_h_30(double *state, double *unused, double *out_8395045831279462596);
void car_H_30(double *state, double *unused, double *out_7674637105408619035);
void car_h_26(double *state, double *unused, double *out_7791729946602985079);
void car_H_26(double *state, double *unused, double *out_7159942596570116427);
void car_h_27(double *state, double *unused, double *out_429736672376249024);
void car_H_27(double *state, double *unused, double *out_8597343656500507670);
void car_h_29(double *state, double *unused, double *out_1831701130526705992);
void car_H_29(double *state, double *unused, double *out_7164405761094226851);
void car_h_28(double *state, double *unused, double *out_3193621841167676208);
void car_H_28(double *state, double *unused, double *out_5200775489528900600);
void car_h_31(double *state, double *unused, double *out_3980778547408211502);
void car_H_31(double *state, double *unused, double *out_7514652196388418537);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}