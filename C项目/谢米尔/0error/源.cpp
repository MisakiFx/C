#include <graphics.h>
#include <conio.h>
#define PI 3.14159265
int main()
{
	// ������СΪ 1024 * 800 �Ļ�ͼ����
	initgraph(1024, 800);
	// ����ԭ�� (0, 0) Ϊ��Ļ���루Y��Ĭ������Ϊ����
	setorigin(512, 400);
	//setbkcolor(WHITE);
	cleardevice();//��������0
	/*����*/
	setfillcolor(WHITE);//�������ɫ
	setlinecolor(BLACK);//����������ɫ
	fillcircle(0,0,350);//ͷ����
	setlinestyle(PS_SOLID, 8);
	fillcircle(-175,-110,75);//�۾�
	fillcircle(175, -110, 75);//�۾�
	setlinestyle(PS_SOLID, 2);
	line(-75,-45,75,-45);//����
	setlinestyle(PS_SOLID, 4);
	arc(-340,-540,340,160,PI * 37 / 32,PI * 59 / 32);
	arc(-250,10,250,150,PI * 3 / 32, PI * 29 / 32);//��
	setfillcolor(BLACK);
	line(-170, 27, -170, 107);
	line(-170, 107, -70, 107);
	line(-70, 107, -70, 12);
	line(-65,12, -65, 107);
	line(-65, 107, 65, 107);
	line(65, 107, 65, 11);
	line(70, 12, 70, 107);
	line(70, 107, 170, 107);
	line(170, 107, 170, 27);//����
	floodfill(0,120,BLACK);//���
	char c = _getch();
	closegraph();
}