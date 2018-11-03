#include <stdio.h>
int num=0;
int factorial(int num);//计算阶乘函数 
void test(int num)
{
	printf("%d",num++);
	test(num);//自己调用自己，死循环 
 } 
int main()
{
	//函数自己调用自己的过程叫递归
	//test(num);//循环最好有退出条件 
	int result=factorial(5);
	printf("%d",result);
}
int factorial(int num)
{
	if(num == 1)
	{
		return 1;
	}
	else
	{
		num=num*factorial(num-1);
		return num;
	}
}
