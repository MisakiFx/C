#include <stdio.h>
int main()
{
	int i;
	int nums[5];
	printf("请输入数组的值：\n"); 
	for(i=0;i<5;i++)
	{
		scanf("%d",&nums[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("%d\t",nums[i]);
	}
}
