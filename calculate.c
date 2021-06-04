#include <math.h>
#include <stdio.h>
int main() {
	int CO = 01`, X1 = 0, X2 = 0, Y1 = 0, Y2 = 0, Y = 0, X = 0, S = 0, D = 0;
	int A[100][2];
	int i = 0;
	int j = 0;
	while (i < 100) {
		while (j < 2) {
			A[i][j] = j;
			j = j + 1;
		}
		if (i > 0) {
			X1 = A[i-1][0] ;
			Y1 = A[i-1][1] ;
			X2 = A[i][0] ;
			Y2 = A[i][1] ;
			X = X2 - X1;
			Y = Y2 - Y1;
			D = sqrt((X * X) - (Y * Y));
			S =S+D;
		}
		i = i + 1;
	}



	printf("\n the distance is %d \n\n", S);
	printf("\n the distance is %d \n\n", X1);



}