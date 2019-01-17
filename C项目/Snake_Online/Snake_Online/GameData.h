/**
游戏数据的声明
*/
#pragma once
/**
蛇的身体节点结构
*/
typedef struct _snake_node 
{
	int x;//本节身体横坐标
	int y;//本节身体的纵坐标
	int color;//本节身体的颜色
	_snake_node* next;//下一节身体位置
	_snake_node* prev;//上一节身体位置
}SnakeNode;
/**
食物数据结构
*/
typedef struct _food
{
	int x;//食物的横坐标
	int y;//食物的纵坐标
	int color;//食物的颜色
}Food;
/**
小蛇移动的方向
*/
typedef enum _snak_direction
{
	S_UP = 'w',//上方向
	S_DOWN = 's',//下方向
	S_LEFT = 'a',//左方向
	S_RIGHT = 'd'//右方向
}SnakeDirection;
/**
游戏数据
*/
typedef struct _game_data
{
	int score;//得分
	int lenth;//长度
	double speed;//速度
	int map_width;//地图的宽度
	int map_height;//地图的高度
	SnakeNode* snake;//小蛇
	SnakeNode* snake_tail;//小蛇的尾巴
	Food* food;//食物
	SnakeDirection direction;//当前移动方向
}GameData;