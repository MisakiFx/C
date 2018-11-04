#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int a,b,c,d,e;
	char choice;
	srand(time(NULL));
	do
	{
		printf("请输入A-E来抢红包：");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'A':
				a = rand() % 100 + 1;
				printf("%d\n",a);
				fflush(stdin);
				break;
			case 'B':
				b = rand() % 100 + 1;
				printf("%d\n",b);
				fflush(stdin);
				break;
			case 'C':
				c = rand() % 100 + 1;
				printf("%d\n",c);
				fflush(stdin);
				break;
			case 'D':
				d = rand() % 100 + 1;
				printf("%d\n",d);
				fflush(stdin);
				break;
			case 'E':
				e = rand() % 100 + 1;
				printf("%d\n",e);
				fflush(stdin);
				break;
			default:
				printf("无效命令!\n");
				fflush(stdin);
				break;
		}
	}while(1);
	return 0;
}
