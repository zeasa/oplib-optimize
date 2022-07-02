#ifndef _MANASI_ASM_INSTR_ENCODE_H__
#define _MANASI_ASM_INSTR_ENCODE_H__

#ifndef BUILD_FOR_TEST
#define BUILD_FOR_TEST
#endif

#include "npu_reg_def.h"
#include "npu_instr_gen.h"

#define s2_v                    (1)
#define s2_s                    (0)
/******************************************************************************************************************************************************/
#define encode_vadd_vs(  vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0000, vrd,  0B00010, 0B11)
#define encode_vadd_vv(  vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0000, vrd,  0B00010, 0B11)
#define encode_vaddc_vs( vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0001, vrd,  0B00010, 0B11)
#define encode_vaddc_vv( vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0001, vrd,  0B00010, 0B11)
#define encode_vsub_vs(  vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0010, vrd,  0B00010, 0B11)
#define encode_vsub_vv(  vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0010, vrd,  0B00010, 0B11)
#define encode_vsubc_vs( vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0011, vrd,  0B00010, 0B11)
#define encode_vsubc_vv( vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0011, vrd,  0B00010, 0B11)
#define encode_vrsub_vs( vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0100, vrd,  0B00010, 0B11)
#define encode_vrsub_vv( vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0100, vrd,  0B00010, 0B11)
#define encode_vrsubc_vs(vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0101, vrd,  0B00010, 0B11)
#define encode_vrsubc_vv(vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0101, vrd,  0B00010, 0B11)

#define encode_vgeu_vs(  vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0110, vrd,  0B00010, 0B11)
#define encode_vgeu_vv(  vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0110, vrd,  0B00010, 0B11)
#define encode_vge_vs(   vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B0111, vrd,  0B00010, 0B11)
#define encode_vge_vv(   vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B0111, vrd,  0B00010, 0B11)
#define encode_vltu_vs(  vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B1000, vrd,  0B00010, 0B11)
#define encode_vltu_vv(  vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B1000, vrd,  0B00010, 0B11)
#define encode_vlt_vs(   vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B1001, vrd,  0B00010, 0B11)
#define encode_vlt_vv(   vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B1001, vrd,  0B00010, 0B11)

#define encode_vand_vs(  vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B1010, vrd,  0B00010, 0B11)
#define encode_vand_vv(  vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B1010, vrd,  0B00010, 0B11)
#define encode_vor_vs(   vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B1011, vrd,  0B00010, 0B11)
#define encode_vor_vv(   vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B1011, vrd,  0B00010, 0B11)
#define encode_vxor_vs(  vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B1100, vrd,  0B00010, 0B11)
#define encode_vxor_vv(  vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B1100, vrd,  0B00010, 0B11)
#define encode_vnxor_vs( vrd, vrs1, rs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_s,   rs2,  vrs1,    0B1101, vrd,  0B00010, 0B11)
#define encode_vnxor_vv( vrd, vrs1,vrs2, msk_idx, sh_idx)       GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx, s2_v,  vrs2,  vrs1,    0B1101, vrd,  0B00010, 0B11)

#define encode_vmand(   vmrd, vmrs1, vmrs2, msk_idx, sh_idx)    GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx,  0B0, vmrs2, vmrs1,    0B1110,vmrd,  0B00010, 0B11)
#define encode_vmor(    vmrd, vmrs1, vmrs2, msk_idx, sh_idx)    GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx,  0B1, vmrs2, vmrs1,    0B1110,vmrd,  0B00010, 0B11)
#define encode_vmxor(   vmrd, vmrs1, vmrs2, msk_idx, sh_idx)    GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx,  0B0, vmrs2, vmrs1,    0B1111,vmrd,  0B00010, 0B11)
#define encode_vmnxor(  vmrd, vmrs1, vmrs2, msk_idx, sh_idx)    GEN_VEC_INSTR_TYPE1(msk_idx, sh_idx,  0B1, vmrs2, vmrs1,    0B1111,vmrd,  0B00010, 0B11)

#define encode_vsrl_vs(vrd, vrs1, rs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B00, s2_s,   rs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsrl_vv(vrd, vrs1,vrs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B00, s2_v,  vrs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsra_vs(vrd, vrs1, rs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B01, s2_s,   rs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsra_vv(vrd, vrs1,vrs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B01, s2_v,  vrs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsrc_vs(vrd, vrs1, rs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B10, s2_s,   rs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsrc_vv(vrd, vrs1,vrs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B10, s2_v,  vrs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsrs_vs(vrd, vrs1, rs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B11, s2_s,   rs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsrs_vv(vrd, vrs1,vrs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B11, s2_v,  vrs2,  vrs1,    0B0000, vrd,  0B01010, 0B11)
#define encode_vsrl_vi(vrd, vrs1,     imm_5, msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B00,  0B0, imm_5,  vrs1,    0B0001, vrd,  0B01010, 0B11)
#define encode_vsra_vi(vrd, vrs1,     imm_5, msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B01,  0B0, imm_5,  vrs1,    0B0001, vrd,  0B01010, 0B11)
#define encode_vsrc_vi(vrd, vrs1,     imm_5, msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B10,  0B0, imm_5,  vrs1,    0B0001, vrd,  0B01010, 0B11)
#define encode_vsrs_vi(vrd, vrs1,     imm_5, msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B11,  0B0, imm_5,  vrs1,    0B0001, vrd,  0B01010, 0B11)
#define encode_vsl_vs( vrd, vrs1, rs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B00, s2_s,   rs2,  vrs1,    0B0010, vrd,  0B01010, 0B11)
#define encode_vsl_vv( vrd, vrs1,vrs2,       msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B00, s2_v,  vrs2,  vrs1,    0B0010, vrd,  0B01010, 0B11)
#define encode_vsl_vi( vrd, vrs1, rs2,imm_5, msk_idx)           GEN_VEC_INSTR_TYPE1(msk_idx,   0B00,  0B0, imm_5,  vrs1,    0B0011, vrd,  0B01010, 0B11)

#define encode_vmulu_vs( vrd, vrs1, rs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B00, s2_s,   rs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)
#define encode_vmulu_vv( vrd, vrs1,vrs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B00, s2_v,  vrs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)
#define encode_vmulus_vs(vrd, vrs1, rs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B01, s2_s,   rs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)
#define encode_vmulus_vv(vrd, vrs1,vrs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B01, s2_v,  vrs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)
#define encode_vmulsu_vs(vrd, vrs1, rs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B10, s2_s,   rs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)
#define encode_vmulsu_vv(vrd, vrs1,vrs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B10, s2_v,  vrs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)
#define encode_vmul_vs(  vrd, vrs1, rs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B11, s2_s,   rs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)
#define encode_vmul_vv(  vrd, vrs1,vrs2, msk_idx)               GEN_VEC_INSTR_TYPE1(msk_idx,   0B11, s2_v,  vrs2,  vrs1,    0B1001, vrd,  0B01010, 0B11)

#define encode_valign_h(    vrd, vrs1, rs2, msk_idx)            GEN_VEC_INSTR_TYPE2(msk_idx,   0B000,        rs2,  vrs1,    0B0100, vrd,  0B01010, 0B11)
#define encode_valign_v(    vrd, vrs1,vrs2, msk_idx)            GEN_VEC_INSTR_TYPE2(msk_idx,   0B010,       vrs2,  vrs1,    0B0100, vrd,  0B01010, 0B11)
#define encode_valign_cross(vrd, vrs1, rs2, msk_idx)            GEN_VEC_INSTR_TYPE2(msk_idx,   0B100,        rs2,  vrs1,    0B0100, vrd,  0B01010, 0B11)
#define encode_vsel(        vrd, vrs1,vrs2, sel_idx)            GEN_VEC_INSTR_TYPE2(sel_idx,   0B110,       vrs2,  vrs1,    0B0100, vrd,  0B01010, 0B11)
#define encode_vargsort(    vrd, vrs1, rs2, msk_idx)            GEN_VEC_INSTR_TYPE2(msk_idx,   0B001,        rs2,  vrs1,    0B0100, vrd,  0B01010, 0B11)
#define encode_vreorder(    vrd, vrs1,vrs2, msk_idx)            GEN_VEC_INSTR_TYPE2(msk_idx,   0B011,       vrs2,  vrs1,    0B0100, vrd,  0B01010, 0B11)
#define encode_vtranspose(  vrd, vrs1,      msk_idx)            GEN_VEC_INSTR_TYPE2(msk_idx,   0B101,        0B0,  vrs1,    0B0100, vrd,  0B01010, 0B11)

#define encode_vrmax(vmrd, vrs1, sel_idx)                       GEN_VEC_INSTR_TYPE2(sel_idx,   0B000,        0B0,  vrs1,    0B0101,vmrd,  0B01010, 0B11)
#define encode_vrmin(vmrd, vrs1, sel_idx)                       GEN_VEC_INSTR_TYPE2(sel_idx,   0B010,        0B0,  vrs1,    0B0101,vmrd,  0B01010, 0B11)
#define encode_vrsum(vrd, vrs1, sel_idx)                        GEN_VEC_INSTR_TYPE2(sel_idx,   0B100,        0B0,  vrs1,    0B0101, vrd,  0B01010, 0B11)
#define encode_vrcompress(vrd, vrs1, sel_idx)                   GEN_VEC_INSTR_TYPE2(sel_idx,   0B110,        0B0,  vrs1,    0B0101, vrd,  0B01010, 0B11)

#define encode_vfadd( vrd, vrs1, vrs2, msk_idx)                 GEN_VEC_INSTR_TYPE2(msk_idx,   0B000,       vrs2,  vrs1,    0B0110, vrd,  0B01010, 0B11)
#define encode_vfsub( vrd, vrs1, vrs2, msk_idx)                 GEN_VEC_INSTR_TYPE2(msk_idx,   0B010,       vrs2,  vrs1,    0B0110, vrd,  0B01010, 0B11)
#define encode_vfmul( vrd, vrs1, vrs2, msk_idx)                 GEN_VEC_INSTR_TYPE2(msk_idx,   0B100,       vrs2,  vrs1,    0B0110, vrd,  0B01010, 0B11)
#define encode_vfsort(vrd, vrs1,  rs2, msk_idx)                 GEN_VEC_INSTR_TYPE2(msk_idx,   0B110,        rs2,  vrs1,    0B0110, vrd,  0B01010, 0B11)
#define encode_vftoi( vrd, vrs1,       msk_idx)                 GEN_VEC_INSTR_TYPE2(msk_idx,   0B001,        0B0,  vrs1,    0B0110, vrd,  0B01010, 0B11)
#define encode_vitof( vrd, vrs1,       msk_idx)                 GEN_VEC_INSTR_TYPE2(msk_idx,   0B011,        0B0,  vrs1,    0B0110, vrd,  0B01010, 0B11)

#define encode_vlog2(vrd, vrs1,       msk_idx)                  GEN_VEC_INSTR_TYPE2(msk_idx,   0B000,        0B0,  vrs1,    0B0111, vrd,  0B01010, 0B11)
#define encode_vexp2(vrd, vrs1,       msk_idx)                  GEN_VEC_INSTR_TYPE2(msk_idx,   0B010,        0B0,  vrs1,    0B0111, vrd,  0B01010, 0B11)
#define encode_vrcp( vrd, vrs1,       msk_idx)                  GEN_VEC_INSTR_TYPE2(msk_idx,   0B100,        0B0,  vrs1,    0B0111, vrd,  0B01010, 0B11)
#define encode_vsqrt(vrd, vrs1,       msk_idx)                  GEN_VEC_INSTR_TYPE2(msk_idx,   0B110,        0B0,  vrs1,    0B0111, vrd,  0B01010, 0B11)

#define encode_vlbu(vrd, rs1, imm_8)                            GEN_VEC_INSTR_TYPE3(imm_8,     0B000,               rs1,    0B1110, vrd,  0B01010, 0B11)
#define encode_vlb( vrd, rs1, imm_8)                            GEN_VEC_INSTR_TYPE3(imm_8,     0B010,               rs1,    0B1110, vrd,  0B01010, 0B11)
#define encode_vlhu(vrd, rs1, imm_8)                            GEN_VEC_INSTR_TYPE3(imm_8,     0B010,               rs1,    0B1110, vrd,  0B01010, 0B11)
#define encode_vlh( vrd, rs1, imm_8)                            GEN_VEC_INSTR_TYPE3(imm_8,     0B011,               rs1,    0B1110, vrd,  0B01010, 0B11)
#define encode_vlw( vrd, rs1, imm_8)                            GEN_VEC_INSTR_TYPE3(imm_8,     0B101,               rs1,    0B1110, vrd,  0B01010, 0B11)
#define encode_vlf( vrd, rs1, imm_8)                            GEN_VEC_INSTR_TYPE3(imm_8,     0B111,               rs1,    0B1110, vrd,  0B01010, 0B11)

#define encode_vsb(rs1, vrs2, imm_8)                            GEN_VEC_INSTR_TYPE4(imm_8,     0B001,       vrs2,   rs1,    0B1111,       0B01010, 0B11)
#define encode_vsh(rs1, vrs2, imm_8)                            GEN_VEC_INSTR_TYPE4(imm_8,     0B011,       vrs2,   rs1,    0B1111,       0B01010, 0B11)
#define encode_vsw(rs1, vrs2, imm_8)                            GEN_VEC_INSTR_TYPE4(imm_8,     0B101,       vrs2,   rs1,    0B1111,       0B01010, 0B11)
#define encode_vsf(rs1, vrs2, imm_8)                            GEN_VEC_INSTR_TYPE4(imm_8,     0B111,       vrs2,   rs1,    0B1111,       0B01010, 0B11)

#define encode_vsset_s(vsrd, rs1,  rs2)                         GEN_VEC_INSTR_TYPE2(0B0, 0B0,                rs2,   rs1,    0B1000,vsrd,  0B01010, 0B11)
#define encode_vsset_i(vsrd, imm1_7, imm2_7)                    GEN_VEC_INSTR_TYPE5(imm1_7, imm2_7, 0B001,                  0B1000,vsrd,  0B01010, 0B11)
#define encode_vfusion_s(rs,  sat_5, su, rnd)                   GEN_VEC_INSTR_TYPE6(su, rnd, 0B010, sat_5, rs,              0B1000, 0B0,  0B01010, 0B11)
#define encode_vfusion_v(vrs, sat_5, su, rnd)                   GEN_VEC_INSTR_TYPE6(su, rnd, 0B011, sat_5,vrs,              0B1000, 0B0,  0B01010, 0B11)
#define encode_vloop_start(imm_18)                              GEN_VEC_INSTR_TYPE7(imm_18, 0B100,                          0B1000,       0B01010, 0B11)
#define encode_vloop_end(imm_4)                                 GEN_VEC_INSTR_TYPE2(0B0, 0B110, 0B0, 0B0,                   0B1000,imm_4, 0B01010, 0B11)
/******************************************************************************************************************************************************/
#define encode_mad(    vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B0, 0B0, rs2, rs1, 0B00, 0B00, vbrd, 0B10110, 0B11)
#define encode_madc(   vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B0, 0B1, rs2, rs1, 0B00, 0B00, vbrd, 0B10110, 0B11)
#define encode_mmad(   vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B1, 0B0, rs2, rs1, 0B00, 0B00, vbrd, 0B10110, 0B11)
#define encode_mmadc(  vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B1, 0B1, rs2, rs1, 0B00, 0B00, vbrd, 0B10110, 0B11)
#define encode_mvmad(  vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B1, 0B0, rs2, rs1, 0B00, 0B01, vbrd, 0B10110, 0B11)
#define encode_mvmadc( vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B1, 0B1, rs2, rs1, 0B00, 0B01, vbrd, 0B10110, 0B11)
#define encode_mvbmad( vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B1, 0B0, rs2, rs1, 0B00, 0B10, vbrd, 0B10110, 0B11)
#define encode_mvbmadc(vbrd, rs1, rs2, pt_idx)                  GEN_MTX_INSTR_TYPE1(pt_idx, 0B0,    0B1, 0B1, rs2, rs1, 0B00, 0B10, vbrd, 0B10110, 0B11)
#define encode_mcmad(  vbrd, rs1, rs2, pt_idx, fm2_en)          GEN_MTX_INSTR_TYPE1(pt_idx, fm2_en, 0B1, 0B0, rs2, rs1, 0B00, 0B11, vbrd, 0B10110, 0B11)
#define encode_mcmadc( vbrd, rs1, rs2, pt_idx, fm2_en)          GEN_MTX_INSTR_TYPE1(pt_idx, fm2_en, 0B1, 0B1, rs2, rs1, 0B00, 0B11, vbrd, 0B10110, 0B11)
#define encode_mx(     vbrd, rs1, rs2, pt_idx, fm2_en)          GEN_MTX_INSTR_TYPE1(pt_idx, fm2_en, 0B0, 0B0, rs2, rs1, 0B01, 0B11, vbrd, 0B10110, 0B11)
#define encode_mxc(    vbrd, rs1, rs2, pt_idx, fm2_en)          GEN_MTX_INSTR_TYPE1(pt_idx, fm2_en, 0B0, 0B1, rs2, rs1, 0B01, 0B11, vbrd, 0B10110, 0B11)
#define encode_mi(     vbrd, rs1, rs2, pt_idx, fm2_en)          GEN_MTX_INSTR_TYPE1(pt_idx, fm2_en, 0B0, 0B0, rs2, rs1, 0B10, 0B11, vbrd, 0B10110, 0B11)
#define encode_mic(    vbrd, rs1, rs2, pt_idx, fm2_en)          GEN_MTX_INSTR_TYPE1(pt_idx, fm2_en, 0B0, 0B1, rs2, rs1, 0B10, 0B11, vbrd, 0B10110, 0B11)
/******************************************************************************************************************************************************/
#define encode_barrier( rs1)                                    GEN_SPC_INSTR_TYPE1(0B0011,   0B000,  0B00101,     rs1, 0B000, 0B00000, 0B11100, 0B11)
#define encode_buf_push(imm_pnum, pt_idx)                       GEN_SPC_INSTR_TYPE1(pt_idx,   0B000, imm_pnum, 0B00000, 0B000, 0B00000, 0B11110, 0B11)
#define encode_buf_pop( vrd)                                    GEN_SPC_INSTR_TYPE2(0B0000,   0B001,  0B00000, 0B00000, 0B000,     vrd, 0B11110, 0B11)
#define encode_idep_set(immd_5, imm1_5, imm2_5, imm3_5)         GEN_SPC_INSTR_TYPE3(  0B00,  imm3_5,   imm2_5,  imm1_5, 0B100,  immd_5, 0B11110, 0B11)
#define encode_idep_rls()                                       GEN_SPC_INSTR_TYPE3(  0B01, 0B00000,  0B00000, 0B00000, 0B100, 0B00000, 0B11110, 0B11)
#define encode_ddep_set(immd_5, imm1_5, imm2_5, imm3_5)         GEN_SPC_INSTR_TYPE3(  0B00,  imm3_5,   imm2_5,  imm1_5, 0B101,  immd_5, 0B11110, 0B11)
#define encode_ddep_rls()                                       GEN_SPC_INSTR_TYPE3(  0B01, 0B00000,  0B00000, 0B00000, 0B101, 0B00000, 0B11110, 0B11)



/******************************************************************************************************************************************************/
#endif/*_MANASI_ASM_INSTR_ENCODE_H__*/