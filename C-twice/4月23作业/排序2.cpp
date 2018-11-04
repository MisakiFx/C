#include <stdio.h>
#define N 10
int main()
{
	int a[N] = {7,8,9,54,25,65,84,66,88,10}, t, num, low = 0, high = 9, mid, find = 0;
	//冒泡排序：外循环次数等于元素个数-1,内循环每一轮为元素个数，每次循环都会把最小的数向前进行交换 
	for(int i = 0; i < N - 1; i++) 
	{
		for(int j = 0; j < N - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	//二分法查找，从排序好的数组的中间一个数开始比较，一步步缩小范围，如果中间数比查找数小，则锁定数组的后半部分，锁定前半部分 
	printf("请输入要查找的数：",&num);
	scanf("%d",&num);
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(a[mid] == num)
		{
			printf("找到了,下标是%d\n",mid);
			find = 1;
		}
		if(a[mid] < num)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	if(find == 0)
	{
		printf("未找到！");
	 } 
}
