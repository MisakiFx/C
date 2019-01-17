#pragma once
/**
基础面板的定义文件
*/
#include "WinApiHelper.h"
#include "KeyHandle.h"
/**
基础面板结构定义
*/
typedef struct _base_panel
{
	int x;	//x坐标
	int y;	//y坐标
	int width;//宽度
	int height;//高度
	char hLetter;//横线字符
	char vLetter;//竖线字符
	int color;	//前景色
	int bjColor;//背景色
}Panel;
/**
基础的展示组件
*/
typedef struct _base_text_view
{
	int x;//x坐标
	int y;//y坐标
	int color;//前景色
	int bjcolor;//背景色
	int size;//显示宽度
	char txt[50];//显示字符
	int selectAble;//是否可以选择(0不可选（默认），1可选)
}TextView;
/**
面板的初始化函数
*/
Panel* panelInit();
/**
面板的绘制函数
绘制的参数
*/
void drawPanel(Panel* panel);
/**
绘制控制面板组件函数
目标控制面板指针 目标组件指针 长度
*/
void drawViews(Panel* panel, TextView* views, int len);
/**
表示选中了哪个组件
所有的组件指针，组件个数，选中状态颜色
返回选中组件的下标
*/
int querySelctedView(TextView* views, int len, int color);
/**
选中组件的切换函数
所有的组件 长度 选中后的前景色 选中后的背景色 向上或向下选中
说明：选中后的颜色的前景色和背景色和选中前刚好相反
*/
void changeSelectedView(TextView* views, int len, int color, int bjcolor, int upOrDown);

