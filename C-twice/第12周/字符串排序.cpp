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
		printf("�������%d���ַ�������Ҫ����50���ַ���:",i + 1);
		scanf("%s",p[i]);
	}
	printf("����ǰ:\n");
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
	printf("�����:\n");
	for(int i = 0; i < 5; i++)
	{
		puts(p[i]);
	}
}
