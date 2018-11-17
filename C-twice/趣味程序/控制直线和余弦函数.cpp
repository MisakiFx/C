#include <stdio.h>
#include <math.h>
int main()
{
	double y;
	int yy, m, n, x;
	for(int yy = 0; yy <= 20; yy++)
	{
		y = (double)yy / 10;
		m = acos(1 - y) * 10;
		n = 45 * (y - 1) + 31;
		for(x = 0; x <= 62; x++)
		{
			if(m == x && n == x || n == x)
			{
				printf("+");
			}
			else if(x == m || x == 62 - m)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		} 
		printf("\n");
	} 
}
