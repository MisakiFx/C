#include "control.h"
extern LONGLONG count;
/**
�����ǵĿ���
*/

void gameStart()
{
	while (isDead() != 1)
	{
		PersonKey();
		drawGame();
		count++;
	}
}
/**
�ⲿ�������
*/
void gameControl()
{
	setTitle();
	setWinSize(30, 60);
	disableCurrsole();
	menuPanelInit();
	drawPanelBackGround();
	/*PlaySound("Music\\MenuBGM.wav",
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/
	while (menu())
	{

	}
}
