//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_1D
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

void calvar_kernel(const ptr_double rho_new,
  const ptr_double rhou_new,
  const ptr_double rhoE_new,
  ptr_double workarray2,
  ptr_double workarray3, const double gam1)
{
  double p, rhoi, u;
  rhoi = 1/OPS_ACCS(rho_new, 0);
  u = OPS_ACCS(rhou_new, 0) * rhoi;
  p = gam1 * (OPS_ACCS(rhoE_new, 0) - 0.5 * OPS_ACCS(rho_new, 0)* u * u);

  OPS_ACCS(workarray2, 0) = p + OPS_ACCS(rhou_new, 0) * u ;
  OPS_ACCS(workarray3, 0) = (p + OPS_ACCS(rhoE_new, 0)) * u ;
  }


__kernel void ops_calvar_kernel(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global double* restrict arg3,
__global double* restrict arg4,
const double gam1,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int size0 ){


  int idx_x = get_global_id(0);

  if (idx_x < size0) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1] };
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1] };
    const ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1] };
    ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1] };
    ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1] };
    calvar_kernel(ptr0,
                  ptr1,
                  ptr2,
                  ptr3,
                  ptr4,
                  gam1);
  }

}
