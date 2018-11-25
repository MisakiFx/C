#define _CRT_SECURE_NO_WARNINGS
/*!
 * \项目 第十二次作业
 *
 * \作者 Misaki
 * \日期 十一月 2018
 * \说明 第十二次作业，C语言练习
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
判断两个数是否相等
参数：这两个数
返回值：结果
*/
int IsEqu(int num1, int num2)
{
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((num1 >> i) & 1) != ((num2 >> i) & 1))
		{
			break;
		}
	}
	if (i == 32)
	{
		return 1;
	}
	return 0;
}
/*
一组数据中找出只出现了一次的那个
参数：这组数据
返回值：只出现了一次的数
*/
int NumAppearOnce(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		int count = 0;
		for (int j = 0; j < length; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
			if (count >= 2)
			{
				break;
			}
		}
		if (count < 2)
		{
			return i;
		}
	}
	return -1;
}
/*
判断两个数哪个最小
参数：两个数
返回值较小的数
*/
int Min(int num1, int num2)
{
	return (num1 < num2) ? num1 : num2;
}
/*
求两个数的平均值
参数：这两个数
返回值：平均值
*/
int Mean(int num1, int num2)
{
	return Min(num1, num2) + abs(num1 - num2) / 2;
}
/*
将一个无符号整形的数的二进制形式前后个位数进行翻转
参数：这个无符号整形
返回值：翻转后的结果
*/
unsigned int reverse_bit(unsigned int value)
{
	for (int i = 0; i < 16; i++)
	{
		int right = (value >> i) & 1;
		int left = (value >> (31 - i)) & 1;
		if (right == 1)
		{
			value |= (1 << (31 - i));
		}
		else
		{
			value &= (~(1 << (31 - i)));
		}
		if (left == 1)
		{
			value |= (1 << i);
		}
		else
		{
			value &= (~(1 << i));
		}
	}
	return value;
}
/*
字符串翻转函数，将范围内字符数组中的字符倒序
参数：字符数组，左范围，右范围
*/
void ReverseString(char* string, int a, int b)
{
	if (b <= a)
	{
		return;
	}
	while (a < b - 1)
	{
		char t = string[a];
		string[a] = string[b - 1];
		string[b - 1] = t;
		b--;
		a++;
	}
}
int main()
{
	printf("%u\n", reverse_bit(25));
	printf("\n");
	printf("3和1的平均值为：%d\n", Mean(3, 1));
	printf("\n");
	int arr[5] = { 1, 1, 2, 3, 3 };
	printf("原数组为：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("只出现一次的数是：%d\n", arr[NumAppearOnce(arr, 5)]);
	printf("\n");
	char string1[] = "student a am i";
	ReverseString(string1, 0, 14);
	int num[5];
	int j = 0;
	for (int i = 0; i < 15; i++)
	{
	
		if (string1[i] == ' ' || string1[i] == '\0')
		{
			num[j++] = i;
		}
	}
	for (int i = -1,j = 0;j < 5;)
	{
		ReverseString(string1, i + 1, num[j++]);
		i = num[j - 1];
	}
	printf("%s\n",string1);
	system("pause");
	return 0;
}
