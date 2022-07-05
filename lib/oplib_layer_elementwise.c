#include <omp.h>
#include "oplib_common.h"
#include "oplib_interface.h"

void oplib_layer_relu_forward(const strReluParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    assert((pParam != NULL) && (pbuf_in != NULL) && (pbuf_out != NULL));
    
    int N  = pParam->param_N ;
    int IC = pParam->param_IC;
    int IH = pParam->param_IH;
    int IW = pParam->param_IW;
    int BATCH_CUBE = N*IC*IH*IW;
    int i;

    for(i=0; i<BATCH_CUBE; ++i)
    {
        pbuf_out[i] = (pbuf_in[i] <= 0) ? 0 : pbuf_in[i];
    }
}

void oplib_layer_relu_forward_omp(const strReluParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    assert((pParam != NULL) && (pbuf_in != NULL) && (pbuf_out != NULL));
    
    int N  = pParam->param_N ;
    int IC = pParam->param_IC;
    int IH = pParam->param_IH;
    int IW = pParam->param_IW;
    int BATCH_CUBE = N*IC*IH*IW;
    int i;

#pragma omp parallel for num_threads(8)
//#pragma omp parallel for
    for(i=0; i<BATCH_CUBE; ++i)
    {
        pbuf_out[i] = (pbuf_in[i] <= 0) ? 0 : pbuf_in[i];
    }
}

double oplib_layer_relu_report_property(const strReluParam_t *pParam)
{
    assert(pParam != NULL);
    double gflops = 0.0;
    
    DEBUG_INFO("oplib_layer_relu param : IN=[%d],IH=[%d],IW=[%d],IC=[%d],OH=[%d],OW=[%d],OC=[%d],gflops=[%.6lf]\n", 
               pParam->param_N, 
               pParam->param_IH, 
               pParam->param_IW, 
               pParam->param_IC, 
               pParam->param_OH, 
               pParam->param_OW, 
               pParam->param_OC, 
               gflops);

    return gflops;
}
