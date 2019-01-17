/**
��Ϸ���ݵ�����
*/
#pragma once
/**
�ߵ�����ڵ�ṹ
*/
typedef struct _snake_node 
{
	int x;//�������������
	int y;//���������������
	int color;//�����������ɫ
	_snake_node* next;//��һ������λ��
	_snake_node* prev;//��һ������λ��
}SnakeNode;
/**
ʳ�����ݽṹ
*/
typedef struct _food
{
	int x;//ʳ��ĺ�����
	int y;//ʳ���������
	int color;//ʳ�����ɫ
}Food;
/**
С���ƶ��ķ���
*/
typedef enum _snak_direction
{
	S_UP = 'w',//�Ϸ���
	S_DOWN = 's',//�·���
	S_LEFT = 'a',//����
	S_RIGHT = 'd'//�ҷ���
}SnakeDirection;
/**
��Ϸ����
*/
typedef struct _game_data
{
	int score;//�÷�
	int lenth;//����
	double speed;//�ٶ�
	int map_width;//��ͼ�Ŀ��
	int map_height;//��ͼ�ĸ߶�
	SnakeNode* snake;//С��
	SnakeNode* snake_tail;//С�ߵ�β��
	Food* food;//ʳ��
	SnakeDirection direction;//��ǰ�ƶ�����
}GameData;