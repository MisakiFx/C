#pragma once
/**
�������Ķ����ļ�
*/
#include "WinApiHelper.h"
#include "KeyHandle.h"
/**
�������ṹ����
*/
typedef struct _base_panel
{
	int x;	//x����
	int y;	//y����
	int width;//���
	int height;//�߶�
	char hLetter;//�����ַ�
	char vLetter;//�����ַ�
	int color;	//ǰ��ɫ
	int bjColor;//����ɫ
}Panel;
/**
������չʾ���
*/
typedef struct _base_text_view
{
	int x;//x����
	int y;//y����
	int color;//ǰ��ɫ
	int bjcolor;//����ɫ
	int size;//��ʾ���
	char txt[50];//��ʾ�ַ�
	int selectAble;//�Ƿ����ѡ��(0����ѡ��Ĭ�ϣ���1��ѡ)
}TextView;
/**
���ĳ�ʼ������
*/
Panel* panelInit();
/**
���Ļ��ƺ���
���ƵĲ���
*/
void drawPanel(Panel* panel);
/**
���ƿ�������������
Ŀ��������ָ�� Ŀ�����ָ�� ����
*/
void drawViews(Panel* panel, TextView* views, int len);
/**
��ʾѡ�����ĸ����
���е����ָ�룬���������ѡ��״̬��ɫ
����ѡ��������±�
*/
int querySelctedView(TextView* views, int len, int color);
/**
ѡ��������л�����
���е���� ���� ѡ�к��ǰ��ɫ ѡ�к�ı���ɫ ���ϻ�����ѡ��
˵����ѡ�к����ɫ��ǰ��ɫ�ͱ���ɫ��ѡ��ǰ�պ��෴
*/
void changeSelectedView(TextView* views, int len, int color, int bjcolor, int upOrDown);

