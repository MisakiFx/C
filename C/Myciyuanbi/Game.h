#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/**********************************
*文件名：Game.h
*描    述：定义游戏的核心结构和文件
*创建人：Misaki
*日    期：2018.1.11
*版    本：0.1
*官方QQ：1761607418
**********************************/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
/****************游戏结构****************/
//玩家、地图、装备、怪物
/*游戏地图结构 游戏地图
    编号、名称、介绍、玩家的进入等级*/
    typedef struct _map
    {
        int id;         //地图编号
        char name[50];//地图名称
        int minLevel;//玩家进入的最低等级
        //坐标结构
        COORD coord;//地图的坐标（只有两个属性，一个X，一个Y）
        char desc[200];//地图介绍
    }Map;
/*游戏道具类型枚举:武器、道具、消耗品、卡片、碎片*/
typedef enum _peoptype//枚举不过是定义了一堆常量：默认值从最前面一个附了值的常量向后依次加一
{
    Weapon,Armor,Con,card,Frag
}PropType;
/*游戏道具：武器；防具、消耗品、卡片*/
typedef struct _prop
{
    int id;                      //道具编号
    char name[50];      //道具名称
    int  level;                 //道具的级别
    int stock;                 //道具的库存或背包中打的叠加数量
    double price;         //道具的单价
    PropType type;      //道具的类型
    union{//联合-多选1
        int minAttack;//如果是武器就对应攻击力
        int minDefence;//如果是防具就对应防御力
        int minPower;//如果是血瓶等消耗品就对应增加的能量值
    };
    union{//联合-多选1
        int maxAttack;//如果是武器就对应攻击力
        int maxDefence;//如果是防具就对应防御力
        int maxPower;//如果是血瓶等消耗品就对应增加的能量值
    };
    char desc[200];//道具的描述
} Prop;
/*门派结构*/
typedef struct _martial
{
    int id;
    char name[50];//门派名称
    char type[50];//门派类型
    COORD coord;//门派总舵
    int isOpen;//门派是否开放
    char desc[1000];//门派描述
}Martial;
typedef struct _player
{
    int id;
    char name[50];
    char pass[50];
    int life;//玩家的生命
    int level;//玩家的级别
    int exp;//玩家的经验值
    int hp;//玩家的血量
    int mp;//玩家的法力值
    int mpMax;//当前级别玩家的最大内力值
    int gold;//玩家的金币数量
    COORD coord;//玩家当前所在地图的坐标
    Prop weapon;//玩家装备的武器
    Prop armon;//玩家的防具
    Martial martial;//玩家的门派
    //玩家的背包
}Player;
typedef struct _monster
{
    int id;
    char name[50];
    int level;//怪物的级别
    int hp;//怪物的生命值
    int att;//怪物的攻击力
    int diff;//怪物的防御力
    int minMoney;//杀死怪物后掉落的最小金币
    int maxMoney;
    int exp;//杀死怪物后玩家后的的经验值
    //扩展：杀死怪物后玩家可以获得的道具列表
    int state;//0表示怪物已死，非0表示怪物活着
    COORD coord;//怪物的坐标
}Monster;
void Init();//初始化游戏数据
void Show();//显示全局数据
/*显示游戏的欢迎信息*/
void ShowWelcome();
/*显示游戏地图*/
void ShowMap();
/*显示地图是同时显示地图的信息*/
void ShowMapInfo();
/*显示游戏地图下方的地图信息*/
void ShowInformation();
/*显示游戏的主菜单*/
void ShowMainMenu();
/*处理游戏主菜单*/
void ProcessMainMenu(char key);
/*在界面显示玩家的个人资料*/
void SHowPlayerInfo();
/*在信息界面显示当前地图的怪物*/
void ShowMonsters();
/*pk函数*/
void Fight(Monster *monster);
/*瞬间移动*/
void Move(int a,int b);
int z;
#endif // GAME_H_INCLUDED

