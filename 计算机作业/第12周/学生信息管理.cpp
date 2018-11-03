#include <stdio.h>
#include <stdlib.h>
typedef struct _data
{
	char num[20];//学号 
	char name[20];//姓名 
	double mathScore;//数学分数 
	double physicsScore;//物理分数 
	double CScore;//C分数 
}Data;
typedef struct _stu
{
	Data data;//数据区 
	struct _stu* next;//地址区 
}Student;
Student* g_head = NULL;
void AddHead()
{
	Student* p = (Student*)malloc(sizeof(Student));
	printf("请输入当前学生学号：");
	scanf("%s",p->data.num);
	printf("请输入当前学生姓名：");
	scanf("%s",p->data.name);
	printf("请输入当前学生数学分数：");
	scanf("%lf",&p->data.mathScore); 
	printf("请输入当前学生物理分数：");
	scanf("%lf",&p->data.physicsScore); 
	printf("请输入当前学生C语言分数：");
	scanf("%lf",&p->data.CScore); 
	p->next = g_head;
	g_head = p;
}
void AddTail()
{
	Student* p = (Student*)malloc(sizeof(Student));
	printf("请输入当前学生学号：");
	scanf("%s",p->data.num);
	printf("请输入当前学生姓名：");
	scanf("%s",p->data.name);
	printf("请输入当前学生数学分数：");
	scanf("%lf",&p->data.mathScore); 
	printf("请输入当前学生物理分数：");
	scanf("%lf",&p->data.physicsScore); 
	printf("请输入当前学生C语言分数：");
	scanf("%lf",&p->data.CScore); 
	if(g_head == NULL)
	{
		g_head = p;
		p->next = NULL;
	}
	else
	{
		Student* t = g_head;
		while(t->next != NULL)
		{
			t = t->next;
		}
		t->next = p;
		p->next = NULL;
	}
}
void Print()
{
	Student* p = g_head;
	printf("%10s%10s%15s%15s%15s\n","学号","姓名","数学分数","物理分数","C语言分数");
	while(p != NULL)
	{
		printf("%10s%10s%15.2lf%15.2lf%15.2lf\n",p->data.num,p->data.name,p->data.mathScore,p->data.physicsScore,p->data.CScore);
		p = p->next;
	}
}
int Menu()
{
	int choose;
	printf("1、从头部添加\n");
	printf("2、从尾部添加\n");
	printf("3、打印当前学生信息\n");
	printf("0、退出\n");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			AddHead();
			break;
		case 2:
			AddTail();
			break;
		case 3:
			Print();
			break;
		default:
			break;
	}
	return choose;
}
int main()
{
	while(Menu())
	{
		
	}
}
