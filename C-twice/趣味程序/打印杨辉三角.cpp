#include <stdio.h>
/*在屏幕上显示杨辉三角形*/
/**/
int main()
{
	for(int i = 0; i <= 12; i++)
	{
		for(int j = 0; j < 12 - i; j++)
		{
			printf(" ");
		}
		for(int j = 1; j <= 2 * i + 1; j++)
		{
			if(j % 2 == 0)
			{
				printf(" ");
			}
			else if(j == 1 || j == 2 * i + 1)
			{
				printf("1");
			}
			else
			{
				printf("%c",'*');
			}
		}
		printf("\n");
	} 
}
