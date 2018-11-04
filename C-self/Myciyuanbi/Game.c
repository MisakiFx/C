#include "Game.h"
#include "GameLib.h"
#define SEP "-------------------------------------------------------------------------------"
#define COL 78            //游戏界面总宽度
#define MARGIN_X 20//左边距
#define MAP_START_Y 3
#define MAP_END_Y 11
#define INFO_START_Y 12
#define INFO_END_Y 19
#define MAINMENU_START_Y 20
int x=0,y=0;//假设当前的用户的坐标是3，2
Martial martials[]={
    {1,"短发萌妹最可爱","官方唯一制定名门正派",{6,0},1,"官方唯一指定名门正派，不接受任何反驳，短发妹子最可爱"}
};
Player players[]={
    {9527,"Misaki","Misaki",500,1,1,500,800,1000,1000,.coord.X=0,.coord.Y=0},
    {9528,"栗山未来","没有未来的未来不是我想要的未来",1000,1,1,1000,500,500,1000,.coord.X=0,.coord.Y=0},
};
Monster monsterArray[]={
    {1,"北方战姬",1,100,5,3,5,10,5,1,{0,0}},
    {2,"屎莱姆",1,150,3,2,5,10,5,1,{0,0}},
    {3,"水鬼",2,200,8,5,9,15,8,1,{0,0}},
    {4,"狮鹫兽",2,250,10,7,10,20,12,1,{0,0}},
    {5,"抱脸虫",3,100,15,2,8,15,8,1,{0,0}},
    {6,"铁三角",4,350,15,10,20,50,20,1,{0,0}},
    {7,"程序员君",100,1000000,100000,1000000,0,0,0,1,{0,0}},
    {8,"北方战姬",1,100,5,3,5,10,5,1,{1,0}},
};
Prop propArray[]={
    {1,"咖喱棒",1,5,5000,Weapon,.minAttack=1,.maxAttack=8,"超大咖喱棒你值得拥有"},
    {2,"木盾",2,5,5000,Armor,.minDefence=2,.maxDefence=10,"破烂的新手盾"},
    {3,"初级回血药",3,5,1000,Con,.minPower=50,.maxPower=100,"能补充少量血量"},
};
Map mapArray[8][8]={//X，Y，公认地图坐标
    {{1,"灵剑山",1,{0,0},"这里有座灵剑山！"},{2,"镇魂街",1,{1,0},"这是属于我的镇魂街"},
    {3,"灵域",1,{2,0},"精灵之所1111111111111111111111111111111111111111111111111111"},{4,"回音谷",4,{3,0},"这里有座灵剑山！"},
    {5,"仙境",1,{4,0},"这里有座灵剑山！"},{6,"遗落之地",1,{5,0},"这里有座灵剑山！"},
    {7,"神圣之地",1,{6,0},"这里有座灵剑山！"},{8,"母之山",1,{7,0},"这里有座灵剑山！"}},

    {{1,"地平线城",1,{0,1},"这里有座灵剑山！"},{1,"机械迷域",1,{1,1},"这里有座灵剑山！"},
    {1,"镜底世界",1,{2,1},"这里有座灵剑山！"},{1,"暗黑丛林",1,{3,1},"这里有座灵剑山！"},
    {1,"阿斯山脉",1,{4,1},"这里有座灵剑山！"},{1,"精灵岛",1,{5,1},"这里有座灵剑山！"},
    {1,"普拉卡",1,{6,1},"这里有座灵剑山！"},{1,"隐之都",1,{7,1},"这里有座灵剑山！"}},

    {{1,"高谭市",1,{0,2},"这里有座灵剑山！"},{1,"失落之城",1,{1,2},"这里有座灵剑山！"},
    {1,"居民区",1,{2,2},"这里有座灵剑山！"},{1,"无名之所",1,{3,2},"这里有座灵剑山！"},
    {1,"回音谷",1,{4,2},"这里有座灵剑山！"},{1,"阿卡斯山",1,{5,2},"这里有座灵剑山！"},
    {1,"海岸线",1,{6,2},"这里有座灵剑山！"},{1,"运河",1,{7,2},"这里有座灵剑山！"}},

    {{1,"东方之地",1,{0,3},"这里有座灵剑山！"},{1,"蘑菇岛",1,{1,3},"这里有座灵剑山！"},
    {1,"噩梦墓地",1,{2,3},"这里有座灵剑山！"},{1,"宫崎中学",1,{3,3},"这里有座灵剑山！"},
    {1,"无主之地",1,{4,3},"这里有座灵剑山！"},{1,"普拉斯",1,{5,3},"这里有座灵剑山！"},
    {1,"加里马",1,{6,3},"这里有座灵剑山！"},{1,"阿喀托斯",1,{7,3},"这里有座灵剑山！"}},

    {{1,"无尽之原",1,{0,4},"这里有座灵剑山！"},{1,"荒芜之所",1,{1,4},"这里有座灵剑山！"},
    {1,"拉克一",1,{2,4},"这里有座灵剑山！"},{1,"火焰山",1,{3,4},"这里有座灵剑山！"},
    {1,"母仪之像",1,{4,4},"这里有座灵剑山！"},{1,"水灵湖",1,{5,4},"这里有座灵剑山！"},
    {1,"传音谷",1,{6,4},"这里有座灵剑山！"},{1,"明净草原",1,{7,4},"这里有座灵剑山！"}},

    {{1,"杀戮都市",1,{0,5},"这里有座灵剑山！"},{1,"鬼城",1,{1,5},"这里有座灵剑山！"},
    {1,"寂静岭",1,{2,5},"这里有座灵剑山！"},{1,"第一中学",1,{3,5},"这里有座灵剑山！"},
    {1,"摩天大楼",1,{4,5},"这里有座灵剑山！"},{1,"咖啡馆",1,{5,5},"这里有座灵剑山！"},
    {1,"庙宇",1,{6,5},"这里有座灵剑山！"},{1,"俱乐部",1,{7,5},"这里有座灵剑山！"}},

    {{1,"瞭望塔",1,{0,6},"这里有座灵剑山！"},{1,"前哨站",1,{1,6},"这里有座灵剑山！"},
    {1,"还原站",1,{2,6},"这里有座灵剑山！"},{1,"公司大楼",1,{3,6},"这里有座灵剑山！"},
    {1,"M集团",1,{4,6},"这里有座灵剑山！"},{1,"控制中心",1,{5,6},"这里有座灵剑山！"},
    {1,"虚无空间",1,{6,6},"这里有座灵剑山！"},{1,"飘渺空间",1,{7,6},"这里有座灵剑山！"}},

    {{1,"璀璨空间",1,{0,7},"这里有座灵剑山！"},{1,"塔楼",1,{1,7},"这里有座灵剑山！"},
    {1,"平民窟",1,{2,7},"这里有座灵剑山！"},{1,"工作室",1,{3,7},"这里有座灵剑山！"},
    {1,"制造基地",1,{4,7},"这里有座灵剑山！"},{1,"世界末端",1,{5,7},"这里有座灵剑山！"},
    {1,"人工瀑布",1,{6,7},"这里有座灵剑山！"},{1,"世界尽头",1,{7,7},"这里有座灵剑山！"}}
};
Player *currPlayer;
void Init()//初始化玩家数据
{
    //设置当前登陆玩家默认为玩家1
    currPlayer=&players[0];
    currPlayer->weapon=propArray[0];
    currPlayer->armon=propArray[1];
    currPlayer->martial=martials[0];
}
/*显示游戏的欢迎信息*/
void ShowWelcome()
{
    SetPosition(MARGIN_X,0);
    printf("%-s",SEP);
    SetPosition(MARGIN_X,1);
    printf("|");
    SetPosition(MARGIN_X+30,1);
    printf("这里是次元壁的彼端");
    SetPosition(MARGIN_X+78,1);
    printf("|");
    SetPosition(MARGIN_X,2);
    printf("%s\n",SEP);
}
/*显示游戏地图*/
void ShowMap()
{
    //根据玩家当前坐标显示文字
    int i,j;
    for (i=0;i<8;i++)
    {
        SetPosition(MARGIN_X,i+MAP_START_Y);
        for (j=0;j<8;j++)
        {
            if (j==0)
            {
                printf("|   ");
            }
            if (i == y&&j==x)
            {
                //更改地图文字的颜色和背景色
                SetColor(0,13);
            }
            printf("%-9s",mapArray[i][j].name);
            SetColor(0,15);
        }
        printf("  |");
    }
    SetPosition(MARGIN_X,MAP_END_Y);
    printf("%s",SEP);
    ShowMapInfo();
}
/*显示地图信息函数*/
void ShowMapInfo()
{
    //1、清除信息框的信息
    Clean(MARGIN_X+1,INFO_START_Y,7);
    //2、显示玩家当前所在区域的地图信息
    SetPosition(MARGIN_X+25,INFO_START_Y);
    printf("当前玩家所在地图：《%s》",mapArray[y][x].name);
    SetPosition(MARGIN_X+10,INFO_START_Y+1);
    //需要控制文字显示的行
    char *desc=mapArray[y][x].desc;
    int descLen=strlen(desc);
    int i;
    for(i=0;i<descLen;i++)
    {
        if(i!=0&&i%60==0)
        {
            SetPosition(MARGIN_X+10,INFO_START_Y+1+i/60);
        }
        printf("%c",*(desc+i));
    }
    //printf("%s",mapArray[y][x].desc);
}
/*显示游戏地图下方的地图信息*/
void ShowInformation()
{
    //信息窗口一共有7行
    SetPosition(MARGIN_X,INFO_START_Y);
    int i;
    for(i=0;i<7;i++)
    {
        SetPosition(MARGIN_X,INFO_START_Y+i);
        printf("|");
        SetPosition(MARGIN_X+78,INFO_START_Y+i);
        printf("|");
    }
    SetPosition(MARGIN_X,INFO_START_Y+i);
    printf("%s",SEP);
}
/*显示游戏的主菜单*/
void ShowMainMenu()
{
    SetPosition(MARGIN_X,MAINMENU_START_Y);
    printf("游戏菜单：");
    SetPosition(MARGIN_X,MAINMENU_START_Y+1);
    printf("1、个人资料");
    SetPosition(MARGIN_X,MAINMENU_START_Y+2);
    printf("2、查找怪物");
    SetPosition(MARGIN_X,MAINMENU_START_Y+3);
    printf("3、回基地");
    SetPosition(MARGIN_X,MAINMENU_START_Y+4);
    printf("4、购买装备");
}
/*处理菜单函数*/
void ProcessMainMenu(char key)
{
    switch(key)
    {
    case '1':
        //个人信息
        SHowPlayerInfo();
        break;
    case '2':
        ShowMonsters();
        break;
    case '3':
        Move(currPlayer->martial.coord.X,currPlayer->martial.coord.Y);
        break;
    case '4':
        break;
    case '5':
        break;
    }
}
/*显示玩家信息函数*/
void SHowPlayerInfo()
{
    //清除信息窗口的信息
    Clean(MARGIN_X+1,INFO_START_Y,7);
    SetPosition(MARGIN_X+20,INFO_START_Y);
    printf("主角：《%s》目前的个人资料：",currPlayer->name);
    SetPosition(MARGIN_X+10,INFO_START_Y+1);
    printf("等级：%d\t血量：%d\t法力值：%d\t经验值：%d\t",currPlayer->level,currPlayer->hp,currPlayer->mp,currPlayer->exp);
    SetPosition(MARGIN_X+10,INFO_START_Y+2);
    printf("当前武器：%s(攻击:%d~%d)",currPlayer->weapon.name,currPlayer->weapon.minAttack,currPlayer->weapon.maxAttack);
    SetPosition(MARGIN_X+10,INFO_START_Y+3);
    printf("当前防具：%s(防御：%d~%d)",currPlayer->armon.name,currPlayer->armon.minDefence,currPlayer->armon.maxDefence);
    SetPosition(MARGIN_X+10,INFO_START_Y+4);
    printf("金币：%d",currPlayer->gold);
    SetPosition(MARGIN_X+10,INFO_START_Y+5);
    printf("门派：%s",currPlayer->martial.name);
    SetPosition(MARGIN_X+10,INFO_START_Y+6);
    printf("%s",currPlayer->martial.desc);
}
/*显示怪物函数*/
void ShowMonsters()
{
    //清除信息窗口的信息
    Clean(MARGIN_X+1,INFO_START_Y,7);
    //先获得当前地图的怪物总数
    int monstercount=sizeof(monsterArray)/sizeof(Monster);//所有怪物总数
    int monsterIndexs[9];//当前地图的怪物下标数组
    int currMapMonsterCount=0;//当前地图的怪物总数
    int i;
    for(i=0;i<monstercount;i++)//查找所有怪物中是坐标是当前地图的怪物
    {
        //查找当前地图的怪物总数
        if(monsterArray[i].coord.X==x&&monsterArray[i].coord.Y==y&&monsterArray[i].state!=0)
        {
            monsterIndexs[currMapMonsterCount++]=i;
            if(currMapMonsterCount==9)
            {
                break;
            }
        }
    }
    //打印怪物
    if(currMapMonsterCount==0)
    {
        SetPosition(MARGIN_X+10,INFO_START_Y);
        printf("当前地图的怪物好像都被清光了呢！！");
        return;
    }
    SetPosition(MARGIN_X+10,INFO_START_Y);
    printf("哇，怪物好可啪：");
    SetPosition(MARGIN_X+5,INFO_START_Y+2);
    for(i=0;i<currMapMonsterCount;i++)
    {
        if(i!=0&&i%4==0)
        {
            SetPosition(MARGIN_X+5,INFO_START_Y+2+i/4);
        }
        printf("%d、%s<%d级>\t",i+1,monsterArray[monsterIndexs[i]].name,monsterArray[monsterIndexs[i]].level);
    }
    SetPosition(MARGIN_X+5,INFO_END_Y-1);
    //下面让玩家选择要PK的怪物编号，调用Fight函数
    int pkmonsterId=-1;//要pk的怪物编号
    printf("请输入要攻击的对象《按0返回》");
    do
    {
        scanf("%d",&pkmonsterId);//需要验证用户的输入
        if(pkmonsterId<0||pkmonsterId>9)
        {
            Clean(MARGIN_X+1,INFO_END_Y-1,1);
            SetPosition(MARGIN_X+5,INFO_END_Y-1);
            printf("请输入正确的怪物编号：");
        }
        if(pkmonsterId==0)
        {
            return;
        }
    }while(pkmonsterId<1||pkmonsterId>9);
    Fight(&monsterArray[monsterIndexs[pkmonsterId-1]]);
}
void Fight(Monster *monster)
{
    int fightCount=0;//pk的轮数
    while(1)
    {
        //玩家和怪物Pk
        srand(time(NULL));
        int playerAttack=rand()%(currPlayer->weapon.maxAttack-currPlayer->weapon.minAttack+1)+currPlayer->weapon.minAttack;
        monster->hp-=playerAttack;//玩家打怪物
        if(monster->hp<=0)
        {
            break;//退出pk过程
        }
        currPlayer->hp-=monster->att;//怪物打玩家
        if(currPlayer->hp<=0)
        {
            break;//退出pk过程
        }
        Clean(MARGIN_X+1,INFO_END_Y-1,1);
        SetPosition(MARGIN_X+5,INFO_END_Y-1);
        fightCount++;
        printf("战斗第%d轮：%sHP:%d\t<%s>HP:%d\t",fightCount,currPlayer->name,currPlayer->hp,monster->name,monster->hp);
        Sleep(200);
    }
    Clean(MARGIN_X+1,INFO_END_Y-1,1);
    SetPosition(MARGIN_X+5,INFO_END_Y-1);
    if(currPlayer->hp<=0)
    {
        printf("怪物太强了呢，先去打打低级怪物再来吧- -！按任意键继续");
        currPlayer->hp=100;
        getch();
        return;
    }
    int monsterMoney=rand()%(monster->maxMoney-monster->minMoney+1)+monster->minMoney;
    printf("耶，成功击败了怪物呢！获得%d经验，%d金币！按任意键继续",monster->exp,monsterMoney);
    //currPlayer->hp=currPlayer->life;
    currPlayer->exp+=monster->exp;
    currPlayer->gold+=monsterMoney;
    getch();
}
void Move(int a,int b)
{
    x=a;
    y=b;
    //刷新地图
    ShowMap();
}

