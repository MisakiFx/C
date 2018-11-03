#include "Game.h"
#include "GameLib.h"
#define SEP "-------------------------------------------------------------------------------"
#define COL 78            //��Ϸ�����ܿ��
#define MARGIN_X 20//��߾�
#define MAP_START_Y 3
#define MAP_END_Y 11
#define INFO_START_Y 12
#define INFO_END_Y 19
#define MAINMENU_START_Y 20
int x=0,y=0;//���赱ǰ���û���������3��2
Martial martials[]={
    {1,"�̷�������ɰ�","�ٷ�Ψһ�ƶ���������",{6,0},1,"�ٷ�Ψһָ���������ɣ��������κη������̷�������ɰ�"}
};
Player players[]={
    {9527,"Misaki","Misaki",500,1,1,500,800,1000,1000,.coord.X=0,.coord.Y=0},
    {9528,"��ɽδ��","û��δ����δ����������Ҫ��δ��",1000,1,1,1000,500,500,1000,.coord.X=0,.coord.Y=0},
};
Monster monsterArray[]={
    {1,"����ս��",1,100,5,3,5,10,5,1,{0,0}},
    {2,"ʺ��ķ",1,150,3,2,5,10,5,1,{0,0}},
    {3,"ˮ��",2,200,8,5,9,15,8,1,{0,0}},
    {4,"ʨ����",2,250,10,7,10,20,12,1,{0,0}},
    {5,"������",3,100,15,2,8,15,8,1,{0,0}},
    {6,"������",4,350,15,10,20,50,20,1,{0,0}},
    {7,"����Ա��",100,1000000,100000,1000000,0,0,0,1,{0,0}},
    {8,"����ս��",1,100,5,3,5,10,5,1,{1,0}},
};
Prop propArray[]={
    {1,"��ର�",1,5,5000,Weapon,.minAttack=1,.maxAttack=8,"����ର���ֵ��ӵ��"},
    {2,"ľ��",2,5,5000,Armor,.minDefence=2,.maxDefence=10,"���õ����ֶ�"},
    {3,"������Ѫҩ",3,5,1000,Con,.minPower=50,.maxPower=100,"�ܲ�������Ѫ��"},
};
Map mapArray[8][8]={//X��Y�����ϵ�ͼ����
    {{1,"�齣ɽ",1,{0,0},"���������齣ɽ��"},{2,"����",1,{1,0},"���������ҵ�����"},
    {3,"����",1,{2,0},"����֮��1111111111111111111111111111111111111111111111111111"},{4,"������",4,{3,0},"���������齣ɽ��"},
    {5,"�ɾ�",1,{4,0},"���������齣ɽ��"},{6,"����֮��",1,{5,0},"���������齣ɽ��"},
    {7,"��ʥ֮��",1,{6,0},"���������齣ɽ��"},{8,"ĸ֮ɽ",1,{7,0},"���������齣ɽ��"}},

    {{1,"��ƽ�߳�",1,{0,1},"���������齣ɽ��"},{1,"��е����",1,{1,1},"���������齣ɽ��"},
    {1,"��������",1,{2,1},"���������齣ɽ��"},{1,"���ڴ���",1,{3,1},"���������齣ɽ��"},
    {1,"��˹ɽ��",1,{4,1},"���������齣ɽ��"},{1,"���鵺",1,{5,1},"���������齣ɽ��"},
    {1,"������",1,{6,1},"���������齣ɽ��"},{1,"��֮��",1,{7,1},"���������齣ɽ��"}},

    {{1,"��̷��",1,{0,2},"���������齣ɽ��"},{1,"ʧ��֮��",1,{1,2},"���������齣ɽ��"},
    {1,"������",1,{2,2},"���������齣ɽ��"},{1,"����֮��",1,{3,2},"���������齣ɽ��"},
    {1,"������",1,{4,2},"���������齣ɽ��"},{1,"����˹ɽ",1,{5,2},"���������齣ɽ��"},
    {1,"������",1,{6,2},"���������齣ɽ��"},{1,"�˺�",1,{7,2},"���������齣ɽ��"}},

    {{1,"����֮��",1,{0,3},"���������齣ɽ��"},{1,"Ģ����",1,{1,3},"���������齣ɽ��"},
    {1,"ج��Ĺ��",1,{2,3},"���������齣ɽ��"},{1,"������ѧ",1,{3,3},"���������齣ɽ��"},
    {1,"����֮��",1,{4,3},"���������齣ɽ��"},{1,"����˹",1,{5,3},"���������齣ɽ��"},
    {1,"������",1,{6,3},"���������齣ɽ��"},{1,"������˹",1,{7,3},"���������齣ɽ��"}},

    {{1,"�޾�֮ԭ",1,{0,4},"���������齣ɽ��"},{1,"����֮��",1,{1,4},"���������齣ɽ��"},
    {1,"����һ",1,{2,4},"���������齣ɽ��"},{1,"����ɽ",1,{3,4},"���������齣ɽ��"},
    {1,"ĸ��֮��",1,{4,4},"���������齣ɽ��"},{1,"ˮ���",1,{5,4},"���������齣ɽ��"},
    {1,"������",1,{6,4},"���������齣ɽ��"},{1,"������ԭ",1,{7,4},"���������齣ɽ��"}},

    {{1,"ɱ¾����",1,{0,5},"���������齣ɽ��"},{1,"���",1,{1,5},"���������齣ɽ��"},
    {1,"�ž���",1,{2,5},"���������齣ɽ��"},{1,"��һ��ѧ",1,{3,5},"���������齣ɽ��"},
    {1,"Ħ���¥",1,{4,5},"���������齣ɽ��"},{1,"���ȹ�",1,{5,5},"���������齣ɽ��"},
    {1,"����",1,{6,5},"���������齣ɽ��"},{1,"���ֲ�",1,{7,5},"���������齣ɽ��"}},

    {{1,"�t����",1,{0,6},"���������齣ɽ��"},{1,"ǰ��վ",1,{1,6},"���������齣ɽ��"},
    {1,"��ԭվ",1,{2,6},"���������齣ɽ��"},{1,"��˾��¥",1,{3,6},"���������齣ɽ��"},
    {1,"M����",1,{4,6},"���������齣ɽ��"},{1,"��������",1,{5,6},"���������齣ɽ��"},
    {1,"���޿ռ�",1,{6,6},"���������齣ɽ��"},{1,"Ʈ��ռ�",1,{7,6},"���������齣ɽ��"}},

    {{1,"�貿ռ�",1,{0,7},"���������齣ɽ��"},{1,"��¥",1,{1,7},"���������齣ɽ��"},
    {1,"ƽ���",1,{2,7},"���������齣ɽ��"},{1,"������",1,{3,7},"���������齣ɽ��"},
    {1,"�������",1,{4,7},"���������齣ɽ��"},{1,"����ĩ��",1,{5,7},"���������齣ɽ��"},
    {1,"�˹��ٲ�",1,{6,7},"���������齣ɽ��"},{1,"���羡ͷ",1,{7,7},"���������齣ɽ��"}}
};
Player *currPlayer;
void Init()//��ʼ���������
{
    //���õ�ǰ��½���Ĭ��Ϊ���1
    currPlayer=&players[0];
    currPlayer->weapon=propArray[0];
    currPlayer->armon=propArray[1];
    currPlayer->martial=martials[0];
}
/*��ʾ��Ϸ�Ļ�ӭ��Ϣ*/
void ShowWelcome()
{
    SetPosition(MARGIN_X,0);
    printf("%-s",SEP);
    SetPosition(MARGIN_X,1);
    printf("|");
    SetPosition(MARGIN_X+30,1);
    printf("�����Ǵ�Ԫ�ڵı˶�");
    SetPosition(MARGIN_X+78,1);
    printf("|");
    SetPosition(MARGIN_X,2);
    printf("%s\n",SEP);
}
/*��ʾ��Ϸ��ͼ*/
void ShowMap()
{
    //������ҵ�ǰ������ʾ����
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
                //���ĵ�ͼ���ֵ���ɫ�ͱ���ɫ
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
/*��ʾ��ͼ��Ϣ����*/
void ShowMapInfo()
{
    //1�������Ϣ�����Ϣ
    Clean(MARGIN_X+1,INFO_START_Y,7);
    //2����ʾ��ҵ�ǰ��������ĵ�ͼ��Ϣ
    SetPosition(MARGIN_X+25,INFO_START_Y);
    printf("��ǰ������ڵ�ͼ����%s��",mapArray[y][x].name);
    SetPosition(MARGIN_X+10,INFO_START_Y+1);
    //��Ҫ����������ʾ����
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
/*��ʾ��Ϸ��ͼ�·��ĵ�ͼ��Ϣ*/
void ShowInformation()
{
    //��Ϣ����һ����7��
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
/*��ʾ��Ϸ�����˵�*/
void ShowMainMenu()
{
    SetPosition(MARGIN_X,MAINMENU_START_Y);
    printf("��Ϸ�˵���");
    SetPosition(MARGIN_X,MAINMENU_START_Y+1);
    printf("1����������");
    SetPosition(MARGIN_X,MAINMENU_START_Y+2);
    printf("2�����ҹ���");
    SetPosition(MARGIN_X,MAINMENU_START_Y+3);
    printf("3���ػ���");
    SetPosition(MARGIN_X,MAINMENU_START_Y+4);
    printf("4������װ��");
}
/*����˵�����*/
void ProcessMainMenu(char key)
{
    switch(key)
    {
    case '1':
        //������Ϣ
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
/*��ʾ�����Ϣ����*/
void SHowPlayerInfo()
{
    //�����Ϣ���ڵ���Ϣ
    Clean(MARGIN_X+1,INFO_START_Y,7);
    SetPosition(MARGIN_X+20,INFO_START_Y);
    printf("���ǣ���%s��Ŀǰ�ĸ������ϣ�",currPlayer->name);
    SetPosition(MARGIN_X+10,INFO_START_Y+1);
    printf("�ȼ���%d\tѪ����%d\t����ֵ��%d\t����ֵ��%d\t",currPlayer->level,currPlayer->hp,currPlayer->mp,currPlayer->exp);
    SetPosition(MARGIN_X+10,INFO_START_Y+2);
    printf("��ǰ������%s(����:%d~%d)",currPlayer->weapon.name,currPlayer->weapon.minAttack,currPlayer->weapon.maxAttack);
    SetPosition(MARGIN_X+10,INFO_START_Y+3);
    printf("��ǰ���ߣ�%s(������%d~%d)",currPlayer->armon.name,currPlayer->armon.minDefence,currPlayer->armon.maxDefence);
    SetPosition(MARGIN_X+10,INFO_START_Y+4);
    printf("��ң�%d",currPlayer->gold);
    SetPosition(MARGIN_X+10,INFO_START_Y+5);
    printf("���ɣ�%s",currPlayer->martial.name);
    SetPosition(MARGIN_X+10,INFO_START_Y+6);
    printf("%s",currPlayer->martial.desc);
}
/*��ʾ���ﺯ��*/
void ShowMonsters()
{
    //�����Ϣ���ڵ���Ϣ
    Clean(MARGIN_X+1,INFO_START_Y,7);
    //�Ȼ�õ�ǰ��ͼ�Ĺ�������
    int monstercount=sizeof(monsterArray)/sizeof(Monster);//���й�������
    int monsterIndexs[9];//��ǰ��ͼ�Ĺ����±�����
    int currMapMonsterCount=0;//��ǰ��ͼ�Ĺ�������
    int i;
    for(i=0;i<monstercount;i++)//�������й������������ǵ�ǰ��ͼ�Ĺ���
    {
        //���ҵ�ǰ��ͼ�Ĺ�������
        if(monsterArray[i].coord.X==x&&monsterArray[i].coord.Y==y&&monsterArray[i].state!=0)
        {
            monsterIndexs[currMapMonsterCount++]=i;
            if(currMapMonsterCount==9)
            {
                break;
            }
        }
    }
    //��ӡ����
    if(currMapMonsterCount==0)
    {
        SetPosition(MARGIN_X+10,INFO_START_Y);
        printf("��ǰ��ͼ�Ĺ�����񶼱�������أ���");
        return;
    }
    SetPosition(MARGIN_X+10,INFO_START_Y);
    printf("�ۣ�����ÿ�ž��");
    SetPosition(MARGIN_X+5,INFO_START_Y+2);
    for(i=0;i<currMapMonsterCount;i++)
    {
        if(i!=0&&i%4==0)
        {
            SetPosition(MARGIN_X+5,INFO_START_Y+2+i/4);
        }
        printf("%d��%s<%d��>\t",i+1,monsterArray[monsterIndexs[i]].name,monsterArray[monsterIndexs[i]].level);
    }
    SetPosition(MARGIN_X+5,INFO_END_Y-1);
    //���������ѡ��ҪPK�Ĺ����ţ�����Fight����
    int pkmonsterId=-1;//Ҫpk�Ĺ�����
    printf("������Ҫ�����Ķ��󡶰�0���ء�");
    do
    {
        scanf("%d",&pkmonsterId);//��Ҫ��֤�û�������
        if(pkmonsterId<0||pkmonsterId>9)
        {
            Clean(MARGIN_X+1,INFO_END_Y-1,1);
            SetPosition(MARGIN_X+5,INFO_END_Y-1);
            printf("��������ȷ�Ĺ����ţ�");
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
    int fightCount=0;//pk������
    while(1)
    {
        //��Һ͹���Pk
        srand(time(NULL));
        int playerAttack=rand()%(currPlayer->weapon.maxAttack-currPlayer->weapon.minAttack+1)+currPlayer->weapon.minAttack;
        monster->hp-=playerAttack;//��Ҵ����
        if(monster->hp<=0)
        {
            break;//�˳�pk����
        }
        currPlayer->hp-=monster->att;//��������
        if(currPlayer->hp<=0)
        {
            break;//�˳�pk����
        }
        Clean(MARGIN_X+1,INFO_END_Y-1,1);
        SetPosition(MARGIN_X+5,INFO_END_Y-1);
        fightCount++;
        printf("ս����%d�֣�%sHP:%d\t<%s>HP:%d\t",fightCount,currPlayer->name,currPlayer->hp,monster->name,monster->hp);
        Sleep(200);
    }
    Clean(MARGIN_X+1,INFO_END_Y-1,1);
    SetPosition(MARGIN_X+5,INFO_END_Y-1);
    if(currPlayer->hp<=0)
    {
        printf("����̫ǿ���أ���ȥ���ͼ�����������- -�������������");
        currPlayer->hp=100;
        getch();
        return;
    }
    int monsterMoney=rand()%(monster->maxMoney-monster->minMoney+1)+monster->minMoney;
    printf("Ү���ɹ������˹����أ����%d���飬%d��ң������������",monster->exp,monsterMoney);
    //currPlayer->hp=currPlayer->life;
    currPlayer->exp+=monster->exp;
    currPlayer->gold+=monsterMoney;
    getch();
}
void Move(int a,int b)
{
    x=a;
    y=b;
    //ˢ�µ�ͼ
    ShowMap();
}

