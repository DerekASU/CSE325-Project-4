/*
 * File: rand.h
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Computer Systems Engineering
 *
 */
#ifndef RAND_H_
#define RAND_H_
#include "global.h"

void rand_init();
uint32_t rand_next();
uint32_t rand_between(uint32_t lower, uint32_t upper);

#endif
