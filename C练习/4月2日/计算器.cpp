#include <stdio.h>
int main()
{
	int a, b;
	char c;
	while(1)
	{
		printf("%Please enter the expression:");
		scanf("%d%c%d",&a,&c,&b);
		switch(c)
		{
			case '+':
				printf("%d\n",a + b);
				break;
			case '-':
				printf("%d\n",a - b);
				break;
			case '*':
				printf("%d\n",a * b);
				break;
			case '/':
				if(b == 0)
				{
					printf("输入有误！\n");
					break;
				}
				printf("%d\n",a / b);
				break;
			default:
				printf("输入有误！\n");
				break;
		}
	}
}
