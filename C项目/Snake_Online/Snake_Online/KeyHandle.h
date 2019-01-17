#pragma once
/**
�¼����������ļ�
*/
#include "WinApiHelper.h"
/**
����ṹ����Ĭ�ϵķ����
*/
typedef struct _default_key_Handle
{
	void(*up)(char);//�Ϸ���
	void(*down)(char);//�·���
	void(*left)(char);//����
	void(*right)(char);//�ҷ���
}DefaultHandle;
/**
�����λӳ��
*/
typedef struct _key_mapping 
{
	char key;//��λ
	void (*key_handle)(char);//��λ��Ӧ����
}KeyMapping;

/**
�ⲿ���õİ���������
handle:Ĭ�ϰ������� mappings:���ⰴ������ӳ�伯 len:ӳ�伯�ĳ���
*/
void key_handle_operator(DefaultHandle* handle, KeyMapping* mappings, int len);

