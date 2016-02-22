/*
 * File: led.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "led.h"
#include "global.h"
#include "tpm.h"

void uc_led_on(int n)//turning on individual LEDs
{
	GPIOB_PDOR |= 1 << n;
}

void uc_led_off(int n)//turning off individual LEDs
{
	GPIOB_PDOR &= ~(1 << n);
}

void uc_led_all_off()//turning off all LEDs 
{
	uc_led_off(0);
	uc_led_off(1);
	uc_led_off(2);
	uc_led_off(3);
}

void uc_led_all_on()//turning on all LEDs
{
	uc_led_on(0);
	uc_led_on(1);
	uc_led_on(2);
	uc_led_on(3);
}

void uc_led_after_win()
{
	uc_led_all_off();
	tpm_busy_delay_ms(250);
	uc_led_all_on();
	tpm_busy_delay_ms(250);
	uc_led_all_off();
	tpm_busy_delay_ms(250);
	uc_led_all_on();
	tpm_busy_delay_ms(250);
	uc_led_all_off();
	tpm_busy_delay_ms(250);
	uc_led_all_on();
	tpm_busy_delay_ms(250);
}
