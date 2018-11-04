#include <stdio.h>
#include <stdlib.h>
void PrintPrimeNum()//打印200以内素数
{
	bool key = true;
	for (int i = 2; i < 200; i++)
	{
		key = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				key = false;
				break;
			}
		}
		if (key == true)
		{
			printf("%d\t", i);
		}
	}
}
void PrintMul()//打印乘法口诀
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i >= j)
			{
				printf("%d * %d = %d\t", j+1, i+1, (i + 1) * (j + 1));
			}
		}
		printf("\n");
	}
}
void PrintLeapYear()//打印闰年
{
	for (int i = 1000; i <= 2000; i++)
	{
		if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
		{
			printf("%d\t", i);
		}
	}
}
int main()
{
	printf("打印100-200内素数：\n");
	PrintPrimeNum();//打印200以内素数
	printf("\n");
	printf("\n");
	printf("打印乘法口诀表：\n");
	PrintMul();//打印乘法口诀表
	printf("\n");
	printf("打印1000-2000内闰年：\n");
	PrintLeapYear();//打印闰年
	printf("\n");
	system("pause");
	return 0;
}