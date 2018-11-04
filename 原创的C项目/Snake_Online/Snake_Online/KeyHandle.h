#pragma once
/**
事件处理声明文件
*/
#include "WinApiHelper.h"
/**
定义结构处理默认的方向键
*/
typedef struct _default_key_Handle
{
	void(*up)(char);//上方向
	void(*down)(char);//下方向
	void(*left)(char);//左方向
	void(*right)(char);//右方向
}DefaultHandle;
/**
特殊键位映射
*/
typedef struct _key_mapping 
{
	char key;//键位
	void (*key_handle)(char);//键位对应处理
}KeyMapping;

/**
外部调用的按键处理函数
handle:默认按键处理 mappings:特殊按键处理映射集 len:映射集的长度
*/
void key_handle_operator(DefaultHandle* handle, KeyMapping* mappings, int len);

