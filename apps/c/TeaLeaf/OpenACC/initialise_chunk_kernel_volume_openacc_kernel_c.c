//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_initialise_chunk_kernel_volume;
int xdim1_initialise_chunk_kernel_volume;
int xdim2_initialise_chunk_kernel_volume;
int xdim3_initialise_chunk_kernel_volume;
int xdim4_initialise_chunk_kernel_volume;

//user function
#pragma acc routine
inline 
void initialise_chunk_kernel_volume(ptr_double volume,
  const ptr_double celldy,
  ptr_double xarea,
  const ptr_double celldx,
  ptr_double yarea) {

  double d_x, d_y;

  d_x = (grid.xmax - grid.xmin)/(double)grid.x_cells;
  d_y = (grid.ymax - grid.ymin)/(double)grid.y_cells;

  OPS_ACC(volume, 0,0) = d_x*d_y;
  OPS_ACC(xarea, 0,0) = OPS_ACC(celldy, 0,0);
  OPS_ACC(yarea, 0,0) = OPS_ACC(celldx, 0,0);
}


void initialise_chunk_kernel_volume_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_initialise_chunk_kernel_volume*1*1, xdim0_initialise_chunk_kernel_volume};
      const ptr_double ptr1 = {  p_a1 + n_x*0*1 + n_y*xdim1_initialise_chunk_kernel_volume*1*1, xdim1_initialise_chunk_kernel_volume};
      ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_initialise_chunk_kernel_volume*1*1, xdim2_initialise_chunk_kernel_volume};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_initialise_chunk_kernel_volume*0*1, xdim3_initialise_chunk_kernel_volume};
      ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_initialise_chunk_kernel_volume*1*1, xdim4_initialise_chunk_kernel_volume};
      initialise_chunk_kernel_volume( ptr0,
          ptr1,ptr2,
          ptr3,ptr4 );

    }
  }
}
