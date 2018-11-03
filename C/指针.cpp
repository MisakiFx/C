#include <stdio.h>
int main()
{
	int num=9;
	int*ptr_num=&num;
	printf("num的内存地址为：%p,值为%d\n",ptr_num,*ptr_num);
	*ptr_num=11;
	printf("num新值为：%d",*ptr_num);
}
