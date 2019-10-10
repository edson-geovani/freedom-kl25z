#ifndef UTILS_H
#define UTILS_H


extern int GPIOC_PDOR_ADDRESS;
extern int GPIOC_PDIR_ADDRESS;
extern int GPIOC_PDDR_ADDRESS;
extern int GPIOD_PDOR_ADDRESS;
extern int GPIOD_PDIR_ADDRESS;
extern int GPIOD_PDDR_ADDRESS;
extern int SIM_SCGC5_ADDRESS;


void delay(int x);
void store(int value, int addr);
int load(int addr);
#endif
