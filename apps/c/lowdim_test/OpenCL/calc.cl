//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_3D
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

void calc(ptr_double dat3D,
  const ptr_double dat2D_xy,
  const ptr_double dat2D_yz,
  const ptr_double dat2D_xz,
  const ptr_double dat1D_x,
  const ptr_double dat1D_y,
  const ptr_double dat1D_z)
{
  OPS_ACCS(dat3D, 0,0,0) = OPS_ACCS(dat2D_xy, 0,0,0) +
                           OPS_ACCS(dat2D_yz, 0,0,0) +
                           OPS_ACCS(dat2D_xz, 0,0,0) +
                           OPS_ACCS(dat1D_x, 0,0,0) +
                           OPS_ACCS(dat1D_y, 0,0,0) +
                           OPS_ACCS(dat1D_z, 0,0,0);
}


__kernel void ops_calc(
__global double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
__global const double* restrict arg5,
__global const double* restrict arg6,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int base6,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_calc + idx_z * 1*1 * xdim0_calc * ydim0_calc], xdim0_calc, ydim0_calc};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_calc + idx_z * 0*1 * xdim1_calc * ydim1_calc], xdim1_calc, ydim1_calc};
    const ptr_double ptr2 = { &arg2[base2 + idx_x * 0*1 + idx_y * 1*1 * xdim2_calc + idx_z * 1*1 * xdim2_calc * ydim2_calc], xdim2_calc, ydim2_calc};
    const ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 0*1 * xdim3_calc + idx_z * 1*1 * xdim3_calc * ydim3_calc], xdim3_calc, ydim3_calc};
    const ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 0*1 * xdim4_calc + idx_z * 0*1 * xdim4_calc * ydim4_calc], xdim4_calc, ydim4_calc};
    const ptr_double ptr5 = { &arg5[base5 + idx_x * 0*1 + idx_y * 1*1 * xdim5_calc + idx_z * 0*1 * xdim5_calc * ydim5_calc], xdim5_calc, ydim5_calc};
    const ptr_double ptr6 = { &arg6[base6 + idx_x * 0*1 + idx_y * 0*1 * xdim6_calc + idx_z * 1*1 * xdim6_calc * ydim6_calc], xdim6_calc, ydim6_calc};
    calc(ptr0,
              ptr1,
              ptr2,
              ptr3,
              ptr4,
              ptr5,
              ptr6);
  }

}
