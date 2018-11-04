#include <stdio.h>
#include <math.h>
#define PIE 3.14
int main()
{
	double r, s, c;
	scanf("%lf",&r);
	s = PIE * pow(r,2);
	c = 2 * PIE * r;
	printf("s = %.2lf,c = %.2lf",s,c);
}
