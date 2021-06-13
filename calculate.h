
double distance_twoPoints(double X1, double Y1, double X2, double Y2) // X is latitude & Y is longitude  
	{
		double Pi = 3.14159265;
		double TD = 0;
		double X1_RAD = X1 * (Pi / 180);
		double Y1_RAD = Y1 * (Pi / 180);

		double X2_RAD = X2 * (Pi / 180);
		double Y2_RAD = Y2 * (Pi / 180);

		double D = sin(X1_RAD) * sin(X2_RAD) + cos(X1_RAD) * cos(X2_RAD) * cos(Y1_RAD - Y2_RAD);
		D = acos(D);
		D = 6371000 * D;
		return D;
	}

	double Total_distance(double X1, double Y1, double X2, double Y2) {
		double TD = 0;
		if (X1 != 0 && Y1 != 0) {  // X1 and Y1 will be initialized = 0 as a reference to start points
			                       // X2 And Y2 contains the coordinates from the gps module
			TD = TD + distance_twoPoints(X1, Y1, X2, Y2);
		}
		X1 = X2;
		Y1 = Y2;
		return TD;
	}
