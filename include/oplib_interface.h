#ifndef _OPLIB_CONV2D_H__
#define _OPLIB_CONV2D_H__

#ifdef __cplusplus
extern "C" {
#endif

/*data structure definition*/
typedef struct 
{
    int n;
    int h;
    int w;
    int c;
}strDimNHWC_t;

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
    int param_PT   ;// padding: left
    int param_PB   ;// padding: right
    int param_PL   ;// padding: left
    int param_PR   ;// padding: right
    int param_SH   ;// height-wise stride
    int param_SW   ;// width-wise stride
}strConv2DParam_t;

typedef struct 
{
    int param_N    ;// batch size
    int param_IC   ;// input channels
    int param_IH   ;// input height
    int param_IW   ;// input width
    int param_OC   ;// output channels
    int param_OH   ;// output height
    int param_OW   ;// output width
}strReluParam_t;

typedef struct 
{
    int param_N    ;// batch size
    int param_IC   ;// input channels
    int param_IH   ;// input height
    int param_IW   ;// input width
    int param_KH   ;// weights height
    int param_KW   ;// weights width
    int param_SH   ;// height-wise stride
    int param_SW   ;// width-wise stride
    int param_OC   ;// output channels
    int param_OH   ;// output height
    int param_OW   ;// output width
}strAvgPoolParam_t;

/*common interface*/
void dump_nhwc_fp32(const strDimNHWC_t *p_dim, FLOAT_T *pbuf, const char *strTensorName, int enable);
void gen_nhwc_fp32(const strDimNHWC_t *p_dim, FLOAT_T *pbuf);
double get_cpu_peak_gflops_avx2();
double get_cpu_peak_gflops_fpu();

/*layer interface*/
int  oplib_layer_conv2d_3x3_s1(const strConv2DParam_t *pParam, 
              FLOAT_T *pbuf_in, 
              FLOAT_T *pbuf_out, 
              FLOAT_T *pbuf_wt,
              FLOAT_T *pbuf_bs);
double conv2d_calc_gflops(const strConv2DParam_t *pParam);

/*other interface*/
int oplib_conv2d_demo(int a, int b);

#ifdef __cplusplus
}
#endif
#endif/*_OPLIB_CONV2D_H__*/
