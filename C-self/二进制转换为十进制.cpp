#include <stdio.h>
int main()
{
	int num;
	printf("������һ��0-15֮������֣�");
	scanf("%d",&num);
	printf("%d",(num/8)%2);
	printf("%d",(num/4)%2);
	printf("%d",(num/2)%2);
	printf("%d",num%2);
	
 } 
