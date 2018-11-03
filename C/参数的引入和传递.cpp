#include <stdio.h>
void change1(int*); 
void change(int); 
//用地址将值传入函数，函数更改值后值会返回主函数
//仅将值传入函数进行修改，函数更改值后值不会返回主函数 
int main()
{
	//形参和实参的传递和调用	
	int num=9;
	change(num);//函数无法将值返回主函数
	printf("num=%d\n",num);
	change1(&num);//更改内存地址所控制的值，主函数里的值随之改变 
	printf("num=%d\n",num); 
}
void change(int num)//形式参数，作用仅在这个域，无法返回主函数 
{
	num++;//仅修改副本的值，主函数里的值不变 
}
void change1(int *num)
{
	*num+=1;//内存所控制的值被改变，会传回到主函数 
}
