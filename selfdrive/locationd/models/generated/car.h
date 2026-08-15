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
void car_err_fun(double *nom_x, double *delta_x, double *out_6619387591846923441);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6255087751373156395);
void car_H_mod_fun(double *state, double *out_4439858067594842346);
void car_f_fun(double *state, double dt, double *out_5886307427686295053);
void car_F_fun(double *state, double dt, double *out_628600079770378397);
void car_h_25(double *state, double *unused, double *out_2070862304769966057);
void car_H_25(double *state, double *unused, double *out_9103194180930044430);
void car_h_24(double *state, double *unused, double *out_1698834673375970192);
void car_H_24(double *state, double *unused, double *out_8258197572146349031);
void car_h_30(double *state, double *unused, double *out_4084584891070694072);
void car_H_30(double *state, double *unused, double *out_2186503839438427675);
void car_h_26(double *state, double *unused, double *out_1141322324764630875);
void car_H_26(double *state, double *unused, double *out_5798668211169243829);
void car_h_27(double *state, double *unused, double *out_8940738334510884746);
void car_H_27(double *state, double *unused, double *out_4361267151238852586);
void car_h_29(double *state, double *unused, double *out_5565849718372860404);
void car_H_29(double *state, double *unused, double *out_6074629878108403619);
void car_h_28(double *state, double *unused, double *out_7997228481609222311);
void car_H_28(double *state, double *unused, double *out_7289715178531617423);
void car_h_31(double *state, double *unused, double *out_2346056367054471946);
void car_H_31(double *state, double *unused, double *out_2026518930418227177);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}