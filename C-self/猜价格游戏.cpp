#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	printf("请猜测商品价格，价格在200以内，一共有10次机会\n"); 
	srand(time(NULL));
	int i,sth1,sth=rand()%200+1;
	const int N=10;
	for(i=0;i<N;i++)
	{
		printf("请输入猜测的价格：");
		scanf("%d",&sth1);
		if(sth1==sth) 
		{
			printf("恭喜猜中，获得胜利\n");
			break; 
		}
		
		else if(sth1>sth)
		{
			while(i==9)
			{
				printf("答案偏大，游戏失败\n"); 
				break;
			}
			while(i<9)
			{
			printf("答案偏大，请重新猜测还有%d次机会\n",10-(i+1));
			break;
			}
		}
		else if(sth1<sth)
		{
			while(i==9)
			{
				printf("答案偏小，游戏失败\n"); 
				break;
			}
			while(i<9)
			{
			printf("答案偏小，请重新猜测还有%d次机会\n",10-(i+1));
			break;
			}
		}
	}
	printf("游戏结束,正确答案是%d",sth); 
}
