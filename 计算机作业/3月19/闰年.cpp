#include <stdio.h>
int main()
{
	int year;
	printf("请输入年份：");
	scanf("%d",&year);
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		printf("是闰年"); 
	}
	else
	{
		printf("是平年");
	}
}
