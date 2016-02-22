/*
 * File: pushb.s
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * 
 * Computer Systems Engineering
 *
 */

.file "pushb.s"
.syntax unified
.include "pushb_inc.s"



.global pushb_poll_A1
.global pushb_poll_A2
.global pushb_poll_A12
.global pushb_poll_D
.global pushb_init_A1
.global pushb_init_A2
.global pushb_init_A12
.global pushb_init_D
.global pushb_poll_all
.text
.func pushb_init_A1, pushb_init_A1
.type pushb_init_A1, %function
.thumb_func 

pushb_init_A1: 
    push {lr}
    movs r1, r0
    movs r0, #1
    bl uc_gpio_config_A
    pop {pc}
.endfunc

.func pushb_init_A2, pushb_init_A2
.type pushb_init_A2, %function
.thumb_func 

pushb_init_A2: 
    push {lr}
    movs r1, r0
    movs r0, #2
    bl uc_gpio_config_A
    pop {pc}
.endfunc

.func pushb_init_A12, pushb_init_A12
.type pushb_init_A12, %function
.thumb_func 

pushb_init_A12: 
    push {lr}
    movs r1, r0
    movs r0, #12
    bl uc_gpio_config_A
    pop {pc}
.endfunc

.func pushb_init_D, pushb_init_D
.type pushb_init_D, %function
.thumb_func

pushb_init_D:
    push {lr}
    movs r1, r0
    movs r0, #3
    bl uc_gpio_config_D
    pop {pc}
.endfunc

.func pushb_poll_A1, pushb_poll_A1
.type pushb_poll_A1, %function
.thumb_func
pushb_poll_A1:

    push {lr}
    bl uc_gpio_pin_test
    pop {pc}
.endfunc

.func pushb_poll_A2, pushb_poll_A2
.type pushb_poll_A2, %function
.thumb_func
pushb_poll_A2:

    push {lr}
    bl uc_gpio_pin_test_A
    pop {pc}
.endfunc 

.func pushb_poll_A12, pushb_poll_A12
.type pushb_poll_A12, %function
.thumb_func
pushb_poll_A12:

    push {lr}
    bl uc_gpio_pin_test_A
    pop {pc}
.endfunc
  
.func pushb_poll_D, pushb_poll_D
.type pushb_poll_D, %function
.thumb_func
pushb_poll_D:
    push {lr}
    bl uc_gpio_pin_test_D
    pop {pc}
.endfunc

.func pushb_poll_all, pushb_poll_all
.type pushb_poll_all, %function
.thumb_func
pushb_poll_all:
    push {lr}
    bl uc_gpio_pin_test
    pop {pc}
.endfunc    
    
    
