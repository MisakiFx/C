#include <graphics.h>
#include <conio.h>
#define PI 3.14159265
int main()
{
	// 创建大小为 1024 * 800 的绘图窗口
	initgraph(1024, 800);
	// 设置原点 (0, 0) 为屏幕中央（Y轴默认向下为正）
	setorigin(512, 400);
	//setbkcolor(WHITE);
	cleardevice();//清屏，归0
	/*画脸*/
	setfillcolor(WHITE);//设置填充色
	setlinecolor(BLACK);//设置线条颜色
	fillcircle(0,0,350);//头轮廓
	setlinestyle(PS_SOLID, 8);
	fillcircle(-175,-110,75);//眼睛
	fillcircle(175, -110, 75);//眼睛
	setlinestyle(PS_SOLID, 2);
	line(-75,-45,75,-45);//鼻子
	setlinestyle(PS_SOLID, 4);
	arc(-340,-540,340,160,PI * 37 / 32,PI * 59 / 32);
	arc(-250,10,250,150,PI * 3 / 32, PI * 29 / 32);//嘴
	setfillcolor(BLACK);
	line(-170, 27, -170, 107);
	line(-170, 107, -70, 107);
	line(-70, 107, -70, 12);
	line(-65,12, -65, 107);
	line(-65, 107, 65, 107);
	line(65, 107, 65, 11);
	line(70, 12, 70, 107);
	line(70, 107, 170, 107);
	line(170, 107, 170, 27);//牙齿
	floodfill(0,120,BLACK);//填充
	char c = _getch();
	closegraph();
}