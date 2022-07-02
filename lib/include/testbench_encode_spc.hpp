#ifndef TESTBENCH_CODEGEN_MTX_H__
#define TESTBENCH_CODEGEN_MTX_H__

#include <inttypes.h> 
#include <stdint.h>
#include <cstdint>
#include "npu_reg_def.h"

uint32_t do_encode_barrier(uint32_t rs1);
uint32_t do_encode_buf_push(uint32_t imm_pnum, uint32_t pt_idx);
uint32_t do_encode_buf_pop(uint32_t vrd);
uint32_t do_encode_idep_set(uint32_t immd_5, uint32_t imm1_5, uint32_t imm2_5, uint32_t imm3_5);
uint32_t do_encode_idep_rls();
uint32_t do_encode_ddep_set(uint32_t immd_5, uint32_t imm1_5, uint32_t imm2_5, uint32_t imm3_5);
uint32_t do_encode_ddep_rls();

#endif
