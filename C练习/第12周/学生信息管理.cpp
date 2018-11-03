#include <stdio.h>
#include <stdlib.h>
typedef struct _data
{
	char num[20];//ѧ�� 
	char name[20];//���� 
	double mathScore;//��ѧ���� 
	double physicsScore;//������� 
	double CScore;//C���� 
}Data;
typedef struct _stu
{
	Data data;//������ 
	struct _stu* next;//��ַ�� 
}Student;
Student* g_head = NULL;
void AddHead()
{
	Student* p = (Student*)malloc(sizeof(Student));
	printf("�����뵱ǰѧ��ѧ�ţ�");
	scanf("%s",p->data.num);
	printf("�����뵱ǰѧ��������");
	scanf("%s",p->data.name);
	printf("�����뵱ǰѧ����ѧ������");
	scanf("%lf",&p->data.mathScore); 
	printf("�����뵱ǰѧ�����������");
	scanf("%lf",&p->data.physicsScore); 
	printf("�����뵱ǰѧ��C���Է�����");
	scanf("%lf",&p->data.CScore); 
	p->next = g_head;
	g_head = p;
}
void AddTail()
{
	Student* p = (Student*)malloc(sizeof(Student));
	printf("�����뵱ǰѧ��ѧ�ţ�");
	scanf("%s",p->data.num);
	printf("�����뵱ǰѧ��������");
	scanf("%s",p->data.name);
	printf("�����뵱ǰѧ����ѧ������");
	scanf("%lf",&p->data.mathScore); 
	printf("�����뵱ǰѧ�����������");
	scanf("%lf",&p->data.physicsScore); 
	printf("�����뵱ǰѧ��C���Է�����");
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
	printf("%10s%10s%15s%15s%15s\n","ѧ��","����","��ѧ����","�������","C���Է���");
	while(p != NULL)
	{
		printf("%10s%10s%15.2lf%15.2lf%15.2lf\n",p->data.num,p->data.name,p->data.mathScore,p->data.physicsScore,p->data.CScore);
		p = p->next;
	}
}
int Menu()
{
	int choose;
	printf("1����ͷ�����\n");
	printf("2����β�����\n");
	printf("3����ӡ��ǰѧ����Ϣ\n");
	printf("0���˳�\n");
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
