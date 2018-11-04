#include <stdio.h>
int main()
{
	int a;
	int b; 
	printf("请输入两个整数：");
	scanf("%d%d",&a,&b);
	printf("和:%d\t差:%d\t积:%d\t商:%.2lf\t余数:%d\n",a + b,a - b,a * b,(double)a / b,a % b); 
}
