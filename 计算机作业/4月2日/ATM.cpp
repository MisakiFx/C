#include <stdio.h>
#include <string.h>
#define PASSWORD "123456"
double money = 100;
int Use()
{
	int choice;
	double money2;
	char id[20];
	printf("���������ѡ�\n");
	printf("1����ѯ���\n");
	printf("2��ȡ��\n");
	printf("3�����\n");
	printf("4��ת��\n");
	printf("5����ӡ�˵�\n");
	printf("6���˿�\n"); 
	if(scanf("%d",&choice) != 1)
	{
		printf("����ʧ��\n");
		return 1;
	}
	switch(choice)
	{
		case 1:
			printf("%.2lf\n",money);
			break;
		case 2:
			printf("������ȡ����:");
			scanf("%lf",&money2);
			if(money - money2 < 0)
			{
				printf("���㣡\n");
				break;
			}
			else
			{
				money -= money2;
				printf("ȡ��ɹ���\n");
			}
			break;
		case 3:
			printf("����������:");
			scanf("%lf",&money2);
			money += money2;
			printf("���ɹ���\n");
			break;
		case 4:
			printf("������ת�˷��˺ţ�");
			scanf("%s",id);
			printf("������ת�˽�");
			scanf("%lf",&money2);
			if(money - money2 < 0)
			{
				printf("���㣡\n");
				break;
			}
			printf("ת�˳ɹ���\n"); 
			break;
		case 5:
			printf("��ӡ�嵥�ɹ���\n");
			break;
		case 6:
			break;
		default:
			break;
	} 
	return choice;
}
int main()
{
	char pass[7];
	printf("����������:");
	scanf("%s",pass);
	if(strcmp(pass,PASSWORD) != 0)
	{
		printf("�������");
		return 1; 
	}
	while(Use() != 6)
	{
		
	}
	printf("������ɣ�");
}
