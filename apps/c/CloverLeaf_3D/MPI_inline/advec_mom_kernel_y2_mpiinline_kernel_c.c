//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_advec_mom_kernel_y2;
int ydim0_advec_mom_kernel_y2;
int xdim1_advec_mom_kernel_y2;
int ydim1_advec_mom_kernel_y2;
int xdim2_advec_mom_kernel_y2;
int ydim2_advec_mom_kernel_y2;
int xdim3_advec_mom_kernel_y2;
int ydim3_advec_mom_kernel_y2;
int xdim4_advec_mom_kernel_y2;
int ydim4_advec_mom_kernel_y2;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim0_advec_mom_kernel_y2 +                 \
   (n_z * 1 + (z)) * xdim0_advec_mom_kernel_y2 * ydim0_advec_mom_kernel_y2)
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim1_advec_mom_kernel_y2 +                 \
   (n_z * 1 + (z)) * xdim1_advec_mom_kernel_y2 * ydim1_advec_mom_kernel_y2)
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim2_advec_mom_kernel_y2 +                 \
   (n_z * 1 + (z)) * xdim2_advec_mom_kernel_y2 * ydim2_advec_mom_kernel_y2)
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim3_advec_mom_kernel_y2 +                 \
   (n_z * 1 + (z)) * xdim3_advec_mom_kernel_y2 * ydim3_advec_mom_kernel_y2)
#define OPS_ACC4(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim4_advec_mom_kernel_y2 +                 \
   (n_z * 1 + (z)) * xdim4_advec_mom_kernel_y2 * ydim4_advec_mom_kernel_y2)
//user function



void advec_mom_kernel_y2_c_wrapper(
  double * restrict pre_vol,
  double * restrict post_vol,
  const double * restrict volume,
  const double * restrict vol_flux_x,
  const double * restrict vol_flux_y,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        

  post_vol[OPS_ACC1(0,0,0)]  = volume[OPS_ACC2(0,0,0)]  + vol_flux_x[OPS_ACC3(1,0,0)] - vol_flux_x[OPS_ACC3(0,0,0)] ;
  pre_vol[OPS_ACC0(0,0,0)]   = post_vol[OPS_ACC1(0,0,0)]  + vol_flux_y[OPS_ACC4(0,1,0)] - vol_flux_y[OPS_ACC4(0,0,0)];


      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

