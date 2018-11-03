#include <stdio.h>
void fun()
{
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for(int j = 0; j < 11 - i * 2; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
int main()
{
	fun();
}
