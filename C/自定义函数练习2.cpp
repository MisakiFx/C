#include <stdio.h>
#include <math.h>
double calcCircle(double);//计算圆面积函数
int validate(double);//验证输入的数据是否是正数
double calcRectangle(double,double);//计算矩形面积函数
double calcTangle(double,double); 
int main()
{
	//计算圆，矩形，三角形面积（使用不同的方法）
	//因为计算三个面积有着通用的功能（接收，打印），通用的功能都可以将其书写为函数多次调用 
	double r;//半径 
	double width,height;//宽和高
	double bottom,high;//三角形底和高 
	double s;//图形面积
	int choice;//选择 
	printf("本系统支持计算三种图形的面积，清选择：\n");
	printf("1.圆\n");
	printf("2.矩形\n");
	printf("3.三角形\n");
	printf("请选择：");
	do{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("请输入圆半径：");
				do{		//需要对用户输入的数据进行非负判断 
					scanf("%lf",&r);
					if(!validate(r))
					{
						printf("你逗我呢？特么重输："); 
					}
				}while(!validate(r));
				s=calcCircle(r); //调用圆面积计算函数
				printf("圆的面积为：%.2lf",s); 
				break;
			case 2:
				printf("请输入矩形的长和宽：");
				do{
				scanf("%lf%lf",&width,&height);
				if(!validate(width) || !validate(height))
				{
					printf("逗我玩呢！特么重输：");
				}
				}while(!validate(width) || !validate(height));
				s=calcRectangle(width,height);
				printf("矩形的面积是：%.2lf",s);
				break;
			case 3:
				printf("请输入三角形的底和高：");
				do{
					scanf("%lf%lf",&bottom,&high);
					if(!validate(bottom) || !validate(high))
					{
						printf("逗我玩呢！重输：");
					}
				}while(!validate(bottom)|| !validate(high));
				s=calcTangle(bottom,high);
				printf("三角形的面积是：%lf",s); 
				break;
			default:
				printf("本系统目前只支持三种图形的面积计算，请重新选择：");
		 } 
	}while(choice!=1&&choice!=2&&choice!=3);
 } 
double calcCircle(double r)
{
	double s=3.14*pow(r,2);
	return s;//返回面积 	
}
int validate(double num)
{
	return num>0;//如果num大于0返回一个非0值表示为真 
}
double calcRectangle(double width,double height)
{
	return width*height;
}
double calcTangle(double bottom,double high)
{
	return (bottom*high)/2;
}
