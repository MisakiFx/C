#include <stdio.h>
void fun()
{
	int i = 1, n;
	double sum = 0;
	scanf("%d",&n);
	while(i <= n)
	{
		sum += 1.0 / i;
		i += 2;
	}
	printf("%lf",sum);
}
int main()
{
	fun();
}
