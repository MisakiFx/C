/*!
* \文件名 源.cpp
* \日期 2018/11/02 14:12
*
* \作者 Misaki
* 联系方式 1761607418@qq.com
*
* \brief
*
* 文件描述: 第五次作业
*
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int menu()//开始菜单
{
	int choice;//选择
	printf("1、开始游戏\n");
	printf("0、退出\n");
	printf("请选择：");
	scanf_s("%d", &choice);
	return choice;
}
void game()
{
	srand(time(0));
	int riddle = 0;//用户猜的数字
	int num = rand() % 101;//猜的数的范围是1-101
	while (1)
	{
		printf("请输出你猜的数字：");
		scanf_s("%d", &riddle);
		if (riddle < num)
		{
			printf("低了！\n");
		}
		else if (riddle > num)
		{
			printf("高了！\n");
		}
		else
		{
			break;
		}
	}
	printf("恭喜你猜中了！\n");
}
void gameNumRiddle()
{
	while (1)
	{
		if (menu() == 1)
		{
			game();
		}
		else
			return;
	}
}
int binFind(int* arr, int low, int high, int num)//二分查找
{
	int mid = 0;
	int index = -1;
	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (num > arr[mid])
		{
			low = low + 1;
		}
		else if (arr[mid] > num)
		{
			high = high - 1;
		}
		else
		{
			index = mid;
			break;
		}
	}
	return index;
}
void bintest()//二分查找测试
{
	int arr[5] = { 0,2,5,7,10 };
	int num = 0;
	printf("原数组为：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("请输入要查找的数：");
	scanf("%d", &num);
	int index = binFind(arr, 0, 5, num);
	if (index == -1)
	{
		printf("未找到！\n");
	}
	else
	{
		printf("下表为%d\n", index);
	}
}
void atmPassword()//ATM登陆系统
{
	char password[7] = "123456";
	int turn = 0;
	char enter[7];
	while (turn < 3)
	{
		printf("请输入密码：");
		scanf("%s", enter);
		if (strcmp(enter, password) == 0)
		{
			break;
		}
		turn++;
		printf("密码输入错误，还有%d次机会！\n", 3 - turn);
	}
	if (turn < 3)
	{
		printf("密码正确！\n");
	}
	else
	{
		printf("登陆失败！\n");
	}
}
void readChar()//大写转小写，小写转大写数字不输出
{
	char enter;
	printf("请输入字符：");
	while (scanf("%c", &enter) != EOF)
	{
		if (enter >= 'a' && enter <= 'z')
		{
			printf("%c\n", enter - 32);
		}
		else if (enter >= 'A' && enter <= 'Z')
		{
			printf("%c\n", enter + 32);
		}
		printf("请输入字符："); 
		enter = getchar();
	}
}
int main()
{
	atmPassword();
	bintest();
	gameNumRiddle();//猜数字游戏
	readChar();
	system("pause");
}
