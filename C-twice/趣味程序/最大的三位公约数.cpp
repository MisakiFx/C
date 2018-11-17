#include <stdio.h>
/*问555555的约数中最大的三位数是多少*/
int main()
{
	int i, j;
	printf("请输入一个数：");
	scanf("%d",&i);
	if(i < 100)
	{
		printf("滚！\n");
		return 1;
	}
	for(j = 999; j >= 100; j--)
	{
		if(i % j == 0)
		{
			printf("%d是最大的三位公约数！\n",j);
			break;
		}
	}
	if(j == 99)
	{
		printf("不存在的！\n");
	}
} 
