#include <stdio.h>
void sum1()
{
	//求1+2+3+4+5+……+n
	int sum=0,i,n;
	printf("请输入n的值：");
	scanf("%d",&n);	
	for(i=0;i<=n;i++)
	{
		sum+=i;
	}
	printf("1、答案是：%d\n",sum);
}
void sum2()
{
	//求1+1/2+1/3+……+1/n
	double sum2=0,n;
	int i;
	printf("请输入n的值：");
	scanf("%lf",&n);	
	for(i=1;i<=n;i++)
	{
		sum2=sum2+(1.00/i);
	} 
	printf("2、答案是：%.2lf\n",sum2);
}
void sum3()
{
	//求1-1/2+1/3-1/4+……+1/n 
	double sum3=0,n;
	int i;
	printf("请输入n的值：");
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
	printf("3、答案是：%.2lf\n",sum3);
}
void sum4()
{
	//求n! 
	int i,n,sum=0;
	printf("请输入n的值：");
	scanf("%d",&n);	
	for(i=1;i<=n;i++)
	{
		sum+=i;
	}
	printf("答案是：%d",sum);
}
void sum5()
{
	double sum=0,a;
	printf("请输入数据我来求和：(以#结束)\n");
	while(scanf("%lf",&a)!=0)
	{
		sum+=a;
	}
	printf("答案是：%.2lf\n",sum);
}
void sum6()
{
	double sum=0,a;
	printf("请输入数据我来求和直到输入负数为止：\n");
	while(scanf("%lf",&a)!=0)
	{
		if(a<0)
		{
			break;
		}
		sum+=a;
	}
	printf("答案是：%.2lf\n",sum);
}
void sum7()
{
	double sum;
	double num[10];
	printf("请输入10个数字，我来求其中正数之和\n");
	for(int i=0;i<10;i++)
	{
		printf("请输入第%d个数字：",i+1); 
		scanf("%lf",&num[i]);
	}
	for(int i=0;i<10;i++)
	{
		if(num[i]>0)
		{
			sum+=num[i];
		}
	}
	printf("答案是：%.2lf",sum);
}
int main()
{
	sum1();//求1+2+3+4+5+……+n
	sum2();//求1+1/2+1/3+……+1/n
	sum3();//求1-1/2+1/3-1/4+……+1/n 
	sum4();//求n!
	sum5();//求n个数据的和
	fflush(stdin); //清除键盘缓冲区 
	sum6();//求数据的和直到负数为止 
	fflush(stdin);
	sum7();//求10个数中正数的和 
}
