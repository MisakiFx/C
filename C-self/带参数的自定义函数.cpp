#include <stdio.h>
//形式参数与实参
//实际参数是实际传入哪些数值进入函数
//实现pow函数
double pow(double,int); //这里的参数是形式参数 
int main()
{
	double x;
	int y; 
	printf("请输入数字，我来完成幂运算：");
	scanf("%lf%lf",&x,&y);
	double result=pow(x,y); //这里的参数是实际参数，实参就是调用     
	printf("%.2lf的%.2lf次方=%.2lf",x,y,result);
}
double pow(double a,int b)//这里的参数也是形式参数
{
	int i;
	double result=1;
	for(i=0;i<b;i++)
	{
		result*=a;
	}
	return result;
}
