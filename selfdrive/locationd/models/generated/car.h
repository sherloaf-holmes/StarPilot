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
void car_err_fun(double *nom_x, double *delta_x, double *out_2512363639821553031);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1518432816014801920);
void car_H_mod_fun(double *state, double *out_335460623832969806);
void car_f_fun(double *state, double dt, double *out_1995423965239613252);
void car_F_fun(double *state, double dt, double *out_4354929907587826411);
void car_h_25(double *state, double *unused, double *out_1423072957174624207);
void car_H_25(double *state, double *unused, double *out_8857727602079267431);
void car_h_24(double *state, double *unused, double *out_3139525203150409044);
void car_H_24(double *state, double *unused, double *out_6632019818100398869);
void car_h_30(double *state, double *unused, double *out_6233965745404945676);
void car_H_30(double *state, double *unused, double *out_1941037260587650676);
void car_h_26(double *state, double *unused, double *out_1232292477744100031);
void car_H_26(double *state, double *unused, double *out_5847513152756227961);
void car_h_27(double *state, double *unused, double *out_6385452954855917439);
void car_H_27(double *state, double *unused, double *out_4115800572388075587);
void car_h_29(double *state, double *unused, double *out_2817692455755875660);
void car_H_29(double *state, double *unused, double *out_1430805916273258492);
void car_h_28(double *state, double *unused, double *out_1987500873574288427);
void car_H_28(double *state, double *unused, double *out_6513204933342789066);
void car_h_31(double *state, double *unused, double *out_3623860965696090643);
void car_H_31(double *state, double *unused, double *out_8827081640202307003);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}