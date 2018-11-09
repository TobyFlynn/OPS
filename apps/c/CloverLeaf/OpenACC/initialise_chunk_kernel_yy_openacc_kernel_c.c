//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_initialise_chunk_kernel_yy;

//user function
inline 
void initialise_chunk_kernel_yy(ptr_int yy, int *idx) {
  OPS_ACC(yy, 0,0) = idx[1]-2;
}


void initialise_chunk_kernel_yy_c_wrapper(
  int *p_a0,
  int *p_a1,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int arg_idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      ptr_int ptr0 = {  p_a0 + n_x*0*1 + n_y*xdim0_initialise_chunk_kernel_yy*1*1, xdim0_initialise_chunk_kernel_yy};
      initialise_chunk_kernel_yy( ptr0,
          arg_idx );

    }
  }
}
