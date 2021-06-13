void RED_LED (float distance){ //assume that the variable distance contains the total distance calculated
	if ( distance >= 100) {
	  GPIO_PORTF_DATA_R |= 0x02; }
}
