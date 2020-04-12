//
// auto-generated by ops.py
//

int xdim0_flux_calc_kernely;
int ydim0_flux_calc_kernely;
int xdim1_flux_calc_kernely;
int ydim1_flux_calc_kernely;
int xdim2_flux_calc_kernely;
int ydim2_flux_calc_kernely;
int xdim3_flux_calc_kernely;
int ydim3_flux_calc_kernely;


//user function



void flux_calc_kernely_c_wrapper(
  double * restrict vol_flux_y_p,
  double * restrict yarea_p,
  double * restrict yvel0_p,
  double * restrict yvel1_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        ptr_double vol_flux_y = { vol_flux_y_p + n_x*1 + n_y * xdim0_flux_calc_kernely*1 + n_z * xdim0_flux_calc_kernely * ydim0_flux_calc_kernely*1, xdim0_flux_calc_kernely, ydim0_flux_calc_kernely};
        const ptr_double yarea = { yarea_p + n_x*1 + n_y * xdim1_flux_calc_kernely*1 + n_z * xdim1_flux_calc_kernely * ydim1_flux_calc_kernely*1, xdim1_flux_calc_kernely, ydim1_flux_calc_kernely};
        const ptr_double yvel0 = { yvel0_p + n_x*1 + n_y * xdim2_flux_calc_kernely*1 + n_z * xdim2_flux_calc_kernely * ydim2_flux_calc_kernely*1, xdim2_flux_calc_kernely, ydim2_flux_calc_kernely};
        const ptr_double yvel1 = { yvel1_p + n_x*1 + n_y * xdim3_flux_calc_kernely*1 + n_z * xdim3_flux_calc_kernely * ydim3_flux_calc_kernely*1, xdim3_flux_calc_kernely, ydim3_flux_calc_kernely};
        

  OPS_ACC(vol_flux_y, 0,0,0) = 0.125 * dt * (OPS_ACC(yarea, 0,0,0)) *
  ( OPS_ACC(yvel0, 0,0,0) + OPS_ACC(yvel0, 1,0,0) + OPS_ACC(yvel0, 0,0,1) + OPS_ACC(yvel0, 1,0,1) +
    OPS_ACC(yvel1, 0,0,0) + OPS_ACC(yvel1, 1,0,0) + OPS_ACC(yvel1, 0,0,1) + OPS_ACC(yvel1, 1,0,1));

      }
    }
  }
}