#include <stdio.h>
#include <windows.h>
void SetPosition(int x,int y)
{
    HANDLE winHandle;//句柄
    COORD pos={x,y};
    winHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标的位置
    SetConsoleCursorPosition(winHandle,pos);
}
int main()
{
	SetPosition(1,1);
}
