#include <stdio.h>
#include <stdlib.h>
/*����
1.��д������ʵ������Ԫ�صĲ��ң�Ҫ�󷵻��ҵ���Ԫ���±�
2.��д�������ð�����򲢷�������������
3.��д����Ҫ���û��������루6λ���������������룩�����ز���ӡ�û��������ȷ����
*/ 
//1.��д������ʵ������Ԫ�ص��±꣬Ҫ�󷵻��ҵ���Ԫ���±�
int nums[]={87,96,33,24,84};
int search();
int search()
{
	int nums[]={34,56,78,3,2};
	int i;
	int searchNum,searchIndex=-1;//Ҫ���ҵ�Ԫ�غ�Ԫ�ص��±꣬û�ҵ�IndexΪ-1
	for(i=0;i<5;i++)
	{
		printf("%d\t",*(nums+i));
	} 
	printf("\n");
	printf("������Ҫ���ҵ����֣�\n");
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

//2.��д�������ð�����򲢷�������������
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
//3.��д����Ҫ���û��������루6λ���������������룩�����ز���ӡ�û��������ȷ����
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
