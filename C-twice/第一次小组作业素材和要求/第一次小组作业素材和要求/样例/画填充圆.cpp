#include <graphics.h>      // ������Ҫ�������ͼ�ο�
#include <conio.h>
void main()
{
    initgraph(640, 480);   // ����� TC ��������
	
	setfillcolor(RGB(255,255,0));
	setlinecolor(RGB(0,0,255));  //ʰɫ��
	fillcircle(200, 200, 150); // ��Բ��Բ��(200, 200)���뾶 150
	
	getch();               // �����������
    closegraph();          // �ر�ͼ�ν���
}