#include "Hero.h"
Hero heros[]={
    {"Misaki\t",'fm',"ѧ��",579,0.644,"üͷһ��",{2017,12,26}},
    {"��ɽδ��",'fm',"սʿ",482,0.644,"Ѫ֮�׼�",{2017,12,26}},
    {"С��������",'fm',"��ʦ",517,0.67,"а������",{2017,12,26}}
};

void Show()
{
    //���֪���ṹ����Ĵ�С��
    int len =sizeof(heros)/sizeof(Hero);
    int i;
    for(i=0;i<len;i++)
    {
        printf("%s\t%s\t%d-%d-%d\n",heros[i].name,heros[i].job,heros[i].pubtime.year,heros[i].pubtime.month,heros[i].pubtime.day);
    }
}
