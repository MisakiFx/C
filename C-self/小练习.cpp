#include <stdio.h>
void sum1()
{
	//��1+2+3+4+5+����+n
	int sum=0,i,n;
	printf("������n��ֵ��");
	scanf("%d",&n);	
	for(i=0;i<=n;i++)
	{
		sum+=i;
	}
	printf("1�����ǣ�%d\n",sum);
}
void sum2()
{
	//��1+1/2+1/3+����+1/n
	double sum2=0,n;
	int i;
	printf("������n��ֵ��");
	scanf("%lf",&n);	
	for(i=1;i<=n;i++)
	{
		sum2=sum2+(1.00/i);
	} 
	printf("2�����ǣ�%.2lf\n",sum2);
}
void sum3()
{
	//��1-1/2+1/3-1/4+����+1/n 
	double sum3=0,n;
	int i;
	printf("������n��ֵ��");
	scanf("%lf",&n);	
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			sum3=sum3-(1.00/i);
		}
		else
		{
			sum3=sum3+(1.00/i);
		}
	}
	printf("3�����ǣ�%.2lf\n",sum3);
}
void sum4()
{
	//��n! 
	int i,n,sum=0;
	printf("������n��ֵ��");
	scanf("%d",&n);	
	for(i=1;i<=n;i++)
	{
		sum+=i;
	}
	printf("���ǣ�%d",sum);
}
void sum5()
{
	double sum=0,a;
	printf("����������������ͣ�(��#����)\n");
	while(scanf("%lf",&a)!=0)
	{
		sum+=a;
	}
	printf("���ǣ�%.2lf\n",sum);
}
void sum6()
{
	double sum=0,a;
	printf("�����������������ֱ�����븺��Ϊֹ��\n");
	while(scanf("%lf",&a)!=0)
	{
		if(a<0)
		{
			break;
		}
		sum+=a;
	}
	printf("���ǣ�%.2lf\n",sum);
}
void sum7()
{
	double sum;
	double num[10];
	printf("������10�����֣���������������֮��\n");
	for(int i=0;i<10;i++)
	{
		printf("�������%d�����֣�",i+1); 
		scanf("%lf",&num[i]);
	}
	for(int i=0;i<10;i++)
	{
		if(num[i]>0)
		{
			sum+=num[i];
		}
	}
	printf("���ǣ�%.2lf",sum);
}
int main()
{
	sum1();//��1+2+3+4+5+����+n
	sum2();//��1+1/2+1/3+����+1/n
	sum3();//��1-1/2+1/3-1/4+����+1/n 
	sum4();//��n!
	sum5();//��n�����ݵĺ�
	fflush(stdin); //������̻����� 
	sum6();//�����ݵĺ�ֱ������Ϊֹ 
	fflush(stdin);
	sum7();//��10�����������ĺ� 
}
