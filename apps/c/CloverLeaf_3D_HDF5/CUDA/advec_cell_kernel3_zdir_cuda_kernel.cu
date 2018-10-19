//
// auto-generated by ops.py
//
__constant__ int dims_advec_cell_kernel3_zdir [8][2];
static int dims_advec_cell_kernel3_zdir_h [8][2] = {0};

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7


#define OPS_ACC0(x,y,z) (x+dims_advec_cell_kernel3_zdir[0][0]*(y)+dims_advec_cell_kernel3_zdir[0][0]*dims_advec_cell_kernel3_zdir[0][1]*(z))
#define OPS_ACC1(x,y,z) (x+dims_advec_cell_kernel3_zdir[1][0]*(y)+dims_advec_cell_kernel3_zdir[1][0]*dims_advec_cell_kernel3_zdir[1][1]*(z))
#define OPS_ACC2(x,y,z) (x+dims_advec_cell_kernel3_zdir[2][0]*(y)+dims_advec_cell_kernel3_zdir[2][0]*dims_advec_cell_kernel3_zdir[2][1]*(z))
#define OPS_ACC3(x,y,z) (x+dims_advec_cell_kernel3_zdir[3][0]*(y)+dims_advec_cell_kernel3_zdir[3][0]*dims_advec_cell_kernel3_zdir[3][1]*(z))
#define OPS_ACC4(x,y,z) (x+dims_advec_cell_kernel3_zdir[4][0]*(y)+dims_advec_cell_kernel3_zdir[4][0]*dims_advec_cell_kernel3_zdir[4][1]*(z))
#define OPS_ACC5(x,y,z) (x+dims_advec_cell_kernel3_zdir[5][0]*(y)+dims_advec_cell_kernel3_zdir[5][0]*dims_advec_cell_kernel3_zdir[5][1]*(z))
#define OPS_ACC6(x,y,z) (x+dims_advec_cell_kernel3_zdir[6][0]*(y)+dims_advec_cell_kernel3_zdir[6][0]*dims_advec_cell_kernel3_zdir[6][1]*(z))
#define OPS_ACC7(x,y,z) (x+dims_advec_cell_kernel3_zdir[7][0]*(y)+dims_advec_cell_kernel3_zdir[7][0]*dims_advec_cell_kernel3_zdir[7][1]*(z))

//user function
__device__

inline void advec_cell_kernel3_zdir_gpu( const double *vol_flux_z, const double *pre_vol, const int *zz,
                              const double *vertexdz,
                              const double *density1, const double *energy1 ,
                              double *mass_flux_z, double *ener_flux) {

  double sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int z_max=field.z_max;

  int upwind,donor,downwind,dif;

  if(vol_flux_z[OPS_ACC0(0,0,0)] > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (zz[OPS_ACC2(0,0,1)] < z_max+2-2) {
    upwind   = 1;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  } else {
    upwind   = 0;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  }

  sigmat = fabs(vol_flux_z[OPS_ACC0(0,0,0)])/pre_vol[OPS_ACC1(0,0,donor)];
  sigma3 = (1.0 + sigmat)*(vertexdz[OPS_ACC3(0,0,0)]/vertexdz[OPS_ACC3(0,0,dif)]);
  sigma4 = 2.0 - sigmat;

  sigmav = sigmat;

  diffuw = density1[OPS_ACC4(0,0,donor)] - density1[OPS_ACC4(0,0,upwind)];
  diffdw = density1[OPS_ACC4(0,0,downwind)] - density1[OPS_ACC4(0,0,donor)];

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  mass_flux_z[OPS_ACC6(0,0,0)] = vol_flux_z[OPS_ACC0(0,0,0)] * ( density1[OPS_ACC4(0,0,donor)] + limiter );

  sigmam = fabs(mass_flux_z[OPS_ACC6(0,0,0)])/( density1[OPS_ACC4(0,0,donor)] * pre_vol[OPS_ACC1(0,0,donor)]);
  diffuw = energy1[OPS_ACC5(0,0,donor)] - energy1[OPS_ACC5(0,0,upwind)];
  diffdw = energy1[OPS_ACC5(0,0,downwind)] - energy1[OPS_ACC5(0,0,donor)];

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  ener_flux[OPS_ACC7(0,0,0)] = mass_flux_z[OPS_ACC6(0,0,0)] * ( energy1[OPS_ACC5(0,0,donor)] + limiter );
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7


__global__ void ops_advec_cell_kernel3_zdir(
const double* __restrict arg0,
const double* __restrict arg1,
const int* __restrict arg2,
const double* __restrict arg3,
const double* __restrict arg4,
const double* __restrict arg5,
double* __restrict arg6,
double* __restrict arg7,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel3_zdir[0][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[0][0] * dims_advec_cell_kernel3_zdir[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel3_zdir[1][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[1][0] * dims_advec_cell_kernel3_zdir[1][1];
  arg2 += idx_x * 0*1 + idx_y * 0*1 * dims_advec_cell_kernel3_zdir[2][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[2][0] * dims_advec_cell_kernel3_zdir[2][1];
  arg3 += idx_x * 0*1 + idx_y * 0*1 * dims_advec_cell_kernel3_zdir[3][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[3][0] * dims_advec_cell_kernel3_zdir[3][1];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel3_zdir[4][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[4][0] * dims_advec_cell_kernel3_zdir[4][1];
  arg5 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel3_zdir[5][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[5][0] * dims_advec_cell_kernel3_zdir[5][1];
  arg6 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel3_zdir[6][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[6][0] * dims_advec_cell_kernel3_zdir[6][1];
  arg7 += idx_x * 1*1 + idx_y * 1*1 * dims_advec_cell_kernel3_zdir[7][0] + idx_z * 1*1 * dims_advec_cell_kernel3_zdir[7][0] * dims_advec_cell_kernel3_zdir[7][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    advec_cell_kernel3_zdir_gpu(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6, arg7);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_advec_cell_kernel3_zdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
#else
void ops_par_loop_advec_cell_kernel3_zdir_execute(ops_kernel_descriptor *desc) {
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
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,8,range,118)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(118,"advec_cell_kernel3_zdir");
    OPS_kernels[118].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #ifdef OPS_MPI
  #ifdef OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = sb->decomp_disp[n]+start[n];
  }
  #else
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #endif
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
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
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  int xdim7 = args[7].dat->size[0];
  int ydim7 = args[7].dat->size[1];

  if (xdim0 != dims_advec_cell_kernel3_zdir_h[0][0] || ydim0 != dims_advec_cell_kernel3_zdir_h[0][1] || xdim1 != dims_advec_cell_kernel3_zdir_h[1][0] || ydim1 != dims_advec_cell_kernel3_zdir_h[1][1] || xdim2 != dims_advec_cell_kernel3_zdir_h[2][0] || ydim2 != dims_advec_cell_kernel3_zdir_h[2][1] || xdim3 != dims_advec_cell_kernel3_zdir_h[3][0] || ydim3 != dims_advec_cell_kernel3_zdir_h[3][1] || xdim4 != dims_advec_cell_kernel3_zdir_h[4][0] || ydim4 != dims_advec_cell_kernel3_zdir_h[4][1] || xdim5 != dims_advec_cell_kernel3_zdir_h[5][0] || ydim5 != dims_advec_cell_kernel3_zdir_h[5][1] || xdim6 != dims_advec_cell_kernel3_zdir_h[6][0] || ydim6 != dims_advec_cell_kernel3_zdir_h[6][1] || xdim7 != dims_advec_cell_kernel3_zdir_h[7][0] || ydim7 != dims_advec_cell_kernel3_zdir_h[7][1]) {
    dims_advec_cell_kernel3_zdir_h[0][0] = xdim0;
    dims_advec_cell_kernel3_zdir_h[0][1] = ydim0;
    dims_advec_cell_kernel3_zdir_h[1][0] = xdim1;
    dims_advec_cell_kernel3_zdir_h[1][1] = ydim1;
    dims_advec_cell_kernel3_zdir_h[2][0] = xdim2;
    dims_advec_cell_kernel3_zdir_h[2][1] = ydim2;
    dims_advec_cell_kernel3_zdir_h[3][0] = xdim3;
    dims_advec_cell_kernel3_zdir_h[3][1] = ydim3;
    dims_advec_cell_kernel3_zdir_h[4][0] = xdim4;
    dims_advec_cell_kernel3_zdir_h[4][1] = ydim4;
    dims_advec_cell_kernel3_zdir_h[5][0] = xdim5;
    dims_advec_cell_kernel3_zdir_h[5][1] = ydim5;
    dims_advec_cell_kernel3_zdir_h[6][0] = xdim6;
    dims_advec_cell_kernel3_zdir_h[6][1] = ydim6;
    dims_advec_cell_kernel3_zdir_h[7][0] = xdim7;
    dims_advec_cell_kernel3_zdir_h[7][1] = ydim7;
    cutilSafeCall(cudaMemcpyToSymbol( dims_advec_cell_kernel3_zdir, dims_advec_cell_kernel3_zdir_h, sizeof(dims_advec_cell_kernel3_zdir)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, (z_size-1)/OPS_block_size_z +1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,OPS_block_size_z);



  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int dat6 = (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  int dat7 = (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);

  char *p_a[8];

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

  int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2]);
  p_a[5] = (char *)args[5].data_d + base5;

  int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2]);
  p_a[6] = (char *)args[6].data_d + base6;

  int base7 = args[7].dat->base_offset + 
           dat7 * 1 * (start[0] * args[7].stencil->stride[0]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    (start[1] * args[7].stencil->stride[1]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    (start[2] * args[7].stencil->stride[2]);
  p_a[7] = (char *)args[7].data_d + base7;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 8);
  ops_halo_exchanges(args,8,range);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[118].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_advec_cell_kernel3_zdir<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
         (int *)p_a[2], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6], (double *)p_a[7],x_size, y_size, z_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[118].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 8);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[118].mpi_time += t2-t1;
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[118].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_advec_cell_kernel3_zdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 118;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 118;
  for ( int i=0; i<6; i++ ){
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
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->function = ops_par_loop_advec_cell_kernel3_zdir_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(118,"advec_cell_kernel3_zdir");
  }
  ops_enqueue_kernel(desc);
}
#endif
