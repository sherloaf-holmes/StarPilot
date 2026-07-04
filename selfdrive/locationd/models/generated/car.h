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
void car_err_fun(double *nom_x, double *delta_x, double *out_6969232177100646924);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_526066650873287880);
void car_H_mod_fun(double *state, double *out_7612854989100743873);
void car_f_fun(double *state, double dt, double *out_3073702875103866416);
void car_F_fun(double *state, double dt, double *out_7034473432849563542);
void car_h_25(double *state, double *unused, double *out_3724589618616459119);
void car_H_25(double *state, double *unused, double *out_308483043873115932);
void car_h_24(double *state, double *unused, double *out_7937358655108004402);
void car_H_24(double *state, double *unused, double *out_3866408642675439068);
void car_h_30(double *state, double *unused, double *out_8398141063885333136);
void car_H_30(double *state, double *unused, double *out_2826816002380364559);
void car_h_26(double *state, double *unused, double *out_5690231515636645968);
void car_H_26(double *state, double *unused, double *out_3433020275000940292);
void car_h_27(double *state, double *unused, double *out_1867122279641779993);
void car_H_27(double *state, double *unused, double *out_652052690579939648);
void car_h_29(double *state, double *unused, double *out_6772755197076761891);
void car_H_29(double *state, double *unused, double *out_3337047346694756743);
void car_h_28(double *state, double *unused, double *out_7782753033375642329);
void car_H_28(double *state, double *unused, double *out_1745351670374773831);
void car_h_31(double *state, double *unused, double *out_87140090362436769);
void car_H_31(double *state, double *unused, double *out_4059228377234291768);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}