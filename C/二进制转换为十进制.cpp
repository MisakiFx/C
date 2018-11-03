#include <stdio.h>
int main()
{
	int num;
	printf("请输入一个0-15之间的数字：");
	scanf("%d",&num);
	printf("%d",(num/8)%2);
	printf("%d",(num/4)%2);
	printf("%d",(num/2)%2);
	printf("%d",num%2);
	
 } 
