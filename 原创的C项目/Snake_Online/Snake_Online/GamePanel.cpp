/**
游戏面板的实现文件
*/
#include "GamePanel.h"

Panel* game_panel = NULL;//游戏面板
/**
使用外部文件中的全局变量
*/
extern GameData* gameData;
/**
游戏面板的初始化
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
	//食物的绘制
	int food_x = game_panel->x + gameData->food->x * 2 + 1;//面板x坐标 + 定义的x坐标 * 2
	int food_y = game_panel->y + gameData->food->y + 1;
	setCursorPosition(food_x, food_y);
	setColor(game_panel->bjColor << 4 | gameData->food->color);
	printText("●", 2);
	//小蛇的绘制
	SnakeNode* loop;
	for (loop = gameData->snake; loop != NULL; loop = loop->next)
	{
		int node_x = game_panel->x + loop->x * 2 + 1;
		int node_y = game_panel->y + loop->y + 1;
		setCursorPosition(node_x, node_y);
		setColor(game_panel->bjColor << 4 | loop->color);
		printText("■", 2);
	}
}
/**
游戏面板的绘制
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
上方向键处理
*/
void _game_panel_up(char key)
{
	if (gameData->direction != S_DOWN)
	{
		gameData->direction = S_UP;
	}
}
/**
下方向键处理
*/
void _game_panel_down(char key)
{
	if (gameData->direction != S_UP)
	{
		gameData->direction = S_DOWN;
	}
}
/**
左方向键处理
*/
void _game_panel_left(char key)
{
	if (gameData->direction != S_RIGHT)
	{
		gameData->direction = S_LEFT;
	}
}
/**
右方向键处理
*/
void _game_panel_right(char key)
{
	if (gameData->direction != S_LEFT)
	{
		gameData->direction = S_RIGHT;
	}
}
/**
游戏面板的按键处理
*/
void gamePanelKeyHandler()
{
	DefaultHandle handler = { _game_panel_up,_game_panel_down,_game_panel_left,_game_panel_right };
	key_handle_operator(&handler, NULL, 0);
}
