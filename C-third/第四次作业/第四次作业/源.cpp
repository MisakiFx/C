#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ONES_PLACE 1
#define TENS_PLACE 10
#define HUNDREDS_PLACE 100
void printADiamond()//打印一个菱形
{
	for (int i = 0; i < 7; i++)//打印上半个菱形
	{
		for (int j = 0; j < 6 - i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < 6; i++)//打印下半个菱形
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 11 - 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
int getNum(int num, int digit)//取各位上的数
{
	return num / digit % 10;
}
void printNarNum()//打印0~999的水仙花数
{
	for (int i = 0; i <= 999; i++)
	{
		if (pow(getNum(i, ONES_PLACE), 3) + pow(getNum(i, TENS_PLACE), 3) + pow(getNum(i, HUNDREDS_PLACE), 3) == i)
		{
			printf("%d\t", i);
		}
	}
}
int calSpEx(int a)//打印一个奇葩表达式的结果a+aa+aaa+aaaa+aaaaa
{
	int sum = 0;
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		num += pow(10, i) * a;
		sum += num;
	}
	return sum;
}
int main()
{
	printf("看我的菱形：\n");
	printADiamond();//打印一个菱形
	printf("0~999的水仙花数为：");
	printNarNum();//打印0~999的水仙花数
	printf("\n");
	int a = 0;
	printf("请输入a：");
	scanf_s("%d", &a);
	printf("计算a = %d的表达式结果为%d\n", a, calSpEx(a));
	system("pause");
}