/*
 * File: sim.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "sim.h"
#include "global.h"

void uc_sim_clk()
{
	SIM_BASE_PTR->SCGC5 |= 1 << 10;
	SIM_BASE_PTR->SCGC5 |= 1 << 9;
	SIM_BASE_PTR->SCGC5 |= 1 << 12;
}

