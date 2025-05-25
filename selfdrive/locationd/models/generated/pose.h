#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6053087006272086738);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1848428975880805561);
void pose_H_mod_fun(double *state, double *out_3183080408274160777);
void pose_f_fun(double *state, double dt, double *out_2001410838433046702);
void pose_F_fun(double *state, double dt, double *out_2415085859123987111);
void pose_h_4(double *state, double *unused, double *out_7740735704804213850);
void pose_H_4(double *state, double *unused, double *out_5761281257783660565);
void pose_h_10(double *state, double *unused, double *out_97048509807628744);
void pose_H_10(double *state, double *unused, double *out_4447383680712310759);
void pose_h_13(double *state, double *unused, double *out_756955009987038658);
void pose_H_13(double *state, double *unused, double *out_2549007432451327764);
void pose_h_14(double *state, double *unused, double *out_3752798373710015968);
void pose_H_14(double *state, double *unused, double *out_1798040401444176036);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}