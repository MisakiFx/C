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
Hero heros[100]={//这里的数组名也是结构体的指针 
	{"Misaki",'fm',"学生",1000,0.644,"眉头一皱",{2017,12,26}}
};
void ShowAvg(); 
void Show();
void Input();
int count=1;//当前的英雄总数 (全局变量，整个代码中都起作用） 
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
			printf("英雄的栏位已满！");
			break;
		} 
		printf("当前录入第%d位英雄的信息：\n",count+1);
		printf("英雄名称：");
		heros[count].name=(char*)malloc(50);
		scanf("%s",heros[count].name);
		printf("性别：");
		fflush(stdin);
		heros[count].sex=getchar();
		fflush(stdin);
		printf("职业：");
		heros[count].job=(char*)malloc(50);
		scanf("%s",heros[count].job);
		heros[count].hp=1000;
		heros[count].speed=0.644;
		heros[count].abillity=(char*)malloc(50);
		heros[count].abillity="上天入地";
		heros[count].pubtime.day=27; 
		printf("是否继续录入？(y/n)\n");
		count++;
		answer=getch();//与getchar相比：用户按下键后就立即触发下面语句，不会再让用户敲回车了 
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
	printf("生命值的平均值是：%.2lf",avg);
}
