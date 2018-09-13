//
// auto-generated by ops.py
//

#include "./MPI_inline/clover_leaf_common.h"
//user kernel files
#include "PdV_kernel_nopredict_mpiinline_kernel_c.c"
#include "PdV_kernel_predict_mpiinline_kernel_c.c"
#include "accelerate_kernel_mpiinline_kernel_c.c"
#include "advec_cell_kernel1_xdir_mpiinline_kernel_c.c"
#include "advec_cell_kernel1_ydir_mpiinline_kernel_c.c"
#include "advec_cell_kernel2_xdir_mpiinline_kernel_c.c"
#include "advec_cell_kernel2_ydir_mpiinline_kernel_c.c"
#include "advec_cell_kernel3_xdir_mpiinline_kernel_c.c"
#include "advec_cell_kernel3_ydir_mpiinline_kernel_c.c"
#include "advec_cell_kernel4_xdir_mpiinline_kernel_c.c"
#include "advec_cell_kernel4_ydir_mpiinline_kernel_c.c"
#include "advec_mom_kernel1_x_nonvector_mpiinline_kernel_c.c"
#include "advec_mom_kernel1_y_nonvector_mpiinline_kernel_c.c"
#include "advec_mom_kernel2_x_mpiinline_kernel_c.c"
#include "advec_mom_kernel2_y_mpiinline_kernel_c.c"
#include "advec_mom_kernel_mass_flux_x_mpiinline_kernel_c.c"
#include "advec_mom_kernel_mass_flux_y_mpiinline_kernel_c.c"
#include "advec_mom_kernel_post_pre_advec_x_mpiinline_kernel_c.c"
#include "advec_mom_kernel_post_pre_advec_y_mpiinline_kernel_c.c"
#include "advec_mom_kernel_x1_mpiinline_kernel_c.c"
#include "advec_mom_kernel_x2_mpiinline_kernel_c.c"
#include "advec_mom_kernel_y1_mpiinline_kernel_c.c"
#include "advec_mom_kernel_y2_mpiinline_kernel_c.c"
#include "calc_dt_kernel_get_mpiinline_kernel_c.c"
#include "calc_dt_kernel_min_mpiinline_kernel_c.c"
#include "calc_dt_kernel_mpiinline_kernel_c.c"
#include "calc_dt_kernel_print_mpiinline_kernel_c.c"
#include "field_summary_kernel_mpiinline_kernel_c.c"
#include "flux_calc_kernelx_mpiinline_kernel_c.c"
#include "flux_calc_kernely_mpiinline_kernel_c.c"
#include "generate_chunk_kernel_mpiinline_kernel_c.c"
#include "ideal_gas_kernel_mpiinline_kernel_c.c"
#include "initialise_chunk_kernel_cellx_mpiinline_kernel_c.c"
#include "initialise_chunk_kernel_celly_mpiinline_kernel_c.c"
#include "initialise_chunk_kernel_volume_mpiinline_kernel_c.c"
#include "initialise_chunk_kernel_x_mpiinline_kernel_c.c"
#include "initialise_chunk_kernel_xx_mpiinline_kernel_c.c"
#include "initialise_chunk_kernel_y_mpiinline_kernel_c.c"
#include "initialise_chunk_kernel_yy_mpiinline_kernel_c.c"
#include "reset_field_kernel1_mpiinline_kernel_c.c"
#include "reset_field_kernel2_mpiinline_kernel_c.c"
#include "revert_kernel_mpiinline_kernel_c.c"
#include "update_halo_kernel1_b1_mpiinline_kernel_c.c"
#include "update_halo_kernel1_b2_mpiinline_kernel_c.c"
#include "update_halo_kernel1_l1_mpiinline_kernel_c.c"
#include "update_halo_kernel1_l2_mpiinline_kernel_c.c"
#include "update_halo_kernel1_r1_mpiinline_kernel_c.c"
#include "update_halo_kernel1_r2_mpiinline_kernel_c.c"
#include "update_halo_kernel1_t1_mpiinline_kernel_c.c"
#include "update_halo_kernel1_t2_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_4_b_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_4_b_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_4_b_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_4_b_mpiinline_kernel_c.c"
#include "update_halo_kernel3_minus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel3_minus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel3_minus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel3_minus_4_b_mpiinline_kernel_c.c"
#include "update_halo_kernel3_plus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel3_plus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel3_plus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel3_plus_4_b_mpiinline_kernel_c.c"
#include "update_halo_kernel4_minus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel4_minus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel4_minus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel4_minus_4_b_mpiinline_kernel_c.c"
#include "update_halo_kernel4_plus_2_a_mpiinline_kernel_c.c"
#include "update_halo_kernel4_plus_2_b_mpiinline_kernel_c.c"
#include "update_halo_kernel4_plus_4_a_mpiinline_kernel_c.c"
#include "update_halo_kernel4_plus_4_b_mpiinline_kernel_c.c"
#include "viscosity_kernel_mpiinline_kernel_c.c"
