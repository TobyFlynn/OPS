//
// auto-generated by ops.py
//

//user function
inline void advec_cell_kernel3_xdir( const double *vol_flux_x, const double *pre_vol, const int *xx,
                              const double *vertexdx,
                              const double *density1, const double *energy1 ,
                              double *mass_flux_x, double *ener_flux) {

  double sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int x_max=field.x_max;

  int upwind,donor,downwind,dif;





  if(vol_flux_x[OPS_ACC0(0,0)] > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (xx[OPS_ACC2(1,0)] < x_max+2-2) {
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


  sigmat = fabs(vol_flux_x[OPS_ACC0(0,0)])/pre_vol[OPS_ACC1(donor,0)];
  sigma3 = (1.0 + sigmat)*(vertexdx[OPS_ACC3(0,0)]/vertexdx[OPS_ACC3(dif,0)]);
  sigma4 = 2.0 - sigmat;

  sigmav = sigmat;

  diffuw = density1[OPS_ACC4(donor,0)] - density1[OPS_ACC4(upwind,0)];
  diffdw = density1[OPS_ACC4(downwind,0)] - density1[OPS_ACC4(donor,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  mass_flux_x[OPS_ACC6(0,0)] = (vol_flux_x[OPS_ACC0(0,0)]) * ( density1[OPS_ACC4(donor,0)] + limiter );

  sigmam = fabs(mass_flux_x[OPS_ACC6(0,0)])/( density1[OPS_ACC4(donor,0)] * pre_vol[OPS_ACC1(donor,0)]);
  diffuw = energy1[OPS_ACC5(donor,0)] - energy1[OPS_ACC5(upwind,0)];
  diffdw = energy1[OPS_ACC5(downwind,0)] - energy1[OPS_ACC5(donor,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  ener_flux[OPS_ACC7(0,0)] = mass_flux_x[OPS_ACC6(0,0)] * ( energy1[OPS_ACC5(donor,0)] + limiter );
}





// host stub function
void ops_par_loop_advec_cell_kernel3_xdir_execute(ops_kernel_descriptor *desc) {
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

  //Timing
  double t1,t2,c1,c2;

  char *p_a[8];
  int  offs[8][2];
  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,8,range,9)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(9,"advec_cell_kernel3_xdir");
    OPS_kernels[9].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "advec_cell_kernel3_xdir");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ p_a0 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ p_a1 = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  int * __restrict__ p_a2 = (int *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ p_a3 = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ p_a4 = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ p_a5 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ p_a6 = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ p_a7 = (double *)(args[7].data + base7);


  //initialize global variable with the dimension of dats
  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  xdim3 = args[3].dat->size[0];
  xdim4 = args[4].dat->size[0];
  xdim5 = args[5].dat->size[0];
  xdim6 = args[6].dat->size[0];
  xdim7 = args[7].dat->size[0];

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #pragma simd
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      advec_cell_kernel3_xdir(  p_a0 + n_x*1*1 + n_y*xdim0*1*1,
           p_a1 + n_x*1*1 + n_y*xdim1*1*1, p_a2 + n_x*1*1 + n_y*xdim2*0*1, p_a3 + n_x*1*1 + n_y*xdim3*0*1, p_a4 + n_x*1*1 + n_y*xdim4*1*1,
           p_a5 + n_x*1*1 + n_y*xdim5*1*1, p_a6 + n_x*1*1 + n_y*xdim6*1*1, p_a7 + n_x*1*1 + n_y*xdim7*1*1 );

    }
  }
}

void ops_par_loop_advec_cell_kernel3_xdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 9;
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
  desc->nargs = 8;
  desc->args = (ops_arg*)malloc(8*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->args[1] = arg1;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->args[4] = arg4;
  desc->args[5] = arg5;
  desc->args[6] = arg6;
  desc->args[7] = arg7;
  desc->function = ops_par_loop_advec_cell_kernel3_xdir_execute;
  ops_enqueue_kernel(desc);
  }
