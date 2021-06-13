#include "stdint.h"
#include "LCD.h"
#include "math.h"
#include "string.h"
#include "tm4c123gh6pm.h"
#include "stdlib.h"
#define isdigit(c) (c >= '0' && c <= '9')

int main()
	{
		PortE_Init();
		PortB_Init();
		init_lcd();
		UART5_init ();
		initialize_portF();
		char gomla[]={0};
		double y1=0;
		double x1=0;
		double lat;
		double lon;
		char LCD[10];
		char c;
		double TD = 0;
		while(1)
		{
			lcd_cmd(lcd_Clear);
			Parsing_GPS( &lat , &lon);
		
			double x2 = lat;
			double y2 = lon;
			if(x1!=0 && y1!=0){
            TD += distance_twoPoints(x1,y1,x2,y2);
          } 
			x1=x2;
			y1=y2;
			RED_LED(TD);
					while ( TD > 100 ) {
						lcd_gotoxy(1,1);
						lcd_write_string("distance:");
						lcd_gotoxy(1,2);
						sprintf(LCD,"%f",TD);
						lcd_write_string(LCD);
						delay_ms(1000);
					}
			lcd_gotoxy(1,1);
			lcd_write_string("distance:");
			lcd_gotoxy(1,2);
			sprintf(LCD,"%f",TD);
			lcd_write_string(LCD);
			delay_ms(1000);
		  }
}
