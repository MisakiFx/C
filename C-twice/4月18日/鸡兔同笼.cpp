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
	printf("����%dֻ������%dֻ",n ,m);
}
int main()
{
	fun();
}
