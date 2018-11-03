#include <stdio.h>
int main()
{
	double a, sum;
	while(1)
	{ 
		printf("请输入携带的行李重量 （单位：kg）:");
		if(scanf("%lf",&a) == 1)
		{
			if(a >= 0)
			{
				if(a <= 20)
				{
					printf("应付金额：0\n");
				}
				if(a > 20 && a <= 40)
				{
					printf("应付金额：%.2lf\n",(a - 20) * 2);
				}
				if(a > 40)
				{
					printf("应付金额：%.2lf\n",(a - 40) * 5 + 40);
				}
			}
			else
			{
				printf("输入失败！\n");
			}	
		}
		else
		{
			printf("输入失败！\n");
			fflush(stdin);
		}
	}	
}
