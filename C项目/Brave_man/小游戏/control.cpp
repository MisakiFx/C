#include "control.h"
extern LONGLONG count;
/**
对主角的控制
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
外部整体控制
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
