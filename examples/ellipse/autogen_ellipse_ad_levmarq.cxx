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
    mlx_array<mlx_logical> jacobian(ins[2]);
    bool do_jacobian = jacobian[0];

    mlx_assert(in.cols == data.cols);
    mlx_assert(in.rows == 6);
    mlx_assert(data.rows == 2);

    mwSize out_rows = 1 + (do_jacobian ? 6 : 0);
    mwSize out_cols = 2 * in.cols;
    mlx_make_array<mlx_double> out(out_rows, out_cols);

    double const* in_ptr = in.data;
    double const* data_ptr = data.data;
    double* out_ptr = out.data;

    if (do_jacobian) {
        // const mwSize out_rows = 6 + 1;
        const mwSize out_step = (6 + 1) * 2;
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
    double t2 = cos(x6);
    double t3 = sin(x5);
    double t4 = cos(x5);
    double t5 = sin(x6);
    double t6 = t2*t3*x3;
    double t7 = t4*t5*x4;
    double t8 = t2*t4*x3;
  out_ptr[0] = -data1+t8+x1-t3*t5*x4;
  out_ptr[1 * out_rows + 0] = -data2+t6+t7+x2;
  out_ptr[1] = 1.0;
  out_ptr[1 * out_rows + 2] = 1.0;
  out_ptr[3] = t2*t4;
  out_ptr[1 * out_rows + 3] = t2*t3;
  out_ptr[4] = -t3*t5;
  out_ptr[1 * out_rows + 4] = t4*t5;
  out_ptr[5] = -t6-t7;
  out_ptr[1 * out_rows + 5] = t8-t3*t5*x4;
  out_ptr[6] = -t2*t3*x4-t4*t5*x3;
  out_ptr[1 * out_rows + 6] = t2*t4*x4-t3*t5*x3;

#line 39 "au_autodiff_generate_template.cpp"
        }
    } else {
        const mwSize out_step = 2;
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
    double t2 = cos(x6);
    double t3 = sin(x5);
    double t4 = cos(x5);
    double t5 = sin(x6);
  out_ptr[0] = -data1+x1+t2*t4*x3-t3*t5*x4;
  out_ptr[1] = -data2+x2+t2*t3*x3+t4*t5*x4;

#line 48 "au_autodiff_generate_template.cpp"
        }
    }
    
    outs[0] = out;
}
