#include "Hero.h"
Hero heros[5];
Job jobs[]={
    {1,"��ʦ","biubiubiuר��"},
    {2,"�̿�","ǧ��ɱר��"},
    {3,"սʿ","�ҵ����ر��"},
    {4,"����ʦ","�����׳Է�"},
    {5,"����","ָ�Ĵ���"}
};
void InputHero()
{
    //��̬¼��
    int i,jobchoice,j;
    for(i=0;i<5;i++)
    {
        printf("�������%dλӢ�۵���Ϣ��\n",i+1);
        heros[i].id=i+1;
        printf("���ƣ�");
        heros[i].name=(char*)malloc(50);
        scanf("%s",heros[i].name);
        printf("�Ա�");
        fflush(stdin);//��ջ�����������¼���ַ�ǰ��Ҫʹ��
        scanf("%c",&heros[i].sex);
        fflush(stdin);//��ջ�����������¼���ַ�ǰ��Ҫʹ��
        for(j=0;j<5;j++)
        {
            printf("%d\t%s\t%s\n",jobs[j].id,jobs[j].name,jobs[j].desc);
        }
        printf("��ѡ��ְҵ��(1-5)");
        scanf("%d",&jobchoice);
        heros[i].job=jobs[jobchoice-1];
        printf("%s��ǰ��ְҵ����%s��,�Ա�%c\n",heros[i].name,heros[i].job.name,heros[i].sex);
    }
}
void ShowHero()
{
    int i;
    for (i=0;i<5;i++)
    {
        printf("%s��ǰ��ְҵ����%s��,�Ա�%c\n",heros[i].name,heros[i].job.name,heros[i].sex);
    }
}
