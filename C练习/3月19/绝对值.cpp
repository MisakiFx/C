#include <stdio.h>
int main()
{
	do
	{ 
		double num;
		printf("������һ������");
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
