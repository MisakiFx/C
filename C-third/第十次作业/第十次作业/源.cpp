#include <stdio.h>
#include <stdlib.h>
/*!
 * \项目名 第十次作业
 * \日期 2018/11/19 2:05
 *
 * \作者 Misaki
 * 联系方式  1761607418@qq.com
 *
 * 文件描述: 第十次作业，用循环选择等完成题目
 *
*/
/*
判断比赛顺序
*/
void PrintRank()
{
	char rank[5] = { 0 };
	char rankT[5] = { 'A', 'B', 'C', 'D', 'E' };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int m = 0; m < 5; m++)
				{
					for (int n = 0; n < 5; n++)
					{
						rank[0] = rankT[i];
						rank[1] = rankT[j];
						rank[2] = rankT[k];
						rank[3] = rankT[m];
						rank[4] = rankT[n];
						int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
						for (int o = 0; o < 5; o++)
						{
							if (rank[o] == 'A') num1++;
							if (rank[o] == 'B') num2++;
							if (rank[o] == 'C') num3++;
							if (rank[o] == 'D') num4++;
							if (rank[o] == 'E') num5++;
						}
						if (num1 == 0 || num2 == 0 || num3 == 0 || num4 == 0 || num5 == 0)
						{
							continue;
						}
						if (rank[1] == 'B')
						{
							if (rank[1] == 'B' && rank[3] != 'E')
							{
								if (rank[0] == 'C')
								{
									if (rank[4] == 'C')
									{
										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
								else if (rank[1] == 'D')
								{
									if (rank[4] == 'C')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
							}
							else if (rank[3] == 'E' && rank[1] != 'B')
							{
								if (rank[0] == 'C')
								{
									if (rank[4] == 'C')
									{
										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
								else if (rank[1] == 'D')
								{
									if (rank[4] == 'C')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
							}
						}
						else if(rank[2] == 'A')
						{
							if (rank[1] == 'B' && rank[3] != 'E')
							{
								if (rank[0] == 'C')
								{
									if (rank[4] == 'C')
									{
										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
								else if (rank[1] == 'D')
								{
									if (rank[4] == 'C')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
							}
							else if (rank[3] == 'E')
							{
								if (rank[0] == 'C')
								{
									if (rank[4] == 'C')
									{
										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
								else if (rank[1] == 'D')
								{
									if (rank[4] == 'C')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
									else if (rank[2] == 'D')
									{

										if (rank[3] == 'E')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
										else if (rank[0] == 'A')
										{
											for (int o = 0; o < 5; o++)
											{
												printf("%c\t", rank[o]);
											}
											printf("\n");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void Print(int num)
{
	switch (num)
	{
	case 1:
		printf("A\n");
		break;
	case 2:
		printf("B\n");
		break;
	case 3:
		printf("C\n");
		break;
	case 4:
		printf("D\n");
		break;
	}
}
/*
判断谁是凶手
*/
void PrintMurder()
{
	for (int i = 1; i <= 4; i++)
	{
		if (i == 1)
		{
			if (i == 3 && i == 4 && i != 4)
			{
				Print(i);
			}
		}
		else if (i != 3)
		{
			if (i != 1 && i == 4 && i != 4)
			{
				Print(i);
			}
		}
		else if (i != 4)
		{
			if (i != 1 && i == 3 && i != 4)
			{
				Print(i);
			}
		}
		else if (i == 4)
		{
			if (i == 3 && i != 1)
			{
				Print(i);
			}
		}
	}
}
/*
打印若干行的杨辉三角
参数：行数
*/
void PrintYangHui(int num)
{
	int yangHui[10][20] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		yangHui[i][0] = 0;
	}
	yangHui[0][1] = 1;
	yangHui[0][2] = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < i + 2; j++)
		{
			yangHui[i][j] = yangHui[i - 1][j - 1] + yangHui[i - 1][j];
			yangHui[i][j + 1] = 0;
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j < i + 2; j++)
		{
			printf("%d ", yangHui[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	PrintRank();//第一题
	PrintMurder();//第二题
	PrintYangHui(4);//第三题
	system("pause");
	return 0;
}