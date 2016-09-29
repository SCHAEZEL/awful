#line 2 "au_autodiff_generate_template.cpp"
#include <math.h>

#include "au_mex.h"

// Autogenerated by au_ccode
// FROM: [Anonymous expression]
// au_autodiff_template.cpp - outline code for au_autodiff*
// awf@microsoft.com, Dec 13

void mlx_function(mlx_inputs& ins, mlx_outputs& outs)
{
    mlx_array<mlx_double> in(ins[0]);
    mlx_array<mlx_double> data(ins[1]);
    mlx_scalar<mlx_double> do_jacobian_a(ins[2]);
    int do_jacobian = (int)do_jacobian_a[0];

    mlx_assert(in.cols == data.cols);
    mlx_assert(in.rows == 6);
    mlx_assert(data.rows == 2);
    mlx_assert(do_jacobian == 0 || do_jacobian == 1 || do_jacobian == 2);

    mwSize out_rows = 1;
    if (do_jacobian >= 1) out_rows += in.rows;
    if (do_jacobian >= 2) out_rows += in.rows * (in.rows+1)/2;
    mwSize out_cols = 1 * in.cols;

    mlx_make_array<mlx_double> out(out_rows, out_cols);

    double const* in_ptr = in.data;
    double const* data_ptr = data.data;
    double* out_ptr = out.data;

    const mwSize out_step = out_rows * 1;
    if (do_jacobian == 2) {
        for(mwSize c_in = 0; c_in < in.cols; ++c_in,
                in_ptr += in.rows,
                data_ptr += data.rows,
                out_ptr += out_step) {
              /* inner loop do_jac=2 */
    double x1 = in_ptr[0];
    double x2 = in_ptr[1];
    double x3 = in_ptr[2];
    double x4 = in_ptr[3];
    double x5 = in_ptr[4];
    double x6 = in_ptr[5];
    double data1 = data_ptr[0];
    double data2 = data_ptr[1];
    double t3 = cos(x6);
    double t4 = sin(x5);
    double t5 = cos(x5);
    double t6 = sin(x6);
    double t8 = t3*t5*x3;
    double t9 = t4*t6*x4;
    double t2 = data1-t8+t9-x1;
    double t10 = t3*t4*x3;
    double t11 = t5*t6*x4;
    double t7 = -data2+t10+t11+x2;
    double t12 = t3*t4*x3*2.0;
    double t13 = t5*t6*x4*2.0;
    double t14 = t3*t5*x3*2.0;
    double t15 = t3*t3;
    double t16 = t10+t11;
    double t17 = t8-t9;
    double t18 = t5*t6*x3;
    double t19 = t3*t4*x4;
    double t20 = t18+t19;
    double t21 = t3*t5*x4;
    double t27 = t4*t6*x3;
    double t22 = t21-t27;
    double t23 = t5*t5;
    double t24 = t4*t4;
    double t25 = t6*t6;
    double t26 = t2*t5*t6*2.0;
    double t28 = t3*t5*t7*2.0;
    double t29 = t2*t3*t4*2.0;
    double t30 = t2*t17*2.0;
  out_ptr[0] = t2*t2+t7*t7;
  out_ptr[1] = data1*-2.0+t14+x1*2.0-t4*t6*x4*2.0;
  out_ptr[2] = data2*-2.0+t12+t13+x2*2.0;
  out_ptr[3] = t2*t3*t5*-2.0+t3*t4*t7*2.0;
  out_ptr[4] = t2*t4*t6*2.0+t5*t6*t7*2.0;
  out_ptr[5] = t2*t16*2.0+t7*t17*2.0;
  out_ptr[6] = t2*t20*2.0+t7*t22*2.0;
  out_ptr[7] = 2.0;
  out_ptr[9] = t3*t5*2.0;
  out_ptr[10] = t4*t6*-2.0;
  out_ptr[11] = -t12-t13;
  out_ptr[12] = t3*t4*x4*-2.0-t5*t6*x3*2.0;
  out_ptr[13] = 2.0;
  out_ptr[14] = t3*t4*2.0;
  out_ptr[15] = t5*t6*2.0;
  out_ptr[16] = t14-t4*t6*x4*2.0;
  out_ptr[17] = t3*t5*x4*2.0-t4*t6*x3*2.0;
  out_ptr[18] = t15*t23*2.0+t15*t24*2.0;
  out_ptr[20] = t28+t29+t3*t4*t17*2.0-t3*t5*t16*2.0;
  out_ptr[21] = t26-t4*t6*t7*2.0-t3*t5*t20*2.0+t3*t4*t22*2.0;
  out_ptr[22] = t23*t25*2.0+t24*t25*2.0;
  out_ptr[23] = t26-t4*t6*t7*2.0+t4*t6*t16*2.0+t5*t6*t17*2.0;
  out_ptr[24] = t28+t29+t4*t6*t20*2.0+t5*t6*t22*2.0;
  out_ptr[25] = t30-t7*t16*2.0+(t16*t16)*2.0+(t17*t17)*2.0;
  out_ptr[26] = t2*t22*2.0-t7*t20*2.0+t16*t20*2.0+t17*t22*2.0;
  out_ptr[27] = t30-t7*t16*2.0+(t20*t20)*2.0+(t22*t22)*2.0;

#line 40 "au_autodiff_generate_template.cpp"
        }
    } else if (do_jacobian == 1) {
        for(mwSize c_in = 0; c_in < in.cols; ++c_in,
                in_ptr += in.rows,
                data_ptr += data.rows,
                out_ptr += out_step) {
              /* inner loop do_jac=1 */
    double x1 = in_ptr[0];
    double x2 = in_ptr[1];
    double x3 = in_ptr[2];
    double x4 = in_ptr[3];
    double x5 = in_ptr[4];
    double x6 = in_ptr[5];
    double data1 = data_ptr[0];
    double data2 = data_ptr[1];
    double t3 = cos(x6);
    double t4 = sin(x5);
    double t5 = cos(x5);
    double t6 = sin(x6);
    double t8 = t3*t5*x3;
    double t9 = t4*t6*x4;
    double t2 = data1-t8+t9-x1;
    double t10 = t3*t4*x3;
    double t11 = t5*t6*x4;
    double t7 = -data2+t10+t11+x2;
  out_ptr[0] = t2*t2+t7*t7;
  out_ptr[1] = data1*-2.0+x1*2.0+t3*t5*x3*2.0-t4*t6*x4*2.0;
  out_ptr[2] = data2*-2.0+x2*2.0+t3*t4*x3*2.0+t5*t6*x4*2.0;
  out_ptr[3] = t2*t3*t5*-2.0+t3*t4*t7*2.0;
  out_ptr[4] = t2*t4*t6*2.0+t5*t6*t7*2.0;
  out_ptr[5] = t2*(t10+t11)*2.0+t7*(t8-t9)*2.0;
  out_ptr[6] = t2*(t3*t4*x4+t5*t6*x3)*2.0+t7*(t3*t5*x4-t4*t6*x3)*2.0;

#line 48 "au_autodiff_generate_template.cpp"
        }
    } else {
        for(mwSize c_in = 0; c_in < in.cols; ++c_in,
                in_ptr += in.rows,
                data_ptr += data.rows,
                out_ptr += out_step) {
              /* inner loop do_jac=0 */
    double x1 = in_ptr[0];
    double x2 = in_ptr[1];
    double x3 = in_ptr[2];
    double x4 = in_ptr[3];
    double x5 = in_ptr[4];
    double x6 = in_ptr[5];
    double data1 = data_ptr[0];
    double data2 = data_ptr[1];
    double t3 = cos(x6);
    double t4 = sin(x5);
    double t5 = cos(x5);
    double t6 = sin(x6);
    double t2 = data1-x1-t3*t5*x3+t4*t6*x4;
    double t7 = -data2+x2+t3*t4*x3+t5*t6*x4;
    out_ptr[0] = t2*t2+t7*t7;

#line 56 "au_autodiff_generate_template.cpp"
        }
    }
    
    outs[0] = out;
}