#include <stdio.h>
void fun()
{
	int a[10];
	int n = 0;
	int num;
	scanf("%d",&num);
	while(num > 0)
	{
		if(num % 10 % 2 == 0)
		{
			a[n] = num % 10;
			n++;
		}
		num /= 10;
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d",a[i]);
	}
}
int main()
{
	fun();
}
