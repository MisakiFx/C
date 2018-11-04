#include <stdio.h>//只要年龄出现负数，退出程序。。 
int main()
{
	int i;
	for(;;) 
	{
	printf("请输入年龄:");
	scanf("%d",&i);
	if(i<0)//年龄为负程序退出 
	{
		break;
	}
	}
	printf("over");
}
