/*
 * File: tpm.s
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
.file "tpm.s"
.include "tpm_inc.s"
.global tpm_busy_delay_us
.global tpm_busy_delay_ms
.syntax unified
.text
/*void tpm_busy_delay_us(uint32_t p_delay_us)
{
        SIM_SCGC6 |= 1 << 24;
        SIM_SOPT2 |= 0b11 << 24;
        TPM0_SC &= ~(0b11 << 3);
        TPM0_SC |= 0b01000010;
        TPM0_CNT = 0b000000000000000;
        TPM0_MOD = p_delay_us - 1;
        TPM0_CONF &= ~(0b11 << 16);

        while(~TPM0_SC & TPM_SC_TOF_MASK) {}
        TPM0_SC |= 1 << 7;
        
}
*/
.func tpm_busy_delay_us, tpm_busy_delay_us
.type tpm_busy_delay_us, %function
.thumb_func
tpm_busy_delay_us:

    ldr r1, sim_scg6
    ldr r2, [r1]
    movs r3, #1
    lsls r3, 24
    orrs r2, r3
    str r2, [r1]
    

    ldr r1, sim_sopt2
    ldr r2, [r1]
    movs r3, #3
    lsls r3, 24
    orrs r2, r3
    str r2, [r1]
    

    ldr r1, tpm0_sc
    ldr r2, [r1]
    movs r3, #3
    lsls r3, 3
    rsbs r3, r3, #0
    ands r2, r3
    str r2, [r1]
    

    ldr r1, tpm0_sc
    ldr r2, [r1]
    movs r3, #130
    orrs r2, r3
    str r2, [r1]
    

    ldr r1, tpm0_cnt
    movs r2, #0
    str r2, [r1]
    

    ldr r1, tpm0_mod
    ldr r2, [r1]
    movs r3, #1
    subs r2,r0,1 
    str r2, [r1]
    

    ldr r1, tpm0_conf
    ldr r2, [r1]
    movs r3, #3
    lsls r3, 16
    rsbs r3, r3, #0
    ands r2, r3
    str r2, [r1]
    
    ldr r1, tpm0_sc
    ldr r2, [r1]
    movs r3, #1
    lsls r3, 3
    orrs r2, r3
    str r2, [r1]

    comparewhile:
     ldr r1, tpm0_sc
     ldr r2, tpm_sc_mask
     rsbs r1, r1, #0
     ands r1, r2
     cmp r1, #128
     bne comparewhile

    

    ldr r1, tpm0_sc
    ldr r2, [r1]
    movs r3, #1
    lsls r3, 7
    orrs r2, r3
    str r2, [r1]
    bx lr
.endfunc 
    
    
    
 
/*void tpm_busy_delay_ms(uint32_t p_delay_ms)
{
    SIM_SCGC6 |= 1 << 24;
    SIM_SOPT2 |= 0b11 << 24;
    TPM0_SC &= ~(0b11 << 3);
    TPM0_SC |= 0b010000010;
    TPM0_CNT = 0b000000000000000;
    TPM0_MOD = 999;
    TPM0_CONF &= ~(0b11 << 16);
    TPM0_SC |= (0b01 << 3);
    for(uint32_t i = 0; i < p_delay_ms; i++)
    {
    Loop:
        ldr r1, #0
        while(~TPM0_SC & TPM_SC_TOF_MASK) {}
        TPM0_SC |= 1 << 7;
        add r1, r1, #1
        cmp r1, r0
        ble Loop

    }
}
*/
.func tpm_busy_delay_ms, tpm_busy_delay_ms
.type tpm_busy_delay_ms, %function
.thumb_func
tpm_busy_delay_ms:

    ldr r1, sim_scg6
    ldr r2, [r1]
    movs r3, #1
    lsls r3, 24
    orrs r2, r3
    str r2, [r1]
    

    ldr r1, sim_sopt2
    ldr r2, [r1]
    movs r3, #3
    lsls r3, 24
    orrs r2, r3
    str r2, [r1]
    

    ldr r1, tpm0_sc
    ldr r2, [r1]
    movs r3, #3
    lsls r3, 3
    rsbs r3, r3, #0
    ands r2, r3
    str r2, [r1]
    

    ldr r1, tpm0_sc
    ldr r2, [r1]
    movs r3, #130
    orrs r2, r3
    str r2, [r1]
    

    ldr r1, tpm0_cnt
    movs r2, #0
    str r2, [r1]
    

    ldr r1, tpm0_mod
    ldr r3, mod_ms 
    str r3, [r1]
    

    ldr r1, tpm0_conf
    ldr r2, [r1]
    movs r3, #3
    lsls r3, 16
    rsbs r3, r3, #0
    ands r2, r3
    str r2, [r1]
    
    ldr r1, tpm0_sc
    ldr r2, [r1]
    movs r3, #1
    lsls r3, 3
    orrs r2, r3
    str r2, [r1]

    movs r1, #0
    Loop:
      
   
       comparewhile2:
        ldr r3,tpm0_sc
        ldr r3, [r3]
        mvns r2,r3
        movs r3, #128
        ands r3, r2
        bne comparewhile2

        

       ldr r2, tpm0_sc
       ldr r3, [r2]
       movs r4, #1
       lsls r4, 7
       orrs r3, r4
       str r3, [r2]
       
     adds r1, r1, 1
     cmp r1, r0
     ble Loop
     bx lr
 .align 2
mod_ms: .word 999
sim_scg6: .word 0x4004803C
sim_sopt2: .word 0x40048004
tpm0_sc: .word 0x40038000
tpm0_cnt: .word 0x40038004
tpm0_mod: .word 0x40038008
tpm0_conf: .word 0x40038084
tpm_sc_mask: .word 0x80
.endfunc



