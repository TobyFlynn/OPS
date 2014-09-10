//
// auto-generated by ops.py
//
__constant__ int xdim0_calc_dt_kernel;
int xdim0_calc_dt_kernel_h = -1;
int ydim0_calc_dt_kernel_h = -1;
__constant__ int xdim1_calc_dt_kernel;
int xdim1_calc_dt_kernel_h = -1;
int ydim1_calc_dt_kernel_h = -1;
__constant__ int xdim2_calc_dt_kernel;
int xdim2_calc_dt_kernel_h = -1;
int ydim2_calc_dt_kernel_h = -1;
__constant__ int xdim3_calc_dt_kernel;
int xdim3_calc_dt_kernel_h = -1;
int ydim3_calc_dt_kernel_h = -1;
__constant__ int xdim4_calc_dt_kernel;
int xdim4_calc_dt_kernel_h = -1;
int ydim4_calc_dt_kernel_h = -1;
__constant__ int xdim5_calc_dt_kernel;
int xdim5_calc_dt_kernel_h = -1;
int ydim5_calc_dt_kernel_h = -1;
__constant__ int xdim6_calc_dt_kernel;
int xdim6_calc_dt_kernel_h = -1;
int ydim6_calc_dt_kernel_h = -1;
__constant__ int xdim7_calc_dt_kernel;
int xdim7_calc_dt_kernel_h = -1;
int ydim7_calc_dt_kernel_h = -1;
__constant__ int xdim8_calc_dt_kernel;
int xdim8_calc_dt_kernel_h = -1;
int ydim8_calc_dt_kernel_h = -1;
__constant__ int xdim9_calc_dt_kernel;
int xdim9_calc_dt_kernel_h = -1;
int ydim9_calc_dt_kernel_h = -1;
__constant__ int xdim10_calc_dt_kernel;
int xdim10_calc_dt_kernel_h = -1;
int ydim10_calc_dt_kernel_h = -1;

#define OPS_ACC0(x,y) (x+xdim0_calc_dt_kernel*(y))
#define OPS_ACC1(x,y) (x+xdim1_calc_dt_kernel*(y))
#define OPS_ACC2(x,y) (x+xdim2_calc_dt_kernel*(y))
#define OPS_ACC3(x,y) (x+xdim3_calc_dt_kernel*(y))
#define OPS_ACC4(x,y) (x+xdim4_calc_dt_kernel*(y))
#define OPS_ACC5(x,y) (x+xdim5_calc_dt_kernel*(y))
#define OPS_ACC6(x,y) (x+xdim6_calc_dt_kernel*(y))
#define OPS_ACC7(x,y) (x+xdim7_calc_dt_kernel*(y))
#define OPS_ACC8(x,y) (x+xdim8_calc_dt_kernel*(y))
#define OPS_ACC9(x,y) (x+xdim9_calc_dt_kernel*(y))
#define OPS_ACC10(x,y) (x+xdim10_calc_dt_kernel*(y))

//user function
__device__

void calc_dt_kernel(const double *celldx, const double *celldy, const double *soundspeed,
                    const double *viscosity, const double *density0, const double *xvel0,
                    const double *xarea, const double *volume, const double *yvel0,
                    const double *yarea, double *dt_min ) {

  double div, dsx, dsy, dtut, dtvt, dtct, dtdivt, cc, dv1, dv2, jk_control;

  dsx = celldx[OPS_ACC0(0,0)];
  dsy = celldy[OPS_ACC1(0,0)];

  cc = soundspeed[OPS_ACC2(0,0)] * soundspeed[OPS_ACC2(0,0)];
  cc = cc + 2.0 * viscosity[OPS_ACC3(0,0)]/density0[OPS_ACC4(0,0)];
  cc = MAX(sqrt(cc),g_small);

  dtct = dtc_safe * MIN(dsx,dsy)/cc;

  div=0.0;


  dv1 = (xvel0[OPS_ACC5(0,0)] + xvel0[OPS_ACC5(0,1)]) * xarea[OPS_ACC6(0,0)];
  dv2 = (xvel0[OPS_ACC5(1,0)] + xvel0[OPS_ACC5(1,1)]) * xarea[OPS_ACC6(1,0)];

  div = div + dv2 - dv1;

  dtut = dtu_safe * 2.0 * volume[OPS_ACC7(0,0)]/MAX(MAX(fabs(dv1), fabs(dv2)), g_small * volume[OPS_ACC7(0,0)]);

  dv1 = (yvel0[OPS_ACC8(0,0)] + yvel0[OPS_ACC8(1,0)]) * yarea[OPS_ACC9(0,0)];
  dv2 = (yvel0[OPS_ACC8(0,1)] + yvel0[OPS_ACC8(1,1)]) * yarea[OPS_ACC9(0,1)];

  div = div + dv2 - dv1;

  dtvt = dtv_safe * 2.0 * volume[OPS_ACC7(0,0)]/MAX(MAX(fabs(dv1),fabs(dv2)), g_small * volume[OPS_ACC7(0,0)]);

  div = div/(2.0 * volume[OPS_ACC7(0,0)]);

  if(div < -g_small)
    dtdivt = dtdiv_safe * (-1.0/div);
  else
    dtdivt = g_big;

  dt_min[OPS_ACC10(0,0)] = MIN(MIN(dtct, dtut), MIN(dtvt, dtdivt));


}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10


__global__ void ops_calc_dt_kernel(
const double* __restrict arg0,
const double* __restrict arg1,
const double* __restrict arg2,
const double* __restrict arg3,
const double* __restrict arg4,
const double* __restrict arg5,
const double* __restrict arg6,
const double* __restrict arg7,
const double* __restrict arg8,
const double* __restrict arg9,
double* __restrict arg10,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 0 * xdim0_calc_dt_kernel;
  arg1 += idx_x * 0 + idx_y * 1 * xdim1_calc_dt_kernel;
  arg2 += idx_x * 1 + idx_y * 1 * xdim2_calc_dt_kernel;
  arg3 += idx_x * 1 + idx_y * 1 * xdim3_calc_dt_kernel;
  arg4 += idx_x * 1 + idx_y * 1 * xdim4_calc_dt_kernel;
  arg5 += idx_x * 1 + idx_y * 1 * xdim5_calc_dt_kernel;
  arg6 += idx_x * 1 + idx_y * 1 * xdim6_calc_dt_kernel;
  arg7 += idx_x * 1 + idx_y * 1 * xdim7_calc_dt_kernel;
  arg8 += idx_x * 1 + idx_y * 1 * xdim8_calc_dt_kernel;
  arg9 += idx_x * 1 + idx_y * 1 * xdim9_calc_dt_kernel;
  arg10 += idx_x * 1 + idx_y * 1 * xdim10_calc_dt_kernel;

  if (idx_x < size0 && idx_y < size1) {
    calc_dt_kernel(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6, arg7, arg8,
                   arg9, arg10);
  }

}

// host stub function
void ops_par_loop_calc_dt_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8,
 ops_arg arg9, ops_arg arg10) {

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};


  ops_timing_realloc(71,"calc_dt_kernel");
  OPS_kernels[71].count++;

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<2; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  int xdim0 = args[0].dat->size[0]*args[0].dat->dim;
  int xdim1 = args[1].dat->size[0]*args[1].dat->dim;
  int xdim2 = args[2].dat->size[0]*args[2].dat->dim;
  int xdim3 = args[3].dat->size[0]*args[3].dat->dim;
  int xdim4 = args[4].dat->size[0]*args[4].dat->dim;
  int xdim5 = args[5].dat->size[0]*args[5].dat->dim;
  int xdim6 = args[6].dat->size[0]*args[6].dat->dim;
  int xdim7 = args[7].dat->size[0]*args[7].dat->dim;
  int xdim8 = args[8].dat->size[0]*args[8].dat->dim;
  int xdim9 = args[9].dat->size[0]*args[9].dat->dim;
  int xdim10 = args[10].dat->size[0]*args[10].dat->dim;


  //Timing
  double t1,t2,c1,c2;
  ops_timers_core(&c2,&t2);

  if (xdim0 != xdim0_calc_dt_kernel_h || xdim1 != xdim1_calc_dt_kernel_h || xdim2 != xdim2_calc_dt_kernel_h || xdim3 != xdim3_calc_dt_kernel_h || xdim4 != xdim4_calc_dt_kernel_h || xdim5 != xdim5_calc_dt_kernel_h || xdim6 != xdim6_calc_dt_kernel_h || xdim7 != xdim7_calc_dt_kernel_h || xdim8 != xdim8_calc_dt_kernel_h || xdim9 != xdim9_calc_dt_kernel_h || xdim10 != xdim10_calc_dt_kernel_h) {
    cudaMemcpyToSymbol( xdim0_calc_dt_kernel, &xdim0, sizeof(int) );
    xdim0_calc_dt_kernel_h = xdim0;
    cudaMemcpyToSymbol( xdim1_calc_dt_kernel, &xdim1, sizeof(int) );
    xdim1_calc_dt_kernel_h = xdim1;
    cudaMemcpyToSymbol( xdim2_calc_dt_kernel, &xdim2, sizeof(int) );
    xdim2_calc_dt_kernel_h = xdim2;
    cudaMemcpyToSymbol( xdim3_calc_dt_kernel, &xdim3, sizeof(int) );
    xdim3_calc_dt_kernel_h = xdim3;
    cudaMemcpyToSymbol( xdim4_calc_dt_kernel, &xdim4, sizeof(int) );
    xdim4_calc_dt_kernel_h = xdim4;
    cudaMemcpyToSymbol( xdim5_calc_dt_kernel, &xdim5, sizeof(int) );
    xdim5_calc_dt_kernel_h = xdim5;
    cudaMemcpyToSymbol( xdim6_calc_dt_kernel, &xdim6, sizeof(int) );
    xdim6_calc_dt_kernel_h = xdim6;
    cudaMemcpyToSymbol( xdim7_calc_dt_kernel, &xdim7, sizeof(int) );
    xdim7_calc_dt_kernel_h = xdim7;
    cudaMemcpyToSymbol( xdim8_calc_dt_kernel, &xdim8, sizeof(int) );
    xdim8_calc_dt_kernel_h = xdim8;
    cudaMemcpyToSymbol( xdim9_calc_dt_kernel, &xdim9, sizeof(int) );
    xdim9_calc_dt_kernel_h = xdim9;
    cudaMemcpyToSymbol( xdim10_calc_dt_kernel, &xdim10, sizeof(int) );
    xdim10_calc_dt_kernel_h = xdim10;
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;
  int dat7 = args[7].dat->elem_size;
  int dat8 = args[8].dat->elem_size;
  int dat9 = args[9].dat->elem_size;
  int dat10 = args[10].dat->elem_size;

  char *p_a[11];

  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif //OPS_MPI
  int base0 = dat0 * 1 * 
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif //OPS_MPI
  int base1 = dat1 * 1 * 
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - d_m[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif //OPS_MPI
  int base2 = dat2 * 1 * 
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - d_m[1]);
  p_a[2] = (char *)args[2].data_d + base2;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif //OPS_MPI
  int base3 = dat3 * 1 * 
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - d_m[1]);
  p_a[3] = (char *)args[3].data_d + base3;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d];
  #endif //OPS_MPI
  int base4 = dat4 * 1 * 
  (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - d_m[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - d_m[1]);
  p_a[4] = (char *)args[4].data_d + base4;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d];
  #endif //OPS_MPI
  int base5 = dat5 * 1 * 
  (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - d_m[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1] - args[5].dat->base[1] - d_m[1]);
  p_a[5] = (char *)args[5].data_d + base5;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d] + OPS_sub_dat_list[args[6].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d];
  #endif //OPS_MPI
  int base6 = dat6 * 1 * 
  (start[0] * args[6].stencil->stride[0] - args[6].dat->base[0] - d_m[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1] - args[6].dat->base[1] - d_m[1]);
  p_a[6] = (char *)args[6].data_d + base6;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[7].dat->d_m[d] + OPS_sub_dat_list[args[7].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[7].dat->d_m[d];
  #endif //OPS_MPI
  int base7 = dat7 * 1 * 
  (start[0] * args[7].stencil->stride[0] - args[7].dat->base[0] - d_m[0]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    (start[1] * args[7].stencil->stride[1] - args[7].dat->base[1] - d_m[1]);
  p_a[7] = (char *)args[7].data_d + base7;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[8].dat->d_m[d] + OPS_sub_dat_list[args[8].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[8].dat->d_m[d];
  #endif //OPS_MPI
  int base8 = dat8 * 1 * 
  (start[0] * args[8].stencil->stride[0] - args[8].dat->base[0] - d_m[0]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    (start[1] * args[8].stencil->stride[1] - args[8].dat->base[1] - d_m[1]);
  p_a[8] = (char *)args[8].data_d + base8;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[9].dat->d_m[d] + OPS_sub_dat_list[args[9].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[9].dat->d_m[d];
  #endif //OPS_MPI
  int base9 = dat9 * 1 * 
  (start[0] * args[9].stencil->stride[0] - args[9].dat->base[0] - d_m[0]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    (start[1] * args[9].stencil->stride[1] - args[9].dat->base[1] - d_m[1]);
  p_a[9] = (char *)args[9].data_d + base9;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[10].dat->d_m[d] + OPS_sub_dat_list[args[10].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[10].dat->d_m[d];
  #endif //OPS_MPI
  int base10 = dat10 * 1 * 
  (start[0] * args[10].stencil->stride[0] - args[10].dat->base[0] - d_m[0]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    (start[1] * args[10].stencil->stride[1] - args[10].dat->base[1] - d_m[1]);
  p_a[10] = (char *)args[10].data_d + base10;


  ops_H_D_exchanges_device(args, 11);
  ops_halo_exchanges(args,11,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[71].mpi_time += t1-t2;


  //call kernel wrapper function, passing in pointers to data
  ops_calc_dt_kernel<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)p_a[6], (double *)p_a[7],
           (double *)p_a[8], (double *)p_a[9],
           (double *)p_a[10],x_size, y_size);

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
  }
  ops_timers_core(&c2,&t2);
  OPS_kernels[71].time += t2-t1;
  ops_set_dirtybit_device(args, 11);
  ops_set_halo_dirtybit3(&args[10],range);

  //Update kernel record
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg6);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg7);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg8);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg9);
  OPS_kernels[71].transfer += ops_compute_transfer(dim, range, &arg10);
}
