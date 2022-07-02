#include "gtest/gtest.h"
#include "testbench_encode_mtx.hpp"


/*do_encode_mad(uint32_t rs2, uint32_t rs1, uint32_t vbrd, uint32_t pt_idx)*/
TEST(mad, test0)
{
    /***********PPPPfMc2222211111aaFFvvvvtttttII*******************************/
    ASSERT_EQ(0B11110000010000011000000001011011, do_encode_mad(0x0, sr3, sr4, 0xF));
}

TEST(mad, test1)
{
    /***********PPPPfMc2222211111aaFFvvvvtttttII*******************************/
    ASSERT_EQ(0B11110000010000011000011111011011, do_encode_mad(0xF, sr3, sr4, 0xF));
}

