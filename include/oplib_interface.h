#ifndef _OPLIB_INTERFACE_H__
#define _OPLIB_INTERFACE_H__

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
void   oplib_dump_nhwc_fp32(const strDimNHWC_t *p_dim, const FLOAT_T *pbuf, const char *strTensorName, int enable);
void   oplib_gen_nhwc_fp32(const strDimNHWC_t *p_dim, FLOAT_T *pbuf);
double oplib_get_cpu_peak_gflops_avx2();
double oplib_get_cpu_peak_gflops_fpu();

/*layer interface*/
/*conv2d layer*/
void   oplib_layer_conv2d_s1_forward(const strConv2DParam_t *pParam, 
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs);
void   oplib_layer_conv2d_s1_forward_omp(const strConv2DParam_t *pParam, 
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs);
double oplib_layer_conv2d_s1_report_property(const strConv2DParam_t *pParam);

/*relu layer*/
void   oplib_layer_relu_forward(const strReluParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out);
void   oplib_layer_relu_forward_omp(const strReluParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out);
double oplib_layer_relu_report_property(const strReluParam_t *pParam);

/*avgpool layer*/
void   oplib_layer_avgpool_forward(const strAvgPoolParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out);
void   oplib_layer_avgpool_forward_omp(const strAvgPoolParam_t *pParam, const FLOAT_T *pbuf_in, FLOAT_T *pbuf_out);
double oplib_layer_avgpool_report_property(const strAvgPoolParam_t *pParam);

/*fused conv2d_relu_pooling layer*/
void oplib_layer_fused_conv2d_relu_avgpool_forward(const strConv2DParam_t *pParam_conv, 
              const strReluParam_t *pParam_relu, 
              const strAvgPoolParam_t *pParam_pool,
              const FLOAT_T *pbuf_in, 
                    FLOAT_T *pbuf_out, 
              const FLOAT_T *pbuf_wt,
              const FLOAT_T *pbuf_bs);
double oplib_layer_fused_conv2d_relu_avgpool_report_property(const strConv2DParam_t *pParam_conv, 
              const strReluParam_t *pParam_relu, 
              const strAvgPoolParam_t *pParam_pool);

/*other interface*/

#ifdef __cplusplus
}
#endif
#endif/*_OPLIB_INTERFACE_H__*/
