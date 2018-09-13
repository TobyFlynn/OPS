//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_viscosity_kernel*1+x+xdim0_viscosity_kernel*(y))
#define OPS_ACC1(x,y) (n_x*1+n_y*xdim1_viscosity_kernel*1+x+xdim1_viscosity_kernel*(y))
#define OPS_ACC2(x,y) (n_x*1+n_y*xdim2_viscosity_kernel*0+x+xdim2_viscosity_kernel*(y))
#define OPS_ACC3(x,y) (n_x*0+n_y*xdim3_viscosity_kernel*1+x+xdim3_viscosity_kernel*(y))
#define OPS_ACC4(x,y) (n_x*1+n_y*xdim4_viscosity_kernel*1+x+xdim4_viscosity_kernel*(y))
#define OPS_ACC5(x,y) (n_x*1+n_y*xdim5_viscosity_kernel*1+x+xdim5_viscosity_kernel*(y))
#define OPS_ACC6(x,y) (n_x*1+n_y*xdim6_viscosity_kernel*1+x+xdim6_viscosity_kernel*(y))


//user function

// host stub function
void ops_par_loop_viscosity_kernel_execute(ops_kernel_descriptor *desc) {
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

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[7] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 7, range, 34))
    return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[34].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "viscosity_kernel");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double * __restrict__ xvel0 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ yvel0 = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double * __restrict__ celldx = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double * __restrict__ celldy = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double * __restrict__ pressure = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  const double * __restrict__ density0 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ viscosity = (double *)(args[6].data + base6);


  //initialize global variable with the dimension of dats
  int xdim0_viscosity_kernel = args[0].dat->size[0];
  int xdim1_viscosity_kernel = args[1].dat->size[0];
  int xdim2_viscosity_kernel = args[2].dat->size[0];
  int xdim3_viscosity_kernel = args[3].dat->size[0];
  int xdim4_viscosity_kernel = args[4].dat->size[0];
  int xdim5_viscosity_kernel = args[5].dat->size[0];
  int xdim6_viscosity_kernel = args[6].dat->size[0];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[34].mpi_time += t1 - t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef intel
    #pragma loop_count(10000)
    #pragma omp simd aligned(xvel0,yvel0,celldx,celldy,pressure,density0,viscosity)
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      

  double ugrad, vgrad,
         grad2,
         pgradx,pgrady,
         pgradx2,pgrady2,
         grad,
         ygrad, xgrad,
         div,
         strain2,
         limiter,
         pgrad;


  ugrad = (xvel0[OPS_ACC0(1,0)] + xvel0[OPS_ACC0(1,1)]) - (xvel0[OPS_ACC0(0,0)] + xvel0[OPS_ACC0(0,1)]);
  vgrad = (yvel0[OPS_ACC1(0,1)] + yvel0[OPS_ACC1(1,1)]) - (yvel0[OPS_ACC1(0,0)] + yvel0[OPS_ACC1(1,0)]);

  div = (celldx[OPS_ACC2(0,0)])*(ugrad) + (celldy[OPS_ACC3(0,0)])*(vgrad);

  strain2 = 0.5*(xvel0[OPS_ACC0(0,1)] + xvel0[OPS_ACC0(1,1)] - xvel0[OPS_ACC0(0,0)] - xvel0[OPS_ACC0(1,0)])/(celldy[OPS_ACC3(0,0)]) +
            0.5*(yvel0[OPS_ACC1(1,0)] + yvel0[OPS_ACC1(1,1)] - yvel0[OPS_ACC1(0,0)] - yvel0[OPS_ACC1(0,1)])/(celldx[OPS_ACC2(0,0)]);


  pgradx  = (pressure[OPS_ACC4(1,0)] - pressure[OPS_ACC4(-1,0)])/(celldx[OPS_ACC2(0,0)]+ celldx[OPS_ACC2(1,0)]);
  pgrady = (pressure[OPS_ACC4(0,1)] - pressure[OPS_ACC4(0,-1)])/(celldy[OPS_ACC3(0,0)]+ celldy[OPS_ACC3(0,1)]);

  pgradx2 = pgradx * pgradx;
  pgrady2 = pgrady * pgrady;

  limiter = ((0.5*(ugrad)/celldx[OPS_ACC2(0,0)]) * pgradx2 +
             (0.5*(vgrad)/celldy[OPS_ACC3(0,0)]) * pgrady2 +
              strain2 * pgradx * pgrady)/ MAX(pgradx2 + pgrady2 , 1.0e-16);

  if( (limiter > 0.0) || (div >= 0.0)) {
        viscosity[OPS_ACC6(0,0)] = 0.0;
  }
  else {
    pgradx = SIGN( MAX(1.0e-16, fabs(pgradx)), pgradx);
    pgrady = SIGN( MAX(1.0e-16, fabs(pgrady)), pgrady);
    pgrad = sqrt(pgradx*pgradx + pgrady*pgrady);
    xgrad = fabs(celldx[OPS_ACC2(0,0)] * pgrad/pgradx);
    ygrad = fabs(celldy[OPS_ACC3(0,0)] * pgrad/pgrady);
    grad  = MIN(xgrad,ygrad);
    grad2 = grad*grad;

    viscosity[OPS_ACC6(0,0)] = 2.0 * (density0[OPS_ACC5(0,0)]) * grad2 * limiter * limiter;
  }

    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[34].time += t2 - t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[34].mpi_time += t1 - t2;
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6


void ops_par_loop_viscosity_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 34;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 34;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 7;
  desc->args = (ops_arg*)malloc(7*sizeof(ops_arg));
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
  desc->function = ops_par_loop_viscosity_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(34, "viscosity_kernel");
  }
  ops_enqueue_kernel(desc);
  }
