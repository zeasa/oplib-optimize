#include "testbench_encode_vec.hpp"
#include "npu_instr_encode.h"

uint32_t do_encode_vadd_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vadd_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vadd_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vadd_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vaddc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vaddc_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vaddc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)           
{
    return encode_vaddc_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vsub_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vsub_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vsub_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vsub_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vsubc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vsubc_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vsubc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)           
{
    return encode_vsubc_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vrsub_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vrsub_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vrsub_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)           
{
    return encode_vrsub_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vrsubc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)           
{
    return encode_vrsubc_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vrsubc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)          
{
    return encode_vrsubc_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}


uint32_t do_encode_vge_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)              
{
    return encode_vge_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vge_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vge_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vgeu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vgeu_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vgeu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vgeu_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vlt_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)              
{
    return encode_vlt_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vlt_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vlt_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vltu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vltu_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vltu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vltu_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}


uint32_t do_encode_vand_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vand_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vand_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vand_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vor_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)              
{
    return encode_vor_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vor_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vor_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vxor_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)             
{
    return encode_vxor_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vxor_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vxor_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vnxor_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vnxor_vs(vrd, vrs1, rs2, msk_idx, sh_idx);
}

uint32_t do_encode_vnxor_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx, uint32_t sh_idx)           
{
    return encode_vnxor_vv(vrd, vrs1, vrs2, msk_idx, sh_idx);
}


uint32_t do_encode_vmand(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx)           
{
    return encode_vmand(vmrd, vmrs1, vmrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vmor(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx)            
{
    return encode_vmor(vmrd, vmrs1, vmrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vmxor(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx)           
{
    return encode_vmxor(vmrd, vmrs1, vmrs2, msk_idx, sh_idx);
}

uint32_t do_encode_vmnxor(uint32_t vmrd, uint32_t vmrs1, uint32_t vmrs2, uint32_t msk_idx, uint32_t sh_idx)          
{
    return encode_vmnxor(vmrd, vmrs1, vmrs2, msk_idx, sh_idx);
}


uint32_t do_encode_vsrl_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                        
{
    return encode_vsrl_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vsrl_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                       
{
    return encode_vsrl_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vsra_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                        
{
    return encode_vsra_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vsra_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                       
{
    return encode_vsra_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vsrc_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                        
{
    return encode_vsrc_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vsrc_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                       
{
    return encode_vsrc_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vsrs_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                        
{
    return encode_vsrs_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vsrs_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                       
{
    return encode_vsrs_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vsrl_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx)                        
{
    return encode_vsrl_vi(vrd, vrs1, imm_5, msk_idx);
}

uint32_t do_encode_vsra_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx)                        
{
    return encode_vsra_vi(vrd, vrs1, imm_5, msk_idx);
}

uint32_t do_encode_vsrc_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx)                        
{
    return encode_vsrc_vi(vrd, vrs1, imm_5, msk_idx);
}

uint32_t do_encode_vsrs_vi(uint32_t vrd, uint32_t vrs1, uint32_t imm_5, uint32_t msk_idx)                        
{
    return encode_vsrs_vi(vrd, vrs1, imm_5, msk_idx);
}

uint32_t do_encode_vsl_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                         
{
    return encode_vsl_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vsl_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                        
{
    return encode_vsl_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vsl_vi(uint32_t vrd, uint32_t vrs1, uint32_t rs2,uint32_t imm_5, uint32_t msk_idx)                         
{
    return encode_vsl_vi(vrd, vrs1, rs2, imm_5, msk_idx);
}

uint32_t do_encode_vmulu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                             
{
    return encode_vmulu_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vmulu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                            
{
    return encode_vmulu_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vmulus_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                            
{
    return encode_vmulus_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vmulus_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                           
{
    return encode_vmulus_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vmulsu_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                            
{
    return encode_vmulsu_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vmulsu_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                           
{
    return encode_vmulsu_vv(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vmul_vs(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                              
{
    return encode_vmul_vs(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vmul_vv(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                             
{
    return encode_vmul_vv(vrd, vrs1, vrs2, msk_idx);
}


uint32_t do_encode_valign_h(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                             
{
    return encode_valign_h(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_valign_v(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                            
{
    return encode_valign_v(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_valign_cross(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                         
{
    return encode_valign_cross(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vsel(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t sel_idx)                                
{
    return encode_vsel(vrd, vrs1, vrs2, sel_idx);
}

uint32_t do_encode_vargsort(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                             
{
    return encode_vargsort(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vreorder(uint32_t vrd, uint32_t vrs1, uint32_t rs2, uint32_t msk_idx)                             
{
    return encode_vreorder(vrd, vrs1, rs2, msk_idx);
}

uint32_t do_encode_vtranspose(uint32_t vrd, uint32_t vrs1, uint32_t      msk_idx)                                    
{
    return encode_vtranspose(vrd, vrs1,      msk_idx);
}


uint32_t do_encode_vrmax(uint32_t vmrd, uint32_t vrs1, uint32_t sel_idx)                                             
{
    return encode_vrmax(vmrd, vrs1, sel_idx);
}

uint32_t do_encode_vrmin(uint32_t vmrd, uint32_t vrs1, uint32_t sel_idx)                                             
{
    return encode_vrmin(vmrd, vrs1, sel_idx);
}

uint32_t do_encode_vrsum(uint32_t vrd, uint32_t vrs1, uint32_t sel_idx)                                              
{
    return encode_vrsum(vrd, vrs1, sel_idx);
}

uint32_t do_encode_vrcompress(uint32_t vrd, uint32_t vrs1, uint32_t sel_idx)                                         
{
    return encode_vrcompress(vrd, vrs1, sel_idx);
}


uint32_t do_encode_vfadd(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                               
{
    return encode_vfadd(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vfsub(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                               
{
    return encode_vfsub(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vfmul(uint32_t vrd, uint32_t vrs1, uint32_t vrs2, uint32_t msk_idx)                               
{
    return encode_vfmul(vrd, vrs1, vrs2, msk_idx);
}

uint32_t do_encode_vfsort(uint32_t vrd, uint32_t vrs1, uint32_t  rs2, uint32_t msk_idx)                              
{
    return encode_vfsort(vrd, vrs1,  rs2, msk_idx);
}

uint32_t do_encode_vftoi(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx)                                              
{
    return encode_vftoi(vrd, vrs1, msk_idx);
}

uint32_t do_encode_vitof(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx)                                              
{
    return encode_vitof(vrd, vrs1, msk_idx);
}


uint32_t do_encode_vlog2(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx)                                              
{
    return encode_vlog2(vrd, vrs1, msk_idx);
}

uint32_t do_encode_vexp2(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx)                                              
{
    return encode_vexp2(vrd, vrs1, msk_idx);
}

uint32_t do_encode_vrcp(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx)                                               
{
    return encode_vrcp(vrd, vrs1, msk_idx);
}

uint32_t do_encode_vsqrt(uint32_t vrd, uint32_t vrs1, uint32_t msk_idx)                                              
{
    return encode_vsqrt(vrd, vrs1, msk_idx);
}


uint32_t do_encode_vlb(uint32_t vrd, uint32_t rs1, uint32_t imm_8)                                                   
{
    return encode_vlb(vrd, rs1, imm_8);
}

uint32_t do_encode_vlbu(uint32_t vrd, uint32_t rs1, uint32_t imm_8)                                                  
{
    return encode_vlbu(vrd, rs1, imm_8);
}

uint32_t do_encode_vlh(uint32_t vrd, uint32_t rs1, uint32_t imm_8)                                                   
{
    return encode_vlh(vrd, rs1, imm_8);
}

uint32_t do_encode_vlhu(uint32_t vrd, uint32_t rs1, uint32_t imm_8)                                                  
{
    return encode_vlhu(vrd, rs1, imm_8);
}

uint32_t do_encode_vlw(uint32_t vrd, uint32_t rs1, uint32_t imm_8)                                                   
{
    return encode_vlw(vrd, rs1, imm_8);
}

uint32_t do_encode_vlf(uint32_t vrd, uint32_t rs1, uint32_t imm_8)                                                   
{
    return encode_vlf(vrd, rs1, imm_8);
}


uint32_t do_encode_vsb(uint32_t rs1, uint32_t vrs2, uint32_t imm_8)                                                  
{
    return encode_vsb(rs1, vrs2, imm_8);
}

uint32_t do_encode_vsh(uint32_t rs1, uint32_t vrs2, uint32_t imm_8)                                                  
{
    return encode_vsh(rs1, vrs2, imm_8);
}

uint32_t do_encode_vsw(uint32_t rs1, uint32_t vrs2, uint32_t imm_8)                                                  
{
    return encode_vsw(rs1, vrs2, imm_8);
}

uint32_t do_encode_vsf(uint32_t rs1, uint32_t vrs2, uint32_t imm_8)                                                  
{
    return encode_vsf(rs1, vrs2, imm_8);
}


uint32_t do_encode_vsset_s(uint32_t vsrd, uint32_t rs1, uint32_t  rs2)                                               
{
    return encode_vsset_s(vsrd, rs1,  rs2);
}

uint32_t do_encode_vsset_i(uint32_t vsrd, uint32_t imm1_7, uint32_t imm2_7)                                          
{
    return encode_vsset_i(vsrd, imm1_7, imm2_7);
}

uint32_t do_encode_vfusion_s(uint32_t rs, uint32_t  sat_5, uint32_t su, uint32_t rnd)                                
{
    return encode_vfusion_s(rs,  sat_5, su, rnd);
}

uint32_t do_encode_vfusion_v(uint32_t vrs, uint32_t sat_5, uint32_t su, uint32_t rnd)                                
{
    return encode_vfusion_v(vrs, sat_5, su, rnd);
}

uint32_t do_encode_vloop_start(uint32_t imm_18)                                                                      
{
    return encode_vloop_start(imm_18);
}

uint32_t do_encode_vloop_end(uint32_t imm_4)                                                                         
{
    return encode_vloop_end(imm_4);
}
