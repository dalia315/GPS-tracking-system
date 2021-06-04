void UART_Init(void) { //initialize UART1 in PB0 and PB1
	SYSCTL_RCGCUART_R |= 0x0002;
	SYSCTL_RCGCGPIO_R |= 0x0002;
	while ((SYSCTL_PRGPIO_R &0x02)==0) {};//delay
	UART1_CTL_R &= ~0x0001;
	UART1_IBRD_R = 104;  // assume bus clock is 16 MHZ and baud rate is 9600 bit/sec
	UART1_FBRD_R = 11;
	UART1_LCRH_R = 0x0070;
	UART1_CTL_R = 0x0301;
	GPIO_PORTB_AFSEL_R |=0x03;
	GPIO_PORTB_DEN_R |= 0x03;
        GPIO_PORTB_PCTL_R = ( GPIO_PORTB_PCTL_R & 0xFFFFFF00) + 0x00000011;
	GPIO_PORTB_AMSEL_R &= ~0x03;
	GPIO_PORTB_DIR_R |= 0x02;
}
