//
// auto-generated by ops.py
//

int xdim0_advec_cell_kernel3_xdir;
int xdim1_advec_cell_kernel3_xdir;
int xdim2_advec_cell_kernel3_xdir;
int xdim3_advec_cell_kernel3_xdir;
int xdim4_advec_cell_kernel3_xdir;
int xdim5_advec_cell_kernel3_xdir;
int xdim6_advec_cell_kernel3_xdir;
int xdim7_advec_cell_kernel3_xdir;


//user function



void advec_cell_kernel3_xdir_c_wrapper(
  double * restrict vol_flux_x_p,
  double * restrict pre_vol_p,
  int * restrict xx_p,
  double * restrict vertexdx_p,
  double * restrict density1_p,
  double * restrict energy1_p,
  double * restrict mass_flux_x_p,
  double * restrict ener_flux_p,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      const ptr_double vol_flux_x = { vol_flux_x_p + n_x*1 + n_y * xdim0_advec_cell_kernel3_xdir*1, xdim0_advec_cell_kernel3_xdir};
      const ptr_double pre_vol = { pre_vol_p + n_x*1 + n_y * xdim1_advec_cell_kernel3_xdir*1, xdim1_advec_cell_kernel3_xdir};
      const ptr_int xx = { xx_p + n_x*1 + n_y * xdim2_advec_cell_kernel3_xdir*0, xdim2_advec_cell_kernel3_xdir};
      const ptr_double vertexdx = { vertexdx_p + n_x*1 + n_y * xdim3_advec_cell_kernel3_xdir*0, xdim3_advec_cell_kernel3_xdir};
      const ptr_double density1 = { density1_p + n_x*1 + n_y * xdim4_advec_cell_kernel3_xdir*1, xdim4_advec_cell_kernel3_xdir};
      const ptr_double energy1 = { energy1_p + n_x*1 + n_y * xdim5_advec_cell_kernel3_xdir*1, xdim5_advec_cell_kernel3_xdir};
      ptr_double mass_flux_x = { mass_flux_x_p + n_x*1 + n_y * xdim6_advec_cell_kernel3_xdir*1, xdim6_advec_cell_kernel3_xdir};
      ptr_double ener_flux = { ener_flux_p + n_x*1 + n_y * xdim7_advec_cell_kernel3_xdir*1, xdim7_advec_cell_kernel3_xdir};
      

  double sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int x_max=field.x_max;

  int upwind,donor,downwind,dif;





  if(OPS_ACC(vol_flux_x, 0,0) > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (OPS_ACC(xx, 1,0) < x_max+2-2) {
    upwind   = 1;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  } else {
    upwind   = 0;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  }


  sigmat = fabs(OPS_ACC(vol_flux_x, 0,0))/OPS_ACC(pre_vol, donor,0);
  sigma3 = (1.0 + sigmat)*(OPS_ACC(vertexdx, 0,0)/OPS_ACC(vertexdx, dif,0));
  sigma4 = 2.0 - sigmat;

  sigmav = sigmat;

  diffuw = OPS_ACC(density1, donor,0) - OPS_ACC(density1, upwind,0);
  diffdw = OPS_ACC(density1, downwind,0) - OPS_ACC(density1, donor,0);

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  OPS_ACC(mass_flux_x, 0,0) = (OPS_ACC(vol_flux_x, 0,0)) * ( OPS_ACC(density1, donor,0) + limiter );

  sigmam = fabs(OPS_ACC(mass_flux_x, 0,0))/( OPS_ACC(density1, donor,0) * OPS_ACC(pre_vol, donor,0));
  diffuw = OPS_ACC(energy1, donor,0) - OPS_ACC(energy1, upwind,0);
  diffdw = OPS_ACC(energy1, downwind,0) - OPS_ACC(energy1, donor,0);

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  OPS_ACC(ener_flux, 0,0) = OPS_ACC(mass_flux_x, 0,0) * ( OPS_ACC(energy1, donor,0) + limiter );

    }
  }
}
