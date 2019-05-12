#define _CRT_SECURE_NO_WARNINGS
#include "Management.h"
Equipment* equipment = NULL;//ȫ���豸����
Maintain* maintainMassage = NULL;//ȫ��ά����Ϣ����
/**
���˵�
*/
int menu()
{
	int choose = 0;
	printf("\t\t\t\t\t��ӭ����ʵ�����豸����ϵͳ��\n");
	printf("\t\t\t\t\t1����ʾ��ǰʵ�����豸��\n");
	printf("\t\t\t\t\t2������ʵ�����豸��\n");
	printf("\t\t\t\t\t3���޸ĵ�ǰʵ�����豸��Ϣ��\n");
	printf("\t\t\t\t\t4��ɾ����ǰʵ�����豸��\n");
	printf("\t\t\t\t\t5��ά�޵�ǰʵ�����豸��\n");
	printf("\t\t\t\t\t6����ʾ��ǰʵ�����豸ά�޼�¼��\n");
	printf("\t\t\t\t\t7�����ҵ�ǰʵ�����豸ά�޼�¼��\n");
	printf("\t\t\t\t\t8�����ά�޼�¼��\n");
	printf("\t\t\t\t\t0���˳�ϵͳ��\n");
	printf("��ѡ��:");
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
			printf("�豸��Ϣ�洢ʧ�ܣ�\n");
		}
		break;
	case 3:
		modify();
		if (save() == 0)
		{
			printf("�豸��Ϣ�洢ʧ�ܣ�\n");
		}
		break;
	case 4:
		del();
		if (save() == 0)
		{
			printf("�豸��Ϣ�洢ʧ�ܣ�\n");
		}
		break;
	case 5:
		maintain();
		if (save() == 0)
		{
			printf("�豸��Ϣ�洢ʧ�ܣ�\n");
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
��ʾ��ǰ�Ѵ洢���豸
*/
void printEquipment()
{
	if (equipment == NULL)
	{
		printf("��ǰ���Ѵ洢���豸��\n");
		return;
	}
	printf("\n��ǰʵ�����������豸Ϊ:\n");
	Equipment* p = equipment;
	while (p != NULL)
	{
		printf("�豸���:%d\n",p->data.ID);
		printf("�豸����:%s\n", p->data.name);
		printf("�豸�ͺ�:%s\n", p->data.kind);
		printf("�豸����:%s\n", p->data.manufacturer);
		printf("��������:%d��%d��%d��\n", p->data.buyYear, p->data.buyMonth, p->data.buyDay);
		printf("״̬:%s\n", (p->data.state == 1) ? "����" : "��ά��");
		printf("\n");
		p = p->next;
	}
}
/**
��ͷ������
*/
void addHead()
{
	Equipment* p = (Equipment*)malloc(sizeof(Equipment));
	printf("�������豸�ı�ţ�");
	scanf("%d", &p->data.ID);
	printf("�������豸�����ƣ�");
	scanf("%s", p->data.name, 50);
	printf("�������豸���ͺţ�");
	scanf("%s", p->data.kind, 20);
	printf("�������豸�ĳ��ң�");
	scanf("%s", p->data.manufacturer, 50);
	printf("�������豸��������ڣ��������м��Կո��������");
	scanf("%d", &p->data.buyYear);
	scanf("%d", &p->data.buyMonth);
	scanf("%d", &p->data.buyDay);
	printf("�������豸״̬(0:��ά��;1:����)��");
	scanf("%d", &p->data.state);
	p->next = equipment;
	equipment = p;
}
/**
�洢
*/
int save()
{
	FILE* fp = fopen("1.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 0;
	}
	Equipment* p = equipment;
	if (p == NULL)//������
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
��ʾ�˵�
*/
void printMenu()
{
	int choose;
	printf("\t\t\t\t\t1����ID��С������ʾ��\n");
	printf("\t\t\t\t\t2����ID�Ӵ�С��ʾ��\n");
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
����ID��С����
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
��ID�Ӵ�С����
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
	printf("�����Ҫ�޸ĵ��豸��ID��");
	scanf("%d", &modifyID);
	Equipment* p = equipment;
	if (p == NULL)
	{
		printf("δ�ҵ���Ӧ�豸��\n");
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
		printf("δ�ҵ���Ӧ�豸��\n");
	}
	else
	{
		printf("�������豸�޸ĺ�ı�ţ�");
		scanf("%d", &p->data.ID);
		printf("�������豸�޸ĺ�����ƣ�");
		scanf("%s", p->data.name, 50);
		printf("�������豸�޸ĺ���ͺţ�");
		scanf("%s", p->data.kind, 20);
		printf("�������豸�޸ĺ�ĳ��ң�");
		scanf("%s", p->data.manufacturer, 50);
		printf("�������豸�޸ĺ�������ڣ��������м��Կո��������");
		scanf("%d", &p->data.buyYear);
		scanf("%d", &p->data.buyMonth);
		scanf("%d", &p->data.buyDay);
		printf("�������豸״̬(0:��ά��;1:����)��");
		scanf("%d", &p->data.state);
	}
}
/**
ɾ��
*/
void del()
{
	int delID;
	printf("������Ҫɾ�����豸ID��");
	scanf("%d", &delID);
	Equipment* p = equipment;
	Equipment* q = equipment;
	if (p == NULL)
	{
		printf("δ�ҵ���Ӧ���豸��\n");
		return;
	}
	if (p->data.ID == delID)
	{
		equipment = p->next;
		free(p);
		printf("\nɾ���ɹ���\n");
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
		printf("δ�ҵ���Ӧ���豸��\n");
	}
	else
	{
		q->next = p->next;
		free(p);
		printf("\nɾ���ɹ���\n");
	}
}
/**
ά���豸
*/
void maintain()
{
	int maintainID;
	printf("������Ҫά�޵��豸��ID��");
	scanf("%d", &maintainID);
	Equipment* p = equipment;
	if (p == NULL)
	{
		printf("δ�ҵ���Ӧ�豸��\n");
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
		printf("δ�ҵ���Ӧ���豸��\n");
		return;
	}
	else
	{
		if (p->data.state == 1)
		{
			printf("��ǰ�豸����Ҫά�ޣ�\n");
		}
		else
		{
			p->data.state = 1;
			Maintain* p = (Maintain*)malloc(sizeof(Maintain));
			printf("������ά����Ϣ\n");
			printf("ά������(�����ռ��Կո����):");
			scanf("%d%d%d", &p->data.maintainYear,&p->data.maintainMonth,&p->data.maintainDay);
			p->data.ID = maintainID;
			p->next = maintainMassage;
			maintainMassage = p;
			printf("ά�޳ɹ���\n");
			if (saveMaintain() == 0)
			{
				printf("ά����Ϣ�洢ʧ�ܣ�\n");
			}
		}
	}
}
/**
ά����Ϣ��ȡ
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
ά����Ϣ�洢
*/
int saveMaintain()
{
	FILE* fp = fopen("myfile.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 0;
	}
	Maintain* p = maintainMassage;
	if (p == NULL)//������
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
		printf("ά����Ϣ���ޣ�\n");
		return;
	}
	while (p != NULL)
	{
		printf("ά�����ڣ�%d��%d��%d��\n", p->data.maintainYear, p->data.maintainMonth, p->data.maintainDay);
		printf("ά�޵Ļ�����ţ�%d\n", p->data.ID);
		printf("\n");
		p = p->next;
	}
}
/**
����ά�޼�¼
*/
void findMaintain()
{
	int count = 0;
	Maintain* p = maintainMassage;
	if (p == NULL)
	{
		printf("δ�ҵ���Ӧά�޼�¼��\n");
		return;
	}
	int year, month, day;
	printf("\n������Ҫ���ҵ����ڣ�");
	scanf("%d%d%d", &year, &month, &day);
	while (p != NULL)
	{
		if (p->data.maintainYear == year && p->data.maintainMonth == month && p->data.maintainDay == day)
		{
			printf("\nά�����ڣ�%d��%d��%d��\n", p->data.maintainYear, p->data.maintainMonth, p->data.maintainDay);
			printf("ά�޵Ļ�����ţ�%d\n", p->data.ID);
			printf("\n");
			count++;
		}
		p = p->next;
	}
	if (count == 0)
	{
		printf("�޼�¼��\n");
	}
	else
	{
		printf("���ҵ�%d��ά�޼�¼��\n", count);
	}
}

void cleanMaintain()
{
	Maintain* p = maintainMassage;
	Maintain* q = p;
	if (p == NULL)
	{
		printf("�����ɣ�\n");
		return;
	}
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	maintainMassage = NULL;
	printf("��ճɹ���\n");
	if (saveMaintain() == 0)
	{
		printf("ά����Ϣ�洢ʧ�ܣ�\n");
	}
}
