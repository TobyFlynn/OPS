//
// auto-generated by ops.py
//
#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_flux_calc_kernelz;
int ydim0_flux_calc_kernelz;
int xdim1_flux_calc_kernelz;
int ydim1_flux_calc_kernelz;
int xdim2_flux_calc_kernelz;
int ydim2_flux_calc_kernelz;
int xdim3_flux_calc_kernelz;
int ydim3_flux_calc_kernelz;

#define OPS_ACC0(x,y,z) (x+xdim0_flux_calc_kernelz*(y)+xdim0_flux_calc_kernelz*ydim0_flux_calc_kernelz*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_flux_calc_kernelz*(y)+xdim1_flux_calc_kernelz*ydim1_flux_calc_kernelz*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_flux_calc_kernelz*(y)+xdim2_flux_calc_kernelz*ydim2_flux_calc_kernelz*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_flux_calc_kernelz*(y)+xdim3_flux_calc_kernelz*ydim3_flux_calc_kernelz*(z))

//user function
inline 
void flux_calc_kernelz( double *vol_flux_z, const double *zarea,
                        const double *zvel0, const double *zvel1) {

  vol_flux_z[OPS_ACC0(0,0,0)] = 0.125 * dt * (zarea[OPS_ACC1(0,0,0)]) *
  ( zvel0[OPS_ACC2(0,0,0)] + zvel0[OPS_ACC2(1,0,0)] + zvel0[OPS_ACC2(1,0,0)] + zvel0[OPS_ACC2(1,1,0)] +
    zvel1[OPS_ACC3(0,0,0)] + zvel1[OPS_ACC3(1,0,0)] + zvel1[OPS_ACC3(0,1,0)] + zvel1[OPS_ACC3(1,1,0)]);
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


void flux_calc_kernelz_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        flux_calc_kernelz(  p_a0 + n_x*1 + n_y*xdim0_flux_calc_kernelz*1 + n_z*xdim0_flux_calc_kernelz*ydim0_flux_calc_kernelz*1,
           p_a1 + n_x*1 + n_y*xdim1_flux_calc_kernelz*1 + n_z*xdim1_flux_calc_kernelz*ydim1_flux_calc_kernelz*1,
           p_a2 + n_x*1 + n_y*xdim2_flux_calc_kernelz*1 + n_z*xdim2_flux_calc_kernelz*ydim2_flux_calc_kernelz*1,
           p_a3 + n_x*1 + n_y*xdim3_flux_calc_kernelz*1 + n_z*xdim3_flux_calc_kernelz*ydim3_flux_calc_kernelz*1 );

      }
    }
  }
}
