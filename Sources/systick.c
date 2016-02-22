/*
 * File: systick.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "systick.h"
#include "global.h"

void systick_init()
{
	SYST_RVR = 0x00FFFFFF;
	SYST_CVR = 0;
	SYST_CSR = 0x00000005;
}

int systick_read()
{
	return SYST_CVR;
}
