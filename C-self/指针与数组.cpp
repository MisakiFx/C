#include <stdio.h>
int main()
{
	int i;
	//数组是连续的内存空间，数组名就是内存空间的首地址
	double score[]={98,87,65,43,76};
	//double *ptr_score=&score[0]与&score[0]等价此时也与score等价 
	printf("数组的首地址为：%p\t数组的首元素的地址为：%p\n",score,&score[0]); 
	//************************************************************
	//************************************************************
	//指针可以参与运算
	double *ptr_score;
	ptr_score=score;
	printf("数组为：\n");
	
	for(i=0;i<5;i++)
	{
		printf("%.0lf\t",*ptr_score++);//++在后，所以先参与整体运算再自身+1 
		//一个类型为T的指针的移动，以sizeof(T)为移动单位
		//例如，double指针一次移动8个byte
	}
	printf("\n");
	ptr_score=score;
	for(i=0;i<5;i++)
	{
		//数组名就是一个指针，所以打印数组也可以这样打印 
		printf("%.0lf\t",ptr_score[i]);
		//将score指针给了ptr_score后，ptr_score[]也可以作为数组使用 
	}
	printf("\n");
	ptr_score=score;
	for(i=0;i<5;i++)
	{
		//还可以这样打印 
		printf("%.0lf\t",*(ptr_score+i));
		//推荐这种指针打印方式，指针本身并不发生变化 
	}
	printf("\n");
	//********************************************************
	//指针可以随意加或减某个整数值
	ptr_score+=2;
	printf("%.0lf\n",*ptr_score); 
	ptr_score++;
	printf("%.0lf\n",*ptr_score); 
	ptr_score-=3;
	printf("%.0lf\n",*ptr_score); 
	
}
