//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y) (n_x*1 + x + (n_y*1+(y))*xdim0_initialise_chunk_kernel_zero)

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zero(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0) {
#else
void ops_par_loop_initialise_chunk_kernel_zero_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[1] = { arg0};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,1,range,5)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(5,"initialise_chunk_kernel_zero");
    OPS_kernels[5].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "initialise_chunk_kernel_zero");
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
  if (compute_ranges(args, 1,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_initialise_chunk_kernel_zero = args[0].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ var = (double *)(args[0].data + base0);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 1);
  ops_halo_exchanges(args,1,range);
  ops_H_D_exchanges_host(args, 1);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[5].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef __INTEL_COMPILER
    #pragma loop_count(10000)
    #pragma omp simd aligned(var)
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      
  *var = 0.0;

    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[5].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 1);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[5].mpi_time += __t1-__t2;
    OPS_kernels[5].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
#undef OPS_ACC0


#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zero(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 5;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 5;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 1;
  desc->args = (ops_arg*)malloc(1*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->function = ops_par_loop_initialise_chunk_kernel_zero_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(5,"initialise_chunk_kernel_zero");
  }
  ops_enqueue_kernel(desc);
}
#endif
