/*
 * File: simon.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "simon.h"
#include "rand.h"
#include "tpm.h"
#include "pushb.h"
#include "led.h"
int turn;

#include "simon.h"
#include "gpio.h"

void simonGame () {
	int m, n= 0;
	for (;;){
	int array[n+1 ];
		for (m=0; m < n+1; m++){
				array[m] = rand_between(0,3);
				uc_led_off(array[m]);
				tpm_busy_delay_ms(1000);
				uc_led_all_on();
				tpm_busy_delay_ms(1000);
			}
		int r_counter = 0, w_counter = 0;
		for (r_counter = 0, w_counter =0; !((r_counter == n+1)||(w_counter ==1)) ; ){
			if(pushb_poll_all() == 1){
				uc_led_off(0);
				tpm_busy_delay_ms(1000);
				if (array[r_counter] == 0){
					uc_led_off(0);
					tpm_busy_delay_ms(1000);
					uc_led_all_on();
					tpm_busy_delay_ms(1000);
					r_counter ++;
				}
				else {
					w_counter = 1;
				}
			}
			
			else if (pushb_poll_all() == 2){
				uc_led_off(1);
				tpm_busy_delay_ms(1000);
				if (array[r_counter] == 1){
					uc_led_off(1);
					tpm_busy_delay_ms(1000);
					uc_led_all_on();
					tpm_busy_delay_ms(1000);
					r_counter ++;
					}
					else {
						w_counter = 1;
					}
			}
			else if  (pushb_poll_all() == 3){
				uc_led_off(2);
				tpm_busy_delay_ms(1000);
				if (array[r_counter] == 2){
					uc_led_on(2);
					tpm_busy_delay_ms(1000);
					uc_led_all_on();
					tpm_busy_delay_ms(1000);
					r_counter ++;
					}
					else {
						w_counter = 1;
					}
			}
			else if (pushb_poll_all() == 4){
				uc_led_off(3);
				tpm_busy_delay_ms(1000);
				if (array[r_counter] == 3){
					uc_led_on(3);
					tpm_busy_delay_ms(1000);
					uc_led_all_on();
					tpm_busy_delay_ms(1000);
					r_counter ++;
					}
					else {
						w_counter = 1;
					}
			}
		}
		if (w_counter == 1){
			int counter = 0;
			for (counter = 0; counter < n+1; counter ++){
				uc_led_off(array[counter]);
				tpm_busy_delay_ms(1000);
				uc_led_all_on();
				tpm_busy_delay_ms(1000);
			}
			n = 0;
		}
		else{
			uc_led_after_win();
			n++;
		}
	}
}

