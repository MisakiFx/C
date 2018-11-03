#include <stdio.h>
#include <ctype.h>
int main()
{
	char c, m;
	printf("请输入一个小写字母:");
	scanf("%c",&c); 
	if(islower(c))
	{
		m = c - 32;//m = toupper(c)
		printf("%c",m);
	}
	else
	{
		printf("输入的是非法字符");
	}
} 
