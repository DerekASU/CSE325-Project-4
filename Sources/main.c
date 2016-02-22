#include "global.h"
#include "tpm.h"
#include "gpio.h"
#include "led.h"
#include "systick.h"
#include "rand.h"
#include "sim.h"
#include "simon.h"
#include "port.h"
#include "libcse325.h"
#include "pushb.h"


void hw_init();

int main()
{
	hw_init();
	simonGame();

}

void hw_init()
{
	uc_sim_clk();
	uc_port_gpioD();
	uc_port_gpioB();
	uc_port_gpioA();
	uc_gpio_config_B(0);
	uc_gpio_config_B(1);
	uc_gpio_config_B(2);
	uc_gpio_config_B(3);
	pushb_init_A1(1);
	pushb_init_A2(2);
	pushb_init_A12(12);
	pushb_init_D(3);
	
	
}
