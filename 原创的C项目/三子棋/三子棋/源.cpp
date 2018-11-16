/*!
 * \文件名 源.cpp
 * \日期 2018/11/10 13:35
 *
 * \作者 Misaki
 * 联系方式  1761607418@qq.com
 *
 * 文件描述: 三子棋
 *
*/
#define _CRT_SECURE_NO_WARNINGS
#define ROW 5
#define COL 5
#define WIN 5
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
char g_board[ROW][COL];
/*
将棋盘进行初始化
*/
void initBoard()
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			g_board[row][col] = ' ';//空位置用' '表示
		}
	}
}
/*
打印菜单
*/
int menu()
{
	system("cls");
	int choose = 0;
	printf("1、开始游戏\n");
	printf("2、游戏说明\n");
	printf("3、退出\n");
	printf("请选择：");
	scanf("%d", &choose);
	return choose;
}
/*
打印棋盘
*/
void printBoard()
{
	system("cls");
	for (int col = 0; col < COL; col++)
	{
		printf(" _____");
	}
	printf(" \n");
	for (int row = 0; row < ROW; row++)
	{
		printf("|");
		for (int col = 0; col < COL; col++)
		{
			printf("%6c", '|');
		}
		printf("\n|");
		for (int col = 0; col < COL; col++)
		{
			printf("  %c  |", g_board[row][col]);
		}
		printf("\n|");
		for (int col = 0; col < COL; col++)
		{
			printf("_____|");
		}
		printf("\n");
	}
	printf("\n");
}
/*
玩家回合
*/
void playerMove(int* row, int* col)
{
	printf("玩家回合：\n");
	int rowt = 0, colt = 0, result;
	while (1)
	{
		printf("请输入坐标：(格式：y x)");
		if (result = scanf("%d%d", &rowt, &colt) != 2)
		{
			printf("你输的是坐标么？重来\n");
			rewind(stdin);
			continue;
		}
		if (rowt < 0 || rowt >= ROW || colt < 0 || colt >= COL)
		{
			printf("输入坐标不合法，请重新输入！\n");
			rewind(stdin);
			continue;
		}
		if (g_board[rowt][colt] != ' ')
		{
			printf("这个位置已经有子了！\n");
			rewind(stdin);
			continue;
		}
		g_board[rowt][colt] = 'x';
		//将值返回出去
		*row = rowt;
		*col = colt;
		break;
	}
}
void computerMove(int* row, int* col)
{
	int rowt = 0;
	int colt = 0;
	while (1)
	{
		rowt = rand() % (ROW);
		colt = rand() % (COL);
		if (g_board[rowt][colt] == ' ')
		{
			break;
		}
	}
	g_board[rowt][colt] = 'o';
	//将值返回出去
	*row = rowt;
	*col = colt;
}
/*
判断是否平局
*/
int isdraw()
{
	int num = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (g_board[i][j] == ' ')
			{
				num++;
			}
		}
	}
	if (num == 0)//平局了，棋盘满了
	{
		return 1;
	}
	else//还能打
	{
		return 0;
	}
}
/*
判断是否三子相连
参数：当前下子位置
返回值：谁获得胜利
*/
char judge(int row, int col)
{
	int num =1;//计数相连棋子个数
	int i = 1;//判断周围第i个棋子是否相同
	//从左到右的判断
	for (i = 1; i < WIN; i++)
	{
		if ((col + i) > (COL - 1) || g_board[row][col] != g_board[row][col + i])
		{
			break;
		}
		num++;
	}
	//从右到左的判断
	for (i = 1; i < WIN; i++)
	{
		if ((col - i) < 0 || g_board[row][col] != g_board[row][col - i])
		{
			break;
		}
		num++;
	}
	if (num >= WIN)
	{
		return g_board[row][col];
	}
	num = 1;
	//从上到下的判断
	for (i = 1; i < WIN; i++)
	{
		if ((row + i) > (ROW - 1) || g_board[row][col] != g_board[row + i][col])
		{
			break;
		}
		num++;
	}
	//从下到上的判断
	for (i = 1; i < WIN; i++)
	{
		if ((row - i) < 0 || g_board[row][col] != g_board[row - i][col])
		{
			break;
		}
		num++;
	}
	if (num >= WIN)
	{
		return g_board[row][col];
	}
	num = 1;
	//从左上到右下的判断
	for (i = 1; i < WIN; i++)
	{
		if ((row + i) > (ROW - 1) || (col + i) > (COL - 1) || g_board[row][col] != g_board[row + i][col + i])
		{
			break;
		}
		num++;
	}
	//从右下到左上的判断
	for (i = 1; i < WIN; i++)
	{
		if ((row - i) < 0 || (col - i) < 0 || g_board[row][col] != g_board[row - i][col - i])
		{
			break;
		}
		num++;
	}
	if (num >= WIN)
	{
		return g_board[row][col];
	}
	num = 1;
	//从右上到左下的判断
	for (i = 1; i < WIN; i++)
	{
		if ((row + i) > (ROW - 1) || (col - i) < 0 || g_board[row][col] != g_board[row + i][col - i])
		{
			break;
		}
		num++;
	}
	//从左下到右上的判断
	for (i = 1; i < WIN; i++)
	{
		if ((row - i) < 0 || (col + i) > (COL - 1) || g_board[row][col] != g_board[row - i][col + i])
		{
			break;
		}
		num++;
	}
	if (num >= WIN)
	{
		return g_board[row][col];
	}
	if (isdraw())//平局了
	{
		return 'd';
	}
	else
	{
		return ' ';
	}
}
/*
游戏是否结束
*/
int isOver(int row, int col)
{
	char c = judge(row, col);
	if (c == ' ')
	{
		return 0;
	}
	if (c == 'x')
	{
		printf("恭喜你赢了！\n");
		system("pause");
		return 1;
	}
	if (c == 'o')
	{
		printf("不走运，你输了！\n");
		system("pause");
		return 1;
	}
	else
	{
		printf("平局！\n");
		system("pause");
		return 1;
	}
}
/*
游戏主体
*/
void mainGame()
{
	int row = 0;
	int col = 0;
	//初始化棋盘
	initBoard();
	//打印棋盘
	printBoard();
	//循环控制游戏进程
	while (1)
	{
		//玩家开始下
		playerMove(&row, &col);
		//打印棋盘
		printBoard();
		//判定是否游戏结束
		if (isOver(row, col))
		{
			break;
		}
		//电脑下
		computerMove(&row, &col);
		//打印棋盘
		printBoard();
		printf("计算机回合↑\n");
		//判定是否游戏结束
		if (isOver(row, col))
		{
			break;
		}
	}
}
void gameExplain()
{
	system("cls");
	printf("五子棋你会玩，三子棋你不会玩？\n");
	printf("什么你五子棋都不会玩，你不会百度，搜狗，goole啊！\n");
	system("pause");
}
int main()
{
	srand(time(NULL));
	while (1)
	{
		int choose = menu();
		if (choose == 1)
		{
			mainGame();
			continue;
		}
		if (choose == 2)
		{
			gameExplain();
			continue;
		}
		if (choose == 3)
		{
			break;
		}
		else
		{
			printf("别瞎比选！\n");
			rewind(stdin);
			system("pause");
			continue;
		}
	}
	printBoard();
	return 0;
}