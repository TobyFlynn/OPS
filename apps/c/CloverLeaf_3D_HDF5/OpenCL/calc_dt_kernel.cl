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

void calc_dt_kernel(const ptr_double celldx,
  const ptr_double celldy,
  const ptr_double soundspeed,
  const ptr_double viscosity,
  const ptr_double density0,
  const ptr_double xvel0,
  const ptr_double xarea,
  const ptr_double volume,
  const ptr_double yvel0,
  const ptr_double yarea,
  ptr_double dt_min,
  const ptr_double celldz,
  const ptr_double zvel0,
  const ptr_double zarea, const double g_small, const double dtc_safe, const double dtu_safe, const double dtv_safe, const double dtw_safe, const double dtdiv_safe)
{

  double div, ds, dtut, dtvt, dtct, dtwt, dtdivt, cc, dv1, dv2, du1, du2, dw1, dw2;

  ds = MIN(MIN(OPS_ACCS(celldx, 0,0,0), OPS_ACCS(celldy, 0,0,0)), OPS_ACCS(celldz, 0,0,0));
  ds = 1.0/(ds*ds);

  cc = OPS_ACCS(soundspeed, 0,0,0) * OPS_ACCS(soundspeed, 0,0,0);
  cc = cc + 2.0 * OPS_ACCS(viscosity, 0,0,0)/OPS_ACCS(density0, 0,0,0);

  dtct=ds*cc;
  dtct = dtc_safe*1.0/MAX(sqrt(dtct),g_small);

  du1=(OPS_ACCS(xvel0, 0,0,0)+OPS_ACCS(xvel0, 0,1,0)+OPS_ACCS(xvel0, 0,0,1)+OPS_ACCS(xvel0, 0,1,1))*OPS_ACCS(xarea, 0,0,0);
  du2=(OPS_ACCS(xvel0, 1,0,0)+OPS_ACCS(xvel0, 1,1,0)+OPS_ACCS(xvel0, 1,0,1)+OPS_ACCS(xvel0, 1,1,1))*OPS_ACCS(xarea, 0,0,0);

  dtut = dtu_safe * 4.0 * OPS_ACCS(volume, 0,0,0)/MAX(MAX(fabs(du1), fabs(du2)), 1.0e-5 * OPS_ACCS(volume, 0,0,0));

  dv1=(OPS_ACCS(yvel0, 0,0,0)+OPS_ACCS(yvel0, 1,0,0)+OPS_ACCS(yvel0, 0,0,1)+OPS_ACCS(yvel0, 1,0,1))*OPS_ACCS(yarea, 0,0,0);
  dv2=(OPS_ACCS(yvel0, 0,1,0)+OPS_ACCS(yvel0, 1,1,0)+OPS_ACCS(yvel0, 0,1,1)+OPS_ACCS(yvel0, 1,1,1))*OPS_ACCS(yarea, 0,0,0);

  dtvt = dtv_safe * 4.0 * OPS_ACCS(volume, 0,0,0)/MAX(MAX(fabs(dv1),fabs(dv2)), 1.0e-5 * OPS_ACCS(volume, 0,0,0));

  dw1=(OPS_ACCS(zvel0, 0,0,0)+OPS_ACCS(zvel0, 0,1,0)+OPS_ACCS(zvel0, 1,0,0)+OPS_ACCS(zvel0, 1,1,0))*OPS_ACCS(zarea, 0,0,0);
  dw2=(OPS_ACCS(zvel0, 0,0,1)+OPS_ACCS(zvel0, 0,1,1)+OPS_ACCS(zvel0, 1,0,1)+OPS_ACCS(zvel0, 1,1,1))*OPS_ACCS(zarea, 0,0,0);

  dtwt = dtw_safe * 4.0 * OPS_ACCS(volume, 0,0,0)/MAX(MAX(fabs(dw1),fabs(dw2)), 1.0e-5 * OPS_ACCS(volume, 0,0,0));

  div = du2-du1+dv2-dv1+dw2-dw1;
  dtdivt=dtdiv_safe*4.0*(OPS_ACCS(volume, 0,0,0))/MAX(OPS_ACCS(volume, 0,0,0)*1.0e-05,fabs(div));

  OPS_ACCS(dt_min, 0,0,0) = MIN(MIN(MIN(dtct, dtut), MIN(dtvt, dtdivt)),dtwt);
}


__kernel void ops_calc_dt_kernel(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
__global const double* restrict arg5,
__global const double* restrict arg6,
__global const double* restrict arg7,
__global const double* restrict arg8,
__global const double* restrict arg9,
__global double* restrict arg10,
__global const double* restrict arg11,
__global const double* restrict arg12,
__global const double* restrict arg13,
const double g_small,
const double dtc_safe,
const double dtu_safe,
const double dtv_safe,
const double dtw_safe,
const double dtdiv_safe,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int base6,
const int base7,
const int base8,
const int base9,
const int base10,
const int base11,
const int base12,
const int base13,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 0*1 * xdim0_calc_dt_kernel + idx_z * 0*1 * xdim0_calc_dt_kernel * ydim0_calc_dt_kernel], xdim0_calc_dt_kernel, ydim0_calc_dt_kernel};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 0*1 + idx_y * 1*1 * xdim1_calc_dt_kernel + idx_z * 0*1 * xdim1_calc_dt_kernel * ydim1_calc_dt_kernel], xdim1_calc_dt_kernel, ydim1_calc_dt_kernel};
    const ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_calc_dt_kernel + idx_z * 1*1 * xdim2_calc_dt_kernel * ydim2_calc_dt_kernel], xdim2_calc_dt_kernel, ydim2_calc_dt_kernel};
    const ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_calc_dt_kernel + idx_z * 1*1 * xdim3_calc_dt_kernel * ydim3_calc_dt_kernel], xdim3_calc_dt_kernel, ydim3_calc_dt_kernel};
    const ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_calc_dt_kernel + idx_z * 1*1 * xdim4_calc_dt_kernel * ydim4_calc_dt_kernel], xdim4_calc_dt_kernel, ydim4_calc_dt_kernel};
    const ptr_double ptr5 = { &arg5[base5 + idx_x * 1*1 + idx_y * 1*1 * xdim5_calc_dt_kernel + idx_z * 1*1 * xdim5_calc_dt_kernel * ydim5_calc_dt_kernel], xdim5_calc_dt_kernel, ydim5_calc_dt_kernel};
    const ptr_double ptr6 = { &arg6[base6 + idx_x * 1*1 + idx_y * 1*1 * xdim6_calc_dt_kernel + idx_z * 1*1 * xdim6_calc_dt_kernel * ydim6_calc_dt_kernel], xdim6_calc_dt_kernel, ydim6_calc_dt_kernel};
    const ptr_double ptr7 = { &arg7[base7 + idx_x * 1*1 + idx_y * 1*1 * xdim7_calc_dt_kernel + idx_z * 1*1 * xdim7_calc_dt_kernel * ydim7_calc_dt_kernel], xdim7_calc_dt_kernel, ydim7_calc_dt_kernel};
    const ptr_double ptr8 = { &arg8[base8 + idx_x * 1*1 + idx_y * 1*1 * xdim8_calc_dt_kernel + idx_z * 1*1 * xdim8_calc_dt_kernel * ydim8_calc_dt_kernel], xdim8_calc_dt_kernel, ydim8_calc_dt_kernel};
    const ptr_double ptr9 = { &arg9[base9 + idx_x * 1*1 + idx_y * 1*1 * xdim9_calc_dt_kernel + idx_z * 1*1 * xdim9_calc_dt_kernel * ydim9_calc_dt_kernel], xdim9_calc_dt_kernel, ydim9_calc_dt_kernel};
    ptr_double ptr10 = { &arg10[base10 + idx_x * 1*1 + idx_y * 1*1 * xdim10_calc_dt_kernel + idx_z * 1*1 * xdim10_calc_dt_kernel * ydim10_calc_dt_kernel], xdim10_calc_dt_kernel, ydim10_calc_dt_kernel};
    const ptr_double ptr11 = { &arg11[base11 + idx_x * 0*1 + idx_y * 0*1 * xdim11_calc_dt_kernel + idx_z * 1*1 * xdim11_calc_dt_kernel * ydim11_calc_dt_kernel], xdim11_calc_dt_kernel, ydim11_calc_dt_kernel};
    const ptr_double ptr12 = { &arg12[base12 + idx_x * 1*1 + idx_y * 1*1 * xdim12_calc_dt_kernel + idx_z * 1*1 * xdim12_calc_dt_kernel * ydim12_calc_dt_kernel], xdim12_calc_dt_kernel, ydim12_calc_dt_kernel};
    const ptr_double ptr13 = { &arg13[base13 + idx_x * 1*1 + idx_y * 1*1 * xdim13_calc_dt_kernel + idx_z * 1*1 * xdim13_calc_dt_kernel * ydim13_calc_dt_kernel], xdim13_calc_dt_kernel, ydim13_calc_dt_kernel};
    calc_dt_kernel(ptr0,
                   ptr1,
                   ptr2,
                   ptr3,
                   ptr4,
                   ptr5,
                   ptr6,
                   ptr7,
                   ptr8,
                   ptr9,
                   ptr10,
                   ptr11,
                   ptr12,
                   ptr13,
                   g_small,
                   dtc_safe,
                   dtu_safe,
                   dtv_safe,
                   dtw_safe,
                   dtdiv_safe);
  }

}
