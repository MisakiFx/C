#include <stdio.h>
int count=0;//在外部定义全局变量 ，全局变量就算是不赋初值，系统自动也会分配默认值 
//全局变量的作用域是当前源文件 
void changeNum()
{
	count++;
 } 
int main()
{
	changeNum();
	changeNum();
	printf("%d",count);
} 
