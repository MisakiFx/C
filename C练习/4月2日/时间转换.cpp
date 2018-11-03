#include <stdio.h>
int Turn(int bjt)
{
	if(bjt >= 800)
	{
		return bjt - 800;
	}
	else
	{
		return ((24 - (8 - (bjt / 100))) * 100 + bjt % 100);
	}
}
int main()
{
	int bjt, uct;
	scanf("%d",&bjt);
	uct = Turn(bjt);
	printf("3%d\n",uct);
}
