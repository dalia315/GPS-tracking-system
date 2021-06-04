void Variable_Delay(double x)
{
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = (int)x*15999999;
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
	Variable_Delay(0.01);
	GPIO_PORTB_DATA_R = tenth;
	Variable_Delay(0.01);
	GPIO_PORTB_DATA_R = hunderdth;
	Variable_Delay(0.01);
}
