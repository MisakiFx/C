#include <stdio.h>
int main()
{
	double a;
	while(1)
	{
		if(scanf("%lf",&a) == 1)
		{
			if(a >= 0)
			{
				printf("绝对值为%.2lf\n",a);
			}
			else
			{
				printf("绝对值为%.2lf\n",-a);
			}
		}
		else
		{
			printf("输入不正确！\n");
			return 1;
		}
	}
}
