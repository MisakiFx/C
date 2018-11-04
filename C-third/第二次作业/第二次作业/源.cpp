#include <stdio.h>
#include <stdlib.h>
void change1(int* a, int* b)//给定两个整形的值将他们交换
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void change2(int* a, int* b)//给定两个整形的值将他们交换（不创建新的变量）
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int max(int* array)//求十个数中的最大值
{
	int max = array[0];
	for (int i = 1; i < 10; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}
void printArrHTL(int a, int b, int c)//三个数从大到小输出
{
	int max = 0;
	int mid = 0;
	int low = 0;
	if (a > b)
	{
		max = a;
		mid = b;
	}
	else
	{
		max = b;
		mid = a;
	}
	if (max > c)
	{
		if (c > mid)
		{
			low = mid;
			mid = c;
		}
		else
		{
			low = c;
		}
	}
	else
	{
		low = mid;
		mid = max;
		max = c;
	}
	printf("%d > %d > %d\n", max, mid, low);
}
int gcd(int a, int b)//求最大公约数
{
	int y = 0;
	if (b > a)
	{
		int c = a;
		a = b;
		b = c;
	}
	while (b != 0)
	{
		y = a % b;
		a = b;
		b = y;
	}
	return a;
}
int main()
{
	int a = 10;
	int b = 20;
	//change1(&a, &b);//交换1
	change2(&a, &b);//交换2
	printf("a = %d, b = %d\n", a, b);
	int array[10] = { 10,5,15,100,500,600,3,7,7,8 };
	printf("原数组为：");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	printf("最大值为：%d\n", max(array));//输出10个数中的最大值
	int d = 10; int e = 20; int f = 30;
	printf("三个数为：%d, %d, %d,排序后：", d, e, f);
	printArrHTL(d, e, f);//三个数从大到小输出
	printf("\n");
	int g = 24; int h = 8;
	printf("原来的数为：%d, %d，最大公约数为%d\n", g, h, gcd(g, h));
	system("pause");
}