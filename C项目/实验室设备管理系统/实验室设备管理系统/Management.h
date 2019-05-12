#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
/**
�豸����Ϣ�ṹ
*/
typedef struct _equipment_data
{
	int ID;//���
	char name[50];//����
	char kind[20];//�ͺ�
	char manufacturer[50];//����
	int buyYear;//�������
	int buyMonth;//��
	int buyDay;//��
	int state;//״̬��0����1�ã�
}EquipmentData;
/**
����ά����Ϣ������
*/
typedef struct _maintain_data
{
	int maintainYear;//ά�޵���
	int maintainMonth;//��
	int maintainDay;//��
	int ID;//ά���豸���
}MaintainData;
/**
ά����Ϣ��
*/
typedef struct _maintain
{
	MaintainData data;
	struct _maintain* next;
}Maintain;
/**
�豸��ṹ
*/
typedef struct _equipment
{
	EquipmentData data;
	struct _equipment* next;
}Equipment;
/**
��ʾ��ǰ�Ѵ洢���豸
*/
void printEquipment();
/**
�˵���ӡ����
����ѡ��
*/
int menu();
/**
�洢(ͷ��)
*/
void addHead();
/**
��Ϣ�洢����
*/
int save();
/**
��ʾ�˵�
*/
void printMenu();
/**
����(����ID��С����)
*/
void sort1();
/**
����(����ID�Ӵ�С)
*/
void sort2();
/**
��ȡ
*/
int load();
/**
�޸�
*/
void modify();
/**
ɾ����ǰʵ�����豸
*/
void del();
/**
ά���豸
*/
void maintain();
/**
ά����Ϣ��ȡ
*/
int loadMaintain();
/**
ά����Ϣ�洢
*/
int saveMaintain();
/**
��ʾ��ǰʵ�����豸ά�޼�¼
*/
void printMaintain();
/**
����ά�޼�¼
*/
void findMaintain();
/**
���ά�޼�¼
*/
void cleanMaintain();
