//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_drhouupdx_kernel;
int xdim1_drhouupdx_kernel;
int xdim2_drhouupdx_kernel;
int xdim3_drhouupdx_kernel;


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)
#define OPS_ACC2(x) (x)
#define OPS_ACC3(x) (x)

//user function
inline 
void drhouupdx_kernel(const double *rhou_new, const double* rho_new, const double* rhoE_new, double *rhou_res) {

			double fni = rhou_new[OPS_ACC0(0)] * rhou_new[OPS_ACC0(0)] / rho_new[OPS_ACC1(0)] ;
			double p = gam1 * (rhoE_new[OPS_ACC2(0)] - 0.5 * fni);
			fni = fni + p;
			double fnim1 = rhou_new[OPS_ACC0(-1)] * rhou_new[OPS_ACC0(-1)] / rho_new[OPS_ACC1(-1)];
			p = gam1 * (rhoE_new[OPS_ACC2(-1)] - 0.5 * fnim1);
			fnim1 = fnim1 + p;
			double fnim2 = rhou_new[OPS_ACC0(-2)] * rhou_new[OPS_ACC0(-2)] / rho_new[OPS_ACC1(-2)];
			p = gam1 * (rhoE_new[OPS_ACC2(-2)] - 0.5 * fnim2);
			fnim2 = fnim2 + p;
			double fnip1 = rhou_new[OPS_ACC0(1)] * rhou_new[OPS_ACC0(1)] / rho_new[OPS_ACC1(1)];
			p = gam1 * (rhoE_new[OPS_ACC2(1)] - 0.5 * fnip1);
			fnip1 = fnip1 + p;
			double fnip2 = rhou_new[OPS_ACC0(2)] * rhou_new[OPS_ACC0(2)] / rho_new[OPS_ACC1(2)];
			p = gam1 * (rhoE_new[OPS_ACC2(2)] - 0.5 * fnip2);
			fnip2 = fnip2 + p;

			double deriv = (fnim2 - fnip2 + 8.0* (fnip1 - fnim1))/(12.00*dx);
			rhou_res[OPS_ACC3(0)] = deriv;
}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3



void drhouupdx_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    drhouupdx_kernel(  p_a0 + n_x*1*1,
           p_a1 + n_x*1*1, p_a2 + n_x*1*1,
           p_a3 + n_x*1*1 );

  }
}
