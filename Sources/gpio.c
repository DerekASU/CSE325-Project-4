/*
 * File: gpio.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "gpio.h"
#include "global.h"
void uc_gpio_config_B(int n) //function to configure the specific gpio ports for output.
{
	PTB_BASE_PTR->PDDR |= 1 << n;
}

void uc_gpio_config_A(int n) //function to configure the specific gpio ports for output.
{
	PTA_BASE_PTR->PDDR &= ~(1 << n);
}

void uc_gpio_config_D(int n) //function to configure the specific gpio ports for output.
{
	PTD_BASE_PTR->PDDR &= ~(1 << n);
}
int uc_gpio_pin_test_A(int n)
{
	int result;
	result = (PTA_BASE_PTR->PDIR >> n)& 1;
	return result;
}
int uc_gpio_pin_test()
{
	if(~GPIOA_PDIR & (1 << 1)){
		return 4;
	}
	else if(~GPIOA_PDIR & (1 << 2)){
			return 3;
		}
	else if(~GPIOA_PDIR & (1 << 12)){
			return 1;
		}
	else if(~GPIOD_PDIR & (1 << 3)){
			return 2;
		}
	return 0;
}
int uc_gpio_pin_test_D(int n)
{
	int result;
	result = (PTD_BASE_PTR->PDIR >> n)& 1;
	return result;
}
