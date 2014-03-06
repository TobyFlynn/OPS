//
// auto-generated by ops.py on 2014-03-06 16:41
//

__constant__ int xdim0_generate_chunk_kernel;
__constant__ int xdim1_generate_chunk_kernel;
__constant__ int xdim2_generate_chunk_kernel;
__constant__ int xdim3_generate_chunk_kernel;
__constant__ int xdim4_generate_chunk_kernel;
__constant__ int xdim5_generate_chunk_kernel;
__constant__ int xdim6_generate_chunk_kernel;
__constant__ int xdim7_generate_chunk_kernel;

#define OPS_ACC0(x,y) (x+xdim0_generate_chunk_kernel*(y))
#define OPS_ACC1(x,y) (x+xdim1_generate_chunk_kernel*(y))
#define OPS_ACC2(x,y) (x+xdim2_generate_chunk_kernel*(y))
#define OPS_ACC3(x,y) (x+xdim3_generate_chunk_kernel*(y))
#define OPS_ACC4(x,y) (x+xdim4_generate_chunk_kernel*(y))
#define OPS_ACC5(x,y) (x+xdim5_generate_chunk_kernel*(y))
#define OPS_ACC6(x,y) (x+xdim6_generate_chunk_kernel*(y))
#define OPS_ACC7(x,y) (x+xdim7_generate_chunk_kernel*(y))

//user function
__device__

void generate_chunk_kernel( const double *vertexx, const double *vertexy,
                     double *energy0, double *density0,
                     double *xvel0,  double *yvel0,
                     const double *cellx, const double *celly) {

  double radius, x_cent, y_cent;


  energy0[OPS_ACC2(0,0)]= states[0]->energy;
  density0[OPS_ACC3(0,0)]= states[0]->density;
  xvel0[OPS_ACC4(0,0)]=states[0]->xvel;
  yvel0[OPS_ACC5(0,0)]=states[0]->yvel;

  for(int i = 1; i<number_of_states; i++) {

    x_cent=states[i]->xmin;
    y_cent=states[i]->ymin;

    if (states[i]->geometry == g_rect) {
      if(vertexx[OPS_ACC0(1,0)] >= states[i]->xmin  && vertexx[OPS_ACC0(0,0)] < states[i]->xmax) {
        if(vertexy[OPS_ACC1(0,1)] >= states[i]->ymin && vertexy[OPS_ACC1(0,0)] < states[i]->ymax) {

          energy0[OPS_ACC2(0,0)] = states[i]->energy;
          density0[OPS_ACC3(0,0)] = states[i]->density;

          xvel0[OPS_ACC4(0,0)] = states[i]->xvel;
          xvel0[OPS_ACC4(1,0)] = states[i]->xvel;
          xvel0[OPS_ACC4(0,1)] = states[i]->xvel;
          xvel0[OPS_ACC4(1,1)] = states[i]->xvel;

          yvel0[OPS_ACC5(0,0)] = states[i]->yvel;
          yvel0[OPS_ACC5(1,0)] = states[i]->yvel;
          yvel0[OPS_ACC5(0,1)] = states[i]->yvel;
          yvel0[OPS_ACC5(1,1)] = states[i]->yvel;
        }
      }

    }
    else if(states[i]->geometry == g_circ) {
      radius = sqrt ((cellx[OPS_ACC6(0,0)] - x_cent) * (cellx[OPS_ACC6(0,0)] - x_cent) +
                     (celly[OPS_ACC7(0,0)] - y_cent) * (celly[OPS_ACC7(0,0)] - y_cent));
      if(radius <= states[i]->radius) {
        energy0[OPS_ACC2(0,0)] = states[i]->energy;
        density0[OPS_ACC3(0,0)] = states[i]->density;

        xvel0[OPS_ACC4(0,0)] = states[i]->xvel;
        xvel0[OPS_ACC4(1,0)] = states[i]->xvel;
        xvel0[OPS_ACC4(0,1)] = states[i]->xvel;
        xvel0[OPS_ACC4(1,1)] = states[i]->xvel;

        yvel0[OPS_ACC5(0,0)] = states[i]->yvel;
        yvel0[OPS_ACC5(1,0)] = states[i]->yvel;
        yvel0[OPS_ACC5(0,1)] = states[i]->yvel;
        yvel0[OPS_ACC5(1,1)] = states[i]->yvel;
      }
    }
    else if(states[i]->geometry == g_point) {
      if(vertexx[OPS_ACC0(0,0)] == x_cent && vertexy[OPS_ACC1(0,0)] == y_cent) {
        energy0[OPS_ACC2(0,0)] = states[i]->energy;
        density0[OPS_ACC3(0,0)] = states[i]->density;

        xvel0[OPS_ACC4(0,0)] = states[i]->xvel;
        xvel0[OPS_ACC4(1,0)] = states[i]->xvel;
        xvel0[OPS_ACC4(0,1)] = states[i]->xvel;
        xvel0[OPS_ACC4(1,1)] = states[i]->xvel;

        yvel0[OPS_ACC5(0,0)] = states[i]->yvel;
        yvel0[OPS_ACC5(1,0)] = states[i]->yvel;
        yvel0[OPS_ACC5(0,1)] = states[i]->yvel;
        yvel0[OPS_ACC5(1,1)] = states[i]->yvel;
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
#undef OPS_ACC7


__global__ void ops_generate_chunk_kernel(
const double* __restrict arg0,
const double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
const double* __restrict arg6,
const double* __restrict arg7,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 0 * xdim0_generate_chunk_kernel;
  arg1 += idx_x * 0 + idx_y * 1 * xdim1_generate_chunk_kernel;
  arg2 += idx_x * 1 + idx_y * 1 * xdim2_generate_chunk_kernel;
  arg3 += idx_x * 1 + idx_y * 1 * xdim3_generate_chunk_kernel;
  arg4 += idx_x * 1 + idx_y * 1 * xdim4_generate_chunk_kernel;
  arg5 += idx_x * 1 + idx_y * 1 * xdim5_generate_chunk_kernel;
  arg6 += idx_x * 1 + idx_y * 0 * xdim6_generate_chunk_kernel;
  arg7 += idx_x * 0 + idx_y * 1 * xdim7_generate_chunk_kernel;

  if (idx_x < size0 && idx_y < size1) {
    generate_chunk_kernel(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6, arg7);
  }

}

// host stub function
void ops_par_loop_generate_chunk_kernel(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start_add[ndim*8];
  int end_add[ndim*8];

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

  for ( int i=0; i<8; i++ ){
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


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(81,"generate_chunk_kernel");
  ops_timers_core(&c1,&t1);

  if (OPS_kernels[81].count == 0) {
    cudaMemcpyToSymbol( xdim0_generate_chunk_kernel, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_generate_chunk_kernel, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_generate_chunk_kernel, &xdim2, sizeof(int) );
    cudaMemcpyToSymbol( xdim3_generate_chunk_kernel, &xdim3, sizeof(int) );
    cudaMemcpyToSymbol( xdim4_generate_chunk_kernel, &xdim4, sizeof(int) );
    cudaMemcpyToSymbol( xdim5_generate_chunk_kernel, &xdim5, sizeof(int) );
    cudaMemcpyToSymbol( xdim6_generate_chunk_kernel, &xdim6, sizeof(int) );
    cudaMemcpyToSymbol( xdim7_generate_chunk_kernel, &xdim7, sizeof(int) );
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

  char *p_a[8];

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


  ops_H_D_exchanges_cuda(args, 8);


  //call kernel wrapper function, passing in pointers to data
  ops_generate_chunk_kernel<<<grid, block >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)p_a[6], (double *)p_a[7],x_size, y_size);

  if (OPS_diags>1) cudaDeviceSynchronize();
  ops_set_dirtybit_cuda(args, 8);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[81].count++;
  OPS_kernels[81].time += t2-t1;
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg6);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg7);
}
