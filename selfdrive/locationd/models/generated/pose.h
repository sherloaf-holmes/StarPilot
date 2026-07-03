#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5453162044416851201);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2848752773381496345);
void pose_H_mod_fun(double *state, double *out_4906589349598379822);
void pose_f_fun(double *state, double dt, double *out_2760483319111957401);
void pose_F_fun(double *state, double dt, double *out_2462794523887094837);
void pose_h_4(double *state, double *unused, double *out_3872084989267929897);
void pose_H_4(double *state, double *unused, double *out_2518858984437369523);
void pose_h_10(double *state, double *unused, double *out_3895192167056429518);
void pose_H_10(double *state, double *unused, double *out_5406689180752611899);
void pose_h_13(double *state, double *unused, double *out_6846163796915800555);
void pose_H_13(double *state, double *unused, double *out_5731132809769702324);
void pose_h_14(double *state, double *unused, double *out_4572829225510058656);
void pose_H_14(double *state, double *unused, double *out_563929447858002773);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}