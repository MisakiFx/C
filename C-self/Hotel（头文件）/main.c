#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"
extern char hotelNames[4][50];
int main()
{
    //ͷ�ļ���һ���һЩ�ظ�ʹ�õĴ��룬����������������
    //�Զ���ͷ�ļ�
    //�û�������ס�ľƵ������������������Ӧ�Ľ��
    int choice;//ѡ��
    int nights;//����
    double totalCost;//�û�֧�����ܷ���
    double  currCost;//�û���ǰ��ס�ľƵ귿��
    //1.��ʾ�˵�
   while((choice=Menu())!=5)
   {
       //2.�������
       switch (choice)
       {
       case 1://�û���ס��һ�ҾƵ�
           currCost=HOTEL1;
        break;
       case 2://�û���ס�ڶ��ҾƵ�
           currCost=HOTEL2;
        break;
       case 3://�û���ס�����ҾƵ�
           currCost=HOTEL3;
        break;
       case 4://�û���ס���ļҾƵ�
           currCost=HOTEL4;
        break;
       default:
           currCost=0;
       }
       //�õ��û���ס������
       nights=GetNights();
       //�����ܷ���
       ShowPrice(choice,nights,currCost);
   }
   printf("��лʹ�ñ�ϵͳ���ٻᣡ��");
    return 0;
}
