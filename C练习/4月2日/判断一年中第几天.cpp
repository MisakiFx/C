#include <stdio.h>
int main()
{
	int year, month, day, sumday = 0;
	printf("�����������գ�");
	if(scanf("%d%d%d",&year,&month,&day) != 3 || year <= 0 || month <= 0 || month > 12 || day < 0)
	{
		printf("�������\n");
		return 1;
	}
	if(((month != 8) && (month % 2 == 0) && (day > 30)) || ((month % 2 != 0) && (day > 31)) || (month == 8) && (day > 31))
	{
		printf("�������");
		return 1;
	}
	if(year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)))
	{
		if(month == 2 && day > 29)
		{
			printf("�������");
			return 1;
		}
		for(int i = 1; i < month; i++)
		{
			if(i % 2 != 0)
			{
				sumday += 31;
			}
			else
			{
				sumday += 30;
			}
		}
		if(month > 2)
		{
			sumday -= 1;
		}
		if(month > 8)
		{
			sumday += 1;
		}
		sumday += day;
	}
	else
	{
		if(month == 2 && day > 28)
		{
			printf("�������");
			return 1;
		}
		for(int i = 1; i < month; i++)
		{
			if(i % 2 != 0)
			{
				sumday += 31;
			}
			else
			{
				sumday += 30;
			}
		}
		if(month > 2)
		{
			sumday -= 2;
		}
		if(month > 8)
		{
			sumday += 1;
		}
		sumday += day;
	}
	printf("����һ���е�%d�죡\n",sumday);
}
