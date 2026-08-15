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
void err_fun(double *nom_x, double *delta_x, double *out_6619387591846923441) {
   out_6619387591846923441[0] = delta_x[0] + nom_x[0];
   out_6619387591846923441[1] = delta_x[1] + nom_x[1];
   out_6619387591846923441[2] = delta_x[2] + nom_x[2];
   out_6619387591846923441[3] = delta_x[3] + nom_x[3];
   out_6619387591846923441[4] = delta_x[4] + nom_x[4];
   out_6619387591846923441[5] = delta_x[5] + nom_x[5];
   out_6619387591846923441[6] = delta_x[6] + nom_x[6];
   out_6619387591846923441[7] = delta_x[7] + nom_x[7];
   out_6619387591846923441[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6255087751373156395) {
   out_6255087751373156395[0] = -nom_x[0] + true_x[0];
   out_6255087751373156395[1] = -nom_x[1] + true_x[1];
   out_6255087751373156395[2] = -nom_x[2] + true_x[2];
   out_6255087751373156395[3] = -nom_x[3] + true_x[3];
   out_6255087751373156395[4] = -nom_x[4] + true_x[4];
   out_6255087751373156395[5] = -nom_x[5] + true_x[5];
   out_6255087751373156395[6] = -nom_x[6] + true_x[6];
   out_6255087751373156395[7] = -nom_x[7] + true_x[7];
   out_6255087751373156395[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4439858067594842346) {
   out_4439858067594842346[0] = 1.0;
   out_4439858067594842346[1] = 0.0;
   out_4439858067594842346[2] = 0.0;
   out_4439858067594842346[3] = 0.0;
   out_4439858067594842346[4] = 0.0;
   out_4439858067594842346[5] = 0.0;
   out_4439858067594842346[6] = 0.0;
   out_4439858067594842346[7] = 0.0;
   out_4439858067594842346[8] = 0.0;
   out_4439858067594842346[9] = 0.0;
   out_4439858067594842346[10] = 1.0;
   out_4439858067594842346[11] = 0.0;
   out_4439858067594842346[12] = 0.0;
   out_4439858067594842346[13] = 0.0;
   out_4439858067594842346[14] = 0.0;
   out_4439858067594842346[15] = 0.0;
   out_4439858067594842346[16] = 0.0;
   out_4439858067594842346[17] = 0.0;
   out_4439858067594842346[18] = 0.0;
   out_4439858067594842346[19] = 0.0;
   out_4439858067594842346[20] = 1.0;
   out_4439858067594842346[21] = 0.0;
   out_4439858067594842346[22] = 0.0;
   out_4439858067594842346[23] = 0.0;
   out_4439858067594842346[24] = 0.0;
   out_4439858067594842346[25] = 0.0;
   out_4439858067594842346[26] = 0.0;
   out_4439858067594842346[27] = 0.0;
   out_4439858067594842346[28] = 0.0;
   out_4439858067594842346[29] = 0.0;
   out_4439858067594842346[30] = 1.0;
   out_4439858067594842346[31] = 0.0;
   out_4439858067594842346[32] = 0.0;
   out_4439858067594842346[33] = 0.0;
   out_4439858067594842346[34] = 0.0;
   out_4439858067594842346[35] = 0.0;
   out_4439858067594842346[36] = 0.0;
   out_4439858067594842346[37] = 0.0;
   out_4439858067594842346[38] = 0.0;
   out_4439858067594842346[39] = 0.0;
   out_4439858067594842346[40] = 1.0;
   out_4439858067594842346[41] = 0.0;
   out_4439858067594842346[42] = 0.0;
   out_4439858067594842346[43] = 0.0;
   out_4439858067594842346[44] = 0.0;
   out_4439858067594842346[45] = 0.0;
   out_4439858067594842346[46] = 0.0;
   out_4439858067594842346[47] = 0.0;
   out_4439858067594842346[48] = 0.0;
   out_4439858067594842346[49] = 0.0;
   out_4439858067594842346[50] = 1.0;
   out_4439858067594842346[51] = 0.0;
   out_4439858067594842346[52] = 0.0;
   out_4439858067594842346[53] = 0.0;
   out_4439858067594842346[54] = 0.0;
   out_4439858067594842346[55] = 0.0;
   out_4439858067594842346[56] = 0.0;
   out_4439858067594842346[57] = 0.0;
   out_4439858067594842346[58] = 0.0;
   out_4439858067594842346[59] = 0.0;
   out_4439858067594842346[60] = 1.0;
   out_4439858067594842346[61] = 0.0;
   out_4439858067594842346[62] = 0.0;
   out_4439858067594842346[63] = 0.0;
   out_4439858067594842346[64] = 0.0;
   out_4439858067594842346[65] = 0.0;
   out_4439858067594842346[66] = 0.0;
   out_4439858067594842346[67] = 0.0;
   out_4439858067594842346[68] = 0.0;
   out_4439858067594842346[69] = 0.0;
   out_4439858067594842346[70] = 1.0;
   out_4439858067594842346[71] = 0.0;
   out_4439858067594842346[72] = 0.0;
   out_4439858067594842346[73] = 0.0;
   out_4439858067594842346[74] = 0.0;
   out_4439858067594842346[75] = 0.0;
   out_4439858067594842346[76] = 0.0;
   out_4439858067594842346[77] = 0.0;
   out_4439858067594842346[78] = 0.0;
   out_4439858067594842346[79] = 0.0;
   out_4439858067594842346[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5886307427686295053) {
   out_5886307427686295053[0] = state[0];
   out_5886307427686295053[1] = state[1];
   out_5886307427686295053[2] = state[2];
   out_5886307427686295053[3] = state[3];
   out_5886307427686295053[4] = state[4];
   out_5886307427686295053[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5886307427686295053[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5886307427686295053[7] = state[7];
   out_5886307427686295053[8] = state[8];
}
void F_fun(double *state, double dt, double *out_628600079770378397) {
   out_628600079770378397[0] = 1;
   out_628600079770378397[1] = 0;
   out_628600079770378397[2] = 0;
   out_628600079770378397[3] = 0;
   out_628600079770378397[4] = 0;
   out_628600079770378397[5] = 0;
   out_628600079770378397[6] = 0;
   out_628600079770378397[7] = 0;
   out_628600079770378397[8] = 0;
   out_628600079770378397[9] = 0;
   out_628600079770378397[10] = 1;
   out_628600079770378397[11] = 0;
   out_628600079770378397[12] = 0;
   out_628600079770378397[13] = 0;
   out_628600079770378397[14] = 0;
   out_628600079770378397[15] = 0;
   out_628600079770378397[16] = 0;
   out_628600079770378397[17] = 0;
   out_628600079770378397[18] = 0;
   out_628600079770378397[19] = 0;
   out_628600079770378397[20] = 1;
   out_628600079770378397[21] = 0;
   out_628600079770378397[22] = 0;
   out_628600079770378397[23] = 0;
   out_628600079770378397[24] = 0;
   out_628600079770378397[25] = 0;
   out_628600079770378397[26] = 0;
   out_628600079770378397[27] = 0;
   out_628600079770378397[28] = 0;
   out_628600079770378397[29] = 0;
   out_628600079770378397[30] = 1;
   out_628600079770378397[31] = 0;
   out_628600079770378397[32] = 0;
   out_628600079770378397[33] = 0;
   out_628600079770378397[34] = 0;
   out_628600079770378397[35] = 0;
   out_628600079770378397[36] = 0;
   out_628600079770378397[37] = 0;
   out_628600079770378397[38] = 0;
   out_628600079770378397[39] = 0;
   out_628600079770378397[40] = 1;
   out_628600079770378397[41] = 0;
   out_628600079770378397[42] = 0;
   out_628600079770378397[43] = 0;
   out_628600079770378397[44] = 0;
   out_628600079770378397[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_628600079770378397[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_628600079770378397[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_628600079770378397[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_628600079770378397[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_628600079770378397[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_628600079770378397[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_628600079770378397[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_628600079770378397[53] = -9.8100000000000005*dt;
   out_628600079770378397[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_628600079770378397[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_628600079770378397[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_628600079770378397[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_628600079770378397[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_628600079770378397[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_628600079770378397[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_628600079770378397[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_628600079770378397[62] = 0;
   out_628600079770378397[63] = 0;
   out_628600079770378397[64] = 0;
   out_628600079770378397[65] = 0;
   out_628600079770378397[66] = 0;
   out_628600079770378397[67] = 0;
   out_628600079770378397[68] = 0;
   out_628600079770378397[69] = 0;
   out_628600079770378397[70] = 1;
   out_628600079770378397[71] = 0;
   out_628600079770378397[72] = 0;
   out_628600079770378397[73] = 0;
   out_628600079770378397[74] = 0;
   out_628600079770378397[75] = 0;
   out_628600079770378397[76] = 0;
   out_628600079770378397[77] = 0;
   out_628600079770378397[78] = 0;
   out_628600079770378397[79] = 0;
   out_628600079770378397[80] = 1;
}
void h_25(double *state, double *unused, double *out_2070862304769966057) {
   out_2070862304769966057[0] = state[6];
}
void H_25(double *state, double *unused, double *out_9103194180930044430) {
   out_9103194180930044430[0] = 0;
   out_9103194180930044430[1] = 0;
   out_9103194180930044430[2] = 0;
   out_9103194180930044430[3] = 0;
   out_9103194180930044430[4] = 0;
   out_9103194180930044430[5] = 0;
   out_9103194180930044430[6] = 1;
   out_9103194180930044430[7] = 0;
   out_9103194180930044430[8] = 0;
}
void h_24(double *state, double *unused, double *out_1698834673375970192) {
   out_1698834673375970192[0] = state[4];
   out_1698834673375970192[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8258197572146349031) {
   out_8258197572146349031[0] = 0;
   out_8258197572146349031[1] = 0;
   out_8258197572146349031[2] = 0;
   out_8258197572146349031[3] = 0;
   out_8258197572146349031[4] = 1;
   out_8258197572146349031[5] = 0;
   out_8258197572146349031[6] = 0;
   out_8258197572146349031[7] = 0;
   out_8258197572146349031[8] = 0;
   out_8258197572146349031[9] = 0;
   out_8258197572146349031[10] = 0;
   out_8258197572146349031[11] = 0;
   out_8258197572146349031[12] = 0;
   out_8258197572146349031[13] = 0;
   out_8258197572146349031[14] = 1;
   out_8258197572146349031[15] = 0;
   out_8258197572146349031[16] = 0;
   out_8258197572146349031[17] = 0;
}
void h_30(double *state, double *unused, double *out_4084584891070694072) {
   out_4084584891070694072[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2186503839438427675) {
   out_2186503839438427675[0] = 0;
   out_2186503839438427675[1] = 0;
   out_2186503839438427675[2] = 0;
   out_2186503839438427675[3] = 0;
   out_2186503839438427675[4] = 1;
   out_2186503839438427675[5] = 0;
   out_2186503839438427675[6] = 0;
   out_2186503839438427675[7] = 0;
   out_2186503839438427675[8] = 0;
}
void h_26(double *state, double *unused, double *out_1141322324764630875) {
   out_1141322324764630875[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5798668211169243829) {
   out_5798668211169243829[0] = 0;
   out_5798668211169243829[1] = 0;
   out_5798668211169243829[2] = 0;
   out_5798668211169243829[3] = 0;
   out_5798668211169243829[4] = 0;
   out_5798668211169243829[5] = 0;
   out_5798668211169243829[6] = 0;
   out_5798668211169243829[7] = 1;
   out_5798668211169243829[8] = 0;
}
void h_27(double *state, double *unused, double *out_8940738334510884746) {
   out_8940738334510884746[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4361267151238852586) {
   out_4361267151238852586[0] = 0;
   out_4361267151238852586[1] = 0;
   out_4361267151238852586[2] = 0;
   out_4361267151238852586[3] = 1;
   out_4361267151238852586[4] = 0;
   out_4361267151238852586[5] = 0;
   out_4361267151238852586[6] = 0;
   out_4361267151238852586[7] = 0;
   out_4361267151238852586[8] = 0;
}
void h_29(double *state, double *unused, double *out_5565849718372860404) {
   out_5565849718372860404[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6074629878108403619) {
   out_6074629878108403619[0] = 0;
   out_6074629878108403619[1] = 1;
   out_6074629878108403619[2] = 0;
   out_6074629878108403619[3] = 0;
   out_6074629878108403619[4] = 0;
   out_6074629878108403619[5] = 0;
   out_6074629878108403619[6] = 0;
   out_6074629878108403619[7] = 0;
   out_6074629878108403619[8] = 0;
}
void h_28(double *state, double *unused, double *out_7997228481609222311) {
   out_7997228481609222311[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7289715178531617423) {
   out_7289715178531617423[0] = 1;
   out_7289715178531617423[1] = 0;
   out_7289715178531617423[2] = 0;
   out_7289715178531617423[3] = 0;
   out_7289715178531617423[4] = 0;
   out_7289715178531617423[5] = 0;
   out_7289715178531617423[6] = 0;
   out_7289715178531617423[7] = 0;
   out_7289715178531617423[8] = 0;
}
void h_31(double *state, double *unused, double *out_2346056367054471946) {
   out_2346056367054471946[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2026518930418227177) {
   out_2026518930418227177[0] = 0;
   out_2026518930418227177[1] = 0;
   out_2026518930418227177[2] = 0;
   out_2026518930418227177[3] = 0;
   out_2026518930418227177[4] = 0;
   out_2026518930418227177[5] = 0;
   out_2026518930418227177[6] = 0;
   out_2026518930418227177[7] = 0;
   out_2026518930418227177[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6619387591846923441) {
  err_fun(nom_x, delta_x, out_6619387591846923441);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6255087751373156395) {
  inv_err_fun(nom_x, true_x, out_6255087751373156395);
}
void car_H_mod_fun(double *state, double *out_4439858067594842346) {
  H_mod_fun(state, out_4439858067594842346);
}
void car_f_fun(double *state, double dt, double *out_5886307427686295053) {
  f_fun(state,  dt, out_5886307427686295053);
}
void car_F_fun(double *state, double dt, double *out_628600079770378397) {
  F_fun(state,  dt, out_628600079770378397);
}
void car_h_25(double *state, double *unused, double *out_2070862304769966057) {
  h_25(state, unused, out_2070862304769966057);
}
void car_H_25(double *state, double *unused, double *out_9103194180930044430) {
  H_25(state, unused, out_9103194180930044430);
}
void car_h_24(double *state, double *unused, double *out_1698834673375970192) {
  h_24(state, unused, out_1698834673375970192);
}
void car_H_24(double *state, double *unused, double *out_8258197572146349031) {
  H_24(state, unused, out_8258197572146349031);
}
void car_h_30(double *state, double *unused, double *out_4084584891070694072) {
  h_30(state, unused, out_4084584891070694072);
}
void car_H_30(double *state, double *unused, double *out_2186503839438427675) {
  H_30(state, unused, out_2186503839438427675);
}
void car_h_26(double *state, double *unused, double *out_1141322324764630875) {
  h_26(state, unused, out_1141322324764630875);
}
void car_H_26(double *state, double *unused, double *out_5798668211169243829) {
  H_26(state, unused, out_5798668211169243829);
}
void car_h_27(double *state, double *unused, double *out_8940738334510884746) {
  h_27(state, unused, out_8940738334510884746);
}
void car_H_27(double *state, double *unused, double *out_4361267151238852586) {
  H_27(state, unused, out_4361267151238852586);
}
void car_h_29(double *state, double *unused, double *out_5565849718372860404) {
  h_29(state, unused, out_5565849718372860404);
}
void car_H_29(double *state, double *unused, double *out_6074629878108403619) {
  H_29(state, unused, out_6074629878108403619);
}
void car_h_28(double *state, double *unused, double *out_7997228481609222311) {
  h_28(state, unused, out_7997228481609222311);
}
void car_H_28(double *state, double *unused, double *out_7289715178531617423) {
  H_28(state, unused, out_7289715178531617423);
}
void car_h_31(double *state, double *unused, double *out_2346056367054471946) {
  h_31(state, unused, out_2346056367054471946);
}
void car_H_31(double *state, double *unused, double *out_2026518930418227177) {
  H_31(state, unused, out_2026518930418227177);
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
