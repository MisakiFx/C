#include <graphics.h>      // 就是需要引用这个图形库
#include <conio.h>
void main()
{
    initgraph(640, 480);   // 这里和 TC 略有区别
	
	setfillcolor(RGB(255,255,0));
	setlinecolor(RGB(0,0,255));  //拾色器
	fillcircle(200, 200, 150); // 画圆，圆心(200, 200)，半径 150
	
	getch();               // 按任意键继续
    closegraph();          // 关闭图形界面
}