#include "port.h"
void uc_port_gpioB()//Configuring registers the Port A,B, and D for GPIO
{
	PORTB_PCR0 |= PORT_PCR_MUX(0b001);
	PORTB_PCR1 |= PORT_PCR_MUX(0b001);
	PORTB_PCR2 |= PORT_PCR_MUX(0b001);
	PORTB_PCR3 |= PORT_PCR_MUX(0b001);
}

void uc_port_gpioA()
{
	PORTA_PCR1 |= PORT_PCR_MUX(0b001);
	PORTA_PCR2 |= PORT_PCR_MUX(0b001);
	PORTA_PCR12 |= PORT_PCR_MUX(0b001);
}

void uc_port_gpioD()
{
	PORTD_PCR3 |= 0b001 << 8;
}
