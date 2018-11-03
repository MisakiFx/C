#include <stdio.h>
void changeNum()
{
	//局部变量
	//函数结束，变量自动死亡 
	int num1=5,num2=8;
	num1=55;
	num2=88;
}
int main()
{
	 int num1=5;
	 int num2=8;
	 changeNum();//调用函数
	 printf("num1=%d\tnum2=%d\n",num1,num2);//此时的num1和num2是主函数里的，和changeNum中的局部变量完全不是一个空间 
	 return 0; 
 } 
