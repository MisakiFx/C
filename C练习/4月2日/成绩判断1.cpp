#include <stdio.h>
int main()
{
	double score;
	while(1)
	{
		printf("请输入成绩：");
		scanf("%lf",&score);
		if(score <= 100 && score >= 0)
		{
			if(score >= 90)
			{
				printf("A\n");
			}
			else if(score >= 80)
			{
				printf("B\n");
			}
			else if(score >= 70)
			{
				printf("C\n");
			}
			else if(score >= 60)
			{
				printf("D\n");
			}
			else 
			{
				printf("E\n");
			}
		}
		else
		{
			printf("成绩输入失效！\n");
		}
	}
}
