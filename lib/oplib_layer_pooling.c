#include "oplib_common.h"
#include "oplib_interface.h"

void oplib_layer_avgpool_forward(const strAvgPoolParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    assert((pParam != NULL) && (pbuf_in != NULL) && (pbuf_out != NULL));

    int N  = pParam->param_N ;
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
    int n, oc, oh, ow, kh, kw;
    FLOAT_T pooling_window = 1.0 / (KH*KW);
    int ICUBE  = IC*IW*IH;
    int ISLICE = IC*IW;
    int OCUBE  = OC*OW*OH;
    int OSLICE = OC*OW;

    for(n = 0; n < N; ++n)
    {
        for(oh = 0; oh < OH; ++oh)
        {
            for(ow = 0; ow < OW; ++ow)
            {
                for(oc = 0; oc < OC; ++oc)
                {
                    FLOAT_T psum = 0;

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
                            psum += pbuf_in[ICUBE*n + ISLICE*ih + IC*iw + oc];
                        }
                    }

                    /*store the result to memory*/
                    pbuf_out[OCUBE*n + OSLICE*oh + OC*ow + oc] = psum * pooling_window;
                }
            }
        }        
    }

}

void oplib_layer_avgpool_forward_omp(const strAvgPoolParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out)
{
    assert((pParam != NULL) && (pbuf_in != NULL) && (pbuf_out != NULL));

    int N  = pParam->param_N ;
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
    int n, oc, oh, ow, kh, kw, iw, ih;
    FLOAT_T pooling_window = 1.0 / (KH*KW);
    int ICUBE  = IC*IW*IH;
    int ISLICE = IC*IW;
    int OCUBE  = OC*OW*OH;
    int OSLICE = OC*OW;

    #pragma omp parallel for collapse(2) private(n, oc, oh, ow, kh, kw, iw, ih)
    for(n = 0; n < N; ++n)
    {
        for(oh = 0; oh < OH; ++oh)
        {
            for(ow = 0; ow < OW; ++ow)
            {
                for(oc = 0; oc < OC; ++oc)
                {
                    FLOAT_T psum = 0;

                    for(kh = 0; kh < KH; ++kh)
                    {
                        for(kw = 0; kw < KW; ++kw)
                        {
                            /*calculate the source data memory location*/
                            iw = ow*SW + kw;
                            ih = oh*SH + kh;
                            if( (iw>=IW) || (ih>=IH) )
                                continue;
                            
                            /*fetch source data from memory and do the real calculation*/
                            psum += pbuf_in[ICUBE*n + ISLICE*ih + IC*iw + oc];
                        }
                    }

                    /*store the result to memory*/
                    pbuf_out[OCUBE*n + OSLICE*oh + OC*ow + oc] = psum * pooling_window;
                }
            }
        }        
    }

}


double oplib_layer_avgpool_report_property(const strAvgPoolParam_t *pParam)
{
    assert(pParam != NULL);
    double gflops = 1.0d * pParam->param_N * pParam->param_OC * pParam->param_OW * pParam->param_OH * 
                    pParam->param_KH * pParam->param_KW / (1.0*1000*1000*1000);
    
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