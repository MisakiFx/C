#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	while(1)
	{
		int b;
		srand(time(NULL));
		int a = rand()%51 + 50;
		printf("���������֣�");
		scanf("%d",&b);
		if(a == b)
		{
			printf("�¶��ˣ�\n");
		}
		else
		{
			printf("�´���!\n"); 
			printf("��ȷ����Ϊ��%d\n",a); 
		}
	}
}
