//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_flux_calc_kernelx;
int xdim0_flux_calc_kernelx_h = -1;
extern int ydim0_flux_calc_kernelx;
int ydim0_flux_calc_kernelx_h = -1;
extern int xdim1_flux_calc_kernelx;
int xdim1_flux_calc_kernelx_h = -1;
extern int ydim1_flux_calc_kernelx;
int ydim1_flux_calc_kernelx_h = -1;
extern int xdim2_flux_calc_kernelx;
int xdim2_flux_calc_kernelx_h = -1;
extern int ydim2_flux_calc_kernelx;
int ydim2_flux_calc_kernelx_h = -1;
extern int xdim3_flux_calc_kernelx;
int xdim3_flux_calc_kernelx_h = -1;
extern int ydim3_flux_calc_kernelx;
int ydim3_flux_calc_kernelx_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void flux_calc_kernelx_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_flux_calc_kernelx(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[4] = { arg0, arg1, arg2, arg3};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 4, range, 42))
    return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(42, "flux_calc_kernelx");
    OPS_kernels[42].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute localy allocated range for the sub-block

  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<3; n++ ){
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
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);


  xdim0 = args[0].dat->size[0];
  ydim0 = args[0].dat->size[1];
  xdim1 = args[1].dat->size[0];
  ydim1 = args[1].dat->size[1];
  xdim2 = args[2].dat->size[0];
  ydim2 = args[2].dat->size[1];
  xdim3 = args[3].dat->size[0];
  ydim3 = args[3].dat->size[1];
  if (xdim0 != xdim0_flux_calc_kernelx_h || ydim0 != ydim0_flux_calc_kernelx_h || xdim1 != xdim1_flux_calc_kernelx_h || ydim1 != ydim1_flux_calc_kernelx_h || xdim2 != xdim2_flux_calc_kernelx_h || ydim2 != ydim2_flux_calc_kernelx_h || xdim3 != xdim3_flux_calc_kernelx_h || ydim3 != ydim3_flux_calc_kernelx_h) {
    xdim0_flux_calc_kernelx = xdim0;
    xdim0_flux_calc_kernelx_h = xdim0;
    ydim0_flux_calc_kernelx = ydim0;
    ydim0_flux_calc_kernelx_h = ydim0;
    xdim1_flux_calc_kernelx = xdim1;
    xdim1_flux_calc_kernelx_h = xdim1;
    ydim1_flux_calc_kernelx = ydim1;
    ydim1_flux_calc_kernelx_h = ydim1;
    xdim2_flux_calc_kernelx = xdim2;
    xdim2_flux_calc_kernelx_h = xdim2;
    ydim2_flux_calc_kernelx = ydim2;
    ydim2_flux_calc_kernelx_h = ydim2;
    xdim3_flux_calc_kernelx = xdim3;
    xdim3_flux_calc_kernelx_h = xdim3;
    ydim3_flux_calc_kernelx = ydim3;
    ydim3_flux_calc_kernelx_h = ydim3;
  }



  //set up initial pointers
  int base0 = args[0].dat->base_offset + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0 + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1 + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2 + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3 + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif


  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 4);
  #else
  ops_H_D_exchanges_host(args, 4);
  #endif
  ops_halo_exchanges(args,4,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 4);
  #else
  ops_H_D_exchanges_host(args, 4);
  #endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[42].mpi_time += t2 - t1;
  }

  flux_calc_kernelx_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    x_size, y_size, z_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[42].time += t1 - t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 4);
  #else
  ops_set_dirtybit_host(args, 4);
  #endif
  ops_set_halo_dirtybit3(&args[0],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[42].mpi_time += t2 - t1;
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
