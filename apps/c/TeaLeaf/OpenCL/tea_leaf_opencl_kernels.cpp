//
// auto-generated by ops.py//

//header
#define OPS_ACC_MD_MACROS
#define OPS_2D
#include "stdlib.h"
#include "stdio.h"
#include "ops_lib_cpp.h"
#include "ops_opencl_rt_support.h"
#include "user_types.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
//global constants
extern field_type field;
extern grid_type grid;
extern int number_of_states;
extern state_type *states;
extern int g_circ;
extern int g_point;
extern int g_rect;

extern ops_opencl_core OPS_opencl_core;

void ops_init_backend() {}

//this needs to be a platform specific copy symbol to device function
void ops_decl_const_char( int dim, char const * type, int typeSize, char * dat, char const * name ) {
  cl_int ret = 0;
  if (OPS_opencl_core.constant == NULL) {
    OPS_opencl_core.constant = (cl_mem*) malloc((7)*sizeof(cl_mem));
    for ( int i=0; i<7; i++ ){
      OPS_opencl_core.constant[i] = NULL;
    }
  }
  if (!strcmp(name,"field")) {
    if (OPS_opencl_core.constant[0] == NULL) {
      OPS_opencl_core.constant[0] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[0], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"grid")) {
    if (OPS_opencl_core.constant[1] == NULL) {
      OPS_opencl_core.constant[1] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[1], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"number_of_states")) {
    if (OPS_opencl_core.constant[2] == NULL) {
      OPS_opencl_core.constant[2] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[2], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"states")) {
    if (OPS_opencl_core.constant[3] == NULL) {
      OPS_opencl_core.constant[3] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[3], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"g_circ")) {
    if (OPS_opencl_core.constant[4] == NULL) {
      OPS_opencl_core.constant[4] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[4], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"g_point")) {
    if (OPS_opencl_core.constant[5] == NULL) {
      OPS_opencl_core.constant[5] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[5], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"g_rect")) {
    if (OPS_opencl_core.constant[6] == NULL) {
      OPS_opencl_core.constant[6] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[6], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  {
    printf("error: unknown const name\n"); exit(1);
  }
}

extern ops_opencl_core OPS_opencl_core;

void buildOpenCLKernels() {
  static bool isbuilt = false;

  if(!isbuilt) {
    //clSafeCall( clUnloadCompiler() );

    OPS_opencl_core.n_kernels = 57;
    OPS_opencl_core.kernel = (cl_kernel*) malloc(57*sizeof(cl_kernel));
  }
  isbuilt = true;
}

//user kernel files
#include "tea_leaf_init_zero2_kernel_opencl_kernel.cpp"
#include "set_field_kernel_opencl_kernel.cpp"
#include "tea_leaf_jacobi_kernel_opencl_kernel.cpp"
#include "tea_leaf_common_init_kernel_opencl_kernel.cpp"
#include "tea_leaf_ppcg_reduce_kernel_opencl_kernel.cpp"
#include "tea_leaf_cg_calc_w_reduce_kernel_opencl_kernel.cpp"
#include "tea_leaf_yeqx_kernel_opencl_kernel.cpp"
#include "update_halo_kernel1_r1_opencl_kernel.cpp"
#include "update_halo_kernel1_r2_opencl_kernel.cpp"
#include "tea_leaf_recip3_kernel_opencl_kernel.cpp"
#include "tea_leaf_recip_kernel_opencl_kernel.cpp"
#include "update_halo_kernel1_l2_opencl_kernel.cpp"
#include "tea_leaf_common_init_u_u0_kernel_opencl_kernel.cpp"
#include "tea_leaf_zeqxty_kernel_opencl_kernel.cpp"
#include "tea_leaf_axpy_kernel_opencl_kernel.cpp"
#include "tea_leaf_ppcg_init2_kernel_opencl_kernel.cpp"
#include "tea_leaf_ppcg_inner1_kernel_opencl_kernel.cpp"
#include "update_halo_kernel1_b1_opencl_kernel.cpp"
#include "update_halo_kernel1_b2_opencl_kernel.cpp"
#include "field_summary_kernel_opencl_kernel.cpp"
#include "tea_leaf_common_residual_kernel_opencl_kernel.cpp"
#include "tea_leaf_cg_calc_ur_r_reduce_kernel_opencl_kernel.cpp"
#include "tea_leaf_norm2_kernel_opencl_kernel.cpp"
#include "tea_leaf_common_init_Kx_Ky_kernel_opencl_kernel.cpp"
#include "tea_leaf_axpby_kernel_opencl_kernel.cpp"
#include "tea_leaf_dot_kernel_opencl_kernel.cpp"
#include "tea_leaf_init_zero_kernel_opencl_kernel.cpp"
#include "update_halo_kernel1_t2_opencl_kernel.cpp"
#include "tea_leaf_recip2_kernel_opencl_kernel.cpp"
#include "tea_leaf_ppcg_inner2_kernel_opencl_kernel.cpp"
#include "update_halo_kernel1_t1_opencl_kernel.cpp"
#include "tea_leaf_common_init_diag_init_kernel_opencl_kernel.cpp"
#include "tea_leaf_ppcg_init1_kernel_opencl_kernel.cpp"
#include "tea_leaf_xpy_kernel_opencl_kernel.cpp"
#include "update_halo_kernel1_l1_opencl_kernel.cpp"
#include "tea_leaf_cheby_init_kernel_opencl_kernel.cpp"
