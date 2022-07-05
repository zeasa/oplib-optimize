#include "gtest/gtest.h"
#include "oplib_common.h"
#include "oplib_interface.h"
#include "test_oplib_layer_testcase.h"

TEST(conv2d, test0)
{
    int i;

    oplib_layer_conv2d_s1_forward(&conv2d_param, 
                                   ifm_conv, 
                                   ofm_conv, 
                                   wt_conv,
                                   bs_conv);
    for(i=0; i<OFM_CONV_SZ;++i)
    {
        ASSERT_FLOAT_EQ(ofm_conv[i], ofm_conv_golden[i]);
    }
    
}

TEST(conv2d, test1)
{
    int i;

    oplib_layer_conv2d_s1_forward_omp(&conv2d_param, 
                                   ifm_conv, 
                                   ofm_conv, 
                                   wt_conv,
                                   bs_conv);
    for(i=0; i<OFM_CONV_SZ;++i)
    {
        ASSERT_FLOAT_EQ(ofm_conv[i], ofm_conv_golden[i]);
    }
    
}
