#include "oplib_common.h"
#include "oplib_interface.h"

void oplib_layer_fused_conv2d_relu_avgpool_forward(
              const strConv2DParam_t  *pParam_conv, 
              const strReluParam_t    *pParam_relu, 
              const strAvgPoolParam_t *pParam_pool,
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs)
{
    assert((pParam_conv != NULL) && (pParam_relu != NULL) && (pParam_pool != NULL) &&
           (pbuf_in != NULL) && (pbuf_out != NULL) && (pbuf_wt) && (pbuf_bs));

    int N  = pParam_conv->param_N ;// batch size
    int OC = pParam_conv->param_OC;// output channels
    int OH = pParam_conv->param_OH;// output height
    int OW = pParam_conv->param_OW;// output width
    int KH = pParam_conv->param_KH;// weights height
    int KW = pParam_conv->param_KW;// weights width
    int IC = pParam_conv->param_IC;// input  channels
    int IH = pParam_conv->param_IH;// input  height
    int IW = pParam_conv->param_IW;// input  width
    int n;
    int ow, oh, oc;
    int kw, kh, ic;

    for(n = 0; n < N; ++n)
    {
        for(oc = 0; oc < OC; ++oc)
        {
            for(oh = 0; oh < OH; ++oh)
            {
                for(ow = 0; ow < OW; ++ow)
                {
                    FLOAT_T psum = 0;

                    for(kh = 0; kh < KH; ++kh)
                    {
                        for(kw = 0; kw < KW; ++kw)
                        {
                            for(ic = 0; ic < IC; ++ic)
                            {
                                /*calculate the source data memory location*/
                                int iw = ow + (kw - ((KW+1)/2 - 1));
                                int ih = oh + (kh - ((KH+1)/2 - 1));
                                if( (iw<0) || (iw>=IW) || (ih<0) || (ih>=IH) )
                                    continue;

                                /*fetch source data from memory and do the real calculation*/
                                psum += pbuf_in[IC*IW*IH*n + IC*IW*ih + IC*iw + ic] * 
                                        pbuf_wt[KH*KW*OC*oc + IC*KW*kh + IC*kw + ic];
                            }
                        }
                    }

                    /*add bias and store the result to memory*/
                    pbuf_out[OC*OW*OH*n + OC*OW*oh + OC*ow + oc] = psum + pbuf_bs[oc];
                }
            }
        }        
    }

}

double oplib_layer_fused_conv2d_relu_avgpool_report_property(const strConv2DParam_t *pParam_conv, 
              const strReluParam_t *pParam_relu, 
              const strAvgPoolParam_t *pParam_pool)
{
    assert((pParam_conv != NULL) && (pParam_relu != NULL) && (pParam_pool != NULL));

    return 0.0;
}