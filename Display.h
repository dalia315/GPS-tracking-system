void Delay()
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
	units = 0x10 | (num%10);
  tenth = 0x20 | ((num/10)%10);
	hunderdth = 0x40 |( num/100);
	GPIO_PORTB_DATA_R = units ;
	Delay();
	GPIO_PORTB_DATA_R = tenth;
	Delay();
	GPIO_PORTB_DATA_R = hunderdth;
	Delay();
}
