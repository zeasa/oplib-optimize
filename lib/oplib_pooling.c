#include "oplib_common.h"
#include "oplib_interface.h"

int oplib_layer_avgpool_2x2_s1(const strAvgPoolParam_t *pParam, FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    assert((pParam != NULL) && (pbuf_in != NULL) && (pbuf_out != NULL));

    int IC = pParam->param_IC;
    int IH = pParam->param_IH;
    int IW = pParam->param_IW;
    int ic, ih, iw;

    for(ic = 0; ic < IC; ++ic)
    {
        for(ih = 0; ih < IH; ++ih)
        {
            for(iw = 0; iw < IW; ++iw)
            {
                
            }
        }
    }
}

//double conv2d_calc_gflops(const strConv2DParam_t *pParam)
//{
//    return 2.0d * pParam->param_N * pParam->param_OC * pParam->param_OW * 
//           pParam->param_OH * pParam->param_KW * pParam->param_KH * pParam->param_IC / (1.0*1000*1000*1000);
//}

