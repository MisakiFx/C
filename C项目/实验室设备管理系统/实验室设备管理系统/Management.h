#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
/**
设备类信息结构
*/
typedef struct _equipment_data
{
	int ID;//编号
	char name[50];//名称
	char kind[20];//型号
	char manufacturer[50];//厂家
	int buyYear;//购买的年
	int buyMonth;//月
	int buyDay;//日
	int state;//状态（0坏，1好）
}EquipmentData;
/**
定义维修信息类数据
*/
typedef struct _maintain_data
{
	int maintainYear;//维修的年
	int maintainMonth;//月
	int maintainDay;//日
	int ID;//维修设备编号
}MaintainData;
/**
维修信息类
*/
typedef struct _maintain
{
	MaintainData data;
	struct _maintain* next;
}Maintain;
/**
设备类结构
*/
typedef struct _equipment
{
	EquipmentData data;
	struct _equipment* next;
}Equipment;
/**
显示当前已存储的设备
*/
void printEquipment();
/**
菜单打印调用
返回选项
*/
int menu();
/**
存储(头部)
*/
void addHead();
/**
信息存储函数
*/
int save();
/**
显示菜单
*/
void printMenu();
/**
排序(按照ID从小到大)
*/
void sort1();
/**
排序(按照ID从大到小)
*/
void sort2();
/**
读取
*/
int load();
/**
修改
*/
void modify();
/**
删除当前实验室设备
*/
void del();
/**
维修设备
*/
void maintain();
/**
维修信息读取
*/
int loadMaintain();
/**
维修信息存储
*/
int saveMaintain();
/**
显示当前实验室设备维修记录
*/
void printMaintain();
/**
查找维修记录
*/
void findMaintain();
/**
清空维修记录
*/
void cleanMaintain();
