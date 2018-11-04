/**
��Ϸ�������Ķ���
*/

#include "GameControl.h"
#include <time.h>
void snake_intial(Setting* set);
/**
ȫ����Ϸ����
*/
GameData* gameData = NULL;
/**
����ʳ����Ϣ
*/
void freshFoodInfo()
{
	gameData->food->x = rand() % gameData->map_width;
	gameData->food->y = rand() % gameData->map_height;
	gameData->food->color = rand() % 0xF;
}
/**
��ȡ��������
*/
void positionByDirection(int* x, int* y)
{
	//��ȡ��������
	switch (gameData->direction)//��֤�����ڵ�ͼ��
	{
	case S_UP://y����ݼ�
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
С���ƶ�
*/
void snakeMove()
{
	//9,0
	int x = gameData->snake->x;
	int y = gameData->snake->y;
	//��ȡ��������
	positionByDirection(&x, &y);
	//�����һ�ؿ�ʼ���λ�ȡǰһ����������
	SnakeNode* loop = NULL;
	for (loop = gameData->snake_tail; loop->prev != NULL; loop = loop->prev)
	{
		loop->x = loop->prev->x;
		loop->y = loop->prev->y;
	}
	//��ȡ�����������һ������
	gameData->snake->x = x;
	gameData->snake->y = y;
}
/**
��ʳʳ��
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
		//�����ٶȺͷ���
		gameData->score += 10;
		if (gameData->score > 0 && gameData->score % 20 && gameData->speed > 0.05)
		{
			gameData->speed -= 0.01;
		}
		gameData->lenth++;
		setGameInfo(gameData->score, gameData->lenth, gameData->speed);
		//�޸�ʳ����Ϣ�����꼰��ɫ
		freshFoodInfo();
	}
}
/**
����Ƿ�����
*/
int checkDead()
{
	SnakeNode* loop = NULL;
	for (loop = gameData->snake->next; loop != NULL; loop = loop->next)
	{
		if (loop->x == gameData->snake->x && loop->y == gameData->snake->y)
		{
			return 1;//С������
		}
	}
	return 0;//С�߻���
}

void resetGame()
{
	//С�ߵ������ͷ�
	SnakeNode* loop = NULL;
	for (loop = gameData->snake_tail->prev; loop != NULL; loop = loop->prev)
	{
		free(loop->next);
		loop->next = NULL;
	}
	//����ͷ���ͷ�
	free(gameData->snake);
	gameData->snake = NULL;
	gameData->snake_tail = NULL;
	//������Ϸ����
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
	printText("С������", 16);
	resetGame();
}
/**
С�ߵĳ�ʼ��
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
		if (gameData->snake == NULL)//������һ������
		{
			gameData->snake = node;
			gameData->snake_tail = node;
		}
		else
		{
			//β�͵���һ�ڣ�ƴ�ӵ�ǰ�ڵ�
			gameData->snake_tail->next = node;
			//��ǰ�ڵ����һ�ڣ�ƴ�ӵ�β����
			node->prev = gameData->snake_tail;
			//��ǰ�ڵ�����Ϊβ��(����β��)
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
	setTitle("̰���ߣ���ľ�棩");
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
