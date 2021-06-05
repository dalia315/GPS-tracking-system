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
void Seven_Segment_Display_Initialize (void){ 
SYSCTL_RCGCGPIO_R |= 0x03; //clock Enable for portB & portA
while((SYSCTL_PRGPIO_R &0x03)==0); //delay
GPIO_PORTB_AMSEL_R &= ~0xFC;
GPIO_PORTB_PCTL_R &= ~0xFFFFFF00;
GPIO_PORTB_AFSEL_R &= ~0xFC;
GPIO_PORTB_DIR_R |= 0xFC;
GPIO_PORTB_DEN_R |= 0xFC;
GPIO_PORTA_AMSEL_R &= ~0x0C;
GPIO_PORTA_PCTL_R &= ~0x0000FF00;
GPIO_PORTA_AFSEL_R &= ~0x0C;
GPIO_PORTA_DIR_R |= 0x0C;
GPIO_PORTA_DEN_R |= 0x0C;
}
