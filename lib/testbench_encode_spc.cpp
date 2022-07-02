#include "testbench_encode_spc.hpp"
#include "npu_instr_encode.h"

uint32_t do_encode_barrier( uint32_t rs1)
{
    return encode_barrier(rs1);
}

uint32_t do_encode_buf_push(uint32_t imm_pnum, uint32_t pt_idx)
{
    return encode_buf_push(imm_pnum, pt_idx);
}

uint32_t do_encode_buf_pop( uint32_t vrd)
{
    return encode_buf_pop(vrd);
}

uint32_t do_encode_idep_set(uint32_t immd_5, uint32_t imm1_5, uint32_t imm2_5, uint32_t imm3_5)
{
    return encode_idep_set(immd_5, imm1_5, imm2_5, imm3_5);
}

uint32_t do_encode_idep_rls()
{
    return encode_idep_rls();
}

uint32_t do_encode_ddep_set(uint32_t immd_5, uint32_t imm1_5, uint32_t imm2_5, uint32_t imm3_5)
{
    return encode_ddep_set(immd_5, imm1_5, imm2_5, imm3_5);
}

uint32_t do_encode_ddep_rls()
{
    return encode_ddep_rls();
}
