//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_advec_mom_kernel_mass_flux_x;
int ydim0_advec_mom_kernel_mass_flux_x;
int xdim1_advec_mom_kernel_mass_flux_x;
int ydim1_advec_mom_kernel_mass_flux_x;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim0_advec_mom_kernel_mass_flux_x * 1 +                    \
   n_z * xdim0_advec_mom_kernel_mass_flux_x *                                  \
       ydim0_advec_mom_kernel_mass_flux_x * 1 +                                \
   x + xdim0_advec_mom_kernel_mass_flux_x * (y) +                              \
   xdim0_advec_mom_kernel_mass_flux_x * ydim0_advec_mom_kernel_mass_flux_x *   \
       (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim1_advec_mom_kernel_mass_flux_x * 1 +                    \
   n_z * xdim1_advec_mom_kernel_mass_flux_x *                                  \
       ydim1_advec_mom_kernel_mass_flux_x * 1 +                                \
   x + xdim1_advec_mom_kernel_mass_flux_x * (y) +                              \
   xdim1_advec_mom_kernel_mass_flux_x * ydim1_advec_mom_kernel_mass_flux_x *   \
       (z))

// user function

void advec_mom_kernel_mass_flux_x_c_wrapper(double *restrict node_flux,
                                            const double *restrict mass_flux_x,
                                            int x_size, int y_size,
                                            int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {

        node_flux[OPS_ACC0(0, 0, 0)] =
            0.125 *
            (mass_flux_x[OPS_ACC1(0, -1, 0)] + mass_flux_x[OPS_ACC1(0, 0, 0)] +
             mass_flux_x[OPS_ACC1(1, -1, 0)] + mass_flux_x[OPS_ACC1(1, 0, 0)] +
             mass_flux_x[OPS_ACC1(0, -1, -1)] +
             mass_flux_x[OPS_ACC1(0, 0, -1)] +
             mass_flux_x[OPS_ACC1(1, -1, -1)] +
             mass_flux_x[OPS_ACC1(1, 0, -1)]);
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
