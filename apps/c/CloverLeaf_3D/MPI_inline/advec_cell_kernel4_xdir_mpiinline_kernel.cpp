//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

extern int xdim0_advec_cell_kernel4_xdir;
int xdim0_advec_cell_kernel4_xdir_h = -1;
extern int ydim0_advec_cell_kernel4_xdir;
int ydim0_advec_cell_kernel4_xdir_h = -1;
extern int xdim1_advec_cell_kernel4_xdir;
int xdim1_advec_cell_kernel4_xdir_h = -1;
extern int ydim1_advec_cell_kernel4_xdir;
int ydim1_advec_cell_kernel4_xdir_h = -1;
extern int xdim2_advec_cell_kernel4_xdir;
int xdim2_advec_cell_kernel4_xdir_h = -1;
extern int ydim2_advec_cell_kernel4_xdir;
int ydim2_advec_cell_kernel4_xdir_h = -1;
extern int xdim3_advec_cell_kernel4_xdir;
int xdim3_advec_cell_kernel4_xdir_h = -1;
extern int ydim3_advec_cell_kernel4_xdir;
int ydim3_advec_cell_kernel4_xdir_h = -1;
extern int xdim4_advec_cell_kernel4_xdir;
int xdim4_advec_cell_kernel4_xdir_h = -1;
extern int ydim4_advec_cell_kernel4_xdir;
int ydim4_advec_cell_kernel4_xdir_h = -1;
extern int xdim5_advec_cell_kernel4_xdir;
int xdim5_advec_cell_kernel4_xdir_h = -1;
extern int ydim5_advec_cell_kernel4_xdir;
int ydim5_advec_cell_kernel4_xdir_h = -1;
extern int xdim6_advec_cell_kernel4_xdir;
int xdim6_advec_cell_kernel4_xdir_h = -1;
extern int ydim6_advec_cell_kernel4_xdir;
int ydim6_advec_cell_kernel4_xdir_h = -1;
extern int xdim7_advec_cell_kernel4_xdir;
int xdim7_advec_cell_kernel4_xdir_h = -1;
extern int ydim7_advec_cell_kernel4_xdir;
int ydim7_advec_cell_kernel4_xdir_h = -1;
extern int xdim8_advec_cell_kernel4_xdir;
int xdim8_advec_cell_kernel4_xdir_h = -1;
extern int ydim8_advec_cell_kernel4_xdir;
int ydim8_advec_cell_kernel4_xdir_h = -1;
extern int xdim9_advec_cell_kernel4_xdir;
int xdim9_advec_cell_kernel4_xdir_h = -1;
extern int ydim9_advec_cell_kernel4_xdir;
int ydim9_advec_cell_kernel4_xdir_h = -1;
extern int xdim10_advec_cell_kernel4_xdir;
int xdim10_advec_cell_kernel4_xdir_h = -1;
extern int ydim10_advec_cell_kernel4_xdir;
int ydim10_advec_cell_kernel4_xdir_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void advec_cell_kernel4_xdir_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_advec_cell_kernel4_xdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10) {

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,11,range,112)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(112, "advec_cell_kernel4_xdir");
    OPS_kernels[112].count++;
  }

  //compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];

  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (compute_ranges(args, 11, block, range, start, end, arg_idx) < 0)
    return;
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
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
  xdim4 = args[4].dat->size[0];
  ydim4 = args[4].dat->size[1];
  xdim5 = args[5].dat->size[0];
  ydim5 = args[5].dat->size[1];
  xdim6 = args[6].dat->size[0];
  ydim6 = args[6].dat->size[1];
  xdim7 = args[7].dat->size[0];
  ydim7 = args[7].dat->size[1];
  xdim8 = args[8].dat->size[0];
  ydim8 = args[8].dat->size[1];
  xdim9 = args[9].dat->size[0];
  ydim9 = args[9].dat->size[1];
  xdim10 = args[10].dat->size[0];
  ydim10 = args[10].dat->size[1];

  //Timing
  double t1,t2,c1,c2;
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
  }

  if (xdim0 != xdim0_advec_cell_kernel4_xdir_h || ydim0 != ydim0_advec_cell_kernel4_xdir_h || xdim1 != xdim1_advec_cell_kernel4_xdir_h || ydim1 != ydim1_advec_cell_kernel4_xdir_h || xdim2 != xdim2_advec_cell_kernel4_xdir_h || ydim2 != ydim2_advec_cell_kernel4_xdir_h || xdim3 != xdim3_advec_cell_kernel4_xdir_h || ydim3 != ydim3_advec_cell_kernel4_xdir_h || xdim4 != xdim4_advec_cell_kernel4_xdir_h || ydim4 != ydim4_advec_cell_kernel4_xdir_h || xdim5 != xdim5_advec_cell_kernel4_xdir_h || ydim5 != ydim5_advec_cell_kernel4_xdir_h || xdim6 != xdim6_advec_cell_kernel4_xdir_h || ydim6 != ydim6_advec_cell_kernel4_xdir_h || xdim7 != xdim7_advec_cell_kernel4_xdir_h || ydim7 != ydim7_advec_cell_kernel4_xdir_h || xdim8 != xdim8_advec_cell_kernel4_xdir_h || ydim8 != ydim8_advec_cell_kernel4_xdir_h || xdim9 != xdim9_advec_cell_kernel4_xdir_h || ydim9 != ydim9_advec_cell_kernel4_xdir_h || xdim10 != xdim10_advec_cell_kernel4_xdir_h || ydim10 != ydim10_advec_cell_kernel4_xdir_h) {
    xdim0_advec_cell_kernel4_xdir = xdim0;
    xdim0_advec_cell_kernel4_xdir_h = xdim0;
    ydim0_advec_cell_kernel4_xdir = ydim0;
    ydim0_advec_cell_kernel4_xdir_h = ydim0;
    xdim1_advec_cell_kernel4_xdir = xdim1;
    xdim1_advec_cell_kernel4_xdir_h = xdim1;
    ydim1_advec_cell_kernel4_xdir = ydim1;
    ydim1_advec_cell_kernel4_xdir_h = ydim1;
    xdim2_advec_cell_kernel4_xdir = xdim2;
    xdim2_advec_cell_kernel4_xdir_h = xdim2;
    ydim2_advec_cell_kernel4_xdir = ydim2;
    ydim2_advec_cell_kernel4_xdir_h = ydim2;
    xdim3_advec_cell_kernel4_xdir = xdim3;
    xdim3_advec_cell_kernel4_xdir_h = xdim3;
    ydim3_advec_cell_kernel4_xdir = ydim3;
    ydim3_advec_cell_kernel4_xdir_h = ydim3;
    xdim4_advec_cell_kernel4_xdir = xdim4;
    xdim4_advec_cell_kernel4_xdir_h = xdim4;
    ydim4_advec_cell_kernel4_xdir = ydim4;
    ydim4_advec_cell_kernel4_xdir_h = ydim4;
    xdim5_advec_cell_kernel4_xdir = xdim5;
    xdim5_advec_cell_kernel4_xdir_h = xdim5;
    ydim5_advec_cell_kernel4_xdir = ydim5;
    ydim5_advec_cell_kernel4_xdir_h = ydim5;
    xdim6_advec_cell_kernel4_xdir = xdim6;
    xdim6_advec_cell_kernel4_xdir_h = xdim6;
    ydim6_advec_cell_kernel4_xdir = ydim6;
    ydim6_advec_cell_kernel4_xdir_h = ydim6;
    xdim7_advec_cell_kernel4_xdir = xdim7;
    xdim7_advec_cell_kernel4_xdir_h = xdim7;
    ydim7_advec_cell_kernel4_xdir = ydim7;
    ydim7_advec_cell_kernel4_xdir_h = ydim7;
    xdim8_advec_cell_kernel4_xdir = xdim8;
    xdim8_advec_cell_kernel4_xdir_h = xdim8;
    ydim8_advec_cell_kernel4_xdir = ydim8;
    ydim8_advec_cell_kernel4_xdir_h = ydim8;
    xdim9_advec_cell_kernel4_xdir = xdim9;
    xdim9_advec_cell_kernel4_xdir_h = xdim9;
    ydim9_advec_cell_kernel4_xdir = ydim9;
    ydim9_advec_cell_kernel4_xdir_h = ydim9;
    xdim10_advec_cell_kernel4_xdir = xdim10;
    xdim10_advec_cell_kernel4_xdir_h = xdim10;
    ydim10_advec_cell_kernel4_xdir = ydim10;
    ydim10_advec_cell_kernel4_xdir_h = ydim10;
  }

  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int dat6 = (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  int dat7 = (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);
  int dat8 = (OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size);
  int dat9 = (OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size);
  int dat10 = (OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size);

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset +
              (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
                  start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
              args[0].dat->size[0] * start[1] * args[0].stencil->stride[1];
  base0 = base0 +
          (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
              args[0].dat->size[0] * args[0].dat->size[1] * start[2] *
              args[0].stencil->stride[2];
  double *p_a0 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset +
              (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
                  start[0] * args[1].stencil->stride[0];
  base1 = base1 +
          (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
              args[1].dat->size[0] * start[1] * args[1].stencil->stride[1];
  base1 = base1 +
          (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
              args[1].dat->size[0] * args[1].dat->size[1] * start[2] *
              args[1].stencil->stride[2];
  double *p_a1 = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset +
              (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
                  start[0] * args[2].stencil->stride[0];
  base2 = base2 +
          (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
              args[2].dat->size[0] * start[1] * args[2].stencil->stride[1];
  base2 = base2 +
          (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
              args[2].dat->size[0] * args[2].dat->size[1] * start[2] *
              args[2].stencil->stride[2];
  double *p_a2 = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset +
              (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
                  start[0] * args[3].stencil->stride[0];
  base3 = base3 +
          (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
              args[3].dat->size[0] * start[1] * args[3].stencil->stride[1];
  base3 = base3 +
          (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
              args[3].dat->size[0] * args[3].dat->size[1] * start[2] *
              args[3].stencil->stride[2];
  double *p_a3 = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset +
              (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
                  start[0] * args[4].stencil->stride[0];
  base4 = base4 +
          (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
              args[4].dat->size[0] * start[1] * args[4].stencil->stride[1];
  base4 = base4 +
          (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
              args[4].dat->size[0] * args[4].dat->size[1] * start[2] *
              args[4].stencil->stride[2];
  double *p_a4 = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset +
              (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
                  start[0] * args[5].stencil->stride[0];
  base5 = base5 +
          (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
              args[5].dat->size[0] * start[1] * args[5].stencil->stride[1];
  base5 = base5 +
          (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
              args[5].dat->size[0] * args[5].dat->size[1] * start[2] *
              args[5].stencil->stride[2];
  double *p_a5 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset +
              (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
                  start[0] * args[6].stencil->stride[0];
  base6 = base6 +
          (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
              args[6].dat->size[0] * start[1] * args[6].stencil->stride[1];
  base6 = base6 +
          (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
              args[6].dat->size[0] * args[6].dat->size[1] * start[2] *
              args[6].stencil->stride[2];
  double *p_a6 = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset +
              (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
                  start[0] * args[7].stencil->stride[0];
  base7 = base7 +
          (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
              args[7].dat->size[0] * start[1] * args[7].stencil->stride[1];
  base7 = base7 +
          (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
              args[7].dat->size[0] * args[7].dat->size[1] * start[2] *
              args[7].stencil->stride[2];
  double *p_a7 = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset +
              (OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) *
                  start[0] * args[8].stencil->stride[0];
  base8 = base8 +
          (OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) *
              args[8].dat->size[0] * start[1] * args[8].stencil->stride[1];
  base8 = base8 +
          (OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size) *
              args[8].dat->size[0] * args[8].dat->size[1] * start[2] *
              args[8].stencil->stride[2];
  double *p_a8 = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset +
              (OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) *
                  start[0] * args[9].stencil->stride[0];
  base9 = base9 +
          (OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) *
              args[9].dat->size[0] * start[1] * args[9].stencil->stride[1];
  base9 = base9 +
          (OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size) *
              args[9].dat->size[0] * args[9].dat->size[1] * start[2] *
              args[9].stencil->stride[2];
  double *p_a9 = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset +
               (OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) *
                   start[0] * args[10].stencil->stride[0];
  base10 = base10 +
           (OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) *
               args[10].dat->size[0] * start[1] * args[10].stencil->stride[1];
  base10 = base10 +
           (OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size) *
               args[10].dat->size[0] * args[10].dat->size[1] * start[2] *
               args[10].stencil->stride[2];
  double *p_a10 = (double *)(args[10].data + base10);

  ops_H_D_exchanges_host(args, 11);
  ops_halo_exchanges(args,11,range);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[112].mpi_time += t1 - t2;
  }

  advec_cell_kernel4_xdir_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    p_a8,
    p_a9,
    p_a10,
    x_size, y_size, z_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[112].time += t2 - t1;
  }
  ops_set_dirtybit_host(args, 11);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[9],range);

  //Update kernel record
  if (OPS_diags > 1) {
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[112].transfer += ops_compute_transfer(dim, start, end, &arg10);
  }
}
