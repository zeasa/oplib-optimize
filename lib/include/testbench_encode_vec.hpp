#ifndef TESTBENCH_CODEGEN_VEC_H__
#define TESTBENCH_CODEGEN_VEC_H__

#include <inttypes.h> 
#include <stdint.h>
#include <cstdint>
#include "npu_reg_def.h"

uint32_t do_encode_vadd_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vadd_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vaddc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vaddc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vsub_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vsub_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vsubc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vsubc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vrsub_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vrsub_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vrsubc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vrsubc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vge_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vge_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vgeu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vgeu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vlt_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vlt_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vltu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vltu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vand_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vand_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vor_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vor_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vxor_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vxor_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vnxor_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vnxor_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vmand(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vmor(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vmxor(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vmnxor(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx);
uint32_t do_encode_vsrl_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vsrl_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vsra_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vsra_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vsrc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vsrc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vsrs_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vsrs_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vsrl_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx);
uint32_t do_encode_vsra_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx);
uint32_t do_encode_vsrc_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx);
uint32_t do_encode_vsrs_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx);
uint32_t do_encode_vsl_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vsl_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vsl_vi(uint32_t vrd, uint32_t vrs1, uint32_t rs2,uint32_t imm_5, uint32_t msk_idx);
uint32_t do_encode_vmulu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vmulu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vmulus_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vmulus_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vmulsu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vmulsu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vmul_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vmul_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_valign_h(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_valign_v(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_valign_cross(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vsel(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t sel_idx);
uint32_t do_encode_vargsort(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vreorder(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx);
uint32_t do_encode_vtranspose(uint32_t vrd, uint32_t vrs1, uint32_t      msk_idx);
uint32_t do_encode_vrmax(uint32_t vmrd, uint32_t vrs1, uint32_t sel_idx);
uint32_t do_encode_vrmin(uint32_t vmrd, uint32_t vrs1, uint32_t sel_idx);
uint32_t do_encode_vrsum(uint32_t vrd, uint32_t vrs1, uint32_t sel_idx);
uint32_t do_encode_vrcompress(uint32_t vrd, uint32_t vrs1, uint32_t sel_idx);
uint32_t do_encode_vfadd(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vfsub(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vfmul(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx);
uint32_t do_encode_vfsort(uint32_t vrd, uint32_t vrs1, uint32_t  rs2, uint32_t msk_idx);
uint32_t do_encode_vftoi(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx);
uint32_t do_encode_vitof(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx);
uint32_t do_encode_vlog2(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx);
uint32_t do_encode_vexp2(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx);
uint32_t do_encode_vrcp(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx);
uint32_t do_encode_vsqrt(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx);
uint32_t do_encode_vlb(uint32_t vrd, uint32_t rs1, uint32_t imm_8);
uint32_t do_encode_vlbu(uint32_t vrd, uint32_t rs1, uint32_t imm_8);
uint32_t do_encode_vlh(uint32_t vrd, uint32_t rs1, uint32_t imm_8);
uint32_t do_encode_vlhu(uint32_t vrd, uint32_t rs1, uint32_t imm_8);
uint32_t do_encode_vlw(uint32_t vrd, uint32_t rs1, uint32_t imm_8);
uint32_t do_encode_vlf(uint32_t vrd, uint32_t rs1, uint32_t imm_8);
uint32_t do_encode_vsb(uint32_t rs1, uint32_t vrs2, uint32_t imm_8);
uint32_t do_encode_vsh(uint32_t rs1, uint32_t vrs2, uint32_t imm_8);
uint32_t do_encode_vsw(uint32_t rs1, uint32_t vrs2, uint32_t imm_8);
uint32_t do_encode_vsf(uint32_t rs1, uint32_t vrs2, uint32_t imm_8);
uint32_t do_encode_vsset_s(uint32_t vsrd, uint32_t rs1, uint32_t  rs2);
uint32_t do_encode_vsset_i(uint32_t vsrd, uint32_t imm1_7, uint32_t imm2_7);
uint32_t do_encode_vfusion_s(uint32_t rs, uint32_t  sat_5, uint32_t su, uint32_t rnd);
uint32_t do_encode_vfusion_v(uint32_t vrs, uint32_t sat_5, uint32_t su, uint32_t rnd);
uint32_t do_encode_vloop_start(uint32_t imm_18);
uint32_t do_encode_vloop_end(uint32_t imm_4);

#endif
