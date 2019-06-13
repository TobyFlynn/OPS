//
// auto-generated by ops.py
//

// user function
inline void drhoEpudx_kernel(const double *rhou_new, const double *rho_new,
                             const double *rhoE_new, double *rhoE_res) {

  double fni =
      rhou_new[OPS_ACC0(0)] * rhou_new[OPS_ACC0(0)] / rho_new[OPS_ACC1(0)];
  double p = gam1 * (rhoE_new[OPS_ACC2(0)] - 0.5 * fni);
  fni = (rhoE_new[OPS_ACC2(0)] + p) * rhou_new[OPS_ACC0(0)] /
        rho_new[OPS_ACC1(0)];

  double fnim1 =
      rhou_new[OPS_ACC0(-1)] * rhou_new[OPS_ACC0(-1)] / rho_new[OPS_ACC1(-1)];
  p = gam1 * (rhoE_new[OPS_ACC2(-1)] - 0.5 * fnim1);
  fnim1 = (rhoE_new[OPS_ACC2(-1)] + p) * rhou_new[OPS_ACC0(-1)] /
          rho_new[OPS_ACC1(-1)];

  double fnim2 =
      rhou_new[OPS_ACC0(-2)] * rhou_new[OPS_ACC0(-2)] / rho_new[OPS_ACC1(-2)];
  p = gam1 * (rhoE_new[OPS_ACC2(-2)] - 0.5 * fnim2);
  fnim2 = (rhoE_new[OPS_ACC2(-2)] + p) * rhou_new[OPS_ACC0(-2)] /
          rho_new[OPS_ACC1(-2)];

  double fnip1 =
      rhou_new[OPS_ACC0(1)] * rhou_new[OPS_ACC0(1)] / rho_new[OPS_ACC1(1)];
  p = gam1 * (rhoE_new[OPS_ACC2(1)] - 0.5 * fnip1);
  fnip1 = (rhoE_new[OPS_ACC2(1)] + p) * rhou_new[OPS_ACC0(1)] /
          rho_new[OPS_ACC1(1)];

  double fnip2 =
      rhou_new[OPS_ACC0(2)] * rhou_new[OPS_ACC0(2)] / rho_new[OPS_ACC1(2)];
  p = gam1 * (rhoE_new[OPS_ACC2(2)] - 0.5 * fnip2);
  fnip2 = (rhoE_new[OPS_ACC2(2)] + p) * rhou_new[OPS_ACC0(2)] /
          rho_new[OPS_ACC1(2)];

  double deriv = (fnim2 - fnip2 + 8.0 * (fnip1 - fnim1)) / (12.00 * dx);
  rhoE_res[OPS_ACC3(0)] = deriv;
}

// host stub function
void ops_par_loop_drhoEpudx_kernel(char const *name, ops_block block, int dim,
                                   int *range, ops_arg arg0, ops_arg arg1,
                                   ops_arg arg2, ops_arg arg3) {

  // Timing
  double t1, t2, c1, c2;

  char *p_a[4];
  int offs[4][1];
  ops_arg args[4] = {arg0, arg1, arg2, arg3};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 4, range, 5))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(5, "drhoEpudx_kernel");
    OPS_kernels[5].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[1];
  int end[1];

#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
#endif
#ifdef OPS_DEBUG
  ops_register_args(args, "drhoEpudx_kernel");
#endif

  int arg_idx[1];
  int arg_idx_base[1];
#ifdef OPS_MPI
  if (compute_ranges(args, 4, block, range, start, end, arg_idx) < 0)
    return;
#else  // OPS_MPI
  for (int n = 0; n < 1; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
    arg_idx[n] = start[n];
  }
#endif // OPS_MPI
  for (int n = 0; n < 1; n++) {
    arg_idx_base[n] = arg_idx[n];
  }
  offs[0][0] = args[0].stencil->stride[0] * 1; // unit step in x dimension

  offs[1][0] = args[1].stencil->stride[0] * 1; // unit step in x dimension

  offs[2][0] = args[2].stencil->stride[0] * 1; // unit step in x dimension

  offs[3][0] = args[3].stencil->stride[0] * 1; // unit step in x dimension

  int off0_0 = offs[0][0];
  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int off1_0 = offs[1][0];
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int off2_0 = offs[2][0];
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int off3_0 = offs[3][0];
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset +
              (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
                  start[0] * args[0].stencil->stride[0];
  p_a[0] = (char *)args[0].data + base0;

  int base1 = args[1].dat->base_offset +
              (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
                  start[0] * args[1].stencil->stride[0];
  p_a[1] = (char *)args[1].data + base1;

  int base2 = args[2].dat->base_offset +
              (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
                  start[0] * args[2].stencil->stride[0];
  p_a[2] = (char *)args[2].data + base2;

  int base3 = args[3].dat->base_offset +
              (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
                  start[0] * args[3].stencil->stride[0];
  p_a[3] = (char *)args[3].data + base3;

  // initialize global variable with the dimension of dats
  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  xdim3 = args[3].dat->size[0];

  // Halo Exchanges
  ops_H_D_exchanges_host(args, 4);
  ops_halo_exchanges(args, 4, range);
  ops_H_D_exchanges_host(args, 4);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[5].mpi_time += t1 - t2;
  }

  int n_x;
#pragma novector
  for (n_x = start[0];
       n_x < start[0] + ((end[0] - start[0]) / SIMD_VEC) * SIMD_VEC;
       n_x += SIMD_VEC) {
// call kernel function, passing in pointers to data -vectorised
#pragma simd
    for (int i = 0; i < SIMD_VEC; i++) {
      drhoEpudx_kernel(
          (double *)p_a[0] + i * 1 * 1, (double *)p_a[1] + i * 1 * 1,
          (double *)p_a[2] + i * 1 * 1, (double *)p_a[3] + i * 1 * 1);
    }

    // shift pointers to data x direction
    p_a[0] = p_a[0] + (dat0 * off0_0) * SIMD_VEC;
    p_a[1] = p_a[1] + (dat1 * off1_0) * SIMD_VEC;
    p_a[2] = p_a[2] + (dat2 * off2_0) * SIMD_VEC;
    p_a[3] = p_a[3] + (dat3 * off3_0) * SIMD_VEC;
  }

  for (int n_x = start[0] + ((end[0] - start[0]) / SIMD_VEC) * SIMD_VEC;
       n_x < end[0]; n_x++) {
    // call kernel function, passing in pointers to data - remainder
    drhoEpudx_kernel((double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
                     (double *)p_a[3]);

    // shift pointers to data x direction
    p_a[0] = p_a[0] + (dat0 * off0_0);
    p_a[1] = p_a[1] + (dat1 * off1_0);
    p_a[2] = p_a[2] + (dat2 * off2_0);
    p_a[3] = p_a[3] + (dat3 * off3_0);
  }

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[5].time += t2 - t1;
  }
  ops_set_dirtybit_host(args, 4);
  ops_set_halo_dirtybit3(&args[3], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[5].mpi_time += t1 - t2;
    OPS_kernels[5].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[5].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[5].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[5].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
