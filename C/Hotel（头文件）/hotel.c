//��Ӧhotel.h��ʵ���ļ�

#include <stdio.h>
#include "hotel.h"//�����Զ���ͷ�ļ�ʱʹ��˫����
char hotelNames[4][50]={
            "���޾Ƶ�","�������㳡�Ƶ�","��˹ͼ����˹�����������Ƶ�","˹�����������ؾƵ�"
};
int Menu()
{
    int choice;//�û���ѡ��
    int result;//�û�������״̬����жϣ�0��ʾ�Ƿ���1��ʾ��
    int i;
    printf("��ѡ����ס�ľƵ꣺\n");
    for(i=0;i<4;i++)
    {
        printf("%d��%s\n",i+1,hotelNames[i]);
    }
    printf("5���˳�����\n");
    printf("����������ѡ��");
    while((result=scanf("%d",&choice))!=1||choice<1||choice>5)//���û������ֵ���Ϸ�ʱ��������
    {
        if(result!=1)//����û�����Ĳ�����������
        {
            scanf("%*s");//������������������룬*��ʾ�������ڶ���󲻸�ֵ����Ӧ�ı�����ȡ�����ַ���ֵ��choice
            fflush(stdin);//��ջ�����
        }
        printf("��������1-5֮���������");
    }
    //1���û���ѡ�����Ƿ�����
    //2���û���������ֱ�����ѡ���ڵģ�1-5
    return choice;
}
int GetNights(void)
{
    int nights;//�û���ס������
    printf("������Ҫ��ס��������");
     while(scanf("%d",&nights)!=1)//���û������ֵ���Ϸ�ʱ��������
    {
        scanf("%*s");//������������������룬*��ʾ�������ڶ���󲻸�ֵ����Ӧ�ı�����ȡ�����ַ���ֵ��choice
        fflush(stdin);//��ջ�����
        printf("��������ȷ��������������������\n");
        printf("������Ҫ��ס��������");
    }
    return nights;
}
void ShowPrice(int choice,int nights,double price)
{
    //�ܼ۸�=�ۼ�ǰһ���95%
    double total=0;
    int i;
    for(i=0;i<nights;i++)
    {
        total+=price;
        price=price*DISCOUNT;
    }
    printf("ѡ�����%s,��ס%d�죬������%.2lfԪ��\n",hotelNames[choice-1],nights,total);
}
