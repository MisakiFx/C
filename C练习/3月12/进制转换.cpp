#include <stdio.h>
void Eight()
{
	int d,i = 0,j = 0;
	int num[10] = {0};
	scanf("%d",&d);
	printf("0%o\n",d);
}
void Six()
{
	int d,i = 0,j = 0;
	int num[10] = {0};
	scanf("%d",&d);
	printf("0x%x",d);
}
int main()
{
	Eight();
	Six();
}
