#include "gtest/gtest.h"
#include "oplib_common.h"
#include "oplib_interface.h"
#include "test_oplib_layer_testcase.h"


TEST(conv_relu_pooling, test0)
{
    int i;

    oplib_layer_fused_conv2d_relu_avgpool_forward(
                                   &conv2d_param, 
                                   &relu_param, 
                                   &pool_param,
                                   ifm_conv, 
                                   ofm_pool, 
                                   wt_conv,
                                   bs_conv);

    for(i=0; i<OFM_POOL_SZ;++i)
    {
        ASSERT_FLOAT_EQ(ofm_pool[i], ofm_pool_golden[i]);
    }
}

TEST(conv_relu_pooling, test1)
{
    int i;

    oplib_layer_fused_conv2d_relu_avgpool_forward_omp(
                                   &conv2d_param, 
                                   &relu_param, 
                                   &pool_param,
                                   ifm_conv, 
                                   ofm_pool, 
                                   wt_conv,
                                   bs_conv);

    for(i=0; i<OFM_POOL_SZ;++i)
    {
        ASSERT_FLOAT_EQ(ofm_pool[i], ofm_pool_golden[i]);
    }
}
