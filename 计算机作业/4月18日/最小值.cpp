#include <stdio.h>
void fun()
{
	int num,n;
	int smallest = 32767;
	int biggest = -32767;
	printf("������һ����������");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&num);
		if(num < smallest)
		{
			smallest = num;
		}
		if(num > biggest)
		{
			biggest = num;
		}
		
	}
	printf("��С��Ϊ��%d",smallest);
	printf("�����Ϊ��%d",biggest);
}
int main()
{
	fun();
}
