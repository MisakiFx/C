#include <stdio.h>
void fun()
{
	int n, m;
	for(n = 0; n <= 35; n++)
	{
		m = 35 - n;
		if(4 * n + 2 * m == 94)
		{
			break;
		}
	}
	printf("兔有%d只，鸡有%d只",n ,m);
}
int main()
{
	fun();
}
