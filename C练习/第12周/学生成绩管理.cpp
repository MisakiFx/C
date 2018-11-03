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
	printf("请输入学生总数:");
	scanf("%d",&n);
	Student **p = (Student**)malloc(sizeof(Student*) * n);
	for(int i = 0; i < n; i++)
	{
		p[i] = (Student*)malloc(sizeof(Student));
	}
	for(int i = 0; i < n; i++)
	{
		printf("请输入第%d个学生的学号:",i + 1);
		scanf("%s",p[i]->num);
		printf("请输入第%d个学生的姓名:",i + 1);
		scanf("%s",p[i]->name);
		printf("请输入第%d个学生的第一门课成绩:",i + 1);
		scanf("%lf",&p[i]->score1);	
		printf("请输入第%d个学生的第二门课成绩:",i + 1);
		scanf("%lf",&p[i]->score2);	
		printf("请输入第%d个学生的第三门课成绩:",i + 1);
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
	printf("平均分最高的学生信息为:\n");
	printf("%10s%10s%10s%10s%10s%10s\n","学号","姓名","成绩1","成绩2","成绩3","平均分");
	printf("%10s%10s%10.2lf%10.2lf%10.2lf%10.2lf\n",p[max]->num,p[max]->name,p[max]->score1,p[max]->score2,p[max]->score3,p[max]->ave);
}
