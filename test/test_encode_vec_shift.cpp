#include "gtest/gtest.h"
#include "testbench_encode_vec.hpp"

/*do_encode_vsrl_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)  */
TEST(vsrl_vs, test0)
{
    /***********mmmmSSv2222211111ffffDDDDtttttII*******************************/
    ASSERT_EQ(0B00000000000000000000000000101011, do_encode_vsrl_vs(vr0, vr0, sr0, msk_idx0));
}

TEST(vsrl_vs, test1)
{
    /***********mmmmSSv2222211111ffffDDDDtttttII*******************************/
    ASSERT_EQ(0B11110001111101111000011110101011, do_encode_vsrl_vs(vr15, vr15, sr31, msk_idx15));
}

