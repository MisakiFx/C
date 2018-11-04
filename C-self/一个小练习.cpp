#include <stdio.h>
#include <math.h>
int main()
{
	int j,i;
	char c;
	double nums[1000];
	for(i=0;i<1000;i++)
	{
		scanf("%lf%c",&nums[i],&c);
		if(c=='#')
		{
			break;
		}
	}
		for(j=0;j<i+1;j++)
	{
		printf("%.2lf\t",nums[j]);
	}
	 
 } 
