#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include "Management.h"
int main()
{
	if (load() == 0)
	{
		printf("�豸��Ϣ��ȡʧ�ܣ�\n");
	}
	if (loadMaintain() == 0)
	{
		printf("ά����Ϣ��ȡʧ�ܣ�\n");
	}
	while (menu())
	{

	}
}