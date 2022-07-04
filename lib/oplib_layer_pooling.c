#include "oplib_common.h"
#include "oplib_interface.h"

void oplib_layer_avgpool_forward(const strAvgPoolParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    assert((pParam != NULL) && (pbuf_in != NULL) && (pbuf_out != NULL));

    int IC = pParam->param_IC;
    int IH = pParam->param_IH;
    int IW = pParam->param_IW;
    int OC = pParam->param_OC;
    int OH = pParam->param_OH;
    int OW = pParam->param_OW;
    int KH = pParam->param_KH;
    int KW = pParam->param_KW;
    int SH = pParam->param_SH;
    int SW = pParam->param_SW;
    int oc, oh, ow, kh, kw;
    int sz_window = KH*KW;


    for(oh = 0; oh < OH; ++oh)
    {
        for(ow = 0; ow < OW; ++ow)
        {
            for(oc = 0; oc < OC; ++oc)
            {
                float psum = 0;

                for(kh = 0; kh < KH; ++kh)
                {
                    for(kw = 0; kw < KW; ++kw)
                    {
                        /*calculate the source data memory location*/
                        int iw = ow*SW + kw;
                        int ih = oh*SH + kh;
                        if( (iw>=IW) || (ih>=IH) )
                            continue;
                        
                        /*fetch source data from memory and do the real calculation*/
                        psum += pbuf_in[IC*IW*ih + IC*iw + oc];
                    }
                }

                /*store the result to memory*/
                pbuf_out[OC*OW*oh + OC*ow + oc] = psum / sz_window;
            }
        }
    }

}

double oplib_layer_avgpool_report_property(const strAvgPoolParam_t *pParam)
{
    assert(pParam != NULL);
    double gflops = 0.0;
    
    DEBUG_INFO("oplib_layer_avgpool param : IN=[%d],IH=[%d],IW=[%d],IC=[%d],OH=[%d],OW=[%d],OC=[%d],gflops=[%.6lf]\n", 
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