#ifndef _OPLIB_GTEST_TESTCASE_H__
#define _OPLIB_GTEST_TESTCASE_H__


#define  CONV_N		(1)       // batch size
#define  CONV_IC	(2)       // input channels
#define  CONV_IH	(4)       // input height
#define  CONV_IW	(4)       // input width
#define  CONV_OC	(2)       // output channels
#define  CONV_OH	(CONV_IH) // output height
#define  CONV_OW	(CONV_IW) // output width
#define  CONV_KH	(3)       // weights height
#define  CONV_KW	(3)       // weights width
#define  CONV_PT	(1)       // padding: left
#define  CONV_PB	(1)       // padding: right
#define  CONV_PL	(1)       // padding: left
#define  CONV_PR	(1)       // padding: right
#define  CONV_SH	(1)       // height-wise stride
#define  CONV_SW	(1)       // width-wise stride

#define  RELU_N		(CONV_N)   // batch size
#define  RELU_IC	(CONV_OC)  // input channels
#define  RELU_IH	(CONV_OH)  // input height
#define  RELU_IW	(CONV_OW)  // input width
#define  RELU_OC	(RELU_IC)  // output channels
#define  RELU_OH	(RELU_IH)  // output height
#define  RELU_OW	(RELU_IW)  // output width

#define  POOL_N		(RELU_N)   // batch size
#define  POOL_IC	(RELU_OC)  // input channels
#define  POOL_IH	(RELU_OH)  // input height
#define  POOL_IW	(RELU_OW)  // input width
#define  POOL_KH	(2)        // kernel height
#define  POOL_KW	(2)        // kernel width
#define  POOL_SH	(2)        // height-wise stride
#define  POOL_SW	(2)        // width-wise stride
#define  POOL_OC	(POOL_IC)  // input channels
#define  POOL_OH	((POOL_IH+1)/POOL_SH)  // input height
#define  POOL_OW	((POOL_IW+1)/POOL_SW)  // input width


#define  IFM_CONV_SZ    (CONV_N*CONV_IC*CONV_IH*CONV_IW)
static const float ifm_conv[IFM_CONV_SZ] = 
{
    1,2, 1,2, 1,2, 1,2,
    1,2, 1,2, 1,2, 1,2,
    1,2, 1,2, 1,2, 1,2,
    1,2, 1,2, 1,2, 1,2
};

#define  WT_CONV_SZ     (CONV_OC*CONV_KH*CONV_KW*CONV_IC)
static const float wt_conv[WT_CONV_SZ] = 
{
    1,2, 1,2, 1,2, 
    1,2, 1,2, 1,2, 
    1,2, 1,2, 1,2, 

    2,1, 2,1, 2,1,
    2,1, 2,1, 2,1,
    2,1, 2,1, 2,1
};

#define  BS_CONV_SZ     (CONV_OC)
static const float bs_conv[BS_CONV_SZ] = 
{
    0.5, 0.4
};

#define  OFM_CONV_SZ    (CONV_N*CONV_OC*CONV_OH*CONV_OW)
static const float ofm_conv_golden[OFM_CONV_SZ] =
{
    20.5,16.4, 30.5,24.4, 30.5,24.4, 20.5,16.4,
    30.5,24.4, 45.5,36.4, 45.5,36.4, 30.5,24.4,
    30.5,24.4, 45.5,36.4, 45.5,36.4, 30.5,24.4,
    20.5,16.4, 30.5,24.4, 30.5,24.4, 20.5,16.4,
};
static float ofm_conv[OFM_CONV_SZ] = 
{
    0
};

#define  OFM_RELU_SZ    (RELU_N*RELU_OC*RELU_OH*RELU_OW)
static const float ofm_relu_golden[OFM_RELU_SZ] =
{
    20.5,16.4, 30.5,24.4, 30.5,24.4, 20.5,16.4,
    30.5,24.4, 45.5,36.4, 45.5,36.4, 30.5,24.4,
    30.5,24.4, 45.5,36.4, 45.5,36.4, 30.5,24.4,
    20.5,16.4, 30.5,24.4, 30.5,24.4, 20.5,16.4,
};
static float ofm_relu[OFM_CONV_SZ] = 
{
    0
};

#define  OFM_POOL_SZ    (POOL_N*POOL_OC*POOL_OH*POOL_OW)
static const float ofm_pool_golden[OFM_POOL_SZ] =
{
    31.75,25.4, 31.75,25.4, 
    31.75,25.4, 31.75,25.4
};
static float ofm_pool[OFM_POOL_SZ] = 
{
    0
};

static const strConv2DParam_t conv2d_param = 
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

static const strReluParam_t relu_param = 
{
    RELU_N,  // batch size
    RELU_IC, // input channels
    RELU_IH, // input height
    RELU_IW, // input width
    RELU_OC, // output channels
    RELU_OH, // output height
    RELU_OW  // output width,
};

static const strAvgPoolParam_t pool_param =  
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

#endif /*_OPLIB_GTEST_TESTCASE_H__*/
