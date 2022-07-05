#ifndef _BENCHMARK_TESTCASE_H__
#define _BENCHMARK_TESTCASE_H__

#define  CONV_N		(4)        // batch size
#define  CONV_IC	(32)       // input channels
#define  CONV_IH	(512)      // input height
#define  CONV_IW	(512)      // input width
#define  CONV_OC	(16)       // output channels
#define  CONV_OH	(CONV_IH)  // output height
#define  CONV_OW	(CONV_IW)  // output width
#define  CONV_KH	(3)        // weights height
#define  CONV_KW	(3)        // weights width
#define  CONV_PT	(1)        // padding: left
#define  CONV_PB	(1)        // padding: right
#define  CONV_PL	(1)        // padding: left
#define  CONV_PR	(1)        // padding: right
#define  CONV_SH	(1)        // height-wise stride
#define  CONV_SW	(1)        // width-wise stride

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

#define CONV_ITERNUM        (1)
#define RELU_ITERNUM        (200)
#define POOL_ITERNUM        (200)

#ifdef __cplusplus
}
#endif
#endif /*_BENCHMARK_TESTCASE_H__*/
