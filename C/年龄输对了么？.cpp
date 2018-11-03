#include <stdio.h>
int main()//输入五次年龄，计算年龄输错次数，＜0就是错的 
{
	const int N=5;
	int old,i,count=0;
	for (i=0;i<5;i++)
	{
		printf("请输入年龄：");
		scanf("%d",&old);
		if(old>0)
		{
			continue;
		} 
		count++;
	}
	printf("输入错误次数为：%d",count);
} 
