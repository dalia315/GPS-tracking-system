void UART5_init (void){ 
	SYSCTL_RCGCUART_R |= 0x0020;
	while((SYSCTL_PRUART_R & 0x0020)==0){};
	UART5_CTL_R &= ~0x0001;
	UART5_IBRD_R = 104; 
	UART5_FBRD_R = 11;
	UART5_LCRH_R = 0x0070;
	UART5_CTL_R = 0x0301;
}
char UART_InChar(void){
	while ((UART5_FR_R & 0x10) != 0 ) {};
		return (char) (UART5_DR_R & 0xFF);
	}
