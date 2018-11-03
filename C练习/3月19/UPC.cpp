#include <stdio.h>
#include <math.h>
int main()
{
	int x = 0,y = 0;//计数
	long long upc;
	long long temp = 10000000000;
	int sum1 = 0,sum2 = 0; 
	int odd[10] = {0};
	int even[10] = {0};
	int end = 0;
	printf("请输入十一位数字：");
	scanf("%lld",&upc);
	if((upc / temp) > 9 || upc < 0)
	{
		printf("输入错误！");
		return 1;
	}
	for(int i = 0; i < 11; i++)//存位 
	{
		static long long j = 1; 
		if(i % 2 == 0)
		{
			odd[x] = upc / j % 10;
			x++;
		}
		else
		{
			even[y] = upc / j % 10;
			y++;
		}
		j *= 10;
	}
	for(int i = 0; i < 10; i++)
	{
		sum1 += odd[i];
	}
	for(int i = 0; i < 10; i++)
	{
		sum2 += even[i];
	}
	end  = (sum1 * 3 - sum2) % 10;
	printf("%d%lld",end,upc);
} 
