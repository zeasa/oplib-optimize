#include "gtest/gtest.h"
#include "testbench_encode_vec.hpp"

/*do_encode_vgeu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx) */
TEST(vgeu_vs, test0)
{
    /***********mmmmSSv2222211111ffffDDDDtttttII*******************************/
    ASSERT_EQ(0B00000000000000000011000000001011, do_encode_vgeu_vs(vr0, vr0, sr0, msk_idx0, sft_idx0));
}

TEST(vgeu_vs, test1)
{
    /***********mmmmSSv2222211111ffffDDDDtttttII*******************************/
    ASSERT_EQ(0B11111101111101111011011110001011, do_encode_vgeu_vs(vr15, vr15, sr31, msk_idx15, sft_idx3));
}

