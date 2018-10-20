//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_update_halo_kernel1_fr1;
int ydim0_update_halo_kernel1_fr1;
int xdim1_update_halo_kernel1_fr1;
int ydim1_update_halo_kernel1_fr1;
int xdim2_update_halo_kernel1_fr1;
int ydim2_update_halo_kernel1_fr1;
int xdim3_update_halo_kernel1_fr1;
int ydim3_update_halo_kernel1_fr1;
int xdim4_update_halo_kernel1_fr1;
int ydim4_update_halo_kernel1_fr1;
int xdim5_update_halo_kernel1_fr1;
int ydim5_update_halo_kernel1_fr1;
int xdim6_update_halo_kernel1_fr1;
int ydim6_update_halo_kernel1_fr1;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim0_update_halo_kernel1_fr1 +             \
   (n_z * 1 + (z)) * xdim0_update_halo_kernel1_fr1 *                           \
       ydim0_update_halo_kernel1_fr1)
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim1_update_halo_kernel1_fr1 +             \
   (n_z * 1 + (z)) * xdim1_update_halo_kernel1_fr1 *                           \
       ydim1_update_halo_kernel1_fr1)
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim2_update_halo_kernel1_fr1 +             \
   (n_z * 1 + (z)) * xdim2_update_halo_kernel1_fr1 *                           \
       ydim2_update_halo_kernel1_fr1)
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim3_update_halo_kernel1_fr1 +             \
   (n_z * 1 + (z)) * xdim3_update_halo_kernel1_fr1 *                           \
       ydim3_update_halo_kernel1_fr1)
#define OPS_ACC4(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim4_update_halo_kernel1_fr1 +             \
   (n_z * 1 + (z)) * xdim4_update_halo_kernel1_fr1 *                           \
       ydim4_update_halo_kernel1_fr1)
#define OPS_ACC5(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim5_update_halo_kernel1_fr1 +             \
   (n_z * 1 + (z)) * xdim5_update_halo_kernel1_fr1 *                           \
       ydim5_update_halo_kernel1_fr1)
#define OPS_ACC6(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim6_update_halo_kernel1_fr1 +             \
   (n_z * 1 + (z)) * xdim6_update_halo_kernel1_fr1 *                           \
       ydim6_update_halo_kernel1_fr1)
//user function



void update_halo_kernel1_fr1_c_wrapper(
  double * restrict density0,
  double * restrict density1,
  double * restrict energy0,
  double * restrict energy1,
  double * restrict pressure,
  double * restrict viscosity,
  double * restrict soundspeed,
  const int * restrict fields,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        
  if(fields[FIELD_DENSITY0] == 1) density0[OPS_ACC0(0,0,0)] = density0[OPS_ACC0(0,0,-1)];
  if(fields[FIELD_DENSITY1] == 1) density1[OPS_ACC1(0,0,0)] = density1[OPS_ACC1(0,0,-1)];
  if(fields[FIELD_ENERGY0] == 1) energy0[OPS_ACC2(0,0,0)] = energy0[OPS_ACC2(0,0,-1)];
  if(fields[FIELD_ENERGY1] == 1) energy1[OPS_ACC3(0,0,0)] = energy1[OPS_ACC3(0,0,-1)];
  if(fields[FIELD_PRESSURE] == 1) pressure[OPS_ACC4(0,0,0)] = pressure[OPS_ACC4(0,0,-1)];
  if(fields[FIELD_VISCOSITY] == 1) viscosity[OPS_ACC5(0,0,0)] = viscosity[OPS_ACC5(0,0,-1)];
  if(fields[FIELD_SOUNDSPEED] == 1) soundspeed[OPS_ACC6(0,0,0)] = soundspeed[OPS_ACC6(0,0,-1)];


      }
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

