//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_advec_mom_kernel_post_pre_advec_y(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
#else
void ops_par_loop_advec_mom_kernel_post_pre_advec_y_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,5,range,131)) return;
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(131,"advec_mom_kernel_post_pre_advec_y");
    OPS_instance::getOPSInstance()->OPS_kernels[131].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "advec_mom_kernel_post_pre_advec_y");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
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


  //initialize global variable with the dimension of dats
  int xdim0_advec_mom_kernel_post_pre_advec_y = args[0].dat->size[0];
  int ydim0_advec_mom_kernel_post_pre_advec_y = args[0].dat->size[1];
  int xdim1_advec_mom_kernel_post_pre_advec_y = args[1].dat->size[0];
  int ydim1_advec_mom_kernel_post_pre_advec_y = args[1].dat->size[1];
  int xdim2_advec_mom_kernel_post_pre_advec_y = args[2].dat->size[0];
  int ydim2_advec_mom_kernel_post_pre_advec_y = args[2].dat->size[1];
  int xdim3_advec_mom_kernel_post_pre_advec_y = args[3].dat->size[0];
  int ydim3_advec_mom_kernel_post_pre_advec_y = args[3].dat->size[1];
  int xdim4_advec_mom_kernel_post_pre_advec_y = args[4].dat->size[0];
  int ydim4_advec_mom_kernel_post_pre_advec_y = args[4].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ node_mass_post_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ post_vol_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ density1_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ node_mass_pre_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ node_flux_p = (double *)(args[4].data + base4);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 5);
  ops_halo_exchanges(args,5,range);
  ops_H_D_exchanges_host(args, 5);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_instance::getOPSInstance()->OPS_kernels[131].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd
      #elif defined(__clang__)
      #pragma clang loop vectorize(assume_safety)
      #elif defined(__GNUC__)
      #pragma simd
      #pragma GCC ivdep
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        ACC<double> node_mass_post(xdim0_advec_mom_kernel_post_pre_advec_y, ydim0_advec_mom_kernel_post_pre_advec_y, node_mass_post_p + n_x*1 + n_y * xdim0_advec_mom_kernel_post_pre_advec_y*1 + n_z * xdim0_advec_mom_kernel_post_pre_advec_y * ydim0_advec_mom_kernel_post_pre_advec_y*1);
        const ACC<double> post_vol(xdim1_advec_mom_kernel_post_pre_advec_y, ydim1_advec_mom_kernel_post_pre_advec_y, post_vol_p + n_x*1 + n_y * xdim1_advec_mom_kernel_post_pre_advec_y*1 + n_z * xdim1_advec_mom_kernel_post_pre_advec_y * ydim1_advec_mom_kernel_post_pre_advec_y*1);
        const ACC<double> density1(xdim2_advec_mom_kernel_post_pre_advec_y, ydim2_advec_mom_kernel_post_pre_advec_y, density1_p + n_x*1 + n_y * xdim2_advec_mom_kernel_post_pre_advec_y*1 + n_z * xdim2_advec_mom_kernel_post_pre_advec_y * ydim2_advec_mom_kernel_post_pre_advec_y*1);
        ACC<double> node_mass_pre(xdim3_advec_mom_kernel_post_pre_advec_y, ydim3_advec_mom_kernel_post_pre_advec_y, node_mass_pre_p + n_x*1 + n_y * xdim3_advec_mom_kernel_post_pre_advec_y*1 + n_z * xdim3_advec_mom_kernel_post_pre_advec_y * ydim3_advec_mom_kernel_post_pre_advec_y*1);
        const ACC<double> node_flux(xdim4_advec_mom_kernel_post_pre_advec_y, ydim4_advec_mom_kernel_post_pre_advec_y, node_flux_p + n_x*1 + n_y * xdim4_advec_mom_kernel_post_pre_advec_y*1 + n_z * xdim4_advec_mom_kernel_post_pre_advec_y * ydim4_advec_mom_kernel_post_pre_advec_y*1);
        

  node_mass_post(0,0,0) = 0.125 * ( density1(0,-1,0) * post_vol(0,-1,0) +
                                              density1(0,0,0)   * post_vol(0,0,0)   +
                                              density1(-1,-1,0) * post_vol(-1,-1,0) +
                                              density1(-1,0,0)  * post_vol(-1,0,0) +
                                              density1(0,-1,-1) * post_vol(0,-1,-1) +
                                              density1(0,0,-1)   * post_vol(0,0,-1)   +
                                              density1(-1,-1,-1) * post_vol(-1,-1,-1) +
                                              density1(-1,0,-1)  * post_vol(-1,0,-1)  );

  node_mass_pre(0,0,0) = node_mass_post(0,0,0) - node_flux(0,-1,0) + node_flux(0,0,0);

      }
    }
  }
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_instance::getOPSInstance()->OPS_kernels[131].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 5);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[3],range);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_instance::getOPSInstance()->OPS_kernels[131].mpi_time += __t1-__t2;
    OPS_instance::getOPSInstance()->OPS_kernels[131].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_instance::getOPSInstance()->OPS_kernels[131].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_instance::getOPSInstance()->OPS_kernels[131].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_instance::getOPSInstance()->OPS_kernels[131].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_instance::getOPSInstance()->OPS_kernels[131].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_advec_mom_kernel_post_pre_advec_y(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 131;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 131;
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
  desc->function = ops_par_loop_advec_mom_kernel_post_pre_advec_y_execute;
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(131,"advec_mom_kernel_post_pre_advec_y");
  }
  ops_enqueue_kernel(desc);
}
#endif
