#include <stdio.h>
int main()
{
	int num1=1024;
	int num2=2048;
	int *ptr1,*ptr2;
	ptr1=&num1;
	ptr2=&num2;
	printf("num1的值是%d\tnum1地址是%p\n",num1,ptr1);
	printf("num2的值是%d\tnum2地址是%p\n",num2,ptr2);
	//将变量1的值赋给变量2
	//num2=num1;*ptr2=*ptr1;两句话等价
	//直接操作指针
	ptr2=ptr1; 
	printf("重新赋值后：\n"); 
	printf("num1的值是%d\tnum1地址是%p\n",num1,ptr1);
	printf("num2的值是%d\tnum2地址是%p\n",num2,ptr2);
	//将ptr1赋给ptr2，此时ptr2也指向num1，但是实际上num2的值没有变
	printf("\n");
	printf("num1的值是%d\tnum1地址是%p\n",num1,ptr1);
	printf("num1的值是%d\tnum1地址是%p\n",*ptr2,ptr2);//也可以这么表示了
	*ptr2=111111;
	//此时ptr2指向的是num1，所以被更改的也是num1了
	printf("重新赋值后：\n"); 
	printf("num1的值是%d\tnum1地址是%p\n",num1,ptr1);
	printf("num1的值是%d\tnum1地址是%p\n",*ptr2,ptr2);
	//此时num1=*ptr1=*ptr2，ptr1，ptr2都指向num1
	//指针不用时，将指针置为空
	ptr1=NULL; 
	 
	 
	 
	 
}
