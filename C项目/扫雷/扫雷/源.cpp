#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 10
#define MAX_COL 10
#define MINE_NUM 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*!
 * \项目名 扫雷
 * \日期 2018/11/19 23:19
 *
 * \作者 Misaki
 * 联系方式  1761607418@qq.com
 *
 * 文件描述: 10 * 10扫雷游戏初步实现
 *
*/
/*
菜单
返回：用户输入
*/
int Menu()
{
	system("cls");
	printf("*********************************\n");
	printf("1、开始游戏！\n");
	printf("2、游戏说明！\n");
	printf("0、退出游戏！\n");
	printf("*********************************\n");
	printf("请选择：");
	int choose = 0;
	rewind(stdin);
	if(scanf("%d", &choose) != 1) return 3;
	return choose;
}
/*
初始化地图
参数：两张地图
*/
void InitMap (char show_map[MAX_ROW + 2][MAX_COL + 2], char mine_map[MAX_ROW + 2][MAX_COL + 2])
{
	//现将两个地图全部初始化
	for (int i = 0; i < MAX_ROW + 2; i++)
	{
		for (int j = 0; j < MAX_COL + 2; j++)
		{
			show_map[i][j] = '*';
			mine_map[i][j] = '0';
		}
	}
	//设置随机雷阵
	for (int i = 0; i < MINE_NUM; )
	{
		int it = rand() % 10 + 1;
		int jt = rand() % 10 + 1;
		if (mine_map[it][jt] != '1')
		{
			mine_map[it][jt] = '1';
			i++;
		}
	}
}
/*
打印地图
参数：地图
*/
void PrintMap(char map[MAX_ROW + 2][MAX_COL + 2])
{
	system("cls");
	printf("   ");
	for (int i = 1; i < MAX_ROW + 1; i++)
	{
		printf("%d  ", i);
	}
	printf("\n");
	printf("   ");
	for (int i = 1; i < MAX_ROW + 1; i++)
	{
		printf("___", i);
	}
	printf("\n");
	for (int i = 1; i < MAX_ROW + 1; i++)
	{
		printf("%02d|", i);
		for (int j = 1; j < MAX_COL + 1; j++)
		{
			printf("%c  ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/*
判断周围有几个雷
参数：地雷地图，用户选择的坐标
返回：雷的个数
*/
int MineNum(char mine_map[MAX_ROW + 2][MAX_COL + 2], int row, int col)
{
	int count = (mine_map[row][col - 1] - '0') + (mine_map[row - 1][col - 1] - '0') + (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0') + (mine_map[row][col + 1] - '0') + (mine_map[row + 1][col + 1] - '0')
		+ (mine_map[row + 1][col] - '0') + (mine_map[row + 1][col - 1] - '0');
	return count;
}
/*
更新游戏显示地图
参数：两张地图和用户选择的坐标
*/
void UpdateMap(char show_map[MAX_ROW + 2][MAX_COL + 2], char mine_map[MAX_ROW + 2][MAX_COL + 2], int row, int col)
{
	int count = MineNum(mine_map, row, col);
	show_map[row][col] = '0' + count;
	if (count == 0)
	{
		if (row >= 1 && col - 1 >= 1)
		{
			int count1 = MineNum(mine_map, row, col - 1);
			show_map[row][col - 1] = '0' + count1;
		}
		if (row - 1 >= 1 && col - 1 >= 1)
		{
			int count2 = MineNum(mine_map, row - 1, col - 1);
			show_map[row - 1][col - 1] = '0' + count2;
		}
		if (row - 1 >= 1 && col >= 1)
		{
			int count3 = MineNum(mine_map, row - 1, col);
			show_map[row - 1][col] = '0' + count3;
		}
		if (row - 1 >= 1 && col + 1 <= 10)
		{
			int count4 = MineNum(mine_map, row - 1, col + 1);
			show_map[row - 1][col + 1] = '0' + count4;
		}
		if (row >= 1 && col + 1 <= 10)
		{
			int count5 = MineNum(mine_map, row, col + 1);
			show_map[row][col + 1] = '0' + count5;
		}
		if (row + 1 <= 10 && col + 1 <= 10)
		{
			int count6 = MineNum(mine_map, row + 1, col + 1);
			show_map[row + 1][col + 1] = '0' + count6;
		}
		if (row + 1 <= 10 && col >= 1)
		{
			int count7 = MineNum(mine_map, row + 1, col);
			show_map[row + 1][col] = '0' + count7;
		}
		if (row + 1 <= 10 && col - 1 >= 1)
		{
			int count8 = MineNum(mine_map, row + 1, col - 1);
			show_map[row + 1][col - 1] = '0' + count8;
		}
	}
}
int LostMineNum(char show_map[MAX_ROW + 2][MAX_COL + 2])
{
	int count = 0;
	for (int i = 1; i < MAX_ROW + 1; i++)
	{
		for (int j = 1; j < MAX_COL + 1; j++)
		{
			if (show_map[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
/*游戏主体*/
void Game()
{
	//将地图加个边框，目的为了后续方便设计计算雷数算法
	char show_map[MAX_ROW + 2][MAX_COL + 2];//显示地图
	char mine_map[MAX_ROW + 2][MAX_COL + 2];//地雷地图
	//初始化地图
	InitMap(show_map, mine_map);
	PrintMap(mine_map);
	while (1)
	{
		//打印地图
		PrintMap(show_map);
		printf("当前未扫区域 / 总雷数：%d / %d\n", LostMineNum(show_map), MINE_NUM);
		//用户输入（判断是否合法）
		int row = 0, col = 0;
		while (1)
		{
			printf("请输入坐标（x y）：");
			rewind(stdin);
			int result = scanf("%d%d", &row, &col);
			if (row < 1 || row > 10 || col < 1 || col > 10 || result != 2)
			{
				printf("看好再输！\n");
			}
			else
			{
				break;
			}
		}
		//判断该处是否有雷，有雷直接GG跳出循环
		if (mine_map[row][col] == '1')
		{
			PrintMap(mine_map);
			printf("pa!你死了\n");
			break;
		}
		//没扫完继续，计算该处附近有及个雷，填入显示地图中如果没有雷，继续计算周边一圈全部显示到地图中
		UpdateMap(show_map, mine_map, row, col);
		//没雷判断是否是最后一个，全部扫完游戏结束跳出循环
		if (LostMineNum(show_map) <= 10)
		{
			PrintMap(mine_map);
			printf("你赢啦，牛逼！\n");
			break;
		}
	}
	//游戏结束打印地雷地图
	system("pause");
}
void GameExplain()
{
	system("cls");
	printf("扫雷都不玩你有没有童年！\n");
	system("pause");
}
int main()
{
	srand(time(NULL));
	int choose = 0;
	while (choose = Menu())
	{
		if (choose == 1)
		{
			//开始游戏
			Game();
			continue;
		}
		if (choose == 2)
		{
			//游戏说明
			GameExplain();
			continue;
		}
		else
		{
			printf("别瞎b输！\n");
			system("pause");
			continue;
		}
	}
	system("pause");
	return 0;
}