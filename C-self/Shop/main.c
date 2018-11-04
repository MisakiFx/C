#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��Ʒ�ṹ�����ơ����ۡ���桢����
//�����ṹ����ұ�š����ߡ�10������������
//��ҽṹ����š����ơ���Ǯ����������

/*��Ʒ�ṹ*/
typedef struct _prop
{
    int id;                        //���߱�ţ�Ψһ��
    char name[50];        //��������
    double price;           //���ߵ���
    int stock;                  //�����:����ڱ����У���ʾ���ߵĵ�������
    char desc[50];         //��������
}Prop;

/*�����ṹ*/
typedef struct _bag
{
    int playerId;           //������ҵı��
    int count;               //��ǰ�����е��ߵ�����
    int max;                 //��ǰ�����еĲ����������Ǯ������
    Prop props[8];      //��ǰ�����еĵ�������
}Bag;

/*��ҽṹ*/
typedef struct _player
{
    int id;                   //��ұ��
    char names[50]; //�������
    char pass[50];    //�������
    Bag bags;           //��ҵı���
    double gold;     //��ҽ��-������ʾ�����Խ�10000ͭ��ת��Ϊ���ҽ����ʾ
    double sysee;   //Ԫ������
}Player;
void ShowProps();             //��ӡ��Ʒ����
void ShowPlayers();          //��ӡ��Һ���
/**
*���׺���
*����1�����뽻�׵����ָ��-�����޸���ҽ��׺�Ľ��
*����2��������������Ʒid
**/
void Trade(Player *,int propId);    //���׺���
    //1����ʼ������
Prop propArray[]={
    {1,"Misakiר��Сȹ��",3000,10,"���ɰ���Сȹ��Ŷ"},
    {2,"Misakiר��è����",5000,5,"������"},
    {3,"Misakiר�ö̷�",10000,1,"��һ�޶��Ĵ���"},
    {4,"����",100000,0,"û���Ҳ�������"},
    {5,"��̱����",8000,11,"�������ָо�- -"}
};
Prop *props=propArray;
int propsCount=5;
Player playerArray[]={
    {1,"Misaki","123456",{1,0,8}, .gold=50000},
    {2,"������ɵ��","321654",{2,0,8},.gold=50000},
    {3,"���Ѷ���ɵ��","654321",{3,0,8},.gold=50000},
    {4,"����ȫ������ɵ��","159753",{4,0,8},.gold=500000}
};
Player *players=playerArray;
int playersCount=4;
int main()
{
    //2����ӡ��ֵ
    printf("**************************����ǰ****************************\n");
    ShowProps();
    printf("*******************************************************\n");
    ShowPlayers();
    Trade(players+3,2);
    printf("\n\n**************************���׺�****************************\n");
    ShowProps();
    printf("*******************************************************\n");
    ShowPlayers();
    return 0;
}
void Trade(Player *player,int propId)    //���׺���
{
    //�жϣ���ҵ���Ʒ�Ŀ�桢��ҵ�����ұ����ռ乻����
    int i;
    Prop *tradeProp=NULL;//Ҫ�������Ʒָ��
    for(i=0;i<propsCount;i++)
    {
        if(propId==props[i].id)
        {
            tradeProp=&props[i+1];
            break;
        }
    }
        if(tradeProp->stock<=0)
        {
            printf("��Ʒ������\n");
            return;
        }
        if(player->gold<=tradeProp->price)
        {
            printf("ûǮ����������ȥ���ɣ�");
            return;
        }
        if(player->bags.count>=player->bags.max)
        {
            printf("�����ռ�����������������Ի���ȥ���򱳰���λ��");
            return;
        }
        //���㽻��������ִ�н��ײ���
        //1����Ʒ����1
        tradeProp->stock--;
        //2����ҽ��-��Ʒ����
        player->gold-=tradeProp->price;
        //3����ұ����������ӣ��ж���ұ������Ƿ��Ѿ��и���Ʒ�����û����Ӹ���Ʒ������и���Ʒ�������и���Ʒ����+1��
        for(i=0;i<player->bags.count;i++)
        {
            if(player->bags.props[i].id==propId)
            {
                player->bags.props[i].stock++;
                break;
            }
        }
        if(i==player->bags.count)//���û����Ӹ���Ʒ
        {
            //�򱳰��д���һ����Ʒ
            player->bags.props[player->bags.count].id=tradeProp->id;
            strcpy(player->bags.props[player->bags.count].name,tradeProp->name);
            strcpy(player->bags.props[player->bags.count].desc,tradeProp->desc);
            player->bags.props[player->bags.count].price=(tradeProp->price)/2;
            player->bags.props[player->bags.count].stock=1;
            player->bags.count++;
        }
    }
void ShowProps()
{
    int i;
    if(props==NULL) return;
    printf("%-5s%-20s%-10s%-5s%-20s\n","���","����","����","���","��Ʒ����");
    for(i=0;i<propsCount;i++)
    {
        printf("%-5d%-20s%-10.0lf%-5d%-20s\n",props[i].id,props[i].name,props[i].price,props[i].stock,props[i].desc);
    }
}
void ShowPlayers()
{
    int i,j;
    if(players==NULL) return;
    printf("���\t%-20s���\n","����");
    for(i=0;i<playersCount;i++)
    {
        printf("\n%d\t%-20s%.0lf\n",players[i].id,players[i].names,players[i].gold);
        printf("�����Ʒ���£�\n");
        for(j=0;j<players[i].bags.count;j++)
        {
            printf("%-20s**************           %d\n",players[i].bags.props[j].name,players[i].bags.props[j].stock);
        }
    }
}

