#include <stdio.h>
int main()
{
	int year;
	printf("��������ݣ�");
	scanf("%d",&year);
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		printf("������"); 
	}
	else
	{
		printf("��ƽ��");
	}
}
