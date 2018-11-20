#include <stdio.h>
#include <stdlib.h>
/*!
 * \项目名 第十次作业
 * \日期 2018/11/20 1:01
 *
 * \作者 Misaki
 * 联系方式  1761607418@qq.com
 *
 * 文件描述: 操作符的相关练习
 *
*/
/*
计算一个数的二进制中有几个1
参数：这个数
返回值：个数
*/
int BitOneCount(unsigned int num)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (num >> i & 1 != 0)
		{
			count++;
		}
	}
	return count;
}
/*
计算两个整数中二进制有多少个位不同
参数：这两个数
返回值：不相同的位数
*/
int DifferentBit(int num1, int num2)
{
	int num = num1 ^ num2;
	return BitOneCount(num);
}
/*
依次打印一个整数的每一位
参数：这个数
*/
void PrintNum(int num)
{
	if (num > 9)
	{
		PrintNum(num / 10);
	}
	printf("%d", num % 10);
}
/*
分别输出一个数的二进制表示中奇数位和偶数位
参数：这个数
*/
void PrintBitNum(int num)
{
	int arr[32];
	for (int i = 0; i < 32; i++)
	{
		arr[i] = (num >> (31 - i)) & 1;
	}
	for (int i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d", arr[i]);
		}
	}
	printf("\n");
	for (int i = 0; i < 32; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d", arr[i]);
		}
	}
	printf("\n");
}
int main()
{
	printf("3的二进制表示汇总1的个数：%d\n\n", BitOneCount(3));
	printf("分别打印-1的二进制表示中的偶数位与奇数位：\n");
	PrintBitNum(-1);
	printf("\n");
	printf("顺序打印123456中的每一位：\n");
	PrintNum(123456);
	printf("\n\n");
	printf("1999与2999的二进制表示中位数不同的个数：%d\n", DifferentBit(1999, 2299));
	system("pause");
	return 0;
}