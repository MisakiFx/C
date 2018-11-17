#include <stdio.h>
/*中国有句俗语叫"三天打鱼两天晒网"。某人从 1990 年 1 月 1 日起开始"三天打鱼两天晒 网"，
问这个人在以后的某一天中是在"打鱼"还是在"晒网" */
typedef struct _date
{
	int year;
	int month;
	int day;
}date; 
int Days(date term)//计算这一年的天数 
{
	int day_tab[][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30},//平年 
	{0,31,29,31,30,31,30,31,31,30,31,30},//闰年 
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
	printf("请输入当前年月日：");
	scanf("%d%d%d",&today.year, &today.month, &today.day);
	term.month = 12;
	term.day = 31;
	/*计算到当前年份的前一年的天数*/
	for(year = 1990; year < today.year; year++)
	{
		term.year = year;
		yearday += Days(term);
	}
	yearday += Days(today);
	day = year % 5;
	printf((day > 0 && day < 4)?"他在打渔！\n":"他在晒网！\n");
}
