#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
int main()
{
    initgraph(640, 480);   // ������ͼ���ڣ���СΪ 640x480 ����
    circle(200, 200, 200); // ��Բ��Բ��(200, 200)���뾶 200
    getch();              // �����������
    closegraph();          // �رջ�ͼ����
}