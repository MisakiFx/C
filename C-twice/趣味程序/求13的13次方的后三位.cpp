#include <stdio.h>
/*��13��13�η��������λ��*/
/*����λ��ֻ������ͱ������ĺ���λ�й�*/
int main()
{
	int i, x, y, last = 1;
	printf("��������ʽ��");
	scanf("%d%d",&x,&y);
	for(int i = 1; i <= y; i++)
	{
		last = last * x % 1000;//��������������λȡ���������´���� 
	}
	printf("����λ�ǣ�%d\t",last);
} 
