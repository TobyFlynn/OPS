//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_advec_cell_kernel4_ydir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10) {
#else
void ops_par_loop_advec_cell_kernel4_ydir_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
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
  ops_arg arg8 = desc->args[8];
  ops_arg arg9 = desc->args[9];
  ops_arg arg10 = desc->args[10];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,11,range,68)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(68,"advec_cell_kernel4_ydir");
    OPS_kernels[68].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "advec_cell_kernel4_ydir");
  #endif


  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #ifdef OPS_MPI
  int arg_idx[2];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 11,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_advec_cell_kernel4_ydir = args[0].dat->size[0];
  int xdim1_advec_cell_kernel4_ydir = args[1].dat->size[0];
  int xdim2_advec_cell_kernel4_ydir = args[2].dat->size[0];
  int xdim3_advec_cell_kernel4_ydir = args[3].dat->size[0];
  int xdim4_advec_cell_kernel4_ydir = args[4].dat->size[0];
  int xdim5_advec_cell_kernel4_ydir = args[5].dat->size[0];
  int xdim6_advec_cell_kernel4_ydir = args[6].dat->size[0];
  int xdim7_advec_cell_kernel4_ydir = args[7].dat->size[0];
  int xdim8_advec_cell_kernel4_ydir = args[8].dat->size[0];
  int xdim9_advec_cell_kernel4_ydir = args[9].dat->size[0];
  int xdim10_advec_cell_kernel4_ydir = args[10].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ density1_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ energy1_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ mass_flux_y_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ vol_flux_y_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ pre_vol_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ post_vol_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ pre_mass_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ post_mass_p = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  double * __restrict__ advec_vol_p = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  double * __restrict__ post_ener_p = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  double * __restrict__ ener_flux_p = (double *)(args[10].data + base10);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 11);
  ops_halo_exchanges(args,11,range);
  ops_H_D_exchanges_host(args, 11);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[68].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef __INTEL_COMPILER
    #pragma loop_count(10000)
    #pragma omp simd
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      ACC<double> density1(xdim0_advec_cell_kernel4_ydir, density1_p + n_x*1 + n_y * xdim0_advec_cell_kernel4_ydir*1);
      ACC<double> energy1(xdim1_advec_cell_kernel4_ydir, energy1_p + n_x*1 + n_y * xdim1_advec_cell_kernel4_ydir*1);
      const ACC<double> mass_flux_y(xdim2_advec_cell_kernel4_ydir, mass_flux_y_p + n_x*1 + n_y * xdim2_advec_cell_kernel4_ydir*1);
      const ACC<double> vol_flux_y(xdim3_advec_cell_kernel4_ydir, vol_flux_y_p + n_x*1 + n_y * xdim3_advec_cell_kernel4_ydir*1);
      const ACC<double> pre_vol(xdim4_advec_cell_kernel4_ydir, pre_vol_p + n_x*1 + n_y * xdim4_advec_cell_kernel4_ydir*1);
      const ACC<double> post_vol(xdim5_advec_cell_kernel4_ydir, post_vol_p + n_x*1 + n_y * xdim5_advec_cell_kernel4_ydir*1);
      ACC<double> pre_mass(xdim6_advec_cell_kernel4_ydir, pre_mass_p + n_x*1 + n_y * xdim6_advec_cell_kernel4_ydir*1);
      ACC<double> post_mass(xdim7_advec_cell_kernel4_ydir, post_mass_p + n_x*1 + n_y * xdim7_advec_cell_kernel4_ydir*1);
      ACC<double> advec_vol(xdim8_advec_cell_kernel4_ydir, advec_vol_p + n_x*1 + n_y * xdim8_advec_cell_kernel4_ydir*1);
      ACC<double> post_ener(xdim9_advec_cell_kernel4_ydir, post_ener_p + n_x*1 + n_y * xdim9_advec_cell_kernel4_ydir*1);
      const ACC<double> ener_flux(xdim10_advec_cell_kernel4_ydir, ener_flux_p + n_x*1 + n_y * xdim10_advec_cell_kernel4_ydir*1);
      

  pre_mass(0,0) = density1(0,0) * pre_vol(0,0);
  post_mass(0,0) = pre_mass(0,0) + mass_flux_y(0,0) - mass_flux_y(0,1);
  post_ener(0,0) = ( energy1(0,0) * pre_mass(0,0) + ener_flux(0,0) - ener_flux(0,1))/post_mass(0,0);
  advec_vol(0,0) = pre_vol(0,0) + vol_flux_y(0,0) - vol_flux_y(0,1);
  density1(0,0) = post_mass(0,0)/advec_vol(0,0);
  energy1(0,0) = post_ener(0,0);


    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[68].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 11);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[9],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[68].mpi_time += __t1-__t2;
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[68].transfer += ops_compute_transfer(dim, start, end, &arg10);
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
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10


#ifdef OPS_LAZY
void ops_par_loop_advec_cell_kernel4_ydir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 68;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 68;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 11;
  desc->args = (ops_arg*)malloc(11*sizeof(ops_arg));
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
  desc->args[8] = arg8;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg8.dat->index;
  desc->args[9] = arg9;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg9.dat->index;
  desc->args[10] = arg10;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg10.dat->index;
  desc->function = ops_par_loop_advec_cell_kernel4_ydir_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(68,"advec_cell_kernel4_ydir");
  }
  ops_enqueue_kernel(desc);
}
#endif
