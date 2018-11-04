#include <stdio.h>
#include <math.h>
int main()
{
	double x,y;
	do
	{
		printf("请输入x的值：");
		scanf("%lf",&x);
		if(x < 0 || x >= 5)
		{
			printf("不合法！\n");
		}
		if(x >= 0 && x < 1)
		{
			printf("y = 0\n");
		}
		if(x >= 1 && x < 2)
		{
			printf("y = %.2lf\n",3 * x + 5);
		}
		if(x >= 2 && x < 3)
		{
			printf("y = %.2lf\n",2 * sin(x) - 1);
		}
		if(x >= 3 && x < 4)
		{
			printf("y = %.2lf\n",log(1 + pow(x,2)));	
		}
		if(x >= 4 && x < 5)
		{
			printf("y = %.2lf\n",log10(pow(x,2) - 2 * x));
		}	
	}while(1);
}
