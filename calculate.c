
#include <iostream>
using namespace std;
// void SystemInit() {};
//float calculate (values that will be put on the array) {   NOTE : WE WILL REMOVE INT MAIN LINE OF COURSE 

/*anther way to make this calculate function is to make the inputs of it are X1 Y1 X2 Y2 the we will inverse
the 4 lines of taking data from the array, to make them saving data in the array bec data is already in X1 X2 Y1 Y2*/
int main() {
	double   X1_RAD, Y1_RAD, X2_RAD, Y2_RAD, X1, Y1, X2, Y2, D, TD = 0, Pi = 3.14;    // X is latitude & Y is longitude  
	float A[3][2] = { {30.063758128835385,31.453817158461234},{30.063547412427067,31.454816012023876},{111,211} };
	int i = 0;
	while (i < 2) {
		X1 = A[i][0];
		Y1 = A[i][1];
		X2 = A[i + 1][0];
		Y2 = A[i + 1][1];

		X1_RAD = X1 * (Pi / 180);
		Y1_RAD = Y1 * (Pi / 180);

		X2_RAD = X2 * (Pi / 180);
		Y2_RAD = Y2 * (Pi / 180);

		D = sin(X1_RAD) * sin(X2_RAD) + cos(X1_RAD) * cos(X2_RAD) * cos(Y1_RAD - Y2_RAD);
		D = acos(D);
		D = 6371000 * D;
		TD += D;
		i += 1;
		cout << TD << endl;


	}
	// return (S)
}
