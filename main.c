#include "stdint.h"
#include <math.h>
#include "string.h"
#include "tm4c123gh6pm.h"
#include "stdlib.h"
#include "calculate.h"
#define isdigit(c) (c >= '0' && c <= '9')

int main()
	{
		PortE_Init();
		PortB_Init();
		Display_on_LCD();
		UART5_init();
		initialize_portF();
		double y1=0;
		double x1=0;
		double lat=0;
		double lon=0;
		char LCD[10];
		char c;
		double TD = 0;
		while(1)
		{
			Config_LCD(0x01);
			Parsing_GPS( &lat , &lon);
		
			double x2 = lat;
			double y2 = lon;
			if(x1!=0 && y1!=0){
            TD += distance_twoPoints(x1,y1,x2,y2);
          } 
			x1=x2;
			y1=y2;
			RED_LED(TD);
					while ( TD > 240 ) {             // stop adding new points when distance exceeds 240m
						                        //our trajectory was around 240m with (+ or - 10m accuracy)
						Position_into_LCD(1,1);
						write_string_LCD("Total distance:");
						Position_into_LCD(1,2);
						sprintf(LCD,"%f",TD);
						write_string_LCD(LCD);
						delay(1000);
					}
			Position_into_LCD(1,1);
						write_string_LCD("Total distance:");
						Position_into_LCD(1,2);
						sprintf(LCD,"%f",TD);
						write_string_LCD(LCD);
						delay(1000);
}
		}
