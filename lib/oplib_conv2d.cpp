#include <stdlib.h>
#include <stdio.h>
#include "oplib_common.h"
#include "oplib_conv2d.h"


void dump_nhwc_fp32(const strDimNHWC_t *pDim, FLOAT_T *pbuf, const char *strTensorName, int enable)
{
    int N = pDim->n;
    int C = pDim->c;
    int H = pDim->h;
    int W = pDim->w;
    int i_n, i_c, i_h, i_w;

    if(enable)
    {
        printf("\n\n<Tensor(%s)[%d,%d,%d,%d]>", strTensorName, N,C,H,W);
        for(i_n = 0; i_n < N; ++i_n)
        {
            printf("\n*******n[%d]************************************\n", i_n);
            for(i_c = 0; i_c < C; ++i_c)
            {
                printf(" ======i_c[%d]====================================\n", i_c);
                for(i_h = 0; i_h < H; ++i_h)
                {
                    printf(" ");
                    for(i_w = 0; i_w < W; ++i_w)
                    {
                        printf("%.2f ", pbuf[C*W*H*i_n + C*W*i_h + C*i_w + i_c]);
                    }
                    printf("\n");
                }   
            }
        }
    }
}

void gen_nhwc_fp32(const strDimNHWC_t *pDim, FLOAT_T *pbuf)
{
    int N = pDim->n;
    int C = pDim->c;
    int H = pDim->h;
    int W = pDim->w;
    int i_n, i_c, i_h, i_w;
    FLOAT_T cnt = 1.0;

    for(i_n=0;i_n<N;++i_n)
    {
        for(i_c=0;i_c<C;++i_c)
        {
            for(i_h=0;i_h<H;++i_h)
            {
                for(i_w=0;i_w<W;++i_w)
                {
                    pbuf[C*W*H*i_n + C*W*i_h + C*i_w + i_c] = cnt;
                    cnt += 0.1;
                }
            }   
        }
    }
}

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

double get_cpu_peak_gflops_avx2()
{
    PROF_TMR_DECL();
    //DEBUG_INFO("get_cpu_peak_gflops_avx2.........\n");

    PROF_TMR_START();
    __asm__(
        "mov $1000000000, %rax;"
        "vxorps %ymm0, %ymm0, %ymm0;"
        "vxorps %ymm1, %ymm1, %ymm1;"
        "vxorps %ymm2, %ymm2, %ymm2;"
        "vxorps %ymm3, %ymm3, %ymm3;"
        "loop1:"
        "vmulps %ymm1, %ymm1, %ymm0;"
        "vaddps %ymm3, %ymm3, %ymm2;"
        "subq $0x1, %rax;"
        "jne loop1;"
    );
    PROF_TMR_END();

    DEBUG_INFO("peak avx2 vmul+vadd computation performance(1 thread) is [%lf] GFLOPS\n", (8+8)*1000000000.0/PROF_TMR_VALSEC/1000000000);
}

double get_cpu_peak_gflops_fpu()
{
    PROF_TMR_DECL();
    //DEBUG_INFO("get_cpu_peak_gflops_fpu.........\n");

    PROF_TMR_START();
    __asm__(
        "mov $1000000000, %rax;"
        "pxor  %xmm0, %xmm0;"
        "pxor  %xmm1, %xmm1;"
        "pxor  %xmm2, %xmm2;"
        "pxor  %xmm3, %xmm3;"
        "pxor  %xmm4, %xmm4;"
        "pxor  %xmm5, %xmm5;"
        "pxor  %xmm6, %xmm6;"
        "pxor  %xmm7, %xmm7;"
        "loop2:"
        "mulss %xmm0, %xmm0;"
        "mulss %xmm1, %xmm1;"
        "mulss %xmm2, %xmm2;"
        "mulss %xmm3, %xmm3;"
        "addss %xmm4, %xmm4;"
        "addss %xmm5, %xmm5;"
        "addss %xmm6, %xmm6;"
        "addss %xmm7, %xmm7;"
        "subq $0x1, %rax;"
        "jne loop2;"
    );
    PROF_TMR_END();

    DEBUG_INFO("peak fpu computation performance(1 thread) is [%lf] GFLOPS\n", (4+4)*1000000000.0/PROF_TMR_VALSEC/1000000000);
}

int oplib_conv2d_demo(int a, int b)
{
    return a+b;
}
