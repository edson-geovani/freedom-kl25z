#include "utils.h"

////////////// Global variables for addresses
int GPIOC_PDOR_ADDRESS = 0x400FF080 + 0x00;		// PORTC Data Output Register address
int GPIOC_PDIR_ADDRESS = 0x400FF080 +0x10;		// PORTC Data Input Register address

int GPIOD_PDOR_ADDRESS = 0x400FF0C0 + 0x00;		// PORTD Data Output Register address
int GPIOD_PDIR_ADDRESS = 0x400FF0C0 + 0x10;		// PORTD Data Input Register address
int GPIOC_PDDR_ADDRESS = 0x400FF080 + 0x14;   
int GPIOD_PDDR_ADDRESS = 0x400FF0C0 + 0x14;
int SIM_SCGC5_ADDRESS =  0x40047000 + 0x1038;

void delay(int x){
	for (int i = 0; i < x*(21000000/4); i++);
}

////////////// write the value in the given memory addr
void store(int value, int addr)
{
	/*********** YOUR CODE HERE *************/
	int* ptr;
	ptr = (int*) addr;
	*ptr = value;
}


////////////// read a value from the given memory address
int load(int addr)
{
	/*********** YOUR CODE HERE *************/
	int value;
	int* ptr = (int*) addr;
	
	value = *ptr;
	
	return value;
	
}
