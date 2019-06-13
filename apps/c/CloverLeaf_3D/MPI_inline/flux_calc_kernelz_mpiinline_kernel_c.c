//
// auto-generated by ops.py
//

int xdim0_flux_calc_kernelz;
int ydim0_flux_calc_kernelz;
int xdim1_flux_calc_kernelz;
int ydim1_flux_calc_kernelz;
int xdim2_flux_calc_kernelz;
int ydim2_flux_calc_kernelz;
int xdim3_flux_calc_kernelz;
int ydim3_flux_calc_kernelz;


#define OPS_ACC0(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_flux_calc_kernelz + (n_z*1+(z))*xdim0_flux_calc_kernelz*ydim0_flux_calc_kernelz)
#define OPS_ACC1(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim1_flux_calc_kernelz + (n_z*1+(z))*xdim1_flux_calc_kernelz*ydim1_flux_calc_kernelz)
#define OPS_ACC2(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim2_flux_calc_kernelz + (n_z*1+(z))*xdim2_flux_calc_kernelz*ydim2_flux_calc_kernelz)
#define OPS_ACC3(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim3_flux_calc_kernelz + (n_z*1+(z))*xdim3_flux_calc_kernelz*ydim3_flux_calc_kernelz)
//user function



void flux_calc_kernelz_c_wrapper(
  double * restrict vol_flux_z,
  const double * restrict zarea,
  const double * restrict zvel0,
  const double * restrict zvel1,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        

  vol_flux_z[OPS_ACC0(0,0,0)] = 0.125 * dt * (zarea[OPS_ACC1(0,0,0)]) *
  ( zvel0[OPS_ACC2(0,0,0)] + zvel0[OPS_ACC2(1,0,0)] + zvel0[OPS_ACC2(1,0,0)] + zvel0[OPS_ACC2(1,1,0)] +
    zvel1[OPS_ACC3(0,0,0)] + zvel1[OPS_ACC3(1,0,0)] + zvel1[OPS_ACC3(0,1,0)] + zvel1[OPS_ACC3(1,1,0)]);

      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

