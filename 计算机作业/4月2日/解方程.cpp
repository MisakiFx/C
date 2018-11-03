#include <stdio.h>
#include <math.h>
 int main()
 {
	double a, b, c, d;
	double x1, x2;
	printf("请输入方程中a,b,c的值：");
	scanf("%lf%lf%lf",&a,&b,&c);
	d = b * b - 4 * a * c;
	if(d < 0)
	{
		printf("方程无解！\n");
		return 1;
	}
	else if(d == 0)
	{
		x1 = (-b) / (2 * a);
		printf("方程有唯一解：%.2lf\n",x1);
	}
	else
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		printf("方程解为：x1 = %.2lf\tx2 = %.2lf\n",x1,x2);
	} 
 }
