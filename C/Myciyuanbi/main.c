#include "Game.h"
#include "GameLib.h"
extern int x,y;
int main()
{
    char key;
    system("color F0");
    SetTitle("��Ԫ�ڵ��ѷ�");
    Init();
    ShowWelcome();
    ShowMap();
    ShowInformation();
    ShowMainMenu();
    while(1)
    {
        fflush(stdin);
        key=getch();
        fflush(stdin);
        if(key=='1'||key=='2'||key=='3'||key=='4'||key=='5')
        {
            ProcessMainMenu(key);//ͨ������������Ϸ�Ĳ˵�ѡ��
            continue;
        }
        else if(key==VK_UP||key==72)
        {
            y--;
        }
        else if(key==VK_DOWN||key==80)
        {
            y++;
        }
        else if(key==VK_RIGHT||key==77)
        {
            x++;
        }
        else if(key==VK_LEFT||key==75)
        {
            x--;
        }
        if(x>7)
        {
            x=0;
        }
        if(x<0)
        {
            x=7;
        }
        if(y>7)
        {
            y=0;
        }
        if(y<0)
        {
            y=7;
        }
        ShowMap();
    }
    return 0;
}
