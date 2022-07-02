#ifndef _MANASI_ASM_INSTR_GEN_H__
#define _MANASI_ASM_INSTR_GEN_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#define MSHIFT(val, msk, shft)  ((val & msk) << shft)
#define _TOSTR(x)               #x
#define TOSTR(x)                _TOSTR(x)

#define REG1                    sr_t5
#define REG2                    sr_t6
#define COPY_VAR1               "mv t5, %0\n"
#define COPY_VAR2               "mv t6, %0\n"
#define COPY_VAR12              "mv t5, %0\nmv t6, %1\n"

#define COPY_VAR1_END(x)        ::"r"(x): "t5"
#define COPY_VAR2_END(x)        ::"r"(x): "t6"
#define COPY_VAR12_END(x,y)     ::"r"(x),"r"(y): "t5","t6"

#define GEN_VEC_INSTR_TYPE1(bit31_28, bit27_26, bit25, bit24_20, bit19_15, bit14_11, bit10_7, bit6_2, bit1_0) \
            MSHIFT(bit31_28, 0xF,   28) |                                                                     \
            MSHIFT(bit27_26, 0x3,   26) |                                                                     \
            MSHIFT(bit25,    0x1,   25) |                                                                     \
            MSHIFT(bit24_20, 0x1F,  20) |                                                                     \
            MSHIFT(bit19_15, 0x1F,  15) |                                                                     \
            MSHIFT(bit14_11, 0xF,   11) |                                                                     \
            MSHIFT(bit10_7,  0xF,    7) |                                                                     \
            MSHIFT(bit6_2,   0x1F,   2) |                                                                     \
            MSHIFT(bit1_0,   0x3,    0)

#define GEN_VEC_INSTR_TYPE2(bit31_28, bit27_25, bit24_20, bit19_15, bit14_11, bit10_7, bit6_2, bit1_0) \
            MSHIFT(bit31_28, 0xF,   28) |                                                              \
            MSHIFT(bit27_25, 0x7,   25) |                                                              \
            MSHIFT(bit24_20, 0x1F,  20) |                                                              \
            MSHIFT(bit19_15, 0x1F,  15) |                                                              \
            MSHIFT(bit14_11, 0xF,   11) |                                                              \
            MSHIFT(bit10_7,  0xF,    7) |                                                              \
            MSHIFT(bit6_2,   0x1F,   2) |                                                              \
            MSHIFT(bit1_0,   0x3,    0)

#define GEN_VEC_INSTR_TYPE3(imm_8, bit27_25, bit19_15, bit14_11, bit10_7, bit6_2, bit1_0)  \
            MSHIFT(imm_8,    0xF0,  (28 - 4))|                                             \
            MSHIFT(bit27_25, 0x7,   25)      |                                             \
            MSHIFT(imm_8,    0x0F,  20)      |                                             \
            MSHIFT(bit19_15, 0x1F,  15)      |                                             \
            MSHIFT(bit14_11, 0xF,   11)      |                                             \
            MSHIFT(bit10_7,  0xF,    7)      |                                             \
            MSHIFT(bit6_2,   0x1F,   2)      |                                             \
            MSHIFT(bit1_0,   0x3,    0)

#define GEN_VEC_INSTR_TYPE4(imm_8, bit27_25, bit24_20, bit19_15, bit14_11, bit6_2, bit1_0)  \
            MSHIFT(imm_8,    0xF0,  (28 - 4))|                                              \
            MSHIFT(bit27_25, 0x7,   25)      |                                              \
            MSHIFT(bit24_20, 0x1F,  20)      |                                              \
            MSHIFT(bit19_15, 0x1F,  15)      |                                              \
            MSHIFT(bit14_11, 0xF,   11)      |                                              \
            MSHIFT(imm_8,    0x0F,   7)      |                                              \
            MSHIFT(bit6_2,   0x1F,   2)      |                                              \
            MSHIFT(bit1_0,   0x3,    0)

#define GEN_VEC_INSTR_TYPE5(imm1_7, imm2_7, bit27_25, bit14_11, bit8_7, bit6_2, bit1_0)  \
            MSHIFT(imm2_7,   0x60,  (30 - 5))|                                           \
            MSHIFT(imm1_7,   0x60,  (28 - 5))|                                           \
            MSHIFT(bit27_25, 0x7,   25)      |                                           \
            MSHIFT(imm2_7,   0x1F,  20)      |                                           \
            MSHIFT(imm1_7,   0x1F,  15)      |                                           \
            MSHIFT(bit14_11, 0xF,   11)      |                                           \
            MSHIFT(bit8_7,   0x3,    7)      |                                           \
            MSHIFT(bit6_2,   0x1F,   2)      |                                           \
            MSHIFT(bit1_0,   0x3,    0)

#define GEN_VEC_INSTR_TYPE6(bit31, bit29_28, bit27_25, bit24_20, bit19_15, bit14_11, bit10_7, bit6_2, bit1_0) \
            MSHIFT(bit31,    0x1,   31) |                                                                     \
            MSHIFT(bit29_28, 0x3,   28) |                                                                     \
            MSHIFT(bit27_25, 0x7,   25) |                                                                     \
            MSHIFT(bit24_20, 0x1F,  20) |                                                                     \
            MSHIFT(bit19_15, 0x1F,  15) |                                                                     \
            MSHIFT(bit14_11, 0xF,   11) |                                                                     \
            MSHIFT(bit10_7,  0xF,    7) |                                                                     \
            MSHIFT(bit6_2,   0x1F,   2) |                                                                     \
            MSHIFT(bit1_0,   0x3,    0)

#define GEN_VEC_INSTR_TYPE7(imm_18, bit27_25, bit14_11, bit6_2, bit1_0) \
            MSHIFT(imm_18,   0xF0,   (28 - 4)) |                        \
            MSHIFT(bit27_25, 0x7,     25)      |                        \
            MSHIFT(imm_18,   0x3E000,(20 -13)) |                        \
            MSHIFT(imm_18,   0x1F00, (15 - 8)) |                        \
            MSHIFT(bit14_11, 0xF,     11)      |                        \
            MSHIFT(imm_18,   0xF,    ( 7 - 0)) |                        \
            MSHIFT(bit6_2,   0x1F,     2)      |                        \
            MSHIFT(bit1_0,   0x3,      0)

#define GEN_MTX_INSTR_TYPE1(bit31_28, bit27, bit26, bit25, bit24_20, bit19_15, bit14_13, bit12_11, bit10_7, bit6_2, bit1_0) \
            MSHIFT(bit31_28, 0xF,   28) |                                                                                   \
            MSHIFT(bit27,    0x1,   27) |                                                                                   \
            MSHIFT(bit26,    0x1,   26) |                                                                                   \
            MSHIFT(bit25,    0x1,   25) |                                                                                   \
            MSHIFT(bit24_20, 0x1F,  20) |                                                                                   \
            MSHIFT(bit19_15, 0x1F,  15) |                                                                                   \
            MSHIFT(bit14_13, 0x3,   13) |                                                                                   \
            MSHIFT(bit12_11, 0x3,   11) |                                                                                   \
            MSHIFT(bit10_7,  0xF,    7) |                                                                                   \
            MSHIFT(bit6_2,   0x1F,   2) |                                                                                   \
            MSHIFT(bit1_0,   0x3,    0)

#define GEN_SPC_INSTR_TYPE1(bit31_28, bit27_25, bit24_20, bit19_15, bit14_12, bit11_7, bit6_2, bit1_0) \
            MSHIFT(bit31_28, 0xF,   28) |                                                              \
            MSHIFT(bit27_25, 0x7,   25) |                                                              \
            MSHIFT(bit24_20, 0x1F,  20) |                                                              \
            MSHIFT(bit19_15, 0x1F,  15) |                                                              \
            MSHIFT(bit14_12, 0x7,   12) |                                                              \
            MSHIFT(bit11_7,  0x1F,   7) |                                                              \
            MSHIFT(bit6_2,   0x1F,   2) |                                                              \
            MSHIFT(bit1_0,   0x3,    0)
#define GEN_SPC_INSTR_TYPE2(bit31_28, bit27_25, bit24_20, bit19_15, bit14_12, bit10_7, bit6_2, bit1_0) \
            MSHIFT(bit31_28, 0xF,   28) |                                                              \
            MSHIFT(bit27_25, 0x7,   25) |                                                              \
            MSHIFT(bit24_20, 0x1F,  20) |                                                              \
            MSHIFT(bit19_15, 0x1F,  15) |                                                              \
            MSHIFT(bit14_12, 0x7,   12) |                                                              \
            MSHIFT(bit10_7,  0xF,    7) |                                                              \
            MSHIFT(bit6_2,   0x1F,   2) |                                                              \
            MSHIFT(bit1_0,   0x3,    0)
#define GEN_SPC_INSTR_TYPE3(bit31_30, bit29_25, bit24_20, bit19_15, bit14_12, bit11_7, bit6_2, bit1_0) \
            MSHIFT(bit31_30, 0x3,   30) |                                                              \
            MSHIFT(bit29_25, 0x1F,  25) |                                                              \
            MSHIFT(bit24_20, 0x1F,  20) |                                                              \
            MSHIFT(bit19_15, 0x1F,  15) |                                                              \
            MSHIFT(bit14_12, 0x7,   12) |                                                              \
            MSHIFT(bit11_7,  0x1F,   7) |                                                              \
            MSHIFT(bit6_2,   0x1F,   2) |                                                              \
            MSHIFT(bit1_0,   0x3,    0)

#ifdef __cplusplus
}
#endif

#endif/*_MANASI_ASM_INSTR_LIST_H__*/