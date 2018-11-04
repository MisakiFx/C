#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#define HOTEL1 872.0 //各家酒店的默认房费
#define HOTEL2 1838.0
#define HOTEL3 789.0
#define HOTEL4 1658.0
#define DISCOUNT 0.95 //折扣率
//菜单函数：显示菜单选项，接收并返回用户的输入
int Menu(void);
int GetNights(void);//接收入住多少天
void ShowPrice(int choice,int nights,double price);//根据入住的天数和房间的单价计算最终的价格
#endif // HOTEL_H_INCLUDED
