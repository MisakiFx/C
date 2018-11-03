#include <stdio.h>
#include <math.h>
void fun()
{
	int n;
	double sum;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		sum += i * (i + 2) / pow((2 * i), 2);
	}
	printf("%lf",sum);
}
int main()
{
	fun();
}
