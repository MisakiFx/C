#include <stdio.h>
int main()
{
	int i,deletenum,inset,deleteindex=-1,count=5;
	int nums[]={123,456,789,741,852};
	printf("原来的数组是：\n"); 
	for(i=0;i<count;i++)
	{
		printf("%d\t",nums[i]);
	 } 
	printf("\n请输入要删除的数字：\n"); 
	scanf("%d",&deletenum);
	for(i=0;i<count;i++)
	{
		if(nums[i]==deletenum)
		{
			deleteindex=i;
			break;
		}
	}
	if(deleteindex==-1)
	{
		printf("没有找到要删除的数字\n");
	}
	else
	{
		for(i=deleteindex;i<count;i++)
		{
			nums[i]=nums[i+1];
		}
	
		printf("删除后的数组为：\n");
		for(i=0;i<count-1;i++)
		{
			printf("%d\t",nums[i]);
		}
		printf("\n请输入要插入的数字：\n");//给删除数字后的数组的末尾插入一个数字 
		scanf("%d",&inset);
		nums[count-1]=inset;
		printf("修改后的数组为：\n");
		for(i=0;i<count;i++)
		{
			printf("%d\t",nums[i]);
		}
	}	
 } 
