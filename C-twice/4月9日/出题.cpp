#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIXED 0.001
double answer;
int score = 0;
char charactor(int num1, int num2)
{
	srand(time(NULL));
	int choice = rand() % 4 + 1;
	switch(choice)
	{
		case 1:
			answer = num1 + num2;
			return '+';
			break;
		case 2:
			answer = num1 - num2;
			return '-';
			break;
		case 3:
			answer = num1 * num2;
			return '*';
			break;
		case 4:
			answer = (double)num1 / num2;
			return '/';
			break;
	}
}
void Question()
{
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
	{
		double answer0;
		int num1 = rand() % 10 +1;
		int num2 = rand() % 10 +1;
		printf("第%d题：%d%c%d=",i + 1,num1,charactor(num1,num2),num2);
		scanf("%lf",&answer0);
		if(answer - answer0 <= FIXED && answer0 - answer <= FIXED)
		{
			printf("正确！\n");
			score += 10;
		}
		else
		{
			printf("错误！\n");
		}
	}
}
int main()
{
	printf("开始答题！(结果保留三位小数)\n");
	do
	{
		score = 0;
		Question();
		printf("总分为：%d\n",score);
	}while((score <= 75)?printf("请重来！\n"):0);
	printf("恭喜通过！");
}
