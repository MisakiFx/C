#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
//�ṹ�壺�ṹ��һ�ֽṹ�������ͣ���������������϶���
//�ṹ���岻Ԥ���ڴ�
//�ṹ������ڿ�ͷ����
//�ṹ��������������ṹ����ʽ��ʹ�ýṹ��Ҫ�����ṹ�ı��� 
/*
	struct Name
	{
		//�ṹ��Ա
		Data Type var1
		Data Type var2
		//����
	}
*/
struct Hero//�൱���ٴ�������һ���������ͣ����������� 
{
	int id;
	char name[50];//Ӣ�۵����� 
	char skill[50];//Ӣ�۵ļ��� 
	int hp;//Ӣ�۵�Ѫ��
	int mp;//Ӣ�۵�ħ��ֵ
	int level;//Ӣ�۵ĵȼ� 	
}; 
struct Hero1//�൱���ٴ�������һ���������ͣ����������� 
{
	int id;
	char *name;//Ӣ�۵����� 
	char *skill;//Ӣ�۵ļ��� 
	int hp;//Ӣ�۵�Ѫ��
	int mp;//Ӣ�۵�ħ��ֵ
	int level;//Ӣ�۵ĵȼ�
};
/*
	struct Hero//ֱ������ �ṹ��������ʱ��HeroҲ����ʡ�ԣ� 
	{
		char * name;
		char * job;
		char * skill;
		int level; 
	}laola,jackieChen,Misaki;
*/
int main()
{
	struct Hero hero1={2,"����","����",1000,.mp=200};//����ʹ������������ķ�ʽ��ֵ,Ҳ�����ڸ�ֵ�ǶԶ�Ӧ���ѡ�ֵ�������һ����
	//���ǲ����Զ�ͬһ���ṹ������������ϵ��������鷽ʽ��ֵ 
	hero1.level=10; //���ǿ�������һ��һ����������ֵ�ķ�ʽ����һ��һ��ֵ
	/* 
	hero1.id=1;
	strcpy(hero1.name,"Misaki");//���ַ�����ֵҪ���ַ������Ƶķ�ʽ�������������ַ�ָ������Խ��ַ���ֱ�Ӹ�ֵ��ָ�룩 
	hero1.hp=500;
	hero1.mp=100;
	hero1.level=5;
	strcpy(hero1.skill,"����");//Ҳ����ʹ��һ��һ�����и�ֵ 
	*/
	printf("%d\t%s\t%d\t%d\t%d\t%s\n",hero1.id,hero1.name,hero1.level,hero1.hp,hero1.mp,hero1.skill);
	struct Hero1 hero2;
	hero2.name="��������";
	printf("������Ӣ�۵����ƣ�");
	hero2.name=(char*)malloc(sizeof(char)*20); //��ָ�붯̬��ֵ
	scanf("%s",hero2.name);//��Ҫ��ָ�붯̬��ֵ��Ҫ��ָ��һ���ռ� 
	printf("%s",hero2.name);
	 
}
