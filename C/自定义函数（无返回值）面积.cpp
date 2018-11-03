#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
//自定义函数，三要素（返回值类型、函数名、参数列表）
//使用函数完成三种图形的面积计算公式，打印计算结果
//圆，矩形

//考虑这个函数需要返回值么？
//函数名是什么？
//需要给这个函数参数么？

//计算圆的面积（无返回值） 
void calcCircle();//函数原型 
void calcCircle()//函数实现
{
	double radius,s;//半径和面积 
	printf("请输入圆半径：");
	scanf("%lf",&radius);
	s = 3.14*pow(radius,2);//圆面积
	printf("半径为%.2lf的圆的面积为：%.2lf\n",radius,s); 
 }
 
 //计算矩形面积（无返回值） 
void calcRectangle();//函数原型
void calcRectangle()
{
	double width,height,s;//宽和高和面积
	printf("请输入矩形的宽和高：");
	scanf("%lf%lf",&width,&height);
	if(width<0||height<0)
	{
		printf("宽和高不能小于0，逗比");
		return;//用return立刻终止函数，返回值本来就是0，不能return 0； 
	}
	s=width*height;
	printf("矩形的面积是：%.2lf",s); 
 } 
 
int main()
{
	calcCircle();//调用计算圆面积的函数
	calcRectangle();//调用计算矩形的函数 
 } 
