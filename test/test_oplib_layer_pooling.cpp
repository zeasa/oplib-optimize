#include "gtest/gtest.h"
#include "oplib_common.h"
#include "oplib_interface.h"
#include "test_oplib_layer_testcase.h"


TEST(pooling, test0)
{
    int i;

    oplib_layer_avgpool_forward(&pool_param, 
                              ofm_relu_golden, 
                              ofm_pool);

    for(i=0; i<OFM_POOL_SZ;++i)
    {
        ASSERT_FLOAT_EQ(ofm_pool[i], ofm_pool_golden[i]);
    }
    
}

TEST(pooling, test1)
{
    int i;

    oplib_layer_avgpool_forward_omp(&pool_param, 
                              ofm_relu_golden, 
                              ofm_pool);

    for(i=0; i<OFM_POOL_SZ;++i)
    {
        ASSERT_FLOAT_EQ(ofm_pool[i], ofm_pool_golden[i]);
    }
    
}
