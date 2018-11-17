#include <stdio.h>
#include <math.h>
#define WIGHT 62//假设图形总宽度为62 
#define WIGHT2 62
int main()
{
	double y;//余弦函数的y轴
	int x, m;//余弦函数的x轴和每一行点的横坐标
	for(y = 1; y >= -1; y -= 0.1)//外层循环控制行 
	{
		m = acos(y) * 10;//将计算出来的横坐标给m,10是扩大倍数，数字越小越大 
		for(x = 1; x < m; x++)
		{
			printf(" "); 
		}
		printf("*");//找到打印星号的位置打印 
		for(;x < WIGHT - m; x++)//利用对称进行打印 
		{
			printf(" ");
		}
		printf("*\n"); 
	} 
	for(y = 1; y >= 0; y -= 0.1)
	{
		m = asin(y) * 20;
		for(x = 1; x < m; x++)
		{
			printf(" ");
		}
		printf("*");
		for(; x < WIGHT2 - m; x++)
		{
			printf(" ");
		}
		printf("*\n");
	}
	for(y = 0; y <= 1; y += 0.1)
	{
		m = asin(y) * 20;
		for(x = 1; x < WIGHT2+m+2; x++)
		{
			printf(" ");
		}
		printf("*");
		for(; x < 2 * WIGHT2 - m; x++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}
