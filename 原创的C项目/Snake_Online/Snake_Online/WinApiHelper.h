#pragma once
/**
windows API帮助头文件
*/
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
/**
设置窗体的标题
title是标题的内容
*/
void setTitle(const char* title);
/**
设置窗体的大小
widgth 是窗体的宽，height 是窗体的高
*/
void setWinSize(int width, int height);
/**
设置光标位置
x坐标,y坐标
*/
void setCursorPosition(int x, int y);
/**
颜色的设置
color是颜色参数
*/
void setColor(int color);
/**
绘制横线
x坐标
y坐标
颜色
绘制字符
绘制长度
*/
void drawHLine(int x, int y,int color, int letter, int len);
/**
绘制竖线
x坐标
y坐标
颜色
绘制字符
绘制长度
*/
void drawVLine(int x, int y, int color, int letter, int len);
/**
文本输出函数
text输出的文本
size输出的长度
*/
void printText(const char* text, int size);
/**
字符填充函数
x坐标，y坐标,颜色,字符,宽度,高度
*/
void fillText(int x, int y, int color, int letter, int width, int height);
/**
读取一个字符
*/
char readChar();
/**
隐藏光标
*/
void disableCurrsole();
