#include "oplib_common.h"
#include "oplib_interface.h"

void oplib_layer_relu_forward(const strReluParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
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

double oplib_layer_relu_report_property(const strReluParam_t *pParam)
{
    assert(pParam != NULL);


    return 0.0;
}
