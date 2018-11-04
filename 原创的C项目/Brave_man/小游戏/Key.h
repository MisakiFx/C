#pragma once
#include "Panel.h"
#include "Menu.h"
#include "control.h"
typedef struct key
{
	void(*up)(char a);
	void(*down)(char a);
	void(*left)(char a);
	void(*right)(char a);
	void(*enter)(char a);
}Key;
/**
按键绑定函数
绑定的按键结构体
*/
void KeyBind(Key* key);
/**
字符读取函数
*/
char ReadChar();
/**
主角按键外部调用函数
*/
void PersonKey();
/**
菜单按键外部代用函数
*/
void MenuKey();
