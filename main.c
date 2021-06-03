#include "stdint.h"
#include "C:/Users/DELL/OneDrive/Desktop/project/tm4c123gh6pm.h"
void SystemInt(void) {}
void initialize_portF() { // for Red Led
SYSCTL_RCGCGPIO_R |=0X20; //clock Enable for portF
while((SYSCTL_PRGPIO_R &0x02)==0);//delay
GPIO_PORTF_LOCK_R= 0x40C4F434B;
GPIO_PORTF_CR_R |= 0x02; 
GPIO_PORTF_AMSEL_R &= ~0x02; 
GPIO_PORTF_PCTL_R &= ~0x000000F0; 
GPIO_PORTF_AFSEL_R &= ~0x02; 
GPIO_PORTF_DIR_R |= 0x02; 
GPIO_PORTF_DEN_R |= 0x02; 
GPIO_PORTF_DATA_R &= ~0x02; //Intialize led to be off
}
void initialize_PortA(void) { // for UART
SYSCTL_RCGCGPIO_R |= 0x01; //clock enable for portA
while((SYSCTL_PRGPIO_R & 0x01)==0); //delay
	