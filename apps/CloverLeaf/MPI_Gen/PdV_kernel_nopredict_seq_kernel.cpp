//
// auto-generated by ops.py on 2014-03-06 10:56
//

//user function
#include "PdV_kernel.h"

// host stub function
void ops_par_loop_PdV_kernel_nopredict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13) {

  char *p_a[14];
  int  offs[14][2];
  ops_arg args[14] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13};


  sub_block_list sb = OPS_sub_block_list[block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start[ndim*14];
  int end[ndim*14];

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

  for ( int i=0; i<14; i++ ){
    for ( int n=0; n<ndim; n++ ){
      start[i*ndim+n] = s[n];
      end[i*ndim+n]   = e[n];
    }
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "PdV_kernel_nopredict");
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

  offs[5][0] = args[5].stencil->stride[0]*1;  //unit step in x dimension
  offs[5][1] = off2D(1, &start[5*2],
  &end[5*2],args[5].dat->block_size, args[5].stencil->stride);

  offs[6][0] = args[6].stencil->stride[0]*1;  //unit step in x dimension
  offs[6][1] = off2D(1, &start[6*2],
  &end[6*2],args[6].dat->block_size, args[6].stencil->stride);

  offs[7][0] = args[7].stencil->stride[0]*1;  //unit step in x dimension
  offs[7][1] = off2D(1, &start[7*2],
  &end[7*2],args[7].dat->block_size, args[7].stencil->stride);

  offs[8][0] = args[8].stencil->stride[0]*1;  //unit step in x dimension
  offs[8][1] = off2D(1, &start[8*2],
  &end[8*2],args[8].dat->block_size, args[8].stencil->stride);

  offs[9][0] = args[9].stencil->stride[0]*1;  //unit step in x dimension
  offs[9][1] = off2D(1, &start[9*2],
  &end[9*2],args[9].dat->block_size, args[9].stencil->stride);

  offs[10][0] = args[10].stencil->stride[0]*1;  //unit step in x dimension
  offs[10][1] = off2D(1, &start[10*2],
  &end[10*2],args[10].dat->block_size, args[10].stencil->stride);

  offs[11][0] = args[11].stencil->stride[0]*1;  //unit step in x dimension
  offs[11][1] = off2D(1, &start[11*2],
  &end[11*2],args[11].dat->block_size, args[11].stencil->stride);

  offs[12][0] = args[12].stencil->stride[0]*1;  //unit step in x dimension
  offs[12][1] = off2D(1, &start[12*2],
  &end[12*2],args[12].dat->block_size, args[12].stencil->stride);

  offs[13][0] = args[13].stencil->stride[0]*1;  //unit step in x dimension
  offs[13][1] = off2D(1, &start[13*2],
  &end[13*2],args[13].dat->block_size, args[13].stencil->stride);



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
  int off5_1 = offs[5][0];
  int off5_2 = offs[5][1];
  int dat5 = args[5].dat->size;
  int off6_1 = offs[6][0];
  int off6_2 = offs[6][1];
  int dat6 = args[6].dat->size;
  int off7_1 = offs[7][0];
  int off7_2 = offs[7][1];
  int dat7 = args[7].dat->size;
  int off8_1 = offs[8][0];
  int off8_2 = offs[8][1];
  int dat8 = args[8].dat->size;
  int off9_1 = offs[9][0];
  int off9_2 = offs[9][1];
  int dat9 = args[9].dat->size;
  int off10_1 = offs[10][0];
  int off10_2 = offs[10][1];
  int dat10 = args[10].dat->size;
  int off11_1 = offs[11][0];
  int off11_2 = offs[11][1];
  int dat11 = args[11].dat->size;
  int off12_1 = offs[12][0];
  int off12_2 = offs[12][1];
  int dat12 = args[12].dat->size;
  int off13_1 = offs[13][0];
  int off13_2 = offs[13][1];
  int dat13 = args[13].dat->size;

  //set up initial pointers and exchange halos if nessasary
  int base0 = dat0 * 1 * 
  (start[ndim+0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start[ndim+1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data + base0;
  ops_exchange_halo(&args[0],2);

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
  ops_exchange_halo(&args[2],2);

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
  ops_exchange_halo(&args[4],2);

  //set up initial pointers and exchange halos if nessasary
  int base5 = dat5 * 1 * 
  (start[ndim+0] * args[5].stencil->stride[0] - args[5].dat->offset[0]);
  base5 = base5  + dat5 * args[5].dat->block_size[0] * 
  (start[ndim+1] * args[5].stencil->stride[1] - args[5].dat->offset[1]);
  p_a[5] = (char *)args[5].data + base5;
  ops_exchange_halo(&args[5],2);

  //set up initial pointers and exchange halos if nessasary
  int base6 = dat6 * 1 * 
  (start[ndim+0] * args[6].stencil->stride[0] - args[6].dat->offset[0]);
  base6 = base6  + dat6 * args[6].dat->block_size[0] * 
  (start[ndim+1] * args[6].stencil->stride[1] - args[6].dat->offset[1]);
  p_a[6] = (char *)args[6].data + base6;

  //set up initial pointers and exchange halos if nessasary
  int base7 = dat7 * 1 * 
  (start[ndim+0] * args[7].stencil->stride[0] - args[7].dat->offset[0]);
  base7 = base7  + dat7 * args[7].dat->block_size[0] * 
  (start[ndim+1] * args[7].stencil->stride[1] - args[7].dat->offset[1]);
  p_a[7] = (char *)args[7].data + base7;
  ops_exchange_halo(&args[7],2);

  //set up initial pointers and exchange halos if nessasary
  int base8 = dat8 * 1 * 
  (start[ndim+0] * args[8].stencil->stride[0] - args[8].dat->offset[0]);
  base8 = base8  + dat8 * args[8].dat->block_size[0] * 
  (start[ndim+1] * args[8].stencil->stride[1] - args[8].dat->offset[1]);
  p_a[8] = (char *)args[8].data + base8;
  ops_exchange_halo(&args[8],2);

  //set up initial pointers and exchange halos if nessasary
  int base9 = dat9 * 1 * 
  (start[ndim+0] * args[9].stencil->stride[0] - args[9].dat->offset[0]);
  base9 = base9  + dat9 * args[9].dat->block_size[0] * 
  (start[ndim+1] * args[9].stencil->stride[1] - args[9].dat->offset[1]);
  p_a[9] = (char *)args[9].data + base9;
  ops_exchange_halo(&args[9],2);

  //set up initial pointers and exchange halos if nessasary
  int base10 = dat10 * 1 * 
  (start[ndim+0] * args[10].stencil->stride[0] - args[10].dat->offset[0]);
  base10 = base10  + dat10 * args[10].dat->block_size[0] * 
  (start[ndim+1] * args[10].stencil->stride[1] - args[10].dat->offset[1]);
  p_a[10] = (char *)args[10].data + base10;

  //set up initial pointers and exchange halos if nessasary
  int base11 = dat11 * 1 * 
  (start[ndim+0] * args[11].stencil->stride[0] - args[11].dat->offset[0]);
  base11 = base11  + dat11 * args[11].dat->block_size[0] * 
  (start[ndim+1] * args[11].stencil->stride[1] - args[11].dat->offset[1]);
  p_a[11] = (char *)args[11].data + base11;
  ops_exchange_halo(&args[11],2);

  //set up initial pointers and exchange halos if nessasary
  int base12 = dat12 * 1 * 
  (start[ndim+0] * args[12].stencil->stride[0] - args[12].dat->offset[0]);
  base12 = base12  + dat12 * args[12].dat->block_size[0] * 
  (start[ndim+1] * args[12].stencil->stride[1] - args[12].dat->offset[1]);
  p_a[12] = (char *)args[12].data + base12;
  ops_exchange_halo(&args[12],2);

  //set up initial pointers and exchange halos if nessasary
  int base13 = dat13 * 1 * 
  (start[ndim+0] * args[13].stencil->stride[0] - args[13].dat->offset[0]);
  base13 = base13  + dat13 * args[13].dat->block_size[0] * 
  (start[ndim+1] * args[13].stencil->stride[1] - args[13].dat->offset[1]);
  p_a[13] = (char *)args[13].data + base13;



  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(6,"PdV_kernel_nopredict");
  ops_timers_core(&c1,&t1);

  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];
  xdim2 = args[2].dat->block_size[0];
  xdim3 = args[3].dat->block_size[0];
  xdim4 = args[4].dat->block_size[0];
  xdim5 = args[5].dat->block_size[0];
  xdim6 = args[6].dat->block_size[0];
  xdim7 = args[7].dat->block_size[0];
  xdim8 = args[8].dat->block_size[0];
  xdim9 = args[9].dat->block_size[0];
  xdim10 = args[10].dat->block_size[0];
  xdim11 = args[11].dat->block_size[0];
  xdim12 = args[12].dat->block_size[0];
  xdim13 = args[13].dat->block_size[0];

  int n_x;
  for ( int n_y=s[1]; n_y<e[1]; n_y++ ){
    for ( int n_x=s[0]; n_x<s[0]+(e[0]-s[0])/SIMD_VEC; n_x++ ){
        //call kernel function, passing in pointers to data -vectorised
        #pragma simd
        for ( int i=0; i<SIMD_VEC; i++ ){
          PdV_kernel_nopredict(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1, (double *)p_a[2]+ i*1,
           (double *)p_a[3]+ i*1, (double *)p_a[4]+ i*1, (double *)p_a[5]+ i*1, (double *)p_a[6]+ i*1,
           (double *)p_a[7]+ i*1, (double *)p_a[8]+ i*1, (double *)p_a[9]+ i*1, (double *)p_a[10]+ i*1,
           (double *)p_a[11]+ i*1, (double *)p_a[12]+ i*1, (double *)p_a[13]+ i*1 );

        }

        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1)*SIMD_VEC;
        p_a[1]= p_a[1] + (dat1 * off1_1)*SIMD_VEC;
        p_a[2]= p_a[2] + (dat2 * off2_1)*SIMD_VEC;
        p_a[3]= p_a[3] + (dat3 * off3_1)*SIMD_VEC;
        p_a[4]= p_a[4] + (dat4 * off4_1)*SIMD_VEC;
        p_a[5]= p_a[5] + (dat5 * off5_1)*SIMD_VEC;
        p_a[6]= p_a[6] + (dat6 * off6_1)*SIMD_VEC;
        p_a[7]= p_a[7] + (dat7 * off7_1)*SIMD_VEC;
        p_a[8]= p_a[8] + (dat8 * off8_1)*SIMD_VEC;
        p_a[9]= p_a[9] + (dat9 * off9_1)*SIMD_VEC;
        p_a[10]= p_a[10] + (dat10 * off10_1)*SIMD_VEC;
        p_a[11]= p_a[11] + (dat11 * off11_1)*SIMD_VEC;
        p_a[12]= p_a[12] + (dat12 * off12_1)*SIMD_VEC;
        p_a[13]= p_a[13] + (dat13 * off13_1)*SIMD_VEC;
      }

      for ( int n_x=s[0]+((e[0]-s[0])/SIMD_VEC)*SIMD_VEC; n_x<e[0]; n_x++ ){
          //call kernel function, passing in pointers to data - remainder
          PdV_kernel_nopredict(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3], (double *)p_a[4], (double *)p_a[5], (double *)p_a[6],
           (double *)p_a[7], (double *)p_a[8], (double *)p_a[9], (double *)p_a[10],
           (double *)p_a[11], (double *)p_a[12], (double *)p_a[13] );


          //shift pointers to data x direction
          p_a[0]= p_a[0] + (dat0 * off0_1);
          p_a[1]= p_a[1] + (dat1 * off1_1);
          p_a[2]= p_a[2] + (dat2 * off2_1);
          p_a[3]= p_a[3] + (dat3 * off3_1);
          p_a[4]= p_a[4] + (dat4 * off4_1);
          p_a[5]= p_a[5] + (dat5 * off5_1);
          p_a[6]= p_a[6] + (dat6 * off6_1);
          p_a[7]= p_a[7] + (dat7 * off7_1);
          p_a[8]= p_a[8] + (dat8 * off8_1);
          p_a[9]= p_a[9] + (dat9 * off9_1);
          p_a[10]= p_a[10] + (dat10 * off10_1);
          p_a[11]= p_a[11] + (dat11 * off11_1);
          p_a[12]= p_a[12] + (dat12 * off12_1);
          p_a[13]= p_a[13] + (dat13 * off13_1);
        }

        //shift pointers to data y direction
        p_a[0]= p_a[0] + (dat0 * off0_2);
        p_a[1]= p_a[1] + (dat1 * off1_2);
        p_a[2]= p_a[2] + (dat2 * off2_2);
        p_a[3]= p_a[3] + (dat3 * off3_2);
        p_a[4]= p_a[4] + (dat4 * off4_2);
        p_a[5]= p_a[5] + (dat5 * off5_2);
        p_a[6]= p_a[6] + (dat6 * off6_2);
        p_a[7]= p_a[7] + (dat7 * off7_2);
        p_a[8]= p_a[8] + (dat8 * off8_2);
        p_a[9]= p_a[9] + (dat9 * off9_2);
        p_a[10]= p_a[10] + (dat10 * off10_2);
        p_a[11]= p_a[11] + (dat11 * off11_2);
        p_a[12]= p_a[12] + (dat12 * off12_2);
        p_a[13]= p_a[13] + (dat13 * off13_2);
      }
      ops_set_halo_dirtybit(&args[6]);
      ops_set_halo_dirtybit(&args[10]);
      ops_set_halo_dirtybit(&args[13]);

      //Update kernel record
      ops_timers_core(&c2,&t2);
      OPS_kernels[6].count++;
      OPS_kernels[6].time += t2-t1;
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg0);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg1);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg2);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg3);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg4);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg5);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg6);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg7);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg8);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg9);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg10);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg11);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg12);
      OPS_kernels[6].transfer += ops_compute_transfer(dim, range, &arg13);
    }
