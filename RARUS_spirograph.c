/* 
*
*  Name   : RAMOS, JESTER DARYLHANS
*  Section: S15B
*  Submission Date: 12/3/2018
*
*  Implement the program for the hypotrochoid (also known as spirograph).
*
*/

#include <stdio.h>
#include "mp_math.h"
int
main()
{
	/*	t = theta
		x = x coordinates
		y = y coordinates
		a = big circle radius
		b = small circle radius
		h = determines location of point (inside or outside)
	*/
	double t,x,y,a,b,h,radangle,refangle,r,rtangle,rt;
	scanf ("%lf %lf %lf", &a, &b, &h);
	r = (a-b)/b;

	for (t = 0; t <= a*360 ; t++){
		rt=r*t;
		refangle=t;
		// Guarantees that refangle is within 0 - 360 degrees
		while (refangle>360)
			refangle=refangle-360;
		// Guarantees that 	rt is within 0 - 360 degrees
		while (rt>360)
			rt=rt-360;
		// Converts refangle into radians	
		radangle = deg_to_rad(refangle);
		// Converts rt into radians
		rtangle = deg_to_rad(rt);
		x = ((a-b) * cosine(radangle) + (h * cosine(rtangle)));
		y = ((a-b) * sine(radangle) - (h * sine(rtangle)));
		printf ("%.6lf \t %.6lf\n", x, y);
	}
	return 0;
}
