#include <stdio.h>
#define N 5
int main()
{
	int i,j,temp;
	int nums[N]={5,8,9,12,7};
	printf("ԭ���������ǣ�\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",nums[i]);//Դ���� 
	 } 
	 printf("\n");
	for(i=0;i<N-1;i++)//�����鰴��С�������� 
	{
		for(j=0;j<N-i-1;j++)
		{
		
			if(nums[j]>nums[j+1])
			{
				temp=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=temp;
			}
		}
	}
	printf("����С�������к������Ϊ��\n"); 
	for(i=0;i<5;i++)
	{
		printf("%d\t",nums[i]);
	 } 
} 
