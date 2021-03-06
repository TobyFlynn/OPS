//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_flux_calc_kernely;
int ydim0_flux_calc_kernely;
int xdim1_flux_calc_kernely;
int ydim1_flux_calc_kernely;
int xdim2_flux_calc_kernely;
int ydim2_flux_calc_kernely;
int xdim3_flux_calc_kernely;
int ydim3_flux_calc_kernely;

//user function
#pragma acc routine
inline 
void flux_calc_kernely(ptr_double vol_flux_y,
  const ptr_double yarea,
  const ptr_double yvel0,
  const ptr_double yvel1) {

  OPS_ACC(vol_flux_y, 0,0,0) = 0.125 * dt * (OPS_ACC(yarea, 0,0,0)) *
  ( OPS_ACC(yvel0, 0,0,0) + OPS_ACC(yvel0, 1,0,0) + OPS_ACC(yvel0, 0,0,1) + OPS_ACC(yvel0, 1,0,1) +
    OPS_ACC(yvel1, 0,0,0) + OPS_ACC(yvel1, 1,0,0) + OPS_ACC(yvel1, 0,0,1) + OPS_ACC(yvel1, 1,0,1));
}


void flux_calc_kernely_c_wrapper(
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
        ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_flux_calc_kernely*1*1 + n_z*xdim0_flux_calc_kernely*ydim0_flux_calc_kernely*1*1, xdim0_flux_calc_kernely, ydim0_flux_calc_kernely};
        const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_flux_calc_kernely*1*1 + n_z*xdim1_flux_calc_kernely*ydim1_flux_calc_kernely*1*1, xdim1_flux_calc_kernely, ydim1_flux_calc_kernely};
        const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_flux_calc_kernely*1*1 + n_z*xdim2_flux_calc_kernely*ydim2_flux_calc_kernely*1*1, xdim2_flux_calc_kernely, ydim2_flux_calc_kernely};
        const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_flux_calc_kernely*1*1 + n_z*xdim3_flux_calc_kernely*ydim3_flux_calc_kernely*1*1, xdim3_flux_calc_kernely, ydim3_flux_calc_kernely};
        flux_calc_kernely( ptr0,
          ptr1,
          ptr2,
          ptr3 );

      }
    }
  }
}
