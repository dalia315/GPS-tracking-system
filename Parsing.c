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
  
