//
// auto-generated by ops.py
//
__constant__ int xdim0_update_halo_kernel1_b1;
int xdim0_update_halo_kernel1_b1_h = -1;
__constant__ int xdim1_update_halo_kernel1_b1;
int xdim1_update_halo_kernel1_b1_h = -1;
__constant__ int xdim2_update_halo_kernel1_b1;
int xdim2_update_halo_kernel1_b1_h = -1;
__constant__ int xdim3_update_halo_kernel1_b1;
int xdim3_update_halo_kernel1_b1_h = -1;
__constant__ int xdim4_update_halo_kernel1_b1;
int xdim4_update_halo_kernel1_b1_h = -1;
__constant__ int xdim5_update_halo_kernel1_b1;
int xdim5_update_halo_kernel1_b1_h = -1;
__constant__ int xdim6_update_halo_kernel1_b1;
int xdim6_update_halo_kernel1_b1_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6


#define OPS_ACC0(x,y) (x+xdim0_update_halo_kernel1_b1*(y))
#define OPS_ACC1(x,y) (x+xdim1_update_halo_kernel1_b1*(y))
#define OPS_ACC2(x,y) (x+xdim2_update_halo_kernel1_b1*(y))
#define OPS_ACC3(x,y) (x+xdim3_update_halo_kernel1_b1*(y))
#define OPS_ACC4(x,y) (x+xdim4_update_halo_kernel1_b1*(y))
#define OPS_ACC5(x,y) (x+xdim5_update_halo_kernel1_b1*(y))
#define OPS_ACC6(x,y) (x+xdim6_update_halo_kernel1_b1*(y))

//user function
__device__

inline void update_halo_kernel1_b1_gpu(double *density0, double *density1,
                          double *energy0, double *energy1,
                          double *pressure, double *viscosity,
                          double *soundspeed , const int* fields) {

  if(fields[FIELD_DENSITY0] == 1) density0[OPS_ACC0(0,0)] = density0[OPS_ACC0(0,1)];
  if(fields[FIELD_DENSITY1] == 1) density1[OPS_ACC1(0,0)] = density1[OPS_ACC1(0,1)];
  if(fields[FIELD_ENERGY0] == 1) energy0[OPS_ACC2(0,0)] = energy0[OPS_ACC2(0,1)];
  if(fields[FIELD_ENERGY1] == 1) energy1[OPS_ACC3(0,0)] = energy1[OPS_ACC3(0,1)];
  if(fields[FIELD_PRESSURE] == 1) pressure[OPS_ACC4(0,0)] = pressure[OPS_ACC4(0,1)];
  if(fields[FIELD_VISCOSITY] == 1) viscosity[OPS_ACC5(0,0)] = viscosity[OPS_ACC5(0,1)];
  if(fields[FIELD_SOUNDSPEED] == 1) soundspeed[OPS_ACC6(0,0)] = soundspeed[OPS_ACC6(0,1)];

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6


__global__ void ops_update_halo_kernel1_b1(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
double* __restrict arg6,
const int* __restrict arg7,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * xdim0_update_halo_kernel1_b1;
  arg1 += idx_x * 1*1 + idx_y * 1*1 * xdim1_update_halo_kernel1_b1;
  arg2 += idx_x * 1*1 + idx_y * 1*1 * xdim2_update_halo_kernel1_b1;
  arg3 += idx_x * 1*1 + idx_y * 1*1 * xdim3_update_halo_kernel1_b1;
  arg4 += idx_x * 1*1 + idx_y * 1*1 * xdim4_update_halo_kernel1_b1;
  arg5 += idx_x * 1*1 + idx_y * 1*1 * xdim5_update_halo_kernel1_b1;
  arg6 += idx_x * 1*1 + idx_y * 1*1 * xdim6_update_halo_kernel1_b1;

  if (idx_x < size0 && idx_y < size1) {
    update_halo_kernel1_b1_gpu(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6, arg7);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_update_halo_kernel1_b1(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
#else
void ops_par_loop_update_halo_kernel1_b1_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,8,range,44)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(44,"update_halo_kernel1_b1");
    OPS_kernels[44].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #if OPS_MPI && !OPS_LAZY
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
  #else
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  int xdim6 = args[6].dat->size[0];

  if (xdim0 != xdim0_update_halo_kernel1_b1_h || xdim1 != xdim1_update_halo_kernel1_b1_h || xdim2 != xdim2_update_halo_kernel1_b1_h || xdim3 != xdim3_update_halo_kernel1_b1_h || xdim4 != xdim4_update_halo_kernel1_b1_h || xdim5 != xdim5_update_halo_kernel1_b1_h || xdim6 != xdim6_update_halo_kernel1_b1_h) {
    cudaMemcpyToSymbol( xdim0_update_halo_kernel1_b1, &xdim0, sizeof(int) );
    xdim0_update_halo_kernel1_b1_h = xdim0;
    cudaMemcpyToSymbol( xdim1_update_halo_kernel1_b1, &xdim1, sizeof(int) );
    xdim1_update_halo_kernel1_b1_h = xdim1;
    cudaMemcpyToSymbol( xdim2_update_halo_kernel1_b1, &xdim2, sizeof(int) );
    xdim2_update_halo_kernel1_b1_h = xdim2;
    cudaMemcpyToSymbol( xdim3_update_halo_kernel1_b1, &xdim3, sizeof(int) );
    xdim3_update_halo_kernel1_b1_h = xdim3;
    cudaMemcpyToSymbol( xdim4_update_halo_kernel1_b1, &xdim4, sizeof(int) );
    xdim4_update_halo_kernel1_b1_h = xdim4;
    cudaMemcpyToSymbol( xdim5_update_halo_kernel1_b1, &xdim5, sizeof(int) );
    xdim5_update_halo_kernel1_b1_h = xdim5;
    cudaMemcpyToSymbol( xdim6_update_halo_kernel1_b1, &xdim6, sizeof(int) );
    xdim6_update_halo_kernel1_b1_h = xdim6;
  }


  int *arg7h = (int *)arg7.data;

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,OPS_block_size_z);

  int consts_bytes = 0;

  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));

  reallocConstArrays(consts_bytes);

  consts_bytes = 0;
  arg7.data = OPS_consts_h + consts_bytes;
  arg7.data_d = OPS_consts_d + consts_bytes;
  for (int d=0; d<NUM_FIELDS; d++) ((int *)arg7.data)[d] = arg7h[d];
  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));
  mvConstArraysToDevice(consts_bytes);
  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int dat6 = (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);

  char *p_a[8];

  //set up initial pointers
  int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  p_a[2] = (char *)args[2].data_d + base2;

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

  int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1]);
  p_a[6] = (char *)args[6].data_d + base6;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 8);
  ops_halo_exchanges(args,8,range);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[44].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    ops_update_halo_kernel1_b1<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)p_a[6], (int *)arg7.data_d,x_size, y_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[44].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 8);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  ops_set_halo_dirtybit3(&args[6],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[44].mpi_time += t2-t1;
    OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_update_halo_kernel1_b1(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 44;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 44;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg*)malloc(8*sizeof(ops_arg));
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
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  char *tmp = (char*)malloc(NUM_FIELDS*sizeof(int));
  memcpy(tmp, arg7.data,NUM_FIELDS*sizeof(int));
  desc->args[7].data = tmp;
  desc->function = ops_par_loop_update_halo_kernel1_b1_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(44,"update_halo_kernel1_b1");
  }
  ops_enqueue_kernel(desc);
}
#endif
