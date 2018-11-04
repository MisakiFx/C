/**
��������ʵ���ļ�
*/
#include "ControlPanel.h"
Panel* control_panel = NULL;//ȫ�����ָ��
/**
ȫ�ֿ����������¼�
*/
ControlPanelOperator* control_pan_op = NULL;
/**
�����ڿ��������Ҫչʾ�����
*/
TextView control_views[] = {
	{5,2,0xC,0x0,8,"����:0",0},
	{5,5,0xC,0x0,8,"����:0",0},
	{5,8,0xC,0x0,8,"��/��:0",0},
	{5,11,0x0,0xC,8,"��Ϸ",1},
	{5,14,0xC,0x0,8,"setting",1}
};
/**
���ݵ�ǰѡ�е������ʾ��Ӧ�����
*/
void viewPanelBySelected(int len)
{
	if (NULL != control_pan_op)
	{
		int queryIdx = querySelctedView(control_views, len, control_panel->bjColor);
		TextView *v = &control_views[queryIdx];
		if (strcmp(v->txt, "��Ϸ") == 0)
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
�������Ļ��ƺ���
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
	drawViews(control_panel, control_views, view_len);//�������еĿ���������
}
/**
�ڿ������ʱ�Ϸ������Ӧ����
*/
void control_panel_up_handle(char v)
{
	int len = sizeof(control_views) / sizeof(TextView);
	changeSelectedView(control_views, len, control_views->bjcolor, control_views->color, 0);
	drawViews(control_panel, control_views, len);
	viewPanelBySelected(len);
}
/**
�ڿ������ʱ�·������Ӧ����
*/
void control_panel_down_handle(char v)
{
	int len = sizeof(control_views) / sizeof(TextView);
	changeSelectedView(control_views, len, control_views->bjcolor, control_views->color, 1);
	drawViews(control_panel, control_views, len);
	viewPanelBySelected(len);
}
/**
�س����ķ�װ
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
���õİ����󶨺�ʵ�ֹ��ܺ���
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
	char score_str[50];//�޸ķ���ֵ
	sprintf_s(score_str, "����:%d", score);
	strcpy_s(control_views[0].txt, score_str);
	char len_str[50];
	sprintf_s(len_str, "����:%d", len);
	strcpy_s(control_views[1].txt, len_str);
	char speed_str[50];
	sprintf_s(speed_str, "��/��:%.2lf", speed);
	strcpy_s(control_views[2].txt, speed_str);
	drawControlPanel();
}
