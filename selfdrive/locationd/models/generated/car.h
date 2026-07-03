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
void car_err_fun(double *nom_x, double *delta_x, double *out_5095523285720935963);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7157467776234621149);
void car_H_mod_fun(double *state, double *out_3219454610501945799);
void car_f_fun(double *state, double dt, double *out_8968218806304622496);
void car_F_fun(double *state, double dt, double *out_559280476475270084);
void car_h_25(double *state, double *unused, double *out_7874470337533308693);
void car_H_25(double *state, double *unused, double *out_1945350534564629578);
void car_h_24(double *state, double *unused, double *out_3796468718341357467);
void car_H_24(double *state, double *unused, double *out_8146383214415791004);
void car_h_30(double *state, double *unused, double *out_6473970437896871059);
void car_H_30(double *state, double *unused, double *out_2074689481707869648);
void car_h_26(double *state, double *unused, double *out_7417480290798533494);
void car_H_26(double *state, double *unused, double *out_5686853853438685802);
void car_h_27(double *state, double *unused, double *out_7535487684731910238);
void car_H_27(double *state, double *unused, double *out_4249452793508294559);
void car_h_29(double *state, double *unused, double *out_7077286322573348576);
void car_H_29(double *state, double *unused, double *out_5962815520377845592);
void car_h_28(double *state, double *unused, double *out_6513304307696012366);
void car_H_28(double *state, double *unused, double *out_7401529536262175450);
void car_h_31(double *state, double *unused, double *out_8149664399817814582);
void car_H_31(double *state, double *unused, double *out_1914704572687669150);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}