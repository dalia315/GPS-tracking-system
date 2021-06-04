#include <math.h>
#include <stdio.h>
void SystemInit() {};
int main() {
	double X1,X2,Y1,Y2,Y,X;
	float S = 0, D , A[3][2] = { {1,2},{3,4},{5,6} }; 
	//here we input array manually but in the next phase the input will come from GPS module and array size will change ofcourse 
	int i = 0 ;
	while (i < 2) {
		
			X1 = A[i][0] ;
			Y1 = A[i][1] ;
			X2 = A[i+1][0] ;
			Y2 = A[i+1][1] ;
			X = X2 - X1;
			Y = Y2 - Y1;
			D = sqrt((X * X) + (Y * Y));
			S += D;
		i += 1 ; 
		}
	}
