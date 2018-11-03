#include <stdio.h>
int main()
{
	int i,j;
	char name[3][10]={"初音未来","见崎鸣","栗山未来"};
	int scores[4][3]={
	{1,2,3},
	{4,5,6},
	{7,8,9}
};
	printf("语文\t数学\t英语\t\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%-8d",scores[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		printf("%-12s",name[i]);	
	}
 }
