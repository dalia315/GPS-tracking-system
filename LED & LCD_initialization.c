#include "stdint.h"
#include "C:/Users/DELL/OneDrive/Desktop/project/tm4c123gh6pm.h"
void SystemInt() {}

void initialize_portF(void) { // for Red Led
SYSCTL_RCGCGPIO_R |=0X20; //clock Enable for portF
while((SYSCTL_PRGPIO_R &0x20)==0);//delay
GPIO_PORTF_LOCK_R|= 0x40C4F434B;
GPIO_PORTF_CR_R |= 0x02; 
GPIO_PORTF_AMSEL_R &= ~0x02; 
GPIO_PORTF_PCTL_R &= ~0x000000F0; 
GPIO_PORTF_AFSEL_R &= ~0x02; 
GPIO_PORTF_DIR_R |= 0x02; 
GPIO_PORTF_DEN_R |= 0x02; 
GPIO_PORTF_DATA_R &= ~0x02; //Intialize led to be off
}
void PortB_Init ()
{ 
	SYSCTL_RCGCGPIO_R |= 0x00000002;
  while ((SYSCTL_PRGPIO_R&0x02) == 0){};
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AMSEL_R = 0x00;
	GPIO_PORTB_AFSEL_R = 0x00; 
	GPIO_PORTB_PCTL_R = 0x00000000;
  GPIO_PORTB_PUR_R = 0x00;
  
}
void PortE_Init ()
{
	SYSCTL_RCGCGPIO_R |= 0x00000010;
  while ((SYSCTL_PRGPIO_R&0x10) == 0){};
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x3E;
	GPIO_PORTE_DIR_R = 0x0E;
	GPIO_PORTE_DEN_R = 0x3E;
	GPIO_PORTE_AMSEL_R = 0x00;
	GPIO_PORTE_AFSEL_R = 0x30;
	GPIO_PORTE_PCTL_R = 0x00110000;
  GPIO_PORTE_PUR_R = 0x00;
  
}
