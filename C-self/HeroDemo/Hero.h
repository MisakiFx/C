#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
typedef struct _mytime
{
    int year;
    int month;
    int day;
}Mytime;
typedef struct _hero
{
    char name[50];//Ӣ������
    char sex;//Ӣ���Ա�
    char job[20];//Ӣ��ְҵ
    int hp;//Ӣ������ֵ
    double speed;//�����ٶ�
    char abillity[20];//Ӣ����������
    Mytime pubtime;//����ʱ��
}Hero;
void Show();//��ʾӢ�۵���ϸ��Ϣ
#endif // HERO_H_INCLUDED
