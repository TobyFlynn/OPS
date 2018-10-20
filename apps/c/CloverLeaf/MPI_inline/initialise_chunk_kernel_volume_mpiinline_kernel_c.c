//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_initialise_chunk_kernel_volume;
int xdim1_initialise_chunk_kernel_volume;
int xdim2_initialise_chunk_kernel_volume;
int xdim3_initialise_chunk_kernel_volume;
int xdim4_initialise_chunk_kernel_volume;

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim0_initialise_chunk_kernel_volume)
#define OPS_ACC1(x, y)                                                         \
  (n_x * 0 + x + (n_y * 1 + (y)) * xdim1_initialise_chunk_kernel_volume)
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim2_initialise_chunk_kernel_volume)
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 + x + (n_y * 0 + (y)) * xdim3_initialise_chunk_kernel_volume)
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim4_initialise_chunk_kernel_volume)
// user function

void initialise_chunk_kernel_volume_c_wrapper(double *restrict volume,
                                              const double *restrict celldy,
                                              double *restrict xarea,
                                              const double *restrict celldx,
                                              double *restrict yarea,
                                              int x_size, int y_size) {
#pragma omp parallel for
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {

      double d_x, d_y;

      d_x = (grid.xmax - grid.xmin) / (double)grid.x_cells;
      d_y = (grid.ymax - grid.ymin) / (double)grid.y_cells;

      volume[OPS_ACC0(0, 0)] = d_x * d_y;
      xarea[OPS_ACC2(0, 0)] = celldy[OPS_ACC1(0, 0)];
      yarea[OPS_ACC4(0, 0)] = celldx[OPS_ACC3(0, 0)];
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
