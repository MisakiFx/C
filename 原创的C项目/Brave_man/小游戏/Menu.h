#pragma once
#include "Panel.h"
#include "Key.h"
#include "control.h"
/**
�˵�ѡ��
*/
typedef struct _menu_choice
{
	int x;//x����
	int y;//y����
	char string[50];//����
	int color;//ǰ��ɫ
	int bjColor;//����ɫ
}MenuChoice;
/**
�˵���ӡ����
*/
void drawMenuPanel();
/**
�˵�������ӡ����
*/
void drawPanelBackGround();
/**
�˵�ѡ���ӡ
*/
void menuChoicePrint();
/**
�˵����ƺ���
*/
int menu();
void menuPanelInit();
