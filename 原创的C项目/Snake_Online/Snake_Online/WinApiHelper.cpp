#include "WinApiHelper.h"
/**
winodws API帮助实现文件
*/

HANDLE std_win_handle = 0;//定义一个全局的句柄
/**
获取标准的输出句柄
*/
void setWinHandle()
{
	if (std_win_handle == 0)
	{
		std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);//让句柄指向标准的输出句柄
	}
}
/**
设置控制台的标题
*/
void setTitle(const char* title)
{
	SetConsoleTitle(TEXT(title));
}
/**
设置窗体的尺寸需要使用setWindowInfo实现，还需要窗体的句柄
*/
void setWinSize(int width, int height)
{
	SMALL_RECT rect = { 0,0,width - 1, height - 1 };//利用SMALL_RECT结构体表示窗体区域大小（起点-终点）
	COORD coord = { width,height };//利用COORD结构体表示缓冲区区域坐标（在控制台的输出打印位置）
	setWinHandle();//得到标准的输出句柄，放在定义的全局句柄中
	SetConsoleScreenBufferSize(std_win_handle,coord);//调用函数设置缓冲区位置
	SetConsoleWindowInfo(std_win_handle, TRUE, &rect);//调用函数设置窗体大小
}
/**
设置光标位置
*/
void setCursorPosition(int x, int y)
{
	COORD pos = { x,y };//表示光标的位置
	setWinHandle();//得到输出句柄
	SetConsoleCursorPosition(std_win_handle, pos);//设置光标位置
}
/**
设置文字颜色
*/
void setColor(int color)
{
	setWinHandle();//得到句柄
	SetConsoleTextAttribute(std_win_handle, color);
}
/**
绘制横线
*/
void drawHLine(int x, int y, int color, int letter, int len)
{
	setCursorPosition(x, y);
	setColor(color);
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%c",letter);
	}
}
/**
绘制竖线
*/
void drawVLine(int x, int y, int color, int letter, int len)
{
	setCursorPosition(x, y);
	setColor(color);
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%c", letter);
		setCursorPosition(x, ++y);
	}
}
/**
文本输出函数
*/
void printText(const char * text, int size)
{
	char format[30] = "%-";//目标格式字符串
	char sizebuf[5];
	_itoa_s(size, sizebuf,10);//将size中的整数值转换为字符型
	strcat_s(format,sizebuf);//将sizebuf拼接到format后面
	strcat_s(format, "s");//将"s"拼接到format后面
	printf(format, text);//将格式字符串作为参数，进行格式操作
}
/**
区域填充函数
*/
void fillText(int x, int y, int color, int letter, int width, int height)
{
	setWinHandle();
	DWORD relen;
	int i;
	for (i = 0; i < height; i++)
	{
		COORD coord = { x,y++ };
		FillConsoleOutputAttribute(std_win_handle, color, width, coord, &relen);
		FillConsoleOutputCharacter(std_win_handle, letter, width, coord, &relen);
	}
}
/**
从键盘中读取一个字符
*/
char readChar()
{
	char rech = 0;//返回的字符
	if (_kbhit())
	{
		rech = _getch();
	}
	return rech;
}
/**
隐藏光标
*/
void disableCurrsole()
{
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(std_win_handle, &cursor_info);
}
