#include "oplib_common.h"
#include "oplib_interface.h"

//  convolution operation
//  apply kernel on input and save results on output
void oplib_layer_conv2d_s1_forward(const strConv2DParam_t *pParam, 
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs) 
{
    assert((pParam != NULL) && (pbuf_in != NULL) && 
           (pbuf_out != NULL) && (pbuf_wt) && (pbuf_bs));
    
    int N  = pParam->param_N ;// batch size
    int OC = pParam->param_OC;// output channels
    int OH = pParam->param_OH;// output height
    int OW = pParam->param_OW;// output width
    int KH = pParam->param_KH;// weights height
    int KW = pParam->param_KW;// weights width
    int IC = pParam->param_IC;// input  channels
    int IH = pParam->param_IH;// input  height
    int IW = pParam->param_IW;// input  width
    int KCUBE  = IC*KW*KH;
    int KSLICE = IC*KW;
    int ICUBE  = IC*IW*IH;
    int ISLICE = IC*IW;
    int OCUBE  = OC*OW*OH;
    int OSLICE = OC*OW;
    int KW_HALF = (KW+1)/2 - 1;
    int KH_HALF = (KH+1)/2 - 1;
    int n, oc, oh, ow, kh, kw, ic, iw, ih;

    for(n = 0; n < N; ++n)
    {
        for(oc = 0; oc < OC; ++oc)
        {
            FLOAT_T bias_oc = pbuf_bs[oc];

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
                                iw = ow + (kw - KW_HALF);
                                ih = oh + (kh - KH_HALF);
                                if( (iw<0) || (iw>=IW) || (ih<0) || (ih>=IH) )
                                    continue;

                                /*fetch source data from memory and do the real calculation*/
                                psum += pbuf_in[ICUBE*n  + ISLICE*ih + IC*iw + ic] * 
                                        pbuf_wt[KCUBE*oc + KSLICE*kh + IC*kw + ic];
                            }
                        }
                    }

                    /*add bias store the result to memory*/
                    pbuf_out[OCUBE*n + OSLICE*oh + OC*ow + oc] = psum + bias_oc;
                }
            }
        }        
    }

}

void oplib_layer_conv2d_s1_forward_omp(const strConv2DParam_t *pParam, 
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs) 
{
    assert((pParam != NULL) && (pbuf_in != NULL) && 
           (pbuf_out != NULL) && (pbuf_wt) && (pbuf_bs));
    
    int N  = pParam->param_N ;// batch size
    int OC = pParam->param_OC;// output channels
    int OH = pParam->param_OH;// output height
    int OW = pParam->param_OW;// output width
    int KH = pParam->param_KH;// weights height
    int KW = pParam->param_KW;// weights width
    int IC = pParam->param_IC;// input  channels
    int IH = pParam->param_IH;// input  height
    int IW = pParam->param_IW;// input  width
    int KCUBE  = IC*KW*KH;
    int KSLICE = IC*KW;
    int ICUBE  = IC*IW*IH;
    int ISLICE = IC*IW;
    int OCUBE  = OC*OW*OH;
    int OSLICE = OC*OW;
    int KW_HALF = (KW+1)/2 - 1;
    int KH_HALF = (KH+1)/2 - 1;
    int n, oc, oh, ow, kh, kw, ic, iw, ih;

    #pragma omp parallel for collapse(2) private(n, oc, oh, ow, kh, kw, ic, iw, ih)
    for(n = 0; n < N; ++n)
    {
        for(oc = 0; oc < OC; ++oc)
        {
            FLOAT_T bias_oc = pbuf_bs[oc];

            //#pragma omp parallel for num_threads(8)
            for(oh = 0; oh < OH; ++oh)
            {
                //#pragma omp parallel for num_threads(8)
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
                                iw = ow + (kw - KW_HALF);
                                ih = oh + (kh - KH_HALF);
                                if( (iw<0) || (iw>=IW) || (ih<0) || (ih>=IH) )
                                    continue;

                                /*fetch source data from memory and do the real calculation*/
                                psum += pbuf_in[ICUBE*n  + ISLICE*ih + IC*iw + ic] * 
                                        pbuf_wt[KCUBE*oc + KSLICE*kh + IC*kw + ic];
                            }
                        }
                    }

                    /*add bias store the result to memory*/
                    pbuf_out[OCUBE*n + OSLICE*oh + OC*ow + oc] = psum + bias_oc;
                }
            }
        }        
    }

}


double oplib_layer_conv2d_s1_report_property(const strConv2DParam_t *pParam)
{
    assert(pParam != NULL);
    double gflops = 2.0d * pParam->param_N * pParam->param_OC * pParam->param_OW * 
           pParam->param_OH * pParam->param_KW * pParam->param_KH * pParam->param_IC / (1.0*1000*1000*1000);;

    DEBUG_INFO("oplib_layer_conv2d_s1 param : IN=[%d],IH=[%d],IW=[%d],IC=[%d],KW=[%d],KH=[%d],OC=[%d],gflops=[%.6lf]\n", 
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

