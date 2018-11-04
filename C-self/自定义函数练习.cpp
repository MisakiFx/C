#include <stdio.h>
#include <stdlib.h>
/*需求：
1.书写函数，实现数组元素的查找，要求返回找到的元素下标
2.书写函数完成冒泡排序并返回排序后的数组
3.书写函数要求用户输入密码（6位，错误则重新输入），返回并打印用户输入的正确密码
*/ 
//1.书写函数，实现数组元素得下标，要求返回找到的元素下标
int nums[]={87,96,33,24,84};
int search();
int search()
{
	int nums[]={34,56,78,3,2};
	int i;
	int searchNum,searchIndex=-1;//要查找的元素和元素的下标，没找到Index为-1
	for(i=0;i<5;i++)
	{
		printf("%d\t",*(nums+i));
	} 
	printf("\n");
	printf("请输入要查找的数字：\n");
	scanf("%d",&searchNum);
	for(i=0;i<5;i++)
	{
		if(nums[i]==searchNum)
		{
			searchIndex=i;
			break;
		}
	}
	return searchIndex;
 }

//2.书写函数完成冒泡排序并返回排序后的数组
int* sort();                                                  
int* sort()
{
	int i,j,temp;
	int *ptr_nums=nums;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(*(nums+j)>*(nums+j+1))
			{
				temp=*(nums+j);
				*(nums+j)=*(nums+j+1);
				*(nums+j+1)=temp;
			}
		}
	}
	return ptr_nums;
	
}
//3.书写函数要求用户输入密码（6位，错误则重新输入），返回并打印用户输入的正确密码
/*
char * password();
char * password()
{
	
}
*/ 
int main()
{
	int i;
	int searchIndex=search();
	printf("%d\n",searchIndex);
	int *nums=sort();
	for(i=0;i<5;i++)
	{
		printf("%d\t",*(nums+i));
	}
	nums=NULL;
	return 0;
	
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
