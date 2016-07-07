//
// auto-generated by ops.py
//

//user function
inline void advec_mom_kernel_x2( double *pre_vol, double *post_vol,
                          const double *volume,
                          const double *vol_flux_y) {

  post_vol[OPS_ACC1(0,0)]  = volume[OPS_ACC2(0,0)] ;
  pre_vol[OPS_ACC0(0,0)]   = post_vol[OPS_ACC1(0,0)]  + vol_flux_y[OPS_ACC3(0,1)] - vol_flux_y[OPS_ACC3(0,0)];

}





// host stub function
void ops_par_loop_advec_mom_kernel_x2_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];

  //Timing
  double t1,t2,c1,c2;

  char *p_a[4];
  int  offs[4][2];
  ops_arg args[4] = { arg0, arg1, arg2, arg3};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,17)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(17,"advec_mom_kernel_x2");
    OPS_kernels[17].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "advec_mom_kernel_x2");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ p_a0 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ p_a1 = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ p_a2 = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ p_a3 = (double *)(args[3].data + base3);


  //initialize global variable with the dimension of dats
  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  xdim3 = args[3].dat->size[0];

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #pragma omp simd
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      advec_mom_kernel_x2(  p_a0 + n_x*1*1 + n_y*xdim0*1*1,
           p_a1 + n_x*1*1 + n_y*xdim1*1*1, p_a2 + n_x*1*1 + n_y*xdim2*1*1, p_a3 + n_x*1*1 + n_y*xdim3*1*1 );

    }
  }
}

void ops_par_loop_advec_mom_kernel_x2(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 17;
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<2; n++ ){
    desc->range[2*n] = sb->decomp_disp[n];desc->range[2*n+1] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (desc->range[2*n] >= range[2*n]) {
      desc->range[2*n] = 0;
    }
    else {
      desc->range[2*n] = range[2*n] - desc->range[2*n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) desc->range[2*n] = range[2*n];
    if (desc->range[2*n+1] >= range[2*n+1]) {
      desc->range[2*n+1] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      desc->range[2*n+1] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      desc->range[2*n+1] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else //OPS_MPI
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
  }
  #endif //OPS_MPI
  desc->nargs = 4;
  desc->args = (ops_arg*)malloc(4*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->args[1] = arg1;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->function = ops_par_loop_advec_mom_kernel_x2_execute;
  ops_enqueue_kernel(desc);
  }
