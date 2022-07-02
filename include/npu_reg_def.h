#ifndef _MANASI_ASM_REG_DEF_H__
#define _MANASI_ASM_REG_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define sr0                     (0)
#define sr1                     (1)
#define sr2                     (2)
#define sr3                     (3)
#define sr4                     (4)
#define sr5                     (5)
#define sr6                     (6)
#define sr7                     (7)
#define sr8                     (8)
#define sr9                     (9)
#define sr10                    (10)
#define sr11                    (11)
#define sr12                    (12)
#define sr13                    (13)
#define sr14                    (14)
#define sr15                    (15)
#define sr16                    (16)
#define sr17                    (17)
#define sr18                    (18)
#define sr19                    (19)
#define sr20                    (20)
#define sr21                    (21)
#define sr22                    (22)
#define sr23                    (23)
#define sr24                    (24)
#define sr25                    (25)
#define sr26                    (26)
#define sr27                    (27)
#define sr28                    (28)
#define sr29                    (29)
#define sr30                    (30)
#define sr31                    (31)

#define sr_zero                 (sr0)  //hardware zero
#define sr_ra                   (sr1)  //return addr
#define sr_sp                   (sr2)  //stack pointer
#define sr_gp                   (sr3)  //global pointer
#define sr_tp                   (sr4)  //thread pointer
#define sr_t0                   (sr5)  //temporary
#define sr_t1                   (sr6)  //temporary
#define sr_t2                   (sr7)  //temporary
#define sr_s0                   (sr8)  //saved reg
#define sr_s1                   (sr9)  //saved reg
#define sr_a0                   (sr10) //function argument, return val
#define sr_a1                   (sr11) //function argument, return val
#define sr_a2                   (sr12) //function argument
#define sr_a3                   (sr13) //function argument
#define sr_a4                   (sr14) //function argument
#define sr_a5                   (sr15) //function argument
#define sr_a6                   (sr16) //function argument
#define sr_a7                   (sr17) //function argument
#define sr_s2                   (sr18) //saved reg
#define sr_s3                   (sr19) //saved reg
#define sr_s4                   (sr20) //saved reg
#define sr_s5                   (sr21) //saved reg
#define sr_s6                   (sr22) //saved reg
#define sr_s7                   (sr23) //saved reg
#define sr_s8                   (sr24) //saved reg
#define sr_s9                   (sr25) //saved reg
#define sr_s10                  (sr26) //saved reg
#define sr_s11                  (sr27) //saved reg
#define sr_t3                   (sr28) //temporary
#define sr_t4                   (sr29) //temporary
#define sr_t5                   (sr30) //temporary
#define sr_t6                   (sr31) //temporary

// Alias
#define zero                    (sr0) 
#define ra                      (sr1) 
#define sp                      (sr2) 
#define gp                      (sr3) 
#define fp                      (sr8)
#define tp                      (sr4) 
#define t0                      (sr5) 
#define t1                      (sr6) 
#define t2                      (sr7) 
#define t3                      (sr28) 
#define t4                      (sr29) 
#define t5                      (sr30) 
#define t6                      (sr31)
#define s0                      (sr8) 
#define s1                      (sr9) 
#define s2                      (sr18) 
#define s3                      (sr19) 
#define s4                      (sr20) 
#define s5                      (sr21)
#define s6                      (sr22) 
#define s7                      (sr23) 
#define s8                      (sr24) 
#define s9                      (sr25) 
#define s10                     (sr26) 
#define s11                     (sr27)
#define a0                      (sr10) 
#define a1                      (sr11) 
#define a2                      (sr12) 
#define a3                      (sr13) 
#define a4                      (sr14) 
#define a5                      (sr15) 
#define a6                      (sr16) 
#define a7                      (sr17)

#define vr0                     (0)
#define vr1                     (1)
#define vr2                     (2)
#define vr3                     (3)
#define vr4                     (4)
#define vr5                     (5)
#define vr6                     (6)
#define vr7                     (7)
#define vr8                     (8)
#define vr9                     (9)
#define vr10                    (10)
#define vr11                    (11)
#define vr12                    (12)
#define vr13                    (13)
#define vr14                    (14)
#define vr15                    (15)

#define vmr0                    (0) /*64’hffff_ffff_ffff_ffff*/
#define vmr1                    (1) /*64’h5555_5555_5555_5555*/
#define vmr2                    (2) /*64’h0000_0000_0000_00ff*/
#define vmr3                    (3) /*64’h0101_0101_0101_0101*/
#define vmr4                    (4) /*64’hffff_ffff_ffff_ffff*/
#define vmr5                    (5) /*carry out*/
#define vmr6                    (6) /*sign*/
#define vmr7                    (7) /*overflow*/
#define vmr8                    (8) /*mark*/
#define vmr9                    (9) /*equal*/
#define vmr10                   (10)/*general purpose*/
#define vmr11                   (11)/*general purpose*/
#define vmr12                   (12)/*general purpose*/
#define vmr13                   (13)/*general purpose*/
#define vmr14                   (14)/*general purpose*/
#define vmr15                   (15)/*general purpose*/

#define vbr0                    (0)
#define vbr1                    (1)
#define vbr2                    (2)
#define vbr3                    (3)
#define vbr4                    (4)
#define vbr5                    (5)
#define vbr6                    (6)
#define vbr7                    (7)
#define vbr8                    (8)
#define vbr9                    (9)
#define vbr10                   (10)
#define vbr11                   (11)
#define vbr12                   (12)
#define vbr13                   (13)
#define vbr14                   (14)
#define vbr15                   (15)

#define msk_idx0                (0)
#define msk_idx1                (1)
#define msk_idx2                (2)
#define msk_idx3                (3)
#define msk_idx4                (4)
#define msk_idx5                (5)
#define msk_idx6                (6)
#define msk_idx7                (7)
#define msk_idx8                (8)
#define msk_idx9                (9)
#define msk_idx10               (10)
#define msk_idx11               (11)
#define msk_idx12               (12)
#define msk_idx13               (13)
#define msk_idx14               (14)
#define msk_idx15               (15)

#define sft_idx0                (0)
#define sft_idx1                (1)
#define sft_idx2                (2)
#define sft_idx3                (3)

#define ptb_idx0                (0)
#define ptb_idx1                (1)
#define ptb_idx2                (2)
#define ptb_idx3                (3)
#define ptb_idx4                (4)
#define ptb_idx5                (5)
#define ptb_idx6                (6)
#define ptb_idx7                (7)
#define ptb_idx8                (8)
#define ptb_idx9                (9)
#define ptb_idx10               (10)
#define ptb_idx11               (11)
#define ptb_idx12               (12)
#define ptb_idx13               (13)
#define ptb_idx14               (14)
#define ptb_idx15               (15)

#ifdef __cplusplus
}
#endif

#endif/*_MANASI_ASM_REG_DEF_H__*/