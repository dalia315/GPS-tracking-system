void delay(int delay){  //delay of LCD
	for(int i=0;i<delay;i++){
		for(int j=0;j<3180;j++){	
		}
	}
}
void Config_LCD(unsigned char configuration)    //LCD configuration       
{
	GPIO_PORTB_DATA_R=configuration;
	GPIO_PORTE_DATA_R=(0<<1)|(0<<2)|(1<<3);
	delay(1);
	GPIO_PORTE_DATA_R=(0<<1)|(0<<2)|(0<<3);
	delay(50);
	
	return;
}
void Display_on_LCD (void)                     
{
	Config_LCD(0x38); //make the LCD get *-bit data
	delay(1);
	Config_LCD(0x06); //to make cursor move sequentially from left to right
	delay(1);
	Config_LCD(0x0F); // to turn on the LCD
	delay(1);
	Config_LCD(0x01); // to clear the display
	delay(2);
	Config_LCD(0x02); // to write on the first place
	delay(2);
	
	return;
}



void write_Data_LCD(unsigned char data) // write on LCD from tiva
{
	GPIO_PORTB_DATA_R=data;
	
	GPIO_PORTE_DATA_R=(1<<1)|(0<<2)|(1<<3);
	delay(1);
	GPIO_PORTE_DATA_R=(1<<1)|(0<<2)|(0<<3);
	delay(50);
	
	return;
}

void write_string_LCD(unsigned char *array)    //write on the LCD a string     
{
	int		i=0;
	while(array[i]!='\0')
	{
		write_Data_LCD(array[i]);
		i++;
		}
	delay(100);
	return;
}

void Position_into_LCD(unsigned char x,unsigned char y)       //where to write on LCD      
{
	unsigned char firstcharadr[]={0x80,0xC0};
	Config_LCD(firstcharadr[y-1] + x - 1);
	delay(50);
}
