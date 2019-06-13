//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel3_plus_2_back;
int ydim0_update_halo_kernel3_plus_2_back;
int xdim1_update_halo_kernel3_plus_2_back;
int ydim1_update_halo_kernel3_plus_2_back;


#define OPS_ACC0(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_update_halo_kernel3_plus_2_back + (n_z*1+(z))*xdim0_update_halo_kernel3_plus_2_back*ydim0_update_halo_kernel3_plus_2_back)
#define OPS_ACC1(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim1_update_halo_kernel3_plus_2_back + (n_z*1+(z))*xdim1_update_halo_kernel3_plus_2_back*ydim1_update_halo_kernel3_plus_2_back)
//user function



void update_halo_kernel3_plus_2_back_c_wrapper(
  double * restrict vol_flux_x,
  double * restrict mass_flux_x,
  const int * restrict fields,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        
  if(fields[FIELD_VOL_FLUX_X] == 1)  vol_flux_x[OPS_ACC0(0,0,0)]  = vol_flux_x[OPS_ACC0(0,0,2)];
  if(fields[FIELD_MASS_FLUX_X] == 1) mass_flux_x[OPS_ACC1(0,0,0)] = mass_flux_x[OPS_ACC1(0,0,2)];

      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1

