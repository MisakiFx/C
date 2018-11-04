#pragma once
#include <stdio.h>
#include <windows.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <mmsystem.h>//��������ͷ�ļ�
#pragma comment(lib,"Winmm.lib")
#include "Key.h"
typedef struct _person
{
	int x;//����
	int y;
}Person;
typedef struct _panel
{
	int x;//���
	int y;
	int width;//��
	int high;//��
	char a;//��ӡ���ַ�
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
���ñ���
*/
void setTitle();
/**
���ù��λ��
*/
void setCursorPosition(int x, int y);
/**
���ô��ڴ�С
*/
void setWinSize(int width, int high);
/**
���ƺ���
������� ���� �ַ�
*/
void drawXLine(int x, int y, int len, char a);
/**
��������
*/
void drawYLine(int x, int y, int len, char a);
/**
���ƽ���߿�
*/
void drawPanel(int x, int y, int width, int high, char a);
/**
�����ϰ���
*/
void drawStone();
/**
������Ϸ����
*/
void drawGame();
/**
���ع��
*/
void disableCurrsole();
/**
�ϰ�����ƺ���
*/
void stoneControl();
/**
��������
*/
void clean();
/**
��������
*/
void drawPerson();
/**
���þ��
*/
void setHandle();
/**
������ɫ
*/
void setColor(int color);
/**
�ж��Ƿ���������
*/
int isDead();
/**
�������ٶȴ�ӡ
*/
void messagePrint();
/**
��Ϸ˵�������ӡ
(��Ҳ����д�����һ�������ˡ������ڽ�����)
(�Ҳ����������ʵ���и��ʵ�����)
*/
void gameInstruction();