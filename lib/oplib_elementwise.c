#include "oplib_common.h"
#include "oplib_interface.h"

int oplib_layer_relu(const strReluParam_t *pParam, FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    assert((pParam != NULL) && (pbuf_in != NULL) && (pbuf_out != NULL));
    
    int IC = pParam->param_IC;
    int IH = pParam->param_IH;
    int IW = pParam->param_IW;
    int i;

    for(i=0; i<IC*IH*IW; ++i)
    {
        pbuf_out[i] = (pbuf_in[i] <= 0) ? 0 : pbuf_in[i];
    }
}

//double conv2d_calc_gflops(const strConv2DParam_t *pParam)
//{
//    return 2.0d * pParam->param_N * pParam->param_OC * pParam->param_OW * 
//           pParam->param_OH * pParam->param_KW * pParam->param_KH * pParam->param_IC / (1.0*1000*1000*1000);
//}

