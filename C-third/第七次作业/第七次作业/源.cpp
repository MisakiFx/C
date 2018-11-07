/*!
 * \文件名 源.cpp
 * \日期 2018/11/07 20:49
 *
 * \作者 Misaki
 * 联系方式  1761607418@qq.com
 *
 * \brief 
 *
 * 文件描述: 第七次作业（只能用递归）
 *
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
递归版斐波那契数列
参数：数列中第几个数
返回值：第几个数的值
*/
int fibRecursion(int num)
{
	if (num == 1 || num == 2)//第一个或第二个数为1，直接返回
	{
		return 1;
	}
	return fibRecursion(num - 1) + fibRecursion(num - 2);
}
/*
迭代版斐波那契数列
参数：数列中第几个数
返回值：第几个数的值
*/
int fibIteration(int num)
{
	int fib = 0;
	int low = 1;
	int high = 1;
	if (num == 1 || num == 2)
	{
		return 1;
	}
	for (int i = 3; i <= num; i++)
	{
		fib = low + high;
		low = high;
		high = fib;
	}
	return num;
}
/*
num的power次方
参数：被乘方的数，方数
返回值：结果
*/
int powNum(int num, int power)
{
	if (power <= 1)
	{
		return num;
	}
	return num * powNum(num, --power);
}
/*
输出一个数字返回组成它的各位上数字之和
参数：这个数
返回值：和
*/
int digitSum(int num)
{
	int sum = 0;
	if (num < 10)
	{
		return sum += num;
	}
	return sum += num % 10 + digitSum(num / 10);
}
///*
//将字符串中的字符反向排列
//参数：字符串
//*/
//char* reverse_string(char* string)
//{
//	int len = 0;
//	while (string[len] != '\0')
//	{
//		len++;
//	}
//	static char* p = (char*)malloc(sizeof(char) * (len + 1));
//	if (len <= 0)
//	{
//		return string;
//	}
//	int i = 0;
//	p[i] = string[len - 1];
//}
/*
递归实现读取字符串长度
参数：字符串
返回值：长度
*/
int strlenRecursion(const char* string)
{
	if (*string == '\0')
	{
		return 0;
	}
	return 1 + strlenRecursion(string + 1);
}
/*
迭代实现读取字符串长度
参数：字符串
返回值：长度
*/
int strlenIteration(const char* string)
{
	int len = 0;
	while (string[len] != '\0')
	{
		len++;
	}
	return len;
}
/*
递归实现一个数的阶乘
参数：这个数
返回值：结果
*/
int factorialRecursion(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return num * factorialRecursion(num - 1);
}
/*
迭代实现一个数的阶乘
参数：这个数
返回值：结果
*/
int factorialInteration(int num)
{
	int mix = 1;
	while (num != 1)
	{
		mix *= num--;
	}
	return mix;
}
/*
递归方式打印一个数的每一位
参数：这个数
返回值：结果
*/
void printDigitNum(int num)
{
	if (num > 9)
	{
		printDigitNum(num / 10);
	}
	printf("%d ", num % 10);
}
/*
递归实现将字符串逆置输出
参数：字符串
*/
void reverse_string(const char* string)
{
	if (*string == '\0')
	{
		return;
	}
	reverse_string(string + 1);
	putchar(*string);
}
int main()
{
	//printf("输出Fib数列第5个数：%d（递归版）\n", fibRecursion(5));//递归版实现
	//printf("输出Fib数列第5个数：%d（迭代版）\n", fibIteration(5));//迭代版实现
	//printf("\n");
	///***********************************************************************/
	//printf("6的立方是：%d\n", powNum(6, 3));
	//printf("\n");
	///***********************************************************************/
	//printf("123各位数字的和为：%d\n", digitSum(123));
	//printf("\n");
	/***********************************************************************/
	printf("\"123456\"的长度是%d（递归版）\n", strlenRecursion("123456"));
	printf("\"123456\"的长度是%d（迭代版）\n", strlenIteration("123456"));
	printf("\n");
	/**********************************************************************/
	printf("3! = %d（递归版）\n", factorialRecursion(3));
	printf("3! = %d（迭代版）\n", factorialInteration(3));
	printf("\n");
	/*********************************************************************/
	printf("\"123456\"的逆置是：");
	reverse_string("123456");
	printf("\n\n");
	/************************************************************************/
	printDigitNum(123);
	printf("\n\n");
	system("pause");
	return 0;
}