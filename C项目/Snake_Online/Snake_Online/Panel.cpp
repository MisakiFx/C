/**
基础面板的实现文件
*/
#include "Panel.h"
/**
面板参数的初始化函数
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
面板的绘制函数
*/
void drawPanel(Panel * panel)
{
	//背景绘制
	fillText(panel->x, panel->y, panel->bjColor << 4 | panel->color, ' ', panel->width, panel->height);
	//竖线绘制
	drawVLine(panel->x, panel->y, panel->bjColor << 4 | panel->color, panel->vLetter, panel->height);
	drawVLine(panel->x + panel->width - 1, panel->y, panel->bjColor << 4 | panel->color, panel->vLetter, panel->height);
	//横线绘制
	drawHLine(panel->x, panel->y, panel->bjColor<<4|panel->color,panel->hLetter,panel->width);
	drawHLine(panel->x, panel->y+panel->height, panel->bjColor << 4 | panel->color, panel->hLetter, panel->width);
}
/**
控制面板组件绘制函数
*/
void drawViews(Panel * panel, TextView * views, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		TextView* v = views + i;//获取第i个展示组件的指针
		int x = panel->x + v->x;
		int y = panel->y + v->y;
		setCursorPosition(x, y);
		setColor(v->bjcolor << 4 | v->color);
		printText(v->txt, v->size);
	}
}
/**
查看选中了哪个组件
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
选中组件的切换函数
*/
void changeSelectedView(TextView * views, int len, int color, int bjcolor, int upOrDown)
{
	//当前是哪一个被选中
	int selectedIdx = querySelctedView(views, len, color);
	selectedIdx > -1 ? selectedIdx : 0;//默认第一个被选中
	//查找下一个被选中的组件
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
		//修改当前被选中组件的颜色
		TextView* selectedView = views + selectedIdx;
		selectedView->color = bjcolor;
		selectedView->bjcolor = color;
		//修改下一个被选中的组件的颜色
		nextSelected->color = color;
		nextSelected->bjcolor = bjcolor;
	}
}
