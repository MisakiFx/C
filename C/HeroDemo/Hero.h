#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
typedef struct _mytime
{
    int year;
    int month;
    int day;
}Mytime;
typedef struct _hero
{
    char name[50];//英雄名称
    char sex;//英雄性别
    char job[20];//英雄职业
    int hp;//英雄生命值
    double speed;//攻击速度
    char abillity[20];//英雄特殊能力
    Mytime pubtime;//上线时间
}Hero;
void Show();//显示英雄的详细信息
#endif // HERO_H_INCLUDED
