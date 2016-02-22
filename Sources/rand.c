/*
 * File: rand.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "rand.h"
#include "systick.h"
#include "global.h"

uint32_t prev;

void rand_init()
{
	systick_init();
	prev = systick_read();
}

uint32_t rand_next()
{
	uint32_t next_number;
	next_number = (1103515245 * prev + 12345)% 4294967296;
	prev = next_number;
	return next_number;
	
}

uint32_t rand_between(uint32_t lower, uint32_t upper)
{
	uint32_t range = upper - lower + 1;
	return lower + rand_next() % range;
}
