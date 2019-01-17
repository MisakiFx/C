#pragma once
/**
�������Ķ����ļ�
*/
#include "Panel.h"
/**
Ԥ�ƴ���
*/
typedef struct _control_panel_operator
{
	void(*view_game_panel)();//��ʾ��Ϸ����
	void(*view_setting_panel)();//��ʾ���ý���
	void(*start_game)();//��ʼ��Ϸ
}ControlPanelOperator;
/**
�������Ļ��ƺ���
*/
void drawControlPanel();
/**
���õİ����󶨺�ʵ�ֹ��ܺ���
*/
void control_panel_key_bind();
/**
���ÿ������Ĵ�����
*/
void setControlPanelOperator(ControlPanelOperator* op);
/**
������Ϸ�����е������Ϣ
���������ȣ�С�߳��ȣ��ٶ�
*/
void setGameInfo(int score, int len, double speed);