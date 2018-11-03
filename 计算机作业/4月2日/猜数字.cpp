#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	while(1)
	{
		int b;
		srand(time(NULL));
		int a = rand()%51 + 50;
		printf("请输入数字：");
		scanf("%d",&b);
		if(a == b)
		{
			printf("猜对了！\n");
		}
		else
		{
			printf("猜错了!\n"); 
			printf("正确数字为：%d\n",a); 
		}
	}
}
