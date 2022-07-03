#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <mkl.h>
#include "oplib_conv2d.h"

#define __DEBUG
#ifdef  __DEBUG
#define DEBUG_INFO(format, ...)		printf("[DEBUG]: " format, ##__VA_ARGS__)
#else
#define DEBUG_INFO(format, ...)
#endif

#define FLOAT_T             float

#define PROF_TMR_DECL()     struct timeval stime, etime, diff;double timeinsec, perf, time_st, time_end
#define PROF_TMR_START()    gettimeofday(&stime, NULL);time_st  = dsecnd()
#define PROF_TMR_END()      time_end = dsecnd();gettimeofday(&etime,NULL);timersub(&etime, &stime, &diff);timeinsec=(diff.tv_sec*1000+diff.tv_usec/1000)/1000.0;
#define PROF_TMR_VALSEC     (time_end - time_st)

#define MEM_LAYOUT_NHWC     (0)
#define MEM_LAYOUT_NCHW     (1)
#define MEM_LAYOUT_NHWC8    (2)

typedef struct 
{
    int param_N    ;// batch size
    int param_IC   ;// input channels
    int param_IH   ;// input height
    int param_IW   ;// input width
    int param_OC   ;// output channels
    int param_OH   ;// output height
    int param_OW   ;// output width
    int param_KH   ;// weights height
    int param_KW   ;// weights width
    int param_PH_L ;// height padding: left
    int param_PH_R ;// height padding: right
    int param_PW_L ;// width padding: left
    int param_PW_R ;// width padding: right
    int param_SH   ;// height-wise stride
    int param_SW   ;// width-wise stride
}strConv2Dparam_t;



#define CONST_N     (4)// batch size
#define CONST_IC    (64)// input channels
#define CONST_IH    (1024)// input height
#define CONST_IW    (1024)// input width
#define CONST_OC    (64)// output channels
#define CONST_OH    ()// output height
#define CONST_OW    ()// output width
#define CONST_KH    (3)// weights height
#define CONST_KW    (3)// weights width
#define CONST_PT    (1)// padding top
#define CONST_PB    (1)// padding bot
#define CONST_PL    (1)// padding left
#define CONST_PR    (1)// padding right
#define CONST_SH    ((CONST_IH - CONST_KH + CONST_PT + CONST_PB) / CONST_SH + 1)
#define CONST_SW    ((CONST_IW - CONST_KW + CONST_PL + CONST_PR) / CONST_SW + 1)

#define IN  (2)
#define IC  (8)
#define IH  (8)
#define IW  (8)
#define OC  (8)
#define KW  (3)
#define KH  (3)
#define OH  (IH)
#define OW  (IW)

void dump_nhwc_fp32(int N, int C, int H, int W, FLOAT_T *pbuf, const char *strTensorName);
void gen_nhwc_fp32(int N, int C, int H, int W, FLOAT_T *pbuf);
int conv2d_3x3_s1(strConv2Dparam_t *pParam, 
              FLOAT_T *pbuf_in, 
              FLOAT_T *pbuf_out, 
              FLOAT_T *pbuf_wt,
              FLOAT_T *pbuf_bs);
double get_cpu_peak_computation_capability_in_gflops();

int main() 
{
    int n, c, h, w;
    FLOAT_T *pifm = NULL;
    FLOAT_T *pofm = NULL;
    FLOAT_T *pwt  = NULL;
    FLOAT_T *pbs  = NULL;
    PROF_TMR_DECL();


    DEBUG_INFO("hello example_oplib_conv2d\n");
    //DEBUG_INFO("the result is %d\n", oplib_conv2d(11, 22));

#if 0
    pifm = (FLOAT_T*)malloc(IN*IC*IW*IH*sizeof(FLOAT_T));
    if(pifm == NULL)
        perror("ifm malloc failed!");

    pwt  = (FLOAT_T*)malloc(OC*KW*KH*IC*sizeof(FLOAT_T));
    if(pwt == NULL)
        perror("pwt malloc failed!");

    pofm = (FLOAT_T*)malloc(IN*OC*OW*OH*sizeof(FLOAT_T));
    if(pofm == NULL)
        perror("pofm malloc failed!");

    n = IN;
    c = IC;
    h = IH;
    w = IW;
    gen_nhwc_fp32(n, c, h, w, pifm);
    dump_nhwc_fp32(n, c, h, w, pifm, "ifm");

    n = OC;
    c = IC;
    h = KH;
    w = KW;
    gen_nhwc_fp32(n, c, h, w, pwt);
    dump_nhwc_fp32(n, c, h, w, pwt, "weight");
    
    PROF_TMR_START();
    for(int i=0;i<10000;i++)
    {
        conv2d_3x3_s1(NULL, 
                pifm, 
                pofm, 
                pwt,
                NULL); 
    }
    PROF_TMR_END();
    DEBUG_INFO("conv2d_3x3_s1() cost %lf seconds\n", PROF_TMR_VALSEC);

    n = IN;
    c = OC;
    h = OH;
    w = OW;
    dump_nhwc_fp32(n, c, h, w, pofm, "ofm");

    free(pifm);
#endif

    get_cpu_peak_computation_capability_in_gflops();
    return 0;
}

void dump_nhwc_fp32(int N, int C, int H, int W, FLOAT_T *pbuf, const char *strTensorName)
{
    int n, c, h, w;

    printf("\n\n<Tensor(%s)[%d,%d,%d,%d]>", strTensorName, N,C,H,W);
    for(n=0;n<N;++n)
    {
        printf("\n*******n[%d]************************************\n", n);
        for(c=0;c<C;++c)
        {
            printf(" ======c[%d]====================================\n", c);
            for(h=0;h<H;++h)
            {
                printf(" ");
                for(w=0;w<W;++w)
                {
                    printf("%.2f ", pbuf[C*W*H*n + C*W*h + C*w + c]);
                }
                printf("\n");
            }   
        }
    }
}

void gen_nhwc_fp32(int N, int C, int H, int W, FLOAT_T *pbuf)
{
    FLOAT_T cnt = 1.0;
    int n, c, h, w;

    for(n=0;n<N;++n)
    {
        for(c=0;c<C;++c)
        {
            for(h=0;h<H;++h)
            {
                for(w=0;w<W;++w)
                {
                    pbuf[C*W*H*n + C*W*h + C*w + c] = cnt;
                    cnt += 0.1;
                }
            }   
        }
    }
}

//  convolution operation
//  apply kernel on input and save results on output
int conv2d_3x3_s1(strConv2Dparam_t *pParam, 
              FLOAT_T *pbuf_in, 
              FLOAT_T *pbuf_out, 
              FLOAT_T *pbuf_wt,
              FLOAT_T *pbuf_bs) 
{
    int iOW, iOH, iOC;
    int iKW, iKH, iIC;

    for(iOC = 0; iOC < OC; ++iOC)
    {
        for(iOH = 0; iOH < OH; ++iOH)
        {
            for(iOW = 0; iOW < OH; ++iOW)
            {
                FLOAT_T psum = 0;

                for(iKH = 0; iKH < KH; ++iKH)
                {
                    for(iKW = 0; iKW < KW; ++iKW)
                    {
                        for(iIC = 0; iIC < OH; ++iIC)
                        {
                            int iIW = iOW - (iKW - ((KW+1)/2 - 1));
                            int iIH = iOH - (iKH - ((KH+1)/2 - 1));
                            if( (iIW<0) || (iIW>=iOW) || (iIH<0) || (iIH>=iOH) )
                                continue;
                            psum += pbuf_in[IC*IW*iIH + IC*iIW + iIC] * 
                                    pbuf_wt[KH*KW*OC*iOC + IC*KW*iKH + IC*iKW + iIC];
                        }
                    }
                }

                pbuf_out[OC*OW*iOH + OC*iOW + iOC] = psum;
            }
        }
    }

    return 0;
}

double get_cpu_peak_computation_capability_in_gflops()
{
    PROF_TMR_DECL();

    DEBUG_INFO("get_cpu_peak_computation_capability_in_gflops.........\n");

    PROF_TMR_START();
    __asm__(
        "mov $1000000000, %rax;"
        "vxorps %ymm0, %ymm0, %ymm0;"
        "vxorps %ymm1, %ymm1, %ymm1;"
        "vxorps %ymm2, %ymm2, %ymm2;"
        "vxorps %ymm3, %ymm3, %ymm3;"
        "loop:"
        "vmulps %ymm1, %ymm1, %ymm0;"
        "vaddps %ymm3, %ymm3, %ymm2;"
        "subq $0x1, %rax;"
        "jne loop;"
    );
    PROF_TMR_END();

    DEBUG_INFO("peak avx2 vmul+vadd computation performance(1 thread) is [%lf] GFLOPS\n", (8+8)*1000000000.0/PROF_TMR_VALSEC/100000000);
}