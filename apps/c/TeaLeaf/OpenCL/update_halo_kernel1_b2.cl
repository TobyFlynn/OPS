//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
#define OPS_2D
#define OPS_API 2
#define OPS_NO_GLOBALS
#include "ops_macros.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5

//user function

inline void update_halo_kernel1_b2(ptr_double density0, 
  ptr_double energy0, 
  ptr_double energy1, 
  ptr_double u, 
  ptr_double p, 
  ptr_double sd, 
  const __global int* restrict  fields) {
  if(fields[FIELD_DENSITY] == 1) OPS_ACCS(density0, 0,0) = OPS_ACCS(density0, 0,3);
  if(fields[FIELD_ENERGY0] == 1) OPS_ACCS(energy0, 0,0) = OPS_ACCS(energy0, 0,3);
  if(fields[FIELD_ENERGY1] == 1) OPS_ACCS(energy1, 0,0) = OPS_ACCS(energy1, 0,3);
  if(fields[FIELD_U] == 1) OPS_ACCS(u, 0,0) = OPS_ACCS(u, 0,3);
  if(fields[FIELD_P] == 1) OPS_ACCS(p, 0,0) = OPS_ACCS(p, 0,3);
  if(fields[FIELD_SD] == 1) OPS_ACCS(sd, 0,0) = OPS_ACCS(sd, 0,3);

}


__kernel void ops_update_halo_kernel1_b2(
__global double* restrict arg0,
__global double* restrict arg1,
__global double* restrict arg2,
__global double* restrict arg3,
__global double* restrict arg4,
__global double* restrict arg5,
__global const int* restrict arg6,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int size0,
const int size1 ){


  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_update_halo_kernel1_b2], xdim0_update_halo_kernel1_b2};
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_update_halo_kernel1_b2], xdim1_update_halo_kernel1_b2};
    ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_update_halo_kernel1_b2], xdim2_update_halo_kernel1_b2};
    ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_update_halo_kernel1_b2], xdim3_update_halo_kernel1_b2};
    ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_update_halo_kernel1_b2], xdim4_update_halo_kernel1_b2};
    ptr_double ptr5 = { &arg5[base5 + idx_x * 1*1 + idx_y * 1*1 * xdim5_update_halo_kernel1_b2], xdim5_update_halo_kernel1_b2};
    update_halo_kernel1_b2(ptr0,
                       ptr1,
                       ptr2,
                       ptr3,
                       ptr4,
                       ptr5,
                       arg6);
  }

}
