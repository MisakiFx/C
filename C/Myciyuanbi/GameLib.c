/**********************************
*�ļ�����GameLib.c
*��    ����ʵ��GameLib.h�еĲ�������
*�����ˣ�Misaki
*��    �ڣ�2018.1.16
*��    ����0.1
*�ٷ�QQ��1761607418
**********************************/
#include "GameLib.h"
void SetTitle(char *title)
{
    SetConsoleTitle(title);
}
void SetColor(int foreColor,int backColor)
{
    HANDLE winHandle;//���
    winHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    //����������ɫ
    SetConsoleTextAttribute(winHandle,foreColor+backColor*0x10);
}
void SetPosition(int x,int y)
{
    HANDLE winHandle;//���
    COORD pos={x,y};
    winHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù���λ��
    SetConsoleCursorPosition(winHandle,pos);
}
void Clean(int x,int y,int rowCount)
{
    //ÿ�����78���ַ�-��ӡ78���ո�
    int i,j;
    for (i=0;i<rowCount;i++)
    {
        SetPosition(x,y+i);
        for(j=0;j<77;j++)
        {
            printf(" ");
        }
    }
}


