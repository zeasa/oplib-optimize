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

    /*pooling variable*/
    int N  = pParam_pool->param_N ;
    int IC = pParam_pool->param_IC;
    int IH = pParam_pool->param_IH;
    int IW = pParam_pool->param_IW;
    int OC = pParam_pool->param_OC;
    int OH = pParam_pool->param_OH;
    int OW = pParam_pool->param_OW;
    int KH = pParam_pool->param_KH;
    int KW = pParam_pool->param_KW;
    int SH = pParam_pool->param_SH;
    int SW = pParam_pool->param_SW;

    int n, oc, oh, ow, kh, kw, iw, ih;
    FLOAT_T pooling_window = 1.0 / (KH*KW);
    int ICUBE  = IC*IW*IH;
    int ISLICE = IC*IW;
    int OCUBE  = OC*OW*OH;
    int OSLICE = OC*OW;

    /*conv variable*/
    int N_C  = pParam_conv->param_N ;// batch size
    int OC_C = pParam_conv->param_OC;// output channels
    int OH_C = pParam_conv->param_OH;// output height
    int OW_C = pParam_conv->param_OW;// output width
    int KH_C = pParam_conv->param_KH;// weights height
    int KW_C = pParam_conv->param_KW;// weights width
    int IC_C = pParam_conv->param_IC;// input  channels
    int IH_C = pParam_conv->param_IH;// input  height
    int IW_C = pParam_conv->param_IW;// input  width
    int KCUBE_C  = IC_C*KW_C*KH_C;
    int KSLICE_C = IC_C*KW_C;
    int ICUBE_C  = IC_C*IW_C*IH_C;
    int ISLICE_C = IC_C*IW_C;
    int OCUBE_C  = OC_C*OW_C*OH_C;
    int OSLICE_C = OC_C*OW_C;
    int KW_HALF_C = (KW_C+1)/2 - 1;
    int KH_HALF_C = (KH_C+1)/2 - 1;
    int kh_c, kw_c, ic_c, iw_c, ih_c;

    /*pool*/
    for(n = 0; n < N; ++n)
    {
        for(oh = 0; oh < OH; ++oh)
        {
            for(ow = 0; ow < OW; ++ow)
            {
                for(oc = 0; oc < OC; ++oc)
                {
                    FLOAT_T psum = 0;
                    FLOAT_T bias_oc = pbuf_bs[oc];

                    for(kh = 0; kh < KH; ++kh)
                    {
                        for(kw = 0; kw < KW; ++kw)
                        {
                            /*calculate the source data memory location*/
                            int iw = ow*SW + kw;
                            int ih = oh*SH + kh;
                            if( (iw>=IW) || (ih>=IH) )
                                continue;
                            
                            /*calculate the conv*/
                            FLOAT_T psum_c = 0;
                            for(kh_c = 0; kh_c < KH_C; ++kh_c)
                            {
                                for(kw_c = 0; kw_c < KW_C; ++kw_c)
                                {
                                    for(ic_c = 0; ic_c < IC_C; ++ic_c)
                                    {
                                        /*calculate the source data memory location*/
                                        iw_c = iw + (kw_c - KW_HALF_C);
                                        ih_c = ih + (kh_c - KH_HALF_C);
                                        if( (iw_c<0) || (iw_c>=IW_C) || (ih_c<0) || (ih_c>=IH_C) )
                                            continue;

                                        /*fetch source data from memory and do the real calculation*/
                                        psum_c += pbuf_in[ICUBE_C*n  + ISLICE_C*ih_c + IC_C*iw_c + ic_c] * 
                                                  pbuf_wt[KCUBE_C*oc + KSLICE_C*kh_c + IC_C*kw_c + ic_c];
                                    }
                                }
                            }
                            psum_c += bias_oc;
                            /*endof conv calculation*/

                            /*calculate the relu on the result of conv*/
                            psum_c = (psum_c <= 0) ? 0 : psum_c;

                            /*add the conv+relu result into the pooling window psum*/
                            psum += psum_c;
                        }
                    }

                    /*store the result to memory*/
                    pbuf_out[OCUBE*n + OSLICE*oh + OC*ow + oc] = psum * pooling_window;
                }
            }
        }        
    }
}

void oplib_layer_fused_conv2d_relu_avgpool_forward_omp(
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

    /*pooling variable*/
    int N  = pParam_pool->param_N ;
    int IC = pParam_pool->param_IC;
    int IH = pParam_pool->param_IH;
    int IW = pParam_pool->param_IW;
    int OC = pParam_pool->param_OC;
    int OH = pParam_pool->param_OH;
    int OW = pParam_pool->param_OW;
    int KH = pParam_pool->param_KH;
    int KW = pParam_pool->param_KW;
    int SH = pParam_pool->param_SH;
    int SW = pParam_pool->param_SW;

    int n, oc, oh, ow, kh, kw, iw, ih;
    FLOAT_T pooling_window = 1.0 / (KH*KW);
    int ICUBE  = IC*IW*IH;
    int ISLICE = IC*IW;
    int OCUBE  = OC*OW*OH;
    int OSLICE = OC*OW;

    /*conv variable*/
    int N_C  = pParam_conv->param_N ;// batch size
    int OC_C = pParam_conv->param_OC;// output channels
    int OH_C = pParam_conv->param_OH;// output height
    int OW_C = pParam_conv->param_OW;// output width
    int KH_C = pParam_conv->param_KH;// weights height
    int KW_C = pParam_conv->param_KW;// weights width
    int IC_C = pParam_conv->param_IC;// input  channels
    int IH_C = pParam_conv->param_IH;// input  height
    int IW_C = pParam_conv->param_IW;// input  width
    int KCUBE_C  = IC_C*KW_C*KH_C;
    int KSLICE_C = IC_C*KW_C;
    int ICUBE_C  = IC_C*IW_C*IH_C;
    int ISLICE_C = IC_C*IW_C;
    int OCUBE_C  = OC_C*OW_C*OH_C;
    int OSLICE_C = OC_C*OW_C;
    int KW_HALF_C = (KW_C+1)/2 - 1;
    int KH_HALF_C = (KH_C+1)/2 - 1;
    int kh_c, kw_c, ic_c, iw_c, ih_c;

    /*pool*/
    #pragma omp parallel for collapse(2) private(n, oc, oh, ow, kh, kw, iw, ih, kh_c, kw_c, ic_c, iw_c, ih_c)
    for(n = 0; n < N; ++n)
    {
        for(oh = 0; oh < OH; ++oh)
        {
            for(ow = 0; ow < OW; ++ow)
            {
                for(oc = 0; oc < OC; ++oc)
                {
                    FLOAT_T psum = 0;
                    FLOAT_T bias_oc = pbuf_bs[oc];

                    for(kh = 0; kh < KH; ++kh)
                    {
                        for(kw = 0; kw < KW; ++kw)
                        {
                            /*calculate the source data memory location*/
                            int iw = ow*SW + kw;
                            int ih = oh*SH + kh;
                            if( (iw>=IW) || (ih>=IH) )
                                continue;
                            
                            /*calculate the conv*/
                            FLOAT_T psum_c = 0;
                            for(kh_c = 0; kh_c < KH_C; ++kh_c)
                            {
                                for(kw_c = 0; kw_c < KW_C; ++kw_c)
                                {
                                    for(ic_c = 0; ic_c < IC_C; ++ic_c)
                                    {
                                        /*calculate the source data memory location*/
                                        iw_c = iw + (kw_c - KW_HALF_C);
                                        ih_c = ih + (kh_c - KH_HALF_C);
                                        if( (iw_c<0) || (iw_c>=IW_C) || (ih_c<0) || (ih_c>=IH_C) )
                                            continue;

                                        /*fetch source data from memory and do the real calculation*/
                                        psum_c += pbuf_in[ICUBE_C*n  + ISLICE_C*ih_c + IC_C*iw_c + ic_c] * 
                                                  pbuf_wt[KCUBE_C*oc + KSLICE_C*kh_c + IC_C*kw_c + ic_c];
                                    }
                                }
                            }
                            psum_c += bias_oc;
                            /*endof conv calculation*/

                            /*calculate the relu on the result of conv*/
                            psum_c = (psum_c <= 0) ? 0 : psum_c;

                            /*add the conv+relu result into the pooling window psum*/
                            psum += psum_c;
                        }
                    }

                    /*store the result to memory*/
                    pbuf_out[OCUBE*n + OSLICE*oh + OC*ow + oc] = psum * pooling_window;
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
    double gflops_conv, gflops_relu, gflops_pool;

    gflops_conv = 2.0d * pParam_conv->param_N * pParam_conv->param_OC * pParam_conv->param_OW * 
           pParam_conv->param_OH * pParam_conv->param_KW * pParam_conv->param_KH * pParam_conv->param_IC / (1.0*1000*1000*1000);

    DEBUG_INFO("oplib_layer_fused_conv_relu_pool.conv param : IN=[%d],IH=[%d],IW=[%d],IC=[%d],KW=[%d],KH=[%d],OC=[%d],gflops=[%.6lf]\n", 
               pParam_conv->param_N, 
               pParam_conv->param_IH, 
               pParam_conv->param_IW, 
               pParam_conv->param_IC, 
               pParam_conv->param_KW, 
               pParam_conv->param_KH, 
               pParam_conv->param_OC, 
               gflops_conv);

    gflops_relu = 1.0d * pParam_relu->param_N * pParam_relu->param_IC * pParam_relu->param_IW * pParam_relu->param_IH / (1.0*1000*1000*1000);
    
    DEBUG_INFO("oplib_layer_fused_conv_relu_pool.relu param : IN=[%d],IH=[%d],IW=[%d],IC=[%d],OH=[%d],OW=[%d],OC=[%d],gflops=[%.6lf]\n", 
               pParam_relu->param_N, 
               pParam_relu->param_IH, 
               pParam_relu->param_IW, 
               pParam_relu->param_IC, 
               pParam_relu->param_OH, 
               pParam_relu->param_OW, 
               pParam_relu->param_OC, 
               gflops_relu);

    gflops_pool = 1.0d * pParam_pool->param_N * pParam_pool->param_OC * pParam_pool->param_OW * pParam_pool->param_OH * 
                    pParam_pool->param_KH * pParam_pool->param_KW / (1.0*1000*1000*1000);
    
    DEBUG_INFO("oplib_layer_fused_conv_relu_pool.pool param : IN=[%d],IH=[%d],IW=[%d],IC=[%d],OH=[%d],OW=[%d],OC=[%d],gflops=[%.6lf]\n", 
               pParam_pool->param_N, 
               pParam_pool->param_IH, 
               pParam_pool->param_IW, 
               pParam_pool->param_IC, 
               pParam_pool->param_OH, 
               pParam_pool->param_OW, 
               pParam_pool->param_OC, 
               gflops_pool);

    return gflops_conv+gflops_relu+gflops_pool;
}