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
				printf("����ֵΪ%.2lf\n",a);
			}
			else
			{
				printf("����ֵΪ%.2lf\n",-a);
			}
		}
		else
		{
			printf("���벻��ȷ��\n");
			return 1;
		}
	}
}
