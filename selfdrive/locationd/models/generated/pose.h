#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4144373577117027043);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6853650036846835829);
void pose_H_mod_fun(double *state, double *out_3371818439070572688);
void pose_f_fun(double *state, double dt, double *out_5714706012790040296);
void pose_F_fun(double *state, double dt, double *out_2453777362197051626);
void pose_h_4(double *state, double *unused, double *out_7475340564657993549);
void pose_H_4(double *state, double *unused, double *out_4569765920953470792);
void pose_h_10(double *state, double *unused, double *out_4511047330400710663);
void pose_H_10(double *state, double *unused, double *out_2217581622006004275);
void pose_h_13(double *state, double *unused, double *out_5268165593067890584);
void pose_H_13(double *state, double *unused, double *out_736010457650946768);
void pose_h_14(double *state, double *unused, double *out_7369017124756604631);
void pose_H_14(double *state, double *unused, double *out_1486977488658098496);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}