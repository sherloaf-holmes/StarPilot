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
void car_err_fun(double *nom_x, double *delta_x, double *out_7208701368394961077);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5744805479138773162);
void car_H_mod_fun(double *state, double *out_5233187869129643325);
void car_f_fun(double *state, double dt, double *out_7910145160920043829);
void car_F_fun(double *state, double dt, double *out_8682084775257829483);
void car_h_25(double *state, double *unused, double *out_8040854508369159628);
void car_H_25(double *state, double *unused, double *out_3960000356782593912);
void car_h_24(double *state, double *unused, double *out_5925075352520764756);
void car_H_24(double *state, double *unused, double *out_5268064829286601313);
void car_h_30(double *state, double *unused, double *out_1270019282018808692);
void car_H_30(double *state, double *unused, double *out_8487696686910202110);
void car_h_26(double *state, double *unused, double *out_2213529134920471127);
void car_H_26(double *state, double *unused, double *out_7701503675656650136);
void car_h_27(double *state, double *unused, double *out_8644170393045637145);
void car_H_27(double *state, double *unused, double *out_6264102615726258893);
void car_h_29(double *state, double *unused, double *out_6165124152409892121);
void car_H_29(double *state, double *unused, double *out_7977465342595809926);
void car_h_28(double *state, double *unused, double *out_1006264216397917331);
void car_H_28(double *state, double *unused, double *out_5386879714044211116);
void car_h_31(double *state, double *unused, double *out_2642624308519719547);
void car_H_31(double *state, double *unused, double *out_8327711777890001612);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}