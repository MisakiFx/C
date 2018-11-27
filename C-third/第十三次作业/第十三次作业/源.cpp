/*!
 * \项目 第十三次作业
 *
 * \作者 Misaki
 * \日期 十一月 2018
 * \说明 第十三次作业
 * 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
将数组中的奇数位于前半部分，偶数位于后半部分
参数：数组，数组的长度
*/
void Settle(int* arr, int len)
{
	int k = 0;
	for (int i = 0; i < len; )
	{
		if (arr[i] % 2 == 1 && i != k)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			k++;
			continue;
		}
		i++;
	}
}
int Search(int(*arr)[3], int row, int col, int num)
{
	if (num > arr[row - 1][col - 1])
	{
		return false;
	}
	int i = 0;
	int j = col - 1;
	while (arr[i][j] != num && i < row && j >= 0)
	{
		if (num > arr[i][j])
		{
			i++;
		}
		if (num < arr[i][j])
		{
			j--;
		}
	}
	if (j < 0 || i == row)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("原数组为：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	Settle(arr, 10);
	printf("整理后为：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
	int arr2[][3] = {
		{1,2,3},
		{2,3,4},
		{3,4,5},
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", arr2[i][j]);
		}
		printf("\n");
	}
	printf("在其中查找3的结果为：%s\n", Search(arr2, 3, 3, 3) ? "找的到" : "找不到");
	system("pause");
	return 0;
}
