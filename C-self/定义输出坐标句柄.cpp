#include <stdio.h>
#include <windows.h>
void SetPosition(int x,int y)
{
    HANDLE winHandle;//���
    COORD pos={x,y};
    winHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù���λ��
    SetConsoleCursorPosition(winHandle,pos);
}
int main()
{
	SetPosition(1,1);
}
