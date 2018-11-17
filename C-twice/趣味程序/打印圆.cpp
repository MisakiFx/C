#include <stdio.h>
#include <math.h>
int main()
{
	//利用圆的方程R*R=X*X+Y*Y 
	double y;
	int x, m;
	for(y = 10; y >= -10; y--)
	{
		m = 2.0 * sqrt(100 - y * y);//2.0调节屏幕纵宽比 
		for(x = 1; x < 25 - m; x++)//半径-x坐标等于前面要打的空格 
		{
			printf(" ");
		}
		printf("*");
		for(; x < 25 + m; x++)//半径+x坐标等于中间要打的空格 
		{
			printf(" ");
		}
		printf("*\n");
	}
} 
