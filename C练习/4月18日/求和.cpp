#include <stdio.h>
void fun()
{
	int n,i = 1;
	int sum = 0;
	scanf("%d",&n);
	while(i <= n)
	{
		sum += i;
		i += 2;
	}
	printf("%d",sum);
}
int main()
{
	fun();
}
