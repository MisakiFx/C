#include <stdio.h>
int main()
{
	int i,deletenum,inset,deleteindex=-1,count=5;
	int nums[]={123,456,789,741,852};
	printf("ԭ���������ǣ�\n"); 
	for(i=0;i<count;i++)
	{
		printf("%d\t",nums[i]);
	 } 
	printf("\n������Ҫɾ�������֣�\n"); 
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
		printf("û���ҵ�Ҫɾ��������\n");
	}
	else
	{
		for(i=deleteindex;i<count;i++)
		{
			nums[i]=nums[i+1];
		}
	
		printf("ɾ���������Ϊ��\n");
		for(i=0;i<count-1;i++)
		{
			printf("%d\t",nums[i]);
		}
		printf("\n������Ҫ��������֣�\n");//��ɾ�����ֺ�������ĩβ����һ������ 
		scanf("%d",&inset);
		nums[count-1]=inset;
		printf("�޸ĺ������Ϊ��\n");
		for(i=0;i<count;i++)
		{
			printf("%d\t",nums[i]);
		}
	}	
 } 
