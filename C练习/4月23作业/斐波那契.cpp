#include <stdio.h>
void fun()
{
	int num1 = 1, num2 = 1,num3;
	printf("%-20d%-20d",num1,num2);
	for(int i = 3; i <= 40; i++)
	{
		num3 = num1 + num2;
		printf("%-20d",num3);
		num1 = num2;
		num2 = num3;
		if(i % 4 == 0)
		printf("\n");
	}
}
int main()
{
	fun();
}
