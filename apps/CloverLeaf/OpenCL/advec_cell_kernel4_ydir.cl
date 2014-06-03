//
// auto-generated by ops.py on 2014-06-03 14:49
//


#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;
#define OPS_ACC0(x,y) (x+xdim0_advec_cell_kernel4_ydir*(y))
#define OPS_ACC1(x,y) (x+xdim1_advec_cell_kernel4_ydir*(y))
#define OPS_ACC2(x,y) (x+xdim2_advec_cell_kernel4_ydir*(y))
#define OPS_ACC3(x,y) (x+xdim3_advec_cell_kernel4_ydir*(y))
#define OPS_ACC4(x,y) (x+xdim4_advec_cell_kernel4_ydir*(y))
#define OPS_ACC5(x,y) (x+xdim5_advec_cell_kernel4_ydir*(y))
#define OPS_ACC6(x,y) (x+xdim6_advec_cell_kernel4_ydir*(y))
#define OPS_ACC7(x,y) (x+xdim7_advec_cell_kernel4_ydir*(y))
#define OPS_ACC8(x,y) (x+xdim8_advec_cell_kernel4_ydir*(y))
#define OPS_ACC9(x,y) (x+xdim9_advec_cell_kernel4_ydir*(y))
#define OPS_ACC10(x,y) (x+xdim10_advec_cell_kernel4_ydir*(y))


//user function
inline void advec_cell_kernel4_ydir( __global double *density1, __global double *energy1, __global double *mass_flux_y, 
__global double *vol_flux_y, __global double *pre_vol, __global double *post_vol, __global double *pre_mass, 
__global double *post_mass, __global double *advec_vol, __global double *post_ener, __global double *ener_flux, 

  int xdim0_advec_cell_kernel4_ydir,
int xdim1_advec_cell_kernel4_ydir,
int xdim2_advec_cell_kernel4_ydir,
int xdim3_advec_cell_kernel4_ydir,
int xdim4_advec_cell_kernel4_ydir,
int xdim5_advec_cell_kernel4_ydir,
int xdim6_advec_cell_kernel4_ydir,
int xdim7_advec_cell_kernel4_ydir,
int xdim8_advec_cell_kernel4_ydir,
int xdim9_advec_cell_kernel4_ydir,
int xdim10_advec_cell_kernel4_ydir)

  {

  pre_mass[OPS_ACC6(0,0)] = density1[OPS_ACC0(0,0)] * pre_vol[OPS_ACC4(0,0)];
  post_mass[OPS_ACC7(0,0)] = pre_mass[OPS_ACC6(0,0)] + mass_flux_y[OPS_ACC2(0,0)] - mass_flux_y[OPS_ACC2(0,1)];
  post_ener[OPS_ACC9(0,0)] = ( energy1[OPS_ACC1(0,0)] * pre_mass[OPS_ACC6(0,0)] + ener_flux[OPS_ACC10(0,0)] - ener_flux[OPS_ACC10(0,1)])/post_mass[OPS_ACC7(0,0)];
  advec_vol[OPS_ACC8(0,0)] = pre_vol[OPS_ACC4(0,0)] + vol_flux_y[OPS_ACC3(0,0)] - vol_flux_y[OPS_ACC3(0,1)];
  density1[OPS_ACC0(0,0)] = post_mass[OPS_ACC7(0,0)]/advec_vol[OPS_ACC8(0,0)];
  energy1[OPS_ACC1(0,0)] = post_ener[OPS_ACC9(0,0)];

}



 #undef OPS_ACC0
 #undef OPS_ACC1
 #undef OPS_ACC2
 #undef OPS_ACC3
 #undef OPS_ACC4
 #undef OPS_ACC5
 #undef OPS_ACC6
 #undef OPS_ACC7
 #undef OPS_ACC8
 #undef OPS_ACC9
 #undef OPS_ACC10


 __kernel void ops_advec_cell_kernel4_ydir(
 __global double* arg0,
 __global double* arg1,
 __global double* arg2,
 __global double* arg3,
 __global double* arg4,
 __global double* arg5,
 __global double* arg6,
 __global double* arg7,
 __global double* arg8,
 __global double* arg9,
 __global double* arg10,
 int xdim0_advec_cell_kernel4_ydir,
 int xdim1_advec_cell_kernel4_ydir,
 int xdim2_advec_cell_kernel4_ydir,
 int xdim3_advec_cell_kernel4_ydir,
 int xdim4_advec_cell_kernel4_ydir,
 int xdim5_advec_cell_kernel4_ydir,
 int xdim6_advec_cell_kernel4_ydir,
 int xdim7_advec_cell_kernel4_ydir,
 int xdim8_advec_cell_kernel4_ydir,
 int xdim9_advec_cell_kernel4_ydir,
 int xdim10_advec_cell_kernel4_ydir,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 const int base4,
 const int base5,
 const int base6,
 const int base7,
 const int base8,
 const int base9,
 const int base10,
 int size0,
 int size1 ){


   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1) {
     advec_cell_kernel4_ydir(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_advec_cell_kernel4_ydir],
                       &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_advec_cell_kernel4_ydir],
                       &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_advec_cell_kernel4_ydir],
                       &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_advec_cell_kernel4_ydir],
                       &arg4[base4 + idx_x * 1 + idx_y * 1 * xdim4_advec_cell_kernel4_ydir],
                       &arg5[base5 + idx_x * 1 + idx_y * 1 * xdim5_advec_cell_kernel4_ydir],
                       &arg6[base6 + idx_x * 1 + idx_y * 1 * xdim6_advec_cell_kernel4_ydir],
                       &arg7[base7 + idx_x * 1 + idx_y * 1 * xdim7_advec_cell_kernel4_ydir],
                       &arg8[base8 + idx_x * 1 + idx_y * 1 * xdim8_advec_cell_kernel4_ydir],
                       &arg9[base9 + idx_x * 1 + idx_y * 1 * xdim9_advec_cell_kernel4_ydir],
                       &arg10[base10 + idx_x * 1 + idx_y * 1 * xdim10_advec_cell_kernel4_ydir],
                       
                       xdim0_advec_cell_kernel4_ydir,
                       xdim1_advec_cell_kernel4_ydir,
                       xdim2_advec_cell_kernel4_ydir,
                       xdim3_advec_cell_kernel4_ydir,
                       xdim4_advec_cell_kernel4_ydir,
                       xdim5_advec_cell_kernel4_ydir,
                       xdim6_advec_cell_kernel4_ydir,
                       xdim7_advec_cell_kernel4_ydir,
                       xdim8_advec_cell_kernel4_ydir,
                       xdim9_advec_cell_kernel4_ydir,
                       xdim10_advec_cell_kernel4_ydir);
   }

 }
