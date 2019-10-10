#include "GPIO_CONFIG.h"
#include "../library/utils.h"

////////////// Global variables for addresses

////////////// write the value in the given memory addr
void MY_MTS_GPIO_init(void)
{
	int val;
	int result;

	val = load(SIM_SCGC5_ADDRESS);

	val |= (1 << 11);

	store(val, SIM_SCGC5_ADDRESS);
	SIM->SCGC5 |= (1 << 12);

	PORTC_SELECT_GPIO_FUNCTION();
	PORTD_SELECT_GPIO_FUNCTION();

	val = load (GPIOC_PDDR_ADDRESS);
	
	val |= ((3<<16) | (15<<10) | (31));
	store(val, GPIOC_PDDR_ADDRESS);
	
	PTD->PDDR &= ~(65<<2); 
}

////////////// Use to enalbe pins to GPIO function
void PORTD_SELECT_GPIO_FUNCTION(void){
	int d;
	for( d=2; d <= 7; d++)   PORTD->PCR[d] |= PORT_PCR_MUX(1);  // Pin    PTD[7:2]    are GPIO
}



void PORTC_SELECT_GPIO_FUNCTION(void){
	int c;
  for( c=0; c <= 4; c++)   PORTC->PCR[c] |= PORT_PCR_MUX(1);	// Pins   PTC[4:0]    are GPIO
  for( c=10; c <= 13; c++) PORTC->PCR[c] |= PORT_PCR_MUX(1);	// Pins   PTC[13:10]  are GPIO
  for( c=16; c <= 17; c++) PORTC->PCR[c] |= PORT_PCR_MUX(1);  // Pins   PTC[17:16]  are GPIO
}
/***********************end***********************/
