//
// auto-generated by ops.py//

// header
#define OPS_2D
#define OPS_ACC_MD_MACROS
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// set max number of OMP threads for reductions
#ifndef MAX_REDUCT_THREADS
#define MAX_REDUCT_THREADS 64
#endif
// global constants

void ops_init_backend() {}

// user kernel files
#include "mgrid_populate_kernel_1_omp_kernel.cpp"
#include "mgrid_populate_kernel_3_omp_kernel.cpp"
#include "mgrid_prolong_kernel_omp_kernel.cpp"
#include "mgrid_restrict_kernel_omp_kernel.cpp"
#include "prolong_check_omp_kernel.cpp"
#include "restrict_check_omp_kernel.cpp"
