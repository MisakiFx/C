#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
//��������ṹ���ͣ�������Ҫ��ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
//��ͷ�ļ��ﶨ��ṹ��
//�ṹ�壺Ӣ�ۡ�ְҵ��������ʱ��
typedef struct _job//typedef�÷�����define��ר�������������͵ģ��궨�����ͣ�
{
    int id;
    char *name;//ְҵ����
    char *desc;//����
}Job;//������Ǻ궨���������
typedef struct _abillity
{
    int id;
    char *name;//��������
    char *intro;//����˵��
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
    char *name;//����
    char sex;
    Job job;//�򻯽ṹ���ʹ��
    double hp;//����ֵ
    double speed;//�����ٶ�
    Abillity abillity;//��������������ʹ�������ʾ�������������
    PubTime pubtime;//����ʱ��
}Hero;
void InputHero();//��������Ӣ�۵���Ϣ
void ShowHero();//�������Ӣ�۵���Ϣ

#endif // HERO_H_INCLUDED
