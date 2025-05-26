#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3885858244012813024);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7758055863153927741);
void pose_H_mod_fun(double *state, double *out_4317949509398023693);
void pose_f_fun(double *state, double dt, double *out_8188623410399122820);
void pose_F_fun(double *state, double dt, double *out_5523207584579487610);
void pose_h_4(double *state, double *unused, double *out_2098647727660446226);
void pose_H_4(double *state, double *unused, double *out_7592171588188972946);
void pose_h_10(double *state, double *unused, double *out_5052239660944612817);
void pose_H_10(double *state, double *unused, double *out_8850730047157910148);
void pose_h_13(double *state, double *unused, double *out_6619314201641466470);
void pose_H_13(double *state, double *unused, double *out_18459620127727983);
void pose_h_14(double *state, double *unused, double *out_1585921583011697059);
void pose_H_14(double *state, double *unused, double *out_3628930731849488417);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}