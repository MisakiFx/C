#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"
extern char hotelNames[4][50];
int main()
{
    //头文件：一般放一些重复使用的代码，变量，常量声明等
    //自定义头文件
    //用户输入入住的酒店和天数，程序计算出对应的金额
    int choice;//选择
    int nights;//天数
    double totalCost;//用户支付的总房费
    double  currCost;//用户当前入住的酒店房费
    //1.显示菜单
   while((choice=Menu())!=5)
   {
       //2.计算过程
       switch (choice)
       {
       case 1://用户入住第一家酒店
           currCost=HOTEL1;
        break;
       case 2://用户入住第二家酒店
           currCost=HOTEL2;
        break;
       case 3://用户入住第三家酒店
           currCost=HOTEL3;
        break;
       case 4://用户入住第四家酒店
           currCost=HOTEL4;
        break;
       default:
           currCost=0;
       }
       //得到用户入住的天数
       nights=GetNights();
       //计算总费用
       ShowPrice(choice,nights,currCost);
   }
   printf("感谢使用本系统，再会！！");
    return 0;
}
