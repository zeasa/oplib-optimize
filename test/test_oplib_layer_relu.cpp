#include "gtest/gtest.h"
#include "oplib_common.h"
#include "oplib_interface.h"
#include "test_oplib_layer_testcase.h"


TEST(relu, test0)
{
    int i;

    oplib_layer_relu_forward(&relu_param, 
                              ofm_conv_golden, 
                              ofm_relu);

    for(i=0; i<OFM_RELU_SZ;++i)
    {
        ASSERT_FLOAT_EQ(ofm_relu[i], ofm_relu_golden[i]);
    }
    
}