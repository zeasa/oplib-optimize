#include <stdlib.h>
#include <stdio.h>
#include "oplib_common.h"
#include "oplib_interface.h"

int oplib_conv2d_avgpool_relu(const strConv2DParam_t *pParam, 
              FLOAT_T *pbuf_in, 
              FLOAT_T *pbuf_out, 
              FLOAT_T *pbuf_wt,
              FLOAT_T *pbuf_bs)
{

}

//double conv2d_calc_gflops(const strConv2DParam_t *pParam)
//{
//    return 2.0d * pParam->param_N * pParam->param_OC * pParam->param_OW * 
//           pParam->param_OH * pParam->param_KW * pParam->param_KH * pParam->param_IC / (1.0*1000*1000*1000);
//}

