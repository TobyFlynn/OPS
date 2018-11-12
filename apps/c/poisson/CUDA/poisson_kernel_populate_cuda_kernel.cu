//
// auto-generated by ops.py
//
__constant__ int dims_poisson_kernel_populate [6][1];
static int dims_poisson_kernel_populate_h [6][1] = {0};

//user function
__device__

void poisson_kernel_populate_gpu(const int *dispx, const int *dispy, const int *idx, ACC<double> &u, ACC<double> &f, ACC<double> &ref) {
  double x = dx * (double)(idx[0]+dispx[0]);
  double y = dy * (double)(idx[1]+dispy[0]);

  u(0,0) = myfun(sin(M_PI*x),cos(2.0*M_PI*y))-1.0;
  f(0,0) = -5.0*M_PI*M_PI*sin(M_PI*x)*cos(2.0*M_PI*y);
  ref(0,0) = sin(M_PI*x)*cos(2.0*M_PI*y);

}



__global__ void ops_poisson_kernel_populate(
const int arg0,
const int arg1,
int arg_idx0, int arg_idx1,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  int arg_idx[2];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_poisson_kernel_populate[3][0];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_poisson_kernel_populate[4][0];
  arg5 += idx_x * 1*1 + idx_y * 1*1 * dims_poisson_kernel_populate[5][0];

  if (idx_x < size0 && idx_y < size1) {
    ACC<double> argp3(dims_poisson_kernel_populate[3][0], arg3);
    ACC<double> argp4(dims_poisson_kernel_populate[4][0], arg4);
    ACC<double> argp5(dims_poisson_kernel_populate[5][0], arg5);
    poisson_kernel_populate_gpu(&arg0,
                   &arg1,
                   arg_idx,
                   argp3,
                   argp4,
                   argp5);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_poisson_kernel_populate(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_poisson_kernel_populate_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  int *range = desc->range;
  #ifdef OPS_MPI
  ops_block block = desc->block;
  #endif
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,6,range,0)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(0,"poisson_kernel_populate");
    OPS_kernels[0].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  int arg_idx[2];
  #ifdef OPS_MPI
  #ifdef OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = sb->decomp_disp[n]+start[n];
  }
  #else
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif
  #else
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];

  if (xdim3 != dims_poisson_kernel_populate_h[3][0] || xdim4 != dims_poisson_kernel_populate_h[4][0] || xdim5 != dims_poisson_kernel_populate_h[5][0]) {
    dims_poisson_kernel_populate_h[3][0] = xdim3;
    dims_poisson_kernel_populate_h[4][0] = xdim4;
    dims_poisson_kernel_populate_h[5][0] = xdim5;
    cutilSafeCall(cudaMemcpyToSymbol( dims_poisson_kernel_populate, dims_poisson_kernel_populate_h, sizeof(dims_poisson_kernel_populate)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,OPS_block_size_z);



  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);

  char *p_a[6];

  //set up initial pointers
  int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  p_a[3] = (char *)args[3].data_d + base3;

  int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1]);
  p_a[4] = (char *)args[4].data_d + base4;

  int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1]);
  p_a[5] = (char *)args[5].data_d + base5;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 6);
  ops_halo_exchanges(args,6,range);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[0].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    ops_poisson_kernel_populate<<<grid, tblock >>> (  *(int *)arg0.data, *(int *)arg1.data,
         arg_idx[0], arg_idx[1], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],x_size, y_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[0].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 6);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[0].mpi_time += t2-t1;
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg5);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_poisson_kernel_populate(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 0;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 0;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)malloc(6*sizeof(ops_arg));
  desc->args[0] = arg0;
  char *tmp = (char*)malloc(1*sizeof(int));
  memcpy(tmp, arg0.data,1*sizeof(int));
  desc->args[0].data = tmp;
  desc->args[1] = arg1;
  tmp = (char*)malloc(1*sizeof(int));
  memcpy(tmp, arg1.data,1*sizeof(int));
  desc->args[1].data = tmp;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->function = ops_par_loop_poisson_kernel_populate_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(0,"poisson_kernel_populate");
  }
  ops_enqueue_kernel(desc);
}
#endif
