#include <stdio.h>
/*��555555��Լ����������λ���Ƕ���*/
int main()
{
	int i, j;
	printf("������һ������");
	scanf("%d",&i);
	if(i < 100)
	{
		printf("����\n");
		return 1;
	}
	for(j = 999; j >= 100; j--)
	{
		if(i % j == 0)
		{
			printf("%d��������λ��Լ����\n",j);
			break;
		}
	}
	if(j == 99)
	{
		printf("�����ڵģ�\n");
	}
} 
