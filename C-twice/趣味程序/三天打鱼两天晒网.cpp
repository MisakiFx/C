#include <stdio.h>
/*�й��о������"�����������ɹ��"��ĳ�˴� 1990 �� 1 �� 1 ����ʼ"�����������ɹ ��"��
����������Ժ��ĳһ��������"����"������"ɹ��" */
typedef struct _date
{
	int year;
	int month;
	int day;
}date; 
int Days(date term)//������һ������� 
{
	int day_tab[][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30},//ƽ�� 
	{0,31,29,31,30,31,30,31,31,30,31,30},//���� 
	};
	int lp;
	lp = term.year % 4 == 0 && term.year % 100 != 0 || term.year % 400 == 0;
	for(int i = 1; i < term.month; i++)
	{
		term.day += day_tab[lp][i];
	}
	return term.day;
}
int main()
{
	date today, term;
	int yearday = 0, year, day;
	printf("�����뵱ǰ�����գ�");
	scanf("%d%d%d",&today.year, &today.month, &today.day);
	term.month = 12;
	term.day = 31;
	/*���㵽��ǰ��ݵ�ǰһ�������*/
	for(year = 1990; year < today.year; year++)
	{
		term.year = year;
		yearday += Days(term);
	}
	yearday += Days(today);
	day = year % 5;
	printf((day > 0 && day < 4)?"���ڴ��棡\n":"����ɹ����\n");
}
