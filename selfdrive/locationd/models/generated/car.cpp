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
void err_fun(double *nom_x, double *delta_x, double *out_7208701368394961077) {
   out_7208701368394961077[0] = delta_x[0] + nom_x[0];
   out_7208701368394961077[1] = delta_x[1] + nom_x[1];
   out_7208701368394961077[2] = delta_x[2] + nom_x[2];
   out_7208701368394961077[3] = delta_x[3] + nom_x[3];
   out_7208701368394961077[4] = delta_x[4] + nom_x[4];
   out_7208701368394961077[5] = delta_x[5] + nom_x[5];
   out_7208701368394961077[6] = delta_x[6] + nom_x[6];
   out_7208701368394961077[7] = delta_x[7] + nom_x[7];
   out_7208701368394961077[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5744805479138773162) {
   out_5744805479138773162[0] = -nom_x[0] + true_x[0];
   out_5744805479138773162[1] = -nom_x[1] + true_x[1];
   out_5744805479138773162[2] = -nom_x[2] + true_x[2];
   out_5744805479138773162[3] = -nom_x[3] + true_x[3];
   out_5744805479138773162[4] = -nom_x[4] + true_x[4];
   out_5744805479138773162[5] = -nom_x[5] + true_x[5];
   out_5744805479138773162[6] = -nom_x[6] + true_x[6];
   out_5744805479138773162[7] = -nom_x[7] + true_x[7];
   out_5744805479138773162[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5233187869129643325) {
   out_5233187869129643325[0] = 1.0;
   out_5233187869129643325[1] = 0.0;
   out_5233187869129643325[2] = 0.0;
   out_5233187869129643325[3] = 0.0;
   out_5233187869129643325[4] = 0.0;
   out_5233187869129643325[5] = 0.0;
   out_5233187869129643325[6] = 0.0;
   out_5233187869129643325[7] = 0.0;
   out_5233187869129643325[8] = 0.0;
   out_5233187869129643325[9] = 0.0;
   out_5233187869129643325[10] = 1.0;
   out_5233187869129643325[11] = 0.0;
   out_5233187869129643325[12] = 0.0;
   out_5233187869129643325[13] = 0.0;
   out_5233187869129643325[14] = 0.0;
   out_5233187869129643325[15] = 0.0;
   out_5233187869129643325[16] = 0.0;
   out_5233187869129643325[17] = 0.0;
   out_5233187869129643325[18] = 0.0;
   out_5233187869129643325[19] = 0.0;
   out_5233187869129643325[20] = 1.0;
   out_5233187869129643325[21] = 0.0;
   out_5233187869129643325[22] = 0.0;
   out_5233187869129643325[23] = 0.0;
   out_5233187869129643325[24] = 0.0;
   out_5233187869129643325[25] = 0.0;
   out_5233187869129643325[26] = 0.0;
   out_5233187869129643325[27] = 0.0;
   out_5233187869129643325[28] = 0.0;
   out_5233187869129643325[29] = 0.0;
   out_5233187869129643325[30] = 1.0;
   out_5233187869129643325[31] = 0.0;
   out_5233187869129643325[32] = 0.0;
   out_5233187869129643325[33] = 0.0;
   out_5233187869129643325[34] = 0.0;
   out_5233187869129643325[35] = 0.0;
   out_5233187869129643325[36] = 0.0;
   out_5233187869129643325[37] = 0.0;
   out_5233187869129643325[38] = 0.0;
   out_5233187869129643325[39] = 0.0;
   out_5233187869129643325[40] = 1.0;
   out_5233187869129643325[41] = 0.0;
   out_5233187869129643325[42] = 0.0;
   out_5233187869129643325[43] = 0.0;
   out_5233187869129643325[44] = 0.0;
   out_5233187869129643325[45] = 0.0;
   out_5233187869129643325[46] = 0.0;
   out_5233187869129643325[47] = 0.0;
   out_5233187869129643325[48] = 0.0;
   out_5233187869129643325[49] = 0.0;
   out_5233187869129643325[50] = 1.0;
   out_5233187869129643325[51] = 0.0;
   out_5233187869129643325[52] = 0.0;
   out_5233187869129643325[53] = 0.0;
   out_5233187869129643325[54] = 0.0;
   out_5233187869129643325[55] = 0.0;
   out_5233187869129643325[56] = 0.0;
   out_5233187869129643325[57] = 0.0;
   out_5233187869129643325[58] = 0.0;
   out_5233187869129643325[59] = 0.0;
   out_5233187869129643325[60] = 1.0;
   out_5233187869129643325[61] = 0.0;
   out_5233187869129643325[62] = 0.0;
   out_5233187869129643325[63] = 0.0;
   out_5233187869129643325[64] = 0.0;
   out_5233187869129643325[65] = 0.0;
   out_5233187869129643325[66] = 0.0;
   out_5233187869129643325[67] = 0.0;
   out_5233187869129643325[68] = 0.0;
   out_5233187869129643325[69] = 0.0;
   out_5233187869129643325[70] = 1.0;
   out_5233187869129643325[71] = 0.0;
   out_5233187869129643325[72] = 0.0;
   out_5233187869129643325[73] = 0.0;
   out_5233187869129643325[74] = 0.0;
   out_5233187869129643325[75] = 0.0;
   out_5233187869129643325[76] = 0.0;
   out_5233187869129643325[77] = 0.0;
   out_5233187869129643325[78] = 0.0;
   out_5233187869129643325[79] = 0.0;
   out_5233187869129643325[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7910145160920043829) {
   out_7910145160920043829[0] = state[0];
   out_7910145160920043829[1] = state[1];
   out_7910145160920043829[2] = state[2];
   out_7910145160920043829[3] = state[3];
   out_7910145160920043829[4] = state[4];
   out_7910145160920043829[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7910145160920043829[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7910145160920043829[7] = state[7];
   out_7910145160920043829[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8682084775257829483) {
   out_8682084775257829483[0] = 1;
   out_8682084775257829483[1] = 0;
   out_8682084775257829483[2] = 0;
   out_8682084775257829483[3] = 0;
   out_8682084775257829483[4] = 0;
   out_8682084775257829483[5] = 0;
   out_8682084775257829483[6] = 0;
   out_8682084775257829483[7] = 0;
   out_8682084775257829483[8] = 0;
   out_8682084775257829483[9] = 0;
   out_8682084775257829483[10] = 1;
   out_8682084775257829483[11] = 0;
   out_8682084775257829483[12] = 0;
   out_8682084775257829483[13] = 0;
   out_8682084775257829483[14] = 0;
   out_8682084775257829483[15] = 0;
   out_8682084775257829483[16] = 0;
   out_8682084775257829483[17] = 0;
   out_8682084775257829483[18] = 0;
   out_8682084775257829483[19] = 0;
   out_8682084775257829483[20] = 1;
   out_8682084775257829483[21] = 0;
   out_8682084775257829483[22] = 0;
   out_8682084775257829483[23] = 0;
   out_8682084775257829483[24] = 0;
   out_8682084775257829483[25] = 0;
   out_8682084775257829483[26] = 0;
   out_8682084775257829483[27] = 0;
   out_8682084775257829483[28] = 0;
   out_8682084775257829483[29] = 0;
   out_8682084775257829483[30] = 1;
   out_8682084775257829483[31] = 0;
   out_8682084775257829483[32] = 0;
   out_8682084775257829483[33] = 0;
   out_8682084775257829483[34] = 0;
   out_8682084775257829483[35] = 0;
   out_8682084775257829483[36] = 0;
   out_8682084775257829483[37] = 0;
   out_8682084775257829483[38] = 0;
   out_8682084775257829483[39] = 0;
   out_8682084775257829483[40] = 1;
   out_8682084775257829483[41] = 0;
   out_8682084775257829483[42] = 0;
   out_8682084775257829483[43] = 0;
   out_8682084775257829483[44] = 0;
   out_8682084775257829483[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8682084775257829483[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8682084775257829483[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8682084775257829483[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8682084775257829483[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8682084775257829483[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8682084775257829483[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8682084775257829483[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8682084775257829483[53] = -9.8100000000000005*dt;
   out_8682084775257829483[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8682084775257829483[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8682084775257829483[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8682084775257829483[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8682084775257829483[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8682084775257829483[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8682084775257829483[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8682084775257829483[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8682084775257829483[62] = 0;
   out_8682084775257829483[63] = 0;
   out_8682084775257829483[64] = 0;
   out_8682084775257829483[65] = 0;
   out_8682084775257829483[66] = 0;
   out_8682084775257829483[67] = 0;
   out_8682084775257829483[68] = 0;
   out_8682084775257829483[69] = 0;
   out_8682084775257829483[70] = 1;
   out_8682084775257829483[71] = 0;
   out_8682084775257829483[72] = 0;
   out_8682084775257829483[73] = 0;
   out_8682084775257829483[74] = 0;
   out_8682084775257829483[75] = 0;
   out_8682084775257829483[76] = 0;
   out_8682084775257829483[77] = 0;
   out_8682084775257829483[78] = 0;
   out_8682084775257829483[79] = 0;
   out_8682084775257829483[80] = 1;
}
void h_25(double *state, double *unused, double *out_8040854508369159628) {
   out_8040854508369159628[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3960000356782593912) {
   out_3960000356782593912[0] = 0;
   out_3960000356782593912[1] = 0;
   out_3960000356782593912[2] = 0;
   out_3960000356782593912[3] = 0;
   out_3960000356782593912[4] = 0;
   out_3960000356782593912[5] = 0;
   out_3960000356782593912[6] = 1;
   out_3960000356782593912[7] = 0;
   out_3960000356782593912[8] = 0;
}
void h_24(double *state, double *unused, double *out_5925075352520764756) {
   out_5925075352520764756[0] = state[4];
   out_5925075352520764756[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5268064829286601313) {
   out_5268064829286601313[0] = 0;
   out_5268064829286601313[1] = 0;
   out_5268064829286601313[2] = 0;
   out_5268064829286601313[3] = 0;
   out_5268064829286601313[4] = 1;
   out_5268064829286601313[5] = 0;
   out_5268064829286601313[6] = 0;
   out_5268064829286601313[7] = 0;
   out_5268064829286601313[8] = 0;
   out_5268064829286601313[9] = 0;
   out_5268064829286601313[10] = 0;
   out_5268064829286601313[11] = 0;
   out_5268064829286601313[12] = 0;
   out_5268064829286601313[13] = 0;
   out_5268064829286601313[14] = 1;
   out_5268064829286601313[15] = 0;
   out_5268064829286601313[16] = 0;
   out_5268064829286601313[17] = 0;
}
void h_30(double *state, double *unused, double *out_1270019282018808692) {
   out_1270019282018808692[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8487696686910202110) {
   out_8487696686910202110[0] = 0;
   out_8487696686910202110[1] = 0;
   out_8487696686910202110[2] = 0;
   out_8487696686910202110[3] = 0;
   out_8487696686910202110[4] = 1;
   out_8487696686910202110[5] = 0;
   out_8487696686910202110[6] = 0;
   out_8487696686910202110[7] = 0;
   out_8487696686910202110[8] = 0;
}
void h_26(double *state, double *unused, double *out_2213529134920471127) {
   out_2213529134920471127[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7701503675656650136) {
   out_7701503675656650136[0] = 0;
   out_7701503675656650136[1] = 0;
   out_7701503675656650136[2] = 0;
   out_7701503675656650136[3] = 0;
   out_7701503675656650136[4] = 0;
   out_7701503675656650136[5] = 0;
   out_7701503675656650136[6] = 0;
   out_7701503675656650136[7] = 1;
   out_7701503675656650136[8] = 0;
}
void h_27(double *state, double *unused, double *out_8644170393045637145) {
   out_8644170393045637145[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6264102615726258893) {
   out_6264102615726258893[0] = 0;
   out_6264102615726258893[1] = 0;
   out_6264102615726258893[2] = 0;
   out_6264102615726258893[3] = 1;
   out_6264102615726258893[4] = 0;
   out_6264102615726258893[5] = 0;
   out_6264102615726258893[6] = 0;
   out_6264102615726258893[7] = 0;
   out_6264102615726258893[8] = 0;
}
void h_29(double *state, double *unused, double *out_6165124152409892121) {
   out_6165124152409892121[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7977465342595809926) {
   out_7977465342595809926[0] = 0;
   out_7977465342595809926[1] = 1;
   out_7977465342595809926[2] = 0;
   out_7977465342595809926[3] = 0;
   out_7977465342595809926[4] = 0;
   out_7977465342595809926[5] = 0;
   out_7977465342595809926[6] = 0;
   out_7977465342595809926[7] = 0;
   out_7977465342595809926[8] = 0;
}
void h_28(double *state, double *unused, double *out_1006264216397917331) {
   out_1006264216397917331[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5386879714044211116) {
   out_5386879714044211116[0] = 1;
   out_5386879714044211116[1] = 0;
   out_5386879714044211116[2] = 0;
   out_5386879714044211116[3] = 0;
   out_5386879714044211116[4] = 0;
   out_5386879714044211116[5] = 0;
   out_5386879714044211116[6] = 0;
   out_5386879714044211116[7] = 0;
   out_5386879714044211116[8] = 0;
}
void h_31(double *state, double *unused, double *out_2642624308519719547) {
   out_2642624308519719547[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8327711777890001612) {
   out_8327711777890001612[0] = 0;
   out_8327711777890001612[1] = 0;
   out_8327711777890001612[2] = 0;
   out_8327711777890001612[3] = 0;
   out_8327711777890001612[4] = 0;
   out_8327711777890001612[5] = 0;
   out_8327711777890001612[6] = 0;
   out_8327711777890001612[7] = 0;
   out_8327711777890001612[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7208701368394961077) {
  err_fun(nom_x, delta_x, out_7208701368394961077);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5744805479138773162) {
  inv_err_fun(nom_x, true_x, out_5744805479138773162);
}
void car_H_mod_fun(double *state, double *out_5233187869129643325) {
  H_mod_fun(state, out_5233187869129643325);
}
void car_f_fun(double *state, double dt, double *out_7910145160920043829) {
  f_fun(state,  dt, out_7910145160920043829);
}
void car_F_fun(double *state, double dt, double *out_8682084775257829483) {
  F_fun(state,  dt, out_8682084775257829483);
}
void car_h_25(double *state, double *unused, double *out_8040854508369159628) {
  h_25(state, unused, out_8040854508369159628);
}
void car_H_25(double *state, double *unused, double *out_3960000356782593912) {
  H_25(state, unused, out_3960000356782593912);
}
void car_h_24(double *state, double *unused, double *out_5925075352520764756) {
  h_24(state, unused, out_5925075352520764756);
}
void car_H_24(double *state, double *unused, double *out_5268064829286601313) {
  H_24(state, unused, out_5268064829286601313);
}
void car_h_30(double *state, double *unused, double *out_1270019282018808692) {
  h_30(state, unused, out_1270019282018808692);
}
void car_H_30(double *state, double *unused, double *out_8487696686910202110) {
  H_30(state, unused, out_8487696686910202110);
}
void car_h_26(double *state, double *unused, double *out_2213529134920471127) {
  h_26(state, unused, out_2213529134920471127);
}
void car_H_26(double *state, double *unused, double *out_7701503675656650136) {
  H_26(state, unused, out_7701503675656650136);
}
void car_h_27(double *state, double *unused, double *out_8644170393045637145) {
  h_27(state, unused, out_8644170393045637145);
}
void car_H_27(double *state, double *unused, double *out_6264102615726258893) {
  H_27(state, unused, out_6264102615726258893);
}
void car_h_29(double *state, double *unused, double *out_6165124152409892121) {
  h_29(state, unused, out_6165124152409892121);
}
void car_H_29(double *state, double *unused, double *out_7977465342595809926) {
  H_29(state, unused, out_7977465342595809926);
}
void car_h_28(double *state, double *unused, double *out_1006264216397917331) {
  h_28(state, unused, out_1006264216397917331);
}
void car_H_28(double *state, double *unused, double *out_5386879714044211116) {
  H_28(state, unused, out_5386879714044211116);
}
void car_h_31(double *state, double *unused, double *out_2642624308519719547) {
  h_31(state, unused, out_2642624308519719547);
}
void car_H_31(double *state, double *unused, double *out_8327711777890001612) {
  H_31(state, unused, out_8327711777890001612);
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
