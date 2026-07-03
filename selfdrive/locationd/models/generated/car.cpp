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
void err_fun(double *nom_x, double *delta_x, double *out_5095523285720935963) {
   out_5095523285720935963[0] = delta_x[0] + nom_x[0];
   out_5095523285720935963[1] = delta_x[1] + nom_x[1];
   out_5095523285720935963[2] = delta_x[2] + nom_x[2];
   out_5095523285720935963[3] = delta_x[3] + nom_x[3];
   out_5095523285720935963[4] = delta_x[4] + nom_x[4];
   out_5095523285720935963[5] = delta_x[5] + nom_x[5];
   out_5095523285720935963[6] = delta_x[6] + nom_x[6];
   out_5095523285720935963[7] = delta_x[7] + nom_x[7];
   out_5095523285720935963[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7157467776234621149) {
   out_7157467776234621149[0] = -nom_x[0] + true_x[0];
   out_7157467776234621149[1] = -nom_x[1] + true_x[1];
   out_7157467776234621149[2] = -nom_x[2] + true_x[2];
   out_7157467776234621149[3] = -nom_x[3] + true_x[3];
   out_7157467776234621149[4] = -nom_x[4] + true_x[4];
   out_7157467776234621149[5] = -nom_x[5] + true_x[5];
   out_7157467776234621149[6] = -nom_x[6] + true_x[6];
   out_7157467776234621149[7] = -nom_x[7] + true_x[7];
   out_7157467776234621149[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3219454610501945799) {
   out_3219454610501945799[0] = 1.0;
   out_3219454610501945799[1] = 0.0;
   out_3219454610501945799[2] = 0.0;
   out_3219454610501945799[3] = 0.0;
   out_3219454610501945799[4] = 0.0;
   out_3219454610501945799[5] = 0.0;
   out_3219454610501945799[6] = 0.0;
   out_3219454610501945799[7] = 0.0;
   out_3219454610501945799[8] = 0.0;
   out_3219454610501945799[9] = 0.0;
   out_3219454610501945799[10] = 1.0;
   out_3219454610501945799[11] = 0.0;
   out_3219454610501945799[12] = 0.0;
   out_3219454610501945799[13] = 0.0;
   out_3219454610501945799[14] = 0.0;
   out_3219454610501945799[15] = 0.0;
   out_3219454610501945799[16] = 0.0;
   out_3219454610501945799[17] = 0.0;
   out_3219454610501945799[18] = 0.0;
   out_3219454610501945799[19] = 0.0;
   out_3219454610501945799[20] = 1.0;
   out_3219454610501945799[21] = 0.0;
   out_3219454610501945799[22] = 0.0;
   out_3219454610501945799[23] = 0.0;
   out_3219454610501945799[24] = 0.0;
   out_3219454610501945799[25] = 0.0;
   out_3219454610501945799[26] = 0.0;
   out_3219454610501945799[27] = 0.0;
   out_3219454610501945799[28] = 0.0;
   out_3219454610501945799[29] = 0.0;
   out_3219454610501945799[30] = 1.0;
   out_3219454610501945799[31] = 0.0;
   out_3219454610501945799[32] = 0.0;
   out_3219454610501945799[33] = 0.0;
   out_3219454610501945799[34] = 0.0;
   out_3219454610501945799[35] = 0.0;
   out_3219454610501945799[36] = 0.0;
   out_3219454610501945799[37] = 0.0;
   out_3219454610501945799[38] = 0.0;
   out_3219454610501945799[39] = 0.0;
   out_3219454610501945799[40] = 1.0;
   out_3219454610501945799[41] = 0.0;
   out_3219454610501945799[42] = 0.0;
   out_3219454610501945799[43] = 0.0;
   out_3219454610501945799[44] = 0.0;
   out_3219454610501945799[45] = 0.0;
   out_3219454610501945799[46] = 0.0;
   out_3219454610501945799[47] = 0.0;
   out_3219454610501945799[48] = 0.0;
   out_3219454610501945799[49] = 0.0;
   out_3219454610501945799[50] = 1.0;
   out_3219454610501945799[51] = 0.0;
   out_3219454610501945799[52] = 0.0;
   out_3219454610501945799[53] = 0.0;
   out_3219454610501945799[54] = 0.0;
   out_3219454610501945799[55] = 0.0;
   out_3219454610501945799[56] = 0.0;
   out_3219454610501945799[57] = 0.0;
   out_3219454610501945799[58] = 0.0;
   out_3219454610501945799[59] = 0.0;
   out_3219454610501945799[60] = 1.0;
   out_3219454610501945799[61] = 0.0;
   out_3219454610501945799[62] = 0.0;
   out_3219454610501945799[63] = 0.0;
   out_3219454610501945799[64] = 0.0;
   out_3219454610501945799[65] = 0.0;
   out_3219454610501945799[66] = 0.0;
   out_3219454610501945799[67] = 0.0;
   out_3219454610501945799[68] = 0.0;
   out_3219454610501945799[69] = 0.0;
   out_3219454610501945799[70] = 1.0;
   out_3219454610501945799[71] = 0.0;
   out_3219454610501945799[72] = 0.0;
   out_3219454610501945799[73] = 0.0;
   out_3219454610501945799[74] = 0.0;
   out_3219454610501945799[75] = 0.0;
   out_3219454610501945799[76] = 0.0;
   out_3219454610501945799[77] = 0.0;
   out_3219454610501945799[78] = 0.0;
   out_3219454610501945799[79] = 0.0;
   out_3219454610501945799[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8968218806304622496) {
   out_8968218806304622496[0] = state[0];
   out_8968218806304622496[1] = state[1];
   out_8968218806304622496[2] = state[2];
   out_8968218806304622496[3] = state[3];
   out_8968218806304622496[4] = state[4];
   out_8968218806304622496[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8968218806304622496[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8968218806304622496[7] = state[7];
   out_8968218806304622496[8] = state[8];
}
void F_fun(double *state, double dt, double *out_559280476475270084) {
   out_559280476475270084[0] = 1;
   out_559280476475270084[1] = 0;
   out_559280476475270084[2] = 0;
   out_559280476475270084[3] = 0;
   out_559280476475270084[4] = 0;
   out_559280476475270084[5] = 0;
   out_559280476475270084[6] = 0;
   out_559280476475270084[7] = 0;
   out_559280476475270084[8] = 0;
   out_559280476475270084[9] = 0;
   out_559280476475270084[10] = 1;
   out_559280476475270084[11] = 0;
   out_559280476475270084[12] = 0;
   out_559280476475270084[13] = 0;
   out_559280476475270084[14] = 0;
   out_559280476475270084[15] = 0;
   out_559280476475270084[16] = 0;
   out_559280476475270084[17] = 0;
   out_559280476475270084[18] = 0;
   out_559280476475270084[19] = 0;
   out_559280476475270084[20] = 1;
   out_559280476475270084[21] = 0;
   out_559280476475270084[22] = 0;
   out_559280476475270084[23] = 0;
   out_559280476475270084[24] = 0;
   out_559280476475270084[25] = 0;
   out_559280476475270084[26] = 0;
   out_559280476475270084[27] = 0;
   out_559280476475270084[28] = 0;
   out_559280476475270084[29] = 0;
   out_559280476475270084[30] = 1;
   out_559280476475270084[31] = 0;
   out_559280476475270084[32] = 0;
   out_559280476475270084[33] = 0;
   out_559280476475270084[34] = 0;
   out_559280476475270084[35] = 0;
   out_559280476475270084[36] = 0;
   out_559280476475270084[37] = 0;
   out_559280476475270084[38] = 0;
   out_559280476475270084[39] = 0;
   out_559280476475270084[40] = 1;
   out_559280476475270084[41] = 0;
   out_559280476475270084[42] = 0;
   out_559280476475270084[43] = 0;
   out_559280476475270084[44] = 0;
   out_559280476475270084[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_559280476475270084[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_559280476475270084[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_559280476475270084[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_559280476475270084[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_559280476475270084[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_559280476475270084[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_559280476475270084[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_559280476475270084[53] = -9.8100000000000005*dt;
   out_559280476475270084[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_559280476475270084[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_559280476475270084[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_559280476475270084[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_559280476475270084[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_559280476475270084[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_559280476475270084[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_559280476475270084[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_559280476475270084[62] = 0;
   out_559280476475270084[63] = 0;
   out_559280476475270084[64] = 0;
   out_559280476475270084[65] = 0;
   out_559280476475270084[66] = 0;
   out_559280476475270084[67] = 0;
   out_559280476475270084[68] = 0;
   out_559280476475270084[69] = 0;
   out_559280476475270084[70] = 1;
   out_559280476475270084[71] = 0;
   out_559280476475270084[72] = 0;
   out_559280476475270084[73] = 0;
   out_559280476475270084[74] = 0;
   out_559280476475270084[75] = 0;
   out_559280476475270084[76] = 0;
   out_559280476475270084[77] = 0;
   out_559280476475270084[78] = 0;
   out_559280476475270084[79] = 0;
   out_559280476475270084[80] = 1;
}
void h_25(double *state, double *unused, double *out_7874470337533308693) {
   out_7874470337533308693[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1945350534564629578) {
   out_1945350534564629578[0] = 0;
   out_1945350534564629578[1] = 0;
   out_1945350534564629578[2] = 0;
   out_1945350534564629578[3] = 0;
   out_1945350534564629578[4] = 0;
   out_1945350534564629578[5] = 0;
   out_1945350534564629578[6] = 1;
   out_1945350534564629578[7] = 0;
   out_1945350534564629578[8] = 0;
}
void h_24(double *state, double *unused, double *out_3796468718341357467) {
   out_3796468718341357467[0] = state[4];
   out_3796468718341357467[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8146383214415791004) {
   out_8146383214415791004[0] = 0;
   out_8146383214415791004[1] = 0;
   out_8146383214415791004[2] = 0;
   out_8146383214415791004[3] = 0;
   out_8146383214415791004[4] = 1;
   out_8146383214415791004[5] = 0;
   out_8146383214415791004[6] = 0;
   out_8146383214415791004[7] = 0;
   out_8146383214415791004[8] = 0;
   out_8146383214415791004[9] = 0;
   out_8146383214415791004[10] = 0;
   out_8146383214415791004[11] = 0;
   out_8146383214415791004[12] = 0;
   out_8146383214415791004[13] = 0;
   out_8146383214415791004[14] = 1;
   out_8146383214415791004[15] = 0;
   out_8146383214415791004[16] = 0;
   out_8146383214415791004[17] = 0;
}
void h_30(double *state, double *unused, double *out_6473970437896871059) {
   out_6473970437896871059[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2074689481707869648) {
   out_2074689481707869648[0] = 0;
   out_2074689481707869648[1] = 0;
   out_2074689481707869648[2] = 0;
   out_2074689481707869648[3] = 0;
   out_2074689481707869648[4] = 1;
   out_2074689481707869648[5] = 0;
   out_2074689481707869648[6] = 0;
   out_2074689481707869648[7] = 0;
   out_2074689481707869648[8] = 0;
}
void h_26(double *state, double *unused, double *out_7417480290798533494) {
   out_7417480290798533494[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5686853853438685802) {
   out_5686853853438685802[0] = 0;
   out_5686853853438685802[1] = 0;
   out_5686853853438685802[2] = 0;
   out_5686853853438685802[3] = 0;
   out_5686853853438685802[4] = 0;
   out_5686853853438685802[5] = 0;
   out_5686853853438685802[6] = 0;
   out_5686853853438685802[7] = 1;
   out_5686853853438685802[8] = 0;
}
void h_27(double *state, double *unused, double *out_7535487684731910238) {
   out_7535487684731910238[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4249452793508294559) {
   out_4249452793508294559[0] = 0;
   out_4249452793508294559[1] = 0;
   out_4249452793508294559[2] = 0;
   out_4249452793508294559[3] = 1;
   out_4249452793508294559[4] = 0;
   out_4249452793508294559[5] = 0;
   out_4249452793508294559[6] = 0;
   out_4249452793508294559[7] = 0;
   out_4249452793508294559[8] = 0;
}
void h_29(double *state, double *unused, double *out_7077286322573348576) {
   out_7077286322573348576[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5962815520377845592) {
   out_5962815520377845592[0] = 0;
   out_5962815520377845592[1] = 1;
   out_5962815520377845592[2] = 0;
   out_5962815520377845592[3] = 0;
   out_5962815520377845592[4] = 0;
   out_5962815520377845592[5] = 0;
   out_5962815520377845592[6] = 0;
   out_5962815520377845592[7] = 0;
   out_5962815520377845592[8] = 0;
}
void h_28(double *state, double *unused, double *out_6513304307696012366) {
   out_6513304307696012366[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7401529536262175450) {
   out_7401529536262175450[0] = 1;
   out_7401529536262175450[1] = 0;
   out_7401529536262175450[2] = 0;
   out_7401529536262175450[3] = 0;
   out_7401529536262175450[4] = 0;
   out_7401529536262175450[5] = 0;
   out_7401529536262175450[6] = 0;
   out_7401529536262175450[7] = 0;
   out_7401529536262175450[8] = 0;
}
void h_31(double *state, double *unused, double *out_8149664399817814582) {
   out_8149664399817814582[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1914704572687669150) {
   out_1914704572687669150[0] = 0;
   out_1914704572687669150[1] = 0;
   out_1914704572687669150[2] = 0;
   out_1914704572687669150[3] = 0;
   out_1914704572687669150[4] = 0;
   out_1914704572687669150[5] = 0;
   out_1914704572687669150[6] = 0;
   out_1914704572687669150[7] = 0;
   out_1914704572687669150[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5095523285720935963) {
  err_fun(nom_x, delta_x, out_5095523285720935963);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7157467776234621149) {
  inv_err_fun(nom_x, true_x, out_7157467776234621149);
}
void car_H_mod_fun(double *state, double *out_3219454610501945799) {
  H_mod_fun(state, out_3219454610501945799);
}
void car_f_fun(double *state, double dt, double *out_8968218806304622496) {
  f_fun(state,  dt, out_8968218806304622496);
}
void car_F_fun(double *state, double dt, double *out_559280476475270084) {
  F_fun(state,  dt, out_559280476475270084);
}
void car_h_25(double *state, double *unused, double *out_7874470337533308693) {
  h_25(state, unused, out_7874470337533308693);
}
void car_H_25(double *state, double *unused, double *out_1945350534564629578) {
  H_25(state, unused, out_1945350534564629578);
}
void car_h_24(double *state, double *unused, double *out_3796468718341357467) {
  h_24(state, unused, out_3796468718341357467);
}
void car_H_24(double *state, double *unused, double *out_8146383214415791004) {
  H_24(state, unused, out_8146383214415791004);
}
void car_h_30(double *state, double *unused, double *out_6473970437896871059) {
  h_30(state, unused, out_6473970437896871059);
}
void car_H_30(double *state, double *unused, double *out_2074689481707869648) {
  H_30(state, unused, out_2074689481707869648);
}
void car_h_26(double *state, double *unused, double *out_7417480290798533494) {
  h_26(state, unused, out_7417480290798533494);
}
void car_H_26(double *state, double *unused, double *out_5686853853438685802) {
  H_26(state, unused, out_5686853853438685802);
}
void car_h_27(double *state, double *unused, double *out_7535487684731910238) {
  h_27(state, unused, out_7535487684731910238);
}
void car_H_27(double *state, double *unused, double *out_4249452793508294559) {
  H_27(state, unused, out_4249452793508294559);
}
void car_h_29(double *state, double *unused, double *out_7077286322573348576) {
  h_29(state, unused, out_7077286322573348576);
}
void car_H_29(double *state, double *unused, double *out_5962815520377845592) {
  H_29(state, unused, out_5962815520377845592);
}
void car_h_28(double *state, double *unused, double *out_6513304307696012366) {
  h_28(state, unused, out_6513304307696012366);
}
void car_H_28(double *state, double *unused, double *out_7401529536262175450) {
  H_28(state, unused, out_7401529536262175450);
}
void car_h_31(double *state, double *unused, double *out_8149664399817814582) {
  h_31(state, unused, out_8149664399817814582);
}
void car_H_31(double *state, double *unused, double *out_1914704572687669150) {
  H_31(state, unused, out_1914704572687669150);
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
