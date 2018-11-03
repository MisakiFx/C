#include <stdio.h>   
void fun(char str1[])   
{   
	/***********begin***********/
	int i = 0; 
	while(str1[i] != '\0')
	{
		if(str1[i] > 'A' && str1[i] < 'Z')
		{
			str1[i] = str1[i] + ' ';
		}
		i++;
	}
	/************end************/   
}   
int main()   
{     
	char str1[80];     
	printf("Please input a string:\n");     
	gets(str1);     
	fun(str1);     
	printf("Result is: %s\n",str1);   
}
