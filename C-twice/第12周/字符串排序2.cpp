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
		int min = i;
		for(int j = i + 1; j < 5; j++)
		{
			if(strcmp(p[min],p[j]) > 0)
			{
				min = j;
			}
		}
		if(min != i)
		{
			char *t;
			t = p[i];
			p[i] = p[min];
			p[min] = t;
		}
	}
	printf("�����:\n");
	for(int i = 0; i < 5; i++)
	{
		puts(p[i]);
	}
}
