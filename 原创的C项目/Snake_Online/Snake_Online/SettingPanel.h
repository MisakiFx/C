/**
���������������
*/
#pragma once
#include "Panel.h"
#include "GameData.h"
/**
���õĻ�����Ϣ
*/
typedef struct _setting_data
{
	int snake_x;//С�߳�ʼ��x����
	int snake_y;//С�߳�ʼ��y����
	int snake_color;//С�߳�ʼ��ɫ
	double snake_speed;//С�ߵ��ٶ�
	int snake_len;//С�ߵĳ�ʼ����
	int map_width;//��ͼ���
	int map_height;//��ͼ�߶�
	SnakeDirection direction;//С��Ĭ���ƶ�����
}Setting;
/**
�����������
*/
void drawSettingPanel();
/**
	�ⲿ��ȡ���ݺ���
*/
Setting* getSettingData();

