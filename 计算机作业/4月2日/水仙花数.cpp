#include <stdio.h>
#include <math.h>
int main()
{
	int num, a, b, c, num2;
	while(1)
	{
		printf("请输入一个数:");
		scanf("%d",&num);
		a = num % 10;
		b = num / 10 % 10;
		c = num / 100 % 10;
		num2 = pow(a,3) + pow(b,3) + pow(c,3);
		if(num2 == num)
		{
			printf("是水仙花数\n");
		}
		else
		{
			printf("不是水仙花数\n");
		} 
	}
}
