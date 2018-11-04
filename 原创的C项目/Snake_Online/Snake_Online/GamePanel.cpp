/**
��Ϸ����ʵ���ļ�
*/
#include "GamePanel.h"

Panel* game_panel = NULL;//��Ϸ���
/**
ʹ���ⲿ�ļ��е�ȫ�ֱ���
*/
extern GameData* gameData;
/**
��Ϸ���ĳ�ʼ��
*/
void initial_game_panel()
{
	game_panel = panelInit();
	game_panel->x = 20;
	game_panel->y = 2;
	game_panel->width = 36;
	game_panel->height = 18;
	game_panel->color = 0x0;
	game_panel->bjColor = 0xF;
}

void drawGameData()
{
	//ʳ��Ļ���
	int food_x = game_panel->x + gameData->food->x * 2 + 1;//���x���� + �����x���� * 2
	int food_y = game_panel->y + gameData->food->y + 1;
	setCursorPosition(food_x, food_y);
	setColor(game_panel->bjColor << 4 | gameData->food->color);
	printText("��", 2);
	//С�ߵĻ���
	SnakeNode* loop;
	for (loop = gameData->snake; loop != NULL; loop = loop->next)
	{
		int node_x = game_panel->x + loop->x * 2 + 1;
		int node_y = game_panel->y + loop->y + 1;
		setCursorPosition(node_x, node_y);
		setColor(game_panel->bjColor << 4 | loop->color);
		printText("��", 2);
	}
}
/**
��Ϸ���Ļ���
*/
void drawGamePanel()
{
	initial_game_panel();
	if (NULL != game_panel)
	{
		drawPanel(game_panel);
		if (NULL != gameData)
		{
			drawGameData();
		}
	}
}
/**
�Ϸ��������
*/
void _game_panel_up(char key)
{
	if (gameData->direction != S_DOWN)
	{
		gameData->direction = S_UP;
	}
}
/**
�·��������
*/
void _game_panel_down(char key)
{
	if (gameData->direction != S_UP)
	{
		gameData->direction = S_DOWN;
	}
}
/**
���������
*/
void _game_panel_left(char key)
{
	if (gameData->direction != S_RIGHT)
	{
		gameData->direction = S_LEFT;
	}
}
/**
�ҷ��������
*/
void _game_panel_right(char key)
{
	if (gameData->direction != S_LEFT)
	{
		gameData->direction = S_RIGHT;
	}
}
/**
��Ϸ���İ�������
*/
void gamePanelKeyHandler()
{
	DefaultHandle handler = { _game_panel_up,_game_panel_down,_game_panel_left,_game_panel_right };
	key_handle_operator(&handler, NULL, 0);
}
