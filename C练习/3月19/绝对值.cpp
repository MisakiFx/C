#include <stdio.h>
int main()
{
	do
	{ 
		double num;
		printf("请输入一个数：");
		scanf("%lf",&num);
		if(num > 0)
		{
			printf("%.2lf\n",num);
		}
		else
		{
			printf("%.2lf\n",(-1) * num);
		}
	}while(1);
}
