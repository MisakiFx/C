#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/**********************************
*�ļ�����Game.h
*��    ����������Ϸ�ĺ��Ľṹ���ļ�
*�����ˣ�Misaki
*��    �ڣ�2018.1.11
*��    ����0.1
*�ٷ�QQ��1761607418
**********************************/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
/****************��Ϸ�ṹ****************/
//��ҡ���ͼ��װ��������
/*��Ϸ��ͼ�ṹ ��Ϸ��ͼ
    ��š����ơ����ܡ���ҵĽ���ȼ�*/
    typedef struct _map
    {
        int id;         //��ͼ���
        char name[50];//��ͼ����
        int minLevel;//��ҽ������͵ȼ�
        //����ṹ
        COORD coord;//��ͼ�����ֻ꣨���������ԣ�һ��X��һ��Y��
        char desc[200];//��ͼ����
    }Map;
/*��Ϸ��������ö��:���������ߡ�����Ʒ����Ƭ����Ƭ*/
typedef enum _peoptype//ö�ٲ����Ƕ�����һ�ѳ�����Ĭ��ֵ����ǰ��һ������ֵ�ĳ���������μ�һ
{
    Weapon,Armor,Con,card,Frag
}PropType;
/*��Ϸ���ߣ����������ߡ�����Ʒ����Ƭ*/
typedef struct _prop
{
    int id;                      //���߱��
    char name[50];      //��������
    int  level;                 //���ߵļ���
    int stock;                 //���ߵĿ��򱳰��д�ĵ�������
    double price;         //���ߵĵ���
    PropType type;      //���ߵ�����
    union{//����-��ѡ1
        int minAttack;//����������Ͷ�Ӧ������
        int minDefence;//����Ƿ��߾Ͷ�Ӧ������
        int minPower;//�����Ѫƿ������Ʒ�Ͷ�Ӧ���ӵ�����ֵ
    };
    union{//����-��ѡ1
        int maxAttack;//����������Ͷ�Ӧ������
        int maxDefence;//����Ƿ��߾Ͷ�Ӧ������
        int maxPower;//�����Ѫƿ������Ʒ�Ͷ�Ӧ���ӵ�����ֵ
    };
    char desc[200];//���ߵ�����
} Prop;
/*���ɽṹ*/
typedef struct _martial
{
    int id;
    char name[50];//��������
    char type[50];//��������
    COORD coord;//�����ܶ�
    int isOpen;//�����Ƿ񿪷�
    char desc[1000];//��������
}Martial;
typedef struct _player
{
    int id;
    char name[50];
    char pass[50];
    int life;//��ҵ�����
    int level;//��ҵļ���
    int exp;//��ҵľ���ֵ
    int hp;//��ҵ�Ѫ��
    int mp;//��ҵķ���ֵ
    int mpMax;//��ǰ������ҵ��������ֵ
    int gold;//��ҵĽ������
    COORD coord;//��ҵ�ǰ���ڵ�ͼ������
    Prop weapon;//���װ��������
    Prop armon;//��ҵķ���
    Martial martial;//��ҵ�����
    //��ҵı���
}Player;
typedef struct _monster
{
    int id;
    char name[50];
    int level;//����ļ���
    int hp;//���������ֵ
    int att;//����Ĺ�����
    int diff;//����ķ�����
    int minMoney;//ɱ�������������С���
    int maxMoney;
    int exp;//ɱ���������Һ�ĵľ���ֵ
    //��չ��ɱ���������ҿ��Ի�õĵ����б�
    int state;//0��ʾ������������0��ʾ�������
    COORD coord;//���������
}Monster;
void Init();//��ʼ����Ϸ����
void Show();//��ʾȫ������
/*��ʾ��Ϸ�Ļ�ӭ��Ϣ*/
void ShowWelcome();
/*��ʾ��Ϸ��ͼ*/
void ShowMap();
/*��ʾ��ͼ��ͬʱ��ʾ��ͼ����Ϣ*/
void ShowMapInfo();
/*��ʾ��Ϸ��ͼ�·��ĵ�ͼ��Ϣ*/
void ShowInformation();
/*��ʾ��Ϸ�����˵�*/
void ShowMainMenu();
/*������Ϸ���˵�*/
void ProcessMainMenu(char key);
/*�ڽ�����ʾ��ҵĸ�������*/
void SHowPlayerInfo();
/*����Ϣ������ʾ��ǰ��ͼ�Ĺ���*/
void ShowMonsters();
/*pk����*/
void Fight(Monster *monster);
/*˲���ƶ�*/
void Move(int a,int b);
int z;
#endif // GAME_H_INCLUDED

