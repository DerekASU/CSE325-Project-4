/*
 * File: gpio.h
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#ifndef GPIO_H_
#define GPIO_H_

void uc_gpio_config_B(int);
void uc_gpio_config_input_B(int);
void uc_gpio_config_A(int);
void uc_gpio_config_D(int);
int uc_gpio_pin_test();
int uc_gpio_pin_test_A(int);
int uc_gpio_pin_test_D(int);

#endif
