#define _CRT_SECURE_NO_WARNINGS
#define ARRINITSIZE 10
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
/*
打印乘法口诀表
*/
void printMudList()
{
	int line;//行数
	printf("请输入打印的行数：");
	scanf("%d", &line);
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line; j++)
		{
			if (j <= i)
			{
				printf("%d * %d = %d\t", j + 1, i + 1, (j + 1) * (i + 1));
			}
		}
		printf("\n");
	}
}
/*
两个数的交换
参数：
num1，num2：交换的两个数
*/
void exChange(int* num1, int* num2)
{
	int numt = *num1;
	*num1 = *num2;
	*num2 = numt;
}
/*
判断是否是闰年
参数：年份
*/
int isLeap(int year)
{
	if (year % 400 == 0)
	{
		return 1;
	}
	if ((year % 4 == 0) && (year % 100 != 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
是否是闰年
*/
void isLeapYear()
{
	int year = 0;
	printf("请输入年份：");
	scanf("%d", &year);
	if (isLeap(year) == 1)
	{
		printf("是闰年！\n");
	}
	else
	{
		printf("不是闰年！\n");
	}
}
/*
初始化数组
参数：长度
返回值：数组的指针
*/
ElemType* arrInit(int len)
{
	ElemType* arr = (ElemType*)malloc(sizeof(ElemType) *10);
	if (!arr)
	{
		return NULL;
	}
	printf("请输入10个数初始化数组：");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	return arr;
}
/*
打印数组
参数：数组，长度
*/
void pritfArr(ElemType* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
/*
清空数组
参数：数组， 长度
*/
void cleanArr(ElemType* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}
/*
逆置数组
参数：数组，长度
*/
void reverseArr(ElemType* arr, int len)
{
	int mid = len >> 1;
	for (int i = 0; i < mid; i++)
	{
		exChange(&arr[i], &arr[len - i - 1]);
	}
}
/*
判断是不是质数
*/
void isPrime(int num)
{
	int i = 0;
	if (num <= 1)
	{
		printf("无法判断！\n");
		return;
	}
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			break;
		}
	}
	if (i == num)
	{
		printf("是素数！\n");
	}
	else
	{
		printf("不是素数！\n");
	}
}
int main()
{
	printMudList();//打印乘法口诀表
	printf("\n\n");
	/*********************************/
	int num1 = 2, num2 = 3;
	printf("num1 = %d, num2 = %d\n", num1, num2);
	exChange(&num1, &num2);//将两个数交换
	printf("交换后：num1 = %d, num2 = %d\n", num1, num2);
	printf("\n\n");
	/**************************************/
	isLeapYear();//判断是否是闰年
	printf("\n\n");
	/***************************************/
	ElemType* arr = arrInit(ARRINITSIZE);//初始化数组，初空间为10
	pritfArr(arr, ARRINITSIZE);
	reverseArr(arr, ARRINITSIZE);//逆置数组
	printf("逆置后：\n");
	pritfArr(arr, ARRINITSIZE);
	cleanArr(arr, ARRINITSIZE);//清空
	printf("清空后：\n");
	pritfArr(arr, ARRINITSIZE);
	printf("\n\n");
	/*****************************************/
	int num = 0;
	printf("请输入一个来判断是不是素数：");
	scanf("%d", &num);
	isPrime(num);
	printf("\n");
	system("pause");
	return 0;
}