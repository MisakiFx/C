#include <stdio.h>
int main()
{
	int num=9;
	int*ptr_num=&num;
	printf("num���ڴ��ַΪ��%p,ֵΪ%d\n",ptr_num,*ptr_num);
	*ptr_num=11;
	printf("num��ֵΪ��%d",*ptr_num);
}
