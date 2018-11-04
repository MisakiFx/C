#include <stdio.h>
void fun(char a[],char c)
{
	int i,j;
	/***********SPACE***********/
	for(i=j=0;i < 20;i++)
	if(a[i]!=c) a[j++]=a[i];
	/***********SPACE***********/
	a[j] = '\0';
}
int main()
{
	char a[20],cc;
	gets(a);
	/***********SPACE***********/
	scanf("%c",&cc);
	/***********SPACE***********/
	fun(a,cc);
	puts(a);
}

