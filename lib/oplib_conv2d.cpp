#include <stdlib.h>
#include <stdio.h>
#include "oplib_common.h"
#include "oplib_interface.h"

//  convolution operation
//  apply kernel on input and save results on output
int oplib_layer_conv2d_3x3_s1(const strConv2DParam_t *pParam, 
              FLOAT_T *pbuf_in, 
              FLOAT_T *pbuf_out, 
              FLOAT_T *pbuf_wt,
              FLOAT_T *pbuf_bs) 
{
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

    return 0;
}

int oplib_layer_avgpool_2x2_s1(const strAvgPoolParam_t *pParam, FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
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

int oplib_layer_relu(const strReluParam_t *pParam, FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    int IC = pParam->param_IC;
    int IH = pParam->param_IH;
    int IW = pParam->param_IW;
    int i;

    for(i=0; i<IC*IH*IW; ++i)
    {
        pbuf_out[i] = (pbuf_in[i] <= 0) ? 0 : pbuf_in[i];
    }
}

int oplib_conv2d_avgpool_relu(const strConv2DParam_t *pParam, 
              FLOAT_T *pbuf_in, 
              FLOAT_T *pbuf_out, 
              FLOAT_T *pbuf_wt,
              FLOAT_T *pbuf_bs)
{

}

double conv2d_calc_gflops(const strConv2DParam_t *pParam)
{
    return 2.0d * pParam->param_N * pParam->param_OC * pParam->param_OW * 
           pParam->param_OH * pParam->param_KW * pParam->param_KH * pParam->param_IC / (1.0*1000*1000*1000);
}

