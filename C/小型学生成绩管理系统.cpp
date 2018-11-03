#include <stdio.h>
#define N 5
//使用数组作为函数参数（调用指针）
//书写一个小型的学生成绩管理系统
//数组就是指针，指针就是数组 ,用函数对数组进行操作，就是用指针对内存进行操作 
//数组作为函数参数时，只把数组的首地址传入函数 
void input(double[]);//录入函数
void sort(double *);//排序函数    等同于void sort(double[]) 
void show(double[]);//显示函数
int validate(double);//判断函数
int search(double[]);//查找函数 
int main()
{ 
	int index;
	double scores[N];
	//1、录入
	input(scores);
	//量取数组大小
	printf("数组的元素个数是：%d\n",sizeof(scores)/sizeof(double));//等同于printf("数组的元素个数是：%d\n",sizeof(scores)/sizeof(scores[0])) 
	//2、排序
	sort(scores);
	//3、按照某种格式打印
	show(scores);
	//4、搜索成绩，返回成绩的下标
	index=search(scores);
	printf("对应成绩的下标是：%d",index); 
	 
}
void input(double *scores)//等价于 void input(double scores[])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("请输入第%d个成绩：",i+1);
		do{
			scanf("%lf",&scores[i]);
			if(validate(*(scores+i))==0)
			{
				printf("输入有误；请重新输入："); 
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
	printf("语文\t数学\t英语\t物理\t化学\n"); 
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
	printf("请输入要查找的数字：");
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
			printf("没有找到，请重新输入成绩：");
		}
	}while(index==-1);
	return index;
}
