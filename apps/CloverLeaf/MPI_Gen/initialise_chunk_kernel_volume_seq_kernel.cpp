//
// auto-generated by ops.py on 2014-03-06 10:56
//

//user function
#include "initialise_chunk_kernel.h"

// host stub function
void ops_par_loop_initialise_chunk_kernel_volume(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {

  char *p_a[5];
  int  offs[5][2];
  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  sub_block_list sb = OPS_sub_block_list[block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start[ndim*5];
  int end[ndim*5];

  int s[ndim];
  int e[ndim];

  for ( int n=0; n<ndim; n++ ){
    s[n] = sb->istart[n];e[n] = sb->iend[n]+1;
    if (s[n] >= range[2*n]) {
      s[n] = 0;
    }
    else {
      s[n] = range[2*n] - s[n];
    }
    if (e[n] >= range[2*n+1]) {
      e[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      e[n] = sb->sizes[n];
    }
  }

  for ( int i=0; i<5; i++ ){
    for ( int n=0; n<ndim; n++ ){
      start[i*ndim+n] = s[n];
      end[i*ndim+n]   = e[n];
    }
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "initialise_chunk_kernel_volume");
  #endif

  offs[0][0] = args[0].stencil->stride[0]*1;  //unit step in x dimension
  offs[0][1] = off2D(1, &start[0*2],
  &end[0*2],args[0].dat->block_size, args[0].stencil->stride);

  offs[1][0] = args[1].stencil->stride[0]*1;  //unit step in x dimension
  offs[1][1] = off2D(1, &start[1*2],
  &end[1*2],args[1].dat->block_size, args[1].stencil->stride);

  offs[2][0] = args[2].stencil->stride[0]*1;  //unit step in x dimension
  offs[2][1] = off2D(1, &start[2*2],
  &end[2*2],args[2].dat->block_size, args[2].stencil->stride);

  offs[3][0] = args[3].stencil->stride[0]*1;  //unit step in x dimension
  offs[3][1] = off2D(1, &start[3*2],
  &end[3*2],args[3].dat->block_size, args[3].stencil->stride);

  offs[4][0] = args[4].stencil->stride[0]*1;  //unit step in x dimension
  offs[4][1] = off2D(1, &start[4*2],
  &end[4*2],args[4].dat->block_size, args[4].stencil->stride);



  int off0_1 = offs[0][0];
  int off0_2 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_1 = offs[1][0];
  int off1_2 = offs[1][1];
  int dat1 = args[1].dat->size;
  int off2_1 = offs[2][0];
  int off2_2 = offs[2][1];
  int dat2 = args[2].dat->size;
  int off3_1 = offs[3][0];
  int off3_2 = offs[3][1];
  int dat3 = args[3].dat->size;
  int off4_1 = offs[4][0];
  int off4_2 = offs[4][1];
  int dat4 = args[4].dat->size;

  //set up initial pointers and exchange halos if nessasary
  int base0 = dat0 * 1 * 
  (start[ndim+0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start[ndim+1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data + base0;

  //set up initial pointers and exchange halos if nessasary
  int base1 = dat1 * 1 * 
  (start[ndim+0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start[ndim+1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data + base1;
  ops_exchange_halo(&args[1],2);

  //set up initial pointers and exchange halos if nessasary
  int base2 = dat2 * 1 * 
  (start[ndim+0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2  + dat2 * args[2].dat->block_size[0] * 
  (start[ndim+1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  p_a[2] = (char *)args[2].data + base2;

  //set up initial pointers and exchange halos if nessasary
  int base3 = dat3 * 1 * 
  (start[ndim+0] * args[3].stencil->stride[0] - args[3].dat->offset[0]);
  base3 = base3  + dat3 * args[3].dat->block_size[0] * 
  (start[ndim+1] * args[3].stencil->stride[1] - args[3].dat->offset[1]);
  p_a[3] = (char *)args[3].data + base3;
  ops_exchange_halo(&args[3],2);

  //set up initial pointers and exchange halos if nessasary
  int base4 = dat4 * 1 * 
  (start[ndim+0] * args[4].stencil->stride[0] - args[4].dat->offset[0]);
  base4 = base4  + dat4 * args[4].dat->block_size[0] * 
  (start[ndim+1] * args[4].stencil->stride[1] - args[4].dat->offset[1]);
  p_a[4] = (char *)args[4].data + base4;



  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(80,"initialise_chunk_kernel_volume");
  ops_timers_core(&c1,&t1);

  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];
  xdim2 = args[2].dat->block_size[0];
  xdim3 = args[3].dat->block_size[0];
  xdim4 = args[4].dat->block_size[0];

  int n_x;
  for ( int n_y=s[1]; n_y<e[1]; n_y++ ){
    for ( int n_x=s[0]; n_x<s[0]+(e[0]-s[0])/SIMD_VEC; n_x++ ){
        //call kernel function, passing in pointers to data -vectorised
        #pragma simd
        for ( int i=0; i<SIMD_VEC; i++ ){
          initialise_chunk_kernel_volume(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*0, (double *)p_a[2]+ i*1,
           (double *)p_a[3]+ i*1, (double *)p_a[4]+ i*1 );

        }

        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1)*SIMD_VEC;
        p_a[1]= p_a[1] + (dat1 * off1_1)*SIMD_VEC;
        p_a[2]= p_a[2] + (dat2 * off2_1)*SIMD_VEC;
        p_a[3]= p_a[3] + (dat3 * off3_1)*SIMD_VEC;
        p_a[4]= p_a[4] + (dat4 * off4_1)*SIMD_VEC;
      }

      for ( int n_x=s[0]+((e[0]-s[0])/SIMD_VEC)*SIMD_VEC; n_x<e[0]; n_x++ ){
          //call kernel function, passing in pointers to data - remainder
          initialise_chunk_kernel_volume(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3], (double *)p_a[4] );


          //shift pointers to data x direction
          p_a[0]= p_a[0] + (dat0 * off0_1);
          p_a[1]= p_a[1] + (dat1 * off1_1);
          p_a[2]= p_a[2] + (dat2 * off2_1);
          p_a[3]= p_a[3] + (dat3 * off3_1);
          p_a[4]= p_a[4] + (dat4 * off4_1);
        }

        //shift pointers to data y direction
        p_a[0]= p_a[0] + (dat0 * off0_2);
        p_a[1]= p_a[1] + (dat1 * off1_2);
        p_a[2]= p_a[2] + (dat2 * off2_2);
        p_a[3]= p_a[3] + (dat3 * off3_2);
        p_a[4]= p_a[4] + (dat4 * off4_2);
      }
      ops_set_halo_dirtybit(&args[0]);
      ops_set_halo_dirtybit(&args[2]);
      ops_set_halo_dirtybit(&args[4]);

      //Update kernel record
      ops_timers_core(&c2,&t2);
      OPS_kernels[80].count++;
      OPS_kernels[80].time += t2-t1;
      OPS_kernels[80].transfer += ops_compute_transfer(dim, range, &arg0);
      OPS_kernels[80].transfer += ops_compute_transfer(dim, range, &arg1);
      OPS_kernels[80].transfer += ops_compute_transfer(dim, range, &arg2);
      OPS_kernels[80].transfer += ops_compute_transfer(dim, range, &arg3);
      OPS_kernels[80].transfer += ops_compute_transfer(dim, range, &arg4);
    }
