#ifndef ADVEC_MOM_KERNEL_H
#define ADVEC_MOM_KERNEL_H

void advec_mom_kernel_x1( double **pre_vol, double **post_vol,
                          double **volume,
                          double **vol_flux_x, double **vol_flux_y) {

  //vol_flux_y accessed with : 0,0, 1,0
  //vol_flux_y accessed with : 0,0, 0,1

  **post_vol = **volume + (*vol_flux_y[1]) - (*vol_flux_y[0]);
  **pre_vol = **post_vol + (*vol_flux_x[1]) - (*vol_flux_x[0]);

}

void advec_mom_kernel_y1( double **pre_vol, double **post_vol,
                          double **volume,
                          double **vol_flux_x, double **vol_flux_y) {

  //vol_flux_y accessed with : 0,0, 1,0
  //vol_flux_y accessed with : 0,0, 0,1

  **post_vol = **volume + (*vol_flux_x[1]) - (*vol_flux_x[0]);
  **pre_vol  = **post_vol + (*vol_flux_y[1]) - (*vol_flux_y[0]);

}

void advec_mom_kernel_x2( double **pre_vol, double **post_vol,
                          double **volume,
                          double **vol_flux_y) {

  //vol_flux_y accessed with : 0,0, 0,1

  **post_vol = **volume;
  **pre_vol  = **post_vol + (*vol_flux_y[1]) - (*vol_flux_y[0]);

}

void advec_mom_kernel_y2( double **pre_vol, double **post_vol,
                          double **volume,
                          double **vol_flux_x) {

//vol_flux_x accessed with : {0,0, 1,0}

  **post_vol = **volume;
  **pre_vol  = **post_vol + (*vol_flux_x[1]) - (*vol_flux_x[0]);

}


void advec_mom_kernel_mass_flux_x( double **node_flux, double **mass_flux_x) {

  //mass_flux_x accessed with: {0,0, 1,0, 0,-1, 1,-1}

  **node_flux = 0.25 * ( (*mass_flux_x[2]) + (*mass_flux_x[0]) +
    (*mass_flux_x[3]) + (*mass_flux_x[1])); // Mass Flux in x
}
void advec_mom_kernel_mass_flux_y( double **node_flux, double **mass_flux_y) {

  //mass_flux_y accessed with: {0,0, 0,1, -1,0, -1,1}

  **node_flux = 0.25 * ( (*mass_flux_y[2]) + (*mass_flux_y[0]) +
      (*mass_flux_y[3]) + (*mass_flux_y[1]) ); // Mass Flux in y
}





void advec_mom_kernel_post_advec_x( double **node_mass_post, double **post_vol,
                                  double **density1) {

  //post_vol accessed with: {0,0, -1,0, 0,-1, -1,-1}
  //density1 accessed with: {0,0, -1,0, 0,-1, -1,-1}

  **node_mass_post = 0.25 * ( (*density1[2]) * (*post_vol[2]) +
                              (*density1[0]) * (*post_vol[0]) +
                              (*density1[3]) * (*post_vol[3]) +
                              (*density1[1]) * (*post_vol[1]) );

}

//this is the same as advec_mom_kernel_post_advec_x ... just repeated here for debugging
void advec_mom_kernel_post_advec_y( double **node_mass_post, double **post_vol,
                                  double **density1) {

  //post_vol accessed with: {0,0, -1,0, 0,-1, -1,-1}
  //density1 accessed with: {0,0, -1,0, 0,-1, -1,-1}

  **node_mass_post = 0.25 * ( (*density1[2]) * (*post_vol[2]) +
                              (*density1[0]) * (*post_vol[0]) +
                              (*density1[3]) * (*post_vol[3]) +
                              (*density1[1]) * (*post_vol[1]) );

}


void advec_mom_kernel_pre_advec_x( double **node_mass_pre, double **node_mass_post,
                                  double **node_flux) {

  //node_flux accessed with: {0,0, -1,0}
  **node_mass_pre = (**node_mass_post) - (*node_flux[1]) + (*node_flux[0]);

}
void advec_mom_kernel_pre_advec_y( double **node_mass_pre, double **node_mass_post,
                                  double **node_flux) {

  //node_flux accessed with: {0,0, 0,-1}
  **node_mass_pre = (**node_mass_post) - (*node_flux[1]) + (*node_flux[0]);

}


void advec_mom_kernel1_x( double **node_flux, double **node_mass_pre,
                        double **advec_vel, double **mom_flux,
                        double **celldx, double **vel1) {

  //node_flux accessed with: {0,0}
  //node_mass_pre accessed with: {0,0, 1,0}
  //celldx is accessed with {0,0, 1,0, -1,0, -2,0} striding in x
  //vel1 is accessed with {0,0, 1,0, 2,0, -1,0}

  double sigma, wind, width;
  double sigma2, wind2;
  double vdiffuw, vdiffdw, auw, adw, limiter;
  double vdiffuw2, vdiffdw2, auw2, limiter2;

  sigma = fabs(**node_flux)/(*node_mass_pre[1]);
  sigma2 = fabs(**node_flux)/(*node_mass_pre[0]);

  width = *celldx[0];
  vdiffuw = (*vel1[1]) - (*vel1[2]);
  vdiffdw = (*vel1[0]) - (*vel1[1]);
  vdiffuw2 = (*vel1[0]) - (*vel1[3]);
  vdiffdw2 = -vdiffdw;

  auw = fabs(vdiffuw);
  adw = fabs(vdiffdw);
  auw2 = fabs(vdiffuw2);
  wind = 1.0;
  wind2 = 1.0;

  if(vdiffdw <= 0.0) wind = -1.0;
  if(vdiffdw2 <= 0.0) wind2 = -1.0;

  limiter = wind * MIN( width * ( (2.0 - sigma) * adw/width + (1.0 + sigma) *
                        auw/(*celldx[1]) )/6.0 , MIN(auw, adw) );
  limiter2= wind2* MIN( width * ( (2.0 - sigma2) * adw/width + (1.0 + sigma2) *
                        auw2/(*celldx[2]) )/6.0, MIN(auw2,adw) );

  if((vdiffuw * vdiffdw) <= 0.0) limiter = 0.0;
  if((vdiffuw2 * vdiffdw2) <= 0.0) limiter2 = 0.0;

  if( (**node_flux) < 0.0) {
    **advec_vel = (*vel1[1]) + (1.0 - sigma) * limiter;
  }
  else {
    **advec_vel = (*vel1[0]) + (1.0 - sigma2) * limiter2;
  }

  **mom_flux = (**advec_vel) * (**node_flux);

}

void advec_mom_kernel1_y( double **node_flux, double **node_mass_pre,
                        double **advec_vel, double **mom_flux,
                        double **celldy, double **vel1) {

  //node_flux accessed with: {0,0}
  //node_mass_pre accessed with: {0,0, 0,1}
  //celldy is accessed with {0,0, 0,1, 0,-1, 0,-2} striding in y
  //vel1 is accessed with {0,0, 0,1, 0,2, 0,-1}

  double sigma, wind, width;
  double sigma2, wind2;
  double vdiffuw, vdiffdw, auw, adw, limiter;
  double vdiffuw2, vdiffdw2, auw2, limiter2;

  sigma = fabs(*node_flux[0])/(*node_mass_pre[1]);
  sigma2 = fabs(*node_flux[0])/(*node_mass_pre[0]);

  //printf("sigma %3.15e, sigma2, %3.15e ",sigma, sigma2);
  //printf("*node_flux[0] %3.15e, *node_mass_pre[0], %3.15e\n",*node_flux[0], *node_mass_pre[0]);

  width = *celldy[0];
  vdiffuw = (*vel1[1]) - (*vel1[2]);
  vdiffdw = (*vel1[0]) - (*vel1[1]);
  vdiffuw2 = (*vel1[0])- (*vel1[3]);
  vdiffdw2 = -vdiffdw;
  auw = fabs(vdiffuw);
  adw = fabs(vdiffdw);
  auw2 = fabs(vdiffuw2);
  wind = 1.0;
  wind2 = 1.0;

  if(vdiffdw <= 0.0) wind = -1.0;
  if(vdiffdw2 <= 0.0) wind2 = -1.0;

  limiter = wind * MIN( width * ( (2.0 - sigma) * adw/width + (1.0 + sigma) *
                        auw/(*celldy[1]))/6.0, MIN(auw, adw));
  limiter2 = wind2 * MIN( width * ( (2.0 - sigma2) * adw/width + (1.0 + sigma2) *
                        auw2/(*celldy[2]))/6.0, MIN(auw2,adw));

  //printf("limiter %3.15e, limiter2, %3.15e\n",limiter, limiter2);
  //printf("vdiffdw %3.15e, vdiffdw2, %3.15e\n",vdiffdw, vdiffdw2);


  if((vdiffuw * vdiffdw) <= 0.0) limiter = 0.0;
  if((vdiffuw2 * vdiffdw2) <= 0.0) limiter2 = 0.0;

  if( (**node_flux) < 0.0)
    **advec_vel = (*vel1[1]) + (1.0 - sigma) * limiter;
  else
    **advec_vel = (*vel1[0]) + (1.0 - sigma2) * limiter2;

  **mom_flux = (**advec_vel) * (**node_flux);
}

void advec_mom_kernel2_x( double **vel1, double **node_mass_post,
                        double **node_mass_pre, double **mom_flux) {

  //mom_flux accessed with: {0,0, -1,0}
  **vel1 = ( (**vel1) * (**node_mass_pre)  + (*mom_flux[1]) - (*mom_flux[0]) ) / (**node_mass_post);

}


void advec_mom_kernel2_y( double **vel1, double **node_mass_post,
                        double **node_mass_pre, double **mom_flux) {

  //mom_flux accessed with: {0,0, 0,-1}
  **vel1 = ( (**vel1) * (**node_mass_pre)  + (*mom_flux[1]) - (*mom_flux[0]) ) / (**node_mass_post);
}



#endif