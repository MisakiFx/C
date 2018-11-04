#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char **p = (char**)malloc(sizeof(char*) * 5);
	for(int i = 0; i < 5; i++)
	{
		p[i] = (char*)malloc(sizeof(char) * 51);
	}
	for(int i = 0; i < 5; i++)
	{
		printf("请输入第%d个字符串（不要超过50个字符）:",i + 1);
		scanf("%s",p[i]);
	}
	printf("排序前:\n");
	for(int i = 0; i < 5; i++)
	{
		puts(p[i]);
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4 - i; j++)
		{
			if(strcmp(p[j],p[j + 1]) > 0)
			{
				char *t;
				t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
			}
		}
	}
	printf("排序后:\n");
	for(int i = 0; i < 5; i++)
	{
		puts(p[i]);
	}
}
