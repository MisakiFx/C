#include <stdio.h>
#define N 5
int main()
{
	int i,j,temp;
	int nums[N]={5,8,9,12,7};
	printf("原来的数组是：\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",nums[i]);//源数组 
	 } 
	 printf("\n");
	for(i=0;i<N-1;i++)//将数组按从小到大排列 
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
	printf("按从小到大排列后的数组为：\n"); 
	for(i=0;i<5;i++)
	{
		printf("%d\t",nums[i]);
	 } 
} 
