#include <stdio.h>
int main()//����������䣬������������������0���Ǵ�� 
{
	const int N=5;
	int old,i,count=0;
	for (i=0;i<5;i++)
	{
		printf("���������䣺");
		scanf("%d",&old);
		if(old>0)
		{
			continue;
		} 
		count++;
	}
	printf("����������Ϊ��%d",count);
} 
