#include <stdio.h>
int main()
{
	int a;
	int b; 
	printf("����������������");
	scanf("%d%d",&a,&b);
	printf("��:%d\t��:%d\t��:%d\t��:%.2lf\t����:%d\n",a + b,a - b,a * b,(double)a / b,a % b); 
}
