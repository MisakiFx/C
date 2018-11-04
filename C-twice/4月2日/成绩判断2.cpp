#include <stdio.h>
int main()
{
	double score1;
	int score;
	while(1)
	{
		printf("ÇëÊäÈë³É¼¨£º");
		scanf("%lf",&score1);
		if(score1 >= 0 && score1 <= 100)
		{
			score = score1 / 10;
			switch(score)
			{
				case 10:
					printf("A\n");
					break;
				case 9:
					printf("A\n");
					break;
				case 8:
					printf("B\n");
					break;
				case 7:
					printf("C\n");
					break;
				case 6:
					printf("D\n");
					break;
				default:
					printf("E\n");
					break;
			}
		}
		else 
		{
			printf("³É¼¨ÊäÈë´íÎó£¡\n");
		}
	}
}
