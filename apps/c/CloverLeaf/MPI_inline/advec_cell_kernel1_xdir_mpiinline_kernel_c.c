//
// auto-generated by ops.py
//

int xdim0_advec_cell_kernel1_xdir;
int xdim1_advec_cell_kernel1_xdir;
int xdim2_advec_cell_kernel1_xdir;
int xdim3_advec_cell_kernel1_xdir;
int xdim4_advec_cell_kernel1_xdir;


//user function



void advec_cell_kernel1_xdir_c_wrapper(
  double * restrict pre_vol_p,
  double * restrict post_vol_p,
  double * restrict volume_p,
  double * restrict vol_flux_x_p,
  double * restrict vol_flux_y_p,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double pre_vol = { pre_vol_p + n_x*1 + n_y * xdim0_advec_cell_kernel1_xdir*1, xdim0_advec_cell_kernel1_xdir};
      ptr_double post_vol = { post_vol_p + n_x*1 + n_y * xdim1_advec_cell_kernel1_xdir*1, xdim1_advec_cell_kernel1_xdir};
      const ptr_double volume = { volume_p + n_x*1 + n_y * xdim2_advec_cell_kernel1_xdir*1, xdim2_advec_cell_kernel1_xdir};
      const ptr_double vol_flux_x = { vol_flux_x_p + n_x*1 + n_y * xdim3_advec_cell_kernel1_xdir*1, xdim3_advec_cell_kernel1_xdir};
      const ptr_double vol_flux_y = { vol_flux_y_p + n_x*1 + n_y * xdim4_advec_cell_kernel1_xdir*1, xdim4_advec_cell_kernel1_xdir};
    }
  }
}
