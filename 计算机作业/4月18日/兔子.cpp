#include <stdio.h>
#include <math.h>
void fun()
{
	int n;
	scanf("%d",&n);
	int m = n / 3;
	printf("%d",(int)pow(2, (m + 1)));
}
int main()
{
	fun(); 
}
