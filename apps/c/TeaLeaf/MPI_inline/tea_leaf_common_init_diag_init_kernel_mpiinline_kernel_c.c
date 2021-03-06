//
// auto-generated by ops.py
//

int xdim0_tea_leaf_common_init_diag_init_kernel;
int xdim1_tea_leaf_common_init_diag_init_kernel;
int xdim2_tea_leaf_common_init_diag_init_kernel;


//user function



void tea_leaf_common_init_diag_init_kernel_c_wrapper(
  double * restrict Mi_p,
  double * restrict Kx_p,
  double * restrict Ky_p,
  const double * restrict rx,
  const double * restrict ry,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double Mi = { Mi_p + n_x*1 + n_y * xdim0_tea_leaf_common_init_diag_init_kernel*1, xdim0_tea_leaf_common_init_diag_init_kernel};
      const ptr_double Kx = { Kx_p + n_x*1 + n_y * xdim1_tea_leaf_common_init_diag_init_kernel*1, xdim1_tea_leaf_common_init_diag_init_kernel};
      const ptr_double Ky = { Ky_p + n_x*1 + n_y * xdim2_tea_leaf_common_init_diag_init_kernel*1, xdim2_tea_leaf_common_init_diag_init_kernel};
      
	OPS_ACC(Mi, 0,0) = 1.0/(1.0
			+(*ry)*(OPS_ACC(Ky, 0,1) + OPS_ACC(Ky, 0,0))
			+(*rx)*(OPS_ACC(Kx, 1,0) + OPS_ACC(Kx, 0,0)));

    }
  }
}
