#include <stdio.h>
#include <stdlib.h>
int main()
{
	//��ά�����ָ��
	//��ά������׵�ַ��&a[0][0]
	//��ά�������⣺��N��һά��������ɵ� 
	int i,j;
	double score[5][3]={
		{55,66,77},
		{52,62,72},
		{15,26,37},
		{54,65,76},
		{55,66,77},
	};
	double (*ptr_score)[3]=score;//ָ�붨���ά����Ҫ��ָ��һ��ά�Ȳ��ܶ��� ����ָ�룩 
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
	//������һ������
	for(i=0;i<3;i++)
	{
		printf("%.2lf\t",score[0][i]);//score[0]���ǵ�һ�е������� 
	 } 
	 printf("\n"); 
	//�����ڶ�������
	for(i=0;i<3;i++)
	{
		printf("%.2lf\t",score[1][i]);//score[1]���ǵڶ��е������� 
	}*/
	int (*p)[5] = (int(*)[5])malloc(sizeof(int[5])*10);
	printf("%d",sizeof(p));
	
}
