/*
 * File: pushb_inc.s
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */

.ifndef PUSHB_INC
.equ PUSHB_INC, 1

.file "pushb_inc.s"
.syntax unified


.extern pushb_poll_A1
.extern pushb_poll_A2
.extern pushb_poll_A12
.extern pushb_poll_D
.extern pushb_init_A1
.extern pushb_init_A2
.extern pushb_init_A12
.extern pushb_init_D
.extern pushb_poll_all
.endif
