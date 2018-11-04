#include <stdio.h>
void fun()
{
	int num,n;
	int smallest = 32767;
	int biggest = -32767;
	printf("请输入一共几个数：");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&num);
		if(num < smallest)
		{
			smallest = num;
		}
		if(num > biggest)
		{
			biggest = num;
		}
		
	}
	printf("最小数为：%d",smallest);
	printf("最大数为：%d",biggest);
}
int main()
{
	fun();
}
