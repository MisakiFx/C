#include "Menu.h"
Panel* menuPanel = NULL;
MenuChoice* menuChoice[3] = { NULL };
int isOver = 1;
/**
�˵�ѡ���ʼ��
*/
void menuChoiceInit()
{
	MenuChoice temp[3] = {
		{35,9,"��ʼ��Ϸ",0x5,0x9},
		{35,10,"��Ϸ˵��",0x5,0xF},
		{35,11,"�˳�",0x5,0xF}
	};
	for (int i = 0; i < 3; i++)
	{
		if (menuChoice[i] == NULL)
		{
			menuChoice[i] = (MenuChoice*)malloc(sizeof(MenuChoice));
			*menuChoice[i] = temp[i];
		}
	}
}
/**
��ʼ���˵�����
*/
void menuPanelInit()
{
	if (menuPanel == NULL)
	{
		menuPanel = (Panel*)malloc(sizeof(Panel));
		menuPanel->x = 10;
		menuPanel->y = 2;
		menuPanel->high = 25;
		menuPanel->width = 80;
		menuPanel->a = '*';
	}
}
/**
�˵���������
*/
void drawPanelBackGround()
{
	setColor(0xFF);
	for (int i = 0; i < menuPanel->high - 1; i++)
	{
		for (int j = 0; j < menuPanel->width - 1; j++)
		{
			setCursorPosition(menuPanel->x + 1 + j, menuPanel->y + 1 + i);
			printf(" ");
		}
	}
}
/**
�˵�ѡ���ӡ
*/
void menuChoicePrint()
{
	menuChoiceInit();
	for (int i = 0; i < 3; i++)
	{
		setColor(menuChoice[i]->bjColor << 4 | menuChoice[i]->color);
		setCursorPosition(menuPanel->x + 1 + menuChoice[i]->x, menuPanel->y + 1 + menuChoice[i]->y);
		printf("%s", menuChoice[i]->string);
	}
}
/**
�˵��ⲿ����
*/
int menu()
{
	MenuKey();
	drawMenuPanel();
	return isOver;
}
/**
���˵����溯��
*/
void drawMenuPanel()
{
	drawPanel(menuPanel->x, menuPanel->y, menuPanel->width, menuPanel->high, menuPanel->a);
	menuChoicePrint();
	setColor(0xFD);
	setCursorPosition(60, 22);
	printf("'��' '��'��'w''s'�ƶ���꣡");
	setCursorPosition(60, 24);
	printf("�س�������ѡ��");
}
