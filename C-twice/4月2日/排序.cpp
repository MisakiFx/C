#include <stdio.h>
int main()
{
	double nums[3];
	printf("请输入三个数字:");
	for(int i = 0; i < 3; i++)
	{
		scanf("%lf",&nums[i]);
	}
	for(int i = 0; i < 3 - 1; i++)
	{
		for(int j = 0; j < 3 - i - 1; j++)
		{
			if(nums[j + 1] > nums[j])
			{
				double temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
	for(int i = 0; i < 3; i++)
	{
		printf("%.2lf\t",nums[i]);
	}
}
