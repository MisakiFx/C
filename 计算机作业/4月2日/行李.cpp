#include <stdio.h>
int main()
{
	double a, sum;
	while(1)
	{ 
		printf("������Я������������ ����λ��kg��:");
		if(scanf("%lf",&a) == 1)
		{
			if(a >= 0)
			{
				if(a <= 20)
				{
					printf("Ӧ����0\n");
				}
				if(a > 20 && a <= 40)
				{
					printf("Ӧ����%.2lf\n",(a - 20) * 2);
				}
				if(a > 40)
				{
					printf("Ӧ����%.2lf\n",(a - 40) * 5 + 40);
				}
			}
			else
			{
				printf("����ʧ�ܣ�\n");
			}	
		}
		else
		{
			printf("����ʧ�ܣ�\n");
			fflush(stdin);
		}
	}	
}
