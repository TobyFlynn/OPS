//
// auto-generated by ops.py
//
__constant__ int dims_advec_cell_kernel2_ydir [5][2];
static int dims_advec_cell_kernel2_ydir_h [5][2] = {0};

//user function
__device__

inline void advec_cell_kernel2_ydir_gpu(ACC<double> &pre_vol,
  ACC<double> &post_vol,
  const ACC<double> &volume,
  const ACC<double> &vol_flux_y,
  const ACC<double> &vol_flux_x) {

  pre_vol(0,0,0) = volume(0,0,0) + vol_flux_y(0,1,0) - vol_flux_y(0,0,0)
                                                     + vol_flux_x(1,0,0) - vol_flux_x(0,0,0);
  post_vol(0,0,0)= pre_vol(0,0,0)-(vol_flux_y(0,1,0) - vol_flux_y(0,0,0));

}



__global__ void ops_advec_cell_kernel2_ydir(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel2_ydir[0][0] + idx_z * 1*1 * dims_advec_cell_kernel2_ydir[0][0] * dims_advec_cell_kernel2_ydir[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel2_ydir[1][0] + idx_z * 1*1 * dims_advec_cell_kernel2_ydir[1][0] * dims_advec_cell_kernel2_ydir[1][1];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel2_ydir[2][0] + idx_z * 1*1 * dims_advec_cell_kernel2_ydir[2][0] * dims_advec_cell_kernel2_ydir[2][1];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel2_ydir[3][0] + idx_z * 1*1 * dims_advec_cell_kernel2_ydir[3][0] * dims_advec_cell_kernel2_ydir[3][1];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel2_ydir[4][0] + idx_z * 1*1 * dims_advec_cell_kernel2_ydir[4][0] * dims_advec_cell_kernel2_ydir[4][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ACC<double> argp0(dims_advec_cell_kernel2_ydir[0][0], dims_advec_cell_kernel2_ydir[0][1], arg0);
    ACC<double> argp1(dims_advec_cell_kernel2_ydir[1][0], dims_advec_cell_kernel2_ydir[1][1], arg1);
    const ACC<double> argp2(dims_advec_cell_kernel2_ydir[2][0], dims_advec_cell_kernel2_ydir[2][1], arg2);
    const ACC<double> argp3(dims_advec_cell_kernel2_ydir[3][0], dims_advec_cell_kernel2_ydir[3][1], arg3);
    const ACC<double> argp4(dims_advec_cell_kernel2_ydir[4][0], dims_advec_cell_kernel2_ydir[4][1], arg4);
    advec_cell_kernel2_ydir_gpu(argp0, argp1, argp2, argp3,
                   argp4);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_advec_cell_kernel2_ydir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
#else
void ops_par_loop_advec_cell_kernel2_ydir_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,5,range,114)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,114,"advec_cell_kernel2_ydir");
    block->instance->OPS_kernels[114].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
  #endif

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];

  if (xdim0 != dims_advec_cell_kernel2_ydir_h[0][0] || ydim0 != dims_advec_cell_kernel2_ydir_h[0][1] || xdim1 != dims_advec_cell_kernel2_ydir_h[1][0] || ydim1 != dims_advec_cell_kernel2_ydir_h[1][1] || xdim2 != dims_advec_cell_kernel2_ydir_h[2][0] || ydim2 != dims_advec_cell_kernel2_ydir_h[2][1] || xdim3 != dims_advec_cell_kernel2_ydir_h[3][0] || ydim3 != dims_advec_cell_kernel2_ydir_h[3][1] || xdim4 != dims_advec_cell_kernel2_ydir_h[4][0] || ydim4 != dims_advec_cell_kernel2_ydir_h[4][1]) {
    dims_advec_cell_kernel2_ydir_h[0][0] = xdim0;
    dims_advec_cell_kernel2_ydir_h[0][1] = ydim0;
    dims_advec_cell_kernel2_ydir_h[1][0] = xdim1;
    dims_advec_cell_kernel2_ydir_h[1][1] = ydim1;
    dims_advec_cell_kernel2_ydir_h[2][0] = xdim2;
    dims_advec_cell_kernel2_ydir_h[2][1] = ydim2;
    dims_advec_cell_kernel2_ydir_h[3][0] = xdim3;
    dims_advec_cell_kernel2_ydir_h[3][1] = ydim3;
    dims_advec_cell_kernel2_ydir_h[4][0] = xdim4;
    dims_advec_cell_kernel2_ydir_h[4][1] = ydim4;
    cutilSafeCall(block->instance->ostream(), cudaMemcpyToSymbol( dims_advec_cell_kernel2_ydir, dims_advec_cell_kernel2_ydir_h, sizeof(dims_advec_cell_kernel2_ydir)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, (y_size-1)/block->instance->OPS_block_size_y + 1, (z_size-1)/block->instance->OPS_block_size_z +1);
  dim3 tblock(block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z);



  int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);

  char *p_a[5];

  //set up initial pointers
  int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2]);
  p_a[3] = (char *)args[3].data_d + base3;

  int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2]);
  p_a[4] = (char *)args[4].data_d + base4;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 5);
  ops_halo_exchanges(args,5,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[114].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_advec_cell_kernel2_ydir<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         (double *)p_a[4],x_size, y_size, z_size);

  cutilSafeCall(block->instance->ostream(), cudaGetLastError());

  if (block->instance->OPS_diags>1) {
    cutilSafeCall(block->instance->ostream(), cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[114].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 5);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[114].mpi_time += t2-t1;
    block->instance->OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_advec_cell_kernel2_ydir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 114;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 114;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 5;
  desc->args = (ops_arg*)malloc(5*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->function = ops_par_loop_advec_cell_kernel2_ydir_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,114,"advec_cell_kernel2_ydir");
  }
  ops_enqueue_kernel(desc);
}
#endif
