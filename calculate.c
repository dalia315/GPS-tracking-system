#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
//void SystemInit() {};
//float calculate (values that will be put on the array) {   NOTE : WE WILL REMOVE INT MAIN LINE OF COURSE 

/*anther way to make this calculate function is to make the inputs of it are X1 Y1 X2 Y2 the we will inverse
the 4 lines of taking data from the array, to make them saving data in the array bec data is already in X1 X2 Y1 Y2*/
int main (){
 double X1, X2, Y1, Y2, delta_Y, delta_X ,M,N ;    // X is latitude & Y is longitude 
 float R = 6371000 ;  //in Meter 
 float S = 0, D, A[3][2] = { {30.063758128835385,31.453817158461234},{30.063547412427067,31.454816012023876},{111,211} };
	int i = 0;
	while (i < 2) {
		X1 = A[i][0];
		Y1 = A[i][1];
		X2 = A[i + 1][0];
		Y2 = A[i + 1][1];
		X1 = X1 * 3.141592653589793 / 180;
		X2 = X2 * 3.141592653589793 / 180;
		Y1 = Y1 * 3.141592653589793 / 180;
		Y2 = Y1 * 3.141592653589793 / 180;
		delta_X = X2 - X1;
		delta_Y = Y2 - Y1;
		//M is the angular distance in radians
		//N is the square of half the chord length between the points.
		N = sin(delta_X / 2) * sin(delta_X / 2) + cos(X1) * cos(X2) * sin(delta_Y / 2) * sin(delta_Y / 2) ; //Haversine formula
		M = 2 * atan2(sqrt(N),sqrt(1-N));
		D = R * M ;
		S += D ;
		i += 1 ;
		cout << S << endl ;
		 
		
	}
	// return (S)
}
