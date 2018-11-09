//
// auto-generated by ops.py
//

int xdim0_multidim_kernel;
int ydim0_multidim_kernel;
int zdim0_multidim_kernel;


//user function



void multidim_kernel_c_wrapper(
  double * restrict val_p,
  int * restrict idx,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        int idx[] = {arg_idx0+n_x, arg_idx1+n_y, arg_idx2+n_z};
        #ifdef OPS_SOA
        ptrm_double val = { val_p + n_x*1 + n_y * xdim0_multidim_kernel*1 + n_z * xdim0_multidim_kernel * ydim0_multidim_kernel*1, xdim0_multidim_kernel, ydim0_multidim_kernel, zdim0_multidim_kernel};
        #else
        ptrm_double val = { val_p + n_x*1 + n_y * xdim0_multidim_kernel*1 + n_z * xdim0_multidim_kernel * ydim0_multidim_kernel*1, xdim0_multidim_kernel, ydim0_multidim_kernel, 3};
        #endif
        
  OPS_ACC(val, 0,0,0,0) = (double)(idx[0]);
  OPS_ACC(val, 1,0,0,0) = (double)(idx[1]);
  OPS_ACC(val, 2,0,0,0) = (double)(idx[2]);




      }
    }
  }
}

#undef OPS_ACC_MD0
