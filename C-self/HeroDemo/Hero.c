#include "Hero.h"
Hero heros[]={
    {"Misaki\t",'fm',"学生",579,0.644,"眉头一皱",{2017,12,26}},
    {"栗山未来",'fm',"战士",482,0.644,"血之献祭",{2017,12,26}},
    {"小鸟游六花",'fm',"法师",517,0.67,"邪王真眼",{2017,12,26}}
};

void Show()
{
    //如何知道结构数组的大小呢
    int len =sizeof(heros)/sizeof(Hero);
    int i;
    for(i=0;i<len;i++)
    {
        printf("%s\t%s\t%d-%d-%d\n",heros[i].name,heros[i].job,heros[i].pubtime.year,heros[i].pubtime.month,heros[i].pubtime.day);
    }
}
