#include <stdio.h>
double fun() 
{
	double min = 11, max = -1, num, sum = 0;
	for(int i = 0; i < 10; i++)
	{
		do
		{
			if(num < 0 || num > 10)
			{
				printf("����������������룺");
			}
			printf("�������%d���ɼ���",i + 1);
			scanf("%lf",&num);
		}while(num < 0 || num > 10);
		if(num > max)
		{
			max = num;
		}
		if(num < min)
		{
			min = num;
		}
		sum += num;
	}
	sum -= max + min;
	return sum / 8;
}
int main()
{
	printf("���ճɼ�Ϊ��%lf",fun());
}
