//
// auto-generated by ops.py
//

void ops_init_backend();
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPS_2D
#include "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_mgrid_populate_kernel_1(char const *, ops_block, int, int *,
                                          ops_arg, ops_arg);

void ops_par_loop_mgrid_prolong_kernel(char const *, ops_block, int, int *,
                                       ops_arg, ops_arg, ops_arg);

void ops_par_loop_mgrid_prolong_kernel(char const *, ops_block, int, int *,
                                       ops_arg, ops_arg, ops_arg);

void ops_par_loop_prolong_check(char const *, ops_block, int, int *, ops_arg,
                                ops_arg, ops_arg, ops_arg, ops_arg);

void ops_par_loop_mgrid_populate_kernel_3(char const *, ops_block, int, int *,
                                          ops_arg, ops_arg);

void ops_par_loop_mgrid_restrict_kernel(char const *, ops_block, int, int *,
                                        ops_arg, ops_arg, ops_arg);

void ops_par_loop_mgrid_restrict_kernel(char const *, ops_block, int, int *,
                                        ops_arg, ops_arg, ops_arg);

void ops_par_loop_restrict_check(char const *, ops_block, int, int *, ops_arg,
                                 ops_arg, ops_arg, ops_arg);

//#include "mgrid_populate_kernel.h"
//#include "mgrid_restrict_kernel.h"
//#include "mgrid_prolong_kernel.h"

int main(int argc, const char **argv) {

  ops_init(argc, argv, 2);
  ops_init_backend();

  ops_block grid0 = ops_decl_block(2, "grid0");

  int s2D_00[] = {0, 0};
  int s2D_00_M10_P10[] = {0, 0, -1, 0, 1, 0};
  int s2D_5pt[] = {0, 0, -1, 0, 1, 0, 0, -1, 0, 1};
  ops_stencil S2D_00 = ops_decl_stencil(2, 1, s2D_00, "00");
  ops_stencil S2D_5pt = ops_decl_stencil(2, 5, s2D_5pt, "5pt");

  int fac = 1;

  int d_p[2] = {2, 2};

  int d_m[2] = {-2, -2};

  int size4[2] = {24 * fac, 24 * fac};
  int size0[2] = {12 * fac, 12 * fac};
  int size1[2] = {6 * fac, 6 * fac};
  int size2[2] = {4 * fac, 4 * fac};

  int size3[2] = {6 * fac, 6 * fac};

  int stride0[2] = {1, 1};
  int stride1[2] = {2, 2};
  int stride2[2] = {3, 3};
  int stride3[2] = {4, 4};

  ops_stencil S2D_RESTRICT_00 =
      ops_decl_restrict_stencil(2, 1, s2D_00, stride1, "RESTRICT_00");

  ops_stencil S2D_PROLONG_00 =
      ops_decl_prolong_stencil(2, 1, s2D_00, stride1, "PROLONG_00");
  ops_stencil S2D_PROLONG_00_M10_P10 = ops_decl_prolong_stencil(
      2, 3, s2D_00_M10_P10, stride1, "PROLONG_00_M10_P10");
  ops_stencil S2D_RESTRICT_00_M10_P10 = ops_decl_restrict_stencil(
      2, 3, s2D_00_M10_P10, stride1, "RESTRICT_00_M10_P10");
#define ZEROBASE
#ifdef ZEROBASE
  int base[2] = {0, 0};
#else
  int base[2] = {-1, -1};
#endif
  double *temp = NULL;

  ops_dat data0 = ops_decl_dat(grid0, 1, size0, base, d_m, d_p, stride1, temp,
                               "double", "data0");
  ops_dat data1 = ops_decl_dat(grid0, 1, size1, base, d_m, d_p, stride3, temp,
                               "double", "data1");

  ops_dat data5 = ops_decl_dat(grid0, 1, size4, base, d_m, d_p, stride0, temp,
                               "double", "data5");
  ops_dat data6 = ops_decl_dat(grid0, 1, size0, base, d_m, d_p, stride1, temp,
                               "double", "data6");

  ops_dat data3 = ops_decl_dat(grid0, 1, size1, base, d_m, d_p, stride3, temp,
                               "double", "data3");

  ops_reduction reduct_err =
      ops_decl_reduction_handle(sizeof(int), "int", "reduct_err");

  ops_halo_group halos[3];
  {
    int halo_iter[] = {2, size4[1] + 4};
    int from_base[] = {0, -2};
    int to_base[] = {size4[0], -2};
    int dir[] = {1, 2};
    ops_halo halo1 =
        ops_decl_halo(data5, data5, halo_iter, from_base, to_base, dir, dir);
    from_base[0] = size4[0] - 2;
    to_base[0] = -2;
    ops_halo halo2 =
        ops_decl_halo(data5, data5, halo_iter, from_base, to_base, dir, dir);
    int halo_iter2[] = {size4[0] + 4, 2};
    int from_base2[] = {-2, 0};
    int to_base2[] = {-2, size4[1]};
    ops_halo halo1_2 =
        ops_decl_halo(data5, data5, halo_iter2, from_base2, to_base2, dir, dir);
    from_base2[1] = size4[1] - 2;
    to_base2[1] = -2;
    ops_halo halo2_2 =
        ops_decl_halo(data5, data5, halo_iter2, from_base2, to_base2, dir, dir);
    ops_halo halog1[] = {halo1, halo2, halo1_2, halo2_2};
    halos[0] = ops_decl_halo_group(4, halog1);

    halo_iter[1] = size0[1] + 4;
    from_base[0] = 0;
    to_base[0] = size0[1];
    ops_halo halo3 =
        ops_decl_halo(data0, data0, halo_iter, from_base, to_base, dir, dir);
    from_base[0] = size0[0] - 2;
    to_base[0] = -2;
    ops_halo halo4 =
        ops_decl_halo(data0, data0, halo_iter, from_base, to_base, dir, dir);
    ops_halo halog2[] = {halo3, halo4};
    halos[1] = ops_decl_halo_group(2, halog2);

    halo_iter[1] = size1[1] + 4;
    from_base[0] = 0;
    to_base[0] = size1[1];
    ops_halo halo5 =
        ops_decl_halo(data1, data1, halo_iter, from_base, to_base, dir, dir);
    from_base[0] = size1[0] - 2;
    to_base[0] = -2;
    ops_halo halo6 =
        ops_decl_halo(data1, data1, halo_iter, from_base, to_base, dir, dir);
    ops_halo halog3[] = {halo5, halo6};
    halos[2] = ops_decl_halo_group(2, halog3);
  }
  ops_partition("");

  double ct0, ct1, et0, et1;
  ops_timers_core(&ct0, &et0);
#ifdef ZEROBASE
  int iter_range[] = {0, 12, 0, 12};
  int iter_range_large[] = {0, 24, 0, 24};
  int iter_range_small[] = {0, 6, 0, 6};
  int iter_range_tiny[] = {0, 4, 0, 4};
#else
  int iter_range[] = {-1, 11, -1, 11};
  int iter_range_large[] = {-1, 23, -1, 23};
  int iter_range_small[] = {-1, 5, -1, 5};
  int iter_range_tiny[] = {-1, 3, -1, 3};
#endif

  ops_par_loop_mgrid_populate_kernel_1(
      "mgrid_populate_kernel_1", grid0, 2, iter_range_small,
      ops_arg_dat(data1, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());
  ops_halo_transfer(halos[2]);

  ops_par_loop_mgrid_prolong_kernel(
      "mgrid_prolong_kernel", grid0, 2, iter_range,
      ops_arg_dat(data1, 1, S2D_PROLONG_00_M10_P10, "double", OPS_READ),
      ops_arg_dat(data0, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());
  ops_halo_transfer(halos[1]);

  ops_par_loop_mgrid_prolong_kernel(
      "mgrid_prolong_kernel", grid0, 2, iter_range_large,
      ops_arg_dat(data0, 1, S2D_PROLONG_00_M10_P10, "double", OPS_READ),
      ops_arg_dat(data5, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());
  ops_halo_transfer(halos[0]);

  ops_par_loop_prolong_check("prolong_check", grid0, 2, iter_range_large,
                             ops_arg_dat(data5, 1, S2D_5pt, "double", OPS_READ),
                             ops_arg_idx(),
                             ops_arg_reduce(reduct_err, 1, "int", OPS_MAX),
                             ops_arg_gbl(&size4[0], 1, "int", OPS_READ),
                             ops_arg_gbl(&size4[1], 1, "int", OPS_READ));

  int err_prolong = 0;
  ops_reduction_result(reduct_err, &err_prolong);

  ops_par_loop_mgrid_populate_kernel_3(
      "mgrid_populate_kernel_3", grid0, 2, iter_range_large,
      ops_arg_dat(data5, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());

  ops_par_loop_mgrid_restrict_kernel(
      "mgrid_restrict_kernel", grid0, 2, iter_range,
      ops_arg_dat(data5, 1, S2D_RESTRICT_00_M10_P10, "double", OPS_READ),
      ops_arg_dat(data6, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());
  ops_par_loop_mgrid_restrict_kernel(
      "mgrid_restrict_kernel", grid0, 2, iter_range_small,
      ops_arg_dat(data6, 1, S2D_RESTRICT_00_M10_P10, "double", OPS_READ),
      ops_arg_dat(data3, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());

  ops_par_loop_restrict_check("prolong_check", grid0, 2, iter_range_small,
                              ops_arg_dat(data3, 1, S2D_00, "double", OPS_READ),
                              ops_arg_idx(),
                              ops_arg_reduce(reduct_err, 1, "int", OPS_MAX),
                              ops_arg_gbl(&size4[0], 1, "int", OPS_READ));

  int err_restrict = 0;
  ops_reduction_result(reduct_err, &err_restrict);

  ops_timers_core(&ct1, &et1);
  ops_timing_output(stdout);

  ops_printf("\nTotal Wall time %lf\n", et1 - et0);

  ops_fetch_block_hdf5_file(grid0, "data.h5");
  ops_fetch_dat_hdf5_file(data3, "data.h5");
  ops_fetch_dat_hdf5_file(data5, "data.h5");
  ops_fetch_dat_hdf5_file(data6, "data.h5");

  if (err_prolong == 0 && err_restrict == 0)
    ops_printf("\nPASSED\n");
  else
    ops_printf("\nFAILED\n");

  ops_exit();
}
