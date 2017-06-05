//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_update_halo_kernel1_b1;
extern int xdim1_update_halo_kernel1_b1;
extern int xdim2_update_halo_kernel1_b1;
extern int xdim3_update_halo_kernel1_b1;
extern int xdim4_update_halo_kernel1_b1;
extern int xdim5_update_halo_kernel1_b1;
extern int xdim6_update_halo_kernel1_b1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

#define OPS_ACC0(x, y) (x + xdim0_update_halo_kernel1_b1 * (y))
#define OPS_ACC1(x, y) (x + xdim1_update_halo_kernel1_b1 * (y))
#define OPS_ACC2(x, y) (x + xdim2_update_halo_kernel1_b1 * (y))
#define OPS_ACC3(x, y) (x + xdim3_update_halo_kernel1_b1 * (y))
#define OPS_ACC4(x, y) (x + xdim4_update_halo_kernel1_b1 * (y))
#define OPS_ACC5(x, y) (x + xdim5_update_halo_kernel1_b1 * (y))
#define OPS_ACC6(x, y) (x + xdim6_update_halo_kernel1_b1 * (y))

// user function

void update_halo_kernel1_b1_c_wrapper(
    double *p_a0, int base0, int tot0, double *p_a1, int base1, int tot1,
    double *p_a2, int base2, int tot2, double *p_a3, int base3, int tot3,
    double *p_a4, int base4, int tot4, double *p_a5, int base5, int tot5,
    double *p_a6, int base6, int tot6, int *p_a7, int tot7, int x_size,
    int y_size) {
  int num_blocks = round(((double)x_size * (double)y_size) / 128);
#pragma omp target enter data map(                                             \
    to : p_a0[0 : tot0], p_a1[0 : tot1],                                       \
                              p_a2[0 : tot2],                                  \
                                   p_a3[0 : tot3],                             \
                                        p_a4[0 : tot4],                        \
                                             p_a5[0 : tot5],                   \
                                                  p_a6[0 : tot6],              \
                                                       p_a7[0 : tot7])
#ifdef OPS_GPU

#pragma omp target map(to : p_a0[0 : tot0],                                    \
                                 p_a1[0 : tot1],                               \
                                      p_a2[0 : tot2],                          \
                                           p_a3[0 : tot3],                     \
                                                p_a4[0 : tot4],                \
                                                     p_a5[0 : tot5],           \
                                                          p_a6[0 : tot6],      \
                                                               p_a7[0 : tot7])
#pragma omp teams num_teams(num_blocks) thread_limit(128)
#pragma omp distribute parallel for simd collapse(2) schedule(static, 1)
#endif
  for (int n_y = 0; n_y < y_size; n_y++) {
#ifdef OPS_GPU
#endif
    for (int n_x = 0; n_x < x_size; n_x++) {
      double *density0 = p_a0 + base0 + n_x * 1 * 1 +
                         n_y * xdim0_update_halo_kernel1_b1 * 1 * 1;

      double *density1 = p_a1 + base1 + n_x * 1 * 1 +
                         n_y * xdim1_update_halo_kernel1_b1 * 1 * 1;
      double *energy0 = p_a2 + base2 + n_x * 1 * 1 +
                        n_y * xdim2_update_halo_kernel1_b1 * 1 * 1;

      double *energy1 = p_a3 + base3 + n_x * 1 * 1 +
                        n_y * xdim3_update_halo_kernel1_b1 * 1 * 1;
      double *pressure = p_a4 + base4 + n_x * 1 * 1 +
                         n_y * xdim4_update_halo_kernel1_b1 * 1 * 1;

      double *viscosity = p_a5 + base5 + n_x * 1 * 1 +
                          n_y * xdim5_update_halo_kernel1_b1 * 1 * 1;
      double *soundspeed = p_a6 + base6 + n_x * 1 * 1 +
                           n_y * xdim6_update_halo_kernel1_b1 * 1 * 1;

      const int *fields = p_a7;

      if (fields[FIELD_DENSITY0] == 1)
        density0[OPS_ACC0(0, 0)] = density0[OPS_ACC0(0, 1)];
      if (fields[FIELD_DENSITY1] == 1)
        density1[OPS_ACC1(0, 0)] = density1[OPS_ACC1(0, 1)];
      if (fields[FIELD_ENERGY0] == 1)
        energy0[OPS_ACC2(0, 0)] = energy0[OPS_ACC2(0, 1)];
      if (fields[FIELD_ENERGY1] == 1)
        energy1[OPS_ACC3(0, 0)] = energy1[OPS_ACC3(0, 1)];
      if (fields[FIELD_PRESSURE] == 1)
        pressure[OPS_ACC4(0, 0)] = pressure[OPS_ACC4(0, 1)];
      if (fields[FIELD_VISCOSITY] == 1)
        viscosity[OPS_ACC5(0, 0)] = viscosity[OPS_ACC5(0, 1)];
      if (fields[FIELD_SOUNDSPEED] == 1)
        soundspeed[OPS_ACC6(0, 0)] = soundspeed[OPS_ACC6(0, 1)];
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
