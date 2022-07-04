#include "gtest/gtest.h"
#include "oplib_common.h"
#include "oplib_interface.h"


TEST(relu, test0)
{
    ASSERT_EQ(7, oplib_conv2d_demo(3, 4));
}

TEST(relu, test1)
{
    ASSERT_EQ(15, oplib_conv2d_demo(7, 8));
}
