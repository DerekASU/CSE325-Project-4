/*
 * File: tpm.h
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Computer Systems Engineering
 *
 */
#ifndef TPM_H_
#define TPM_H_

#include "global.h"

void tpm_busy_delay_us(uint32_t);
void tpm_busy_delay_ms(uint32_t);

#endif

