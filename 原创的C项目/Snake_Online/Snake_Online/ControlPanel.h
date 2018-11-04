#pragma once
/**
控制面板的定义文件
*/
#include "Panel.h"
/**
预制处理
*/
typedef struct _control_panel_operator
{
	void(*view_game_panel)();//显示游戏界面
	void(*view_setting_panel)();//显示设置界面
	void(*start_game)();//开始游戏
}ControlPanelOperator;
/**
控制面板的绘制函数
*/
void drawControlPanel();
/**
调用的按键绑定和实现功能函数
*/
void control_panel_key_bind();
/**
设置控制面板的处理函数
*/
void setControlPanelOperator(ControlPanelOperator* op);
/**
设置游戏过程中的相关信息
分数，长度，小蛇长度，速度
*/
void setGameInfo(int score, int len, double speed);