#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8735210990522162572);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7512947709845212137);
void pose_H_mod_fun(double *state, double *out_5447571817541560059);
void pose_f_fun(double *state, double dt, double *out_8475410656787984151);
void pose_F_fun(double *state, double dt, double *out_1772783662641610101);
void pose_h_4(double *state, double *unused, double *out_6916116063039855928);
void pose_H_4(double *state, double *unused, double *out_4133444241626837871);
void pose_h_10(double *state, double *unused, double *out_2205799671886878540);
void pose_H_10(double *state, double *unused, double *out_5975290705310221044);
void pose_h_13(double *state, double *unused, double *out_1493083868240557826);
void pose_H_13(double *state, double *unused, double *out_7345718066959170672);
void pose_h_14(double *state, double *unused, double *out_3088699159055375359);
void pose_H_14(double *state, double *unused, double *out_8096685097966322400);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}