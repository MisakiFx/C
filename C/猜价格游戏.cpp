#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	printf("��²���Ʒ�۸񣬼۸���200���ڣ�һ����10�λ���\n"); 
	srand(time(NULL));
	int i,sth1,sth=rand()%200+1;
	const int N=10;
	for(i=0;i<N;i++)
	{
		printf("������²�ļ۸�");
		scanf("%d",&sth1);
		if(sth1==sth) 
		{
			printf("��ϲ���У����ʤ��\n");
			break; 
		}
		
		else if(sth1>sth)
		{
			while(i==9)
			{
				printf("��ƫ����Ϸʧ��\n"); 
				break;
			}
			while(i<9)
			{
			printf("��ƫ�������²²⻹��%d�λ���\n",10-(i+1));
			break;
			}
		}
		else if(sth1<sth)
		{
			while(i==9)
			{
				printf("��ƫС����Ϸʧ��\n"); 
				break;
			}
			while(i<9)
			{
			printf("��ƫС�������²²⻹��%d�λ���\n",10-(i+1));
			break;
			}
		}
	}
	printf("��Ϸ����,��ȷ����%d",sth); 
}
