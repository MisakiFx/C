#define _CRT_SECURE_NO_WARNINGS
#include "Management.h"
Equipment* equipment = NULL;//全局设备链表
Maintain* maintainMassage = NULL;//全局维修信息链表
/**
主菜单
*/
int menu()
{
	int choose = 0;
	printf("\t\t\t\t\t欢迎进入实验室设备管理系统！\n");
	printf("\t\t\t\t\t1、显示当前实验室设备！\n");
	printf("\t\t\t\t\t2、增加实验室设备！\n");
	printf("\t\t\t\t\t3、修改当前实验室设备信息！\n");
	printf("\t\t\t\t\t4、删除当前实验室设备！\n");
	printf("\t\t\t\t\t5、维修当前实验室设备！\n");
	printf("\t\t\t\t\t6、显示当前实验室设备维修记录！\n");
	printf("\t\t\t\t\t7、查找当前实验室设备维修记录！\n");
	printf("\t\t\t\t\t8、清空维修记录！\n");
	printf("\t\t\t\t\t0、退出系统！\n");
	printf("请选择:");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		printMenu();
		break;
	case 2:
		addHead();
		if (save() == 0)
		{
			printf("设备信息存储失败！\n");
		}
		break;
	case 3:
		modify();
		if (save() == 0)
		{
			printf("设备信息存储失败！\n");
		}
		break;
	case 4:
		del();
		if (save() == 0)
		{
			printf("设备信息存储失败！\n");
		}
		break;
	case 5:
		maintain();
		if (save() == 0)
		{
			printf("设备信息存储失败！\n");
		}
		break;
	case 6:
		printMaintain();
		break;
	case 7:
		findMaintain();
		break;
	case 8:
		cleanMaintain();
		break;
	default:
		break;
	}
	return choose;
}
/**
显示当前已存储的设备
*/
void printEquipment()
{
	if (equipment == NULL)
	{
		printf("当前无已存储的设备！\n");
		return;
	}
	printf("\n当前实验室中已有设备为:\n");
	Equipment* p = equipment;
	while (p != NULL)
	{
		printf("设备编号:%d\n",p->data.ID);
		printf("设备名称:%s\n", p->data.name);
		printf("设备型号:%s\n", p->data.kind);
		printf("设备厂家:%s\n", p->data.manufacturer);
		printf("购买日期:%d年%d月%d日\n", p->data.buyYear, p->data.buyMonth, p->data.buyDay);
		printf("状态:%s\n", (p->data.state == 1) ? "正常" : "待维修");
		printf("\n");
		p = p->next;
	}
}
/**
从头部插入
*/
void addHead()
{
	Equipment* p = (Equipment*)malloc(sizeof(Equipment));
	printf("请输入设备的编号：");
	scanf("%d", &p->data.ID);
	printf("请输入设备的名称：");
	scanf("%s", p->data.name, 50);
	printf("请输入设备的型号：");
	scanf("%s", p->data.kind, 20);
	printf("请输入设备的厂家：");
	scanf("%s", p->data.manufacturer, 50);
	printf("请输入设备购买的日期（年月日中间以空格隔开）：");
	scanf("%d", &p->data.buyYear);
	scanf("%d", &p->data.buyMonth);
	scanf("%d", &p->data.buyDay);
	printf("请输入设备状态(0:待维修;1:正常)：");
	scanf("%d", &p->data.state);
	p->next = equipment;
	equipment = p;
}
/**
存储
*/
int save()
{
	FILE* fp = fopen("1.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		return 0;
	}
	Equipment* p = equipment;
	if (p == NULL)//无数据
	{
		fclose(fp);
		return 1;
	}
	while (p != NULL)
	{
		fwrite(&p->data, sizeof(EquipmentData), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return 1;
}
/**
显示菜单
*/
void printMenu()
{
	int choose;
	printf("\t\t\t\t\t1、按ID从小到大显示！\n");
	printf("\t\t\t\t\t2、按ID从大到小显示！\n");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		sort1();
		printEquipment();
		break;
	case 2:
		sort2();
		printEquipment();
		break;
	}
}
/**
排序按ID从小到大
*/
void sort1()
{
	Equipment* p = equipment;
	if (p == NULL)
	{
		return;
	}
	while (p->next != NULL)
	{
		Equipment* q = p->next;
		while (q != NULL)
		{
			if (q->data.ID < p->data.ID)
			{
				EquipmentData t = p->data;
				p->data = q->data;
				q->data = t;
			}
			q = q->next;
		}
		p = p->next;
	}
}
/**
按ID从大到小排序
*/
void sort2()
{
	Equipment* p = equipment;
	if (p == NULL)
	{
		return;
	}
	while (p->next != NULL)
	{
		Equipment* q = p->next;
		while (q != NULL)
		{
			if (q->data.ID > p->data.ID)
			{
				EquipmentData t = p->data;
				p->data = q->data;
				q->data = t;
			}
			q = q->next;
		}
		p = p->next;
	}
}

int load()
{
	FILE* fp = fopen("1.txt", "r");
	if (fp == NULL)
	{
		return 1;
	}
	Equipment* tHead = NULL;
	EquipmentData data;
	while (fread(&data, sizeof(EquipmentData), 1, fp))
	{
		Equipment* p = (Equipment*)malloc(sizeof(Equipment));
		p->data = data;
		p->next = tHead;
		tHead = p;
	}
	equipment = tHead;
	fclose(fp);
	return 1;
}

void modify()
{
	int modifyID;
	printf("请输出要修改的设备的ID：");
	scanf("%d", &modifyID);
	Equipment* p = equipment;
	if (p == NULL)
	{
		printf("未找到对应设备！\n");
		return;
	}
	while (p != NULL)
	{
		if (p->data.ID == modifyID)
		{
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("未找到对应设备！\n");
	}
	else
	{
		printf("请输入设备修改后的编号：");
		scanf("%d", &p->data.ID);
		printf("请输入设备修改后的名称：");
		scanf("%s", p->data.name, 50);
		printf("请输入设备修改后的型号：");
		scanf("%s", p->data.kind, 20);
		printf("请输入设备修改后的厂家：");
		scanf("%s", p->data.manufacturer, 50);
		printf("请输入设备修改后购买的日期（年月日中间以空格隔开）：");
		scanf("%d", &p->data.buyYear);
		scanf("%d", &p->data.buyMonth);
		scanf("%d", &p->data.buyDay);
		printf("请输入设备状态(0:待维修;1:正常)：");
		scanf("%d", &p->data.state);
	}
}
/**
删除
*/
void del()
{
	int delID;
	printf("请输入要删除的设备ID：");
	scanf("%d", &delID);
	Equipment* p = equipment;
	Equipment* q = equipment;
	if (p == NULL)
	{
		printf("未找到对应的设备！\n");
		return;
	}
	if (p->data.ID == delID)
	{
		equipment = p->next;
		free(p);
		printf("\n删除成功！\n");
		return;
	}
	while (p != NULL)
	{
		if (p->data.ID == delID)
		{
			break;
		}
		q = p;
		p = p->next;
	}
	if (p == NULL)
	{
		printf("未找到对应的设备！\n");
	}
	else
	{
		q->next = p->next;
		free(p);
		printf("\n删除成功！\n");
	}
}
/**
维修设备
*/
void maintain()
{
	int maintainID;
	printf("请输入要维修的设备的ID：");
	scanf("%d", &maintainID);
	Equipment* p = equipment;
	if (p == NULL)
	{
		printf("未找到对应设备！\n");
		return;
	}
	while (p != NULL)
	{
		if (p->data.ID == maintainID)
		{
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("未找到对应的设备！\n");
		return;
	}
	else
	{
		if (p->data.state == 1)
		{
			printf("当前设备不需要维修！\n");
		}
		else
		{
			p->data.state = 1;
			Maintain* p = (Maintain*)malloc(sizeof(Maintain));
			printf("请输入维修信息\n");
			printf("维修日期(年月日间以空格隔开):");
			scanf("%d%d%d", &p->data.maintainYear,&p->data.maintainMonth,&p->data.maintainDay);
			p->data.ID = maintainID;
			p->next = maintainMassage;
			maintainMassage = p;
			printf("维修成功！\n");
			if (saveMaintain() == 0)
			{
				printf("维修信息存储失败！\n");
			}
		}
	}
}
/**
维修信息读取
*/
int loadMaintain()
{
	FILE* fp = fopen("myfile.txt", "r");
	if (fp == NULL)
	{
		return 1;
	}
	Maintain* tHead = NULL;
	MaintainData data;
	while (fread(&data, sizeof(MaintainData), 1, fp))
	{
		Maintain* p = (Maintain*)malloc(sizeof(Maintain));
		p->data = data;
		p->next = tHead;
		tHead = p;
	}
	maintainMassage = tHead;
	fclose(fp);
	return 1;
}
/**
维修信息存储
*/
int saveMaintain()
{
	FILE* fp = fopen("myfile.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		return 0;
	}
	Maintain* p = maintainMassage;
	if (p == NULL)//无数据
	{
		fclose(fp);
		return 1;
	}
	while (p != NULL)
	{
		fwrite(&p->data, sizeof(MaintainData), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return 1;
}

void printMaintain()
{
	Maintain* p = maintainMassage;
	if (p == NULL)
	{
		printf("维修信息暂无！\n");
		return;
	}
	while (p != NULL)
	{
		printf("维修日期：%d年%d月%d日\n", p->data.maintainYear, p->data.maintainMonth, p->data.maintainDay);
		printf("维修的机器编号：%d\n", p->data.ID);
		printf("\n");
		p = p->next;
	}
}
/**
查找维修记录
*/
void findMaintain()
{
	int count = 0;
	Maintain* p = maintainMassage;
	if (p == NULL)
	{
		printf("未找到对应维修记录！\n");
		return;
	}
	int year, month, day;
	printf("\n请输入要查找的日期：");
	scanf("%d%d%d", &year, &month, &day);
	while (p != NULL)
	{
		if (p->data.maintainYear == year && p->data.maintainMonth == month && p->data.maintainDay == day)
		{
			printf("\n维修日期：%d年%d月%d日\n", p->data.maintainYear, p->data.maintainMonth, p->data.maintainDay);
			printf("维修的机器编号：%d\n", p->data.ID);
			printf("\n");
			count++;
		}
		p = p->next;
	}
	if (count == 0)
	{
		printf("无记录！\n");
	}
	else
	{
		printf("共找到%d条维修记录！\n", count);
	}
}

void cleanMaintain()
{
	Maintain* p = maintainMassage;
	Maintain* q = p;
	if (p == NULL)
	{
		printf("清空完成！\n");
		return;
	}
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	maintainMassage = NULL;
	printf("清空成功！\n");
	if (saveMaintain() == 0)
	{
		printf("维修信息存储失败！\n");
	}
}
