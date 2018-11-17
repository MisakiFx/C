#include <stdio.h>
/*求13的13次方的最后三位数*/
/*后三位数只与乘数和被乘数的后三位有关*/
int main()
{
	int i, x, y, last = 1;
	printf("请输入算式：");
	scanf("%d%d",&x,&y);
	for(int i = 1; i <= y; i++)
	{
		last = last * x % 1000;//将相乘完的数后三位取出来用于下次相乘 
	}
	printf("后三位是：%d\t",last);
} 
