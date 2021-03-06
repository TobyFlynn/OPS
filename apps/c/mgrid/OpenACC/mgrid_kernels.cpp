//
// auto-generated by ops.py//

#include "./OpenACC/mgrid_common.h"

#include <openacc.h>

void ops_init_backend() {acc_set_device_num(ops_get_proc()%acc_get_num_devices(acc_device_nvidia),acc_device_nvidia); }

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  ops_execute(OPS_instance::getOPSInstance());
  {
    throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");
  }
}

//user kernel files
#include "mgrid_populate_kernel_1_openacc_kernel.cpp"
#include "mgrid_prolong_kernel_openacc_kernel.cpp"
#include "prolong_check_openacc_kernel.cpp"
#include "mgrid_populate_kernel_3_openacc_kernel.cpp"
#include "mgrid_restrict_kernel_openacc_kernel.cpp"
#include "restrict_check_openacc_kernel.cpp"
