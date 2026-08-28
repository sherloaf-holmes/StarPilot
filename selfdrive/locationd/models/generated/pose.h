#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3780223817999612054);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7482788729204437735);
void pose_H_mod_fun(double *state, double *out_559578409299766791);
void pose_f_fun(double *state, double dt, double *out_2617827132714175645);
void pose_F_fun(double *state, double dt, double *out_7803734003668636083);
void pose_h_4(double *state, double *unused, double *out_937302404657292548);
void pose_H_4(double *state, double *unused, double *out_1757525891182664895);
void pose_h_10(double *state, double *unused, double *out_6324073732783034610);
void pose_H_10(double *state, double *unused, double *out_5216067087000817824);
void pose_h_13(double *state, double *unused, double *out_255942539802975373);
void pose_H_13(double *state, double *unused, double *out_2076229572119859129);
void pose_h_14(double *state, double *unused, double *out_3257165685410083893);
void pose_H_14(double *state, double *unused, double *out_1325262541112707401);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}