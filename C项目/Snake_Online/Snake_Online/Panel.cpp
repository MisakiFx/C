/**
��������ʵ���ļ�
*/
#include "Panel.h"
/**
�������ĳ�ʼ������
*/
Panel * panelInit()
{
	Panel* panel = (Panel*)malloc(sizeof(Panel));
	memset(panel, 0, sizeof(Panel));
	panel->width = 5;
	panel->height = 5;
	panel->hLetter = '-';
	panel->vLetter = '|';
	panel->color = 0xF;
	panel->bjColor = 0x0;
	return panel;
}
/**
���Ļ��ƺ���
*/
void drawPanel(Panel * panel)
{
	//��������
	fillText(panel->x, panel->y, panel->bjColor << 4 | panel->color, ' ', panel->width, panel->height);
	//���߻���
	drawVLine(panel->x, panel->y, panel->bjColor << 4 | panel->color, panel->vLetter, panel->height);
	drawVLine(panel->x + panel->width - 1, panel->y, panel->bjColor << 4 | panel->color, panel->vLetter, panel->height);
	//���߻���
	drawHLine(panel->x, panel->y, panel->bjColor<<4|panel->color,panel->hLetter,panel->width);
	drawHLine(panel->x, panel->y+panel->height, panel->bjColor << 4 | panel->color, panel->hLetter, panel->width);
}
/**
�������������ƺ���
*/
void drawViews(Panel * panel, TextView * views, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		TextView* v = views + i;//��ȡ��i��չʾ�����ָ��
		int x = panel->x + v->x;
		int y = panel->y + v->y;
		setCursorPosition(x, y);
		setColor(v->bjcolor << 4 | v->color);
		printText(v->txt, v->size);
	}
}
/**
�鿴ѡ�����ĸ����
*/
int querySelctedView(TextView * views, int len, int color)
{
	int i;
	for (i = 0; i < len; i++)
	{
		TextView* v = views + i;
		if (v->color == color)
		{
			return i;
		}
	}
	return -1;
}
/**
ѡ��������л�����
*/
void changeSelectedView(TextView * views, int len, int color, int bjcolor, int upOrDown)
{
	//��ǰ����һ����ѡ��
	int selectedIdx = querySelctedView(views, len, color);
	selectedIdx > -1 ? selectedIdx : 0;//Ĭ�ϵ�һ����ѡ��
	//������һ����ѡ�е����
	TextView* nextSelected = NULL;
	if (upOrDown)
	{
		int i;
		for (i = selectedIdx + 1; i < len + selectedIdx; i++)
		{
			TextView* v = views + (i % len);
			if (v->selectAble == 1)
			{
				nextSelected = v;
				break;
			}
		}
	}
	else
	{
		int i;
		for (i = len + selectedIdx - 1; i > 0; i--)
		{
			TextView* v = views + (i % len);
			if (v->selectAble == 1)
			{
				nextSelected = v;
				break;
			}
		}
	}
	if (nextSelected != NULL)
	{
		//�޸ĵ�ǰ��ѡ���������ɫ
		TextView* selectedView = views + selectedIdx;
		selectedView->color = bjcolor;
		selectedView->bjcolor = color;
		//�޸���һ����ѡ�е��������ɫ
		nextSelected->color = color;
		nextSelected->bjcolor = bjcolor;
	}
}
