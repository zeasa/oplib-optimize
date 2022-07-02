#include "testbench_encode_mtx.hpp"
#include "npu_instr_encode.h"

uint32_t do_encode_mad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{    
    return encode_mad(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_madc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{    
    return encode_madc(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_mmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{    
    return encode_mmad(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_mmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{    
    return encode_mmadc(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_mvmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{    
    return encode_mvmad(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_mvmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{   
    return encode_mvmadc(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_mvbmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{    
    return encode_mvbmad(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_mvbmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx)           
{    
    return encode_mvbmadc(vbrd, rs1, rs2, pt_idx);
}

uint32_t do_encode_mcmad(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en)   
{    
    return encode_mcmad(vbrd, rs1, rs2, pt_idx, fm2_en);
}

uint32_t do_encode_mcmadc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en)   
{    
    return encode_mcmadc(vbrd, rs1, rs2, pt_idx, fm2_en);
}

uint32_t do_encode_mx(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en)   
{    
    return encode_mx(vbrd, rs1, rs2, pt_idx, fm2_en);
}

uint32_t do_encode_mxc(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en)   
{    
    return encode_mxc(vbrd, rs1, rs2, pt_idx, fm2_en);
}
uint32_t do_encode_mi(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en)   
{    
    return encode_mi(vbrd, rs1, rs2, pt_idx, fm2_en);
}

uint32_t do_encode_mic(uint32_t vbrd, uint32_t rs1, uint32_t rs2, uint32_t pt_idx, uint32_t fm2_en)   
{    
    return encode_mic(vbrd, rs1, rs2, pt_idx, fm2_en);
}