#include <stdio.h>//ֻҪ������ָ������˳����򡣡� 
int main()
{
	int i;
	for(;;) 
	{
	printf("����������:");
	scanf("%d",&i);
	if(i<0)//����Ϊ�������˳� 
	{
		break;
	}
	}
	printf("over");
}
