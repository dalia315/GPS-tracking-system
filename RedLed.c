void RED_LED (int distance){ //assume that the variable distance contains the total distance calculated
	while ( distance > 100) {
	  GPIO_PORTF_DATA_R |= 0x02; }
}
