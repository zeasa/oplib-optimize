#include "argtable3.h"
#include "oplib_common.h"
#include "oplib_interface.h"
#include "benchmark_testcase.h"

#define __ARGTABLE

struct arg_lit  *help;
struct arg_lit  *version;
struct arg_lit  *debug;
struct arg_end  *argend;

const strConv2DParam_t conv2d_param = 
{
    CONV_N,  // batch size
    CONV_IC, // input channels
    CONV_IH, // input height
    CONV_IW, // input width
    CONV_OC, // output channels
    CONV_OH, // output height
    CONV_OW, // output width
    CONV_KH, // weights height
    CONV_KW, // weights width
    CONV_PT, // height padding: left
    CONV_PB, // height padding: right
    CONV_PL, // width padding: left
    CONV_PR, // width padding: right
    CONV_SH, // height-wise stride
    CONV_SW  // width-wise stride
};

const strReluParam_t relu_param = 
{
    RELU_N,  // batch size
    RELU_IC, // input channels
    RELU_IH, // input height
    RELU_IW, // input width
    RELU_OC, // output channels
    RELU_OH, // output height
    RELU_OW  // output width,
};

const strAvgPoolParam_t pool_param =  
{
    POOL_N,  // batch size
    POOL_IC, // input channels
    POOL_IH, // input height
    POOL_IW, // input width
    POOL_KH, // input height
    POOL_KW, // input width
    POOL_SH, // height-wise stride
    POOL_SW, // width-wise stride
    POOL_OC, // output channels
    POOL_OH, // output height
    POOL_OW  // output width
};

int main(int argc, char *argv[])
{
    int dump_enable = 0;
    int n, c, h, w;
    double cpu_gflops_avx2;
    double cpu_gflops_fpu;

    double conv_gflops;
    double relu_gflops;
    double pool_gflops;
    double conv_time_used;
    double relu_time_used;
    double pool_time_used;
    double conv_omp_time_used;
    double relu_omp_time_used;
    double pool_omp_time_used;

    FLOAT_T *pbuf_ifm_conv = NULL;
    FLOAT_T *pbuf_ofm_conv = NULL;
    FLOAT_T *pbuf_wt_conv  = NULL;
    FLOAT_T *pbuf_bs_conv  = NULL;
    FLOAT_T *pbuf_ifm_relu = NULL;
    FLOAT_T *pbuf_ofm_relu = NULL;
    FLOAT_T *pbuf_ifm_pool = NULL;
    FLOAT_T *pbuf_ofm_pool = NULL;

    ssize_t sz_ifm_conv, sz_ofm_conv;
    ssize_t sz_wt_conv, sz_bs_conv;
    ssize_t sz_ifm_relu;
    ssize_t sz_ofm_relu;
    ssize_t sz_ifm_pool;
    ssize_t sz_ofm_pool;

    strDimNHWC_t dim_nhwc;

    PROF_TMR_DECL();

    DEBUG_INFO("benchmark_net_conv2d_relu_pooling_nofuse...\n");
    DEBUG_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    //argment processing
#ifdef __ARGTABLE
    void *argtable[] = {
        help    = arg_lit0("h", "help",    "display this help and exit"),
        version = arg_lit0("v", "version", "display version info and exit"),
        debug   = arg_lit0("d", "debug",   "enable log of debug information"),
        argend  = arg_end(20)
    };
    char *progname = argv[0];

    /* verify the argtable[] entries were allocated sucessfully */
    if (arg_nullcheck(argtable) != 0)
        perror("insufficient memory!");

    /* If the parser returned any errors then display them and exit */
    if (arg_parse(argc,argv,argtable) > 0)
    {
        /* Display the error details contained in the arg_end struct.*/
        arg_print_errors(stdout, argend, progname);
        perror("Try '--help' for more information!");
    }
    /* special case: '--help' takes precedence over error reporting */
    if (help->count > 0)
    {
        printf("Usage: %s", progname);
        arg_print_syntax(stdout, argtable, "\n");
        printf("List information about the FILE(s) "
               "(the current directory by default).\n\n");
        arg_print_glossary(stdout, argtable, "  %-25s %s\n");
        goto failed;
    }

    /* special case: '--version' takes precedence error reporting */
    if (version->count > 0)
    {
        printf("'%s' example program for the \"argtable\" command line argument parser.\n",progname);
        printf("03/07/2022, zhangw\n");
        goto failed;
    }

    /* special case: '--debug' takes precedence error reporting */
    if (debug->count > 0)
    {
        dump_enable = 1;
    }
#endif

    DEBUG_INFO("dump mode = [%s]\n", dump_enable ? "true" : "false");

    //cpu performance detection
    cpu_gflops_avx2 = oplib_get_cpu_peak_gflops_avx2();
    cpu_gflops_fpu  = oplib_get_cpu_peak_gflops_fpu();

    sz_ifm_conv = conv2d_param.param_N *conv2d_param.param_IC*conv2d_param.param_IH*conv2d_param.param_IW*sizeof(FLOAT_T);
    sz_ofm_conv = conv2d_param.param_N *conv2d_param.param_OC*conv2d_param.param_OH*conv2d_param.param_OW*sizeof(FLOAT_T);
    sz_wt_conv  = conv2d_param.param_OC*conv2d_param.param_KW*conv2d_param.param_KH*conv2d_param.param_IC*sizeof(FLOAT_T);
    sz_bs_conv  = conv2d_param.param_OC*sizeof(FLOAT_T);
    sz_ifm_relu = relu_param.param_N *relu_param.param_IC*relu_param.param_IH*relu_param.param_IW*sizeof(FLOAT_T);
    sz_ofm_relu = relu_param.param_N *relu_param.param_OC*relu_param.param_OH*relu_param.param_OW*sizeof(FLOAT_T);
    sz_ifm_pool = pool_param.param_N *pool_param.param_IC*pool_param.param_IH*pool_param.param_IW*sizeof(FLOAT_T);
    sz_ofm_pool = pool_param.param_N *pool_param.param_OC*pool_param.param_OH*pool_param.param_OW*sizeof(FLOAT_T);

    DEBUG_INFO("allocate buffers for input/output/intermediate tensors!\n");
    //buffer allocation and data preferation
    pbuf_ifm_conv = (FLOAT_T*)malloc(sz_ifm_conv);
    if(pbuf_ifm_conv == NULL)
        perror("pbuf_ifm_conv malloc failed!");

    pbuf_ofm_conv = (FLOAT_T*)malloc(sz_ofm_conv);
    if(pbuf_ofm_conv == NULL)
        perror("pbuf_ofm_conv malloc failed!");

    pbuf_wt_conv = (FLOAT_T*)malloc(sz_wt_conv);
    if(pbuf_wt_conv == NULL)
        perror("pbuf_wt_conv malloc failed!");

    pbuf_bs_conv = (FLOAT_T*)malloc(sz_bs_conv);
    if(pbuf_bs_conv == NULL)
        perror("pbuf_bs_conv malloc failed!");

    pbuf_ifm_relu = (FLOAT_T*)malloc(sz_ifm_relu);
    if(pbuf_ifm_relu == NULL)
        perror("pbuf_ifm_relu malloc failed!");

    pbuf_ofm_relu = (FLOAT_T*)malloc(sz_ofm_relu);
    if(pbuf_ofm_relu == NULL)
        perror("pbuf_ofm_relu malloc failed!");

    pbuf_ifm_pool = (FLOAT_T*)malloc(sz_ifm_pool);
    if(pbuf_ifm_pool == NULL)
        perror("pbuf_ifm_pool malloc failed!");

    pbuf_ofm_pool = (FLOAT_T*)malloc(sz_ofm_pool);
    if(pbuf_ofm_pool == NULL)
        perror("pbuf_ofm_pool malloc failed!");

    DEBUG_INFO("generate test data for [pbuf_ifm_conv]\n");
    dim_nhwc.n = conv2d_param.param_N ;
    dim_nhwc.h = conv2d_param.param_IH;
    dim_nhwc.w = conv2d_param.param_IW;
    dim_nhwc.c = conv2d_param.param_IC;
    oplib_gen_nhwc_fp32(&dim_nhwc, pbuf_ifm_conv);
    oplib_dump_nhwc_fp32(&dim_nhwc, pbuf_ifm_conv, "pbuf_ifm_conv", dump_enable);

    DEBUG_INFO("generate test data for [pbuf_wt_conv]\n");
    dim_nhwc.n = conv2d_param.param_OC;
    dim_nhwc.h = conv2d_param.param_KH;
    dim_nhwc.w = conv2d_param.param_KW;
    dim_nhwc.c = conv2d_param.param_IC;
    oplib_gen_nhwc_fp32(&dim_nhwc, pbuf_wt_conv);
    oplib_dump_nhwc_fp32(&dim_nhwc, pbuf_wt_conv, "pbuf_wt_conv", dump_enable);

    DEBUG_INFO("generate test data for [pbuf_bs_conv]\n");
    dim_nhwc.n = 1;
    dim_nhwc.h = 1;
    dim_nhwc.w = 1;
    dim_nhwc.c = conv2d_param.param_OC;
    oplib_gen_nhwc_fp32(&dim_nhwc, pbuf_bs_conv);
    oplib_dump_nhwc_fp32(&dim_nhwc, pbuf_bs_conv, "pbuf_bs_conv", dump_enable);

    //gflops calculation and property report
    conv_gflops = oplib_layer_conv2d_s1_report_property(&conv2d_param);
    relu_gflops = oplib_layer_relu_report_property(&relu_param);
    pool_gflops = oplib_layer_avgpool_report_property(&pool_param);

    //do the conv2d calculation and profiling///////////////////////////////////
    PROF_TMR_START();
    for(int i=0; i<CONV_ITERNUM; i++)
    {
        oplib_layer_conv2d_s1_forward(&conv2d_param, 
                                   pbuf_ifm_conv, 
                                   pbuf_ofm_conv, 
                                   pbuf_wt_conv,
                                   pbuf_bs_conv); 
    }
    PROF_TMR_END();
    conv_time_used = PROF_TMR_VALSEC / CONV_ITERNUM;

    PROF_TMR_START();
    for(int i=0; i<CONV_ITERNUM; i++)
    {
        oplib_layer_conv2d_s1_forward_omp(&conv2d_param, 
                                   pbuf_ifm_conv, 
                                   pbuf_ofm_conv, 
                                   pbuf_wt_conv,
                                   pbuf_bs_conv); 
    }
    PROF_TMR_END();
    conv_omp_time_used = PROF_TMR_VALSEC / CONV_ITERNUM;

    //do the relu calculation and profiling/////////////////////////////////
    PROF_TMR_START();
    for(int i=0; i<RELU_ITERNUM; i++)
    {
        oplib_layer_relu_forward(&relu_param, 
                                   pbuf_ofm_conv, 
                                   pbuf_ofm_relu); 
    }
    PROF_TMR_END();
    relu_time_used = PROF_TMR_VALSEC / RELU_ITERNUM;

    PROF_TMR_START();
    for(int i=0; i<RELU_ITERNUM; i++)
    {
        oplib_layer_relu_forward_omp(&relu_param, 
                                   pbuf_ofm_conv, 
                                   pbuf_ofm_relu); 
    }
    PROF_TMR_END();
    relu_omp_time_used = PROF_TMR_VALSEC / RELU_ITERNUM;

    //do the pooling calculation and profiling/////////////////////////////////
    PROF_TMR_START();
    for(int i=0; i<POOL_ITERNUM; i++)
    {
        oplib_layer_avgpool_forward(&pool_param, 
                                   pbuf_ofm_relu, 
                                   pbuf_ofm_pool); 
    }
    PROF_TMR_END();
    pool_time_used = PROF_TMR_VALSEC / POOL_ITERNUM;

    PROF_TMR_START();
    for(int i=0; i<POOL_ITERNUM; i++)
    {
        oplib_layer_avgpool_forward_omp(&pool_param, 
                                   pbuf_ofm_relu, 
                                   pbuf_ofm_pool); 
    }
    PROF_TMR_END();
    pool_omp_time_used = PROF_TMR_VALSEC / POOL_ITERNUM;
    //check the result////////////////////////////////////////////////////////
    dim_nhwc.n = pool_param.param_N;
    dim_nhwc.c = pool_param.param_OC;
    dim_nhwc.h = pool_param.param_OH;
    dim_nhwc.w = pool_param.param_OW;
    oplib_dump_nhwc_fp32(&dim_nhwc, pbuf_ofm_pool, "pbuf_ofm_pool", dump_enable);


    DEBUG_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    DEBUG_INFO("report : oplib_layer_conv2d_s1     cost [%lf] seconds in avg within [%d] iters\n", conv_time_used, CONV_ITERNUM);
    DEBUG_INFO("report : oplib_layer_relu          cost [%lf] seconds in avg within [%d] iters\n", relu_time_used, RELU_ITERNUM);
    DEBUG_INFO("report : oplib_layer_avgpool       cost [%lf] seconds in avg within [%d] iters\n", pool_time_used, POOL_ITERNUM);

    DEBUG_INFO("report : oplib_layer_conv2d_s1_omp cost [%lf] seconds in avg within [%d] iters\n", conv_omp_time_used, CONV_ITERNUM);
    DEBUG_INFO("report : oplib_layer_relu_omp      cost [%lf] seconds in avg within [%d] iters\n", relu_omp_time_used, RELU_ITERNUM);
    DEBUG_INFO("report : oplib_layer_avgpool_omp   cost [%lf] seconds in avg within [%d] iters\n", pool_omp_time_used, POOL_ITERNUM);

    DEBUG_INFO("report : oplib_layer_conv2d_s1     calculation profermance is [%lf] GFLOPS/s\n", conv_gflops / conv_time_used);
    DEBUG_INFO("report : oplib_layer_relu          calculation profermance is [%lf] GFLOPS/s\n", relu_gflops / relu_time_used);
    DEBUG_INFO("report : oplib_layer_avgpool       calculation profermance is [%lf] GFLOPS/s\n", pool_gflops / pool_time_used);

    DEBUG_INFO(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    //do program finalization
    free(pbuf_ifm_conv);
    free(pbuf_ofm_conv);
    free(pbuf_wt_conv );
    free(pbuf_bs_conv );
    free(pbuf_ifm_relu);
    free(pbuf_ofm_relu);
    free(pbuf_ifm_pool);
    free(pbuf_ofm_pool);

failed:
    /* deallocate each non-null entry in argtable[] */
    arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
    DEBUG_INFO("program exit!\n");
    return 0;
}
