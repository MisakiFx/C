#include <stdio.h>
#include <stdlib.h>
typedef struct _stu_1
{
	char num[20];
	char name[50];
	double score1;
	double score2;
	double score3;
	double ave;
}Student;
int main()
{
	int n;
	int max = 0;
	printf("������ѧ������:");
	scanf("%d",&n);
	Student **p = (Student**)malloc(sizeof(Student*) * n);
	for(int i = 0; i < n; i++)
	{
		p[i] = (Student*)malloc(sizeof(Student));
	}
	for(int i = 0; i < n; i++)
	{
		printf("�������%d��ѧ����ѧ��:",i + 1);
		scanf("%s",p[i]->num);
		printf("�������%d��ѧ��������:",i + 1);
		scanf("%s",p[i]->name);
		printf("�������%d��ѧ���ĵ�һ�ſγɼ�:",i + 1);
		scanf("%lf",&p[i]->score1);	
		printf("�������%d��ѧ���ĵڶ��ſγɼ�:",i + 1);
		scanf("%lf",&p[i]->score2);	
		printf("�������%d��ѧ���ĵ����ſγɼ�:",i + 1);
		scanf("%lf",&p[i]->score3);	
	}
	for(int i = 0; i < n; i++)
	{
		p[i]->ave = (p[i]->score1 + p[i]->score2 + p[i]->score3) / 3;
	}
	for(int i = 1; i < n; i++)
	{
		if(p[i]->ave > p[max]->ave)
		{
			max = i;
		}
	}
	printf("ƽ������ߵ�ѧ����ϢΪ:\n");
	printf("%10s%10s%10s%10s%10s%10s\n","ѧ��","����","�ɼ�1","�ɼ�2","�ɼ�3","ƽ����");
	printf("%10s%10s%10.2lf%10.2lf%10.2lf%10.2lf\n",p[max]->num,p[max]->name,p[max]->score1,p[max]->score2,p[max]->score3,p[max]->ave);
}
