//
// auto-generated by ops.py//




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define OPS_3D
#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_init_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_preproc_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_rms_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );



#include "data.h"

//#include "init_kernel.h"
//#include "preproc_kernel.h"
//#include "rms_kernel.h"


int nx;
int ny;
int nz;
int iter;
int opts[3], synch;

double lambda;

int main(int argc, char **argv)
{

  nx = 256;
  ny = 256;
  nz = 256;
  iter = 10;
  opts[0] = 0;
  opts[1] = 0;
  opts[2] = 0;
  synch = 1;

  lambda=1.0f;


  ops_init(argc,argv,1);


  ops_block heat3D = ops_decl_block(3, "Heat3D");

  int d_p[3] = {1,1,1};
  int d_m[3] = {-1,-1,-1};
  int size[3] = {nx, ny, nz};
  int base[3] = {0,0,0};
  double* temp = NULL;

  ops_dat h_u     = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_u");

  d_p[0] = 0; d_p[1] = 0; d_p[2] = 0;
  d_m[0] = 0; d_m[1] = 0; d_m[2] = 0;

  ops_dat h_temp  = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_tmp");
  ops_dat h_du    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_du");
  ops_dat h_ax    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_ax");
  ops_dat h_bx    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_bx");
  ops_dat h_cx    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_cx");
  ops_dat h_ay    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_ay");
  ops_dat h_by    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_by");
  ops_dat h_cy    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_cy");
  ops_dat h_az    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_az");
  ops_dat h_bz    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_bz");
  ops_dat h_cz    = ops_decl_dat(heat3D, 1, size, base, d_m, d_p, temp, "double", "h_cz");

  int s3D_000[]         = {0,0,0};
  ops_stencil S3D_000 = ops_decl_stencil( 3, 1, s3D_000, "000");

  int s3D_7pt[] = { 0,0,0, -1,0,0, 1,0,0, 0,-1,0, 0,1,0, 0,0,-1, 0,0,1 };
  ops_stencil S3D_7PT = ops_decl_stencil( 3, 7, s3D_7pt, "3d7Point");

  ops_decl_const2( "nx",1, "int",&nx);
  ops_decl_const2( "ny",1, "int",&ny);
  ops_decl_const2( "nz",1, "int",&nz);
  ops_decl_const2( "lambda",1, "double",&lambda);

  ops_reduction rms = ops_decl_reduction_handle(sizeof(double), "double", "rms");

  ops_partition("3D_BLOCK_DECOMPSE");

  double ct0, ct1, et0, et1, ct2, et2, ct3, et3;

  printf("\nGrid dimensions: %d x %d x %d\n", nx, ny, nz);
  ops_diagnostic_output();

  ops_initTridMultiDimBatchSolve(3 , size );

  int iter_range[] = {0,nx, 0,ny, 0,nz};
  ops_par_loop_init_kernel("init_kernel", heat3D, 3, iter_range,
               ops_arg_dat(h_u, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_idx());

  ops_timers(&ct0, &et0);

  for(int it = 0; it<iter; it++) {

  int iter_range[] = {0,nx, 0,ny, 0,nz};

  ops_timers(&ct2, &et2);
  ops_par_loop_preproc_kernel("preproc_kernel", heat3D, 3, iter_range,
               ops_arg_dat(h_u, 1, S3D_7PT, "double", OPS_READ),
               ops_arg_dat(h_du, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_ax, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_bx, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_cx, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_ay, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_by, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_cy, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_az, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_bz, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(h_cz, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_idx());
  ops_timers(&ct3, &et3);
  ops_printf("Elapsed preproc (sec): %lf (s)\n",et3-et2);

  double rms_value = 0.0;
  ops_par_loop_rms_kernel("rms_kernel", heat3D, 3, iter_range,
               ops_arg_dat(h_du, 1, S3D_000, "double", OPS_READ),
               ops_arg_reduce(rms, 1, "double", OPS_INC));

  ops_reduction_result(rms,&rms_value);
  ops_printf("Value %lg\n",rms_value);

  exit(-2);

  ops_timers(&ct2, &et2);
  ops_tridMultiDimBatch( 3, 0 , size, h_ax, h_bx, h_cx, h_du, h_u, opts);
  ops_timers(&ct3, &et3);
  ops_printf("Elapsed trid_x (sec): %lf (s)\n",et3-et2);



  ops_timers(&ct2, &et2);
  ops_tridMultiDimBatch( 3, 1 , size, h_ay, h_by, h_cy, h_du, h_u, opts );
  ops_timers(&ct3, &et3);
  ops_printf("Elapsed trid_y (sec): %lf (s)\n",et3-et2);

  ops_timers(&ct2, &et2);
  ops_tridMultiDimBatch_Inc( 3, 2 , size, h_az, h_bz, h_cz, h_du, h_u, opts );
  ops_timers(&ct3, &et3);
  ops_printf("Elapsed trid_z (sec): %lf (s)\n",et3-et2);

  }

  ops_timers(&ct1, &et1);


  ops_print_dat_to_txtfile(h_u, "h_u.dat");


  for(int k=0; k<2; k++) {
    printf("k = %i\n",k);
    for(int j=0; j<MIN(ny,17); j++) {
      printf(" %d   ", j);
      for(int i=0; i<MIN(nx,17); i++) {
        int ind = i + j*nx + k*nx*ny;
        printf(" %5.5g ", ((double *)h_u->data)[ind]);
      }
      printf("\n");
    }
    printf("\n");
  }

  for(int k=0; k<2; k++) {
    printf("k = %i\n",k);
    for(int j=0; j<MIN(ny,17); j++) {
      printf(" %d   ", j);
      for(int i=MAX(0,nx-17); i<nx; i++) {
        int ind = i + j*nx + k*nx*ny;
        printf(" %5.5g ", ((double *)h_u->data)[ind]);
      }
      printf("\n");
    }
    printf("\n");
  }

  ops_printf("\nTotal Wall time %lf\n",et1-et0);
  ops_exit();
}