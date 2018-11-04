#include <stdio.h>
#include <ctype.h>
int main()
{
	char a;
	do
	{
		printf("请输入一个字符:");
		scanf("%c",&a);
		if(isalpha(a))
		{
			printf("输入的是字母\n");
		}
		else if(isdigit(a))
		{
			printf("输入的是数字\n");
		}
		else
		{
			printf("输入的是其他字符\n"); 
		}
		fflush(stdin);
	}while(1);
}
