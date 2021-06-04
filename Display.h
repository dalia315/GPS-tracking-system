void Varying_Delay(int factor)
{
    int delay;
    delay = 15999*factor;
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = delay;
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
	Varying_Delay(1);
	GPIO_PORTB_DATA_R = tenth;
	Varying_Delay(1);
	GPIO_PORTB_DATA_R = hunderdth;
	GPIO_PORTA_DATA_R = 0x01;
	Varying_Delay(1);
	GPIO_PORTA_DATA_R = 0;
}
