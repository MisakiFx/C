#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>//��������ͷ�ļ�
#pragma comment(lib,"Winmm.lib")
#include <string.h>  //֧���ַ���ͷ�ļ�
#define MAX 6        //����MAX��ʾϢϵͳҪ�������������
#define DAY 10

int main()
{
    int searchIndex;            //�������ҵ����ӵ��±�
    char emperorName[50];       //�ʵ۵�����
    char tempName[20];          //���������ʱ�ַ�������ʱ����
    int choice,i,j,temp,k;           //�ʵ۵�ѡ��
    int count=5;                //��ǰδ�����乬�����Ӹ���
    char names[MAX][20]={"��ɽδ��","������","����δ��","������","С��������"};
    //��������
    char levelNames[][10]={"�������","��������","׹�밮��","�ɲ��һ�","һҹ�ߴ�"};
    //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵ�ǰ����
    int levels[MAX]={1,4,0,0,0,-1};
    //��Ӧÿ�����ӵĺøж�,��ʼ���Ϊ100
    int loves[MAX]={100,100,100,100,100,-1};
    int num=0;          //����������Ӻøж�С��60�ĸ���
    /*
    printf("���Դ��룺��ǰ����״̬��\n");
    printf("%-16s%-16s%-16s\n","����","����","�øж�");
    for(i=0;i<count;i++)
    {
        printf("%-16s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    */
    system("color F5");
    printf("��Ϸ˵����\n");
    printf("��10���ھ��������ӵĺøжȶ����ߣ�ÿ�����ӳ�ʼ�øж�Ϊ100\n");
    printf("���ӵ��6�����ӣ�һ�����������������Ӻøжȵ���60����Ϸʧ��");
    printf("����һ����5���ȼ����ӵڵ���Ϊ��\n");
    printf("�������,��������,׹�밮��,�ɲ��һ�,һҹ�ߴ�\n");
    printf("��ּѡ������������������\n");
    printf("���Ƴ������ӱ��������ӵĺøжȺ͵ȼ������������ӺøжȽ���\n");
    printf("�����乬�������ӵ�����\n");
    printf("����žžž�������ӱ�ž���ӵĺøжȣ���������ߵȼ����������ӵĺøж�Ҳ���ή��\n");
    printf("��Ϸ��ʼ��\n");
    printf("�����뵱ǰ�ǻ��Ļʵ����ţ�\n");
    scanf("%s",emperorName);    //¼���ַ���ʱ������Ҫ&����
    printf("�ʵۡ�%s�����٣��������������꣡\n",emperorName);
    printf("***************************************************\n");
    printf("��ǰ����״̬��\n");
    printf("%-16s%-16s%-16s\n","����","����","�øж�");
    for(i=0;i<count;i++)
    {
        printf("%-16s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    printf("****************************************************\n");
    for(k=0;k<DAY;k++)
    {
         //��������
        PlaySound(TEXT("sounds\\��������.wav"),
                  NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("��%d��\n",k+1);
        printf("1.�ʵ���ּѡ����\t\t�����ӹ��ܣ�\n");
        printf("2.���Ƴ��ң�\t\t\t���޸�״̬���ܣ�\n");
        printf("3.�����乬��\t\t\t��ɾ�����ܣ�\n");
        printf("4.�����ټ�����žžž��\n");
        printf("������ѡ��\n");
        do{
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                 //��������
                PlaySound(TEXT("sounds\\����.wav"),
                          NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                //����nums�����loves��levels
                //����ǰ��Ҫ�ж�������û�пռ�
                if(count<MAX)//�����ǰ��������С�������������
                {
                    //ִ����Ӳ���
                    printf("�����������ӵ�������\n");
                    scanf("%s",names[count]);
                    levels[count]=0;        //��ʼ������
                    loves[count]=100;       //��ʼ���øж�
                    count+=1;               //������������
                }
                else
                {
                    printf("��ô%d�����������棬���±�̰������\n",MAX);
                }
                break;
            case 2:
                    //�ҵ�Ҫ���ҵĹ������±�
                    //�޸�������ӵ�״̬ �øж�+10 ����+1 �����߼���������
                    //�޸��������ӵ�״̬ �øж�-10
                    //��������
                    PlaySound(TEXT("sounds\\����.wav"),
                              NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    printf("���£�������Ҫ���ҵ����ӣ�\n");
                    do
                    {
                        scanf("%s",tempName);
                        //�ַ�������strcmp����Ҫ����<string.h>
                         for(i=0;i<count;i++)
                        {
                            if(strcmp(tempName,names[i])==0)        //����������������ĳ�����ӵ�����
                            //��������0�������ַ�����ȣ����Ϊ1���ʾǰһ�����ں�һ�������Ϊ-1��ǰһ��С�ں�һ��
                            {
                                break;
                            }
                        }
                        if(i==count)
                        {
                            printf("δ�ҵ����ӣ�����������Ҫ���ҵ����ӣ�\n");
                        }
                    }while(i==count);
                    for(i=0;i<count;i++)
                    {
                        if(strcmp(tempName,names[i])==0)        //����������������ĳ�����ӵ�����
                        //��������0�������ַ�����ȣ����Ϊ1���ʾǰһ�����ں�һ�������Ϊ-1��ǰһ��С�ں�һ��
                        {
                            loves[i]+=10;
                            if(levels[i]<4)
                            {
                            levels[i]+=1;        //�����ܳ���5��,0-4֮��
                            }
                        }
                        else
                        {
                            loves[i]-=10;
                        }
                    }
                    break;
            case 3:
                //����
                //����һ����ֵ��ǰ��һ��
                //count-1
                 //��������
                PlaySound(TEXT("sounds\\�乬.wav"),
                          NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                printf("����������Ҫ�����乬�����ӣ�\n");
                do
                {
                    scanf("%s",tempName);
                    for(i=0;i<count;i++)
                        {
                            if(strcmp(tempName,names[i])==0)        //����������������ĳ�����ӵ�����
                            //��������0�������ַ�����ȣ����Ϊ1���ʾǰһ�����ں�һ�������Ϊ-1��ǰһ��С�ں�һ��
                            {
                                break;
                            }
                        }
                     if(i==count)
                    {
                        printf("δ�ҵ����ӣ�����������Ҫ�����乬�����ӡ�\n");
                    }
                }while(i==count);
                for(i=0;i<count;i++)
                {
                    if(strcmp(tempName,names[i])==0)        //����������������ĳ�����ӵ�����
                    //��������0�������ַ�����ȣ����Ϊ1���ʾǰһ�����ں�һ�������Ϊ-1��ǰһ��С�ں�һ��
                    {
                       searchIndex=i;
                       break;
                    }
                }
                for(i=searchIndex;i<count-1;i++)
                {
                    //names[i]=names[i+1];C�����в�֧���ַ�����ֱ�Ӹ�ֵ
                    //��Ҫʹ��strcpyʵ������ĸ�ֵ
                    strcpy(names[i],names[i+1]);
                    loves[i]=loves[i+1];
                    levels[i]=levels[i+1];
                }
                count--;//����������
                break;
            case 4:
                //����
                //�������Ӻøж�
                //��������
                PlaySound(TEXT("sounds\\����.wav"),
                          NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                printf("������Ҫž������- -��\n");
                do{
                    scanf("%s",tempName);
                    for(i=0;i<count;i++)
                        {
                            if(strcmp(tempName,names[i])==0)        //����������������ĳ�����ӵ�����
                            //��������0�������ַ�����ȣ����Ϊ1���ʾǰһ�����ں�һ�������Ϊ-1��ǰһ��С�ں�һ��
                            {
                                loves[i]+=10;
                                break;
                            }
                        }
                        if(i==count)
                        {
                            printf("δ�ҵ�Ҫž�����ӣ�������ѡ��\n");
                        }
                 }while(i==count);
                 break;
            default:
                printf("����Ϸ�ԣ��������ٴ�ȷ�ϣ�\n");
            }
        }while(choice!=1&&choice!=2&&choice!=3&&choice!=4);
        //����ӡǰʹ��ð������
        for(i=0;i<count-1;i++)
        {
            for(j=0;j<count-i-1;j++)
            {
                if(levels[j]<levels[j+1])
                {
                    temp=levels[j];
                    levels[j]=levels[j+1];
                    levels[j+1]=temp;
                    temp=loves[j];
                    loves[j]=loves[j+1];
                    loves[j+1]=temp;
                    //ע���ַ����Ľ���
                    strcpy(tempName,names[j]);
                    strcpy(names[i],names[j+1]);
                    strcpy(names[j+1],tempName);
                }
            }
        }
        printf("***************************************************\n");
        printf("��ǰ����״̬��\n");
        printf("%-16s%-16s%-16s\n","����","����","�øж�");
        for(i=0;i<count;i++)
        {
            printf("%-16s%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
        }
        printf("***************************************************\n");
        for(i=0;i<count;i++)
        {
            if(loves[i]<60)
            {
                num++;
            }
        }
        if(num>2)
        {
            //��������
            PlaySound(TEXT("sounds\\����.wav"),
                      NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("����̫�����������ˣ���������췴�����ڵ�%d��\n",k+1);
            break;
        }
    }
    if(num<=2)
    {
        //��������
        PlaySound(TEXT("sounds\\ʤ��.wav"),
                  NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("��Ϸʤ����Ӯ���������ӵķ��ģ���\n");
    }
    printf("��Ϸ����");
    system("pause");
    return 0;
}
