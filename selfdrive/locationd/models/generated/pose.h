#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_793421623727173718);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6937176692902514454);
void pose_H_mod_fun(double *state, double *out_1217280767504544402);
void pose_f_fun(double *state, double dt, double *out_4609271159637541739);
void pose_F_fun(double *state, double dt, double *out_5279488839905480126);
void pose_h_4(double *state, double *unused, double *out_301709123607443688);
void pose_H_4(double *state, double *unused, double *out_4417690668606014426);
void pose_h_10(double *state, double *unused, double *out_7106035581154739398);
void pose_H_10(double *state, double *unused, double *out_5716162753714162166);
void pose_h_13(double *state, double *unused, double *out_9094498493959954093);
void pose_H_13(double *state, double *unused, double *out_3853088748924170322);
void pose_h_14(double *state, double *unused, double *out_5269288261350591165);
void pose_H_14(double *state, double *unused, double *out_7500479100901386722);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}