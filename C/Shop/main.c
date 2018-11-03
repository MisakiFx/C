#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//商品结构：名称、单价、库存、描述
//背包结构：玩家编号、道具【10】、道具数量
//玩家结构：编号、名称、金钱、（背包）

/*商品结构*/
typedef struct _prop
{
    int id;                        //道具编号（唯一）
    char name[50];        //道具名称
    double price;           //道具单价
    int stock;                  //库存量:如果在背包中，表示道具的叠加数量
    char desc[50];         //道具描述
}Prop;

/*背包结构*/
typedef struct _bag
{
    int playerId;           //所属玩家的编号
    int count;               //当前背包中道具的数量
    int max;                 //当前背包中的插槽总数，拿钱买多余的
    Prop props[8];      //当前背包中的道具数组
}Bag;

/*玩家结构*/
typedef struct _player
{
    int id;                   //玩家编号
    char names[50]; //玩家名称
    char pass[50];    //玩家密码
    Bag bags;           //玩家的背包
    double gold;     //玩家金币-人性显示：可以将10000铜币转换为银币金币显示
    double sysee;   //元宝数量
}Player;
void ShowProps();             //打印商品函数
void ShowPlayers();          //打印玩家函数
/**
*交易函数
*参数1：参与交易的玩家指针-方便修改玩家交易后的金额
*参数2：玩家所购买的商品id
**/
void Trade(Player *,int propId);    //交易函数
    //1、初始化数据
Prop propArray[]={
    {1,"Misaki专用小裙子",3000,10,"超可爱的小裙子哦"},
    {2,"Misaki专用猫耳朵",5000,5,"萌萌哒"},
    {3,"Misaki专用短发",10000,1,"独一无二的存在"},
    {4,"男主",100000,0,"没错我才是男主"},
    {5,"面瘫表情",8000,11,"就是这种感觉- -"}
};
Prop *props=propArray;
int propsCount=5;
Player playerArray[]={
    {1,"Misaki","123456",{1,0,8}, .gold=50000},
    {2,"室友是傻逼","321654",{2,0,8},.gold=50000},
    {3,"室友都是傻逼","654321",{3,0,8},.gold=50000},
    {4,"室友全部都是傻逼","159753",{4,0,8},.gold=500000}
};
Player *players=playerArray;
int playersCount=4;
int main()
{
    //2、打印初值
    printf("**************************交易前****************************\n");
    ShowProps();
    printf("*******************************************************\n");
    ShowPlayers();
    Trade(players+3,2);
    printf("\n\n**************************交易后****************************\n");
    ShowProps();
    printf("*******************************************************\n");
    ShowPlayers();
    return 0;
}
void Trade(Player *player,int propId)    //交易函数
{
    //判断：玩家的商品的库存、玩家的余额、玩家背包空间够不够
    int i;
    Prop *tradeProp=NULL;//要购买的商品指针
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
            printf("商品已售罄\n");
            return;
        }
        if(player->gold<=tradeProp->price)
        {
            printf("没钱还想入正，去死吧！");
            return;
        }
        if(player->bags.count>=player->bags.max)
        {
            printf("背包空间已满，请清理后重试或者去购买背包栏位！");
            return;
        }
        //满足交易条件，执行交易操作
        //1、商品库存减1
        tradeProp->stock--;
        //2、玩家金币-商品单价
        player->gold-=tradeProp->price;
        //3、玩家背包道具增加（判断玩家背包中是否已经有该商品，如果没有添加该商品，如果有该商品，背包中该商品总数+1）
        for(i=0;i<player->bags.count;i++)
        {
            if(player->bags.props[i].id==propId)
            {
                player->bags.props[i].stock++;
                break;
            }
        }
        if(i==player->bags.count)//如果没有添加该商品
        {
            //向背包中创建一个商品
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
    printf("%-5s%-20s%-10s%-5s%-20s\n","编号","名称","单价","库存","商品介绍");
    for(i=0;i<propsCount;i++)
    {
        printf("%-5d%-20s%-10.0lf%-5d%-20s\n",props[i].id,props[i].name,props[i].price,props[i].stock,props[i].desc);
    }
}
void ShowPlayers()
{
    int i,j;
    if(players==NULL) return;
    printf("编号\t%-20s金币\n","名称");
    for(i=0;i<playersCount;i++)
    {
        printf("\n%d\t%-20s%.0lf\n",players[i].id,players[i].names,players[i].gold);
        printf("玩家物品如下：\n");
        for(j=0;j<players[i].bags.count;j++)
        {
            printf("%-20s**************           %d\n",players[i].bags.props[j].name,players[i].bags.props[j].stock);
        }
    }
}

