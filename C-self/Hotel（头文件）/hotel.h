#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#define HOTEL1 872.0 //���ҾƵ��Ĭ�Ϸ���
#define HOTEL2 1838.0
#define HOTEL3 789.0
#define HOTEL4 1658.0
#define DISCOUNT 0.95 //�ۿ���
//�˵���������ʾ�˵�ѡ����ղ������û�������
int Menu(void);
int GetNights(void);//������ס������
void ShowPrice(int choice,int nights,double price);//������ס�������ͷ���ĵ��ۼ������յļ۸�
#endif // HOTEL_H_INCLUDED
