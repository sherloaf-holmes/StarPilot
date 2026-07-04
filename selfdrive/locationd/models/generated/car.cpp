#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6969232177100646924) {
   out_6969232177100646924[0] = delta_x[0] + nom_x[0];
   out_6969232177100646924[1] = delta_x[1] + nom_x[1];
   out_6969232177100646924[2] = delta_x[2] + nom_x[2];
   out_6969232177100646924[3] = delta_x[3] + nom_x[3];
   out_6969232177100646924[4] = delta_x[4] + nom_x[4];
   out_6969232177100646924[5] = delta_x[5] + nom_x[5];
   out_6969232177100646924[6] = delta_x[6] + nom_x[6];
   out_6969232177100646924[7] = delta_x[7] + nom_x[7];
   out_6969232177100646924[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_526066650873287880) {
   out_526066650873287880[0] = -nom_x[0] + true_x[0];
   out_526066650873287880[1] = -nom_x[1] + true_x[1];
   out_526066650873287880[2] = -nom_x[2] + true_x[2];
   out_526066650873287880[3] = -nom_x[3] + true_x[3];
   out_526066650873287880[4] = -nom_x[4] + true_x[4];
   out_526066650873287880[5] = -nom_x[5] + true_x[5];
   out_526066650873287880[6] = -nom_x[6] + true_x[6];
   out_526066650873287880[7] = -nom_x[7] + true_x[7];
   out_526066650873287880[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7612854989100743873) {
   out_7612854989100743873[0] = 1.0;
   out_7612854989100743873[1] = 0.0;
   out_7612854989100743873[2] = 0.0;
   out_7612854989100743873[3] = 0.0;
   out_7612854989100743873[4] = 0.0;
   out_7612854989100743873[5] = 0.0;
   out_7612854989100743873[6] = 0.0;
   out_7612854989100743873[7] = 0.0;
   out_7612854989100743873[8] = 0.0;
   out_7612854989100743873[9] = 0.0;
   out_7612854989100743873[10] = 1.0;
   out_7612854989100743873[11] = 0.0;
   out_7612854989100743873[12] = 0.0;
   out_7612854989100743873[13] = 0.0;
   out_7612854989100743873[14] = 0.0;
   out_7612854989100743873[15] = 0.0;
   out_7612854989100743873[16] = 0.0;
   out_7612854989100743873[17] = 0.0;
   out_7612854989100743873[18] = 0.0;
   out_7612854989100743873[19] = 0.0;
   out_7612854989100743873[20] = 1.0;
   out_7612854989100743873[21] = 0.0;
   out_7612854989100743873[22] = 0.0;
   out_7612854989100743873[23] = 0.0;
   out_7612854989100743873[24] = 0.0;
   out_7612854989100743873[25] = 0.0;
   out_7612854989100743873[26] = 0.0;
   out_7612854989100743873[27] = 0.0;
   out_7612854989100743873[28] = 0.0;
   out_7612854989100743873[29] = 0.0;
   out_7612854989100743873[30] = 1.0;
   out_7612854989100743873[31] = 0.0;
   out_7612854989100743873[32] = 0.0;
   out_7612854989100743873[33] = 0.0;
   out_7612854989100743873[34] = 0.0;
   out_7612854989100743873[35] = 0.0;
   out_7612854989100743873[36] = 0.0;
   out_7612854989100743873[37] = 0.0;
   out_7612854989100743873[38] = 0.0;
   out_7612854989100743873[39] = 0.0;
   out_7612854989100743873[40] = 1.0;
   out_7612854989100743873[41] = 0.0;
   out_7612854989100743873[42] = 0.0;
   out_7612854989100743873[43] = 0.0;
   out_7612854989100743873[44] = 0.0;
   out_7612854989100743873[45] = 0.0;
   out_7612854989100743873[46] = 0.0;
   out_7612854989100743873[47] = 0.0;
   out_7612854989100743873[48] = 0.0;
   out_7612854989100743873[49] = 0.0;
   out_7612854989100743873[50] = 1.0;
   out_7612854989100743873[51] = 0.0;
   out_7612854989100743873[52] = 0.0;
   out_7612854989100743873[53] = 0.0;
   out_7612854989100743873[54] = 0.0;
   out_7612854989100743873[55] = 0.0;
   out_7612854989100743873[56] = 0.0;
   out_7612854989100743873[57] = 0.0;
   out_7612854989100743873[58] = 0.0;
   out_7612854989100743873[59] = 0.0;
   out_7612854989100743873[60] = 1.0;
   out_7612854989100743873[61] = 0.0;
   out_7612854989100743873[62] = 0.0;
   out_7612854989100743873[63] = 0.0;
   out_7612854989100743873[64] = 0.0;
   out_7612854989100743873[65] = 0.0;
   out_7612854989100743873[66] = 0.0;
   out_7612854989100743873[67] = 0.0;
   out_7612854989100743873[68] = 0.0;
   out_7612854989100743873[69] = 0.0;
   out_7612854989100743873[70] = 1.0;
   out_7612854989100743873[71] = 0.0;
   out_7612854989100743873[72] = 0.0;
   out_7612854989100743873[73] = 0.0;
   out_7612854989100743873[74] = 0.0;
   out_7612854989100743873[75] = 0.0;
   out_7612854989100743873[76] = 0.0;
   out_7612854989100743873[77] = 0.0;
   out_7612854989100743873[78] = 0.0;
   out_7612854989100743873[79] = 0.0;
   out_7612854989100743873[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3073702875103866416) {
   out_3073702875103866416[0] = state[0];
   out_3073702875103866416[1] = state[1];
   out_3073702875103866416[2] = state[2];
   out_3073702875103866416[3] = state[3];
   out_3073702875103866416[4] = state[4];
   out_3073702875103866416[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3073702875103866416[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3073702875103866416[7] = state[7];
   out_3073702875103866416[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7034473432849563542) {
   out_7034473432849563542[0] = 1;
   out_7034473432849563542[1] = 0;
   out_7034473432849563542[2] = 0;
   out_7034473432849563542[3] = 0;
   out_7034473432849563542[4] = 0;
   out_7034473432849563542[5] = 0;
   out_7034473432849563542[6] = 0;
   out_7034473432849563542[7] = 0;
   out_7034473432849563542[8] = 0;
   out_7034473432849563542[9] = 0;
   out_7034473432849563542[10] = 1;
   out_7034473432849563542[11] = 0;
   out_7034473432849563542[12] = 0;
   out_7034473432849563542[13] = 0;
   out_7034473432849563542[14] = 0;
   out_7034473432849563542[15] = 0;
   out_7034473432849563542[16] = 0;
   out_7034473432849563542[17] = 0;
   out_7034473432849563542[18] = 0;
   out_7034473432849563542[19] = 0;
   out_7034473432849563542[20] = 1;
   out_7034473432849563542[21] = 0;
   out_7034473432849563542[22] = 0;
   out_7034473432849563542[23] = 0;
   out_7034473432849563542[24] = 0;
   out_7034473432849563542[25] = 0;
   out_7034473432849563542[26] = 0;
   out_7034473432849563542[27] = 0;
   out_7034473432849563542[28] = 0;
   out_7034473432849563542[29] = 0;
   out_7034473432849563542[30] = 1;
   out_7034473432849563542[31] = 0;
   out_7034473432849563542[32] = 0;
   out_7034473432849563542[33] = 0;
   out_7034473432849563542[34] = 0;
   out_7034473432849563542[35] = 0;
   out_7034473432849563542[36] = 0;
   out_7034473432849563542[37] = 0;
   out_7034473432849563542[38] = 0;
   out_7034473432849563542[39] = 0;
   out_7034473432849563542[40] = 1;
   out_7034473432849563542[41] = 0;
   out_7034473432849563542[42] = 0;
   out_7034473432849563542[43] = 0;
   out_7034473432849563542[44] = 0;
   out_7034473432849563542[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7034473432849563542[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7034473432849563542[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7034473432849563542[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7034473432849563542[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7034473432849563542[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7034473432849563542[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7034473432849563542[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7034473432849563542[53] = -9.8100000000000005*dt;
   out_7034473432849563542[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7034473432849563542[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7034473432849563542[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7034473432849563542[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7034473432849563542[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7034473432849563542[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7034473432849563542[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7034473432849563542[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7034473432849563542[62] = 0;
   out_7034473432849563542[63] = 0;
   out_7034473432849563542[64] = 0;
   out_7034473432849563542[65] = 0;
   out_7034473432849563542[66] = 0;
   out_7034473432849563542[67] = 0;
   out_7034473432849563542[68] = 0;
   out_7034473432849563542[69] = 0;
   out_7034473432849563542[70] = 1;
   out_7034473432849563542[71] = 0;
   out_7034473432849563542[72] = 0;
   out_7034473432849563542[73] = 0;
   out_7034473432849563542[74] = 0;
   out_7034473432849563542[75] = 0;
   out_7034473432849563542[76] = 0;
   out_7034473432849563542[77] = 0;
   out_7034473432849563542[78] = 0;
   out_7034473432849563542[79] = 0;
   out_7034473432849563542[80] = 1;
}
void h_25(double *state, double *unused, double *out_3724589618616459119) {
   out_3724589618616459119[0] = state[6];
}
void H_25(double *state, double *unused, double *out_308483043873115932) {
   out_308483043873115932[0] = 0;
   out_308483043873115932[1] = 0;
   out_308483043873115932[2] = 0;
   out_308483043873115932[3] = 0;
   out_308483043873115932[4] = 0;
   out_308483043873115932[5] = 0;
   out_308483043873115932[6] = 1;
   out_308483043873115932[7] = 0;
   out_308483043873115932[8] = 0;
}
void h_24(double *state, double *unused, double *out_7937358655108004402) {
   out_7937358655108004402[0] = state[4];
   out_7937358655108004402[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3866408642675439068) {
   out_3866408642675439068[0] = 0;
   out_3866408642675439068[1] = 0;
   out_3866408642675439068[2] = 0;
   out_3866408642675439068[3] = 0;
   out_3866408642675439068[4] = 1;
   out_3866408642675439068[5] = 0;
   out_3866408642675439068[6] = 0;
   out_3866408642675439068[7] = 0;
   out_3866408642675439068[8] = 0;
   out_3866408642675439068[9] = 0;
   out_3866408642675439068[10] = 0;
   out_3866408642675439068[11] = 0;
   out_3866408642675439068[12] = 0;
   out_3866408642675439068[13] = 0;
   out_3866408642675439068[14] = 1;
   out_3866408642675439068[15] = 0;
   out_3866408642675439068[16] = 0;
   out_3866408642675439068[17] = 0;
}
void h_30(double *state, double *unused, double *out_8398141063885333136) {
   out_8398141063885333136[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2826816002380364559) {
   out_2826816002380364559[0] = 0;
   out_2826816002380364559[1] = 0;
   out_2826816002380364559[2] = 0;
   out_2826816002380364559[3] = 0;
   out_2826816002380364559[4] = 1;
   out_2826816002380364559[5] = 0;
   out_2826816002380364559[6] = 0;
   out_2826816002380364559[7] = 0;
   out_2826816002380364559[8] = 0;
}
void h_26(double *state, double *unused, double *out_5690231515636645968) {
   out_5690231515636645968[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3433020275000940292) {
   out_3433020275000940292[0] = 0;
   out_3433020275000940292[1] = 0;
   out_3433020275000940292[2] = 0;
   out_3433020275000940292[3] = 0;
   out_3433020275000940292[4] = 0;
   out_3433020275000940292[5] = 0;
   out_3433020275000940292[6] = 0;
   out_3433020275000940292[7] = 1;
   out_3433020275000940292[8] = 0;
}
void h_27(double *state, double *unused, double *out_1867122279641779993) {
   out_1867122279641779993[0] = state[3];
}
void H_27(double *state, double *unused, double *out_652052690579939648) {
   out_652052690579939648[0] = 0;
   out_652052690579939648[1] = 0;
   out_652052690579939648[2] = 0;
   out_652052690579939648[3] = 1;
   out_652052690579939648[4] = 0;
   out_652052690579939648[5] = 0;
   out_652052690579939648[6] = 0;
   out_652052690579939648[7] = 0;
   out_652052690579939648[8] = 0;
}
void h_29(double *state, double *unused, double *out_6772755197076761891) {
   out_6772755197076761891[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3337047346694756743) {
   out_3337047346694756743[0] = 0;
   out_3337047346694756743[1] = 1;
   out_3337047346694756743[2] = 0;
   out_3337047346694756743[3] = 0;
   out_3337047346694756743[4] = 0;
   out_3337047346694756743[5] = 0;
   out_3337047346694756743[6] = 0;
   out_3337047346694756743[7] = 0;
   out_3337047346694756743[8] = 0;
}
void h_28(double *state, double *unused, double *out_7782753033375642329) {
   out_7782753033375642329[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1745351670374773831) {
   out_1745351670374773831[0] = 1;
   out_1745351670374773831[1] = 0;
   out_1745351670374773831[2] = 0;
   out_1745351670374773831[3] = 0;
   out_1745351670374773831[4] = 0;
   out_1745351670374773831[5] = 0;
   out_1745351670374773831[6] = 0;
   out_1745351670374773831[7] = 0;
   out_1745351670374773831[8] = 0;
}
void h_31(double *state, double *unused, double *out_87140090362436769) {
   out_87140090362436769[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4059228377234291768) {
   out_4059228377234291768[0] = 0;
   out_4059228377234291768[1] = 0;
   out_4059228377234291768[2] = 0;
   out_4059228377234291768[3] = 0;
   out_4059228377234291768[4] = 0;
   out_4059228377234291768[5] = 0;
   out_4059228377234291768[6] = 0;
   out_4059228377234291768[7] = 0;
   out_4059228377234291768[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_6969232177100646924) {
  err_fun(nom_x, delta_x, out_6969232177100646924);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_526066650873287880) {
  inv_err_fun(nom_x, true_x, out_526066650873287880);
}
void car_H_mod_fun(double *state, double *out_7612854989100743873) {
  H_mod_fun(state, out_7612854989100743873);
}
void car_f_fun(double *state, double dt, double *out_3073702875103866416) {
  f_fun(state,  dt, out_3073702875103866416);
}
void car_F_fun(double *state, double dt, double *out_7034473432849563542) {
  F_fun(state,  dt, out_7034473432849563542);
}
void car_h_25(double *state, double *unused, double *out_3724589618616459119) {
  h_25(state, unused, out_3724589618616459119);
}
void car_H_25(double *state, double *unused, double *out_308483043873115932) {
  H_25(state, unused, out_308483043873115932);
}
void car_h_24(double *state, double *unused, double *out_7937358655108004402) {
  h_24(state, unused, out_7937358655108004402);
}
void car_H_24(double *state, double *unused, double *out_3866408642675439068) {
  H_24(state, unused, out_3866408642675439068);
}
void car_h_30(double *state, double *unused, double *out_8398141063885333136) {
  h_30(state, unused, out_8398141063885333136);
}
void car_H_30(double *state, double *unused, double *out_2826816002380364559) {
  H_30(state, unused, out_2826816002380364559);
}
void car_h_26(double *state, double *unused, double *out_5690231515636645968) {
  h_26(state, unused, out_5690231515636645968);
}
void car_H_26(double *state, double *unused, double *out_3433020275000940292) {
  H_26(state, unused, out_3433020275000940292);
}
void car_h_27(double *state, double *unused, double *out_1867122279641779993) {
  h_27(state, unused, out_1867122279641779993);
}
void car_H_27(double *state, double *unused, double *out_652052690579939648) {
  H_27(state, unused, out_652052690579939648);
}
void car_h_29(double *state, double *unused, double *out_6772755197076761891) {
  h_29(state, unused, out_6772755197076761891);
}
void car_H_29(double *state, double *unused, double *out_3337047346694756743) {
  H_29(state, unused, out_3337047346694756743);
}
void car_h_28(double *state, double *unused, double *out_7782753033375642329) {
  h_28(state, unused, out_7782753033375642329);
}
void car_H_28(double *state, double *unused, double *out_1745351670374773831) {
  H_28(state, unused, out_1745351670374773831);
}
void car_h_31(double *state, double *unused, double *out_87140090362436769) {
  h_31(state, unused, out_87140090362436769);
}
void car_H_31(double *state, double *unused, double *out_4059228377234291768) {
  H_31(state, unused, out_4059228377234291768);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
