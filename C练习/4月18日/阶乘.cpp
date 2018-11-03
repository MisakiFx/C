#include <stdio.h>
void fun()
{
	int sum = 1;
	int i = 1, n;
	scanf("%d",&n);
	do
	{
		sum *= i;
		i++;
	}while(i <= n);
	printf("%d",sum);
}
int main()
{
	fun();
}
