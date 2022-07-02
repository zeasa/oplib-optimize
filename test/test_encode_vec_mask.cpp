#include "gtest/gtest.h"
#include "testbench_encode_vec.hpp"

/*do_encode_vmand(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx)  */
TEST(vmand, test0)
{
    /***********mmmmSSv2222211111ffffDDDDtttttII*******************************/
    ASSERT_EQ(0B00000000000000000111000000001011, do_encode_vmand(vmr0, vmr0, vmr0, msk_idx0, sft_idx0));
}

TEST(vmand, test1)
{
    /***********mmmmSSv2222211111ffffDDDDtttttII*******************************/
    ASSERT_EQ(0B11111100111101111111011110001011, do_encode_vmand(vmr15, vmr15, vmr15, msk_idx15, sft_idx3));
}

