#include <stdio.h>
#include <stdlib.h>
#define LEN 10
void exchange(int* a, int* b)//将两个数进行交换
{
	int c = *a;
	*a = *b;
	*b = c;
}
void exchangeArr(int* arr1, int* arr2, int len)//将两个数组的元素进行交换
{
	//老实讲没说清交换什么类型的数组我是想用CPP写模版函数的，
	//但是鉴于这是C语言作业，就暂时以整形作为例子
	for (int i = 0; i < len; i++)
	{
		exchange(arr1 + i, arr2 + i);
	}
}
void printArr(int* arr, int len)//打印数组
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
}
double compute()//计算一个辣鸡表达式的值
{
	double res = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			res -= 1.0 / i;
		}
		else
		{
			res += 1.0 / i;
		}
	}
	return res;
}
int numOfNine()//计算1~100出现多少次数字9
{
	int num = 0;
	for (int i = 10; i <= 99; i++)
	{
		int ones = i % 10;
		if (ones == 9)
		{
			num++;
		}
		int tens = i / 10;
		if (tens == 9)
		{
			num++;
		}
	}
	return num + 1;
}
int main()
{
	int arr1[LEN] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[LEN] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	printf("数组1：");
	printArr(arr1, LEN);
	printf("\n");
	printf("数组2：");
	printArr(arr2, LEN);
	printf("\n");
	exchangeArr(arr1, arr2, LEN);
	printf("交换后：\n");
	printf("数组1：");
	printArr(arr1, LEN);
	printf("\n");
	printf("数组2：");
	printArr(arr2, LEN);
	printf("\n");
	printf("辣鸡表达式的计算结果为：%lf\n", compute());
	printf("1~100的数字里9出现的次数为：%d\n", numOfNine());
	system("pause");
}