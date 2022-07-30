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
#if 0
//  convolution operation
//  apply kernel on input and save results on output
void oplib_layer_conv2d_s1_forward_tensorcore(const strConv2DParam_t *pParam, 
              const INT8_T *pbuf_in, 
                    INT8_T *pbuf_out, 
              const INT8_T *pbuf_wt,
              const INT8_T *pbuf_bs) 
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
        for(oc = 0; oc < (OC / 8); ++oc)
        {
            INT8_T bias_oc[8] = pbuf_bs[oc];

            for(oh = 0; oh < OH; ++oh)
            {
                for(ow = 0; ow < (OW / 8); ++ow)
                {
                    INT32VEC8_T psum[8] = 0;

                    //kernel conv
                    for(kh = 0; kh < KH; ++kh)
                    {
                        for(kw = 0; kw < KW; ++kw)
                        {
                            for(ic = 0; ic < (IC / 8); ++ic)
                            {
                                //load wt from ddr to sram
                                INT8VEC8_T tensor_wt[8];
                                void *pWtAddr = KCUBE * oc * 8 + KSLICE * kh + IC * kw + ic * 8;
                                intrinsic_int8vec8load(tensor_wt[0], pWtAddr);
                                intrinsic_int8vec8load(tensor_wt[1], pWtAddr+KCUBE*1);
                                intrinsic_int8vec8load(tensor_wt[2], pWtAddr+KCUBE*2);
                                intrinsic_int8vec8load(tensor_wt[3], pWtAddr+KCUBE*3);
                                intrinsic_int8vec8load(tensor_wt[4], pWtAddr+KCUBE*4);
                                intrinsic_int8vec8load(tensor_wt[5], pWtAddr+KCUBE*5);
                                intrinsic_int8vec8load(tensor_wt[6], pWtAddr+KCUBE*6);
                                intrinsic_int8vec8load(tensor_wt[7], pWtAddr+KCUBE*7);

                                INT8VEC8_T tensor_fm[8];
                                void *pIfmAddr = ICUBE * n + ISLICE * ih + IC * iw + ic;
                                intrinsic_int8vec8load(tensor_fm[0], pIfmAddr);
                                intrinsic_int8vec8load(tensor_fm[1], pIfmAddr+ISLICE/8*1);
                                intrinsic_int8vec8load(tensor_fm[2], pIfmAddr+ISLICE/8*2);
                                intrinsic_int8vec8load(tensor_fm[3], pIfmAddr+ISLICE/8*3);
                                intrinsic_int8vec8load(tensor_fm[4], pIfmAddr+ISLICE/8*4);
                                intrinsic_int8vec8load(tensor_fm[5], pIfmAddr+ISLICE/8*5);
                                intrinsic_int8vec8load(tensor_fm[6], pIfmAddr+ISLICE/8*6);
                                intrinsic_int8vec8load(tensor_fm[7], pIfmAddr+ISLICE/8*7);

                                /*calculate the source data memory location*/
                                //iw = ow + (kw - KW_HALF);
                                //ih = oh + (kh - KH_HALF);
                                //if( (iw<0) || (iw>=IW) || (ih<0) || (ih>=IH) )
                                //    continue;

                                /*fetch source data from memory and do the real calculation*/
                                //psum += pbuf_in[ICUBE*n  + ISLICE*ih + IC*iw + ic] * 
                                //        pbuf_wt[KCUBE*oc + KSLICE*kh + IC*kw + ic];
                                intrinsic_tensorcore_gemm(tensor_fm, tensor_wt, psum);
                            }
                        }
                    }

                    /*add bias store the result to memory*/
                    //pbuf_out[OCUBE*n + OSLICE*oh + OC*ow + oc] = psum + bias_oc;

                    /*store result from sram to ddr*/
                    void *pOfmAddr = OCUBE*n + OSLICE*oh + OC*ow + oc;
                    intrinsic_int8vec8store(psum[0], pOfmAddr);
                    intrinsic_int8vec8store(psum[1], pOfmAddr+OSLICE/8*1);
                    intrinsic_int8vec8store(psum[2], pOfmAddr+OSLICE/8*2);
                    intrinsic_int8vec8store(psum[3], pOfmAddr+OSLICE/8*3);
                    intrinsic_int8vec8store(psum[4], pOfmAddr+OSLICE/8*4);
                    intrinsic_int8vec8store(psum[5], pOfmAddr+OSLICE/8*5);
                    intrinsic_int8vec8store(psum[6], pOfmAddr+OSLICE/8*6);
                    intrinsic_int8vec8store(psum[7], pOfmAddr+OSLICE/8*7);
                }
            }
        }        
    }

}
#endif

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
           pParam->param_OH * pParam->param_KW * pParam->param_KH * pParam->param_IC / (1.0*1000*1000*1000);

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

