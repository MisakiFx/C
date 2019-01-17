#pragma once
#include <stdio.h>
#include <windows.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <mmsystem.h>//导入声音头文件
#pragma comment(lib,"Winmm.lib")
#include "Key.h"
typedef struct _person
{
	int x;//坐标
	int y;
}Person;
typedef struct _panel
{
	int x;//起点
	int y;
	int width;//宽
	int high;//高
	char a;//打印的字符
}Panel;
typedef struct _stone_data
{
	int x;
	int y;
	int bjcolor;
	int qjcolor;
}StoneData;
typedef struct _stone
{
	StoneData stonedata;
	struct _stone* next;
}Stone;
/**
设置标题
*/
void setTitle();
/**
设置光标位置
*/
void setCursorPosition(int x, int y);
/**
设置窗口大小
*/
void setWinSize(int width, int high);
/**
绘制横线
起点坐标 长度 字符
*/
void drawXLine(int x, int y, int len, char a);
/**
绘制竖线
*/
void drawYLine(int x, int y, int len, char a);
/**
绘制界面边框
*/
void drawPanel(int x, int y, int width, int high, char a);
/**
绘制障碍物
*/
void drawStone();
/**
绘制游戏界面
*/
void drawGame();
/**
隐藏光标
*/
void disableCurrsole();
/**
障碍物控制函数
*/
void stoneControl();
/**
清屏函数
*/
void clean();
/**
绘制主角
*/
void drawPerson();
/**
设置句柄
*/
void setHandle();
/**
设置颜色
*/
void setColor(int color);
/**
判断是否死亡函数
*/
int isDead();
/**
分数及速度打印
*/
void messagePrint();
/**
游戏说明界面打印
(这也是我写的最后一个函数了。。终于结束了)
(我不会告诉你其实还有个彩蛋！！)
*/
void gameInstruction();