#include <stdio.h>
#define N 5
//ʹ��������Ϊ��������������ָ�룩
//��дһ��С�͵�ѧ���ɼ�����ϵͳ
//�������ָ�룬ָ��������� ,�ú�����������в�����������ָ����ڴ���в��� 
//������Ϊ��������ʱ��ֻ��������׵�ַ���뺯�� 
void input(double[]);//¼�뺯��
void sort(double *);//������    ��ͬ��void sort(double[]) 
void show(double[]);//��ʾ����
int validate(double);//�жϺ���
int search(double[]);//���Һ��� 
int main()
{ 
	int index;
	double scores[N];
	//1��¼��
	input(scores);
	//��ȡ�����С
	printf("�����Ԫ�ظ����ǣ�%d\n",sizeof(scores)/sizeof(double));//��ͬ��printf("�����Ԫ�ظ����ǣ�%d\n",sizeof(scores)/sizeof(scores[0])) 
	//2������
	sort(scores);
	//3������ĳ�ָ�ʽ��ӡ
	show(scores);
	//4�������ɼ������سɼ����±�
	index=search(scores);
	printf("��Ӧ�ɼ����±��ǣ�%d",index); 
	 
}
void input(double *scores)//�ȼ��� void input(double scores[])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("�������%d���ɼ���",i+1);
		do{
			scanf("%lf",&scores[i]);
			if(validate(*(scores+i))==0)
			{
				printf("�����������������룺"); 
			}
		}while(validate(*(scores+i))==0);
	}
}
int validate(double num)
{
	return num>=0;
}
void show(double scores[])
{
	int i;
	printf("**************************************************************\n");
	printf("����\t��ѧ\tӢ��\t����\t��ѧ\n"); 
	for (i=0;i<N;i++)
	{
		printf("%.2lf\t",scores[i]);
	}
	printf("\n**************************************************************\n");
}
void sort(double scores[])
{
	int i,j;
	double temp;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(scores[j]>scores[j+1])
			{
				temp=scores[j];
				scores[j]=scores[j+1];
				scores[j+1]=temp;
			}
		}
	}
} 
int search(double scores[])
{
	int i,index=-1;
	double score;
	printf("������Ҫ���ҵ����֣�");
	do{
		scanf("%lf",&score);
		for(i=0;i<N;i++)
		{
			if(scores[i]==score)
			{
				index=i;
			}
		}
		if(index==-1)
		{
			printf("û���ҵ�������������ɼ���");
		}
	}while(index==-1);
	return index;
}
