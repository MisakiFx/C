/**
设置面板的定义文件
*/

#include "SettingPanel.h"
Panel* setting_panel = NULL;//设置面板全局变量
TextView setting_panel_views[] = {
	{5,2,0x9,0x0,12,"背景音乐(开/关):开"},
	{5,4,0x9,0x0,12,"音    效(开/关):开"},
	{5,6,0x9,0x0,12,"小蛇初始长度:3"},
	{5,8,0x9,0x0,12,"速度:、0"},
	{5,10,0x9,0x0,12,"背景:白"},
};
/**
游戏的设置信息
*/
Setting* setting_data = NULL;
/**

*/
void setting_initial()
{
	if (NULL == setting_data)
	{
		setting_data = (Setting*)malloc(sizeof(Setting));
		memset(setting_data, 0, sizeof(Setting));
		setting_data->map_width = 16;
		setting_data->map_height = 16;
		setting_data->snake_x = 2;
		setting_data->snake_y = 9;
		setting_data->snake_len = 3;
		setting_data->snake_color = 0xC;
		setting_data->snake_speed = 0.3;
		setting_data->direction = S_RIGHT;
	}
}
/**
设置面板的初始化
*/
void setting_panel_init()
{
	if (setting_panel == NULL)
	{
		setting_panel = panelInit();
	}
	setting_initial();
	setting_panel->x = 20;
	setting_panel->y = 2;
	setting_panel->width = 36;
	setting_panel->height = 18;
	setting_panel->bjColor = 0x0;
	setting_panel->color = 0xF;
}
/**
绘制设置面板
*/
void drawSettingPanel()
{
	setting_panel_init();
	if (NULL != setting_panel)
	{
		drawPanel(setting_panel);
		int len = sizeof(setting_panel_views) / sizeof(TextView);
		drawViews(setting_panel, setting_panel_views, len);
	}
}

Setting *getSettingData()
{
	if (NULL == setting_data)
	{
		setting_initial();
	}
	return setting_data;
}
