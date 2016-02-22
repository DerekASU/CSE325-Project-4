/*
 * File: tpm_inc.s
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "global.h"
#include "tpm.h"
#include "gpio.h"

.ifndef TPM_INC
.equ TPM_INC, 1
.syntax unified

.file "tpm_inc.s"

.extern tpm_busy_delay_us
.extern tpm_busy_delay_ms

.endif

