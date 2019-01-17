#pragma once
#include "Panel.h"
#include "Key.h"
#include "control.h"
/**
菜单选项
*/
typedef struct _menu_choice
{
	int x;//x坐标
	int y;//y坐标
	char string[50];//内容
	int color;//前景色
	int bjColor;//背景色
}MenuChoice;
/**
菜单打印函数
*/
void drawMenuPanel();
/**
菜单背景打印函数
*/
void drawPanelBackGround();
/**
菜单选项打印
*/
void menuChoicePrint();
/**
菜单控制函数
*/
int menu();
void menuPanelInit();
