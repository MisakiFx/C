#include <stdio.h>

//定义有返回值的函数：求1-100的偶数和
//返回值：1.调用函数后会有一个值返回；
		//2.一个函数只能返回一个值，不能多个值返回，但是可以返回数组；
		//3.return会立即终止函数并返回，可以返回空值 
int calcSum();
int calcSum()//定义有返回值的函数 
{
	int sum,i;
	for(i=1;i<=100;i++)
	{
		if(i%2==0)
		{
			sum+=i;
		}
	}
	return sum;//将计算好的结果返回 
} 
int main()
{
	//如果函数有返回值，调用时记得使用对应类型的变量接收
	int sum=calcSum();
	printf("1-100之间的偶数和为：%d\n",sum);	
} 
