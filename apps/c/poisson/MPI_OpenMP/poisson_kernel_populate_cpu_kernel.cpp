//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_poisson_kernel_populate(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_poisson_kernel_populate_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,6,range,0)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(0,"poisson_kernel_populate");
    OPS_kernels[0].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "poisson_kernel_populate");
  #endif


  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  int arg_idx[2];
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif

  #ifdef OPS_MPI
  arg_idx[0] -= start[0];
  arg_idx[1] -= start[1];
  #else
  arg_idx[0] = 0;
  arg_idx[1] = 0;
  #endif //OPS_MPI

  //initialize global variable with the dimension of dats
  int xdim3_poisson_kernel_populate = args[3].dat->size[0];
  int xdim4_poisson_kernel_populate = args[4].dat->size[0];
  int xdim5_poisson_kernel_populate = args[5].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int * __restrict__ dispx = (int *)args[0].data;


  int * __restrict__ dispy = (int *)args[1].data;



  int base3 = args[3].dat->base_offset;
  double * __restrict__ u_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ f_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ ref_p = (double *)(args[5].data + base5);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args,6,range);
  ops_H_D_exchanges_host(args, 6);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[0].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    int idx[] = {0, arg_idx[1]+n_y};
    #ifdef __INTEL_COMPILER
    #pragma loop_count(10000)
    #pragma omp simd aligned(u,f,ref)
    #elif defined(__clang__)
    #pragma clang loop vectorize(assume_safety)
    #elif defined(__GNUC__)
    #pragma simd
    #pragma GCC ivdep
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      idx[0] = arg_idx[0]+n_x;
      ACC<double> u(xdim3_poisson_kernel_populate, u_p + n_x*1 + n_y * xdim3_poisson_kernel_populate*1);
      ACC<double> f(xdim4_poisson_kernel_populate, f_p + n_x*1 + n_y * xdim4_poisson_kernel_populate*1);
      ACC<double> ref(xdim5_poisson_kernel_populate, ref_p + n_x*1 + n_y * xdim5_poisson_kernel_populate*1);
      
  double x = dx * (double)(idx[0]+dispx[0]);
  double y = dy * (double)(idx[1]+dispy[0]);

  u(0,0) = myfun(sin(M_PI*x),cos(2.0*M_PI*y))-1.0;
  f(0,0) = -5.0*M_PI*M_PI*sin(M_PI*x)*cos(2.0*M_PI*y);
  ref(0,0) = sin(M_PI*x)*cos(2.0*M_PI*y);


    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[0].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 6);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[0].mpi_time += __t1-__t2;
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg5);
  }
}
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5


#ifdef OPS_LAZY
void ops_par_loop_poisson_kernel_populate(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
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
