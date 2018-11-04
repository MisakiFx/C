#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
//结构体：结构是一种结构数据类型，由若干数据项组合而成
//结构定义不预留内存
//结构定义放在开头部分
//结构定义近用来描述结构的形式，使用结构需要声明结构的变量 
/*
	struct Name
	{
		//结构成员
		Data Type var1
		Data Type var2
		//……
	}
*/
struct Hero//相当于再次声明了一个变量类型，类似于数组 
{
	int id;
	char name[50];//英雄的名称 
	char skill[50];//英雄的技能 
	int hp;//英雄的血量
	int mp;//英雄的魔法值
	int level;//英雄的等级 	
}; 
struct Hero1//相当于再次声明了一个变量类型，类似于数组 
{
	int id;
	char *name;//英雄的名称 
	char *skill;//英雄的技能 
	int hp;//英雄的血量
	int mp;//英雄的魔法值
	int level;//英雄的等级
};
/*
	struct Hero//直接声明 结构变量（此时的Hero也可以省略） 
	{
		char * name;
		char * job;
		char * skill;
		int level; 
	}laola,jackieChen,Misaki;
*/
int main()
{
	struct Hero hero1={2,"鸡酱","卖萌",1000,.mp=200};//可以使用类似于数组的方式赋值,也可以在赋值是对对应打的选项赋值（如最后一个）
	//但是不可以对同一个结构体进行两次以上的利用数组方式赋值 
	hero1.level=10; //但是可以在用一个一个拉出来赋值的方式进行一对一赋值
	/* 
	hero1.id=1;
	strcpy(hero1.name,"Misaki");//给字符串赋值要用字符串复制的方式（如果定义的是字符指针则可以将字符串直接赋值给指针） 
	hero1.hp=500;
	hero1.mp=100;
	hero1.level=5;
	strcpy(hero1.skill,"卖萌");//也可以使用一个一个进行赋值 
	*/
	printf("%d\t%s\t%d\t%d\t%d\t%s\n",hero1.id,hero1.name,hero1.level,hero1.hp,hero1.mp,hero1.skill);
	struct Hero1 hero2;
	hero2.name="北方军姬";
	printf("请输入英雄的名称：");
	hero2.name=(char*)malloc(sizeof(char)*20); //给指针动态赋值
	scanf("%s",hero2.name);//想要给指针动态赋值需要给指针一个空间 
	printf("%s",hero2.name);
	 
}
