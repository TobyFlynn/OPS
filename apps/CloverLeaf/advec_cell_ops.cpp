//
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
// auto-generated by ops.py on 2014-06-17 17:28
=======
// auto-generated by ops.py on 2014-05-08 10:28
>>>>>>> 03fb03d... viscosity kernel running with opencl
=======
// auto-generated by ops.py on 2014-05-12 13:11
>>>>>>> 01b5ecc... Generating OpenCL master kernels file
=======
// auto-generated by ops.py on 2014-05-13 14:48
>>>>>>> 45be066... addign advec_mom to OpenCL
=======
// auto-generated by ops.py on 2014-05-14 16:53
>>>>>>> fcc5de7... Attempting to upload global constants, but these need to be uploaded every time
=======
// auto-generated by ops.py on 2014-05-15 16:54
>>>>>>> 2eff219... Added advec_cell kernel to OpenCL with ability to pass constants to device
=======
// auto-generated by ops.py on 2014-05-15 16:56
>>>>>>> 7f143a4... working OpenCL with all non-reduction kernels and without Update halo
=======
// auto-generated by ops.py on 2014-05-15 17:08
>>>>>>> ceca208... Attempting to setup update halo kernel to OpenCL .. need to fix reductions
=======
// auto-generated by ops.py on 2014-05-28 15:13
>>>>>>> 033d7a0... Attempting to add calc_dt global reductions to OpenCL
=======
// auto-generated by ops.py on 2014-06-02 12:10
>>>>>>> ad432fc... Code generating global reductions
=======
// auto-generated by ops.py on 2014-06-02 12:26
>>>>>>> aee5038... Codegen working for reductions except for the __global key word issue in user kernel
=======
// auto-generated by ops.py on 2014-06-02 14:07
>>>>>>> 24690b8... Fixed user kernel parsing for __global
=======
// auto-generated by ops.py on 2014-06-02 16:13
>>>>>>> 496889f... Adding update halo kernel to Opencl - performance had gotten worse
=======
// auto-generated by ops.py on 2014-06-03 12:34
>>>>>>> ea30500... Setting up compilation that works for both CPUs and NVIDIA GPUs
=======
// auto-generated by ops.py on 2014-06-03 13:36
>>>>>>> 16b8dff... Fixing parse error in user kernel argument parsing
=======
// auto-generated by ops.py on 2014-06-03 14:49
>>>>>>> 4eb6712... Code generating initialize_chunk and generate .. but structs not working
=======
// auto-generated by ops.py on 2014-06-05 11:30
>>>>>>> a794738... Reverting to working version of OpenCL
=======
// auto-generated by ops.py on 2014-06-05 12:48
>>>>>>> 6ba9c42... OpenCL broken after rebase
=======
// auto-generated by ops.py on 2014-06-05 13:01
>>>>>>> a7f01b0... Still attempting to debug
//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_advec_cell_kernel1_xdir(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel2_xdir(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel3_xdir(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel4_xdir(char const *, ops_block, int , int*,
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

void ops_par_loop_advec_cell_kernel1_ydir(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel2_ydir(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel3_ydir(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel4_ydir(char const *, ops_block, int , int*,
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



#include "data.h"
#include "definitions.h"
//#include "advec_cell_kernel.h"


void advec_cell(int sweep_number, int dir)
{

  int x_cells = grid.x_cells;
  int y_cells = grid.y_cells;
  int x_min = field.x_min;
  int x_max = field.x_max;
  int y_min = field.y_min;
  int y_max = field.y_max;

  int rangexy[] = {x_min-2,x_max+2,y_min-2,y_max+2};
  int rangexy_inner[] = {x_min,x_max,y_min,y_max};

  int rangexy_inner_plus2x[] = {x_min,x_max+2,y_min,y_max};
  int rangexy_inner_plus2y[] = {x_min,x_max,y_min,y_max+2};


  if(dir == g_xdir) {

    if(sweep_number == 1) {
      ops_par_loop_advec_cell_kernel1_xdir("advec_cell_kernel1_xdir", clover_grid, 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                   ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));
    }
    else {
      ops_par_loop_advec_cell_kernel2_xdir("advec_cell_kernel2_xdir", clover_grid, 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ));
    }

    ops_par_loop_advec_cell_kernel3_xdir("advec_cell_kernel3_xdir", clover_grid, 2, rangexy_inner_plus2x,
                 ops_arg_dat(vol_flux_x, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00_P10_M10_M20, "double", OPS_READ),
                 ops_arg_dat(xx, S2D_00_P10_STRID2D_X, "int", OPS_READ),
                 ops_arg_dat(vertexdx, S2D_00_P10_M10_M20_STRID2D_X, "double", OPS_READ),
                 ops_arg_dat(density1, S2D_00_P10_M10_M20, "double", OPS_READ),
                 ops_arg_dat(energy1, S2D_00_P10_M10_M20, "double", OPS_READ),
                 ops_arg_dat(mass_flux_x, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE));

    ops_par_loop_advec_cell_kernel4_xdir("advec_cell_kernel4_xdir", clover_grid, 2, rangexy_inner,
                 ops_arg_dat(density1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(energy1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(mass_flux_x, S2D_00_P10, "double", OPS_READ),
                 ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array4, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array5, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00_P10, "double", OPS_READ));

  }
  else {


    if(sweep_number == 1) {
      ops_par_loop_advec_cell_kernel1_ydir("advec_cell_kernel1_ydir", clover_grid, 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                   ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));
    }
    else {

      ops_par_loop_advec_cell_kernel2_ydir("advec_cell_kernel2_ydir", clover_grid, 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));

  }

    ops_par_loop_advec_cell_kernel3_ydir("advec_cell_kernel3_ydir", clover_grid, 2, rangexy_inner_plus2y,
                 ops_arg_dat(vol_flux_y, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00_0P1_0M1_0M2, "double", OPS_READ),
                 ops_arg_dat(yy, S2D_00_0P1_STRID2D_Y, "int", OPS_READ),
                 ops_arg_dat(vertexdy, S2D_00_0P1_0M1_0M2_STRID2D_Y, "double", OPS_READ),
                 ops_arg_dat(density1, S2D_00_0P1_0M1_0M2, "double", OPS_READ),
                 ops_arg_dat(energy1, S2D_00_0P1_0M1_0M2, "double", OPS_READ),
                 ops_arg_dat(mass_flux_y, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE));

    ops_par_loop_advec_cell_kernel4_ydir("advec_cell_kernel4_ydir", clover_grid, 2, rangexy_inner,
                 ops_arg_dat(density1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(energy1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(mass_flux_y, S2D_00_0P1, "double", OPS_READ),
                 ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array4, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array5, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00_0P1, "double", OPS_READ));

  }

}
