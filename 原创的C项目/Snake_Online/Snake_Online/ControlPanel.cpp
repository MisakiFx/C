/**
控制面板的实现文件
*/
#include "ControlPanel.h"
Panel* control_panel = NULL;//全局面板指针
/**
全局控制面板操作事件
*/
ControlPanelOperator* control_pan_op = NULL;
/**
定义在控制面板中要展示的组件
*/
TextView control_views[] = {
	{5,2,0xC,0x0,8,"分数:0",0},
	{5,5,0xC,0x0,8,"长度:0",0},
	{5,8,0xC,0x0,8,"秒/格:0",0},
	{5,11,0x0,0xC,8,"游戏",1},
	{5,14,0xC,0x0,8,"setting",1}
};
/**
根据当前选中的组件显示对应的面板
*/
void viewPanelBySelected(int len)
{
	if (NULL != control_pan_op)
	{
		int queryIdx = querySelctedView(control_views, len, control_panel->bjColor);
		TextView *v = &control_views[queryIdx];
		if (strcmp(v->txt, "游戏") == 0)
		{
			if (control_pan_op->view_setting_panel != NULL)
			{
				control_pan_op->view_game_panel();
			}
		}
		else if(strcmp(v->txt, "setting") == 0)
		{
			if (control_pan_op->view_game_panel != NULL)
			{
				control_pan_op->view_setting_panel(); 
			}
		}
	}
}
/**
控制面板的绘制函数
*/
void drawControlPanel()
{
	if (control_panel == NULL)
	{
		control_panel = panelInit();
		control_panel->x = 2;
		control_panel->y = 2;
		control_panel->width = 18;
		control_panel->height = 18;
		control_panel->color = 0xE;
		control_panel->bjColor = 0x0;
	}
	drawPanel(control_panel);
	int view_len = sizeof(control_views) / sizeof(TextView);
	drawViews(control_panel, control_views, view_len);//绘制所有的控制面板组件
}
/**
在控制面板时上方向键对应函数
*/
void control_panel_up_handle(char v)
{
	int len = sizeof(control_views) / sizeof(TextView);
	changeSelectedView(control_views, len, control_views->bjcolor, control_views->color, 0);
	drawViews(control_panel, control_views, len);
	viewPanelBySelected(len);
}
/**
在控制面板时下方向键对应函数
*/
void control_panel_down_handle(char v)
{
	int len = sizeof(control_views) / sizeof(TextView);
	changeSelectedView(control_views, len, control_views->bjcolor, control_views->color, 1);
	drawViews(control_panel, control_views, len);
	viewPanelBySelected(len);
}
/**
回车键的封装
*/
void enter_key_press(char v)
{
	
	if (control_pan_op != NULL && control_pan_op->start_game != NULL)
	{
		int len = sizeof(control_views) / sizeof(TextView);
		int queryIdx = querySelctedView(control_views, len, control_panel->bjColor);
		if (queryIdx == 3)
		{
			control_pan_op->start_game();
		}
	}
}
/**
调用的按键绑定和实现功能函数
*/
void control_panel_key_bind()
{
	DefaultHandle handle = {control_panel_up_handle ,control_panel_down_handle };
	KeyMapping mappings[] = 
	{
		{13,enter_key_press}
	};
	int len = sizeof(mappings) / sizeof(KeyMapping);
	key_handle_operator(&handle, mappings, len);
}

void setControlPanelOperator(ControlPanelOperator * op)
{
	control_pan_op = op;
}

void setGameInfo(int score, int len, double speed)
{
	char score_str[50];//修改分数值
	sprintf_s(score_str, "分数:%d", score);
	strcpy_s(control_views[0].txt, score_str);
	char len_str[50];
	sprintf_s(len_str, "长度:%d", len);
	strcpy_s(control_views[1].txt, len_str);
	char speed_str[50];
	sprintf_s(speed_str, "秒/格:%.2lf", speed);
	strcpy_s(control_views[2].txt, speed_str);
	drawControlPanel();
}
