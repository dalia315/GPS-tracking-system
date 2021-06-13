double atof1(const char *s)
{
double a = 0.0;
int e = 0;
int c;
while ((c = *s++) != '\0' && isdigit(c)) {
a = a*10.0 + (c - '0');
}
if (c == '.') {
while ((c = *s++) != '\0' && isdigit(c)) {
a = a*10.0 + (c - '0');
e = e-1;
}
}
if (c == 'e' || c == 'E') {
int sign = 1;
int i = 0;
c = *s++;
if (c == '+')
c = *s++;
else if (c == '-') {
c = *s++;
sign = -1;
}
while (isdigit(c)) {
i = i*10 + (c - '0');
c = *s++;
}
e += i*sign;
}
while (e > 0) {
a *= 10.0;
e--;
}
while (e < 0) {
a *= 0.1;
e++;
}
return a;
}
void Parsing_GPS(double *lat , double *lon) {
    
		char save[70] = {0};
    char deg[4];
    char min[9];
		int i=6;
    int j=0;
		int Wrong_Data=1;
    char Data ;
		while (Wrong_Data==1){
			Data = UART_InChar();
			if (Data == '$'){
				Data = UART_InChar();
				if (Data == 'G') {
					Data = UART_InChar();
					if (Data == 'N') {
							Data = UART_InChar();
							if (Data == 'G') {
									Data = UART_InChar();
									if (Data == 'G') {
											Data = UART_InChar();
											if (Data == 'A') {
												save[0]='$';
												save[1]='G';
												save[2]='N';
												save[3]='G';
												save[4]='G';
												save[5]='A';
												Data = UART_InChar();
													while (Data != '$') {
															save[i] = Data;
															i = i + 1;
															Data = UART_InChar(); 
													}
													Wrong_Data=0; 
                    }
                }
            }
        }
      }
	  }
  }
  
char* token = strtok(save,",");
			if (!strcmp(token,"$GNGGA"))
			{
				for (j = 0; j < 4; j++)
				{
					token = strtok(NULL, ",");
					if (j == 1)
					{
						strncpy(deg, token, 2);
						strncpy(min, token + 2, strlen(token) - 1);
						deg[2] = '\0';
						min[7] = '\0';
						*lat = atof1(deg) + atof1(min) / 60;


					}
					else if (j == 3)
					{
						strncpy(deg, token, 3);
						strncpy(min, token + 3, strlen(token) - 1);
						deg[3] = '\0';
						min[7] = '\0';
						*lon = atof1(deg) + atof1(min) / 60;

					}
				}
			}
		}
