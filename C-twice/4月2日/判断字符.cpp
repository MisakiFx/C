#include <stdio.h>
#include <ctype.h>
int main()
{
	char a;
	do
	{
		printf("������һ���ַ�:");
		scanf("%c",&a);
		if(isalpha(a))
		{
			printf("���������ĸ\n");
		}
		else if(isdigit(a))
		{
			printf("�����������\n");
		}
		else
		{
			printf("������������ַ�\n"); 
		}
		fflush(stdin);
	}while(1);
}
