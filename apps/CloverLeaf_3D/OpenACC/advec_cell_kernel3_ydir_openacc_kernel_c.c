//
// auto-generated by ops.py
//
#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_advec_cell_kernel3_ydir;
int ydim0_advec_cell_kernel3_ydir;
int xdim1_advec_cell_kernel3_ydir;
int ydim1_advec_cell_kernel3_ydir;
int xdim2_advec_cell_kernel3_ydir;
int ydim2_advec_cell_kernel3_ydir;
int xdim3_advec_cell_kernel3_ydir;
int ydim3_advec_cell_kernel3_ydir;
int xdim4_advec_cell_kernel3_ydir;
int ydim4_advec_cell_kernel3_ydir;
int xdim5_advec_cell_kernel3_ydir;
int ydim5_advec_cell_kernel3_ydir;
int xdim6_advec_cell_kernel3_ydir;
int ydim6_advec_cell_kernel3_ydir;
int xdim7_advec_cell_kernel3_ydir;
int ydim7_advec_cell_kernel3_ydir;

#define OPS_ACC0(x,y,z) (x+xdim0_advec_cell_kernel3_ydir*(y)+xdim0_advec_cell_kernel3_ydir*ydim0_advec_cell_kernel3_ydir*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_advec_cell_kernel3_ydir*(y)+xdim1_advec_cell_kernel3_ydir*ydim1_advec_cell_kernel3_ydir*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_advec_cell_kernel3_ydir*(y)+xdim2_advec_cell_kernel3_ydir*ydim2_advec_cell_kernel3_ydir*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_advec_cell_kernel3_ydir*(y)+xdim3_advec_cell_kernel3_ydir*ydim3_advec_cell_kernel3_ydir*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_advec_cell_kernel3_ydir*(y)+xdim4_advec_cell_kernel3_ydir*ydim4_advec_cell_kernel3_ydir*(z))
#define OPS_ACC5(x,y,z) (x+xdim5_advec_cell_kernel3_ydir*(y)+xdim5_advec_cell_kernel3_ydir*ydim5_advec_cell_kernel3_ydir*(z))
#define OPS_ACC6(x,y,z) (x+xdim6_advec_cell_kernel3_ydir*(y)+xdim6_advec_cell_kernel3_ydir*ydim6_advec_cell_kernel3_ydir*(z))
#define OPS_ACC7(x,y,z) (x+xdim7_advec_cell_kernel3_ydir*(y)+xdim7_advec_cell_kernel3_ydir*ydim7_advec_cell_kernel3_ydir*(z))

//user function

inline void advec_cell_kernel3_ydir( const double *vol_flux_y, const double *pre_vol, const int *yy,
                              const double *vertexdy,
                              const double *density1, const double *energy1 ,
                              double *mass_flux_y, double *ener_flux) {

  double sigma, sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int y_max=field.y_max;

  int upwind,donor,downwind,dif;





  if(vol_flux_y[OPS_ACC0(0,0,0)] > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (yy[OPS_ACC2(0,1,0)] < y_max+2-2) {
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


  sigmat = fabs(vol_flux_y[OPS_ACC0(0,0,0)])/pre_vol[OPS_ACC1(0,donor,0)];
  sigma3 = (1.0 + sigmat)*(vertexdy[OPS_ACC3(0,0,0)]/vertexdy[OPS_ACC3(0,dif,0)]);
  sigma4 = 2.0 - sigmat;

  sigma = sigmat;
  sigmav = sigmat;

  diffuw = density1[OPS_ACC4(0,donor,0)] - density1[OPS_ACC4(0,upwind,0)];
  diffdw = density1[OPS_ACC4(0,downwind,0)] - density1[OPS_ACC4(0,donor,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  mass_flux_y[OPS_ACC6(0,0,0)] = (vol_flux_y[OPS_ACC0(0,0,0)]) * ( density1[OPS_ACC4(0,donor,0)] + limiter );

  sigmam = fabs(mass_flux_y[OPS_ACC6(0,0,0)])/( density1[OPS_ACC4(0,donor,0)] * pre_vol[OPS_ACC1(0,donor,0)]);
  diffuw = energy1[OPS_ACC5(0,donor,0)] - energy1[OPS_ACC5(0,upwind,0)];
  diffdw = energy1[OPS_ACC5(0,downwind,0)] - energy1[OPS_ACC5(0,donor,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  ener_flux[OPS_ACC7(0,0,0)] = mass_flux_y[OPS_ACC6(0,0,0)] * ( energy1[OPS_ACC5(0,donor,0)] + limiter );
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7


void advec_cell_kernel3_ydir_c_wrapper(
  double *p_a0,
  double *p_a1,
  int *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        advec_cell_kernel3_ydir(  p_a0 + n_x*1 + n_y*xdim0_advec_cell_kernel3_ydir*1 + n_z*xdim0_advec_cell_kernel3_ydir*ydim0_advec_cell_kernel3_ydir*1,
           p_a1 + n_x*1 + n_y*xdim1_advec_cell_kernel3_ydir*1 + n_z*xdim1_advec_cell_kernel3_ydir*ydim1_advec_cell_kernel3_ydir*1,
           p_a2 + n_x*0 + n_y*xdim2_advec_cell_kernel3_ydir*1 + n_z*xdim2_advec_cell_kernel3_ydir*ydim2_advec_cell_kernel3_ydir*0,
           p_a3 + n_x*0 + n_y*xdim3_advec_cell_kernel3_ydir*1 + n_z*xdim3_advec_cell_kernel3_ydir*ydim3_advec_cell_kernel3_ydir*0,
           p_a4 + n_x*1 + n_y*xdim4_advec_cell_kernel3_ydir*1 + n_z*xdim4_advec_cell_kernel3_ydir*ydim4_advec_cell_kernel3_ydir*1,
           p_a5 + n_x*1 + n_y*xdim5_advec_cell_kernel3_ydir*1 + n_z*xdim5_advec_cell_kernel3_ydir*ydim5_advec_cell_kernel3_ydir*1,
           p_a6 + n_x*1 + n_y*xdim6_advec_cell_kernel3_ydir*1 + n_z*xdim6_advec_cell_kernel3_ydir*ydim6_advec_cell_kernel3_ydir*1,
           p_a7 + n_x*1 + n_y*xdim7_advec_cell_kernel3_ydir*1 + n_z*xdim7_advec_cell_kernel3_ydir*ydim7_advec_cell_kernel3_ydir*1 );

      }
    }
  }
}
