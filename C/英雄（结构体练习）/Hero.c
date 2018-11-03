#include "Hero.h"
Hero heros[5];
Job jobs[]={
    {1,"法师","biubiubiu专家"},
    {2,"刺客","千年杀专家"},
    {3,"战士","我的肉特别厚"},
    {4,"机甲师","靠机甲吃饭"},
    {5,"射手","指哪打哪"}
};
void InputHero()
{
    //动态录入
    int i,jobchoice,j;
    for(i=0;i<5;i++)
    {
        printf("请输入第%d位英雄的信息：\n",i+1);
        heros[i].id=i+1;
        printf("名称：");
        heros[i].name=(char*)malloc(50);
        scanf("%s",heros[i].name);
        printf("性别：");
        fflush(stdin);//清空缓冲区，输入录入字符前后都要使用
        scanf("%c",&heros[i].sex);
        fflush(stdin);//清空缓冲区，输入录入字符前后都要使用
        for(j=0;j<5;j++)
        {
            printf("%d\t%s\t%s\n",jobs[j].id,jobs[j].name,jobs[j].desc);
        }
        printf("请选择职业：(1-5)");
        scanf("%d",&jobchoice);
        heros[i].job=jobs[jobchoice-1];
        printf("%s当前的职业：《%s》,性别：%c\n",heros[i].name,heros[i].job.name,heros[i].sex);
    }
}
void ShowHero()
{
    int i;
    for (i=0;i<5;i++)
    {
        printf("%s当前的职业：《%s》,性别：%c\n",heros[i].name,heros[i].job.name,heros[i].sex);
    }
}
