void delay()
{
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 15999;
    NVIC_ST_CTRL_R |= 0x5;
    while( (NVIC_ST_CTRL_R & (1<<16) ) == 0);
    NVIC_ST_CTRL_R = 0;
}
void display(int num)
{
int units , tenth , hunderdth;
	units = 0x40 | ((num%10)<<2);
  tenth = 0x80| (((num/10)%10)<<2);
	hunderdth = (( num/100))<<2;
	GPIO_PORTB_DATA_R = units ;
	Variable_Delay();
	GPIO_PORTB_DATA_R = tenth;
	Variable_Delay();
	GPIO_PORTB_DATA_R = hunderdth;
	GPIO_PORTA_DATA_R = 0x01;
	Variable_Delay();
	GPIO_PORTA_DATA_R = 0;
}
