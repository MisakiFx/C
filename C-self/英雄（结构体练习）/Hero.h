#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
//用来定义结构类型，声明需要的头文件
#include <stdio.h>
#include <stdlib.h>
//在头文件里定义结构体
//结构体：英雄、职业、能力、时间
typedef struct _job//typedef用法很像define是专门用来定义类型的（宏定义类型）
{
    int id;
    char *name;//职业名称
    char *desc;//描述
}Job;//这个才是宏定义的类型名
typedef struct _abillity
{
    int id;
    char *name;//能力名称
    char *intro;//能力说明
}Abillity;
typedef struct _pubtime
{
    int year;
    int month;
    int day;
}PubTime;
typedef struct _hero
{
    int id;
    char *name;//名称
    char sex;
    Job job;//简化结构体的使用
    double hp;//生命值
    double speed;//攻击速度
    Abillity abillity;//特殊能力（可以使用数组表示多个特殊能力）
    PubTime pubtime;//上线时间
}Hero;
void InputHero();//用来输入英雄的信息
void ShowHero();//用来输出英雄的信息

#endif // HERO_H_INCLUDED
