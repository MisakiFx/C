#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>//导入声音头文件
#pragma comment(lib,"Winmm.lib")
#include <string.h>  //支持字符串头文件
#define MAX 6        //常量MAX表示息系统要求的最大贵妃数量
#define DAY 10

int main()
{
    int searchIndex;            //用来查找的妃子的下标
    char emperorName[50];       //皇帝的名号
    char tempName[20];          //用来存放临时字符串的临时变量
    int choice,i,j,temp,k;           //皇帝的选择
    int count=5;                //当前未打入冷宫的妃子个数
    char names[MAX][20]={"栗山未来","见崎鸣","初音未来","洛天依","小鸟游六花"};
    //级别数组
    char levelNames[][10]={"初次相见","萌生爱意","坠入爱河","干柴烈火","一夜七次"};
    //用来存放每位妃子的级别，每个数组元素对应每个妃子当前级别
    int levels[MAX]={1,4,0,0,0,-1};
    //对应每个妃子的好感度,初始情况为100
    int loves[MAX]={100,100,100,100,100,-1};
    int num=0;          //用来存放妃子好感度小于60的个数
    /*
    printf("测试代码：当前妃子状态：\n");
    printf("%-16s%-16s%-16s\n","姓名","级别","好感度");
    for(i=0;i<count;i++)
    {
        printf("%-16s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    */
    system("color F5");
    printf("游戏说明：\n");
    printf("在10天内尽量让妃子的好感度都增高，每个妃子初始好感度为100\n");
    printf("最多拥有6个妃子，一旦有三个及以上妃子好感度低于60则游戏失败");
    printf("妃子一共有5个等级，从第到高为：\n");
    printf("初次相见,萌生爱意,坠入爱河,干柴烈火,一夜七次\n");
    printf("下旨选妃可以增加妃子数量\n");
    printf("翻牌宠幸增加被宠幸妃子的好感度和等级，但其它妃子好感度降低\n");
    printf("打入冷宫减少妃子的数量\n");
    printf("单独啪啪啪可以增加被啪妃子的好感度，但不会提高等级，其余妃子的好感度也不会降低\n");
    printf("游戏开始！\n");
    printf("请输入当前登基的皇帝名号：\n");
    scanf("%s",emperorName);    //录入字符串时，不需要&符号
    printf("皇帝“%s”驾临，万岁万岁万万岁！\n",emperorName);
    printf("***************************************************\n");
    printf("当前妃子状态：\n");
    printf("%-16s%-16s%-16s\n","姓名","级别","好感度");
    for(i=0;i<count;i++)
    {
        printf("%-16s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    printf("****************************************************\n");
    for(k=0;k<DAY;k++)
    {
         //播放音乐
        PlaySound(TEXT("sounds\\背景音乐.wav"),
                  NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("第%d天\n",k+1);
        printf("1.皇帝下旨选妃：\t\t（增加功能）\n");
        printf("2.翻牌宠幸：\t\t\t（修改状态功能）\n");
        printf("3.打入冷宫！\t\t\t（删除功能）\n");
        printf("4.单独召见爱妃啪啪啪。\n");
        printf("陛下请选择：\n");
        do{
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                 //播放音乐
                PlaySound(TEXT("sounds\\纳新.wav"),
                          NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                //增加nums数组和loves和levels
                //增加前需要判断数组有没有空间
                if(count<MAX)//如果当前妃子数量小于最大妃子数量
                {
                    //执行添加操作
                    printf("请输入新妃子的姓名：\n");
                    scanf("%s",names[count]);
                    levels[count]=0;        //初始化级别
                    loves[count]=100;       //初始化好感度
                    count+=1;               //增加妃子数量
                }
                else
                {
                    printf("特么%d个还不够你玩，陛下别贪得无厌\n",MAX);
                }
                break;
            case 2:
                    //找到要宠幸的贵妃的下标
                    //修改这个妃子的状态 好感度+10 级别+1 如果最高级则不再升级
                    //修改其他妃子的状态 好感度-10
                    //播放音乐
                    PlaySound(TEXT("sounds\\翻牌.wav"),
                              NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    printf("陛下，请输入要宠幸的妃子：\n");
                    do
                    {
                        scanf("%s",tempName);
                        //字符串查找strcmp，需要引入<string.h>
                         for(i=0;i<count;i++)
                        {
                            if(strcmp(tempName,names[i])==0)        //如果输入的姓名等于某个妃子的名称
                            //如果恒等于0则两个字符串相等，如果为1则表示前一个大于后一个，如果为-1则前一个小于后一个
                            {
                                break;
                            }
                        }
                        if(i==count)
                        {
                            printf("未找到妃子，请重新输入要宠幸的妃子：\n");
                        }
                    }while(i==count);
                    for(i=0;i<count;i++)
                    {
                        if(strcmp(tempName,names[i])==0)        //如果输入的姓名等于某个妃子的名称
                        //如果恒等于0则两个字符串相等，如果为1则表示前一个大于后一个，如果为-1则前一个小于后一个
                        {
                            loves[i]+=10;
                            if(levels[i]<4)
                            {
                            levels[i]+=1;        //级别不能超过5级,0-4之间
                            }
                        }
                        else
                        {
                            loves[i]-=10;
                        }
                    }
                    break;
            case 3:
                //查找
                //后面一个赋值个前面一个
                //count-1
                 //播放音乐
                PlaySound(TEXT("sounds\\冷宫.wav"),
                          NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                printf("陛下请输入要打入冷宫的妃子：\n");
                do
                {
                    scanf("%s",tempName);
                    for(i=0;i<count;i++)
                        {
                            if(strcmp(tempName,names[i])==0)        //如果输入的姓名等于某个妃子的名称
                            //如果恒等于0则两个字符串相等，如果为1则表示前一个大于后一个，如果为-1则前一个小于后一个
                            {
                                break;
                            }
                        }
                     if(i==count)
                    {
                        printf("未找到妃子，请重新输入要打入冷宫的妃子。\n");
                    }
                }while(i==count);
                for(i=0;i<count;i++)
                {
                    if(strcmp(tempName,names[i])==0)        //如果输入的姓名等于某个妃子的名称
                    //如果恒等于0则两个字符串相等，如果为1则表示前一个大于后一个，如果为-1则前一个小于后一个
                    {
                       searchIndex=i;
                       break;
                    }
                }
                for(i=searchIndex;i<count-1;i++)
                {
                    //names[i]=names[i+1];C语言中不支持字符数组直接赋值
                    //需要使用strcpy实现数组的赋值
                    strcpy(names[i],names[i+1]);
                    loves[i]=loves[i+1];
                    levels[i]=levels[i+1];
                }
                count--;//更新总人数
                break;
            case 4:
                //查找
                //妃子增加好感度
                //播放音乐
                PlaySound(TEXT("sounds\\宠幸.wav"),
                          NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                printf("请输入要啪的妃子- -：\n");
                do{
                    scanf("%s",tempName);
                    for(i=0;i<count;i++)
                        {
                            if(strcmp(tempName,names[i])==0)        //如果输入的姓名等于某个妃子的名称
                            //如果恒等于0则两个字符串相等，如果为1则表示前一个大于后一个，如果为-1则前一个小于后一个
                            {
                                loves[i]+=10;
                                break;
                            }
                        }
                        if(i==count)
                        {
                            printf("未找到要啪的妃子，请重新选择。\n");
                        }
                 }while(i==count);
                 break;
            default:
                printf("君无戏言，陛下请再次确认！\n");
            }
        }while(choice!=1&&choice!=2&&choice!=3&&choice!=4);
        //最后打印前使用冒泡排序
        for(i=0;i<count-1;i++)
        {
            for(j=0;j<count-i-1;j++)
            {
                if(levels[j]<levels[j+1])
                {
                    temp=levels[j];
                    levels[j]=levels[j+1];
                    levels[j+1]=temp;
                    temp=loves[j];
                    loves[j]=loves[j+1];
                    loves[j+1]=temp;
                    //注意字符串的交换
                    strcpy(tempName,names[j]);
                    strcpy(names[i],names[j+1]);
                    strcpy(names[j+1],tempName);
                }
            }
        }
        printf("***************************************************\n");
        printf("当前妃子状态：\n");
        printf("%-16s%-16s%-16s\n","姓名","级别","好感度");
        for(i=0;i<count;i++)
        {
            printf("%-16s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
        }
        printf("***************************************************\n");
        for(i=0;i<count;i++)
        {
            if(loves[i]<60)
            {
                num++;
            }
        }
        if(num>2)
        {
            //播放音乐
            PlaySound(TEXT("sounds\\起义.wav"),
                      NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("你惹太多妃子生气了，妃子起兵造反，卒于第%d天\n",k+1);
            break;
        }
    }
    if(num<=2)
    {
        //播放音乐
        PlaySound(TEXT("sounds\\胜利.wav"),
                  NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("游戏胜利，赢得所有妃子的芳心！！\n");
    }
    printf("游戏结束");
    system("pause");
    return 0;
}
