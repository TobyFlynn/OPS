//
// auto-generated by ops.py
//
#include "./OpenMP4/poisson_common.h"

#define OPS_GPU

extern int xdim0_poisson_kernel_update;
extern int xdim1_poisson_kernel_update;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y) (x + xdim0_poisson_kernel_update * (y))
#define OPS_ACC1(x, y) (x + xdim1_poisson_kernel_update * (y))

// user function

void poisson_kernel_update_c_wrapper(double *p_a0, int base0, int tot0,
                                     double *p_a1, int base1, int tot1,
                                     int x_size, int y_size) {
  int num_blocks = round(((double)x_size * (double)y_size) / 64);
#pragma omp target enter data map(to : p_a0[0 : tot0], p_a1[0 : tot1])
#ifdef OPS_GPU

#pragma omp target map(to : p_a0[0 : tot0], p_a1[0 : tot1])
#pragma omp teams num_teams(num_blocks) thread_limit(64)
#pragma omp distribute parallel for simd collapse(2) schedule(static, 1)
#endif
  for (int n_y = 0; n_y < y_size; n_y++) {
#ifdef OPS_GPU
#endif
    for (int n_x = 0; n_x < x_size; n_x++) {
      const double *u2 = p_a0 + base0 + n_x * 1 * 1 +
                         n_y * xdim0_poisson_kernel_update * 1 * 1;

      double *u = p_a1 + base1 + n_x * 1 * 1 +
                  n_y * xdim1_poisson_kernel_update * 1 * 1;

      u[OPS_ACC1(0, 0)] = u2[OPS_ACC0(0, 0)];
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
