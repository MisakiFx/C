#include <stdio.h>
#include <stdlib.h>
int main()
{
	//二维数组和指针
	//二维数组的首地址：&a[0][0]
	//二维数组的理解：由N个一维数组所组成的 
	int i,j;
	double score[5][3]={
		{55,66,77},
		{52,62,72},
		{15,26,37},
		{54,65,76},
		{55,66,77},
	};
	double (*ptr_score)[3]=score;//指针定义二维数组要给指针一个维度才能定义 （行指针） 
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%.2lf\t",*(*(ptr_score+i)+j));
			//printf("%.2lf\t",*(score[i]+j));
			//score[i][j]=>*(score[i]+j)
		}
		printf("\n");
	}
	/*
	//遍历第一行数据
	for(i=0;i<3;i++)
	{
		printf("%.2lf\t",score[0][i]);//score[0]就是第一行的数组名 
	 } 
	 printf("\n"); 
	//遍历第二行数据
	for(i=0;i<3;i++)
	{
		printf("%.2lf\t",score[1][i]);//score[1]就是第二行的数组名 
	}*/
	int (*p)[5] = (int(*)[5])malloc(sizeof(int[5])*10);
	printf("%d",sizeof(p));
	
}
