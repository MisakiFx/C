#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include "Management.h"
int main()
{
	if (load() == 0)
	{
		printf("设备信息读取失败！\n");
	}
	if (loadMaintain() == 0)
	{
		printf("维修信息读取失败！\n");
	}
	while (menu())
	{

	}
}