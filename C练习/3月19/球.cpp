#include <stdio.h>
#include <math.h>
#define PIE 3.14
int main()
{
	double r;//°ë¾¶
	double v,s; 
	printf("ÇëÊäÈëÇòµÄ°ë¾¶£º");
	scanf("%lf",&r);
	s = 4 * PIE * pow(r,2);
	v = 4 / 3 * PIE * pow(r,3);
	printf("s:%.2lf\tv:%.2lf",s,v);
}
