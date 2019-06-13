//
// auto-generated by ops.py
//

#define OPS_3D
void ops_init_backend();
#include "ops_lib_cpp.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char **argv) {

  ops_init(argc, argv, 5);
  ops_init_backend();
  ops_printf("Hello world from OPS!\n\n");

  ops_block block = ops_decl_block_hdf5(3, "grid0", "write_data.h5");

  ops_dat single =
      ops_decl_dat_hdf5(block, 1, "double", "single", "write_data.h5");
  ops_dat multi =
      ops_decl_dat_hdf5(block, 2, "double", "multi", "write_data.h5");
  ops_dat integ = ops_decl_dat_hdf5(block, 1, "int", "integ", "write_data.h5");

  ops_partition("empty_string_that_does_nothing_yet");
  ops_diagnostic_output();

  ops_fetch_block_hdf5_file(block, "read_data.h5");
  ops_fetch_dat_hdf5_file(multi, "read_data.h5");
  ops_fetch_dat_hdf5_file(single, "read_data.h5");
  ops_fetch_dat_hdf5_file(integ, "read_data.h5");

  int my_const;
  ops_get_const_hdf5("my_const", 1, "int", (char *)&my_const, "write_data.h5");
  printf("Read const: %d\n", my_const);

  char buffer[50];
  ops_get_const_hdf5("my_text", 11, "char", buffer, "write_data.h5");
  printf("Read text: %s\n", buffer);

  ops_write_const_hdf5("my_const", 1, "int", (char *)&my_const, "read_data.h5");
  ops_write_const_hdf5("my_text", 11, "char", (char *)buffer, "read_data.h5");

  ops_timing_output(stdout);
  ops_printf("\nSucessful exit from OPS!\n");
  ops_exit();
}
