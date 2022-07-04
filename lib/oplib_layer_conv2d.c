#include "oplib_common.h"
#include "oplib_interface.h"

//  convolution operation
//  apply kernel on input and save results on output
void oplib_layer_conv2d_3x3_s1_forward(const strConv2DParam_t *pParam, 
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs) 
{
    assert((pParam != NULL) && (pbuf_in != NULL) && 
           (pbuf_out != NULL) && (pbuf_wt) && (pbuf_bs));
    
    int OC = pParam->param_OC;
    int OH = pParam->param_OH;
    int OW = pParam->param_OW;
    int KH = pParam->param_KH;
    int KW = pParam->param_KW;
    int IC = pParam->param_IC;
    int IH = pParam->param_IH;
    int IW = pParam->param_IW;
    int i_ow, i_oh, i_oc;
    int i_kw, i_kh, i_ic;

    for(i_oc = 0; i_oc < OC; ++i_oc)
    {
        for(i_oh = 0; i_oh < OH; ++i_oh)
        {
            for(i_ow = 0; i_ow < OW; ++i_ow)
            {
                FLOAT_T psum = 0;

                for(i_kh = 0; i_kh < KH; ++i_kh)
                {
                    for(i_kw = 0; i_kw < KW; ++i_kw)
                    {
                        for(i_ic = 0; i_ic < IC; ++i_ic)
                        {
                            int i_iw = i_ow - (i_kw - ((KW+1)/2 - 1));
                            int i_ih = i_oh - (i_kh - ((KH+1)/2 - 1));
                            if( (i_iw<0) || (i_iw>=IW) || (i_ih<0) || (i_ih>=IH) )
                                continue;
                            psum += pbuf_in[IC*IW*i_ih + IC*i_iw + i_ic] * 
                                    pbuf_wt[KH*KW*OC*i_oc + IC*KW*i_kh + IC*i_kw + i_ic];
                        }
                    }
                }

                pbuf_out[OC*OW*i_oh + OC*i_ow + i_oc] = psum;
            }
        }
    }

}

double oplib_layer_conv2d_3x3_s1_report_property(const strConv2DParam_t *pParam)
{
    assert(pParam != NULL);
    double gflops = 2.0d * pParam->param_N * pParam->param_OC * pParam->param_OW * 
           pParam->param_OH * pParam->param_KW * pParam->param_KH * pParam->param_IC / (1.0*1000*1000*1000);;

    DEBUG_INFO("oplib_layer_conv2d_3x3_s1 param : IN=[%d],IH=[%d],IW=[%d],IC=[%d],KW=[%d],KH=[%d],OC=[%d],gflops=[%.6lf]\n", 
               pParam->param_N, 
               pParam->param_IH, 
               pParam->param_IW, 
               pParam->param_IC, 
               pParam->param_KW, 
               pParam->param_KH, 
               pParam->param_OC, 
               gflops);

    return gflops;
}

