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
�����󶨺���
�󶨵İ����ṹ��
*/
void KeyBind(Key* key);
/**
�ַ���ȡ����
*/
char ReadChar();
/**
���ǰ����ⲿ���ú���
*/
void PersonKey();
/**
�˵������ⲿ���ú���
*/
void MenuKey();
