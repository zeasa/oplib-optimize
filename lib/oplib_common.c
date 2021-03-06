#include "oplib_common.h"
#include "oplib_interface.h"

#define N_LIMIT     (4)
#define C_LIMIT     (2)
#define H_LIMIT     (8)
#define W_LIMIT     (8)

void oplib_dump_nhwc_fp32(const strDimNHWC_t *pDim, const FLOAT_T *pbuf, const char *strTensorName, int enable)
{
    assert((pDim != NULL) && (pbuf != NULL));

    int N = pDim->n;
    int C = pDim->c;
    int H = pDim->h;
    int W = pDim->w;
    int i_n, i_c, i_h, i_w;
    
    int n_once_flag = 0;
    int c_once_flag = 0;
    int h_once_flag = 0;
    int w_once_flag = 0;

    if(enable)
    {
        printf("\n\n<Tensor(%s)[%d,%d,%d,%d]>", strTensorName, N,C,H,W);
        for(i_n = 0; i_n < N; ++i_n)
        {
            if((i_n < N_LIMIT) || (i_n == (N-1)) )
            {
                c_once_flag = 0;
                printf("\n*******n[%d]************************************\n", i_n);
                for(i_c = 0; i_c < C; ++i_c)
                {
                    if((i_c < C_LIMIT) || (i_c == (C-1)) )
                    {
                        h_once_flag = 0;
                        printf(" ======c[%d]====================================\n", i_c);
                        for(i_h = 0; i_h < H; ++i_h)
                        {
                            if((i_h < H_LIMIT) || (i_h == (H-1)) )
                            {
                                w_once_flag = 0;
                                printf(" ");
                                for(i_w = 0; i_w < W; ++i_w)
                                {
                                    if((i_w < W_LIMIT) || (i_w == (W-1)) )
                                    {
                                        printf("%.2f ", pbuf[C*W*H*i_n + C*W*i_h + C*i_w + i_c]);
                                    }
                                    else
                                    {
                                        if(w_once_flag == 0)
                                        {
                                            w_once_flag = 1;
                                            printf("... ");
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                if(h_once_flag == 0)
                                {
                                    h_once_flag = 1;
                                    printf(" ....\n");
                                }
                            }
                        }  
                    }
                    else
                    {
                        if(c_once_flag == 0)
                        {
                            c_once_flag = 1;
                            printf("\n .....\n\n");
                        }
                    }

                }
            }
            else
            {
                if(n_once_flag == 0)
                {
                    n_once_flag = 1;
                    printf("\n\n......\n\n");
                }
            }

        }
        printf("\n\n");
    }
}

void oplib_gen_nhwc_fp32(const strDimNHWC_t *pDim, FLOAT_T *pbuf)
{
    assert((pDim != NULL) && (pbuf != NULL));

    int N = pDim->n;
    int C = pDim->c;
    int H = pDim->h;
    int W = pDim->w;
    int i_n, i_c, i_h, i_w;
    FLOAT_T cnt = -0.8;

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
                    if(cnt >= 0.8)
                        cnt = -0.8;
                }
            }   
        }
    }
}

double oplib_get_cpu_peak_gflops_avx2()
{
    PROF_TMR_DECL();

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

    DEBUG_INFO("peak avx2 vmul+vadd computation performance(1 thread) is [%lf] GFLOPS/s\n", (8+8)*1000000000.0/PROF_TMR_VALSEC/1000000000);
}

double oplib_get_cpu_peak_gflops_fpu()
{
    PROF_TMR_DECL();

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

    DEBUG_INFO("peak fpu computation performance(1 thread) is [%lf] GFLOPS/s\n", (4+4)*1000000000.0/PROF_TMR_VALSEC/1000000000);
}
