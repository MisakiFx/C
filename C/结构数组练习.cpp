#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct _mytime
{
	int year;
	int month;
	int day;
}Mytime;
typedef struct _hero
{
	char *name;
	char sex;
	char *job;
	int hp;
	int speed;
	char *abillity;
	Mytime pubtime;	
}Hero;
Hero heros[100]={//�����������Ҳ�ǽṹ���ָ�� 
	{"Misaki",'fm',"ѧ��",1000,0.644,"üͷһ��",{2017,12,26}}
};
void ShowAvg(); 
void Show();
void Input();
int count=1;//��ǰ��Ӣ������ (ȫ�ֱ��������������ж������ã� 
int main()
{
	Show();
	Input();
	Show();
	ShowAvg(); 
	
}
void Show()
{
	printf("\n");
	for(int i=0;i<count;i++)
	{
		printf("%s\t%s\t%d\n",heros[i].name,heros[i].job,heros[i].pubtime.day);
	}
}
void Input()
{
	char answer='y';
	do{
		if(count==100)
		{
			printf("Ӣ�۵���λ������");
			break;
		} 
		printf("��ǰ¼���%dλӢ�۵���Ϣ��\n",count+1);
		printf("Ӣ�����ƣ�");
		heros[count].name=(char*)malloc(50);
		scanf("%s",heros[count].name);
		printf("�Ա�");
		fflush(stdin);
		heros[count].sex=getchar();
		fflush(stdin);
		printf("ְҵ��");
		heros[count].job=(char*)malloc(50);
		scanf("%s",heros[count].job);
		heros[count].hp=1000;
		heros[count].speed=0.644;
		heros[count].abillity=(char*)malloc(50);
		heros[count].abillity="�������";
		heros[count].pubtime.day=27; 
		printf("�Ƿ����¼�룿(y/n)\n");
		count++;
		answer=getch();//��getchar��ȣ��û����¼������������������䣬���������û��ûس��� 
	}while(answer=='Y'||answer=='y');
}
void ShowAvg()
{
	int hpsum=0;
	double avg;
	for(int i=0;i<count;i++)
	{
		hpsum+=(heros+i)->hp;
	}
	avg=hpsum*1.0/count;
	printf("����ֵ��ƽ��ֵ�ǣ�%.2lf",avg);
}
