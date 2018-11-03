#include <stdio.h>
int main()
{
	int d,sum,a,b,c;
	scanf("%d",&d);
	a = d % 10;
	b = d % 100 / 10;
	c = d / 100;
	sum = a + b + c;
	printf("%d",sum);  
}
