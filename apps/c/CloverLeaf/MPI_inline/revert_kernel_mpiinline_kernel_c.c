//
// auto-generated by ops.py
//

int xdim0_revert_kernel;
int xdim1_revert_kernel;
int xdim2_revert_kernel;
int xdim3_revert_kernel;


#define OPS_ACC0(x,y) (n_x*1 + x + (n_y*1+(y))*xdim0_revert_kernel)
#define OPS_ACC1(x,y) (n_x*1 + x + (n_y*1+(y))*xdim1_revert_kernel)
#define OPS_ACC2(x,y) (n_x*1 + x + (n_y*1+(y))*xdim2_revert_kernel)
#define OPS_ACC3(x,y) (n_x*1 + x + (n_y*1+(y))*xdim3_revert_kernel)
//user function



void revert_kernel_c_wrapper(
  const double * restrict density0,
  double * restrict density1,
  const double * restrict energy0,
  double * restrict energy1,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      

  density1[OPS_ACC1(0,0)] = density0[OPS_ACC0(0,0)];
  energy1[OPS_ACC3(0,0)] = energy0[OPS_ACC2(0,0)];

    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

