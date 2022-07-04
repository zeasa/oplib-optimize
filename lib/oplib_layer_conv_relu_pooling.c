#include "oplib_common.h"
#include "oplib_interface.h"

void oplib_layer_fused_conv2d_relu_avgpool_forward(const strConv2DParam_t *pParam_conv, 
              const strReluParam_t *pParam_relu, 
              const strAvgPoolParam_t *pParam_pool,
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs)
{
    assert((pParam_conv != NULL) && (pParam_relu != NULL) && (pParam_pool != NULL) &&
           (pbuf_in != NULL) && (pbuf_out != NULL) && (pbuf_wt) && (pbuf_bs));

    
}

double oplib_layer_fused_conv2d_relu_avgpool_report_property(const strConv2DParam_t *pParam_conv, 
              const strReluParam_t *pParam_relu, 
              const strAvgPoolParam_t *pParam_pool)
{
    assert((pParam_conv != NULL) && (pParam_relu != NULL) && (pParam_pool != NULL));

    return 0.0;
}