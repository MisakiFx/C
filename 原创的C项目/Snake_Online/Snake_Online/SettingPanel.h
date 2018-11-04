/**
设置面板的声明面板
*/
#pragma once
#include "Panel.h"
#include "GameData.h"
/**
设置的基本信息
*/
typedef struct _setting_data
{
	int snake_x;//小蛇初始的x坐标
	int snake_y;//小蛇初始的y坐标
	int snake_color;//小蛇初始颜色
	double snake_speed;//小蛇的速度
	int snake_len;//小蛇的初始长度
	int map_width;//地图宽度
	int map_height;//地图高度
	SnakeDirection direction;//小蛇默认移动方向
}Setting;
/**
绘制设置面板
*/
void drawSettingPanel();
/**
	外部获取数据函数
*/
Setting* getSettingData();

