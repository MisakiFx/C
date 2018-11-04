#include <stdio.h>
int main()
{
	double a, b, c;
	printf("请输入三角形三边长度：");
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a + b > c && a + c > b && b + c > a && a - b < c && a - c < b && b - c < a && b - a < c && c - a < b && c - b < a)
	{
		if(a == b && a != c|| a == c && a != b|| b == c && b != a)
		{
			printf("等腰");
		}
		if(a == b && a == c)
		{
			printf("等边");
		}
		if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
		{
			printf("直角");
		}
	}
	else
	{
		printf("不是");
	}
	printf("三角形\n");
}
