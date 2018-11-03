#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, c, p, s;
	scanf("%lf%lf%lf",&a,&b,&c);
//	if(a + b <= c || a + c <= b || b + c <= a)
//	{
//		printf("三角形非法");
//		return 0;
//	} 
	p = (a + b + c) / 2.0;
	s = sqrt(p*(p - a) * (p - b) * (p - c));
	if(s == 0)
	{
		printf("三角形非法");
		return 0;
	 } 
	printf("%.2lf",s);
}
