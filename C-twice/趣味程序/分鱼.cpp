#include <stdio.h>
/*甲、乙、丙三位、渔夫出海打鱼，他们随船带了21只箩筐。
当晚返航时，他们发现有7筐装满 了鱼，还有7筐只装了半筐鱼，另外7筐则是空的。
由于他们没有秤，只好通过目测认为7个满筐鱼的重量是相等的，7个半筐鱼的重量是相等的。
在不将鱼倒出来的前提下，怎样将鱼和筐平分为三份? */
int main()
{
	int i, k, j, m, flag = 1, count = 0,n; 
	int mean[3][3];
	for(i = 0; i <= 3; i++)
	{
		mean[0][0] = i;
		for(j = 0; j <= 7 - i && j <= 3; j++)
		{
			mean[1][0] = j;
			if(mean[2][0] = (7 - j - mean[0][0]) > 3) continue;
			if(mean[2][0] < mean[1][0]) break;
			for(k = 1; k <= 7; k++)
			{
				mean[0][1] = k;
				for(m = 1; m <= 7 - k; m++)
				{
					mean[1][1] = m;
					mean[2][1] = 7 - mean[0][1] - mean[1][1];
					for(n = 0, flag = 1; flag && n < 3; n++)
					{
						if(mean[n][0] + mean[n][1] < 7 && mean[n][0] * 2 + mean[n][1] == 7)
						{
							mean[n][2] = 7 - mean[n][0] - mean[n][1];
						}
						else
						{
							flag = 0;
						}
					}
					if(flag)
					{
						printf("第%d个方法：\n满\t半\t空\n",++count);
						for(n = 0; n < 3; n++)
						{
							printf("%d\t%d\t%d\n",mean[n][0],mean[n][1],mean[n][2]);
						}
					}
				}
			}
		}
	}
} 
