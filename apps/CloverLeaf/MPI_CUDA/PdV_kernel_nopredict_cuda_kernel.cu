//
// auto-generated by ops.py on 2014-03-06 16:41
//

__constant__ int xdim0_PdV_kernel_nopredict;
__constant__ int xdim1_PdV_kernel_nopredict;
__constant__ int xdim2_PdV_kernel_nopredict;
__constant__ int xdim3_PdV_kernel_nopredict;
__constant__ int xdim4_PdV_kernel_nopredict;
__constant__ int xdim5_PdV_kernel_nopredict;
__constant__ int xdim6_PdV_kernel_nopredict;
__constant__ int xdim7_PdV_kernel_nopredict;
__constant__ int xdim8_PdV_kernel_nopredict;
__constant__ int xdim9_PdV_kernel_nopredict;
__constant__ int xdim10_PdV_kernel_nopredict;
__constant__ int xdim11_PdV_kernel_nopredict;
__constant__ int xdim12_PdV_kernel_nopredict;
__constant__ int xdim13_PdV_kernel_nopredict;

#define OPS_ACC0(x,y) (x+xdim0_PdV_kernel_nopredict*(y))
#define OPS_ACC1(x,y) (x+xdim1_PdV_kernel_nopredict*(y))
#define OPS_ACC2(x,y) (x+xdim2_PdV_kernel_nopredict*(y))
#define OPS_ACC3(x,y) (x+xdim3_PdV_kernel_nopredict*(y))
#define OPS_ACC4(x,y) (x+xdim4_PdV_kernel_nopredict*(y))
#define OPS_ACC5(x,y) (x+xdim5_PdV_kernel_nopredict*(y))
#define OPS_ACC6(x,y) (x+xdim6_PdV_kernel_nopredict*(y))
#define OPS_ACC7(x,y) (x+xdim7_PdV_kernel_nopredict*(y))
#define OPS_ACC8(x,y) (x+xdim8_PdV_kernel_nopredict*(y))
#define OPS_ACC9(x,y) (x+xdim9_PdV_kernel_nopredict*(y))
#define OPS_ACC10(x,y) (x+xdim10_PdV_kernel_nopredict*(y))
#define OPS_ACC11(x,y) (x+xdim11_PdV_kernel_nopredict*(y))
#define OPS_ACC12(x,y) (x+xdim12_PdV_kernel_nopredict*(y))
#define OPS_ACC13(x,y) (x+xdim13_PdV_kernel_nopredict*(y))

//user function
__device__

void PdV_kernel_nopredict(double *xarea, double *xvel0, double *xvel1,
                double *yarea, double *yvel0, double *yvel1,
                double *volume_change, double *volume,
                double *pressure,
                double *density0, double *density1,
                double *viscosity,
                double *energy0, double *energy1) {


  double recip_volume, energy_change, min_cell_volume;
  double right_flux, left_flux, top_flux, bottom_flux, total_flux;

  left_flux = ( xarea[OPS_ACC0(0,0)] * ( xvel0[OPS_ACC1(0,0)] + xvel0[OPS_ACC1(0,1)] +
                                xvel1[OPS_ACC2(0,0)] + xvel1[OPS_ACC2(0,1)] ) ) * 0.25 * dt;
  right_flux = ( xarea[OPS_ACC0(1,0)] * ( xvel0[OPS_ACC1(1,0)] + xvel0[OPS_ACC1(1,1)] +
                                 xvel1[OPS_ACC2(1,0)] + xvel1[OPS_ACC2(1,1)] ) ) * 0.25 * dt;

  bottom_flux = ( yarea[OPS_ACC3(0,0)] * ( yvel0[OPS_ACC4(0,0)] + yvel0[OPS_ACC4(1,0)] +
                                  yvel1[OPS_ACC5(0,0)] + yvel1[OPS_ACC5(1,0)] ) ) * 0.25* dt;
  top_flux = ( yarea[OPS_ACC3(0,1)] * ( yvel0[OPS_ACC4(0,1)] + yvel0[OPS_ACC4(1,1)] +
                               yvel1[OPS_ACC5(0,1)] + yvel1[OPS_ACC5(1,1)] ) ) * 0.25 * dt;

  total_flux = right_flux - left_flux + top_flux - bottom_flux;

  volume_change[OPS_ACC6(0,0)] = (volume[OPS_ACC7(0,0)])/(volume[OPS_ACC7(0,0)] + total_flux);

  min_cell_volume = MIN( volume[OPS_ACC7(0,0)] + right_flux - left_flux + top_flux - bottom_flux ,
                           MIN(volume[OPS_ACC7(0,0)] + right_flux - left_flux,
                           volume[OPS_ACC7(0,0)] + top_flux - bottom_flux) );

  recip_volume = 1.0/volume[OPS_ACC7(0,0)];

  energy_change = ( pressure[OPS_ACC8(0,0)]/density0[OPS_ACC9(0,0)] +
                    viscosity[OPS_ACC11(0,0)]/density0[OPS_ACC9(0,0)] ) * total_flux * recip_volume;
  energy1[OPS_ACC13(0,0)] = energy0[OPS_ACC12(0,0)] - energy_change;
  density1[OPS_ACC10(0,0)] = density0[OPS_ACC9(0,0)] * volume_change[OPS_ACC6(0,0)];

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
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13


__global__ void ops_PdV_kernel_nopredict(
const double* __restrict arg0,
const double* __restrict arg1,
const double* __restrict arg2,
const double* __restrict arg3,
const double* __restrict arg4,
const double* __restrict arg5,
double* __restrict arg6,
const double* __restrict arg7,
const double* __restrict arg8,
const double* __restrict arg9,
double* __restrict arg10,
const double* __restrict arg11,
const double* __restrict arg12,
double* __restrict arg13,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 1 * xdim0_PdV_kernel_nopredict;
  arg1 += idx_x * 1 + idx_y * 1 * xdim1_PdV_kernel_nopredict;
  arg2 += idx_x * 1 + idx_y * 1 * xdim2_PdV_kernel_nopredict;
  arg3 += idx_x * 1 + idx_y * 1 * xdim3_PdV_kernel_nopredict;
  arg4 += idx_x * 1 + idx_y * 1 * xdim4_PdV_kernel_nopredict;
  arg5 += idx_x * 1 + idx_y * 1 * xdim5_PdV_kernel_nopredict;
  arg6 += idx_x * 1 + idx_y * 1 * xdim6_PdV_kernel_nopredict;
  arg7 += idx_x * 1 + idx_y * 1 * xdim7_PdV_kernel_nopredict;
  arg8 += idx_x * 1 + idx_y * 1 * xdim8_PdV_kernel_nopredict;
  arg9 += idx_x * 1 + idx_y * 1 * xdim9_PdV_kernel_nopredict;
  arg10 += idx_x * 1 + idx_y * 1 * xdim10_PdV_kernel_nopredict;
  arg11 += idx_x * 1 + idx_y * 1 * xdim11_PdV_kernel_nopredict;
  arg12 += idx_x * 1 + idx_y * 1 * xdim12_PdV_kernel_nopredict;
  arg13 += idx_x * 1 + idx_y * 1 * xdim13_PdV_kernel_nopredict;

  if (idx_x < size0 && idx_y < size1) {
    PdV_kernel_nopredict(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6, arg7, arg8,
                   arg9, arg10, arg11, arg12, arg13);
  }

}

// host stub function
void ops_par_loop_PdV_kernel_nopredict(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8,
 ops_arg arg9, ops_arg arg10, ops_arg arg11, ops_arg arg12, ops_arg arg13) {

  ops_arg args[14] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start_add[ndim*14];
  int end_add[ndim*14];

  int s[ndim];
  int e[ndim];

  for ( int n=0; n<ndim; n++ ){
    s[n] = sb->istart[n];e[n] = sb->iend[n]+1;
    if (s[n] >= range[2*n]) {
      s[n] = 0;
    }
    else {
      s[n] = range[2*n] - s[n];
    }
    if (e[n] >= range[2*n+1]) {
      e[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      e[n] = sb->sizes[n];
    }
  }

  for ( int i=0; i<14; i++ ){
    for ( int n=0; n<ndim; n++ ){
      start_add[i*ndim+n] = s[n];
      end_add[i*ndim+n]   = e[n];
    }
  }


  int x_size = e[0]-s[0];
  int y_size = e[1]-s[1];

  int xdim0 = args[0].dat->block_size[0];
  int xdim1 = args[1].dat->block_size[0];
  int xdim2 = args[2].dat->block_size[0];
  int xdim3 = args[3].dat->block_size[0];
  int xdim4 = args[4].dat->block_size[0];
  int xdim5 = args[5].dat->block_size[0];
  int xdim6 = args[6].dat->block_size[0];
  int xdim7 = args[7].dat->block_size[0];
  int xdim8 = args[8].dat->block_size[0];
  int xdim9 = args[9].dat->block_size[0];
  int xdim10 = args[10].dat->block_size[0];
  int xdim11 = args[11].dat->block_size[0];
  int xdim12 = args[12].dat->block_size[0];
  int xdim13 = args[13].dat->block_size[0];


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(6,"PdV_kernel_nopredict");
  ops_timers_core(&c1,&t1);

  if (OPS_kernels[6].count == 0) {
    cudaMemcpyToSymbol( xdim0_PdV_kernel_nopredict, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_PdV_kernel_nopredict, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_PdV_kernel_nopredict, &xdim2, sizeof(int) );
    cudaMemcpyToSymbol( xdim3_PdV_kernel_nopredict, &xdim3, sizeof(int) );
    cudaMemcpyToSymbol( xdim4_PdV_kernel_nopredict, &xdim4, sizeof(int) );
    cudaMemcpyToSymbol( xdim5_PdV_kernel_nopredict, &xdim5, sizeof(int) );
    cudaMemcpyToSymbol( xdim6_PdV_kernel_nopredict, &xdim6, sizeof(int) );
    cudaMemcpyToSymbol( xdim7_PdV_kernel_nopredict, &xdim7, sizeof(int) );
    cudaMemcpyToSymbol( xdim8_PdV_kernel_nopredict, &xdim8, sizeof(int) );
    cudaMemcpyToSymbol( xdim9_PdV_kernel_nopredict, &xdim9, sizeof(int) );
    cudaMemcpyToSymbol( xdim10_PdV_kernel_nopredict, &xdim10, sizeof(int) );
    cudaMemcpyToSymbol( xdim11_PdV_kernel_nopredict, &xdim11, sizeof(int) );
    cudaMemcpyToSymbol( xdim12_PdV_kernel_nopredict, &xdim12, sizeof(int) );
    cudaMemcpyToSymbol( xdim13_PdV_kernel_nopredict, &xdim13, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;
  int dat2 = args[2].dat->size;
  int dat3 = args[3].dat->size;
  int dat4 = args[4].dat->size;
  int dat5 = args[5].dat->size;
  int dat6 = args[6].dat->size;
  int dat7 = args[7].dat->size;
  int dat8 = args[8].dat->size;
  int dat9 = args[9].dat->size;
  int dat10 = args[10].dat->size;
  int dat11 = args[11].dat->size;
  int dat12 = args[12].dat->size;
  int dat13 = args[13].dat->size;

  char *p_a[14];

  //set up initial pointers
  int base0 = dat0 * 1 * 
  (start_add[ndim+0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start_add[ndim+1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data + base0;

  //set up initial pointers
  int base1 = dat1 * 1 * 
  (start_add[ndim+0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start_add[ndim+1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data + base1;

  //set up initial pointers
  int base2 = dat2 * 1 * 
  (start_add[ndim+0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2  + dat2 * args[2].dat->block_size[0] * 
  (start_add[ndim+1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  p_a[2] = (char *)args[2].data + base2;

  //set up initial pointers
  int base3 = dat3 * 1 * 
  (start_add[ndim+0] * args[3].stencil->stride[0] - args[3].dat->offset[0]);
  base3 = base3  + dat3 * args[3].dat->block_size[0] * 
  (start_add[ndim+1] * args[3].stencil->stride[1] - args[3].dat->offset[1]);
  p_a[3] = (char *)args[3].data + base3;

  //set up initial pointers
  int base4 = dat4 * 1 * 
  (start_add[ndim+0] * args[4].stencil->stride[0] - args[4].dat->offset[0]);
  base4 = base4  + dat4 * args[4].dat->block_size[0] * 
  (start_add[ndim+1] * args[4].stencil->stride[1] - args[4].dat->offset[1]);
  p_a[4] = (char *)args[4].data + base4;

  //set up initial pointers
  int base5 = dat5 * 1 * 
  (start_add[ndim+0] * args[5].stencil->stride[0] - args[5].dat->offset[0]);
  base5 = base5  + dat5 * args[5].dat->block_size[0] * 
  (start_add[ndim+1] * args[5].stencil->stride[1] - args[5].dat->offset[1]);
  p_a[5] = (char *)args[5].data + base5;

  //set up initial pointers
  int base6 = dat6 * 1 * 
  (start_add[ndim+0] * args[6].stencil->stride[0] - args[6].dat->offset[0]);
  base6 = base6  + dat6 * args[6].dat->block_size[0] * 
  (start_add[ndim+1] * args[6].stencil->stride[1] - args[6].dat->offset[1]);
  p_a[6] = (char *)args[6].data + base6;

  //set up initial pointers
  int base7 = dat7 * 1 * 
  (start_add[ndim+0] * args[7].stencil->stride[0] - args[7].dat->offset[0]);
  base7 = base7  + dat7 * args[7].dat->block_size[0] * 
  (start_add[ndim+1] * args[7].stencil->stride[1] - args[7].dat->offset[1]);
  p_a[7] = (char *)args[7].data + base7;

  //set up initial pointers
  int base8 = dat8 * 1 * 
  (start_add[ndim+0] * args[8].stencil->stride[0] - args[8].dat->offset[0]);
  base8 = base8  + dat8 * args[8].dat->block_size[0] * 
  (start_add[ndim+1] * args[8].stencil->stride[1] - args[8].dat->offset[1]);
  p_a[8] = (char *)args[8].data + base8;

  //set up initial pointers
  int base9 = dat9 * 1 * 
  (start_add[ndim+0] * args[9].stencil->stride[0] - args[9].dat->offset[0]);
  base9 = base9  + dat9 * args[9].dat->block_size[0] * 
  (start_add[ndim+1] * args[9].stencil->stride[1] - args[9].dat->offset[1]);
  p_a[9] = (char *)args[9].data + base9;

  //set up initial pointers
  int base10 = dat10 * 1 * 
  (start_add[ndim+0] * args[10].stencil->stride[0] - args[10].dat->offset[0]);
  base10 = base10  + dat10 * args[10].dat->block_size[0] * 
  (start_add[ndim+1] * args[10].stencil->stride[1] - args[10].dat->offset[1]);
  p_a[10] = (char *)args[10].data + base10;

  //set up initial pointers
  int base11 = dat11 * 1 * 
  (start_add[ndim+0] * args[11].stencil->stride[0] - args[11].dat->offset[0]);
  base11 = base11  + dat11 * args[11].dat->block_size[0] * 
  (start_add[ndim+1] * args[11].stencil->stride[1] - args[11].dat->offset[1]);
  p_a[11] = (char *)args[11].data + base11;

  //set up initial pointers
  int base12 = dat12 * 1 * 
  (start_add[ndim+0] * args[12].stencil->stride[0] - args[12].dat->offset[0]);
  base12 = base12  + dat12 * args[12].dat->block_size[0] * 
  (start_add[ndim+1] * args[12].stencil->stride[1] - args[12].dat->offset[1]);
  p_a[12] = (char *)args[12].data + base12;

  //set up initial pointers
  int base13 = dat13 * 1 * 
  (start_add[ndim+0] * args[13].stencil->stride[0] - args[13].dat->offset[0]);
  base13 = base13  + dat13 * args[13].dat->block_size[0] * 
  (start_add[ndim+1] * args[13].stencil->stride[1] - args[13].dat->offset[1]);
  p_a[13] = (char *)args[13].data + base13;


  ops_H_D_exchanges_cuda(args, 14);


  //call kernel wrapper function, passing in pointers to data
  ops_PdV_kernel_nopredict<<<grid, block >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)p_a[6], (double *)p_a[7],
           (double *)p_a[8], (double *)p_a[9],
           (double *)p_a[10], (double *)p_a[11],
           (double *)p_a[12], (double *)p_a[13],x_size, y_size);

  if (OPS_diags>1) cudaDeviceSynchronize();
  ops_set_dirtybit_cuda(args, 14);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[6].count++;
  OPS_kernels[6].time += t2-t1;
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg6);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg7);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg8);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg9);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg10);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg11);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg12);
  OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg13);
}
