#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8853800063451770622);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1474102248584144178);
void pose_H_mod_fun(double *state, double *out_2871704563598328823);
void pose_f_fun(double *state, double dt, double *out_7815213456120633288);
void pose_F_fun(double *state, double dt, double *out_5268289123395507135);
void pose_h_4(double *state, double *unused, double *out_3086539292408065832);
void pose_H_4(double *state, double *unused, double *out_2280813821440751912);
void pose_h_10(double *state, double *unused, double *out_7331610063879172077);
void pose_H_10(double *state, double *unused, double *out_1458363770220884896);
void pose_h_13(double *state, double *unused, double *out_4988216010094665786);
void pose_H_13(double *state, double *unused, double *out_5493087646773084713);
void pose_h_14(double *state, double *unused, double *out_3365460086081990543);
void pose_H_14(double *state, double *unused, double *out_801974610854620384);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}