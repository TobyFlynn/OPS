//
// auto-generated by ops.py
//

int xdim0_advec_cell_kernel2_zdir;
int ydim0_advec_cell_kernel2_zdir;
int xdim1_advec_cell_kernel2_zdir;
int ydim1_advec_cell_kernel2_zdir;
int xdim2_advec_cell_kernel2_zdir;
int ydim2_advec_cell_kernel2_zdir;
int xdim3_advec_cell_kernel2_zdir;
int ydim3_advec_cell_kernel2_zdir;


#define OPS_ACC0(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_advec_cell_kernel2_zdir + (n_z*1+(z))*xdim0_advec_cell_kernel2_zdir*ydim0_advec_cell_kernel2_zdir)
#define OPS_ACC1(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim1_advec_cell_kernel2_zdir + (n_z*1+(z))*xdim1_advec_cell_kernel2_zdir*ydim1_advec_cell_kernel2_zdir)
#define OPS_ACC2(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim2_advec_cell_kernel2_zdir + (n_z*1+(z))*xdim2_advec_cell_kernel2_zdir*ydim2_advec_cell_kernel2_zdir)
#define OPS_ACC3(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim3_advec_cell_kernel2_zdir + (n_z*1+(z))*xdim3_advec_cell_kernel2_zdir*ydim3_advec_cell_kernel2_zdir)
//user function



void advec_cell_kernel2_zdir_c_wrapper(
  double * restrict pre_vol,
  double * restrict post_vol,
  const double * restrict volume,
  const double * restrict vol_flux_z,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        

  pre_vol[OPS_ACC0(0,0,0)] = volume[OPS_ACC2(0,0,0)] + vol_flux_z[OPS_ACC3(0,0,1)] - vol_flux_z[OPS_ACC3(0,0,0)];
  post_vol[OPS_ACC1(0,0,0)] = volume[OPS_ACC2(0,0,0)];


      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

