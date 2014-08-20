//
// auto-generated by ops.py
//
#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_viscosity_kernel;
int ydim0_viscosity_kernel;
int xdim1_viscosity_kernel;
int ydim1_viscosity_kernel;
int xdim2_viscosity_kernel;
int ydim2_viscosity_kernel;
int xdim3_viscosity_kernel;
int ydim3_viscosity_kernel;
int xdim4_viscosity_kernel;
int ydim4_viscosity_kernel;
int xdim5_viscosity_kernel;
int ydim5_viscosity_kernel;
int xdim6_viscosity_kernel;
int ydim6_viscosity_kernel;
int xdim7_viscosity_kernel;
int ydim7_viscosity_kernel;
int xdim8_viscosity_kernel;
int ydim8_viscosity_kernel;
int xdim9_viscosity_kernel;
int ydim9_viscosity_kernel;
int xdim10_viscosity_kernel;
int ydim10_viscosity_kernel;
int xdim11_viscosity_kernel;
int ydim11_viscosity_kernel;

#define OPS_ACC0(x,y,z) (x+xdim0_viscosity_kernel*(y)+xdim0_viscosity_kernel*ydim0_viscosity_kernel*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_viscosity_kernel*(y)+xdim1_viscosity_kernel*ydim1_viscosity_kernel*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_viscosity_kernel*(y)+xdim2_viscosity_kernel*ydim2_viscosity_kernel*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_viscosity_kernel*(y)+xdim3_viscosity_kernel*ydim3_viscosity_kernel*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_viscosity_kernel*(y)+xdim4_viscosity_kernel*ydim4_viscosity_kernel*(z))
#define OPS_ACC5(x,y,z) (x+xdim5_viscosity_kernel*(y)+xdim5_viscosity_kernel*ydim5_viscosity_kernel*(z))
#define OPS_ACC6(x,y,z) (x+xdim6_viscosity_kernel*(y)+xdim6_viscosity_kernel*ydim6_viscosity_kernel*(z))
#define OPS_ACC7(x,y,z) (x+xdim7_viscosity_kernel*(y)+xdim7_viscosity_kernel*ydim7_viscosity_kernel*(z))
#define OPS_ACC8(x,y,z) (x+xdim8_viscosity_kernel*(y)+xdim8_viscosity_kernel*ydim8_viscosity_kernel*(z))
#define OPS_ACC9(x,y,z) (x+xdim9_viscosity_kernel*(y)+xdim9_viscosity_kernel*ydim9_viscosity_kernel*(z))
#define OPS_ACC10(x,y,z) (x+xdim10_viscosity_kernel*(y)+xdim10_viscosity_kernel*ydim10_viscosity_kernel*(z))
#define OPS_ACC11(x,y,z) (x+xdim11_viscosity_kernel*(y)+xdim11_viscosity_kernel*ydim11_viscosity_kernel*(z))

//user function
inline 
void viscosity_kernel( const double *xvel0, const double *yvel0,
                       const double *celldx, const double *celldy,
                       const double *pressure, const double *density0,
                       double *viscosity, const double *zvel0, const double *celldz, const double *xarea, const double *yarea, const double *zarea) {

  double grad2,
         pgradx,pgrady,pgradz,
         pgradx2,pgrady2,pgradz2,
         grad,
         ygrad, xgrad, zgrad,
         div,
         strain2,
         limiter,
         pgrad;

  double ugradx1=xvel0[OPS_ACC0(0,0,0)]+xvel0[OPS_ACC0(0,1,0)]+xvel0[OPS_ACC0(0,0,1)]+xvel0[OPS_ACC0(0,1,1)];
  double ugradx2=xvel0[OPS_ACC0(1,0,0)]+xvel0[OPS_ACC0(1,1,0)]+xvel0[OPS_ACC0(1,0,1)]+xvel0[OPS_ACC0(1,1,1)];
  double ugrady1=xvel0[OPS_ACC0(0,0,0)]+xvel0[OPS_ACC0(1,0,0)]+xvel0[OPS_ACC0(0,0,1)]+xvel0[OPS_ACC0(1,0,1)];
  double ugrady2=xvel0[OPS_ACC0(0,1,0)]+xvel0[OPS_ACC0(1,1,0)]+xvel0[OPS_ACC0(0,1,1)]+xvel0[OPS_ACC0(1,1,1)];
  double ugradz1=xvel0[OPS_ACC0(0,0,0)]+xvel0[OPS_ACC0(1,0,0)]+xvel0[OPS_ACC0(0,1,0)]+xvel0[OPS_ACC0(1,1,0)];
  double ugradz2=xvel0[OPS_ACC0(0,0,1)]+xvel0[OPS_ACC0(1,0,1)]+xvel0[OPS_ACC0(0,1,1)]+xvel0[OPS_ACC0(1,1,1)];

  double vgradx1=yvel0[OPS_ACC1(0,0,0)]+yvel0[OPS_ACC1(0,1,0)]+yvel0[OPS_ACC1(0,0,1)]+yvel0[OPS_ACC1(0,1,1)];
  double vgradx2=yvel0[OPS_ACC1(1,0,0)]+yvel0[OPS_ACC1(1,1,0)]+yvel0[OPS_ACC1(1,0,1)]+yvel0[OPS_ACC1(1,1,1)];
  double vgrady1=yvel0[OPS_ACC1(0,0,0)]+yvel0[OPS_ACC1(1,0,0)]+yvel0[OPS_ACC1(0,0,1)]+yvel0[OPS_ACC1(1,0,1)];
  double vgrady2=yvel0[OPS_ACC1(0,1,0)]+yvel0[OPS_ACC1(1,1,0)]+yvel0[OPS_ACC1(0,1,1)]+yvel0[OPS_ACC1(1,1,1)];
  double vgradz1=yvel0[OPS_ACC1(0,0,0)]+yvel0[OPS_ACC1(1,0,0)]+yvel0[OPS_ACC1(0,1,0)]+yvel0[OPS_ACC1(1,1,0)];
  double vgradz2=yvel0[OPS_ACC1(0,0,1)]+yvel0[OPS_ACC1(1,0,1)]+yvel0[OPS_ACC1(0,1,1)]+yvel0[OPS_ACC1(1,1,1)];

  double wgradx1=zvel0[OPS_ACC7(0,0,0)]+zvel0[OPS_ACC7(0,1,0)]+zvel0[OPS_ACC7(0,0,1)]+zvel0[OPS_ACC7(0,1,1)];
  double wgradx2=zvel0[OPS_ACC7(1,0,0)]+zvel0[OPS_ACC7(1,1,0)]+zvel0[OPS_ACC7(1,0,1)]+zvel0[OPS_ACC7(1,1,1)];
  double wgrady1=zvel0[OPS_ACC7(0,0,0)]+zvel0[OPS_ACC7(1,0,0)]+zvel0[OPS_ACC7(0,0,1)]+zvel0[OPS_ACC7(1,0,1)];
  double wgrady2=zvel0[OPS_ACC7(0,1,0)]+zvel0[OPS_ACC7(1,1,0)]+zvel0[OPS_ACC7(0,1,1)]+zvel0[OPS_ACC7(1,1,1)];
  double wgradz1=zvel0[OPS_ACC7(0,0,0)]+zvel0[OPS_ACC7(1,0,0)]+zvel0[OPS_ACC7(0,1,0)]+zvel0[OPS_ACC7(1,1,0)];
  double wgradz2=zvel0[OPS_ACC7(0,0,1)]+zvel0[OPS_ACC7(1,0,1)]+zvel0[OPS_ACC7(0,1,1)]+zvel0[OPS_ACC7(1,1,1)];

  div = xarea[OPS_ACC9(0,0,0)]*(ugradx2-ugradx1) + yarea[OPS_ACC10(0,0,0)]*(vgrady2-vgrady1) + zarea[OPS_ACC11(0,0,0)]*(wgradz2-wgradz1);

  double xx = 0.25*(ugradx2-ugradx1)/(celldx[OPS_ACC2(0,0,0)]);
  double yy = 0.25*(vgrady2-vgrady1)/(celldy[OPS_ACC3(0,0,0)]);
  double zz = 0.25*(wgradz2-wgradz1)/(celldz[OPS_ACC8(0,0,0)]);
  double xy = 0.25*(ugrady2-ugrady1)/(celldy[OPS_ACC3(0,0,0)])+0.25*(vgradx2-vgradx1)/(celldx[OPS_ACC2(0,0,0)]);
  double xz = 0.25*(ugradz2-ugradz1)/(celldz[OPS_ACC8(0,0,0)])+0.25*(wgradx2-wgradx1)/(celldx[OPS_ACC2(0,0,0)]);
  double yz = 0.25*(vgradz2-vgradz1)/(celldz[OPS_ACC8(0,0,0)])+0.25*(wgrady2-wgrady1)/(celldy[OPS_ACC3(0,0,0)]);


  pgradx = (pressure[OPS_ACC4(1,0,0)] - pressure[OPS_ACC4(-1,0,0)])/(celldx[OPS_ACC2(0,0,0)]+ celldx[OPS_ACC2(1,0,0)]);
  pgrady = (pressure[OPS_ACC4(0,1,0)] - pressure[OPS_ACC4(0,-1,0)])/(celldy[OPS_ACC3(0,0,0)]+ celldy[OPS_ACC3(0,1,0)]);
  pgradz = (pressure[OPS_ACC4(0,0,1)] - pressure[OPS_ACC4(0,0,-1)])/(celldz[OPS_ACC8(0,0,0)]+ celldz[OPS_ACC8(0,0,1)]);

  pgradx2 = pgradx * pgradx;
  pgrady2 = pgrady * pgrady;
  pgradz2 = pgradz * pgradz;
  limiter = (xx*pgradx2+yy*pgrady2+zz*pgradz2
          +  xy*pgradx*pgrady+xz*pgradx*pgradz+yz*pgrady*pgradz)
                / MAX(pgradx2+pgrady2+pgradz2,1.0e-16);

  if( (limiter > 0.0) || (div >= 0.0)) {
        viscosity[OPS_ACC6(0,0,0)] = 0.0;
  }
  else {
    pgradx = SIGN( MAX(1.0e-16, fabs(pgradx)), pgradx);
    pgrady = SIGN( MAX(1.0e-16, fabs(pgrady)), pgrady);
    pgradz = SIGN( MAX(1.0e-16, fabs(pgradz)), pgradz);
    pgrad = sqrt(pgradx*pgradx + pgrady*pgrady + pgradz*pgradz);
    xgrad = fabs(celldx[OPS_ACC2(0,0,0)] * pgrad/pgradx);
    ygrad = fabs(celldy[OPS_ACC3(0,0,0)] * pgrad/pgrady);
    zgrad = fabs(celldz[OPS_ACC8(0,0,0)] * pgrad/pgradz);
    grad  = MIN(xgrad,MIN(ygrad,zgrad));
    grad2 = grad*grad;

    viscosity[OPS_ACC6(0,0,0)] = 2.0 * (density0[OPS_ACC5(0,0,0)]) * grad2 * limiter * limiter;
  }
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11


void viscosity_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  double *p_a11,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10,p_a11)
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
        viscosity_kernel(  p_a0 + n_x*1 + n_y*xdim0_viscosity_kernel*1 + n_z*xdim0_viscosity_kernel*ydim0_viscosity_kernel*1,
           p_a1 + n_x*1 + n_y*xdim1_viscosity_kernel*1 + n_z*xdim1_viscosity_kernel*ydim1_viscosity_kernel*1,
           p_a2 + n_x*1 + n_y*xdim2_viscosity_kernel*0 + n_z*xdim2_viscosity_kernel*ydim2_viscosity_kernel*0,
           p_a3 + n_x*0 + n_y*xdim3_viscosity_kernel*1 + n_z*xdim3_viscosity_kernel*ydim3_viscosity_kernel*0,
           p_a4 + n_x*1 + n_y*xdim4_viscosity_kernel*1 + n_z*xdim4_viscosity_kernel*ydim4_viscosity_kernel*1,
           p_a5 + n_x*1 + n_y*xdim5_viscosity_kernel*1 + n_z*xdim5_viscosity_kernel*ydim5_viscosity_kernel*1,
           p_a6 + n_x*1 + n_y*xdim6_viscosity_kernel*1 + n_z*xdim6_viscosity_kernel*ydim6_viscosity_kernel*1,
           p_a7 + n_x*1 + n_y*xdim7_viscosity_kernel*1 + n_z*xdim7_viscosity_kernel*ydim7_viscosity_kernel*1,
           p_a8 + n_x*0 + n_y*xdim8_viscosity_kernel*0 + n_z*xdim8_viscosity_kernel*ydim8_viscosity_kernel*1,
           p_a9 + n_x*1 + n_y*xdim9_viscosity_kernel*1 + n_z*xdim9_viscosity_kernel*ydim9_viscosity_kernel*1,
           p_a10 + n_x*1 + n_y*xdim10_viscosity_kernel*1 + n_z*xdim10_viscosity_kernel*ydim10_viscosity_kernel*1,
           p_a11 + n_x*1 + n_y*xdim11_viscosity_kernel*1 + n_z*xdim11_viscosity_kernel*ydim11_viscosity_kernel*1 );

      }
    }
  }
}
