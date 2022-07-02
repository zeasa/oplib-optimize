#ifndef TESTBENCH_CODEGEN_MTX_H__
#define TESTBENCH_CODEGEN_MTX_H__

#include <inttypes.h> 
#include <stdint.h>
#include <cstdint>
#include "npu_reg_def.h"

uint32_t do_encode_mad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_madc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_mmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_mmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_mvmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_mvmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_mvbmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_mvbmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx);
uint32_t do_encode_mcmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en);
uint32_t do_encode_mcmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en);
uint32_t do_encode_mx(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en);
uint32_t do_encode_mxc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en);
uint32_t do_encode_mi(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en);
uint32_t do_encode_mic(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en);

#endif
