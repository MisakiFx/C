#include "WinApiHelper.h"
/**
winodws API����ʵ���ļ�
*/

HANDLE std_win_handle = 0;//����һ��ȫ�ֵľ��
/**
��ȡ��׼��������
*/
void setWinHandle()
{
	if (std_win_handle == 0)
	{
		std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);//�þ��ָ���׼��������
	}
}
/**
���ÿ���̨�ı���
*/
void setTitle(const char* title)
{
	SetConsoleTitle(TEXT(title));
}
/**
���ô���ĳߴ���Ҫʹ��setWindowInfoʵ�֣�����Ҫ����ľ��
*/
void setWinSize(int width, int height)
{
	SMALL_RECT rect = { 0,0,width - 1, height - 1 };//����SMALL_RECT�ṹ���ʾ���������С�����-�յ㣩
	COORD coord = { width,height };//����COORD�ṹ���ʾ�������������꣨�ڿ���̨�������ӡλ�ã�
	setWinHandle();//�õ���׼�������������ڶ����ȫ�־����
	SetConsoleScreenBufferSize(std_win_handle,coord);//���ú������û�����λ��
	SetConsoleWindowInfo(std_win_handle, TRUE, &rect);//���ú������ô����С
}
/**
���ù��λ��
*/
void setCursorPosition(int x, int y)
{
	COORD pos = { x,y };//��ʾ����λ��
	setWinHandle();//�õ�������
	SetConsoleCursorPosition(std_win_handle, pos);//���ù��λ��
}
/**
����������ɫ
*/
void setColor(int color)
{
	setWinHandle();//�õ����
	SetConsoleTextAttribute(std_win_handle, color);
}
/**
���ƺ���
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
��������
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
�ı��������
*/
void printText(const char * text, int size)
{
	char format[30] = "%-";//Ŀ���ʽ�ַ���
	char sizebuf[5];
	_itoa_s(size, sizebuf,10);//��size�е�����ֵת��Ϊ�ַ���
	strcat_s(format,sizebuf);//��sizebufƴ�ӵ�format����
	strcat_s(format, "s");//��"s"ƴ�ӵ�format����
	printf(format, text);//����ʽ�ַ�����Ϊ���������и�ʽ����
}
/**
������亯��
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
�Ӽ����ж�ȡһ���ַ�
*/
char readChar()
{
	char rech = 0;//���ص��ַ�
	if (_kbhit())
	{
		rech = _getch();
	}
	return rech;
}
/**
���ع��
*/
void disableCurrsole()
{
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(std_win_handle, &cursor_info);
}
