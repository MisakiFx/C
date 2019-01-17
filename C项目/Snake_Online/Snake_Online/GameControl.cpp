/**
游戏控制器的定义
*/

#include "GameControl.h"
#include <time.h>
void snake_intial(Setting* set);
/**
全局游戏设置
*/
GameData* gameData = NULL;
/**
更改食物信息
*/
void freshFoodInfo()
{
	gameData->food->x = rand() % gameData->map_width;
	gameData->food->y = rand() % gameData->map_height;
	gameData->food->color = rand() % 0xF;
}
/**
获取最新坐标
*/
void positionByDirection(int* x, int* y)
{
	//获取最新坐标
	switch (gameData->direction)//保证坐标在地图中
	{
	case S_UP://y坐标递减
		(*y)--;
		if ((*y) < 0)
		{
			(*y) = gameData->map_height;

		}
		break;
	case S_DOWN:
		(*y)++;
		if ((*y) > gameData->map_height)
		{
			(*y) = 0;
		}
		break;
	case S_LEFT:
		(*x)--;
		if ((*x) < 0)
		{
			(*x) = gameData->map_width;
		}
		break;
	case S_RIGHT:
		(*x)++;
		if ((*x) > gameData->map_width)
		{
			(*x) = 0;
		}
		break;
	default:
		break;
	}
}
/**
小蛇移动
*/
void snakeMove()
{
	//9,0
	int x = gameData->snake->x;
	int y = gameData->snake->y;
	//获取最新坐标
	positionByDirection(&x, &y);
	//从最后一截开始依次获取前一节身体坐标
	SnakeNode* loop = NULL;
	for (loop = gameData->snake_tail; loop->prev != NULL; loop = loop->prev)
	{
		loop->x = loop->prev->x;
		loop->y = loop->prev->y;
	}
	//获取最新坐标给第一节身体
	gameData->snake->x = x;
	gameData->snake->y = y;
}
/**
捕食食物
*/
void eatFood()
{
	if (gameData->snake->x == gameData->food->x && gameData->snake->y == gameData->food->y)
	{
		SnakeNode* node = (SnakeNode*)malloc(sizeof(SnakeNode));
		memset(node, 0, sizeof(SnakeNode));
		node->prev = NULL;
		int x = gameData->snake->x;
		int y = gameData->snake->y;
		positionByDirection(&x, &y);
		node->x = x;
		node->y = y;
		node->color = gameData->food->color;
		node->next = gameData->snake;
		gameData->snake->prev = node;
		gameData->snake = node;
		//处理速度和分数
		gameData->score += 10;
		if (gameData->score > 0 && gameData->score % 20 && gameData->speed > 0.05)
		{
			gameData->speed -= 0.01;
		}
		gameData->lenth++;
		setGameInfo(gameData->score, gameData->lenth, gameData->speed);
		//修改食物信息，坐标及颜色
		freshFoodInfo();
	}
}
/**
检查是否死亡
*/
int checkDead()
{
	SnakeNode* loop = NULL;
	for (loop = gameData->snake->next; loop != NULL; loop = loop->next)
	{
		if (loop->x == gameData->snake->x && loop->y == gameData->snake->y)
		{
			return 1;//小蛇死亡
		}
	}
	return 0;//小蛇活着
}

void resetGame()
{
	//小蛇的数据释放
	SnakeNode* loop = NULL;
	for (loop = gameData->snake_tail->prev; loop != NULL; loop = loop->prev)
	{
		free(loop->next);
		loop->next = NULL;
	}
	//处理头的释放
	free(gameData->snake);
	gameData->snake = NULL;
	gameData->snake_tail = NULL;
	//重置游戏数据
	Setting* setting = getSettingData();
	gameData->lenth = setting->snake_len;
	gameData->speed = setting->snake_speed;
	gameData->score = 0;
	gameData->direction = setting->direction;
	freshFoodInfo();
	snake_intial(setting);
}
void startGame()
{
	setGameInfo(gameData->score, gameData->lenth, gameData->speed);
	for (; checkDead() == 0;)
	{

		gamePanelKeyHandler();
		eatFood();
		snakeMove();
		drawGamePanel();
		double s_time = gameData->speed * 1000;
		Sleep(s_time);
	}
	setCursorPosition(30, 10);
	setColor(0x4F);
	printText("小蛇死亡", 16);
	resetGame();
}
/**
小蛇的初始化
*/
void snake_intial(Setting* set)
{
	int i = 0;
	for (i = set->snake_len - 1; i >= 0; i--)
	{
		SnakeNode* node = (SnakeNode*)malloc(sizeof(SnakeNode));
		node->x = i;
		node->y = set->snake_y;
		node->color = set->snake_color;
		node->next = NULL;
		node->prev = NULL;
		if (gameData->snake == NULL)//创建第一节身体
		{
			gameData->snake = node;
			gameData->snake_tail = node;
		}
		else
		{
			//尾巴的下一节，拼接当前节点
			gameData->snake_tail->next = node;
			//当前节点的上一节，拼接到尾巴上
			node->prev = gameData->snake_tail;
			//当前节点设置为尾巴(更新尾巴)
			gameData->snake_tail = node;
		}
	}
}
void gameInitial()
{
	srand(time(NULL));
	Setting* setting = getSettingData();
	if (NULL == gameData)
	{
		gameData = (GameData*)malloc(sizeof(GameData));
		memset(gameData, 0, sizeof(GameData));
		gameData->snake = NULL;
		gameData->snake_tail = NULL;
		gameData->food = NULL;
	}
	gameData->map_width = setting->map_width;
	gameData->map_height = setting->map_height;
	gameData->lenth = setting->snake_len;
	gameData->direction = setting->direction;
	if (NULL == gameData->snake)
	{
		snake_intial(setting);
	}
	if (NULL == gameData->food)
	{
		gameData->food = (Food*)malloc(sizeof(Food));
		freshFoodInfo();
	}
	gameData->score = 0;
	gameData->speed = setting->snake_speed;
}
void readyGame()
{
	setTitle("贪吃蛇（积木版）");
	setWinSize(60, 27);
	disableCurrsole();
	gameInitial();
	drawControlPanel();
	drawGamePanel();
	ControlPanelOperator control_op = {
		drawGamePanel,
		drawSettingPanel,
		startGame
	};
	setControlPanelOperator(&control_op);
	while (1)
	{
		control_panel_key_bind();
		Sleep(100);
	}
}
