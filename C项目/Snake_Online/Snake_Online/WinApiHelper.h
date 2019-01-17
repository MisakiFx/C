#pragma once
/**
windows API����ͷ�ļ�
*/
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
/**
���ô���ı���
title�Ǳ��������
*/
void setTitle(const char* title);
/**
���ô���Ĵ�С
widgth �Ǵ���Ŀ�height �Ǵ���ĸ�
*/
void setWinSize(int width, int height);
/**
���ù��λ��
x����,y����
*/
void setCursorPosition(int x, int y);
/**
��ɫ������
color����ɫ����
*/
void setColor(int color);
/**
���ƺ���
x����
y����
��ɫ
�����ַ�
���Ƴ���
*/
void drawHLine(int x, int y,int color, int letter, int len);
/**
��������
x����
y����
��ɫ
�����ַ�
���Ƴ���
*/
void drawVLine(int x, int y, int color, int letter, int len);
/**
�ı��������
text������ı�
size����ĳ���
*/
void printText(const char* text, int size);
/**
�ַ���亯��
x���꣬y����,��ɫ,�ַ�,���,�߶�
*/
void fillText(int x, int y, int color, int letter, int width, int height);
/**
��ȡһ���ַ�
*/
char readChar();
/**
���ع��
*/
void disableCurrsole();
